#include <iostream>

#include "BatteryModel.h"
#include "TestSchedule.h"
#include "SimulationEngine.h"
#include "FileLogger.h"
#include <vector>

int main()
{
    // Step1. Input the benchmark spreadsheet for the cell
    BatteryModel testModel(0, { { 0, 3.0 }, { 10, 3.5 }, { 20, 3.6 }, { 30, 3.65 }, { 40, 3.7 },
        { 50, 3.75 }, { 60, 3.8 }, { 70, 3.85 }, { 80, 3.9 }, { 90, 4.0 }, { 100, 4.2 } }, 3500);
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