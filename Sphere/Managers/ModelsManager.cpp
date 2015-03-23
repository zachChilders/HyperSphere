#include "ModelsManager.h"

using namespace Managers;
using namespace Rendering;

Managers::ModelsManager::ModelsManager()
{
	Models::Triangle* triangle = new Models::Triangle();
	triangle->SetProgram(ShaderManager::GetShader("colorShader"));
	triangle->Create();
	gameModelList["triangle"] = triangle;

	Models::Quad* quad = new Models::Quad();
	quad->SetProgram(ShaderManager::GetShader("colorShader"));
	quad->Create();
	gameModelList["quad"] = quad;
}

Managers::ModelsManager::~ModelsManager()
{
	for (auto model : gameModelList)
	{
		delete model.second;
	}
	gameModelList.clear();
}

void Managers::ModelsManager::DeleteModel(const std::string & gameModelName)
{
	IGameObject* model = gameModelList[gameModelName];
	model->Destroy();
	gameModelList.erase(gameModelName);
}

const IGameObject& ModelsManager::GetModel(const std::string& gameModelName)
{
	return (*gameModelList.at(gameModelName));
}

void ModelsManager::Update()
{
	for (auto model : gameModelList)
	{
		model.second->Update();
	}
}

void ModelsManager::Draw()
{
	for (auto model : gameModelList)
	{
		model.second->Draw();
	}
}

