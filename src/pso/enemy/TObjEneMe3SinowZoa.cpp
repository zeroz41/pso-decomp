#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/enemy/TObjEneDD_ST.h"
#include "pso/enemy/TObjEneMe3SinowZoaReal.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TUnk_804806E8.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/object/TObjMotion.h"
#include "pso/enemy/TObjEneMe3SinowZoa.h"
extern "C" void has_flag_0x800__13TUnk_804806E8Fv();
extern "C" void test_flag30_512__13TUnk_804806E8Fv();
extern "C" void test_flag_1000__13TUnk_804806E8Fv();
extern "C" void test_flag_256__13TUnk_804806E8Fv();
#include "pso/object/obj_band.h"
#include "pso/system/vector.h"

#include <stddef.h>
#include "pso/TParticleCtrl.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/boss/TBoss8Dragon.h"
#include "pso/boss/TObjBoss2Tunnel.h"

#include "pso/enemy/TObjEneEpsilon.h"
#include "pso/enemy/TObjEneMe3ShinowaReal.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/enemy/TObjEneRecon.h"
#include "pso/misc/TScene.h"
#include "pso/misc/TTecResta.h"
#include "pso/misc/TTecSifta.h"
#include "pso/object/TObjFish.h"

#define V8(n) virtual void v##n();
#define V64(n) V8(n##0) V8(n##1) V8(n##2) V8(n##3) V8(n##4) V8(n##5) V8(n##6) V8(n##7)

struct Vec_803181A8 { f32 x, y, z; };

extern "C" {
f32 calc_boss4_scale__10TObjPlayerFi(s32);
s32 transition_enemy_state__9TObjEneDDFs(void *, int);
void advance_animation_playback(void *);
void play_sound_effect(s32, void *, s32, s32);
extern const f32 lbl_805DF334;
struct VBase_14_948132 { char pad[0x14]; };

struct VObj_14_948132 : VBase_14_948132 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual s32 m5();
};

struct Stack_80319B8C {
    s32 sp8;
    f32 spC;
};

struct Vec_80319E74 { f32 x, y; };

struct VBase_18_64d9d3 { char pad[0x18]; };

struct VObj_18_64d9d3 : VBase_18_64d9d3 {
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
    virtual s32 m92();
    virtual void m93();
    virtual void m94();
    virtual void m95();
    virtual void m96();
    virtual void m97();
    virtual void m98();
    virtual void m99();
    virtual s32 m100();
};

typedef struct Vec_80317F90 { f32 x; f32 y; f32 z; } Vec_80317F90;

struct VBase_18_e66632 { char pad[0x18]; };

struct VObj_18_e66632 : VBase_18_e66632 {
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
    virtual void m93();
    virtual s32 m94();
    virtual void m95();
    virtual void m96();
    virtual void m97();
    virtual void m98();
    virtual void m99();
    virtual s32 m100();
    virtual void m101();
    virtual void m102();
    virtual void m103();
    virtual s32 m104();
    virtual void m105();
    virtual void m106();
    virtual void m107();
    virtual void m108();
    virtual s32 m109();
};

struct RecoveredGlobal_8031A3D8_lbl_80542FDC {
    s32 value;
    u8 remaining[0x10];
};

struct B_8031A178 { u8 pad[0x18]; };

struct V_8031A178 : B_8031A178 {
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
    virtual void f87();
    virtual void f88();
    virtual void f89();
    virtual void f90();
    virtual void f91();
    virtual void f92();
    virtual void f93();
    virtual void f94();
    virtual void f95();
    virtual void f96();
    virtual void f97();
    virtual void f98();
    virtual void f99();
    virtual void f100();
    virtual void f101();
    virtual void f102();
    virtual void f103();
    virtual void f104();
    virtual void f105();
    virtual void f106();
    virtual void f107();
    virtual void f108();
    virtual void f109();
    virtual void f110();
    virtual void f111(s32);
};

struct Param_8031A2A0 { u8 pad[0x18]; s32 level; };

typedef char RecoveredGlobal_8031A3D8_lbl_80542FDC_size[sizeof(RecoveredGlobal_8031A3D8_lbl_80542FDC) == 0x14 ? 1 : -1];

struct T_8031A494 { u8 pad[0x354]; f32 f354; };

struct Base_8031A4E8 { char pad[0x18]; };

struct VObj_8031A4E8 : Base_8031A4E8 {
    virtual void m0();  virtual void m1();  virtual void m2();  virtual void m3();
    virtual void m4();  virtual void m5();  virtual void m6();  virtual void m7();
    virtual void m8();  virtual void m9();  virtual void m10(); virtual void m11();
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
    virtual void m84(); virtual void m85(); virtual void m86();
};

struct Base_8031A538 { char pad[0x18]; };

struct VObj_8031A538 : Base_8031A538 {
    V64(a) V64(b)
    V8(c0) V8(c1) V8(c2) V8(c3) V8(c4) V8(c5) V8(c6) V8(c7)
    V8(d0) V8(d1) V8(d2) V8(d3) V8(d4) V8(d5) V8(d6) V8(d7)
    V8(e0) V8(e1) V8(e2) V8(e3) V8(e4) V8(e5) V8(e6) V8(e7)
    V8(f0) V8(f1) V8(f2) V8(f3) V8(f4) V8(f5) V8(f6) V8(f7)
    V8(g0) V8(g1) V8(g2) V8(g3) V8(g4) V8(g5) V8(g6) V8(g7)
    V8(h0) V8(h1) V8(h2) V8(h3) V8(h4) V8(h5) V8(h6) V8(h7)
    V8(i0) V8(i1) V8(i2) V8(i3) V8(i4) V8(i5) V8(i6) V8(i7)
    V8(j0) V8(j1) V8(j2) V8(j3) V8(j4) V8(j5) V8(j6) V8(j7)
    V8(k0) V8(k1) V8(k2) V8(k3) V8(k4) V8(k5) V8(k6) V8(k7)
    V8(l0) V8(l1) V8(l2) V8(l3) V8(l4) V8(l5) V8(l6)
    virtual void m95();
    virtual void m96();
    f32 f3c_get();
};

struct VObj8031A598_Base { char pad[0x14]; };

struct VObj8031A598 : VObj8031A598_Base {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
};

struct VObj8031A5E0_Base { char pad[0x14]; };

struct VObj8031A5E0 : VObj8031A5E0_Base {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
};

struct RecoveredGlobal_800E7324_lbl_8043CF94 {
    s32 value;
    u8 remaining[0x8];
};

struct Vec_800E75AC { f32 x; f32 y; f32 z; };

struct Node_800E75AC { u8 pad[0x2c]; void *child; };

struct Obj_800E75AC { u8 pad[0x34]; Node_800E75AC *node; u8 pad2[0xc0 - 0x38]; f32 fc0; u8 pad3[0xf8 - 0xc4]; s32 ff8; };

struct Sub_800E750C { f32 f0; u8 pad4[4]; f32 f8; f32 fC; f32 f10; s32 f14; s32 f18; };

struct Obj_800E750C { u8 pad0[0x60]; s32 f60; u8 pad1[0xA4 - 0x64]; Sub_800E750C *fA4; };

struct VBase_18_bd3b49 { char pad[0x18]; };

struct VObj_18_bd3b49 : VBase_18_bd3b49 {
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
    virtual s32 m18(void *, f32);
    virtual void m19();
    virtual f32 m20(void *, f32);
    virtual void m21();
    virtual void m22();
    virtual s32 m23(void *, f32);
};

typedef char RecoveredGlobal_800E7324_lbl_8043CF94_size[sizeof(RecoveredGlobal_800E7324_lbl_8043CF94) == 0xC ? 1 : -1];

struct VBase_14_c143b1 { char pad[0x14]; };

struct VObj_14_c143b1 : VBase_14_c143b1 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual s32 m4();
    virtual s32 m5();
};

struct VBase_14_2ab9de { char pad[0x14]; };

struct VObj_14_2ab9de : VBase_14_2ab9de {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual s32 m3();
};

typedef struct Tbl_8031AF88 { u8 pad[0xC]; s32 t[3][2]; } Tbl_8031AF88;

