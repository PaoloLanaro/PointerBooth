//
// Created by dbusn on 12/7/2023.
//

#include "FilterPackManager.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
#include <utility>

using json = nlohmann::json;

const std::vector<std::string> FILTER_NAMES {"contour", "pointillism", "gaussianblur", "glitch", "otsu", "pixelsort", "greyscale"};

/**
 * Linear search for param
 *
 * @param toFind string to search for
 * @param values vector to search in
 * @return Presence in vector
 */
bool valInVector(std::vector<std::string> values, std::string toFind) {
    return std::any_of(values.begin(), values.end(), [&toFind](const std::string& current) {
        return current == toFind;
    });
}

/**
 * Save a json filter pack with the provided list of filters
 *
 * @param name Name of filter pack
 * @param outputPath Path to output json
 * @param inputVals Filters to include
 */
void FilterPackManager::saveFilterPack(const std::string& name, const std::string& outputPath,
                                       std::vector<std::string> inputVals) {
    json j;
    j["pack-name"] = name;
    for (const std::string& filterName : FILTER_NAMES) {
        j[filterName] = valInVector(inputVals, filterName);
    }

    //output the json file
    std::ofstream output(outputPath);
    if (output.is_open()) {
        output << j;
        output.close();
        std::cout << "output!";
    } else {
        std::cerr << "Could not output.";
    }
}

/**
 * Open the filter pack at the provided location and read in its information
 *
 * @return vector of pack data
 */
std::vector<std::string> FilterPackManager::readFilterPack(const std::string& path) {
    json data;
    std::ifstream reader(path);
    std::vector<std::string> output;
    if (reader.is_open()) {
        data = json::parse(reader);
    }
    for (json::iterator iter = data.begin(); iter != data.end(); iter++) {
        std::string curKey = iter.key();
        if (curKey != "pack-name") {
            if (data[curKey])
                output.push_back(curKey);
        }
    }
    return output;
}

/**
 * Handle the dialogue for outputting a configuration file
 *
 * @param filters filters to jsonify
 */
void FilterPackManager::handleWriteDialogue(std::vector<std::string> filters) {
    std::cout << "Save this pack!" << std::endl << "Please enter a name for your pack:";
    std::string packName;
    std::cin >> packName;
    std::cout << "Please enter the directory you would like to save it in [type '.' for working directory]: ";
    std::string directory;
    std::cin >> directory;
    directory = directory == "." ? "" : directory;
    directory += packName + ".json";
    this->saveFilterPack(packName, directory, std::move(filters));
    std::cout << "Successfully saved!";
}

/**
 * Handle diaogue for inputting a configuration file
 *
 * @param filters output variable for filter list
 */
void FilterPackManager::handleOpenDialogue(std::vector<std::string>& filters) {
    std::cout << "Open a FilterPack!" << std::endl << "Please enter the directory of the FilterPack .json file: ";
    std::string inputPath;
    std::cin >> inputPath;
    filters = this->readFilterPack(inputPath);
}
