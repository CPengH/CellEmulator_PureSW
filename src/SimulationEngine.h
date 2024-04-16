#ifndef SIMULATIONENGINE_H
#define SIMULATIONENGINE_H
#include "BatteryModel.h"
#include "TestSchedule.h"
#include "CSVLogger.h"
#include <iostream>

class SimulationEngine
{
public:
    SimulationEngine(BatteryModel& model, TestSchedule& schedule);
    void runSimulation();
    void executeStep(TestStep step);

private:
    BatteryModel& batteryModel;
    TestSchedule& testSchedule;
    std::unique_ptr<Logger> logger;
    double scheduleTime;
    double getOcvBySoc(double soc);
};

#endif