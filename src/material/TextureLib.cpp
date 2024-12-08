#include "TextureLib.h"

std::unordered_map<std::string, Texture*> TextureLib::textures = std::unordered_map<std::string, Texture*>();

Texture* TextureLib::getTexture(std::string texturePath) {
  if (textures.find(texturePath) == textures.end()) {
    textures[texturePath] = new Texture(texturePath);
  }
  return textures[texturePath];
}

TextureLib::~TextureLib() {
  for (auto& texture : textures) {
    delete texture.second;
  }
}