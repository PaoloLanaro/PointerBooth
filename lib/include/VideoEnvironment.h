//
// Created by dbusn on 12/7/2023.
//

#ifndef FINALPROJECT_VIDEOENVIRONMENT_H
#define FINALPROJECT_VIDEOENVIRONMENT_H


#include "Filter.h"

/**
 * VideoEnvironment represents the associated data with a video scene
 */
class VideoEnvironment {
private:
    void applyFilters(cv::Mat&, std::vector<std::string>);
public:
    void startVideo(const std::vector<std::string>&);
    void startExamples();
};


#endif //FINALPROJECT_VIDEOENVIRONMENT_H
