//
// Created by dbusn on 12/6/2023.
//

#include "MatAdapter.h"

/**
 * Sets the next three values of array to values of triplet
 * Assumes there is space in the array
 *
 * @param toAssign
 * @param val
 */
void setVals3D(unsigned char* toAssign, cv::Vec3b val) {
    *toAssign = val[0];
    *(toAssign + 1) = val[1];
    *(toAssign + 2) = val[2];
}

/*
 * This method converts a 2D OpenCV matrix to a 1D array compatible with
 * the stbi library.
 */
unsigned char* MatAdapter::convertToStbiArray(const cv::Mat& input, int numComponents) const {

    int outputSize = input.cols * input.rows * numComponents;
    unsigned char* outputPixels = new unsigned char[outputSize];

    for (int curRow = 0; curRow < input.rows; curRow++) {
        for (int curCol = 0; curCol < input.cols; curCol++) {
            int curIndex = curRow * input.cols + curCol;
            if (numComponents == 3) {
                setVals3D(outputPixels + curIndex, input.at<cv::Vec3b>(curRow, curCol));
            } else {
                outputPixels[curIndex] = input.at<uchar>(curRow, curCol);
            }
        }
    }
    return outputPixels;
}
