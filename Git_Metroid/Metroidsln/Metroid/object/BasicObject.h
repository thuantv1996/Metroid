#pragma once
#include"../global.h"
#include<vector>
using namespace std;
class BasicObject
{
protected:
	// hộp xét va chạm
	Box box;
	// biến kiểm tra có va chạm hay không
	bool isColl;
	// Danh sách đối tượng va chạm
	vector<BasicObject*> lstColl;
	// biến kiểm tra đối tượng đã chết hay chưa
	bool die;
	// biến lưu thời gian update đối tượng
	float time;
	// biến lưu chỉ số máu của đối tượng
	int hp;
public:
	Box getBox();
	int getHp();
	bool isDie();
	virtual void Init();
	virtual void Update(float dtime);
	virtual void Render(float dtime);
	virtual void OnCollision(BasicObject* o,float nx,float ny);
	BasicObject();
	~BasicObject();
};

