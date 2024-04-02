#ifndef SIMULATIONENGINE_H
#define SIMULATIONENGINE_H
#include "BatteryModel.h"
#include "TestSchedule.h"

class SimulationEngine
{
public:
    SimulationEngine(BatteryModel& model, TestSchedule& schedule);
    void runSimulation();

private:
    BatteryModel& batteryModel;
    TestSchedule& testSchedule;
    double getOcvBySoc(double soc);
};

#endif