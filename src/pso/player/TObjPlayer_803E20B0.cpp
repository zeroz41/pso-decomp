#include "types.h"
#include "pso/player/TObjPlayer_803E20B0.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/RenderSbssGlobals.h"
#include <dolphin/mtx.h>

extern "C" {
// <dolphin/gx/GXTransform.h> pulls libc/math.h, whose sqrt statics this TU lacks.
void GXLoadPosMtxImm(f32 mtx[3][4], u32 id);
void GXSetCurrentMtx(u32 id);

typedef struct Cam_803E20B0 { u8 pad0[0x4C]; f32 f4C; u8 pad50[4]; f32 f54; } Cam_803E20B0;
typedef struct Vp_803E20B0 { u8 pad0[4]; u16 w; u16 h; } Vp_803E20B0;

extern Cam_803E20B0 scene_projection_state;
extern Vp_803E20B0 *active_gx_render_mode;
void TObjPlayer::load_screen_space_matrix() {
    Mtx34 m;
    f32 z;
    f32 s;

    PSMTXIdentity(m);
    z = scene_projection_state.f54;
    s = scene_projection_state.f4C / ((f32)active_gx_render_mode->w / (f32)active_gx_render_mode->h);
    m[0][0] = -z * s;
    m[0][2] = s * ((0.5f * (f32)active_gx_render_mode->w) * z);
    m[1][1] = z;
    m[1][2] = (0.5f * (f32)(-active_gx_render_mode->h)) * z;
    GXLoadPosMtxImm(m, 0);
    GXSetCurrentMtx(0);
}
}

#pragma push
#pragma scheduling off
void load_camera_view_matrix(void) {
    GXLoadPosMtxImm(*current_matrix, 0);
}
#pragma pop
