#pragma once
class Scene
{
public:
	Scene();
	virtual ~Scene();

	virtual void Create() {}; // Init�̶� �Ȱ���
	virtual void Update() {};
	virtual void OnExit() {}; // Scene�� ������
};
