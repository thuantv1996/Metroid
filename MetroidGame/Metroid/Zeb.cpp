#include "Zeb.h"


Zeb::Zeb()
{
	this->_type = ZEB;
}


Zeb::~Zeb()
{
}

void Zeb::Init()
{
	Action.Create("src//img//enemy//zeb//Zeb.png",18,18,2,1.0f/60,RIGHT);
	isAttack = false;
	_width = 18;
	_height = 18;
	_vy = -VY_ZEB;
	_vx = 0;
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
		}
		break;
	default:
		break;
	}
}