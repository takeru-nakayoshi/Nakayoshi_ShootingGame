#include "BulletsBase.h"

BulletsBase::BulletsBase(T_Location location, float radius, int damge, T_Location speed)
	:SphereCollider(location, radius), damage(damge), speed(speed) {

}
int BulletsBase::GetDamge() {
	return damage;
}