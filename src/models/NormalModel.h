#pragma once
#include "Model.h"

class NormalModel : public Model
{
public:
  NormalModel(const float* vertices, size_t size, Material* material);
  ~NormalModel() override;
};

