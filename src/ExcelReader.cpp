#include "ExcelReader.h"
#include <fstream>
#include <sstream>
#include <iostream>

void skipBOM(std::ifstream &file) {
    char checkBOM[3] = {0};
    file.read(checkBOM, 3);
    if (!(checkBOM[0] == (char)0xEF && checkBOM[1] == (char)0xBB && checkBOM[2] == (char)0xBF)) {
        // If the file does not start with the BOM, move the cursor back to the beginning.
        file.seekg(0);
    }
}

std::vector<std::pair<double, double>> ExcelReader::readSocToOcvMap(const std::string& filepath) {
    std::vector<std::pair<double, double>> socToOcvMap;

    std::ifstream file(filepath);

    // Check if the file was successfully opened
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filepath << std::endl;
    }

    skipBOM(file);
    
    std::string line;

    // Read the file line by line
    while (getline(file, line)) {
        std::stringstream lineStream(line);
        std::string cell;
        double firstValue, secondValue;

        // Get the first value
        if (getline(lineStream, cell, ',')) {
            firstValue = std::stod(cell);
        } else {
            continue; // Skip to the next line if parsing failed
        }

        // Get the second value
        if (getline(lineStream, cell, ',')) {
            secondValue = std::stod(cell);
        } else {
            continue; // Skip to the next line if parsing failed
        }

        // Add the parsed values to the vector
        socToOcvMap.push_back(std::make_pair(firstValue, secondValue));
    }

    file.close(); // Close the file

    return socToOcvMap;
}
