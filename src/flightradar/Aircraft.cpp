#include "Aircraft.h"

Aircraft::Aircraft(char* owner, AircraftType& type, Location location)
	: owner(owner), type(type), location(location)
{
	this->altitude = 0;
	this->speed = 0;
	this->heading = 0;
}

char* Aircraft::get_owner()
{
	return this->owner;
}

AircraftType& Aircraft::get_type()
{
	return this->type;
}

Location Aircraft::get_location()
{
	return this->location;
}

void Aircraft::set_heading(double heading)
{
	this->heading = heading;
}

void Aircraft::move(int sec)
{
	auto telemetry = this->type.get_telemetry(sec);
	this->speed = telemetry.first;
	this->altitude = telemetry.second;
	//todo -> calc new location
}
