#include "types.h"
#include "pso/player/TObjPlayer_8012981C.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80128A70.h"
#include "pso/unk/text_80087278.h"
#include "pso/player/TUnk_804A444C.h"
#include "pso/player/TObjPlayer_801299DC.h"
#include "pso/unk/text_80129AB0.h"
#include "pso/item/TItemEquipVariant_80129B08.h"
#include "pso/item/TItemEquipVariant_8012A82C.h"
#include "pso/item/TItem.h"

extern "C" {

s32 rotate_matrix_z(s32, s32);
}

void s_rank_shot_turn_barrels(void *arg0) {
    if (TObjPlayer::get_player_list() == 1) {
        rotate_matrix_z(0, *(s32 *)((s8 *)arg0 + 0x200));
    }
    if (TObjPlayer::get_player_list() == 4) {
        rotate_matrix_z(0, -*(s32 *)((s8 *)arg0 + 0x200));
    }
}

struct VBase_18_8622c5 { char pad[0x18]; };

struct VObj_18_8622c5 : VBase_18_8622c5 {
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

struct RecoveredGlobal_80129878_lbl_804A4438 {
    s32 value;
    u8 remaining[0x10];
};

extern "C" {
extern RecoveredGlobal_80129878_lbl_804A4438 s_rank_shot_marker_offsets;
typedef char RecoveredGlobal_80129878_lbl_804A4438_size[sizeof(RecoveredGlobal_80129878_lbl_804A4438) == 0x14 ? 1 : -1];
void TUnk_804A444C::emit_marker_effects() {
    u8 *arg0 = (u8 *)this;
    s32 sp8;
    TObjPlayer__sub_80128A70();
    ((TItemWeapon *)arg0)->get_joint_position(7, (void *)&sp8);
    spawn_particle_effect((&sp8), 9);
    ((VObj_18_8622c5 *)(arg0))->m49(&sp8, 0, *(s32 *)((s8 *)&s_rank_shot_marker_offsets.value + 0), 1);
    ((TItemWeapon *)arg0)->get_joint_position(3, (void *)&sp8);
    ((VObj_18_8622c5 *)(arg0))->m49(&sp8, 1, *(s32 *)((s8 *)&s_rank_shot_marker_offsets.value + 4), 1);
    ((TItemWeapon *)arg0)->get_joint_position(5, (void *)&sp8);
    ((VObj_18_8622c5 *)(arg0))->m49(&sp8, 2, *(s32 *)((s8 *)&s_rank_shot_marker_offsets.value + 8), 1);
    ((TItemWeapon *)arg0)->get_joint_position(2, (void *)&sp8);
    ((VObj_18_8622c5 *)(arg0))->m49(&sp8, 3, *(s32 *)((s8 *)&s_rank_shot_marker_offsets.value + 0xC), 1);
    ((TItemWeapon *)arg0)->get_joint_position(6, (void *)&sp8);
    ((VObj_18_8622c5 *)(arg0))->m49(&sp8, 4, *(s32 *)((s8 *)&s_rank_shot_marker_offsets.value + 0x10), 1);
}

}

extern "C" {

int construct_srank_weapon(void);

void TUnk_804A444C::update_idle() {
    u8 *arg0 = (u8 *)this;
    if ((s32) *(s32 *)((s8 *)arg0 + 0x200) < 0x2000) {
        TObjPlayer::add_angle_clamped((s32 *)(arg0 + 0x200), 0x2D8, 0x2000);
    }
}

void TUnk_804A444C::update_attack() {
    u8 *arg0 = (u8 *)this;
    if ((s32) *(s32 *)((s8 *)arg0 + 0x200) > 0) {
        TObjPlayer::add_angle_clamped((s32 *)(arg0 + 0x200), -0x2000, 0);
    }
}

    extern unsigned char create_gun_shot[];
    extern s32 s_rank_shot_weapon_vtable[];
void *init_s_rank_shot(void *a0, s32 parent, s32 item) { construct_srank_weapon(); *(int*)((char*)a0 + 0x18) = (int)s_rank_shot_weapon_vtable; *(int*)((char*)a0 + 0x200) = 8192; ((TItemWeapon *)a0)->set_weapon_flags(2); *(int*)((char*)a0 + 0x1f0) = (int)create_gun_shot; *(float*)((char*)a0 + 0x1e4) = 15.0f; return a0; }

}

extern "C" {
u8 *__nw__5TItemFUl(s32);
}
extern s32 tl_05;
u8 *create_s_rank_shot(s32 arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != 0) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x204));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(init_s_rank_shot(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}

extern s32 s_rank_shot_weapon_vtable[];

void *__dt__13TUnk_804A444CFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = s_rank_shot_weapon_vtable;
        __dt__13TUnk_804A4948Fv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}
