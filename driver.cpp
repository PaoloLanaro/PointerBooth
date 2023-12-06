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

using namespace std;
using namespace cv;

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

    cv::Mat currFrame, frameClone, frameClone2;

    while(true) {
        videoCam >> currFrame;
        frameClone = currFrame.clone();
        frameClone2 = currFrame.clone();
        cv::imshow("Initial Frame", frameClone); // original image

        cv::Mat grayFrame, gaussGray;
        cv::cvtColor(currFrame, grayFrame, cv::COLOR_BGR2GRAY);
        cv::medianBlur(grayFrame, grayFrame, 5); //5 is a tunable param. must stay odd and pos
        cv::imshow("Gray frame", grayFrame);

        cv::GaussianBlur(grayFrame, gaussGray, cv::Size(5, 5), 0);
        cv::imshow("Gauss gray", gaussGray);

        cv::Mat postOtsuThresholding;
        double thresh = 100;
        double maxValue = 255;

//        cv::CascadeClassifier faceCascadeClass;
//        faceCascadeClass.load("../res/haarcascade_frontalface_alt.xml");
        cv::threshold(grayFrame, postOtsuThresholding, thresh, maxValue, cv::THRESH_OTSU);
        cv::imshow("reg otsu binary", postOtsuThresholding);

        //some sort of polymorphism for filters here
        //they can be stacked too-- maybe some sort of command for them
        //example usage

        GlitchFilter gf;
        PixelSortFilter psf;
        ScrambleFilter sf;

//        gf.edit(&frame);
//        psf.edit(&frameClone2);
//        sf.edit(&frame);




//        frameClone2 = currFrame.clone();
//        cv::Mat adaptiveOutput;
//        cv::adaptiveThreshold(grayFrame, adaptiveOutput, 150, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY, 11, 5); // tunable params
//        cv::imshow("adaptive gauss binary", adaptiveOutput);

        std::vector<std::vector<cv::Point>> contours;
        std::vector<cv::Vec4i> hierarchy;
        findContours(postOtsuThresholding, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_NONE);

        cv::Mat finalFrame = currFrame.clone();
        drawContours(finalFrame, contours, -1, cv::Scalar(0, 0, 255), 2);
        cv::imshow("final", finalFrame);

        int key = cv::waitKey(1);
        if (key == 27) {        // esc key
            break;
        }
    }
    return 0;
}
