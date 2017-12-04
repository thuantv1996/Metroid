#pragma once
#include"BasicObject.h"
#include<d3dx9.h>
class Camera: public BasicObject
{
private:
	static Camera* instance;
	D3DXMATRIX matrix;
public:
	static Camera* getInstance();
	D3DXMATRIX getMatrix();
	Camera();
	~Camera();
};

