#include "State_1.h"
#include"ImgDeath.h"


State_1::State_1()
{
}
State_1* State_1::instance = 0;
State_1* State_1::getInstance()
{
	if (!instance)
	{
		instance = new State_1();
	}
	return instance;
}
void State_1::Init(HWND hWnd, HINSTANCE instance)
{
	GameSprite::getInstance()->Init(GraphicsDevice::GetInstance()->device);
	BackgroundGame::getInstance()->Init("TitleMaps.txt", 256, 256);
	Camera::getInstance()->Create(590, 1104, 256, 250);
	MetroidChacracter::getInstance()->Create(635, 950, 10, 29);
	MetroidChacracter::getInstance()->Init(instance, hWnd);
	// init sound
	Sound::getInstance()->Init(hWnd);
	//load sound
	Sound::getInstance()->loadSound("man1.wav", "man1");
	Sound::getInstance()->play("man1",true,0);
}
void State_1::Update(float time)
{
	//QTree::getInstance()->LoadObjectToCamera(QTree::getInstance()->Root);
	MetroidChacracter::getInstance()->Update(time);
	//Camera::getInstance()->Update(time);
	ImgDeath::getInstance()->Update(time);
}
void State_1::Draw(float time)
{
	//BackgroundGame::getInstance()->Draw();
	//Camera::getInstance()->Draw(time);
	MetroidChacracter::getInstance()->Draw(time);
	ImgDeath::getInstance()->Draw(time);
}
void State_1::Delete()
{
	delete BackgroundGame::getInstance();
	delete Camera::getInstance();
	delete MetroidChacracter::getInstance();
	delete Sound::getInstance();
}
State_1::~State_1()
{
}
