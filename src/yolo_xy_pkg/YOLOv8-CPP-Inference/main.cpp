#include <iostream>
#include <vector>
#include <getopt.h>
#include <iomanip>
#include <opencv2/opencv.hpp>

#include "inference.h"

using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
    std::string projectBasePath = "/home/zhongrui/env/ultralytics-8.1.0";
    bool runOnGPU = false;

    Inference inf(projectBasePath + "/examples/YOLOv8-CPP-Inference/best.onnx",
                  cv::Size(640, 640),
                  "/home/zhongrui/env/ultralytics-8.1.0/examples/YOLOv8-CPP-Inference/classes.txt",
                  runOnGPU);
    cv::VideoCapture cap(0);
    if (!cap.isOpened())
    {
        std::cerr << "Error: 无法打开摄像头！" << std::endl;
        return -1;
    }
    cap.set(cv::CAP_PROP_FRAME_WIDTH, 640);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 480);

    cv::Mat frame;
    std::cout << "摄像头已打开，按 'q' 退出程序..." << std::endl;

    while (true)
    {
        cap >> frame;
        if (frame.empty())
        {
            std::cerr << "Error: 无法读取摄像头帧！" << std::endl;
            break;
        }

        std::vector<Detection> output = inf.runInference(frame);
        int detections = output.size();
        std::cout << "\nNumber of detections: " << detections << std::endl;

        // 画框
        for (int j = 0; j < detections; ++j)
        {
            Detection detection = output[j];
            cv::Rect box = detection.box;
            cv::Scalar color = detection.color;
            float centerX = box.x + box.width / 2.0f;
            float centerY = box.y + box.height / 2.0f;

            std::cout << "目标" << j + 1
                      << " | 置信度：" << fixed << setprecision(2) << detection.confidence
                      << " | 中心点坐标：(" << centerX << ", " << centerY << ")" << std::endl;

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

        float scale = 0.8;
        cv::resize(frame, frame, cv::Size(frame.cols * scale, frame.rows * scale));
        cv::imshow("Camera", frame);

        if (cv::waitKey(1) == 'q')
        {
            std::cout << "程序已退出！" << std::endl;
            break;
        }
    }

    cap.release();
    cv::destroyAllWindows();
    return 0;
}
