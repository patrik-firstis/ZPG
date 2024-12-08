#pragma once
#include "Model.h"


class PositionModel : public Model
{
public:
  PositionModel(const float* vertices, size_t size, Material* material);
  ~PositionModel() override;
};

