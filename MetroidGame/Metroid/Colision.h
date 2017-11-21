#pragma once
#include<iostream>
#include "GameplayObject.h"
using namespace std;
class CColision
{
public:
	static float mSweptAABB(GameplayObject* obj1, GameplayObject* obj2, float &normalx, float &normaly,float time);
	static bool collision(GameplayObject* obj1, GameplayObject* obj2);
	CColision();
	~CColision();
private:
	
	static GameplayObject* GetSweptBroadphaseBox(GameplayObject* o,float time);
};

