#pragma once
#include <GL/glew.h>
#include <glm/vec3.hpp> 

class Model {
public:
  Model(const float* vertices, size_t size, glm::vec3 color = glm::vec3(0.385, 0.647, 0.812));
  ~Model();

  void draw();

	glm::vec3 getColor() const { return color; }

private:
  GLuint VAO, VBO;
	int numVertices;

	glm::vec3 color;
};