#pragma once
#include "Light.h"

class PointLight : public Light
{
public:
	PointLight(int index, float intensity = 1.0, glm::vec3 color = glm::vec3(1.0), glm::vec3 ambient = glm::vec3(0.1));
};

