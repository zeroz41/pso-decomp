#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/TObjEneRe7Berura_803E4CE0.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "types.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/enemy/TObjEneDD_ST.h"
#include "pso/enemy/TObjEneEpsilon.h"
#include "pso/enemy/TObjEneEpsilonGuard.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjChara.h"
#include "pso/unk/TObjEneEpsilonBody.h"
#include "pso/object/TObjMotion.h"
extern "C" void has_flag_0x800__9TObjCharaFv();
extern "C" void test_flag30_512__9TObjCharaFv();
extern "C" void test_flag_1000__9TObjCharaFv();
extern "C" void test_flag_256__9TObjCharaFv();
#include "pso/TParticleCtrl.h"
#include "pso/boss/TBoss3Volopt.h"

#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/misc/RenderFadeState.h"
#include "pso/misc/TNowLoading.h"
#include "pso/object/TObjFish.h"

#include "pso/enemy/TUnk_80494938.h"
#include "pso/TObject.h"

struct EGPad_8035DD68 { char pad[0x18]; };
#define V1(n) virtual void vpad##n();
#define V10(n) V1(n##0) V1(n##1) V1(n##2) V1(n##3) V1(n##4) V1(n##5) V1(n##6) V1(n##7) V1(n##8) V1(n##9)
struct EG_8035DD68 : EGPad_8035DD68 {
    V10(0) V10(1) V10(2) V10(3) V10(4) V10(5) V10(6) V10(7) V10(8)
    V1(90) V1(91) V1(92)
    virtual void slot93();
};

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
    virtual s32 m53();
};

struct RecoveredGlobal_8035E374_lbl_805439E0 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_8035E374_lbl_805439E0_size[sizeof(RecoveredGlobal_8035E374_lbl_805439E0) == 0x10 ? 1 : -1];

struct VBase_18_6ff2a2 { char pad[0x18]; };

struct VObj_18_6ff2a2 : VBase_18_6ff2a2 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
    virtual s32 m9(f32, f32, f32);
};

#include <stddef.h>

extern "C" {
RecoveredGlobal_8035E374_lbl_805439E0 lbl_805439E0;
s32 epsilon_guard_camera_step;
s32 epsilon_guard_camera_ctrl_ptr;
}

struct VBase_18_7f4864 { char pad[0x18]; };

struct VObj_18_7f4864 : VBase_18_7f4864 {
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
    virtual s32 m87();
    virtual void m88();
    virtual void m89();
    virtual void m90();
    virtual void m91();
    virtual void m92();
    virtual s32 m93();
    virtual s32 m94(s32);
};

struct VBase_14_87d649 { char pad[0x14]; };

struct VObj_14_87d649 : VBase_14_87d649 {
    virtual void m0();
    virtual s32 m1(s32);
    virtual s32 m2();
    virtual void m3();
    virtual s32 m4();
};

struct RecoveredFields_8035E578_arg0 {
    u8 unknown_0[0xB8];
    s16 field_B8;
    u8 unknown_BA[0x3B2];
    s32 field_46C;
};

struct O_8035DDC8 { u8 pad[0x30]; u32 f30; u8 pad2[0x46c - 0x34]; u32 f46c; };

struct O_8035DE08 { u8 pad[0x30]; u32 f30; u8 pad2[0x46c - 0x34]; u32 f46c; };

struct VB_8035E430 { char pad[0x18]; };

struct VO_8035E430 : VB_8035E430 {
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
    virtual void m56(); virtual void m57(); virtual void m58(); virtual void m59();
    virtual void m60(); virtual void m61(); virtual void m62(); virtual void m63();
    virtual void m64(); virtual void m65(); virtual void m66(); virtual void m67();
    virtual void m68(); virtual void m69(); virtual void m70(); virtual void m71();
    virtual void m72(); virtual void m73(); virtual void m74(); virtual void m75();
    virtual void m76(); virtual void m77(); virtual void m78(); virtual void m79();
    virtual void m80(); virtual void m81(); virtual void m82(); virtual void m83();
    virtual void m84(); virtual void m85(); virtual void m86(); virtual void m87();
    virtual void m88(); virtual void m89(); virtual void m90(); virtual void m91();
    virtual void m92(); virtual void m93(); virtual void m94();
};

struct G_8035E430 {
    u8 pad0[0x24]; s32 x24; u8 pad28[0x10]; u8 x38[0x28]; s32 x60; u8 pad64[0x54];
    s16 xB8; u8 padBA[0x2FC - 0xBA]; u8 x2FC[0x430 - 0x2FC]; s32 x430; s32 x434;
    u8 pad438[0x28]; u8 x460[0xC]; s32 flags;
};

struct VBase_8035E018 { char pad[0x14]; };

struct VObj_8035E018 : VBase_8035E018 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5();
    virtual void m6();
    virtual void m7();
};

struct Rec_8035E018 { u8 b[0x1C]; };

struct Self_8035E018 { u8 pad[0x3C0]; Rec_8035E018 recs[4]; };

struct Base_A { char pad[0x18]; };

struct V_A : Base_A {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual void f64();
    virtual void f65();
    virtual void f66();
    virtual void f67();
    virtual void f68();
    virtual void f69();
    virtual void f70();
    virtual void f71();
    virtual void f72();
    virtual void f73();
    virtual void f74();
    virtual void f75();
    virtual void f76();
    virtual void f77();
    virtual void f78();
    virtual void f79();
    virtual void f80();
    virtual void f81();
    virtual void f82();
    virtual void f83();
    virtual void f84();
    virtual void f85();
    virtual void f86();
    virtual void m87();
    virtual void f88();
    virtual void f89();
    virtual void f90();
    virtual void f91();
    virtual void f92();
    virtual void f93();
    virtual void m94(s32);
};

struct Pair_8035EA90 { s32 a; f32 b; };

struct VBase_8035EA90 { char pad[0x18]; };

struct VObj_8035EA90 : VBase_8035EA90 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20();
    virtual void m21(void *, Pair_8035EA90, int, int, int);
    virtual void m22();
    virtual void m23(void *);
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27();
    virtual void m28(); virtual void m29(); virtual void m30();
    virtual s32 m31();
};

