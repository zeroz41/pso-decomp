#include "types.h"
#include "pso/system/FlagWord.h"
#include "pso/item/TItemMenuCtrl_80115AF0.h"
#include "pso/TItemMenuCtrl.h"
#include "pso/item/TItemEffOrgaFlowShot.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/TObjBoss2Tunnel.h"
#include "pso/item/TItemEffectWeapon.h"

extern "C" {
s32 is_split_screen(void);
u8 * __ct__15TEffStarLight2DFPvPvP7TObject(void *, s32, s32, s32);
u8 *__nw__7TObjectFUl(s32);
int set__8FlagWordFUl(void*);

int TItemMenuCtrl::set_menu_flags() { return set__8FlagWordFUl((char*)this + 0x1c); }
}

extern const f32 lbl_805DABE8;

#pragma push
#pragma scheduling off
u8 *spawn_star_light_2d(s32 arg0, s32 arg1, s32 arg2) {
    u8 *eff_star_light2_d;
    u8 *var_r0;
    if (is_split_screen() == 0) {
        eff_star_light2_d = (u8 *)(__nw__7TObjectFUl(0x4C));
        var_r0 = eff_star_light2_d;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(__ct__15TEffStarLight2DFPvPvP7TObject(eff_star_light2_d, arg0, arg1, arg2));
        }
        return var_r0;
    }
    return NULL;
}
#pragma pop

void TItemEffOrgaFlowShot::approach_value(f32 *arg0, f32 farg0, f32 farg1) {
    *arg0 += farg0;
    if (farg0 > lbl_805DABE8) {
        if (*arg0 > farg1) {
            *arg0 = farg1;
        }
    } else if (*arg0 < farg1) {
        *arg0 = farg1;
    }
}

void TObjPlayer::add_angle_clamped(s32 *arg0, s32 arg1, s32 arg2) {
    *arg0 += arg1;
    if (arg1 > 0) {
        if ((s32) *arg0 > arg2) {
            *arg0 = arg2;
        }
    } else if ((s32) *arg0 < arg2) {
        *arg0 = arg2;
    }
}

void advance_angle_wrap(s32 *arg0, s32 arg1) {
    s32 temp_r4;
    *arg0 += arg1;
    temp_r4 = *arg0;
    if (temp_r4 >= 0x10000) {
        *arg0 = temp_r4 + 0xFFFF0000;
    }
}
