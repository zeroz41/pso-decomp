#include "types.h"
#include "pso/player/TObjPlayer_801D6C4C.h"
#include "pso/system/memory.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/particle/TParticleCtrl.h"

extern "C" {

int clear_player_sub_object_slots(void*);

void TObjPlayer::reset_particle_ctrl(s32 *arg0) {
    *arg0 = 0;
    ((TParticleCtrl *)arg0)->destroy_particle();
}

s32 destroy__10TObjPlayerFis(saddr arg0, s16 arg1) {
    if (arg0 != 0) {
        ((TParticleCtrl *)arg0)->destroy_particle();
        if (arg1 > 0) {
            ::operator delete((void *)arg0);
        }
    }
    return arg0;
}

void*TObjPlayer::init_sub_objects() { TObjPlayer::init_sub_object((saddr)((char*)this + 0x8)); TObjPlayer::init_sub_object((saddr)((char*)this + 0x18)); TObjPlayer::init_sub_object((saddr)((char*)this + 0x28)); TObjPlayer::init_sub_object((saddr)((char*)this + 0x38)); TObjPlayer::init_sub_object((saddr)((char*)this + 0x48)); clear_player_sub_object_slots((char*)this + 0x58); *(int*)((char*)this + 0x4) = 0; TObjPlayer::reset_particle_ctrl((s32 *)this); return this; }

s8 TObjPlayer__sub_801D6D28(void *arg0) {
    s32 temp_r3 = *(s8 *)((s8 *)arg0 + 0x13);
    if ((temp_r3 < 0) || (temp_r3 > 0x63)) {
        return 0;
    }
    return temp_r3;
}

void TObjPlayer::set_level(s32 lvl) {
    u8 *arg0 = (u8 *)this;
    s32 var_r4;

    var_r4 = lvl;
    if ((var_r4 < 0) || (var_r4 > 0x63)) {
        var_r4 = 0;
    }
    *(s8 *)((s8 *)arg0 + 0x13) = var_r4;
}

}
