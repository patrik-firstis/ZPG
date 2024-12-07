#pragma once
#include <glm/mat4x4.hpp>

class Subject;
class Observer
{
public:
	virtual	void notify(Subject* subject) = 0;
};

