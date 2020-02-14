#pragma once
#include "Node.h"
#include "Texture.h"
class Sprite : public Node
{
public:
	Sprite(); // 생성자
	~Sprite(); // 소멸자
	RECT GetRect(); // RECT를 구하는 함수
	Texture* texture; // Sprite가 가지고 있는 texture
	void SetTexture(wstring filename); // texture를 세팅해주는 함수
	void AddRenderTarget(); // sprite를 렌더시키게 하는 함수
	void Render() override; // sprite를 렌더하는 함수
};

