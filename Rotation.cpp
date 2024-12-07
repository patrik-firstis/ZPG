#include "Rotation.h"

Rotation::Rotation(float angle, glm::vec3 axis, float duration) : Transformation(duration) {
	this->angle = angle;
	this->axis = axis;
}

glm::mat4 Rotation::getMatrix() {
	if (this->time == -1.0f)
		resetTime();

	if (duration == -1.0f) {
		float angle = this->angle * (float)glfwGetTime();
		this->matrix = glm::rotate(glm::mat4(1.0f), glm::radians(angle), this->axis);
	}
	else if (duration == 0.0f)
	{
		this->matrix = glm::rotate(glm::mat4(1.0f), glm::radians(this->angle), this->axis);
	}
	else
	{
		float diff = (float)glfwGetTime() - this->time;
		float angle = this->angle * (diff / this->duration);

		if (diff > this->duration)
			this->matrix = glm::rotate(glm::mat4(1.0f), glm::radians(this->angle), this->axis);
		else
			this->time = 0.0f;
	}
	return this->matrix;
}