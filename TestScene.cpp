#include "DXUT.h"
#include "TestScene.h"

void TestScene::Create()
{
	testSprite = new Sprite(); // 동적할당
	testSprite->SetTexture(L"rect.png"); // 텍스쳐 설정
	testSprite->_position = { 640 / 2, 480 / 2 }; // 화면 정중앙에 설정
	testSprite->_isUI = true; // 일단 카메라를 설정해주지 않았으니, UI상태로 만들어줌
	testSprite->AddRenderTarget(); // 렌더 시작
}

void TestScene::Update()
{
}

void TestScene::OnExit()
{
}
