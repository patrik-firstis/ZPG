#pragma once
#include "Shader.h"
class FragmentShader : public Shader
{
public:
	FragmentShader(const char* fragmentSource = "default.frag", bool isPath = true);
	~FragmentShader() {};
};

