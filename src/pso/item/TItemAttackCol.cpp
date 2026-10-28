#include "types.h"
#include "pso/system/FlagWord.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/item/TItem.h"
#include "pso/item/TUnk_804E355C.h"

#include <stddef.h>
#include "pso/item/TItemAttackCol.h"
#include "pso/TParticleCtrl.h"
#include "pso/item/TItemProShield.h"
#include "pso/misc/TNowLoading.h"
#include "pso/player/TObjPlayer.h"
struct VBase_18_f2ea1e { char pad[0x18]; };

struct VObj_18_f2ea1e : VBase_18_f2ea1e {
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
    virtual s32 m19(void *, s32, s32, f32);
    virtual f32 m20(void *, f32);
    virtual void m21();
    virtual s32 m22(void *, s32);
    virtual s32 m23(void *, f32);
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
    virtual void m63();
    virtual void m64();
    virtual void m65();
    virtual void m66();
    virtual void m67();
    virtual void m68();
    virtual void m69();
    virtual void m70();
    virtual void m71();
    virtual void m72();
    virtual s32 m73();
};

struct Stack_802E456C {
    u8 sp8;
    u8 sp9;
    u8 pad_A[0x2];
    u8 * spC;
    u8 pad_10[0x4];
    u8 * sp14;
    s32 sp18;
};

typedef struct S_802E451C {
    f32 f0, f4, f8, fC;
    s32 f10;
    u16 f14;
    s16 f16;
    s32 f18;
    f32 f1C, f20;
    s32 f24;
} S_802E451C;

struct VBase_802E3C4C { char pad[0x18]; };
struct VObj_802E3C4C : VBase_802E3C4C {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27();
    virtual void m28(); virtual void m29(); virtual void m30(); virtual void m31();
    virtual void m32(); virtual void m33(); virtual void m34(); virtual void m35();
    virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39();
    virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43();
    virtual void m44(); virtual void m45(); virtual void m46(); virtual void m47();
    virtual void m48(); virtual void m49(); virtual void m50(); virtual void m51();
    virtual void m52(); virtual void m53(); virtual void m54(); virtual void m55();
    virtual void m56(); virtual void m57(); virtual void m58();
    virtual void m59(u8 *, s32, s32, f32, s32);
};

typedef void (*Cb_802E3C4C)(s32, s32 *, void *);
struct Obj_802E3C4C {
    u8 pad0[0xA8];
    u16 fA8;
    u8 padAA[2];
    s32 fAC;
    u8 padB0[4];
    f32 fB4;
    s32 fB8;
    u8 padBC[0xD0 - 0xBC];
    u8 fD0[0xE4 - 0xD0];
    s32 fE4;
    u8 padE8[0x13C - 0xE8];
    Cb_802E3C4C cb;
};

struct Hit_802E3D8C { s32 pad; void *pos; };

extern "C" {
s32 disallow_rendering__7TObjectFv(void *);
s32 test_flags_any(void *, int);
s32 copy_position__15TEffStarLight2DFPv(int, void *);
}
f32 vec_distance_squared(u8 *arg0, u8 *arg1);
extern "C" {
s32 has_game_join_id__13TUnk_804E355CFv(void *);
s32 play_weapon_hit_sound(void *);
void apply_camera_shake__10TObjPlayerFiii(s32 arg0, s32 arg1, s32 arg2);
void *get_player_by_client_id(s32 i);
extern const f32 lbl_805DE914;
extern const f32 lbl_805DE928;
extern const float lbl_805DE918;
extern const f32 lbl_805DE924;
void TObjPlayer__sub_802E451C(S_802E451C *arg0);
Hit_802E3D8C *csnVector(void *, void *, s32);
extern const f32 lbl_805DE910;
s32 all_parents_unqueued_for_destruction__7TObjectFv();
s32 rotate_matrix_by_node_angles(void *, int);
s32 push_matrix();
s32 scale_current_matrix(void *);
s32 post_translate_matrix(void *);
extern int attack_collider_render_owner;
extern int attack_collider_active_count;
void TItemAttackCol__vt5(s32 arg0);
void* TObjPlayer__sub_802E449C(void* a0);
void *__dt__14TItemAttackColFv(TItemAttackCol *arg0, s16 arg1);
s32 vec3_add_to(s32 *, s32);
void *TItemAttackCol__ct(void *, void *, void *);
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);
int fn_802E3BA8(void*, void*);

