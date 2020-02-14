#include "DXUT.h"
#include "Director.h"

void Director::DirectorInit()
{
	_currentScene = nullptr;
	_sprite = nullptr;
	D3DXCreateSprite(DXUTGetD3D9Device(), &_sprite); // Device�� Sprite�� ������.
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
	Renderer::Instance()->Render(); // ���� ������Ʈ�ʰ� ���ÿ� �����ϰ�����.
}
