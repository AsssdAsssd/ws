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

#include "center_msg_pkg/msg/center.hpp"

#include <stdio.h>
#include <time.h>

using namespace std;
using namespace cv;
using namespace std::chrono_literals;

class TargetxySubscriber : public rclcpp::Node
{
public:
    TargetxySubscriber() : Node("targetxysubscriber")
    {
        init();

        publisher_ = this->create_publisher<center_msg_pkg::msg::Center>("centerxy_topic", 10);

        RCLCPP_INFO(this->get_logger(), "发布者节点已启动");

        command_subscribe_ = this->create_subscription<sensor_msgs::msg::Image>("image", 0, std::bind(&TargetxySubscriber::command_callback, this, std::placeholders::_1));
        RCLCPP_INFO(this->get_logger(), "接收者节点已启动");
    }

private:
    void command_callback(const sensor_msgs::msg::Image::SharedPtr msg)
    {
        // time(1);
        cv::Mat frame;
        frame = processe_image(msg);

        if (frame.empty())
        {
            RCLCPP_INFO(this->get_logger(), "Error: 无法读取摄像头帧！");
            return;
        }

        std::vector<Detection> output = inf->runInference(frame);
        // time(2);
        int detections = output.size();
        RCLCPP_INFO(this->get_logger(), "目标数: %d", detections);
        // 显示输出
        draw(output, frame);

        float scale = 0.8;
        cv::resize(frame, frame, cv::Size(frame.cols * scale, frame.rows * scale));
        cv::imshow("Camera Detection", frame);
        // time(3);

        if (cv::waitKey(1) == 'q')
        {
            std::cout << "程序已退出！" << std::endl;
            rclcpp::shutdown();
            return;
        }

        std::vector<float> centerX(detections);
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

        timer_callback(detections, centerX, centerY);
    }

    void time(const int a)
    {
        clock_gettime(CLOCK_REALTIME, &ts);

        time_t t = ts.tv_sec;
        struct tm *tm = localtime(&t);

        printf("%d当前时间： %04d-%02d-%02d %02d:%02d:%02d.%03ld\n", a, tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec, ts.tv_nsec / 1000000);
    }
    void timer_callback(int boxnum, std::vector<float> centerX, std::vector<float> centerY)
    {
        if (boxnum)
        {
            center_msg_pkg::msg::Center message;
            message.box_num = boxnum;
            for (int i = 0; i < boxnum; i++)
            {
                center_msg_pkg::msg::Singlecenter point;
                point.center_x = centerX[i];
                point.center_y = centerY[i];
                message.boxes.push_back(point);
            }
            publisher_->publish(message);
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

    void draw(const std::vector<Detection> &output, cv::Mat &frame)
    {
        int detections = output.size();
        for (int j = 0; j < detections; ++j)
        {
            Detection detection = output[j];
            cv::Rect box = detection.box;
            cv::Scalar color = detection.color;
            float centerX = box.x + box.width / 2.0f;
            float centerY = box.y + box.height / 2.0f;

            cv::rectangle(frame, box, color, 5);
            cv::circle(frame, cv::Point(centerX, centerY), 5, cv::Scalar(0, 0, 255), -1);

            std::string classString = detection.className + " " + to_string(detection.confidence).substr(0, 4);
            std::string centerText = "(" + to_string(centerX).substr(0, 5) + ", " + to_string(centerY).substr(0, 5) + ")";
            std::string showText = classString + " |" + centerText;

            cv::Size textSize = cv::getTextSize(showText, cv::FONT_HERSHEY_DUPLEX, 0.8, 2, 0);
            cv::Rect textBox(box.x, box.y - 25, textSize.width + 5, textSize.height + 10);

            cv::rectangle(frame, textBox, color, cv::FILLED);
            cv::putText(frame, showText, cv::Point(box.x + 3, box.y - 7),
                        cv::FONT_HERSHEY_DUPLEX, 0.8, cv::Scalar(0, 0, 0), 2, 0);
        }
    }

    void init()
    {
        this->declare_parameter<std::string>("projectBasePath", "/src/yoloxy_pkg/");
        projectBasePath = this->get_parameter("projectBasePath").as_string();
        this->declare_parameter<int>("imgsz", 640);
        imgsz = this->get_parameter("imgsz").as_int();
        this->declare_parameter<bool>("runGPU", "false");
        bool runOnGPU = this->get_parameter("runGPU").as_bool();

        this->declare_parameter<double>("ConfidenceThreshold", 0.6);
        ConfidenceThreshold = this->get_parameter("ConfidenceThreshold").as_double();
        this->declare_parameter<double>("ScoreThreshold", 0.6);
        ScoreThreshold = this->get_parameter("ScoreThreshold").as_double();
        this->declare_parameter<double>("NMSThreshold", 0.6);
        NMSThreshold = this->get_parameter("NMSThreshold").as_double();

        inf = std::make_unique<Inference>(
            projectBasePath + "resource/best.onnx",
            cv::Size(imgsz, imgsz),
            projectBasePath + "resource/classes.txt",
            runOnGPU,
            ConfidenceThreshold,
            ScoreThreshold,
            NMSThreshold);

        cv::Mat frame1;
        frame1 = cv::imread(projectBasePath + "resource/1.jpg");

        std::vector<Detection> output = inf->runInference(frame1);

        cv::namedWindow("Camera Detection", cv::WINDOW_NORMAL);
    }

    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr command_subscribe_;
    std::string projectBasePath;
    double ConfidenceThreshold;
    double ScoreThreshold;
    double NMSThreshold;
    std::unique_ptr<Inference> inf;
    int imgsz;

    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<center_msg_pkg::msg::Center>::SharedPtr publisher_;

    struct timespec ts;
};
int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<TargetxySubscriber>());
    rclcpp::shutdown();
    cv::destroyAllWindows();
    return 0;
}
