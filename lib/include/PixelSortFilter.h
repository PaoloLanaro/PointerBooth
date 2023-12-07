//
// Created by David on 12/4/2023.
//

#ifndef FINALPROJECT_PIXELSORTFILTER_H
#define FINALPROJECT_PIXELSORTFILTER_H

#include <opencv2/core/types.hpp>
#include <chrono>
#include <opencv2/core/mat.hpp>
#include <opencv2/core.hpp>
#include "Filter.h"

class PixelSortFilter : public Filter {
public:
    virtual void edit(cv::Mat &frame) {
        for (int col = 0; col < frame.cols; ++col) {
            //Get the column as a separate matrix
            cv::Mat column = frame.col(col);

            //Reshape the column into a vector
            cv::Mat reshaped = column.reshape(1, column.total());

            //Sort the elements in the column
            cv::sort(reshaped, reshaped, cv::SORT_EVERY_COLUMN);

        }
    }
};

#endif //FINALPROJECT_PIXELSORTFILTER_H
