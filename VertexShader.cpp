#include "VertexShader.h"

VertexShader::VertexShader(const char* vertexSource, bool isPath) : Shader(GL_VERTEX_SHADER, vertexSource, isPath) {}