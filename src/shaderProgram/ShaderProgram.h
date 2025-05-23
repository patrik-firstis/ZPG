 #pragma once
#include "VertexShader.h"
#include "FragmentShader.h"
#include <glm/vec3.hpp> 
#include <glm/vec4.hpp> 
#include <glm/mat4x4.hpp> 
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtc/type_ptr.hpp> 
#include "ShaderLoader.h"
#include "../patterns/Observer.h"
#include "../material/Material.h"

class ShaderProgram : public Observer
{
private:
	GLuint programId;
	GLint linkStatus = GL_TRUE;

public:
	ShaderProgram(VertexShader* vertexShader, FragmentShader* fragmentShader);
	ShaderProgram(const char* vertexShaderPath, const char* fragmentShaderPath);
	~ShaderProgram();

	bool use();
	void setUniform(const char* name, glm::mat4 value);
	void setUniform(const char* name, glm::mat3 value);
	void setUniform(const char* name, glm::vec4 value);
	void setUniform(const char* name, glm::vec3 value);
	void setUniform(const char* name, float value);
	void setUniform(const char* name, int value);
	void notify(Subject* subject) override;
  void setMaterial(Material* material);
};

