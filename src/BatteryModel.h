#ifndef BATTERYMODEL_H
#define BATTERYMODEL_H
#include <vector>

class BatteryModel{
public:
	BatteryModel(double currentCapacity, const std::vector<std::pair<double, double>>& socToOcvMap, const double nominalCapacity);
    double getSoc() const;
<<<<<<< Updated upstream
	double getVoltage() const;
	double getCurrent() const;
	double getCurrentCapacity() const;
=======
    double getVoltage() const;
    double getCurrent() const;
    double getInternalR() const;
    double getCurrentCapacity() const;
>>>>>>> Stashed changes
    double getNominalCapacity() const;
    void setSoc(double newSoc);
    void setVoltage(double newVoltage);
    void setCurrent(double newCurrent);
    void setCurrentCapacity(double newCapacity);
	void displayBatteryParams() const;
	void initParams();
	std::vector<std::pair<double, double>> socToOcvMap;

private:
<<<<<<< Updated upstream
	double soc;
	double voltage;
	double current;
=======
    double soc;
    double voltage;
    double current;
    double internalR;
>>>>>>> Stashed changes
    double nominalCapacity;
    double currentCapacity;
	bool isConnected;
};

#endif