extern "C" {
s32 TObjEneEpsilonGuard__sub_8035DD74(u8 *arg0);
void TObjEneEpsilonGuard__sub_8035DEC0(u8 *arg0);
void get_camera_ctrl__9TObjEneDDFv(s32, s32);
extern RecoveredGlobal_8035E374_lbl_805439E0 lbl_805439E0;
extern s32 epsilon_guard_camera_step;
extern s32 epsilon_guard_camera_ctrl_ptr;
s32 is_main_phase_15__9TObjEneDDFv();
s32 update_player_state__9TObjEneDDFv(void *, int, int);

void render__19TObjEneEpsilonGuardFv(u8 *);
void TObjEneEpsilonGuard__sub_8035E578(u8 *, s32);
void play_sound_effect(int, void *, int, int);
extern u8 epsilon_guard_breakup_params[];
extern s32 lbl_805D6FA8;
struct G_8035E430;
s32 is_split_screen();
s32 get_camera_mode__11TCameraCtrlFv();
s32 get_mode__11TCameraCtrlFPv(void *);
s32 update__15RenderFadeStateFv(void *);
s32 rotate_matrix_y(int, int);
s32 translate_matrix(int, f32, f32, f32);
s32 push_matrix();
s32 pop_matrix();
s32 post_translate_matrix(void *);
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;

void render_with_fade__19TObjEneEpsilonGuardFPvi(u8 *arg0, s32 arg1);
s32 move_with_wall_slide_commit__9TObjEneDDFfff(void *, void *, f32, f32, f32);
extern void *TObjEneEpsilonGuard__movement_params;
void TObjEneEpsilonGuard__sub_8035E8C0(void *, s32);
s32 VecCopy__FP3VecPC3Vec(void *);
s32 obj_is_hit_receivable();
void queue_destruction__7TObjectFv(void *arg0);
VObj_8035EA90 *get_battle_param__10TObjPlayerFi(s32);
void *create_particle_emitter(void *pos, s32 id);
void *find_entity_by_id(u16 id);
extern void *TObjEneEpsilonGuard__model_desc[];

struct Base_8035E3B8_8035DD68 { char pad[0x18]; };
struct VObj_8035E3B8_8035DD68 : Base_8035E3B8_8035DD68 {
    virtual void m0();
    virtual void m1();  virtual void m2();  virtual void m3();  virtual void m4();
    virtual void m5();  virtual void m6();  virtual void m7();  virtual void m8();
    virtual void m9();  virtual void m10(); virtual void m11(); virtual void m12();
    virtual void m13(); virtual void m14(); virtual void m15(); virtual void m16();
    virtual void m17(); virtual void m18(); virtual void m19(); virtual void m20();
    virtual void m21(); virtual void m22(); virtual void m23(); virtual void m24();
    virtual void m25(); virtual void m26(); virtual void m27(); virtual void m28();
    virtual void m29(); virtual void m30(); virtual void m31(); virtual void m32();
    virtual void m33(); virtual void m34(); virtual void m35(); virtual void m36();
    virtual void m37(); virtual void m38(); virtual void m39(); virtual void m40();
    virtual void m41(); virtual void m42(); virtual void m43(); virtual void m44();
    virtual void m45(); virtual void m46(); virtual void m47(); virtual void m48();
    virtual void m49(); virtual void m50(); virtual void m51(); virtual void m52();
    virtual void m53(); virtual void m54(); virtual void m55(); virtual void m56();
    virtual void m57(); virtual void m58(); virtual void m59(); virtual void m60();
    virtual void m61(); virtual void m62(); virtual void m63(); virtual void m64();
    virtual void m65(); virtual void m66(); virtual void m67(); virtual void m68();
    virtual void m69(); virtual void m70(); virtual void m71(); virtual void m72();
    virtual void m73(); virtual void m74(); virtual void m75(); virtual void m76();
    virtual void m77(); virtual void m78(); virtual void m79(); virtual void m80();
    virtual void m81(); virtual void m82(); virtual void m83(); virtual void m84();
    virtual void m85(); virtual void m86(); virtual void m87(); virtual void m88();
    virtual void m89(); virtual void m90(); virtual void m91(); virtual void m92();
    virtual void m93();
};

int TObjEneEpsilonGuard__sub_8035DD68(void* p);
s32 scale_matrix(int, f32, f32, f32);
int TObjEneEpsilonGuard__sub_8035F95C(void *p);
int TObjEneEpsilonGuard__sub_8035F968(void);
void draw_model_motion(void *arg0, void *arg1, f32 farg0);

// (moved from TBoss6DPB: these three EpsilonGuard methods at 0x8035DCC0-0x8035DD68 use this unit's pool)
struct Msg_8035DD18 { s32 type; s32 value; };
extern "C" {
f32 receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll(void *, s32, Msg_8035DD18, void *, s32, s32);
f32 TObjEneEpsilonGuard__vt21(s32 arg0, s32 arg1, Msg_8035DD18 *msg, void *arg3, s32 arg4, s32 arg5);
}

f32 TObjEneEpsilonGuard::receive_weapon_special_attack(void *, void *) {
    s32 arg0 = (s32)this;
    ((TObjChara *)arg0)->try_apply_damage(arg0 + 0x2FC, 0);
    return 0.0f;
}
f32 TObjEneEpsilonGuard::receive_physical_attack(void *, f32) {
    s32 arg0 = (s32)this;
    ((TObjChara *)arg0)->try_apply_damage(arg0 + 0x2FC, 0);
    return 0.0f;
}
f32 TObjEneEpsilonGuard__vt21(s32 arg0, s32 att, Msg_8035DD18 *msg, void *coll, s32 tech, s32 arg5) {
    if (msg->type == 0x14) {
        return receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll((void *)arg0, att, *msg, coll, tech, arg5);
    }
    ((TObjChara *)arg0)->try_apply_damage(arg0 + 0x2FC, 0);
    return 0.0f;
}

int TObjEneEpsilonGuard__sub_8035DD68(void* p) { return (*(u32*)((char*)p + 0x46c) >> 7) & 0x1; }

s32 TObjEneEpsilonGuard__sub_8035DD74(u8 *arg0) {
    if (*(s32 *)((s8 *)arg0 + 0x30) & 0xA00) {
        return 0;
    }
    return ((u32) *(u32 *)((s8 *)arg0 + 0x46C) >> 4U) & 1;
}

s32 TObjEneEpsilonGuard::is_guard_active() {
    if (*(s32 *)((s8 *)((u8 *)this) + 0x30) & 0xA00) {
        return 0;
    }
    if ((s16) *(s16 *)((s8 *)((u8 *)this) + 0x326) != 1) {
        return 0;
    }
    return ((u32) *(u32 *)((s8 *)((u8 *)this) + 0x46C) >> 9U) & 1;
}

s32 TObjEneEpsilonGuard::is_state_flag_set() {
    if (((O_8035DDC8 *)this)->f30 & 0xa00) {
        return 0;
    }
    if (((O_8035DDC8 *)this)->f46c & 0x10) {
        return 0;
    }
    if (((O_8035DDC8 *)this)->f46c & 0x20) {
        return 0;
    }
    return (((O_8035DDC8 *)this)->f46c & 4) ? 1 : 0;
}

s32 TObjEneEpsilonGuard::is_guard_ready() {
    if (((O_8035DE08 *)this)->f30 & 0xa00) {
        return 0;
    }
    if (((O_8035DE08 *)this)->f46c & 0x10) {
        return 0;
    }
    if (((O_8035DE08 *)this)->f46c & 0x20) {
        return 0;
    }
    return (((O_8035DE08 *)this)->f46c & 4) ? 1 : 0;
}

void TObjEneEpsilonGuard::clear_and_flag_state() {
    *(s32 *)((s8 *)((u8 *)this) + 0x44C) = 0;
    *(s32 *)((s8 *)((u8 *)this) + 0x46C) = (s32) (*(s32 *)((s8 *)((u8 *)this) + 0x46C) | 0x20);
    this->clear_all_status_effects();
}

void TObjEneEpsilonGuard::set_flag_8_and_notify() {
    *(s32 *)((s8 *)((u8 *)this) + 0x46C) = (s32) (*(s32 *)((s8 *)((u8 *)this) + 0x46C) | 8);
    this->clear_all_status_effects();
}

void TObjEneEpsilonGuard__sub_8035DEC0(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 0x46C) = (s32) (*(s32 *)((s8 *)arg0 + 0x46C) | 2);
    ((VObj_18 *)(arg0))->m53();
}

void TObjEneEpsilonGuard::set_target(s32 arg1, s32 arg2, s32 arg3) {
    (void)arg1;
    VecCopy__FP3VecPC3Vec(((u8 *)this) + 0x38);
    *(s32 *)((s8 *)((u8 *)this) + 0x60) = arg2;
    if (arg3 != 0) {
        *(s32 *)((s8 *)((u8 *)this) + 0x46C) = (s32) (*(s32 *)((s8 *)((u8 *)this) + 0x46C) | 0x100);
    } else {
        *(s32 *)((s8 *)((u8 *)this) + 0x46C) = (s32) (*(s32 *)((s8 *)((u8 *)this) + 0x46C) & 0xFFFFFEFF);
    }
    *(s32 *)((s8 *)((u8 *)this) + 0x46C) = (s32) (*(s32 *)((s8 *)((u8 *)this) + 0x46C) | 1);
    this->clear_all_status_effects();
}

void TObjEneEpsilonGuard::render_guard_effect() {
    f32 temp_f1;

    if ((*(s32 *)((s8 *)((u8 *)this) + 0x46C) & 0x20) && (get_mode__11TCameraCtrlFPv((void *) (((s32 *)&main_task))) & 0x200)) {
        TObjFish::set_global_param((int) (*(s32 *)((s8 *)((u8 *)this) + 0x24)));
        push_matrix();
        post_translate_matrix((void *) (((u8 *)this) + 0x38));
        translate_matrix(0, 0.0f, 24.0f, 0.0f);
        temp_f1 = *(f32 *)((s8 *)((u8 *)this) + 0x458);
        scale_matrix(0, temp_f1, temp_f1, temp_f1);
        set_motion_packed_rotation();
        draw_model_motion((void *)(*(s32 *)((s8 *)((u8 *)this) + 0x444)), (void *)(*(s32 *)((s8 *)((u8 *)this) + 0x448)), (f32) (*(f32 *)((s8 *)((u8 *)this) + 0x454)));
        clear_motion_packed_rotation();
        pop_matrix();
    }
}

