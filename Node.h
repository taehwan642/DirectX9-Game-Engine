#pragma once
class Node
{
public:
	Node();
	virtual ~Node() {};
	Vec2 position;
	Vec2 scale;
	Vec2 pivot;
	Vec2 nv;
	Color color;
	int layer;
	float rotation;
	bool visible;
	bool isUI;
	D3DXMATRIX GetMatrix();
	virtual void Draw() {};
	virtual void Update() {};
};

