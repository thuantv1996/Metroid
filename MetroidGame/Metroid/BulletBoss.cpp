#include "BulletBoss.h"


BulletBoss::BulletBoss(int x, int y, float speedx, float speedy)
{
	_type = BULLET_ENEMY;
	tTime = 0;
	Create(x, y, 7, 8);
	_vx = speedx;
	_vy = speedy;
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
	_vy += 5;
	float nx = 0, ny = 0;
	if (CColision::mSweptAABB(this, MetroidChacracter::getInstance(), nx, ny, time) != 1)
	{
		MetroidChacracter::getInstance()->OnCollision(this, -nx, -ny);
	}
	_x += this->_vx*time;
	_y += _vy*time;
	
}
void BulletBoss::Draw(float time)
{
	img.Draw(D3DXVECTOR3(_x, _y, 0), RIGHT, time);
}