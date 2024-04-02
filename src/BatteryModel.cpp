#include "BatteryModel.h"
#include <iostream>
#include <iomanip>
#include <vector>

#define DISPLAY_OFFSET 7

BatteryModel::BatteryModel(double currentCapacity, const std::vector<std::pair<double, double>>& socToOcvMap)
	: currentCapacity(currentCapacity), soc(100), voltage(0), current(0), isConnected(false), nominalCapacity(3500), socToOcvMap(socToOcvMap) {
    initParams();
}

double BatteryModel::getVoltage() const { return voltage; }

double BatteryModel::getCurrent() const { return current; }

double BatteryModel::getCurrentCapacity() const { return currentCapacity; }

double BatteryModel::getNominalCapacity() const { return nominalCapacity; }

double BatteryModel::getSoc() const { return soc; }

void BatteryModel::setSoc(double newSoc) {soc = newSoc;}

void BatteryModel::setVoltage(double newVoltage) {voltage = newVoltage;}

void BatteryModel::setCurrent(double newCurrent) {current = newCurrent;}

void BatteryModel::setCurrentCapacity(double newCapacity) {currentCapacity = newCapacity;}

void BatteryModel::initParams() {
    soc = currentCapacity / nominalCapacity * 100;
}

void BatteryModel::displayBatteryParams() const { 
    std::cout << std::right
            << "-----------------------" << "\n"
            << "Capacity: " << std::setw(DISPLAY_OFFSET) << getCurrentCapacity() << " Ah\n"
            << "SOC     : " << std::setw(DISPLAY_OFFSET) << getSoc() << " %\n"
            << "Voltage : " << std::setw(DISPLAY_OFFSET) << getVoltage() << " V\n"
            << "Current : " << std::setw(DISPLAY_OFFSET) << getCurrent() << " A\n"
            << "Nominal : " << std::setw(DISPLAY_OFFSET) << getNominalCapacity() << " A\n"
            << "-----------------------" << "\n";
}