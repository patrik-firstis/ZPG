#pragma once
#include <vector>
#include <memory>
#include "Model.h"
#include "ShaderProgram.h"
#include "Transformation.h"

class DrawableObject
{
private:
	Model* model;
	ShaderProgram* shaderProgram;
	std::vector<Transformation*> animatedTransformations;
	
public:
	DrawableObject(Model* model, ShaderProgram* shaderProgram);
	DrawableObject(Model* model, ShaderProgram* shaderProgram, std::vector<Transformation*> animatedTransformations);

	void draw();
	void addTransform(Transformation* transform);
};

