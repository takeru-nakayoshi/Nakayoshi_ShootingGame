#pragma once
#include "AbstractScene.h"
class GameMainScene :public AbstractScene
{
public:
	virtual ~GameMainScene() {};

	virtual void Update() override;
	virtual void Draw() const override;
	virtual AbstractScene* ChangeScene() override;
};

