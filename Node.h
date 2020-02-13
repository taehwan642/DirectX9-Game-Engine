#pragma once
class Node
{
public:
	Node(); // �ʱ�ȭ �뵵�� ����ϴ� ������
	virtual ~Node() {}; // ���� �Ҹ���

	Vector2 _position; // ���� ��ü�� ��ġ
	Vector2 _scale; // ���� ��ü�� ũ��
	float _rotation; // ���� ��ü�� ����
	int _layer; // ���� ��ü�� ���̾�
	bool _active; // ���� ��ü�� ȭ�鿡 ��µǰ��ֳ�
	bool _isUI; // ���� ��ü�� UI �� �������� ���ǰ��ֳ� (User Interface)
	Color _color; // ���� ��ü�� ����
	Vector2 _nv; // ��ü�� ���� ��������(Normal Vector)

	D3DXMATRIX GetMatrix(); // ��ü�� ũ��, ����, ��ġ�� ��� ��ķ� ��ȯ�ϴ� �۾��� ���ִ� �Լ�
	
	virtual void Update() {}; // ��ü�� ������Ʈ
	virtual void Render() {}; // ��ü�� �ؽ��� ����
};

