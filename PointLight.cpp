#include "PointLight.h"

PointLight::PointLight(int index, float intensity, glm::vec3 color, glm::vec3 ambient)
{
	this->position = position;
	this->color = color;
	this->type = 1;
	this->index = index;
	this->intensity = intensity;
	this->ambient = ambient;
}