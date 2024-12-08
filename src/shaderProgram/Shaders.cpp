#include "Shaders.h"

std::unordered_map<std::string, ShaderProgram*> Shaders::shaders = {};

Shaders::~Shaders() {
	for (auto shader : shaders) {
		delete shader.second;
	}
}

ShaderProgram* Shaders::Constant(std::string sceneName) {
  auto key = "constant|" + sceneName;
  if (shaders.find(key) == shaders.end()) {
    shaders[key] = new ShaderProgram("src/shaders/constant_vert.glsl", "src/shaders/constant_frag.glsl");
  }
  return shaders[key];
}

ShaderProgram* Shaders::Phong(std::string sceneName) {
  auto key = "phong|" + sceneName;
  if (shaders.find(key) == shaders.end()) {
		shaders[key] = new ShaderProgram("src/shaders/phong_vert.glsl", "src/shaders/phong_frag.glsl");
  }
	return shaders[key];
}

ShaderProgram* Shaders::Lambert(std::string sceneName) {
	auto key = "lambert|" + sceneName;
  if (shaders.find(key) == shaders.end()) {
    shaders[key] = new ShaderProgram("src/shaders/lambert_vert.glsl", "src/shaders/lambert_frag.glsl");
  }
  return shaders[key];
}

ShaderProgram* Shaders::Skybox(std::string sceneName) {
  auto key = "skybox|" + sceneName;
  if (shaders.find(key) == shaders.end()) {
    shaders[key] = new ShaderProgram("src/shaders/skybox_vert.glsl", "src/shaders/skybox_frag.glsl");
  }
  return shaders[key];
}