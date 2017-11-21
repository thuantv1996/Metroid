#include "MetroidChacracter.h"


MetroidChacracter::MetroidChacracter()
{
	_type = Player;
}
MetroidChacracter* MetroidChacracter::instance = 0;
MetroidChacracter* MetroidChacracter::getInstance()
{
	if (!instance)
	{
		instance = new MetroidChacracter();
	}
	return instance;
}
MetroidChacracter::~MetroidChacracter()
{
	free(lstAction);
}

void MetroidChacracter::Init(HINSTANCE hInstance, HWND hWnd)
{
	this->hInstance = hInstance;
	this->hWindown = hWnd;
	this->_type = Player;
	filename = PATH;
	this->normalx = 0;
	this->normaly = 0;
	this->_direct = RIGHT;
	this->lstAction = new Animation[15];
	this->InitKeyboard(hInstance, hWnd);
	this->yDraw = _y - 5;
	SetListAction();
	Begin();
	Ve = 0;
	isbt = false;
	isFall = false;
	isGround = true;
	isStop = false;
	isJumming = false;
	count_time_bt = 0;
	numberRocket = 0;
}
void MetroidChacracter::SetListAction()
{
	lstAction[BEGIN].Create(filename+"begin.png", 64, 32, 4, 1.5f, RIGHT);
	lstAction[STOP].Create(filename + "stop.png", 18, 32, 1, float(1.0f / 24), RIGHT);
	lstAction[UP].Create(filename + "up.png", 15, 38, 1, 1, RIGHT);
	lstAction[UP_ATTACK].Create(filename + "up_attack.png", 15, 38, 1, float(1.0f / 24), RIGHT);
	lstAction[RUN].Create(filename + "run.png",87 , 32, 3, 1.0f/24, RIGHT);
	lstAction[RUN_UP].Create(filename + "run_up.png", 69, 38, 3, float(1.0f / 24), RIGHT);
	lstAction[RUN_UP_ATTACK].Create(filename + "run_up_attack.png", 23, 38, 1, float(1.0f / 24), RIGHT);
	lstAction[RUN_ATTACK].Create(filename + "run_attack.png", 87, 31, 3, float(1.0f / 24), RIGHT);
	lstAction[JUM].Create(filename + "jum.png", 25, 25, 1, float(1.0f / 24), RIGHT);
	lstAction[JUM_UP].Create(filename + "jum_up.png", 19, 32, 1, 1, RIGHT);
	lstAction[JUM_UP_ATTACK].Create(filename + "jum_up_attack.png", 19, 32, 1, 1, RIGHT);
	lstAction[JUM_ROLL].Create(filename + "jum_roll.png", 76, 23, 4, float(1.0f / 24), RIGHT);
	lstAction[ROLL].Create(filename + "roll.png", 48, 13, 4, float(1.0f / 24), RIGHT);
	lstAction[ATTACK].Create(filename + "attack.png", 19, 32, 1, 1, RIGHT);
	lstAction[JUM_ATTACK].Create(filename + "jum_attack.png", 25, 25, 1, 1, RIGHT);
}
void MetroidChacracter::UpdateAction()
{
	if (lstAction[curAction].NextFrame(GameTime::getInstance()->curentTime) == 0)
	{
		isAction = false;
	}
	else
	{
		isAction = true;
		return;
	}
}
void MetroidChacracter::UpdatePosition(float time)
{
	if (curAction == BEGIN&& lstAction[curAction].NextFrame(time)==0)
	{
		Stop();
	}
	isGround = false;
	isStop = false;
	if (isJumming || isFall)
	{
		_vy += 3;
	}
	if (_vy > 0)
	{
		isFall = true;
	}
	for (int i = 0; i < Camera::getInstance()->GetListGround().size(); i++)
	{
		float nx = 0;
		float ny = 0;
		if (CColision::mSweptAABB(this, Camera::getInstance()->GetListGround()[i], nx, ny, time) != 1 ||
			CColision::mSweptAABB(Camera::getInstance()->GetListGround()[i], this, nx, ny, time) != 1)
		{
			OnCollision(Camera::getInstance()->GetListGround()[i], nx, ny);
		}
	}
	// xét va chạm giửa char vs ground
	for (int i = 0; i < Camera::getInstance()->GetListItem().size(); i++)
	{
		float nx = 0;
		float ny = 0;
		if (CColision::mSweptAABB(this, Camera::getInstance()->GetListItem()[i], nx, ny, time) != 1 ||
			CColision::mSweptAABB(Camera::getInstance()->GetListItem()[i], this, nx, ny, time) != 1)
		{
			OnCollision(Camera::getInstance()->GetListItem()[i], nx, ny);
		}
	}

	if (isGround)
	{
		_vy = 0;
	}
	else
	{
		isFall = true;
	}
	if (isStop)
	{
		_vx = 0;
	}

	_dx = _vx*time;
	_dy = (_vy + _a)*time;
	_x += _dx;
	_y += _dy;


	if (isbt)
	{
		count_time_bt += time;
		if (count_time_bt >= 0.25f)
		{
			count_time_bt = 0;
			if (++Ve >= 12)
			{
				isbt = false;
			}
		}
	}
}
void MetroidChacracter::Draw(float time)
{
	if (isbt)
	{
		if (Ve % 2 == 1)
		{
			lstAction[curAction].Draw(D3DXVECTOR3(_x-xDraw, _y-yDraw, 0), _direct, time);
		}
		return;
	}

	lstAction[curAction].Draw(D3DXVECTOR3(_x-xDraw, _y-yDraw, 0), _direct, time);

	if (mybullet)
	{
		mybullet->Draw(time);
	}
}
void MetroidChacracter::Update(float time)
{
	this->_ProcessKeyBoard(hWindown);
	UpdatePosition(time);
}
void MetroidChacracter::OnKeyUp(int KeyCode)
{
	switch (KeyCode)
	{
	case DIK_Z:
		press_key_z = 0;
		break;
	case DIK_X:
		press_key_x = 0;
		break;
	case DIK_C:
		press_key_c = 0;
		if (curAction == RUN_ATTACK)
		{
			Run();
			break;
		}
		if (curAction == JUM_ATTACK)
		{
			Jum();
			break;
		}
		if (curAction == ATTACK)
		{
			Stop();
			break;
		}
		if (curAction == RUN_UP_ATTACK)
		{
			RunUp();
			break;
		}
		if (curAction == UP_ATTACK)
		{
			Up();
			break;
		}
		break;
	case DIK_UP:
		press_key_up = 0;
		if (curAction == UP)
		{
			Stop();
			_vx = 0;
			break;
		}
		if (curAction == RUN_UP)
		{
			Run();
			break;
		}

		break;
	case DIK_DOWN:
		press_key_down = 0;
		break;
	case DIK_LEFT:
		press_key_left = 0;
		if (press_key_right)
		{
			break;
		}
		if (curAction == RUN)
		{
			Stop();
			_vx = 0;
			break;
		}
		if (curAction == RUN_UP)
		{
			Up();
			_vx = 0;
			break;
		}
		if (curAction == ROLL)
		{
			_vx = 0;
			break;
		}
		if (curAction == JUM || curAction == JUM_ROLL)
		{
			_vx = 0;
		}
		break;
	case DIK_RIGHT:
		press_key_right = 0;
		if (press_key_left)
		{
			break;
		}
		if (curAction == RUN)
		{
			Stop();
			_vx = 0;
			break;
		}
		if (curAction == ROLL)
		{
			_vx = 0;
			break;
		}
		if (curAction == RUN_UP)
		{
			Up();
			_vx = 0;
			break;
		}
		if (curAction == JUM || curAction == JUM_ROLL)
		{
			_vx = 0;
		}
		break;
	}
}
void MetroidChacracter::OnKeyDown(int KeyCode)
{
	UpdateAction();
	switch (KeyCode)
	{
	case DIK_Z:
		press_key_z = 1;
		if (curAction == STOP)
		{
			Jum();
			_vx = 0;
			_vy = -VELOCITYJUM;
			isJumming = true;
			break;
		}
		if (curAction == UP)
		{
			JumUp();
			isJumming = true;
			_vy = -VELOCITYJUM;
			break;
		}
		if (curAction == RUN)
		{
			JumRoll();
			isJumming = true;
			_vy = -VELOCITYJUM;
			break;
		}
		break;
	case DIK_X:
		press_key_x = 1;
		break;
	case DIK_C:
		press_key_c = 1;
		if (curAction == UP)
		{
			UpAttack();
			break;
		}
		if (curAction == STOP)
		{
			Attack();
			break;
		}
		if (curAction == JUM)
		{
			JumAttack();
			break;
		}
		if (curAction == JUM_UP)
		{
			JumUpAttack();
			break;
		}
		if (curAction == RUN)
		{
			RunAttack();
			break;
		}
		if (curAction == RUN_UP)
		{
			RunUpAttack();
			break;
		}
		break;
	case DIK_UP:
		press_key_up = 1;
		if (curAction == STOP)
		{
			Up();
			_vx = 0;
			break;
		}
		if (curAction == RUN)
		{
			RunUp();
			break;
		}
		if (curAction == ROLL)
		{
			if (!press_key_left&& !press_key_right)
			{
				Stop();
				_vx = 0;
				break;
			}
		}
		break;
	case DIK_DOWN:
		press_key_down = 1;
		if (curAction == STOP)
		{
			Roll();
			break;
		}
		break;
	case DIK_LEFT:
		press_key_left = 1;
		_direct = LEFT;
		_vx = -VELOCITYX;
		if (curAction == STOP)
		{
			Run();
			break;
		}
		if (curAction == UP)
		{
			RunUp();
			break;
		}
		break;
	case DIK_RIGHT:
		press_key_right = 1;
		_direct = RIGHT;
		_vx = VELOCITYX;
		if (curAction == STOP)
		{
			Run();
			break;
		}
		if (curAction == UP)
		{
			RunUp();
			break;
		}
		break;

	}
}
void MetroidChacracter::OnCollision(GameplayObject* o, float nx, float ny)
{
	switch (o->_type)
	{
	case GROUND:
		if (isJumming)
		{
			if (_vy > 0)
			{
				isJumming = false;
				Stop();
				_y = o->_y - _height;
			}
		}
		if (isFall)
		{
			isFall = false;
			_y = o->_y - _height;
		}
		isGround = true;
		
		break;
	case BOMB:
		o->isDead = true;
		break;
	case BEAM:
		o->isDead = true;
		break;
	case MARU:
		o->isDead = true;
		break;
	case WALL:

		if (o->_y == Bottom())
		{
			isGround = true;
			return;
		}
		if (o->YCenter() > Top() && o->YCenter() < Bottom())
		{
			isStop = true;
		}
		break;
	case DOOR:
		if (nx == 1)// left
		{
			_x += 65;
		}
		else
		{
			_x -= 65;
		}
	case LAVA:

		if (!isbt)
		{
			isbt = true;
			count_time_bt = 0;
			Ve = 0;
			HP -= 2;
		}
		if (HP <= 0)
		{
			isDead = true;
		}
		break;
	case RIO:
		if (!isbt)
		{
			isbt = true;
			count_time_bt = 0;
			Ve = 0;
			HP -= 5;
		}
		if (HP <= 0)
		{
			isDead = true;
		}
		break;
	case RIPPER:
		if (!isbt)
		{
			isbt = true;
			count_time_bt = 0;
			Ve = 0;
			HP -= 5;
		}
		if (HP <= 0)
		{
			isDead = true;
		}
		break;
	case SKREE:
		if (!isbt)
		{
			isbt = true;
			count_time_bt = 0;
			Ve = 0;
			HP -= 5;
		}
		if (HP <= 0)
		{
			isDead = true;
		}
		break;
	case ZEB:
		if (!isbt)
		{
			isbt = true;
			count_time_bt = 0;
			Ve = 0;
			HP -= 5;
		}
		if (HP <= 0)
		{
			isDead = true;
		}
		break;
	case ZOMMER:
		if (!isbt)
		{
			isbt = true;
			count_time_bt = 0;
			Ve = 0;
			HP -= 5;
		}
		if (HP <= 0)
		{
			isDead = true;
		}
		break;
	default:
		break;
	}
}

