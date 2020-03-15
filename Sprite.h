#pragma once
#include "Node.h"
#include "Texture.h"
#include "Renderer.h"	
class Sprite : public Node
{
public:
	Texture* mTexture;
	LPD3DXSPRITE mSprite;
	Sprite();
	~Sprite();
	void SetTexture(wstring path);
	void AddRendertarget();
	RECT GetRect();
	void Draw() override;
};

