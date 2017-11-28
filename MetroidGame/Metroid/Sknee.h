#pragma once
#include"GameplayObject.h"
#include"Animation.h"
#include"BulletOfSkree.h"

#define WIDTH_SKNEE 18
#define HEIGHT_SKNEE 26
#define VX_SKNEE 70
#define VY_SKNEE -80
#define	PATH_SKNEE "src//img//enemy//sknee//sknee.png"
class Animation;
 
enum Sknee_Status {
	SKNEE_BEGIN,
	SKNEE_ATTACK
};
class Sknee:public GameplayObject
{
private:
	Animation* lstAction;
	Sknee_Status curAction;
	bool isfolow;
public:
	BulletOfSkree* skree_bullet;
	void Draw(float time);
	void Update(float time);
	void SetAction();
	void OnCollision(GameplayObject* obj, int nx, int ny);
	void Init();
	void Begin();
	void Attack();
	Sknee();
	~Sknee();
};

