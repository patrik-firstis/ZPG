#pragma once
#include "Shader.h"

class VertexShader : public Shader
{
public:
	VertexShader(const char* vertexSource = "default.vert", bool isPath = true);
	~VertexShader() {};
};

