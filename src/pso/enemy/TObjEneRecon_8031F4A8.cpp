#include "types.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/enemy/TObjEneRecon.h"

extern "C" {

s32 advance_animation_playback();
s32 get_flag_b4__9TObjEneDDFv();
s32 is_out_of_range__12TObjEneReconFv();

void TObjEneRecon::handle_action_state(s32 arg1) {

    switch (arg1) {
    case 4:
        *(s32 *)&this->m_428 = (*(s32 *)&this->m_428 & 0xFFFFFFFE);
        this->requested_action = 2;
        this->vfunc_96();
        set_field_378(2);
        return;
    case 3:
        if (is_out_of_range__12TObjEneReconFv() != 0) {
            transition_enemy_state(5);
        }
    case 5:
        return;
    case 0:
        advance_animation_playback();
        update_child_spawn();
        break;
    }
}

void TObjEneRecon::update_state(s32 arg1) {
    switch (arg1) {
    case 4:
        *(s32 *)&this->m_428 = *(s32 *)&this->m_428 & 0xFFFFFFFE;
        this->requested_action = 1;
        this->vfunc_96();
        set_field_378(3);
        return;
    case 3:
        if (get_flag_b4__9TObjEneDDFv() != 0) {
            this->m_4d8 = 0;
            *(s32 *)((s8 *)this + 0x4DC) = 0x1E;
            transition_enemy_state(4);
        }
    case 5:
        return;
    case 0:
        advance_animation_playback();
        break;
    }
}

}
