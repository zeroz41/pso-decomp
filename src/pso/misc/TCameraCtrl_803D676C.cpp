#include "pso/animation/MotionContext.h"
#include "types.h"
#include "pso/system/NinjaTypes.h"
#include "pso/misc/TCameraCtrl_803D6538.h"

#include <stddef.h>
#include "pso/misc/TCameraCtrl.h"
#include "pso/player/TObjPlayer.h"
struct RecoveredGlobal_803D662C_lbl_8058D4D0 {
    s32 value;
    u8 remaining[0x24];
};

struct G_803D6688 { f32 f0, f4, pad8[2], f10, f14, f18, f1c, f20, f24; };

struct Proj_803D676C { f32 m[4][4]; s32 f40; f32 f44, f48, f4C, f50, f54; };

struct Disp_803D676C { u8 pad[6]; u16 h; };

extern "C" {
s32 C_MTXPerspective(void *, f32, f32, f32, f32);
s32 GXSetProjection(void *, int);
f64 atan(f32);
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
Proj_803D676C scene_projection_state;
extern RecoveredGlobal_803D662C_lbl_8058D4D0 camera_clip_parameters;
extern G_803D6688 lbl_8058D4F8;
extern Disp_803D676C *active_gx_render_mode;
}

#pragma push
#pragma use_lmw_stmw off

// The pool before the int->double constants (0x805E0E18-0x805E0E3C) is still read
// through its labels: as literals, 0.85f is loaded before the conversion and 1.0f
// changes the register allocation.
extern const f32 lbl_805E0E18;
extern const f64 lbl_805E0E20;
extern const f64 lbl_805E0E28;
extern const f32 lbl_805E0E30;
extern const f32 lbl_805E0E34;
extern const f32 lbl_805E0E38;

void set_perspective_projection_from_fov(s32 arg0, f32 farg0, f32 farg1, f32 farg2) {
    s32 h;
    f32 c;
    f32 r;
    f32 x;
    f32 sc;
    f32 b;
    f32 a;
    f32 one;
    h = (s32)((f32)arg0 * lbl_805E0E18) / 2;
    c = cos_table_lookup(h);
    r = atan((sin_table_lookup(h) / c) / farg0);
    C_MTXPerspective(&scene_projection_state, lbl_805E0E20 * ((s32)(lbl_805E0E28 * r) * 2), farg0, farg1, farg2);
    GXSetProjection(&scene_projection_state, 0);
    scene_projection_state.f40 = 0;
    scene_projection_state.f44 = farg1;
    scene_projection_state.f48 = farg2;
    scene_projection_state.f4C = farg0;
    sc = lbl_805E0E30 * ((f32)active_gx_render_mode->h * scene_projection_state.m[1][1]);
    scene_projection_state.f50 = sc;
    one = lbl_805E0E34;
    scene_projection_state.f54 = one / sc;
    lbl_8058D4F8.f18 = sc;
    x = farg0 / lbl_805E0E38;
    lbl_8058D4F8.f1c = x;
    lbl_8058D4F8.f20 = one;
    lbl_8058D4F8.f24 = one / farg0;
    a = x * (f32)(f64)lbl_8058D4F8.f18;
    lbl_8058D4F8.f0 = a;
    b = -(one * (f32)(f64)lbl_8058D4F8.f18);
    lbl_8058D4F8.f4 = b;
    lbl_8058D4F8.f10 = one / a;
    lbl_8058D4F8.f14 = one / (f32)(f64)b;
    *(f32 *)((s8 *)&camera_clip_parameters.value + 0) = farg2;
    *(f32 *)((s8 *)&camera_clip_parameters.value + 4) = farg1;
}
#pragma pop
