#ifndef BATTERYMODEL_H
#define BATTERYMODEL_H
#include <vector>

class BatteryModel{
public:
	BatteryModel(double capacity, const std::vector<std::pair<double, double>>& socToOcvMap);
    double getSoc() const;
	double getVoltage() const;
	double getCurrent() const;
	double getCurrentCapacity() const;
    double getNominalCapacity() const;
    void setSoc(double newSoc);
    void setVoltage(double newVoltage);
    void setCurrent(double newCurrent);
    void setCurrentCapacity(double newCapacity);
	void displayBatteryParams() const;
	void initParams();

private:
	double soc;
	double voltage;
	double current;
    double nominalCapacity;
    double currentCapacity;
	bool isConnected;
    std::vector<std::pair<double, double>> socToOcvMap;
};

#endif