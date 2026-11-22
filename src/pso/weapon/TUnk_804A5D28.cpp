#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/player/TObjPlayer_8012E760.h"
#include "pso/player/TObjPlayer.h"
#include "pso/weapon/TItemAttacker.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/TUnk_804A5D10.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/vector.h"
#include "pso/item/TItem.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/weapon/TUnk_804A5D28.h"
#include "pso/effect/item/TItemEffOrgaFlowShot.h"
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

TUnk_804A5D10::~TUnk_804A5D10() {}

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
        TItemEffOrgaFlowShot::approach_value(&barrel_offset, (-0.5f), (-2.0f));
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
        TItemEffOrgaFlowShot::approach_value(&barrel_offset, 0.2f, 0.0f);
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

struct RecoveredGlobal_8012E414_lbl_804A5D10 {
    s32 value;
    u8 remaining[0x14];
};

extern "C" {
void __ct__7TObjectFP7TObject(void *, void *);
extern RecoveredGlobal_8012E414_lbl_804A5D10 __vt__13TUnk_804A5D10;

#pragma push
#pragma opt_common_subs off
#pragma fp_contract on
u8 *TObjPlayer::construct_weapon_casing(u8 *parent, u8 *arg2, u8 *arg3, u8 *arg4, u8 *arg5) {
    __ct__7TObjectFP7TObject(this, parent);
    *(s32 **)((s8 *)((u8 *)this) + 0x18) = &__vt__13TUnk_804A5D10.value;
    *(s32 *)((s8 *)((u8 *)this) + 0x1C) = ((TItem *)arg2)->get_item_id();
    VecCopy((Vec *)(((u8 *)this) + 0x2C), (const Vec *)arg3);
    copy_xyz(((u8 *)this) + 0x38, arg5);
    VecCopy((Vec *)(((u8 *)this) + 0x20), (const Vec *)arg4);
    *(f32 *)&this->m_20 = (f32) (*(f32 *)&this->m_20 * ((0.5f * (3.0517578e-05f * (f32) rand())) + 0.5f));
    *(f32 *)&this->texlist = (f32) (*(f32 *)&this->texlist * ((0.5f * (3.0517578e-05f * (f32) rand())) + 0.5f));
    *(f32 *)&this->room = (f32) (*(f32 *)&this->room * ((0.5f * (3.0517578e-05f * (f32) rand())) + 0.5f));
    return ((u8 *)this);
}
#pragma pop

}

void TUnk_804A5D10::run_task() {
    u8 *arg0 = (u8 *)this;
    if (find_equipped_item(*(s32 *)((s8 *)arg0 + 0x1C)) == 0U) {
        ((TObject *)arg0)->queue_destruction();
        return;
    }
    vec3_add_to(arg0 + 0x2C, arg0 + 0x20);
    this->m_24 += -0.2f;
}


void TUnk_804A5D10::render() {
    u8 *arg0 = (u8 *)this;
    uaddr temp_r31;
    u8 *equipped_item;

    equipped_item = (u8 *)find_equipped_item(*(s32 *)((s8 *)arg0 + 0x1C));
    if (equipped_item != NULL) {
        temp_r31 = *(u32 *)((s8 *)equipped_item + 0x188);
        if (temp_r31 != 0U) {
            set_texlist(((TItem *)equipped_item)->get_texlist());
            push_matrix();
            post_translate_matrix(arg0 + 0x2C);
            rotate_matrix_y(0, *(s32 *)&this->unk_3C);
            rotate_matrix_x(0, this->m_38);
            rotate_matrix_z(0, this->m_40);
            draw_ginja_object((void *)temp_r31);
            pop_matrix();
        }
    }
}


void TObjPlayer::launch_weapon_casing(saddr arg0, uaddr arg1, s32 joint, uaddr arg3, uaddr angle) {
    u8 sp8[0x18];
    void *object;
    if ((arg0 != 0) && (arg1 != 0U) && (arg3 != 0U) && (angle != 0U) && (((TItemWeapon *)arg1)->get_joint_position(joint, sp8) != 0)) {
        object = TObject::operator new(0x44);
        if (object != NULL) {
            object = ((TObjPlayer *)object)->construct_weapon_casing((u8 *)arg0, (u8 *)arg1, (u8 *)sp8, (u8 *)arg3, (u8 *)angle);
        }
        TItemAttacker::spawn_item_timer((TObject *)object, (ItemTimerCallback)expire_weapon_casing, 0xF);
    }
}

void TObjPlayer::spawn_weapon_casing(saddr arg0, uaddr arg1, uaddr pos, uaddr arg3, uaddr angle) {
    void *p;
    if ((arg0 != 0) && (arg1 != 0U) && (pos != 0U) && (arg3 != 0U) && (angle != 0U)) {
        p = TObject::operator new(0x44);
        if (p != 0) {
            p = ((TObjPlayer *)p)->construct_weapon_casing((u8 *)arg0, (u8 *)arg1, (u8 *)pos, (u8 *)arg3, (u8 *)angle);
        }
        TItemAttacker::spawn_item_timer((TObject *)p, (ItemTimerCallback)expire_weapon_casing, 0xF);
    }
}

