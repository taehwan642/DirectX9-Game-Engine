#pragma once
#include "SingleTon.h"

class Texture
{
public:
	wstring _filename; // ������ ��ġ�� ���� ���ڿ�!
	D3DXIMAGE_INFO _info; // �޾ƿ� �̹����� ����(info)
	IDirect3DTexture9* _texture; // ȭ�鿡 ���̴� �ؽ��ĸ� �Ҵ��� ģ��
};

class TextureMNG : SingleTon<TextureMNG>
{
private:
	list<Texture*> _texturepool; // �̹����� �Ҵ��� �ؽ��ĵ��� ���� �����̳�
public:
	Texture* LoadTexture(wstring path); // texture�� wstring�� ����Ͽ� ���Ͽ��� ����� �Լ�
};
