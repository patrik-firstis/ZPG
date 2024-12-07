#include "Scale.h"

Scale::Scale(glm::vec3 scale, float duration) : Transformation(duration) {
	this->scale = scale;
}

glm::mat4 Scale::getMatrix() {
	if (this->time == -1.0f)
		resetTime();

	if (this->duration == -1.0f)
	{
		glm::vec3 scale = this->scale * (float)glfwGetTime();
		this->matrix = glm::scale(glm::mat4(1.0f), scale);
	}
	else if (this->duration == 0.0f || this->time == 0.0f)
	{
		this->matrix = glm::scale(glm::mat4(1.0f), this->scale);
	}
	else
	{
		float diff = (float)glfwGetTime() - this->time;
		glm::vec3	scale = this->scale * (diff / this->duration);

		if (diff < this->duration)
			this->matrix = glm::scale(glm::mat4(1.0f), scale);
		else
			this->time = 0.0f;
	}

	return this->matrix;
}