s32 is_locally_controlled__10TObjPlayerFPv(void *);
u32 get_item_field_6__10TObjPlayerFPv(void *);
f32 fabs_float(f32);
void queue_destruction__7TObjectFv(void *);
void fn_8002B630(void *, void *, s32);
void *create_timed_particle_emitter(void *owner, s32 id, s32 b, s32 c);
void *spawn_particle_effect(void *pos, s32 id);
s32 get_item_id__5TItemFv();
}
void enemy_turn_and_move_on_ground(u8 *arg0, s32 arg1, f32 farg0);
extern "C" {
int select_and_apply_target__12TObjEneDD_STFf(void*);
void *__dt__12TObjEneDD_STFv(void *arg0, s16 arg1);
s32 check_v2_mode__9TObjEneDDFv(s32, s32);
s32 reset_hp__9TObjEneDDFv(void *, int, int, int);
s32 initialize_enemy_state__9TObjEneDDFv(void *, int);
int vfunc_96__9TObjEneDDFv(void*);
int vfunc_95__9TObjEneDDFv(void*);
void TObjEneDD__sub_800BA438(void *, void *);
s32 init_model__9TObjEneDDFv(void *, void *, int, int);
s32 TObjEneMe3SinowZoa__sub_800D72A4(void *);
s32 TObjEneMe3SinowZoa__sub_800D758C(void *);
void *__dt__13TUnk_80494938Fv(void *arg0, s16 arg1);
s32 TBoss3Volopt__sub_800D8D88(void *, f32);
f32 * TBoss3Volopt__sub_800F059C(void *);
s32 check_enemy_body_collisions(void *);
void free_collision_body_parts(void *);
void send_6x26_unequip_item__10TObjPlayerFPvPv(void *, s32);
void __dl__7TObjectFPv(void *);
void create__10TTecDebandFlll(void *, void *, int);
void create__9TTecJelinFllll(void *, void *, void *, int);
void create_instance__9TTecZaruaFllll(void *, void *, void *, int);
s32 TObjEneMe3SinowZoa__sub_80316840(void *);
s32 TObjEneMe3SinowZoa__sub_80316C3C(void *, s32);
void TObjEneMe3SinowZoa__sub_803170F0(u8 *arg0, s32 arg1);
void TObjEneMe3SinowZoa__sub_80317254(u8 *arg0, s32 arg1);
void TObjEneMe3SinowZoa__sub_80317B50(void *, s32);
void TObjEneMe3SinowZoa__sub_80317F90(u8 *arg0, s32 arg1);
void TObjEneMe3SinowZoa__sub_803182F8(u8 *, s32);
void TObjEneMe3SinowZoa__sub_80318564(u8 *, s32);
void TObjEneMe3SinowZoa__sub_8031884C(void *, s32);
void TObjEneMe3SinowZoa__sub_80318C0C(void *, s32);
struct Ene_80318F7C;
void TObjEneMe3SinowZoa__sub_80318F7C(Ene_80318F7C *, s32);
void TObjEneMe3SinowZoa__sub_80319748(u8 *arg0, s32 arg1);
void TObjEneMe3SinowZoa__sub_80319B8C(u8 *arg0, s32 arg1);
void action__18TObjEneMe3SinowZoaFPvi(u8 *arg0, s32 arg1);
void dispatch_state__18TObjEneMe3SinowZoaFPvUii(u8 *arg0, u32 arg1, s32 arg2);
void cast_technique__18TObjEneMe3SinowZoaFPv(u8 *arg0);
u8 sub_8031A454__18TObjEneMe3SinowZoaFv(u8 *arg0);
int select_and_apply_target__18TObjEneMe3SinowZoaFPv(void* p);
u8 is_outside_visible_range__18TObjEneMe3SinowZoaFv(T_8031A494 *self);
s32 sub_8031A4D0__18TObjEneMe3SinowZoaFv(u8 *arg0);
void vfunc_89__18TObjEneMe3SinowZoaFv(void *arg0);
void vfunc_112__18TObjEneMe3SinowZoaFv(void);
s32 try_run_effect_m7__18TObjEneMe3SinowZoaFv(u8 *arg0);
s32 try_run_effect_m6__18TObjEneMe3SinowZoaFv(u8 *arg0);
u8 is_target_in_range__18TObjEneMe3SinowZoaFv(void *arg0);
void vfunc_108__18TObjEneMe3SinowZoaFv(void);
void TObjEneMe3SinowZoa__sub_8031A6A0(u8 *arg0);
bool TObjEneMe3SinowZoa__sub_8031A820(u8 *arg0);
u8 check_body_collision_at__18TObjEneMe3SinowZoaFlf(Obj_800E750C *arg0, s32 arg1, f32 farg0);
void vfunc_96__18TObjEneMe3SinowZoaFv(void* p);
void vfunc_95__18TObjEneMe3SinowZoaFv(void* p);
void vfunc_88__18TObjEneMe3SinowZoaFv(void *arg0);
void vfunc_61__18TObjEneMe3SinowZoaFv(void);
void vfunc_28__18TObjEneMe3SinowZoaFv(void);
void run_task__18TObjEneMe3SinowZoaFv(u8 *arg0);
void * __dt__18TObjEneMe3SinowZoaFv(void *arg0, s16 arg1);
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
void bind_motion_context(s32, f32);
void compose_motion_node_matrix(void *arg0);
s32 matrix_mult_vec(int, void *, void *);
s32 push_matrix_from(void *);
s32 pop_matrix();

extern f32 *TObjEneMe3SinowZoa__kind_param_tbls[];
extern u8 *TObjEneMe3SinowZoa__data_805D6AD8;
extern s32 TObjEneMe3SinowZoa__data_805D6AE0;
extern const f32 TObjEneMe3SinowZoa__data_805DF2F0;
extern const f32 TObjEneMe3SinowZoa__data_805DF2F4;
extern const f32 TObjEneMe3SinowZoa__data_805DF2FC;
extern const f32 TObjEneMe3SinowZoa__data_805DF314;
extern const f32 TObjEneMe3SinowZoa__data_805DF31C;
extern const f32 TObjEneMe3SinowZoa__data_805DF320;
extern const f32 TObjEneMe3SinowZoa__data_805DF324;
extern const f32 TObjEneMe3SinowZoa__data_805DF328;
extern const f32 TObjEneMe3SinowZoa__data_805DF32C;
extern s32 __vt__18TObjEneMe3SinowZoa[];
extern u8 sinow_zoa_breakup_params[];
extern Tbl_8031AF88 lbl_80542FB0;
extern RecoveredGlobal_8031A3D8_lbl_80542FDC lbl_80542FDC;
extern u8 identity_matrix[];
extern s32 game_difficulty_selection;
extern const f32 lbl_805DF2F8;
extern const f32 lbl_805DF300;
extern const f32 lbl_805DF304;
extern const f32 lbl_805DF330;
extern const f32 lbl_805DF350;

extern const f32 lbl_805DF374;
extern const f32 lbl_805DF378;
extern f32 lbl_805DF37C;
extern f32 lbl_805DF380;
extern const f32 lbl_805DF384;
extern const f32 lbl_805DF388;
extern const f32 lbl_805DF38C;
#pragma push
#pragma fp_contract on
extern "C" {
void vfunc_6__13TUnk_804B9870FPsl();
}
extern "C" {
void vfunc_103__9TObjEneDDFPUc();
}
extern "C" {
void vfunc_79__9TObjEneDDFv();
}
extern "C" {
void TObjEneDD__vt82();
}
extern "C" {
void vfunc_85__9TObjEneDDFv();
}
extern "C" {
void vfunc_86__9TObjEneDDFv();
}
extern "C" {
void vfunc_90__9TObjEneDDFv();
}
extern "C" {
void vfunc_91__9TObjEneDDFv();
}
extern "C" {
void vfunc_92__9TObjEneDDFv();
}
extern "C" {
void vfunc_93__9TObjEneDDFv();
}
extern "C" {
void vfunc_94__9TObjEneDDFv();
}
extern "C" {
void vfunc_97__9TObjEneDDFv();
}
extern "C" {
void vfunc_98__9TObjEneDDFv();
}
extern "C" {
void vfunc_99__9TObjEneDDFv();
}
extern "C" {
void vfunc_100__9TObjEneDDFv();
}
extern "C" {
void vfunc_101__9TObjEneDDFPUc();
}
extern "C" {
void vfunc_102__9TObjEneDDFv();
}
extern "C" {
void vfunc_83__12TObjEneDD_STFv();
}
extern "C" {
void vfunc_107__22TObjEneMe3SinowZoaRealFv();
}
extern "C" {
void vfunc_111__22TObjEneMe3SinowZoaRealFv();
}
extern "C" {
void vfunc_62__22TObjEneMe3SinowZoaRealFv();
}
extern "C" {
void vfunc_63__22TObjEneMe3SinowZoaRealFv();
}
extern "C" {
void receive_damage_and_transition__18TObjEneMe3SinowZoaFPviii();
}
extern "C" {
void vfunc_115__18TObjEneMe3SinowZoaFv();
}
extern "C" {
void render__18TObjEneMe3SinowZoaFv(u8 *);
}
extern "C" {
void vfunc_29__13TUnk_804806E8Fv();
}
extern "C" {
void vfunc_73__13TUnk_804806E8Fv();
}
extern "C" {
void consume_timer_field__13TUnk_804806E8Fl();
}
extern "C" {
void vfunc_67__13TUnk_804806E8Ff();
}
extern "C" {
void vfunc_66__13TUnk_804806E8Fv();
}
extern "C" {
void get_anim_node_position__13TUnk_804806E8FlP3Vec();
}
extern "C" {
void vfunc_60__13TUnk_804806E8Fv();
}
extern "C" {
void vfunc_59__13TUnk_804806E8Fv();
}
extern "C" {
void vfunc_58__13TUnk_804806E8Fv();
}
extern "C" {
void apply_slow_status__13TUnk_804806E8Fv();
}
extern "C" {
void update_shock_clock__13TUnk_804806E8Fv();
}
extern "C" {
void vfunc_43__13TUnk_804806E8Fv();
}
extern "C" {
void vfunc_18__13TUnk_804806E8FPUc();
}
extern "C" {
void interact__13TUnk_804AF8A0Fl();
}
extern "C" {
void vfunc_74__9TObjEnemyFl();
}
extern "C" {
void apply_hit_message_flags__9TObjEnemyFPv();
}
extern "C" {
void *__dt__22TObjEneMe3SinowZoaRealFv(void *arg0, s16 arg1);
}
extern "C" {
void add_actor_exp__13TUnk_804806E8Fl();
}
extern "C" {
void apply_action_hold_status__13TUnk_804806E8Ff();
}
extern "C" {
void apply_anti_technique__13TUnk_804806E8Fl();
}
extern "C" {
void apply_attack_stat_status__13TUnk_804806E8FPv();
}
extern "C" {
void apply_confusion_status__13TUnk_804806E8Fv();
}
extern "C" {
void apply_knockback_from_attacker__13TUnk_804806E8FPUc();
}
extern "C" {
void apply_movement_ailment__13TUnk_804806E8Fl();
}
extern "C" {
void apply_object_set_data__13TUnk_804B9870FPv();
}
extern "C" {
void apply_paralysis__13TUnk_804806E8Fv();
}
extern "C" {
void apply_poison_status__13TUnk_804806E8Fv();
}
extern "C" {
void apply_set_data__9TObjEnemyFPv();
}
extern "C" {
void apply_shock_status__13TUnk_804806E8Fv();
}
extern "C" {
void apply_switch_attack__13TUnk_804806E8Fv();
}
extern "C" {
void calc_distance_accuracy_penalty__13TUnk_804806E8FPvPvPvf();
}
extern "C" {
void classify_actor_view_detail__13TUnk_804B9870Ffff();
}
extern "C" {
void clear_all_status_effects__13TUnk_804806E8Fv();
}
extern "C" {
void clear_harmful_statuses__13TUnk_804806E8Fv();
}
extern "C" {
void cure_paralysis__13TUnk_804806E8Fv();
}
extern "C" {
void cure_poison_ailment__13TUnk_804806E8Fv();
}
extern "C" {
void enemy_spawn_jellen_effect__13TUnk_804806E8Fv();
}
extern "C" {
void enemy_spawn_zalure_effect__13TUnk_804806E8Fv();
}
extern "C" {
void vfunc_78__13TUnk_804806E8Fl();
}
extern "C" {
void vfunc_77__13TUnk_804806E8Fv();
}
extern "C" {
void vfunc_76__13TUnk_804806E8Fv();
}
extern "C" {
void vfunc_75__13TUnk_804806E8Ff();
}
extern "C" {
void clear_lobby_object_state__9TObjEnemyFv();
}
extern "C" {
void vfunc_9__13TUnk_804806E8Fv();
}
extern "C" {
void get_actor_level_index__13TUnk_804806E8Fv();
}
extern "C" {
void get_name__9TObjEnemyFv();
}
extern "C" {
void get_pos__13TUnk_804806E8Fl();
}
extern "C" {
void is_actor_cadence_frame__13TUnk_804806E8Fl();
}
extern "C" {
void is_target_in_attack_range__13TUnk_804806E8Fv();
}
extern "C" {
extern u8 lbl_80475E2C[];
}
extern "C" {
extern u8 lbl_80475E3C[];
}
extern "C" {
extern u8 lbl_80475E54[];
}
extern "C" {
extern u8 lbl_80475E68[];
}
extern "C" {
extern u8 lbl_80475E84[];
}
extern "C" {
extern u8 lbl_80475E9C[];
}
extern "C" {
extern u8 lbl_80475EB4[];
}
extern "C" {
extern u8 lbl_80475EC8[];
}
extern "C" {
extern u8 lbl_80475EE0[];
}
extern "C" {
extern u8 lbl_80475EF4[];
}
extern "C" {
extern u8 lbl_80475F10[];
}
extern "C" {
extern u8 lbl_80475F24[];
}
extern "C" {
extern u8 lbl_80475F38[];
}
extern "C" {
extern u8 lbl_80475F54[];
}
extern "C" {
extern u8 lbl_80475F64[];
}
extern "C" {
void receive_physical_attack__13TUnk_804806E8FPvf();
}
extern "C" {
void receive_weapon_special_attack__13TUnk_804806E8FPvPv();
void apply_defense_stat_status__13TUnk_804806E8FPv();
}
extern "C" {
void render_shadows__9TObjEnemyFv(u8 *arg0);
}
extern "C" {
void reset_motion_fields__13TUnk_804806E8Fv();
}
extern "C" {
void reset_pose__13TUnk_804806E8Fv();
}
extern "C" {
void roll_physical_accuracy__13TUnk_804806E8FPvlf();
}
extern "C" {
void select_melee_contact_body__13TUnk_804806E8FPvf();
}
extern "C" {
void trigger_switch_attack__13TUnk_804806E8Fv(s32 arg0);
}
extern "C" {
void try_start_action__13TUnk_804806E8Fll();
}
extern "C" {
void update_action_hold_status__13TUnk_804806E8Fv();
}
extern "C" {
s32 vfunc_37__13TUnk_804806E8Fv(u8 *arg0);
}
extern "C" {
void update_actor_ground_y__13TUnk_804806E8Fv();
}
extern "C" {
s32 update_attack_stat_status__13TUnk_804806E8Fv(u8 *arg0);
}
extern "C" {
s32 update_defense_stat_status__13TUnk_804806E8Fv(u8 *arg0);
}
extern "C" {
void update_flag30_timer__13TUnk_804806E8Fv();
}
extern "C" {
void action__18TObjEneMe3SinowZoaFl();
}
extern "C" {
void update_movement_status__13TUnk_804806E8Fv();
}
extern "C" {
void update_object_view_visibility__13TUnk_804B9870Fff();
}
extern "C" {
void update_poison_status__13TUnk_804806E8Fv();
}
extern void *lbl_804E87F0[2];
extern void *lbl_804E87F8[16];
extern void *lbl_804E8838[2];
extern void *lbl_804E8840[16];
void *TObjEneMe3SinowZoa_init_params[7] = {
    (void *)0x43610000, (void *)0x0, (void *)0x600, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *sinow_zoa_collision_parts[11] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x41400000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
__declspec(section ".data") void *lbl_804E87F0[2] = {
    (void *)&lbl_80475E2C, (void *)0x0,
};
void *lbl_804E87F8[16] = {
    (void *)&lbl_80475E3C, (void *)&lbl_80475E54, (void *)&lbl_80475E68, (void *)&lbl_80475E84,
    (void *)&lbl_80475E9C, (void *)&lbl_80475EB4, (void *)&lbl_80475EC8, (void *)&lbl_80475EE0,
    (void *)&lbl_80475EF4, (void *)&lbl_80475F10, (void *)&lbl_80475F24, (void *)0x0,
    (void *)&lbl_80475F38, (void *)&lbl_804E87F0, (void *)&lbl_804E87F8, (void *)0x1000b,
};
__declspec(section ".data") void *lbl_804E8838[2] = {
    (void *)&lbl_80475F54, (void *)0x0,
};
void *lbl_804E8840[16] = {
    (void *)&lbl_80475E3C, (void *)&lbl_80475E54, (void *)&lbl_80475E68, (void *)&lbl_80475E84,
    (void *)&lbl_80475E9C, (void *)&lbl_80475EB4, (void *)&lbl_80475EC8, (void *)&lbl_80475EE0,
    (void *)&lbl_80475EF4, (void *)&lbl_80475F10, (void *)&lbl_80475F24, (void *)0x0,
    (void *)&lbl_80475F64, (void *)&lbl_804E8838, (void *)&lbl_804E8840, (void *)0x1000b,
};
void *lbl_804E8880[52] = {
    (void *)0x10000, (void *)0x0, (void *)0x3f000000, (void *)0x80000000,
    (void *)0x30000, (void *)0x1, (void *)0x3f333333, (void *)0x80000000,
    (void *)0x10000, (void *)0x9, (void *)0x3f000000, (void *)0x80000000,
    (void *)0x30000, (void *)0x2, (void *)0x3f4ccccd, (void *)0x0,
    (void *)0x30000, (void *)0x4, (void *)0x3ecccccd, (void *)0x0,
    (void *)0x30000, (void *)0x5, (void *)0x3f19999a, (void *)0x0,
    (void *)0x30000, (void *)0x6, (void *)0x3f333333, (void *)0x0,
    (void *)0x30000, (void *)0x7, (void *)0x3f800000, (void *)0x0,
    (void *)0x30000, (void *)0x8, (void *)0x3f800000, (void *)0x0,
    (void *)0x10000, (void *)0x9, (void *)0x3f000000, (void *)0x0,
    (void *)0x10000, (void *)0xa, (void *)0x3f8ccccd, (void *)0x0,
    (void *)0x30000, (void *)0x3, (void *)0x3f333333, (void *)0x0,
    (void *)0x30000, (void *)0x8, (void *)0x3f800000, (void *)0x0,
};
void *__vt__22TObjEneMe3SinowZoaReal[116] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__22TObjEneMe3SinowZoaRealFv, (void *)&run_task__18TObjEneMe3SinowZoaFv,
    (void *)&render__18TObjEneMe3SinowZoaFv, (void *)&render_shadows__9TObjEnemyFv, (void *)&vfunc_6__13TUnk_804B9870FPsl, (void *)&apply_object_set_data__13TUnk_804B9870FPv,
    (void *)&reset_motion_fields__13TUnk_804806E8Fv, (void *)&vfunc_9__13TUnk_804806E8Fv, (void *)&update_object_view_visibility__13TUnk_804B9870Fff, (void *)&classify_actor_view_detail__13TUnk_804B9870Ffff,
    (void *)&get_name__9TObjEnemyFv, (void *)&interact__13TUnk_804AF8A0Fl, (void *)&add_actor_exp__13TUnk_804806E8Fl, (void *)&consume_timer_field__13TUnk_804806E8Fl,
    (void *)&get_actor_level_index__13TUnk_804806E8Fv, (void *)&update_actor_ground_y__13TUnk_804806E8Fv, (void *)&vfunc_18__13TUnk_804806E8FPUc, (void *)&is_actor_cadence_frame__13TUnk_804806E8Fl,
    (void *)&select_melee_contact_body__13TUnk_804806E8FPvf, (void *)&calc_distance_accuracy_penalty__13TUnk_804806E8FPvPvPvf, (void *)&receive_physical_attack__13TUnk_804806E8FPvf, (void *)&receive_damage_and_transition__18TObjEneMe3SinowZoaFPviii,
    (void *)&receive_weapon_special_attack__13TUnk_804806E8FPvPv, (void *)&apply_knockback_from_attacker__13TUnk_804806E8FPUc, (void *)&try_start_action__13TUnk_804806E8Fll, (void *)&roll_physical_accuracy__13TUnk_804806E8FPvlf,
    (void *)&vfunc_28__18TObjEneMe3SinowZoaFv, (void *)&vfunc_29__13TUnk_804806E8Fv, (void *)&is_target_in_attack_range__13TUnk_804806E8Fv, (void *)&test_flag_256__13TUnk_804806E8Fv,
    (void *)&test_flag30_512__13TUnk_804806E8Fv, (void *)&has_flag_0x800__13TUnk_804806E8Fv, (void *)&test_flag_1000__13TUnk_804806E8Fv, (void *)&update_poison_status__13TUnk_804806E8Fv,
    (void *)&update_action_hold_status__13TUnk_804806E8Fv, (void *)&vfunc_37__13TUnk_804806E8Fv, (void *)&update_flag30_timer__13TUnk_804806E8Fv, (void *)&update_movement_status__13TUnk_804806E8Fv,
    (void *)&update_shock_clock__13TUnk_804806E8Fv, (void *)&update_attack_stat_status__13TUnk_804806E8Fv, (void *)&update_defense_stat_status__13TUnk_804806E8Fv, (void *)&vfunc_43__13TUnk_804806E8Fv,
    (void *)&apply_poison_status__13TUnk_804806E8Fv, (void *)&apply_paralysis__13TUnk_804806E8Fv, (void *)&apply_slow_status__13TUnk_804806E8Fv, (void *)&apply_confusion_status__13TUnk_804806E8Fv,
    (void *)&apply_movement_ailment__13TUnk_804806E8Fl, (void *)&apply_shock_status__13TUnk_804806E8Fv, (void *)&clear_harmful_statuses__13TUnk_804806E8Fv, (void *)&apply_attack_stat_status__13TUnk_804806E8FPv,
    (void *)&apply_defense_stat_status__13TUnk_804806E8FPv, (void *)&cure_poison_ailment__13TUnk_804806E8Fv, (void *)&cure_paralysis__13TUnk_804806E8Fv, (void *)&clear_all_status_effects__13TUnk_804806E8Fv,
    (void *)&apply_action_hold_status__13TUnk_804806E8Ff, (void *)&apply_anti_technique__13TUnk_804806E8Fl, (void *)&vfunc_58__13TUnk_804806E8Fv, (void *)&vfunc_59__13TUnk_804806E8Fv,
    (void *)&vfunc_60__13TUnk_804806E8Fv, (void *)&vfunc_61__18TObjEneMe3SinowZoaFv, (void *)&vfunc_62__22TObjEneMe3SinowZoaRealFv, (void *)&vfunc_63__22TObjEneMe3SinowZoaRealFv,
    (void *)&reset_pose__13TUnk_804806E8Fv, (void *)&get_anim_node_position__13TUnk_804806E8FlP3Vec, (void *)&vfunc_66__13TUnk_804806E8Fv, (void *)&vfunc_67__13TUnk_804806E8Ff,
    (void *)&get_pos__13TUnk_804806E8Fl, (void *)&apply_switch_attack__13TUnk_804806E8Fv, (void *)&enemy_spawn_jellen_effect__13TUnk_804806E8Fv, (void *)&trigger_switch_attack__13TUnk_804806E8Fv,
    (void *)&enemy_spawn_zalure_effect__13TUnk_804806E8Fv, (void *)&vfunc_73__13TUnk_804806E8Fv, (void *)&vfunc_74__9TObjEnemyFl, (void *)&vfunc_75__13TUnk_804806E8Ff,
    (void *)&vfunc_76__13TUnk_804806E8Fv, (void *)&vfunc_77__13TUnk_804806E8Fv, (void *)&vfunc_78__13TUnk_804806E8Fl, (void *)&vfunc_79__9TObjEneDDFv,
    (void *)&apply_hit_message_flags__9TObjEnemyFPv, (void *)&apply_set_data__9TObjEnemyFPv, (void *)&clear_lobby_object_state__9TObjEnemyFv, (void *)&vfunc_83__12TObjEneDD_STFv,
    (void *)&TObjEneDD__vt82, (void *)&vfunc_85__9TObjEneDDFv, (void *)&vfunc_86__9TObjEneDDFv, (void *)&dispatch_state__18TObjEneMe3SinowZoaFPvUii,
    (void *)&vfunc_88__18TObjEneMe3SinowZoaFv, (void *)&vfunc_89__18TObjEneMe3SinowZoaFv, (void *)&vfunc_90__9TObjEneDDFv, (void *)&vfunc_91__9TObjEneDDFv,
    (void *)&vfunc_92__9TObjEneDDFv, (void *)&vfunc_93__9TObjEneDDFv, (void *)&vfunc_94__9TObjEneDDFv, (void *)&vfunc_95__18TObjEneMe3SinowZoaFv,
    (void *)&vfunc_96__18TObjEneMe3SinowZoaFv, (void *)&vfunc_97__9TObjEneDDFv, (void *)&vfunc_98__9TObjEneDDFv, (void *)&vfunc_99__9TObjEneDDFv,
    (void *)&vfunc_100__9TObjEneDDFv, (void *)&vfunc_101__9TObjEneDDFPUc, (void *)&vfunc_102__9TObjEneDDFv, (void *)&vfunc_103__9TObjEneDDFPUc,
    (void *)&select_and_apply_target__18TObjEneMe3SinowZoaFPv, (void *)&TObjEneMe3SinowZoa__sub_8031A6A0, (void *)&is_target_in_range__18TObjEneMe3SinowZoaFv, (void *)&vfunc_107__22TObjEneMe3SinowZoaRealFv,
    (void *)&vfunc_108__18TObjEneMe3SinowZoaFv, (void *)&try_run_effect_m6__18TObjEneMe3SinowZoaFv, (void *)&try_run_effect_m7__18TObjEneMe3SinowZoaFv, (void *)&vfunc_111__22TObjEneMe3SinowZoaRealFv,
    (void *)&vfunc_112__18TObjEneMe3SinowZoaFv, (void *)&action__18TObjEneMe3SinowZoaFPvi, (void *)&action__18TObjEneMe3SinowZoaFl, (void *)&vfunc_115__18TObjEneMe3SinowZoaFv,
};
#define sinow_zoa_collision_parts ((u8 *)sinow_zoa_collision_parts)

struct VBase_14_aa9368 { char pad[0x14]; };
struct VObj_14_aa9368 : VBase_14_aa9368 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual s32 m6();
    virtual s32 m7();
};
struct VBase_18_fc0b09 { char pad[0x18]; };
struct VObj_18_fc0b09 : VBase_18_fc0b09 {
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
    virtual void m97();
    virtual void m98();
    virtual void m99();
    virtual void m100();
    virtual void m101();
    virtual void m102();
    virtual void m103();
    virtual void m104();
    virtual void m105();
    virtual s32 m106();
    virtual s32 m107();
    virtual s32 m108();
    virtual void m109();
    virtual void m110();
    virtual void m111();
    virtual void m112();
    virtual s32 m113();
};

