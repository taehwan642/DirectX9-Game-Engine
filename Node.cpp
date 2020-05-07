#include "DXUT.h"
#include "Node.h"

Node::Node()
{
	position = { 0,0 };
	scale = { 1,1 };
	pivot = { 0.5f,0.5f };
	nv = { 0,0 };
	color = 0xffffffff;
	layer = 0;
	rotation = 0;
	visible = true;
	isUI = false;
}

D3DXMATRIX Node::GetMatrix()
{
	D3DXMATRIX m;
	D3DXMatrixIdentity(&m);
	D3DXMatrixTransformation2D(&m, nullptr, 0, &scale, nullptr, rotation, &position);
	return m;
}

