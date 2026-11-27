#include "types.h"
#include "pso/player/TObjPlayer.h"

s16 demo_camera_index;
// Nothing in the retail game sets this, so check_demo_mode always returns 0.
s8 demo_mode_enabled;

s32 check_demo_mode() {
    if (demo_mode_enabled != 0) {
        if (demo_camera_index == 4 || demo_camera_index == 2) {
            return 0;
        }
        return 1;
    }
    return 0;
}
