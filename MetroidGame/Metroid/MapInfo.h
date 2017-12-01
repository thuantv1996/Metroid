#pragma once
#include<map>
#include"QNode.h"
#include"GameplayObject.h"
#include<fstream>
#include"Bomb_Item.h"
#include"Door.h"
#include"Ground.h"
#include"Lave.h"
#include"LongBeam.h"
#include"MaruMari.h"
#include"Rio.h"
#include"Ripper.h"
#include"Sknee.h"
#include"TuBe.h"
#include"Zeb.h"
#include"Zoomer.h"
#include"Rocket_Item.h"
using namespace std;
class MapInfo
{
private:
	static MapInfo* instance;
public:
	map<int, QNode*> mapNode;
	map<int, GameplayObject*> mapObject;
	void LoadNodeFromFile(char* file_name);
	void LoadObjectFromFile(char* file_name);
	static MapInfo* getInstance();
	MapInfo();
	~MapInfo();
};
