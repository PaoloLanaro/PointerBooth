#include <iostream>

using std::cout, std::endl;

#pragma ide diagnostic ignored "EndlessLoop"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/core/utility.hpp>
#include <opencv2\opencv.hpp>
#include <opencv2\imgcodecs.hpp>
#include "opencv2/videoio.hpp"
#include "PixelSortFilter.h"
#include "ScrambleFilter.h"
#include <opencv2/highgui.hpp>
#include <GlitchFilter.h>
#include <opencv2/video.hpp>

typedef cv::Point3_<uint8_t> Pixel;

int videoCapture();

void imageTest();

int main() {
    return videoCapture();

//    imageTest();

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

        //some sort of polymorphism for filters here
        //they can be stacked too-- maybe some sort of command for them
        //example usage

        GlitchFilter gf;
        PixelSortFilter psf;
        ScrambleFilter sf;

//        gf.Edit(&frame);
        psf.Edit(&frame);
//        sf.Edit(&frame);




        frameOut = frame.clone();

        cv::imshow("firstFrame", frameOut);

        int key = cv::waitKey(1);
        if (key == 27) {        // esc key
            break;
        }
    }
    return 0;
}
