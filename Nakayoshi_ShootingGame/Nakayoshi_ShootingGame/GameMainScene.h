#pragma once
#include "AbstractScene.h"
#include"Player.h"
#include"Enemy.h"
class GameMainScene :public AbstractScene
{
private:
	Player* player;
	Enemy** enemy;

public:
	GameMainScene();
	virtual ~GameMainScene() {};
public:
	

	virtual void Update() override;
	virtual void Draw() const override;
	virtual AbstractScene* ChangeScene() override;
};

