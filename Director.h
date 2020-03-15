#pragma once
#include "Singleton.h"
#include "Scene.h"
#include "Renderer.h"
#include "Camera.h"
class Director : public Singleton<Director>
{
private:
	Scene* mcurrentScene;
public:
	void DirectorInit();
	void SceneSet(Scene* s);
	void SceneUpdate();
};

