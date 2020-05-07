#pragma once
#include "Director.h"
#include "Node.h"
#include "Texture.h"
#include "Renderer.h"
class Sprite :
	public Node
{
public:
	Texture* texture;
	LPD3DXSPRITE sprite;
	Sprite();
	~Sprite();
	void SetTexture(wstring filepath);
	void AddRenderTarget();
	RECT GetRect();
	void Draw() override;
};

