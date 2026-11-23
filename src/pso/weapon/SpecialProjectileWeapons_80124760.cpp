#include "pso/effect/TEffStarLight2D.h"
#include "pso/weapon/SpecialProjectileWeapons_80124760.h"
#include "pso/weapon/TUnk_804A204C.h"
#include "pso/weapon/shoot/TUnk_804A2148.h"
#include "pso/weapon/TUnk_804A2164.h"
#include "types.h"
#include "pso/system/data/FlagWord.h"
#include "pso/item/TItemFollowStarLight.h"
#include "pso/weapon/shoot/TItemShoot.h"
#include "pso/system/task/TObject.h"


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

struct RecoilWeaponView : TItemWeapon {
    s32 projectileVisible;
    s32 projectileSpin;
    s32 recoilAngle;
    s32 recoilPhase;
};

typedef struct MegidWeaponRenderView { u8 pad[0x200]; s32 f200; } MegidWeaponRenderView;


struct WeaponStarLightParameterWords { u32 w[5]; };

struct StarLightFollowerView {
    u8 pad0[0x18];
    void *vtbl;
    s32 f1c;
    s32 f20;
    s32 f24;
    s32 f28;
};

LAYOUT_ASSERT(RecoilVisibleOffset, offsetof(RecoilWeaponView, projectileVisible) == 0x1F8);
LAYOUT_ASSERT(RecoilSpinOffset, offsetof(RecoilWeaponView, projectileSpin) == 0x1FC);
LAYOUT_ASSERT(RecoilAngleOffset, offsetof(RecoilWeaponView, recoilAngle) == 0x200);
LAYOUT_ASSERT(RecoilPhaseOffset, offsetof(RecoilWeaponView, recoilPhase) == 0x204);
LAYOUT_ASSERT(RecoilWeaponExtent, sizeof(RecoilWeaponView) == 0x208);
LAYOUT_ASSERT(WeaponStarLightParameterWordsExtent, sizeof(WeaponStarLightParameterWords) == 0x14);
LAYOUT_ASSERT(StarLightFollowerExtent, sizeof(StarLightFollowerView) == 0x2C);

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *);
s32 post_translate_matrix(void *);

void __ct__15TItemShootModelFPvPC3VecPC3Vecf(void *);
typedef u8 *(*Fn_80124694_3)(void *, s32, void *);
typedef s32 (*Fn_80124810_5)(s32, s32, s32, s32, f32);
}
s32 drill_launcher_create_shot(s32 arg0, s32 arg1, s32 arg2, f32 farg0);

void* drill_launcher_ct(void* a0, s32, void *);
extern s32 tl_05;
TItem *create_drill_launcher(u8 *arg0);
void drill_launcher_return_timer(void *arg0);
extern void *__vt__13TUnk_804A2148[];
extern void *__vt__13TUnk_804A2164[];
#define __vt__13TUnk_804A2148 ((s32 *)__vt__13TUnk_804A2148)


void TUnk_804A2148::render() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r31;
    u8 *temp_r3;

    if (TItemShootModel::is_owner_alive() != 0) {
        temp_r3 = (unsigned char *) (this->model);
        if ((temp_r3 != NULL) && ((uaddr) this->texture_list != 0U)) {
            temp_r31 = (unsigned char *) (*(void **)((s8 *)((unsigned char *) (*(void **)((s8 *)temp_r3 + 0x2C))) + 0x30));
            *(s32 *)((s8 *)temp_r31 + 0) = (s32) (*(s32 *)((s8 *)temp_r31 + 0) & 0xFFFFFFFB);
            *(f32 *)((s8 *)temp_r31 + 0x20) = (f32) 10.0f;
            push_matrix();
            set_texlist((uaddr)this->texture_list);
            post_translate_matrix(arg0 + 0x1C);
            rotate_matrix_y(0, this->m_count);
            rotate_matrix_x(0, this->m_28 - 0x4000);
            draw_ginja_object((this->model));
            pop_matrix();
            *(f32 *)((s8 *)temp_r31 + 0x20) = (f32) 1.0f;
        }
    }
}

void TUnk_804A2148::hook() {  }

void *ct_shoot_model__10TObjPlayerFPv(void *item_shoot_model) {
    __ct__15TItemShootModelFPvPC3VecPC3Vecf(item_shoot_model);
    *(s32 **)((s8 *)item_shoot_model + 0x18) = __vt__13TUnk_804A2148;
    return item_shoot_model;
}

s32 drill_launcher_create_shot(s32 owner, s32 pos, s32 dir, f32 life) {
    saddr var_r0;
    s32 var_r31;

    var_r31 = 0;
    if (owner != 0) {
        var_r0 = (saddr)TObject::operator new(0x6C);
        if (var_r0 != 0) {
            var_r0 = ((Fn_80124810_5)ct_shoot_model__10TObjPlayerFPv)(var_r0, owner, pos, dir, life);
        }
        var_r31 = var_r0;
    }
    var_r0 = (uaddr)TObjPlayer::spawn_shoot_particle(owner, pos, dir, life);
    if (var_r0 != 0U) {
        ((TItemShootParticle *)var_r0)->spawn_slot_emitter(0x1BB, 0);
    }
    return var_r31;
}
LAYOUT_ASSERT(BurstReadyOffset, offsetof(RecoilWeaponView, projectileVisible)==0x1F8);
LAYOUT_ASSERT(BurstModeOffset, offsetof(RecoilWeaponView, recoilPhase)==0x204);

