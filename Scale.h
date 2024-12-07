#pragma once
#include "Transformation.h"
class Scale : public Transformation
{
private:
	glm::vec3 scale;
public:
	Scale(glm::vec3 scale, float duration = 0.0f);
	glm::mat4 getMatrix() override;
};

