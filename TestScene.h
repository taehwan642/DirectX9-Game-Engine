#pragma once
#include "Scene.h"
#include "Sprite.h"
class TestScene : public Scene
{
public:
	void Create() override;
	void Update() override;
	void OnExit() override;
	Sprite* testSprite;
};

