//
// Created by David on 12/4/2023.
//

#ifndef FINALPROJECT_MATRIXFILTER_H
#define FINALPROJECT_MATRIXFILTER_H

#include <opencv2/core/types.hpp>

typedef cv::Point3_<uint8_t> CVPixel;

class MatrixFilter {
public:
    virtual void edit(cv::Mat &frame) = 0;
};


#endif //FINALPROJECT_MATRIXFILTER_H
