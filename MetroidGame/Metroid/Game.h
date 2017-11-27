#pragma once
#include<Windows.h>
#include"GraphicsDevice.h"
#include"GameTime.h"
#include"MetroidChacracter.h"
#include"Animation.h"
#include"Background.h"
#include"Zoomer.h"
#include"Sknee.h"
#include"Ripper.h"
#include"Rocket_Item.h"
#include"Zeb.h"
#include"Rio.h"
#include"Colision.h"
#include"Node.h"
#include"Map.h"
#include"Boss.h"
class Game
{
private:
	HWND windown;
	HINSTANCE hInstance;
	float totalTime;
public:
	Game();
	~Game();
	bool Init(HWND hWnd, HINSTANCE instance);
	void Run(float gametime);
	void Update();
	void Draw();
public:
	LPDIRECT3DSURFACE9 backbuffer;
	Node* Root;
	Boss* b;
};

