#pragma once
#include <unordered_map>
#include <string>
#include "Material.h"
#include "TextureLib.h"

static class MaterialLib
{
private:
  static std::unordered_map<std::string, Material*> materials;

public:
  ~MaterialLib();

  static Material* getMaterial(std::string texturePath, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, float shininess);
  
  static Material* getMaterial(glm::vec3 color, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, float shininess);

  static Material* Base(glm::vec3 color = glm::vec3(0.1, 0.3, 0.7));

  static Material* Base(std::string texturePath);

  static Material* Steel();

  static Material* Gold();

  static Material* Wood();

  static Material* Plastic(glm::vec3 color = glm::vec3(0.1, 0.3, 0.7));


};