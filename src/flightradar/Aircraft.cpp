#include "Aircraft.h"

Aircraft::Aircraft(std::string code, int topSpeed) {
	this->topSpeed = topSpeed;
	this->code = code;
}

int Aircraft::getSpeed() {
	return this->topSpeed;
}

std::string Aircraft::getCode() {
	return this->code;
}

void Aircraft::setCurrentAirport(Airport* airport) {
	this->currentAirport = airport;
}

Airport* Aircraft::getCurrentAirport() {
	return this->currentAirport;
}