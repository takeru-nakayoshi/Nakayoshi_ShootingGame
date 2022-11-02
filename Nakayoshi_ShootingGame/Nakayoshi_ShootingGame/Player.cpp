#include "Player.h"
#include"DxLib.h"
#include"StraightBullets.h"
#include"KeyManager.h"

Player::Player(T_Location Location) 
	: CharaBase(Location, 10.f, T_Location{ 2,2 }), score(0), life(1) {
	bullets = new BulletsBase * [30];
	for (int i = 0; i < 30; i++) {
		bullets[i] = nullptr;
	}
}

void Player::Update() {
	T_Location newLocation = GetLocation();
	if (KeyManager::OnkeyPresed(KEY_INPUT_W)) {
		newLocation.y -= speed.y;
	}
	if (KeyManager::OnkeyPresed(KEY_INPUT_S)) {
		newLocation.y += speed.y;
	}
	if (KeyManager::OnkeyPresed(KEY_INPUT_A)) {
		newLocation.x -= speed.x;
	}
	if (KeyManager::OnkeyPresed(KEY_INPUT_D)) {
		newLocation.x += speed.x;
	}
	SetLocation(newLocation);
	
	int bulletCount;
	for (bulletCount = 0; bulletCount < 30; bulletCount++) {
		if (bullets[bulletCount] == nullptr) {
				break;
			}
		bullets[bulletCount]->Update();
		//��ʊO�Œe������
		if (bullets[bulletCount]->isScreenOut()) {
			DeleteBullet(bulletCount);
			bulletCount--;
		}
	}
		


	if (KeyManager::OnMousePresed(MOUSE_INPUT_LEFT)){
		if (bulletCount < 30 && bullets[bulletCount] == nullptr) {
			bullets[bulletCount] = new StraightBullets(GetLocation());
		}
	}
}
void Player::Draw() {
	DrawCircle(GetLocation().x, GetLocation().y, Getradius(), GetColor(255, 0, 0));

	for (int bulletCount = 0; bulletCount < 30; bulletCount++) {
		if (bullets[bulletCount] == nullptr) {
			break;
		}
		bullets[bulletCount]->Draw();
	}

}
void Player::Hit(int damage) {

}
bool Player::LifeCheck() {
	bool ret = (life <= 0);
	return ret;
}
int Player::GetScore() {
	return score;
}