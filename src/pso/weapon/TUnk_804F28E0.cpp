#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/boss/derolle/TBoss2DeRolLe.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/unk/text_80087278.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/weapon/TUnk_804F28E0.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/item/TItemEffectWeapon_803632B4.h"
#include "pso/effect/item/TItemEffOrgaFlowShot.h"
#include "pso/effect/item/TItemEffectWeapon.h"
#include "pso/system/task/TMainTask.h"

extern "C" {
void get_weapon_color__11TItemWeaponFPv(void *, void *);
}

void TUnk_804F28E0::vfunc_60() {
    if (TObjPlayer::get_player_list() == 1) {
        translate_matrix(0, 0.0f, pad_1fc, 0.0f);
    }
}

void TUnk_804F28E0::init_weapon_effect_descriptor(Desc_8011E5C4 *desc) {
    u8 sp8[16];
    desc->flags |= 0x39C;
    get_weapon_color__11TItemWeaponFPv(sp8, this);
    copy_argb((NJS_ARGB *)desc->color, (NJS_ARGB *)sp8);
    desc->model = second_model;
    desc->pad_10 = 4;
    desc->pad_4c = 2.0f;
    desc->pad_70 = (void *)TObjPlayer::forward_item_effect_callback;
}

void TUnk_804F28E0::emit_marker_effects() {
    s32 arg0 = (s32)this;
    s32 sp8;

    ((TItemWeapon *)arg0)->get_gun_point(&sp8);
    spawn_particle_effect(&sp8, 9);
    ((TItemWeapon *)arg0)->spawn_light_task();
    ((TItemWeapon *)arg0)->fire_shot_at_target(&sp8, 0, 0);
}

void TUnk_804F28E0::update_idle() {
    s32 arg0 = (s32)this;
    TItemEffOrgaFlowShot::approach_value((f32 *)(arg0 + 0x1FC), (f32)0.5f, (f32)4.0f);
}

void TUnk_804F28E0::update_attack() {
    s32 arg0 = (s32)this;
    TItemEffOrgaFlowShot::approach_value((f32 *)(arg0 + 0x1FC), (f32)(-1.0f), (f32)0.0f);
}

extern "C" {
TUnk_804F28E0::TUnk_804F28E0(TObject *parent, u8 *item) : TUnk_804A4948(parent, item) {
    set_weapon_flags(2);
    pad_1fc = 0.0f;
}
u8 *TItemEffectWeapon::create_instance() {
    u8 *arg0 = (u8 *)this;
    if (arg0 != NULL) {
        return (u8 *)new TUnk_804F28E0(tl_05, arg0);
    }
    return NULL;
}

}

TUnk_804F28E0::~TUnk_804F28E0() {}
