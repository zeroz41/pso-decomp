#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TOBarrierEnergy01.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

s32 update_anim_phase__13TObjMapObjectFv();

extern s32 *TOBarrierEnergy01__texture_lists;

void TOBarrierEnergy01::update_open() {
    update_anim_phase__13TObjMapObjectFv();
    this->play_ambient_loop_sound();
    if (!(this->door_flags & 1)) {
        this->m_ac = 3;
        this->clear_player_status_flag(0, 8);
        this->texlist = (s32) *TOBarrierEnergy01__texture_lists;
    }
}

}
