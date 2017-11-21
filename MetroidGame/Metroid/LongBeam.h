#pragma once
#include "GameplayObject.h"
#include"Animation.h"
#define WIDTH_BEAM 18
#define HEIGHT_BEAM 18
class Animation;
class LongBeam :
	public GameplayObject
{
private:
	Animation img;
public:
	void Update(float time);
	void Draw(float time);
	void OnCollision(GameplayObject* obj, int nx, int ny);
	void Init();
	LongBeam();
	~LongBeam();
};

