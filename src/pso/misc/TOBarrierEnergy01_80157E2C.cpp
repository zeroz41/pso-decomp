#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TOBarrierEnergy01.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

s32 update_anim_phase__13TUnk_804AFBF8Fv();

extern s32 *TOBarrierEnergy01__texture_lists;

void TOBarrierEnergy01::vfunc_17() {
    update_anim_phase__13TUnk_804AFBF8Fv();
    this->play_ambient_loop_sound();
    if (!(this->m_d0 & 1)) {
        this->m_ac = 3;
        this->clear_player_status_flag(0, 8);
        this->texlist = (s32) *TOBarrierEnergy01__texture_lists;
    }
}

}