void render_with_fade__19TObjEneEpsilonGuardFPvi(u8 *ene_re7_berura, s32 arg1) {
    s32 i;
    VObj_8035E018 *r;
    i = 0;
    if (is_split_screen() != 0) {
        i = get_camera_mode__11TCameraCtrlFv();
    }
    saved_model_render_flags = model_render_flags;
    saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
    saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
    r = (VObj_8035E018 *)&((Self_8035E018 *)ene_re7_berura)->recs[i];
    update__15RenderFadeStateFv(r);
    if (((RenderFadeState *)r)->updateFromCamera((const f32*)(ene_re7_berura + 0x2FC)) != 0) {
        r->m6();
        if (!(get_mode__11TCameraCtrlFPv(((s32 *)&main_task)) & 0x200)) {
            model_render_flags = saved_model_render_flags;
            chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
            chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
            return;
        }
    } else if (*(s16 *)((s8 *)ene_re7_berura + 0x326) == 3) {
        ((VObj_8035E018 *)(ene_re7_berura + 0x4BC))->m6();
        if (!(get_mode__11TCameraCtrlFPv(((s32 *)&main_task)) & 0x200)) {
            model_render_flags = saved_model_render_flags;
            chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
            chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
            return;
        }
    } else if (get_mode__11TCameraCtrlFPv(((s32 *)&main_task)) & 0x200) {
        model_render_flags = saved_model_render_flags;
        chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
        chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
        return;
    }
    ((TObjEneDD *)ene_re7_berura)->update_secondary_light();
    TObjFish::set_global_param(*(s32 *)((s8 *)ene_re7_berura + 0x24));
    push_matrix();
    post_translate_matrix(ene_re7_berura + 0x38);
    translate_matrix(0, 0.0f, 24.0f, 0.0f);
    rotate_matrix_y(0, *(s32 *)((s8 *)ene_re7_berura + 0x60));
    TObjEneDD::clear_global_flag_400();
    epsilon_guard_camera_step = 0;
    epsilon_guard_camera_ctrl_ptr = (s32)(ene_re7_berura + 0x460);
    *(f32 *)((s8 *)ene_re7_berura + 0x460) = 0.0f;
    *(f32 *)((s8 *)ene_re7_berura + 0x464) = 0.0f;
    *(f32 *)((s8 *)ene_re7_berura + 0x468) = 0.0f;
    set_chunk_model_node_callback((s32)((void *)TObjEneEpsilonGuard::advance_camera_ctrl_step));
    TObjPlayer::toggle_particle_effect();
    if (arg1 == 1) {
        ((TObjMotion *)ene_re7_berura)->draw();
    } else {
        ((TObjEnemy *)ene_re7_berura)->draw_motion_model();
    }
    TParticleCtrl::end_effect_render();
    set_chunk_model_node_callback((s32)NULL);
    pop_matrix();
    ((TObjEneDD *)ene_re7_berura)->update_primary_light();
    if (((RenderFadeState *)r)->updateFromCamera((const f32*)(ene_re7_berura + 0x2FC)) != 0) {
        r->m7();
    } else if (*(s16 *)((s8 *)ene_re7_berura + 0x326) == 3) {
        ((VObj_8035E018 *)(ene_re7_berura + 0x4BC))->m7();
    }
    model_render_flags = saved_model_render_flags;
    chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
    chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
}

#pragma push
#pragma opt_common_subs off
void render__19TObjEneEpsilonGuardFv(u8 *ene_epsilon_guard) {
    s32 var_r31;
    if ((TObjPlayer::check_demo_mode() == 0) && !(*(s32 *)((s8 *)ene_epsilon_guard + 0x30) & 0x02000000)) {
        var_r31 = 0;
        if (!(*(s32 *)((s8 *)ene_epsilon_guard + 0x46C) & 0x10)) {
            if (is_main_phase_15__9TObjEneDDFv() != 0) {
                var_r31 = ((VObj_18_6ff2a2 *)(ene_epsilon_guard))->m9(6e+02f, 6e+02f, 15.0f);
            } else if (((VObj_18_6ff2a2 *)(ene_epsilon_guard))->m8(6e+02f, 15.0f) != 0) {
                var_r31 = 1;
            } else {
                var_r31 = 0;
            }
        }
        if (var_r31 != 0) {
            update_player_state__9TObjEneDDFv(ene_epsilon_guard, 0, 0);
            ((TObject *)ene_epsilon_guard)->defer_render();
            render_with_fade__19TObjEneEpsilonGuardFPvi(ene_epsilon_guard, var_r31);
            ((TObjEneEpsilonGuard *)ene_epsilon_guard)->render_guard_effect();
            return;
        }
        *(f32 *)((s8 *)ene_epsilon_guard + 0x460) = (f32) 0.0f;
        *(f32 *)((s8 *)ene_epsilon_guard + 0x464) = (f32) 0.0f;
        *(f32 *)((s8 *)ene_epsilon_guard + 0x468) = (f32) 0.0f;
        ((TObjEneEpsilonGuard *)ene_epsilon_guard)->sub_803626A8((s32)(ene_epsilon_guard + 0x460), 0);
    }
}
#pragma pop

void TObjEneEpsilonGuard::advance_camera_ctrl_step() {
    if ((s32) epsilon_guard_camera_step == 0) {
        get_camera_ctrl__9TObjEneDDFv((s32) &lbl_805439E0.value, epsilon_guard_camera_ctrl_ptr);
    }
    epsilon_guard_camera_step += 1;
}

void TObjEneEpsilonGuard::handle_message(s32 arg1) {
    switch (arg1) {
    case 4:
        ((struct VObj_8035E3B8_8035DD68 *) this)->m93();
        *(s32 *)((s8 *)this + 0x46C) = (s32) (*(s32 *)((s8 *)this + 0x46C) | 0x14);
        this->send_entity_set_flags();
        return;
    case 3:
        queue_destruction__7TObjectFv(this);
    case 5:
    case 0:
        return;
    }
}

#pragma push
#pragma opt_common_subs off
typedef char RecoveredFields_8035E578_arg0_B8_offset[offsetof(RecoveredFields_8035E578_arg0, field_B8) == 0xB8 ? 1 : -1];
typedef char RecoveredFields_8035E578_arg0_46C_offset[offsetof(RecoveredFields_8035E578_arg0, field_46C) == 0x46C ? 1 : -1];

void TObjEneEpsilonGuard::handle_break_state(s32 arg1) {
    switch (arg1) {
    case 4:
        ((G_8035E430 *)this)->xB8 = 0;
        set_field_378(4);
        ((G_8035E430 *)this)->flags |= 0x40;
        ((G_8035E430 *)this)->flags &= ~0x14;
        this->vfunc_96();
        TObjPlayer::spawn_effect_f8((s32)(((G_8035E430 *)this)->x460), 0x14);
        ((G_8035E430 *)this)->x430 = 0;
        ((G_8035E430 *)this)->x434 = 0;
        break;
    case 3:
        if (((G_8035E430 *)this)->x430 == 1) {
            transition_enemy_state(5);
        }
        break;
    case 5:
        break;
    case 0:
        advance_animation();
        ((G_8035E430 *)this)->x434++;
        if (((G_8035E430 *)this)->x434 >= 0x14) {
            ((VO_8035E430 *)((G_8035E430 *)this))->m94();
            TBoss3Volopt::create_breakup_mdl((s32)lbl_805D6FA8, (s32)epsilon_guard_breakup_params, (s32)(((G_8035E430 *)this)->x24), (s32)(((G_8035E430 *)this)->x38), (s32)(((G_8035E430 *)this)->x60));
            play_sound_effect(0x4003AD4C, ((G_8035E430 *)this)->x2FC, 0, 0);
            ((TObjPlayer *)(((G_8035E430 *)this)->x2FC))->trigger_dell_biter_events();
            ((G_8035E430 *)this)->x430 = 1;
        }
        ((VO_8035E430 *)((G_8035E430 *)this))->m87();
        break;
    }
}

void TObjEneEpsilonGuard__sub_8035E578(u8 *ene_dd, s32 arg1) {
    s32 temp_r4;
    switch (arg1) {
    case 4:
        ((RecoveredFields_8035E578_arg0 *)ene_dd)->field_B8 = 0;
        ((TObjEneDD *)ene_dd)->set_field_378(3);
        ((VObj_14_87d649 *)(ene_dd + (1212)))->m1(0x14);
        ((VObj_14_87d649 *)(ene_dd + (1212)))->m2();
        temp_r4 = ((RecoveredFields_8035E578_arg0 *)ene_dd)->field_46C;
        ((RecoveredFields_8035E578_arg0 *)ene_dd)->field_46C = (s32) (temp_r4 & ~0x14);
        ((VObj_18_7f4864 *)(ene_dd))->m94(temp_r4);
        break;
    case 3:
        if (((VObj_14_87d649 *)(ene_dd + (1212)))->m4() != 0) {
            ((TObjEneDD *)ene_dd)->transition_enemy_state(0);
            ((RecoveredFields_8035E578_arg0 *)ene_dd)->field_46C = (s32) (((RecoveredFields_8035E578_arg0 *)ene_dd)->field_46C | 0x10);
            ((TObjEneDD *)(ene_dd))->vfunc_95();
            break;
        }
    case 5:
        break;
    case 0:
        ((TObjMotion *)ene_dd)->advance_animation();
        ((TObjEneDD *)(ene_dd))->vfunc_89();
        break;
    }
}
#pragma pop

