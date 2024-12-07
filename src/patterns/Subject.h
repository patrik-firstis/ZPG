#pragma once
#include <glm/mat4x4.hpp>
#include <vector>
#include "Observer.h"

class Subject
{
private:
	std::vector<Observer*> observers;

public:
	virtual ~Subject() = default;
	void addObserver(Observer* observer);
	void removeObserver(Observer* observer);
	void notifyObservers();
};

