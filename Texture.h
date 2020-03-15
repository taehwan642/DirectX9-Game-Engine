#pragma once
#include "Singleton.h"
class Texture
{
public:
	D3DXIMAGE_INFO minfo;
	LPDIRECT3DTEXTURE9 mtexture;
	wstring mfilename;
};

class TexMNG : public Singleton<TexMNG>
{
private:
	list<Texture*> ltexturepool;
public:
	Texture* LoadTexture(wstring path);
};
