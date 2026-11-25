#include "pso/item/TItemMenuCtrl_80115A28.h"
#include "pso/item/TItemMenuCtrl.h"
#include "types.h"
#include "pso/system/data/FlagWord.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/effect/item/TItemEffOrgaFlowShot.h"
#include "pso/math/ClampedStep.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/effect/item/TItemEffectWeapon.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/effect/TEffStarLight2D.h"

#pragma readonly_strings on

TItemMenuCtrl *TItemMenuCtrl__instance;

TItemMenuCtrl::~TItemMenuCtrl() {
    TItemMenuCtrl__instance = 0;
}


const char *lbl_805D2C18 = "TItemMenuCtrl";

TItemMenuCtrl::TItemMenuCtrl(TObject *parent) : TObject(parent) {
    TItemMenuCtrl__instance = this;
    m_name = lbl_805D2C18;
}

#define TOBJECT_OUT_OF_LINE_HELPERS

extern "C" {

void TItemMenuCtrl::open_menu(u32 arg0) {
    if (TItemMenuCtrl__instance == NULL) {
        new TItemMenuCtrl(tl_05);
    }
    if (arg0 < 7U) {
        if (arg0 == 0) {
            TItemMenuCtrl__instance->queue_destruction();
            return;
        }
        TItemMenuCtrl__instance->set_menu_flags(1U << arg0);
    }
}

}

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

void advance_angle_wrap(s32 *angle, s32 blade_speed) {
    s32 wrapped;
    *angle += blade_speed;
    wrapped = *angle;
    if (wrapped >= 0x10000) {
        *angle = wrapped + 0xFFFF0000;
    }
}

s32 decrement_timer(u32 *packed, s32 step) {
    return TObjBoss2Tunnel::decrement_packed_timer(packed, step);
}
