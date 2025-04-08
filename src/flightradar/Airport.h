#pragma once
#include <utility>

using Location = std::pair<double, double>;

class Airport
{
private:
	char* name;
	Location location;
public:
	Airport(char* name, double lat, double lon);
	char* get_name();
	Location get_location();
};

