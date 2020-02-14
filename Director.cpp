#include "DXUT.h"
#include "Director.h"

void Director::DirectorInit()
{
	_currentScene = nullptr;
	_sprite = nullptr;
	D3DXCreateSprite(DXUTGetD3D9Device(), &_sprite); // Device에 Sprite를 생성함.
}

void Director::ChangeScene(Scene* scene)
{
	if (_currentScene)
		_currentScene->OnExit();
	_currentScene = scene;
	_currentScene->Create();
}

void Director::UpdateScene()
{
	if(_currentScene)
		_currentScene->Update();
	Renderer::Instance()->Render(); // 씬이 업데이트됨과 동시에 렌더하게해줌.
}
