#pragma once
#include "Singleton.h"
class Texture
{
public:
	D3DXIMAGE_INFO _info; // ������ ��ġ�� ���� ���ڿ�!
	wstring _filename; // �޾ƿ� �̹����� ����(info)
	LPDIRECT3DTEXTURE9 _texture; // ȭ�鿡 ���̴� �ؽ��ĸ� �Ҵ��� ģ��
};
class TextureMNG : public Singleton<TextureMNG>
{
private:
	list<Texture*>	_texturepool; // �̹����� �Ҵ��� �ؽ��ĵ��� ���� �����̳�
public:
	Texture* LoadTexture(wstring path); // texture�� wstring�� ����Ͽ� ���Ͽ��� ����� �Լ�
};