#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TOBarrierEnergy01.h"

extern "C" {

s32 update_anim_phase__13TObjMapObjectFv();

extern void *TOBarrierEnergy01__texture_lists;

void TOBarrierEnergy01::update_closed() {
    update_anim_phase__13TObjMapObjectFv();
    this->play_ambient_loop_sound();
    if (this->door_flags & 1) {
        this->m_ac = 1;
        set_indexed_flags(0, 8);
        this->texlist = (s32) *(s32 *)((s8 *)TOBarrierEnergy01__texture_lists + 4);
    }
}

}
