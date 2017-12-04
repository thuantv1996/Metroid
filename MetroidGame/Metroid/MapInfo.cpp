#include "MapInfo.h"



MapInfo::MapInfo()
{
}
MapInfo* MapInfo::instance = 0;
MapInfo* MapInfo::getInstance()
{
	if (!instance)
	{
		instance = new MapInfo();
	}
	return instance;
}
void MapInfo::LoadNodeFromFile(char* file_name)
{
	int id, x, y,w,h;
	ifstream f(file_name);
	if (!f.is_open())
		printf("khong mo dc file");
	while (!f.eof())
	{
		f >> id >> x >> y >> w >> h;
		QNode* n = new QNode();
		n->Create(x, y, w, h);
		n->_id = id;
		mapNode[id] = n;
	}
	f.close();
}
void MapInfo::LoadObjectFromFile(char* file_name)
{
	int id,idnode, x, y;
	char type[255];
	ifstream f(file_name);
	if (!f.is_open())
		printf("khong mo dc file");
	while (!f.eof())
	{
		f >> id >> idnode >> type >> x >> y;
		if (mapNode[idnode] != NULL)
		{
			mapNode[idnode]->lstIdObject.push_back(id);
		}
		GameplayObject* go;
		if (strcmp(type, "RIO") == 0)
		{
			go = new Rio();
			go->Create(x, y, 16, 16);
			go->_id = id;
			go->Init();
		}
		if (strcmp(type, "RIPPER") == 0)
		{
			go = new Ripper();
			go->Create(x, y, 16, 16);
			go->_id = id;
			go->Init();
		}
		if (strcmp(type, "SKREE") == 0)
		{
			go = new Sknee();
			go->Create(x, y, 16, 16);
			go->_id = id;
			go->Init();
		}
		if (strcmp(type, "TUBE") == 0)
		{
			go = new TuBe();
			go->Create(x, y, 16, 16);
			go->_id = id;
			go->Init();
		}
		if (strcmp(type, "ZOMMER") == 0)
		{
			go = new Zoomer();
			go->Create(x, y, 16, 16);
			go->_id = id;
			go->Init();
		}
		if (strcmp(type, "GROUND") == 0)
		{
			go = new Ground();
			go->Create(x, y, 16, 16);
			go->_id = id;
			go->Init();
		}
		if (strcmp(type, "LAVA") == 0)
		{
			go = new Lave();
			go->Create(x, y, 16, 16);
			go->_id = id;
			go->Init();
		}
		if (strcmp(type, "ROCKET") == 0)
		{
			go = new Rocket_Item();
			go->Create(x, y, 16, 16);
			go->_id = id;
			go->Init();
		}
		if (strcmp(type, "MARU") == 0)
		{
			go = new MaruMari();
			go->Create(x, y, 16, 16);
			go->_id = id;
			go->Init();
		}
		if (strcmp(type, "BOMB") == 0)
		{
			go = new Bomb_Item();
			go->Create(x, y, 16, 16);
			go->_id = id;
			go->Init();
		}
		if (strcmp(type, "BEAM") == 0)
		{
			go = new LongBeam();
			go->Create(x, y, 16, 16);
			go->_id = id;
			go->Init();
		}
		if (strcmp(type, "DOOR") == 0)
		{
			go = new Door();
			go->Create(x, y, 16, 16);
			go->_id = id;
			go->Init();
		}
		if (strcmp(type, "WALL") == 0)
		{
			go = new Wall();
			go->Create(x, y, 16, 16);
			go->_id = id;
			go->Init();
		}
	}
	f.close();
}
MapInfo::~MapInfo()
{
}
