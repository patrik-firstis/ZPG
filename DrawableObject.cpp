#include "DrawableObject.h"

DrawableObject::DrawableObject(Model* model, ShaderProgram* shaderProgram) {
	this->model = model;
	this->shaderProgram = shaderProgram;
}

DrawableObject::DrawableObject(Model* model, ShaderProgram* shaderProgram, std::vector<Transformation*> animatedTransformations) {
	this->model = model;
	this->shaderProgram = shaderProgram;
	this->animatedTransformations = animatedTransformations;
}


void DrawableObject::draw() {
	glm::mat4 modelMatrix = glm::mat4(1.0f);

	for (auto transform : this->animatedTransformations) {
		modelMatrix = modelMatrix * transform->getMatrix();
	}

	this->shaderProgram->setUniform("modelMatrix", modelMatrix);
	this->shaderProgram->setUniform("objectColor", this->model->getColor());

	this->shaderProgram->use();
	this->model->draw();
	glUseProgram(0);
}

void DrawableObject::addTransform(Transformation* transform) {
	this->animatedTransformations.push_back(transform);
}