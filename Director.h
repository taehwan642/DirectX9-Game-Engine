#pragma once
#include "Singleton.h"
#include "Scene.h"
#include "Renderer.h"
class Director :
	public Singleton<Director>
{
private:
	Scene* currentScene;
public:
	void DirectorInit();
	void SetScene(Scene* scene);
	void UpdateScene();
};

