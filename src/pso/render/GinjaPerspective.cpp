#include "pso/render/GinjaView.h"
#include "types.h"
#include "pso/system/NinjaTypes.h"

#include <stddef.h>
#include <math.h>
#include <dolphin/mtx.h>
#include <dolphin/gx/GXTransform.h>
#include <dolphin/gx/GXStruct.h>
#include "pso/camera/TCameraCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/math/AngleLookup.h"

SceneProjectionState scene_projection_state;
extern GXRenderModeObj *active_gx_render_mode;

#pragma push
#pragma use_lmw_stmw off

void set_perspective_projection_from_fov(s32 fov, f32 aspect, f32 near_z, f32 far_z) {
    s32 half;
    f32 c;
    f32 r;
    f32 width;
    f32 scale;
    f32 scale_y;
    f32 scale_x;
    f32 one;
    half = (s32)((f32)fov * fov_angle_scale) / 2;
    c = cos_table_lookup(half);
    r = atan((sin_table_lookup(half) / c) / aspect);
    C_MTXPerspective(scene_projection_state.matrix, angle_to_degrees * ((s32)(radians_to_angle * r) * 2), aspect, near_z, far_z);
    GXSetProjection(scene_projection_state.matrix, GX_PERSPECTIVE);
    scene_projection_state.type = 0;
    scene_projection_state.near_z = near_z;
    scene_projection_state.far_z = far_z;
    scene_projection_state.aspect = aspect;
    scale = screen_half_scale * ((f32)active_gx_render_mode->efbHeight * scene_projection_state.matrix[1][1]);
    scene_projection_state.screen_scale = scale;
    one = projection_unit;
    scene_projection_state.inv_screen_scale = one / scale;
    screen_projection.distance = scale;
    width = aspect / screen_aspect_ratio;
    screen_projection.width = width;
    screen_projection.height = one;
    screen_projection.aspect = one / aspect;
    scale_x = width * (f32)(f64)screen_projection.distance;
    screen_projection.scale_x = scale_x;
    scale_y = -(one * (f32)(f64)screen_projection.distance);
    screen_projection.scale_y = scale_y;
    screen_projection.inv_scale_x = one / scale_x;
    screen_projection.inv_scale_y = one / (f32)(f64)scale_y;
    camera_clip_parameters[0] = far_z;
    camera_clip_parameters[1] = near_z;
}
#pragma pop

__declspec(section ".sdata2") const f32 fov_angle_scale = 0.85f;
__declspec(section ".sdata2") const f64 angle_to_degrees = 0.0054931640625;
__declspec(section ".sdata2") const f64 radians_to_angle = 10430.38043493439;
__declspec(section ".sdata2") const f32 screen_half_scale = 0.5f;
__declspec(section ".sdata2") const f32 projection_unit = 1.0f;
__declspec(section ".sdata2") const f32 screen_aspect_ratio = 1.3333334f;
