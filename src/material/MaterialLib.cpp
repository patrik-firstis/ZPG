#include "MaterialLib.h"

std::unordered_map<std::string, Material*> MaterialLib::materials = std::unordered_map<std::string, Material*>();

Material* MaterialLib::getMaterial(std::string texturePath, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, float shininess) {
  auto key = texturePath + "|" + std::to_string(ambient.x) + std::to_string(ambient.y) + std::to_string(ambient.z) +
    "|" + std::to_string(diffuse.x) + std::to_string(diffuse.y) + std::to_string(diffuse.z) +
    "|" + std::to_string(specular.x) + std::to_string(specular.y) + std::to_string(specular.z) +
    "|" + std::to_string(shininess);

  if (materials.find(key) == materials.end()) {
    materials[key] = new Material(TextureLib::getTexture(texturePath), ambient, diffuse, specular, shininess);
  }
  return materials[key];
}

Material* MaterialLib::getMaterial(glm::vec3 color, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, float shininess){
  auto key = std::to_string(color.x) + std::to_string(color.y) + std::to_string(color.z) +
    "|" + std::to_string(ambient.x) + std::to_string(ambient.y) + std::to_string(ambient.z) +
    "|" + std::to_string(diffuse.x) + std::to_string(diffuse.y) + std::to_string(diffuse.z) +
    "|" + std::to_string(specular.x) + std::to_string(specular.y) + std::to_string(specular.z) +
    "|" + std::to_string(shininess);

  if (materials.find(key) == materials.end()) {
    materials[key] = new Material(color, ambient, diffuse, specular, shininess);
  }
  return materials[key];
}

Material* MaterialLib::Base(glm::vec3 color) {
  return getMaterial(color, glm::vec3(1.0f), glm::vec3(1.0), glm::vec3(1.0), 32.0);
}

Material* MaterialLib::Base(std::string texturePath) {
  return getMaterial(texturePath, glm::vec3(1.0f), glm::vec3(1.0), glm::vec3(1.0), 32.0);
}

Material* MaterialLib::Steel() {
  return getMaterial(glm::vec3(0.6), glm::vec3(0.3f), glm::vec3(0.6), glm::vec3(1.0), 128.0);
}

Material* MaterialLib::Gold() {
  return getMaterial(glm::vec3(0.8, 0.6, 0.2), glm::vec3(0.25, 0.2, 0.07), glm::vec3(0.8, 0.6, 0.2), glm::vec3(1.0), 64.0);
}

Material* MaterialLib::Wood() {
  return getMaterial(glm::vec3(0.5, 0.3, 0.2), glm::vec3(0.2, 0.1, 0.05), glm::vec3(0.5, 0.3, 0.2), glm::vec3(0.1, 0.05, 0.05), 16.0);
}

Material* MaterialLib::Plastic(glm::vec3 color) {
  return getMaterial(color, glm::vec3(0.2, 0.0, 0.0), glm::vec3(0.8, 0.8, 0.8), glm::vec3(0.5, 0.5, 0.5), 32.0);
}

MaterialLib::~MaterialLib() {
  for (auto& material : materials) {
    delete material.second;
  }
}