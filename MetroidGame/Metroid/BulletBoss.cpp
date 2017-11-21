#include "BulletBoss.h"


BulletBoss::BulletBoss(int x, int y, float speed, float angle)
{
	_type = BULLET;
	Speed = speed;
	Angle = angle;
	tTime = 0;
	Create(x, y, 7, 8);
	_vx = speed*cos(Angle);
	_vy = -speed;
	img.Create("src//img//boss//bullet_boss.png", 28, 8, 4, 1.0f / 24, RIGHT);
	Camera::getInstance()->AddObject(this);
}


BulletBoss::~BulletBoss()
{
}
void BulletBoss::Update(float time)
{
	
	tTime += time;
	if (tTime >= 2.0f)
	{
		isDead = true;
		return;
	}
	_vy+=3;
	_x += this->_vx*time;
	_y += _vy*time;
}
void BulletBoss::Draw(float time)
{
	img.Draw(D3DXVECTOR3(_x, _y, 0), RIGHT, time);
}