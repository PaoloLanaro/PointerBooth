//
// Created by dbusn on 12/7/2023.
//

#include <opencv2/opencv.hpp>
#include <iostream>
#include "VideoEnvironment.h"
#include "GrayScaleFilter.h"
#include "SimpleBlurFilter.h"
#include "GaussianBlurFilter.h"
#include "OtsuThresholdingFilter.h"
#include "GlitchFilter.h"
#include "PixelSortFilter.h"
#include "MatAdapter.h"
#include "Image.h"
#include "Editor.h"
#include "ContourFilter.h"

void VideoEnvironment::startVideo(std::vector<MatrixFilter*> filters) {
    cv::VideoCapture videoCam(0);
    videoCam.set(cv::CAP_PROP_SETTINGS, 1);

    if (!videoCam.isOpened()) {
        std::cerr << "Can't open the camera." << std::endl;
        return;
    }

    cv::Mat currFrame;

    while(true) {
        videoCam >> currFrame;

        cv::imshow("Video", currFrame);
        int key = cv::waitKey(1);
        if (key == 27) {        // esc key
            break;
        }
    }

}

void VideoEnvironment::startExamples() {
    cv::VideoCapture videoCam(0);
    videoCam.set(cv::CAP_PROP_SETTINGS, 1);

    if (!videoCam.isOpened()) {
        std::cerr << "Can't open the camera." << std::endl;
        return;
    }

    cv::Mat currFrame;

    while(true) {
        videoCam >> currFrame;

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



        GlitchFilter gf;
        cv::Mat glitchFrame = currFrame.clone();
        gf.edit(glitchFrame);
        cv::imshow("Glitch Frame", glitchFrame);

        PixelSortFilter psf;
        cv::Mat sortFrame = currFrame.clone();
        psf.edit(sortFrame);
        cv::imshow("PixelSort Frame", sortFrame);


        //ADAPTER TEST
        cv::Mat pointFrame = currFrame.clone();
        MatAdapter test;
        unsigned char* data = test.convertToStbiArray(currFrame, 3);
        Image testImg(data, currFrame.rows, currFrame.cols, 3);
        Editor edit(testImg);
        edit.pointillism();

        cv::Mat updatedFrame = test.convertToMatrix(testImg.flatten(), 3, testImg.getWidth(), testImg.getHeight());
        cv::imshow("Pointillism", updatedFrame);


        cv::imshow("No MatrixFilter", currFrame);

        int key = cv::waitKey(1);
        if (key == 27) {        // esc key
            break;
        }
    }
}
