#include "ScreenManager.h"


ScreenManager* ScreenManager::instance = 0;
ScreenManager* ScreenManager::getInstance()
{
	if (!instance)
	{
		instance = new ScreenManager();
	}
	return instance;
}
ScreenManager::ScreenManager()
{
}

void ScreenManager::SetScreen(Screen* screen, HWND hwnd, HINSTANCE hinstance)
{
	this->curScreen = screen;
	curScreen->Init(hwnd,hinstance);
}
void ScreenManager::Update(float time)
{
	curScreen->Update(time);
}
void ScreenManager::Draw(float time)
{
	curScreen->Draw(time);
}
void ScreenManager::Delete()
{
	curScreen->Delete();
	delete curScreen;
}
ScreenManager::~ScreenManager()
{
}
