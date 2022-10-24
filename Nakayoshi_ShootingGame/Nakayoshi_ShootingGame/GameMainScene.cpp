#include "GameMainScene.h"

GameMainScene::GameMainScene() {
	T_Location location = T_Location{ 20, 100 };
	player = new Player(location);
}

//�`��ȊO
void GameMainScene::Update() {
	/*T_Location location = T_Location{ 100,100 };
	Player test = Player(location);
	test.Draw();

	if (test.HitSphere(player)) {
		return;
	}*/

	
	player->Update();
}

//�`��
void GameMainScene::Draw() const {
	player->Draw();
}

//�V�[���̕ύX
AbstractScene* GameMainScene::ChangeScene() {
	return this;
}