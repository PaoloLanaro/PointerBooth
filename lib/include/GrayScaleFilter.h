//
// Created by lanar on 12/6/2023.
//

#ifndef FINALPROJECT_GRAYSCALEFILTER_H
#define FINALPROJECT_GRAYSCALEFILTER_H

#include "Filter.h"

class GrayScaleFilter : public Filter {
    virtual void edit(cv::Mat* frame) override;
};

#endif //FINALPROJECT_GRAYSCALEFILTER_H
