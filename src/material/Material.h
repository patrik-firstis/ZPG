#pragma once
#include <glm/glm.hpp>
#include "Texture.h"

class Material {
private:
  glm::vec3 ambient;
  glm::vec3 diffuse;
  glm::vec3 specular;
  float shininess = 32.0f;

  glm::vec3 color;

  Texture* texture = nullptr;

public:
  Material(Texture* texture, glm::vec3 ambient = glm::vec3(0.0f), glm::vec3 diffuse = glm::vec3(1.0), glm::vec3 specular = glm::vec3(1.0), float shininess = 32.0);

  Material(glm::vec3 color = glm::vec3(0.1,0.5,1.0), glm::vec3 ambient = glm::vec3(1.0f), glm::vec3 diffuse = glm::vec3(1.0), glm::vec3 specular = glm::vec3(1.0), float shininess = 32.0);

  glm::vec3 getAmbient() const;
  glm::vec3 getDiffuse() const;
  glm::vec3 getSpecular() const;
  glm::vec3 getColor() const;
  float getShininess() const;

  void bindTexture();

  std::string getIdentity();
};

