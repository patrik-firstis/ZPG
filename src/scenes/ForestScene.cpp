#include "ForestScene.h"


void ForestScene::init()
{
	// Shaders
	auto phongShader = Shaders::Phong("forest");
	auto constantShader = Shaders::Constant("forest");
  auto skyboxShader = Shaders::Skybox("forest");

	// Camera
	auto camera = new Camera(windowWidth, windowHeight, glm::vec3(10.0f, 5.0f, 10.0f), glm::vec3(0.0f, 5.0f, 0.0f));
	camera->addObserver(phongShader);
	camera->addObserver(constantShader);
  camera->addObserver(skyboxShader);

	// Lights
	Light* directLight = new DirectLight(0, glm::vec3(-1.0, -1.0, -1.0), 0.5);
	directLight->addObserver(phongShader);
	Light* flashLight = new SpotLight(1, 5.0, 15.0);
	flashLight->addObserver(phongShader);
	Light* fireLight1 = new PointLight(2, 3, glm::vec3(1, 0, 0));
	fireLight1->addObserver(phongShader);
	Light* fireLight2 = new PointLight(3, 4, glm::vec3(0, 1, 0));
	fireLight2->addObserver(phongShader);
	Light* fireLight3 = new PointLight(4, 5, glm::vec3(0, 0, 1));
	fireLight3->addObserver(phongShader);

	// Lights Objects
	auto fireLight1Object = new DrawableObject(ModelLib::Sphere(MaterialLib::Base(glm::vec3(1, 0, 0))), constantShader);
	auto fireLight2Object = new DrawableObject(ModelLib::Sphere(MaterialLib::Base(glm::vec3(0, 1, 0))), constantShader);
	auto fireLight3Object = new DrawableObject(ModelLib::Sphere(MaterialLib::Base(glm::vec3(0, 0, 1))), constantShader);

	// Lights Transformations
	auto fireLight1Position = Transformations::translate(40.0, 1.0, 40.0);
	auto fireLight1Animation = Transformations::composite(-1.0f);
	fireLight1Animation->addTransformation(Transformations::translateX(10.0f, 2.0f));
	fireLight1Animation->addTransformation(Transformations::translateX(-10.0f, 2.0f));

	auto fireLight2Position = Transformations::translate(50.0, 1.0, 50.0);
	auto fireLight2Animation = Transformations::composite(-1.0f);
	fireLight2Animation->addTransformation(Transformations::translateZ(10.0f, 1.0f));
	fireLight2Animation->addTransformation(Transformations::translateZ(-10.0f, 1.0f));

	auto fireLight3Position = Transformations::translate(60.0, 1.0, 40.0);
	auto fireLight3Animation = Transformations::composite(-1.0f);
	fireLight3Animation->addTransformation(Transformations::translateZ(10.0f, 2.0f));
	fireLight3Animation->addTransformation(Transformations::translateX(10.0f, 2.0f));
	fireLight3Animation->addTransformation(Transformations::translateZ(-10.0f, 2.0f));
	fireLight3Animation->addTransformation(Transformations::translateX(-10.0f, 2.0f));

	fireLight1->addTransformation(fireLight1Animation);
	fireLight1->addTransformation(fireLight1Position);
	fireLight1Object->addTransform(fireLight1Position);
	fireLight1Object->addTransform(fireLight1Animation);
	fireLight1Object->addTransform(Transformations::scale(0.3));

	fireLight2->addTransformation(fireLight2Animation);
	fireLight2->addTransformation(fireLight2Position);
	fireLight2Object->addTransform(fireLight2Position);
	fireLight2Object->addTransform(fireLight2Animation);
	fireLight2Object->addTransform(Transformations::scale(0.4));

	fireLight3->addTransformation(fireLight3Animation);
	fireLight3->addTransformation(fireLight3Position);
	fireLight3Object->addTransform(fireLight3Position);
	fireLight3Object->addTransform(fireLight3Animation);
	fireLight3Object->addTransform(Transformations::scale(0.5));


	
	// Create a model

  this->skybox = new DrawableObject(ModelLib::Skybox(), skyboxShader);

  this->objects["house"] = new DrawableObject(ModelLib::House(), phongShader);
	this->objects["login"] = new DrawableObject(ModelLib::Login(MaterialLib::Gold()), phongShader);
  this->objects["login"]->addTransform(Transformations::translateY(7));
  this->objects["login"]->addTransform(Transformations::rotateY(90));
  this->objects["login"]->addTransform(Transformations::scale(3));
	this->objects["login"]->addTransform(Transformations::rotateY(30, -1));

  this->generateGrass(phongShader);
	this->generateTrees(50, phongShader);
	this->generateBushes(50, phongShader);

	this->camera = camera;

	this->lights.push_back(directLight);
	this->lights.push_back(flashLight);
	this->lights.push_back(fireLight1);
	this->lights.push_back(fireLight2);
	this->lights.push_back(fireLight3);

	this->objects["fireLight1"] = fireLight1Object;
	this->objects["fireLight2"] = fireLight2Object;
	this->objects["fireLight3"] = fireLight3Object;
}

