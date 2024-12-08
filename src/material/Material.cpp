#include "Material.h"

Material::Material(Texture* texture, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, float shininess){
  this->ambient = ambient;
  this->diffuse = diffuse;
  this->specular = specular;
  this->texture = texture;
  this->color = glm::vec3(-1.0);
  this->shininess = shininess;
}

Material::Material(glm::vec3 color, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, float shininess) {
  this->ambient = ambient;
  this->diffuse = diffuse;
  this->specular = specular;
  this->color = color;
  this->shininess = shininess;
}

glm::vec3 Material::getAmbient() const {
  return this->ambient;
}

glm::vec3 Material::getDiffuse() const {
  return this->diffuse;
}

glm::vec3 Material::getSpecular() const {
  return this->specular;
}

glm::vec3 Material::getColor() const {
  return this->color;
}

float Material::getShininess() const {
  return this->shininess;
}

void Material::bindTexture() {
  if (texture != nullptr) {
    texture->bind();
  }
}

std::string Material::getIdentity() {
  std::string identity = "";
  if (texture != nullptr) {
    identity += texture->getFileName();
  }
  else {
    identity += std::to_string(this->color.r) + "," + std::to_string(this->color.g) + "," + std::to_string(this->color.b);
  }

  identity += "|" + std::to_string(ambient.r) + "," + std::to_string(ambient.g) + "," + std::to_string(ambient.b);
  identity += "|" + std::to_string(diffuse.r) + "," + std::to_string(diffuse.g) + "," + std::to_string(diffuse.b);
  identity += "|" + std::to_string(specular.r) + "," + std::to_string(specular.g) + "," + std::to_string(specular.b);
  identity += "|" + std::to_string(shininess);

  return identity;
}