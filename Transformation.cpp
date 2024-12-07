#include "Transformation.h"

Transformation::Transformation(glm::mat4 matrix, float duration) {
	this->matrix = matrix;
	this->duration = duration;
}

Transformation::Transformation(float duration) {
	this->matrix = glm::mat4(1.0f);
	this->duration = duration;
}

glm::mat4 Transformation::getMatrix() {
	return this->matrix;
}
