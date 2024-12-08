#include "DrawableObject.h"
#include "../models/PositionModel.h"
#include "../models/NormalModel.h"
#include "../models/TextureModel.h"
#include "../models/CubemapModel.h"

DrawableObject::DrawableObject(Model* model, ShaderProgram* shaderProgram, Material* material, std::vector<Transformation*> animatedTransformation) {
	this->model = model;
	this->shaderProgram = shaderProgram;
  this->material = material;
  this->animatedTransformations = animatedTransformation;
}


void DrawableObject::draw() {
	glm::mat4 modelMatrix = glm::mat4(1.0f);

	for (auto transform : this->animatedTransformations) {
		modelMatrix = modelMatrix * transform->getMatrix();
	}

  this->shaderProgram->setUniform("modelMatrix", modelMatrix);
  this->shaderProgram->setMaterial(this->material->getAmbient(), this->material->getDiffuse(), this->material->getSpecular(), this->material->getColor());
  this->material->bindTexture();

	if (auto skyboxModel = dynamic_cast<CubemapModel*>(this->model)) {
		glDepthMask(GL_FALSE);
    this->shaderProgram->use();
    this->model->draw();
		this->shaderProgram->setUniform("textureUnitID", 0);
    glDepthMask(GL_TRUE);
  }
  else {
		this->shaderProgram->use();
		this->model->draw();
		this->shaderProgram->setUniform("textureUnitID", 0);
  }
	
	glUseProgram(0);
}

void DrawableObject::addTransform(Transformation* transform) {
	this->animatedTransformations.push_back(transform);
}