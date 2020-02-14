#pragma once
#include "Singleton.h"
#include "Scene.h"
#include "Renderer.h"
class Director : public Singleton<Director>
{
private:
	Scene* _currentScene;
	LPD3DXSPRITE _sprite; // Director가 가지고 있을 sprite
public:
	void DirectorInit();
	void ChangeScene(Scene* scene);
	void UpdateScene();
	LPD3DXSPRITE GetSprite() { return _sprite; }; // _sprite를 리턴해주는 함수
};

