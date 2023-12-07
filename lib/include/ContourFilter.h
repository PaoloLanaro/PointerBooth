//
// Created by lanar on 12/6/2023.
//

#ifndef FINALPROJECT_CONTOURFILTER_H
#define FINALPROJECT_CONTOURFILTER_H

#include <opencv2/core/mat.hpp>
#include "Filter.h"

class ContourFilter : public Filter {
private:
    cv::Mat initialImage;
public:
    explicit ContourFilter(cv::Mat& ioFrame);
    // should only ever be executed with a cloned frame. This WILL mutate the param Matrix!!
    virtual void edit(cv::Mat& frame) override;
};

#endif //FINALPROJECT_CONTOURFILTER_H
