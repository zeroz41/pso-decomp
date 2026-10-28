#include "types.h"
#include "pso/player/TUnk_80494AE0.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/enemy/TObjEneMe3ShinowaReal.h"
#include "pso/system/vector.h"
#include "pso/TParticleCtrl.h"
#include "pso/enemy/TObjEneDD_ST.h"
#include "pso/enemy/TObjEneMe3ShinowaMirage.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/enemy/TObjEneMe3Shinowa.h"

struct Base_800e3a88_800E3A58 { char pad[0x14]; };
struct VObj_800e3a88_800E3A58 : Base_800e3a88_800E3A58 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
};
struct Base_800E3B34_800E3A58 { char pad[0x18]; };
struct VObj_800E3B34_800E3A58 : Base_800E3B34_800E3A58 {
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
    virtual void m73();
    virtual void m74();
    virtual void m75();
    virtual void m76();
    virtual void m77();
    virtual void m78();
    virtual void m79();
    virtual void m80();
    virtual void m81();
    virtual void m82();
    virtual void m83();
    virtual void m84();
    virtual void m85();
    virtual void m86();
    virtual void m87();
    virtual void m88();
    virtual void m89();
    virtual void m90();
    virtual void m91();
    virtual void m92();
};

struct VB14_800E3DFC { u8 pad[0x14]; };
struct Sub_800E3DFC : VB14_800E3DFC {
    virtual void v0();
    virtual void v1(s32, void *, f32);
    virtual void v2();
};
struct VB18_800E3DFC { u8 pad[0x18]; };
struct Self_800E3DFC : VB18_800E3DFC {
#define V(n) virtual void m##n();
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
    V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
    V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49)
    V(50) V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59)
    V(60) V(61) V(62) V(63) V(64) V(65) V(66) V(67) V(68) V(69)
    V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77) V(78) V(79)
    V(80) V(81) V(82) V(83) V(84)
#undef V
    virtual void m85(s16, s32);
};

#include <stddef.h>
#include "pso/misc/TNowLoading.h"
#include "pso/player/TObjPlayer.h"
struct VBase_14_85ec0b { char pad[0x14]; };

struct VObj_14_85ec0b : VBase_14_85ec0b {
    virtual void m0();
    virtual void m1();
    virtual s32 m2();
    virtual s32 m3();
    virtual s32 m4();
    virtual s32 m5();
};

struct Stack_800E3F8C {
    f32 sp8;
    f32 spC;
    f32 sp10;
};

struct VBase_800E420C { char pad[0x18]; };

struct VObj_800E420C : VBase_800E420C {
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
    virtual void m73();
    virtual void m74();
    virtual void m75();
    virtual void m76();
    virtual void m77();
    virtual void m78();
    virtual void m79();
    virtual void m80();
    virtual void m81();
    virtual void m82();
    virtual void m83();
    virtual void m84();
    virtual void m85();
    virtual void m86();
    virtual void m87();
    virtual void m88();
    virtual void m89();
    virtual void m90();
    virtual void m91();
    virtual void m92();
    virtual void m93();
    virtual void m94();
    virtual void m95();
    virtual void m96();
    virtual s32 m97();
    virtual void m98();
    virtual void m99();
    virtual void m100();
};

struct Vec_800E420C { f32 x, y, z; };

