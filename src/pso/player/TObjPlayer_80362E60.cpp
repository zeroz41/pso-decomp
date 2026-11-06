#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TObjPlayer.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/weapon/TUnk_804F27E0.h"

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

#include <stddef.h>
#include "pso/item/TItem.h"
#include "pso/system/NinjaTypes.h"
#include "pso/player/TObjPlayer_8032E4C8.h"

extern "C" void get_weapon_color__11TItemWeaponFPv(void *, void *);

void TUnk_804F27E0::init_weapon_effect_descriptor(Desc_8011E5C4 *desc) {
    u8 sp8[16];
    desc->pad_4c = 5.0f;
    desc->pad_58 = 0xC000;
    desc->flags |= 0x282;
    get_weapon_color__11TItemWeaponFPv(sp8, this);
    copy_argb((NJS_ARGB *)desc->color, (NJS_ARGB *)sp8);
    desc->pad_74 = (void *)TObjPlayer::create_network_object;
    desc->pad_70 = (void *)TObjPlayer__sub_8032E648;
}
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
u8 *__nw__5TItemFUl(s32);
u8 *TObjPlayer__sub_803630F0(u8 *arg0);
s32 rotate_matrix_x(int, int);
s32 push_matrix();
s32 pop_matrix();
f32 post_translate_matrix(void *);
extern RecoveredGlobal_80362FB4_lbl_80479FC8 lbl_80479FC8;

void TUnk_804F27E0::update_weapon() {
    if (((TItemWeapon *)this)->get_attack_stage() == 2) {
        (*(s32 *)((u8 *)this + 0x1FC)) = (s32) ((*(s32 *)((u8 *)this + 0x1FC)) | 1);
        return;
    }
    (*(s32 *)((u8 *)this + 0x1FC)) = (s32) ((*(s32 *)((u8 *)this + 0x1FC)) & 0xFFFFFFFE);
}

void TObjPlayer::create_cane_if_ready(s32 arg0, void *position) {
    if (((TItemWeapon *)arg0)->get_attack_stage() == 0) {
        ((TObjPlayer *)tl_05)->create_item_eff_cane((TItem*)arg0, -1, 0x1BD);
    }
}


void TUnk_804F27E0::emit_marker_effects() {
    u8 *arg0 = (u8 *)this;
    s32 sp8;
    ((VObj_18_f1aa6a *)(this->owner))->m63(0x30, &sp8);
    if (get_validated_attack_stage(*(u8 * *)&this->owner + 0x7CC) == 2) {
        ((TItemWeapon *)arg0)->fire_shot_at_target((void *)(&sp8), (void *)(*(s32 *)((s8 *)arg0 + 0xF4)), 0);
        ((TItemWeapon *)arg0)->fire_shot_at_target((void *)(&sp8), (void *)(*(s32 *)((s8 *)arg0 + 0xF4)), 0x1555);
        ((TItemWeapon *)arg0)->fire_shot_at_target((void *)(&sp8), (void *)(*(s32 *)((s8 *)arg0 + 0xF4)), -0x1555);
    } else {
        ((TItemWeapon *)arg0)->fire_shot_at_target((void *)(&sp8), (void *)(*(s32 *)((s8 *)arg0 + 0xF4)), 0);
    }
    TObjPlayer::create_cane_if_ready((s32)arg0, (void *)((void *)&sp8));
}

typedef char RecoveredGlobal_80362FB4_lbl_80479FC8_size[sizeof(RecoveredGlobal_80362FB4_lbl_80479FC8) == 0x10 ? 1 : -1];
void TUnk_804F27E0::vfunc_60() {
    typedef char sp8_offset[(offsetof(Stack_80362FB4, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_80362FB4, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_80362FB4, sp10) == 0x8) ? 1 : -1];
    Stack_80362FB4 stack;
    if (TObjPlayer::get_player_list() == 0) {
        stack.sp8 = *(s32 *)((s8 *)&lbl_80479FC8.value + 0);
        stack.spC = *(s32 *)((s8 *)&lbl_80479FC8.value + 4);
        stack.sp10 = *(s32 *)((s8 *)&lbl_80479FC8.value + 8);
        post_translate_matrix((void *)&stack.sp8);
        rotate_matrix_x(0, 0x18E3);
        if (*(s32 *)((s8 *)((u8 *)this) + 0x1FC) & 1) {
            push_matrix();
            rotate_matrix_x(0, 0x2AAA);
            ((TItem *)((u8 *)this))->draw_model();
            pop_matrix();
            push_matrix();
            rotate_matrix_x(0, -0x2AAA);
            ((TItem *)((u8 *)this))->draw_model();
            pop_matrix();
        }
    }
}

void TUnk_804F27E0::reserved_53() {
    u8 *arg0 = (u8 *)this;
    if (((TItemWeapon *)arg0)->test_weapon_flags(0x01000000U) == 0U) {
        ((TItemWeapon *)arg0)->draw_weapon_model();
    }
}

TUnk_804F27E0::TUnk_804F27E0(TObject *parent, u8 *item) : TUnk_804A4948(parent, item) {
    set_weapon_flags(3);
    pad_1fc = 0;
}
u8 *TObjPlayer__sub_803630F0(u8 *arg0) {
    if (arg0 != NULL) {
        return (u8 *)new TUnk_804F27E0(tl_05, arg0);
    }
    return NULL;
}

TUnk_804F27E0::~TUnk_804F27E0() {}

}
