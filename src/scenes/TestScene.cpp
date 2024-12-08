#include "TestScene.h"


void TestScene::init()
{


	auto shaderProgram = Shaders::Constant();
  auto shaderProgram2 = Shaders::Skybox();

	this->camera = new Camera(windowWidth, windowHeight, glm::vec3(0.0f, 1.0f, 5.0f));
	this->camera->addObserver(shaderProgram);
  this->camera->addObserver(shaderProgram2);

	this->objects["plain"] = new DrawableObject(Models::Triangle(), shaderProgram);

  this->skybox = new DrawableObject(Models::Skybox(), shaderProgram2);

}
