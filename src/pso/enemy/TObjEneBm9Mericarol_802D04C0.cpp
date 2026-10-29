#include "types.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/enemy/TObjEneDD_ST.h"
#include "pso/enemy/TObjEneBm9Mericarol.h"

extern "C" {

s32 enemy_clear_target__12TObjEneDD_STFUs(void *);
s32 set_field_378__9TObjEneDDFl(void *, s32, s32);
s32 advance_animation_playback();
s32 try_set_mode8_if_flag2__19TObjEneBm9MericarolFv();
s32 TObjEneBm9Mericarol__sub_802D093C(void *);
extern const f32 lbl_805DE73C;

void TObjEneBm9Mericarol::handle_event(s32 arg1) {
    s32 temp_r5;

    switch (arg1) {
    case 4:
        this->requested_action = 2;
        this->vfunc_96();
        TObjEneBm9Mericarol__sub_802D093C(this);
        temp_r5 = this->m_454;
        this->m_454 = (s32) (temp_r5 & ~0x28);
        set_field_378__9TObjEneDDFl(this, 2, temp_r5);
        enemy_clear_target__12TObjEneDD_STFUs(this);
        return;
    case 3:
        if ((try_set_mode8_if_flag2__19TObjEneBm9MericarolFv() == 0) && (update_linked_position(lbl_805DE73C) != 0)) {
            transition_enemy_state(3);
        }
    case 5:
    case 1:
        return;
    case 0:
        advance_animation_playback();
        this->vfunc_102();
        this->vfunc_88();
        break;
    }
}

}
