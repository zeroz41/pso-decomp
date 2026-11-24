#include "types.h"
#include "pso/render/ScreenPrimitiveDraw.h"
#include "pso/render/GinjaView.h"
#include "pso/render/RenderSbssGlobals.h"
#define PSO_SDK_COMPACT_MATH
#include <dolphin/gx.h>
#undef PSO_SDK_COMPACT_MATH
#include <dolphin/mtx.h>

extern GXRenderModeObj *active_gx_render_mode;

// Maps (x, y, 1) / -w of a screen-space vertex onto the view the projection draws with.
void load_screen_space_matrix() {
    Mtx34 m;
    f32 z;
    f32 s;

    PSMTXIdentity(m);
    z = scene_projection_state.inv_screen_scale;
    s = scene_projection_state.aspect / ((f32)active_gx_render_mode->fbWidth / (f32)active_gx_render_mode->efbHeight);
    m[0][0] = -z * s;
    m[0][2] = s * ((0.5f * (f32)active_gx_render_mode->fbWidth) * z);
    m[1][1] = z;
    m[1][2] = (0.5f * (f32)(-active_gx_render_mode->efbHeight)) * z;
    GXLoadPosMtxImm(m, GX_PNMTX0);
    GXSetCurrentMtx(GX_PNMTX0);
}

#pragma push
#pragma scheduling off
void load_camera_view_matrix() {
    GXLoadPosMtxImm(*current_matrix, GX_PNMTX0);
}
#pragma pop
