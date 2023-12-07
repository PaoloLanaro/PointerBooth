//
// Created by dbusn on 12/6/2023.
//

#ifndef FINALPROJECT_MATADAPTER_H
#define FINALPROJECT_MATADAPTER_H

#include <opencv2/core/mat.hpp>

class MatAdapter {
public:
    unsigned char* convertToStbiArray(const cv::Mat& input, int numComponents) const;
    cv::Mat convertToMatrix(unsigned char* imgData, int numComponents, int imgWidthPixels, int imgHeightPixels);
};

#endif //FINALPROJECT_MATADAPTER_H
