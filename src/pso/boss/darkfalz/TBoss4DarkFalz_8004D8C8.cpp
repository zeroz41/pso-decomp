#include "types.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/boss/darkfalz/TObjDFUsoTower.h"

/* Own TU: these four follow __sinit_TBoss4DarkFalz_8004C93C_cpp in .text, and CodeWarrior emits a
 * TU's static initializer after every function of that TU (weak inline copies follow their first
 * caller under -inline off and -inline off,deferred alike). */

struct Obj_8004D8C8 { u8 pad[0x2D4]; u16 f2d4; u16 f2d6; };

extern "C" u16 obj_getArrU16_FC(void *obj, s32 i);

void TBoss4DarkFalz::get_defeat_params(u16 *a, u16 *b, u16 *out) {
    s32 i;
    *a = ((Obj_8004D8C8 *)this)->f2d6;
    *b = ((Obj_8004D8C8 *)this)->f2d4;
    for (i = 0; i < 4; i++) {
        out[i] = obj_getArrU16_FC(this, i);
    }
}

void TBoss4DarkFalz::get_demo2_params(u16 *a, u16 *b, u16 *out) {
    s32 i;
    *a = ((Obj_8004D8C8 *)this)->f2d6;
    *b = ((Obj_8004D8C8 *)this)->f2d4;
    for (i = 0; i < 4; i++) {
        out[i] = obj_getArrU16_FC(this, i);
    }
}

s32 TBoss4DarkFalz::sub_8004D990() {
    return *(s32 *)((s8 *)this + 0x388) - *(s32 *)((s8 *)this + 0x38C);
}

void TObjDFUsoTower::sub_8004D9A0(s32 v) { *(s32 *)((char *)this + 0x90) = v; }
