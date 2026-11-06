#include "pso/animation/MotionContext.h"
#include "types.h"
#include "pso/system/NinjaTypes.h"
#include "pso/camera/TCameraCtrl_803D6538.h"

#include <stddef.h>
#include "pso/camera/TCameraCtrl.h"
#include "pso/player/TObjPlayer.h"
struct RecoveredGlobal_803D662C_lbl_8058D4D0 {
    s32 value;
    u8 remaining[0x24];
};

struct V_803D6558 { f32 x, y, z; };

struct G_803D6688 { f32 f0, f4, pad8[2], f10, f14, f18, f1c, f20, f24; };

extern "C" {
extern RecoveredGlobal_803D662C_lbl_8058D4D0 camera_clip_parameters;
extern G_803D6688 lbl_8058D4F8;
void C_MTXLookAt(void *, void *, void *, void *);
extern u8 *current_matrix;
s32 translate_matrix(s32, f32, f32, f32);
void set_matrix_identity(u8 *arg0);
}
extern u8 camera_look_at_up_vector[];

void TCameraCtrl::update_camera_state(f32 _w0, f32 _w1, f32 _w2) {
    TCameraCtrl::translate_view_negated(_w0, _w1, _w2);
}

void TCameraCtrl::look_at_position(f32 farg0, f32 farg1, f32 farg2) {
    u8 eye[0x14];
    V_803D6558 v;
    TCameraCtrl__sub_803D65F8(eye);
    v.x = farg0;
    v.y = farg1;
    v.z = farg2;
    set_matrix_identity(0);
    set_camera_look_at(eye, (u8*)((u8 *)&v), camera_look_at_up_vector);
}

#pragma push
#pragma scheduling off
s32 TCameraCtrl::translate_view_negated(f32 x, f32 y, f32 z) {
    return translate_matrix(0, -x, -y, -z);
}
#pragma pop

void TCameraCtrl__sub_803D65F8(u8 * _w0) {

}

#pragma push
#pragma scheduling off
void set_camera_look_at(u8* eye, u8* target, u8* up) {
    C_MTXLookAt(current_matrix, eye, up, target);
}
#pragma pop

#pragma push
#pragma opt_common_subs off
#pragma scheduling off
typedef char RecoveredGlobal_803D662C_lbl_8058D4D0_size[sizeof(RecoveredGlobal_803D662C_lbl_8058D4D0) == 0x28 ? 1 : -1];

void TCameraCtrl::set_clamped_offsets(f32 farg0, f32 farg1) {
    f32 var_f1;
    f32 var_f2;
    var_f1 = farg0;
    var_f2 = farg1;
    if (var_f1 > -1.0f) {
        var_f1 = -1.0f;
    }
    if (var_f1 < -65535.0f) {
        var_f1 = -65535.0f;
    }
    if (var_f2 > -1.0f) {
        var_f2 = -1.0f;
    }
    if (var_f2 < -65535.0f) {
        var_f2 = -65535.0f;
    }
    *(f32 *)((s8 *)&camera_clip_parameters.value + 4) = (f32) -var_f1;
    *(f32 *)((s8 *)&camera_clip_parameters.value + 0) = (f32) -var_f2;
}
#pragma pop

void set_screen_size(f32 farg0, f32 farg1) {
    f32 a, b;
    lbl_8058D4F8.f1c = farg0;
    lbl_8058D4F8.f20 = farg1;
    lbl_8058D4F8.f24 = farg1 / farg0;
    a = (f32)(f64)farg0 * lbl_8058D4F8.f18;
    lbl_8058D4F8.f0 = a;
    b = -((f32)(f64)farg1 * lbl_8058D4F8.f18);
    lbl_8058D4F8.f4 = b;
    lbl_8058D4F8.f10 = 1.0f / a;
    lbl_8058D4F8.f14 = 1.0f / (f32)(f64)b;
}
