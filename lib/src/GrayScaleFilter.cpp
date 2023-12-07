//
// Created by lanar on 12/6/2023.
//

#include "filters/GrayScaleFilter.h"
#include <opencv2/imgproc.hpp>

/**
 * Filter to convert to greyscale
 *
 * @param frame frame to edit
 */
void GrayScaleFilter::edit(cv::Mat &frame) {
    cv::cvtColor(frame, frame, cv::COLOR_BGR2GRAY);
}
