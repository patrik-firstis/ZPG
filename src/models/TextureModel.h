#pragma once
#include "Model.h"

class TextureModel : public Model
{
public:
  TextureModel(const float* vertices, size_t size);
  ~TextureModel() override;
};

