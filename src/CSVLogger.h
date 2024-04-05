#ifndef CSVLOGGER_H
#define CSVLOGGER_H

#include "Logger.h"
#include <fstream>
#include <string>
#include <iostream>

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
            outFile << "Timestamp,LogLevel,Message\n";
        }
    }

    ~CSVLogger() override {
        if (outFile.is_open()) {
            outFile.close();
        }
    }

    void log(const std::string& message) override {
        // Example log structure: "Timestamp,LogLevel,Message"
        // Adjust this to fit your actual logging needs
        std::string timestamp = getCurrentTimestamp(); // Implement this
        std::string logLevel = "INFO"; // This should be adjusted based on actual log level
        outFile << timestamp << "," << logLevel << ",\"" << message << "\"\n";
    }
    
    // Implement getCurrentTimestamp to return a string representation of the current timestamp
    std::string getCurrentTimestamp() {
        // Placeholder for timestamp implementation
        // This should return a string with the current time in your preferred format
        return "2023-01-01 00:00:00";
    }
};

#endif // CSVLOGGER_H
