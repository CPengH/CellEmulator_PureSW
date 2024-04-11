#ifndef EXCELREADER_H
#define EXCELREADER_H

#include <vector>
#include <string>

class ExcelReader {
public:
    static std::vector<std::pair<double, double>> readSocToOcvMap(const std::string& filepath);
};

#endif // EXCELREADER_H