void ForestScene::generateGrass(ShaderProgram* shaderProgram)
{
	auto grassMaterial = MaterialLib::getMaterial("src/models/textures/grass.png", glm::vec3(1.0), glm::vec3(1.0), glm::vec3(0.1), 16);
	for (int x = -100; x < 100; x += 10 ) {
		for (int z = -100; z < 100; z += 10) {
      auto grass = new DrawableObject(ModelLib::Plain(grassMaterial), shaderProgram);
      grass->addTransform(Transformations::translate(x, 0.0, z));
      grass->addTransform(Transformations::scale(5));
			this->objects["grass" + std::to_string(x) + "|" + std::to_string(z)] = grass;
		}
	}
}

void ForestScene::generateTrees(int n, ShaderProgram* shaderProgram)
{
	for (int i = 0; i < n; i++)
	{
		float randX = rand() % 50 + 20;
		float randZ = rand() % 50 + 20;

		int randXNeg = rand() % 2 ? -1 : 1;
		int randZNeg = rand() % 2 ? -1 : 1;

		float randScale = (float)(rand() % 10) / 50 + 0.1;

		auto treeObj = new DrawableObject(ModelLib::Tree(), shaderProgram);
		treeObj->addTransform(Transformations::translate(randX * randXNeg, 0.0, randZ * randZNeg));
		treeObj->addTransform(Transformations::scale(randScale));
		this->objects["tree" + std::to_string(i)] = treeObj;
	}	
}

void ForestScene::generateBushes(int n, ShaderProgram* shaderProgram)
{
	for (int i = 0; i < n; i++)
	{
		float randX = rand() % 50 + 20;
		float randZ = rand() % 50 + 20;

		int randXNeg = rand() % 2 ? -1 : 1;
		int randZNeg = rand() % 2 ? -1 : 1;

		float randScale = (float)(rand() % 10) / 3 + 1;

		auto bushObj = new DrawableObject(ModelLib::Bushes(), shaderProgram);
		bushObj->addTransform(Transformations::translate(randX * randXNeg, 0.0, randZ * randZNeg));
		bushObj->addTransform(Transformations::scale(randScale));
		this->objects["bush" + std::to_string(i)] = bushObj;
	}
}

void ForestScene::addTree(glm::vec3 position, bool zombie)
{
  auto translation = Transformations::translate(position);
	if (zombie) {
    auto zombie = new DrawableObject(ModelLib::Zombie(), Shaders::Phong("forest"));
    zombie->addTransform(translation);
		this->objects["zombie" + std::to_string(this->objects.size())] = zombie;
	}
	else
	{
		auto tree = new DrawableObject(ModelLib::Tree(), Shaders::Phong("forest"));
		tree->addTransform(translation);
		tree->addTransform(Transformations::scale(0.1));
		this->objects["tree" + std::to_string(this->objects.size())] = tree;
	}
}
