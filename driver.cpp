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
#include "GrayScaleFilter.h"
#include "SimpleBlurFilter.h"
#include "GaussianBlurFilter.h"
#include "OtsuThresholdingFilter.h"
#include "ContourFilter.h"
#include "MatAdapter.h"

using namespace std;
using namespace cv;

typedef cv::Point3_<uint8_t> Pixel;

int videoCapture();

void imageTest();

int main() {
//    return videoCapture();

    imageTest();

    return 0;
}

void imageTest() {
    cv::Mat img = cv::imread("../test_images/finger-up.jpg");
    MatAdapter test;
    cv::imgshow("test", img);
}

int videoCapture() {

    cv::VideoCapture videoCam(0);
    videoCam.set(cv::CAP_PROP_SETTINGS, 1);

    if (!videoCam.isOpened()) {
        cout << "Can't open the camera." << endl;
        return -1;
    }

    cv::Mat currFrame;

    while(true) {
        videoCam >> currFrame;
        cv::imshow("Initial Frame", currFrame); // original image

        cv::Mat grayFrame = currFrame.clone();
        GrayScaleFilter gsf;
        gsf.edit(grayFrame);

        cv::imshow("Gray frame", grayFrame);

        cv::Mat blurredFrame = currFrame.clone();
        SimpleBlurFilter sbf;
        sbf.edit(blurredFrame);

        cv::imshow("Simple Blurred Frame", blurredFrame);

        cv::Mat gaussBlurFrame = currFrame.clone();
        GaussianBlurFilter gbf;
        gbf.edit(gaussBlurFrame);

        cv::imshow("Gaussian Blurred Frame", gaussBlurFrame);

        // combines gray and simple blur filters
        cv::Mat grayGaussian = grayFrame.clone();
        sbf.edit(grayGaussian);

        OtsuThresholdingFilter otf;
        otf.edit(grayGaussian);

        cv::imshow("simple otsu thresholding (binarization) ", grayGaussian);

        //some sort of polymorphism for filters here
        //they can be stacked too-- maybe some sort of command for them
        //example usage

        GlitchFilter gf;
        PixelSortFilter psf;
        ScrambleFilter sf;

//        gf.edit(&currFrame);
//        psf.edit(&currFrame);
//        sf.edit(&currFrame);

        cv::Mat ioFrame = currFrame.clone();
        ContourFilter cf(ioFrame);
        cf.edit(grayGaussian);

        cv::imshow("final", ioFrame);

        int key = cv::waitKey(1);
        if (key == 27) {        // esc key
            break;
        }
    }
    return 0;
}
