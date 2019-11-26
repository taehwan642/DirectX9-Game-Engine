#pragma once
#include "Node.h"
#include "Texture.h"
#include "Renderer.h"
#include "Director.h"

class Sprite : public Node
{
public:
	Sprite();
	~Sprite();

	void Create(wstring filename);
	void AddRenderTarget();

	bool Animation(wstring path, int frame, float delay, int aniNum);
	int _nowFrame;
	int _aniNum;
	float _timer;

	float GetDistance(Sprite* Target);
	void LookAt(Sprite* Target);
	bool Goto(Sprite* Target, float Speed);
	bool Goto(vector2 Target, float Speed);

	RECT GetRect();
	
	Texture2D* texture;

	void Draw() override;
};

