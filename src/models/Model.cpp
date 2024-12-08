#include "Model.h"

Model::Model(int verticesCount, bool disableDepth) {
  this->disableDepth = disableDepth;
  this->verticesCount = verticesCount;

  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);

  glGenVertexArrays(1, &VAO);
  glBindVertexArray(VAO);

  /*glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * (sizeof(float)), NULL);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * (sizeof(float)), (GLvoid*)(3 * (sizeof(GLfloat))));
	glEnableVertexAttribArray(1);*/
}



void Model::draw() {
  glBindVertexArray(VAO);
  glDrawArrays(GL_TRIANGLES, 0, this->verticesCount);
}