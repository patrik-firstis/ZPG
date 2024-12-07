#include "TestScene.h"


void TestScene::init()
{
	const float triangle[18] = {
		-1.0f , 1.0f , 0.0f , 0.0f , 0.0f , 1.0f ,
		1.0f , 1.0f , 0.0f , 0.0f , 0.0f , 1.0f ,
		0.0f , 2.0f , 0.0f , 0.0f , 0.0f , 1.0f ,
	};

	ShaderProgram* shaderProgram = new ShaderProgram("default_vert.glsl","default_frag.glsl");
	this->camera = new Camera(windowWidth, windowHeight, glm::vec3(0.0f, 1.0f, 5.0f));
	this->camera->addObserver(shaderProgram);

	this->objects["plain"] = new DrawableObject(new Model(triangle, sizeof(triangle)), shaderProgram);
}
