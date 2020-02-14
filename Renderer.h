#pragma once
#include "Singleton.h"
#include "Node.h"
class Renderer :
	public Singleton<Renderer>
{
public:
	void AddRenderTarget(Node* node); // 렌더 컨테이너에 원하는 객체를 넣는 함수
	void RemoveRenderTarget(Node* node); // 렌더 컨테이너에 원하는 객체를 빼는 함수
	void Render(); // 렌더 컨테이너 속 객체들을 활성화, 즉 렌더시키는 함수
private:
	list<Node*> _rendertargets; // 렌더 컨테이너
	static bool Comp(Node* a, Node* b); 
};

