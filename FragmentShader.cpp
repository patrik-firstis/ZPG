#include "FragmentShader.h"

FragmentShader::FragmentShader(const char* fragmentSource, bool isPath) : Shader(GL_FRAGMENT_SHADER, fragmentSource, isPath) {}