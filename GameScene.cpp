#include "DXUT.h"
#include "GameScene.h"

void GameScene::Init()
{
	cout << "in" << endl;
	sp = new Sprite();
	sp->SetTexture(L"AquariumDX.jpg");
	sp->mPosition = { Screen_Width / 2, Screen_Height / 2 };
	sp->mIsUI = false;
	x = CamIns->GetPos().x;
	y = CamIns->GetPos().y;
}

void GameScene::Update()
{
	if (DXUTIsKeyDown('D'))
		x++;
	if (DXUTIsKeyDown('S'))
		y++;
	if (DXUTIsKeyDown('A'))
		x--;
	if (DXUTIsKeyDown('W'))
		y--;

	Camera::GetIns()->SetPos({x,y});

	cout <<Camera::GetIns()->GetPos().x << " " << Camera::GetIns()->GetPos().y << endl;
}

void GameScene::Exit()
{
}
