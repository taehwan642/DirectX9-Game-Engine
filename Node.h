#pragma once
class Node
{
public:
	Node();
	virtual ~Node();
	
	Vec2 _position;
	Vec2 _scale;
	bool visible;

	virtual void Update() {};
	virtual void Draw() {};
};

