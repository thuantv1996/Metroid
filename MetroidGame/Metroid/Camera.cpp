#include "Camera.h"
#include "GraphicsDevice.h"

Camera::Camera(){
	D3DXMatrixIdentity(&mt);
}
Camera* Camera::instance = 0;
Camera* Camera::getInstance()
{
	if (!instance)
	{
		instance = new Camera();
	}
	return instance;
}

void Camera::Update(float time)
{
	if (MetroidChacracter::getInstance()->XCenter() < XCenter() && MetroidChacracter::getInstance()->_vx>0)
	{
		return;
	}
	// xet cac vi tri cho phep camera di chuyen theo chieu doc
	if (this->_x>= 2560)
	{
		_x=2560;
		vCam = true;
	}
	else
	{
		vCam = false;
	}
	if (!vCam)
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
	/*if (_y <= 240)
	{
		_y = 240;
	}
	if (_x <= 256)
	{
		_x = 256;
	}*/
	mt._41 = - _x;
	mt._42 = _y;
	mt._22 = -1;
	// update object
	UpdateObject(time);
}
void Camera::Draw(float time)
{
	for (int i = 0; i < listObjectOnCamera.size(); i++)
	{
		listObjectOnCamera[i]->Draw(time);
	}
	for (int i = 0; i < listBulletOnCamera.size(); i++)
	{
		if (listBulletOnCamera[i]->isDead)
		{
			listBulletOnCamera.erase(listBulletOnCamera.begin()+i);
			i--;
			continue;
		}
		listBulletOnCamera[i]->Draw(time);
	}
}
void Camera::OnCollision(GameplayObject* o,float nx,float ny)
{
	// code va cham
}
void Camera::AddObject(GameplayObject* o)
{
	if (o->_type == BULLET|| o->_type == BULLET_ENEMY)
	{
		listBulletOnCamera.push_back(o);
	}
	else
	{
		listObjectOnCamera.push_back(o);
	}
	
}
void Camera::UpdateObject(float time)
{
	for (int i = 0; i < listBulletOnCamera.size(); i++)
	{
		listBulletOnCamera[i]->Update(time);
	}
	for (int i = 0; i < listObjectOnCamera.size(); i++)
	{
		listObjectOnCamera[i]->Update(time);
	}
}
D3DXMATRIX Camera::getMatrix()
{
	return mt;
}



