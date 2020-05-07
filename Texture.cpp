#include "DXUT.h"
#include "Texture.h"

Texture* TextureMNG::LoadTexture(wstring filepath)
{
	for (auto it : texturepool)
	{
		if (it->filename == filepath)
			return it;
	}

	auto route = L"res/" + filepath;
	Texture* tex = new Texture();
	tex->filename = filepath;
	auto isFail = D3DXCreateTextureFromFileEx(DXUTGetD3D9Device(), route.c_str(), -2, -2, 1, 0, D3DFORMAT::D3DFMT_A8B8G8R8, D3DPOOL::D3DPOOL_MANAGED,
		D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, &tex->info, nullptr, &tex->texture);
	
	if (FAILED(isFail))
	{
		wcout << "LOAD FAIL " << route.c_str() << endl;
		delete tex;
		return nullptr;
	}
	else
	{
		wcout << "LOAD COMPLETE " << route.c_str() << endl;
		texturepool.push_back(tex);
		return tex;
	}
}