struct Zoa_8031786C {
    u8 pad0[0x3C0];
    s32 f3C0;
    u8 pad3C4[0x3CC - 0x3C4];
    s32 f3CC;
    s32 f3D0;
    u8 pad3D4[0x3F8 - 0x3D4];
    s32 f3F8;
    u8 pad3FC[0x414 - 0x3FC];
    VObj_14_aa9368 sub;
};

s32 is_main_phase_15__9TObjEneDDFv();
s32 defer_render__7TObjectFv(void *);
s32 rotate_matrix_y(int, int);
void translate_matrix(u32 arg0, f32 x, f32 y, f32 z);
s32 push_matrix();
s32 post_translate_matrix(void *);
extern u8 saved_model_draw_color[];
extern s32 *lbl_80542FF0[];
extern u8 model_material_color[];
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 lbl_805D6ADC;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;
extern const f32 lbl_805D9E84;
extern const f32 lbl_805D9E88;
extern const f32 lbl_805DF318;

#define v ((VObj_18_fc0b09 *)((u8 *)this))
void TObjEneMe3SinowZoa::render() {
    s32 mode;
    s32 draw;
    s32 i;
    Zoa_8031786C *o = (Zoa_8031786C *)this;

    if (TObjPlayer::check_demo_mode() != 0) {
        v->m113();
        return;
    }
    sub_8031A454__18TObjEneMe3SinowZoaFv(((u8 *)this));
    if (o->f3CC & 2) {
        mode = 0;
    } else if (is_main_phase_15__9TObjEneDDFv() != 0) {
        mode = v->m9(lbl_805D9E88, lbl_805D9E84, TObjEneMe3SinowZoa__data_805DF2F0);
    } else if (v->m8(lbl_805DF318, TObjEneMe3SinowZoa__data_805DF2F0) != 0) {
        mode = 1;
    } else {
        mode = 0;
    }
    if (mode != 0) {
        if (this->render_model_if_visible() != 0) {
            return;
        }
        this->update_secondary_light();
        saved_model_render_flags = model_render_flags;
        saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
        saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
        copy_argb((NJS_ARGB *)saved_model_draw_color, (NJS_ARGB *)model_material_color);
        if (!(o->f3D0 & 0x4000)) {
            v->m106();
            TObjEneDD::clear_global_flag_400();
        }
        TObjPlayer::toggle_particle_effect();
        TObjFish::set_global_param(*(s32 *)(((u8 *)this) + 0x24));
        for (i = 0; i < 3; i++) {
            if (lbl_80542FF0[i] != NULL) {
                *lbl_80542FF0[i] = o->f3F8;
            }
        }
        draw = 1;
        if (v->m107() != 0) {
            if (defer_render__7TObjectFv(this) != 0) {
                draw = 0;
            } else if (o->f3C0 != 0) {
                draw = 0;
            }
        } else if (TObjEneMe3SinowZoa__sub_800D72A4(&o->sub) != 0) {
            o->sub.m6();
            if (defer_render__7TObjectFv(this) != 0) {
                draw = 0;
            }
        } else if (o->f3C0 != 0) {
            draw = 0;
        }
        if (draw != 0) {
            push_matrix();
            post_translate_matrix(((u8 *)this) + 0x38);
            translate_matrix(0, TObjEneMe3SinowZoa__data_805DF31C, *(f32 *)(((u8 *)this) + 0x3E4), TObjEneMe3SinowZoa__data_805DF31C);
            rotate_matrix_y(0, *(s32 *)(((u8 *)this) + 0x60));
            lbl_805D6ADC = 0;
            if (mode == 1) {
                this->draw();
            } else {
                this->render_world_model();
            }
            pop_matrix();
        }
        if (v->m108() == 0 && TObjEneMe3SinowZoa__sub_800D72A4(&o->sub) != 0) {
            o->sub.m7();
        }
        copy_argb((NJS_ARGB *)model_material_color, (NJS_ARGB *)saved_model_draw_color);
        chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
        chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
        model_render_flags = saved_model_render_flags;
        this->update_primary_light();
    }
    TParticleCtrl::end_effect_render();
}

#undef v

struct VBase_14_c5778e { char pad[0x14]; };
struct VObj_14_c5778e : VBase_14_c5778e {
    virtual void m0();
    virtual s32 m1(s32);
    virtual void m2();
    virtual void m3();
    virtual s32 m4();
};
struct Vec_80317B50 { f32 x, y, z; };
u32 csnVectorUnder(void *, void *, int);
u32 csnVector(void *, void *, int);
s32 check_move_collision__18TObjEneMe3SinowZoaFPvPv(void *, void *);
extern const f32 TObjEneMe3SinowZoa__data_805DF308;

#pragma push
#pragma fp_contract on
void TObjEneMe3SinowZoa__sub_80317B50(void *arg0_, s32 arg1) {
    Vec_80317B50 v;
    Vec_80317B50 pos;
    Vec_80317B50 tmp;
    s32 d[3];
    s32 i;
    u8 *ene_me3_sinow_zoa = (u8 *)arg0_;

    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)ene_me3_sinow_zoa + 0xB8) = 0xC;
        ((TObjEneDD *)ene_me3_sinow_zoa)->set_field_378(0xC);
        ((TObjEneMe3SinowZoa *)ene_me3_sinow_zoa)->vfunc_95();
        *(s32 *)((s8 *)ene_me3_sinow_zoa + 0x3CC) &= 0xFFEFFFF9;
        *(s32 *)((s8 *)ene_me3_sinow_zoa + 0x3CC) |= 1;
        *(s32 *)((s8 *)ene_me3_sinow_zoa + 0x434) = 0;
        break;
    case 3:
        if (*(s32 *)((s8 *)ene_me3_sinow_zoa + 0x434) == 2) {
            *(s32 *)((s8 *)ene_me3_sinow_zoa + 0x3C0) = 1;
            *(s32 *)((s8 *)ene_me3_sinow_zoa + 0x3CC) |= 0x40000;
            ((TUnk_804AF8A0 *)ene_me3_sinow_zoa)->set_indexed_flags(0, 0x08000000);
            if (calc_boss4_scale__10TObjPlayerFi((s32)ene_me3_sinow_zoa) <= *(f32 *)((s8 *)ene_me3_sinow_zoa + 0x3E8)) {
                if (((s32 (*)(u8 *))sub_8031A454__18TObjEneMe3SinowZoaFv)(ene_me3_sinow_zoa) != 0) {
                    if (calc_boss4_scale__10TObjPlayerFi((s32)ene_me3_sinow_zoa) > TObjEneMe3SinowZoa__kind_param_tbls[*(s32 *)((s8 *)ene_me3_sinow_zoa + 0x3C8)][5]) {
                        transition_enemy_state__9TObjEneDDFs(ene_me3_sinow_zoa, 0x10);
                    } else {
                        transition_enemy_state__9TObjEneDDFs(ene_me3_sinow_zoa, 0xB);
                    }
                } else {
                    transition_enemy_state__9TObjEneDDFs(ene_me3_sinow_zoa, 0x10);
                }
            } else {
                transition_enemy_state__9TObjEneDDFs(ene_me3_sinow_zoa, 1);
            }
        }
        break;
    case 0:
        switch (*(s32 *)((s8 *)ene_me3_sinow_zoa + 0x434)) {
        case 0:
            advance_animation_playback(ene_me3_sinow_zoa);
            if (((TObjEneDD *)ene_me3_sinow_zoa)->get_flag_b4() != 0) {
                *(s32 *)((s8 *)ene_me3_sinow_zoa + 0x3CC) |= 4;
                play_sound_effect(0x4003AD2F, ene_me3_sinow_zoa + 0x38, 0, 0);
                ((VObj_14_c5778e *)(ene_me3_sinow_zoa + 0x414))->m1(0x1E);
                VecCopy((Vec *)&v, (const Vec *)(ene_me3_sinow_zoa + 0x38));
                v.y = *(f32 *)((s8 *)ene_me3_sinow_zoa + 0x3E0) - TObjEneMe3SinowZoa__data_805DF320;
                *(s32 *)((s8 *)ene_me3_sinow_zoa + 0x434) = 1;
            }
            ((TObjEneMe3SinowZoa *)ene_me3_sinow_zoa)->vfunc_102();
            ((TObjEneMe3SinowZoa *)ene_me3_sinow_zoa)->vfunc_89();
            break;
        case 1:
            if (((VObj_14_c5778e *)(ene_me3_sinow_zoa + 0x414))->m4() != 0) {
                *(s32 *)((s8 *)ene_me3_sinow_zoa + 0x3CC) |= 2;
                if (((TObjEneDD_ST *)ene_me3_sinow_zoa)->update_linked_position(TObjEneMe3SinowZoa__data_805DF324) != 0) {
                    if (*(u8 **)((s8 *)ene_me3_sinow_zoa + 0x390) == NULL) {
                        break;
                    }
                    d[0] = (s32)(TObjEneMe3SinowZoa__data_805DF328 * calc_boss4_scale__10TObjPlayerFi((s32)ene_me3_sinow_zoa)) - 1;
                    d[1] = (s32)(TObjEneMe3SinowZoa__data_805DF32C * calc_boss4_scale__10TObjPlayerFi((s32)ene_me3_sinow_zoa)) - 1;
                    if (d[1] <= d[0]) {
                        d[1]++;
                    }
                    d[2] = -(d[0] + d[1]);
                    for (i = 0; i < 3; i++) {
                        s32 ang;
                        VecCopy((Vec *)&pos, (const Vec *)(*(u8 **)((s8 *)ene_me3_sinow_zoa + 0x390) + 0x38));
                        ang = *(s32 *)((s8 *)(*(u8 **)((s8 *)ene_me3_sinow_zoa + 0x390)) + 0x60) + ((d[i] + 1) << 14);
                        pos.x += TObjEneMe3SinowZoa__data_805DF320 * cos_table_lookup(ang);
                        pos.z -= TObjEneMe3SinowZoa__data_805DF320 * sin_table_lookup(ang);
                        pos.y += TObjEneMe3SinowZoa__data_805DF308;
                        VecCopy((Vec *)&tmp, (const Vec *)&pos);
                        tmp.x += pos.x - *(f32 *)((s8 *)(*(u8 **)((s8 *)ene_me3_sinow_zoa + 0x390)) + 0x38);
                        tmp.z += pos.z - *(f32 *)((s8 *)(*(u8 **)((s8 *)ene_me3_sinow_zoa + 0x390)) + 0x40);
                        if (check_move_collision__18TObjEneMe3SinowZoaFPvPv(ene_me3_sinow_zoa, &tmp) == 0 &&
                            csnVector(*(u8 **)((s8 *)ene_me3_sinow_zoa + 0x390) + 0x38, &tmp, 0x88E0) == 0 &&
                            csnVectorUnder(&pos, ene_me3_sinow_zoa + 0x120, 0x15) != 0 &&
                            *(s16 *)((s8 *)ene_me3_sinow_zoa + 0x28) == ((TScene *)(&pos))->find_section_at_position()) {
                            VecCopy((Vec *)(ene_me3_sinow_zoa + 0x38), (const Vec *)&pos);
                            *(s32 *)((s8 *)ene_me3_sinow_zoa + 0x60) = ang + 0xC000;
                            break;
                        }
                    }
                }
                *(s32 *)((s8 *)ene_me3_sinow_zoa + 0x434) = 2;
            }
            break;
        }
        break;
    case 5:
        *(s32 *)((s8 *)ene_me3_sinow_zoa + 0x3CC) &= ~4;
        break;
    }
}
#pragma pop

