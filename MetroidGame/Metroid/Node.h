#pragma once
#include "GameplayObject.h"
#include<iostream>
#include<vector>
using namespace std;

class Node :
	public GameplayObject
{
public:
	Node* _1;
	Node* _2;
	Node* _3;
	Node* _4;
	int numberObject;
	vector<GameplayObject*> lst;
public:
	void CreateNode();
	bool AddObject(GameplayObject* o);
	void Delete(int id);
	Node();
	~Node();
};

