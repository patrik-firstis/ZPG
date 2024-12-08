#pragma once
#include <GL/glew.h>
#include <glm/vec3.hpp> 

class Model {
protected:
  GLuint VAO, VBO;
  int verticesCount;
  bool disableDepth;

public:
  Model(int verticesCount, bool disableDepth = false);
  virtual ~Model() = 0 {};

  virtual void draw();
};