void TObjEneMe3SinowZoa__sub_80317F90(u8 *arg0, s32 arg1) {
    Vec_80317F90 v;
    Vec_80317F90 p;
    *(s32 *)((s8 *)arg0 + 0x3C0) = 0;
    switch (arg1) {
    case 3:
    case 5:
        break;
    case 4:
        *(s16 *)((s8 *)arg0 + 0xB8) = 5;
        ((TBoss8Dragon *)arg0)->refresh_and_send_entity_flags();
        ((VObj_18_64d9d3 *)(arg0))->m92();
        *(s32 *)((s8 *)arg0 + 0x3CC) = (s32) (*(s32 *)((s8 *)arg0 + 0x3CC) & 0xFFEFFFF8);
        *(s32 *)((s8 *)arg0 + 0x434) = 0;
        break;
    case 0:
        switch (*(s32 *)((s8 *)arg0 + 0x434)) {
        case 0:
            advance_animation_playback(arg0);
            if (objInBand((GameObj *)arg0, (f32)lbl_805DF330) != 0 || objInBand((GameObj *)((GameObj *)arg0), (f32)((f32)lbl_805DF300)) != 0) {
                play_sound_effect(0x4003A82A, arg0 + 0x38, 0, 0);
            }
            if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
                *(s32 *)((s8 *)arg0 + 0x434) = 1;
                *(s32 *)((s8 *)arg0 + 0x438) = 0;
                v.x = TObjEneMe3SinowZoa__data_805DF31C;
                v.y = TObjEneMe3SinowZoa__data_805DF314;
                v.z = TObjEneMe3SinowZoa__data_805DF320;
                ((TObjBoss2Tunnel *)(&v))->init_zako(arg0 + 0x38, *(s32 *)((s8 *)arg0 + 0x60));
                TObjPlayer::spawn_effect_f8((s32)&v, 0x14);
            }
            break;
        case 1:
            *(s32 *)((s8 *)arg0 + 0x438) += 1;
            if (*(s32 *)((s8 *)arg0 + 0x438) >= 0x14) {
                *(s32 *)((s8 *)arg0 + 0x434) = 2;
                *(s32 *)((s8 *)arg0 + 0x3CC) |= 2;
                TBoss3Volopt::create_breakup_mdl((s32)TObjEneMe3SinowZoa__data_805D6AE0, (s32)sinow_zoa_breakup_params, (s32)(*(s32 *)((s8 *)arg0 + 0x24)), (s32)(arg0 + 0x38), (s32)(*(s32 *)((s8 *)arg0 + 0x60)));
                VecCopy((Vec *)&p, (const Vec *)(arg0 + 0x38));
                p.x += TObjEneMe3SinowZoa__data_805DF320 * sin_table_lookup(*(s32 *)((s8 *)arg0 + 0x60));
                p.z += TObjEneMe3SinowZoa__data_805DF320 * cos_table_lookup(*(s32 *)((s8 *)arg0 + 0x60));
                ((TObjPlayer *)(&p))->trigger_dell_biter_events();
                play_sound_effect(0x4003AD2E, arg0 + 0x38, 0, 0);
            }
            ((VObj_18_64d9d3 *)(arg0))->m100();
            break;
        case 2:
            queue_destruction__7TObjectFv(arg0);
            break;
        }
        break;
    }
}
#pragma pop

struct VBase_14_803182F8 { char pad[0x14]; };
struct VObj_14_803182F8 : VBase_14_803182F8 {
    virtual void m0();
    virtual void m1(s32);
    virtual void m2();
    virtual void m3();
    virtual s32 m4();
};

extern "C" {

void TObjEneMe3SinowZoa::state_knockback(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    Vec_803181A8 v;
    f32 len;
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)arg0 + 0xB8) = 4;
        advance_animation_playback(arg0);
        ((TObjEneDD_ST *)arg0)->set_active();
        play_sound_effect(0x4003A82D, arg0 + 0x38, 0, 0);
        *(s32 *)((s8 *)arg0 + 0x3CC) &= 0xFFEFFFF8;
        break;
    case 3:
        if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
            if (*(s32 *)((s8 *)arg0 + 0x3C0) == 1 && calc_boss4_scale__10TObjPlayerFi((s32)arg0) <= *(f32 *)((s8 *)arg0 + 0x3F0)) {
                transition_enemy_state__9TObjEneDDFs(arg0, 0x12);
            } else {
                transition_enemy_state__9TObjEneDDFs(arg0, *(s32 *)((s8 *)arg0 + 0x378));
            }
        }
        break;
    case 0:
        advance_animation_playback(arg0);
        VecCopy((Vec *)&v, (const Vec *)(arg0 + 0x308));
        len = ((TObjBoss2Tunnel *)(&v))->clamp_velocity();
        ((TObjEneDD *)arg0)->move_clamped_on_ground(v.x, v.z, len);
        *(f32 *)((s8 *)arg0 + 0x308) *= lbl_805DF334;
        *(f32 *)((s8 *)arg0 + 0x310) *= lbl_805DF334;
        this->vfunc_89();
        break;
    case 5:
        ((TObjEneDD *)arg0)->clear_attack_receipts();
        ((TObjEneDD *)arg0)->clear_field_388();
        break;
    }
}

void TObjEneMe3SinowZoa__sub_803182F8(u8 *ene_dd, s32 arg1) {
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)ene_dd + 0xB8) = 8;
        ((TObjEneDD *)ene_dd)->set_field_378(6);
        ((TObjEneDD *)(ene_dd))->vfunc_95();
        *(s32 *)((s8 *)ene_dd + 0x3CC) = (s32) (*(s32 *)((s8 *)ene_dd + 0x3CC) & 0xFFEFFFFC);
        *(s32 *)((s8 *)ene_dd + 0x3CC) = (s32) (*(s32 *)((s8 *)ene_dd + 0x3CC) | 4);
        ((VObj_14_803182F8 *)(ene_dd + 0x414))->m1(0x1E);
        ((VObj_14_803182F8 *)(ene_dd + 0x414))->m2();
        *(s32 *)((s8 *)ene_dd + 0x434) = 1;
        break;
    case 3:
        if (*(s32 *)((s8 *)ene_dd + 0x434) == 2) {
            transition_enemy_state__9TObjEneDDFs(ene_dd, 0);
        }
        break;
    case 0:
        advance_animation_playback(ene_dd);
        switch (*(s32 *)((s8 *)ene_dd + 0x434)) {
        case 0:
            if (((TObjEneDD *)ene_dd)->get_flag_b4() != 0) {
                *(s32 *)((s8 *)ene_dd + 0x434) = 1;
            }
            break;
        case 1:
            if (((VObj_14_803182F8 *)(ene_dd + 0x414))->m4() != 0) {
                *(s32 *)((s8 *)ene_dd + 0x434) = 2;
            }
            break;
        }
        ((TObjEneDD *)(ene_dd))->vfunc_102();
        break;
    case 5:
        *(s32 *)((s8 *)ene_dd + 0x3CC) = (s32) (*(s32 *)((s8 *)ene_dd + 0x3CC) & 0xFFFFFFFB);
        break;
    }
}

}

extern "C" {

void TObjEneMe3SinowZoa::handle_state_substate(s32 arg1) {
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)this + 0xB8) = 9;
        set_field_378(0xD);
        *(u32 *)((s8 *)this + 0x3CC) &= 0xFFEFFFF8;
        this->vfunc_95();
        *(s32 *)((s8 *)this + 0x3FC) = 0;
        *(s32 *)((s8 *)this + 0x434) = 0;
        break;
    case 3:
        if (update_linked_position(TObjEneMe3SinowZoa__data_805DF324) != 0) {
            transition_enemy_state__9TObjEneDDFs(this, 6);
        } else if (*(s32 *)((s8 *)this + 0x434) >= 0x5A) {
            transition_enemy_state__9TObjEneDDFs(this, 0xA);
        }
        break;
    case 5:
        break;
    case 0:
        (*(s32 *)((s8 *)this + 0x434))++;
        advance_animation_playback(this);
        this->vfunc_102();
        this->vfunc_89();
        break;
    }
}

}

struct Base18_80318564 { char pad[0x18]; };
struct VObj_80318564 : Base18_80318564 {
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
    virtual void m97();
    virtual void m98();
    virtual void m99();
    virtual void m100();
};
struct Base14_80318564 { char pad[0x14]; };
struct VSub_80318564 : Base14_80318564 {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual s32 s4();
};

extern "C" {

extern const f32 TObjEneMe3SinowZoa__data_805DF30C;
extern const f32 TObjEneMe3SinowZoa__data_805DF310;

#define F(T, o) (*(T *)(arg0 + (o)))
#define VO ((VObj_80318564 *)arg0)
#define VS ((VSub_80318564 *)(arg0 + 0x414))
#define TBL(o) (((s32 *)TObjEneMe3SinowZoa__kind_param_tbls[F(s32, 0x3C8)])[(o) / 4])

void TObjEneMe3SinowZoa__sub_80318564(u8 *arg0, s32 arg1) {
    switch (arg1) {
    case 4:
        F(s16, 0xB8) = 8;
        ((TObjEneDD *)arg0)->set_field_378(0xB);
        VO->m94();
        F(s32, 0x3CC) &= 0xFFEFFFF8;
        if (F(s32, 0x3C0) != 0) {
            ((TObjEneMe3SinowZoa *)(arg0 + 0x414))->set_field_10(TObjEneMe3SinowZoa__data_805DF30C);
            VS->s3();
            F(s32, 0x3CC) |= 0x100000;
            F(s32, 0x3CC) |= 0x40000;
            ((TUnk_804AF8A0 *)arg0)->clear_player_status_flag(0, 0x08000000);
            F(s32, 0x434) = 0;
        } else {
            F(s32, 0x434) = 1;
        }
        F(s32, 0x438) = 0;
        break;
    case 3:
        if (F(s32, 0x438) > TBL(0x1C)) {
            transition_enemy_state__9TObjEneDDFs(arg0, 6);
        }
        break;
    case 5:
        break;
    case 0:
        advance_animation_playback(arg0);
        switch (F(s32, 0x434)) {
        case 0:
            advance_animation_playback(arg0);
            if (((TObjEneMe3SinowZoa *)(arg0 + 0x414))->advance_timer(TObjEneMe3SinowZoa__data_805DF310) != 0) {
                F(s32, 0x434) = 1;
            }
        case 1:
            if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
                cast_technique__18TObjEneMe3SinowZoaFPv(arg0);
                if (((s32 (*)(void))check_v2_mode__9TObjEneDDFv)() != 0) {
                    F(s32, 0x434) = 3;
                } else if (F(s32, 0x3CC) & 0x100000) {
                    F(s32, 0x434) = 4;
                } else {
                    F(s32, 0x434) = 2;
                }
                F(s32, 0x438) = 0;
            }
            break;
        case 2:
            F(s32, 0x438)++;
            break;
        case 3:
            F(s32, 0x438)++;
            if (F(s32, 0x438) == 5) {
                TTecSifta::create((void *)arg0, arg0 + 0x38, (void *)(TObjEneDD::clamp_frame_index(TBL(0x18))));
            } else if (F(s32, 0x438) == 0xA) {
                create__10TTecDebandFlll(arg0, arg0 + 0x38, TObjEneDD::clamp_frame_index(TBL(0x18)));
                if (F(s32, 0x3CC) & 0x100000) {
                    F(s32, 0x434) = 4;
                } else {
                    F(s32, 0x434) = 2;
                }
                F(s32, 0x438) = 0;
            }
            break;
        case 4:
            if (VS->s4() != 0) {
                F(s32, 0x434) = 2;
                F(s32, 0x3CC) |= 0x40000;
                ((TUnk_804AF8A0 *)arg0)->set_indexed_flags(0, 0x08000000);
            }
            break;
        }
        VO->m100();
        break;
    }
}

}

struct VBase_18_347dfc { char pad[0x18]; };
struct VObj_18_347dfc : VBase_18_347dfc {
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
    virtual s32 m89();
    virtual s32 m90();
    virtual void m91();
    virtual void m92();
    virtual void m93();
    virtual s32 m94();
    virtual void m95();
    virtual void m96();
    virtual void m97();
    virtual void m98();
    virtual void m99();
    virtual s32 m100();
    virtual void m101();
    virtual s32 m102(f32);
};
f64 atan2_float(f32, f32);
s32 approach_angle_limited(int, int, int);
extern const f64 TObjEneMe3SinowZoa__data_804760A0;
extern const f32 lbl_805DF338;
extern const f32 lbl_805DF33C;
extern const f32 lbl_805DF340;
extern const f32 lbl_805DF344;
#define arg0 ((u8 *)arg0_)
void TObjEneMe3SinowZoa__sub_8031884C(void *arg0_, s32 arg1) {
    s32 temp_r5;
    s32 zero;

    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)arg0 + 0xB8) = 3;
        ((TObjEneDD *)arg0)->set_field_378(6);
        ((TObjEneMe3SinowZoa *)(arg0))->vfunc_96();
        zero = 0;
        *(s32 *)((s8 *)arg0 + 0x3CC) &= 0xFFEFFFF8;
        *(s32 *)((s8 *)arg0 + 0x3FC) = zero;
        *(s32 *)((s8 *)arg0 + 0x434) = 3;
        if (((VObj_18_347dfc *)(arg0))->m102(TObjEneMe3SinowZoa__data_805DF324) != 0) {
            ((TObjEneDD_ST *)arg0)->enemy_copy_target_destination();
            ((TObjEneDD *)arg0)->update_velocity();
            *(s32 *)((s8 *)arg0 + 0x43C) = (s32) (TObjEneMe3SinowZoa__data_804760A0 * atan2_float((f32) (*(f32 *)((s8 *)arg0 + 0x3A0)), (f32) (*(f32 *)((s8 *)arg0 + 0x3A8))));
            if (((s32 (*)(void *, s32, f32))check_body_collision_at__18TObjEneMe3SinowZoaFlf)(arg0, (int) (*(s32 *)((s8 *)arg0 + 0x43C) + 0x8000), lbl_805DF338) == 0) {
                *(f32 *)((s8 *)arg0 + 0x3A0) = (f32) (*(f32 *)((s8 *)arg0 + 0x3A0) * lbl_805DF33C);
                *(f32 *)((s8 *)arg0 + 0x3A8) = (f32) (*(f32 *)((s8 *)arg0 + 0x3A8) * lbl_805DF33C);
                *(s32 *)((s8 *)arg0 + 0x434) = 0;
                *(f32 *)((s8 *)arg0 + 0x440) = (f32) lbl_805DF340;
            }
        }
        ((TObjEneDD_ST *)arg0)->set_active();
        return;
    case 3:
        if ((s32) *(s32 *)((s8 *)arg0 + 0x434) == 3) {
            if (((s32) *(s32 *)((s8 *)arg0 + 0x3C0) == 0) && (calc_boss4_scale__10TObjPlayerFi((s32)arg0) <= *(f32 *)((s8 *)arg0 + 0x3EC))) {
                transition_enemy_state__9TObjEneDDFs(arg0, 0x11);
            } else if (calc_boss4_scale__10TObjPlayerFi((s32)arg0) <= *(f32 *)((s8 *)arg0 + 0x3E8)) {
                if (((s32 (*)(u8 *))sub_8031A454__18TObjEneMe3SinowZoaFv)(arg0) != 0) {
                    if (calc_boss4_scale__10TObjPlayerFi((s32)arg0) > TObjEneMe3SinowZoa__kind_param_tbls[*(s32 *)((s8 *)arg0 + 0x3C8)][5]) {
                        transition_enemy_state__9TObjEneDDFs(arg0, 0x10);
                    } else {
                        transition_enemy_state__9TObjEneDDFs(arg0, 0xB);
                    }
                } else {
                    transition_enemy_state__9TObjEneDDFs(arg0, 0x10);
                }
            } else if (calc_boss4_scale__10TObjPlayerFi((s32)arg0) <= *(f32 *)((s8 *)arg0 + 0x3F4)) {
                transition_enemy_state__9TObjEneDDFs(arg0, 0xC);
            } else {
                transition_enemy_state__9TObjEneDDFs(arg0, 6);
            }
        }
        break;
    case 0:
        advance_animation_playback(arg0);
        switch (*(s32 *)((s8 *)arg0 + 0x434)) {
        case 0:
            *(s32 *)((s8 *)arg0 + 0x60) = approach_angle_limited((int) (*(s32 *)((s8 *)arg0 + 0x60)), (int) (*(s32 *)((s8 *)arg0 + 0x43C)), 0x31C7);
            if ((*(f32 *)((s8 *)arg0 + 0xC0) + *(f32 *)((s8 *)arg0 + 0xC8)) >= TObjEneMe3SinowZoa__data_805DF2F0) {
                *(s32 *)((s8 *)arg0 + 0x434) = 1;
                ((TObjEneMe3SinowZoa *)(arg0))->vfunc_91();
                play_sound_effect(0x4003A829, arg0 + 0x38, 0, 0);
            }
            ((TObjEneMe3SinowZoa *)(arg0))->vfunc_102();
            ((TObjEneMe3SinowZoa *)(arg0))->vfunc_89();
            return;
        case 1:
            if ((*(f32 *)((s8 *)arg0 + 0xC0) + *(f32 *)((s8 *)arg0 + 0xC8)) >= lbl_805DF344) {
                *(s32 *)((s8 *)arg0 + 0x434) = 2;
                ((TObjEneMe3SinowZoa *)(arg0))->vfunc_92();
                play_sound_effect(0x4003A82A, arg0 + 0x38, 0, 0);
                ((TObjEneMe3SinowZoa *)arg0)->check_and_notify();
            }
            ((TObjEneDD *)arg0)->move_clamped_on_ground((f32) (*(f32 *)((s8 *)arg0 + 0x3A0)), (f32) (*(f32 *)((s8 *)arg0 + 0x3A8)), (f32) (*(f32 *)((s8 *)arg0 + 0x440)));
            return;
        case 2:
            if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
                *(s32 *)((s8 *)arg0 + 0x434) = 3;
            }
            ((TObjEneMe3SinowZoa *)(arg0))->vfunc_102();
            ((TObjEneMe3SinowZoa *)(arg0))->vfunc_89();
            return;
        }
        break;
    case 5:
        ((TObjEneMe3SinowZoa *)(arg0))->vfunc_92();
        ((TObjEneDD *)arg0)->clear_field_388();
        break;
    }
}
#undef arg0

