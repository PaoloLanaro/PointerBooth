//
// Created by dbusn on 12/6/2023.
//

#ifndef FINALPROJECT_MATADAPTER_H
#define FINALPROJECT_MATADAPTER_H

#include <opencv2/core/mat.hpp>

class MatAdapter {
    unsigned char* convertToStbiArray(const cv::Mat& input, int numComponents) const;
};

#endif //FINALPROJECT_MATADAPTER_H
