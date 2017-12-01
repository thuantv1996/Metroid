#pragma once
#include"Screen.h"
class ScreenManager
{
private:
	Screen* curScreen;
	static ScreenManager* instance;
public:
	static ScreenManager* getInstance();
	void SetScreen(Screen* screen,HWND hwnd,HINSTANCE hinstance);
	void Update(float time);
	void Draw(float time);
	void Delete();
	ScreenManager();
	~ScreenManager();
};

