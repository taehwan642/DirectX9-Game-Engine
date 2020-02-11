#include "DXUT.h"
#include "Director.h"

Director::Director()
{
	_currentScene = nullptr; // 씬 초기화
}

void Director::UpdateScene()
{
	_currentScene->Update(); // 씬 업데이트
}

void Director::ChangeScene(Scene* nextscene)
{
	if (_currentScene)// 만약 현재 씬이 있을땐
		_currentScene->OnExit(); // 나가기

	_currentScene = nextscene; // 다음 씬으로 변환
	_currentScene->Create(); // 다음 씬의 시작!
}
