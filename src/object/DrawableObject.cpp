#include "DrawableObject.h"
#include "../models/PositionModel.h"
#include "../models/NormalModel.h"
#include "../models/TextureModel.h"
#include "../models/CubemapModel.h"

int DrawableObject::count = 0;

DrawableObject::DrawableObject(Model* model, ShaderProgram* shaderProgram, std::vector<Transformation*> animatedTransformation) {
	this->model = model;
	this->shaderProgram = shaderProgram;
  this->animatedTransformations = animatedTransformation;
  this->id = count++;
}


void DrawableObject::draw() {
	glm::mat4 modelMatrix = glm::mat4(1.0f);

	for (auto transform : this->animatedTransformations) {
		modelMatrix = modelMatrix * transform->getMatrix();
	}

  this->shaderProgram->setUniform("modelMatrix", modelMatrix);
  this->shaderProgram->setMaterial(this->model->getMaterial());
  this->model->bindTexture();

	if (auto skyboxModel = dynamic_cast<CubemapModel*>(this->model)) {
		glDepthMask(GL_FALSE);
    this->shaderProgram->use();
		glStencilFunc(GL_ALWAYS, this->id, 0x00);
    this->model->draw();
		this->shaderProgram->setUniform("textureUnitID", 0);
    glDepthMask(GL_TRUE);
  }
  else {
		this->shaderProgram->use();
		glStencilFunc(GL_ALWAYS, this->id, 0xFF);
		this->model->draw();
		this->shaderProgram->setUniform("textureUnitID", 0);
  }
	
	glUseProgram(0);
}

void DrawableObject::addTransform(Transformation* transform) {
	this->animatedTransformations.push_back(transform);
}