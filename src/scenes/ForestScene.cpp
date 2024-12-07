#include "ForestScene.h"
#include "../../models/tree.h"
#include "../../models/plain.h"
#include "../../models/sphere.h"
#include "../../models/bushes.h"

void ForestScene::init()
{
	// Shaders
	auto phongShader = Shaders::Phong();
	auto constantShader = Shaders::Constant();

	// Camera
	auto camera = new Camera(windowWidth, windowHeight, glm::vec3(10.0f, 5.0f, 10.0f), glm::vec3(0.0f, 5.0f, 0.0f));
	camera->addObserver(phongShader);
	camera->addObserver(constantShader);

	// Lights
	Light* directLight = new DirectLight(0, glm::vec3(-1.0, -1.0, -1.0), 0.1);
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
	auto fireLight1Object = new DrawableObject(new Model(sphere, sizeof(sphere), glm::vec4(1, 0, 0, 1)), constantShader);
	auto fireLight2Object = new DrawableObject(new Model(sphere, sizeof(sphere), glm::vec4(0, 1, 0, 1)), constantShader);
	auto fireLight3Object = new DrawableObject(new Model(sphere, sizeof(sphere), glm::vec4(0, 0, 1, 1)), constantShader);

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
	this->objects["plain"] = new DrawableObject(new Model(plain, sizeof(plain), glm::vec4(0.1,1,0.1,1)), phongShader);
	this->objects["plain"]->addTransform(Transformations::scale(1000.0));

	this->generateTrees(50, phongShader);
	this->generateBushes(50, phongShader);

	this->camera = camera;

	this->lights.push_back(directLight);
	//this->lights.push_back(flashLight);
	this->lights.push_back(fireLight1);
	this->lights.push_back(fireLight2);
	this->lights.push_back(fireLight3);

	this->objects["fireLight1"] = fireLight1Object;
	this->objects["fireLight2"] = fireLight2Object;
	this->objects["fireLight3"] = fireLight3Object;
}

void ForestScene::generateTrees(int n, ShaderProgram* shaderProgram)
{
	for (int i = 0; i < n; i++)
	{
		float randX = rand() % 50 + 20;
		float randZ = rand() % 50 + 20;

		int randXNeg = rand() % 2 ? -1 : 1;
		int randZNeg = rand() % 2 ? -1 : 1;

		float randScale = (float)(rand() % 10) / 10 + 0.5;

		DrawableObject* treeObj = new DrawableObject(new Model(tree, sizeof(tree)), shaderProgram);
		treeObj->addTransform(Transformations::scale(randScale));
		treeObj->addTransform(Transformations::translate(randX * randXNeg, 0.0, randZ * randZNeg));
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

		float randScale = (float)(rand() % 10) / 10 + 0.5;

		DrawableObject* bushObj = new DrawableObject(new Model(bushes, sizeof(bushes)), shaderProgram);
		bushObj->addTransform(Transformations::scale(randScale));
		bushObj->addTransform(Transformations::translate(randX * randXNeg, 0.0, randZ * randZNeg));
		this->objects["bush" + std::to_string(i)] = bushObj;
	}
}