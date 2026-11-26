#include "types.h"
#include "pso/player/LocalClientId.h"
#include "pso/network/client_id.h"
#include "pso/effect/enemy/TObjEneHoldEffect.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/unk/text_800FD8A0.h"
#include "pso/camera/TCameraCtrl.h"

s32 local_client_id;
s32 actor_frame_tick;
// Never stored: the control role create_player_object hands each local player (base + split-screen slot)
// to setup_control_role; name inferred from that use.
s32 player_control_role_base;
s32 designated_client_id;
s32 lbl_805D53B0;

void FloorTransition::init_range(s32 floor) {
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
u8 is_xz_nonfinite(f32 *xz) {
    int result;

    result = 0;
    if ((is_float_nonfinite(xz[0]) != 0) || (is_float_nonfinite(xz[1]) != 0)) {
        result = 1;
    }
    return (u8)result;
}

s32 has_nonfinite_position(f32 *xz) {
    int result;

    result = 0;
    if ((is_float_nonfinite(xz[0]) != 0) || (is_float_nonfinite(xz[1]) != 0)) {
        result = 1;
    }
    return (u8) result;
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

bool fn_800FD8A0(s32 target) {
    return lbl_805D53B0 == target;
}
