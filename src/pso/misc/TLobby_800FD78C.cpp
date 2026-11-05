#include "types.h"
#include "pso/misc/TLobby_800FD78C.h"
#include "pso/misc/TLobby.h"

extern "C" {

int TCameraCtrl__sub_8006B370(f32 farg0);

void Obj_80515BA0::init_range(s32 floor) {
    current_floor = floor;
    f8 = floor + 1;
    next_floor = floor + 1;
    current_map = 0;
    f14 = 0;
    next_map = 0;
    previous_floor = -1;
    f1C = 0;
    state_flags = 0;
}

u8 fn_800FD7C0(void *arg0) {
    int var_r31;

    var_r31 = 0;
    if ((TCameraCtrl__sub_8006B370(*(f32 *)((s8 *)arg0 + 0)) != 0) || (TCameraCtrl__sub_8006B370(*(f32 *)((s8 *)arg0 + 4)) != 0)) {
        var_r31 = 1;
    }
    return (u8)var_r31;
}

}
