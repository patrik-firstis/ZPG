#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <unordered_map>
#include "../object/DrawableObject.h"
#include "../camera/Camera.h"
#include "../lights/DirectLight.h"
#include "../lights/PointLight.h"
#include "../lights/SpotLight.h"
#include "../shaderProgram/Shaders.h"
#include "../tranformations/Transformations.h"
#include "../models/ModelLib.h"


class Scene
{
protected:
	int windowHeight, windowWidth;
	Camera* camera;
  DrawableObject* skybox = nullptr;
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
  Camera* getCamera();
};