struct VBase_14_6ea8ee { char pad[0x14]; };
struct VObj_14_6ea8ee : VBase_14_6ea8ee {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual s32 m3();
    virtual s32 m4();
};
struct VBase_18_4f5f2e { char pad[0x18]; };
struct VObj_18_4f5f2e : VBase_18_4f5f2e {
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
    virtual void m93();
    virtual s32 m94();
    virtual void m95();
    virtual void m96();
    virtual void m97();
    virtual void m98();
    virtual void m99();
    virtual s32 m100();
    virtual void m101();
    virtual void m102();
    virtual s32 m103();
    virtual void m104();
    virtual s32 m105();
    virtual void m106();
    virtual void m107();
    virtual void m108();
    virtual void m109();
    virtual s32 m110();
};

s32 move_to_shot_position__9TObjEneDDFfff(void *, f32 *, f32, f32, f32);

#pragma push
#pragma opt_common_subs off
void TObjEneMe3SinowZoa__sub_80318C0C(void *arg0_, s32 arg1) {
    u8 *ene_epsilon = (u8 *)arg0_;
    s32 var_r4;
    f32 temp_f1;

    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)ene_epsilon + 0xB8) = 7;
        ((TObjEneDD *)ene_epsilon)->set_field_378(0xC);
        ((TObjEneEpsilon *)(ene_epsilon))->vfunc_96();
        *(s32 *)((s8 *)ene_epsilon + 0x3CC) = (s32) (*(s32 *)((s8 *)ene_epsilon + 0x3CC) & 0xFFEFFFF8);
        *(s32 *)((s8 *)ene_epsilon + 0x3CC) |= 0x10000;
        *(s32 *)((s8 *)ene_epsilon + 0x3CC) |= 0x40000;
        ((TUnk_804AF8A0 *)ene_epsilon)->clear_player_status_flag(0, 0x08000000);
        if (*(s32 *)((s8 *)ene_epsilon + 0x3C0) != 0) {
            ((TObjEneMe3SinowZoa *)(ene_epsilon + 0x414))->set_field_10(TObjEneMe3SinowZoa__data_805DF30C);
            ((VObj_14_6ea8ee *)(ene_epsilon + 0x414))->m3();
            *(s32 *)((s8 *)ene_epsilon + 0x3CC) |= 0x100000;
            *(s32 *)((s8 *)ene_epsilon + 0x434) = 0;
        } else {
            *(s32 *)((s8 *)ene_epsilon + 0x434) = 1;
        }
        *(s32 *)((s8 *)ene_epsilon + 0x438) = 0;
        return;
    case 3:
        if (*(s32 *)((s8 *)ene_epsilon + 0x434) == 4) {
            *(s32 *)((s8 *)ene_epsilon + 0x3CC) |= 0x80000;
            ((VObj_18_4f5f2e *)(ene_epsilon))->m105();
        }
        return;
    case 0:
        switch (*(s32 *)((s8 *)ene_epsilon + 0x434)) {
        case 0:
            if (((TObjEneMe3SinowZoa *)(ene_epsilon + 0x414))->advance_timer(TObjEneMe3SinowZoa__data_805DF310) != 0) {
                *(s32 *)((s8 *)ene_epsilon + 0x434) = 1;
            }
        case 1:
            advance_animation_playback(ene_epsilon);
            ((VObj_18_4f5f2e *)(ene_epsilon))->m103();
            if (*(f32 *)((s8 *)ene_epsilon + 0xC0) < TObjEneMe3SinowZoa__data_805DF320) {
                if (((TObjEneEpsilon *)ene_epsilon)->update_death_check() != 0) {
                    ((TObjEneDD_ST *)ene_epsilon)->enemy_copy_target_destination();
                    ((TObjEneDD *)ene_epsilon)->update_velocity();
                    var_r4 = (s32) (TObjEneMe3SinowZoa__data_804760A0 * atan2_float(*(f32 *)((s8 *)ene_epsilon + 0x3A0), *(f32 *)((s8 *)ene_epsilon + 0x3A8)));
                } else {
                    var_r4 = *(s32 *)((s8 *)ene_epsilon + 0x60);
                }
                *(s32 *)((s8 *)ene_epsilon + 0x60) = approach_angle_limited(*(s32 *)((s8 *)ene_epsilon + 0x60), var_r4, 0x300);
                *(f32 *)((s8 *)ene_epsilon + 0x3A0) = sin_table_lookup(*(s32 *)((s8 *)ene_epsilon + 0x60));
                *(f32 *)((s8 *)ene_epsilon + 0x3A8) = cos_table_lookup(*(s32 *)((s8 *)ene_epsilon + 0x60));
            }
            ((VObj_18_4f5f2e *)(ene_epsilon))->m110();
            TObjEneMe3SinowZoa__sub_80316840(ene_epsilon);
            temp_f1 = *(f32 *)((s8 *)ene_epsilon + 0xC0);
            if (temp_f1 >= TObjEneMe3SinowZoa__data_805DF31C && temp_f1 <= TObjEneMe3SinowZoa__data_805DF308) {
                f32 *rec = TObjEneMe3SinowZoa__kind_param_tbls[*(s32 *)((s8 *)ene_epsilon + 0x3C8)];
                move_to_shot_position__9TObjEneDDFfff(ene_epsilon, rec, *(f32 *)((s8 *)ene_epsilon + 0x3A0), *(f32 *)((s8 *)ene_epsilon + 0x3A8), rec[2]);
            } else {
                ((TObjEneEpsilon *)(ene_epsilon))->vfunc_102();
            }
            if (((TObjEneDD *)ene_epsilon)->get_flag_b4() != 0) {
                *(s32 *)((s8 *)ene_epsilon + 0x434) = 2;
            }
            break;
        case 2:
            *(s32 *)((s8 *)ene_epsilon + 0x438) += 1;
            if (*(s32 *)((s8 *)ene_epsilon + 0x438) >= ((s32 *)TObjEneMe3SinowZoa__kind_param_tbls[*(s32 *)((s8 *)ene_epsilon + 0x3C8)])[8]) {
                if (*(s32 *)((s8 *)ene_epsilon + 0x3CC) & 0x100000) {
                    *(s32 *)((s8 *)ene_epsilon + 0x434) = 3;
                } else {
                    *(s32 *)((s8 *)ene_epsilon + 0x434) = 4;
                }
            }
            ((TObjEneEpsilon *)(ene_epsilon))->vfunc_102();
            break;
        case 3:
            if (((VObj_14_6ea8ee *)(ene_epsilon + 0x414))->m4() != 0) {
                *(s32 *)((s8 *)ene_epsilon + 0x434) = 4;
                *(s32 *)((s8 *)ene_epsilon + 0x3CC) |= 0x40000;
                ((TUnk_804AF8A0 *)ene_epsilon)->set_indexed_flags(0, 0x08000000);
            }
            break;
        }
        ((TObjEneEpsilon *)(ene_epsilon))->vfunc_89();
        break;
    case 5:
        break;
    }
}
#pragma pop

#pragma push
#pragma fp_contract on

struct Vec_80318F7C { f32 x, y, z; };

struct SubBase_80318F7C { char pad[0x14]; };
struct Sub_80318F7C : SubBase_80318F7C {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual s32 m4();
};

struct TgtBase_80318F7C { char pad[0x18]; };
struct Tgt_80318F7C : TgtBase_80318F7C {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17();
    virtual s32 m18(void *, f32);
    virtual void m19();
    virtual void m20(void *, f32);
    virtual void m21(); virtual void m22();
    virtual void m23(void *, f32);
};

struct ObjBase_80318F7C { char pad[0x18]; };
struct Obj_80318F7C : ObjBase_80318F7C {
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
    virtual void m84(); virtual void m85(); virtual void m86();
    virtual void m87();
    virtual void m88();
    virtual void m89();
    virtual void m90();
    virtual void m91(); virtual void m92(); virtual void m93();
    virtual void m94();
    virtual void m95(); virtual void m96(); virtual void m97(); virtual void m98(); virtual void m99();
    virtual u32 m100();
};

struct Ene_80318F7C : Obj_80318F7C {
    u8 pad1c[0x28 - 0x1C];
    s16 f28;
    u8 pad2a[0x38 - 0x2A];
    Vec_80318F7C pos;
    u8 pad44[0x60 - 0x44];
    s32 f60;
    u8 pad64[0xB0 - 0x64];
    s32 fB0;
    u8 padb4[0xB8 - 0xB4];
    s16 fB8;
    u8 padba[0xC0 - 0xBA];
    f32 fC0;
    u8 padc4[0xC8 - 0xC4];
    f32 fC8;
    u8 padcc[0x390 - 0xCC];
    Tgt_80318F7C *f390;
    u8 pad394[0x3A0 - 0x394];
    f32 f3A0;
    u8 pad3a4[0x3A8 - 0x3A4];
    f32 f3A8;
    f32 f3AC;
    u8 pad3b0[0x3C0 - 0x3B0];
    s32 f3C0;
    u8 pad3c4[0x3CC - 0x3C4];
    s32 f3CC;
    u8 pad3d0[0x3E0 - 0x3D0];
    f32 f3E0;
    f32 f3E4;
    u8 pad3e8[0x414 - 0x3E8];
    Sub_80318F7C sub;
    u8 pad42c[0x434 - 0x42C];
    s32 f434;
    u8 pad438[0x440 - 0x438];
    f32 f440;
    f32 f444;
};

extern "C" {

u32 csnVecterUnder(void *, int);
extern const f32 lbl_805DF348;
extern const f32 lbl_805DF34C;
extern const f32 lbl_805DF354;

void TObjEneMe3SinowZoa__sub_80318F7C(Ene_80318F7C *self, s32 arg1) {
    switch (arg1) {
    case 4:
        self->fB8 = 6;
        ((TObjEneDD *)self)->set_field_378(6);
        self->m94();
        self->f3CC &= 0xFFEFFFF8;
        self->f3CC |= 0x10000;
        self->f434 = 0;
        self->f440 = TObjEneMe3SinowZoa__data_805DF31C;
        ((TObjEneDD_ST *)self)->set_active();
        break;
    case 3:
        if (self->f434 == 7 || ((TObjEneDD *)self)->get_flag_b4() != 0) {
            if (self->m100() == 0) {
                transition_enemy_state__9TObjEneDDFs(self, 10);
            } else {
                transition_enemy_state__9TObjEneDDFs(self, 6);
            }
        }
        break;
    case 0:
        switch ((u32)self->f434) {
        case 0:
            advance_animation_playback(self);
            if (self->fB0 & 8) {
                self->f434 = 1;
            }
            self->m100();
            self->m87();
            break;
        case 1: {
            s32 target;
            advance_animation_playback(self);
            if (((TObjEneEpsilon *)self)->update_death_check() != 0) {
                ((TObjEneDD_ST *)self)->enemy_copy_target_destination();
                ((TObjEneDD *)self)->update_velocity();
                target = (s32)(TObjEneMe3SinowZoa__data_804760A0 * atan2_float(self->f3A0, self->f3A8));
            } else {
                target = self->f60;
            }
            self->f60 = approach_angle_limited(self->f60, target, 0x1000);
            if (objInBand((GameObj *)self, (f32)TObjEneMe3SinowZoa__data_805DF314) != 0) {
                self->f434 = 2;
            }
            self->m100();
            self->m87();
            break;
        }
        case 2:
            advance_animation_playback(self);
            if (((TObjEneEpsilon *)self)->update_death_check() != 0) {
                ((TObjEneDD_ST *)self)->enemy_copy_target_destination();
                ((TObjEneDD *)self)->update_velocity();
            }
            if (self->fC0 + self->fC8 >= lbl_805DF348) {
                if (((s32 (*)(void *, s32, f32))check_body_collision_at__18TObjEneMe3SinowZoaFlf)(self, self->f60, self->f3AC - TObjEneMe3SinowZoa__data_805DF320) != 0) {
                    self->f434 = 7;
                } else {
                    Vec_80318F7C v;
                    f32 d = self->f3AC - TObjEneMe3SinowZoa__data_805DF320;
                    VecCopy((Vec *)&v, (const Vec *)&self->pos);
                    v.x = self->f3A0 * d + v.x;
                    v.y = v.y + TObjEneMe3SinowZoa__data_805DF320;
                    v.z = self->f3A8 * d + v.z;
                    if (csnVecterUnder(&v, 0x15) != 0) {
                        if (self->f28 == ((TScene *)(&v))->find_section_at_position()) {
                            if (self->f3C0 != 0) {
                                ((TObjEneMe3SinowZoa *)(&self->sub))->set_field_10(TObjEneMe3SinowZoa__data_805DF30C);
                                self->sub.m3();
                                self->f3CC |= 0x100000;
                                self->f3CC |= 0x40000;
                                ((TUnk_804AF8A0 *)self)->clear_player_status_flag(0, 0x08000000);
                                self->f434 = 3;
                            } else {
                                self->f434 = 4;
                            }
                            self->f444 = (self->f3AC - TObjEneMe3SinowZoa__data_805DF320) / lbl_805DF34C;
                            self->m89();
                            play_sound_effect(0x4003A82C, &self->pos, 0, 0);
                        } else {
                            self->f434 = 7;
                        }
                    } else {
                        self->f434 = 7;
                    }
                }
            }
            self->m100();
            self->m87();
            break;
        case 3:
            if (((TObjEneMe3SinowZoa *)(&self->sub))->advance_timer(TObjEneMe3SinowZoa__data_805DF310) != 0) {
                self->f434 = 4;
            }
        case 4:
            advance_animation_playback(self);
            if (self->fC0 + self->fC8 >= lbl_805DF2F8) {
                if (self->f3CC & 0x100000) {
                    self->f434 = 5;
                } else {
                    self->f434 = 6;
                }
                self->m90();
                play_sound_effect(0x4003A82A, &self->pos, 0, 0);
                ((TObjEneMe3SinowZoa *)self)->check_and_notify();
            }
            ((TObjEneDD *)self)->move_with_wall_slide_commit(self->f3A0, self->f3A8, self->f444);
            break;
        case 5:
            if (self->fC0 > TObjEneMe3SinowZoa__data_805DF2F0 && self->sub.m4() != 0) {
                self->f3CC &= ~0x100000;
                self->f434 = 6;
                self->f3CC |= 0x40000;
                ((TUnk_804AF8A0 *)self)->set_indexed_flags(0, 0x08000000);
            }
        case 6:
            advance_animation_playback(self);
            if (objInBand((GameObj *)self, (f32)lbl_805DF350) != 0 && ((TObjEneDD_ST *)self)->enemy_check_target_valid() != 0) {
                if (self->f390->m18(self, TObjEneMe3SinowZoa__data_805DF2F4) != 0) {
                    self->f390->m20(self, TObjEneMe3SinowZoa__data_805DF2F4);
                    self->f390->m23(self, TObjEneMe3SinowZoa__data_805DF328);
                }
            }
            self->f444 *= lbl_805DF354;
            ((TObjEneDD *)self)->move_with_wall_slide_on_ground(self->f3A0, self->f3A8, self->f444);
            self->m87();
            break;
        }
        break;
    case 5:
        self->f3E0 = self->pos.y;
        self->f3E4 = TObjEneMe3SinowZoa__data_805DF31C;
        self->m90();
        ((TObjEneDD *)self)->clear_field_388();
        break;
    }
}

}
#pragma pop

