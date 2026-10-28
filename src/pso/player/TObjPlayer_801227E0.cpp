#include "types.h"
#include "pso/items/TItemWeapon.h"
#include "pso/player/TObjPlayer.h"

extern "C" {


void TObjPlayer::update_twice() { ((TItemWeapon *)this)->roll_technique(); ((TItemWeapon *)this)->roll_technique(); }

}