void TObjEneEpsilonGuard::state_orbit(s32 arg1) {
    u32 temp_r3;

    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)this + 0xB8) = 0;
        set_field_378(2);
        *(s32 *)((s8 *)this + 0x46C) = (s32) (*(s32 *)((s8 *)this + 0x46C) | 4);
        *(s32 *)((s8 *)this + 0x46C) = (s32) (*(s32 *)((s8 *)this + 0x46C) & 0xFFFFFFE7);
        this->vfunc_96();
        *(s32 *)((s8 *)this + 0x430) = 0;
        *(s32 *)((s8 *)this + 0x438) = (s32) *(s32 *)((s8 *)this + 0x60);
        *(s32 *)((s8 *)this + 0x43C) = 0;
        return;
    case 3:
        if (*(s32 *)((s8 *)this + 0x46C) & 8) {
            transition_enemy_state(3);
        }
    case 5:
        return;
    case 0:
        advance_animation();
        switch (*(s32 *)((s8 *)this + 0x430)) {
        case 0:
            if (*(s32 *)((s8 *)this + 0x46C) & 0x100) {
                *(s32 *)((s8 *)this + 0x43C) = (s32) (((-65536.0f) * *(f32 *)((s8 *)TObjEneEpsilonGuard__movement_params + 8)) / (6.283184f * *(f32 *)((s8 *)TObjEneEpsilonGuard__movement_params + 0)));
            } else {
                *(s32 *)((s8 *)this + 0x43C) = (s32) ((65536.0f * *(f32 *)((s8 *)TObjEneEpsilonGuard__movement_params + 8)) / (6.283184f * *(f32 *)((s8 *)TObjEneEpsilonGuard__movement_params + 0)));
            }
            *(s32 *)((s8 *)this + 0x430) = 1;
            break;
        case 1:
            temp_r3 = (u32)find_entity_by_id(*(u16 *)((s8 *)this + 0x470));
            if (temp_r3 != 0U) {
                if (TObjEneEpsilonGuard__sub_8035F968() == 1) {
                    *(s32 *)((s8 *)this + 0x46C) = (s32) (*(s32 *)((s8 *)this + 0x46C) & 0xFFFFFFFB);
                    *(s32 *)((s8 *)this + 0x430) = 2;
                } else if (TObjEneEpsilonGuard__sub_8035F95C((void *)temp_r3) != 1) {
                    goto block_23;
                }
            } else {
block_23:
                *(s32 *)((s8 *)this + 0x438) = (s32) (*(s32 *)((s8 *)this + 0x438) + *(s32 *)((s8 *)this + 0x43C));
                set_orbit_destination(*(s32 *)((s8 *)this + 0x438));
                this->update_velocity();
                move_with_wall_slide_commit__9TObjEneDDFfff(this, TObjEneEpsilonGuard__movement_params, *(f32 *)((s8 *)this + 0x3A0), *(f32 *)((s8 *)this + 0x3A8), *(f32 *)((s8 *)TObjEneEpsilonGuard__movement_params + 8));
            }
            break;
        case 2:
            if ((find_entity_by_id(*(u16 *)((s8 *)this + 0x470)) != 0U) && (TObjEneEpsilonGuard__sub_8035F968() == 0)) {
                *(s32 *)((s8 *)this + 0x46C) = (s32) (*(s32 *)((s8 *)this + 0x46C) | 4);
                *(s32 *)((s8 *)this + 0x430) = 1;
            }
            break;
        }
        *(s32 *)((s8 *)this + 0x60) = calc_angle_to_target();
        this->vfunc_89();
        break;
    }
}

void TObjEneEpsilonGuard__sub_8035E8C0(void *ene_epsilon_guard, s32 arg1) {
    s32 temp_r4;
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)ene_epsilon_guard + 0xB8) = 0;
        ((TObjEneDD *)ene_epsilon_guard)->set_field_378(1);
        temp_r4 = *(s32 *)((s8 *)ene_epsilon_guard + 0x46C);
        *(s32 *)((s8 *)ene_epsilon_guard + 0x46C) = (s32) (temp_r4 & ~0x216);
        ((V_A *) ene_epsilon_guard)->m94(temp_r4);
        return;
    case 3:
        if (*(s32 *)((s8 *)ene_epsilon_guard + 0x46C) & 2) {
            ((TObjEneDD *)ene_epsilon_guard)->transition_enemy_state(2);
        }
    case 5:
        return;
    case 0:
        ((TObjMotion *)ene_epsilon_guard)->advance_animation();
        ((TObjEneDD_ST *)ene_epsilon_guard)->enemy_copy_target_destination();
        ((TObjEneDD *)ene_epsilon_guard)->update_velocity();
        if (!(*(s32 *)((s8 *)ene_epsilon_guard + 0x46C) & 0x200)) {
            f32 *d = (f32 *)TObjEneEpsilonGuard__movement_params;
            if (*(f32 *)((s8 *)ene_epsilon_guard + 0x3AC) > d[0] + d[1]) {
                *(s32 *)((s8 *)ene_epsilon_guard + 0x46C) |= 0x200;
            } else {
                move_with_wall_slide_commit__9TObjEneDDFfff(ene_epsilon_guard, d, -*(f32 *)((s8 *)ene_epsilon_guard + 0x3A0), -*(f32 *)((s8 *)ene_epsilon_guard + 0x3A8), d[1]);
            }
        }
        *(s32 *)((s8 *)ene_epsilon_guard + 0x60) = ((TObjEneEpsilonGuard *)ene_epsilon_guard)->calc_angle_to_target();
        ((TObjEneDD *)ene_epsilon_guard)->vfunc_89();
        break;
    }
}

