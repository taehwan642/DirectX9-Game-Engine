#pragma once
#include "Singleton.h"
class Texture
{
public:
	wstring filename;
	D3DXIMAGE_INFO info;
	IDirect3DTexture9* texture;
};

class TextureMNG : 
	public Singleton<TextureMNG>
{
private:
	list<Texture*> texturepool;
public:
	Texture* LoadTexture(wstring filepath);
};