#pragma once
#include "GameplayObject.h"
#include"Animation.h"
class Ground : public GameplayObject
{
public:
	void Init();
	void Update(float time);
	void Draw(float time);
	void OnCollision(GameplayObject* obj, int nx, int ny);
	Ground();
	~Ground();
};