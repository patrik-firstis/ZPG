#include "Light.h"


void Light::draw() {
	auto matrix = glm::mat4(1.0f);
	for (auto transformation : this->animatedTransformations) {
		auto tmatrix = transformation->getMatrix();
		matrix = matrix * tmatrix;
	}
	this->position = glm::vec3(matrix[3][0], matrix[3][1], matrix[3][2]);
	notifyObservers();
}

int Light::getIndex() const {
	return this->index;
}

int Light::getType() const {
	return this->type;
}

glm::vec3 Light::getPosition() const {
	return this->position;
}

glm::vec3 Light::getDirection() const {
	return this->direction;
}

glm::vec3 Light::getColor() const {
	return this->color;
}

glm::vec3 Light::getAmbient() const {
	return this->ambient;
}

float Light::getIntensity() const {
	return this->intensity;
}

float Light::getConstantAttenuation() const {
	return this->constantAttenuation;
}

float Light::getLinearAttenuation() const {
	return this->linearAttenuation;
}

float Light::getQuadraticAttenuation() const {
	return this->quadraticAttenuation;
}

float Light::getInnerConeAngle() const {
	return this->innerConeAngle;
}

float Light::getOuterConeAngle() const {
	return this->outerConeAngle;
}

void Light::addTransformation(Transformation* transformation) {
	this->animatedTransformations.push_back(transformation);
}