#include "Camera.h"

Camera::Camera(int width, int height, glm::vec3 position, glm::vec3 target, glm::vec3 up, float FOVdeg) {
	this->width = width;
	this->height = height;
	this->position = position;
	this->FOVdeg = FOVdeg;

	this->up = up;
	this->orientation = glm::normalize(target - position);

	this->pitch = glm::degrees(asin(orientation.y));
	this->yaw = glm::degrees(atan2(orientation.z, orientation.x));
		
	this->viewMatrix = glm::mat4(1.0f);
	this->projectionMatrix = glm::mat4(1.0f);

	updateMatrices();
}

Camera::Camera(int width, int height, glm::vec3 position, float pitch, float yaw, glm::vec3 up, float FOVdeg) {
	this->width = width;
	this->height = height;
	this->position = position;
	this->FOVdeg = FOVdeg;

	this->up = up;
	this->pitch = pitch;
	this->yaw = yaw;

	this->orientation = glm::vec3(cos(glm::radians(yaw)) * cos(glm::radians(pitch)), sin(glm::radians(pitch)), sin(glm::radians(yaw)) * cos(glm::radians(pitch)));

	this->viewMatrix = glm::mat4(1.0f);
	this->projectionMatrix = glm::mat4(1.0f);

	updateMatrices();
}

void Camera::updateMatrices() {
	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;

	// Update orientation vector
	orientation.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	orientation.y = sin(glm::radians(pitch));
	orientation.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	orientation = glm::normalize(orientation);

	projectionMatrix = glm::perspective(glm::radians(FOVdeg), (float)width / (float)height, 0.1f, 200.0f);
	viewMatrix = glm::lookAt(position, position + orientation, up);
	notifyObservers();
}

void Camera::handleMovement(int key)
{
	if (key == GLFW_KEY_W)
	{
		position += speed * orientation;
	}
	if (key == GLFW_KEY_A)
	{
		position += speed * -glm::normalize(glm::cross(orientation, up));
	}
	if (key == GLFW_KEY_S)
	{
		position += speed * -orientation;
	}
	if (key == GLFW_KEY_D)
	{
		position += speed * glm::normalize(glm::cross(orientation, up));
	}
	if (key == GLFW_KEY_SPACE)
	{
		position += speed * up;
	}
	if (key == GLFW_KEY_LEFT_CONTROL)
	{
		position += speed * -up;
	}
}

void Camera::handleMouseMovement(float deltaX, float deltaY) {
	// Adjust yaw and pitch based on mouse input
	yaw += deltaY * sensitivity;
	pitch -= deltaX * sensitivity; // Invert Y-axis for typical camera controls

	updateMatrices();
}

void Camera::updatePerspective(int width, int height) {
	this->width = width;
	this->height = height;
	projectionMatrix = glm::perspective(glm::radians(FOVdeg), (float)width / (float)height, 0.1f, 200.0f);
}