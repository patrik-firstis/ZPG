#pragma once
#include <unordered_map>
#include <string>
#include "ShaderProgram.h"
static class Shaders
{
private:
	static std::vector<ShaderProgram*> shaders;
public:
	~Shaders();
	static ShaderProgram* Constant();
	static ShaderProgram* Phong();
	static ShaderProgram* Lambert();
};

