#pragma once
#include "Light.h"

class SpotLight : public Light
{
public:
	SpotLight(int index, float innerAngleDeg, float outerAngleDeg, float intensity = 1.0, glm::vec3 color = glm::vec3(1.0), glm::vec3 ambient = glm::vec3(0.05));
};

