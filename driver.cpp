//
// Created by dbusn on 12/7/2023.
//

#include "VideoEnvironment.h"
#include "Filter.h"
#include "FilterPackManager.h"
#include <opencv2/core/mat.hpp>
#include <iostream>


int main(int argc, char** argv) {
    bool saveThisPack = false;
    bool openAPack = false;
    std::vector<std::string> filters;

    //parse command line args
    for (int curArg = 1; curArg < argc; curArg++) {
        //check for save or open args
        saveThisPack |= std::string(argv[curArg]) == "-s" || std::string(argv[curArg]) == "--save";
        openAPack |= std::string(argv[curArg]) == "-o" || std::string(argv[curArg]) == "--open";

        //validate and add filter to list
        if (Filter::isValidName(std::string(argv[curArg])))
            filters.emplace_back(argv[curArg]);
    }

    FilterPackManager fpm;
    if (openAPack)
        fpm.handleOpenDialogue(filters);
    if (saveThisPack)
        fpm.handleWriteDialogue(filters);


    //run the video
    VideoEnvironment video;
    video.startVideo(filters);
}