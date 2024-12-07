#pragma once
#include <glm/glm.hpp>
#include "Subject.h"
#include "Transformation.h"
#include <vector>

class Light : public Subject
{
protected:
	int type;
	int index;
	glm::vec3 position;
	glm::vec3 direction;
	glm::vec3 color;
	glm::vec3 ambient;

	float intensity = 1.0;
	float constantAttenuation = 1;
	float linearAttenuation = 0.1;
	float quadraticAttenuation = 0.01;

	float innerConeAngle;
	float outerConeAngle;

	std::vector<Transformation*> animatedTransformations;
	
public:
	virtual ~Light() = default;
	void draw();

	int getIndex() const;
	int getType() const;
	glm::vec3 getPosition() const;
	glm::vec3 getDirection() const;
	glm::vec3 getColor() const;
	glm::vec3 getAmbient() const;
	float getIntensity() const;
	float getConstantAttenuation() const;
	float getLinearAttenuation() const;
	float getQuadraticAttenuation() const;
	float getInnerConeAngle() const;
	float getOuterConeAngle() const;

	void addTransformation(Transformation* transformation);
};

