#pragma once
#include "CharaBase.h"
class Player : public CharaBase{
private:
	int score;
	int life;

public:
	Player(T_Location Location);
public:
	void Update() override;
	void Draw() override;
	void Hit() override;
	bool LifeCheck();
	int GetScore();
	
};

