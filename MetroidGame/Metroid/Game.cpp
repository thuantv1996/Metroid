#include "Game.h"
Game::Game()
{
}

bool Game::Init(HWND hWnd, HINSTANCE instance)
{
	if (!GraphicsDevice::GetInstance()->Init(hWnd, true))
	{
		return false;
	}
	this->windows = hWnd;
	this->hInstance = instance;
	ScreenManager::getInstance()->SetScreen(State_1::getInstance(), windows, hInstance);
	return true;
}

void Game::Run(float time)
{
	Update(time);
	Draw(time);
}

void Game::Update(float time)
{
	ScreenManager::getInstance()->Update(time);
}

void Game::Draw(float time)
{
	GraphicsDevice::GetInstance()->Clear(D3DCOLOR_XRGB(0, 0, 0));
	GraphicsDevice::GetInstance()->Begin();
	GameSprite::getInstance()->Begin();
	ScreenManager::getInstance()->Draw(time);
	GameSprite::getInstance()->End();
	GraphicsDevice::GetInstance()->End();
	GraphicsDevice::GetInstance()->Present();
}
void Game::Delete()
{
	ScreenManager::getInstance()->Delete();
	delete ScreenManager::getInstance();
	delete GameSprite::getInstance();
}

Game::~Game()
{
	
	GraphicsDevice::GetInstance()->~GraphicsDevice();

}
