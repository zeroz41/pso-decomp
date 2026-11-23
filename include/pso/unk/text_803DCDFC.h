#ifndef PSO_UNK_TEXT_803DCDFC_H
#define PSO_UNK_TEXT_803DCDFC_H

#include "types.h"
#include <dolphin/mtx/GeoTypes.h>

extern "C" {
void fn_803DCEC8(void);
void fn_803DCF0C(void);
void fn_803DD294(void);
void func_803DCDFC__Fv(void);
}
void func_803DCDFC(void);
void init_gx_display(void);
void init_locked_cache_heap(u8 *arg0);
void init_sin_cos_table(void);
// Fills the screen projection defaults, the sin/cos table and the render context.
void init_projection_state(void);
void present_frame_and_wait_vsync(void);
void set_present_interval(s32 *arg0, s32 arg1);

extern Mtx34 identity_matrix;

#endif
