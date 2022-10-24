#pragma once
#include "AbstractScene.h"
#include"Player.h"
class GameMainScene :public AbstractScene
{
private:
	Player* player;

public:
	GameMainScene();
	virtual ~GameMainScene() {};
public:
	

	virtual void Update() override;
	virtual void Draw() const override;
	virtual AbstractScene* ChangeScene() override;
};

