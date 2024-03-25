class BatteryModel{
public:
	BatteryModel(double capacity, double internalResistance);
	double getVoltage() const;
	double getCurrent() const;

private:
	double soc;
	double capacity;
	double internalResistance;
	double voltage;
	double current;
	bool isConnected;
};
