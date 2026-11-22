#include "types.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/TObjEnePanBARA.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"

extern "C" {
void fn_800660B8(u8 *arg0);
}

void TObjEnePanarms::init(s16 action) { fn_800660B8((u8 *)this); change_action(action); sub_8002AE64(); }

s32 TObjEnePanBARA::is_dying() {
    return state == 7 || state == 8;
}

int TObjEnePanBARA::get_state_flag() { return (this->actorFlags >> 4) & 0x1; }
