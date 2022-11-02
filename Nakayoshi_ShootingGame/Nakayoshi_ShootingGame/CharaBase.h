#pragma once
#include "SphereCollider.h"
#include"BulletsBase.h"
class CharaBase : public SphereCollider{

protected:
	BulletsBase** bullets;
	int *image;
//bullets(ポインタ配列)
	T_Location speed;
public:
	CharaBase(T_Location location, float radius, T_Location speed);

public:
	virtual void Update() = 0;
	virtual void Draw() =0;
	virtual void Hit(int damage) = 0;
	BulletsBase** GetBullets();
	void DeleteBullet(int bulletNum);

};

