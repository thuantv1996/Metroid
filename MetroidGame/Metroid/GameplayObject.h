
#pragma once
#include<d3d9.h>
#include <cmath>
#include"public_values.h"

#define M_PI 3.1415926535897932384626433832795



class GameplayObject
{
public:
	int _id;
	TypeObject _type;
	GameplayObject();
	// them code loai object
	float _x;// toa do
	float _y;
	int _width;// kich thuoc
	int _height;
	float _vx;// van toc
	float _vy;
	float _a;// gia toc
	float _dx, _dy;//khoang di chuyen trong 1 frame
	bool isColl;// kt va cham
	bool isDead; // kt chet
	float normalx, normaly;
	Direct _direct;
	int HP;
	int _xOld, _yOld;
	
public:

	void Create(int, int, int, int);
	virtual void Update(float time);
	virtual void Draw(float time);
	virtual void OnCollision(GameplayObject* obj, int nx, int ny);
	virtual void Init() {}
	float XCenter();
	float YCenter();
	float Left();
	float Right();
	float Top();
	float Bottom();





};


