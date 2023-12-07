//
// Created by lanar on 12/6/2023.
//

#include <opencv2/imgproc.hpp>
#include "GaussianBlurFilter.h"

void GaussianBlurFilter::edit(cv::Mat &frame) {
    cv::GaussianBlur(frame, frame, cv::Size(5, 5), 0);
}

