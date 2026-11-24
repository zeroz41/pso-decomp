#include "types.h"
#include "pso/boss/darkfalz/TBoss4Type3.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/boss/darkfalz/TObjDFUsoTower.h"

/* Own TU: these four follow __sinit_TBoss4DarkFalz_8004C93C_cpp in .text, and CodeWarrior emits a
 * TU's static initializer after every function of that TU (weak inline copies follow their first
 * caller under -inline off and -inline off,deferred alike). */


void TBoss4Type3::get_defeat_params(u16 *a, u16 *b, u16 *out) {
    s32 i;
    *a = local_attacker_id;
    *b = attacker_id;
    for (i = 0; i < 4; i++) {
        out[i] = obj_getArrU16_FC(this, i);
    }
}

void TBoss4Type2::get_demo2_params(u16 *a, u16 *b, u16 *out) {
    s32 i;
    *a = local_attacker_id;
    *b = attacker_id;
    for (i = 0; i < 4; i++) {
        out[i] = obj_getArrU16_FC(this, i);
    }
}

s32 TBoss4DarkFalz::get_live_minion_count() {
    return minions_spawned - minions_lost;
}

void TObjDFUsoTower::set_fade_state(s32 state) { fade_state = state; }
