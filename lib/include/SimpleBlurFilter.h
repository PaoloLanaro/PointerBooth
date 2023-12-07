//
// Created by lanar on 12/6/2023.
//

#ifndef FINALPROJECT_SIMPLEBLURFILTER_H
#define FINALPROJECT_SIMPLEBLURFILTER_H

#include "MatrixFilter.h"

class SimpleBlurFilter : public MatrixFilter {
public:
    // should only ever be executed with a cloned frame. This WILL mutate the param Matrix!!
    virtual void edit(cv::Mat& frame) override;
};

#endif //FINALPROJECT_SIMPLEBLURFILTER_H
