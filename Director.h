#include "SingleTon.h"
#include "Scene.h"
#pragma once
class Director :public SingleTon<Director> // �θ� ���
{
private:
	Scene* _currentScene;// ���� ���� ��
public:
	Director(); // ������

	void UpdateScene(); // ���� ������Ʈ������ �Լ�
	void ChangeScene(Scene* nextscene);	// ���� �ٲ��� �Լ�
};

