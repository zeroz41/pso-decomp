#include "types.h"
#include "pso/player/TObjPlayer_800666B0.h"
#include "pso/boss/galgryphon/TBoss5GryphonShockWave.h"
#include "pso/boss/galgryphon/Boss5GryphonMotionEntry.h"

extern "C" {

    extern unsigned char camera_capture_overlay_alpha;
    extern unsigned char camera_capture_flags;
void set_camera_capture_overlay_alpha(int a0) { camera_capture_overlay_alpha = a0; camera_capture_flags = (camera_capture_flags | 0x2); }

}

void Boss5GryphonMotionEntry::init() {
    s32 i;
    state = 0x21;
    timer = -1;
    for (i = 0; i < 4; i++) {
        args.words[i] = 0;
    }
}
