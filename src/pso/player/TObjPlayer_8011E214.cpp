#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/weapon/TItemWeapon.h"

void TObjPlayer::set_flag_10000() {
    set_state_flags(0x10000);
}
void TObjPlayer::set_state_flags(u32 v) { this->m_334 |= v; }
