//
// Created by lanar on 12/6/2023.
//

#ifndef FINALPROJECT_OTSUTHRESHOLDINGFILTER_H
#define FINALPROJECT_OTSUTHRESHOLDINGFILTER_H

#include "MatrixFilter.h"

class OtsuThresholdingFilter : public MatrixFilter {
public:
    // should only ever be executed with a cloned frame. This WILL mutate the param Matrix!!
    virtual void edit(cv::Mat& frame) override;
};

#endif //FINALPROJECT_OTSUTHRESHOLDINGFILTER_H
