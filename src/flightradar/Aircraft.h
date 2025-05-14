#pragma once
#include "Airport.h"
#include <string>

class Aircraft
{
private:
	int topSpeed;
	std::string code;
	Airport* currentAirport;

public:
	Aircraft(std::string code, int topSpeed = 650);
	
	void setCurrentAirport(Airport* airport);
	Airport* getCurrentAirport();
	int getSpeed();
	std::string getCode();
};

