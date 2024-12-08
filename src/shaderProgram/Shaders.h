#pragma once
#include <unordered_map>
#include <string>
#include "ShaderProgram.h"
static class Shaders
{
private:
	static std::unordered_map<std::string, ShaderProgram*> shaders;
public:
	~Shaders();
	static ShaderProgram* Constant(std::string sceneName);
	static ShaderProgram* Phong(std::string sceneName);
	static ShaderProgram* Lambert(std::string sceneName);
  static ShaderProgram* Skybox(std::string sceneName);
};

