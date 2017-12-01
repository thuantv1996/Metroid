#include "QTree.h"


QTree::QTree()
{
}
QTree* QTree::instance = 0;
QTree* QTree::getInstance()
{
	if (!instance)
	{
		instance = new QTree();
	}
	return instance;
}
QTree::~QTree()
{
}

void QTree::Build()
{
	map<int, QNode*>::iterator temp;
	for (temp = MapInfo::getInstance()->mapNode.begin(); temp != MapInfo::getInstance()->mapNode.end(); temp++)
	{
		int id_c = temp->first;
		if (id_c == 0)
		{
			Root = MapInfo::getInstance()->mapNode[id_c];
		}
		else
		{
			int id_p = id_c / 10;
			int child = id_c % 10;
			QNode* parent= MapInfo::getInstance()->mapNode[id_p];
			if (parent!=NULL)
			{
				switch (child)
				{
				case 1:
					parent->_1 = MapInfo::getInstance()->mapNode[id_c];
					break;
				case 2:
					parent->_2 = MapInfo::getInstance()->mapNode[id_c];
					break;
				case 3:
					parent->_3 = MapInfo::getInstance()->mapNode[id_c];
					break;
				case 4:
					parent->_4 = MapInfo::getInstance()->mapNode[id_c];
					break;
				}
			}
		}	
	}
}
void QTree::LoadObjectToCamera(QNode* r)
{
	if (!CColision::collision(Camera::getInstance(), r))
	{
		return;
	}
	if (r->_id == 0)
	{
		Camera::getInstance()->listObjectOnCamera.clear();
		/*Camera::getInstance()->GetListItem().clear();
		Camera::getInstance()->GetListEnemy().clear();
		Camera::getInstance()->GetListGround().clear();*/
	}
	if (r->_1 != NULL)
	{
		LoadObjectToCamera(r->_1);
		LoadObjectToCamera(r->_2);
		LoadObjectToCamera(r->_3);
		LoadObjectToCamera(r->_4);
	}
	if (r->lstIdObject.empty())
	{
		return;
	}
	for (int i = 0; i < r->lstIdObject.size(); i++)
	{
		if (!MapInfo::getInstance()->mapObject[r->lstIdObject[i]]->isDead)
		{
				Camera::getInstance()->AddObject(MapInfo::getInstance()->mapObject[r->lstIdObject[i]]);
		}
	}
}
