#include"Player.h"
Player::Player() {}
Player::~Player() {}
Player* Player::instance = 0;
Player* Player::getInstance()
{
	if (!instance)
	{
		instance = new Player();
	}
	return instance;
}

void Player::Init()
{
	lstAction = new Animation[2];
	lstAction[BEGIN].Create("src//character//begin.png", 64, 32, 4, 1.5f, RIGHT);
	lstAction[STOP].Create("src//character//begin.png", 64, 32, 4, 1.0f, RIGHT);
	curAction = BEGIN;
}
void Player::Update(float dtime)
{
	// bàn phím
	//Vận tốc ban đầu
	// xét va chạm
	// xữ lý va chạm
	//update vi trí
	box.x = 100;
	box.y += 200.0f * dtime;
}
void Player::Render(float dtime)
{
	lstAction[curAction].Draw(D3DXVECTOR3(box.x, box.y, 0), RIGHT, dtime);
}

void Player::Begin()
{
	curAction = BEGIN;
	box.height = 32;
	xDraw = 3;
	yDraw = 0;
}
//void Player::Stop()
//{
//	if (curAction == JUM || curAction == JUM_ATTACK)
//	{
//		// Thay doi height
//		box.height = 32;
//		box.y += 7;
//	}
//	else
//		if (curAction == JUM_ROLL)
//		{
//			box.height = 32;
//			box.y += 9;
//		}
//		else
//			if (curAction == ROLL)
//			{
//				box.height = 32;
//				box.y += 19;
//			}
//	if (_direct == RIGHT)
//	{
//		xDraw = 3;
//	}
//	else
//	{
//		xDraw = 4;
//	}
//
//	yDraw = 0;
//	box.height = 32;
//	curAction = STOP;
//}
//void Player::Up()
//{
//	if (curAction == STOP || curAction == UP_ATTACK)
//	{
//		curAction = UP;
//	}
//	else
//		if (curAction == JUM_UP || curAction == JUM_UP_ATTACK)
//		{
//			curAction = UP;
//			box.y += 7;
//		}
//		else
//			if (curAction == RUN_UP)
//			{
//				curAction = UP;
//			}
//			else
//				return;
//	box.height = 32;
//	xDraw = 2;
//	yDraw = 6;
//}
//void Player::UpAttack()
//{
//	/*if (mybullet)
//	{
//	if (!mybullet->isDead)
//	{
//	return;
//	}
//	}*/
//	if (curAction != UP&&curAction != RUN_UP_ATTACK)
//		return;
//	curAction = UP_ATTACK;
//	box.height = 32;
//	xDraw = 2;
//	yDraw = 6;
//	if (_direct == RIGHT)
//	{
//		mybullet = new Bullet(_x + 8, _y, 0, -100.0f, false);
//	}
//	else
//	{
//		mybullet = new Bullet(Right() - 8, _y, 0, -100.0f, false);
//	}
//}
//void Player::Run()
//{
//	if (curAction != STOP && curAction != RUN_ATTACK&&curAction != RUN_UP)
//	{
//		return;
//	}
//	curAction = RUN;
//	box.height = 32;
//	xDraw = 9;
//	yDraw = 0;
//}
//void Player::RunUp()
//{
//	if (curAction != RUN && curAction != UP)
//	{
//		return;
//	}
//	curAction = RUN_UP;
//	box.height = 32;
//	xDraw = 6;
//	yDraw = 6;
//}
//void Player::Jum()
//{
//	if (curAction != STOP)
//	{
//		return;
//	}
//	curAction = JUM;
//	xDraw = 7;
//	yDraw = 0;
//	box.height = 25;
//	box.y -= 7;
//}
//void Player::JumUp()
//{
//	if (curAction != UP && curAction != JUM && curAction != JUM_ATTACK)
//	{
//		return;
//	}
//	if (curAction == UP)
//	{
//		box.y -= 7;
//	}
//	curAction = JUM_UP;
//	xDraw = 4;
//	box.height = 25;
//	yDraw = 7;
//}
//void Player::JumRoll()
//{
//	if (curAction != RUN)
//	{
//		return;
//	}
//	curAction = JUM_ROLL;
//	xDraw = 0;
//	yDraw = 0;
//	box.height = 23;
//	box.y -= 9;
//}
//void Player::Roll()
//{
//	if (curAction != STOP)
//	{
//		return;
//	}
//	curAction = ROLL;
//	box.y -= 19;
//	xDraw = 0;
//	yDraw = 0;
//	box.height = 13;
//}
//void Player::Attack()
//{
//	/*if (mybullet)
//	{
//	if (!mybullet->isDead)
//	{
//	return;
//	}
//	}*/
//
//	if (curAction != STOP && curAction != RUN_ATTACK)
//	{
//		return;
//	}
//	xDraw = 4;
//	yDraw = 0;
//	box.height = 32;
//	curAction = ATTACK;
//	if (_direct == RIGHT)
//	{
//		mybullet = new Bullet(Right() + 3, _y - 10, 100.0f, 0, false);
//	}
//	else
//	{
//		mybullet = new Bullet(Left() - 3, _y - 10, -100.0f, 0, false);
//	}
//}
//void Player::RunAttack()
//{
//	if (curAction != RUN)
//	{
//		return;
//	}
//	xDraw = 9;
//	yDraw = 0;
//	box.height = 32;
//	curAction = RUN_ATTACK;
//	if (_direct == RIGHT)
//	{
//		mybullet = new Bullet(Right() + 6, _y - 10, 100.0f, 0, false);
//	}
//	else
//	{
//		mybullet = new Bullet(Left() - 6, _y - 10, -100.0f, 0, false);
//	}
//}
//void Player::JumAttack()
//{
//
//	if (curAction != JUM)
//	{
//		return;
//	}
//	xDraw = 7;
//	yDraw = 0;
//	curAction = JUM_ATTACK;
//	if (_direct == RIGHT)
//	{
//		mybullet = new Bullet(Right() + 3, _y - 10, 100.0f, 0, false);
//	}
//	else
//	{
//		mybullet = new Bullet(Left() - 3, _y - 10, -100.0f, 0, false);
//	}
//}
//void Player::RunUpAttack()
//{
//	if (curAction != RUN_UP)
//	{
//		return;
//	}
//	xDraw = 6;
//	yDraw = 6;
//	if (_direct == RIGHT)
//	{
//		mybullet = new Bullet(_x + 12, _y + 10, 0, -100.0f, false);
//	}
//	else
//	{
//		mybullet = new Bullet(Right() - 12, _y + 10, 0, -100.0f, false);
//	}
//}
//void Player::JumUpAttack()
//{
//	if (curAction != JUM_UP)
//	{
//		return;
//	}
//	yDraw = 7;
//	xDraw = 4;
//	if (_direct == RIGHT)
//	{
//		mybullet = new Bullet(_x + 8, _y + 10, 0, -100.0f, false);
//	}
//	else
//	{
//		mybullet = new Bullet(Right() - 8, _y + 10, 0, -100.0f, false);
//	}
//}