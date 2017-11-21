#pragma once
#include "GameplayObject.h"
#include"Animation.h"
#include"BulletBoss.h"
#define WIDTH_BOSS 31
#define HEIGHT_BOSS 46
class Animation;
class Boss :
	public GameplayObject
{
private:
	Animation* action;
	bool isActtack;
	BulletBoss* bullet;
	float totalTime;
public:
	void Update(float time);
	void Draw(float time);
	void Init();
	void Stop();
	void Attack();
	void CreateBullet();
	void OnCollision(GameplayObject* o, float nx, float ny);
	Boss();
	~Boss();
};

