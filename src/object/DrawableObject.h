#pragma once
#include <vector>
#include <memory>
#include "../models/Model.h"
#include "../shaderProgram/ShaderProgram.h"
#include "../tranformations/Transformation.h"
#include "Material.h"
class DrawableObject
{
protected:
	Model* model;
  Material* material;
	ShaderProgram* shaderProgram;
	std::vector<Transformation*> animatedTransformations;
	
public:
	DrawableObject(Model* model,	ShaderProgram* shaderProgram, Material* material = new Material(), std::vector<Transformation*> animatedTransformations = {});

	void draw();
	void addTransform(Transformation* transform);
};

