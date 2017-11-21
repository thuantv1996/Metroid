#include "Map.h"
#include"Wall.h"


Map::Map()
{
}



Map::~Map()
{
}

Node* Map::LoadObjectFromFile(char* file_name)
{
	ifstream f(file_name);
	if (!f.is_open())
		printf("khong mo dc file");
	vector<GameplayObject*> l;
	int id=0;
	while (!f.eof())
	{
		id++;
		char name[255];
		int x, y, w, h;
		GameplayObject* o;
		f >> name >> name >> x >> y >> w >> h;
		if (strcmp(name, "RIO")==0)
		{
			o = new Rio();
			o->Create( x, y, w, h);
			o->_id = id;
			o->Init();
			o->_xOld = x;
			o->_yOld = y;
			l.push_back(o);
			continue;
		}
		if (strcmp(name, "RIPPER") == 0)
		{
			o = new Ripper();
			o->Create(x, y, w, h);
			o->Init();
			o->_id = id;
			o->_xOld = x;
			o->_yOld = y;
			l.push_back(o);
			continue;
		}
		if (strcmp(name, "SKREE") == 0)
		{
			o = new Sknee();
			o->Create(x, y, w, h);
			o->Init();
			o->_id = id;
			o->_xOld = x;
			o->_yOld = y;
			l.push_back(o);
			continue;
		}
		if (strcmp(name, "TUBE") == 0)
		{
			o = new TuBe();
			o->Create(x, y, w, h);
			o->Init();
			o->_id = id;
			o->_xOld = x;
			o->_yOld = y;
			l.push_back(o);
			continue;
		}
		if (strcmp(name, "ZOMMER") == 0)
		{
			o = new Zoomer();
			o->Create(x, y, w, h);
			o->Init();
			o->_id = id;
			o->_xOld = x;
			o->_yOld = y;
			l.push_back(o);
			continue;
		}
		if (strcmp(name, "GROUND") == 0)
		{
			o = new Ground();
			o->Create(x, y, w, h);
			o->Init();
			o->_id = id;
			o->_xOld = x;
			o->_yOld = y;
			l.push_back(o);
			continue;
		}
		if (strcmp(name, "LAVA") == 0)
		{
			o = new Lave();
			o->Create(x, y, w, h);
			o->Init();
			o->_id = id;
			o->_xOld = x;
			o->_yOld = y;
			l.push_back(o);
			continue;
		}
		if (strcmp(name, "ROCKET") == 0)
		{
			o = new Rocket_Item();
			o->Create(x, y, w, h);
			o->Init();
			o->_id = id;
			o->_xOld = x;
			o->_yOld = y;
			l.push_back(o);
			continue;
		}
		if (strcmp(name, "MARU") == 0)
		{
			o = new MaruMari();
			o->Create(x, y, w, h);
			o->Init();
			o->_id = id;
			o->_xOld = x;
			o->_yOld = y;
			l.push_back(o);
			continue;
		}
		if (strcmp(name, "BOMB") == 0)
		{
			o = new Bomb_Item();
			o->Create(x, y, w, h);
			o->Init();
			o->_id = id;
			o->_xOld = x;
			o->_yOld = y;
			l.push_back(o);
			continue;
		}
		if (strcmp(name, "BEAM") == 0)
		{
			o = new LongBeam();
			o->Create(x, y, w, h);
			o->Init();
			o->_id = id;
			o->_xOld = x;
			o->_yOld = y;
			l.push_back(o);
			continue;
		}
		if (strcmp(name, "DOOR") == 0)
		{
			o = new Door();
			o->Create( x, y, w, h);
			o->Init();
			o->_id = id;
			o->_xOld = x;
			o->_yOld = y;
			l.push_back(o);
			continue;
		}
		if (strcmp(name, "WALL") == 0)
		{
			o = new Wall();
			o->Create(x, y, w, h);
			o->Init();
			o->_id = id;
			o->_xOld = x;
			o->_yOld = y;
			l.push_back(o);
			continue;
		}
	}
	Node* root = QTree::CreateRoot(7680, 4560, l);
	QTree::Build(256, 250, root);
	f.close();
	return root;
}

void Map::ColisionCamera(Node* r,float time)
{
	if (!CColision::collision(Camera::getInstance(), r))
	{
		return;
	}
	if (r->_1!=NULL)
	{
		ColisionCamera(r->_1,time);
		ColisionCamera(r->_2, time);
		ColisionCamera(r->_3, time);
		ColisionCamera(r->_4, time);
	}
	if (r->lst.size() == 0)
	{
		return;
	}
	for (int i = 0; i < r->lst.size(); i++)
	{
		if (!r->lst[i])
			continue;
		if (!Camera::getInstance()->findObject(r->lst[i]))
		{
			Camera::getInstance()->AddObject(r->lst[i]);
		}
	}

}