void TObjEneEpsilonGuard::handle_event(s32 arg1) {
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)this + 0xB8) = 0;
        set_field_378(0);
        ((EG_8035DD68 *) this)->slot93();
        *(s32 *)((s8 *)this + 0x46C) = (s32) (*(s32 *)((s8 *)this + 0x46C) | 0x10);
        *(s32 *)((s8 *)this + 0x46C) = (s32) (*(s32 *)((s8 *)this + 0x46C) & ~5);
        return;
    case 3:
        if (*(s32 *)((s8 *)this + 0x46C) & 1) {
            transition_enemy_state(1);
        }
    case 5:
        return;
    case 0:
        *(s32 *)((s8 *)this + 0x46C) = (s32) (*(s32 *)((s8 *)this + 0x46C) | 0x10);
        break;
    }
}
#pragma push
#pragma opt_common_subs off
void TObjEneEpsilonGuard::sub_8035EA90() {
    f32 lim;
    s32 i;
    VObj_8035EA90 *p;
    u32 t;
    if (*(s32 *)((s8 *)((u8 *)this) + 0x46C) & 0x20) {
        switch (*(s32 *)((s8 *)((u8 *)this) + 0x44C)) {
        case 0:
            *(f32 *)((s8 *)((u8 *)this) + 0x458) = 0.0f;
            *(s32 *)((s8 *)((u8 *)this) + 0x450) = 0;
            *(f32 *)((s8 *)((u8 *)this) + 0x454) = 0.0f;
            *(s32 *)((s8 *)((u8 *)this) + 0x44C) = 1;
            *(void **)((s8 *)((u8 *)this) + 0x440) = create_particle_emitter(((u8 *)this) + 0x2FC, 0x221);
            break;
        case 1:
            *(f32 *)((s8 *)((u8 *)this) + 0x458) += 0.1f;
            if (*(void **)((s8 *)((u8 *)this) + 0x440) != NULL) {
                ((TParticleCtrl *)*(void **)((s8 *)((u8 *)this) + 0x440))->set_position(((u8 *)this) + 0x2FC);
            }
            if (*(f32 *)((s8 *)((u8 *)this) + 0x458) >= 1.0f) {
                *(f32 *)((s8 *)((u8 *)this) + 0x458) = 1.0f;
                *(s32 *)((s8 *)((u8 *)this) + 0x44C) = 2;
            }
            break;
        case 2:
            (*(s32 *)((s8 *)((u8 *)this) + 0x450))++;
            if (*(void **)((s8 *)((u8 *)this) + 0x440) != NULL) {
                ((TParticleCtrl *)*(void **)((s8 *)((u8 *)this) + 0x440))->set_position(((u8 *)this) + 0x2FC);
            }
            if (*(s32 *)((s8 *)((u8 *)this) + 0x450) >= *(s32 *)((s8 *)TObjEneEpsilonGuard__movement_params + 0x18)) {
                *(f32 *)((s8 *)((u8 *)this) + 0x458) = 1.0f;
                *(s32 *)((s8 *)((u8 *)this) + 0x44C) = 3;
            }
            break;
        case 3:
            *(f32 *)((s8 *)((u8 *)this) + 0x458) -= 0.1f;
            if (*(void **)((s8 *)((u8 *)this) + 0x440) != NULL) {
                ((TParticleCtrl *)*(void **)((s8 *)((u8 *)this) + 0x440))->set_position(((u8 *)this) + 0x2FC);
            }
            if (*(f32 *)((s8 *)((u8 *)this) + 0x458) <= 0.0f) {
                *(f32 *)((s8 *)((u8 *)this) + 0x458) = 0.0f;
                *(s32 *)((s8 *)((u8 *)this) + 0x46C) &= ~0x20;
                if (*(void **)((s8 *)((u8 *)this) + 0x440) != NULL) {
                    queue_destruction__7TObjectFv(*(void **)((s8 *)((u8 *)this) + 0x440));
                    *(void **)((s8 *)((u8 *)this) + 0x440) = NULL;
                }
            }
            break;
        default:
            *(s32 *)((s8 *)((u8 *)this) + 0x46C) &= ~0x20;
            if (*(void **)((s8 *)((u8 *)this) + 0x440) != NULL) {
                queue_destruction__7TObjectFv(*(void **)((s8 *)((u8 *)this) + 0x440));
                *(void **)((s8 *)((u8 *)this) + 0x440) = NULL;
            }
            break;
        }
        lim = (f32)*(u32 *)((s8 *)(*(u8 **)((s8 *)((u8 *)this) + 0x448)) + 4) - 1.0f;
        *(f32 *)((s8 *)((u8 *)this) + 0x454) += 0.5f;
        if (lim < *(f32 *)((s8 *)((u8 *)this) + 0x454)) {
            *(f32 *)((s8 *)((u8 *)this) + 0x454) -= lim;
        }
        *(f32 *)((s8 *)((u8 *)TObjEneEpsilonGuard__model_desc) + 0x38) = 36.0f * *(f32 *)((s8 *)((u8 *)this) + 0x458);
        ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(*(u8 **)((s8 *)((u8 *)this) + 0x45C) + 0x38, ((u8 *)this) + 0x38);
        TObjPlayer::init_all_slots();
        ((TObjPlayer *)(*(void **)((s8 *)((u8 *)this) + 0x45C)))->check_object_collisions();
        if (*(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 **)((s8 *)((u8 *)this) + 0x45C)) + 0xA4)) + 0x18) & 0x80000) {
            for (i = 0; i < 16; i++) {
                p = get_battle_param__10TObjPlayerFi(i);
                if (p == NULL) {
                    break;
                }
                if (obj_is_hit_receivable() != 0) {
                    t = (u32)find_entity_by_id(*(u16 *)((s8 *)((u8 *)this) + 0x470));
                    if (t != 0 && p->m31() == 0) {
                        Pair_8035EA90 pr;
                        pr.a = ((TObjEneEpsilonBody *)t)->get_table_value_by_index();
                        pr.b = *(f32 *)((s8 *)TObjEneEpsilonGuard__movement_params + 0xC);
                        p->m21(this, pr, 0, -1, -1);
                        p->m23(this);
                    }
                }
            }
        }
    } else if (*(void **)((s8 *)((u8 *)this) + 0x440) != NULL) {
        queue_destruction__7TObjectFv(*(void **)((s8 *)((u8 *)this) + 0x440));
        *(void **)((s8 *)((u8 *)this) + 0x440) = NULL;
    }
}
#pragma pop

void vfunc_88__19TObjEneEpsilonGuardFv(void *);
void vfunc_89__19TObjEneEpsilonGuardFv(void *);
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);
s32 vfunc_89__9TObjEneDDFv();
s32 TObjEneEpsilonGuard__sub_8035F950();
s16 get_entity_id(int);

void TObjEneEpsilonGuard::update_guard_state() {
    s16 temp_r0;
    s32 entity;

    if (!(*(s32 *)((s8 *)((u8 *)this) + 0x46C) & 0x40)) {
        entity = (s32)find_entity_by_id((*(u16 *)((s8 *)((u8 *)this) + 0x470)));
        if ((entity == 0) || (TObjEneEpsilonGuard__sub_8035F950() == 1)) {
            if (*(s32 *)((s8 *)((u8 *)this) + 0x46C) & 0x10) {
                transition_enemy_state(5);
            } else {
                transition_enemy_state(4);
            }
        } else {
            *(s32 *)((s8 *)((u8 *)this) + 0x390) = entity;
            *(s16 *)((s8 *)((u8 *)this) + 0x38C) = get_entity_id((int) (*(s32 *)((s8 *)((u8 *)this) + 0x390)));
            enemy_copy_target_destination();
            sub_8035EA90();
        }
        if (*(s32 *)((s8 *)((u8 *)this) + 0x46C) & 0x20) {
            play_persistent_sound(0x4003A846, (s32)this, (u32)(((u8 *)this) + 0x38), 0, 0);
            return;
        }
        temp_r0 = *(s16 *)((s8 *)((u8 *)this) + 0x326);
        if ((temp_r0 != 4) && (temp_r0 != 5)) {
            play_persistent_sound(0x4003AD43, (s32)this, (u32)(((u8 *)this) + 0x38), 0, 0);
        }
    }
}

void TObjEneEpsilonGuard::vfunc_89() {
    vfunc_89__9TObjEneDDFv();
    if (*(s32 *)((s8 *)(*(void **)((s8 *)this + 0xA4)) + 0x18) & 0x400000) {
        *(s32 *)((s8 *)this + 0x46C) = (s32) (*(s32 *)((s8 *)this + 0x46C) | 0x80);
    } else {
        *(s32 *)((s8 *)this + 0x46C) = (s32) (*(s32 *)((s8 *)this + 0x46C) & 0xFFFFFF7F);
    }
    update_center_position();
}

void TObjEneEpsilonGuard::update_center_position() {
    u8 *arg0 = (u8 *)this;
    *(f32 *)((s8 *)arg0 + 0x2FC) = (f32) *(f32 *)((s8 *)arg0 + 0x38);
    *(f32 *)((s8 *)arg0 + 0x300) = (f32) (24.0f + *(f32 *)((s8 *)arg0 + 0x3C));
    *(f32 *)((s8 *)arg0 + 0x304) = (f32) *(f32 *)((s8 *)arg0 + 0x40);
    ((s32 (*)(void *, void *, void *, f32))VecCopy__FP3VecPC3Vec)(arg0 + 0x74, arg0 + 0x2FC, arg0, 24.0f);
}
void TObjEneEpsilonGuard::vfunc_88() { set_part_local_pos((void *)((char*)this + 0x2fc), (s32)((void*)0)); }

}

#include "pso/boss/TBoss8Dragon.h"
#include "pso/enemy/TObjEneMe3SinowZoa.h"
#include "pso/enemy/TObjEnePanarms.h"

struct Rec_8035F4B4 { u8 b[0x1C]; };

struct Self_8035F4B4 { u8 pad[0x3C0]; Rec_8035F4B4 recs[4]; };

struct VBase_8035F234 { char pad[0x18]; };

struct VObj_8035F234 : VBase_8035F234 {
    virtual void m0(int);
};

struct VBase_18_b345b0 { char pad[0x18]; };
struct VObj_18_b345b0 : VBase_18_b345b0 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4();
    virtual void m5(); virtual void m6(); virtual void m7(); virtual void m8(); virtual void m9();
    virtual void m10(); virtual void m11(); virtual void m12(); virtual void m13(); virtual void m14();
    virtual void m15(); virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23(); virtual void m24();
    virtual void m25(); virtual void m26(); virtual void m27(); virtual void m28(); virtual void m29();
    virtual void m30(); virtual void m31(); virtual void m32(); virtual void m33(); virtual void m34();
    virtual void m35(); virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39();
    virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43(); virtual void m44();
    virtual void m45(); virtual void m46(); virtual void m47(); virtual void m48(); virtual void m49();
    virtual void m50(); virtual void m51(); virtual void m52(); virtual void m53(); virtual void m54();
    virtual void m55(); virtual void m56(); virtual void m57(); virtual void m58(); virtual void m59();
    virtual void m60(); virtual void m61(); virtual void m62(); virtual void m63(); virtual void m64();
    virtual void m65(); virtual void m66(); virtual void m67(); virtual void m68(); virtual void m69();
    virtual void m70(); virtual void m71(); virtual void m72(); virtual void m73(); virtual void m74();
    virtual void m75(); virtual void m76(); virtual void m77(); virtual void m78(); virtual void m79();
    virtual void m80(); virtual void m81(); virtual void m82(); virtual void m83(); virtual void m84();
    virtual s32 m85(s16, s32);
    virtual void m86(); virtual void m87(); virtual void m88(); virtual void m89();
    virtual void m90(); virtual void m91(); virtual void m92();
    virtual s32 m93();
};

