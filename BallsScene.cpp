#include "BallsScene.h"
#include "ShaderProgram.h"
#include "VertexShader.h"
#include "FragmentShader.h"
#include "Transformations.h"
#include "Camera.h"
#include "sphere.h"
#include "Light.h"
#include "tree.h"
#include <glm/vec3.hpp> 
#include <glm/vec4.hpp> 
#include <glm/mat4x4.hpp> 
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtc/type_ptr.hpp> 

void BallsScene::init()
{
	auto phongShader = Shaders::Phong();
	auto constantShader = Shaders::Constant();

	auto camera = new Camera(this->windowWidth, this->windowHeight, glm::vec3(0.0f, 5.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f));
	camera->addObserver(phongShader);
	camera->addObserver(constantShader);

	auto light = new PointLight(0, 1.0, glm::vec3(1.0, 1.0, 0.0));
	light->addObserver(phongShader);

	this->camera = camera;
	this->lights.push_back(light);

	this->objects["sun"] = new DrawableObject(new Model(sphere, sizeof(sphere), glm::vec3(1.0,1.0,0.0)), constantShader);
	this->objects["sun"]->addTransform(Transformations::scale(0.5));

	this->objects["ball1"] = new DrawableObject(new Model(sphere, sizeof(sphere)), phongShader);
	this->objects["ball1"]->addTransform(Transformations::translate(2.0, 0.0, 2.0));
	this->objects["ball1"]->addTransform(Transformations::rotateY(10.0, -1));
	this->objects["ball2"] = new DrawableObject(new Model(sphere, sizeof(sphere)), phongShader);
	this->objects["ball2"]->addTransform(Transformations::translate(2.0, 0.0, -2.0));
	this->objects["ball3"] = new DrawableObject(new Model(sphere, sizeof(sphere)), phongShader);
	this->objects["ball3"]->addTransform(Transformations::translate(-2.0, 0.0, -2.0));
	this->objects["ball4"] = new DrawableObject(new Model(sphere, sizeof(sphere)), phongShader);
	this->objects["ball4"]->addTransform(Transformations::translate(-2.0, 0.0, 2.0));
}

