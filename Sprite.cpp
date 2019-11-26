#include "DXUT.h"
#include "Sprite.h"

Sprite::Sprite()
{
	_aniNum;
	_timer = 0;
	_nowFrame = 0;
	texture = nullptr;
}

Sprite::~Sprite()
{

}