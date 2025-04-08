#include "Airport.h"

Airport::Airport(char* name, double lat, double lon) : name(name), location(std::make_pair(lat, lon))
{
}

char* Airport::get_name()
{
	return this->name;
}

Location Airport::get_location()
{
	return this->location;
}
