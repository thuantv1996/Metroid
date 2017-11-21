#include "GraphicsDevice.h"


GraphicsDevice::GraphicsDevice()
{
	d3d = NULL;
	device = NULL;
}

GraphicsDevice* GraphicsDevice::instance = 0;

GraphicsDevice* GraphicsDevice::GetInstance()
{
	if (!instance)
	{
		instance = new GraphicsDevice();
	}
	return instance;
}
GraphicsDevice::~GraphicsDevice()
{
	if (device){
		device->Release();
		device = NULL;
	}
	if (d3d)
	{
		d3d->Release();
		d3d = NULL;
	}
	if (instance)
	{
		free(instance);
	}
	
}

bool GraphicsDevice::Init(HWND hWnd,bool isWindowed)
{
	d3d = Direct3DCreate9(D3D_SDK_VERSION);
	D3DPRESENT_PARAMETERS para;
	ZeroMemory(&para, sizeof(D3DPRESENT_PARAMETERS));
	para.Windowed = isWindowed;
	para.SwapEffect = D3DSWAPEFFECT_DISCARD;
	para.hDeviceWindow = hWnd;
	para.BackBufferCount = 1;
	para.BackBufferWidth = 256; //kich thuoc camera
	para.BackBufferHeight = 256; // ``

	if (!SUCCEEDED(d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &para, &device)))
	{
		return false;
	}
	return true;
}

void GraphicsDevice::Clear(DWORD color)
{
	device->Clear(0, NULL, D3DCLEAR_TARGET, color, 1.0f, 0);
}
void GraphicsDevice::Begin()
{
	device->BeginScene();
}
void GraphicsDevice::End()
{
	device->EndScene();
}
void GraphicsDevice::Present()
{
	device->Present(NULL, NULL, NULL, NULL);
}