#pragma push
#pragma fp_contract on
void TObjEneMe3SinowZoa::state_chase_target(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)arg0 + 0xB8) = 0xA;
        ((TObjEneDD *)arg0)->set_field_378(6);
        this->vfunc_96();
        *(s32 *)((s8 *)arg0 + 0x3CC) = (s32) (*(s32 *)((s8 *)arg0 + 0x3CC) & 0xFFEFFFF8);
        *(f32 *)((s8 *)arg0 + 0x3AC) = (f32) 300.0f;
        *(f32 *)((s8 *)arg0 + 0x440) = (f32) *TObjEneMe3SinowZoa__kind_param_tbls[*(s32 *)((s8 *)arg0 + 0x3C8)];
        *(f32 *)((s8 *)arg0 + 0x444) = (f32) TObjEneMe3SinowZoa__data_805DF31C;
        return;
    case 3:
        if ((u32) *(u32 *)((s8 *)arg0 + 0x390) == 0U) {
            this->vfunc_111();
            transition_enemy_state__9TObjEneDDFs(arg0, 0xD);
            return;
        }
        if (((s32 (*)(f32))TObjEneMe3SinowZoa__sub_8031A820)((f32) (*(f32 *)((s8 *)arg0 + 0x444))) != 0) {
            transition_enemy_state__9TObjEneDDFs(arg0, 8);
            return;
        }
        if (((VObj_18_e66632 *)(arg0))->m104() != 0) {
            transition_enemy_state__9TObjEneDDFs(arg0, 7);
        }
    case 5:
        return;
    case 0:
        advance_animation_playback(arg0);
        if (((TObjEneDD_ST *)arg0)->update_linked_position(TObjEneMe3SinowZoa__data_805DF324) != 0) {
            ((TObjEneDD_ST *)arg0)->enemy_copy_target_destination();
            ((TObjEneDD *)arg0)->update_velocity();
            TObjEneMe3SinowZoa__sub_80316840(arg0);
            *(f32 *)((s8 *)arg0 + 0x444) = (f32) ((*(f32 *)((s8 *)arg0 + 0x3A0) * sin_table_lookup((s32)((int) (*(s32 *)((s8 *)arg0 + 0x60))))) + (*(f32 *)((s8 *)arg0 + 0x3A8) * cos_table_lookup((s32)((int) (*(s32 *)((s8 *)arg0 + 0x60))))));
            if (*(f32 *)((s8 *)arg0 + 0x444) < cos_table_lookup(0x1000)) {
                ((TObjEneEpsilon *)arg0)->update_angle(0x500);
                this->vfunc_102();
            } else {
                enemy_turn_and_move_on_ground((arg0), 0x500, (f32) (*(f32 *)((s8 *)arg0 + 0x440)));
            }
            this->vfunc_89();
        }
        break;
    }
}
#pragma pop

void TObjEneMe3SinowZoa__sub_80319748(u8 *ene_me3_sinow_zoa, s32 arg1) {
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f31;

    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)ene_me3_sinow_zoa + 0xB8) = 1;
        ((TObjEneDD *)ene_me3_sinow_zoa)->set_field_378(0xD);
        ((TObjEneDD *)(ene_me3_sinow_zoa))->vfunc_96();
        *(s32 *)((s8 *)ene_me3_sinow_zoa + 0x3CC) = (s32) (*(s32 *)((s8 *)ene_me3_sinow_zoa + 0x3CC) & 0xFFEFFFF9);
        *(s32 *)((s8 *)ene_me3_sinow_zoa + 0x3CC) = (s32) (*(s32 *)((s8 *)ene_me3_sinow_zoa + 0x3CC) | 1);
        *(s32 *)((s8 *)ene_me3_sinow_zoa + 0x434) = 0;
        *(f32 *)((s8 *)ene_me3_sinow_zoa + 0x440) = (f32) TObjEneMe3SinowZoa__data_805DF31C;
        if (((TObjEneDD_ST *)ene_me3_sinow_zoa)->enemy_has_live_target() != 0) {
            ((TObjEneDD_ST *)ene_me3_sinow_zoa)->enemy_copy_target_destination();
            ((TObjEneDD *)ene_me3_sinow_zoa)->update_velocity();
        }
        break;
    case 3:
        if ((s32) *(s32 *)((s8 *)ene_me3_sinow_zoa + 0x434) == 3) {
            transition_enemy_state__9TObjEneDDFs(ene_me3_sinow_zoa, 0xD);
        }
        break;
    case 0:
        switch (*(s32 *)((s8 *)ene_me3_sinow_zoa + 0x434)) {
        case 0:
            temp_f31 = ((TObjEneMe3SinowZoa *)ene_me3_sinow_zoa)->get_node_height();
            advance_animation_playback(ene_me3_sinow_zoa);
            *(f32 *)((s8 *)ene_me3_sinow_zoa + 0x444) = ((TObjEneMe3SinowZoa *)ene_me3_sinow_zoa)->get_node_height();
            *(f32 *)((s8 *)ene_me3_sinow_zoa + 0x3E0) = (f32) (*(f32 *)((s8 *)ene_me3_sinow_zoa + 0x3E0) + (temp_f31 - *(f32 *)((s8 *)ene_me3_sinow_zoa + 0x444)));
            *(s32 *)((s8 *)ene_me3_sinow_zoa + 0x434) = 1;
            *(f32 *)((s8 *)ene_me3_sinow_zoa + 0x3E4) = (f32) (*(f32 *)((s8 *)ene_me3_sinow_zoa + 0x3E0) - *(f32 *)((s8 *)ene_me3_sinow_zoa + 0x3C));
            break;
        case 1:
            advance_animation_playback(ene_me3_sinow_zoa);
            if (*(f32 *)((s8 *)ene_me3_sinow_zoa + 0xC0) > 29.0f) {
                *(f32 *)((s8 *)ene_me3_sinow_zoa + 0xC0) = 29.0f;
            }
            *(f32 *)((s8 *)ene_me3_sinow_zoa + 0x440) -= 0.3f;
            if (*(f32 *)((s8 *)ene_me3_sinow_zoa + 0x440) < -5.0f) {
                *(f32 *)((s8 *)ene_me3_sinow_zoa + 0x440) = -5.0f;
            }
            *(f32 *)((s8 *)ene_me3_sinow_zoa + 0x3E0) = (f32) (*(f32 *)((s8 *)ene_me3_sinow_zoa + 0x3E0) + *(f32 *)((s8 *)ene_me3_sinow_zoa + 0x440));
            temp_f1 = ((TObjEneMe3SinowZoa *)ene_me3_sinow_zoa)->get_node_height();
            *(f32 *)((s8 *)ene_me3_sinow_zoa + 0x3E0) = (f32) (*(f32 *)((s8 *)ene_me3_sinow_zoa + 0x3E0) - (temp_f1 - *(f32 *)((s8 *)ene_me3_sinow_zoa + 0x444)));
            *(f32 *)((s8 *)ene_me3_sinow_zoa + 0x444) = temp_f1;
            if (*(f32 *)((s8 *)ene_me3_sinow_zoa + 0x3E0) < *(f32 *)((s8 *)ene_me3_sinow_zoa + 0x3C)) {
                *(f32 *)((s8 *)ene_me3_sinow_zoa + 0x3E0) = *(f32 *)((s8 *)ene_me3_sinow_zoa + 0x3C);
                *(s32 *)((s8 *)ene_me3_sinow_zoa + 0x434) = 2;
                play_sound_effect(0x4003A82A, ene_me3_sinow_zoa + 0x38, 0, 0);
                ((TObjEneMe3SinowZoa *)ene_me3_sinow_zoa)->check_and_notify();
            }
            break;
        case 2:
            if (((TObjEneDD *)ene_me3_sinow_zoa)->get_flag_b4() != 0) {
                *(s16 *)((s8 *)ene_me3_sinow_zoa + 0xB8) = 9;
                *(s32 *)((s8 *)ene_me3_sinow_zoa + 0x434) = 3;
                *(f32 *)((s8 *)ene_me3_sinow_zoa + 0x3E0) = (f32) *(f32 *)((s8 *)ene_me3_sinow_zoa + 0x3C);
                *(f32 *)((s8 *)ene_me3_sinow_zoa + 0x3E4) = (f32) TObjEneMe3SinowZoa__data_805DF31C;
            }
            advance_animation_playback(ene_me3_sinow_zoa);
            break;
        }
        ((TObjEneDD *)(ene_me3_sinow_zoa))->vfunc_102();
        ((TObjEneMe3SinowZoa *)ene_me3_sinow_zoa)->update_distance_state();
        ((TObjEneDD *)(ene_me3_sinow_zoa))->vfunc_89();
        *(f32 *)((s8 *)ene_me3_sinow_zoa + 0x3E4) = (f32) (*(f32 *)((s8 *)ene_me3_sinow_zoa + 0x3E0) - *(f32 *)((s8 *)ene_me3_sinow_zoa + 0x3C));
        break;
    case 5:
        *(s32 *)((s8 *)ene_me3_sinow_zoa + 0x3CC) = (s32) (*(s32 *)((s8 *)ene_me3_sinow_zoa + 0x3CC) & 0xFFFFFFFE);
        *(f32 *)((s8 *)ene_me3_sinow_zoa + 0x3E4) = (f32) TObjEneMe3SinowZoa__data_805DF31C;
        break;
    }
}

extern "C" {

s32 enemy_validate_retained_target(u8 *arg0);
extern const u32 lbl_805DF368;

void TObjEneMe3SinowZoa::update_state_action(s32 arg1) {
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)this + 0xB8) = 0;
        set_field_378(5);
        this->vfunc_95();
        *(u32 *)((s8 *)this + 0x3CC) &= 0xFFEFFFF8;
        *(s32 *)((s8 *)this + 0x434) = 0;
        *(s32 *)((s8 *)this + 0x438) = 0;
        break;
    case 3:
        if (*(s32 *)((s8 *)this + 0x434) > 0x1E) {
            transition_enemy_state__9TObjEneDDFs(this, 5);
        }
        break;
    case 0:
        advance_animation_playback(this);
        if (*(s32 *)((s8 *)this + 0x434) == 0) {
            if (update_linked_position(TObjEneMe3SinowZoa__data_805DF324) != 0) {
                *(s32 *)((s8 *)this + 0x434) = 1;
                *(u32 *)((s8 *)this + 0x3F8) = 0x1C00FFFF;
                *(u32 *)((s8 *)this + 0x3F8) &= lbl_805DF368;
                *(s32 *)((s8 *)this + 0x438) = 0;
            }
        } else {
            (*(s32 *)((s8 *)this + 0x434))++;
            *(s32 *)((s8 *)this + 0x438) += 0x10;
            if (*(s32 *)((s8 *)this + 0x438) > 0xFF) {
                *(s32 *)((s8 *)this + 0x438) = 0xFF;
            }
            *(u32 *)((s8 *)this + 0x3F8) = (*(s32 *)((s8 *)this + 0x438) << 24) | (*(u32 *)((s8 *)this + 0x3F8) & 0xFFFFFF);
            if (enemy_validate_retained_target((u8 *)this) == 0) {
                *(s32 *)((s8 *)this + 0x434) = 0;
                *(s32 *)((s8 *)this + 0x3F8) = 0;
            }
        }
        this->vfunc_102();
        update_distance_state();
        this->vfunc_89();
        *(f32 *)((s8 *)this + 0x3E4) = *(f32 *)((s8 *)this + 0x3E0) - *(f32 *)((s8 *)this + 0x3C);
        break;
    case 5:
        *(s32 *)((s8 *)this + 0x3F8) = 0x1C00FFFF;
        *(f32 *)((s8 *)this + 0x3E4) = TObjEneMe3SinowZoa__data_805DF31C;
        break;
    }
}

}

struct VBase_18_bb4b7f { char pad[0x18]; };
struct VObj_18_bb4b7f : VBase_18_bb4b7f {
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
    virtual void m93();
    virtual s32 m94();
    virtual void m95();
    virtual void m96();
    virtual void m97();
    virtual void m98();
    virtual void m99();
    virtual s32 m100();
    virtual void m101();
    virtual s32 m102(f32);
    virtual void m103();
    virtual s32 m104();
};

extern "C" {

extern const f32 lbl_805DF36C;
extern const f32 lbl_805DF370;

#pragma push
#pragma fp_contract on
void TObjEneMe3SinowZoa__sub_80319B8C(u8 *ene_dd, s32 arg1) {
    typedef char sp8_offset[(offsetof(Stack_80319B8C, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_80319B8C, spC) == 0x4) ? 1 : -1];
    Stack_80319B8C stack;
    f32 temp_f1;
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)ene_dd + 0xB8) = 0;
        ((TObjEneDD *)ene_dd)->set_field_378(0);
        ((TObjEneDD *)(ene_dd))->vfunc_95();
        *(s32 *)((s8 *)ene_dd + 0x3CC) = (s32) (*(s32 *)((s8 *)ene_dd + 0x3CC) | 7);
        TObjEneMe3SinowZoa__sub_800D758C(ene_dd + 0x414);
        VecCopy((Vec *)(&stack.sp8), (const Vec *)(ene_dd + 0x38));
        temp_f1 = *(f32 *)((s8 *)ene_dd + 0x3E0);
        stack.spC = temp_f1 - TObjEneMe3SinowZoa__data_805DF314;
        TBoss3Volopt__sub_800D8D88(&stack.sp8, temp_f1);
        break;
    case 3:
        if (((VObj_14_948132 *)(ene_dd + (1044)))->m5() != 0) {
            transition_enemy_state__9TObjEneDDFs(ene_dd, 4);
            break;
        }
    case 0:
        break;
    case 5:
        *(s32 *)((s8 *)ene_dd + 0x3CC) = (s32) (*(s32 *)((s8 *)ene_dd + 0x3CC) & 0xFFFFFFFB);
        break;
    }
}
void TObjEneMe3SinowZoa::state_chase(s32 arg1) {
#define arg0 ((u8 *)this)
    s32 temp_r0;
    s32 temp_r4;

    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)arg0 + 0xB8) = 9;
        ((TObjEneDD *)arg0)->set_field_378(0xD);
        ((VObj_18_bb4b7f *)(arg0))->m94();
        *(s32 *)((s8 *)arg0 + 0x3CC) = (s32) (*(s32 *)((s8 *)arg0 + 0x3CC) & 0xFFEFFFF8);
        *(s32 *)((s8 *)arg0 + 0x434) = 0;
        *(s32 *)((s8 *)arg0 + 0x438) = 0;
        *(f32 *)((s8 *)arg0 + 0x444) = (f32) TObjEneMe3SinowZoa__data_805DF31C;
        return;
    case 3:
        if (((VObj_18_bb4b7f *)(arg0))->m102(TObjEneMe3SinowZoa__data_805DF324) != 0) {
            if (*(f32 *)((s8 *)arg0 + 0x3AC) <= lbl_805DF36C) {
                transition_enemy_state__9TObjEneDDFs(arg0, 0xD);
                return;
            }
            temp_r0 = *(s32 *)((s8 *)arg0 + 0x438) - 1;
            *(s32 *)((s8 *)arg0 + 0x438) = temp_r0;
            if ((temp_r0 <= 0) && (((VObj_18_bb4b7f *)(arg0))->m104() != 0)) {
                *(s32 *)((s8 *)arg0 + 0x438) = 0x3C;
                if (((f32 (*)(void *))calc_boss4_scale__10TObjPlayerFi)(arg0) <= lbl_805DF370) {
                    transition_enemy_state__9TObjEneDDFs(arg0, 7);
                    return;
                }
            }
        } else if ((s32) *(s32 *)((s8 *)arg0 + 0x434) >= 0xE10) {
            transition_enemy_state__9TObjEneDDFs(arg0, 0xD);
            return;
        }
        break;
    case 5:
        break;
    case 0:
        (*(s32 *)((s8 *)arg0 + 0x434))++;
        advance_animation_playback(arg0);
        if (((TObjEneDD_ST *)arg0)->update_linked_position(TObjEneMe3SinowZoa__data_805DF324) != 0) {
            ((TObjEneDD_ST *)arg0)->enemy_copy_target_destination();
            ((TObjEneDD *)arg0)->update_velocity();
            *(f32 *)((s8 *)arg0 + 0x444) = (f32) ((*(f32 *)((s8 *)arg0 + 0x3A0) * sin_table_lookup((int) (*(s32 *)((s8 *)arg0 + 0x60)))) + (*(f32 *)((s8 *)arg0 + 0x3A8) * cos_table_lookup((int) (*(s32 *)((s8 *)arg0 + 0x60)))));
            if (*(f32 *)((s8 *)arg0 + 0x444) < cos_table_lookup(0x1000)) {
                ((TObjEneEpsilon *)arg0)->update_angle(0x500);
                ((VObj_18_bb4b7f *)(arg0))->m100();
            }
        }
        ((VObj_18_bb4b7f *)(arg0))->m87();
        break;
    }
}
#undef arg0
#pragma pop

}

