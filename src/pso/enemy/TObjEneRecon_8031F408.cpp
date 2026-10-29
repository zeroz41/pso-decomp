#include "types.h"
#include "pso/enemy/TObjEneRecon_8031F408.h"
#include "pso/enemy/TObjEneDD.h"

extern "C" {

s32 advance_animation_playback();
s32 get_flag_b4__9TObjEneDDFv();

void TObjEneRecon__sub_8031F408(void *ene_dd, s32 arg1) {

    switch (arg1) {
    case 4:
        *(s32 *)((s8 *)ene_dd + 0x40C) = (*(s32 *)((s8 *)ene_dd + 0x40C) & 0xFFFFFFFE);
        ((TObjEneDD *)ene_dd)->requested_action = 3;
        ((TObjEneDD *)ene_dd)->vfunc_96();
        ((TObjEneDD *)ene_dd)->set_field_378(5);
        break;
    case 3:
        if (get_flag_b4__9TObjEneDDFv() != 0) {
            ((TObjEneDD *)ene_dd)->transition_enemy_state(2);
        }
        break;
    case 5:
        break;
    case 0:
        advance_animation_playback();
        break;
    }
}

}
