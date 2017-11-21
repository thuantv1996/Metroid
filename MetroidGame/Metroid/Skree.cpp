#include "Skree.h"


Skree::Skree()
{
}


Skree::~Skree()
{
}
void Skree::UpdatePosition(float time)
{
	if (!follow->isDead)
	{
		if ((follow->Top() - this->Bottom() <= 180) && (follow->Left() >= Left() || follow->Right() <= Right()))
		{
			isfollow = true;
		}
	}
	if (isfollow)
	{
		_vy = VELOCITY;
		_x += follow->_dx;
	}
	else
	{
		_vy = 0;
	}
	_y += _vy*time;
}
void Skree::Draw()
{
	if (isDead)
		return;
	lstAction[curAction].Draw(D3DXVECTOR3(_x, _y, 0), RIGHT);
}
void Skree::Update()
{
	// viết mã xét va chạm
	UpdatePosition(GameTime::getInstance()->curentTime);
}
void Skree::OnCollision(GameplayObject* obj, int nx, int ny)
{

}

void Skree::Begin()
{
	curAction = BEGIN;
}
void Skree::Attack()
{
	curAction = ATTACK;
}
void Skree::Bum()
{
	curAction = BUM;
}
void Skree::Die()
{
	curAction = DIE;
	isDead = true;
}
void Skree::SetListAction()
{
	lstAction[0].Create(device, filename + FILENAME_BEGIN, 116, 39, 4, 1, RIGHT);
	lstAction[1].Create(device, filename + FILENAME_ATTACK, 29, 39, 1, 1, RIGHT);
}

