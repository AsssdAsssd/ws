#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <opencv2/opencv.hpp>
#include <iostream>
// 必须包含的头文件
#include "sensor_msgs/msg/image.hpp"
#include "cv_bridge/cv_bridge.h"
#include "std_msgs/msg/header.hpp"

using namespace std;
using namespace cv;
using namespace std::chrono_literals;

class CameraPublisher : public rclcpp::Node
{
public:
    CameraPublisher() : Node("camera_publisher")
    {
        // 初始化摄像头和参数
        init();
        // 创建发布者，发布String类型消息到"camera_topic"话题
        publisher_ = this->create_publisher<sensor_msgs::msg::Image>("image", 10);
        // 定时器频率沿用你正常代码的50ms（通过后续resize/处理缓冲频率）
        timer_ = this->create_wall_timer(50ms, std::bind(&CameraPublisher::timer_callback, this));
        RCLCPP_INFO(this->get_logger(), "摄像头发布节点已启动");
    }

    ~CameraPublisher()
    {
        // 规范释放资源（沿用你正常代码的资源管理逻辑）
        if (cap.isOpened())
        {
            cap.release();
            RCLCPP_INFO(this->get_logger(), "摄像头资源已释放");
        }
        cv::destroyAllWindows();
        RCLCPP_INFO(this->get_logger(), "节点已关闭");
    }

private:
    void timer_callback()
    {
        cv::Mat frame;
        cap >> frame;

        // 帧为空的错误处理
        if (frame.empty())
        {
            RCLCPP_WARN(this->get_logger(), "Error: 无法读取摄像头帧！");
            return;
        }

        // 修复帧格式/尺寸异常
        float scale = 0.8;
        cv::resize(frame, frame, cv::Size(frame.cols * scale, frame.rows * scale));

        // 显示窗口
        cv::imshow("Camera Publisher", frame);

        // 退出逻辑
        if (cv::waitKey(1) == 'q')
        {
            RCLCPP_INFO(this->get_logger(), "用户按下q，程序退出");
            rclcpp::shutdown();
            return;
        }

        // 构造消息头
        auto header = std_msgs::msg::Header();
        header.stamp = this->now(); // 节点当前时间戳
        header.frame_id = "camera_frame";

        // 转换OpenCV帧为ROS2 Image消息
        auto ros_image = cv_mat_to_ros_image(frame, header);

        if (ros_image)
        {
            // 关键修正1：直接发布转换后的ros_image（不是新建空的message）
            publisher_->publish(*ros_image);
            // 打印日志，显示发布的帧尺寸（方便调试）
            RCLCPP_INFO(this->get_logger(), "成功发布图像消息！帧尺寸：%dx%d",
                        frame.cols, frame.rows);
        }
        else
        {
            RCLCPP_ERROR(this->get_logger(), "图像转换失败，未发布消息");
        }
    }

    sensor_msgs::msg::Image::SharedPtr cv_mat_to_ros_image(const cv::Mat &cv_image, const std_msgs::msg::Header &header)
    {
        try
        {
            cv_bridge::CvImage cv_bridge_image(header, sensor_msgs::image_encodings::BGR8, cv_image);
            return cv_bridge_image.toImageMsg();
        }
        catch (const cv_bridge::Exception &e)
        {
            RCLCPP_ERROR(this->get_logger(), "cv_bridge异常: %s", e.what());
            return nullptr;
        }
    }
    // 沿用你正常代码的init函数结构，完善初始化逻辑
    void init()
    {
        // 打开摄像头（和你正常代码一致的打开方式）
        cap.open(0);
        if (!cap.isOpened())
        {
            RCLCPP_ERROR(this->get_logger(), "Error: 无法打开摄像头");
            rclcpp::shutdown();
            return;
        }

        // 设置摄像头分辨率（和你正常代码参数一致）
        cap.set(cv::CAP_PROP_FRAME_WIDTH, 640);
        cap.set(cv::CAP_PROP_FRAME_HEIGHT, 480);

        // 核心修复：创建规范窗口（你正常代码的关键细节，之前简化版缺失）
        cv::namedWindow("Camera Publisher", cv::WINDOW_NORMAL);
    }

    // 成员变量（沿用你正常代码的声明风格）
    rclcpp::TimerBase::SharedPtr timer_;
    // 替换原来的String类型publisher声明
    rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr publisher_;

    cv::VideoCapture cap;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<CameraPublisher>());
    rclcpp::shutdown();
    return 0;
}
