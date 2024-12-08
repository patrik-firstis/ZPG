#pragma once
#include <unordered_map>
#include <string>
#include "Texture.h"

static class TextureLib
{
private:
  static std::unordered_map<std::string, Texture*> textures;

public:
  ~TextureLib();

  static Texture* getTexture(std::string texturePath);
};
