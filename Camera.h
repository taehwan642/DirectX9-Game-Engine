#pragma once
#include "Singleton.h"
class Camera : public Singleton<Camera>
{
private:
	D3DXMATRIX OM;
	D3DXMATRIX IM;
	D3DXMATRIX VM;
	vec2 mCampos;
	float mCameraSize;
public:
	void CameraInit();
	void Update();
	void SetPos(vec2 v) { mCampos = v; };
	vec2 GetPos() { return mCampos; };
	void SetSize(float f) { mCameraSize = f; };
	float GetSize() { return mCameraSize; };
};