void TObjEneMe3SinowZoa::sub_80319E74(s32 arg1) {
    Vec_80319E74 v;
    f32 t;
    u8 *arg0 = (u8 *)this;
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)arg0 + 0xB8) = 2;
        ((TObjEneDD *)arg0)->set_field_378(0);
        ((TObjEneMe3SinowZoa *)arg0)->vfunc_95();
        *(s32 *)((s8 *)arg0 + 0x3CC) &= 0xFFEFFFFD;
        *(s32 *)((s8 *)arg0 + 0x3CC) |= 5;
        TObjEneMe3SinowZoa__sub_800D758C(arg0 + 0x414);
        VecCopy((Vec *)&v, (const Vec *)(arg0 + 0x38));
        t = *(f32 *)((s8 *)arg0 + 0x3E0);
        v.y = t - TObjEneMe3SinowZoa__data_805DF320;
        if (*(s32 *)((s8 *)arg0 + 0x3C0) == 0) {
            TBoss3Volopt__sub_800D8D88(&v, t);
        } else {
            create_timed_particle_emitter(arg0 + 0x38, 0x79, 0, 0xF);
        }
        break;
    case 3:
        if (((VObj_14_948132 *) (arg0 + 0x414))->m5() != 0) {
            if (*(s32 *)((s8 *)arg0 + 0x3C0) == 1) {
                transition_enemy_state__9TObjEneDDFs(arg0, 2);
            } else {
                transition_enemy_state__9TObjEneDDFs(arg0, 0xD);
            }
        }
        break;
    case 0:
        if (*TBoss3Volopt__sub_800F059C(arg0 + 0x414) >= lbl_805DF374) {
            advance_animation_playback(arg0);
        }
        ((TObjEneMe3SinowZoa *)arg0)->vfunc_102();
        ((TObjEneMe3SinowZoa *)arg0)->vfunc_89();
        break;
    case 5:
        *(s32 *)((s8 *)arg0 + 0x3CC) &= ~4;
        break;
    }
}

void action__18TObjEneMe3SinowZoaFPvi(u8 *ene_me3_sinow_zoa, s32 arg1) {
    s32 temp_r3;
    s32 temp_r4;

    switch (arg1) {
    case 4:
        if ((s32) *(s32 *)((s8 *)ene_me3_sinow_zoa + 0x3C4) == 1) {
            *(s16 *)((s8 *)ene_me3_sinow_zoa + 0xB8) = 2;
            ((TObjEneDD *)ene_me3_sinow_zoa)->set_field_378(1);
        } else {
            *(s16 *)((s8 *)ene_me3_sinow_zoa + 0xB8) = 0;
            ((TObjEneDD *)ene_me3_sinow_zoa)->set_field_378(3);
        }
        ((TObjEneMe3SinowZoa *)ene_me3_sinow_zoa)->vfunc_95();
        temp_r4 = *(s32 *)((s8 *)ene_me3_sinow_zoa + 0x3CC);
        *(s32 *)((s8 *)ene_me3_sinow_zoa + 0x3CC) = (s32) (temp_r4 | 2);
        temp_r3 = *(s32 *)((s8 *)ene_me3_sinow_zoa + 0x3CC);
        *(s32 *)((s8 *)ene_me3_sinow_zoa + 0x3CC) = (s32) (temp_r3 & 0xFFEFFFFA);
        if (check_v2_mode__9TObjEneDDFv(temp_r3, temp_r4) != 0) {
            *(s32 *)((s8 *)ene_me3_sinow_zoa + 0x3CC) = (s32) (*(s32 *)((s8 *)ene_me3_sinow_zoa + 0x3CC) & 0xFFFEFFFF);
        }
        *(s32 *)((s8 *)ene_me3_sinow_zoa + 0x434) = 0;
        VecCopy((Vec *)(ene_me3_sinow_zoa + 0x38), (const Vec *)(ene_me3_sinow_zoa + 0x50));
        VecCopy((Vec *)(ene_me3_sinow_zoa + 0x44), (const Vec *)(ene_me3_sinow_zoa + 0x50));
        VecCopy((Vec *)(ene_me3_sinow_zoa + 0x2FC), (const Vec *)(ene_me3_sinow_zoa + 0x50));
        *(f32 *)((s8 *)ene_me3_sinow_zoa + 0x3E0) = (f32) *(f32 *)((s8 *)ene_me3_sinow_zoa + 0x3C);
        *(s32 *)((s8 *)ene_me3_sinow_zoa + 0x3F8) = 0;
        *(s32 *)((s8 *)ene_me3_sinow_zoa + 0x3FC) = 0;
        return;
    case 3:
        if ((s32) *(s32 *)((s8 *)ene_me3_sinow_zoa + 0x434) > 5) {
            if ((s32) *(s32 *)((s8 *)ene_me3_sinow_zoa + 0x3C4) == 1) {
                ((s32 (*)(void *, s32))transition_enemy_state__9TObjEneDDFs)(ene_me3_sinow_zoa, 1);
            } else {
                ((s32 (*)(void *, s32))transition_enemy_state__9TObjEneDDFs)(ene_me3_sinow_zoa, 3);
            }
        }
    case 5:
        return;
    case 0:
        *(s32 *)((s8 *)ene_me3_sinow_zoa + 0x434) = (s32) (*(s32 *)((s8 *)ene_me3_sinow_zoa + 0x434) + 1);
        if ((s32) *(s32 *)((s8 *)ene_me3_sinow_zoa + 0x434) == 1) {
            *(f32 *)((s8 *)ene_me3_sinow_zoa + 0x3E0) = (f32) *(f32 *)((s8 *)ene_me3_sinow_zoa + 0x3C);
            ((TObjEneMe3SinowZoa *)ene_me3_sinow_zoa)->vfunc_102();
            *(f32 *)((s8 *)ene_me3_sinow_zoa + 0x3E4) = (f32) (*(f32 *)((s8 *)ene_me3_sinow_zoa + 0x3E0) - *(f32 *)((s8 *)ene_me3_sinow_zoa + 0x3C));
        }
        break;
    }
}

void dispatch_state__18TObjEneMe3SinowZoaFPvUii(u8 *arg0, u32 arg1, s32 arg2) {
    V_8031A178 *v = (V_8031A178 *) arg0;
    switch (arg1) {
    case 0:
        v->f111(arg2);
        return;
    case 1:
        ((TObjEneMe3SinowZoa *)arg0)->sub_80319E74(arg2);
        return;
    case 3:
        ((s32 (*)(void *, s32))TObjEneMe3SinowZoa__sub_80319B8C)(arg0, arg2);
        return;
    case 2:
        ((TObjEneMe3SinowZoa *)arg0)->state_chase(arg2);
        return;
    case 4:
        ((TObjEneMe3SinowZoa *)arg0)->update_state_action(arg2);
        return;
    case 5:
        ((s32 (*)(void *, s32))TObjEneMe3SinowZoa__sub_80319748)(arg0, arg2);
        return;
    case 6:
        ((TObjEneMe3SinowZoa *)arg0)->state_chase_target(arg2);
        return;
    case 7:
        TObjEneMe3SinowZoa__sub_80318F7C((Ene_80318F7C *)arg0, arg2);
        return;
    case 8:
        TObjEneMe3SinowZoa__sub_80318C0C(arg0, arg2);
        return;
    case 9:
        TObjEneMe3SinowZoa__sub_8031884C(arg0, arg2);
        return;
    case 13:
        ((TObjEneMe3SinowZoa *)arg0)->handle_state_substate(arg2);
        return;
    case 10:
        TObjEneMe3SinowZoa__sub_803182F8(arg0, arg2);
        return;
    case 11:
        TObjEneMe3SinowZoa__sub_80318564(arg0, arg2);
        return;
    case 14:
        ((TObjEneMe3SinowZoa *)arg0)->state_knockback(arg2);
        return;
    case 15:
        ((s32 (*)(void *, s32))TObjEneMe3SinowZoa__sub_80317F90)(arg0, arg2);
        return;
    case 12:
        TObjEneMe3SinowZoa__sub_80317B50(arg0, arg2);
        return;
    case 16:
        TObjEneMe3SinowZoa__sub_80316C3C(arg0, arg2);
        return;
    case 17:
        TObjEneMe3SinowZoa__sub_80317254(arg0, arg2);
        return;
    case 18:
        TObjEneMe3SinowZoa__sub_803170F0(arg0, arg2);
    default:
        return;
    }
}

void cast_technique__18TObjEneMe3SinowZoaFPv(u8 *arg0) {
    s32 lv;
    lv = TObjEneDD::clamp_frame_index(((Param_8031A2A0 * *)TObjEneMe3SinowZoa__kind_param_tbls)[*(s32 *)((s8 *)arg0 + 0x3C8)]->level);
    if (((s32 (*)(void *))sub_8031A454__18TObjEneMe3SinowZoaFv)(arg0) != 0) {
        if (game_difficulty_selection == 3) {
            TTecSifta::create((void *)arg0, arg0 + 0x38, (void *)(TObjEneDD::clamp_frame_index(((Param_8031A2A0 * *)TObjEneMe3SinowZoa__kind_param_tbls)[*(s32 *)((s8 *)arg0 + 0x3C8)]->level)));
            create__10TTecDebandFlll(arg0, arg0 + 0x38, TObjEneDD::clamp_frame_index(((Param_8031A2A0 * *)TObjEneMe3SinowZoa__kind_param_tbls)[*(s32 *)((s8 *)arg0 + 0x3C8)]->level));
        } else {
            create_instance__9TTecZaruaFllll(arg0, arg0 + 0x38, arg0 + 0x38, TObjEneDD::clamp_frame_index(((Param_8031A2A0 * *)TObjEneMe3SinowZoa__kind_param_tbls)[*(s32 *)((s8 *)arg0 + 0x3C8)]->level));
            create__9TTecJelinFllll(arg0, arg0 + 0x38, arg0 + 0x38, TObjEneDD::clamp_frame_index(((Param_8031A2A0 * *)TObjEneMe3SinowZoa__kind_param_tbls)[*(s32 *)((s8 *)arg0 + 0x3C8)]->level));
        }
    } else {
        TTecResta::create((void *)arg0, arg0 + 0x38, (void *)lv);
    }
}

void TObjEneMe3SinowZoa::sub_8031A3D8() {
    if (((s32 (*)(void *))sub_8031A454__18TObjEneMe3SinowZoaFv)(this) != 0) {
        *(s32 **)((s8 *)((u8 *)this) + 0x24) = &lbl_80542FDC.value;
        initialize_enemy_state__9TObjEneDDFv(this, 0x46);
        *(s32 *)((s8 *)((u8 *)this) + 0x3C8) = 1;
        return;
    }
    *(s32 **)((s8 *)((u8 *)this) + 0x24) = (s32 *) *(s32 **)((s8 *)(*(u8 **)((s8 *)TObjEneMe3SinowZoa__data_805D6AD8 + 0x42C)) + 0xC);
    initialize_enemy_state__9TObjEneDDFv(this, 0x45);
    *(s32 *)((s8 *)((u8 *)this) + 0x3C8) = 0;
}

u8 TObjEneMe3SinowZoa::sub_8031A454() {
    return (u8) (*(s32 *)((s8 *)((u8 *)this) + 0x400) >= 1);
}

int select_and_apply_target__18TObjEneMe3SinowZoaFPv(void* p) { return select_and_apply_target__12TObjEneDD_STFf(p); }

u8 TObjEneMe3SinowZoa::is_outside_visible_range() {
    T_8031A494 *self = (T_8031A494 *)this;
    s32 r = 0;
    if (self->f354 < (*(f32 *)&TObjEneMe3SinowZoa__data_805DF2F4) ||
        (self->f354 >= (*(f32 *)&TObjEneMe3SinowZoa__data_805DF32C) && self->f354 < (*(f32 *)&TObjEneMe3SinowZoa__data_805DF328))) r = 1;
    return r;
}

s32 TObjEneMe3SinowZoa::sub_8031A4D0() {
    return *(f32 *)((s8 *)((u8 *)this) + 0x354) < TObjEneMe3SinowZoa__data_805DF32C;
}

void TObjEneMe3SinowZoa::vfunc_89() {
    struct VObj_8031A4E8 *o = (struct VObj_8031A4E8 *)this;
    o->m86();
    ((TObjPlayer *)this)->check_object_collisions();
    check_enemy_body_collisions(this);
    ((TObjPlayer *)this)->update_enemy_collision_flags();
}

void TObjEneMe3SinowZoa::update_distance_state() {
    VObj_8031A538 *o = (VObj_8031A538 *)this;
    f32 thr = lbl_805DF378;
    if ((*(f32 *)((s8 *)this + 0x3E0) - *(f32 *)((s8 *)this + 0x3C)) > thr) {
        o->m95();
        return;
    }
    o->m96();
}

void TObjEneMe3SinowZoa::vfunc_112() {  }

void TObjEneMe3SinowZoa::vfunc_111() {  }

s32 TObjEneMe3SinowZoa::try_run_effect_m7() {
    u8 *arg0 = (u8 *)this;

    if (*(s32 *)((s8 *)arg0 + 0x3CC) & 4) {
        ((VObj8031A598*)(arg0 + 0x414))->m7();
        return 1;
    }
    return 0;
}

s32 TObjEneMe3SinowZoa::try_run_effect_m6() {
    u8 *arg0 = (u8 *)this;

    if (*(s32 *)((s8 *)arg0 + 0x3CC) & 4) {
        ((VObj8031A5E0*)(arg0 + 0x414))->m6();
        return 1;
    }
    return 0;
}

void TObjEneMe3SinowZoa::vfunc_107() {  }

u8 TObjEneMe3SinowZoa::is_target_in_range() {
    f32 temp_f1;
    s32 var_r31;

    var_r31 = 0;
    if (!(*(s32 *)((s8 *)this + 0x3CC) & 0x10000)) {
        temp_f1 = *(f32 *)((s8 *)this + 0x3AC);
        if ((temp_f1 > lbl_805DF37C) && (temp_f1 < lbl_805DF380) && (((s32 (*)(void *, s32, f32))check_body_collision_at__18TObjEneMe3SinowZoaFlf)(this, *(s32 *)((s8 *)this + 0x60), temp_f1 - (*(f32 *)&TObjEneMe3SinowZoa__data_805DF320)) == 0)) {
            var_r31 = 1;
        }
    }
    return (u8)var_r31;
}

void TObjEneMe3SinowZoa::vfunc_108() {  }

void TObjEneMe3SinowZoa__sub_8031A6A0(u8 *arg0) {
    f32 d;
    s32 near;
    VObj_18_bd3b49 *pl;
    near = objInBand((GameObj *)arg0, (f32)lbl_805DF2F8);
    if (objInBand((GameObj *)arg0, (f32)TObjEneMe3SinowZoa__data_805DF2F0) != 0 || near != 0) {
        if (((TObjEneDD_ST *)arg0)->enemy_check_target_valid() != 0) {
            if ((*(VObj_18_bd3b49 **)((s8 *)arg0 + 0x390))->m18(arg0, TObjEneMe3SinowZoa__data_805DF2F4) != 0) {
                d = (*(VObj_18_bd3b49 **)((s8 *)arg0 + 0x390))->m20(arg0, TObjEneMe3SinowZoa__data_805DF2F4);
                (*(VObj_18_bd3b49 **)((s8 *)arg0 + 0x390))->m23(arg0, TObjEneMe3SinowZoa__data_805DF328);
                if (d > TObjEneMe3SinowZoa__data_805DF31C) {
                    if (((s32 (*)(void *))sub_8031A454__18TObjEneMe3SinowZoaFv)(arg0) != 0) {
                        pl = *(VObj_18_bd3b49 **)((s8 *)arg0 + 0x390);
                        if (is_locally_controlled__10TObjPlayerFPv(pl) != 0 && get_item_field_6__10TObjPlayerFPv(pl) != 0) {
                            send_6x26_unequip_item__10TObjPlayerFPvPv(pl, get_item_id__5TItemFv());
                            ((TObjPlayer *)pl)->get_hand_joint_position((s32)(arg0 + 0x408));
                            spawn_particle_effect(arg0 + 0x408, 0x1D0);
                        }
                    } else if (near != 0 && calc_boss4_scale__10TObjPlayerFi((s32) arg0) <= lbl_805DF384) {
                        TObjEneDD__sub_800BA438(arg0, *(void **)((s8 *)arg0 + 0x390));
                    }
                }
            }
        }
        ((s32 (*)(int, void *, int, int))play_sound_effect)(0x4003AA2B, arg0 + 0x38, 0, 0);
    }
}

