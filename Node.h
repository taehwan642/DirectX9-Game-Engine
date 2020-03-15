#pragma once
class Node
{
public:
	vec2 mScale;
	vec2 mPosition;
	vec2 mPivot;
	vec2 nv;
	float mRotation;
	bool mVisible;
	bool mIsUI;
	color mColor;
	int mLayer;
	D3DXMATRIX GetMatrix();
	Node();
	virtual ~Node() {};
	virtual void Draw() {};
	virtual void Update() {};
};

