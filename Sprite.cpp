#include "DXUT.h"
#include "Sprite.h"
#include "Director.h"
#include "Renderer.h"
Sprite::Sprite()
{
	texture = nullptr; // �ʱ�ȭ
}

Sprite::~Sprite()
{
	Renderer::Instance()->RemoveRenderTarget(this); // �Ҹ�ɶ� �� �ڽ��� ������Ű�� �ʰ� ��
}

void Sprite::SetTexture(wstring filename)
{
	texture = TextureMNG::Instance()->LoadTexture(filename); // �� �ڽ��� ������ �ִ� �ؽ��ĸ� ��� ������ ������� ����
	AddRenderTarget(); // ���� �� �� �ڽ��� ������Ŵ
}

void Sprite::AddRenderTarget()
{
	Renderer::Instance()->AddRenderTarget(this); // �� �ڽ��� �����ϰ� ��
}
RECT Sprite::GetRect()
{
	RECT r = { 0,0,0,0 };
	r.right = _position.x + (texture->_info.Width / 2 * _scale.x);
	r.left = _position.x - (texture->_info.Width / 2 * _scale.x);
	r.top = _position.y - (texture->_info.Height / 2 * _scale.y);
	r.bottom = _position.y + (texture->_info.Height / 2 * _scale.y);
	return r;
}
void Sprite::Render()
{

	if (!_visible) // ���� Ȱ������ ������ �������� �ʰ� ��
		return;
	if (texture == nullptr) // ���� �ؽ��İ� ������ �������� �ʰ� ��
		return;
	//���� UI��� ī�޶� ���� ������ ���� �ʰ� �ϰ�, UI�� �ƴ϶�� ī�޶��� ������ �ް� ��
	_isUI ? Director::Instance()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND) : Director::Instance()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_OBJECTSPACE);
	Director::Instance()->GetSprite()->SetTransform(&GetMatrix()); // ���� scale, rotation, position�� ����
	Vector3 center = { _pivot.x * texture->_info.Width,_pivot.y * texture->_info.Height,0 }; // ���� �߽����� ����
	Director::Instance()->GetSprite()->Draw(texture->_texture, nullptr, &center, nullptr, _color); // �� �ڽ��� �׸�
	Director::Instance()->GetSprite()->End(); // ���̻� �� �ڽ��� ������� �޸� �ս��� ���⿡ �׸� �׸�
}
