#include "DXUT.h"
#include "Node.h"

Node::Node()
{
	// �ʱ�ȭ
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
	D3DXMATRIX m; // m �̶�� ��� ����
	D3DXMatrixIdentity(&m); // ���� ��ķ� ��ȯ
	D3DXMatrixTransformation2D(&m, nullptr, 0, &_scale, nullptr, _rotation, &_position); // m�̶� ��Ŀ� scale rotation position ���� ����
	return m; // ��ü�� scale rotation position�� ������ ������ �ִ� m ����
}
