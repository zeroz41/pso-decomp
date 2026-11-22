#include "types.h"
#include "pso/system/vector.h"
#include "pso/enemy/nanodrago/TObjEneNanoDrago.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/player/TObjPlayer_801542CC.h"

#pragma push
#pragma fp_contract on
// The hook update_action_hold_status calls: a drago still hidden in flight (behavior_flags bit 18)
// lands back home; otherwise a pending appear (next action 7) is dropped, as in
// TObjEneDubchik::clear_state7_flag.
void TObjEneNanoDrago::clear_state7_flag() {
    if (behavior_flags & 0x40000) {
        behavior_flags &= ~0x40000;
        VecCopy(&position, &home_position);
        project_actor_to_ground(this, &position, NULL);
        return;
    }
    if (next_action == 7) {
        behavior_flags &= ~1;
        update_if_active(0);
    }
}
#pragma pop
