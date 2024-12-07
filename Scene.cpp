#include "Scene.h"


Scene::Scene(int windowHeight, int windowWidth) {
	this->windowHeight = windowHeight;
	this->windowWidth = windowWidth;	
}

Scene::~Scene() {
	for (auto& object : this->objects) {
		delete object.second;
	}
}

void Scene::draw() {
	camera->updateMatrices();
	for (auto& light : this->lights) {
		light->draw();
	}
	for (auto& object : this->objects) {
		object.second->draw();
	}
}

void Scene::moveCamera(int key)
{
	camera->handleMovement(key);
}

void Scene::lookCamera(float deltaX, float deltaY)
{
	camera->handleMouseMovement(deltaX, deltaY);
}

void Scene::updatePerspective(int width, int height)
{
	camera->updatePerspective(width, height);
}
