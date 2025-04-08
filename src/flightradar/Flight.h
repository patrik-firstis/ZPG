#pragma once
#include "Airport.h"
#include "Aircraft.h"

class Flight
{
private:
	Airport departurePort;
	Airport destinationPort;
	Aircraft aircraft;
	time_t departureTime;
	time_t arrivalTime;
	int currentFlightTime;
public:
	Flight(Airport&, Airport&, Aircraft&, time_t, time_t);
	void update();
	void calc_heading();
};

