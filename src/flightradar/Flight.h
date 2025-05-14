#pragma once
#include "Aircraft.h"
#include "Airport.h"
#include <chrono>


class Flight
{
private:
	Aircraft* aircraft;
	Airport* origin;
	Airport* destination;
	std::chrono::time_point<std::chrono::system_clock> landingTime;

public:
	Flight(Aircraft* aircraft, Airport* origin, Airport* destination);

	double getFlightTime();
	double getFlightDistance();
	double getHeading();
	bool hasLanded();

	Aircraft* getAircraft();
	Airport* getOrigin();
	Airport* getDestination();
};

