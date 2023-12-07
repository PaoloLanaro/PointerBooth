//
// Created by lanar on 12/6/2023.
//
#include <opencv2/imgproc.hpp>
#include "filters/OtsuThresholdingFilter.h"

/**
 * Apply Otsu Thresholding effect
 *
 * @param frame Frame to edit
 */
void OtsuThresholdingFilter::edit(cv::Mat &frame) {
    double thresh = 100;
    double maxValue = 255;
    cv::threshold(frame, frame, thresh, maxValue, cv::THRESH_OTSU);
}

