#include "Airport.h"
#define M_PI 3.14159265358979323846


Airport::Airport(std::string code, double lon, double lat, int size) {
	this->longitude = lon;
	this->latitude = lat;

	this->size = size % 11;
	this->code = code;
}

double Airport::getLongitute() {
	return this->longitude;
}

double Airport::getLatitute() {
	return this->latitude;
}

std::string Airport::getCode() {
	return this->code;
}

int Airport::getSize() {
	return this->size;
}

double Airport::getDistanceTo(Airport* other) {
	double lat1 = this->latitude;
	double lon1 = this->longitude;
	double lat2 = other->latitude;
	double lon2 = other->longitude;
	
	double square = pow(abs(lat1 - lat2), 2) + pow(abs(lon1 - lon2), 2);
	return pow(square, 0.5);
}

double Airport::getHeadingTo(Airport* other) {
	double lat1 = this->latitude;
	double lon1 = this->longitude;
	double lat2 = other->latitude;
	double lon2 = other->longitude;
	double heading = atan2(lat2 - lat1, lon2 - lon1);
	double headingDeg = heading * 180.0 / M_PI;

	// Normalize to [0, 360)
	if (headingDeg < 0) {
		headingDeg += 360.0;
	}

	return headingDeg;
}