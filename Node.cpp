#include "DXUT.h"
#include "Node.h"

Node::Node()
{
	_position = { 0,0 };
	_scale = { 1,1 };
	_pivot = { 0.5f,0.5f };
	_rotation = 0;
	_visible = true;
	_color = 0xffffffff;
	_layer = 0;
	isUI = false;
	v = { 0,0 };
}


D3DXMATRIX Node::GetMatrix()
{
	D3DXMATRIX matrix;
	D3DXMatrixIdentity(&matrix);
	D3DXMatrixTransformation2D(&matrix, nullptr, 0, &_scale, nullptr, _rotation, &_position);
	return matrix;
}

