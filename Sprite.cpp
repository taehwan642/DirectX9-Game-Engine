#include "DXUT.h"
#include "Sprite.h"
#include "Director.h"
#include "Renderer.h"
Sprite::Sprite()
{
	texture = nullptr; // 초기화
}

Sprite::~Sprite()
{
	Renderer::Instance()->RemoveRenderTarget(this); // 소멸될때 나 자신을 렌더시키지 않게 함
}

void Sprite::SetTexture(wstring filename)
{
	texture = TextureMNG::Instance()->LoadTexture(filename); // 나 자신이 가지고 있는 텍스쳐를 경로 설정한 사진대로 입힘
	AddRenderTarget(); // 입힌 뒤 나 자신을 렌더시킴
}

void Sprite::AddRenderTarget()
{
	Renderer::Instance()->AddRenderTarget(this); // 나 자신을 렌더하게 함
}
RECT Sprite::GetRect()
{
	RECT r = { 0,0,0,0 };
	r.right = _position.x + (texture->_info.Width / 2 * _scale.x);
	r.left = _position.x - (texture->_info.Width / 2 * _scale.x);
	r.top = _position.y - (texture->_info.Height / 2 * _scale.y);
	r.bottom = _position.y + (texture->_info.Height / 2 * _scale.y);
	return r;
}
void Sprite::Render()
{

	if (!_visible) // 내가 활동하지 않으면 렌더하지 않게 함
		return;
	if (texture == nullptr) // 나의 텍스쳐가 없으면 렌더하지 않게 함
		return;
	//내가 UI라면 카메라에 따른 영향을 받지 않게 하고, UI가 아니라면 카메라의 영향을 받게 함
	_isUI ? Director::Instance()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND) : Director::Instance()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_OBJECTSPACE);
	Director::Instance()->GetSprite()->SetTransform(&GetMatrix()); // 나의 scale, rotation, position을 설정
	Vector3 center = { _pivot.x * texture->_info.Width,_pivot.y * texture->_info.Height,0 }; // 나의 중심점을 잡음
	Director::Instance()->GetSprite()->Draw(texture->_texture, nullptr, &center, nullptr, _color); // 나 자신을 그림
	Director::Instance()->GetSprite()->End(); // 더이상 나 자신을 덧씌우면 메모리 손실이 나기에 그만 그림
}
