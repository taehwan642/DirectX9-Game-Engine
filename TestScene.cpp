#include "DXUT.h"
#include "TestScene.h"

void TestScene::Create()
{
	testSprite = new Sprite(); // �����Ҵ�
	testSprite->SetTexture(L"rect.png"); // �ؽ��� ����
	testSprite->_position = { 640 / 2, 480 / 2 }; // ȭ�� ���߾ӿ� ����
	testSprite->_isUI = true; // �ϴ� ī�޶� ���������� �ʾ�����, UI���·� �������
	testSprite->AddRenderTarget(); // ���� ����
}

void TestScene::Update()
{
}

void TestScene::OnExit()
{
}
