#pragma once
#include"Node.h"
class QTree
{
public:
	static void Build(int ws, int hs, Node* R);
	static Node* CreateRoot(int w, int h, vector<GameplayObject*> l);
	QTree();
	~QTree();
};

