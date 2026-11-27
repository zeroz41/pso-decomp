#include "pso/player/TEquippedWeaponDrawTask.h"
#include "pso/item/TItemMenuCtrl.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/TEffStarLight2D.h"
#include "pso/weapon/TItemWeaponDrillLauncher.h"
#include "pso/technique/TTecMegid.h"
#include "pso/weapon/TItemWeaponEvilCurst.h"
#include "pso/item/TItemFollowStarLight.h"
#include "pso/item/TItemTimerEventTpDrain.h"
#include "pso/weapon/shoot/TItemShootDrillLauncher.h"
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
#include "pso/math/MatrixReflect.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/render/GinjaMaterial.h"

struct TItemEquipBase;
#include "pso/weapon/shoot/TItemShootParticle.h"

#include "pso/weapon/TItemAttacker.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/item/mag/TItemMag.h"
#include "pso/camera/TObjCamera.h"
#include "pso/weapon/SpecialProjectileWeapons.h"
#include "pso/system/MatrixStack.h"
#include "pso/render/model_render_state.h"
#include "pso/system/scene/TScene.h"


void TItemWeaponEvilCurst::emit_marker_effects() {
    Vec joint_position;
    TObjPlayer *owner;
    if (is_mode_two_and_ready() != 0) {
        if (get_joint_position(5, &joint_position) != 0) {
            owner = this->owner;
            TTecMegid::create_ex(owner, &joint_position, owner->rotation.y, ((TItemWeapon *)this)->get_tp());
            this->roll_technique();
        }
    } else {
        ((TItemWeapon *)this)->update_active_game_effect();
    }
}

void TItemWeaponEvilCurst::update_weapon() {
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
        if (is_item_area_enabled(floor) != 0) {
            spawn_item_follow_star_light(tl_05, get_item_id(), 5);
        }
    }
}

void TItemWeaponEvilCurst::transform_model_node() {
    switch (((u32)get_model_node_counter())) {
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

void TItemWeaponEvilCurst::draw_held_model() {
    Vec joint_position;
    NJS_OBJECT *model_link;
    NJS_OBJECT *effect_model;
    if (item_model != NULL && is_hidden() == 0) {
        model_link = item_model->child->sibling;
        effect_model = model_link->sibling;
        effect_model->evalflags |= 0x18;
        draw_weapon_at_joint(0x30);
        effect_model->evalflags &= ~0x18;
        if (get_joint_position(5, &joint_position) != 0) {
            push_matrix();
            TEquippedWeaponDrawTask::save_model_render_state();
            model_render_flags &= 0xFFFFFFEF;
            TEquippedWeaponDrawTask::set_fade_alpha((f32)this->get_owner_alpha());
            post_translate_matrix(&joint_position.x);
            rotate_matrix_y(0, this->owner->rotation.y);
            effect_model->evalflags |= 0x11;
            draw_ginja_object(effect_model);
            ::begin_effect_render();
            draw_ginja_object(effect_model->child);
            ::end_effect_render();
            effect_model->evalflags &= ~0x11;
            TEquippedWeaponDrawTask::end_fade();
            pop_matrix();
            pop_matrix();
        }
    }
}

void TItemWeaponEvilCurst::on_equipped() {
    floor_area = -1;
    if (effect_objects != NULL) {
        new TItemTimerEventTpDrain(effect_objects, get_owner_client(), 0x5A);
    }
    roll_technique();
    roll_technique();
}

TItemWeaponEvilCurst::~TItemWeaponEvilCurst() {

}

TItemWeaponEvilCurst::TItemWeaponEvilCurst(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    effect_flags.set(32);
    set_weapon_flags(35);
    set_technique_roll_range(12);
    pad_1f8 = 0;
    swing_angle = 0;
    floor_area = -1;
}

TItem *TItemWeaponEvilCurst::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponEvilCurst(tl_05, item);
    }
    return NULL;
}
