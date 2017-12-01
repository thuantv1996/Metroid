#include "BulletOfSkree.h"


BulletOfSkree::BulletOfSkree()
{
}

void BulletOfSkree::Draw(float time)
{
	if (!isDead)
	{
		lstAction.Draw(D3DXVECTOR3(_x, _y, 0), RIGHT, time);
	}
}
void BulletOfSkree::Update(float time)
{
	total_time += time;
	float nx = 0, ny = 0;
	if (CColision::mSweptAABB(this, MetroidChacracter::getInstance(), nx, ny, time) != 1.0f)
	{
		MetroidChacracter::getInstance()->OnCollision(this, nx, ny);
	}
	_x += _vx*time;
	_y += _vy*time;
	if (total_time > 1.0f)
	{
		isDead = true;
	}
}
BulletOfSkree::BulletOfSkree(float xc, float yc, float vx, float vy)
{
	this->_type = BULLET_ENEMY;
	_vx = vx;
	_vy = vy;
	_width = 7;
	_height = 7;
	lstAction.Create("src//img//item//bullet_of_skree.png", 7, 7, 1, 1.0f / 24, RIGHT);
	_x = xc - _width / 2;
	_y = yc + _height / 2;
	total_time = 0;
	Camera::getInstance()->AddObject(this);
}

BulletOfSkree::~BulletOfSkree()
{
}
