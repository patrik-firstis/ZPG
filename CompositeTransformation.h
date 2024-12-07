#pragma once
#include <memory>
#include <vector>
#include "Transformation.h"

class CompositeTransformation : public Transformation
{
private:
	std::vector<Transformation*> animatedTransformations;
	float compositeDuration = 0.0f;

public:
	CompositeTransformation(std::vector<Transformation*> animatedTransformations, float duration = 0.0f);
	CompositeTransformation(float duration = 0.0f);

	glm::mat4 getMatrix() override;
	void resetTime(float time = 0.0f) override;
	void addTransformation(Transformation* transformation);
	void removeTransformation(int index);
	void clearTransformations();
};

