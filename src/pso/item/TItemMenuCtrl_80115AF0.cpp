#include "pso/effect/item/TItemEffOrgaFlowShot.h"
#include "pso/math/ClampedStep.h"
#include "types.h"
#include "pso/item/TItemMenuCtrl_80115AF0.h"
#include "pso/item/TItemMenuCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/effect/item/TItemEffectWeapon.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/effect/TEffStarLight2D.h"

extern "C" {

void TItemMenuCtrl::set_menu_flags(u32 mask) { menu_flags.set(mask); }
}

TEffStarLight2D *spawn_star_light_2d(const Vec *position, const StarLightParameters *parameters, TObject *parent) {
    if (is_split_screen() == 0) {
        return new TEffStarLight2D(const_cast<Vec *>(position), const_cast<StarLightParameters *>(parameters), parent);
    }
    return NULL;
}

void approach_value(f32 *value, f32 step, f32 target) {
    *value += step;
    if (step > 0.0f) {
        if (*value > target) {
            *value = target;
        }
    } else if (*value < target) {
        *value = target;
    }
}

void add_angle_clamped(s32 *value, s32 step, s32 limit) {
    *value += step;
    if (step > 0) {
        if (*value > limit) {
            *value = limit;
        }
    } else if (*value < limit) {
        *value = limit;
    }
}

void advance_angle_wrap(s32 *arg0, s32 blade_speed) {
    s32 temp_r4;
    *arg0 += blade_speed;
    temp_r4 = *arg0;
    if (temp_r4 >= 0x10000) {
        *arg0 = temp_r4 + 0xFFFF0000;
    }
}

s32 decrement_timer(u32 *packed, s32 step) {
    return TObjBoss2Tunnel::decrement_packed_timer(packed, step);
}
