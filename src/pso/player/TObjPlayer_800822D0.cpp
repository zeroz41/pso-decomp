#include "types.h"
#include "pso/player/TObjPlayer_800822D0.h"
#include "pso/player/TUnk_804806E8.h"
#include "pso/misc/TUnk_8048E1A4.h"
#include "pso/player/TObjPlayer.h"

void TUnk_8048E1A4::apply_knockback_from_attacker(u8 *) {  }
void TObjPlayer::set_position_xy(f32 a, f32 b) { this->position.z = a; this->prev_position.x = b; }

f32 TUnk_804806E8::get_speed() { return this->m_c0; }

u8 TObjPlayer::test_action_mask(s32 arg1) {
    return (u8) (((*(s32 *)&this->unk_31C[4]) & arg1) != 0);
}

s32 TObjPlayer__sub_80082300(void* p) { return *(s32*)((char*)p + 0xc); }
