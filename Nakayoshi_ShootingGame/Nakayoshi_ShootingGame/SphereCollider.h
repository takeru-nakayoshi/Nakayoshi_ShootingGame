#pragma once
#include"common.h"

class SphereCollider {
private:
	 //���S���W
	T_Location location;
	//���a
	float radius;		 

public:
	SphereCollider(T_Location location, float radius);

public:
	//SphereCollider���m�̓����蔻��
	bool HitSphere(const SphereCollider* collider) const;		
	//���S���W�̎擾
	T_Location GetLocation()const;		
	//���S���W�̎w��
	void SetLocation(T_Location location);
	//���a�̎擾
	float Getradius() const;			
		
};
