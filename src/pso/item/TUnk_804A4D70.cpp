#include "types.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItemEquipVariant_8012B200.h"
#include "pso/item/TItem.h"
#include "pso/item/TUnk_804A4D70.h"
#include "pso/item/TItemEffOrgaFlowShot.h"
#include "pso/item/TItemProShield.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_8012B3C4.h"
#include "pso/unk/text_8012B524.h"

#ifndef PSO_ITEMS_TITEMWEAPONPARTISAN_H
#define PSO_ITEMS_TITEMWEAPONPARTISAN_H
#include "pso/items/TItemWeapon.h"
struct TItemWeaponPartisan : TItemWeapon {
    virtual ~TItemWeaponPartisan();
    virtual void emit_marker_effects();
    s32 rotation;
    WeaponVector scale;
    WeaponVector first_translation;
    WeaponVector second_translation;
};
typedef char PartisanRotationOffset[(offsetof(TItemWeaponPartisan,rotation)==0x1F8)?1:-1];
typedef char PartisanScaleOffset[(offsetof(TItemWeaponPartisan,scale)==0x1FC)?1:-1];
typedef char PartisanFirstTranslationOffset[(offsetof(TItemWeaponPartisan,first_translation)==0x208)?1:-1];
typedef char PartisanSecondTranslationOffset[(offsetof(TItemWeaponPartisan,second_translation)==0x214)?1:-1];
typedef char PartisanSize[(sizeof(TItemWeaponPartisan)==0x220)?1:-1];
#endif

struct RecoveredGlobal_8012B524_lbl_804A4D70 { s32 value; u8 remaining[0xF4]; };
typedef char RecoveredGlobal_8012B524_lbl_804A4D70_size[sizeof(RecoveredGlobal_8012B524_lbl_804A4D70) == 0xF8 ? 1 : -1];

extern "C" {
u8 get_item_index__5TItemFv();
s32 is_mode_two_and_ready__10TObjPlayerFv(TItemWeapon*);
int obj_getPtr2B0_20(u8 *p);
s32 try_spend_actor_meseta(u8 *arg0, s32 arg1);
void show_meseta_label(s32 arg0, u32 arg1, s32 arg2, s32 arg3);
void update_active_game_effect__10TObjPlayerFv(TItemWeapon*);
void *spawn_particle_effect(void *pos, s32 id);
s32 scale_current_matrix(void *);
s32 post_translate_matrix(void *);
s32 rotate_matrix_z(int, int);
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
u8 * TItemWeapon__ct(void *, void *);
extern RecoveredGlobal_8012B524_lbl_804A4D70 partisan_weapon_vtable;
}
void advance_angle_wrap(s32 *arg0, s32 arg1);

void *__dt__13TUnk_804A4D70Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = &partisan_weapon_vtable.value;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

void TUnk_804A4D70::emit_marker_effects() {
    switch (((TItem *)this)->get_item_index()) {
    case 6:
        if (is_mode_two_and_ready__10TObjPlayerFv(this) && obj_getPtr2B0_20((u8 *)owner) >= 10000) {
            try_spend_actor_meseta((u8 *)owner, 10000);
            show_meseta_label((s32)owner, (u32)((WeaponVector*)((u8*)owner + 0x2FC)), 0, -10000);
            apply_scale_if_active(3.0f);
            spawn_particle_effect((WeaponVector*)((u8*)owner + 0x2FC), 0x66);
            spawn_particle_effect((WeaponVector*)((u8*)owner + 0x2FC), 0x66);
        } else {
            update_active_game_effect__10TObjPlayerFv(this);
        }
        break;
    default:
        update_active_game_effect__10TObjPlayerFv(this);
        break;
    }
}

extern "C" {

void TObjPlayer::update_area_effect_objects() {
    s32 player_list;

    switch ((s32) get_item_index__5TItemFv()) {
    case 6:
        if (TObjPlayer::get_player_list() == 4) {
            rotate_matrix_z(0, (int) (*(s32 *)&this->unk_1F8));
        }
        break;
    case 5:
        player_list = TObjPlayer::get_player_list();
        switch (player_list) {
        case 1:
            post_translate_matrix((u8 *)&this->unk_208);
            return;
        case 2:
            post_translate_matrix((u8 *)&this->m_214);
            return;
        case 3:
            scale_current_matrix((u8 *)&this->m_1fc);
            break;
        }
        break;
    }
}

void TUnk_804A4D70::update_idle() {
    if (get_item_index__5TItemFv() == 5) {
        TItemEffOrgaFlowShot::approach_value((f32 *)(((u8 *)this) + 0x204), (f32)0.2f, (f32)0.0f);
        if (this->m_204 <= 0.0f) {
            TItemEffOrgaFlowShot::approach_value((f32 *)(((u8 *)this) + 0x20C), (f32)(-0.2f), (f32)(-1.055f));
            TItemEffOrgaFlowShot::approach_value((f32 *)(((u8 *)this) + 0x218), (f32)0.15f, (f32)0.75f);
        }
    }
}
void TUnk_804A4D70::update_attack() {
    u8 *arg0 = (u8 *)this;
    if (get_item_index__5TItemFv() == 5) {
        TItemEffOrgaFlowShot::approach_value((f32 *)(arg0 + 0x20C), (f32)0.5f, (f32)0.0f);
        TItemEffOrgaFlowShot::approach_value((f32 *)(arg0 + 0x218), (f32)(-0.25f), (f32)0.0f);
        if (0.0f <= this->m_20c) {
            TItemEffOrgaFlowShot::approach_value((f32 *)(arg0 + 0x204), (f32)0.5f, (f32)1.0f);
        }
    }
}

void TUnk_804A4D70::update_weapon() {
    s32 var_r4;

    if (get_item_index__5TItemFv() == 6) {
        var_r4 = obj_getPtr2B0_20((u8 *)this->owner) / 100000;
        var_r4 = var_r4 * 0x222;
        if (var_r4 > 0x1555) {
            var_r4 = 0x1555;
        }
        advance_angle_wrap((s32 *)&this->unk_1F8, var_r4 + 0x1555);
    }
}

u8 *TItemWeaponPartisan__ct(u8 *arg0, u8 *arg1, s32 _w2) {
    TItemWeapon__ct(arg0, arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = &partisan_weapon_vtable.value;
    *(s32 *)((s8 *)arg0 + 0x1F8) = 0;
    ((TUnk_804A4D70 *)arg0)->m_1fc = (f32) 1.0f;
    *(f32 *)((s8 *)arg0 + 0x200) = (f32) 1.0f;
    ((TUnk_804A4D70 *)arg0)->m_204 = (f32) 1.0f;
    *(f32 *)((s8 *)arg0 + 0x208) = (f32) 0.0f;
    ((TUnk_804A4D70 *)arg0)->m_20c = (f32) 0.0f;
    *(f32 *)((s8 *)arg0 + 0x210) = (f32) 0.0f;
    ((TUnk_804A4D70 *)arg0)->m_214 = (f32) 0.0f;
    *(f32 *)((s8 *)arg0 + 0x218) = (f32) 0.0f;
    ((TUnk_804A4D70 *)arg0)->m_21c = (f32) 0.0f;
    ((TObjPlayer *)arg0)->set_status_flags(2);
    if (((TItem *)arg0)->get_item_index() == 6) {
        ((TObjPlayer *)arg0)->set_status_flags(0x20);
    }
    return arg0;
}
}

u8 *create_partisan_weapon(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x220));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(TItemWeaponPartisan__ct((u8 *)temp_r3, (u8 *)tl_05, (s32)arg0));
        }
        return var_r0;
    }
    return NULL;
}