extern "C" {
void TObjEneEpsilonGuard__vt85(TObjEneEpsilonGuard *arg0, s32 arg1, s32 arg2);
void run_task__19TObjEneEpsilonGuardFv(u8 *arg0);
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
s32 get_bml_motion(void *, int);
s32 TObjFish__sub_8001EDB0(void *, int);
s32 get_bml_model(void *, int);
s32 reset_hp__9TObjEneDDFv(void *, s32, s32, s32);
s32 initialize_enemy_state__9TObjEneDDFv(void *, int);
s32 init_model__9TObjEneDDFv(void *, void *, int);
s32 init_collision_body_parts(void *, void *, int);
void *__ct__14TObjCollidableFP7TObject(void *, int);
extern s32 epsilon_guard_boss_stat_handle;
extern s32 epsilon_guard_shared_handler_b;
extern s32 epsilon_guard_registered_object_handle;
extern u8 *lbl_805D6FA0;
s32 TObjEneEpsilon__ct();
extern s32 TObjEneEpsilonGuard__class_name;
void *TObjEneEpsilonGuard__ct(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4, void *arg5, void *arg6);
void *__dt__13TUnk_80494938Fv(void *arg0, s16 arg1);
s32 free_collision_body_parts(void *);
s32 __dl__7TObjectFPv(void *);
u8 *__dt__14TObjEneEpsilonFv(u8 *arg0, s16 arg1);
u8 *__dt__19TObjEneEpsilonGuardFv(u8 *arg0, s16 arg1);
void vfunc_28__19TObjEneEpsilonGuardFv(void);
void vfunc_61__19TObjEneEpsilonGuardFv(void);
void vfunc_62__19TObjEneEpsilonGuardFv(void);
void vfunc_63__19TObjEneEpsilonGuardFv(void);
void *__nw__7TObjectFUl(int);
f64 atan2_float(f32, f32, f32);

extern const f64 lbl_80479C88;

extern "C" void vfunc_6__8TObjBaseFPsl();
extern "C" void vfunc_103__9TObjEneDDFPUc();
extern "C" void vfunc_79__9TObjEneDDFPl();
extern "C" void vfunc_84__9TObjEneDDFv();
extern "C" void vfunc_85__9TObjEneDDFv();
extern "C" void vfunc_86__9TObjEneDDFv();
extern "C" void vfunc_90__9TObjEneDDFv();
extern "C" void vfunc_91__9TObjEneDDFv();
extern "C" void vfunc_92__9TObjEneDDFv();
extern "C" void vfunc_93__9TObjEneDDFv();
extern "C" void vfunc_94__9TObjEneDDFv();
extern "C" void vfunc_95__9TObjEneDDFv();
extern "C" void vfunc_96__9TObjEneDDFv();
extern "C" void vfunc_97__9TObjEneDDFv();
extern "C" void vfunc_98__9TObjEneDDFv();
extern "C" void vfunc_99__9TObjEneDDFv();
extern "C" void vfunc_100__9TObjEneDDFv();
extern "C" void vfunc_101__9TObjEneDDFPUc();
extern "C" void vfunc_102__9TObjEneDDFv();
extern "C" void receive_physical_attack__19TObjEneEpsilonGuardFPvf();
extern "C" void receive_weapon_special_attack__19TObjEneEpsilonGuardFPvPv();
extern "C" int vfunc_104__12TObjEneDD_STFf(void *p);
extern "C" void is_target_in_attack_range__14TObjEneEpsilonFv();
extern "C" void update_movement_status__14TObjEneEpsilonFv();
extern "C" void vfunc_83__12TObjEneDD_STFv();
extern "C" void vfunc_29__9TObjCharaFv();
extern "C" void recalc_stats__9TObjCharaFv();
extern "C" void consume_timer_field__9TObjCharaFl();
extern "C" void vfunc_67__9TObjCharaFf();
extern "C" void vfunc_66__9TObjCharaFv();
extern "C" void get_anim_node_position__9TObjCharaFlP3Vec();
extern "C" void vfunc_60__9TObjCharaFv();
extern "C" void vfunc_59__9TObjCharaFv();
extern "C" void vfunc_58__9TObjCharaFv();
extern "C" void apply_slow_status__9TObjCharaFv();
extern "C" void update_shock_clock__9TObjCharaFv();
extern "C" void vfunc_43__9TObjCharaFv();
extern "C" void vfunc_18__9TObjCharaFPUc();
extern "C" void interact__14TObjCollidableFl();
extern "C" void vfunc_74__9TObjEnemyFl();
extern "C" void apply_hit_message_flags__9TObjEnemyFPv();
extern "C" void add_actor_exp__9TObjCharaFl();
extern "C" void apply_action_hold_status__9TObjCharaFf();
extern "C" void apply_anti_technique__9TObjCharaFl();
extern "C" void apply_attack_stat_status__9TObjCharaFPv();
extern "C" void apply_confusion_status__9TObjCharaFv();
extern "C" void apply_knockback_from_attacker__9TObjCharaFPUcf();
extern "C" void apply_movement_ailment__9TObjCharaFl();
extern "C" void apply_object_set_data__8TObjBaseFPv();
extern "C" void apply_paralysis__9TObjCharaFv();
extern "C" void apply_poison_status__9TObjCharaFv();
extern "C" void apply_set_data__9TObjEnemyFPv();
extern "C" void apply_shock_status__9TObjCharaFv();
extern "C" void apply_switch_attack__9TObjCharaFv();
extern "C" void calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf();
extern "C" void classify_actor_view_detail__8TObjBaseFfff();
extern "C" void clear_all_status_effects__9TObjCharaFv();
extern "C" void clear_harmful_statuses__9TObjCharaFv();
extern "C" void cure_paralysis__9TObjCharaFv();
extern "C" void cure_poison_ailment__9TObjCharaFv();
extern "C" void apply_defense_stat_status__9TObjCharaFPv();
extern "C" void enemy_spawn_jellen_effect__9TObjCharaFv();
extern "C" void enemy_spawn_zalure_effect__9TObjCharaFv();
extern "C" void vfunc_78__9TObjCharaFl();
extern "C" void vfunc_77__9TObjCharaFv();
extern "C" void vfunc_76__9TObjCharaFv();
extern "C" void vfunc_75__9TObjCharaFf();
extern "C" void clear_lobby_object_state__9TObjEnemyFv();
extern "C" void get_center__9TObjCharaFv();
extern "C" void get_actor_level_index__9TObjCharaFv();
extern "C" void get_name__9TObjEnemyFv();
extern "C" void get_pos__9TObjCharaFl();
extern "C" void is_actor_cadence_frame__9TObjCharaFl();
extern "C" void render_shadows__9TObjEnemyFv(u8 *arg0);
extern "C" void reset_motion_fields__9TObjCharaFv();
extern "C" void reset_pose__9TObjCharaFv();
extern "C" void roll_physical_accuracy__9TObjCharaFPvlf();
extern "C" void select_melee_contact_body__9TObjCharaFPvf();
extern "C" void trigger_switch_attack__9TObjCharaFv(s32 arg0);
extern "C" void try_start_action__9TObjCharaFll();
extern "C" void update_action_hold_status__9TObjCharaFv();
extern "C" s32 vfunc_37__9TObjCharaFv(u8 *arg0);
extern "C" void update_actor_ground_y__9TObjCharaFv();
extern "C" s32 update_attack_stat_status__9TObjCharaFv(u8 *arg0);
extern "C" s32 update_defense_stat_status__9TObjCharaFv(u8 *arg0);
extern "C" void update_flag30_timer__9TObjCharaFv();
extern "C" void update_object_view_visibility__8TObjBaseFff();
extern "C" void update_poison_status__9TObjCharaFv();
void *epsilon_guard_params[7] = {
    (void *)0x43160000, (void *)0x3f0e38e3, (void *)0x400, (void *)0x1e0000,
    (void *)0x0, (void *)0x1, (void *)0x0,
};
void *lbl_804F2024[4] = {
    (void *)0x10000, (void *)0x2, (void *)0x3f800000, (void *)0x0,
};
void *TObjEneEpsilonGuard__model_desc[22] = {
    (void *)0x0, (void *)0x41400000, (void *)0x0, (void *)0x40000000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x41400000, (void *)0x0, (void *)0x42100000, (void *)0x0,
    (void *)0x0, (void *)0x8003, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0,
};
void *__vt__19TObjEneEpsilonGuard[105] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__19TObjEneEpsilonGuardFv, (void *)&run_task__19TObjEneEpsilonGuardFv,
    (void *)&render__19TObjEneEpsilonGuardFv, (void *)&render_shadows__9TObjEnemyFv, (void *)&vfunc_6__8TObjBaseFPsl, (void *)&apply_object_set_data__8TObjBaseFPv,
    (void *)&reset_motion_fields__9TObjCharaFv, (void *)&get_center__9TObjCharaFv, (void *)&update_object_view_visibility__8TObjBaseFff, (void *)&classify_actor_view_detail__8TObjBaseFfff,
    (void *)&get_name__9TObjEnemyFv, (void *)&interact__14TObjCollidableFl, (void *)&add_actor_exp__9TObjCharaFl, (void *)&consume_timer_field__9TObjCharaFl,
    (void *)&get_actor_level_index__9TObjCharaFv, (void *)&update_actor_ground_y__9TObjCharaFv, (void *)&vfunc_18__9TObjCharaFPUc, (void *)&is_actor_cadence_frame__9TObjCharaFl,
    (void *)&select_melee_contact_body__9TObjCharaFPvf, (void *)&calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf, (void *)&receive_physical_attack__19TObjEneEpsilonGuardFPvf, (void *)&TObjEneEpsilonGuard__vt21,
    (void *)&receive_weapon_special_attack__19TObjEneEpsilonGuardFPvPv, (void *)&apply_knockback_from_attacker__9TObjCharaFPUcf, (void *)&try_start_action__9TObjCharaFll, (void *)&roll_physical_accuracy__9TObjCharaFPvlf,
    (void *)&vfunc_28__19TObjEneEpsilonGuardFv, (void *)&vfunc_29__9TObjCharaFv, (void *)&is_target_in_attack_range__14TObjEneEpsilonFv, (void *)&test_flag_256__9TObjCharaFv,
    (void *)&test_flag30_512__9TObjCharaFv, (void *)&has_flag_0x800__9TObjCharaFv, (void *)&test_flag_1000__9TObjCharaFv, (void *)&update_poison_status__9TObjCharaFv,
    (void *)&update_action_hold_status__9TObjCharaFv, (void *)&vfunc_37__9TObjCharaFv, (void *)&update_flag30_timer__9TObjCharaFv, (void *)&update_movement_status__14TObjEneEpsilonFv,
    (void *)&update_shock_clock__9TObjCharaFv, (void *)&update_attack_stat_status__9TObjCharaFv, (void *)&update_defense_stat_status__9TObjCharaFv, (void *)&vfunc_43__9TObjCharaFv,
    (void *)&apply_poison_status__9TObjCharaFv, (void *)&apply_paralysis__9TObjCharaFv, (void *)&apply_slow_status__9TObjCharaFv, (void *)&apply_confusion_status__9TObjCharaFv,
    (void *)&apply_movement_ailment__9TObjCharaFl, (void *)&apply_shock_status__9TObjCharaFv, (void *)&clear_harmful_statuses__9TObjCharaFv, (void *)&apply_attack_stat_status__9TObjCharaFPv,
    (void *)&apply_defense_stat_status__9TObjCharaFPv, (void *)&cure_poison_ailment__9TObjCharaFv, (void *)&cure_paralysis__9TObjCharaFv, (void *)&clear_all_status_effects__9TObjCharaFv,
    (void *)&apply_action_hold_status__9TObjCharaFf, (void *)&apply_anti_technique__9TObjCharaFl, (void *)&vfunc_58__9TObjCharaFv, (void *)&vfunc_59__9TObjCharaFv,
    (void *)&vfunc_60__9TObjCharaFv, (void *)&vfunc_61__19TObjEneEpsilonGuardFv, (void *)&vfunc_62__19TObjEneEpsilonGuardFv, (void *)&vfunc_63__19TObjEneEpsilonGuardFv,
    (void *)&reset_pose__9TObjCharaFv, (void *)&get_anim_node_position__9TObjCharaFlP3Vec, (void *)&vfunc_66__9TObjCharaFv, (void *)&vfunc_67__9TObjCharaFf,
    (void *)&get_pos__9TObjCharaFl, (void *)&apply_switch_attack__9TObjCharaFv, (void *)&enemy_spawn_jellen_effect__9TObjCharaFv, (void *)&trigger_switch_attack__9TObjCharaFv,
    (void *)&enemy_spawn_zalure_effect__9TObjCharaFv, (void *)&recalc_stats__9TObjCharaFv, (void *)&vfunc_74__9TObjEnemyFl, (void *)&vfunc_75__9TObjCharaFf,
    (void *)&vfunc_76__9TObjCharaFv, (void *)&vfunc_77__9TObjCharaFv, (void *)&vfunc_78__9TObjCharaFl, (void *)&vfunc_79__9TObjEneDDFPl,
    (void *)&apply_hit_message_flags__9TObjEnemyFPv, (void *)&apply_set_data__9TObjEnemyFPv, (void *)&clear_lobby_object_state__9TObjEnemyFv, (void *)&vfunc_83__12TObjEneDD_STFv,
    (void *)&vfunc_84__9TObjEneDDFv, (void *)&vfunc_85__9TObjEneDDFv, (void *)&vfunc_86__9TObjEneDDFv, (void *)&TObjEneEpsilonGuard__vt85,
    (void *)&vfunc_88__19TObjEneEpsilonGuardFv, (void *)&vfunc_89__19TObjEneEpsilonGuardFv, (void *)&vfunc_90__9TObjEneDDFv, (void *)&vfunc_91__9TObjEneDDFv,
    (void *)&vfunc_92__9TObjEneDDFv, (void *)&vfunc_93__9TObjEneDDFv, (void *)&vfunc_94__9TObjEneDDFv, (void *)&vfunc_95__9TObjEneDDFv,
    (void *)&vfunc_96__9TObjEneDDFv, (void *)&vfunc_97__9TObjEneDDFv, (void *)&vfunc_98__9TObjEneDDFv, (void *)&vfunc_99__9TObjEneDDFv,
    (void *)&vfunc_100__9TObjEneDDFv, (void *)&vfunc_101__9TObjEneDDFPUc, (void *)&vfunc_102__9TObjEneDDFv, (void *)&vfunc_103__9TObjEneDDFPUc,
    (void *)&vfunc_104__12TObjEneDD_STFf,
};

