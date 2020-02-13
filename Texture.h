#pragma once
#include "SingleTon.h"

class Texture
{
public:
	wstring _filename; // 파일의 위치를 담을 문자열!
	D3DXIMAGE_INFO _info; // 받아온 이미지의 정보(info)
	IDirect3DTexture9* _texture; // 화면에 보이는 텍스쳐를 할당할 친구
};

class TextureMNG : SingleTon<TextureMNG>
{
private:
	list<Texture*> _texturepool; // 이미지에 할당한 텍스쳐들을 모은 컨테이너
public:
	Texture* LoadTexture(wstring path); // texture를 wstring을 사용하여 파일에서 끄집어낼 함수
};
