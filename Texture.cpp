#include "DXUT.h"
#include "Texture.h"

Texture* TextureMNG::LoadTexture(wstring path)
{
	// texturepool �ӿ� �ִ� element ���� ���� �˻� ����
	for (auto it : _texturepool)  // it �� texturepool �� element�� �ش��
	{
		if (it->_filename == path) // ���� �˻� ���� texturepool �� element�� �� �ϳ��� �ҷ����� ���� ������ ��ġ�Ѵٸ� element ����,
			return it;
	}
	// ��ġ�ϴ°� ���ٸ� ��� ����
	auto route = L"res/" + path; // ������ ã�� ��Ʈ�� ����ǵ�, ������ ���� ���� �� res �� ������ �־�� ��.
	Texture* texture = new Texture();	// �ؽ��� ��ü�� �����
	texture->_filename = path; // �ؽ��� ��ü �� _filename�� path�� �־���
	// isFail == �̹����� ����� �������� �˷��ִ� ����, CreateTextureFromFileEX�� ���״�� ���ϼӿ��� ������ ��Ʈ�� ���� �ؽ��ĸ� ������.
	auto isFail = D3DXCreateTextureFromFileEx(DXUTGetD3D9Device(), route.c_str(), -2, -2, ACL_REVISION1, 0, D3DFORMAT::D3DFMT_A8B8G8R8
		, D3DPOOL::D3DPOOL_MANAGED, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, &texture->_info, nullptr, &texture->_texture);
	
	if (FAILED(isFail)) // ���� ���������ÿ�
	{
		wcout << "Load Failed " << route.c_str() << endl; // �����߽��ϴ� �ֿܼ� ���
		return nullptr; // nullptr�� ������, �ؽ��ĸ� ��Ÿ���� ����
	}
	else
	{
		wcout << "Load Complete " << route.c_str() << endl; // �����߽��ϴ� �ֿܼ� ���
		_texturepool.push_back(texture); // �ؽ��ĸ� ������ �����̳� �ӿ� texture�� ����.
		return texture; // �ؽ��ĸ� ������, path���� �ҷ��� �ؽ��ĸ� ���
	}
}
