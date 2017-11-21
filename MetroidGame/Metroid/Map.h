#pragma once
#include"QTree.h"
#include"Node.h"
#include"Camera.h"
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
#include"Colision.h"
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<iostream>
#include<fstream>
using namespace std;

/*
Class Map co nhiem vu:
- Load obj tu file txt vao game
- Kiem tra va cham giua camera voi cac node va xuat ra danh sach cac node va cham vs camera
- Load cac obj trong cac node va cham voi camera vao game
*/
class Map
{

public:
	static Node* LoadObjectFromFile(char* file_name);
	static void ColisionCamera(Node* r,float time);
	Map();
	~Map();
};

