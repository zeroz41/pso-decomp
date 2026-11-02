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

struct Cam_803D66DC { f32 f0, f4, f8, fC, f10, f14, f18, f1C, f20, f24; };

extern "C" {
extern RecoveredGlobal_803D662C_lbl_8058D4D0 camera_clip_parameters;
extern G_803D6688 lbl_8058D4F8;
}

#pragma push
#pragma use_lmw_stmw off

#pragma push
#pragma opt_common_subs off

void TCameraCtrl::update_projection_params() {
    Cam_803D66DC *arg0 = (Cam_803D66DC *)this;
    f32 c, b, a;
    (*(Cam_803D66DC *)&lbl_8058D4F8).f18 = a = arg0->f18;
    (*(Cam_803D66DC *)&lbl_8058D4F8).f8 = b = arg0->f8;
    (*(Cam_803D66DC *)&lbl_8058D4F8).fC = c = arg0->fC;
    (*(Cam_803D66DC *)&lbl_8058D4F8).f0 = (*(Cam_803D66DC *)&lbl_8058D4F8).f1C * a;
    (*(Cam_803D66DC *)&lbl_8058D4F8).f4 = -((*(Cam_803D66DC *)&lbl_8058D4F8).f20 * a);
    (*(Cam_803D66DC *)&lbl_8058D4F8).f10 = 1.0f / (*(Cam_803D66DC *)&lbl_8058D4F8).f0;
    (*(Cam_803D66DC *)&lbl_8058D4F8).f14 = 1.0f / (*(Cam_803D66DC *)&lbl_8058D4F8).f4;
    (*(Cam_803D66DC *)&camera_clip_parameters).f8 = (*(Cam_803D66DC *)&camera_clip_parameters).f20 - b;
    (*(Cam_803D66DC *)&camera_clip_parameters).fC = (*(Cam_803D66DC *)&camera_clip_parameters).f18 - b;
    (*(Cam_803D66DC *)&camera_clip_parameters).f10 = (*(Cam_803D66DC *)&camera_clip_parameters).f24 - c;
    (*(Cam_803D66DC *)&camera_clip_parameters).f14 = (*(Cam_803D66DC *)&camera_clip_parameters).f1C - c;
}
#pragma pop
#pragma pop
