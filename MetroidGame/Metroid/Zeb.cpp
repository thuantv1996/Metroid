#include "Zeb.h"
#include"ImgDeath.h"

Zeb::Zeb()
{
	this->_type = ZEB;
}


Zeb::~Zeb()
{
}

void Zeb::Init()
{
	Action.Create("src//img//enemy//zeb//Zeb.png",16,16,2,1.0f/60,LEFT);
	isAttack = false;
	_width = 18;
	_height = 18;
	_vy = VY_ZEB;
	_vx = 0;
	HP = 15;
	isDead = false;
}
void Zeb::Update(float time)
{
	if (!isAttack)
	{
		if (MetroidChacracter::getInstance()->XCenter() <= _x)
		{
			_direct = LEFT;
		}
		else
		{
			_direct = RIGHT;
		}
		if (_y <= MetroidChacracter::getInstance()->_y)
		{
			_vx = VX_ZEB*_direct;
			isAttack = true;
			_vy = 0;
		}
	}
	float nx = 0, ny = 0;
	for (int i = 0; i < Camera::getInstance()->listObjectOnCamera.size(); i++)
	{
		if (CColision::mSweptAABB(this, Camera::getInstance()->listObjectOnCamera[i], nx, ny, time) != 1.0f)
		{
			OnCollision(Camera::getInstance()->listObjectOnCamera[i], nx, ny);
		}
	}
	_dx = _vx*time;
	_dy = _vy*time;
	_x += _dx;
	_y += _dy;
	
}
void Zeb::Draw(float time)
{
	if (!isDead)
		Action.Draw(D3DXVECTOR3(_x, _y, 0), _direct, time);
}
void Zeb::OnCollision(GameplayObject* obj, int nx, int ny)
{
	switch (obj->_type)
	{
	case BULLET:
		HP -= 5;
		if (HP == 0)
		{
			this->isDead = true;
			ImgDeath::getInstance()->Set(XCenter(), YCenter());
		}
		break;
	default:
		break;
	}
}