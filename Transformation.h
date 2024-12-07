#pragma once
#include <glm/vec3.hpp> 
#include <glm/mat4x4.hpp> 
#include <glm/gtc/matrix_transform.hpp> 
#include <GLFW/glfw3.h>
#include <memory> 

class Transformation
{
protected:
	glm::mat4 matrix;
	float duration;
	float time = -1.0f;

public:
	Transformation(glm::mat4 matrix, float duration = 0.0f);
	Transformation(float duration = 0.0f);

	virtual glm::mat4 getMatrix();
	float getDuration() { return this->duration; }
	void setDuration(float duration) { this->duration = duration; }
	virtual void resetTime(float time = 0.0f) { 
		if (!time)
			this->time = (float)glfwGetTime();
		else
			this->time = time;
	}
};

