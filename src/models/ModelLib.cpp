#include "ModelLib.h"

std::unordered_map<std::string, Model*> ModelLib::models = {};

ModelLib::~ModelLib() {
  for (auto& model : models) {
    delete model.second;
  }

}

Model* ModelLib::Triangle(Material* material) {
  auto key = "triangle|" + material->getIdentity();
  if (models.find(key) == models.end()) {
    models[key] = new PositionModel(triangle, sizeof(triangle), material);
  }
  return models[key];
}

Model* ModelLib::Sphere(Material* material) {
  auto key = "sphere|" + material->getIdentity();
  if (models.find(key) == models.end()) {
    models[key] = new NormalModel(sphere, sizeof(sphere), material);
  }
  return models[key];
}

Model* ModelLib::ArrayTree(Material* material) {
  auto key = "arrayTree|" + material->getIdentity();
  if (models.find(key) == models.end()) {
    models[key] = new NormalModel(tree, sizeof(tree), material);
  }
  return models[key];
}

Model* ModelLib::Bushes(Material* material) {
  auto key = "bushes|" + material->getIdentity();
  if (models.find(key) == models.end()) {
    models[key] = new NormalModel(bushes, sizeof(bushes), material);
  }
  return models[key];
}

Model* ModelLib::Plain(Material* material) {
  auto key = "plain|" + material->getIdentity();
  if (models.find(key) == models.end()) {
    models[key] = new TextureModel(plain, sizeof(plain), material);
  }
  return models[key];
}

Model* ModelLib::Skybox() {
  auto key = "skybox|";
  if (models.find(key) == models.end()) {
    models[key] = new CubemapModel(skycube, sizeof(skycube), "src/models/textures/skybox/");
  }
  return models[key];
}

Model* ModelLib::Zombie(Material* material) {
  std::string key = "zombie|";
  if (material == nullptr) {
    key += "src/models/objects/zombie/zombie.png";
    if (models.find(key) == models.end()) {
      models[key] = new AssimpModel("src/models/objects/zombie/zombie.obj", "src/models/objects/zombie/zombie.png");
    }
  }
  else {
    key += material->getIdentity();
    if (models.find(key) == models.end()) {
      models[key] = new AssimpModel("src/models/objects/zombie/zombie.obj", material);
    }
  }
  return models[key];
}

Model* ModelLib::House(Material* material) {
  std::string key = "house|";

  if (material == nullptr) {
    key += "src/models/objects/house/house.png";
    if (models.find(key) == models.end()) {
      models[key] = new AssimpModel("src/models/objects/house/house.obj", "src/models/objects/house/house.png");
    }
  }
  else {
    key += material->getIdentity();
    if (models.find(key) == models.end()) {
      models[key] = new AssimpModel("src/models/objects/house/house.obj", material);
    }
  }
  return models[key];
}

Model* ModelLib::Login(Material* material) {
  auto key = "login|" + material->getIdentity();
  if (models.find(key) == models.end()) {
    models[key] = new AssimpModel("src/models/objects/login/login.obj", material);
  }
  return models[key];
}

Model* ModelLib::Tree(Material* material) {
  std::string key = "tree|";
  if (material == nullptr) {
    key += "src/models/objects/tree/tree.png";
    if (models.find(key) == models.end()) {
      models[key] = new AssimpModel("src/models/objects/tree/tree.obj", "src/models/objects/tree/tree.png");
    }
  }
  else {
    key += material->getIdentity();
    if (models.find(key) == models.end()) {
      models[key] = new AssimpModel("src/models/objects/tree/tree.obj", material);
    }
  }
  return models[key];
}