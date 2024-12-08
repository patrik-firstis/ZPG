#include "Model.h"

Model::Model(int verticesCount, Material* material) {
  this->material = material;
  this->verticesCount = verticesCount;

  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);

  glGenVertexArrays(1, &VAO);
  glBindVertexArray(VAO);
}

void Model::draw() {
  glBindVertexArray(VAO);
  glDrawArrays(GL_TRIANGLES, 0, this->verticesCount);
}

void Model::bindTexture() {
  this->material->bindTexture();
}

Material* Model::getMaterial() {
  return this->material;
}