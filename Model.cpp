#include "Model.h"

Model::Model(const float* vertices, size_t size, glm::vec3 color) {
  
  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);

  glGenVertexArrays(1, &VAO);
  glBindVertexArray(VAO);
  glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);


  
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * (sizeof(float)), NULL);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * (sizeof(float)), (GLvoid*)(3 * (sizeof(GLfloat))));
	glEnableVertexAttribArray(1);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);


	this->numVertices = size / 6;
	this->color = color;
}

Model::~Model() {
  glDeleteBuffers(1, &VBO);
  glDeleteVertexArrays(1, &VAO);
}

void Model::draw() {
  glBindVertexArray(VAO);
  glDrawArrays(GL_TRIANGLES, 0, this->numVertices);
}