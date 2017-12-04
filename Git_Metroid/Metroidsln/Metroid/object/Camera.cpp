#include "Camera.h"



Camera::Camera()
{
}
Camera* Camera::instance = 0;
Camera* Camera::getInstance()
{
	if (!instance)
	{
		instance = new Camera();
	}
	return instance;
}
D3DXMATRIX Camera::getMatrix()
{
	return matrix;
}
Camera::~Camera()
{
}
