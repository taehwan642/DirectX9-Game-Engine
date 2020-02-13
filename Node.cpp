#include "DXUT.h"
#include "Node.h"

Node::Node()
{
	// 초기화
	_position = { 0,0 };
	_scale = { 0,0 };
	_rotation = 0;
	_layer = 0;
	_active = true;
	_isUI = false;
	_color = 0xffffffff;
	_nv = { 0,0 };
}

D3DXMATRIX Node::GetMatrix()
{
	D3DXMATRIX m; // m 이라는 행렬 선언
	D3DXMatrixIdentity(&m); // 단위 행렬로 변환
	D3DXMatrixTransformation2D(&m, nullptr, 0, &_scale, nullptr, _rotation, &_position); // m이란 행렬에 scale rotation position 전부 넣음
	return m; // 객체의 scale rotation position의 정보를 가지고 있는 m 리턴
}
