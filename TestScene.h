#pragma once
#include "Scene.h"
class TestScene : public Scene // 씬의 한 종류인 TestScene 이기에 상속시켜줌.
{
	void Create() override;// 가상함수 Create 재정의
	void Update() override;// 가상함수 Update 재정의
	void OnExit() override;// 가상함수 OnExit 재정의
};

