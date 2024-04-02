#include "SimulationEngine.h"
#include <iostream>

SimulationEngine::SimulationEngine(BatteryModel& model, TestSchedule& schedule)
    :batteryModel(model), testSchedule(schedule) {}

void SimulationEngine::runSimulation()
{
    double capacity = batteryModel.getCurrentCapacity();
    TestStep step = testSchedule.nextStep();
    capacity += (step.value * step.duration / 3600 * 1000);
    batteryModel.setCurrentCapacity(capacity);
    batteryModel.setSoc(capacity/batteryModel.getNominalCapacity()*100);
}