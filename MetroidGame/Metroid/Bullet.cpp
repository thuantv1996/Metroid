#include "Bullet.h"


Bullet::Bullet()
{
	this->_type = BULLET;
}


Bullet::~Bullet()
{
}

void Bullet::Draw(float time)
{
	if (!isDead)
	{
		lstAction->Draw(D3DXVECTOR3(_x, _y, 0), RIGHT, time);
	}
}
void Bullet::Update(float time)
{
	total_time += time;
	float nx = 0, ny = 0;
	for (int i = 0; i < Camera::getInstance()->listObjectOnCamera.size(); i++)
	{
		if (CColision::mSweptAABB(this, Camera::getInstance()->listObjectOnCamera[i], nx, ny, time) != 1.0f)
		{
			Camera::getInstance()->listObjectOnCamera[i]->OnCollision(this, -nx, -ny);
		}
	}
	_dx = _vx*time;
	_dy = _vy*time;
	_x += _dx;
	_y += _dy;
	if (total_time > TIME_FLY)
	{
		isDead = true;
	}
}
Bullet::Bullet(float xc, float yc, float vx, float vy, bool isrocket)
{
	this->_type = BULLET;
	lstAction = new Animation[2];
	if (vx != 0)
	{
		lstAction->Create("src//img//item//bullet.png", 4, 5, 1, 1.0f / 24, RIGHT);
		_width = 4;
		_height = 5;
	}
	else
	{
		lstAction->Create("src//img//item//bullet_v.png", 5, 4, 1, 1.0f / 24, RIGHT);
		_width = 5;
		_height = 4;
	}
	
	_x = xc-_width/2;
	_y = yc+_height/2;
	_vx = vx;
	_vy = -vy;
	total_time = 0;
	isDead = false;
	isRocket = isrocket;
	Camera::getInstance()->AddObject(this);
}

