#pragma once
#include "Scene.h"

class ForestScene : public Scene
{
public:
	ForestScene(int windowHeight, int windowWidth) : Scene(windowHeight, windowWidth) {};

	void init() override;
	void generateTrees(int n, ShaderProgram* shaderProgram);
	void generateBushes(int n, ShaderProgram* shaderProgram);
};

