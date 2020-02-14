#include "DXUT.h"
#include "Renderer.h"
void Renderer::AddRenderTarget(Node* node)
{
	if (find(_rendertargets.begin(), _rendertargets.end(), node) != _rendertargets.end())
		return; // 예외처리
	_rendertargets.push_back(node); // 렌더 컨테이너에 node 를 넣음
}

void Renderer::RemoveRenderTarget(Node* node)
{
	_rendertargets.remove(node); // 렌더 컨테이너에서 node 를 뺌
}

void Renderer::Render()
{
	_rendertargets.sort(Comp); // 렌더 컨테이너를 함수 포인터를 사용한 Comp 함수를 호출해 정렬함
	for (auto it : _rendertargets) // 렌더 컨테이너 속 element들을 it이라고 칭함
	{
		it->Render(); // it의 Render 시작
		it->Update(); // it의 Update 시작
	}
}

bool Renderer::Comp(Node* a, Node* b) // 정렬을 도와주는 함수
{
	return (a->_layer < b->_layer);
}