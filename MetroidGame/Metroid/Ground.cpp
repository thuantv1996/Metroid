#include"Ground.h"

Ground::Ground()
{
	this->_type = GROUND;
}

void Ground::Init()
{
	_width = 16;
	_height = 16;
	isDead = false;
}
void Ground::Update(float time)
{

}
void Ground::Draw(float time)
{

}
void Ground::OnCollision(GameplayObject* obj, int nx, int ny)
{

}