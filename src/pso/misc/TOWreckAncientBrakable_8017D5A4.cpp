#include "types.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/unk/text_80087278.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TOWreckAncientBrakable.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

s32 play_sound_effect(s32, void *, s32, s32);
u8 is_current_floor_switch_set(u16);
s32 TOWreckAncientBrakable__sub_8017D444(void *);

void TOWreckAncientBrakable::run_task() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0_2;

    if (TObjPlayer::check_demo_mode() == 1) {
        TOWreckAncientBrakable__sub_8017D444(arg0);
        return;
    }
    switch (this->m_b4) {
    default:
        this->m_b4 = 0;
    case 0:
        temp_r0_2 = this->m_b8;
        if ((temp_r0_2 >= 0) && (temp_r0_2 < 0x100) && (is_current_floor_switch_set((u16) temp_r0_2) == 1)) {
            this->m_b4 = 1;
            play_sound_effect(0x43C11, (u8 *)&this->position, 0, 0);
            spawn_particle_effect(&this->position, 0x45);
            spawn_particle_effect(&this->position, 0x46);
            ((TOWreckAncientBrakable *)arg0)->spawn_debris();
        }
        return;
    case 1:
        ((TObjCollidable *)arg0)->set_flag8();
        queue_destruction__7TObjectFv(arg0);
        break;
    }
}

}
