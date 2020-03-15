#include "DXUT.h"
#include "Sprite.h"

Sprite::Sprite()
{
	mTexture = nullptr;
	mSprite = nullptr;
	D3DXCreateSprite(DXUTGetD3D9Device(), &mSprite);
}

Sprite::~Sprite()
{
	Renderer::GetIns()->DeleteRenderTarget(this);
}

void Sprite::SetTexture(wstring path)
{
	mTexture = TexMNG::GetIns()->LoadTexture(path);
	AddRendertarget();
}

void Sprite::AddRendertarget()
{
	Renderer::GetIns()->AddRenderTarget(this);
}

RECT Sprite::GetRect()
{
	RECT r;
	r.right = mPosition.x + (mTexture->minfo.Width / 2 * mScale.x);
	r.left = mPosition.x - (mTexture->minfo.Width / 2 * mScale.x);
	r.bottom = mPosition.y + (mTexture->minfo.Height / 2 * mScale.y);
	r.top = mPosition.y - (mTexture->minfo.Height / 2 * mScale.y);
	return r;
}

void Sprite::Draw()
{
	if (!mVisible)
		return;
	if (mTexture == nullptr)
		return;
	mIsUI ? mSprite->Begin(D3DXSPRITE_ALPHABLEND) : mSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_OBJECTSPACE);
	mSprite->SetTransform(&GetMatrix());
	vec3 center = { mPivot.x * mTexture->minfo.Width,mPivot.y * mTexture->minfo.Height, 0 };
	mSprite->Draw(mTexture->mtexture, nullptr, &center, nullptr, mColor);
	mSprite->End();
}
