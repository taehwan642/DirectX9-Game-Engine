#include "DXUT.h"
#include "Director.h"

void Director::DirectorInit()
{
	mcurrentScene = nullptr;
	Camera::GetIns()->CameraInit();
}

void Director::SceneSet(Scene* s)
{
	if (mcurrentScene != nullptr)
		mcurrentScene->Exit();
	mcurrentScene = s;
	mcurrentScene->Init();
}

void Director::SceneUpdate()
{
	if (mcurrentScene != nullptr)
		mcurrentScene->Update();
	Camera::GetIns()->Update();
	Renderer::GetIns()->Render();
}