s32 TObjEneEpsilonGuard::calc_angle_to_target() {
    f32 temp_f3;

    this->enemy_copy_target_destination();
    temp_f3 = *(f32 *)((s8 *)((u8 *)this) + 0x38);
    return (s32) (lbl_80479C88 * atan2_float((f32) (temp_f3 - *(f32 *)((s8 *)((u8 *)this) + 0x394)), (f32) (*(f32 *)((s8 *)((u8 *)this) + 0x40) - *(f32 *)((s8 *)((u8 *)this) + 0x39C)), temp_f3));
}

#pragma push
#pragma fp_contract on
void TObjEneEpsilonGuard::set_orbit_destination(s32 arg1) {
    this->enemy_copy_target_destination();
    *(f32 *)((s8 *)((u8 *)this) + 0x394) = (f32) ((*(f32 *)((s8 *)(*(f32 * *)&TObjEneEpsilonGuard__movement_params) + 0) * sin_table_lookup(arg1)) + *(f32 *)((s8 *)((u8 *)this) + 0x394));
    *(f32 *)((s8 *)((u8 *)this) + 0x39C) = (f32) ((*(f32 *)((s8 *)(*(f32 * *)&TObjEneEpsilonGuard__movement_params) + 0) * cos_table_lookup(arg1)) + *(f32 *)((s8 *)((u8 *)this) + 0x39C));
}
#pragma pop

void TObjEneEpsilonGuard::vfunc_61() {  }
void TObjEneEpsilonGuard::vfunc_62() {  }
void TObjEneEpsilonGuard::vfunc_63() {  }
void TObjEneEpsilonGuard::vfunc_28() {  }

extern void *tl_04;

void TObjEneEpsilonGuard__vt85(TObjEneEpsilonGuard *ene_epsilon_guard, s32 arg1, s32 msg) {
    switch (arg1) {
    case 0:
        ene_epsilon_guard->handle_event(msg);
        return;
    case 1:
        ((s32 (*)(void *, s32))TObjEneEpsilonGuard__sub_8035E8C0)(ene_epsilon_guard, msg);
        return;
    case 2:
        ene_epsilon_guard->state_orbit(msg);
        return;
    case 3:
        ((s32 (*)(void *, s32))TObjEneEpsilonGuard__sub_8035E578)(ene_epsilon_guard, msg);
        return;
    case 4:
        ene_epsilon_guard->handle_break_state(msg);
        return;
    case 5:
        ene_epsilon_guard->handle_message(msg);
        return;
    }
}

