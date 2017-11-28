#pragma once
#include "GameplayObject.h"
#include"Animation.h"
#define VX_RIO 50.0f
#define VY_RIO -80.0f
class Animation;
enum Rio_Status
{
	RIO_BEGIN,
	RIO_ATTACK
};
class Rio :
	public GameplayObject
{
private:
	Animation* Action;
	bool isColGround;
	bool isAttack;
	int curAction;
public:
	void Init();
	void Update(float time);
	void Draw(float time);
	void OnCollision(GameplayObject* obj, int nx, int ny);
	Rio();
	~Rio();
};

