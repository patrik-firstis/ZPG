
#include "Application.h"
#include "ForestScene.h"
#include "TestScene.h"
#include "BallsScene.h"
#include <iostream>

void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
	// Update the viewport to the new window dimensions
	glViewport(0, 0, width, height);

	// You can print out the new width and height or use it in your rendering code
	std::cout << "Window resized: " << width << "x" << height << std::endl;

	Application* app = static_cast<Application*>(glfwGetWindowUserPointer(window));

	// Call the method on the Application instance to update all scenes
	if (app) {
		app->updatePerspective(width, height);
	}
}

Application::Application(int width, int height) {
	this->windowWidth = width;
	this->windowHeight = height;
}

Application::~Application() {
  glfwDestroyWindow(window);
  glfwTerminate();
}

void Application::init() {
  if (!glfwInit()) {
    std::cerr << "ERROR: could not start GLFW3\n";
    exit(EXIT_FAILURE);
  }

  window = glfwCreateWindow(this->windowWidth, this->windowHeight, "ZPG", NULL, NULL);
  if (!window) {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  glfwMakeContextCurrent(window);
  glfwSwapInterval(1);

  glfwSetWindowUserPointer(window, this);
  glewExperimental = GL_TRUE;
  glewInit();


  glViewport(0, 0, this->windowWidth, this->windowHeight);
  float ratio = (float)this->windowWidth / (float)this->windowHeight;
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
	// Set the clear color to black
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

}

void Application::run() {

	
	//Scene* testScene = new TestScene(windowWidth, windowHeight);
	//testScene->init();
	Scene* forestScene = new ForestScene(windowWidth, windowHeight);
	forestScene->init();
	Scene* ballsScene = new BallsScene(windowWidth, windowHeight);
	ballsScene->init();

	//this->scenes.push_back(testScene);
	this->scenes.push_back(forestScene);
	this->scenes.push_back(ballsScene);

  glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
  while (!glfwWindowShouldClose(window)) {
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
    // Render the triangle
		handleInput(scenes[this->currentScene]);
		scenes[this->currentScene]->draw();

    // Swap buffers and poll events
    glfwSwapBuffers(window);
    glfwPollEvents();
  }
}

void Application::handleInput(Scene* scene) {
	if (glfwGetKey(window, GLFW_KEY_TAB) == GLFW_PRESS) {
		if (!tabPressed) {
			this->currentScene = (this->currentScene + 1) % this->scenes.size();
			tabPressed = true;
		}
	}
	else {
		tabPressed = false;
	}
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		scene->moveCamera(GLFW_KEY_W);
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		scene->moveCamera(GLFW_KEY_S);
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		scene->moveCamera(GLFW_KEY_A);
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		scene->moveCamera(GLFW_KEY_D);
	}
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
		scene->moveCamera(GLFW_KEY_SPACE);
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS) {
		scene->moveCamera(GLFW_KEY_LEFT_CONTROL);
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
		scene->lookCamera(-1, 0);
	}
	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
		scene->lookCamera(1, 0);
	}
	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
		scene->lookCamera(0, 1);
	}
	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
		scene->lookCamera(0, -1);
	}

	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
	{
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

		if (firstClick)
		{
			glfwSetCursorPos(window, (windowWidth / 2), (windowHeight / 2));
			firstClick = false;
		}

		double mouseX;
		double mouseY;

		glfwGetCursorPos(window, &mouseX, &mouseY);

		float deltaX = (float)(mouseY - (windowHeight / 2)) / windowHeight;
		float deltaY = (float)(mouseX - (windowWidth / 2)) / windowWidth;

		scene->lookCamera(deltaX, deltaY);

		glfwSetCursorPos(window, (windowWidth / 2), (windowHeight / 2));
	}
	else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE)
	{
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		firstClick = true;
	}
}

void Application::updatePerspective(int width, int height) {
	for (int i = 0; i < this->scenes.size(); i++)
	{
		this->scenes[i]->updatePerspective(width, height);
	}
}

