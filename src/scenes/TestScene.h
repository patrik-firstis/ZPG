#pragma once
#include "Scene.h"

class TestScene : public Scene
{
public:
	TestScene(int windowHeight, int windowWidth) : Scene(windowHeight, windowWidth) {};

	void init() override;
};

