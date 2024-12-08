#pragma once
#include <vector>
#include <memory>
#include "../models/Model.h"
#include "../shaderProgram/ShaderProgram.h"
#include "../tranformations/Transformation.h"

class DrawableObject
{
private:
  static int count;
  int id = 0;
protected:
	Model* model;
	ShaderProgram* shaderProgram;
	std::vector<Transformation*> animatedTransformations;
	
public:
	DrawableObject(Model* model,	ShaderProgram* shaderProgram, std::vector<Transformation*> animatedTransformations = {});

	void draw();
	void addTransform(Transformation* transform);
};

