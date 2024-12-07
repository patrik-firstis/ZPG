#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <unordered_map>
#include "DrawableObject.h"
#include "Camera.h"
#include "SpotLight.h"
#include "PointLight.h"
#include "DirectLight.h"
#include "Shaders.h"

class Scene
{
protected:
	int windowHeight, windowWidth;
	Camera* camera;
	std::unordered_map<std::string, DrawableObject*> objects;
	std::vector<Light*> lights;

public:
	Scene(int windowHeight, int windowWidth);
	~Scene();
	void draw();
	virtual void init() = 0;
	void moveCamera(int key);
	void lookCamera(float deltaX, float deltaY);
	void updatePerspective(int width, int height);
};

