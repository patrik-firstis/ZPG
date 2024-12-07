#pragma once
#include <GL/glew.h>
#include <string>

class Shader {
private:
  GLuint shaderId = 0;

public:
  Shader(GLenum shaderType, const char* vertexSource, bool isPath);
	~Shader() {};

	GLuint getShaderId() { return this->shaderId; }
};
