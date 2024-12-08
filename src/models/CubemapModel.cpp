#include "CubemapModel.h"
#include "SOIL.h"

CubemapModel::CubemapModel(const float* vertices, size_t size, std::string path) : Model(size / sizeof(float) / 3){
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

	this->textureID = loadCubemap(path);
}

CubemapModel::~CubemapModel() {
  glDeleteTextures(1, &textureID);
  glDeleteBuffers(1, &VBO);
  glDeleteVertexArrays(1, &VAO);
}

void CubemapModel::draw() {
  glBindVertexArray(VAO);
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_CUBE_MAP, this->textureID);
  glDrawArrays(GL_TRIANGLES, 0, this->verticesCount);
}

GLuint CubemapModel::getTextureID() {
  return this->textureID;
}

GLuint CubemapModel::loadCubemap(const std::string path) {
  GLuint image = SOIL_load_OGL_cubemap(
    (path + "posx.jpg").c_str(), (path + "negx.jpg").c_str(), 
    (path + "posy.jpg").c_str(), (path + "negy.jpg").c_str(), 
    (path + "posz.jpg").c_str(), (path + "negz.jpg").c_str(), 
    SOIL_LOAD_RGB, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS);
  if (image == NULL) {
    exit(EXIT_FAILURE);
  }
  glBindTexture(GL_TEXTURE_CUBE_MAP, image);
  glEnable(GL_TEXTURE_CUBE_MAP_SEAMLESS);

  glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

  return image;
} 