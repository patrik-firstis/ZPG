#pragma once
#include "Scene.h"
#include "../flightradar/Flight.h"

class TestScene : public Scene
{
private:
	 std::vector<Flight*> flights;
	 std::vector<Airport*> airports;
	 std::vector<Aircraft*> aircrafts;
	 
	 ShaderProgram* shaderProgram = nullptr;
	 bool trafficOn = false;

	 std::chrono::time_point<std::chrono::system_clock> lastDepartureTime;

	 void setupMap();
	 void generateAicrafts();
	 void checkLandings();
	 void addFlight();
	 void generateFlights();
	 Airport* randomAirport();

public:
	TestScene(int windowHeight, int windowWidth) : Scene(windowHeight, windowWidth) {};

	void init() override;
	void draw() override;
	void addAtc(glm::vec3 position);
	void switchTraffic();
};

