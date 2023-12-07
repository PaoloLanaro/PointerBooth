//
// Created by lanar on 12/6/2023.
//
#include "ContourFilter.h"
#include<opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

void ContourFilter::edit(Mat &frame) {
    if (frame.channels() != 1) {
        return;
    }

    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(frame, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_NONE);

    drawContours(initialImage, contours, -1, Scalar(0, 0, 255), 2);
}

ContourFilter::ContourFilter(Mat &ioFrame) {
    this->initialImage = ioFrame;
}

