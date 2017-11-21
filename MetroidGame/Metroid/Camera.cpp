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
	if (_y <= 240)
	{
		_y = 240;
	}
	if (_x <= 256)
	{
		_x = 256;
	}
	mt._41 = - _x;
	mt._42 = -_y;
	// update object
	UpdateObject(time);
	// delete obj
	DeleteObject();
}
void Camera::Draw(float time)
{
	// ve object
	for (int i = 0; i < lstItem.size(); i++)
	{
		lstItem[i]->Draw(time);
	}
	for (int i = 0; i < lstEnemy.size(); i++)
	{
		lstEnemy[i]->Draw(time);
	}
}
void Camera::OnCollision(GameplayObject* o,float nx,float ny)
{
	// code va cham
}
RECT Camera::getRect()
{
	RECT r;
	r.left = _x;
	r.top = _y;
	r.right = r.left + _width;
	r.bottom = r.top + _height;
	return r;
}
vector<GameplayObject*> Camera::GetListItem()
{
	return lstItem;
}
vector<GameplayObject*> Camera::GetListEnemy()
{
	return lstEnemy;
}
vector<GameplayObject*> Camera::GetListGround()
{
	return lstGround;
}
bool Camera::findObject(GameplayObject* o)
{
	for (int i = 0; i < lstItem.size(); i++)
	{
		if (o == lstItem[i])
		{
			return true;
		}
	}
	for (int i = 0; i < lstEnemy.size(); i++)
	{
		if (o == lstEnemy[i])
		{
			return true;
		}
	}
	for (int i = 0; i < lstGround.size(); i++)
	{
		if (o == lstGround[i])
		{
			return true;
		}
	}
	return false;
}
void Camera::AddObject(GameplayObject* o)
{
	switch (o->_type)
	{
	case GROUND:
	case WALL:
		lstGround.push_back(o);
		break;
	case BOMB:
	case BEAM:
	case ROCKET:
	case DOOR:
	case MARU:
	case TUBE:
	case BULLET:
		lstItem.push_back(o);
		break;
	case RIO:
	case RIPPER:
	case SKREE:
	case ZOMMER:
	case LAVA:
	case ZEB:
		lstEnemy.push_back(o);
		break;
	}
}
void Camera::DeleteObject()
{
	for (int i = 0; i < lstItem.size(); i++)
	{
		if (lstItem[i]->isDead)
		{
			delete(lstItem[i]);
			lstItem.erase(lstItem.begin() + i);
			i--;
			continue;
		}
		float nx = 0, ny = 0;
		if (!CColision::mSweptAABB(this, lstItem[i], nx, ny,1.0f/24))
		{
			lstItem.erase(lstItem.begin() + i);
			i--;
		}
	}
	for (int i = 0; i < lstEnemy.size(); i++)
	{
		if (lstEnemy[i]->isDead)
		{
			delete(lstEnemy[i]);
			lstEnemy.erase(lstEnemy.begin() + i);
			i--;
			continue;
		}
		float nx = 0, ny = 0;
		if (!CColision::mSweptAABB(this, lstEnemy[i], nx, ny, 1.0f / 24))
		{
			lstEnemy[i]->_x = lstEnemy[i]->_xOld;
			lstEnemy[i]->_y = lstEnemy[i]->_yOld;
			lstEnemy[i]->Init();
			lstItem.erase(lstEnemy.begin() + i);
			i--;
			
		}

	}
	for (int i = 0; i < lstGround.size(); i++)
	{
		float nx = 0, ny = 0;
		if (!CColision::mSweptAABB(this, lstGround[i], nx, ny, 1.0f / 24))
		{
			lstGround.erase(lstGround.begin() + i);
			i--;
		}
	}
}
void Camera::UpdateObject(float time)
{
	for (int i = 0; i < lstItem.size(); i++)
	{
		lstItem[i]->Update(time);
	}
	for (int i = 0; i < lstEnemy.size(); i++)
	{
		lstEnemy[i]->Update(time);
	}
	for (int i = 0; i < lstGround.size(); i++)
	{
		lstGround[i]->Update(time);
	}
}
D3DXMATRIX Camera::getMatrix()
{
	return mt;
}



