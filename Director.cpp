#include "DXUT.h"
#include "Director.h"

Director::Director()
{
	_currentScene = nullptr; // �� �ʱ�ȭ
}

void Director::UpdateScene()
{
	_currentScene->Update(); // �� ������Ʈ
}

void Director::ChangeScene(Scene* nextscene)
{
	if (_currentScene)// ���� ���� ���� ������
		_currentScene->OnExit(); // ������

	_currentScene = nextscene; // ���� ������ ��ȯ
	_currentScene->Create(); // ���� ���� ����!
}
