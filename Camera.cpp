#include "DXUT.h"
#include "Camera.h"

void Camera::CameraInit()
{
	D3DXMatrixOrthoLH(&OM, Screen_Width, -Screen_Height, 0, 1);
	D3DXMatrixIdentity(&IM);
	mCameraSize = 1;
	mCampos = { Screen_Width / 2, Screen_Height / 2 };
}

void Camera::Update()
{
	VM = D3DXMATRIX
	{
		1,0,0,0,
		0,1,0,0,
		0,0,1,0,
		-mCampos.x,-mCampos.y,0,1
	};
	D3DXMatrixOrthoLH(&OM, Screen_Width, -Screen_Height, 0, 1);
	DXUTGetD3D9Device()->SetTransform(D3DTS_PROJECTION, &OM);
	DXUTGetD3D9Device()->SetTransform(D3DTS_WORLD, &IM);
	DXUTGetD3D9Device()->SetTransform(D3DTS_VIEW, &VM);
}
