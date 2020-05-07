#include "DXUT.h"
#include "Director.h"

void Director::DirectorInit()
{
	currentScene = nullptr;
}

void Director::SetScene(Scene* scene)
{
	if (currentScene != nullptr)
		currentScene->Exit();
	currentScene = scene;
	currentScene->Init();
}

void Director::UpdateScene()
{
	if (currentScene != nullptr)
	{
		Renderer::getins()->Render();
		currentScene->Update();
	}
}
