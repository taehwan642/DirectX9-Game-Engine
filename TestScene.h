#pragma once
#include "Scene.h"
class TestScene : public Scene // ���� �� ������ TestScene �̱⿡ ��ӽ�����.
{
	void Create() override;// �����Լ� Create ������
	void Update() override;// �����Լ� Update ������
	void OnExit() override;// �����Լ� OnExit ������
};

