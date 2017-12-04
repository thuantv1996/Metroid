#include "BasicObject.h"



BasicObject::BasicObject()
{
}

Box BasicObject::getBox() { return box; }
int BasicObject::getHp(){return hp;}
bool BasicObject::isDie() { return die; }
void BasicObject::Init(){}
void BasicObject::Update(float dtime){}
void BasicObject::Render(float dtime){}
void BasicObject::OnCollision(BasicObject* o, float nx, float ny){}

BasicObject::~BasicObject()
{
}
