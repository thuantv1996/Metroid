#pragma once
#include"Animation.h"
#define WIDTH_ROCKET 18
#define HEIGHT_ROCKET 18
class Animation;
#include "GameplayObject.h"
class Rocket_Item :
	public GameplayObject
{
	Animation img;
public:
	 void Update(float time);
	 void Draw(float time);
	 void OnCollision(GameplayObject* obj, int nx, int ny);
	void Init();
	Rocket_Item();
	~Rocket_Item();
};

