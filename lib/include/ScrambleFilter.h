//
// Created by David on 12/4/2023.
//

#ifndef FINALPROJECT_SCRAMBLEFILTER_H
#define FINALPROJECT_SCRAMBLEFILTER_H

#include "Filter.h"
#include <opencv2/core/types.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/core.hpp>
#include <random>
#include <iostream>

typedef cv::Point3_<uint8_t> Pixel;

class ScrambleFilter : public Filter {
public:
    virtual void Edit(cv::Mat* frame) {
        std::random_device rd;
        std::mt19937 g(rd());
        for (int col = 0; col < frame->rows; ++col) {
            //Get the column as a separate matrix
            cv::Mat column = frame->row(col);

            //Reshape the column into a 1D matrix (vector)
            cv::Mat reshaped = column.reshape(1, column.total());
            //std::cout << column << std::endl;

            //Scramble the column with std algorithms
            //TODO: we need to preserve grouping of RGB
            std::shuffle(reshaped.begin<uint8_t>(), reshaped.end<uint8_t>(), g);
        }
    }
};

#endif //FINALPROJECT_SCRAMBLEFILTER_H
