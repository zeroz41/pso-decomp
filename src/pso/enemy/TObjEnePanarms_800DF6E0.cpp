#include "types.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/TObjEnePanarms.h"

struct O_800DFB44 { u8 pad[0x378]; s32 state; };

extern "C" {
s32 TObjEnePanarms__sub_800DFB44(O_800DFB44 *self);
s32 __ct__11TObjControlFP7TObject(s32, s32);
s32 TObjEnePanarms__ct(s32, s32, s32);
s32 __nw__7TObjectFUl(s32);
int fn_800660B8(void*);

extern s32 tl_04;

s32 TObjEnePanarms::create(s32 arg0) {
    s32 var_r31;
    s32 var_r4;

    var_r31 = __nw__7TObjectFUl(0x47C);
    if (var_r31 != 0) {
        var_r4 = __nw__7TObjectFUl(0x20);
        if (var_r4 != 0) {
            var_r4 = __ct__11TObjControlFP7TObject(var_r4, tl_04);
        }
        var_r31 = TObjEnePanarms__ct(var_r31, var_r4, arg0);
    }
    return var_r31;
}

void TObjEnePanarms::init(s16 action) { fn_800660B8(this); change_action(action); sub_8002AE64(); }

s32 TObjEnePanarms__sub_800DFB44(O_800DFB44 *self) {
    return self->state == 7 || self->state == 8;
}

int TObjEnePanarms::get_state_flag() { return (this->actorFlags >> 4) & 0x1; }

}
