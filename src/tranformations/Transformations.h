#pragma once

#include <glm/vec3.hpp>
#include <unordered_map>
#include <vector>
#include <string>
#include "Rotation.h"
#include "Translation.h"
#include "Scale.h"
#include "CompositeTransformation.h"

class Transformations {
private:
  static std::vector<Transformation*> animatedTransformations;
  static std::unordered_map<std::string, Transformation*> constantTransformations;

  static std::string generateKey(const std::string& type, const glm::vec3& params);

public:
  ~Transformations();

  static Transformation* rotate(float angle, glm::vec3 axis, float duration = 0.0f);
  static Transformation* rotateX(float angle, float duration = 0.0f);
  static Transformation* rotateY(float angle, float duration = 0.0f);
  static Transformation* rotateZ(float angle, float duration = 0.0f);

  static Transformation* translate(glm::vec3 translation, float duration = 0.0f);
  static Transformation* translate(float x, float y, float z, float duration = 0.0f);
  static Transformation* translateX(float distance, float duration = 0.0f);
  static Transformation* translateY(float distance, float duration = 0.0f);
  static Transformation* translateZ(float distance, float duration = 0.0f);

  static Transformation* scale(glm::vec3 scale, float duration = 0.0f);
  static Transformation* scale(float scaleF, float duration = 0.0f);

  static CompositeTransformation* composite(float duration = 0.0f);
};

