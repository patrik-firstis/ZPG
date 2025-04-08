#pragma once
#include "AircraftType.h"

using Location = std::pair<double, double>;

class Aircraft
{
private:
	char* owner;
	AircraftType type;
	Location location;
	double speed;
	double altitude;
	double heading;
public:
	Aircraft(char* owner, AircraftType& type, Location location);
	char* get_owner();
	AircraftType& get_type();
	Location get_location();
	void set_heading(double);
	void move(int sec);
};

