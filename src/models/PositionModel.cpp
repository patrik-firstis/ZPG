#include "PositionModel.h"

PositionModel::PositionModel(const float* vertices, size_t size) : Model(size / sizeof(float) / 3) {
  glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
}

PositionModel::~PositionModel(){
  glDeleteBuffers(1, &VBO);
  glDeleteVertexArrays(1, &VAO);
}