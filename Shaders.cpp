#include "Shaders.h"

std::vector<ShaderProgram*> Shaders::shaders = {};

Shaders::~Shaders() {
	for (auto shader : shaders) {
		delete shader;
	}
}

ShaderProgram* Shaders::Constant() {
	auto shader = new ShaderProgram("constant_vert.glsl", "constant_frag.glsl");
	shaders.push_back(shader);
	return shader;
}

ShaderProgram* Shaders::Phong() {
	auto shader = new ShaderProgram("phong_vert.glsl", "phong_frag.glsl");
	shaders.push_back(shader);
	return shader;
}

ShaderProgram* Shaders::Lambert() {
	auto shader = new ShaderProgram("lambert_vert.glsl", "lambert_frag.glsl");
	shaders.push_back(shader);
	return shader;
}