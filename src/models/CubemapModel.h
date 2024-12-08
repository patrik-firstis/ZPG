#pragma once
#include "Model.h"
#include <string>

class CubemapModel : public Model
{
private:
  GLuint textureID;

  GLuint loadCubemap(const std::string path);

public:
  CubemapModel(const float* vertices, size_t size, std::string path);
  ~CubemapModel() override;

  void draw() override;

  GLuint getTextureID();
};

