#pragma once
#include <glm/mat4x4.hpp>
#include <vector>
#include <memory>
#include "ShaderProgram.h"
#include <GLFW/glfw3.h>
#include "Subject.h"

class Camera : public Subject{
private:
	glm::mat4 viewMatrix;
	glm::mat4 projectionMatrix;

	glm::vec3 position;
	glm::vec3 orientation;
	glm::vec3 up;
	
	float pitch;         // Vertical angle (pitch)
	float yaw;           // Horizontal angle (yaw)

	float speed = 0.3f;
	float sensitivity = 100.0f;
	float FOVdeg;

	int width;
	int height;

public:
	Camera(int width, int height, glm::vec3 position, glm::vec3 target = glm::vec3(0.0, 0.0, -1.0), glm::vec3 up = glm::vec3(0.0, 1.0, 0.0), float FOVdeg = 60.0);
	Camera(int width, int height, glm::vec3 position, float pitch, float yaw, glm::vec3 up = glm::vec3(0.0, 1.0, 0.0), float FOVdeg = 60.0);

	glm::mat4 getViewMatrix() const { return viewMatrix; }
	glm::mat4 getProjectionMatrix() const { return projectionMatrix; }
	glm::vec3 getPosition() const { return position; }
	glm::vec3 getOrientation() const { return orientation; }

	void updateMatrices();
	void handleMovement(int key);
	void handleMouseMovement(float deltaX, float deltaY);
	void updatePerspective(int width, int height);
};

