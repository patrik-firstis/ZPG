#pragma once
#include "Transformation.h"

class Translation : public Transformation
{
private:
	glm::vec3 translation;

public:
	Translation(glm::vec3 translation, float duration = 0.0f);
	glm::mat4 getMatrix() override;
};

