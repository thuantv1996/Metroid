#include "Ripper.h"


Ripper::Ripper()
{
	this->_type = RIPPER;
}


Ripper::~Ripper()
{
	free(lstAction);
}
void Ripper::Draw(float time)
{
	if (!isDead)
	{
		lstAction[0].Draw(D3DXVECTOR3(_x, _y, 0), RIGHT, time);
	}
}
void Ripper::Update(float time)
{
	_dx = _vx*time;
	_x += _dx;
}
void Ripper::SetAction()
{
	lstAction = new Animation[1];
	lstAction[0].Create( PATH_RIPPER, 16, 10, 1,1.0f/60, RIGHT);
}
void Ripper::OnCollision(GameplayObject* obj, int nx, int ny)
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
	case WALL:
		_vx = -_vx;
		break;
	default:
		break;
	}
}
void Ripper::Init()
{
	this->_width = 16;
	this->_height = 10;
	this->_vx = 30;
	SetAction();
}

