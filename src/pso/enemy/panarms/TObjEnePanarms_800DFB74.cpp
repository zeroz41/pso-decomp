#include "types.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/TObjEnePanBARA.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"

int TObjEnePanBARA::sub_800DFB74() {
    u8 result = 0;
    if (state == 4 && action_timer < 0) {
        result = 1;
    }
    return result;
}

s32 TObjEnePanBARA::sub_800DFB9C() {
    return (u8)(state == 0xB);
}

s32 TObjEnePanBARA::is_dead() {
    return (u8)(state == 8);
}

int TObjEnePanarms::get_state_flag() { return (this->actorFlags >> 4) & 0x1; }
