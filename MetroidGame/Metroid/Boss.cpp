#include "Boss.h"


Boss::Boss()
{
}


Boss::~Boss()
{
}

void Boss::Update(float time)
{
	if (MetroidChacracter::getInstance()->_x - Right() <= 70)
	{
		if (abs(MetroidChacracter::getInstance()->YCenter() - YCenter()) <= 80)
		{
			if (isActtack)
			{
				totalTime += time;
				if (totalTime >= 2)
				{
					CreateBullet();
					totalTime = 0;
					return;
				}
				return;
				
			}
			Attack();
			CreateBullet();
			isActtack = true;
		}
		else
		{
			Stop();
			isActtack = false;
		}
	}
	_vx = 0;
	_vy = 0;
	for (int i = 0; i < Camera::getInstance()->GetListItem().size(); i++)
	{
		float nx = 0;
		float ny = 0;
		if (CColision::mSweptAABB(Camera::getInstance()->GetListItem()[i], this, nx, ny, time) != 1)
		{
			OnCollision(Camera::getInstance()->GetListItem()[i], nx, ny);
		}
	}
}
void Boss::Draw(float time)
{
	if (isDead)
		return;
	action->Draw(D3DXVECTOR3(_x, _y, 0), RIGHT, time);
}
void Boss::Init()
{
	_width = WIDTH_BOSS;
	_height = HEIGHT_BOSS;
	Stop();
	isActtack = false;
	isDead = false;
	HP = 100;
	totalTime = 0;
}
void Boss::Stop()
{
	action = new Animation();
	action->Create("src//img//boss//boss_stop.png", 31, 40, 1, 1.0f / 60, RIGHT);
}
void Boss::Attack()
{
	action = new Animation();
	action->Create("src//img//boss//boss_attack.png", 124, 46, 4, 1.0f / 4, RIGHT);
	
}
void Boss::CreateBullet()
{
	bullet = new BulletBoss(Right(), YCenter(), 50,-70);
	bullet = new BulletBoss(Right(), YCenter(), 60,-70);
	bullet = new BulletBoss(Right(), YCenter(), 70,-70);
	bullet = new BulletBoss(Right(), YCenter(), 40,-70);
	bullet = new BulletBoss(Right(), YCenter(), 30,-70);
	
}
void Boss::OnCollision(GameplayObject* o, float nx, float ny)
{
	if (o->_type == BULLET)
	{
		HP -= 5;
		if (HP == 0)
		{
			isDead = true;
		}
	}
}