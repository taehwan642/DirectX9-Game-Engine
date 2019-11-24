#pragma once
#include "Type.h"
class Texture2D
{
public:
	D3DXIMAGE_INFO _info;
	wstring filename;
	LPDIRECT3DTEXTURE9 _texture;
};

class TextMNG : public SingleTon <TextMNG>
{
public:
	Texture2D* LoadTexture(wstring path);
private:
	list<Texture2D*> _texturepool;
};