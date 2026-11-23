#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/TEffStarLight2D.h"
#include "pso/weapon/SpecialProjectileWeapons_80124760.h"
#include "pso/technique/TTecMegid.h"
#include "pso/weapon/TUnk_804A204C.h"
#include "pso/item/TUnk_804A0668.h"
#include "pso/weapon/shoot/TUnk_804A2148.h"
#include "pso/weapon/TUnk_804A2164.h"
#include "types.h"
#include "pso/system/data/FlagWord.h"
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
#include "pso/player/TObjPlayer_80363BE0.h"
#include "pso/weapon/SpecialProjectileWeapons.h"

struct RecoilWeaponView : TItemWeapon {
    s32 projectileVisible;
    s32 projectileSpin;
    s32 recoilAngle;
    s32 recoilPhase;
};

typedef struct MegidWeaponRenderView { u8 pad[0x200]; s32 f200; } MegidWeaponRenderView;


LAYOUT_ASSERT(RecoilVisibleOffset, offsetof(RecoilWeaponView, projectileVisible) == 0x1F8);
LAYOUT_ASSERT(RecoilSpinOffset, offsetof(RecoilWeaponView, projectileSpin) == 0x1FC);
LAYOUT_ASSERT(RecoilAngleOffset, offsetof(RecoilWeaponView, recoilAngle) == 0x200);
LAYOUT_ASSERT(RecoilPhaseOffset, offsetof(RecoilWeaponView, recoilPhase) == 0x204);
LAYOUT_ASSERT(RecoilWeaponExtent, sizeof(RecoilWeaponView) == 0x208);

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *);
s32 post_translate_matrix(void *);
s32 draw_weapon_at_joint(void *, s32, void *);
extern s32 model_render_flags;
s32 is_item_area_enabled();
}

extern s32 tl_05;
extern "C" {
void *TObjPlayer__sub_80124694(TObjPlayer *arg0);
TItem *TObjPlayer__sub_80124708(u8 *arg0);

typedef u8 *(*Fn_80124694_3)(void *, s32, void *);
typedef s32 (*Fn_80124810_5)(s32, s32, s32, s32, f32);
}

void TUnk_804A204C::emit_marker_effects() {
    s32 sp8;
    void *temp_r31;
    if (is_mode_two_and_ready() != 0) {
        if (get_joint_position(5, &sp8) != 0) {
            temp_r31 = this->owner;
            TTecMegid::create_ex((saddr)temp_r31, (saddr)(&sp8), (s32)(*(s32 *)((s8 *)temp_r31 + 0x60)), (s32)(((TItemWeapon *)this)->get_tp()));
            this->roll_technique();
        }
    } else {
        ((TItemWeapon *)this)->update_active_game_effect();
    }
}

void TUnk_804A204C::update_weapon() {
    s32 temp_r3;
    if ((s32) this->m_1fc == 1) {
        *(s32 *)((s8 *)this + 0x200) = (s32) (*(s32 *)((s8 *)this + 0x200) + 0xAAA);
        if ((s32) *(s32 *)((s8 *)this + 0x200) >= 0x2000) {
            *(s32 *)((s8 *)this + 0x200) = 0x2000;
            this->m_1fc = 0;
        }
    } else {
        *(s32 *)((s8 *)this + 0x200) = (s32) (*(s32 *)((s8 *)this + 0x200) - 0xAAA);
        if ((s32) *(s32 *)((s8 *)this + 0x200) <= -0x2000) {
            *(s32 *)((s8 *)this + 0x200) = -0x2000;
            this->m_1fc = 1;
        }
    }
    temp_r3 = get_current_floor();
    if (((s32) this->m_204 != temp_r3) && ((u32) *(u32 *)((s8 *)this + 0xF4) != 0U)) {
        this->m_204 = temp_r3;
        if (is_item_area_enabled() != 0) {
            create_icon__10TObjPlayerFiii(tl_05, (s32)((s32)(this->get_item_id())), 5);
        }
    }
}

void TUnk_804A204C::vfunc_60() {
    switch (((u32)TObjPlayer::get_player_list())) {
    case 1:
        rotate_matrix_y(0, ((MegidWeaponRenderView *)this)->f200);
        return;
    case 2:
        TItem::begin_effect_render();
        return;
    case 3:
        rotate_matrix_y(0, (int)(-((MegidWeaponRenderView *)this)->f200));
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
    s32 sp8;
    s32 temp_r3;
    void *temp_r31;
    void *temp_r5;
    if (((void *) *(void **)((s8 *)this + 0xF4) != NULL) && (this->is_hidden() == 0)) {
        temp_r5 = *(void **)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)this + 0xF4)) + 0x2C)) + 0x30);
        temp_r31 = *(void **)((s8 *)temp_r5 + 0x30);
        *(s32 *)((s8 *)temp_r31 + 0) = (s32) (*(s32 *)((s8 *)temp_r31 + 0) | 0x18);
        draw_weapon_at_joint(this, 0x30, temp_r5);
        *(s32 *)((s8 *)temp_r31 + 0) = (s32) (*(s32 *)((s8 *)temp_r31 + 0) & 0xFFFFFFE7);
        if (get_joint_position(5, &sp8) != 0) {
            push_matrix();
            TObjPlayer__sub_80364198();
            model_render_flags &= 0xFFFFFFEF;
            TObjPlayer::set_model_fade_alpha((f32)this->get_owner_alpha());
            post_translate_matrix(&sp8);
            rotate_matrix_y(0, (int)(*(s32 *)((s8 *)this->owner + 0x60)));
            *(s32 *)((s8 *)temp_r31 + 0) = (s32) (*(s32 *)((s8 *)temp_r31 + 0) | 0x11);
            draw_ginja_object(temp_r31);
            TParticleCtrl::begin_effect_render();
            draw_ginja_object(*(void **)((s8 *)temp_r31 + 0x2C));
            TParticleCtrl::end_effect_render();
            temp_r3 = *(s32 *)((s8 *)temp_r31 + 0);
            *(s32 *)((s8 *)temp_r31 + 0) = (s32) (temp_r3 & ~0x11);
            TObjPlayer::warn_if_gauge_low();
            pop_matrix();
            pop_matrix();
        }
    }
}

void TUnk_804A204C::on_equipped() {
    m_204 = -1;
    if (effect_objects != NULL) {
        new TUnk_804A0668(effect_objects, get_owner_client(), 0x5A);
    }
    roll_technique();
    roll_technique();
}

extern void *__vt__13TUnk_804A204C[];
#define __vt__13TUnk_804A204C ((s32 *)__vt__13TUnk_804A204C)

TUnk_804A204C::~TUnk_804A204C() {

}


void *TObjPlayer__sub_80124694(TObjPlayer *player) {
    __ct__11TItemWeaponFP7TObjectPUc(player);
    *(s32 **)((s8 *)player + 0x18) = __vt__13TUnk_804A204C;
    ((FlagWord *)((char *)player + 376))->set(32);
    ((TItemWeapon *)player)->set_weapon_flags(35);
    player->set_effect_state(12);
    *(u32 *)((s8 *)player + 0x1F8) = 0;
    *(u32 *)((s8 *)player + 0x200) = 0;
    ((TUnk_804A204C *)player)->m_204 = -1;
    return player;
}

TItem *TObjPlayer__sub_80124708(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)((u8 *)TItem::operator new(0x208));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(((Fn_80124694_3)TObjPlayer__sub_80124694)(temp_r3, tl_05, arg0));
        }
        return reinterpret_cast<TItem *>(var_r0);
    }
    return NULL;
}
