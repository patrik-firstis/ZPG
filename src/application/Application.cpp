
#include "Application.h"
#include "../scenes/ForestScene.h"
#include "../scenes/BallsScene.h"
#include "../scenes/TestScene.h"
#include <iostream>

void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);

	Application* app = static_cast<Application*>(glfwGetWindowUserPointer(window));

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

	
	Scene* testScene = new TestScene(windowWidth, windowHeight);
	testScene->init();
	Scene* forestScene = new ForestScene(windowWidth, windowHeight);
	forestScene->init();
	Scene* ballsScene = new BallsScene(windowWidth, windowHeight);
	ballsScene->init();

	this->scenes.push_back(forestScene);
	this->scenes.push_back(ballsScene);
	this->scenes.push_back(testScene);

  glEnable(GL_DEPTH_TEST);
	glfwSwapInterval(0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_STENCIL_TEST);
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
  while (!glfwWindowShouldClose(window)) {
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
    // Render the triangle
		
		scenes[this->currentScene]->draw();
		handleInput(scenes[this->currentScene]);

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

  if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS && !zPressed) {
    zPressed = true;
  }
	else if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_RELEASE && zPressed)
	{
    zPressed = false;
	}

	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS)
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
	else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_RELEASE)
	{
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		firstClick = true;
	}

	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && !leftClickPressed)
	{

    leftClickPressed = true;

		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		GLbyte color[4];
		GLfloat depth;
		GLuint index;

    double x = width / 2;
    double y = height / 2;

		glfwGetCursorPos(window, &x, &y);

    double correctY = height - y;

		glReadPixels(x, correctY, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, color);
		glReadPixels(x, correctY, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &depth);
		glReadPixels(x, correctY, 1, 1, GL_STENCIL_INDEX, GL_UNSIGNED_INT, &index);
		printf("Clicked on pixel %.2f, %.2f, color %02hhx%02hhx%02hhx%02hhx, depth % f, stencil index % u\n", x, y, color[0], color[1], color[2], color[3], depth, index);

		glm::vec4 viewport = glm::vec4(0, 0, width, height);
		glm::vec3 windowCoords = glm::vec3(x, correctY, depth);

		glm::vec3 p = glm::unProject(windowCoords, scenes[currentScene]->getCamera()->getViewMatrix(), scenes[currentScene]->getCamera()->getProjectionMatrix(), viewport);

    if (auto forestScene = dynamic_cast<ForestScene*>(this->scenes[this->currentScene])) {
      forestScene->addTree(p, zPressed);
    }
	}

  else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE && leftClickPressed)
  {
    leftClickPressed = false;
	}
}

void Application::updatePerspective(int width, int height) {
	for (int i = 0; i < this->scenes.size(); i++)
	{
		this->scenes[i]->updatePerspective(width, height);
	}
}

