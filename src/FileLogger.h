#ifndef FILELOGGER_H
#define FILELOGGER_H

#include "Logger.h"
#include <fstream>
#include <iostream>

class FileLogger : public Logger {
private:
    std::ofstream logFile;

public:
    FileLogger(const std::string& filePath) {
        logFile.open(filePath, std::ofstream::out | std::ofstream::app);
        if (!logFile.is_open()) {
            std::cerr << "Failed to open log file: " << filePath << std::endl;
        }
    }

    ~FileLogger() {
        if (logFile.is_open()) {
            logFile.close();
        }
    }

    void log(const std::string& message) override {
        if (logFile.is_open()) {
            logFile << message << std::endl;
        }
    }
};

#endif // FILELOGGER_H