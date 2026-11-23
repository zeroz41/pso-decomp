#ifndef PSO_SYSTEM_SCENE_TENDINGC_H
#define PSO_SYSTEM_SCENE_TENDINGC_H
#include "pso/system/task/TObject.h"
#include "types.h"

class TEndingC : public TObject {
public:
    TEndingC(TObject *parent);
    virtual void render();
    virtual void run_task();
    virtual ~TEndingC();
    static void release_lobby();

    u32 phase;
    s32 elapsed_ticks;
    s32 cycle_index;
    f32 primary_opacity;
    f32 secondary_opacity;
    f32 render_geometry[3][8];
    s32 timing_rate;
    f32 fade_in_ticks;
    f32 fade_out_ticks;
};
#include <stddef.h>
LAYOUT_ASSERT(TEndingCSize, sizeof(TEndingC) == 0x9C);
LAYOUT_ASSERT(TEndingC_phase_offset, offsetof(TEndingC, phase) == 0x1C);
LAYOUT_ASSERT(TEndingC_elapsed_ticks_offset, offsetof(TEndingC, elapsed_ticks) == 0x20);
LAYOUT_ASSERT(TEndingC_cycle_index_offset, offsetof(TEndingC, cycle_index) == 0x24);
LAYOUT_ASSERT(TEndingC_primary_opacity_offset, offsetof(TEndingC, primary_opacity) == 0x28);
LAYOUT_ASSERT(TEndingC_secondary_opacity_offset, offsetof(TEndingC, secondary_opacity) == 0x2C);
LAYOUT_ASSERT(TEndingC_render_geometry_offset, offsetof(TEndingC, render_geometry) == 0x30);
LAYOUT_ASSERT(TEndingC_timing_rate_offset, offsetof(TEndingC, timing_rate) == 0x90);
LAYOUT_ASSERT(TEndingC_fade_in_ticks_offset, offsetof(TEndingC, fade_in_ticks) == 0x94);
LAYOUT_ASSERT(TEndingC_fade_out_ticks_offset, offsetof(TEndingC, fade_out_ticks) == 0x98);

// Seconds into the ending at which TEndingC starts fading its wall in.
int get_ending_c_start_seconds(void);

#endif
