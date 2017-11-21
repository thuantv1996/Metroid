#ifndef GRAPHICSDEVICE_H
#define GRAPHICSDEVICE_H

#pragma once
#include<d3d9.h>
class GraphicsDevice
{
private:
	static GraphicsDevice* instance;
	LPDIRECT3D9 d3d;
public:
	LPDIRECT3DDEVICE9 device;
public:
	GraphicsDevice();
	~GraphicsDevice();
	bool Init(HWND,bool);
	void Clear(DWORD);
	void Begin();
	void End();
	void Present();
	static GraphicsDevice* GetInstance();
};
#endif

