#pragma once
#include <glm/vec2.hpp>
#include <string>

class Airport
{
private:
	double longitude;
	double latitude;

	int size;
	std::string code;

public:
	Airport(std::string code, double lon, double lat, int size = 5);

	double getLongitute();
	double getLatitute();
	std::string getCode();
	int getSize();
	double getDistanceTo(Airport* other);
	double getHeadingTo(Airport* other);
};

