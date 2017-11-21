#pragma once
#include"GameplayObject.h"
#include <DirectXMath.h>
#include"GraphicsDevice.h"
#include<D3dx9math.h>
#include"MetroidChacracter.h"
class MyCamera: public GameplayObject
{
private:
	D3DXMATRIX mt;// ma trận vẽ
	bool isUp;
public:
	void Update(float time);
	void Draw(float time);
	D3DXMATRIX getMatrix();
	MyCamera();
	~MyCamera();
};

