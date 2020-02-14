#include "DXUT.h"
#include "Renderer.h"
void Renderer::AddRenderTarget(Node* node)
{
	if (find(_rendertargets.begin(), _rendertargets.end(), node) != _rendertargets.end())
		return; // ����ó��
	_rendertargets.push_back(node); // ���� �����̳ʿ� node �� ����
}

void Renderer::RemoveRenderTarget(Node* node)
{
	_rendertargets.remove(node); // ���� �����̳ʿ��� node �� ��
}

void Renderer::Render()
{
	_rendertargets.sort(Comp); // ���� �����̳ʸ� �Լ� �����͸� ����� Comp �Լ��� ȣ���� ������
	for (auto it : _rendertargets) // ���� �����̳� �� element���� it�̶�� Ī��
	{
		it->Render(); // it�� Render ����
		it->Update(); // it�� Update ����
	}
}

bool Renderer::Comp(Node* a, Node* b) // ������ �����ִ� �Լ�
{
	return (a->_layer < b->_layer);
}