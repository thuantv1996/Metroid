#pragma once
#include "GameplayObject.h"
#include"Animation.h"
class BulletOfSkree :
	public GameplayObject
{
private:
	Animation lstAction;
	float total_time;
public:
	void Draw(float time);
	void Update(float time);
	BulletOfSkree(float xc, float yc, float vx, float vy);
	BulletOfSkree();
	~BulletOfSkree();
};

