#include "DXUT.h"
#include "Renderer.h"

bool Renderer::Comp(Node* a, Node* b)
{
	return (a->layer < b->layer);
}

void Renderer::AddRenderTarget(Node* n)
{
	if (find(rendertargets.begin(), rendertargets.end(), n) != rendertargets.end())
		return;
	rendertargets.push_back(n);	
	rendertargets.sort(Comp);
}

void Renderer::RemoveRenderTarget(Node* n)
{
	rendertargets.remove(n);
}

void Renderer::Render()
{
	for (auto it : rendertargets)
	{
		it->Update();
		it->Draw();
	}
}
