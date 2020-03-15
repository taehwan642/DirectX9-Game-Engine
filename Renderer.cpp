#include "DXUT.h"
#include "Renderer.h"

bool Renderer::Comp(Node* a, Node* b)
{
	return a->mLayer < b->mLayer;
}

void Renderer::AddRenderTarget(Node* n)
{
	if (find(lrendertargets.begin(), lrendertargets.end(), n) != lrendertargets.end())
		return;
	lrendertargets.push_back(n);
	lrendertargets.sort(Comp);
}

void Renderer::DeleteRenderTarget(Node* n)
{
	lrendertargets.remove(n);
}

void Renderer::Render()
{	
	for (auto it : lrendertargets)
	{
		it->Draw();
		it->Update();
	}
}