void TItemAttackCol::add_to_active_list(void* a0) { fn_802E3BA8((void*)attack_collider_render_owner, a0); attack_collider_active_count = (attack_collider_active_count + 0x1); }

void TItemAttackCol::shift_collision_bounds() {
    *(s32 *)&this->_pad104 = (s32) (*(s32 *)&this->_pad104 + 0xCCC);
    this->m_11c = (this->m_11c - 0xCCC);
}

void TItemAttackCol::vfunc_6(s32 *a) {
    Obj_802E3C4C *o = (Obj_802E3C4C *)this;
    if (!(this->m_e4 & 0x80)) {
        if (((TUnk_804E355C *)o)->resolve_attack_col_hit((u8 *)a) != 0) {
            if (o->cb != NULL) {
                o->cb(this->m_ac, a, o->fD0);
            }
            if (this->m_e4 & 0x100) {
                this->m_b4 = this->m_b4 * lbl_805DE910;
            }
        }
    } else {
        if (o->cb != NULL) {
            o->cb(this->m_ac, a, o->fD0);
        }
        if (this->m_e4 & 0x200) {
            VObj_802E3C4C *p = (VObj_802E3C4C *)find_item_by_id(this->m_ac);
            u8 *b = (u8 *)get_player_by_client_id(this->m_a8);
            if (p != NULL) {
                p->m59(b, a[0], o->fB8, this->m_b4, a[1]);
            }
        }
    }
}

void TItemAttackCol__vt5(s32 arg0) {
    s32 sp8;

    VecCopy((Vec *)&sp8, (const Vec *)(arg0 + 0xD0));
    vec3_add_to(&sp8, arg0 + 0x24);
    ((TItemAttackCol *)arg0)->move_with_collision(&sp8);
}

extern s32 __vt__14TItemAttackCol[];

typedef void (*Cb_802E3D8C)(s32, void *, void *);
void TItemAttackCol::move_with_collision(void *arg1) {
    u8 *arg0 = (u8 *)this;
    Hit_802E3D8C *hit;
    Cb_802E3D8C cb;
    hit = csnVector((u8 *)&this->m_24, arg1, 0x8100);
    if (hit != NULL) {
        ((FlagWord *)(arg0 + 0xE0))->set(1);
        VecCopy((Vec *)(arg0 + 0x24), (const Vec *)(hit->pos));
        cb = *(Cb_802E3D8C *)((s8 *)arg0 + 0x138);
        if (cb != NULL) {
            cb(this->m_ac, (u8 *)&this->m_24, (u8 *)&this->m_d0);
        }
    } else {
        VecCopy((Vec *)(arg0 + 0x24), (const Vec *)(arg1));
    }
}

void TItemAttackCol::render() {
    u8 *arg0 = (u8 *)this;
    if (all_parents_unqueued_for_destruction__7TObjectFv() == 0 || find_equipped_item(this->m_ac) == 0U) {
        return;
    }
    {
        if ((u32) this->m_e8 != 0U) {
            if ((u32) this->m_ec != 0U) {
                TObjPlayer::notify_fish_if_valid(this->m_ec);
            }
            TParticleCtrl::begin_effect_render();
            attack_collider_render_owner = (int)arg0;
            attack_collider_active_count = 0;
            push_matrix();
            post_translate_matrix((u8 *)&this->m_24);
            rotate_matrix_by_node_angles((u8 *)&this->m_f0, 1);
            rotate_matrix_by_node_angles((u8 *)&this->m_fc, 1);
            scale_current_matrix((u8 *)&this->m_108);
            draw_node_tree_with_callback((NJS_OBJECT *)this->m_e8, (void (*)(NJS_OBJECT *))TItemAttackCol::add_to_active_list);
            pop_matrix();
            attack_collider_render_owner = 0;
            TParticleCtrl::end_effect_render();
        }
    }
}

