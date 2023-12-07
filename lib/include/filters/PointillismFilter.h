//
// Created by dbusn on 12/7/2023.
//

#ifndef FINALPROJECT_POINTILLISMFILTER_H
#define FINALPROJECT_POINTILLISMFILTER_H

#include "Filter.h"
#include "MatAdapter.h"
#include "Image.h"
#include "Editor.h"

class PointillismFilter : public Filter {
public:
    virtual void edit(cv::Mat& frame) override {
        //ADAPTER TEST
        MatAdapter convert;
        unsigned char* data = convert.convertToStbiArray(frame, 3);
        Image imgver(data, frame.rows, frame.cols, 3);
        Editor edit(imgver);
        edit.pointillism();
        frame = convert.convertToMatrix(imgver.flatten(), 3, imgver.getWidth(), imgver.getHeight());
    };
};

#endif //FINALPROJECT_POINTILLISMFILTER_H

