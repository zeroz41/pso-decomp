#define PSO_SDK_COMPACT_MATH
#include "types.h"
#include <dolphin/gx/GXFrameBuffer.h>
#undef PSO_SDK_COMPACT_MATH
#include "pso/boss/derolle/TObjBoss2Tunnel_8036EF0C.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"


s32 display_copy_filter_enabled = 1;
extern GXRenderModeObj *active_gx_render_mode;

void set_display_copy_filter(int enabled) {
    display_copy_filter_enabled = enabled;
    GXSetCopyFilter(active_gx_render_mode->aa, active_gx_render_mode->sample_pattern, (GXBool)enabled,
                    active_gx_render_mode->vfilter);
}

s32 get_display_copy_filter(void) {  return display_copy_filter_enabled; }

void reset_display_copy_filter(void) { display_copy_filter_enabled = 1; }

void TObjBoss2Tunnel::enable_and_trigger() { display_copy_filter_enabled = 1; set_display_copy_filter(1); }
