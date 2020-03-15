#pragma once
#include "Scene.h"
#include "Sprite.h"
#include "Camera.h"
class GameScene : public Scene
{
public:
	Sprite* sp;
	float x, y;
	void Init() override;
	void Update() override;
	void Exit() override;
};

