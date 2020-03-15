#include "DXUT.h"
#include "Node.h"

D3DXMATRIX Node::GetMatrix()
{
	D3DXMATRIX m;
	D3DXMatrixIdentity(&m);
	D3DXMatrixTransformation2D(&m, nullptr, 0, &mScale, nullptr, mRotation, &mPosition);
	return m;
}

Node::Node()
{
	mScale = { 1,1 };
	mPosition = { 0,0 };
	mPivot = { 0.5f,0.5f };
	nv = { 0,0 };
	mRotation = 0;
	mVisible = true;
	mIsUI = false;
	mColor = 0xffffffff;
	mLayer = 0;
}
