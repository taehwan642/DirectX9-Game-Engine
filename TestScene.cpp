#include "DXUT.h"
#include "TestScene.h"

void TestScene::Create()
{
	cout << "TestScene CREATE!" << endl;;
}

void TestScene::Update()
{
	if(DXUTIsKeyDown('P')) // P ��� Ű�� ���� ���¶�� cout!
		cout << "TestScene Keyboard UPDATE!" << endl;
	if (DXUTIsMouseButtonDown('0')) // ���� ���콺 ��ư�� ���� ���¶�� cout!
		cout << "TestScene Mouse UPDATE!" << endl;
}

void TestScene::OnExit()
{
	cout << "TestScene ONEXIT!" << endl;
}
