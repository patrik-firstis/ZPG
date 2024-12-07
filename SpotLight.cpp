#include "SpotLight.h"

SpotLight::SpotLight(int index, float innerAngleDeg, float outerAngleDeg, float intensity, glm::vec3 color, glm::vec3 ambient)
{
	this->type = 2;
	this->innerConeAngle = glm::radians(innerAngleDeg);
	this->outerConeAngle = glm::radians(outerAngleDeg);
	this->color = color;
	this->index = index;
	this->intensity = intensity;
	this->ambient = ambient;
}