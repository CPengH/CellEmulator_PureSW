#ifndef CSVLOGGER_H
#define CSVLOGGER_H

#include "Logger.h"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

class CSVLogger : public Logger {
private:
    std::ofstream outFile;
public:
    CSVLogger(const std::string& filename) {
        outFile.open(filename, std::ios::app); // Append mode
        if (!outFile.is_open()) {
            std::cerr << "Failed to open log file for CSV Logger: " << filename << std::endl;
        } else {
            // Optionally write CSV header if file was empty/new
            outFile << "Timestamp,ocv,soc\n";
        }
    }

    ~CSVLogger() override {
        if (outFile.is_open()) {
            outFile.close();
        }
    }

    void log(const std::string& message) override {
        std::istringstream iss(message);

        std::string timestamp, ocv, soc;
        iss >> timestamp >> ocv >> soc;
        
        outFile << timestamp << "," << ocv << "," << soc << "\n";
    }
};

#endif // CSVLOGGER_H
