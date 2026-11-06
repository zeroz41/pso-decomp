#include "types.h"
#include "pso/ui/window/TWindowLockOn.h"

extern "C" {

void *get_window_layout_position();

f32 TWindowLockOn::get_target_distance() {
    return *(f32 *)((s8 *)(get_window_layout_position()) + 4);
}

}
