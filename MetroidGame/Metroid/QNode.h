#pragma once
#include "GameplayObject.h"
#include<vector>
using namespace std;
class QNode :
	public GameplayObject
{
public:
	QNode* _1;
	QNode* _2;
	QNode* _3;
	QNode* _4;
	vector<int> lstIdObject;
public:
	QNode();
	~QNode();
};

