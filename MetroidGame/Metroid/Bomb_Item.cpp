#include "Bomb_Item.h"


Bomb_Item::Bomb_Item()
{
	this->_type = BOMB;
}


Bomb_Item::~Bomb_Item()
{
}

void Bomb_Item::Update(float time)
{

}
void Bomb_Item::Draw(float time)
{
	if (!isDead)
		img.Draw(D3DXVECTOR3(_x, _y, 0), RIGHT, time);
}
void Bomb_Item::OnCollision(GameplayObject* obj, int nx, int ny)
{

}
void Bomb_Item::Init()
{
	img.Create("src//img//item//Bomb.png", 18, 18, 1, 1.0f / 2, RIGHT);
	_height = HEIGHT_BOMB;
	_width = WIDTH_BOMB;
}