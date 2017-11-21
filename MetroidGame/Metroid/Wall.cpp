#include "Wall.h"
#include"public_values.h"

Wall::Wall()
{
	_type = WALL;
}

void Wall::Init()
{
	_width = 16;
	_height = 16;
	isDead = false;
}

Wall::~Wall()
{
}
