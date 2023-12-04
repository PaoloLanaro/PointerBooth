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

class ScrambleFilter : public Filter {
public:
    virtual void Edit(cv::Mat* frame) {
        for (int col = 0; col < frame->cols; ++col) {
            //Get the column as a separate matrix
            cv::Mat column = frame->col(col);

            //Reshape the column into a 1D matrix (vector)
            cv::Mat reshaped = column.reshape(1, column.total());

            //Scramble the column with std algorithms
            std::random_device rd;
            //std::shuffle(reshaped.begin<Pixel>(), reshaped.end<Pixel>(), rd);
        }
    }
};

#endif //FINALPROJECT_SCRAMBLEFILTER_H
