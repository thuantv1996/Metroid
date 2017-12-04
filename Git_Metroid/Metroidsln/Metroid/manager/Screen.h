#pragma once
class Screen
{
public:
	void Init();
	void Update(float dtime);
	void Render(float dtime);
	void Delete();
	Screen();
	~Screen();
};

