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

void ScreenManager::SetScreen(Screen* screen)
{
	this->curScreen = screen;
	curScreen->Init();
}
void ScreenManager::Update(float time)
{
	curScreen->Update(time);
}
void ScreenManager::Draw(float time)
{
	curScreen->Render(time);
}
void ScreenManager::Delete()
{
	curScreen->Delete();
	delete curScreen;
}
ScreenManager::~ScreenManager()
{
}