void TItemAttackCol::run_task() {
    u8 *arg0 = (u8 *)this;
    u32 temp_r3;
    u32 temp_r3_2;
    u32 temp_r3_3;
    u32 temp_r3_4;
    if (has_game_join_id__13TUnk_804E355CFv(arg0) == 0) {
        queue_destruction__7TObjectFv(arg0);
        disallow_rendering__7TObjectFv(arg0);
        return;
    }
    if (this->m_e4 & 4) {
        shift_collision_bounds();
    }
    if (this->m_e4 & 0x20) {
        this->m_100 = (this->m_100 + 0x888);
    }
    this->vfunc_7();
    temp_r3 = this->m_12c;
    if (temp_r3 != 0U) {
        copy_position__15TEffStarLight2DFPv(temp_r3, (u8 *)&this->m_24);
    }
    temp_r3_2 = this->m_130;
    if (temp_r3_2 != 0U) {
        ((TNowLoading *)temp_r3_2)->copy_pos((u8 *)&this->m_24);
    }
    temp_r3_3 = this->m_134;
    if (temp_r3_3 != 0U) {
        ((TNowLoading *)temp_r3_3)->copy_pos((u8 *)&this->m_24);
    }
    temp_r3_4 = this->m_140;
    if (temp_r3_4 != 0U) {
        ((TNowLoading *)temp_r3_4)->copy_pos((u8 *)&this->m_24);
    }
    ((TUnk_804E355C *)arg0)->check_hits();
    if ((this->m_dc <= vec_distance_squared((u8 *)&this->m_24, (u8 *)&this->m_c4)) || (test_flags_any((u8 *)&this->m_e0, 1) != 0)) {
        queue_destruction__7TObjectFv(arg0);
    }
}

