#include "Rocket_Item.h"


Rocket_Item::Rocket_Item()
{
	this->_type = ROCKET;
}


Rocket_Item::~Rocket_Item()
{
}

void Rocket_Item::Update(float time)
{

}
void Rocket_Item::Draw(float time)
{
	img.Draw(D3DXVECTOR3(_x, _y, 0), RIGHT, time);
}
void Rocket_Item::OnCollision(GameplayObject* obj, int nx, int ny)
{

}
void Rocket_Item::Init()
{
	img.Create("src//img//item//Rocket.png",18,18,1,1.0f/60,RIGHT);
	_height = HEIGHT_ROCKET;
	_width = WIDTH_ROCKET;
	isDead = false;
}