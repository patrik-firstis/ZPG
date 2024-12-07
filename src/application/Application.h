#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include "../scenes/Scene.h"

class Application 
{
private:
  GLFWwindow* window;
	int windowWidth, windowHeight;
	bool firstClick = true;
	std::vector<Scene*> scenes;
	int currentScene = 0;
	bool tabPressed = false;

public:
  Application(int windowWidth, int windowHeight);
  ~Application();

  void init();
  void run();
  void handleInput(Scene* scene);
	void updatePerspective(int width, int height);
};