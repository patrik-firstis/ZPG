#pragma once
#include "Model.h"

#include<assimp/Importer.hpp>
#include<assimp/scene.h>
#include<assimp/postprocess.h>/

struct Vertex
{
  float Position[3];
  float Normal[3];
  float Texture[2];
  float Tangent[3];
};

class AssimpModel : public Model
{
private:
  GLuint IBO = 0;
  int indicesCount = 0;

  void load(std::string objectPath, std::string texturePath);

public:
  AssimpModel(const char* objectPath, const char* texturePath);
  AssimpModel(const char* objectPath, Material* material);
  ~AssimpModel() override;

  void draw() override;
};

