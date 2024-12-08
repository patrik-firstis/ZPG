#pragma once
#include <GL/glew.h>
#include <glm/vec3.hpp> 
#include <glm/vec4.hpp>
#include "../material/MaterialLib.h"

class Model {
protected:
  GLuint VAO, VBO;
  int verticesCount;

  Material* material;

public:
  Model(int verticesCount, Material* material);
  virtual ~Model() = 0 {};

  virtual void draw();
  void bindTexture();
  Material* getMaterial();
};