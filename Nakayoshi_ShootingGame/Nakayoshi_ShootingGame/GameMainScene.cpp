#include "GameMainScene.h"

GameMainScene::GameMainScene() {
	T_Location location = T_Location{ 20, 100 };
	player = new Player(location);
}

//描画以外
void GameMainScene::Update() {
	/*T_Location location = T_Location{ 100,100 };
	Player test = Player(location);
	test.Draw();

	if (test.HitSphere(player)) {
		return;
	}*/

	
	player->Update();
}

//描画
void GameMainScene::Draw() const {
	player->Draw();
}

//シーンの変更
AbstractScene* GameMainScene::ChangeScene() {
	return this;
}