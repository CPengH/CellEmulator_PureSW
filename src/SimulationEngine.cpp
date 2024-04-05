#include "SimulationEngine.h"
#include "CSVLogger.h"
#include <iostream>

SimulationEngine::SimulationEngine(BatteryModel& model, TestSchedule& schedule)
    :batteryModel(model), testSchedule(schedule) {}

void SimulationEngine::runSimulation()
{
    std::unique_ptr<Logger> logger = std::make_unique<CSVLogger>("log.csv");

    logger->log("Application started");

    double capacity = batteryModel.getCurrentCapacity();
    TestStep step = testSchedule.nextStep();

    double duration = step.duration;
    double current = step.value;
    const double interval = 100.0;

    double prevTime = 0.0;
    for (double currentTime = 0; currentTime <= duration; currentTime += interval) {
        double soc = batteryModel.getSoc();
        
        capacity += (current * (currentTime - prevTime) / 3600 * 1000);
        prevTime = currentTime;
        batteryModel.setCurrentCapacity(capacity);
        soc = capacity/batteryModel.getNominalCapacity()*100;
        batteryModel.setSoc(soc);

        double vol = getOcvBySoc(soc);
        std::cout << "SOC: " << soc << " OCV: " << vol << std::endl;
        //logger->log("SOC = " + std::to_string(vol) + " Time = " + std::to_string(currentTime));
        logger->log(std::to_string(vol));
    }

    logger->log("Application terminated");
}

double SimulationEngine::getOcvBySoc(double soc)
{
    for (int i = 0; i < batteryModel.socToOcvMap.size(); i++)
    {
        if (batteryModel.socToOcvMap[i].first > soc)
        {
            double prevSoc = batteryModel.socToOcvMap[i - 1].first;
            double prevVol = batteryModel.socToOcvMap[i - 1].second;
            double nxtSoc = batteryModel.socToOcvMap[i].first;
            double nxtVol = batteryModel.socToOcvMap[i].second;
            return (soc - prevSoc) / (nxtSoc - prevSoc) * (nxtVol - prevVol) + prevVol;
        }
    }
}