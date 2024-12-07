#pragma once
#include "Scene.h"

class BallsScene : public Scene
{
public:
	BallsScene(int windowHeight, int windowWidth) : Scene(windowHeight, windowWidth) {};

	void init() override;
};

