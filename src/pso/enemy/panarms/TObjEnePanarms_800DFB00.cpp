#include "types.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"

struct O_800DFB44 { u8 pad[0x378]; s32 state; };

extern "C" {
s32 TObjEnePanarms__sub_800DFB44(O_800DFB44 *self);
int fn_800660B8(void*);

void TObjEnePanarms::init(s16 action) { fn_800660B8(this); change_action(action); sub_8002AE64(); }

s32 TObjEnePanarms__sub_800DFB44(O_800DFB44 *self) {
    return self->state == 7 || self->state == 8;
}

int TObjEnePanarms::get_state_flag() { return (this->actorFlags >> 4) & 0x1; }

}
