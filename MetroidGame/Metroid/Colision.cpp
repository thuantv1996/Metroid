#include "Colision.h"

bool CColision::collision(GameplayObject* obj1, GameplayObject* obj2)
{
	if (obj1->Left() > obj2->Right())
		return false;
	if (obj2->Left() > obj1->Right())
		return false;
	if (obj1->Bottom() < obj2->Top())
		return false;
	if (obj2->Bottom() < obj1->Top())
		return false;
	return true;
}
GameplayObject* CColision::GetSweptBroadphaseBox(GameplayObject* o,float time)
{
	GameplayObject* ob = new GameplayObject();
	int x, y, w, h;
	x = o->_vx>0 ? o->_x : o->_x + o->_vx*time;
	y = o->_vy>0 ? o->_y : o->_y + o->_vy*time;
	w = o->_vx > 0 ? o->_width + o->_vx*time : o->_width - o->_vx*time;
	h = o->_vy > 0 ? o->_height + o->_vy*time : o->_height - o->_vy*time;
	ob->Create(x, y, w, h);
	return ob;
}
float CColision::mSweptAABB(GameplayObject* obj1, GameplayObject* obj2, float &normalx, float &normaly,float time)
{
	
	if (!collision(GetSweptBroadphaseBox(obj1,time), obj2))
	{
		return 1.0f;
	}

	float dxEntry, dxExit;
	float dyEntry, dyExit;

	if (obj1->_vx > 0.0f)
	{
		dxEntry = obj2->_x - (obj1->_x + obj1->_width);
		dxExit = (obj2->_x + obj2->_width) - obj1->_x;
	}
	else
	{
		dxEntry = (obj2->_x + obj2->_width) - obj1->_x;
		dxExit = obj2->_x - (obj1->_x + obj1->_width);
	}

	if (obj1->_vy > 0.0f)
	{
		dyEntry = obj2->_y - (obj1->_y + obj1->_height);
		dyExit = (obj2->_y + obj2->_height) - obj1->_y;
	}
	else
	{
		dyEntry = (obj2->_y + obj2->_height) - obj1->_y;
		dyExit = obj2->_y - (obj1->_y + obj1->_height);
	}

	float txEntry, txExit;
	float tyEntry, tyExit;

	if (obj1->_vx == 0.0f)
	{
		// đang đứng yên thì bằng vô cực (chia cho  0)
		txEntry = -std::numeric_limits<float>::infinity();
		txExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		txEntry = dxEntry / obj1->_vx;
		txExit = dxExit / obj1->_vx;
	}

	if (obj1->_vy == 0.0f)
	{
		tyEntry = -std::numeric_limits<float>::infinity();
		tyExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		tyEntry = dyEntry / obj1->_vy;
		tyExit = dyExit / obj1->_vy;
	}

	// thời gian va chạm là thời gian lớn nhất của 2 trục (2 trục phải cùng tiếp xúc thì mới va chạm)
	float entryTime = max(txEntry, tyEntry);
	// thời gian hết va chạm là thời gian của 2 trục, (1 cái ra khỏi là object hết va chạm)
	float exitTime = min(txExit, tyExit);

	// kiểm tra xem có thể va chạm không
	if (entryTime > exitTime || txEntry < 0.0f && tyEntry < 0.0f || txEntry > time || tyEntry > time)
	{
		return 1.0f;// khong co va cham
	}

	if (txEntry > tyEntry)
	{
		if (dxEntry > 0.0f)
		{
			normalx=1;//Left
		}
		else
		{
			normalx = -1;//Right
		}
	}
	else
	{
		if (dyEntry > 0.0f)
		{
			normaly = 1;// top
		}
		else
		{
			normaly = -1; //bot
		}
	}
	return entryTime;

}

CColision::CColision()
{
}


CColision::~CColision()
{
}
