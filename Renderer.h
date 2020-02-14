#pragma once
#include "Singleton.h"
#include "Node.h"
class Renderer :
	public Singleton<Renderer>
{
public:
	void AddRenderTarget(Node* node); // ���� �����̳ʿ� ���ϴ� ��ü�� �ִ� �Լ�
	void RemoveRenderTarget(Node* node); // ���� �����̳ʿ� ���ϴ� ��ü�� ���� �Լ�
	void Render(); // ���� �����̳� �� ��ü���� Ȱ��ȭ, �� ������Ű�� �Լ�
private:
	list<Node*> _rendertargets; // ���� �����̳�
	static bool Comp(Node* a, Node* b); 
};

