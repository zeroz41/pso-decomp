#include "types.h"
#include "pso/weapon/shoot/TItemShoot.h"

void TItemShoot::set_particle_flags(s16 v) { *(s16*)((char*)this + 0x60) = v; }
