#include "types.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_80087278.h"
#include "pso/unk/TUnk_804A5C18.h"
#include "pso/item/TItemEffOrgaFlowShot.h"
#include "pso/player/TObjPlayer_80109344.h"
#include "pso/unk/text_8011B620.h"
#include "pso/unk/text_80120D50.h"
#include "pso/unk/text_8012DF60.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItemEquipVariant_8012E190.h"
#include "pso/item/TItem.h"

extern "C" {

u8 get_item_index__5TItemFv(void *);
s32 rotate_matrix_z(s32, s32);
s32 rotate_matrix_x(s32, s32);

void TObjPlayer::apply_frame_camera_shake() {
    s32 player_list;
    s32 var_r30;

    player_list = TObjPlayer::get_player_list();
    if (get_item_index__5TItemFv(this) != 6) {
        if (player_list == (s32) this->m_21c) {
            translate_matrix(0, 0.0f, this->m_224, 0.0f);
        }
        var_r30 = *(s32 *)&this->unk_220;
    } else {
        if (player_list == (s32) this->m_21c) {
            rotate_matrix_x(0, -*(s32 *)&this->unk_220);
        }
        var_r30 = (s32) (*(s32 *)&this->unk_220 * 2) / 3;
    }
    if ((player_list == (s32) this->m_20c) || (player_list == (s32) this->m_214)) {
        rotate_matrix_z(0, var_r30);
    }
    if ((player_list == (s32) *(s32 *)&this->unk_210) || (player_list == (s32) *(s32 *)&this->unk_218)) {
        rotate_matrix_z(0, -var_r30);
    }
}

}

struct VBase_8012DE24 { char pad[0x18]; };

struct VObj_8012DE24 : VBase_8012DE24 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual s32 m49(s32 *, s32, s32, s32);
};

struct Self_8012DE24 {
    u8 pad[0x1F8];
    s32 icons[5];
};

extern "C" {
s32 draw_icon__10TObjPlayerFll(void *, int, void *);
extern s32 basic_shot_angle_table[];
void TUnk_804A5C18::emit_marker_effects() {
    s32 sp8[3];
    s32 i;
    for (i = 0; (u32)i != 5U; i++) {
        draw_icon__10TObjPlayerFll(((u8 *)this), ((struct Self_8012DE24 *)((u8 *)this))->icons[i], sp8);
        ((VObj_8012DE24 *)((u8 *)this))->m49(sp8, i, basic_shot_angle_table[i], 1);
        if (i == 0) {
            spawn_particle_effect(sp8, 9);
        }
    }
}

}

void TObjPlayer::update_approach_value() {
    u8 *arg0 = (u8 *)this;
    if ((s32) *(s32 *)&this->unk_220 < 0x2000) {
        TObjPlayer::add_angle_clamped((s32 *)(arg0 + 0x220), 0x2D8, 0x2000);
    }
    TItemEffOrgaFlowShot::approach_value((f32 *)(arg0 + 0x224), (f32)(-0.4f), (f32)(-1.2f));
}

void TUnk_804A5C18::update_attack() {
    u8 *arg0 = (u8 *)this;
    if ((s32) this->m_220 > 0) {
        TObjPlayer::add_angle_clamped((s32 *)(arg0 + 0x220), -0x2000, 0);
    }
    TItemEffOrgaFlowShot::approach_value((f32 *)(arg0 + 0x224), (f32)0.6f, (f32)0.0f);
}

extern "C" {
u8 *__nw__5TItemFUl(s32);
}
extern s32 tl_05;
extern u8 lbl_804A5C18[];

