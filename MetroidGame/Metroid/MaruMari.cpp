#include "MaruMari.h"


MaruMari::MaruMari()
{
}


MaruMari::~MaruMari()
{
}
void MaruMari::Init()
{
	Action.Create("src//img//item//maru.png",16,16,1,1.0f/30,RIGHT);
}
void MaruMari::Update(float time)
{

}
void MaruMari::Draw(float time)
{
	if (!isDead)
	{
		Action.Draw(D3DXVECTOR3(_x, _y, 0), RIGHT, time);
	}
}
void MaruMari::OnCollision(GameplayObject* obj, int nx, int ny)
{

}