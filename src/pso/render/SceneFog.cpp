#define PSO_SDK_COMPACT_MATH
#include <dolphin/gx.h>
#undef PSO_SDK_COMPACT_MATH
#include "types.h"
#include "pso/render/SceneFog.h"
#include "pso/render/GinjaView.h"
#include "pso/render/RenderSbssGlobals.h"

s32 scene_fog_type;
f32 scene_fog_end_distance;
f32 scene_fog_start_distance;
GXColor scene_fog_color;
s8 scene_fog_enable_flag;

// {0.0f, 1.0f} in .sdata; identity_current_matrix_ps loads the 1.0f.
f32 identity_matrix_ps_constants[2] = {0.0f, 1.0f};

asm void identity_current_matrix_ps(void) {
#include "orig_asm/pso/render/SceneFog/identity_current_matrix_ps.inc"
}

asm void push_identity_matrix_ps(void) {
#include "orig_asm/pso/render/SceneFog/push_identity_matrix_ps.inc"
}

void enable_scene_fog() {
    scene_fog_enable_flag = 1;
}

void disable_scene_fog() {
    scene_fog_enable_flag = 0;
}

#pragma push
#pragma scheduling off
#pragma peephole off
void set_scene_fog_color(u32 color) {
    scene_fog_color.r = (color & 0xFF000000) >> 24;
    scene_fog_color.g = (color & 0x00FF0000) >> 16;
    scene_fog_color.b = (color & 0x0000FF00) >> 8;
}
#pragma pop

void set_scene_fog_distances(f32 start, f32 end) {
    scene_fog_start_distance = start;
    scene_fog_end_distance = end;
}

void set_scene_fog_type(s32 type) {
    scene_fog_type = type;
}

void apply_scene_fog() {
    s32 type;
    if (scene_fog_enable_flag != 0) {
        type = scene_fog_type;
    } else {
        type = GX_FOG_NONE;
    }
    GXSetFog((GXFogType)type, scene_fog_start_distance, scene_fog_end_distance, scene_projection_state.near_z,
             scene_projection_state.far_z, scene_fog_color);
}

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
