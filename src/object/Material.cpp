#include "Material.h"

Material::Material(Texture* texture, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular){
  this->ambient = ambient;
  this->diffuse = diffuse;
  this->specular = specular;
  this->texture = texture;
  this->color = glm::vec3(0.0);
}

Material::Material(glm::vec3 color, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular) {
  this->ambient = ambient;
  this->diffuse = diffuse;
  this->specular = specular;
  this->color = color;
}

glm::vec3 Material::getAmbient() const {
  return ambient;
}

glm::vec3 Material::getDiffuse() const {
  return diffuse;
}

glm::vec3 Material::getSpecular() const {
  return specular;
}

glm::vec3 Material::getColor() const {
  return color;
}

void Material::bindTexture() {
  if (texture != nullptr) {
    texture->bind();
  }
}