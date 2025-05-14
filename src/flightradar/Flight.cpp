#include "Flight.h"

Flight::Flight(Aircraft* aircraft, Airport* origin, Airport* destination)
{
	this->aircraft = aircraft;
	this->origin = origin;
	this->destination = destination;
}

double Flight::getFlightTime()
{
	double distance = this->origin->getDistanceTo(this->destination);
	double speed = this->aircraft->getSpeed();
	double seconds = distance / speed * 1000;

	this->landingTime = std::chrono::system_clock::now() + std::chrono::seconds((long long)seconds);

	return seconds;
}

double Flight::getFlightDistance()
{
	return this->origin->getDistanceTo(this->destination);
}

double Flight::getHeading()
{
	return this->origin->getHeadingTo(this->destination);
}

bool Flight::hasLanded()
{
	auto now = std::chrono::system_clock::now();
	return now >= this->landingTime;
}

Aircraft* Flight::getAircraft()
{
	return this->aircraft;
}

Airport* Flight::getOrigin()
{
	return this->origin;
}

Airport* Flight::getDestination()
{
	return this->destination;
}