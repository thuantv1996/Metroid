#pragma once
#include "GameplayObject.h"
#include"Animation.h"

class Animation;

#define WIDTH_RIPPER 18
#define HEIGHT_RIPPER 26
#define VX_RIPPER 40
#define	PATH_RIPPER "src//img//enemy//ripper//Ripper.png"


class Ripper :
	public GameplayObject
{
	Animation* lstAction;
public:
	void Draw(float time);
	void Update(float time);
	void SetAction();
	void OnCollision(GameplayObject* obj, int nx, int ny);
	void Init();
	Ripper();
	~Ripper();
};

