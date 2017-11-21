#pragma once
#include"GameplayObject.h"
#include"Animation.h"
class StaticObject :public GameplayObject
{
	Animation* lstAction;
	int curAction;
public:
	virtual void Update();
	virtual void Draw();
	virtual void Run();
	StaticObject();
	~StaticObject();
};

