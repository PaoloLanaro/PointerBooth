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

int main() {

    cv::VideoCapture vc(0);
    vc.set(cv::CAP_PROP_SETTINGS, 1);

    if (!vc.isOpened()) {
        cout << "Can't open the camera." << endl;
        return -1;
    }

    cv::Mat frame, frameOut;

    while(true) {
        vc >> frame;

        frameOut = frame.clone();

        cv::imshow("firstFrame", frameOut);

        int key = cv::waitKey(1);
        if (key == 27) {
            break;
        }
    }
    return 0;
}
