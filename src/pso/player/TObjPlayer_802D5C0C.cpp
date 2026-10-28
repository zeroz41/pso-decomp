#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/item/TItem.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/player/TUnk_804E23F0.h"
#include "pso/items/TItemWeapon.h"
#include "pso/player/TObjPlayer.h"

namespace P802D5C0C {

struct VBase_18 { char pad[0x18]; };
struct VObj_18 : VBase_18 {
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
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual void m56();
    virtual void m57();
    virtual void m58();
    virtual void m59();
    virtual s32 m60(s32 *);
    virtual void m61();
    virtual void m62();
    virtual s32 m63(s32, s32 *);
};

#include <stddef.h>
struct VBase_18_f1aa6a { char pad[0x18]; };

struct VObj_18_f1aa6a : VBase_18_f1aa6a {
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
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual void m56();
    virtual void m57();
    virtual void m58();
    virtual void m59();
    virtual void m60();
    virtual void m61();
    virtual void m62();
    virtual s32 m63(s32, s32 *);
};

struct Stack_80362FB4 {
    s32 sp8;
    s32 spC;
    s32 sp10;
};

struct RecoveredGlobal_80362FB4_lbl_80479FC8 {
    s32 value;
    u8 remaining[0xC];
};

extern "C" {
s16 get_validated_attack_stage(u8 *arg0);
void fire_spread_shot__10TObjPlayerFPv(u8 *arg0);
s32 draw_weapon_model__11TItemWeaponFv(TItemWeapon *);
void draw_weapon_if_not_hidden__10TObjPlayerFPv(u8 *arg0);
s32 rotate_matrix_x(int, int);
s32 push_matrix();
s32 pop_matrix();
f32 post_translate_matrix(void *);
extern RecoveredGlobal_80362FB4_lbl_80479FC8 lbl_80472590;
void TObjPlayer__sub_802D5DE0(u8 *arg0);
void create_cane_effect_from_state__10TObjPlayerFPv(void *arg0);
void* init_state_445__10TObjPlayerFPv(void* a0);
void set_radar_marker_params__10TObjPlayerFPvPv(u8 *arg0, u8 *arg1);
void update_swim_flag__10TObjPlayerFPv(void *arg0);
s32 get_attack_stage__11TItemWeaponFv();
s32 get_weapon_color__11TItemWeaponFPv(s32 *, void *);
int TItemWeapon__ct(void);
int set_status_flags__10TObjPlayerFUl(void*, void*);

void set_radar_marker_params__10TObjPlayerFPvPv(u8 *weapon, u8 *arg1) {
    s32 sp8;

    *(f32 *)((s8 *)arg1 + 0x4C) = (f32) *(f32 *)((s8 *)weapon + 0x200);
    *(s32 *)((s8 *)arg1 + 0x58) = 0xC000;
    *(s32 *)((s8 *)arg1 + 0x40) = (s32) (*(s32 *)((s8 *)arg1 + 0x40) | 2);
    get_weapon_color__11TItemWeaponFPv(&sp8, weapon);
    copy_argb((NJS_ARGB *)(arg1 + 0x60), (NJS_ARGB *)&sp8);
    *(s32 *)((s8 *)arg1 + 0x74) = (s32) *(s32 *)((s8 *)weapon + 0x208);
    *(s32 *)((s8 *)arg1 + 0x70) = (s32) *(s32 *)((s8 *)weapon + 0x204);
}

void update_swim_flag__10TObjPlayerFPv(void *arg0) {
    if (get_attack_stage__11TItemWeaponFv() == 2) {
        *(s32 *)((s8 *)arg0 + 0x1F8) = (s32) (*(s32 *)((s8 *)arg0 + 0x1F8) | 1);
        return;
    }
    *(s32 *)((s8 *)arg0 + 0x1F8) = (s32) (*(s32 *)((s8 *)arg0 + 0x1F8) & 0xFFFFFFFE);
}

extern s32 tl_05;

void create_cane_effect_from_state__10TObjPlayerFPv(void *item) {
    if (get_attack_stage__11TItemWeaponFv() == 0) {
        ((TObjPlayer *)tl_05)->create_item_eff_cane((TItem*)item, -1, (s32)(((TUnk_804E23F0 *)item)->m_1fc));
    }
}

    extern unsigned char TObjPlayer__sub_8032E648[];
    extern unsigned char create_network_object__10TObjPlayerFlPUll[];
    extern unsigned char lbl_804E23F0[];
    extern const float lbl_805DE7A0;

void fire_spread_shot__10TObjPlayerFPv(u8 *arg0) {
    s32 sp8;
    ((VObj_18 *)(((TUnk_804E23F0 *)arg0)->player))->m63(0x30, &sp8);
    if (get_validated_attack_stage((*(u8 * *)&((TUnk_804E23F0 *)arg0)->player + 0x7CC)) == 2) {
        ((TItemWeapon *)arg0)->fire_shot_at_target((void *)(&sp8), (void *)(*(s32 *)((s8 *)arg0 + 0xF4)), 0);
        ((TItemWeapon *)arg0)->fire_shot_at_target((void *)(&sp8), (void *)(*(s32 *)((s8 *)arg0 + 0xF4)), 0x1555);
        ((TItemWeapon *)arg0)->fire_shot_at_target((void *)(&sp8), (void *)(*(s32 *)((s8 *)arg0 + 0xF4)), -0x1555);
    } else {
        ((TItemWeapon *)arg0)->fire_shot_at_target((void *)(&sp8), (void *)(*(s32 *)((s8 *)arg0 + 0xF4)), 0);
    }
    ((VObj_18 *)(arg0))->m60(&sp8);
}

typedef char RecoveredGlobal_80362FB4_lbl_80479FC8_size[sizeof(RecoveredGlobal_80362FB4_lbl_80479FC8) == 0x10 ? 1 : -1];
void TObjPlayer__sub_802D5DE0(u8 *item_weapon) {
    typedef char sp8_offset[(offsetof(Stack_80362FB4, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_80362FB4, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_80362FB4, sp10) == 0x8) ? 1 : -1];
    Stack_80362FB4 stack;
    if (TObjPlayer::get_player_list() == 0) {
        stack.sp8 = *(s32 *)((s8 *)&lbl_80472590.value + 0);
        stack.spC = *(s32 *)((s8 *)&lbl_80472590.value + 4);
        stack.sp10 = *(s32 *)((s8 *)&lbl_80472590.value + 8);
        post_translate_matrix((void *)&stack.sp8);
        rotate_matrix_x(0, 0x18E3);
        if (*(s32 *)((s8 *)item_weapon + 0x1f8) & 1) {
            push_matrix();
            rotate_matrix_x(0, 0x2AAA);
            ((TItem *)item_weapon)->draw_model();
            pop_matrix();
            push_matrix();
            rotate_matrix_x(0, -0x2AAA);
            ((TItem *)item_weapon)->draw_model();
            pop_matrix();
        }
    }
}

void draw_weapon_if_not_hidden__10TObjPlayerFPv(u8 *item_weapon) {
    if (((TItemWeapon *)item_weapon)->test_flags_1b8(0x01000000U) == 0U) {
        draw_weapon_model__11TItemWeaponFv((TItemWeapon *)item_weapon);
    }
}

void* init_state_445__10TObjPlayerFPv(void* a0) { TItemWeapon__ct(); *(int*)((char*)a0 + 0x18) = (int)lbl_804E23F0; set_status_flags__10TObjPlayerFUl(a0, (void*)3); *(int*)((char*)a0 + 0x1f8) = 0; ((TUnk_804E23F0 *)a0)->m_1fc = 445; *(int*)((char*)a0 + 0x204) = (int)TObjPlayer__sub_8032E648; *(int*)((char*)a0 + 0x208) = (int)create_network_object__10TObjPlayerFlPUll; *(float*)((char*)a0 + 0x200) = lbl_805DE7A0; return a0; }

}

}
