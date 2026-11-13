#include "types.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/enemy/mericarol/TObjEneBm9Mericarol.h"

extern "C" {
void enemy_clear_target__12TObjEneDD_STFUs(TObjEneDD_ST *self);
extern const f32 lbl_805DE73C;
}

void TObjEneBm9Mericarol::handle_event(s32 arg1) {
    switch (arg1) {
    case 4:
        requested_action = 2;
        vfunc_96();
        sub_802D093C();
        m_438 &= ~0x28;
        set_field_378(2);
        enemy_clear_target__12TObjEneDD_STFUs(this);
        return;
    case 3:
        if (try_set_mode8_if_flag2() == 0 && update_linked_position(lbl_805DE73C) != 0) {
            transition_enemy_state(3);
        }
    case 5:
    case 1:
        return;
    case 0:
        advance_animation();
        vfunc_102();
        vfunc_88();
        break;
    }
}
