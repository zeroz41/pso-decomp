#ifndef PSO_SYSTEM_SCENE_TENDINGC_H
#define PSO_SYSTEM_SCENE_TENDINGC_H
#include "pso/system/task/TObject.h"
#include "types.h"

class TEndingC : public TObject {
public:
    virtual void render();
    virtual void run_task();
    virtual ~TEndingC();

    u32 phase;
    s32 elapsed_ticks;
    s32 cycle_index;
    f32 primary_opacity;
    f32 secondary_opacity;
    u8 render_geometry[0x60];
    s32 timing_rate;
    f32 fade_in_ticks;
    f32 fade_out_ticks;
};
#include <stddef.h>
typedef char TEndingCSize[sizeof(TEndingC) == 0x9C ? 1 : -1];
typedef char TEndingC_phase_offset[offsetof(TEndingC, phase) == 0x1C ? 1 : -1];
typedef char TEndingC_elapsed_ticks_offset[offsetof(TEndingC, elapsed_ticks) == 0x20 ? 1 : -1];
typedef char TEndingC_cycle_index_offset[offsetof(TEndingC, cycle_index) == 0x24 ? 1 : -1];
typedef char TEndingC_primary_opacity_offset[offsetof(TEndingC, primary_opacity) == 0x28 ? 1 : -1];
typedef char TEndingC_secondary_opacity_offset[offsetof(TEndingC, secondary_opacity) == 0x2C ? 1 : -1];
typedef char TEndingC_render_geometry_offset[offsetof(TEndingC, render_geometry) == 0x30 ? 1 : -1];
typedef char TEndingC_timing_rate_offset[offsetof(TEndingC, timing_rate) == 0x90 ? 1 : -1];
typedef char TEndingC_fade_in_ticks_offset[offsetof(TEndingC, fade_in_ticks) == 0x94 ? 1 : -1];
typedef char TEndingC_fade_out_ticks_offset[offsetof(TEndingC, fade_out_ticks) == 0x98 ? 1 : -1];

extern "C" {
int TEndingC__sub_8008C6F4(void);
}

// --- C functions defined in TEndingC.cpp ---
extern "C" {
int TEndingC__sub_8008C6F4(void);
}
// --- end of C functions

#endif
