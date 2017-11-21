#pragma once
#include "GameplayObject.h"
#include"Animation.h"
class Animation;
class MaruMari:public GameplayObject
{
	Animation Action;
public:
	void Init();
	void Update(float time);
	void Draw(float time);
	void OnCollision(GameplayObject* obj, int nx, int ny);
	MaruMari();
	~MaruMari();
};

