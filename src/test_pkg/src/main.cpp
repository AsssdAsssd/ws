#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <opencv2/opencv.hpp>
#include <iostream>
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
        init();
        publisher_ = this->create_publisher<sensor_msgs::msg::Image>("image", 10);
        timer_ = this->create_wall_timer(50ms, std::bind(&CameraPublisher::timer_callback, this));
        RCLCPP_INFO(this->get_logger(), "摄像头发布节点启动");
    }

    ~CameraPublisher()
    {
        if (cap.isOpened())
        {
            cap.release();
        }
        cv::destroyAllWindows();
    }

private:
    void timer_callback()
    {
        cv::Mat frame;
        cap >> frame;

        if (frame.empty())
        {
            RCLCPP_WARN(this->get_logger(), "Error: 无法读取摄像头帧！");
            return;
        }

        float scale = 0.8;
        cv::resize(frame, frame, cv::Size(frame.cols * scale, frame.rows * scale));

        cv::imshow("Camera Publisher", frame);

        if (cv::waitKey(1) == 'q')
        {
            rclcpp::shutdown();
            return;
        }

        auto header = std_msgs::msg::Header();
        header.stamp = this->now();
        header.frame_id = "camera_frame";

        // 转换OpenCV帧为ROS2 Image消息
        auto ros_image = cv_mat_to_ros_image(frame, header);

        if (ros_image)
        {

            publisher_->publish(*ros_image);
            RCLCPP_INFO(this->get_logger(), "成功发布图像消息");
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
    void init()
    {

        cap.open(0);
        if (!cap.isOpened())
        {
            RCLCPP_ERROR(this->get_logger(), "Error: 无法打开摄像头");
            rclcpp::shutdown();
            return;
        }

        cap.set(cv::CAP_PROP_FRAME_WIDTH, 640);
        cap.set(cv::CAP_PROP_FRAME_HEIGHT, 480);
        cv::namedWindow("Camera Publisher", cv::WINDOW_NORMAL);
    }

    rclcpp::TimerBase::SharedPtr timer_;
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
