#include "pso/math/ClampedStep.h"
#include "types.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/player/TObjPlayer.h"
#include "pso/weapon/TItemAttacker.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/system/MatrixStack.h"
#include "pso/weapon/TWeaponCasing.h"
#include "pso/system/vector.h"
#include "pso/item/TItem.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/weapon/TItemWeaponInfernoBazooka.h"
#include "pso/player/PrsTextureLoad.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/math/MatrixReflect.h"
#include "pso/math/AngleLookup.h"
#include <stdlib.h>
#include "pso/effect/item/TItemEffFlame.h"
#include "pso/weapon/shoot/TItemShoot.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/MatrixOps.h"

// Built with -inline off,deferred: functions are written last to first.

void TItemWeaponInfernoBazooka::emit_marker_effects() { recoil_state = 1; }

TItemWeaponInfernoBazooka::~TItemWeaponInfernoBazooka() {}

void expire_weapon_casing(TObject *p) { p->queue_destruction(); }

TWeaponCasing::~TWeaponCasing() {}

TItem *TItemWeaponInfernoBazooka::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponInfernoBazooka(tl_05, item);
    }
    return NULL;
}

TItemWeaponInfernoBazooka::TItemWeaponInfernoBazooka(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    barrel_offset = 0.0f;
    impact_callback = spawn_flame_wall_impact;
    recoil_state = 0;
    hit_callback = (WeaponHitCallback)play_target_impact_effect;
    shot_callback = create_shoot_model_with_particles;
    shot_speed = 15.0f;
}

void TItemWeaponInfernoBazooka::update_weapon() {
    s32 ang;
    Vec v;
    s32 rotation[3];
    if (this->recoil_state == 1) {
        ::approach_value(&barrel_offset, (-0.5f), (-2.0f));
        if ((-2.0f) == barrel_offset) {
            this->recoil_state = 2;
            ang = owner->rotation.y + 0x4000;
            v.x = sin_table_lookup(ang);
            v.y = 0.0f;
            v.z = cos_table_lookup(ang);
            rotation[0] = 0x4000;
            rotation[1] = owner->rotation.y;
            rotation[2] = 0;
            launch_weapon_casing(tl_05, this, 3, &v, rotation);
        }
    } else if (this->recoil_state == 2) {
        ::approach_value(&barrel_offset, 0.2f, 0.0f);
        if (0.0f == barrel_offset) {
            this->recoil_state = 0;
        }
    }
}


void TItemWeaponInfernoBazooka::transform_model_node() {
    if (get_model_node_counter() == 1) {
        translate_matrix(0, 0.0f, (-1.0f) * barrel_offset, 0.0f);
    }
}

#pragma push
#pragma opt_common_subs off
#pragma fp_contract on
TWeaponCasing::TWeaponCasing(TObject *parent, TItem *item, Vec *position, Vec *velocity, s32 *rotation) : TObject(parent) {
    item_id = item->get_item_id();
    VecCopy(&this->position, position);
    copy_xyz(&rotation_x, rotation);
    VecCopy(&this->velocity, velocity);
    this->velocity.x *= 0.5f * (3.0517578e-05f * (f32)rand()) + 0.5f;
    this->velocity.y *= 0.5f * (3.0517578e-05f * (f32)rand()) + 0.5f;
    this->velocity.z *= 0.5f * (3.0517578e-05f * (f32)rand()) + 0.5f;
}
#pragma pop

void TWeaponCasing::run_task() {
    if (find_equipped_item(item_id) == 0U) {
        queue_destruction();
        return;
    }
    vec3_add_to(&position, &velocity);
    velocity.y += -0.2f;
}


void TWeaponCasing::render() {
    NJS_OBJECT *child;
    TItemEquipBase *equipped_item;

    equipped_item = (TItemEquipBase *)find_equipped_item(item_id);
    if (equipped_item != NULL) {
        child = equipped_item->second_model;
        if (child != NULL) {
            set_texlist(equipped_item->get_texlist());
            push_matrix();
            post_translate_matrix(&position.x);
            rotate_matrix_y(0, rotation_y);
            rotate_matrix_x(0, rotation_x);
            rotate_matrix_z(0, rotation_z);
            draw_ginja_object(child);
            pop_matrix();
        }
    }
}


void launch_weapon_casing(TObject *parent, TItemWeapon *item, s32 joint, Vec *velocity, s32 *angle) {
    Vec joint_pos;
    TObject *object;
    if ((parent != 0) && (item != 0U) && (velocity != 0U) && (angle != 0U) && (item->get_joint_position(joint, &joint_pos) != 0)) {
        object = new TWeaponCasing(parent, item, &joint_pos, velocity, angle);
        TItemAttacker::spawn_item_timer(object, (ItemTimerCallback)expire_weapon_casing, 0xF);
    }
}

void spawn_weapon_casing(TObject *parent, TItem *item, Vec *pos, Vec *velocity, s32 *angle) {
    TObject *p;
    if ((parent != 0) && (item != 0U) && (pos != 0U) && (velocity != 0U) && (angle != 0U)) {
        p = new TWeaponCasing(parent, item, pos, velocity, angle);
        TItemAttacker::spawn_item_timer(p, (ItemTimerCallback)expire_weapon_casing, 0xF);
    }
}

