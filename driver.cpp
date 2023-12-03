#include <iostream>

using std::cout, std::endl;

#pragma ide diagnostic ignored "EndlessLoop"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/core/utility.hpp>
#include <opencv2\opencv.hpp>
#include <opencv2\imgcodecs.hpp>
#include "opencv2/videoio.hpp"
#include <opencv2/highgui.hpp>
#include <opencv2/video.hpp>

int videoCapture();

void imageTest();

int main() {
//    return videoCapture();

    imageTest();

    return 0;
}

void imageTest() {
    cv::Mat img = cv::imread("./test_images/finger-up.jpg");
//    img.
    cv::imshow("finger-up test", img);
}

int videoCapture() {

    cv::VideoCapture videoCam(0);
    videoCam.set(cv::CAP_PROP_SETTINGS, 1);

    if (!videoCam.isOpened()) {
        cout << "Can't open the camera." << endl;
        return -1;
    }

    cv::Mat frame, frameOut;

    while(true) {
        videoCam >> frame;

        frameOut = frame.clone();

        cv::imshow("firstFrame", frameOut);

        int key = cv::waitKey(1);
        if (key == 27) {        // esc key
            break;
        }
    }
    return 0;
}
