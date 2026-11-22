#include "types.h"
#include "pso/player/TObjPlayer.h"

s16 demo_camera_index;
u8 lbl_805D4ECA;

s32 TObjPlayer::check_demo_mode() {
    s16 v;
    if ((s8) lbl_805D4ECA != 0) {
        v = demo_camera_index;
        if (v == 4) {
            goto ret0;
        }
        if (v != 2) {
            goto ret1;
        }
ret0:
        return 0;
ret1:
        return 1;
    }
    return 0;
}