void *construct_shot_weapon(void *arg0, s32 parent, void *item) {
    TItemWeapon__ct((TItemWeapon *)((u8 *)arg0), (void *)parent, (u8 *)item);
    *(void **)((s8 *)arg0 + 0x18) = lbl_804A5C18;
    ((TObjPlayer *)arg0)->set_status_flags(2);
    *(void **)((s8 *)arg0 + 0x1F0) = (void *)create_gun_shot;
    *(void **)((s8 *)arg0 + 0x1EC) = (void *)spawn_weapon_impact_effect;
    *(f32 *)((s8 *)arg0 + 0x1E4) = (f32) 15.0f;
    ((TUnk_804A5C18 *)arg0)->m_220 = 0x2000;
    *(f32 *)((s8 *)arg0 + 0x224) = (f32) 0.0f;
    ((TUnk_804A5C18 *)arg0)->m_214 = -1;
    *(s32 *)((s8 *)arg0 + 0x218) = -1;
    ((TUnk_804A5C18 *)arg0)->m_220 = -1;
    switch ((s32) (*(u8 *)((s8 *)item + 2))) {
    case 5:
        *(s32 *)((s8 *)arg0 + 0x1F8) = 9;
        ((TUnk_804A5C18 *)arg0)->m_1fc = 4;
        *(s32 *)((s8 *)arg0 + 0x200) = 8;
        ((TUnk_804A5C18 *)arg0)->m_204 = 3;
        *(s32 *)((s8 *)arg0 + 0x208) = 7;
        ((TUnk_804A5C18 *)arg0)->m_20c = 1;
        *(s32 *)((s8 *)arg0 + 0x210) = 5;
        break;
    case 6:
        *(s32 *)((s8 *)arg0 + 0x1F8) = 0xA;
        ((TUnk_804A5C18 *)arg0)->m_1fc = 8;
        *(s32 *)((s8 *)arg0 + 0x200) = 4;
        ((TUnk_804A5C18 *)arg0)->m_204 = 7;
        *(s32 *)((s8 *)arg0 + 0x208) = 3;
        ((TUnk_804A5C18 *)arg0)->m_20c = 5;
        *(s32 *)((s8 *)arg0 + 0x210) = 1;
        ((TUnk_804A5C18 *)arg0)->m_21c = 9;
        break;
    case 7:
        *(s32 *)((s8 *)arg0 + 0x1F8) = 0x13;
        ((TUnk_804A5C18 *)arg0)->m_1fc = 0xE;
        *(s32 *)((s8 *)arg0 + 0x200) = 0xA;
        ((TUnk_804A5C18 *)arg0)->m_204 = 6;
        *(s32 *)((s8 *)arg0 + 0x208) = 2;
        ((TUnk_804A5C18 *)arg0)->m_20c = 3;
        *(s32 *)((s8 *)arg0 + 0x210) = 0xB;
        ((TUnk_804A5C18 *)arg0)->m_214 = 7;
        *(s32 *)((s8 *)arg0 + 0x218) = 0xF;
        ((TUnk_804A5C18 *)arg0)->m_21c = 1;
        break;
    default:
        *(s32 *)((s8 *)arg0 + 0x1F8) = 7;
        ((TUnk_804A5C18 *)arg0)->m_1fc = 3;
        *(s32 *)((s8 *)arg0 + 0x200) = 5;
        ((TUnk_804A5C18 *)arg0)->m_204 = 2;
        *(s32 *)((s8 *)arg0 + 0x208) = 6;
        ((TUnk_804A5C18 *)arg0)->m_20c = 1;
        *(s32 *)((s8 *)arg0 + 0x210) = 4;
        break;
    }
    if ((u8) *(u8 *)((s8 *)item + 2) >= 5U) {
        ((TObjPlayer *)arg0)->set_atp(-1);
    }
    return arg0;
}

u8 *create_shot_weapon(u8 *item) {
    u8 *temp_r3;
    u8 *var_r0;
    if (item != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x22C));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(construct_shot_weapon(temp_r3, tl_05, item));
        }
        return var_r0;
    }
    return NULL;
}

void *__dt__13TUnk_804A5C18Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = (s32 *)lbl_804A5C18;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}
