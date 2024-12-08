#pragma once
#include "PositionModel.h"
#include "NormalModel.h"
#include "TextureModel.h"
#include "CubemapModel.h"
#include "Model.h"

#include "data/triangle.h"
#include "data/sphere.h"
#include "data/tree.h"
#include "data/bushes.h"
#include "data/plain.h"
#include "data/skycube.h"



static class Models
{
public:
  static Model* Triangle() {
    return new PositionModel(triangle, sizeof(triangle));
  }

  static Model* Sphere() {
    return new NormalModel(sphere, sizeof(sphere));
  }

  static Model* Tree() {
    return new NormalModel(tree, sizeof(tree));
  }

  static Model* Bushes() {
    return new NormalModel(bushes, sizeof(bushes));
  }

  static Model* Plain() {
    return new TextureModel(plain, sizeof(plain));
  }

  static Model* Skybox() {
    return new CubemapModel(skycube, sizeof(skycube), "src/models/textures/skybox/");
  }
};

