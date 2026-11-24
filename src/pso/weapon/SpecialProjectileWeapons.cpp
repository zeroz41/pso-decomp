#include "pso/item/TItemMenuCtrl_80115AF0.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/TEffStarLight2D.h"
#include "pso/weapon/SpecialProjectileWeapons_80124760.h"
#include "pso/technique/TTecMegid.h"
#include "pso/weapon/TUnk_804A204C.h"
#include "pso/item/TItemFollowStarLight.h"
#include "pso/item/TUnk_804A0668.h"
#include "pso/weapon/shoot/TUnk_804A2148.h"
#include "pso/weapon/TUnk_804A2164.h"
#include "types.h"
#include "pso/system/data/FlagWord.h"
#include "pso/weapon/shoot/TItemShoot.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"


#include "pso/weapon/TItemWeapon.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/MatrixOps.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/render/GinjaMaterial.h"

struct TItemEquipBase;
#include "pso/weapon/shoot/TItemShootParticle.h"

#include "pso/weapon/TItemAttacker.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/item/mag/TItemMag.h"
#include "pso/camera/TObjCamera.h"
#include "pso/player/TObjPlayer_80363BE0.h"
#include "pso/weapon/SpecialProjectileWeapons.h"

struct RecoilWeaponView : TItemWeapon {
    s32 projectileVisible;
    s32 projectileSpin;
    s32 recoilAngle;
    s32 recoilPhase;
};



LAYOUT_ASSERT(RecoilVisibleOffset, offsetof(RecoilWeaponView, projectileVisible) == 0x1F8);
LAYOUT_ASSERT(RecoilSpinOffset, offsetof(RecoilWeaponView, projectileSpin) == 0x1FC);
LAYOUT_ASSERT(RecoilAngleOffset, offsetof(RecoilWeaponView, recoilAngle) == 0x200);
LAYOUT_ASSERT(RecoilPhaseOffset, offsetof(RecoilWeaponView, recoilPhase) == 0x204);
LAYOUT_ASSERT(RecoilWeaponExtent, sizeof(RecoilWeaponView) == 0x208);

extern "C" {

s32 post_translate_matrix(void *);
s32 draw_weapon_at_joint(void *, s32, void *);
extern s32 model_render_flags;
s32 is_item_area_enabled();
}


void TUnk_804A204C::emit_marker_effects() {
    s32 joint_position;
    void *owner;
    if (is_mode_two_and_ready() != 0) {
        if (get_joint_position(5, &joint_position) != 0) {
            owner = this->owner;
            TTecMegid::create_ex((saddr)owner, (saddr)(&joint_position), (s32)(*(s32 *)((s8 *)owner + 0x60)), (s32)(((TItemWeapon *)this)->get_tp()));
            this->roll_technique();
        }
    } else {
        ((TItemWeapon *)this)->update_active_game_effect();
    }
}

void TUnk_804A204C::update_weapon() {
    s32 floor;
    if (swing_direction == 1) {
        swing_angle += 0xAAA;
        if (swing_angle >= 0x2000) {
            swing_angle = 0x2000;
            swing_direction = 0;
        }
    } else {
        swing_angle -= 0xAAA;
        if (swing_angle <= -0x2000) {
            swing_angle = -0x2000;
            swing_direction = 1;
        }
    }
    floor = get_current_floor();
    if (floor_area != floor && item_model != NULL) {
        floor_area = floor;
        if (is_item_area_enabled() != 0) {
            spawn_item_follow_star_light(tl_05, get_item_id(), 5);
        }
    }
}

void TUnk_804A204C::vfunc_60() {
    switch (((u32)TObjPlayer::get_player_list())) {
    case 1:
        rotate_matrix_y(0, swing_angle);
        return;
    case 2:
        TItem::begin_effect_render();
        return;
    case 3:
        rotate_matrix_y(0, -swing_angle);
        return;
    case 4:
        TItem::begin_effect_render();
        return;
    case 6:
        TItem::begin_effect_render();
        break;
    case 0:
    case 5:
        break;
    }
}

void TUnk_804A204C::reserved_53() {
    s32 joint_position;
    NJS_OBJECT *model_link;
    NJS_OBJECT *effect_model;
    if (item_model != NULL && is_hidden() == 0) {
        model_link = item_model->child->sibling;
        effect_model = model_link->sibling;
        effect_model->evalflags |= 0x18;
        draw_weapon_at_joint(this, 0x30, model_link);
        effect_model->evalflags &= ~0x18;
        if (get_joint_position(5, &joint_position) != 0) {
            push_matrix();
            TObjPlayer::save_model_render_state();
            model_render_flags &= 0xFFFFFFEF;
            TObjPlayer::set_model_fade_alpha((f32)this->get_owner_alpha());
            post_translate_matrix(&joint_position);
            rotate_matrix_y(0, (int)(*(s32 *)((s8 *)this->owner + 0x60)));
            effect_model->evalflags |= 0x11;
            draw_ginja_object(effect_model);
            TParticleCtrl::begin_effect_render();
            draw_ginja_object(effect_model->child);
            TParticleCtrl::end_effect_render();
            effect_model->evalflags &= ~0x11;
            TObjPlayer::warn_if_gauge_low();
            pop_matrix();
            pop_matrix();
        }
    }
}

void TUnk_804A204C::on_equipped() {
    floor_area = -1;
    if (effect_objects != NULL) {
        new TUnk_804A0668(effect_objects, get_owner_client(), 0x5A);
    }
    roll_technique();
    roll_technique();
}

TUnk_804A204C::~TUnk_804A204C() {

}

TUnk_804A204C::TUnk_804A204C(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    effect_flags.set(32);
    set_weapon_flags(35);
    set_technique_roll_range(12);
    pad_1f8 = 0;
    swing_angle = 0;
    floor_area = -1;
}

TItem *TUnk_804A204C::create(u8 *item) {
    if (item != NULL) {
        return new TUnk_804A204C(tl_05, item);
    }
    return NULL;
}
