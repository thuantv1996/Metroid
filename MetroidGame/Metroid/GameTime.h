#pragma once
#include<Windows.h>
class GameTime
{
public:
	static GameTime* getInstance();
	float curentTime;
	float totalTime;
	bool Init();
	void Run();
	GameTime();
	~GameTime();
private:
	static GameTime* instance;
	void Update();
	float start;
	float frequency;
};

