#include "types.h"
#include "pso/unk/TLobby_800FD78C.h"
#include "pso/network/client_id.h"
#include "pso/effect/enemy/TObjEneHoldEffect.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/unk/text_800FD8A0.h"
#include "pso/camera/TCameraCtrl.h"

// One TU 0x800FD78C-0x800FD8B4: its .sbss 0x805D53A0-0x805D53B4 is one run (no pad inside) whose only user
// here is fn_800FD8A0; the zero word at 0x805D53B4 before the 8-aligned 0x805D53B8 closes it (the next TU,
// TObjRoomId_800FD8C8, owns 0x805D53B8-0x805D53C0). The fragments around it have no data of their own.
s32 local_client_id;
s32 actor_frame_tick;
// Never stored: the control role create_player_object hands each local player (base + split-screen slot)
// to setup_control_role; name inferred from that use.
s32 player_control_role_base;
s32 designated_client_id;
s32 lbl_805D53B0;

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

// The validators pass the two packed floats of a position subcommand (x, z).
u8 fn_800FD7C0(f32 *xz) {
    int var_r31;

    var_r31 = 0;
    if ((is_float_nonfinite(xz[0]) != 0) || (is_float_nonfinite(xz[1]) != 0)) {
        var_r31 = 1;
    }
    return (u8)var_r31;
}

s32 has_nonfinite_position(f32 *xz) {
    int var_r31;

    var_r31 = 0;
    if ((is_float_nonfinite(xz[0]) != 0) || (is_float_nonfinite(xz[1]) != 0)) {
        var_r31 = 1;
    }
    return (u8) var_r31;
}


void TWindowCtrl::clear_flag_2() {
    if (instance != NULL) {
        instance->flags &= ~2;
    }
}

void TWindowCtrl::set_close_flag() {
    if (instance != NULL) {
        instance->flags |= 2;
    }
}

bool fn_800FD8A0(s32 arg0) {
    return lbl_805D53B0 == arg0;
}
