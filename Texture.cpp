#include "DXUT.h"
#include "Texture.h"

Texture* TexMNG::LoadTexture(wstring path)
{
	for (auto it : ltexturepool)
	{
		if (it->mfilename == path)
			return it;
	}

	auto route = L"res/" + path;
	Texture* texture = new Texture();
	texture->mfilename = path;

	auto isFail = D3DXCreateTextureFromFileEx(DXUTGetD3D9Device(), route.c_str(), -2, -2, 1, 0,
		D3DFORMAT::D3DFMT_A8B8G8R8, D3DPOOL_MANAGED, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, &texture->minfo, nullptr, &texture->mtexture);
	if (FAILED(isFail))
	{
		wcout << "LOAD FAIL " << route << endl;
		delete texture;
		return nullptr;
	}
	else
	{
		wcout << "LOAD COMPLETE " << route << endl;
		ltexturepool.push_back(texture);
		return texture;
	}
}
