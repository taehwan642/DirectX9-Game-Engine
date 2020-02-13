#pragma once
class Node
{
public:
	Node(); // 초기화 용도로 사용하는 생성자
	virtual ~Node() {}; // 가상 소멸자

	Vector2 _position; // 현재 객체의 위치
	Vector2 _scale; // 현재 객체의 크기
	float _rotation; // 현재 객체의 각도
	int _layer; // 현재 객체의 레이어
	bool _active; // 현재 객체가 화면에 출력되고있나
	bool _isUI; // 현재 객체가 UI 의 목적으로 사용되고있나 (User Interface)
	Color _color; // 현재 객체의 색깔
	Vector2 _nv; // 객체가 가진 법선벡터(Normal Vector)

	D3DXMATRIX GetMatrix(); // 객체의 크기, 각도, 위치를 담아 행렬로 변환하는 작업을 해주는 함수
	
	virtual void Update() {}; // 객체의 업데이트
	virtual void Render() {}; // 객체의 텍스쳐 렌더
};

