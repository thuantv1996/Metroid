#include "MyCamera.h"


MyCamera::MyCamera()
{
	D3DXMatrixIdentity(&mt);
}


MyCamera::~MyCamera()
{
}

void MyCamera::Update(float time)
{
	if (MetroidChacracter::getInstance()->XCenter() < XCenter() && MetroidChacracter::getInstance()->_vx>0)
	{
		return;
	}
	// xet cac vi tri cho phep camera di chuyen theo chieu doc
	if (this->_x >= 2560)
	{
		_x = 2560;
		isUp = true;
	}
	else
	{
		isUp = false;
	}
	if (!isUp)
	{
		this->_vx = MetroidChacracter::getInstance()->_vx;
		this->_vy = 0;
	}
	else
	{
		this->_vy = MetroidChacracter::getInstance()->_vy;
		this->_vx = 0;
	}
	_x += _vx*time;
	_y += _vy*time;
	// xet nhung vi tri ma tai do camera khong the di chuyen duoc nua
	if (_y <= 240)
	{
		_y = 240;
	}
	if (_x <= 256)
	{
		_x = 256;
	}
}
void MyCamera::Draw(float time)
{
	mt._41 = -_x;
	mt._42 = _y;
	D3DXVECTOR4 pos;
	// draw object
}
D3DXMATRIX MyCamera::getMatrix()
{
	return mt;
}