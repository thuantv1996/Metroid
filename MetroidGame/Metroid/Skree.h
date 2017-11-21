#pragma once
#include"DinamicObject.h"

#define VELOCITY 200;
#define VELOCITY_X 50;

#define PATH "src//img//enemi//skin";
#define ORANGE_SKIN "//_1"
#define FILENAME_BEGIN "//Stop.png"
#define FILENAME_ATTACK "//Attack.png"
enum Skree_Status
{
	BEGIN,
	ATTACK,
	BUM,
	DIE
};
class Skree:public DinamicObject
{
	Skree_Status curAction;
	GameplayObject* follow;
	bool isfollow;
	string filename;
public:
	void UpdatePosition(float time);
	void Draw();
	void Update();
	virtual void OnCollision(GameplayObject* obj, int nx, int ny);
	Skree();
	~Skree();
	void SetListAction();
	void Begin();
	void Attack();
	void Bum();
	void Die();
};

