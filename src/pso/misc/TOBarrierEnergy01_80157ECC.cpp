#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TOBarrierEnergy01.h"

extern "C" {

s32 update_anim_phase__13TUnk_804AFBF8Fv();

extern void *TOBarrierEnergy01__texture_lists;

void TOBarrierEnergy01::play_proximity_sound() {
    update_anim_phase__13TUnk_804AFBF8Fv();
    this->play_ambient_loop_sound();
    if (this->m_d0 & 1) {
        this->m_ac = 1;
        set_indexed_flags(0, 8);
        this->texlist = (s32) *(s32 *)((s8 *)TOBarrierEnergy01__texture_lists + 4);
    }
}

}