#pragma push
#pragma fp_contract on
void run_task__19TObjEneEpsilonGuardFv(u8 *arg0) {
    s32 entity;
    if (((TObjEneEpsilonGuard *)(arg0))->vfunc_83() != 4) {
        ((TObjEneEpsilonGuard *)arg0)->update_guard_state();
        ((TObjEneEpsilonGuard *)(arg0))->vfunc_85();
        if (!(*(s32 *)((s8 *)arg0 + 0x46C) & 0x10)) {
            ((TObjEneEpsilonGuard *)(arg0))->vfunc_88();
            ((TObjEneEpsilonGuard *)arg0)->update_center_position();
            ((TObjEnemy *)arg0)->submit_default_cursor_candidate();
            ((TObjEneEpsilonGuard *)(arg0))->vfunc_100();
            return;
        }
        entity = (s32)find_entity_by_id((*(u16 *)((s8 *)arg0 + 0x470)));
        if (entity != 0) {
            ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)((void *)(arg0 + 0x38), (void *)(entity + 0x38));
            ((TObjEneEpsilonGuard *)arg0)->update_center_position();
        }
    } else if (*(s16 *)((s8 *)arg0 + 0x326) == 0) {
        ((TObjEneDD *)arg0)->transition_enemy_state(0);
    }
}
#pragma pop

void *TObjEneEpsilonGuard::create(void *arg1, void *arg2, void *arg3, void *arg4) {
    void *o;
    o = __nw__7TObjectFUl(0x4D8);
    if (o != NULL) {
        o = TObjEneEpsilonGuard__ct(o, tl_04, this, arg1, arg2, arg3, arg4);
    }
    return o;
}

u8 *__dt__19TObjEneEpsilonGuardFv(u8 *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(void ***)((s8 *)arg0 + 0x18) = __vt__19TObjEneEpsilonGuard;
        if (*(void **)((s8 *)arg0 + 0x440) != NULL) {
            queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x440));
            *(void **)((s8 *)arg0 + 0x440) = NULL;
        }
        if (*(void **)((s8 *)arg0 + 0x45C) != NULL) {
            free_collision_body_parts(*(void **)((s8 *)arg0 + 0x45C));
            if (*(VObj_8035F234 **)((s8 *)arg0 + 0x45C) != NULL) {
                (*(VObj_8035F234 **)((s8 *)arg0 + 0x45C))->m0(1);
            }
            *(void **)((s8 *)arg0 + 0x45C) = NULL;
        }
        free_collision_body_parts(arg0);
        __dt__13TUnk_80494938Fv(arg0 + 0x4BC, -1);
        __dt__14TObjEneEpsilonFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

void TObjEneEpsilonGuard::init_model_and_state() {
#define arg0 ((u8 *)this)

    void *o;

    ((TObjEneDD *)arg0)->init_position_vectors();
    *(s32 *)((s8 *)arg0 + 0x34) = get_bml_model(lbl_805D6FA0, 2);
    *(s32 *)((s8 *)arg0 + 0x24) = TObjFish__sub_8001EDB0(lbl_805D6FA0, 0);
    init_model__9TObjEneDDFv(arg0, TObjEneEpsilonGuard__model_desc, 1);
    ((TObjMotion *)arg0)->set_field_d8((s32)lbl_804F2024);
    ((TObjMotion *)arg0)->set_field_dc(*(s32 *)((s8 *)lbl_805D6FA0 + 0x430));
    *(s16 *)((s8 *)arg0 + 0xB8) = 0;
    ((TObjMotion *)arg0)->set_animation(*(s16 *)((s8 *)arg0 + 0xB8));
    ((TObjMotion *)arg0)->set_field_b8(*(s16 *)((s8 *)arg0 + 0xB8));
    reset_hp__9TObjEneDDFv(arg0, epsilon_guard_boss_stat_handle, epsilon_guard_shared_handler_b, epsilon_guard_registered_object_handle);
    ((TObjCollidable *)arg0)->set_indexed_flags(0, 0x80020);
    ((TObjEneDD *)arg0)->check_state_flag_4();
    *(void **)((s8 *)arg0 + 0x350) = epsilon_guard_params;
    initialize_enemy_state__9TObjEneDDFv(arg0, 0x57);
    ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(arg0 + 0x460, arg0 + 0x38);
    *(s32 *)((s8 *)arg0 + 0x46C) = 0;
    *(s32 *)((s8 *)arg0 + 0x46C) |= 0x10;
    ((VObj_18_b345b0 *)(arg0))->m93();
    *(s32 *)((s8 *)arg0 + 0x444) = get_bml_model(lbl_805D6FA0, 3);
    *(s32 *)((s8 *)arg0 + 0x448) = get_bml_motion(lbl_805D6FA0, 3);
    *(f32 *)((s8 *)arg0 + 0x454) = 0.0f;
    *(s32 *)((s8 *)arg0 + 0x450) = 0;
    *(s32 *)((s8 *)arg0 + 0x430) = 0;
    *(s32 *)((s8 *)arg0 + 0x434) = 0;
    *(s32 *)((s8 *)arg0 + 0x438) = 0;
    *(s32 *)((s8 *)arg0 + 0x43C) = 0;
    *(s16 *)((s8 *)arg0 + 0x326) = 0;
    ((VObj_18_b345b0 *)(arg0))->m85(*(s16 *)((s8 *)arg0 + 0x326), 4);
    o = __nw__7TObjectFUl(0xAC);
    if (o != NULL) {
        o = __ct__14TObjCollidableFP7TObject(o, 0);
    }
    *(void **)((s8 *)arg0 + 0x45C) = o;
    init_collision_body_parts(*(void **)((s8 *)arg0 + 0x45C), (u8 *) TObjEneEpsilonGuard__model_desc + 0x2C, 1);
    *(s32 *)((s8 *)arg0 + 0x440) = 0;
    ((TObjEneDD_ST *)arg0)->sub_800F5874(0x3F);
#undef arg0
}

void *TObjEneEpsilonGuard__ct(void *ene_epsilon_guard, void *arg1, void *arg2, void *arg3, void *arg4, void *arg5, void *arg6) {
    s32 i;
    TObjEneEpsilon__ct();
    *(void ***)((s8 *)ene_epsilon_guard + 0x18) = __vt__19TObjEneEpsilonGuard;
    __ct__13TUnk_80494938Fv(((u8 *)ene_epsilon_guard + 0x4BC));
    *(s32 *)((s8 *)ene_epsilon_guard + 0) = (s32) TObjEneEpsilonGuard__class_name;
    *(s16 *)((s8 *)ene_epsilon_guard + 0x470) = ((s16 (*)(void *))get_entity_id)(arg2);
    ((TObjEneDD *)ene_epsilon_guard)->init_common_from((u8 *)arg2);
    *(s16 *)((s8 *)ene_epsilon_guard + 0x1C) = (s16)(s32)arg3;
    *(s16 *)((s8 *)ene_epsilon_guard + 0x2C) = (s16)(s32)arg4;
    *(s16 *)((s8 *)ene_epsilon_guard + 0x28) = (s16) *(s16 *)((s8 *)arg2 + 0x28);
    *(s16 *)((s8 *)ene_epsilon_guard + 0x2A) = (s16) *(s16 *)((s8 *)arg2 + 0x2A);
    ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)((void *) ((u8 *)ene_epsilon_guard + 0x38), (void *)arg5);
    ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)((void *) ((u8 *)ene_epsilon_guard + 0x50), (void *) ((u8 *)arg2 + 0x50));
    *(s32 *)((s8 *)ene_epsilon_guard + 0x64) = 0;
    *(s32 *)((s8 *)ene_epsilon_guard + 0x5C) = 0;
    *(s32 *)((s8 *)ene_epsilon_guard + 0x60) = (s32)arg6;
    ((TObjEneEpsilonGuard *)ene_epsilon_guard)->init_model_and_state();
    ((TObjEneEpsilonGuard *)(ene_epsilon_guard))->vfunc_95();
    *(s32 *)((s8 *)ene_epsilon_guard + 0x46C) = (s32) (*(s32 *)((s8 *)ene_epsilon_guard + 0x46C) | 0x10);
    for (i = 0; i < 4; i++) {
        ((RenderFadeState *)(&((Self_8035F4B4 *)ene_epsilon_guard)->recs[i]))->activate_and_dispatch();
    }
    return ene_epsilon_guard;
}

}
