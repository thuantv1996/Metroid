#include "Node.h"


Node::Node()
{
	_1 = NULL;
	_2 = NULL;
	_3 = NULL;
	_4 = NULL;
}


Node::~Node()
{
}

void Node::CreateNode()
{
	if (!this)
	{
		return;
	}
	_1 = new Node();
	_2 = new Node();
	_3 = new Node();
	_4 = new Node();
	_1->Create(_x, _y, _width / 2, _height / 2);
	_1->_id = _id * 10 + 1;
	_2->Create(_x+_width/2, _y, _width / 2, _height / 2);
	_2->_id = _id * 10 + 2;
	_3->Create(_x, _y+_height/2, _width / 2, _height / 2);
	_3->_id = _id * 10 + 3;
	_4->Create(_x+_width/2, _y+_height/2, _width / 2, _height / 2);
	_4->_id = _id * 10 + 4;
}
bool Node::AddObject(GameplayObject* o)
{
	if (o->Left() >= Left() && o->Right() <= Right() && o->Top() >= Top() && o->Bottom() <= Bottom())
	{
		lst.push_back(o);
		return true;
	}
	return false;
}
void Node::Delete(int id)
{
	for (int i = 0; i < lst.size(); i++)
	{
		if (lst[i]->_id == id)
		{
			lst.erase(lst.begin()+i);
		}
	}
}
