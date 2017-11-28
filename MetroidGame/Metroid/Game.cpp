#include "Game.h"
#include"BackgroundGame.h"
Game::Game()
{
	backbuffer = NULL;
	totalTime = 0;
}

bool Game::Init(HWND hWnd, HINSTANCE instance)
{
	windown = hWnd;
	hInstance = instance;
	// initialize Graphics
	if (!GraphicsDevice::GetInstance()->Init(hWnd, true))
	{
		return false;
	}
	GameSprite::getInstance()->Init(GraphicsDevice::GetInstance()->device);
	BackgroundGame::getInstance()->Init("TitleMaps.txt", 256, 256);
	Camera::getInstance()->Create(100, 100, 256, 250);
	MetroidChacracter::getInstance()->Create( 120, 80, 10, 29);
	MetroidChacracter::getInstance()->Init(hInstance, hWnd);
	//Root=Map::LoadObjectFromFile("object.txt");
	//b = new Boss();
	//b->Create(490, 3280, 0, 0);
	//b->Init();
	return true;
}

void Game::Run(float gametime)
{
	totalTime = gametime;
		Update();
		Draw();
	
}

void Game::Update()
{
	
	MetroidChacracter::getInstance()->Update(totalTime);
	Camera::getInstance()->Update(totalTime);
	//b->Update(totalTime);
	// thêm đối tượng vào camera
	//Map::ColisionCamera(Root,totalTime);
	// xét va chạm giửa enemy vs ground
}

void Game::Draw()
{
	GraphicsDevice::GetInstance()->Clear(D3DCOLOR_XRGB(0, 0, 0));
	GraphicsDevice::GetInstance()->Begin();
	GameSprite::getInstance()->Begin();
	//GraphicsDevice::GetInstance()->device->StretchRect(Background::getInstance()->sufface, &Camera::getInstance()->getRect(), backbuffer, NULL, D3DTEXF_NONE);
	BackgroundGame::getInstance()->Draw();
	//Camera::getInstance()->Draw(totalTime);
	MetroidChacracter::getInstance()->Draw(totalTime);
	//b->Draw(totalTime);

	GameSprite::getInstance()->End();
	GraphicsDevice::GetInstance()->End();
	GraphicsDevice::GetInstance()->Present();
}

Game::~Game()
{
	
	GraphicsDevice::GetInstance()->~GraphicsDevice();

}
