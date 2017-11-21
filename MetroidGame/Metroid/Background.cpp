#include "Background.h"


Background::Background()
{
}

Background* Background::instance = 0;
Background*Background::getInstance()
{
	if (!instance)
	{
		instance = new Background();
	}
	return instance;
}

void Background::Create(char* filename)
{
	HRESULT result;

	result = D3DXGetImageInfoFromFile(filename, &_info);


	result = GraphicsDevice::GetInstance()->device->CreateOffscreenPlainSurface(
		_info.Width,
		_info.Height,
		D3DFMT_X8R8G8B8,
		D3DPOOL_DEFAULT,
		&sufface,
		NULL);


	result = D3DXLoadSurfaceFromFile(
		sufface,
		NULL,
		NULL,
		filename,
		NULL,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(0,0,0),
		NULL);

}


Background::~Background()
{
}
