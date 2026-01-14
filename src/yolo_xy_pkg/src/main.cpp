#include <iostream>
#include <vector>
#include <getopt.h>
#include <iomanip>
#include <opencv2/opencv.hpp>

#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.hpp>
#include "rclcpp/rclcpp.hpp"
#include "inference.h"
#include "std_msgs/msg/string.hpp"
#include "sensor_msgs/msg/image.hpp"
using namespace std;
using namespace cv;
using namespace std::chrono_literals;

class TargetxySubscriber : public rclcpp::Node
{
public:
    TargetxySubscriber() : Node("targetxysubscriber")
    {
        init();
        command_subscribe_ = this->create_subscription<sensor_msgs::msg::Image>("image", 10, std::bind(&TargetxySubscriber::command_callback, this, std::placeholders::_1));
        RCLCPP_INFO(this->get_logger(), "接接收者节点已启动");
    }

private:
    void command_callback(const sensor_msgs::msg::Image::SharedPtr msg)
    {
        cv::Mat frame;
        frame = processe_image(msg);

        if (frame.empty())
        {
            RCLCPP_INFO(this->get_logger(), "Error: 无法读取摄像头帧！");
            return;
        }

        std::vector<Detection> output = inf->runInference(frame);
        int detections = output.size();
        RCLCPP_INFO(this->get_logger(), "Number of detections: %d", detections);

        // 增加：看框
        drawbox(output, frame);

        float scale = 0.8;
        cv::resize(frame, frame, cv::Size(frame.cols * scale, frame.rows * scale));
        cv::imshow("Camera Detection", frame);

        if (cv::waitKey(1) == 'q')
        {
            std::cout << "程序已退出！" << std::endl;
            rclcpp::shutdown(); // 正确退出ROS2节点，而非break
            return;
        }

        // 先只输出xy跑通一下
        std::vector<float>
            centerX(detections);
        std::vector<float> centerY(detections);
        if (detections)
        {
            for (int j = 0; j < detections; ++j)
            {
                Detection detection = output[j];
                cv::Rect box = detection.box;
                centerX[j] = box.x + box.width / 2.0f;
                centerY[j] = box.y + box.height / 2.0f;
            }
        }

        if (detections)
        {
            std::string all_centers;
            for (int j = 0; j < detections; ++j)
            {
                all_centers += "center" + to_string(j + 1) + ":(" + to_string(centerX[j]).substr(0, 5) + "," + to_string(centerY[j]).substr(0, 5) + ") ";
            }
            RCLCPP_INFO(this->get_logger(), "'%s'", all_centers.c_str());
        }
        else
        {
            RCLCPP_INFO(this->get_logger(), "暂无中心点");
        }
    }
    cv::Mat processe_image(const sensor_msgs::msg::Image::SharedPtr &processed_image)
    {
        try
        {
            // 将ROS图像转换为OpenCV格式
            cv_bridge::CvImagePtr cv_ptr = cv_bridge::toCvCopy(processed_image, sensor_msgs::image_encodings::BGR8);
            return cv_ptr->image;
        }
        catch (const cv_bridge::Exception &e)
        {
            RCLCPP_ERROR(this->get_logger(), "无法显示图像: %s", e.what());
            return cv::Mat();
        }
    }

    void drawbox(const std::vector<Detection> &output, cv::Mat &frame)
    {
        int detections = output.size();
        for (int j = 0; j < detections; ++j)
        {
            Detection detection = output[j];
            cv::Rect box = detection.box;
            cv::Scalar color = detection.color;
            float centerX = box.x + box.width / 2.0f;
            float centerY = box.y + box.height / 2.0f;

            cv::rectangle(frame, box, color, 8);
            cv::circle(frame, cv::Point(centerX, centerY), 5, cv::Scalar(0, 0, 255), -1);

            std::string classString = detection.className + " " + to_string(detection.confidence).substr(0, 4);
            std::string centerText = "(" + to_string(centerX).substr(0, 5) + ", " + to_string(centerY).substr(0, 5) + ")";
            std::string showText = classString + " |" + centerText;

            // 计算文字框大小
            cv::Size textSize = cv::getTextSize(showText, cv::FONT_HERSHEY_DUPLEX, 0.8, 2, 0);
            cv::Rect textBox(box.x, box.y - 50, textSize.width + 10, textSize.height + 20);

            // 绘制文字背景框+文字
            cv::rectangle(frame, textBox, color, cv::FILLED);
            cv::putText(frame, showText, cv::Point(box.x + 5, box.y - 15),
                        cv::FONT_HERSHEY_DUPLEX, 0.8, cv::Scalar(0, 0, 0), 2, 0);
        }
    }

    void init()
    {

        this->declare_parameter<std::string>("projectBasePath", "/src/yoloxy_pkg/");
        projectBasePath = this->get_parameter("projectBasePath").as_string();
        this->declare_parameter<int>("imgsz", 640);
        imgsz = this->get_parameter("imgsz").as_int();

        bool runOnGPU = false;
        inf = std::make_unique<Inference>(
            projectBasePath + "resource/best.onnx",
            cv::Size(imgsz, imgsz),
            projectBasePath + "resource/classes.txt",
            runOnGPU);

        cv::namedWindow("Camera Detection", cv::WINDOW_NORMAL);
    }

    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr command_subscribe_;
    std::string projectBasePath;
    std::unique_ptr<Inference> inf;
    int imgsz;
};
int main(int argc, char *argv[])
{

    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<TargetxySubscriber>());
    rclcpp::shutdown();
    cv::destroyAllWindows(); // 新增
    return 0;
}
