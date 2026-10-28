#include "types.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/player/TObjPlayer_8012E760.h"
#include "pso/player/TObjPlayer.h"
#include "pso/TItemAttacker.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/TUnk_804A5D10.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/system/vector.h"
#include "pso/item/TItem.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/player/TUnk_804A5D28.h"
#include "pso/item/TItemEffOrgaFlowShot.h"
#include "pso/player/TObjPlayer_8023E480.h"

extern "C" {
void *__nw__7TObjectFUl(u32);

void TObjPlayer::spawn_weapon_casing(s32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4) {
    void *p;
    if ((arg0 != 0) && (arg1 != 0U) && (arg2 != 0U) && (arg3 != 0U) && (arg4 != 0U)) {
        p = __nw__7TObjectFUl(0x44);
        if (p != 0) {
            p = ((TObjPlayer *)p)->construct_weapon_casing((u8 *)arg0, (u8 *)arg1, (u8 *)arg2, (u8 *)arg3, (u8 *)arg4);
        }
        TItemAttacker::spawn_item_timer((s32)p, (s32)expire_weapon_casing, 0xF);
    }
}

void TObjPlayer::launch_weapon_casing(s32 arg0, u32 arg1, s32 arg2, u32 arg3, u32 arg4) {
    u8 sp8[0x18];
    void *var_r0;
    if ((arg0 != 0) && (arg1 != 0U) && (arg3 != 0U) && (arg4 != 0U) && (((TObjPlayer *)arg1)->draw_icon((s32)arg2, (s32)sp8) != 0)) {
        var_r0 = __nw__7TObjectFUl(0x44);
        if (var_r0 != NULL) {
            var_r0 = ((TObjPlayer *)var_r0)->construct_weapon_casing((u8 *)arg0, (u8 *)arg1, (u8 *)sp8, (u8 *)arg3, (u8 *)arg4);
        }
        TItemAttacker::spawn_item_timer((s32)var_r0, (s32)expire_weapon_casing, 0xF);
    }
}

}

