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

cv::Vec3b getVecFromNextVals(const unsigned char *imgData) {
    auto first = imgData[0];
    auto second = imgData[1];
    auto third = imgData[3];
    cv::Vec3b output(first, second, third);
    return output;
}

/**
 * Note that OpenCV containers have automatic memory management.
 * Converts a provided array of characters into OpenCV matrix data.
 *
 * @param imgData data to convert
 * @param numComponents number of pixel components
 * @param imgWidthPixels width in pixels
 * @param imgHeightPixels height in pixels
 * @return
 */
cv::Mat MatAdapter::convertToMatrix(unsigned char *imgData, int numComponents, int imgWidthPixels, int imgHeightPixels) {
    cv::Mat output;
    if (numComponents == 3) {
        output = cv::Mat(imgHeightPixels, imgWidthPixels, CV_8U); // 8U represents single unsigned integer
    } else {
        output = cv::Mat(imgHeightPixels, imgWidthPixels, CV_8UC3); // 8U represents 3 channel integers
    }

    for (int curRow = 0; curRow < imgHeightPixels; curRow++) {
        for (int curCol = 0; curCol < imgWidthPixels - (numComponents - 1); curCol++) { //go to the start of the last grouping
            int curIndex = curRow * imgWidthPixels + curCol;
            if (numComponents == 3) {
                output.at<cv::Vec3b>(curRow / 3, curCol) = getVecFromNextVals(imgData + curIndex);
                curCol += 2;
            } else {
                output.at<uchar>(curRow, curCol) = imgData[curIndex];
            }
        }
    }
    return output;
}
