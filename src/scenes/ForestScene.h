#pragma once
#include "Scene.h"

class ForestScene : public Scene
{
public:
	ForestScene(int windowHeight, int windowWidth) : Scene(windowHeight, windowWidth) {};

	void init() override;
  void generateGrass(ShaderProgram* shaderProgram);
	void generateTrees(int n, ShaderProgram* shaderProgram);
	void generateBushes(int n, ShaderProgram* shaderProgram);
  void addTree(glm::vec3 position, bool zombie);
};

