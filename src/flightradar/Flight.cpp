#include "Flight.h"
#include <cmath>
#define M_PI 3.14159265358979323846 

static double rad(double deg) { return (deg * M_PI / 180); }
static double deg(double rad) { return (rad * 180 / M_PI); }

Flight::Flight(Airport& departurePort, Airport& destinationPort, Aircraft& aircraft, time_t departureTime, time_t arrivalTime)
	: departurePort(departurePort), destinationPort(destinationPort), aircraft(aircraft), departureTime(departureTime), arrivalTime(arrivalTime)
{
	this->currentFlightTime = 0;
}

void Flight::update()
{
	this->currentFlightTime++;
	this->aircraft.move(this->currentFlightTime);
}

void Flight::calc_heading()
{
  double lat1 = this->departurePort.get_location().first;
  double lat2 = this->destinationPort.get_location().first;
  double lon1 = this->departurePort.get_location().second;
  double lon2 = this->destinationPort.get_location().second;

  double teta1 = rad(lat1);
  double teta2 = rad(lat2);
  double delta1 = rad(lat2 - lat1);
  double delta2 = rad(lon2 - lon1);


  float y = std::sin(delta2) * std::cos(teta2);
  float x = std::cos(teta1) * std::sin(teta2) - std::sin(teta1) * std::cos(teta2) * std::cos(delta2);
  float hdng = atan2(y, x);
  hdng = deg(hdng);
  hdng = (((int)hdng + 360) % 360);

  this->aircraft.set_heading(hdng);
}
