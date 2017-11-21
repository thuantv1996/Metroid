#include "QTree.h"


QTree::QTree()
{
}


QTree::~QTree()
{
}

void QTree::Build(int ws, int hs, Node* r)
{
	if (r->_width <= ws&&r->_height <= hs)
	{
		return;
	}
	if (r->lst.size() == 0)
	{
		return;
	}
	r->CreateNode();
	for (int i = 0; i < r->lst.size(); i++)
	{
		if (r->_1->AddObject(r->lst[i]))
		{
			r->Delete(r->lst[i]->_id);
			i--;
			continue;
		}
		if (r->_2->AddObject(r->lst[i]))
		{
			r->Delete(r->lst[i]->_id);
			i--;
			continue;
		}
		if (r->_3->AddObject(r->lst[i]))
		{
			r->Delete(r->lst[i]->_id);
			i--;
			continue;
		}
		if (r->_4->AddObject(r->lst[i]))
		{
			r->Delete(r->lst[i]->_id);
			i--;
			continue;
		}
	}
	Build(ws, hs, r->_1);
	Build(ws, hs, r->_2);
	Build(ws, hs, r->_3);
	Build(ws, hs, r->_4);

}
Node* QTree::CreateRoot(int w, int h, vector<GameplayObject*> l)
{
	Node* r = new Node();
	r->Create(0, 0, w, h);
	r->_id = 0;
	for (int i = 0; i < l.size(); i++)
	{
		r->AddObject(l[i]);
	}
	return r;
}