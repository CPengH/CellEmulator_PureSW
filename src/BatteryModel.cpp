#include "BatteryModel.h"

BatteryModel::BatteryModel(double capacity, double internalResistance)
	: capacity(capacity), internalResistance(internalResistance), soc(100), voltage(0), current(0) {
}

double BatteryModel::getVoltage() const {
	return voltage;
}

double BatteryModel::getCurrent() const {
	return current;
}