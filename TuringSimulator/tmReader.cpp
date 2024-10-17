#include "tmReader.h"

std::vector<std::string> readTM(std::string loc)
{

    std::ifstream readFile(loc);

    std::string temp;
    std::vector<std::string> lines = {};
    while (std::getline(readFile, temp)) {

        lines.push_back(temp);


    }

    return lines;
}
