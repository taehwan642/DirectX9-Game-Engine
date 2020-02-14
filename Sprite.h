#pragma once
#include "Node.h"
#include "Texture.h"
class Sprite : public Node
{
public:
	Sprite(); // ������
	~Sprite(); // �Ҹ���
	RECT GetRect(); // RECT�� ���ϴ� �Լ�
	Texture* texture; // Sprite�� ������ �ִ� texture
	void SetTexture(wstring filename); // texture�� �������ִ� �Լ�
	void AddRenderTarget(); // sprite�� ������Ű�� �ϴ� �Լ�
	void Render() override; // sprite�� �����ϴ� �Լ�
};

