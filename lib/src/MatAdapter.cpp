//
// Created by dbusn on 12/6/2023.
//

#include <iostream>
#include "MatAdapter.h"

/**
 * Sets the next three values of array to values of triplet
 * Assumes there is space in the array
 *
 * @param toAssign
 * @param val
 */
void setVals3D(unsigned char* toAssign, cv::Vec3b val) {
    *toAssign = val[2];
    *(toAssign + 1) = val[1];
    *(toAssign + 2) = val[0];
}

/*
 * This method converts a 2D OpenCV matrix to a 1D array compatible with
 * the stbi library.
 */
unsigned char* MatAdapter::convertToStbiArray(const cv::Mat& input, int numComponents) const {

    int outputSize = input.cols * input.rows * numComponents;
    unsigned char* outputPixels = new unsigned char[outputSize];

    int curIndex = 0;
    for (int curRow = 0; curRow < input.rows; curRow++) {
        //std::cout << curRow << std::endl << std::endl;
        for (int curCol = 0; curCol < input.cols; curCol++) {
            //std::cout << curIndex << " ";

            if (numComponents == 3) {
                setVals3D(outputPixels + curIndex, input.at<cv::Vec3b>(curRow, curCol));
                curIndex += 2;
            } else {
                outputPixels[curIndex] = input.at<uchar>(curRow, curCol);
            }
            curIndex++;
        }

    }
    return outputPixels;
}

/**
 * Return a vector of the next 3 values
 *
 * @param imgData stbi data to read from
 * @return Vector pixel equivalent
 */
cv::Vec3b getVecFromNextVals(const unsigned char *imgData) {
    auto first = imgData[2];
    auto second = imgData[1];
    auto third = imgData[0];
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
        output = cv::Mat(imgHeightPixels, imgWidthPixels, CV_8UC3); // 8U represents single unsigned integer
    } else {
        output = cv::Mat(imgHeightPixels, imgWidthPixels, CV_8U); // 8U represents 3 channel integers
    }

    int curIndex = 0;
    for (int curRow = 0; curRow < imgHeightPixels; curRow++) {
        for (int curCol = 0; curCol < imgWidthPixels; curCol++) { //go to the start of the last grouping
            //std::cout << curIndex << " ";
            if (numComponents == 3) {
                //std::cout << curRow << " " << curCol << "   ";
                output.at<cv::Vec3b>(curRow, curCol) = getVecFromNextVals(imgData + curIndex);
                curIndex += 3;
            } else {
                output.at<uchar>(curRow, curCol) = imgData[curIndex];
                curIndex += 1;
            }
        }
    }
    return output;
}
