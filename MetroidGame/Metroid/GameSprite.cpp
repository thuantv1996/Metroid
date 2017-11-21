#include "GameSprite.h"


GameSprite::GameSprite()
{
	
}

GameSprite::~GameSprite()
{
	if (sprite)
	{
		sprite->Release();
		sprite = NULL;
	}

}

GameSprite* GameSprite::instance = 0;

GameSprite* GameSprite::getInstance()
{
	if (!instance)
	{
		instance = new GameSprite();
	}
	return instance;
}

bool GameSprite::Init(LPDIRECT3DDEVICE9 device)
{
	color = D3DCOLOR_ARGB(255, 255, 255, 255);
	if (!SUCCEEDED(D3DXCreateSprite(device, &sprite)))
	{
		MessageBox(NULL, "Tạo sprite lỗi! Xem lại fileName!", NULL, MB_OK);
		return false;
	}
}

void GameSprite::Begin()
{
	sprite->Begin(D3DXSPRITE_ALPHABLEND);
}
void GameSprite::End()
{
	sprite->End();
}
void GameSprite::Draw(dxTexture texture,RECT *rect,D3DXVECTOR3 position)
{
	position.x = position.x;
	position.y = position.y;
	if (sprite)
	{
		//sprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_OBJECTSPACE);	
		sprite->Draw(texture.tex, rect, NULL, &position, color);
	}
}
void GameSprite::ReSetTranform()
{
	sprite->SetTransform(&Matrix);
}
void GameSprite::FlipX(int w, int h, D3DXVECTOR3 position)
{
	/*Cách 1: tự định nghĩa ma trận*/
	
	// lấy ra tọa độ của sprite
	sprite->GetTransform(&Matrix);
	D3DXMATRIX MatrixFlip;
	// tạo ma trận đơn vị
	D3DXMatrixIdentity(&MatrixFlip);
	// lật quanh trục y
	MatrixFlip._11 = -1;
	// di chuyển về một lượng bằng gấp đôi khoảng cách từ tâm 
	MatrixFlip._41 = (position.x + w / 2) * 2;
	sprite->SetTransform(&(Matrix*MatrixFlip));
}

void GameSprite::FlipY(int w, int h, D3DXVECTOR3 position)
{
	sprite->GetTransform(&Matrix);
	D3DXMATRIX MatrixFlip;
	D3DXMatrixIdentity(&MatrixFlip);
	MatrixFlip._22 = -1;
	MatrixFlip._42 = (position.y + h / 2) * 2;
	sprite->SetTransform(&(Matrix*MatrixFlip));
}

dxTexture::dxTexture()
{
}
bool dxTexture::Init(LPDIRECT3DDEVICE9 device, std::string fileName, int width, int height)
{
	D3DXIMAGE_INFO info;
	HRESULT h = D3DXGetImageInfoFromFile(fileName.c_str(), &info);
	if (!SUCCEEDED(D3DXCreateTextureFromFileEx(device, fileName.c_str(), width, height, 1, D3DPOOL_DEFAULT, D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, &info, NULL, &tex)))
	{
		MessageBox(NULL, "Tạo texture lỗi! Xem lại fileName!", "Lỗi!", MB_OK);
		return false;
	}
	initialized = true;
	return true;
}

bool dxTexture::isInit()
{
	return initialized;
}
dxTexture::~dxTexture()
{
	
}