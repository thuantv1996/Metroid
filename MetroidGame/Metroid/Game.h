#pragma once
#include<Windows.h>
#include"GraphicsDevice.h"
#include"GameTime.h"
#include"ScreenManager.h"
#include"State_1.h"
class Game
{
private:
	HWND windows;
	HINSTANCE hInstance;
	float totalTime;
public:
	Game();
	~Game();
	bool Init(HWND hWnd, HINSTANCE instance);
	void Run(float time);
	void Update(float time);
	void Draw(float time);
	void Delete();
};

