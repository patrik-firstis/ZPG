#include "NormalModel.h"


NormalModel::NormalModel(const float* vertices, size_t size, Material* material) : Model(size / sizeof(float) / 6, material) {
  glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
}

NormalModel::~NormalModel() {
  glDeleteBuffers(1, &VBO);
  glDeleteVertexArrays(1, &VAO);
  free(material);
}