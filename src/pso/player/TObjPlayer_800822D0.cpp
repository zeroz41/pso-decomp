#include "pso/TParticleCtrl.h"
#include "types.h"
#include "pso/player/TObjPlayer_800822D0.h"
#include "pso/player/TObjChara.h"
#include "pso/misc/TUnk_8048E1A4.h"
#include "pso/player/TObjPlayer.h"

void TUnk_8048E1A4::apply_knockback_from_attacker(u8 *, f32) {  }
void TParticleCtrl::set_scale(f32 a, f32 b) { field_40 = a; field_44 = b; }

f32 TObjMotion::get_frame() { return this->frame; }

s32 TObjPlayer::test_action_mask(s32 arg1) {
    return (u8) (((*(s32 *)&this->unk_31C[4]) & arg1) != 0);
}

s32 TObjPlayer__sub_80082300(void* p) { return *(s32*)((char*)p + 0xc); }
