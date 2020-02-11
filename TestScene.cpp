#include "DXUT.h"
#include "TestScene.h"

void TestScene::Create()
{
	cout << "TestScene CREATE!" << endl;;
}

void TestScene::Update()
{
	if(DXUTIsKeyDown('P')) // P 라는 키가 눌린 상태라면 cout!
		cout << "TestScene Keyboard UPDATE!" << endl;
	if (DXUTIsMouseButtonDown('0')) // 왼쪽 마우스 버튼이 눌린 상태라면 cout!
		cout << "TestScene Mouse UPDATE!" << endl;
}

void TestScene::OnExit()
{
	cout << "TestScene ONEXIT!" << endl;
}
