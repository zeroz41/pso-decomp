#include "types.h"
#include "pso/item/TItemEffectWeapon.h"

extern "C" {

int decrement_packed_timer__15TObjBoss2TunnelFPUll(void*);

int TItemEffectWeapon::decrement_timer() { return decrement_packed_timer__15TObjBoss2TunnelFPUll(this); }

}
