#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/math/ClampedStep.h"
#include "types.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/player/TObjPlayer_8012E760.h"
#include "pso/player/TObjPlayer.h"
#include "pso/weapon/TItemAttacker.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/weapon/TWeaponCasing.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/vector.h"
#include "pso/item/TItem.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/weapon/TUnk_804A5D28.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItemEquipVariant_8012E7D8.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/math/AngleLookup.h"
#include <stdlib.h>
#include "pso/effect/item/TItemEffFlame.h"
#include "pso/unk/text_8011BE50.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject.h"

// Built with -inline off,deferred: functions are written last to first.

extern "C" {
s32 post_translate_matrix(void *);
s32 rotate_matrix_z(s32, s32);
s32 rotate_matrix_x(s32, s32);
s32 vec3_add_to(void *, void *);
}

void TUnk_804A5D28::emit_marker_effects() { m_1fc = 1; }

TUnk_804A5D28::~TUnk_804A5D28() {}

void expire_weapon_casing(void *p) { ((TObject *)p)->queue_destruction(); }

TWeaponCasing::~TWeaponCasing() {}

TItem *TObjPlayer::create_inferno_bazooka(u8 *item) {
    if (item != NULL) {
        return new TUnk_804A5D28(tl_05, item);
    }
    return NULL;
}

TUnk_804A5D28::TUnk_804A5D28(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    barrel_offset = 0.0f;
    impact_callback = (WeaponHitCallback)spawn_flame_wall_impact;
    m_1fc = 0;
    hit_callback = (WeaponHitCallback)play_target_impact_effect;
    shot_callback = (WeaponShotCallback)create_shoot_model_with_particles;
    shot_speed = 15.0f;
}

struct Ang_8012E5A0 { s32 x, y, z; };

void TUnk_804A5D28::update_weapon() {
    s32 ang;
    Vec v;
    Ang_8012E5A0 a;
    if (this->m_1fc == 1) {
        ::approach_value(&barrel_offset, (-0.5f), (-2.0f));
        if ((-2.0f) == barrel_offset) {
            this->m_1fc = 2;
            ang = owner->rotation_y + 0x4000;
            v.x = sin_table_lookup(ang);
            v.y = 0.0f;
            v.z = cos_table_lookup(ang);
            a.x = 0x4000;
            a.y = owner->rotation_y;
            a.z = 0;
            TObjPlayer::launch_weapon_casing((saddr)tl_05, (uaddr)this, 3, (uaddr)&v, (uaddr)&a);
        }
    } else if (this->m_1fc == 2) {
        ::approach_value(&barrel_offset, 0.2f, 0.0f);
        if (0.0f == barrel_offset) {
            this->m_1fc = 0;
        }
    }
}


void TUnk_804A5D28::vfunc_60() {
    if (TObjPlayer::get_player_list() == 1) {
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
    uaddr child;
    u8 *equipped_item;

    equipped_item = (u8 *)find_equipped_item(item_id);
    if (equipped_item != NULL) {
        child = *(u32 *)((s8 *)equipped_item + 0x188);
        if (child != 0U) {
            set_texlist(((TItem *)equipped_item)->get_texlist());
            push_matrix();
            post_translate_matrix(&position);
            rotate_matrix_y(0, rotation_y);
            rotate_matrix_x(0, rotation_x);
            rotate_matrix_z(0, rotation_z);
            draw_ginja_object((void *)child);
            pop_matrix();
        }
    }
}


void TObjPlayer::launch_weapon_casing(saddr parent, uaddr item, s32 joint, uaddr velocity, uaddr angle) {
    u8 sp8[0x18];
    void *object;
    if ((parent != 0) && (item != 0U) && (velocity != 0U) && (angle != 0U) && (((TItemWeapon *)item)->get_joint_position(joint, sp8) != 0)) {
        object = new TWeaponCasing((TObject *)parent, (TItem *)item, (Vec *)sp8, (Vec *)velocity, (s32 *)angle);
        TItemAttacker::spawn_item_timer((TObject *)object, (ItemTimerCallback)expire_weapon_casing, 0xF);
    }
}

void TObjPlayer::spawn_weapon_casing(saddr parent, uaddr item, uaddr pos, uaddr velocity, uaddr angle) {
    void *p;
    if ((parent != 0) && (item != 0U) && (pos != 0U) && (velocity != 0U) && (angle != 0U)) {
        p = new TWeaponCasing((TObject *)parent, (TItem *)item, (Vec *)pos, (Vec *)velocity, (s32 *)angle);
        TItemAttacker::spawn_item_timer((TObject *)p, (ItemTimerCallback)expire_weapon_casing, 0xF);
    }
}

