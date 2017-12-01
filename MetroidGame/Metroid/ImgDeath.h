#pragma once
#include"Animation.h"
class ImgDeath
{
private:
	static ImgDeath* instance;
	float ttime;
	Animation img;
	bool isDeath;
	int x, y;
public:
	static ImgDeath* getInstance();
	void Set(int xc, int yc);
	void Draw(float time);
	void Update(float time);
	ImgDeath();
	~ImgDeath();
};

