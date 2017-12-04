#pragma once
#include<iostream>
#include<fstream>
#include"../framework/GameSprite.h"
#include"../framework/GraphicsDevice.h"
#include"../object/Camera.h"
using namespace std;
class BackgroundGame
{
private:
	static BackgroundGame* instance;
	int** mtBackground;
	int column, row;// so luong hang cua bg
	int cDraw, rDraw;// so luong hang ve ra
	int wBackground, hBackground;// kich thuoc background
	int wTitle, hTitle;// kich thuoc 1 title
	int wScreen, hScreen;// kich thuoc man hinh
	dxTexture titleMap;
public:
	static BackgroundGame* getInstance();
	void Init(char* file, int ws, int hs);
	void Draw();
	BackgroundGame();
	~BackgroundGame();
};

