#include "types.h"
#include "pso/weapon/shoot/TItemShoot.h"

void TItemShoot::set_texture_id(s32 v) { *(s32*)((char*)this + 0x70) = v; }
