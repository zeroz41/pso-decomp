#define PSO_SDK_COMPACT_MATH
#include <dolphin/gx.h>
#undef PSO_SDK_COMPACT_MATH
#include "types.h"
#include "pso/render/GinjaDrawUtil.h"

#pragma push
#pragma scheduling off
void reset_scene_fog() {
    set_scene_fog_color(0xFFFFFFFF);
    set_scene_fog_distances(0.0f, 1000000.0f);
    set_scene_fog_type(GX_FOG_PERSP_LIN);
    enable_scene_fog();
    apply_scene_fog();
}
#pragma pop
