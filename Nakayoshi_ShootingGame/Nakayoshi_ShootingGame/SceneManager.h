#pragma once
#include"AbstractScene.h"


class SceneManager :public AbstractScene {
private:
	AbstractScene* mScene;
public:
	
	SceneManager(AbstractScene* scene) :mScene(scene) {}
	
	~SceneManager() {
		delete mScene;
	}

    void Update() override;
	
	void Draw() const override;

	virtual AbstractScene* ChangeScene() override;

};
