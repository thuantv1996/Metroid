#include "ImgDeath.h"


ImgDeath* ImgDeath::instance = 0;
ImgDeath* ImgDeath::getInstance()
{
	if (!instance)
	{
		instance = new ImgDeath();
	}
	return instance;
}
ImgDeath::ImgDeath()
{
	img.Create("src//img//item//die.png", 96, 32, 3, 0.1f, RIGHT);
	isDeath = true;
}
void ImgDeath::Set(int xc, int yc)
{
	isDeath = false;
	x = xc - 16;
	y = yc + 16;
	ttime = 0;
}
void ImgDeath::Draw(float time)
{
	if (!isDeath) {
		img.Draw(D3DXVECTOR3(x, y, 0), RIGHT, time);
	}
	
}
void ImgDeath::Update(float time)
{
	if (!isDeath)
	{
		ttime += time;
		if (ttime >= 0.6f)
		{
			isDeath = true;
		}
	}
}
ImgDeath::~ImgDeath()
{
}
