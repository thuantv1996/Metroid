#pragma once
#include"QNode.h"
#include"MapInfo.h"
#include"Camera.h"
class QTree
{
private:
	static QTree* instance;
public:
	QNode* Root;
	static QTree* getInstance();
	void Build();
	void LoadObjectToCamera(QNode* r);
	QTree();
	~QTree();
};

