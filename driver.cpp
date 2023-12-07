//
// Created by dbusn on 12/7/2023.
//

#include "VideoEnvironment.h"
#include "Filter.h"

int main(int argc, char** argv) {
    std::vector<std::string> filters;
    for (int curArg = 1; curArg < argc; curArg++)
        filters.emplace_back(argv[curArg]);
    VideoEnvironment video;
    video.startVideo(filters);
}