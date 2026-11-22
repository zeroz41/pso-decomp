#include "types.h"
#include "pso/system/vector.h"
#include "pso/enemy/nanodrago/TObjEneNanoDrago.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/player/TObjPlayer_801542CC.h"

#pragma push
#pragma fp_contract on
// The hook update_action_hold_status calls: a drago still hidden in flight (m_388 bit 18)
// lands back home; otherwise a pending appear (next action 7) is dropped, as in
// TObjEneDubchik::clear_state7_flag.
void TObjEneNanoDrago::clear_state7_flag() {
    if (m_388 & 0x40000) {
        m_388 &= ~0x40000;
        VecCopy(&position, &home_position);
        project_actor_to_ground(this, &position, NULL);
        return;
    }
    if (next_action == 7) {
        m_388 &= ~1;
        update_if_active(0);
    }
}
#pragma pop
