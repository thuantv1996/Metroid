#pragma once
#include "GameplayObject.h"
#include"Animation.h"
#include"GameTime.h"
#include<d3d9.h>
#include"public_values.h"
#include"Ground.h"
#include"Wall.h"

enum ZoomerStatus{
	ZOOMER_UP,
	ZOOMER_DOWN,
	ZOOMER_LEFT,
	ZOOMER_RIGHT
};
 
#define WIDTH_ZOOMER
#define HEIGHT_ZOOMER 
#define VX_ZOOMER 30
#define VY_ZOOMER 30

class Animation;
class Zoomer :
	public GameplayObject
{
private:
	Animation* lstAction;
	ZoomerStatus curAction;
	GameplayObject* oldGround;
	bool isUp;
	bool isDown;
	bool isLeft;
	bool isRight;
	bool isCol;
public:
	void Draw(float time);
	void Update(float time);
	void SetAction();
	void OnCollision(GameplayObject* obj, int nx, int ny);
	void Init();
	void ZUp();
	void ZDown();
	void ZLeft();
	void ZRight();
	Zoomer();
	~Zoomer();
};

