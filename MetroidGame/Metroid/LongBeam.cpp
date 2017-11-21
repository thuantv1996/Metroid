#include "LongBeam.h"


LongBeam::LongBeam()
{
	this->_type = BEAM;
}


LongBeam::~LongBeam()
{
}
void LongBeam::Update(float time)
{

}
void LongBeam::Draw(float time)
{
	if (!isDead)
		img.Draw(D3DXVECTOR3(_x, _y, 0), RIGHT, time);
}
void LongBeam::OnCollision(GameplayObject* obj, int nx, int ny)
{

}
void LongBeam::Init()
{
	img.Create("src//img//item//LongBeam.png", 18, 18, 1, 1.0f / 2, RIGHT);
	_height = HEIGHT_BEAM;
	_width = WIDTH_BEAM;
}
