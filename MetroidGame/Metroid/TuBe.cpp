#include "TuBe.h"


TuBe::TuBe()
{
	this->_type = TUBE;
}


TuBe::~TuBe()
{
}

void TuBe::Init()
{
	_width = 32;
	_height = 16;
	isDead = false;
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
	zeb->Init();
	// them zeb vao list camera
	Camera::getInstance()->AddObject(zeb);
}