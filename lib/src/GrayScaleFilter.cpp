//
// Created by lanar on 12/6/2023.
//

#include "GrayScaleFilter.h"
#include <opencv2/imgproc.hpp>

void GrayScaleFilter::edit(cv::Mat &frame) {
    cv::cvtColor(frame, frame, cv::COLOR_BGR2GRAY);
}
