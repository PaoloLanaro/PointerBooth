//
// Created by dbusn on 12/7/2023.
//

#include "VideoEnvironment.h"
#include "Filter.h"

#include <wx/wx.h>

int main(int argc, char** argv) {
    std::vector<std::string> filters;
    filters.emplace_back("pointillism");
    filters.emplace_back("greyscale");
    VideoEnvironment video;
    video.startVideo(filters);
}