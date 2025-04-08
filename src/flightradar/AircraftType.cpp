#include "AircraftType.h"


AircraftType::AircraftType(char* model, double cruiseSpeed, double cruiseAltitude, double acceleration, double climbrate)
	: model(model), cruiseSpeed(cruiseSpeed), cruiseAltitude(cruiseAltitude), acceleration(acceleration), climbrate(climbrate)
{
}

char* AircraftType::get_model()
{
	return this->model;
}

std::pair<double, double> AircraftType::get_telemetry(int sec)
{
	double speed = std::min(sec * this->acceleration, cruiseSpeed);
	double altitude = std::min(sec * this->climbrate, cruiseAltitude);
	return std::make_pair(speed, altitude);
}




