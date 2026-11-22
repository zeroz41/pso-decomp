#include "pso/animation/MotionContext.h"
#include "pso/camera/TCameraCtrl_803D676C.h"
#include "types.h"
#include "pso/system/NinjaTypes.h"
#include "pso/camera/TCameraCtrl_803D6538.h"

#include <stddef.h>
#include "pso/camera/TCameraCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/math/AngleLookup.h"
#include <math.h>

struct G_803D6688 { f32 f0, f4, pad8[2], f10, f14, f18, f1c, f20, f24; };

struct Proj_803D676C { f32 m[4][4]; s32 f40; f32 f44, f48, f4C, f50, f54; };

struct Disp_803D676C { u8 pad[6]; u16 h; };

extern "C" {
s32 C_MTXPerspective(void *, f32, f32, f32, f32);
s32 GXSetProjection(void *, int);
Proj_803D676C scene_projection_state;
extern f32 camera_clip_parameters[];
extern G_803D6688 lbl_8058D4F8;
extern Disp_803D676C *active_gx_render_mode;
}

#pragma push
#pragma use_lmw_stmw off

void set_perspective_projection_from_fov(s32 arg0, f32 farg0, f32 farg1, f32 farg2) {
    s32 h;
    f32 c;
    f32 r;
    f32 x;
    f32 sc;
    f32 b;
    f32 a;
    f32 one;
    h = (s32)((f32)arg0 * fov_angle_scale) / 2;
    c = cos_table_lookup(h);
    r = atan((sin_table_lookup(h) / c) / farg0);
    C_MTXPerspective(&scene_projection_state, angle_to_degrees * ((s32)(radians_to_angle * r) * 2), farg0, farg1, farg2);
    GXSetProjection(&scene_projection_state, 0);
    scene_projection_state.f40 = 0;
    scene_projection_state.f44 = farg1;
    scene_projection_state.f48 = farg2;
    scene_projection_state.f4C = farg0;
    sc = screen_half_scale * ((f32)active_gx_render_mode->h * scene_projection_state.m[1][1]);
    scene_projection_state.f50 = sc;
    one = projection_unit;
    scene_projection_state.f54 = one / sc;
    lbl_8058D4F8.f18 = sc;
    x = farg0 / screen_aspect_ratio;
    lbl_8058D4F8.f1c = x;
    lbl_8058D4F8.f20 = one;
    lbl_8058D4F8.f24 = one / farg0;
    a = x * (f32)(f64)lbl_8058D4F8.f18;
    lbl_8058D4F8.f0 = a;
    b = -(one * (f32)(f64)lbl_8058D4F8.f18);
    lbl_8058D4F8.f4 = b;
    lbl_8058D4F8.f10 = one / a;
    lbl_8058D4F8.f14 = one / (f32)(f64)b;
    *(f32 *)((s8 *)&camera_clip_parameters + 0) = farg2;
    *(f32 *)((s8 *)&camera_clip_parameters + 4) = farg1;
}
#pragma pop

// .sdata2 0x805E0E18-0x805E0E3C: named constants defined after their user (declared in the header), so they
// stay memory loads and precede the int->double conversion constants of the deferred-compiled function.
// As literals, 0.85f is loaded before the conversion and 1.0f takes another register.
// Names inferred from the use: angle scale, 360/65536, 65536/(2*pi), half screen height, 1, 4:3.
__declspec(section ".sdata2") const f32 fov_angle_scale = 0.85f;
__declspec(section ".sdata2") const f64 angle_to_degrees = 0.0054931640625;
__declspec(section ".sdata2") const f64 radians_to_angle = 10430.38043493439;
__declspec(section ".sdata2") const f32 screen_half_scale = 0.5f;
__declspec(section ".sdata2") const f32 projection_unit = 1.0f;
__declspec(section ".sdata2") const f32 screen_aspect_ratio = 1.3333334f;
