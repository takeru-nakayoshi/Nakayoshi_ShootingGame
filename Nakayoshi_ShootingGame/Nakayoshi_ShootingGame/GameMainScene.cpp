#include "GameMainScene.h"

GameMainScene::GameMainScene() {
	T_Location location = T_Location{ 20, 100 };
	player = new Player(location);
	enemy = new Enemy * [10];
	for (int i = 0; i < 10; i++) {
		enemy[i] = nullptr;
	}
	enemy[0] = new Enemy(T_Location{ 200,0 });
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

	int EnemyCount;
	for (EnemyCount = 0; EnemyCount < 10; EnemyCount++) {
		if (enemy[EnemyCount] == nullptr) {
			break;
		}
		enemy[EnemyCount]->Update();
	}
	
	
	BulletsBase** bullet = player->GetBullets();
	for (EnemyCount = 0; EnemyCount < 10; EnemyCount++) {
		if (enemy[EnemyCount] == nullptr) {
			break;
		}
		for (int bulletCount = 0; bulletCount < 30; bulletCount++) {
			
			if (bullet[bulletCount] == nullptr)
				break;
	
			if (enemy[EnemyCount]->HitSphere(bullet[bulletCount])) {
				//�G�l�~�[�Ƀv���C���[�̒e���q�b�g���Ă�
	
				//�G�l�~�[�Ƀ_���[�W��^����
				enemy[EnemyCount]->Hit(bullet[bulletCount]->GetDamge());
				//�e���폜���܂�
				player->DeleteBullet(bulletCount);
				bulletCount--;
				//�G�l�~�[��HP��0�ȉ���������A�G�l�~�[���폜
				if (enemy[EnemyCount]->HpCheck()) {

				}
			}
		}
	}
}


//�`��
void GameMainScene::Draw() const {
	player->Draw();
	for (int EnemyCount = 0; EnemyCount < 10; EnemyCount++) {
		if (enemy[EnemyCount] == nullptr) {
			break;
		}
		enemy[EnemyCount]->Draw();
	}
}
	

//�V�[���̕ύX
AbstractScene* GameMainScene::ChangeScene() {
	return this;
}