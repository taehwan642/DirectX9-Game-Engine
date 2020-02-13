#include "DXUT.h"
#include "Texture.h"

Texture* TextureMNG::LoadTexture(wstring path)
{
	// texturepool 속에 있는 element 들을 각각 검사 시작
	for (auto it : _texturepool)  // it 은 texturepool 속 element에 해당됨
	{
		if (it->_filename == path) // 만약 검사 도중 texturepool 속 element들 중 하나가 불러오고 싶은 사진과 일치한다면 element 리턴,
			return it;
	}
	// 일치하는게 없다면 계속 진행
	auto route = L"res/" + path; // 파일을 찾을 루트를 만들건데, 무조건 엔진 파일 속 res 란 파일이 있어야 함.
	Texture* texture = new Texture();	// 텍스쳐 객체를 만들고
	texture->_filename = path; // 텍스쳐 객체 속 _filename에 path를 넣어줌
	// isFail == 이미지를 출력이 가능한지 알려주는 변수, CreateTextureFromFileEX는 말그대로 파일속에서 지정한 루트를 통해 텍스쳐를 꺼내옴.
	auto isFail = D3DXCreateTextureFromFileEx(DXUTGetD3D9Device(), route.c_str(), -2, -2, ACL_REVISION1, 0, D3DFORMAT::D3DFMT_A8B8G8R8
		, D3DPOOL::D3DPOOL_MANAGED, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, &texture->_info, nullptr, &texture->_texture);
	
	if (FAILED(isFail)) // 만약 실패했을시엔
	{
		wcout << "Load Failed " << route.c_str() << endl; // 실패했습니다 콘솔에 출력
		return nullptr; // nullptr을 리턴해, 텍스쳐를 나타내지 않음
	}
	else
	{
		wcout << "Load Complete " << route.c_str() << endl; // 성공했습니다 콘솔에 출력
		_texturepool.push_back(texture); // 텍스쳐를 모으는 컨테이너 속에 texture를 넣음.
		return texture; // 텍스쳐를 리턴해, path에서 불러온 텍스쳐를 띄움
	}
}