#pragma push
#pragma fp_contract on
bool TObjEneMe3SinowZoa__sub_8031A820(u8 *ene_dd) {
    f32 temp_f31;
    if (fabs_float(*(f32 *)((s8 *)(*(u8 **)((s8 *)ene_dd + 0x390)) + 0x3C) - *(f32 *)((s8 *)ene_dd + 0x3C)) >= TObjEneMe3SinowZoa__data_805DF320) {
        if (calc_boss4_scale__10TObjPlayerFi((s32) ene_dd) <= *(f32 *)((s8 *)ene_dd + 0x3F4)) {
            transition_enemy_state__9TObjEneDDFs(ene_dd, 0xC);
            goto block_4;
        }
        return 0;
    }
block_4:
    if (*(f32 *)((s8 *)ene_dd + 0x3AC) > lbl_805DF350) {
        return 0;
    }
    temp_f31 = (*(f32 *)((s8 *)ene_dd + 0x3A0) * sin_table_lookup(*(s32 *)((s8 *)ene_dd + 0x60))) + (*(f32 *)((s8 *)ene_dd + 0x3A8) * cos_table_lookup(*(s32 *)((s8 *)ene_dd + 0x60)));
    return (temp_f31 < cos_table_lookup(0x1E00)) == 0;
}
#pragma pop

#pragma push
#pragma fp_contract on
#pragma fp_contract on
u8 TObjEneMe3SinowZoa::check_body_collision_at(s32 arg1, f32 farg0) {
    f32 f2 = farg0 * lbl_805DF304;
    Sub_800E750C *s = ((Obj_800E750C *)this)->fA4;
    u8 res;
    s32 a = ((Obj_800E750C *)this)->f60;
    s32 b = s->f18;
    s->f0 = TObjEneMe3SinowZoa__data_805DF31C;
    s->f8 = f2;
    s->fC = f2;
    s->f10 = TObjEneMe3SinowZoa__data_805DF2FC;
    s->f14 = 1;
    s->f18 = 0x9D01;
    ((Obj_800E750C *)this)->f60 = arg1;
    ((void (*)(void *, s32, f32, f32))check_enemy_body_collisions)(this, arg1, TObjEneMe3SinowZoa__data_805DF31C, f2);
    res = (s->f18 & 0x380000) != 0;
    fn_8002B630(s, sinow_zoa_collision_parts, s->f18 & 0x380000);
    s->f18 = b;
    ((Obj_800E750C *)this)->f60 = a;
    return res;
}
#pragma pop

#pragma push
#pragma fp_contract on
f32 TObjEneMe3SinowZoa::get_node_height() {
    Obj_800E75AC *self = (Obj_800E75AC *)this;
    Vec_800E75AC v;
    Node_800E75AC *node;
    v.x = TObjEneMe3SinowZoa__data_805DF31C;
    v.y = TObjEneMe3SinowZoa__data_805DF31C;
    v.z = TObjEneMe3SinowZoa__data_805DF31C;
    push_matrix_from(identity_matrix);
    bind_motion_context(self->ff8, self->fc0);
    node = self->node;
    compose_motion_node_matrix(node);
    compose_motion_node_matrix(node->child);
    matrix_mult_vec(0, &v, &v);
    pop_matrix();
    return v.y;
}
#pragma pop

void TObjEneMe3SinowZoa::setup_move_bounds() {
    if (((s32 (*)(void))sub_8031A4D0__18TObjEneMe3SinowZoaFv)() != 0) {
        *(s32 *)((s8 *)this + 0x3C0) = 1;
    } else {
        *(s32 *)((s8 *)this + 0x3C0) = 0;
    }
    *(s32 *)((s8 *)this + 0x3C4) = ((s32 (*)(void *))is_outside_visible_range__18TObjEneMe3SinowZoaFv)(this);
    if ((s32) *(s32 *)((s8 *)this + 0x3C4) == 1) {
        *(s16 *)((s8 *)this + 0xB8) = 2;
    } else {
        *(s16 *)((s8 *)this + 0xB8) = 0;
    }
    *(f32 *)((s8 *)this + 0x3E8) = (f32) (lbl_805DF388 + *(f32 *)((s8 *)this + 0x35C));
    *(f32 *)((s8 *)this + 0x3EC) = (f32) (0.3f + *(f32 *)((s8 *)this + 0x358));
    *(f32 *)((s8 *)this + 0x3F0) = (f32) (lbl_805DF38C + *(f32 *)((s8 *)this + 0x364));
    *(f32 *)((s8 *)this + 0x3F4) = (f32) (lbl_805DF304 + *(f32 *)((s8 *)this + 0x360));
    *(s32 *)((s8 *)this + 0x400) = (s32) *(s32 *)((s8 *)this + 0x368);
}

void TObjEneMe3SinowZoa::vfunc_96() { vfunc_96__9TObjEneDDFv(this); sub_800F5864((s32)((void*)38)); }

void TObjEneMe3SinowZoa::vfunc_95() { vfunc_95__9TObjEneDDFv(this); sub_800F5874((s32)((void*)38)); }

void TObjEneMe3SinowZoa::vfunc_88() {
    *(f32 *)((s8 *)(*(void **)((s8 *)this + 0xA4)) + 4) = (f32) (*(f32 *)((s8 *)this + 0x300) - *(f32 *)((s8 *)this + 0x3C));
}

void TObjEneMe3SinowZoa::copy_pos_with_height_offset() {
    u8 *arg0 = (u8 *)this;
    VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)(arg0 + 0x38));
    *(f32 *)((s8 *)arg0 + 0x300) = (f32) (*(f32 *)((s8 *)arg0 + 0x300) + (TObjEneMe3SinowZoa__data_805DF2FC + *(f32 *)((s8 *)arg0 + 0x3E4)));
    VecCopy((Vec *)(arg0 + 0x74), (const Vec *)(arg0 + 0x38));
}

void TObjEneMe3SinowZoa::vfunc_61() {  }

void TObjEneMe3SinowZoa::vfunc_62() {
    u8 *arg0 = (u8 *)this;
    if (*(s32 *)((s8 *)arg0 + 0x3CC) & 1) {
        ((TObjEneDD *)arg0)->clear_attack_receipts();
        if (((s32) *(s32 *)((s8 *)arg0 + 0x3C0) == 1) && (calc_boss4_scale__10TObjPlayerFi((s32) arg0) <= *(f32 *)((s8 *)arg0 + 0x3F0))) {
            ((int (*)(void*, void*))transition_enemy_state__9TObjEneDDFs)(arg0, (void*)(0x12));
        }
    } else if ((s16) *(s16 *)((s8 *)arg0 + 0x326) != 0xE) {
        ((int (*)(void*, void*))transition_enemy_state__9TObjEneDDFs)(arg0, (void*)(0xE));
    }
}

void TObjEneMe3SinowZoa::vfunc_63() { if (*(short*)((char*)this + 0x326) != 15) { ((int (*)(void*, void*))transition_enemy_state__9TObjEneDDFs)(this, (void*)15); } }

void TObjEneMe3SinowZoa::vfunc_28() {  }

void TObjEneMe3SinowZoa::sub_8031AC74() {
    s32 temp_r3;
    s32 temp_r3_2;
    u8 *arg0 = (u8 *)this;
    if (*(s32 *)((s8 *)arg0 + 0x30) & 0x24) {
        if (((s32) *(s32 *)((s8 *)arg0 + 0x3C0) != 0) || (temp_r3 = *(s32 *)((s8 *)arg0 + 0x3CC), (((temp_r3 & 0x100000) == 0) == 0)) || (temp_r3 & 4)) {
            *(s32 *)((s8 *)arg0 + 0x3CC) = (s32) (*(s32 *)((s8 *)arg0 + 0x3CC) | 4);
            if (((VObj_14_c143b1 *)(arg0 + (1044)))->m5() != 0) {
                *(s32 *)((s8 *)arg0 + 0x3C0) = 0;
                *(s32 *)((s8 *)arg0 + 0x3CC) = (s32) (*(s32 *)((s8 *)arg0 + 0x3CC) & 0xFFEFFFFB);
                *(s32 *)((s8 *)arg0 + 0x3CC) = (s32) (*(s32 *)((s8 *)arg0 + 0x3CC) | 0x40000);
                ((TUnk_804AF8A0 *)arg0)->clear_player_status_flag(0, 0x08000000);
            }
        }
        if ((s16) *(s16 *)((s8 *)arg0 + 0x326) == 0x11) {
            transition_enemy_state__9TObjEneDDFs(arg0, 0x12);
        }
    } else {
        temp_r3_2 = *(s32 *)((s8 *)arg0 + 0x3CC);
        if (!(temp_r3_2 & 0x100000) && !(temp_r3_2 & 4) && (TObjEneMe3SinowZoa__sub_800D72A4(arg0 + 0x414) != 0)) {
            if ((s32) *(s32 *)((s8 *)arg0 + 0x3C0) != 0) {
                if (((VObj_14_c143b1 *)(arg0 + (1044)))->m4() != 0) {
                    *(s32 *)((s8 *)arg0 + 0x3CC) = (s32) (*(s32 *)((s8 *)arg0 + 0x3CC) | 0x40000);
                    ((TUnk_804AF8A0 *)arg0)->set_indexed_flags(0, 0x08000000);
                }
            } else if (((VObj_14_c143b1 *)(arg0 + (1044)))->m5() != 0) {
                *(s32 *)((s8 *)arg0 + 0x3CC) = (s32) (*(s32 *)((s8 *)arg0 + 0x3CC) | 0x40000);
                ((TUnk_804AF8A0 *)arg0)->clear_player_status_flag(0, 0x08000000);
            }
        }
    }
}

void TObjEneMe3SinowZoa::run_task() {
    s32 temp_r3;
    if (TObjPlayer::check_demo_mode() != 0) {
        this->vfunc_115();
        return;
    }
    if (this->vfunc_83() != 4) {
        this->vfunc_85();
    }
    sub_8031AC74();
    this->copy_pos_with_height_offset();
    this->vfunc_88();
    temp_r3 = *(s32 *)((s8 *)((u8 *)this) + 0x3CC);
    if (temp_r3 & 0x40000) {
        *(s32 *)((s8 *)((u8 *)this) + 0x3CC) = (s32) (temp_r3 & 0xFFFBFFFF);
    } else {
        ((TBoss8Dragon *)((u8 *)this))->set_player_state_default();
    }
    if (((s32) *(s32 *)((s8 *)((u8 *)this) + 0x3C0) == 0) || (TObjEneMe3SinowZoa__sub_800D72A4(((u8 *)this) + 0x414) != 0)) {
        this->vfunc_100();
    }
    if (*(s32 *)((s8 *)((u8 *)this) + 0x3D0) & 0x4000) {
        TObjEneRecon::set_active();
    }
}

void *__dt__18TObjEneMe3SinowZoaFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__18TObjEneMe3SinowZoa;
        if (*(void **)((s8 *)arg0 + 0x454) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x454)); *(s32 *)((s8 *)arg0 + 0x454) = 0; }
        if (*(void **)((s8 *)arg0 + 0x458) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x458)); *(s32 *)((s8 *)arg0 + 0x458) = 0; }
        free_collision_body_parts(arg0);
        __dt__13TUnk_80494938Fv((s8 *)arg0 + 0x414, -1);
        __dt__12TObjEneDD_STFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

#pragma push
#pragma opt_propagation off
void TObjEneMe3SinowZoaReal::init_enemy() {
    s32 temp_r0;
    u8 *temp_r6;
    Tbl_8031AF88 *tbl = &lbl_80542FB0;

    init_position_vectors();
    sub_8031A3D8();
    temp_r6 = (u8 *)(*(u8 **)((s8 *)TObjEneMe3SinowZoa__data_805D6AD8 + 0x42C));
    *(s32 *)((s8 *)((u8 *)this) + 0x34) = (s32) *(s32 *)((s8 *)temp_r6 + 8);
    init_model__9TObjEneDDFv((void *)this, ((void * *)sinow_zoa_collision_parts), 1, (int)temp_r6);
    *(s32 *)((s8 *)((u8 *)this) + 0xB0) = 0;
    this->set_field_d8((s32)lbl_804E8880);
    this->set_field_dc((int) (*(s32 *)((s8 *)TObjEneMe3SinowZoa__data_805D6AD8 + 0x430)));
    set_animation((*(s16 *)((s8 *)((u8 *)this) + 0xB8)));
    temp_r0 = *(s32 *)((s8 *)((u8 *)this) + 0x3C8);
    {
        s32 *a = tbl->t[0];
        s32 *b = tbl->t[1];
        s32 *c = tbl->t[2];
        reset_hp__9TObjEneDDFv((void *)this, a[temp_r0], b[temp_r0], c[temp_r0]);
    }
    this->check_state_flag_4();
    *(void **)((s8 *)((u8 *)this) + 0x350) = TObjEneMe3SinowZoa_init_params;
    *(f32 *)((s8 *)((u8 *)this) + 0x37C) = (f32) TObjEneMe3SinowZoa__data_805DF314;
    enemy_init_acquire_period(0x1E);
    enemy_init_validate_period(0x1E);
    *(s32 *)((s8 *)((u8 *)this) + 0x3CC) = 0;
    *(s32 *)((s8 *)((u8 *)this) + 0x3D0) = 0;
    VecCopy((Vec *)((u8 *)this + 0x3D4), (const Vec *)((u8 *)this + 0x38));
    *(f32 *)((s8 *)((u8 *)this) + 0x3E0) = (*(f32 *)((s8 *)((u8 *)this) + 0x3C));
    *(f32 *)((s8 *)((u8 *)this) + 0x3E4) = (f32) TObjEneMe3SinowZoa__data_805DF31C;
    *(s32 *)((s8 *)((u8 *)this) + 0x3F8) = 0;
    *(s32 *)((s8 *)((u8 *)this) + 0x3FC) = 0;
    *(s16 *)((s8 *)((u8 *)this) + 0x404) = (s16) *(s16 *)((s8 *)((u8 *)this) + 0x2CC);
    ((VObj_14_2ab9de *)((u8 *)this + (1044)))->m3();
    *(s32 *)((s8 *)((u8 *)this) + 0x434) = 0;
    *(s32 *)((s8 *)((u8 *)this) + 0x438) = 0;
    *(s32 *)((s8 *)((u8 *)this) + 0x43C) = 0;
    *(f32 *)((s8 *)((u8 *)this) + 0x440) = (f32) TObjEneMe3SinowZoa__data_805DF31C;
    *(f32 *)((s8 *)((u8 *)this) + 0x444) = (f32) TObjEneMe3SinowZoa__data_805DF31C;
    *(f32 *)((s8 *)((u8 *)this) + 0x448) = (f32) TObjEneMe3SinowZoa__data_805DF31C;
    *(f32 *)((s8 *)((u8 *)this) + 0x44C) = (f32) TObjEneMe3SinowZoa__data_805DF31C;
    *(f32 *)((s8 *)((u8 *)this) + 0x450) = (f32) TObjEneMe3SinowZoa__data_805DF31C;
    *(s32 *)((s8 *)((u8 *)this) + 0x454) = 0;
    *(s32 *)((s8 *)((u8 *)this) + 0x458) = 0;
    if ((s32) *(s32 *)((s8 *)((u8 *)this) + 0x3C0) == 1) {
        set_indexed_flags(0, 0x08000000);
    } else {
        this->clear_player_status_flag(0, 0x08000000);
    }
}
}
#pragma pop
