#pragma once
#include <utility>
class AircraftType
{
private:
	char* model;
	double cruiseSpeed;
	double cruiseAltitude;
	double acceleration;
	double climbrate;
public:
	AircraftType(char* model, double cruiseSpeed, double cruiseAltitude, double acceleration, double climbrate);
	char* get_model();
	std::pair<double, double> get_telemetry(int sec);
};

