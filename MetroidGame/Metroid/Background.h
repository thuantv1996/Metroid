#pragma once
#include<d3d9.h>
#include<d3dx9.h>
#include<iostream>
#include"GraphicsDevice.h"
using namespace std;
class Background
{
private:
	static Background* instance;
	D3DXIMAGE_INFO _info;
public:
	static Background* getInstance();
	LPDIRECT3DSURFACE9 sufface;
	void Create(char* filename);
	void Draw();
	Background();
	~Background();
};