void TUnk_804A2164::emit_marker_effects() {
    Vec sp8;
    saddr temp_r31;
    s32 var_r30;
    if ((s32) ((RecoilWeaponView *)this)->projectileVisible == 1) {
        TItemAttacker::spawn_item_timer((RecoilWeaponView *)this, (ItemTimerCallback)drill_launcher_return_timer, 0x1E);
        ((RecoilWeaponView *)this)->projectileVisible = 0;
    }
    ((RecoilWeaponView *)this)->recoilPhase = 2;
    temp_r31 = (saddr)((RecoilWeaponView *)this)->owner + 0x7CC;
    if (get_burst_counter((void*)temp_r31) == 0) {
        var_r30 = 0;
        do {
            increment_burst_counter((u8 *)temp_r31);
            var_r30 += 1;
        } while (var_r30 != 2);
    }
    ((TItemWeapon *)((RecoilWeaponView *)this))->get_gun_point(&sp8);
    if (((RecoilWeaponView *)this)->is_mode_two_and_ready() != 0) {
        ((TItemWeapon *)((RecoilWeaponView *)this))->launch_rare_weapon_special(&sp8, 1, (f32) (1.0f));
        return;
    }
    ((RecoilWeaponView *)this)->launch_shot((u8 *)&sp8, 0, 0, 1);
}
void TUnk_804A2164::vfunc_60() {
    s32 player_list;
    player_list = TObjPlayer::get_player_list();
    if ((player_list > 0) && (player_list < 4)) {
        rotate_matrix_z(0, *(s32 *)((s8 *)this + 0x200));
        return;
    }
    if (player_list == 4) {
        if (second_model != 0U) {
            if ((s32) *(s32 *)((s8 *)this + 0x1F8) == 1) {
                draw_ginja_object(second_model);
            }
        }
    }
}

void TUnk_804A2164::update_weapon() {
    void *temp_r4;
    void *temp_r4_2;
    this->m_1fc = (this->m_1fc + 0x1999);
    temp_r4 = this->second_model;
    if (temp_r4 != NULL) {
        temp_r4_2 = *(void **)((s8 *)temp_r4 + 0x2C);
        *(s32 *)((s8 *)temp_r4_2 + 0) = (s32) (*(s32 *)((s8 *)temp_r4_2 + 0) & 0xFFFFFFFD);
        *(s32 *)((s8 *)temp_r4_2 + 0x18) = (s32) this->m_1fc;
    }
    switch (this->m_204) {
    case 1:
        *(s32 *)((s8 *)this + 0x200) = (s32) (*(s32 *)((s8 *)this + 0x200) + 0xE38);
        if ((s32) *(s32 *)((s8 *)this + 0x200) >= 0) {
            *(s32 *)((s8 *)this + 0x200) = 0;
            this->m_204 = 0;
        }
        return;
    case 2:
        *(s32 *)((s8 *)this + 0x200) = (s32) (*(s32 *)((s8 *)this + 0x200) - 0xE38);
        if ((s32) *(s32 *)((s8 *)this + 0x200) <= -0x31C7) {
            *(s32 *)((s8 *)this + 0x200) = -0x31C7;
            this->m_204 = 3;
            return;
        }
        break;
    case 3:
        this->m_204 = 1;
        return;
    }
}
TUnk_804A2164::~TUnk_804A2164() {

}
void* drill_launcher_ct(void* a0, s32 _w1, void * _w2) { __ct__11TItemWeaponFP7TObjectPUc(a0); *(int*)((char*)a0 + 0x18) = (saddr)((unsigned char *)__vt__13TUnk_804A2164); *(int*)((char*)a0 + 0x1f0) = (saddr)drill_launcher_create_shot; *(float*)((char*)a0 + 0x1e4) = 9.0f; ((TItemWeapon *)a0)->set_weapon_flags((saddr)((void*)34)); *(int*)((char*)a0 + 0x1f8) = 1; ((TUnk_804A2164 *)a0)->m_1fc = 0; *(int*)((char*)a0 + 0x200) = 0; return a0; }
TItem *create_drill_launcher(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)((u8 *)TItem::operator new(0x208));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(((u8 *)drill_launcher_ct(temp_r3, tl_05, arg0)));
        }
        return reinterpret_cast<TItem *>(var_r0);
    }
    return NULL;
}

TUnk_804A2148::~TUnk_804A2148() {

}
void drill_launcher_return_timer(void *arg0) {
    if (arg0 != NULL) {
        *(s32 *)((s8 *)arg0 + 0x1F8) = 1;
    }
}

void increment_burst_counter(u8 *counter) {
    *(s32 *)((s8 *)counter + 0x18) = (s32) (*(s32 *)((s8 *)counter + 0x18) + 1);
}
s32 get_burst_counter(void* p) { return *(s32*)((char*)p + 0x18); }
