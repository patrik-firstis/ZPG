#include "TextureModel.h"

TextureModel::TextureModel(const float* vertices, size_t size, Material* material) : Model(size / sizeof(float) / 8, material)
{
  glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
}

TextureModel::~TextureModel()
{
  glDeleteBuffers(1, &VBO);
  glDeleteVertexArrays(1, &VAO);
  free(material);
}
