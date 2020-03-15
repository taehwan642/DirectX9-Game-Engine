#pragma once
#include "Singleton.h"
#include "Node.h"
class Renderer :
	public Singleton<Renderer>
{
private:
	list<Node*> lrendertargets;
	static bool Comp(Node* a, Node* b);
public:
	void AddRenderTarget(Node* n);
	void DeleteRenderTarget(Node* n);
	void Render();
};

