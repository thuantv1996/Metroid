#pragma once
#include "GameplayObject.h"
#include"Animation.h"
class BulletBoss :
	public GameplayObject
{
	Animation img;
	float Speed;
	float Angle;
	float tTime;
public:
	void Update(float time);
	void Draw(float time);
	BulletBoss(int x, int y,float speed, float angle );
	~BulletBoss();
};

