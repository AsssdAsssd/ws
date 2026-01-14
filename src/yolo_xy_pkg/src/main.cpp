#include <iostream>
#include <vector>
#include <getopt.h>
#include <iomanip>
#include <opencv2/opencv.hpp>
#include "rclcpp/rclcpp.hpp"
#include "inference.h"
#include "std_msgs/msg/string.hpp"

using namespace std;
using namespace cv;
using namespace std::chrono_literals;

class TargetxyPublisher : public rclcpp::Node
{
public:
    TargetxyPublisher() : Node("targetxy_publisher")
    {
        init();
        // 创建发布者，发布String类型消息到"topic"话题
        publisher_ = this->create_publisher<std_msgs::msg::String>("xy_topic", 10);
        // 创建定时器，每500ms发布一次消息
        timer_ = this->create_wall_timer(50ms, std::bind(&TargetxyPublisher::timer_callback, this));
        RCLCPP_INFO(this->get_logger(), "发布者节点已启动");
    }

    ~TargetxyPublisher()
    {
        if (cap.isOpened())
        {
            cap.release();
        }
        cv::destroyAllWindows();
        RCLCPP_INFO(this->get_logger(), "关闭");
    }

private:
    void timer_callback()
    {
        cv::Mat frame;
        cap >> frame;

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
        cv::imshow("Camera", frame);

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

        // 创建消息对象
        auto message = std_msgs::msg::String();
        if (detections)
        {
            std::string all_centers;
            for (int j = 0; j < detections; ++j)
            {
                all_centers += "中心点" + to_string(j + 1) + ":(" + to_string(centerX[j]).substr(0, 5) + "," + to_string(centerY[j]).substr(0, 5) + ") ";
            }
            message.data = all_centers;
        }
        else
        {
            message.data = "暂无中心点";
        }
        // 发布消息
        publisher_->publish(message);
        RCLCPP_INFO(this->get_logger(), "发布消息: '%s'", message.data.c_str());
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

            // std::cout << "目标" << j + 1
            //           << " | 置信度：" << fixed << setprecision(2) << detection.confidence
            //           << " | 中心点坐标：(" << centerX << ", " << centerY << ")" << std::endl;

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

        cap.open(0);
        if (!cap.isOpened())
        {
            RCLCPP_ERROR(this->get_logger(), "Error: 无法打开摄像头");
            rclcpp::shutdown();
            return;
        }
        cap.set(cv::CAP_PROP_FRAME_WIDTH, 640);
        cap.set(cv::CAP_PROP_FRAME_HEIGHT, 480);
        cv::namedWindow("Camera Detection", cv::WINDOW_NORMAL);
    }

    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    std::string projectBasePath;
    int imgsz;
    std::unique_ptr<Inference> inf;
    cv::VideoCapture cap;
};

int main(int argc, char *argv[])
{

    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<TargetxyPublisher>());
    rclcpp::shutdown();
    return 0;
}
