#include "DirectLight.h"

DirectLight::DirectLight(int index, glm::vec3 direction, float intensity, glm::vec3 color, glm::vec3 ambient)
{
	this->type = 0;
	this->direction = direction;
	this->color = color;
	this->index = index;
	this->intensity = intensity;
	this->ambient = ambient;
}