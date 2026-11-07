#include "types.h"
#include "pso/player/TObjPlayer_800666B0.h"
#include "pso/boss/galgryphon/TBoss5GryphonShockWave.h"

struct O_800666C4 { s16 a; s16 b; s32 arr[4]; };

extern "C" {
void init_motion_record(O_800666C4 *self);

    extern unsigned char camera_capture_overlay_alpha;
    extern unsigned char camera_capture_flags;
void set_camera_capture_overlay_alpha(int a0) { camera_capture_overlay_alpha = a0; camera_capture_flags = (camera_capture_flags | 0x2); }
void init_motion_record(O_800666C4 *self) {
    s32 i;
    self->a = 0x21;
    self->b = -1;
    for (i = 0; i < 4; i++) {
        self->arr[i] = 0;
    }
}

}
