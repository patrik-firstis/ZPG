#pragma once
#include "PositionModel.h"
#include "NormalModel.h"
#include "TextureModel.h"
#include "CubemapModel.h"
#include "AssimpModel.h"
#include "Model.h"
#pragma once

#include "data/triangle.h"
#include "data/sphere.h"
#include "data/tree.h"
#include "data/bushes.h"
#include "data/plain.h"
#include "data/skycube.h"



static class ModelLib
{
private:
  static std::unordered_map<std::string, Model*> models;

public:
  ~ModelLib();

  static Model* Triangle(Material* material = MaterialLib::Base());

  static Model* Sphere(Material* material = MaterialLib::Base());

  static Model* ArrayTree(Material* material = MaterialLib::Base());

  static Model* Bushes(Material* material = MaterialLib::Base());

  static Model* Plain(Material* material = MaterialLib::Base());

  static Model* Skybox();

  static Model* Zombie(Material* material = nullptr);

  static Model* House(Material* material = nullptr);

  static Model* Login(Material* material = MaterialLib::Steel());

  static Model* Tree(Material* material = nullptr);

	static Model* Earth(Material* material = nullptr);

	static Model* Plane(Material* material = nullptr);

};

