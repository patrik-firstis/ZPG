#include "Shaders.h"

std::vector<ShaderProgram*> Shaders::shaders = {};

Shaders::~Shaders() {
	for (auto shader : shaders) {
		delete shader;
	}
}

ShaderProgram* Shaders::Constant() {
	auto shader = new ShaderProgram("src/shaders/constant_vert.glsl", "src/shaders/constant_frag.glsl");
	shaders.push_back(shader);
	return shader;
}

ShaderProgram* Shaders::Phong() {
	auto shader = new ShaderProgram("src/shaders/phong_vert.glsl", "src/shaders/phong_frag.glsl");
	shaders.push_back(shader);
	return shader;
}

ShaderProgram* Shaders::Lambert() {
	auto shader = new ShaderProgram("src/shaders/lambert_vert.glsl", "src/shaders/lambert_frag.glsl");
	shaders.push_back(shader);
	return shader;
}