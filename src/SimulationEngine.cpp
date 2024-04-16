#include "SimulationEngine.h"
#include "CSVLogger.h"

SimulationEngine::SimulationEngine(BatteryModel& model, TestSchedule& schedule)
    :batteryModel(model), testSchedule(schedule), scheduleTime(0) 
    {
        logger = std::make_unique<CSVLogger>("log.csv");
    }

void SimulationEngine::runSimulation()
{
<<<<<<< Updated upstream
    std::unique_ptr<Logger> logger = std::make_unique<CSVLogger>("log.csv");

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

        double ocv = getOcvBySoc(soc);
        //std::cout << "SOC: " << soc << " OCV: " << ocv << std::endl;
        logger->log(std::to_string(currentTime) + " " + std::to_string(ocv) + " " + std::to_string(soc));
=======
    while (testSchedule.hasNextStep()) {
        TestStep step = testSchedule.nextStep();
        executeStep(step);
>>>>>>> Stashed changes
    }
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

void SimulationEngine::executeStep(TestStep step)
{
    double capacity = batteryModel.getCurrentCapacity();
    double soc = batteryModel.getSoc();

    ControlType controlType = step.controlType;
    double controlValue = step.value;
    double duration = step.duration;
    const double interval = step.logInterval;

    logger->log(std::to_string(scheduleTime) + " " + std::to_string(getOcvBySoc(soc)) + " " + std::to_string(soc));

    double prevTime = 0.0;
    for (double currentTime = interval; currentTime <= duration; currentTime += interval) {
        double current = 0.0;
        switch (controlType)
        {
        case CONSTANT_VOLTAGE:
            current = (controlValue - getOcvBySoc(soc)) / batteryModel.getInternalR();
            break;
        
        case CONSTANT_CURRENT:
            current = controlValue;
            break;

        default:
            break;
        }

        capacity += (current * (currentTime - prevTime) / 3600 * 1000);
        prevTime = currentTime;
        batteryModel.setCurrentCapacity(capacity);
        soc = capacity/batteryModel.getNominalCapacity()*100;
        batteryModel.setSoc(soc);

        double ocv = getOcvBySoc(soc);
        
        scheduleTime += interval;
        logger->log(std::to_string(scheduleTime) + " " + std::to_string(ocv) + " " + std::to_string(soc));
    }
}