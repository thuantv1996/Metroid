#pragma once
#include "GameplayObject.h"
#include"Animation.h"
#define WIDTH_BOMB 16
#define HEIGHT_BOMB 16
class Animation;
class Bomb_Item :
	public GameplayObject
{
private:
	Animation img;
public:
	void Update(float time);
	void Draw(float time);
	void OnCollision(GameplayObject* obj, int nx, int ny);
	void Init();
	Bomb_Item();
	~Bomb_Item();
};

