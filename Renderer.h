#pragma once
#include "Type.h"
#include "Node.h"
class Renderer : public SingleTon<Renderer>
{
private:
	list<Node*> _rendertargets;
	static bool Comp(Node* a, Node* b);
public:
	void AddRenderTarget(Node* node);
	void RemoveRenderTarget(Node* node);
	void Render();
};

