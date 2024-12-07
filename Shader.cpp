#include "Shader.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cstring>
#include <string.h> 
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <sstream>

std::string loadFile(const char* fname)
{
	std::ifstream file(fname);
	if (!file.is_open())
	{
		std::cout << "Unable to open file " << fname << std::endl;
		//exit(1);
	}
	std::stringstream fileData;
	fileData << file.rdbuf();
	file.close();
	return fileData.str();
}

Shader::Shader(GLenum shaderType, const char* shaderSource, bool isPath) {
  const char* shaderData;

	if (isPath) {
		std::string stringData = loadFile(shaderSource);
    shaderData = stringData.c_str();
  }
  else {
    shaderData = shaderSource;
	}

  shaderId = glCreateShader(shaderType);
  glShaderSource(shaderId, 1, &shaderData, NULL);
  glCompileShader(shaderId);


	GLint success;
	GLchar infoLog[512];
	glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(shaderId, 512, NULL, infoLog);
		std::cerr << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
}