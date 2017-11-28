#include "Animation.h"


Animation::Animation()
{
}


void Animation::Create(std::string fileName, int width, int height, int nf, float timedelay, Direct d)
{

	tex.Init(GraphicsDevice::GetInstance()->device, fileName, width, height);
	this->numberFrame = nf;
	this->width = width;
	this->height = height;
	this->maxfps = timedelay;
	this->direct = d;
	this->index = 0;
	this->totalTime = 0;
}

int Animation::NextFrame(float time)
{
	int i=0;
	totalTime += time;
	if (totalTime >= maxfps)
	{
		totalTime = 0;
		i = (index + 1) % numberFrame;
		return i;
	}
	return index;
}

void  Animation::SetDirect(Direct d)
{
	direct = d;
}

void Animation::Draw(D3DXVECTOR3 position, Direct d,float time)
{
	int wf = width / numberFrame;
	//lay khung ve
	D3DXVECTOR4 pos;
	D3DXVec3Transform(&pos, &position, &Camera::getInstance()->getMatrix());
	position.x = pos.x;
	position.y = pos.y;
	RECT rect;
	rect.left = index*wf;
	rect.top = 0;
	rect.bottom = height;
	rect.right = rect.left + wf;
	// lay huong ve
	if (d== direct)
	{

			GameSprite::getInstance()->Draw(tex, &rect, position);
			

	}
	else
	{
			GameSprite::getInstance()->FlipX(wf, height, position);
			GameSprite::getInstance()->Draw(tex, &rect, position);
			GameSprite::getInstance()->ReSetTranform();
	}
	index = NextFrame(time);
}

Animation::~Animation()
{
}
