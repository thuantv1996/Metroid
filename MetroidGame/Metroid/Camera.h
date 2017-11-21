#ifndef CAMERA_H
#define CAMERA_H

#include <DirectXMath.h>
#include"GraphicsDevice.h"
#include"GameplayObject.h"
#include"MetroidChacracter.h"
#include"Node.h"
#include"Colision.h"
#include<iostream>
#include<vector>
#include<D3dx9math.h>
using namespace std;


class Camera: public GameplayObject
{
public:
	bool vCam;// bien cho phep di chuyen ca me ra theo chieu doc
	D3DXMATRIX mt;
public:
	Camera();
	static Camera* getInstance();
	void Update(float time);
	void Draw(float time);
	void OnCollision(GameplayObject* o,float nx,float ny);
	RECT getRect();
	vector<GameplayObject*> GetListItem();
	vector<GameplayObject*> GetListEnemy();
	vector<GameplayObject*> GetListGround();
	bool findObject(GameplayObject* o);// tra ve true neu obj do co trong lst
	void AddObject(GameplayObject* o);
	void DeleteObject();
	void UpdateObject(float time);
	D3DXMATRIX getMatrix();
private:
	vector<GameplayObject*> lstItem;
	vector<GameplayObject*> lstEnemy;
	vector<GameplayObject*> lstGround;
	static Camera* instance;
};

#endif /* CAMERA_H */