void *__dt__14TItemAttackColFv(TItemAttackCol *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__14TItemAttackCol;
        if (*(void **)((s8 *)arg0 + 0x12C) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x12C)); arg0->m_12c = 0; }
        if (*(void **)((s8 *)arg0 + 0x130) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x130)); arg0->m_130 = 0; }
        if (*(void **)((s8 *)arg0 + 0x134) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x134)); arg0->m_134 = 0; }
        if (*(void **)((s8 *)arg0 + 0x140) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x140)); arg0->m_140 = 0; }
        ((TUnk_804E355C *)arg0)->destroy_attack_collision(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

void TItemAttackCol::create(void *arg0, void *arg1) {
    void *o;
    o = __nw__7TObjectFUl(0x144);
    if (o != NULL) {
        TItemAttackCol__ct(o, arg0, arg1);
    }
}

    extern const float lbl_805DE920;
void* TObjPlayer__sub_802E449C(void* a0) { TObjPlayer__sub_802E451C((S_802E451C *)(a0)); *(int*)((char*)a0 + 0x40) = 0; *(int*)((char*)a0 + 0x44) = 0; *(int*)((char*)a0 + 0x48) = 0; *(float*)((char*)a0 + 0x4c) = lbl_805DE918; *(int*)((char*)a0 + 0x50) = 0; *(int*)((char*)a0 + 0x54) = 0; *(int*)((char*)a0 + 0x58) = 0; *(float*)((char*)a0 + 0x5c) = lbl_805DE920; *(float*)((char*)a0 + 0x60) = lbl_805DE918; *(float*)((char*)a0 + 0x64) = lbl_805DE918; *(float*)((char*)a0 + 0x68) = lbl_805DE918; *(float*)((char*)a0 + 0x6c) = lbl_805DE918; *(int*)((char*)a0 + 0x70) = 0; *(int*)((char*)a0 + 0x74) = 0; *(int*)((char*)a0 + 0x78) = -1; *(int*)((char*)a0 + 0x7c) = -1; return a0; }

void TObjPlayer__sub_802E451C(S_802E451C *arg0) {
    arg0->f0 = lbl_805DE914;
    arg0->f4 = lbl_805DE914;
    arg0->f8 = lbl_805DE914;
    arg0->fC = lbl_805DE924;
    arg0->f10 = 1;
    arg0->f14 = 0xFFFF;
    arg0->f16 = -1;
    arg0->f18 = -1;
    arg0->f1C = lbl_805DE914;
    arg0->f20 = (*(const f32 *)&lbl_805DE918);
    arg0->f24 = 0;
}

s32 TUnk_804E355C::resolve_attack_col_hit(u8 *arg1) {
    u8 *arg0 = (u8 *)this;
    typedef char sp8_offset[(offsetof(Stack_802E456C, sp8) == 0x0) ? 1 : -1];
    typedef char sp9_offset[(offsetof(Stack_802E456C, sp9) == 0x1) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_802E456C, spC) == 0x4) ? 1 : -1];
    typedef char sp14_offset[(offsetof(Stack_802E456C, sp14) == 0xC) ? 1 : -1];
    typedef char sp18_offset[(offsetof(Stack_802E456C, sp18) == 0x10) ? 1 : -1];
    Stack_802E456C stack;
    s32 temp_r31;
    s32 temp_r31_2;
    u8 *temp_r30;
    u8 *player;
    u32 item;
    s32 temp_r0;
    f32 var_f31;
    temp_r30 = (u8 *)(*(u8 **)((s8 *)arg1 + 0));
    player = (u8 *)(get_player_by_client_id(this->m_a8));
    item = (u32)find_item_by_id((this->m_ac));
    temp_r31 = *(s32 *)((s8 *)(*(u8 **)((s8 *)arg1 + 0)) + 0xA4) + (*(s32 *)((s8 *)arg1 + 4) * 0x2C);
    if ((player != NULL) && (item != 0U) && (((VObj_18_f2ea1e *)(temp_r30))->m19(player, temp_r31, 0, *(f32 *)((s8 *)arg0 + 0xB0)) != 0)) {
        temp_r0 = *(s32 *)((s8 *)arg0 + 0xB8);
        var_f31 = lbl_805DE914;
        switch (temp_r0) {
        case 0:
            var_f31 = ((VObj_18_f2ea1e *)(temp_r30))->m20(player, this->m_b4);
            break;
        case 1:
            var_f31 = ((VObj_18_f2ea1e *)(temp_r30))->m20(player, this->m_b4);
            ((VObj_18_f2ea1e *)(temp_r30))->m23(player, lbl_805DE928 * var_f31);
            break;
        case 2:
            ((VObj_18_f2ea1e *)(temp_r30))->m22(player, temp_r31);
            break;
        }
        temp_r31_2 = (s32) var_f31;
        TObjPlayer::calc_photon_blast_charge((void *)player, temp_r31_2);
        ((VObj_18_f2ea1e *)(player))->m73();
        apply_camera_shake__10TObjPlayerFiii((s32)player, (s32)temp_r30, (s32)temp_r31_2);
        ((TObjPlayer *)(&stack.sp8))->reset_status_block();
        stack.sp8 = ((TItem *)item)->get_item_group();
        stack.sp9 = ((TItem *)item)->get_item_index();
        stack.spC = player;
        stack.sp14 = temp_r30;
        stack.sp18 = *(s32 *)((s8 *)arg1 + 4);
        play_weapon_hit_sound(&stack.sp8);
        return 1;
    }
    return 0;
}
}
