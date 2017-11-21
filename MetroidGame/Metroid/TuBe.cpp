#include "TuBe.h"


TuBe::TuBe()
{
}


TuBe::~TuBe()
{
}

void TuBe::Init()
{
	_width = 32;
	_height = 16;
}
void TuBe::Update(float time)
{
	if (abs(MetroidChacracter::getInstance()->XCenter() - XCenter() <= 50))
	{
		CreateZeb();
	}
}
void TuBe::Draw(float time){}
void TuBe::OnColision(GameplayObject* o, float nx, float ny){}

void TuBe::CreateZeb()
{
	if (zeb)
	{
		return;
	}
	zeb = new Zeb();
	zeb->Create(XCenter() + 8, _y, 16, 16);
	// them zeb vao list camera
}