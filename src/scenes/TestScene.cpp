#include "TestScene.h"


void TestScene::init()
{
	setupMap();
	generateAicrafts();
}

void TestScene::setupMap() {
	this->shaderProgram = Shaders::Phong("test");

	this->camera = new Camera(windowWidth, windowHeight, glm::vec3(0.0f, 10.0f, 0.0f));
	this->camera->addObserver(this->shaderProgram);

	Light* directLight = new DirectLight(0, glm::vec3(-1.0, -1.0, -1.0), 1);
	directLight->addObserver(this->shaderProgram);
	this->lights.push_back(directLight);

	this->objects["earth"] = new DrawableObject(ModelLib::Earth(), this->shaderProgram);
}

void TestScene::draw() {
	Scene::draw();
	generateFlights();
	checkLandings();
}


void TestScene::addAtc(glm::vec3 position) {
	auto translation = Transformations::translate(position);
	auto atc = new DrawableObject(ModelLib::Atc(), this->shaderProgram);
	atc->addTransform(translation);
	atc->addTransform(Transformations::rotateX(270));
	atc->addTransform(Transformations::scale(0.0004));

	std::string code = "atc" + std::to_string(this->objects.size());
	Airport* airport = new Airport(code, position.x, position.z, rand() % 10 + 1);
	this->airports.push_back(airport);
	this->objects[code] = atc;
}

void TestScene::switchTraffic() {
	this->trafficOn = true;
}

void TestScene::checkLandings() {
	for (auto it = this->flights.begin(); it != this->flights.end(); ) {
		Flight* flight = *it;

		if (flight->hasLanded()) {
			auto aircraft = flight->getAircraft();
			aircraft->setCurrentAirport(flight->getDestination());
			this->aircrafts.push_back(aircraft);
			this->objects.erase(flight->getAircraft()->getCode());

			it = this->flights.erase(it);
		}
		else {
			++it;
		}
	}

}
void TestScene::addFlight() {
	int index = rand() % this->aircrafts.size();
	Aircraft* aircraft = this->aircrafts[index];
	this->aircrafts.erase(this->aircrafts.begin() + index);

	if (!aircraft->getCurrentAirport()) {
		aircraft->setCurrentAirport(randomAirport());
	}
	Airport* origin = aircraft->getCurrentAirport();
	Airport* destination = nullptr;
	while (!destination || origin == destination)
		destination = randomAirport();


	
	Flight* flight = new Flight(aircraft, origin, destination);
	this->flights.push_back(flight);

	auto plane = new DrawableObject(ModelLib::Plane(MaterialLib::Steel()), this->shaderProgram);
	plane->addTransform(Transformations::translate(origin->getLongitute(), 2, origin->getLatitute()));
	plane->addTransform(Transformations::rotateX(270));
	plane->addTransform(Transformations::rotateZ(180));
	
	plane->addTransform(Transformations::rotateZ(- flight->getHeading()));

	plane->addTransform(Transformations::translateX(- flight->getFlightDistance(), flight->getFlightTime()));
	plane->addTransform(Transformations::scale(0.2));

	this->objects[aircraft->getCode()] = plane;
}

Airport* TestScene::randomAirport() {
	Airport* airport = nullptr;
	while (!airport) {
		int index = rand() % this->airports.size();

		airport = this->airports[index];
	}
	
	return airport;
}

void TestScene::generateFlights() {
	if (this->trafficOn && this->aircrafts.size()) {
		auto now = std::chrono::system_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::seconds>(now - this->lastDepartureTime);
		if (duration.count() > 1) {
			addFlight();
			this->lastDepartureTime = now;
		}
	}
}

void TestScene::generateAicrafts() {
	for (int i = 0; i < 30; i++) {
		std::string code = "A" + std::to_string(i);
		Aircraft* aircraft = new Aircraft(code, rand() % 1000 + 500);
		this->aircrafts.push_back(aircraft);
	}

}