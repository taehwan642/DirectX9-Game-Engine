#pragma once
class Scene
{
public:
	Scene();
	virtual ~Scene();

	virtual void Create() {}; // Init이랑 똑같음
	virtual void Update() {};
	virtual void OnExit() {}; // Scene이 꺼질때
};
