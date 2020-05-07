#include "DXUT.h"
#include "Sprite.h"

Sprite::Sprite()
{
	sprite = nullptr;
	texture = nullptr;
	D3DXCreateSprite(DXUTGetD3D9Device(), &sprite);
}

Sprite::~Sprite()
{
	Renderer::getins()->RemoveRenderTarget(this);
}

void Sprite::SetTexture(wstring filepath)
{
	texture = TextureMNG::getins()->LoadTexture(filepath);
	AddRenderTarget();
}

void Sprite::AddRenderTarget()
{
	Renderer::getins()->AddRenderTarget(this);
}

RECT Sprite::GetRect()
{
	RECT r = { 0,0,0,0 };
	r.right = position.x + (texture->info.Width / 2 * scale.x);
	r.left = position.x - (texture->info.Width / 2 * scale.x);
	r.top = position.y - (texture->info.Height / 2 * scale.y);
	r.bottom = position.y + (texture->info.Height / 2 * scale.y);
	return r;
}

void Sprite::Draw()
{
	if (!visible)
		return;
	if (texture == nullptr)
		return;

	isUI ? sprite->Begin(D3DXSPRITE_ALPHABLEND) : sprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_OBJECTSPACE);
	sprite->SetTransform(&GetMatrix());
	Vec3 center = { pivot.x * texture->info.Width,pivot.y * texture->info.Height,0 };
	sprite->Draw(texture->texture, nullptr, &center, nullptr, color);
	sprite->End();
}
