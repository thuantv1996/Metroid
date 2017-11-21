#include"GameplayObject.h"

GameplayObject::GameplayObject(){}
void GameplayObject::Create(int x, int y, int w, int h)
{
	this->_x = x;
	this->_y = y;
	this->_width = w;
	this->_height = h;
	this->_dx = 0;
	this->_dy = 0;
	this->_vx = 0;
	this->_vy = 0;
	this->_a = 0;
}

void GameplayObject::Update(float time){}
void GameplayObject::Draw(float time){}
void GameplayObject::OnCollision(GameplayObject* obj, int nx, int ny){}


float GameplayObject::XCenter(){ return (_x + _width / 2); }
float GameplayObject::YCenter(){ return (_y + _height/2); }
float GameplayObject::Left(){ return _x; }
float GameplayObject::Right(){ return _x + _width; }
float GameplayObject::Top(){ return _y; }
float GameplayObject::Bottom(){ return _y + _height; }