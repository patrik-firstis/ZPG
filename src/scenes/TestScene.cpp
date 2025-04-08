#include "TestScene.h"


void TestScene::init()
{
	auto shaderProgram = Shaders::Phong("test");
  auto shaderProgram2 = Shaders::Skybox("test");

	this->camera = new Camera(windowWidth, windowHeight, glm::vec3(0.0f, 1.0f, 5.0f));
	this->camera->addObserver(shaderProgram);
  this->camera->addObserver(shaderProgram2);

	Light* directLight = new DirectLight(0, glm::vec3(-1.0, -1.0, -1.0), 0.5);
	directLight->addObserver(shaderProgram);
	this->lights.push_back(directLight);
	this->objects["earth"] = new DrawableObject( ModelLib::Earth() /*ModelLib::Plain(MaterialLib::getMaterial("src/models/objects/earth/Flat_earth.jpg", glm::vec3(1.0), glm::vec3(1.0), glm::vec3(0.1), 16))*/, shaderProgram);
	auto plane = new DrawableObject(ModelLib::Plane(MaterialLib::Steel()), shaderProgram);
	plane->addTransform(Transformations::translate(0.0, 10.0, 0.0));
	plane->addTransform(Transformations::scale(10.0));
	
	this->objects["plane"] = plane;
  //this->skybox = new DrawableObject(ModelLib::Skybox(), shaderProgram2);
}
