#include "BackgroundGame.h"


BackgroundGame::BackgroundGame()
{
}


BackgroundGame::~BackgroundGame()
{
}
BackgroundGame* BackgroundGame::instance = 0;
BackgroundGame* BackgroundGame::getInstance()
{
	if (!instance)
	{
		instance = new BackgroundGame();
	}
	return instance;
}
void BackgroundGame::Init(char* file, int ws, int hs)
{
	wScreen = ws;
	hScreen = hs;
	ifstream f(file);
	if (!f.is_open())
		printf("khong mo dc file");
	f >> wBackground >> hBackground >> wTitle >> hTitle;
	column = wBackground / wTitle;
	row = hBackground / hTitle;
	mtBackground = new int*[row];
	for (int i = 0; i < row; i++)
	{
		mtBackground[i] = new int[column];
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			f >> mtBackground[i][j];
		}
	}
	cDraw = wScreen / wTitle;
	rDraw = hScreen / hTitle;
	titleMap.Init(GraphicsDevice::GetInstance()->device, "TitleMaps.png", 1856, 16);
}
void BackgroundGame::Draw()
{
	//// lay toa do cam
	//int xCam = Camera::getInstance()->_x;
	//int yCam = Camera::getInstance()->_y;
	//// tinh vi tri bat dau ve
	//int icDraw = xCam / wTitle;
	//int irDraw = yCam / hTitle;
	//// lay phan ve va ve
	//for (int i = irDraw; i < irDraw + rDraw+1; i++)
	//{
	//	for (int j = icDraw; j < icDraw + cDraw+1; j++)
	//	{
	//		// lay vung ve
	//		RECT r;
	//		r.left = mtBackground[i][j] *wTitle;
	//		r.right = r.left + wTitle;
	//		r.top = 0;
	//		r.bottom = hTitle;
	//		// lay toa do ve;
	//		int yDraw = i*hTitle;
	//		int xDraw = j*wTitle;
	//		xDraw -= Camera::getInstance()->_x;
	//		yDraw -= Camera::getInstance()->_y;
	//		GameSprite::getInstance()->Draw(titleMap, &r, D3DXVECTOR3(xDraw, yDraw, 0));
	//	}
	//}
}