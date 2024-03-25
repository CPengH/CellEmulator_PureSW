#include <iostream>

#include "BatteryModel.h"
#include "TestSchedule.h"

int main()
{
    BatteryModel testModel(3500, 0);
    std::cout << "Current: " << testModel.getCurrent() << std::endl;
    std::cout << "Voltage: " << testModel.getVoltage() << std::endl;

    system("pause");
    return 0;
}