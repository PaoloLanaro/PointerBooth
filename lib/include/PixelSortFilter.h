//
// Created by David on 12/4/2023.
//

#ifndef FINALPROJECT_PIXELSORTFILTER_H
#define FINALPROJECT_PIXELSORTFILTER_H

#include <opencv2/core/types.hpp>
#include <chrono>

typedef cv::Point3_<uint8_t> Pixel;

class GlitchFilter {
public:
    void operator() (Pixel& pixel, const int* position) const {

    }
};

#endif //FINALPROJECT_PIXELSORTFILTER_H
