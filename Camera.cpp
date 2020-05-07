#include "DXUT.h"
#include "Camera.h"

void Camera::CameraInit()
{
	D3DXMatrixOrthoLH(&OM, ScreenWidth, -ScreenHeight, 0, 1);
	D3DXMatrixIdentity(&IM);
	camerasize = 1;
}

void Camera::Update()
{
	VM = D3DXMATRIX
	{
		1,0,0,0,
		0,1,0,0,
		0,0,1,0,
		-campos.x,-campos.y,0,1
	};
	D3DXMatrixOrthoLH(&OM, ScreenWidth * camerasize, -ScreenHeight * camerasize, 0, 1);
	DXUTGetD3D9Device()->SetTransform(D3DTS_PROJECTION, &OM);
	DXUTGetD3D9Device()->SetTransform(D3DTS_WORLD, &IM);
	DXUTGetD3D9Device()->SetTransform(D3DTS_VIEW, &VM);
}
