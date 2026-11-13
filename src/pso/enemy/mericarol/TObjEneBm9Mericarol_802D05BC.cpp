#include "types.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/enemy/mericarol/TObjEneBm9Mericarol.h"
#include "pso/boss/volopt/TBoss3Volopt.h"

extern "C" {
void enemy_clear_target__12TObjEneDD_STFUs(TObjEneDD_ST *self);
}

void TObjEneBm9Mericarol::sub_802D05BC(s32 arg1) {
    switch (arg1) {
    case 4:
        requested_action = 2;
        vfunc_95();
        sub_802D093C();
        m_438 |= 0x28;
        m_438 &= ~0x10;
        set_field_378(2);
        enemy_clear_target__12TObjEneDD_STFUs(this);
        m_46c.start_fade_in();
        ((TBoss3Volopt *)&position)->play_area_sound_effect();
        return;
    case 3:
        if (m_46c.advance_toward_max() != 0) {
            transition_enemy_state(2);
        }
    case 1:
        return;
    case 0:
        advance_animation();
        vfunc_102();
        vfunc_88();
        return;
    case 5:
        m_438 &= ~0x28;
        break;
    }
}

void TObjEneBm9Mericarol::handle_action(s32 arg1) {
    switch (arg1) {
    case 4:
        vfunc_95();
        return;
    case 3:
        transition_enemy_state(1);
    case 5:
    case 0:
        return;
    }
}
