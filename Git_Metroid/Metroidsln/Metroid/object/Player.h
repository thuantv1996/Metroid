#pragma once
#include"BasicObject.h"
#include"../framework/InputGame.h"
#include"../manager/Animation.h"
enum MetroidStatus
{
	BEGIN,
	STOP,
	/*UP,
	UP_ATTACK,
	RUN,
	RUN_UP,
	RUN_UP_ATTACK,
	RUN_ATTACK,
	JUM,
	JUM_UP,
	JUM_UP_ATTACK,
	JUM_ROLL,
	ROLL,
	ATTACK,
	JUM_ATTACK,*/
};
class Animation;
class Player : public BasicObject, public InputGame
{
private:
	// singleton
	static Player* instance;
	// quản lý hình ảnh và hành động của player
	Animation* lstAction;
	MetroidStatus curAction;
	// hổ trợ việc vẽ
	int yDraw;
	int xDraw;
	// quản lý phím bấm
	int press_key_z;
	int press_key_x;
	int press_key_c;
	int press_key_up;
	int press_key_down;
	int press_key_left;
	int press_key_right;
	// quản lý các trạng thái
	bool isJumming;
	bool isRolling;
	bool isJumRoll;
	bool isFall;
	// quản lý bất tử lúc va chạm enemy
	bool isbt;
	float count_time_bt;
	int Ve;
public:
	static Player* getInstance();
	// các hàm thực thi
	void Init();
	void Update(float dtime);
	void Render(float dtime);
	// các hàm thể hiện hành vi
	void Begin();
	void Stop();
	void Up();
	void UpAttack();
	void Run();
	void RunUp();
	void Jum();
	void JumUp();
	void JumRoll();
	void Roll();
	void Attack();
	void RunAttack();
	void JumAttack();
	void RunUpAttack();
	void JumUpAttack();
	Player();
	~Player();
};