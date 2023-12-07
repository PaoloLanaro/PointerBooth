//
// Created by dbusn on 12/7/2023.
//

#ifndef FINALPROJECT_FILTERPACKMANAGER_H
#define FINALPROJECT_FILTERPACKMANAGER_H


#include <string>
#include <vector>

class FilterPackManager {
public:
    void saveFilterPack(const std::string&, const std::string&, std::vector<std::string>);
    std::vector<std::string> readFilterPack(const std::string&);
    void handleWriteDialogue(std::vector<std::string>);
    void handleOpenDialogue(std::vector<std::string>&);
};


#endif //FINALPROJECT_FILTERPACKMANAGER_H
