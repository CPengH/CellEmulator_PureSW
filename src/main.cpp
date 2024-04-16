#include <iostream>

#include "BatteryModel.h"
#include "TestSchedule.h"
#include "SimulationEngine.h"
#include "ExcelReader.h"
#include <vector>
#include <filesystem>

static void printHelp()
{
    std::cout << "Usage: cellEmulator.exe <path_to_spreadsheet_csv>" << std::endl;
}

int main(int argc, char* argv[])
{
    std::string filePath;

    if (argc == 1) {
        filePath = "../../inputExcel/DefaultSpreadSheet.csv";
    } else if (argc == 2) {
        filePath = argv[0];
    } else {
        printHelp();
        return 0;
    }

    // Step0. Load the spreadsheet
    std::vector<std::pair<double, double>> socToOcvPairs = ExcelReader::readSocToOcvMap(filePath);

    // Step1. Input the benchmark spreadsheet for the cell
    BatteryModel testModel(0, socToOcvPairs, 3500);
    testModel.displayBatteryParams();

    // Step2. Customize the test schedule
    TestSchedule schedule;
    schedule.addStep(TestStep(CONSTANT_CURRENT, 3.5, 3600, 100));
    schedule.addStep(TestStep(CONSTANT_CURRENT, -3.5, 3600, 100));
    schedule.addStep(TestStep(CONSTANT_VOLTAGE, 4.2, 7200, 100));
    
    // Step3. Run the simulation
    SimulationEngine simEng(testModel, schedule);
    simEng.runSimulation();
    
    testModel.displayBatteryParams();
    system("pause");
    return 0;
}