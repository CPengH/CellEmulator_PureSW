#include <iostream>

#include "BatteryModel.h"
#include "TestSchedule.h"
#include "SimulationEngine.h"
#include <vector>

int main()
{
    BatteryModel testModel(0, { { 0, 3.0 }, { 10, 3.5 }, { 20, 3.6 }, { 30, 3.65 }, { 40, 3.7 },
        { 50, 3.75 }, { 60, 3.8 }, { 70, 3.85 }, { 80, 3.9 }, { 90, 4.0 }, { 100, 4.2 } });
    testModel.displayBatteryParams();

    TestSchedule schedule;
    schedule.addStep(TestStep(CONSTANT_CURRENT, 3.5, 3600));
    
    SimulationEngine simEng(testModel, schedule);
    simEng.runSimulation();
    
    testModel.displayBatteryParams();
    system("pause");
    return 0;
}