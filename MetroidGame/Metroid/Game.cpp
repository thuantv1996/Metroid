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
	GraphicsDevice::GetInstance()->device->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &backbuffer);
	GameSprite::getInstance()->Init(GraphicsDevice::GetInstance()->device);
	BackgroundGame::getInstance()->Init("TitleMaps.txt", 256, 256);
	Camera::getInstance()->Create(512, 3120, 256, 250);
	MetroidChacracter::getInstance()->Create( 626, 3280, 10, 29);
	MetroidChacracter::getInstance()->Init(hInstance, hWnd);
	Root=Map::LoadObjectFromFile("object.txt");
	b = new Boss();
	b->Create(490, 3280, 0, 0);
	b->Init();
	GameTime::getInstance()->Init();
	return true;
}

void Game::Run()
{
	DWORD last_time;
	GameTime::getInstance()->Run();
	totalTime += GameTime::getInstance()->curentTime;
	if (totalTime >= 1.0f/60)
	{
		Update();
		Draw();
		totalTime = 0;
	}
	
}

void Game::Update()
{
	
	MetroidChacracter::getInstance()->Update(totalTime);
	Camera::getInstance()->Update(totalTime);
	b->Update(totalTime);
	// thêm đối tượng vào camera
	Map::ColisionCamera(Root,totalTime);
	// xét va chạm giửa char vs enemy
	for (int i = 0; i < Camera::getInstance()->GetListEnemy().size(); i++)
	{
		float nx = 0;
		float ny = 0;
		if (CColision::mSweptAABB(MetroidChacracter::getInstance(), Camera::getInstance()->GetListEnemy()[i], nx, ny, totalTime)!=1 ||
			CColision::mSweptAABB(Camera::getInstance()->GetListEnemy()[i], MetroidChacracter::getInstance(), nx, ny, totalTime)!=1)
		{
			MetroidChacracter::getInstance()->OnCollision(Camera::getInstance()->GetListEnemy()[i], nx, ny);
		}
	}
	//// xét va chạm giửa char vs item
	//for (int i = 0; i < Camera::getInstance()->GetListItem().size(); i++)
	//{
	//	float nx = 0;
	//	float ny = 0;
	//	if (CColision::mSweptAABB(MetroidChacracter::getInstance(), Camera::getInstance()->GetListItem()[i], nx, ny, totalTime) != 1)
	//	{
	//		MetroidChacracter::getInstance()->OnCollision(Camera::getInstance()->GetListItem()[i], nx, ny);
	//		break;
	//	}
	//}
	
	// xét va chạm giửa enemy vs ground
	for (int i = 0; i < Camera::getInstance()->GetListEnemy().size(); i++)
	{
		float nx = 0;
		float ny = 0;
		for (int j = 0; j < Camera::getInstance()->GetListGround().size(); j++)
		{
			if (CColision::mSweptAABB(Camera::getInstance()->GetListEnemy()[i], Camera::getInstance()->GetListGround()[j], nx, ny, totalTime)!=1 ||
				CColision::mSweptAABB(Camera::getInstance()->GetListGround()[j], Camera::getInstance()->GetListEnemy()[i], nx, ny, totalTime)!=1)
			{
				Camera::getInstance()->GetListEnemy()[i]->OnCollision(Camera::getInstance()->GetListGround()[j], nx, ny);
			}
		}
	}
}

void Game::Draw()
{
	GraphicsDevice::GetInstance()->Clear(D3DCOLOR_XRGB(0, 0, 0));
	GraphicsDevice::GetInstance()->Begin();
	GameSprite::getInstance()->Begin();
	//GraphicsDevice::GetInstance()->device->StretchRect(Background::getInstance()->sufface, &Camera::getInstance()->getRect(), backbuffer, NULL, D3DTEXF_NONE);
	BackgroundGame::getInstance()->Draw();
	Camera::getInstance()->Draw(totalTime);
	MetroidChacracter::getInstance()->Draw(totalTime);
	b->Draw(totalTime);

	GameSprite::getInstance()->End();
	GraphicsDevice::GetInstance()->End();
	GraphicsDevice::GetInstance()->Present();
}

Game::~Game()
{
	
	GraphicsDevice::GetInstance()->~GraphicsDevice();

}