extern "C" {

s32 post_translate_matrix(void *);
s32 rotate_matrix_z(s32, s32);
s32 rotate_matrix_x(s32, s32);
s32 get_texture_id__10TObjPlayerFv();
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();

void TUnk_804A5D10::render() {
    u8 *arg0 = (u8 *)this;
    u32 temp_r31;
    u8 *temp_r3;

    temp_r3 = (u8 *)find_equipped_item(*(s32 *)((s8 *)arg0 + 0x1C));
    if (temp_r3 != NULL) {
        temp_r31 = *(u32 *)((s8 *)temp_r3 + 0x188);
        if (temp_r31 != 0U) {
            set_texlist(get_texture_id__10TObjPlayerFv());
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

}

extern "C" {

s32 vec3_add_to(void *, void *);

void TUnk_804A5D10::run_task() {
    u8 *arg0 = (u8 *)this;
    if (find_equipped_item(*(s32 *)((s8 *)arg0 + 0x1C)) == 0U) {
        queue_destruction__7TObjectFv(arg0);
        return;
    }
    vec3_add_to(arg0 + 0x2C, arg0 + 0x20);
    this->m_24 += -0.2f;
}

}

struct RecoveredGlobal_8012E414_lbl_804A5D10 {
    s32 value;
    u8 remaining[0x14];
};

extern "C" {
void __ct__7TObjectFP7TObject(void *, void *);
s32 rand(void);
extern RecoveredGlobal_8012E414_lbl_804A5D10 __vt__13TUnk_804A5D10;

#pragma push
#pragma opt_common_subs off
#pragma fp_contract on
typedef char RecoveredGlobal_8012E414_lbl_804A5D10_size[sizeof(RecoveredGlobal_8012E414_lbl_804A5D10) == 0x18 ? 1 : -1];
u8 *TObjPlayer::construct_weapon_casing(u8 *arg1, u8 *arg2, u8 *arg3, u8 *arg4, u8 *arg5) {
    __ct__7TObjectFP7TObject(this, arg1);
    *(s32 **)((s8 *)((u8 *)this) + 0x18) = &__vt__13TUnk_804A5D10.value;
    *(s32 *)((s8 *)((u8 *)this) + 0x1C) = ((TItem *)arg2)->get_item_id();
    VecCopy((Vec *)(((u8 *)this) + 0x2C), (const Vec *)arg3);
    ((TObjPlayer *)(((u8 *)this) + 0x38))->copy_xyz(arg5);
    VecCopy((Vec *)(((u8 *)this) + 0x20), (const Vec *)arg4);
    *(f32 *)&this->m_20 = (f32) (*(f32 *)&this->m_20 * ((0.5f * (3.0517578e-05f * (f32) rand())) + 0.5f));
    *(f32 *)&this->texture_id = (f32) (*(f32 *)&this->texture_id * ((0.5f * (3.0517578e-05f * (f32) rand())) + 0.5f));
    *(f32 *)&this->m_28 = (f32) (*(f32 *)&this->m_28 * ((0.5f * (3.0517578e-05f * (f32) rand())) + 0.5f));
    return ((u8 *)this);
}
#pragma pop

}

void TObjPlayer::apply_scale_effect() {
    if (TObjPlayer::get_player_list() == 1) {
        translate_matrix(0, 0.0f, (-1.0f) * *(f32 *)((s8 *)this + 0x1F8), 0.0f);
    }
}

struct Owner_8012E5A0 { u8 pad[0x60]; s32 f60; };

struct Self_8012E5A0 {
    u8 pad0[0xF0];
    Owner_8012E5A0 *owner;
    u8 padF4[0x1F8 - 0xF4];
    f32 f1FC;
    s32 state;
};

struct Vec_8012E5A0 { f32 x, y, z; };

struct Ang_8012E5A0 { s32 x, y, z; };

extern "C" {
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
extern s32 tl_05;

void TUnk_804A5D28::update_weapon() {
    s32 ang;
    Vec_8012E5A0 v;
    Ang_8012E5A0 a;
    Self_8012E5A0 *self = (Self_8012E5A0 *)this;
    if (this->m_1fc == 1) {
        TItemEffOrgaFlowShot::approach_value(&self->f1FC, (-0.5f), (-2.0f));
        if ((-2.0f) == self->f1FC) {
            this->m_1fc = 2;
            ang = self->owner->f60 + 0x4000;
            v.x = sin_table_lookup(ang);
            v.y = 0.0f;
            v.z = cos_table_lookup(ang);
            a.x = 0x4000;
            a.y = self->owner->f60;
            a.z = 0;
            TObjPlayer::launch_weapon_casing((s32)tl_05, (u32)self, 3, (u32)&v, (u32)&a);
        }
    } else if (this->m_1fc == 2) {
        TItemEffOrgaFlowShot::approach_value(&self->f1FC, 0.2f, 0.0f);
        if (0.0f == self->f1FC) {
            this->m_1fc = 0;
        }
    }
}

}

extern "C" {

int TItemWeapon__ct(void);

    extern unsigned char play_effect__13TItemEffFlameFllll[];
    extern unsigned char create_shoot_model_with_particles[];
    extern unsigned char lbl_804A5D28[];
    
void*TUnk_804A5D28::setup_flame_effect() { TItemWeapon__ct(); *(int*)((char*)this + 0x18) = (int)lbl_804A5D28; *(float*)((char*)this + 0x1f8) = 0.0f; *(int *)&(*(s32 * *)((u8 *)this + 0x1EC)) = (int)play_effect__13TItemEffFlameFllll; *(int *)&(this->m_1fc) = 0; *(int *)&(*(s32 * *)((u8 *)this + 0x1F4)) = (int)play_target_impact_effect; *(int*)((char*)this + 0x1f0) = (int)create_shoot_model_with_particles; (*(float *)((u8 *)this + 0x1E4)) = 15.0f; return this; }

}
