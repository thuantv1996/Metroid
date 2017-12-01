#include "Rio.h"
#include"ImgDeath.h"

Rio::Rio()
{
	this->_type = RIO;
}


Rio::~Rio()
{
}

void Rio::Init()
{
	Action = new Animation[2];
	Action[0].Create("src//img//enemy//rio//begin.png", 26, 21, 1, 1.0f / 2, RIGHT);
	Action[1].Create("src//img//enemy//rio//Rio.png", 52, 21, 2, 1.0f / 3, RIGHT);
	_width = 26;
	_height = 21;
	curAction = 0;
	HP = 15;
}
void Rio::Update(float time)
{
	float Cx = MetroidChacracter::getInstance()->XCenter();
	float Cy = MetroidChacracter::getInstance()->Top();
	if (!isAttack && (abs(Cx - XCenter()) <= 50))
	{
		isAttack = true;
		curAction = 1;
		_vy = VY_RIO;
		if (Cx >= XCenter())
		{
			_vx = VX_RIO;
		}
		else
		{
			_vx = -VX_RIO;
		}
	}
	if (Bottom() >= 3312)
	{
		_vy *= -1;
	}
	float nx = 0, ny = 0;
	for (int i = 0; i < Camera::getInstance()->listObjectOnCamera.size(); i++)
	{
		if (CColision::mSweptAABB(this, Camera::getInstance()->listObjectOnCamera[i], nx, ny,time)!=1.0f)
		{
			OnCollision(Camera::getInstance()->listObjectOnCamera[i], nx, ny);
		}
	}
	_dx = _vx*time;
	_dy = _vy*time;
	_x += _dx;
	_y += _dy;
}
void Rio::Draw(float time)
{
	if (!isDead)
		Action[curAction].Draw(D3DXVECTOR3(_x, _y, 0), RIGHT, time);
}
void Rio::OnCollision(GameplayObject* obj, int nx, int ny)
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
	case GROUND:
		_vy = -_vy;
		break;
	default:
		break;
	}
}