extern "C" {
int transition_enemy_state__9TObjEneDDFs(void*, int);
s32 draw_model__23TObjEneMe3ShinowaMirageFv();
s32 queue_destruction__7TObjectFv(void *);
void run_task__17TObjEneMe3ShinowaFv(u8 *arg0);
void *find_entity_by_id(u16 id);
s32 all_parents_unqueued_for_destruction__7TObjectFv();
s32 create_particle_emitter(s32, s32);
s32 advance_animation_playback(void *, int);
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
extern const f32 lbl_805DA5C8;
extern const f32 TObjEneMe3ShinowaReal__data_805DA5CC;
extern const f32 lbl_805DA5D0;
f32 calc_boss4_scale__10TObjPlayerFi(void *);
s32 enemy_clear_target__12TObjEneDD_STFUs(void *);
s32 transform_relative_position__9TObjEneDDFPv(void *, void *);
s32 is_player_entity_id(u16);
s32 copy_target_state__14TObjEnePanarmsFPv(void *, s32);
s32 play_sound_effect(s32, void *, int, int);
extern const f32 lbl_805DA5D4;
void *__dt__23TObjEneMe3ShinowaMirageFv(void *arg0, s16 arg1);
s32 enemy_set_target_id(void *, int);
u8 *TObjEneMe3ShinowaMirage__ct(u8 *, void *, u8 *, void *, void *);
s16 get_entity_id(void *);
s32 fn_800E762C(void *);
s32 TObjEneMe3Shinowa__ct(void *, void *);
extern s32 lbl_805D2AD0;
extern const f32 lbl_805DA5C0;
s32 TObjEneMe3ShinowaReal__sub_800E45CC(int, int);
void __dl__7TObjectFPv(void *);
void *__dt__17TObjEneMe3ShinowaFv(void *arg0, s16 arg1);
void *__nw__7TObjectFUl(int);

void TObjEneMe3ShinowaMirage::render() {
    u8 *arg0 = (u8 *)this;
    if (!(*(s32 *)((s8 *)arg0 + 0x3C4) & 0x100)) {
        draw_model__23TObjEneMe3ShinowaMirageFv();
    }
}

void TObjEneMe3ShinowaMirage::apply_effect_pair() {  }

void TObjEneMe3ShinowaMirage::dispatch_if_active() {
    s32 arg0 = (s32)this;

    ((VObj_800e3a88_800E3A58 *) ((unsigned char *) (arg0 + 0x3E8)))->m7();
}

extern s32 model_render_flags;

s32 TObjEneMe3ShinowaMirage::update_effect() {
    s32 arg0 = (s32)this;
    model_render_flags |= 0x820;
    set_constant_material((const NJS_ARGB *)((arg0 + 0x430)));
    set_chunk_material_override_pair(0xFF00, 0x800);
    return 0;
}

void TObjEneMe3ShinowaMirage::clear_mirage() {
    *(s32 *)((s8 *)this + 0x3C4) = (s32) (*(s32 *)((s8 *)this + 0x3C4) & 0xFFFFFEFF);
    this->vfunc_93();
}

void TObjEneMe3ShinowaMirage::set_flag_0x100() {
    struct VObj_800E3B34_800E3A58 *o = (struct VObj_800E3B34_800E3A58 *)this;
    *(s32 *)((s8 *)this + 0x3C4) = (s32) (*(s32 *)((s8 *)this + 0x3C4) | 0x100);
    o->m92();
}

int TObjEneMe3ShinowaMirage::init_mirage() { return transition_enemy_state__9TObjEneDDFs(this, 15); }

extern const f32 TObjEneMe3ShinowaMirage__data_805DA5B8;

void TObjEneMe3ShinowaMirage::activate_mirage(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    s32 entity;
    s32 temp_r4;
    s32 temp_r4_2;

    entity = (s32)find_entity_by_id((*(u16 *)((s8 *)arg0 + 0x42C)));
    if (entity != 0) {
        VecCopy((Vec *)(arg0 + 0x38), (const Vec *)(entity + 0x38));
        VecCopy((Vec *)(arg0 + 0x44), (const Vec *)(arg0 + 0x38));
        VecCopy((Vec *)(*(s32 *)&this->m_a4 + 0x1C), (const Vec *)(arg0 + 0x38));
        ((TObjPlayer *)(arg0 + 0x5C))->copy_xyz((void *)(entity + 0x5C));
        temp_r4 = this->actorFlags & 0xFFFFF7FF;
        this->actorFlags = temp_r4;
        this->actorFlags = 0x20000000;
        this->hp = (s16) this->hpmax;
        *(s32 *)((s8 *)arg0 + 0x3D4) = arg1;
        enemy_set_target_id(arg0, (int) (TObjEneMe3ShinowaReal__sub_800E45CC(entity, temp_r4)));
        *(f32 *)((s8 *)arg0 + 0x430) = (f32) TObjEneMe3ShinowaMirage__data_805DA5B8;
        temp_r4_2 = *(s32 *)((s8 *)arg0 + 0x3C4) & 0xFFFFFDFF;
        *(s32 *)((s8 *)arg0 + 0x3C4) = temp_r4_2;
        this->m_b8 = 0xA;
        advance_animation_playback(arg0, temp_r4_2);
        this->m_c0 = (f32) (u32) (*(s32 *)(this->unknownF8 + 4) - 1);
        transition_enemy_state__9TObjEneDDFs(arg0, 8);
        clear_mirage();
    }
}

void TObjEneMe3ShinowaMirage::update_player_state_default() {  }
void TObjEneMe3ShinowaMirage::vfunc_107() { transition_enemy_state__9TObjEneDDFs(this, 4); }
u8 TObjEneMe3ShinowaMirage::can_hit_same_target() { return 0; }
void TObjEneMe3ShinowaMirage::vfunc_105() {  }

void TObjEneMe3ShinowaMirage::vfunc_62() {
    if (this->mode != 15) {
        transition_enemy_state__9TObjEneDDFs(this, 15);
    }
    clear_attack_receipts();
}

extern s32 __vt__23TObjEneMe3ShinowaMirage[];

void TObjEneMe3ShinowaMirage::vfunc_63() {
    u8 *arg0 = (u8 *)this;
    if ((s16) this->mode != 0xF) {
        transition_enemy_state__9TObjEneDDFs(arg0, 0xF);
    }
}

void TObjEneMe3ShinowaMirage::run_task() {
    u8 *arg0 = (u8 *)this;
    if ((find_entity_by_id((*(u16 *)((s8 *)arg0 + 0x42C))) == 0U) || (all_parents_unqueued_for_destruction__7TObjectFv() == 0)) {
        queue_destruction__7TObjectFv(arg0);
        return;
    }
    if (!(*(s32 *)((s8 *)arg0 + 0x3C4) & 0x100)) {
        run_task__17TObjEneMe3ShinowaFv((arg0));
    }
}

void *__dt__23TObjEneMe3ShinowaMirageFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__23TObjEneMe3ShinowaMirage;
        __dt__17TObjEneMe3ShinowaFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

#define arg3 ((s16)(s32)a3)
#define arg4 ((s16)(s32)a4)
u8 *TObjEneMe3ShinowaMirage__ct(u8 *ene_me3_shinowa_mirage, void *ene_me3_shinowa, u8 *arg2, void *a3, void *a4) {
    u8 *temp_r5;

    TObjEneMe3Shinowa__ct(ene_me3_shinowa_mirage, ene_me3_shinowa);
    *(s32 **)((s8 *)ene_me3_shinowa_mirage + 0x18) = __vt__23TObjEneMe3ShinowaMirage;
    *(s32 *)((s8 *)ene_me3_shinowa_mirage + 0) = (s32) lbl_805D2AD0;
    *(s16 *)((s8 *)ene_me3_shinowa_mirage + 0x42C) = get_entity_id(arg2);
    ((TObjEneDD *)ene_me3_shinowa_mirage)->init_common_from((u8 *)arg2);
    *(f32 *)((s8 *)ene_me3_shinowa_mirage + 0x358) = (f32) *(f32 *)((s8 *)arg2 + 0x358);
    fn_800E762C(ene_me3_shinowa_mirage);
    ((TObjEneMe3ShinowaMirage *)ene_me3_shinowa_mirage)->entity_id = arg3;
    *(s16 *)((s8 *)ene_me3_shinowa_mirage + 0x2C) = arg4;
    ((TObjEneMe3Shinowa *)ene_me3_shinowa_mirage)->init_enemy();
    *(s32 *)((s8 *)ene_me3_shinowa_mirage + 0x3D4) = 0;
    *(s32 *)((s8 *)ene_me3_shinowa_mirage + 0x3C4) = (s32) (*(s32 *)((s8 *)ene_me3_shinowa_mirage + 0x3C4) | 0x1000);
    ((TObjEneMe3ShinowaMirage *)ene_me3_shinowa_mirage)->set_flag_0x100();
    *(s32 *)((s8 *)ene_me3_shinowa_mirage + 0x3D0) = 0xB000FFB0;
    *(f32 *)((s8 *)ene_me3_shinowa_mirage + 0x3C) = (f32) lbl_805DA5C0;
    *(f32 *)((s8 *)ene_me3_shinowa_mirage + 0x48) = (f32) lbl_805DA5C0;
    temp_r5 = (unsigned char *) (((TObjEneMe3ShinowaMirage *)ene_me3_shinowa_mirage)->m_a4);
    *(f32 *)((s8 *)temp_r5 + 0x20) = (f32) lbl_805DA5C0;
    ((TObjEneMe3ShinowaMirage *)ene_me3_shinowa_mirage)->actorFlags = (s32) (((TObjEneMe3ShinowaMirage *)ene_me3_shinowa_mirage)->actorFlags | 0x800);
    *(f32 *)((s8 *)ene_me3_shinowa_mirage + 0x430) = (f32) TObjEneMe3ShinowaMirage__data_805DA5B8;
    ((TObjEneMe3ShinowaMirage *)ene_me3_shinowa_mirage)->m_434 = (f32) TObjEneMe3ShinowaMirage__data_805DA5B8;
    *(f32 *)((s8 *)ene_me3_shinowa_mirage + 0x438) = (f32) TObjEneMe3ShinowaMirage__data_805DA5B8;
    ((TObjEneMe3ShinowaMirage *)ene_me3_shinowa_mirage)->m_43c = (f32) TObjEneMe3ShinowaMirage__data_805DA5B8;
    ((Sub_800E3DFC *)(ene_me3_shinowa_mirage + 0x3E8))->v1(0, temp_r5, lbl_805DA5C0);
    ((Sub_800E3DFC *)(ene_me3_shinowa_mirage + 0x3E8))->v2();
    ((TObjEneMe3ShinowaMirage *)ene_me3_shinowa_mirage)->mode = 8;
    ((Self_800E3DFC *)ene_me3_shinowa_mirage)->m85(((TObjEneMe3ShinowaMirage *)ene_me3_shinowa_mirage)->mode, 4);
    return ene_me3_shinowa_mirage;
}
#undef arg3
#undef arg4

extern void *tl_04;

void *TObjEneMe3ShinowaMirage::create(void *arg1, void *arg2) {
    void *o;
    o = __nw__7TObjectFUl(0x440);
    if (o != NULL) {
        o = TObjEneMe3ShinowaMirage__ct((u8 *)o, tl_04, (u8 *)this, arg1, arg2);
    }
    return o;
}
#pragma push
#pragma fp_contract on
void TObjEneMe3ShinowaReal::vfunc_116(s32 arg1) {
    typedef char sp8_offset[(offsetof(Stack_800E3F8C, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_800E3F8C, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_800E3F8C, sp10) == 0x8) ? 1 : -1];
    Stack_800E3F8C stack;
    s32 temp_r3;
    u8 *particle_ctrl;
    u8 *object;
    switch (arg1) {
    case 4:
        this->m_b8 = 7;
        this->set_field_378(0x10);
        this->vfunc_96();
        *(s32 *)((s8 *)((u8 *)this) + 0x3C4) = (s32) (*(s32 *)((s8 *)((u8 *)this) + 0x3C4) & 0xFFFFFFFD);
        *(s32 *)((s8 *)((u8 *)this) + 0x3C4) = (s32) (*(s32 *)((s8 *)((u8 *)this) + 0x3C4) | 1);
        *(s32 *)((s8 *)((u8 *)this) + 0x404) = 0;
        *(u8 **)((s8 *)((u8 *)this) + 0x424) = NULL;
        return;
    case 3:
        if ((s32) *(s32 *)((s8 *)((u8 *)this) + 0x404) == 3) {
            this->try_spawn_mirages();
            transition_enemy_state__9TObjEneDDFs((void*)this, 4);
        }
        return;
    case 0:
        switch (*(s32 *)((s8 *)((u8 *)this) + 0x404)) {
        case 0:
            advance_animation_playback((void *)this, arg1);
            if (this->get_flag_b4() != 0) {
                temp_r3 = *(s32 *)((s8 *)((u8 *)this) + 0x3C4);
                if (temp_r3 & 0x80000) {
                    ((VObj_14_85ec0b *)((u8 *)this + (1000)))->m3();
                    *(s32 *)((s8 *)((u8 *)this) + 0x404) = 1;
                } else {
                    *(s32 *)((s8 *)((u8 *)this) + 0x3C4) = (s32) (temp_r3 | 0x80000);
                    ((VObj_14_85ec0b *)((u8 *)this + (1000)))->m2();
                    *(s32 *)((s8 *)((u8 *)this) + 0x404) = 2;
                }
            }
            if (this->m_c0 >= lbl_805DA5C8) {
                if ((void *) *(u8 **)((s8 *)((u8 *)this) + 0x424) == NULL) {
                    *(u8 **)((s8 *)((u8 *)this) + 0x424) = (unsigned char *) (create_particle_emitter((s32) ((u8 *)this + 0x38), 0x114));
                    particle_ctrl = (u8 *)(*(u8 **)((s8 *)((u8 *)this) + 0x424));
                    if (particle_ctrl != NULL) {
                        ((TParticleCtrl *)particle_ctrl)->enable();
                    }
                } else {
                    VecCopy((Vec *)&stack.sp8, (const Vec *)((u8 *)this + 0x38));
                    stack.sp8 += TObjEneMe3ShinowaReal__data_805DA5CC * sin_table_lookup(this->rotation_y);
                    stack.spC += lbl_805DA5D0;
                    stack.sp10 += TObjEneMe3ShinowaReal__data_805DA5CC * cos_table_lookup(this->rotation_y);
                    ((TNowLoading *)(*(u8 **)((s8 *)((u8 *)this) + 0x424)))->copy_pos(&stack.sp8);
                }
            }
            break;
        case 1:
            if (((VObj_14_85ec0b *)((u8 *)this + (1000)))->m5() != 0) {
                *(s32 *)((s8 *)((u8 *)this) + 0x404) = 3;
                *(s32 *)((s8 *)((u8 *)this) + 0x3C4) = (s32) (*(s32 *)((s8 *)((u8 *)this) + 0x3C4) & 0xFFF7FFFF);
            }
            break;
        case 2:
            if (((VObj_14_85ec0b *)((u8 *)this + (1000)))->m4() != 0) {
                *(s32 *)((s8 *)((u8 *)this) + 0x404) = 3;
            }
            break;
        }
        this->vfunc_102();
        this->vfunc_89();
        return;
    case 5:
        object = (u8 *)(*(u8 **)((s8 *)((u8 *)this) + 0x424));
        if (object != NULL) {
            queue_destruction__7TObjectFv(object);
            *(u8 **)((s8 *)((u8 *)this) + 0x424) = NULL;
        }
        break;
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
#define I(o) (*(s32 *)((s8 *)(((u8 *)this)) + (o)))
#define R(o) (*(f32 *)((s8 *)(((u8 *)this)) + (o)))
#define P(o) (*(u8 **)((s8 *)(((u8 *)this)) + (o)))
#define V ((VObj_800E420C *)(((u8 *)this)))
void TObjEneMe3ShinowaReal::vfunc_114(s32 arg1) {
    s32 ok;
    s32 n;
    Vec_800E420C v;
    switch (arg1) {
    case 4:
        this->m_b8 = 7;
        this->set_field_378(0xE);
        V->m94();
        I(0x3C4) &= ~3;
        I(0x424) = 0;
        break;
    case 3:
        if (this->get_flag_b4() != 0) {
            I(0x3B8) = I(0x3BC);
            ok = 0;
            if (V->m97() != 0 || is_player_entity_id(this->m_38c) != 0) {
                if (transform_relative_position__9TObjEneDDFPv(this, P(0x390)) != 0) {
                    ok = 1;
                }
            } else {
                enemy_clear_target__12TObjEneDD_STFUs(this);
            }
            if (ok == 1) {
                this->enemy_copy_target_destination();
                I(0x3D4) = (s32)(lbl_805DA5D4 * calc_boss4_scale__10TObjPlayerFi(this));
                ok = 0;
                n = 0;
                for (; ok < 5; ok++) {
                    if (I(0x3D4) != ok) {
                        ((TObjEneMe3ShinowaMirage *)(this->get_or_create_mirage(n++)))->activate_mirage(ok);
                    }
                }
                transition_enemy_state__9TObjEneDDFs(this, 8);
                play_sound_effect(copy_target_state__14TObjEnePanarmsFPv(this, 0x4003AD15), ((u8 *)this) + 0x38, 0, 0);
            } else {
                this->try_spawn_mirages();
                transition_enemy_state__9TObjEneDDFs(this, 4);
            }
        }
        break;
    case 0:
        advance_animation_playback(this, arg1);
        if (R(0xC0) >= lbl_805DA5C8) {
            if (P(0x424) == NULL) {
                P(0x424) = (u8 *)create_particle_emitter((s32)(((u8 *)this) + 0x38), 0x114);
                if (P(0x424) != NULL) {
                    ((TParticleCtrl *)(P(0x424)))->enable();
                }
            } else {
                VecCopy((Vec *)&v, (const Vec *)(((u8 *)this) + 0x38));
                v.x = TObjEneMe3ShinowaReal__data_805DA5CC * sin_table_lookup(I(0x60)) + v.x;
                v.y += lbl_805DA5D0;
                v.z = TObjEneMe3ShinowaReal__data_805DA5CC * cos_table_lookup(I(0x60)) + v.z;
                ((TNowLoading *)(P(0x424)))->copy_pos(&v);
            }
        }
        V->m100();
        V->m87();
        break;
    case 5:
        if (P(0x424) != NULL) {
            queue_destruction__7TObjectFv(P(0x424));
            P(0x424) = NULL;
        }
        break;
    }
}
#pragma pop

}
