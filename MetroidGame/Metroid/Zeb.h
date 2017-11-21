#pragma once
#include"GameplayObject.h"
#include"Animation.h"
#define VY_ZEB 60.0f
#define VX_ZEB 60.0f
class Animation;
class Zeb:public GameplayObject
{
private:
	Animation Action;
	bool isAttack;
public:
	void Init();
	void Update(float time);
	void Draw(float time);
	void OnCollision(GameplayObject* obj, int nx, int ny);
	Zeb();
	~Zeb();
};

