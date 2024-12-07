#include "CompositeTransformation.h"

CompositeTransformation::CompositeTransformation(std::vector<Transformation*> animatedTransformations, float duration) : Transformation(duration) {
	this->animatedTransformations = animatedTransformations;
}

CompositeTransformation::CompositeTransformation(float duration) : Transformation(duration) {
	this->animatedTransformations = std::vector<Transformation*>();
}

glm::mat4 CompositeTransformation::getMatrix() {
	if (this->time == -1.0f)
		resetTime();

	this->matrix = glm::mat4(1.0f);

	if (this->duration == -1.0f)
	{
		float diff = (float)glfwGetTime() - this->time;
		this->compositeDuration = 0.0f;
		int i = 0;
		for (auto transformation : this->animatedTransformations)
		{

			if (diff >= this->compositeDuration)
				this->matrix *= transformation->getMatrix();

			this->compositeDuration += transformation->getDuration();
		}
		if (diff >= this->compositeDuration)
			resetTime();
	}
	else if (this->duration == 0.0f || this->time == 0.0f)
	{
		for (auto transformation : this->animatedTransformations)
		{
			this->matrix *= transformation->getMatrix();
		}
	}
	else
	{
		float diff = (float)glfwGetTime() - this->time;
		this->compositeDuration = 0.0f;
		for (auto transformation : this->animatedTransformations)
		{
			if (diff >= this->compositeDuration)
				this->matrix *= transformation->getMatrix();

			this->compositeDuration += transformation->getDuration();
		}
		if (diff >= this->duration) {
			this->time = 0.0f;
			this->duration = 0.0f;
		}
			
		if (diff >= this->compositeDuration) {
			resetTime();
			this->duration -= diff;
		}

		
	}

	return this->matrix;
}

void CompositeTransformation::resetTime(float time) {
	if (!time)
		this->time = glfwGetTime();
	else
		this->time = time;
	
	for (auto& transformation : this->animatedTransformations)
	{
		transformation->resetTime(-1.0f);
	}
}

void CompositeTransformation::addTransformation(Transformation* transformation) {
	this->animatedTransformations.push_back(transformation);
}

void CompositeTransformation::removeTransformation(int index) {
	this->animatedTransformations.erase(this->animatedTransformations.begin() + index);
}

void CompositeTransformation::clearTransformations() {
	this->animatedTransformations.clear();
}