#include "ShaderProgram.h"
#include "../camera/Camera.h"
#include "../lights/Light.h"
#include <iostream>

ShaderProgram::ShaderProgram(VertexShader *vertexShader, FragmentShader *fragmentShader) {
	this->programId = glCreateProgram();
	
	glAttachShader(this->programId, vertexShader->getShaderId());
	glAttachShader(this->programId, fragmentShader->getShaderId());
	glLinkProgram(this->programId);
	glGetProgramiv(this->programId, GL_LINK_STATUS, &this->linkStatus);
	if (this->linkStatus == GL_FALSE)
	{
		GLint infoLogLength;
		glGetProgramiv(this->programId, GL_INFO_LOG_LENGTH, &infoLogLength);
		GLchar* strInfoLog = new GLchar[infoLogLength + 1];
		glGetProgramInfoLog(this->programId, infoLogLength, NULL, strInfoLog);
		fprintf(stderr, "Linker failure: %s\n", strInfoLog);
		delete[] strInfoLog;
	}
}

ShaderProgram::ShaderProgram(const char* vertexShaderPath, const char* fragmentShaderPath) {
	ShaderLoader* shaderLoader = new ShaderLoader();
	this->programId = shaderLoader->loadShader(vertexShaderPath, fragmentShaderPath);
}

ShaderProgram::~ShaderProgram() {
	glDeleteProgram(this->programId);
}

bool ShaderProgram::use() {
	glUseProgram(this->programId);
	return true;
}

void ShaderProgram::setUniform(const char* name, glm::mat4 value) {
	GLint location = glGetUniformLocation(this->programId, name);
	this->use();
	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));
	glUseProgram(0);
}
void ShaderProgram::setUniform(const char* name, glm::mat3 value) {
	GLint location = glGetUniformLocation(this->programId, name);
	this->use();
	glUniformMatrix3fv(location, 1, GL_FALSE, glm::value_ptr(value));
	glUseProgram(0);
}
void ShaderProgram::setUniform(const char* name, glm::vec4 value) {
	GLint location = glGetUniformLocation(this->programId, name);
	this->use();
	glUniform4fv(location, 1, glm::value_ptr(value));
	glUseProgram(0);
}
void ShaderProgram::setUniform(const char* name, glm::vec3 value) {
	GLint location = glGetUniformLocation(this->programId, name);
	this->use();
	glUniform3fv(location, 1, glm::value_ptr(value));
	glUseProgram(0);
}
void ShaderProgram::setUniform(const char* name, float value) {
	GLint location = glGetUniformLocation(this->programId, name);
	this->use();
	glUniform1f(location, value);
	glUseProgram(0);
}
void ShaderProgram::setUniform(const char* name, int value) {
	GLint location = glGetUniformLocation(this->programId, name);
	this->use();
	glUniform1i(location, value);
	glUseProgram(0);
}


void ShaderProgram::notify(Subject* subject)
{
	if (auto camera = dynamic_cast<Camera*>(subject)) {
		this->setUniform("viewMatrix", camera->getViewMatrix());
		this->setUniform("projectionMatrix", camera->getProjectionMatrix());

		this->setUniform("viewPosition", camera->getPosition());
		this->setUniform("viewDirection", camera->getOrientation());
	}
	else if (auto light = dynamic_cast<Light*>(subject)) {
		int index = light->getIndex();

		this->setUniform(("lights[" + std::to_string(index) + "].type").c_str(), light->getType());
		this->setUniform(("lights[" + std::to_string(index) + "].position").c_str(), light->getPosition());
		this->setUniform(("lights[" + std::to_string(index) + "].direction").c_str(), light->getDirection());
		this->setUniform(("lights[" + std::to_string(index) + "].color").c_str(), light->getColor());
		this->setUniform(("lights[" + std::to_string(index) + "].ambient").c_str(), light->getAmbient());
		this->setUniform(("lights[" + std::to_string(index) + "].intensity").c_str(), light->getIntensity());
		this->setUniform(("lights[" + std::to_string(index) + "].constantAttenuation").c_str(), light->getConstantAttenuation());
		this->setUniform(("lights[" + std::to_string(index) + "].linearAttenuation").c_str(), light->getLinearAttenuation());
		this->setUniform(("lights[" + std::to_string(index) + "].quadraticAttenuation").c_str(), light->getQuadraticAttenuation());
		this->setUniform(("lights[" + std::to_string(index) + "].innerConeAngle").c_str(), light->getInnerConeAngle());
		this->setUniform(("lights[" + std::to_string(index) + "].outerConeAngle").c_str(), light->getOuterConeAngle());
	} 
	else {
		fprintf(stderr, "ShaderProgram::notify(unknown type)");
	}
}

void ShaderProgram::setMaterial(Material* material) {
  this->setUniform("material.ambient", material->getAmbient());
  this->setUniform("material.diffuse", material->getDiffuse());
  this->setUniform("material.specular", material->getSpecular());
  this->setUniform("material.color", material->getColor());
}