#ifndef GAMESPRITE_H
#define GAMESPRITE_H
#pragma once
#include<d3d9.h>
#include<d3dx9.h>
#include<string>
class GameSprite;
class dxTexture;

class GameSprite
{
public:
	// method
	GameSprite();
	~GameSprite();
	static GameSprite* getInstance();
	bool Init(LPDIRECT3DDEVICE9 device);
	void Begin();
	void End();
	void Draw(dxTexture texture,RECT *rect, D3DXVECTOR3 position);
	void ReSetTranform();
	void FlipX(int w, int h, D3DXVECTOR3 position);
	void FlipY(int w, int h, D3DXVECTOR3 position);
private:
	static GameSprite* instance;
	D3DXVECTOR3 position;
	LPD3DXSPRITE sprite;
	D3DCOLOR color;
	D3DXMATRIX Matrix;
};

class dxTexture{
public :
	dxTexture();
	LPDIRECT3DTEXTURE9 tex;
	bool Init(LPDIRECT3DDEVICE9 device, std::string fileName, int width, int height);
	bool initialized;
	bool isInit();
	~dxTexture();
};
#endif

