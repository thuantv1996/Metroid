#ifndef METROIDCHARACTER_H
#define METROIDCHARACTER_H
#pragma once
#include"Animation.h"
#include"GameTime.h"
#include"InputGame.h"
#include<iostream>
#include"Bullet.h"
using namespace std;
class Animation;
class Bullet;

#define VELOCITYX 90.0f
#define VELOCITYJUM 130.0f
#define VELOCITYY 100.0f
#define GRAVITY 2.0f

#define WIDHT_METROID 10
#define HEIGHT_METROID_STAND 32
#define HEIGHT_METROID_JUM 27
#define HEIGHT_METROID_ROLL 15

#define PATH "src//img//character//";



enum MetroidStatus
{
	BEGIN,
	STOP,
	UP,
	UP_ATTACK,
	RUN,
	RUN_UP,
	RUN_UP_ATTACK,
	RUN_ATTACK,
	JUM,
	JUM_UP,
	JUM_UP_ATTACK,
	JUM_ROLL,
	ROLL,
	ATTACK,
	JUM_ATTACK,
};

class MetroidChacracter: public GameplayObject , public InputGame 
{
private:
	static MetroidChacracter* instance;
	bool isAction;// kiem tra hanh dong da thuc hien xong chua
	HWND hWindown;
	HINSTANCE hInstance;
	int press_key_z;
	int press_key_x;
	int press_key_c;
	int press_key_up;
	int press_key_down;
	int press_key_left;
	int press_key_right;
	bool isGround;
	bool isStop;
	MetroidStatus curAction;
	string filename;

	bool isJumming;
	bool isRolling;
	bool isJumRoll;
	bool isFall;
	Animation* lstAction;
	Bullet* mybullet;
	int numberRocket;
	int yDraw;
	int xDraw;

	bool isbt;
	float count_time_bt;
	int Ve;
	int HP;
	float time_update;
public:
	static MetroidChacracter* getInstance();
	MetroidChacracter();
	~MetroidChacracter();
	void SetListAction();
	void Init(HINSTANCE,HWND);
	void UpdateAction();
	void UpdatePosition(float time);
	void Draw(float time);
	void Update(float time);
	void OnCollision(GameplayObject* o, float nx, float xy);
	void OnKeyUp(int KeyCode);
	void OnKeyDown(int KeyCode);

	void Begin();
	void Stop();
	void Up();
	void UpAttack();
	void Run();
	void RunUp();
	void Jum();
	void JumUp();
	void JumRoll();
	void Roll();
	void Attack();
	void RunAttack();
	void JumAttack();
	void RunUpAttack();
	void JumUpAttack();
	void CreateBulletHorizontal();
	void CreateBulletVertical();
};

#endif