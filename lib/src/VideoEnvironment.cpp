//
// Created by dbusn on 12/7/2023.
//

#include <opencv2/opencv.hpp>
#include <iostream>
#include "VideoEnvironment.h"
#include "filters/GrayScaleFilter.h"
#include "filters/SimpleBlurFilter.h"
#include "filters/GaussianBlurFilter.h"
#include "filters/OtsuThresholdingFilter.h"
#include "filters/GlitchFilter.h"
#include "filters/PixelSortFilter.h"
#include "MatAdapter.h"
#include "Image.h"
#include "Editor.h"
#include "filters/ContourFilter.h"
#include "filters/PointillismFilter.h"

/**
 * Show video with the provided list of filters
 *
 * @param filters the list of filters to apply in order
 */
void VideoEnvironment::startVideo(const std::vector<std::string>& filters) {
    cv::VideoCapture videoCam(0);
    videoCam.set(cv::CAP_PROP_SETTINGS, 1);

    if (!videoCam.isOpened()) {
        std::cerr << "Can't open the camera." << std::endl;
        return;
    }

    cv::Mat currFrame;

    while(true) {
        videoCam >> currFrame;
        this->applyFilters(currFrame, filters);

        cv::imshow("Video", currFrame);
        int key = cv::waitKey(1);
        if (key == 27) {        // esc key
            break;
        }
    }

}

/**
 * Show all examples of filters at once
 */
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


        cv::imshow("No Filter", currFrame);

        int key = cv::waitKey(1);
        if (key == 27) {        // esc key
            break;
        }
    }
}


/**
 * Convert arg to lowercase for parsing
 *
 * @param input parameter
 * @return lowercase version
 */
std::string convertToLower(std::string input) {
    std::string output = "";
    for (char i : input) {
        output += tolower(i);
    }
    return output;
}

/**
 * Apply filters from the provided list in order.
 *
 * @param frame The frame to edit
 * @param filtersList The list of filter names
 */
void VideoEnvironment::applyFilters(cv::Mat& frame, std::vector<std::string> filtersList) {
    for (std::string requestName : filtersList) {
        requestName = convertToLower(requestName);
        Filter* editWith = nullptr;
        if (requestName == "contour")
            editWith = new ContourFilter (frame);
        else if (requestName == "pointillism")
            editWith = new PointillismFilter();
        else if (requestName == "gaussianblur")
            editWith = new GaussianBlurFilter();
        else if (requestName == "glitch")
            editWith = new GlitchFilter();
        else if (requestName == "otsu")
            editWith = new OtsuThresholdingFilter();
        else if (requestName == "pixelsort")
            editWith = new PixelSortFilter();
        else if (requestName == "simpleblur")
            editWith = new SimpleBlurFilter();
        else if (requestName == "greyscale" || requestName == "grayscale")
            editWith = new GrayScaleFilter();
        else
            continue;

        editWith->edit(frame);
        delete editWith;    //not sure if this is necessary but this would be the dumbest memory leak ever LOL

    }
}
