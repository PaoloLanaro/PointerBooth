//
// Created by David on 12/4/2023.
//

#ifndef FINALPROJECT_FILTER_H
#define FINALPROJECT_FILTER_H

#include <opencv2/core/mat.hpp>

/**
 * Represents a filter which applies an effect to a frame
 */
class Filter {
public:
    virtual void edit(cv::Mat &frame) = 0;
    virtual ~Filter() = default;
    static std::vector<std::string> getValidFilterNames() {
        return std::vector<std::string> {"contour", "pointillism", "gaussianblur", "glitch", "otsu", "pixelsort", "greyscale"};
    }
    static bool isValidName(std::string name) {
        std::vector<std::string> validNames = getValidFilterNames();
        return std::any_of(validNames.begin(), validNames.end(), [&name](const std::string &validName) {
            return validName == name;
        });
    }
};

#endif //FINALPROJECT_FILTER_H
