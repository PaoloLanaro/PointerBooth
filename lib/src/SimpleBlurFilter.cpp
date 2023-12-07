//
// Created by lanar on 12/6/2023.
//

#include <opencv2/imgproc.hpp>
#include "filters/SimpleBlurFilter.h"

/**
 * Blur the frame
 *
 * @param frame Mat of the frame to blur
 */
void SimpleBlurFilter::edit(cv::Mat &frame) {
    cv::medianBlur(frame, frame, 5); //5 is a tunable param. must stay odd and pos
}

