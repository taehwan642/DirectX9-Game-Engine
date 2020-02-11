#include "SingleTon.h"
#include "Scene.h"
#pragma once
class Director :public SingleTon<Director> // 부모 상속
{
private:
	Scene* _currentScene;// 현재 나의 씬
public:
	Director(); // 생성자

	void UpdateScene(); // 씬을 업데이트시켜줄 함수
	void ChangeScene(Scene* nextscene);	// 씬을 바꿔줄 함수
};

