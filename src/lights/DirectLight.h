#pragma once
#include "Light.h"
class DirectLight : public Light
{
public:
	DirectLight(int index, glm::vec3 direction, float intensity = 1.0, glm::vec3 color = glm::vec3(1.0), glm::vec3 ambient = glm::vec3(0.1));
};

