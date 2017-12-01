#pragma once
#include"GraphicsDevice.h"
#include"BackgroundGame.h"
#include"MetroidChacracter.h"
#include"Camera.h"
#include"QTree.h"
class Screen
{
private:
	
public:
	
	virtual void Init(HWND hWnd, HINSTANCE instance);
	virtual void Update(float time);
	virtual void Draw(float time);
	virtual void Delete();
	Screen();
	~Screen();
};