void MetroidChacracter::Begin()
{
	curAction = BEGIN;
	_height = 32;
	xDraw = 3;
	yDraw = 0;
}
void MetroidChacracter::Stop()
{
	if (curAction == JUM || curAction == JUM_ATTACK)
	{
		// Thay doi height
		_height = 32;
		_y -= 7;
	}else
	if (curAction == JUM_ROLL)
	{
		_height = 32;
		_y -= 9;
	}
	else
	if (curAction == ROLL)
	{
		_height = 32;
		_y -= 19;
	}
	if (_direct == RIGHT)
	{
		xDraw = 3;
	}
	else
	{
		xDraw = 4;
	}
	
	yDraw = 0;
	_height = 32;
	curAction = STOP;
}
void MetroidChacracter::Up()
{
	if (curAction == STOP||curAction==UP_ATTACK)
	{
		curAction = UP;
	}
	else
	if (curAction == JUM_UP || curAction == JUM_UP_ATTACK)
	{
		curAction = UP;
		_y -= 7;
	}
	else
	if (curAction == RUN_UP)
	{
		curAction = UP;
	}
	else
		return;
	_height = 32;
	xDraw = 2;
	yDraw = 6;
}
void MetroidChacracter::UpAttack()
{
	/*if (mybullet)
	{
		if (!mybullet->isDead)
		{
			return;
		}
	}*/
	if (curAction != UP&&curAction!=RUN_UP_ATTACK)
		return;
	curAction = UP_ATTACK;
	_height = 32;
	xDraw = 2;
	yDraw = 6;
	if (_direct == RIGHT)
	{
		mybullet = new Bullet(_x + 8, _y , 0, -100.0f, false);
	}
	else
	{
		mybullet = new Bullet(Right() - 8, _y , 0, -100.0f, false);
	}
}
void MetroidChacracter::Run()
{
	if (curAction != STOP && curAction != RUN_ATTACK&&curAction!=RUN_UP)
	{
		return;
	}
	curAction = RUN;
	_height = 32;
	xDraw = 9;
	yDraw = 0;
}
void MetroidChacracter::RunUp()
{
	if (curAction != RUN && curAction != UP)
	{
		return;
	}
	curAction = RUN_UP;
	_height = 32;
	xDraw = 6;
	yDraw = 6;
}
void MetroidChacracter::Jum()
{
	if (curAction != STOP)
	{
		return;
	}
	curAction = JUM;
	xDraw = 7;
	yDraw = 0;
	_height = 25;
	_y += 7;
}
void MetroidChacracter::JumUp()
{
	if (curAction != UP && curAction != JUM && curAction != JUM_ATTACK)
	{
		return;
	}
	if (curAction == UP)
	{
		_y += 7;
	}
	curAction = JUM_UP;
	xDraw = 4;
	_height = 25;
	yDraw = 7;
}
void MetroidChacracter::JumRoll()
{
	if (curAction != RUN)
	{
		return;
	}
	curAction = JUM_ROLL;
	xDraw = 0;
	yDraw = 0;
	_height = 23;
	_y += 9;
}
void MetroidChacracter::Roll()
{
	if (curAction != STOP)
	{
		return;
	}
	curAction = ROLL;
	_y += 19;
	xDraw = 0;
	yDraw = 0;
	_height = 13;
}
void MetroidChacracter::Attack()
{
	/*if (mybullet)
	{
		if (!mybullet->isDead)
		{
			return;
		}
	}*/
	
	if (curAction != STOP && curAction != RUN_ATTACK)
	{
		return;
	}
	xDraw = 4;
	yDraw = 0;
	_height = 32;
	curAction = ATTACK;
	if (_direct == RIGHT)
	{
		mybullet = new Bullet(Right() + 3, _y+10, 100.0f, 0, false);
	}
	else
	{
		mybullet = new Bullet(Left() - 3,_y+ 10, -100.0f, 0, false);
	}
}
void MetroidChacracter::RunAttack()
{

	/*if (mybullet)
	{
		if (!mybullet->isDead)
		{
			return;
		}
	}*/
	if (curAction != RUN)
	{
		return;
	}
	xDraw = 9;
	yDraw = 0;
	_height = 32;
	curAction = RUN_ATTACK;
	if (_direct == RIGHT)
	{
		mybullet = new Bullet(Right() + 6, _y + 10, 100.0f, 0, false);
	}
	else
	{
		mybullet = new Bullet(Left() - 6, _y + 10, -100.0f, 0, false);
	}
}
void MetroidChacracter::JumAttack()
{
	/*if (mybullet)
	{
		if (!mybullet->isDead)
		{
			return;
		}
	}*/
	if (curAction != JUM)
	{
		return;
	}
	xDraw = 7;
	yDraw = 0;
	curAction = JUM_ATTACK;
	if (_direct == RIGHT)
	{
		mybullet = new Bullet(Right() + 3, _y + 10, 100.0f, 0, false);
	}
	else
	{
		mybullet = new Bullet(Left() - 3, _y + 10, -100.0f, 0, false);
	}
}
void MetroidChacracter::RunUpAttack()
{
	/*if (mybullet)
	{
		if (!mybullet->isDead)
		{
			return;
		}
	}*/
	if (curAction != RUN_UP)
	{
		return;
	}
	xDraw = 6;
	yDraw = 6;
	if (_direct == RIGHT)
	{
		mybullet = new Bullet(_x + 12, _y - 10,0, -100.0f, false);
	}
	else
	{
		mybullet = new Bullet(Right() - 12, _y - 10, 0,-100.0f, false);
	}
}
void MetroidChacracter::JumUpAttack()
{
	/*if (mybullet)
	{
		if (!mybullet->isDead)
		{
			return;
		}
	}*/
	if (curAction != JUM_UP)
	{
		return;
	}
	yDraw = 7;
	xDraw = 4;
	if (_direct == RIGHT)
	{
		mybullet = new Bullet(_x + 8, _y - 10, 0, -100.0f, false);
	}
	else
	{
		mybullet = new Bullet(Right() - 8, _y - 10, 0, -100.0f, false);
	}
}



void MetroidChacracter::CreateBulletHorizontal()
{
	int x;
	int y;
	float vx;
	float vy;
	if (_direct == LEFT)
	{
		x = _x - 5;
		y = _y + 10;
		vx = -100.0f;
		vy = 0;
	}
	else
	{
		x = Left()+2;
		y = _y + 10;
		vx = 100.0f;
		vy = 0;
	}
	if (numberRocket > 0)
	{
		mybullet = new Bullet(x, y, vx, vy,true);
	}
	else
	{
		mybullet = new Bullet(x, y, vx, vy,false);
	}
}
void MetroidChacracter::CreateBulletVertical()
{
	int x;
	int y;
	float vx;
	float vy;
	if (_direct == LEFT)
	{
		x = _x + 5;
		y = _y - 5;
	}
	else
	{
		x = Left() - 5;
		y = _y -5;
	}
	vy = -100.0f;
	vx = 0;
	if (numberRocket > 0)
	{
		mybullet = new Bullet( x, y, vx, vy,true);
	}
	else
	{
		mybullet = new Bullet(x, y, vx, vy,false);
	}
}

