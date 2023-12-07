//
// Created by David on 12/4/2023.
//

#ifndef FINALPROJECT_FILTER_H
#define FINALPROJECT_FILTER_H

#include <opencv2/core/types.hpp>

typedef cv::Point3_<uint8_t> CVPixel;

class Filter {
public:
    virtual void edit(cv::Mat &frame) = 0;
    virtual ~Filter() = default;
};

#endif //FINALPROJECT_FILTER_H
