#pragma once
class Node
{
public:
	Node();
	virtual ~Node() {};

	Vector2 _position;
	Vector2 _scale;
	Vector2 _pivot; // ¿ä°Å!
	float _rotation;
	bool _visible;
	Color _color;
	int _layer;
	bool _isUI;
	Vector2 _nv;


	D3DXMATRIX GetMatrix();

	virtual void Update() {};
	virtual void Render() {};

};

