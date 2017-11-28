#include "Sknee.h"


Sknee::Sknee()
{
	this->_type = SKREE;
}


Sknee::~Sknee()
{
	free(lstAction);
}

void Sknee::Draw(float time)
{
	if (!isDead)
	{
		lstAction[curAction].Draw(D3DXVECTOR3(_x, _y, 0), RIGHT, time);
	}
}
void Sknee::Update(float time)
{
	float xFolow = MetroidChacracter::getInstance()->_x;
	float yFolow = MetroidChacracter::getInstance()->_y;
	if (abs(xFolow - _x) <= 25)
	{
		isfolow = true;
		Attack();
	}
	if (isfolow)
	{
		if (XCenter() > MetroidChacracter::getInstance()->XCenter())
		{
			_vx = -VX_SKNEE;
		}
		else
		if (XCenter() < MetroidChacracter::getInstance()->XCenter())
		{
			_vx = VX_SKNEE;
		}
		else
		{
			_vx = 0;
		}
		_vy = VY_SKNEE;
	}
	else
	{
		_vx = 0;
		_vy = 0;
	}
	_dx = _vx*time;
	_dy = _vy*time;
	_x += _dx;
	_y += _dy;
}
void Sknee::SetAction()
{
	lstAction = new Animation[2];
	lstAction[SKNEE_BEGIN].Create(PATH_SKNEE, 54, 26, 3, 1.0f/3, RIGHT);
	lstAction[SKNEE_ATTACK].Create(PATH_SKNEE, 54, 26, 3, 1.0f/6, RIGHT);
}
void Sknee::OnCollision(GameplayObject* obj, int nx, int ny)
{
	switch (obj->_type)
	{
	case BULLET:
		HP -= 5;
		if (HP == 0)
		{
			this->isDead = true;
		}
		break;
	case GROUND:
		isDead = true;
		skree_bullet = new BulletOfSkree(XCenter(), Bottom(), 60, 0);
		skree_bullet = new BulletOfSkree(XCenter(), Bottom(), 45, 45);
		skree_bullet = new BulletOfSkree(XCenter(), Bottom(), 0, 60);
		skree_bullet = new BulletOfSkree(XCenter(), Bottom(), -60, 0);
		skree_bullet = new BulletOfSkree(XCenter(), Bottom(), -45, 45);
		// viet ham tao ra dan no;
		break;
	default:
		break;
	}
}
void Sknee::Init()
{
	SetAction();
	Begin();
	_vx = 0;
	_vy = 0;
	_height = HEIGHT_SKNEE;
	_width = WIDTH_SKNEE;
	isDead = false;
}
void Sknee::Begin()
{
	curAction = SKNEE_BEGIN;
}
void Sknee::Attack()
{
	curAction = SKNEE_ATTACK;
}
