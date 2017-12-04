
#pragma once
#include<d3d9.h>
#include"../framework/GraphicsDevice.h"
#include"../framework/GameSprite.h"
#include"../global.h"
#include"../object/Camera.h"
class Animation
{
private:
	int numberFrame;// so frame
	int index;//frame hien tai
	int width;
	int height;
	float maxfps;//so frame max per s
	float totalTime;// time cho 1 frame
	Direct direct;// huong ve
	dxTexture tex;
public:
	Animation();
	void Create( std::string fileName, int width, int height,int nf, float timedelay, Direct d);
	int NextFrame(float time);
	void SetDirect(Direct d);
	void Draw(D3DXVECTOR3,Direct,float);
	~Animation();
};


