#pragma once
#include"GameplayObject.h"
class Lave:public GameplayObject
{
public:
	void Init();
	void BeforeUpdate();
	void Update(float time);
	void Draw(float time);
	void OnCollision(GameplayObject* obj, int nx, int ny);
	Lave();
	~Lave();
};

