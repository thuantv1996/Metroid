#include "Zoomer.h"
#include"ImgDeath.h"
Zoomer::Zoomer()
{
	this->_type = ZOMMER;
}
void Zoomer::Init()
{
	_y += 2;
	HP = 20;
	ZUp();
	SetAction();
}

void Zoomer::Update(float time)
{
	isColl = false;// kiem tra co va cham voi gach hay khong
	isCol = false;// kiem tra co va cham voi gach dat biet hay khong
	float nx = 0, ny = 0;
	for (int i = 0; i < Camera::getInstance()->listObjectOnCamera.size(); i++)
	{
		if (isCol)
		{
			break;
		}
		if (CColision::mSweptAABB(this, Camera::getInstance()->listObjectOnCamera[i], nx, ny, time) != 1.0f)
		{
			OnCollision(Camera::getInstance()->listObjectOnCamera[i], nx, ny);
		}
	}
	if (!isCol)
	{
		if (!isColl && oldGround!=NULL)
		{
			if (_vx > 0)
			{
				ZRight();
				_x = oldGround->Right();
			}
			else
			if (_vx < 0)
			{
				ZLeft();
				_x = oldGround->_x-_width;
			}
			else
			if (_vy > 0)
			{
				ZDown();
				_y = oldGround->Bottom();
			}
			else
			if (_vy < 0)
			{
				ZUp();
				_y = oldGround->_y-_height;
			}
		}
	}
	_dx = _vx* time;
	_dy = _vy*time;
	_x += _dx;
	_y += _dy;
}
void Zoomer::Draw(float time)
{
	lstAction[curAction].Draw(D3DXVECTOR3(_x, _y,0), RIGHT,time);
}

Zoomer::~Zoomer()
{
	free(lstAction);
}

void Zoomer::OnCollision(GameplayObject* obj, int nx, int ny)
{
	switch (obj->_type)
	{
	case BULLET:
		HP -= 5;
		if (HP == 0)
		{
			this->isDead = true;
			ImgDeath::getInstance()->Set(XCenter(), YCenter());
		}
		break;
	case WALL:
		if (_vx > 0 && YCenter()>obj->Top()&& YCenter()<obj->Bottom())
		{
			
			isCol = true;
			isColl = true;
			ZLeft();
			_x =obj->_x-_width ;
			_y = obj->Bottom() - _height;
			oldGround = obj;
			break;
			
		}
		if (_vx < 0 && YCenter()>obj->Top() && YCenter()<obj->Bottom())
		{
			
			isCol = true;
			isColl = true;
			ZRight();
			_x = obj->Right();
			_y = obj->_y;
			oldGround = obj;
			break;
		}
		oldGround = obj;
		isColl = true;
		break;
	case GROUND:
		if (_vy > 0 && XCenter() < obj->Right() && XCenter()>obj->Left())
		{
			
			isCol = true;
			isColl = true;
			ZUp();
			_x = obj->_x;
			_y = obj->_y - _height;
			oldGround = obj;
			break;
		}
		if (_vy < 0 && XCenter() < obj->Right() && XCenter()>obj->Left())
		{
			
			isCol = true;
			isColl = true;
			ZDown();
			_x = obj->_x;
			_y = obj->Bottom(); 
			oldGround = obj;
			break;
		}
		oldGround = obj;
		isColl = true;
	default:
		break;
	}
}

void Zoomer::ZUp()
{
	curAction = ZOOMER_UP;
	_vx = VX_ZOOMER;
	_vy = 0;
	_width = 16;
	_height = 16;
}
void Zoomer::ZDown()
{
	curAction = ZOOMER_DOWN;
	_vy = 0;
	_vx = -VX_ZOOMER;
	_width = 16;
	_height = 16;
}
void Zoomer::ZLeft()
{
	curAction = ZOOMER_LEFT;
	_vx = 0;
	_vy = -VY_ZOOMER;
	_height = 16;
	_width = 16;
}
void Zoomer::ZRight()
{
	curAction = ZOOMER_RIGHT;
	_vx = 0;
	_vy = VY_ZOOMER;
	_height = 16;
	_width = 16;
}
void Zoomer::SetAction()
{
	lstAction = new Animation[4];
	lstAction[ZOOMER_UP].Create("src//img//enemy//zoomer//Zoomer_up.png", 36, 16, 2, 1.0f/4, RIGHT);
	lstAction[ZOOMER_DOWN].Create( "src//img//enemy//zoomer//Zoomer_down.png", 36, 16, 2, 1.0f / 4, RIGHT);
	lstAction[ZOOMER_LEFT].Create( "src//img//enemy//zoomer//Zoomer_left.png", 32, 18, 2, 1.0f / 4, RIGHT);
	lstAction[ZOOMER_RIGHT].Create( "src//img//enemy//zoomer//Zoomer_right.png", 32, 18, 2, 1.0f / 4, RIGHT);
}