#include "Translation.h"

Translation::Translation(glm::vec3 translation, float duration) : Transformation(duration) {
	this->translation = translation;
}

glm::mat4 Translation::getMatrix() {
	if (this->time == -1.0f)
		resetTime();

	if (this->duration == -1.0f ) {
		glm::vec3 translation = this->translation * (float)glfwGetTime();
		this->matrix = glm::translate(glm::mat4(1.0f), translation);
	}
	else if (this->duration == 0.0f || this->time == 0.0f)
	{
		this->matrix = glm::translate(glm::mat4(1.0f), this->translation);
	}
	else
	{
		float diff = (float)glfwGetTime() - this->time;
		glm::vec3 translation = this->translation * (diff / this->duration);

		if (diff < this->duration)
			this->matrix = glm::translate(glm::mat4(1.0f), translation);
		else
			this->time = 0.0f;
	}
	return this->matrix;
}