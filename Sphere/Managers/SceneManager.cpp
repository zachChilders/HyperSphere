#include "SceneManager.h"

using namespace Managers;

Managers::SceneManager::SceneManager()
{
	glEnable(GL_DEPTH_TEST);

	shaderManager = new ShaderManager();
	shaderManager->CreateProgram("colorShader",
								 "Shaders\\VertexShader.glsl",
								 "Shaders\\FragmentShader.glsl");
	modelsManager = new ModelsManager();
}

Managers::SceneManager::~SceneManager()
{
	delete shaderManager;
	delete modelsManager;
}

void Managers::SceneManager::notifyBeginFrame()
{
	modelsManager->Update();
}

void Managers::SceneManager::notifyDisplayFrame()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	
	modelsManager->Draw();
}

void Managers::SceneManager::notifyEndFrame()
{
}

void Managers::SceneManager::notifyReshape(int width, int height, int previousWidth, int previousHeight)
{
}
