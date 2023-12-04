//
// Created by David on 12/4/2023.
//

#ifndef FINALPROJECT_GLITCHFILTER_H
#define FINALPROJECT_GLITCHFILTER_H

#include <opencv2/core/types.hpp>
#include <chrono>

typedef cv::Point3_<uint8_t> Pixel;

class GlitchFilter {
public:
    void operator() (Pixel& pixel, const int* position) const {
        int choice = rand() % 3;
        auto time = std::chrono::system_clock::now().time_since_epoch();
        long long milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(time).count();
        switch (choice) {
            case 0:
                pixel.x = milliseconds % 255;
                break;
            case 1:
                pixel.y = milliseconds % 255;
                break;
            case 2:
                pixel.z = milliseconds % 255;
                break;
        }
    }
};
#endif //FINALPROJECT_GLITCHFILTER_H
