#pragma once
#include "Screen.h"
#include"Sound.h"
class State_1 :
	public Screen
{
private:
	static State_1* instance;
public:
	static State_1* getInstance();
	void Init(HWND hWnd, HINSTANCE instance);
	void Update(float time);
	void Draw(float time);
	void Delete();
	State_1();
	~State_1();
};

