#include "types.h"
#include "pso/player/TObjPlayer_801D6C4C.h"
#include "pso/system/memory.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/particle/TParticleCtrl.h"

extern "C" {

void TObjPlayer::reset_particle_ctrl(s32 *ctrl) {
    *ctrl = 0;
    ((TParticleCtrl *)ctrl)->destroy_particle();
}

s32 destroy__10TObjPlayerFis(saddr ctrl, s16 flags) {
    if (ctrl != 0) {
        ((TParticleCtrl *)ctrl)->destroy_particle();
        if (flags > 0) {
            ::operator delete((void *)ctrl);
        }
    }
    return ctrl;
}

PlayerBattleScore::PlayerBattleScore() {
    pad_4 = 0;
    TObjPlayer::reset_particle_ctrl(&timer);
}

s32 TObjPlayer__sub_801D6D28(void *record) {
    s32 level = *(s8 *)((s8 *)record + 0x13);
    if ((level < 0) || (level > 0x63)) {
        return 0;
    }
    return level;
}

void TObjPlayer::set_level(s32 lvl) {
    if ((lvl < 0) || (lvl > 0x63)) {
        lvl = 0;
    }
    *(s8 *)((s8 *)this + 0x13) = lvl;
}

}
