//
// Created by lanar on 12/6/2023.
//

#ifndef FINALPROJECT_GRAYSCALEFILTER_H
#define FINALPROJECT_GRAYSCALEFILTER_H

#include "Filter.h"

class GrayScaleFilter : public Filter {
public:
    // should only ever be run with a cloned frame. This WILL mutate the param Matrix!!
    virtual void edit(cv::Mat &frame) override;
};

#endif //FINALPROJECT_GRAYSCALEFILTER_H
