#pragma once
#include"GameplayObject.h"
#include"Zeb.h"
class TuBe: public GameplayObject
{
private:
	Zeb* zeb;
public:
	void Init();
	void Update(float time);
	void Draw(float time);
	void OnColision(GameplayObject* o, float nx, float ny);
	void CreateZeb();
	TuBe();
	~TuBe();
};

