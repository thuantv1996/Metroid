#pragma once
#include<d3d9.h>
#include"Animation.h"
#include"GameplayObject.h"
#define TIME_FLY 1.0f
#define WIDTH_BULLET 2.0f
#define HEIGHT_BULLET 5.0f
#define FILE_NAME "src//img//item//bullet//Bullet.png"

class Animation;

class Bullet:public GameplayObject
{
protected:
	Animation* lstAction;
	float total_time;
	bool isRocket;
public:
	void Draw(float time);
	void Update(float time);
	Bullet();
	Bullet( float xc, float yc, float vx, float vy,bool isrocket);
	~Bullet();
};

