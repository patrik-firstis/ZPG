#include "Transformations.h"
#include <sstream> // For std::to_string

// Static member definitions
std::vector<Transformation*> Transformations::animatedTransformations = {};
std::unordered_map<std::string, Transformation*> Transformations::constantTransformations = {};

// Destructor: Cleans up all transformations
Transformations::~Transformations() {
  for (auto transformation : animatedTransformations) {
    delete transformation;
  }
  for (auto& item : constantTransformations) {
    delete item.second;
  }
}

// Helper function: Generates a unique key for caching
std::string Transformations::generateKey(const std::string& type, const glm::vec3& params) {
  return type + "|" + std::to_string(params.x) + "," + std::to_string(params.y) + "," + std::to_string(params.z);
}

// Rotate
Transformation* Transformations::rotate(float angle, glm::vec3 axis, float duration) {
  if (duration == 0.0f) {
    std::string key = generateKey("rotation", axis);
		key += "|" + std::to_string(angle);
    if (constantTransformations.find(key) == constantTransformations.end()) {
      constantTransformations[key] = new Rotation(angle, axis, duration);
    }
    return constantTransformations[key];
  }

  auto newRotation = new Rotation(angle, axis, duration);
  animatedTransformations.push_back(newRotation);
  return newRotation;
}

Transformation* Transformations::rotateX(float angle, float duration) {
  return rotate(angle, glm::vec3(1.0f, 0.0f, 0.0f), duration);
}

Transformation* Transformations::rotateY(float angle, float duration) {
  return rotate(angle, glm::vec3(0.0f, 1.0f, 0.0f), duration);
}

Transformation* Transformations::rotateZ(float angle, float duration) {
  return rotate(angle, glm::vec3(0.0f, 0.0f, 1.0f), duration);
}

// Translate
Transformation* Transformations::translate(glm::vec3 translation, float duration) {
  if (duration == 0.0f) {
    std::string key = generateKey("translation", translation);
    if (constantTransformations.find(key) == constantTransformations.end()) {
      constantTransformations[key] = new Translation(translation, duration);
    }
    return constantTransformations[key];
  }

  auto newTranslation = new Translation(translation, duration);
  animatedTransformations.push_back(newTranslation);
  return newTranslation;
}

Transformation* Transformations::translate(float x, float y, float z, float duration) {
  return translate(glm::vec3(x, y, z), duration);
}

Transformation* Transformations::translateX(float distance, float duration) {
  return translate(glm::vec3(distance, 0.0f, 0.0f), duration);
}

Transformation* Transformations::translateY(float distance, float duration) {
  return translate(glm::vec3(0.0f, distance, 0.0f), duration);
}

Transformation* Transformations::translateZ(float distance, float duration) {
  return translate(glm::vec3(0.0f, 0.0f, distance), duration);
}

// Scale
Transformation* Transformations::scale(glm::vec3 scale, float duration) {
  if (duration == 0.0f) {
    std::string key = generateKey("scale", scale);
    if (constantTransformations.find(key) == constantTransformations.end()) {
      constantTransformations[key] = new Scale(scale, duration);
    }
    return constantTransformations[key];
  }

  auto newScale = new Scale(scale, duration);
  animatedTransformations.push_back(newScale);
  return newScale;
}

Transformation* Transformations::scale(float scaleF, float duration) {
  return scale(glm::vec3(scaleF, scaleF, scaleF), duration);
}

// Composite transformation
CompositeTransformation* Transformations::composite(float duration) {
  auto newComposite = new CompositeTransformation(duration);
  animatedTransformations.push_back(newComposite);
  return newComposite;
}
