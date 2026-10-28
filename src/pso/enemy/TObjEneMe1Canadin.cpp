#include "types.h"
#include "pso/enemy/TObjEneEpsilon.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/enemy/TObjEneDD_ST.h"
#include "pso/enemy/TObjEneMe1Canadin.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TUnk_804806E8.h"
#include "pso/enemy/TObjEneDf2Bringer_Eff_Rush.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/TObjMotion.h"
extern "C" void has_flag_0x800__13TUnk_804806E8Fv();
extern "C" void test_flag30_512__13TUnk_804806E8Fv();
extern "C" void test_flag_1000__13TUnk_804806E8Fv();
extern "C" void test_flag_256__13TUnk_804806E8Fv();
#include "pso/system/vector.h"

#include "pso/enemy/TUnk_80494938.h"
#include <stddef.h>

#include "pso/enemy/TObjEneMe1CanadinLeader.h"
#include "pso/TObject.h"
#include "pso/TParticleCtrl.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/boss/TBoss8Dragon.h"
#include "pso/boss/TObjBoss2Tunnel.h"

#include "pso/enemy/TObjEneMe1Gee.h"
#include "pso/enemy/TObjEneMe3SinowZoa.h"
#include "pso/enemy/TObjEnePanarms.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/misc/TNowLoading.h"
#include "pso/object/TObjFish.h"

#define VIRT(n) virtual void m##n() = 0;
#define F_8009C510(off) (*(f32 *)(arg0 + (off)))
#define I_8009C510(off) (*(s32 *)(arg0 + (off)))

struct VBase_8009AD18 { char pad[0x18]; };
struct VObj_8009AD18 : VBase_8009AD18 {
    virtual s32 m0();
    virtual s32 m1();
    virtual s32 m2();
    virtual s32 m3();
    virtual s32 m4();
    virtual s32 m5();
    virtual s32 m6();
    virtual s32 m7();
    virtual s32 m8();
    virtual s32 m9();
    virtual s32 m10();
    virtual s32 m11();
    virtual s32 m12();
    virtual s32 m13();
    virtual s32 m14();
    virtual s32 m15();
    virtual s32 m16();
    virtual s32 m17();
    virtual s32 m18();
    virtual s32 m19();
    virtual s32 m20();
    virtual s32 m21();
    virtual s32 m22();
    virtual s32 m23();
    virtual s32 m24();
    virtual s32 m25();
    virtual s32 m26();
    virtual s32 m27();
    virtual s32 m28();
    virtual s32 m29();
    virtual s32 m30();
    virtual s32 m31();
    virtual s32 m32();
    virtual s32 m33();
    virtual s32 m34();
    virtual s32 m35();
    virtual s32 m36();
    virtual s32 m37();
    virtual s32 m38();
    virtual s32 m39();
    virtual s32 m40();
    virtual s32 m41();
    virtual s32 m42();
    virtual s32 m43();
    virtual s32 m44();
    virtual s32 m45();
    virtual s32 m46();
    virtual s32 m47();
    virtual s32 m48();
    virtual s32 m49();
    virtual s32 m50();
    virtual s32 m51();
    virtual s32 m52();
    virtual s32 m53();
    virtual s32 m54();
    virtual s32 m55();
    virtual s32 m56();
    virtual s32 m57();
    virtual s32 m58();
    virtual s32 m59();
    virtual s32 m60();
    virtual s32 m61();
    virtual s32 m62();
    virtual s32 m63();
    virtual s32 m64();
    virtual s32 m65();
    virtual s32 m66();
    virtual s32 m67();
    virtual s32 m68();
    virtual s32 m69();
    virtual s32 m70();
    virtual s32 m71();
    virtual s32 m72();
    virtual s32 m73();
    virtual s32 m74();
    virtual s32 m75();
    virtual s32 m76();
    virtual s32 m77();
    virtual s32 m78();
    virtual s32 m79();
    virtual s32 m80();
    virtual s32 m81();
    virtual s32 m82();
    virtual s32 m83();
    virtual s32 m84();
    virtual s32 m85();
    virtual s32 m86();
    virtual s32 m87();
    virtual s32 m88();
    virtual s32 m89();
    virtual s32 m90();
    virtual s32 m91();
    virtual s32 m92();
    virtual s32 m93();
    virtual s32 m94();
};

struct Obj_8009AD18 {
    u8 pad0[0x3C];
    f32 f3C;
    u8 pad40[0x390 - 0x40];
    s32 f390;
    u8 pad394[0x3C8 - 0x394];
    u32 flags3C8;
    u8 pad3CC[0x400 - 0x3CC];
    s32 timer;
    u8 pad404[0x470 - 0x404];
    s32 sub;
    u8 pad474[0x4A8 - 0x474];
    f32 f4A8;
    f32 f4AC;
    f32 f4B0;
    u8 pad4B4[0x4B8 - 0x4B4];
    s32 f4B8;
    u8 pad4BC[0x4D0 - 0x4BC];
    s32 count;
    void *members[8];
    s32 f4F4;
};

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

struct VBase_18_8dc821 { char pad[0x18]; };

struct VObj_18_8dc821 : VBase_18_8dc821 {
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
    virtual void m106();
    virtual void m107();
    virtual void m108();
    virtual void m109();
    virtual void m110();
    virtual s32 m111();
    virtual void m112();
    virtual s32 m113();
};

struct Vec_8009C91C { f32 x, y, z; };

struct Can_8009C91C {
    u8 pad0[0x38];
    Vec_8009C91C pos38;
    u8 pad44[0x60 - 0x44];
    s32 angle;
    u8 pad64[0x394 - 0x64];
    Vec_8009C91C base;
    Vec_8009C91C vel;
    f32 f3AC;
    u8 pad3B0[0x3C8 - 0x3B0];
    u32 flags;
    u8 pad3CC[0x3E8 - 0x3CC];
    f32 f3E8;
    u8 pad3EC[0x3F4 - 0x3EC];
    f32 f3F4;
    f32 f3F8;
    u8 pad3FC[0x404 - 0x3FC];
    s32 f404;
    s32 f408;
    u8 pad40C[0x414 - 0x40C];
    u8 f414[0x470 - 0x414];
    s32 mode;
    s32 timer;
    s32 count;
    u8 pad47C[4];
    s32 rot;
    f32 f484;
    f32 dist;
    f32 ddist;
    Vec_8009C91C dir;
    u8 pad49C[0x4B4 - 0x49C];
    s32 f4B4;
};

struct VBase_18_2d9fb9 { char pad[0x18]; };

struct VObj_18_2d9fb9 : VBase_18_2d9fb9 {
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
    virtual void m100();
    virtual void m101();
    virtual void m102();
    virtual void m103();
    virtual void m104();
    virtual void m105();
    virtual s32 m106();
};

struct Vec_8009CC74 { f32 x, y, z; };

struct Can_8009CC74 {
    u8 pad0[0x30];
    u32 f30;
    u8 pad34[0x3C - 0x34];
    f32 f3C;
    u8 pad40[0x2FC - 0x40];
    u8 snd[0x390 - 0x2FC];
    void *target;
    u8 pad394[0x3A0 - 0x394];
    Vec_8009CC74 vel;
    f32 f3AC;
    u8 pad3B0[0x3C0 - 0x3B0];
    void *f3C0;
    u8 pad3C4[0x3C8 - 0x3C4];
    u32 flags;
    u8 pad3CC[0x3EC - 0x3CC];
    f32 f3EC;
    u8 pad3F0[0x3F4 - 0x3F0];
    f32 f3F4;
    f32 f3F8;
    u8 pad3FC[0x404 - 0x3FC];
    s32 f404;
    s32 f408;
    u8 pad40C[0x414 - 0x40C];
    u8 f414[0x450 - 0x414];
    Vec_8009CC74 v450;
    Vec_8009CC74 v45C;
    f32 *f468;
    u8 pad46C[4];
    s32 mode;
    s32 timer;
    s32 side;
    u8 pad47C[0x484 - 0x47C];
    f32 speed;
    f32 dheight;
    u8 pad48C[0x4B4 - 0x48C];
    s32 f4B4;
    u8 pad4B8[0x4C8 - 0x4B8];
    u16 f4C8;
};

struct Base_8009CC74 { char pad[0x18]; };

struct VObj_8009CC74 : Base_8009CC74 {
    virtual void pad_8(); virtual void pad_c(); virtual void pad_10(); virtual void pad_14();
    virtual void pad_18(); virtual void pad_1c(); virtual void pad_20(); virtual void pad_24();
    virtual void pad_28(); virtual void pad_2c(); virtual void pad_30(); virtual void pad_34();
    virtual void pad_38(); virtual void pad_3c(); virtual void pad_40(); virtual void pad_44();
    virtual void pad_48(); virtual void pad_4c();
    virtual s32 m18(void *, f32);
    virtual void pad_54();
    virtual void m20(void *, f32);
    virtual void pad_5c(); virtual void pad_60();
    virtual void m23(void *, f32);
    virtual void pad_68(); virtual void pad_6c(); virtual void pad_70(); virtual void pad_74();
    virtual void pad_78(); virtual void pad_7c(); virtual void pad_80(); virtual void pad_84();
    virtual void pad_88(); virtual void pad_8c(); virtual void pad_90(); virtual void pad_94();
    virtual void pad_98(); virtual void pad_9c(); virtual void pad_a0(); virtual void pad_a4();
    virtual void pad_a8(); virtual void pad_ac(); virtual void pad_b0(); virtual void pad_b4();
    virtual void pad_b8(); virtual void pad_bc(); virtual void pad_c0();
    virtual void m47();
    virtual void pad_c8(); virtual void pad_cc(); virtual void pad_d0(); virtual void pad_d4();
    virtual void pad_d8(); virtual void pad_dc(); virtual void pad_e0(); virtual void pad_e4();
    virtual void pad_e8(); virtual void pad_ec(); virtual void pad_f0(); virtual void pad_f4();
    virtual void pad_f8(); virtual void pad_fc(); virtual void pad_100(); virtual void pad_104();
    virtual void pad_108(); virtual void pad_10c(); virtual void pad_110(); virtual void pad_114();
    virtual void pad_118(); virtual void pad_11c(); virtual void pad_120(); virtual void pad_124();
    virtual void m72(s32);
    virtual void pad_12c(); virtual void pad_130(); virtual void pad_134();
    virtual void pad_138(); virtual void pad_13c(); virtual void pad_140(); virtual void pad_144();
    virtual void pad_148(); virtual void pad_14c(); virtual void pad_150(); virtual void pad_154();
    virtual void pad_158(); virtual void pad_15c(); virtual void pad_160(); virtual void pad_164();
    virtual void pad_168(); virtual void pad_16c(); virtual void pad_170(); virtual void pad_174();
    virtual void pad_178(); virtual void pad_17c(); virtual void pad_180(); virtual void pad_184();
    virtual void pad_188(); virtual void pad_18c(); virtual void pad_190(); virtual void pad_194();
    virtual void pad_198(); virtual void pad_19c(); virtual void pad_1a0(); virtual void pad_1a4();
    virtual void pad_1a8(); virtual void pad_1ac(); virtual void pad_1b0(); virtual void pad_1b4();
    virtual void pad_1b8(); virtual void pad_1bc(); virtual void pad_1c0(); virtual void pad_1c4();
    virtual void pad_1c8(); virtual void pad_1cc();
    virtual s32 m114(void *);
};

struct Vec_8009D320 { f32 x, y, z; };

struct Prm_8009D320 { u8 pad[0x18]; s32 f18; s32 f1C; s32 f20; s32 f24; };

struct Can_8009D320 {
    u8 pad0[0x30];
    u32 f30;
    u8 pad34[0xB8 - 0x34];
    s16 fB8;
    u8 padBA[0x2FC - 0xBA];
    u8 snd[0x394 - 0x2FC];
    Vec_8009D320 base;
    u8 pad3A0[0x3C8 - 0x3A0];
    u32 flags;
    u8 pad3CC[0x404 - 0x3CC];
    s32 f404;
    u8 pad408[0x414 - 0x408];
    u8 f414[0x468 - 0x414];
    Prm_8009D320 *prm;
    u8 pad46C[4];
    s32 mode;
    s32 timer;
    u8 pad478[0x490 - 0x478];
    Vec_8009D320 pos;
    void *f49C;
    void *f4A0;
};

struct VBase_18_26a62c { char pad[0x18]; };

struct VObj_18_26a62c : VBase_18_26a62c {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
};

extern "C" {
s32 is_main_phase_15__9TObjEneDDFv();
s32 update_player_state__9TObjEneDDFv(void *, int, int);
s32 defer_render__7TObjectFv(void *);
s32 rotate_matrix_y(int, int);
s32 rotate_matrix_z(int, int);
void translate_matrix(u32 arg0, f32 x, f32 y, f32 z);
s32 push_matrix();
s32 pop_matrix();
s32 post_translate_matrix(void *);
void fn_8009BD00(void);
extern s32 lbl_8043A268[];
extern s32 lbl_8043A274[];
extern u32 lbl_805D4FD4;
extern s32 TObjEneMe1Canadin__render_point_cursor;
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
extern const f32 lbl_805D9898;
extern const f32 lbl_805D98A0;
extern const f32 lbl_805D98A4;
extern const f32 lbl_805D9E84;
extern const f32 lbl_805D9E88;
void render__17TObjEneMe1CanadinFv(u8 *arg0);
f64 atan2_float(f32, f32);
void rotate_xz_pair_by_angle(f32 *arg0, f32 *arg1, s32 arg2);
void TObjEneMe1Canadin__sub_8009E930(u8 *arg0);
void TObjEneMe1Canadin__sub_8009E948(u8 *arg0);
void push_history_entry__17TObjEneMe1CanadinFPvfPvi(s32, f32, void *, s32);
f32 calc_elapsed_scaled__9TObjEneDDFv(void *);
s32 advance_animation_playback();
f32 subtract_vector(void *, void *);
extern const f64 lbl_8043A3C8;
extern const f32 TObjEneMe1Canadin__data_805D988C;
extern const f32 TObjEneMe1Canadin__data_805D98B4;
extern const f32 lbl_805D98D8;
extern const f32 lbl_805D98DC;
extern const f32 lbl_805D98E0;
extern const f32 lbl_805D98E4;
void TObjEneMe1Canadin__sub_8009C91C(void *arg0, s32 arg1);
s32 queue_destruction__7TObjectFv(void *);
void *create_particle_emitter(void *, s32);
void noop__17TObjEneMe1CanadinFv(void);
void advance_state_5_to_4__17TObjEneMe1CanadinFPv(void *arg0);
void TObjEneMe1Canadin_EffDischarge__ct(void *, void *, void *, void *);
u8 *TObjEneMe1Canadin_EffLine__ct(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
void TObjEneEpsilon__sub_800B92F8(u8 *arg0, s32 arg1, f32 farg0);
s32 transition_enemy_state__9TObjEneDDFs(void *, s32);
s32 play_sound_effect(s32, void *, s32, s32);
void * __nw__7TObjectFUl(int);
extern const s32 canadin_formation_reset_vec4[];
extern u8 TObjEneMe1Canadin__map_core_default_vec4[];
extern const f32 TObjEneMe1Canadin__data_805D98BC;
extern const f32 lbl_805D9910;
void TObjEneMe1Canadin__sub_8009D320(void *arg0, s32 arg1);
u32 __cvt_fp2unsigned(f32);
extern const f32 lbl_805D9914;
s32 pack_debug_text_position(s32 arg0, s32 arg1);
void draw_chunk_object(void *child);
extern s32 lbl_8043A398[];
extern s32 lbl_8043A3A8[];
extern s32 lbl_8043A3BC[];
void render_canadin_model_with_debug_type__17TObjEneMe1CanadinFv(u8 *arg0);
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
    virtual s32 m81();
    virtual void m82();
    virtual s32 m83();
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
    virtual s32 m98();
    virtual void m99();
    virtual void m100();
    virtual void m101();
    virtual void m102();
    virtual void m103();
    virtual void m104();
    virtual void m105();
    virtual void m106();
    virtual void m107();
    virtual void m108();
    virtual void m109();
    virtual void m110();
    virtual void m111();
    virtual s32 m112();
};

struct Stack_8009AA64 {
    s32 sp8;
    f32 spC;
    u8 trailing_storage[0x4];
};

struct RecoveredGlobal_8009AA64_lbl_8048FE94 { s32 value; u8 remaining[0x18]; };

typedef char RecoveredGlobal_8009AA64_lbl_8048FE94_size[sizeof(RecoveredGlobal_8009AA64_lbl_8048FE94) == 0x1C ? 1 : -1];

struct Obj_8009B3C0 {
    u8 pad[0x3c8]; u32 flags;
    u8 pad2[0x4d0 - 0x3cc]; s32 count; void *members[1];
};

struct Obj_8009B638 { u8 pad[0x46c]; s32 step; };

struct Obj_8009B1CC { u8 pad0[0x390]; void *key; u8 pad1[0x13C]; s32 count; u8 *items[8]; };

struct LeaderBase_8009AB4C { char pad[0x18]; };

struct Leader_8009AB4C : LeaderBase_8009AB4C {
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
    virtual void m101();
    virtual void m102();
    virtual void m103();
    virtual void m104();
    virtual void m105();
    virtual void m106();
    virtual s32 m107();
};

struct Fields_8009AB4C {
    u8 pad0[0x24];
    s32 field24;
    u8 pad28[0x30 - 0x28];
    u32 flags30;
    u8 pad34[0x60 - 0x34];
    s32 angle;
    u8 pad64[0x2FC - 0x64];
    u8 pos2FC[0x3C8 - 0x2FC];
    u32 flags3C8;
    u8 pad3CC[0x4D0 - 0x3CC];
    s32 count;
    void *members[1];
};

struct Info_8009B274 { u8 pad0[0x2C]; s32 f2C; };

struct Leader_8009B274 {
    u8 pad0[0x3C0];
    s32 f3C0;
    u8 pad3C4[0x3C8 - 0x3C4];
    u32 flags;
    u8 pad3CC[0x468 - 0x3CC];
    Info_8009B274 *info;
    u8 pad46C[0x4C8 - 0x46C];
    u16 f4C8;
    u8 pad4CA[0x4CC - 0x4CA];
    s32 max;
    s32 count;
    u32 ids[8];
    s32 mode;
};

struct Vec_8009B43C { f32 x, y, z; };

struct Info_8009B43C { u8 pad0[0x2C]; s32 f2C; };

struct Leader_8009B43C {
    u8 pad0[0x1C];
    u16 f1C;
    u8 pad1E[0x2C - 0x1E];
    s16 f2C;
    u8 pad2E[0x38 - 0x2E];
    Vec_8009B43C pos;
    u8 pad44[0x60 - 0x44];
    s32 angle;
    u8 pad64[0x468 - 0x64];
    Info_8009B43C *info;
    u8 pad46C[0x4CC - 0x46C];
    s32 max;
    s32 count;
    void *ids[8];
};

struct Obj_8009AF54 {
    u8 pad0[0x2FC];
    u8 pos[0x3C8 - 0x2FC];
    u32 flags3C8;
    u8 pad3CC[0x4A4 - 0x3CC];
    u8 v4A4[0x4B8 - 0x4A4];
    s32 f4B8;
    u8 pad4BC[0x4D0 - 0x4BC];
    s32 count;
    void *members[8];
    s32 state;
};

struct RecoveredGlobal_8009BD00_lbl_80500960 {
    s32 value;
    u8 remaining[0xC];
};

typedef char RecoveredGlobal_8009BD00_lbl_80500960_size[sizeof(RecoveredGlobal_8009BD00_lbl_80500960) == 0x10 ? 1 : -1];

struct VBase_18_0f49f2 { char pad[0x18]; };

struct VObj_18_0f49f2 : VBase_18_0f49f2 {
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
    virtual void m101();
    virtual void m102();
    virtual void m103();
    virtual void m104();
    virtual void m105();
    virtual void m106();
    virtual void m107();
    virtual void m108();
    virtual void m109();
    virtual void m110();
    virtual void m111();
    virtual void m112();
    virtual void m113();
    virtual void m114();
    virtual s32 m115(void *);
};

struct Stack_8009BF0C {
    s32 sp8;
    f32 spC;
};

struct VObj_18_p4 : VBase_18 {
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
    virtual s32 m93();
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
    virtual void m106();
    virtual s32 m107();
    virtual void m108();
    virtual void m109();
    virtual void m110();
    virtual void m111();
    virtual void m112();
    virtual void m113();
    virtual void m114();
    virtual s32 m115(void *);
};

struct Base14_8009C178 { char pad[0x14]; };

struct Sub_8009C178 : Base14_8009C178 {
    virtual void s0();
    virtual void s1(s32);
    virtual void s2();
    virtual void s3();
    virtual s32 s4();
};

struct Copy5_8009C2EC { u32 w[5]; };

struct Vec_8009C510 { f32 x, y, z; };

struct Base { u8 pad[0x18]; };

struct VObj : Base {
    VIRT(0) VIRT(1) VIRT(2) VIRT(3) VIRT(4) VIRT(5) VIRT(6) VIRT(7) VIRT(8) VIRT(9)
    VIRT(10) VIRT(11) VIRT(12) VIRT(13) VIRT(14) VIRT(15) VIRT(16) VIRT(17) VIRT(18) VIRT(19)
    VIRT(20) VIRT(21) VIRT(22) VIRT(23) VIRT(24) VIRT(25) VIRT(26) VIRT(27) VIRT(28) VIRT(29)
    VIRT(30) VIRT(31) VIRT(32) VIRT(33) VIRT(34) VIRT(35) VIRT(36) VIRT(37) VIRT(38) VIRT(39)
    VIRT(40) VIRT(41) VIRT(42) VIRT(43) VIRT(44) VIRT(45) VIRT(46) VIRT(47) VIRT(48) VIRT(49)
    VIRT(50) VIRT(51) VIRT(52) VIRT(53) VIRT(54) VIRT(55) VIRT(56) VIRT(57) VIRT(58) VIRT(59)
    VIRT(60) VIRT(61) VIRT(62) VIRT(63) VIRT(64) VIRT(65) VIRT(66) VIRT(67) VIRT(68) VIRT(69)
    VIRT(70) VIRT(71) VIRT(72) VIRT(73) VIRT(74) VIRT(75) VIRT(76) VIRT(77) VIRT(78) VIRT(79)
    VIRT(80) VIRT(81) VIRT(82) VIRT(83) VIRT(84) VIRT(85) VIRT(86) VIRT(87) VIRT(88) VIRT(89)
    VIRT(90) VIRT(91) VIRT(92) VIRT(93) VIRT(94) VIRT(95) VIRT(96) VIRT(97) VIRT(98) VIRT(99)
    VIRT(100) VIRT(101) VIRT(102) VIRT(103)
};

struct VBase_8009c7d8 { char pad[0x18]; };

struct VObj_8009c7d8 : VBase_8009c7d8 {
#define VM(i) virtual s32 m##i();
    VM(0)VM(1)VM(2)VM(3)VM(4)VM(5)VM(6)VM(7)VM(8)VM(9)VM(10)VM(11)VM(12)VM(13)VM(14)VM(15)
    VM(16)VM(17)VM(18)VM(19)VM(20)VM(21)VM(22)VM(23)VM(24)VM(25)VM(26)VM(27)VM(28)VM(29)VM(30)
    VM(31)VM(32)VM(33)VM(34)VM(35)VM(36)VM(37)VM(38)VM(39)VM(40)VM(41)VM(42)VM(43)VM(44)VM(45)
    VM(46)VM(47)VM(48)VM(49)VM(50)VM(51)VM(52)VM(53)VM(54)VM(55)VM(56)VM(57)VM(58)VM(59)VM(60)
    VM(61)VM(62)VM(63)VM(64)VM(65)VM(66)VM(67)VM(68)VM(69)VM(70)VM(71)VM(72)VM(73)VM(74)VM(75)
    VM(76)VM(77)VM(78)VM(79)VM(80)VM(81)VM(82)VM(83)VM(84)VM(85)VM(86)VM(87)VM(88)VM(89)VM(90)
    VM(91)VM(92)VM(93)VM(94)VM(95)VM(96)VM(97)VM(98)VM(99)VM(100)VM(101)VM(102)VM(103)VM(104)
    VM(105)VM(106)VM(107)VM(108)
#undef VM
};

struct CanadinBase_8009E0AC { char pad[0x18]; };

struct Canadin_8009E0AC : CanadinBase_8009E0AC {
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
    virtual void m101();
    virtual void m102();
    virtual void m103();
    virtual void m104();
    virtual void m105();
    virtual void m106();
    virtual void m107();
    virtual void m108(s32);
    virtual void m109(s32);
    virtual void m110(s32);
};

struct Base_Sub_8009DE90 { char pad[0x14]; };

struct V_Sub_8009DE90 : Base_Sub_8009DE90 {
    virtual void p0(); virtual void p1(); virtual void p2(); virtual void p3(); virtual void p4();
    virtual s32 m5();
};

struct ByteBlock_10 { u8 bytes[0x10]; };

struct ByteBlock_14 { u8 bytes[0x14]; };

struct RecoveredGlobal_8009E1D4_lbl_8043A32C {
    s32 value;
    u8 remaining[0x10];
};

typedef char RecoveredGlobal_8009E1D4_lbl_8043A32C_size[sizeof(RecoveredGlobal_8009E1D4_lbl_8043A32C) == 0x14 ? 1 : -1];

struct Base_8009E7C4_8009E474 { char pad[0x18]; };

struct VObj_8009E7C4_8009E474 : Base_8009E7C4_8009E474 {
    virtual void pad_8(); virtual void pad_c(); virtual void pad_10(); virtual void pad_14();
    virtual void pad_18(); virtual void pad_1c(); virtual void pad_20(); virtual void pad_24();
    virtual void pad_28(); virtual void pad_2c(); virtual void pad_30(); virtual void pad_34();
    virtual void pad_38(); virtual void pad_3c(); virtual void pad_40(); virtual void pad_44();
    virtual void pad_48(); virtual void pad_4c(); virtual void pad_50(); virtual void pad_54();
    virtual void pad_58(); virtual void pad_5c(); virtual void pad_60(); virtual void pad_64();
    virtual void pad_68(); virtual void pad_6c(); virtual void pad_70(); virtual void pad_74();
    virtual void pad_78(); virtual void pad_7c(); virtual void pad_80(); virtual void pad_84();
    virtual void pad_88(); virtual void pad_8c(); virtual void pad_90(); virtual void pad_94();
    virtual void pad_98(); virtual void pad_9c(); virtual void pad_a0(); virtual void pad_a4();
    virtual void pad_a8(); virtual void pad_ac(); virtual void pad_b0(); virtual void pad_b4();
    virtual void pad_b8(); virtual void pad_bc(); virtual void pad_c0(); virtual void pad_c4();
    virtual void pad_c8(); virtual void pad_cc(); virtual void pad_d0(); virtual void pad_d4();
    virtual void pad_d8(); virtual void pad_dc(); virtual void pad_e0(); virtual void pad_e4();
    virtual void pad_e8(); virtual void pad_ec(); virtual void pad_f0(); virtual void pad_f4();
    virtual void pad_f8(); virtual void pad_fc(); virtual void pad_100(); virtual void pad_104();
    virtual void pad_108(); virtual void pad_10c(); virtual void pad_110(); virtual void pad_114();
    virtual void pad_118(); virtual void pad_11c(); virtual void pad_120(); virtual void pad_124();
    virtual void pad_128(); virtual void pad_12c(); virtual void pad_130(); virtual void pad_134();
    virtual void pad_138(); virtual void pad_13c(); virtual void pad_140(); virtual void pad_144();
    virtual void pad_148(); virtual void pad_14c(); virtual void pad_150(); virtual void pad_154();
    virtual void pad_158(); virtual void pad_15c(); virtual void pad_160(); virtual void pad_164();
    virtual void pad_168(); virtual void pad_16c(); virtual void pad_170(); virtual void pad_174();
    virtual void pad_178(); virtual void pad_17c(); virtual void pad_180(); virtual void pad_184();
    virtual void pad_188(); virtual void pad_18c(); virtual void pad_190(); virtual void pad_194();
    virtual void pad_198(); virtual void pad_19c(); virtual void pad_1a0(); virtual void pad_1a4();
    virtual void pad_1a8(); virtual void pad_1ac(); virtual void pad_1b0(); virtual void pad_1b4();
    virtual void pad_1b8(); virtual void pad_1bc(); virtual void pad_1c0(); virtual void pad_1c4();
    virtual void pad_1c8(); virtual void pad_1cc();
    virtual s32 m114(s32);
};

struct RecoveredGlobal_8009E4AC_lbl_8043A2A0 {
    s32 value;
    u8 remaining[0xC];
};

struct TargetBase_8009E860 { char pad[0x18]; };

struct Target_8009E860 : TargetBase_8009E860 {
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
    virtual void m101();
    virtual void m102();
    virtual void m103();
    virtual void m104();
    virtual void m105();
    virtual void m106();
    virtual void m107();
    virtual void m108();
    virtual void m109();
    virtual void m110();
    virtual void m111();
    virtual void m112();
    virtual void m113();
    virtual s32 m114(u32);
};

struct Entry_8009E860 { u16 id; u8 pad2[2]; f32 dist; };

struct Canadin_8009E860 {
    u8 pad0[0x390];
    u32 owner;
    u8 pad394[0x3C0 - 0x394];
    Target_8009E860 *target;
    u8 pad3C4[0x4C8 - 0x3C4];
    u16 target_id;
};

typedef char RecoveredGlobal_8009E4AC_lbl_8043A2A0_size[sizeof(RecoveredGlobal_8009E4AC_lbl_8043A2A0) == 0x10 ? 1 : -1];

struct Stack_800CBDBC {
    s32 sp8;
    f32 spC;
};

struct VBase_8009ED5C_8009ECE0 {
    char pad[0x18];
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
};

struct RecoveredGlobal_8009F2E0___vt__17TObjEneMe1Canadin { s32 value; u8 remaining[0x1D4]; };

typedef char RecoveredGlobal_8009F2E0___vt__17TObjEneMe1Canadin_size[sizeof(RecoveredGlobal_8009F2E0___vt__17TObjEneMe1Canadin) == 0x1D8 ? 1 : -1];

struct VBase_8009F004 { char pad[0x18]; };

struct VObj_8009F004 : VBase_8009F004 {
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
    virtual void m85(s16, s32);
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
};

struct VBase14_8009F004 { char pad[0x14]; };

struct VSub_8009F004 : VBase14_8009F004 {
    virtual void m0(); virtual void m1(); virtual void m2();
};

struct Vec_8009F004 { f32 x, y, z; };

struct Obj_8009F004 { u8 pad[0x414]; Vec_8009F004 v[7]; };

struct Head_8009F004 { u8 b[0x1C]; };

struct Mdl_8009F004 { Head_8009F004 head; u8 model[0x64]; u8 field[4]; };

struct Arr_8009F004 { s32 v[3]; };

struct Tbl_8009F004 { Arr_8009F004 a, b, c, d; };

f32 calc_boss4_scale__10TObjPlayerFi(s32);
u16 obj_getField1c(void *);
f32 newton_sqrtf(f32);
f32 get_random_float__21TObjEneMe3ShinowaRealFv(f32);
s32 copy_vec4__13TRaderMapCoreFPv(void *, void *);
bool is_vec_xz_cross_negative(u8 *arg0, u8 *arg1);
f32 get_status_value_f32__23TObjEneMe1CanadinLeaderFv(f32);
void *create_timed_particle_emitter(void *owner, s32 id, s32 b, s32 c);
void * __dt__26TObjEneDf2Bringer_Eff_RushFv(void *arg0, s16 arg1);
void TObjEneMe1CanadinLeader__vt110(Leader_8009AB4C *obj, s32 mode);
u8 TObjEneMe1CanadinLeader__vt107(void *arg0);
void TObjEneMe1CanadinLeader__vt111(void *arg0);
s32 TObjEneMe1CanadinLeader__vt114(Obj_8009B1CC *arg0);
void TObjEneMe1CanadinLeader__vt115(Leader_8009B274 *self, u32 id);
s32 TObjEneMe1CanadinLeader__vt106(Obj_8009B3C0 *self);
void TObjEneMe1CanadinLeader__vt105(Leader_8009B43C *self);
void TObjEneMe1CanadinLeader__vt103(Obj_8009B638 *self);
void TObjEneMe1CanadinLeader__vt104(void *arg0);
void run_task__23TObjEneMe1CanadinLeaderFv(u8 *arg0);
void * __dt__23TObjEneMe1CanadinLeaderFv(void *arg0, s16 arg1);
void * TObjEneMe1CanadinLeader__ct(void *, void *, void *);
void update_if_ready__17TObjEneMe1CanadinFv(void* p);
void TObjEneMe1Canadin__sub_8009BFF8(u8 *arg0, s32 arg1);
void TObjEneMe1Canadin__sub_8009C178(u8 *arg0, s32 arg1);
void TObjEneMe1Canadin__sub_8009C2EC(u8 *arg0, s32 arg1);
void TObjEneMe1Canadin__sub_8009C510(u8 *arg0, s32 arg1);
void TObjEneMe1Canadin__sub_8009CC74(void *arg0, s32 arg1);
void TObjEneMe1Canadin__sub_8009DE90(void *argv0, s32 arg1);
void dispatch_state__17TObjEneMe1CanadinFPvUii(Canadin_8009E0AC *self, u32 which, s32 arg);
void fn_8009E1D4(u8 *arg0, s32 arg1);
void TObjEneMe1CanadinLeader__sub_8009E258(u8 *arg0);
void TObjEneMe1CanadinLeader__sub_8009E27C(void* p);
void fn_8009E2DC(u8 *arg0);
s32 fn_8009E300(u8 *arg0);
u8 TObjEneMe1CanadinLeader__sub_8009E31C(u8 *arg0, s32 arg1);
void TObjEneMe1CanadinLeader__sub_8009E334(u8 *arg0);
void TObjEneMe1CanadinLeader__sub_8009E350(u8 *arg0);
int TObjEneMe1CanadinLeader__sub_8009E36C(void* p);
void fn_8009E378(void *arg0);
void TObjEneMe1CanadinLeader__sub_8009E4AC(u8 *arg0, s32 arg1);
struct Canadin_8009E504 {
    u8 pad0[0x4A4];
    f32 f4a4;
    u8 pad4a8[0x4B8 - 0x4A8];
    s32 state;
    s32 tblIdx;
    s32 timer;
    s32 pos;
};
int select_and_apply_target__17TObjEneMe1CanadinFPv(void* p);
s32 TObjEneMe1Canadin__sub_8009E76C(u8 *arg0);
s32 TObjEneMe1Canadin__sub_8009E860(Canadin_8009E860 *self, f32 *out, f32 _w2);
int vfunc_89__17TObjEneMe1CanadinFv(void* p);
void TObjEneMe1Canadin__sub_8009EB14(u8 *arg0, f32 height);
void TObjEneMe1Canadin__sub_8009EB98(u8 *arg0, f32 farg0);
void vfunc_101__17TObjEneMe1CanadinFPUc(void *arg0);
void calc_move_vector__17TObjEneMe1CanadinFiPv(s32 arg0, void *arg1);
void vfunc_88__17TObjEneMe1CanadinFv(void *arg0);
void vfunc_61__17TObjEneMe1CanadinFv(void);
void vfunc_62__17TObjEneMe1CanadinFv(void* p);
void vfunc_63__17TObjEneMe1CanadinFv(void *arg0);
void vfunc_28__17TObjEneMe1CanadinFv(void);
void * __dt__17TObjEneMe1CanadinFv(void *arg0, s16 arg1);
u8 * TObjEneMe1Canadin__ct(u8 *arg0, s32 arg1, u8 *arg2, s32 arg3, s16 arg4, s16 arg5);
void * __ct__26TObjEneMe1Canadin_EffLightFP7TObjectl(void *, void *, s32);
void TObjEneEpsilon__sub_800B92AC(u8 *arg0, s32 arg1, f32 farg0);
int select_and_apply_target__12TObjEneDD_STFf(void*);
s32 set_target_player__12TObjEneDD_STFPv(void *);
void *__dt__12TObjEneDD_STFv(void *arg0, s16 arg1);
void reset_hp__9TObjEneDDFv(void *, s32, s32, s32);
s32 get_camera_ctrl__9TObjEneDDFv(void *, int);
s32 update_camera_sequence__9TObjEneDDFv();
void initialize_enemy_state__9TObjEneDDFv(void *, s32);
void TObjEneDD__sub_800BA5A4(void *, void *, void *);
u32 is_player_entity_id(u16 arg0);
int vfunc_89__9TObjEneDDFv(void*);
void set_part_position__9TObjEneDDFPvPvi(void *, s32, s32);
void init_model__9TObjEneDDFv(void *, void *, s32);
u32 vfunc_101__9TObjEneDDFPUc();
s32 collect_enemy_target_candidates(void *, Entry_8009E860 *);
void clear_attack_receipts__9TObjEneDDFv();
void invoke_initialization_hook__9TObjEneDDFv(void *, void *);
s32 TObjEneMe3SinowZoa__sub_800D758C(void *);
void *__dt__13TUnk_80494938Fv(void *arg0, s16 arg1);
void TBoss3Volopt__sub_800D8D88(s32 arg0);
s32 trigger_dell_biter_events__10TObjPlayerFv(void *, f32);
s32 approach_angle_limited(s32, s32, s32);
void *find_entity_by_id(u16 id);
void free_collision_body_parts(void *);
void *get_player_by_client_id(s32 i);
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);
s32 __ct__7TObjectFP7TObject(void *, void *);
s32 rand();
f32 sin_table_lookup(int);
f32 cos_table_lookup(int);
void vec3_add_to(void *, void *);
s32 matrix_mult_vec(int, void *, int);
s32 rotate_vector_by_matrix(int, int, int);

extern const f32 TObjEneMe1Canadin__data_805D98AC;
extern s32 __vt__17TObjEneMe1Canadin[];
extern RecoveredGlobal_8009E4AC_lbl_8043A2A0 canadin_formation_fade_start_color;
extern RecoveredGlobal_8009E1D4_lbl_8043A32C canadin_behavior_params;
extern u8 canadin_projectile_param_block[];
extern s32 bringer_rush_effect_vtable[];
extern RecoveredGlobal_8009BD00_lbl_80500960 lbl_80500960;
extern s32 bringer_rush_effect_name;
extern void *TObjEneMe1Canadin__class_name;
extern void *lbl_805D4FD0;
extern void *lbl_805D4FDC;
extern s32 lbl_805D4FE0;
extern s32 *lbl_805D4FE4;
extern s32 *lbl_805D4FE8;
extern s32 *lbl_805D4FEC;
extern s32 *lbl_805D4FF0;
extern const f32 lbl_805D9860;
extern const f32 lbl_805D9880;
extern const f32 lbl_805D9884;
extern const f32 lbl_805D9890;
extern const f32 lbl_805D9894;
extern const f32 lbl_805D989C;
extern const f32 lbl_805D98A8;
extern const f32 lbl_805D98B0;
extern const f32 lbl_805D98B8;
extern const f32 lbl_805D98C8;
extern const f32 lbl_805D98D0;
extern const f32 lbl_805D98D4;
extern const f32 lbl_805D98F4;
extern const f32 lbl_805D98E8;
extern const f32 lbl_805D98EC;
extern const f32 lbl_805D98F0;
extern const f32 lbl_805D98F8;
extern const f32 lbl_805D98FC;
extern const f32 lbl_805D9900;
extern const f32 lbl_805D9904;
extern const f32 lbl_805D9908;
extern const f32 lbl_805D990C;
int is_target_android(void *p);
extern const f32 lbl_805D991C;
extern const f32 lbl_805D9918;
extern const f32 lbl_805D9920;
extern const f32 lbl_805D9924;
extern const f32 lbl_805D9928;
extern const f32 lbl_805D992C;
extern void *tl_04;

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
void vfunc_95__9TObjEneDDFv();
}
extern "C" {
void vfunc_96__9TObjEneDDFv();
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
void vfunc_102__9TObjEneDDFv();
}
extern "C" {
void vfunc_83__12TObjEneDD_STFv();
}
extern "C" {
void TObjEneMe1CanadinLeader__vt108(u8 *arg0, s32 arg1);
}
extern "C" {
void TObjEneMe1CanadinLeader__vt109(TObjEneMe1Canadin *self, s32 mode);
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
void vfunc_13__13TUnk_804AF8A0Fl();
}
extern "C" {
void vfunc_74__9TObjEnemyFl();
}
extern "C" {
void apply_hit_message_flags__9TObjEnemyFPv();
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
extern u8 lbl_8043A1B0[];
}
extern "C" {
extern u8 lbl_8043A1C0[];
}
extern "C" {
extern u8 lbl_8043A1CC[];
}
extern "C" {
extern u8 lbl_8043A1E4[];
}
extern "C" {
extern u8 lbl_8043A1FC[];
}
extern "C" {
extern u8 lbl_8043A214[];
}
extern "C" {
extern u8 lbl_8043A22C[];
}
extern "C" {
extern u8 lbl_8043A240[];
}
extern "C" {
extern u8 lbl_8043A254[];
}
extern "C" {
extern u8 lbl_8043A2B0[];
}
extern "C" {
extern u8 lbl_8043A2CC[];
}
extern "C" {
extern u8 lbl_8043A2D8[];
}
extern "C" {
extern u8 lbl_8043A2F8[];
}
extern "C" {
extern u8 lbl_8043A308[];
}
extern "C" {
void receive_direct_attack__13TUnk_804806E8FPv19DirectAttackPayloadPvll();
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
void update_movement_status__13TUnk_804806E8Fv();
}
extern "C" {
void update_object_view_visibility__13TUnk_804B9870Fff();
}
extern "C" {
void update_poison_status__13TUnk_804806E8Fv();
}
extern void *bm_ene_me1_mb_model_names[3];
extern void *bm_ene_me1_mb_motion_names[7];
void *canadin_setup_param_block[7] = {
    (void *)0x43610000, (void *)0x0, (void *)0x600, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_8048FECC[11] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x41000000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *bm_ene_me1_mb_model_names[3] = {
    (void *)&lbl_8043A1B0, (void *)&lbl_8043A1C0, (void *)0x0,
};
void *bm_ene_me1_mb_motion_names[7] = {
    (void *)&lbl_8043A1CC, (void *)&lbl_8043A1E4, (void *)&lbl_8043A1FC, (void *)&lbl_8043A214,
    (void *)&lbl_8043A22C, (void *)&lbl_8043A240, (void *)0x0,
};
void *bm_ene_me1_mb_resource_descriptor[4] = {
    (void *)&lbl_8043A254, (void *)&bm_ene_me1_mb_model_names, (void *)&bm_ene_me1_mb_motion_names, (void *)0x20006,
};
void *lbl_8048FF30[28] = {
    (void *)0x10000, (void *)0x4, (void *)0x3e4ccccd, (void *)0x0,
    (void *)0x10000, (void *)0x5, (void *)0x3e4ccccd, (void *)0x0,
    (void *)0x20001, (void *)0x1, (void *)0x3f000000, (void *)0x0,
    (void *)0x20000, (void *)0x0, (void *)0x3f000000, (void *)0x0,
    (void *)0x20000, (void *)0x2, (void *)0x3f333333, (void *)0x0,
    (void *)0x20001, (void *)0x3, (void *)0x3f19999a, (void *)0x0,
    (void *)0x30000, (void *)0x1, (void *)0x3f000000, (void *)0x0,
};
void *canadin_leader_fade_sequence_table[5] = {
    (void *)&lbl_8043A2B0, (void *)&lbl_8043A2CC, (void *)&lbl_8043A2D8, (void *)&lbl_8043A2F8,
    (void *)&lbl_8043A308,
};
void *__vt__23TObjEneMe1CanadinLeader[118] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__23TObjEneMe1CanadinLeaderFv, (void *)&run_task__23TObjEneMe1CanadinLeaderFv,
    (void *)&render__17TObjEneMe1CanadinFv, (void *)&render_shadows__9TObjEnemyFv, (void *)&vfunc_6__13TUnk_804B9870FPsl, (void *)&apply_object_set_data__13TUnk_804B9870FPv,
    (void *)&reset_motion_fields__13TUnk_804806E8Fv, (void *)&vfunc_9__13TUnk_804806E8Fv, (void *)&update_object_view_visibility__13TUnk_804B9870Fff, (void *)&classify_actor_view_detail__13TUnk_804B9870Ffff,
    (void *)&get_name__9TObjEnemyFv, (void *)&vfunc_13__13TUnk_804AF8A0Fl, (void *)&add_actor_exp__13TUnk_804806E8Fl, (void *)&consume_timer_field__13TUnk_804806E8Fl,
    (void *)&get_actor_level_index__13TUnk_804806E8Fv, (void *)&update_actor_ground_y__13TUnk_804806E8Fv, (void *)&vfunc_18__13TUnk_804806E8FPUc, (void *)&is_actor_cadence_frame__13TUnk_804806E8Fl,
    (void *)&select_melee_contact_body__13TUnk_804806E8FPvf, (void *)&calc_distance_accuracy_penalty__13TUnk_804806E8FPvPvPvf, (void *)&receive_physical_attack__13TUnk_804806E8FPvf, (void *)&receive_direct_attack__13TUnk_804806E8FPv19DirectAttackPayloadPvll,
    (void *)&receive_weapon_special_attack__13TUnk_804806E8FPvPv, (void *)&apply_knockback_from_attacker__13TUnk_804806E8FPUc, (void *)&try_start_action__13TUnk_804806E8Fll, (void *)&roll_physical_accuracy__13TUnk_804806E8FPvlf,
    (void *)&vfunc_28__17TObjEneMe1CanadinFv, (void *)&vfunc_29__13TUnk_804806E8Fv, (void *)&is_target_in_attack_range__13TUnk_804806E8Fv, (void *)&test_flag_256__13TUnk_804806E8Fv,
    (void *)&test_flag30_512__13TUnk_804806E8Fv, (void *)&has_flag_0x800__13TUnk_804806E8Fv, (void *)&test_flag_1000__13TUnk_804806E8Fv, (void *)&update_poison_status__13TUnk_804806E8Fv,
    (void *)&update_action_hold_status__13TUnk_804806E8Fv, (void *)&vfunc_37__13TUnk_804806E8Fv, (void *)&update_flag30_timer__13TUnk_804806E8Fv, (void *)&update_movement_status__13TUnk_804806E8Fv,
    (void *)&update_shock_clock__13TUnk_804806E8Fv, (void *)&update_attack_stat_status__13TUnk_804806E8Fv, (void *)&update_defense_stat_status__13TUnk_804806E8Fv, (void *)&vfunc_43__13TUnk_804806E8Fv,
    (void *)&apply_poison_status__13TUnk_804806E8Fv, (void *)&apply_paralysis__13TUnk_804806E8Fv, (void *)&apply_slow_status__13TUnk_804806E8Fv, (void *)&apply_confusion_status__13TUnk_804806E8Fv,
    (void *)&apply_movement_ailment__13TUnk_804806E8Fl, (void *)&apply_shock_status__13TUnk_804806E8Fv, (void *)&clear_harmful_statuses__13TUnk_804806E8Fv, (void *)&apply_attack_stat_status__13TUnk_804806E8FPv,
    (void *)&apply_defense_stat_status__13TUnk_804806E8FPv, (void *)&cure_poison_ailment__13TUnk_804806E8Fv, (void *)&cure_paralysis__13TUnk_804806E8Fv, (void *)&clear_all_status_effects__13TUnk_804806E8Fv,
    (void *)&apply_action_hold_status__13TUnk_804806E8Ff, (void *)&apply_anti_technique__13TUnk_804806E8Fl, (void *)&vfunc_58__13TUnk_804806E8Fv, (void *)&vfunc_59__13TUnk_804806E8Fv,
    (void *)&vfunc_60__13TUnk_804806E8Fv, (void *)&vfunc_61__17TObjEneMe1CanadinFv, (void *)&vfunc_62__17TObjEneMe1CanadinFv, (void *)&vfunc_63__17TObjEneMe1CanadinFv,
    (void *)&reset_pose__13TUnk_804806E8Fv, (void *)&get_anim_node_position__13TUnk_804806E8FlP3Vec, (void *)&vfunc_66__13TUnk_804806E8Fv, (void *)&vfunc_67__13TUnk_804806E8Ff,
    (void *)&get_pos__13TUnk_804806E8Fl, (void *)&apply_switch_attack__13TUnk_804806E8Fv, (void *)&enemy_spawn_jellen_effect__13TUnk_804806E8Fv, (void *)&trigger_switch_attack__13TUnk_804806E8Fv,
    (void *)&enemy_spawn_zalure_effect__13TUnk_804806E8Fv, (void *)&vfunc_73__13TUnk_804806E8Fv, (void *)&vfunc_74__9TObjEnemyFl, (void *)&vfunc_75__13TUnk_804806E8Ff,
    (void *)&vfunc_76__13TUnk_804806E8Fv, (void *)&vfunc_77__13TUnk_804806E8Fv, (void *)&vfunc_78__13TUnk_804806E8Fl, (void *)&vfunc_79__9TObjEneDDFv,
    (void *)&apply_hit_message_flags__9TObjEnemyFPv, (void *)&apply_set_data__9TObjEnemyFPv, (void *)&clear_lobby_object_state__9TObjEnemyFv, (void *)&vfunc_83__12TObjEneDD_STFv,
    (void *)&TObjEneDD__vt82, (void *)&vfunc_85__9TObjEneDDFv, (void *)&vfunc_86__9TObjEneDDFv, (void *)&dispatch_state__17TObjEneMe1CanadinFPvUii,
    (void *)&vfunc_88__17TObjEneMe1CanadinFv, (void *)&vfunc_89__17TObjEneMe1CanadinFv, (void *)&vfunc_90__9TObjEneDDFv, (void *)&vfunc_91__9TObjEneDDFv,
    (void *)&vfunc_92__9TObjEneDDFv, (void *)&vfunc_93__9TObjEneDDFv, (void *)&vfunc_94__9TObjEneDDFv, (void *)&vfunc_95__9TObjEneDDFv,
    (void *)&vfunc_96__9TObjEneDDFv, (void *)&vfunc_97__9TObjEneDDFv, (void *)&vfunc_98__9TObjEneDDFv, (void *)&vfunc_99__9TObjEneDDFv,
    (void *)&vfunc_100__9TObjEneDDFv, (void *)&vfunc_101__17TObjEneMe1CanadinFPUc, (void *)&vfunc_102__9TObjEneDDFv, (void *)&vfunc_103__9TObjEneDDFPUc,
    (void *)&select_and_apply_target__17TObjEneMe1CanadinFPv, (void *)&TObjEneMe1CanadinLeader__vt103, (void *)&TObjEneMe1CanadinLeader__vt104, (void *)&TObjEneMe1CanadinLeader__vt105,
    (void *)&TObjEneMe1CanadinLeader__vt106, (void *)&TObjEneMe1CanadinLeader__vt107, (void *)&TObjEneMe1CanadinLeader__vt108, (void *)&TObjEneMe1CanadinLeader__vt109,
    (void *)&TObjEneMe1CanadinLeader__vt110, (void *)&TObjEneMe1CanadinLeader__vt111, (void *)&update_if_ready__17TObjEneMe1CanadinFv, (void *)&render_canadin_model_with_debug_type__17TObjEneMe1CanadinFv,
    (void *)&TObjEneMe1CanadinLeader__vt114, (void *)&TObjEneMe1CanadinLeader__vt115,
};
#define canadin_setup_param_block ((u8 *)canadin_setup_param_block)
#define lbl_8048FECC ((u8 *)lbl_8048FECC)
#define lbl_8048FF30 ((u8 *)lbl_8048FF30)
#define __vt__23TObjEneMe1CanadinLeader ((s32 *)__vt__23TObjEneMe1CanadinLeader)

u32 lbl_80500930[3];
u32 lbl_8050093C[3];
u32 lbl_80500948[3];
u32 lbl_80500954[3];
#define lbl_80500930 ((s32 *)lbl_80500930)
#define lbl_8050093C ((s32 *)lbl_8050093C)
#define lbl_80500948 ((s32 *)lbl_80500948)
#define lbl_80500954 ((s32 *)lbl_80500954)

void *__dt__26TObjEneDf2Bringer_Eff_RushFv(void *arg0, s16 arg1);
void TObjEneMe1CanadinLeader__vt110(Leader_8009AB4C *obj, s32 mode) {
    s32 i;
    Fields_8009AB4C *self;
    self = (Fields_8009AB4C *)obj;
    switch (mode) {
    case 4:
        TBoss3Volopt::create_breakup_mdl((s32)lbl_805D4FDC, 0, (s32)self->field24, (s32)self->pos2FC, (s32)self->angle);
        for (i = 0; i < self->count; i++) {
            ((TObjEneMe1CanadinLeader *)(self->members[i]))->set_flag3c8_bit20();
        }
        self->flags3C8 |= 0x400000;
        play_sound_effect(0x4003B71D, self->pos2FC, 0, 0);
        ((TObjPlayer *)self)->refresh_lobby_state();
        break;
    case 0:
        if (obj->m107() != 0) {
            ((TObjEnemy *)self)->send_entity_set_flags();
            queue_destruction__7TObjectFv(self);
        }
        break;
    case 5:
        self->flags30 &= ~0x200;
        break;
    case 1:
        return;
    case 3:
        return;
    }
}

void TObjEneMe1CanadinLeader__vt109(TObjEneMe1Canadin *self, s32 mode) {
    switch (mode) {
    case 4:
        advance_state_5_to_4__17TObjEneMe1CanadinFPv(self);
        self->set_field_378(4);
        self->vfunc_96();
        break;
    case 3:
        if (((Obj_8009AD18 *)self)->flags3C8 & 4) {
            self->vfunc_105();
        }
        break;
    case 0:
        advance_animation_playback();
        self->update_linked_position(TObjEneMe1Canadin__data_805D988C);
        TObjEneMe1Canadin::update_move(self);
        self->update_hover_height();
        self->vfunc_89();
        break;
    case 5:
        break;
    }
}

#define self ((Obj_8009AD18 *)arg0)
void TObjEneMe1CanadinLeader__vt108(u8 *arg0, s32 arg1) {
    s32 k;
    s32 i;
    s32 j;

    switch (arg1) {
    case 4: {
        advance_state_5_to_4__17TObjEneMe1CanadinFPv(arg0);
        ((TObjEneDD *)arg0)->set_field_378(3);
        ((VObj_8009AD18 *)arg0)->m94();
        const f32 *p = (const f32 *)canadin_formation_reset_vec4;
        self->f4A8 = p[1];
        self->f4AC = p[2];
        self->f4B0 = p[3];
        self->sub = 0;
        for (k = 2, i = 0; i < self->count; k += 2, i++) {
            ((TObjEneMe1CanadinLeader *)(self->members[i]))->set_leader_index(self->f390, k);
        }
        break;
    }
    case 3:
        if (self->flags3C8 & 2) {
            self->flags3C8 &= ~2;
            self->f4F4 = 1;
            transition_enemy_state__9TObjEneDDFs(arg0, 4);
        }
        break;
    case 0:
        ((void (*)(void *))advance_animation_playback)(arg0);
        ((TObjEneDD_ST *)arg0)->update_linked_position(TObjEneMe1Canadin__data_805D988C);
        switch (self->sub) {
        case 0:
            self->timer--;
            if (self->timer <= 0) {
                self->f4B8 = 2;
                self->sub = 1;
                play_sound_effect(0x4003B21A, arg0 + 0x2FC, 0, 0);
            }
            break;
        case 1:
            if (self->f4B8 == 0) {
                self->flags3C8 |= 0x8000;
                for (j = 0; j < self->count; j++) {
                    if (TObjEneMe1CanadinLeader__sub_8009E36C(self->members[j]) == 0) {
                        break;
                    }
                }
                if (j == self->count) {
                    ((TObjEneMe1CanadinLeader *)arg0)->set_attack_flag();
                    s32 m;
                    for (m = 0; m < self->count; m++) {
                        ((TObjEneMe1CanadinLeader *)(self->members[m]))->set_attack_flag();
                    }
                }
            }
            TObjEneMe1Canadin::update_move(arg0);
            break;
        }
        TObjEneMe1Canadin__sub_8009EB14(arg0, lbl_805D9890 + self->f3C);
        ((VObj_8009AD18 *)arg0)->m87();
        break;
    case 5:
        ((VObj_8009AD18 *)arg0)->m90();
        break;
    }
}
#undef self

#define self ((Obj_8009AF54 *)arg0)
void TObjEneMe1CanadinLeader::update_formation_state(void *arg0) {
    s32 i;
    s32 j;
    if (self->flags3C8 & 0x10) {
        self->flags3C8 &= ~0x10;
        self->state = 7;
    }
    switch (self->state) {
    case 1:
        ((s32 (*)(void *, s32))TObjEneMe1CanadinLeader__sub_8009E4AC)(arg0, 0);
        self->state = 2;
        play_sound_effect(0x4003AD1B, self->pos, 0, 0);
        break;
    case 2:
        if (self->f4B8 == 0) {
            self->state = 3;
            self->flags3C8 &= ~8;
            copy_vec4__13TRaderMapCoreFPv(self->v4A4, ((s32 *)canadin_formation_reset_vec4));
            for (i = 0; i < self->count; i++) {
                if (((s32 (*)(void *, s32))TObjEneMe1CanadinLeader__sub_8009E31C)(self->members[i], 0x200) != 0) {
                    ((s32 (*)(void *))TObjEneMe1CanadinLeader__sub_8009E27C)(self->members[i]);
                }
            }
        }
        break;
    case 3:
        if (self->flags3C8 & 8) {
            self->state = 4;
        }
        break;
    case 4:
        ((s32 (*)(void *, s32))TObjEneMe1CanadinLeader__sub_8009E4AC)(arg0, 2);
        self->state = 5;
        play_sound_effect(0x4003AD1C, self->pos, 0, 0);
        break;
    case 5:
        if (self->f4B8 == 0) {
            copy_vec4__13TRaderMapCoreFPv(self->v4A4, ((s32 *)canadin_formation_reset_vec4));
            self->state = 6;
            for (i = 0; i < self->count; i++) {
                if (((s32 (*)(void *, s32))TObjEneMe1CanadinLeader__sub_8009E31C)(self->members[i], 0x100) != 0) {
                    ((s32 (*)(void *))TObjEneMe1CanadinLeader__sub_8009E27C)(self->members[i]);
                }
            }
        }
        break;
    case 6:
        break;
    case 7:
        ((s32 (*)(void *, s32))TObjEneMe1CanadinLeader__sub_8009E4AC)(arg0, 4);
        self->state = 8;
        play_sound_effect(0x4003AD1B, self->pos, 0, 0);
        break;
    case 8:
        if (self->f4B8 == 0) {
            self->state = 9;
            copy_vec4__13TRaderMapCoreFPv(self->v4A4, ((s32 *)canadin_formation_reset_vec4));
            for (j = 0; j < self->count; j++) {
                ((s32 (*)(void *))TObjEneMe1CanadinLeader__sub_8009E258)(self->members[j]);
            }
            ((s32 (*)(void *))TObjEneMe1CanadinLeader__sub_8009E258)(arg0);
        }
        break;
    case 0:
    case 9:
        break;
    }
}

#undef self
u8 TObjEneMe1CanadinLeader__vt107(void *arg0) {
    return (u8) (*(s32 *)((s8 *)arg0 + 0x4D0) <= 0);
}

void TObjEneMe1CanadinLeader__vt111(void *arg0) {
    *lbl_805D4FE4 = *(s32 *)((s8 *)arg0 + 0x4B4);
    *lbl_805D4FE8 = *(s32 *)((s8 *)arg0 + 0x4B4);
}

s32 TObjEneMe1CanadinLeader__vt114(Obj_8009B1CC *arg0) {
    s32 n = 0;
    s32 i;
    for (i = 0; i < arg0->count; i++) {
        if ((void *)fn_8009E300(arg0->items[i]) == arg0->key) {
            n++;
        }
    }
    if (TObjEneDD::check_v2_mode() != 0) {
        return n < 4;
    }
    return n < 2;
}

void TObjEneMe1CanadinLeader__vt115(Leader_8009B274 *self, u32 id) {
    s32 i;
    for (i = 0; i < self->count; i++) {
        if (self->ids[i] == id) {
            self->count--;
            u32 t = self->ids[self->count];
            self->ids[self->count] = id;
            self->ids[i] = t;
            break;
        }
    }
    if (self->mode == 3) {
        s32 k = get_status_value_f32__23TObjEneMe1CanadinLeaderFv((f32)self->max / (f32)self->info->f2C);
        if (self->count <= self->max - k) {
            self->f3C0 = (s32)find_entity_by_id(self->f4C8);
            ((TObjEneMe1CanadinLeader *)(self->f3C0))->set_flag3c8_bit8();
        }
    }
    if (!(self->flags & 0x100000) && self->count <= self->max / 2) {
        self->flags |= 0x10;
    }
    if (self->count <= 2) {
        self->flags |= 0x40;
    }
}

s32 TObjEneMe1CanadinLeader__vt106(Obj_8009B3C0 *self) {
    s32 i;
    if (self->flags & 0x40) {
        self->flags &= ~0x40;
        ((s32 (*)(void *, s16))transition_enemy_state__9TObjEneDDFs)(self, 0xb);
        for (i = 0; i < self->count; i++) {
            ((TObjEneMe1CanadinLeader *)(self->members[i]))->set_flag3c8_bit40();
        }
        return 1;
    }
    return 0;
}

void TObjEneMe1CanadinLeader__vt105(Leader_8009B43C *self) {
    s32 id;
    s32 sub;
    s32 angle;
    s32 n;
    s32 i;
    s32 j;
    Vec_8009B43C v;
    n = (s32)get_status_value_f32__23TObjEneMe1CanadinLeaderFv((f32)self->max / (f32)self->info->f2C);
    if (n < 1) {
        n = 1;
    }
    angle = self->angle;
    id = (self->f1C + 1) & 0xFFFF;
    sub = self->f2C + 1;
    for (i = 0; i < n; i++) {
        v.x = lbl_805D9894 * sin_table_lookup(angle);
        v.y = lbl_805D9898;
        v.z = lbl_805D9894 * cos_table_lookup(angle);
        vec3_add_to(&v, &self->pos);
        angle += 0x10000 / self->max;
        self->ids[i] = TObjEneMe1CanadinLeader::create_canadin(self, &v, (void *)id++, (void *)sub++);
        ((s32 (*)(void *))TObjEneMe1CanadinLeader__sub_8009E334)(self->ids[i]);
        self->count++;
    }
    for (j = n; j < self->max; j++) {
        v.x = lbl_805D9894 * sin_table_lookup(angle);
        v.y = lbl_805D9898;
        v.z = lbl_805D9894 * cos_table_lookup(angle);
        vec3_add_to(&v, &self->pos);
        angle += 0x10000 / self->max;
        self->ids[j] = TObjEneMe1CanadinLeader::create_canadin(self, &v, (void *)id++, (void *)sub++);
        ((s32 (*)(void *))TObjEneMe1CanadinLeader__sub_8009E350)(self->ids[j]);
        self->count++;
    }
}

void TObjEneMe1CanadinLeader__vt103(Obj_8009B638 *self) {
    switch (self->step) {
    case 0:
    case 1:
        self->step++;
        ((s32 (*)(void *, s16))transition_enemy_state__9TObjEneDDFs)(self, 6);
        break;
    case 2:
        self->step = 0;
        ((s32 (*)(void *, s16))transition_enemy_state__9TObjEneDDFs)(self, 7);
        break;
    }
}

void TObjEneMe1CanadinLeader__vt104(void *arg0) {
    *(s32 *)((s8 *)arg0 + 0x34) = (s32) *(s32 *)((s8 *)(*(void **)((s8 *)lbl_805D4FD0 + 0x42C)) + 0x18);
    *(s32 *)((s8 *)arg0 + 0x24) = (s32) *(s32 *)((s8 *)(*(void **)((s8 *)lbl_805D4FD0 + 0x42C)) + 0x1C);
}

void run_task__23TObjEneMe1CanadinLeaderFv(u8 *pv) {
    if (TObjPlayer::check_demo_mode() != 0) {
        ((VObj_18 *)(pv))->m112();
        return;
    }
    if (((VObj_18 *)(pv))->m81() != 4) {
        ((VObj_18 *)(pv))->m83();
        TObjEneMe1CanadinLeader::update_fade_sequence(pv);
        TObjEneMe1CanadinLeader::update_formation_state(pv);
    }
    ((TObjEneMe1Canadin *)pv)->copy_pos();
    ((TBoss8Dragon *)pv)->set_player_state_default();
    ((VObj_18 *)(pv))->m98();
}

void *__dt__23TObjEneMe1CanadinLeaderFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__23TObjEneMe1CanadinLeader;
        ((void (*)(void *, int))__dt__17TObjEneMe1CanadinFv)(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

struct VBase_18_1e038c { char pad[0x18]; };
struct VObj_18_1e038c : VBase_18_1e038c {
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
    virtual void m101();
    virtual void m102();
    virtual void m103();
    virtual void m104();
};

extern s32 TObjEneMe1CanadinLeader__class_name;

struct List_8009B7C0 { u8 pad[0x4CC]; s32 cap; s32 n; s32 items[8]; };

void *TObjEneMe1CanadinLeader__ct(void *arg0, void *a, void *b) {
    s32 i;
    List_8009B7C0 *l;

    ((TObjEneMe1Canadin *)arg0)->init(a, b, (void *)2);
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__23TObjEneMe1CanadinLeader;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TObjEneMe1CanadinLeader__class_name;
    ((VObj_18_1e038c *)(arg0))->m104();
    *(f32 *)((s8 *)arg0 + 0x3E8) += lbl_805D989C;
    l = (List_8009B7C0 *)arg0;
    l->cap = 8;
    l->n = 0;
    for (i = 0; i < 8; i++) {
        l->items[i] = 0;
    }
    *(s32 *)((s8 *)arg0 + 0x4F4) = 0;
    initialize_enemy_state__9TObjEneDDFv(arg0, 0x1D);
    return arg0;
}

void *TObjEneMe1CanadinLeader::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x4F8);
    if (o != NULL) {
        o = TObjEneMe1CanadinLeader__ct(o, tl_04, arg0);
    }
    return o;
}

void TObjEneMe1Canadin::render_canadin_model_with_debug_type() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r3;
    if ((((s32)((TObjEneDD *)arg0)->get_target_info()) != 0) && ((s32) *(s32 *)((s8 *)arg0 + 0x3C4) == 0)) {
        temp_r3 = *(s32 *)((s8 *)arg0 + 0x3C8);
        if (temp_r3 & 0x100) {
            TObjEneMe1Gee::queue_debug_text((s32)(pack_debug_text_position(0, 0)), (char *)lbl_8043A398);
        } else if (temp_r3 & 0x200) {
            TObjEneMe1Gee::queue_debug_text((s32)(pack_debug_text_position(0, 0)), (char *)lbl_8043A3A8);
        } else {
            TObjEneMe1Gee::queue_debug_text((s32)(pack_debug_text_position(0, 0)), (char *)lbl_8043A3BC);
        }
    }
    if (((VObj_18_26a62c *)(arg0))->m8(lbl_805D98A0, lbl_805D98A4) != 0) {
        update_player_state__9TObjEneDDFv(arg0, 0, 0);
        TObjPlayer::toggle_particle_effect();
        TObjFish::set_global_param((int) (*(s32 *)((s8 *)arg0 + 0x24)));
        push_matrix();
        post_translate_matrix(arg0 + 0x38);
        rotate_matrix_y(0, (int) (*(s32 *)((s8 *)arg0 + 0x60)));
        TObjEneDD::clear_global_flag_400();
        draw_chunk_object((void *)(*(s32 *)((s8 *)arg0 + 0x34)));
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}

void TObjEneMe1Canadin::update_if_ready() { if (get_target_info() != 0) { this->update_by_field_0x354(); } }

void TObjEneMe1Canadin::render() {
    u8 *arg0 = (u8 *)this;
    s16 temp_r0;
    s16 temp_r0_2;
    s32 var_r30;
    s32 var_r29;
    if (TObjPlayer::check_demo_mode() != 0) {
        ((VObj_18_8dc821 *)(arg0))->m113();
        return;
    }
    if (*(s32 *)((s8 *)arg0 + 0x3C8) & 0x400000) {
        var_r30 = 0;
    } else if (is_main_phase_15__9TObjEneDDFv() != 0) {
        var_r30 = ((VObj_18_8dc821 *)(arg0))->m9(lbl_805D9E88, lbl_805D9E84, lbl_805D98A4);
    } else if (((VObj_18_8dc821 *)(arg0))->m8(lbl_805D98A0, lbl_805D98A4) != 0) {
        var_r30 = 1;
    } else {
        var_r30 = 0;
    }
    if (var_r30 != 0) {
        if (*(s32 *)((s8 *)arg0 + 0x3C8) & 0x01000000) {
            update_player_state__9TObjEneDDFv(arg0, 0, 0);
        }
        ((TObjEneDD *)arg0)->update_secondary_light();
        TObjFish::set_global_param((int) (*(s32 *)((s8 *)arg0 + 0x24)));
        saved_model_render_flags = model_render_flags;
        TObjEneDD::clear_global_flag_400();
        TObjPlayer::toggle_particle_effect();
        ((VObj_18_8dc821 *)(arg0))->m111();
        push_matrix();
        post_translate_matrix(arg0 + 0x38);
        translate_matrix(0, lbl_805D9898, (f32) (*(f32 *)((s8 *)arg0 + 0x3F4)), lbl_805D9898);
        rotate_matrix_y(0, (int) (*(s32 *)((s8 *)arg0 + 0x60)));
        temp_r0 = *(s16 *)((s8 *)arg0 + 0x326);
        var_r29 = 1;
        if ((temp_r0 == 1) || (temp_r0 == 0xB)) {
            ((VObj_14_aa9368 *)(arg0 + (972)))->m6();
            if (defer_render__7TObjectFv(arg0) != 0) {
                var_r29 = 0;
            }
        }
        if (var_r29 != 0) {
            if ((s16) *(s16 *)((s8 *)arg0 + 0x326) != 0xA) {
                lbl_805D4FD4 = 0;
                TObjEneMe1Canadin__render_point_cursor = (s32)(arg0 + 0x414);
                VecCopy((Vec *)(arg0 + 0x438), (const Vec *)(lbl_8043A268));
                VecCopy((Vec *)(arg0 + 0x420), (const Vec *)(lbl_8043A274));
                TObjEneRe7Berura::set_global_state((s32)&fn_8009BD00);
                if (var_r30 == 1) {
                    ((TObjMotion *)arg0)->draw();
                } else {
                    ((TObjEnemy *)arg0)->render_world_model();
                }
                TObjEneRe7Berura::set_global_state(NULL);
            } else {
                rotate_matrix_z(0, (int) (*(s32 *)((s8 *)arg0 + 0x64)));
                lbl_805D4FD4 = -1;
                TObjEneMe1Canadin__render_point_cursor = (s32)(arg0 + 0x414);
                VecCopy((Vec *)(arg0 + 0x438), (const Vec *)(lbl_8043A268));
                VecCopy((Vec *)(arg0 + 0x420), (const Vec *)(lbl_8043A274));
                TObjEneRe7Berura::set_global_state((s32)&fn_8009BD00);
                ((TObjEneDD_ST *)arg0)->draw_with_alt_model((int) (*(s32 *)((s8 *)arg0 + 0x410)));
                TObjEneRe7Berura::set_global_state(NULL);
            }
        }
        temp_r0_2 = *(s16 *)((s8 *)arg0 + 0x326);
        if ((temp_r0_2 == 1) || (temp_r0_2 == 0xB)) {
            ((VObj_14_aa9368 *)(arg0 + (972)))->m7();
        }
        pop_matrix();
        TParticleCtrl::end_effect_render();
        model_render_flags = saved_model_render_flags;
        ((TObjEneDD *)arg0)->update_primary_light();
        return;
    }
    VecCopy((Vec *)(arg0 + 0x438), (const Vec *)(lbl_8043A268));
    VecCopy((Vec *)(arg0 + 0x420), (const Vec *)(lbl_8043A274));
    VecCopy((Vec *)(arg0 + 0x42C), (const Vec *)(arg0 + 0x2FC));
    VecCopy((Vec *)(arg0 + 0x414), (const Vec *)(arg0 + 0x2FC));
    VecCopy((Vec *)(arg0 + 0x444), (const Vec *)(arg0 + 0x2FC));
    VecCopy((Vec *)(arg0 + 0x450), (const Vec *)(arg0 + 0x2FC));
    VecCopy((Vec *)(arg0 + 0x45C), (const Vec *)(arg0 + 0x2FC));
}

void fn_8009BD00(void) {
    s32 temp_r4;
    s32 pos;
    s32 temp_r5;
    s32 temp_r5_2;
    switch (lbl_805D4FD4) {
    case 2:
    case 3:
        push_matrix();
        update_camera_sequence__9TObjEneDDFv();
        temp_r5 = TObjEneMe1Canadin__render_point_cursor;
        TObjEneMe1Canadin__render_point_cursor = temp_r5 + 0xC;
        matrix_mult_vec(0, &lbl_80500960.value, temp_r5);
        temp_r4 = TObjEneMe1Canadin__render_point_cursor;
        temp_r5_2 = temp_r4;
        TObjEneMe1Canadin__render_point_cursor = temp_r4 + 0xC;
        rotate_vector_by_matrix(0, temp_r4, temp_r5_2);
        pop_matrix();
        break;
    case 6:
    case 11:
    case 14:
        pos = TObjEneMe1Canadin__render_point_cursor;
        TObjEneMe1Canadin__render_point_cursor = pos + 0xC;
        get_camera_ctrl__9TObjEneDDFv(&lbl_80500960.value, pos);
        break;
    }
    lbl_805D4FD4 += 1;
}

void TObjEneMe1Canadin::update_by_state(s32 arg1) {
    f32 temp_f1;

    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)this + 0xB8) = 0;
        temp_f1 = *(f32 *)((s8 *)this + 0x3C);
        *(f32 *)((s8 *)this + 0x3F8) = (f32) (temp_f1 + *(f32 *)((s8 *)this + 0x3EC));
        *(f32 *)((s8 *)this + 0x484) = ((f32 (*)(s32, f32))sin_table_lookup)(*(s32 *)((s8 *)this + 0x60), temp_f1);
        *(f32 *)((s8 *)this + 0x488) = ((f32 (*)(s32))cos_table_lookup)(*(s32 *)((s8 *)this + 0x60));
        return;
    case 0:
        advance_animation_playback();
        *(f32 *)((s8 *)this + 0x3F8) = (f32) (*(f32 *)((s8 *)this + 0x3C) + *(f32 *)((s8 *)this + 0x3EC));
        *(f32 *)((s8 *)this + 0x300) = (f32) *(f32 *)((s8 *)this + 0x3F8);
        move_with_wall_slide_commit(*(f32 *)((s8 *)this + 0x484), *(f32 *)((s8 *)this + 0x488), lbl_805D98A8);
    case 3:
    case 5:
    case 1:
        return;
    }
}

void TObjEneMe1Canadin::update_walk_animation(s32 arg1) {
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)this + 0xB8) = 0;
        *(s32 *)((s8 *)this + 0x470) = 0;
        return;
    case 0:
        advance_animation_playback();
        *(s32 *)((s8 *)this + 0x470) = (s32) (*(s32 *)((s8 *)this + 0x470) + 1);
        if ((s32) *(s32 *)((s8 *)this + 0x470) > 0x5A) {
            *(s32 *)((s8 *)this + 0x470) = 0;
            *(s16 *)((s8 *)this + 0xB8) = (s16) (*(s16 *)((s8 *)this + 0xB8) + 1);
            if ((s16) *(s16 *)((s8 *)this + 0xB8) >= 7) {
                *(s16 *)((s8 *)this + 0xB8) = 0;
            }
        }
    case 3:
    case 5:
    case 1:
        return;
    }
}

void TObjEneMe1Canadin::vfunc_112(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    Stack_8009BF0C stack;
    f32 temp_f1;
    switch (arg1) {
    case 4:
        if ((s32) *(s32 *)((s8 *)arg0 + 0x3C4) == 1) {
            *(u8 **)((s8 *)arg0 + 0x3C0) = (u8 *)find_entity_by_id(*(u16 *)((s8 *)arg0 + 0x4C8));
            ((VObj_18_0f49f2 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x3C0))))->m115(arg0);
        }
        TBoss3Volopt::create_breakup_mdl(lbl_805D4FE0, 0, (s32)((int) (*(s32 *)((s8 *)arg0 + 0x24))), (s32)(arg0 + 0x2FC), (s32)((int) (*(s32 *)((s8 *)arg0 + 0x60))));
        *(s32 *)((s8 *)arg0 + 0x3C8) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C8) | 0x400000);
        VecCopy((Vec *)(&stack.sp8), (const Vec *)(arg0 + 0x2FC));
        temp_f1 = stack.spC;
        stack.spC = temp_f1 - TObjEneMe1Canadin__data_805D98AC;
        trigger_dell_biter_events__10TObjPlayerFv(&stack.sp8, temp_f1);
        ((TBoss8Dragon *)arg0)->refresh_and_send_entity_flags();
        ((s32 (*)(int, void *, int, int))play_sound_effect)(0x4003AA1E, arg0 + 0x2FC, 0, 0);
        return;
    case 0:
        ((s32 (*)(void))queue_destruction__7TObjectFv)();
    case 3:
    case 5:
        return;
    }
}

void TObjEneMe1Canadin__sub_8009BFF8(u8 *arg0, s32 arg1) {

    switch (arg1) {
    case 4:
        ((TObjEneDD *)arg0)->set_field_378(0xE);
        *(s32 *)((s8 *)arg0 + 0x3C8) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C8) & 0xFFBFFFFF);
        ((VObj *)arg0)->m94();
        *(s32 *)((s8 *)arg0 + 0x470) = 0;
        return;
    case 3:
        if ((s32) *(s32 *)((s8 *)arg0 + 0x470) == 2) {
            ((VObj *)arg0)->m103();
        }
    case 5:
        return;
    case 0:
        advance_animation_playback();
        if (((TObjEneDD_ST *)arg0)->update_linked_position(TObjEneMe1Canadin__data_805D988C) != 0) {
            *(s32 *)((s8 *)arg0 + 0x470) = 2;
        }
        switch (*(s32 *)((s8 *)arg0 + 0x470)) {
        case 0:
            *(s32 *)((s8 *)arg0 + 0x474) = (s32) (*(s32 *)((s8 *)arg0 + 0x474) + 1);
            if ((s32) *(s32 *)((s8 *)arg0 + 0x474) >= 0x3C) {
                *(s32 *)((s8 *)arg0 + 0x470) = 1;
                ((s32 (*)(void *))advance_state_5_to_4__17TObjEneMe1CanadinFPv)(arg0);
            }
            ((s32 (*)(void *, f32))TObjEneMe1Canadin__sub_8009EB14)(arg0, *(f32 *)((s8 *)arg0 + 0x3C) + *(f32 *)((s8 *)arg0 + 0x3F4));
            break;
        case 1:
            ((TObjEneEpsilon *)arg0)->copy_position(arg0 + 0x50);
            ((TObjEneDD *)arg0)->update_velocity();
            ((TObjEneMe1Canadin *)arg0)->update_angle();
            ((TObjEneMe1Canadin *)arg0)->update_position_with_offset();
            if (*(f32 *)((s8 *)arg0 + 0x3AC) > lbl_805D98B0) {
                ((TObjEneDD *)arg0)->move_with_wall_slide_commit(*(f32 *)((s8 *)arg0 + 0x3A0), *(f32 *)((s8 *)arg0 + 0x3A8), TObjEneMe1Canadin__data_805D98B4);
            }
            break;
        }
        ((VObj *)arg0)->m87();
        ((s32 (*)(void *))noop__17TObjEneMe1CanadinFv)(arg0);
        break;
    }
}

void TObjEneMe1Canadin__sub_8009C178(u8 *arg0, s32 arg1) {
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)arg0 + 0xB8) = 0;
        ((TObjEneDD *)arg0)->set_field_378(0xB);
        ((TObjEneDD *)(arg0))->vfunc_95();
        *(s32 *)((s8 *)arg0 + 0x3C8) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C8) & 0xFFBFFFFF);
        *(s32 *)((s8 *)arg0 + 0x30) = (s32) (*(s32 *)((s8 *)arg0 + 0x30) | 0x800);
        if ((s32) *(s32 *)((s8 *)arg0 + 0x3C4) == 1) {
            *(u8 **)((s8 *)arg0 + 0x3C0) = (u8 *)find_entity_by_id(*(u16 *)((s8 *)arg0 + 0x4C8));
            ((VObj_18_p4 *)(*(u8 **)((s8 *)arg0 + 0x3C0)))->m115(arg0);
        } else {
            ((TObjEnemy *)arg0)->send_entity_set_flags();
        }
        create_timed_particle_emitter((arg0 + 0x2FC), 0x117, 0, 0x19);
        create_timed_particle_emitter((arg0 + 0x2FC), 0x118, 0x19, 0xF);
        ((Sub_8009C178 *)(arg0 + 0x3CC))->s1(0x19);
        ((Sub_8009C178 *)(arg0 + 0x3CC))->s2();
        ((s32 (*)(int, void *, int, int))play_sound_effect)(0x4003AD18, arg0 + 0x2FC, 0, 0);
        return;
    case 3:
        if ((((Sub_8009C178 *)(arg0 + 0x3CC))->s4() != 0) && (((VObj_18_p4 *)(arg0))->m107() != 0)) {
            queue_destruction__7TObjectFv(arg0);
        }
    case 5:
    case 0:
        return;
    }
}

void TObjEneMe1Canadin__sub_8009C2EC(u8 *arg0, s32 arg1) {
    switch (arg1) {
    case 4:
        ((TObjEneMe1Canadin *)arg0)->advance_state_4_to_5();
        ((TObjEneDD *)arg0)->set_field_378(0xA);
        ((TObjEneMe1Canadin *)arg0)->vfunc_96();
        *(s32 *)((s8 *)arg0 + 0x3C8) &= 0xFFBFFFFF;
        *(s32 *)((s8 *)arg0 + 0x3C8) |= 0x200000;
        *(s32 *)((s8 *)arg0 + 0x30) |= 0x01000000;
        *(s32 *)((s8 *)arg0 + 0x410) = -0x7F80;
        break;
    case 3:
        if (*(s32 *)((s8 *)arg0 + 0x470) >= 0x96) {
            ((void (*)(void *, s16))transition_enemy_state__9TObjEneDDFs)(arg0, 0xD);
            *(s16 *)((s8 *)arg0 + 0x32C) = 0;
            *(s32 *)((s8 *)arg0 + 0x30) |= 0x800;
            ((s32 (*)(int, void *, int, int))play_sound_effect)(0x4003AD1F, arg0 + 0x2FC, 0, 0);
        }
        break;
    case 1:
        break;
    case 0: {
        advance_animation_playback();
        if (((TObjEneDD_ST *)arg0)->update_linked_position(TObjEneMe1Canadin__data_805D988C) != 0) {
            ((TObjEneDD_ST *)arg0)->enemy_copy_target_destination();
        }
        ((TObjEneDD *)arg0)->update_velocity();
        ((void (*)(void *, f32))TObjEneMe1Canadin__sub_8009EB98)(arg0, *(f32 *)((s8 *)arg0 + 0x3C) + *(f32 *)((s8 *)arg0 + 0x3EC));
        TObjEneEpsilon__sub_800B92AC(arg0, 0x200, lbl_805D98B8);
        *(s32 *)((s8 *)arg0 + 0x64) += 0x2000;
        (*(s32 *)((s8 *)arg0 + 0x470))++;
        if (*(s32 *)((s8 *)arg0 + 0x470) >= 0x96) {
            Copy5_8009C2EC c = *(Copy5_8009C2EC *)canadin_projectile_param_block;
            u8 *t = *(u8 **)((s8 *)arg0 + 0x468);
            *(f32 *)&c.w[1] = *(f32 *)((s8 *)t + 8);
            TObjEneDD__sub_800BA5A4(arg0, &c, t);
            *(s32 *)((s8 *)arg0 + 0x3C8) |= 0x800000;
        }
        if (*(s32 *)((s8 *)arg0 + 0x470) % 10 < 5) {
            *(s32 *)((s8 *)arg0 + 0x410) = 0xFFFF0000;
        } else {
            *(s32 *)((s8 *)arg0 + 0x410) = 0xFF000000;
        }
        play_persistent_sound(0x4003B71D, (s32)arg0, (u32)(arg0 + 0x2FC), 0, 0);
        ((TObjEneMe1Canadin *)arg0)->vfunc_89();
        break;
    }
    case 5:
        *(s32 *)((s8 *)arg0 + 0x64) = 0;
        break;
    }
}

void TObjEneMe1Canadin__sub_8009C510(u8 *arg0, s32 arg1) {
    f32 t;
    Vec_8009C510 v;
    f32 f;
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)arg0 + 0xB8) = I_8009C510(0x3FC);
        advance_animation_playback();
        fn_8009E378(arg0);
        I_8009C510(0x3C8) &= 0xFFBFFFFF;
        ((TObjEneDD *)arg0)->vfunc_96();
        I_8009C510(0x30) &= 0xFEFFFFFF;
        I_8009C510(0x470) = 0;
        if (F_8009C510(0x3F8) > TObjEneMe1Canadin__data_805D98AC + (F_8009C510(0x3C) + F_8009C510(0x3EC))) {
            I_8009C510(0x474) = 0;
        } else {
            I_8009C510(0x474) = 2;
        }
        F_8009C510(0x488) = F_8009C510(0x484) = lbl_805D9898;
        break;
    case 3:
        if (I_8009C510(0x474) == 3) {
            ((void (*)(void *, s32))transition_enemy_state__9TObjEneDDFs)(arg0, I_8009C510(0x378));
        }
        break;
    case 0:
        advance_animation_playback();
        VecCopy((Vec *)&v, (const Vec *)(arg0 + 0x308));
        f = ((TObjBoss2Tunnel *)(&v))->clamp_velocity();
        ((TObjEneDD *)arg0)->move_with_wall_slide_on_ground(v.x, v.z, f);
        f *= TObjEneMe1Canadin__data_805D98BC;
        F_8009C510(0x308) = v.x * f;
        F_8009C510(0x310) = v.z * f;
        switch (I_8009C510(0x474)) {
        case 0:
            F_8009C510(0x484) -= 0.13f;
            if (F_8009C510(0x484) < -4.0f) {
                F_8009C510(0x484) = -4.0f;
            }
            F_8009C510(0x3F8) += F_8009C510(0x484);
            if (F_8009C510(0x3F8) < lbl_805D98C8 + (F_8009C510(0x3C) + F_8009C510(0x3EC))) {
                I_8009C510(0x474) = 1;
                if (F_8009C510(0x484) > -2.0f) {
                    F_8009C510(0x484) = -2.0f;
                }
                F_8009C510(0x488) = F_8009C510(0x484) * F_8009C510(0x484) / lbl_805D98D0;
            }
            break;
        case 1:
            F_8009C510(0x484) += F_8009C510(0x488);
            F_8009C510(0x3F8) += F_8009C510(0x484);
            if (F_8009C510(0x484) >= lbl_805D9898) {
                if (F_8009C510(0x3F8) > F_8009C510(0x3C) + F_8009C510(0x3EC)) {
                    F_8009C510(0x3F8) = F_8009C510(0x3C) + F_8009C510(0x3EC);
                    I_8009C510(0x470) = 0;
                    I_8009C510(0x474) = 2;
                }
            }
            break;
        case 2:
            I_8009C510(0x470)++;
            if (I_8009C510(0x470) >= *(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x468)) + 0x28)) {
                I_8009C510(0x474) = 3;
            }
            break;
        }
        ((TObjEneDD *)arg0)->vfunc_89();
        break;
    case 5:
        clear_attack_receipts__9TObjEneDDFv();
        if (I_8009C510(0x3FC) == 5) {
            *(s16 *)((s8 *)arg0 + 0xB8) = 1;
        } else {
            *(s16 *)((s8 *)arg0 + 0xB8) = 0;
        }
        break;
    }
}

void TObjEneMe1Canadin::run_task(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    switch (arg1) {
    case 4:
        ((s32 (*)(void))advance_state_5_to_4__17TObjEneMe1CanadinFPv)();
        ((TObjEneDD *)arg0)->set_field_378(9);
        *(s32 *)((s8 *)arg0 + 0x3C8) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C8) & 0xFFBFFFFF);
        ((VObj_8009c7d8 *) arg0)->m93();
        *(s32 *)((s8 *)arg0 + 0x30) = (s32) (*(s32 *)((s8 *)arg0 + 0x30) | 0x01000000);
        if ((s32) *(s32 *)((s8 *)arg0 + 0x3C4) == 1) {
            *(s32 *)((s8 *)arg0 + 0x3C0) = (s32)find_entity_by_id((*(u16 *)((s8 *)arg0 + 0x4C8)));
            ((TObjEneMe1CanadinLeader *)(*(s32 *)((s8 *)arg0 + 0x3C0)))->set_flag3c8_bit8();
        }
        *(s32 *)((s8 *)arg0 + 0x404) = 0;
        return;
    case 3:
        if ((((VObj_8009c7d8 *) arg0)->m106() == 0) && (*(f32 *)((s8 *)arg0 + 0x3AC) < lbl_805D98D4)) {
            ((s32 (*)(void *, int))transition_enemy_state__9TObjEneDDFs)(arg0, 5);
        }
    case 5:
        return;
    case 0:
        advance_animation_playback();
        ((TObjEneEpsilon *)arg0)->copy_position((arg0 + 0x50));
        ((TObjEneDD *)arg0)->update_velocity();
        update_angle();
        update_position_with_offset();
        ((TObjEneDD *)arg0)->move_with_wall_slide_commit((f32) (*(f32 *)((s8 *)arg0 + 0x3A0)), (f32) (*(f32 *)((s8 *)arg0 + 0x3A8)), TObjEneMe1Canadin__data_805D98B4);
        ((VObj_8009c7d8 *) arg0)->m86();
        ((s32 (*)(void *))noop__17TObjEneMe1CanadinFv)(arg0);
        break;
    }
}

#pragma push
#pragma fp_contract on
void TObjEneMe1Canadin__sub_8009C91C(void *arg0, s32 arg1) {
    Can_8009C91C *o = (Can_8009C91C *)arg0;
    Vec_8009C91C *dir = &o->dir;
    switch (arg1) {
    case 4:
        ((TObjEneMe1Canadin *)o)->advance_state_4_to_5();
        ((TObjEneDD *)o)->set_field_378(8);
        o->flags &= 0xFFBFFFFF;
        ((TObjEneMe1Canadin *)o)->vfunc_96();
        o->f404 = 0;
        o->mode = 1;
        TObjEneMe1Canadin__sub_8009E948((u8 *)o);
        o->timer = 0;
        o->count = 0;
        o->rot = 0;
        o->f484 = lbl_805D9898;
        o->dist = lbl_805D9898;
        o->ddist = lbl_805D9898;
        dir->x = lbl_805D9898;
        dir->y = lbl_805D9898;
        dir->z = lbl_805D9898;
        break;
    case 3:
        if (((TObjEneMe1Canadin *)o)->vfunc_108() == 0 && ((TObjEneMe1Canadin *)o)->try_trigger_action() == 0 && o->count >= 4) {
            ((TObjEneMe1Canadin *)o)->vfunc_105();
        }
        break;
    case 0:
        advance_animation_playback();
        if (((TObjEneDD_ST *)o)->update_linked_position(TObjEneMe1Canadin__data_805D988C) != 0) {
            switch (o->mode) {
            case 1: {
                if (o->timer == 0) {
                    f32 t;
                    ((TObjEneDD_ST *)o)->enemy_copy_target_destination();
                    ((TObjEneDD *)o)->update_velocity();
                    t = lbl_805D98D8 * calc_elapsed_scaled__9TObjEneDDFv(o);
                    if (t >= lbl_805D9898) {
                        t += lbl_805D98DC;
                    } else {
                        t -= lbl_805D98DC;
                    }
                    t *= lbl_805D98E0;
                    o->rot = t;
                    dir->x = -o->vel.x;
                    dir->z = -o->vel.z;
                    o->f484 = lbl_805D98E0 * (o->f3E8 - o->f3F4);
                    o->ddist = lbl_805D98E0 * (lbl_805D98E4 - o->f3AC);
                    o->dist = o->f3AC;
                }
                o->timer++;
                if (o->timer >= 8) {
                    o->count++;
                    o->mode = 0;
                    TObjEneMe1Canadin__sub_8009E930((u8 *)o);
                }
                o->f3F8 += o->f484;
                rotate_xz_pair_by_angle(&dir->x, &dir->z, o->rot);
                {
                    Vec_8009C91C v;
                    f32 c;
                    o->dist += o->ddist;
                    v.x = dir->x * o->dist + o->base.x;
                    v.z = dir->z * o->dist + o->base.z;
                    subtract_vector(&v, &o->pos38);
                    c = ((TObjBoss2Tunnel *)(&v))->clamp_velocity();
                    ((TObjEneDD *)o)->move_to_wall_clamped_destination(v.x, v.z, c);
                }
                o->angle = (s32)(lbl_8043A3C8 * atan2_float(dir->x, dir->z)) + 0x8000;
                push_history_entry__17TObjEneMe1CanadinFPvfPvi(o->f408, TObjEneMe1Canadin__data_805D98B4, o->f414, o->f4B4);
                break;
            }
            case 0:
                ((TObjEneDD_ST *)o)->enemy_copy_target_destination();
                ((TObjEneDD *)o)->update_velocity();
                ((TObjEneMe1Canadin *)o)->update_angle();
                ((TObjEneMe1Canadin *)o)->update_hover_height();
                o->timer++;
                if (o->timer > 30) {
                    o->timer = 0;
                    o->mode = 1;
                }
                break;
            }
            ((TObjEneMe1Canadin *)o)->vfunc_89();
        }
        break;
    case 5:
        TObjEneMe1Canadin__sub_8009E930((u8 *)o);
        break;
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
#pragma optimization_level 3
void TObjEneMe1Canadin__sub_8009CC74(void *arg0, s32 arg1) {
    Can_8009CC74 *o = (Can_8009CC74 *)arg0;
    switch (arg1) {
    case 4:
        ((TObjEneMe1Canadin *)o)->advance_state_4_to_5();
        ((TObjEneDD *)o)->set_field_378(7);
        o->flags &= 0xFFBFFFFF;
        ((VObj_18_2d9fb9 *)o)->m94();
        o->f30 &= 0xFEFFFFFF;
        o->flags &= 0xFFF7FFFF;
        o->mode = 0;
        o->timer = 40;
        o->side = 0;
        o->speed = lbl_805D9898;
        o->dheight = lbl_805D9898;
        break;
    case 3:
        if (((VObj_18_2d9fb9 *)o)->m106() == 0 && ((TObjEneMe1Canadin *)o)->try_trigger_action() == 0 && o->mode == 4) {
            ((TObjEneDD *)o)->transition_enemy_state(8);
        }
        break;
    case 0:
        advance_animation_playback();
        if (o->mode == 0) {
            if (((TObjEneDD_ST *)o)->update_linked_position(TObjEneMe1Canadin__data_805D988C) == 0) {
                break;
            }
        } else if (((TObjEneEpsilon *)o)->update_death_check() == 0) {
            break;
        }
        switch (o->mode) {
        case 4:
            break;
        case 0: {
            f32 d;
            ((TObjEneDD_ST *)o)->enemy_copy_target_destination();
            ((TObjEneDD *)o)->update_velocity();
            ((TObjEneMe1Canadin *)o)->update_angle();
            o->timer++;
            if (o->timer > 40) {
                o->timer = 0;
                o->mode = 1;
                if (o->flags & 0x40000) {
                    if (o->f3AC < lbl_805D9894) {
                        o->mode = 2;
                        ((TObjEneMe1Canadin *)o)->reset_map_core(TObjEneMe1Canadin__map_core_default_vec4);
                    }
                } else if (o->f3AC < lbl_805D98E8) {
                    o->f3C0 = find_entity_by_id(o->f4C8);
                    if (((VObj_8009CC74 *)o->f3C0)->m114(o->target) != 0) {
                        o->flags |= 0x40000;
                    } else if (TObjEneMe1Canadin__sub_8009E860((Canadin_8009E860 *)o, &d, lbl_805D98EC) != 0) {
                        if (d < lbl_805D98E8) {
                            o->flags |= 0x40000;
                        }
                    } else {
                        o->mode = 4;
                    }
                }
            }
            TObjEneMe1Canadin__sub_8009EB14((u8 *)o, o->f3C + o->f3F4);
            break;
        }
        case 1:
            if (o->timer == 0) {
                f32 s, c, inv, len;
                ((TObjEneDD_ST *)o)->enemy_copy_target_destination();
                ((TObjEneDD *)o)->update_velocity();
                len = lbl_805D98F0;
                inv = lbl_805D98D4 / newton_sqrtf(len);
                c = lbl_805D98D0 * inv;
                s = lbl_805D98D0 * inv;
                len *= inv;
                if (o->side == 1) {
                    o->side = 0;
                    s = c * lbl_805D98F4;
                } else {
                    o->side = 1;
                }
                {
                    f32 nx, nz;
                    nx = o->vel.x * c + o->vel.z * s;
                    nz = o->vel.z * c - o->vel.x * s;
                    o->vel.x = nx;
                    o->vel.z = nz;
                }
                o->speed = lbl_805D98F8 * len;
                o->dheight = lbl_805D98F8 * (o->f3EC - o->f3F4);
                play_sound_effect(0x4003AD18, o->snd, 0, 0);
            }
            TObjEneMe1Canadin__sub_8009E948((u8 *)o);
            o->timer++;
            if (o->timer >= 4) {
                o->timer = 0;
                o->mode = 0;
                TObjEneMe1Canadin__sub_8009E930((u8 *)o);
            }
            o->f3F8 += o->dheight;
            ((TObjEneDD *)o)->move_to_wall_clamped_destination(o->vel.x, o->vel.z, o->speed);
            push_history_entry__17TObjEneMe1CanadinFPvfPvi(o->f408, lbl_805D98FC, o->f414, o->f4B4);
            break;
        case 2:
            ((TObjEneDD_ST *)o)->enemy_copy_target_destination();
            ((TObjEneDD *)o)->update_velocity();
            ((TObjEneMe1Canadin *)o)->update_angle();
            TObjEneMe1Canadin__sub_8009EB98((u8 *)o, o->f3C + o->f3EC);
            if (o->f3AC < lbl_805D9900) {
                if (TObjEneMe1Canadin__sub_8009E76C((u8 *)o) != 0) {
                    o->timer = 0;
                    o->mode = 3;
                }
            } else {
                if (o->f3AC > lbl_805D9894) {
                    o->mode = 1;
                }
                TObjEneEpsilon__sub_800B92AC((u8 *)o, 0x200, *o->f468);
            }
            ((void (*)(void *))noop__17TObjEneMe1CanadinFv)(o);
            break;
        case 3:
            ((TObjEneDD_ST *)o)->enemy_copy_target_destination();
            ((TObjEneDD *)o)->update_velocity();
            ((TObjEneMe1Canadin *)o)->update_angle();
            o->timer++;
            if (o->timer == 20) {
                Vec_8009CC74 v;
                VecCopy((Vec *)&v, (const Vec *)&o->v450);
                vec3_add_to(&v, &o->v45C);
                v.x *= TObjEneMe1Canadin__data_805D98BC;
                v.y *= TObjEneMe1Canadin__data_805D98BC;
                v.z *= TObjEneMe1Canadin__data_805D98BC;
                create_timed_particle_emitter(&v, 0x113, 0, 0x14);
            } else if (o->timer == 25) {
                o->f404++;
                if (TObjEneMe1Canadin__sub_8009E76C((u8 *)o) != 0 && ((VObj_8009CC74 *)o->target)->m18(o, lbl_805D98D4) != 0) {
                    ((VObj_8009CC74 *)o->target)->m20(o, lbl_805D98D4);
                    ((VObj_8009CC74 *)o->target)->m23(o, lbl_805D9904);
                    if ((s32)is_player_entity_id(obj_getField1c(o->target)) != 0 && is_target_android(o->target) != 0 && calc_boss4_scale__10TObjPlayerFi((s32)o) < lbl_805D9908) {
                        ((VObj_8009CC74 *)o->target)->m47();
                        ((VObj_8009CC74 *)o->target)->m72(0);
                    }
                }
                play_sound_effect(0x4003B219, o->snd, 0, 0);
            } else if (o->timer > 50) {
                if (o->f404 >= 3) {
                    o->mode = 4;
                } else {
                    o->timer = 0;
                    if (o->f3AC < lbl_805D990C) {
                        o->mode = 3;
                    } else if (o->f3AC < lbl_805D9894) {
                        o->mode = 2;
                    } else {
                        o->mode = 1;
                        ((TObjEneMe1Canadin *)o)->reset_map_core((void *)canadin_formation_reset_vec4);
                        if (o->f3AC > lbl_805D98E8) {
                            o->flags &= 0xFFFBFFFF;
                        }
                    }
                }
            }
            ((TObjEneMe1Canadin *)o)->set_target_speed_z();
            break;
        }
        ((VObj_18_2d9fb9 *)o)->m87();
        break;
    case 5:
        o->flags &= 0xFFFBFFFF;
        ((TObjEneMe1Canadin *)o)->reset_map_core((void *)canadin_formation_reset_vec4);
        TObjEneMe1Canadin__sub_8009E930((u8 *)o);
        break;
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
void TObjEneMe1Canadin__sub_8009D320(void *arg0, s32 arg1) {
    Vec_8009D320 *pos;
    Can_8009D320 *o = (Can_8009D320 *)arg0;
    pos = &o->pos;
    switch (arg1) {
    case 4:
        ((TObjEneDD *)o)->set_field_378(6);
        o->flags |= 0x10000;
        o->flags &= 0xFFBFFFFF;
        ((VObj_18_2d9fb9 *)o)->m94();
        o->f30 |= 0x01000000;
        ((TObjEneMe1Canadin *)o)->reset_map_core((void *)canadin_formation_reset_vec4);
        o->mode = 1;
        o->timer = 0;
        o->f49C = 0;
        o->f4A0 = 0;
        break;
    case 3:
        if (((VObj_18_2d9fb9 *)o)->m106() == 0 && ((TObjEneMe1Canadin *)o)->try_trigger_action() == 0 && o->mode == 6) {
            if (o->flags & 0x100000) {
                transition_enemy_state__9TObjEneDDFs(o, 8);
            } else {
                transition_enemy_state__9TObjEneDDFs(o, 9);
            }
        }
        break;
    case 0:
        advance_animation_playback();
        if (o->mode == 1) {
            if (((TObjEneDD_ST *)o)->update_linked_position(TObjEneMe1Canadin__data_805D988C) == 0) {
                break;
            }
        } else if (((TObjEneEpsilon *)o)->update_death_check() == 0) {
            break;
        }
        ((TObjEneDD_ST *)o)->enemy_copy_target_destination();
        switch (o->mode) {
        case 1:
            ((TObjEneDD *)o)->update_velocity();
            if (((TObjEneMe1Canadin *)o)->check_target() != 0) {
                o->mode = 2;
                o->flags |= 0x40000;
                ((TObjEneMe1Canadin *)o)->advance_state_4_to_5();
            } else {
                advance_state_5_to_4__17TObjEneMe1CanadinFPv(o);
            }
            TObjEneEpsilon__sub_800B92F8((u8 *)o, 0x200, (f32)TObjEneMe1Canadin__data_805D98BC);
            break;
        case 2:
            ((TObjEneDD *)o)->update_velocity();
            ((TObjEneMe1Canadin *)o)->update_angle();
            if (o->fB8 == 1) {
                void *p;
                o->mode = 3;
                ((TObjEneMe1Canadin *)o)->reset_map_core(TObjEneMe1Canadin__map_core_default_vec4);
                VecCopy((Vec *)pos, (const Vec *)&o->base);
                p = __nw__7TObjectFUl(0x48);
                if (p != 0) {
                    p = TObjEneMe1Canadin_EffLine__ct((u8 *)p, (s32)o, (s32)o->f414, (s32)pos);
                }
                o->f49C = p;
                play_sound_effect(0x4002B71B, o->snd, 0, 0);
                play_sound_effect(0x4002B51E, o->snd, 0, 0);
            }
            break;
        case 3: {
            Vec_8009D320 v;
            ((TObjEneDD *)o)->update_velocity();
            ((TObjEneMe1Canadin *)o)->update_angle();
            VecCopy((Vec *)&v, (const Vec *)&o->base);
            subtract_vector(&v, pos);
            if (((TObjBoss2Tunnel *)(&v))->clamp_velocity() < lbl_805D9910) {
                VecCopy((Vec *)pos, (const Vec *)&o->base);
            } else {
                pos->x = lbl_805D9910 * v.x + pos->x;
                pos->y = lbl_805D9910 * v.y + pos->y;
                pos->z = lbl_805D9910 * v.z + pos->z;
            }
            if (o->f4A0 == 0) {
                o->f4A0 = create_particle_emitter(o->f414, 0xF7);
                if (o->f4A0 != 0) {
                    ((TParticleCtrl *)(o->f4A0))->enable();
                }
            } else {
                ((TNowLoading *)(o->f4A0))->copy_pos(o->f414);
            }
            o->timer++;
            if (o->timer > o->prm->f18) {
                o->mode = 4;
                o->timer = 0;
                queue_destruction__7TObjectFv(o->f49C);
                o->f49C = 0;
                if (o->f4A0 != 0) {
                    queue_destruction__7TObjectFv(o->f4A0);
                    o->f4A0 = 0;
                }
            }
            break;
        }
        case 4:
            o->timer++;
            if (o->timer >= o->prm->f1C) {
                o->mode = 5;
                o->timer = 0;
                o->flags &= 0xFFFBFFFF;
                ((TObjEneMe1Canadin *)o)->reset_map_core((void *)canadin_formation_reset_vec4);
                o->f404++;
                {
                    void *q = __nw__7TObjectFUl(0x68);
                    if (q != 0) {
                        TObjEneMe1Canadin_EffDischarge__ct(q, o, o->f414, pos);
                    }
                }
                play_sound_effect(0x4002A408, o->snd, 0, 0);
            }
            break;
        case 5:
            o->timer++;
            if (o->timer > o->prm->f20) {
                o->timer = 0;
                if (o->f404 >= o->prm->f24) {
                    o->mode = 6;
                } else {
                    o->mode = 1;
                }
            }
            break;
        }
        ((TObjEneMe1Canadin *)o)->update_position_with_offset();
        ((VObj_18_2d9fb9 *)o)->m87();
        ((void (*)(void *))noop__17TObjEneMe1CanadinFv)(o);
        break;
    case 5:
        o->flags &= 0xFFFBFFFF;
        ((TObjEneMe1Canadin *)o)->reset_map_core((void *)canadin_formation_reset_vec4);
        if (o->f49C != 0) {
            queue_destruction__7TObjectFv(o->f49C);
            o->f49C = 0;
        }
        if (o->f4A0 != 0) {
            queue_destruction__7TObjectFv(o->f4A0);
            o->f4A0 = 0;
        }
        break;
    }
}
#pragma pop

void TObjEneMe1Canadin::move(s32 arg1) {
    s32 temp_r3;

    switch (arg1) {
    case 4:
        ((s32 (*)(void))advance_state_5_to_4__17TObjEneMe1CanadinFPv)();
        set_field_378(5);
        *(s32 *)((s8 *)this + 0x3C8) = (s32) (*(s32 *)((s8 *)this + 0x3C8) & 0xFFBFFFFF);
        this->vfunc_96();
        *(s32 *)((s8 *)this + 0x30) = (s32) (*(s32 *)((s8 *)this + 0x30) | 0x01000000);
        *(s32 *)((s8 *)this + 0x470) = 0;
        return;
    case 3:
        if ((this->vfunc_108() == 0) && ((s32) *(s32 *)((s8 *)this + 0x470) == 3)) {
            *(s32 *)((s8 *)this + 0x404) = 0;
            this->vfunc_105();
        }
    case 5:
    case 1:
        return;
    case 0:
        advance_animation_playback();
        update_linked_position(TObjEneMe1Canadin__data_805D988C);
        switch (*(s32 *)((s8 *)this + 0x470)) {
        case 0:
            temp_r3 = *(s32 *)((s8 *)this + 0x3C8);
            if (temp_r3 & 4) {
                *(s32 *)((s8 *)this + 0x3C8) = (s32) (temp_r3 & 0xFFFFFFFB);
                if (((s32 (*)(void *, s32))TObjEneMe1CanadinLeader__sub_8009E31C)(this, 0x200) != 0) {
                    *(s32 *)((s8 *)this + 0x470) = 1;
                    ((s32 (*)(void *, s32))TObjEneMe1CanadinLeader__sub_8009E4AC)(this, 1);
                } else {
                    *(s32 *)((s8 *)this + 0x470) = 2;
                    advance_state_4_to_5();
                    ((s32 (*)(void *, s32))TObjEneMe1CanadinLeader__sub_8009E4AC)(this, 3);
                }
            }
            TObjEneMe1Canadin::update_move(this);
            update_hover_height();
            break;
        case 1:
            if ((s32) *(s32 *)((s8 *)this + 0x4B8) == 0) {
                *(s32 *)((s8 *)this + 0x470) = 3;
            }
            TObjEneMe1Canadin::update_move(this);
            update_hover_height();
            break;
        case 2:
            TObjEneMe1Canadin::update_move(this);
            if ((s32) *(s32 *)((s8 *)this + 0x4B8) != 0) {
                update_hover_height();
            } else {
                ((s32 (*)(void *, f32))TObjEneMe1Canadin__sub_8009EB14)(this, *(f32 *)((s8 *)this + 0x3C) + *(f32 *)((s8 *)this + 0x3F0));
                if (*(s32 *)((s8 *)this + 0x3C8) & 0x80000) {
                    *(s32 *)((s8 *)this + 0x470) = 3;
                }
            }
            break;
        }
        this->vfunc_89();
        ((s32 (*)(void *))noop__17TObjEneMe1CanadinFv)(this);
        break;
    }
}

void TObjEneMe1Canadin::vfunc_111(s32 arg1) {
    switch (arg1) {
    case 4:
        ((s32 (*)(void))advance_state_5_to_4__17TObjEneMe1CanadinFPv)();
        set_field_378(4);
        *(s32 *)((s8 *)this + 0x3C8) = (s32) (*(s32 *)((s8 *)this + 0x3C8) & 0xFFBFFFFF);
        this->vfunc_96();
        *(s32 *)((s8 *)this + 0x30) = (s32) (*(s32 *)((s8 *)this + 0x30) | 0x01000000);
        return;
    case 3:
        if (*(s32 *)((s8 *)this + 0x3C8) & 0x80000) {
            *(s32 *)((s8 *)this + 0x404) = 0;
            this->vfunc_105();
        }
        return;
    case 5:
        break;
    case 0:
        advance_animation_playback();
        update_linked_position(TObjEneMe1Canadin__data_805D988C);
        TObjEneMe1Canadin::update_move(this);
        this->update_hover_height();
        this->vfunc_89();
        ((s32 (*)(void *))noop__17TObjEneMe1CanadinFv)(this);
        break;
    }
}

void TObjEneMe1Canadin::vfunc_110(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    s32 temp_r3;
    f32 temp_f1;

    switch (arg1) {
    case 4:
        ((s32 (*)(void))advance_state_5_to_4__17TObjEneMe1CanadinFPv)();
        ((TObjEneDD *)arg0)->set_field_378(3);
        *(s32 *)((s8 *)arg0 + 0x3C8) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C8) & 0xFFBFFFFF);
        this->vfunc_96();
        *(s32 *)((s8 *)arg0 + 0x30) = (s32) (*(s32 *)((s8 *)arg0 + 0x30) & 0xFEFFFFFF);
        {
            const f32 *p = (const f32 *) canadin_formation_reset_vec4;
            *(f32 *)((s8 *)arg0 + 0x4A8) = p[1];
            *(f32 *)((s8 *)arg0 + 0x4AC) = p[2];
            *(f32 *)((s8 *)arg0 + 0x4B0) = p[3];
            ((TObjEneMe1Canadin *)arg0)->pack_color_rgba();
        }
        *(s32 *)((s8 *)arg0 + 0x470) = 0;
        return;
    case 3:
        if (this->vfunc_108() == 0) {
            temp_r3 = *(s32 *)((s8 *)arg0 + 0x3C8);
            if (temp_r3 & 2) {
                *(s32 *)((s8 *)arg0 + 0x3C8) = (s32) (temp_r3 & 0xFFFFFFFD);
                if ((s32) *(s32 *)((s8 *)arg0 + 0x3C4) == 1) {
                    transition_enemy_state__9TObjEneDDFs(arg0, 5);
                } else {
                    transition_enemy_state__9TObjEneDDFs(arg0, 4);
                }
            }
        }
    case 1:
        return;
    case 0:
        advance_animation_playback();
        ((TObjEneDD_ST *)arg0)->update_linked_position(TObjEneMe1Canadin__data_805D988C);
        switch (*(s32 *)((s8 *)arg0 + 0x470)) {
        case 2:
            break;
        case 0:
            *(s32 *)((s8 *)arg0 + 0x400) = (s32) (*(s32 *)((s8 *)arg0 + 0x400) - 1);
            if ((s32) *(s32 *)((s8 *)arg0 + 0x400) <= 0) {
                *(s32 *)((s8 *)arg0 + 0x4B8) = 2;
                *(s32 *)((s8 *)arg0 + 0x470) = 1;
                play_sound_effect(0x4003B21A, arg0 + 0x2FC, 0, 0);
            }
            break;
        case 1:
            if ((s32) *(s32 *)((s8 *)arg0 + 0x4B8) == 0) {
                *(s32 *)((s8 *)arg0 + 0x3C8) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C8) | 0x8000);
                switch (*(s32 *)((s8 *)arg0 + 0x3C4)) {
                case 0:
                    ((TObjEneMe1CanadinLeader *)arg0)->set_attack_flag();
                case 1:
                    *(s32 *)((s8 *)arg0 + 0x470) = 3;
                    break;
                }
            }
            TObjEneMe1Canadin::update_move(arg0);
            break;
        case 3:
            TObjEneMe1Canadin::update_move(arg0);
            break;
        }
        ((TObjEneMe1Canadin *)arg0)->set_target_speed_z();
        this->vfunc_89();
        return;
    case 5:
        this->vfunc_92();
        break;
    }
}

void TObjEneMe1Canadin::action(s32 arg1) {
    s32 temp_r3;

    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)this + 0xB8) = 0;
        set_field_378(2);
        *(s32 *)((s8 *)this + 0x3C8) = (s32) (*(s32 *)((s8 *)this + 0x3C8) & 0xFFBFFFFF);
        this->vfunc_95();
        *(s32 *)((s8 *)this + 0x30) = (s32) (*(s32 *)((s8 *)this + 0x30) & 0xFEFFFFFF);
        *(s32 *)((s8 *)this + 0x3FC) = 4;
        *(s32 *)((s8 *)this + 0x4B8) = 1;
        break;
    case 3:
        if (this->vfunc_108() == 0) {
            temp_r3 = *(s32 *)((s8 *)this + 0x3C8);
            if (temp_r3 & 1) {
                *(s32 *)((s8 *)this + 0x3C8) = (s32) (temp_r3 & 0xFFFFFFFE);
                transition_enemy_state__9TObjEneDDFs(this, 3);
            } else if (enemy_has_live_target() != 0) {
                transition_enemy_state__9TObjEneDDFs(this, 3);
            }
        }
        break;
    case 0:
        advance_animation_playback();
        if ((s32) *(s32 *)((s8 *)this + 0x3C4) != 1) {
            update_linked_position(TObjEneMe1Canadin__data_805D988C);
        }
        if ((s32) *(s32 *)((s8 *)this + 0x3C4) == 2) {
            ((s32 (*)(void *, f32))TObjEneMe1Canadin__sub_8009EB14)(this, lbl_805D9890 + *(f32 *)((s8 *)this + 0x3C));
        } else {
            set_target_speed_z();
        }
        this->vfunc_89();
        break;
    case 5:
    case 1:
        break;
    }
}

void TObjEneMe1Canadin__sub_8009DE90(void *argv0, s32 arg1) {
#define arg0 ((u8 *)argv0)
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)arg0 + 0xB8) = 0;
        ((TObjEneDD *)arg0)->set_field_378(2);
        *(s32 *)((s8 *)arg0 + 0x3C8) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C8) & 0xFFBFFFFF);
        ((TObjEneMe1Canadin *)arg0)->vfunc_95();
        *(s32 *)((s8 *)arg0 + 0x30) = (s32) (*(s32 *)((s8 *)arg0 + 0x30) | 0x01000000);
        *(s32 *)((s8 *)arg0 + 0x3FC) = 4;
        *(s32 *)((s8 *)arg0 + 0x4B8) = 1;
        TObjEneMe3SinowZoa__sub_800D758C(arg0 + 0x3CC);
        TBoss3Volopt__sub_800D8D88((s32)(arg0 + 0x38));
        return;
    case 3:
        if (((V_Sub_8009DE90 *) (arg0 + 0x3CC))->m5() != 0) {
            transition_enemy_state__9TObjEneDDFs(arg0, 2);
        }
    case 5:
        return;
    case 0:
        advance_animation_playback();
        if ((s32) *(s32 *)((s8 *)arg0 + 0x3C4) == 2) {
            ((s32 (*)(void *, f32))TObjEneMe1Canadin__sub_8009EB14)(arg0, lbl_805D9890 + *(f32 *)((s8 *)arg0 + 0x3C));
        } else {
            ((TObjEneMe1Canadin *)arg0)->set_target_speed_z();
        }
        ((TObjEneMe1Canadin *)arg0)->vfunc_88();
        break;
    }
#undef arg0
}

void TObjEneMe1Canadin::handle_state(s32 arg1) {
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)this + 0xB8) = 0;
        set_field_378(2);
        this->vfunc_95();
        *(s32 *)((s8 *)this + 0x3C8) = (s32) (*(s32 *)((s8 *)this + 0x3C8) | 0x400000);
        *(s32 *)((s8 *)this + 0x3FC) = 4;
        *(s32 *)((s8 *)this + 0x4B8) = 1;
        *(s32 *)((s8 *)this + 0x470) = 0;
        return;
    case 3:
        if ((s32) *(s32 *)((s8 *)this + 0x470) >= 4) {
            if ((s32) *(s32 *)((s8 *)this + 0x3C4) == 0) {
                *(s32 *)((s8 *)this + 0x3C8) = (s32) (*(s32 *)((s8 *)this + 0x3C8) | 0x100000);
            }
            transition_enemy_state__9TObjEneDDFs(this, 1);
        }
    case 5:
        return;
    case 0:
        *(s32 *)((s8 *)this + 0x470) = (s32) (*(s32 *)((s8 *)this + 0x470) + 1);
        if ((s32) *(s32 *)((s8 *)this + 0x470) == 2) {
            this->vfunc_107();
        }
        *(s32 *)((s8 *)this + 0x3C8) = (s32) (*(s32 *)((s8 *)this + 0x3C8) & 0xFEFFFFFF);
        break;
    }
}

void dispatch_state__17TObjEneMe1CanadinFPvUii(Canadin_8009E0AC *self, u32 which, s32 arg) {
    switch (which) {
    case 0:
        ((TObjEneMe1Canadin *)self)->handle_state(arg);
        break;
    case 1:
        TObjEneMe1Canadin__sub_8009DE90(self, arg);
        break;
    case 2:
        ((TObjEneMe1Canadin *)self)->action(arg);
        break;
    case 3:
        self->m108(arg);
        break;
    case 4:
        self->m109(arg);
        break;
    case 5:
        ((TObjEneMe1Canadin *)self)->move(arg);
        break;
    case 6:
        TObjEneMe1Canadin__sub_8009D320(self, arg);
        break;
    case 7:
        TObjEneMe1Canadin__sub_8009CC74(self, arg);
        break;
    case 8:
        TObjEneMe1Canadin__sub_8009C91C(self, arg);
        break;
    case 9:
        ((TObjEneMe1Canadin *)self)->run_task(arg);
        break;
    case 10:
        ((void (*)(void *, s32))TObjEneMe1Canadin__sub_8009C2EC)(self, arg);
        break;
    case 11:
        ((void (*)(void *, s32))TObjEneMe1Canadin__sub_8009C178)(self, arg);
        break;
    case 12:
        ((void (*)(void *, s32))TObjEneMe1Canadin__sub_8009C510)(self, arg);
        break;
    case 13:
        self->m110(arg);
        break;
    case 14:
        ((void (*)(void *, s32))TObjEneMe1Canadin__sub_8009BFF8)(self, arg);
        break;
    case 16:
        ((TObjEneMe1Canadin *)self)->update_walk_animation(arg);
        break;
    case 17:
        ((TObjEneMe1Canadin *)self)->update_by_state(arg);
        break;
    }
}

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void fn_8009E1D4(u8 *arg0, s32 arg1) {
    struct CopyStack_8009E1D4 { u8 bytes[0x14]; };
    CopyStack_8009E1D4 copy_storage_8009E1D4;
    *(ByteBlock_14 *)(copy_storage_8009E1D4.bytes) = *(const ByteBlock_14 *)((s32) ((u8 *)((void *)((u8 *)&canadin_behavior_params.value + -4))) + 4);
    (*(f32 *)(copy_storage_8009E1D4.bytes + 0x4)) = *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x468)) + 4);
    TObjEneDD::setup(arg0, arg1, (s32)copy_storage_8009E1D4.bytes);
}
extern int fold_flush_0;
#pragma pop

void TObjEneMe1CanadinLeader::set_flag3c8_bit40() { *(u32*)((char*)this + 0x3c8) |= 0x40; }

void TObjEneMe1CanadinLeader::set_flag3c8_bit20() { *(u32*)((char*)this + 0x3c8) |= 0x20; }

void TObjEneMe1CanadinLeader__sub_8009E258(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 0x3C8) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C8) | 0x100000 | 4);
}

void TObjEneMe1CanadinLeader::set_flag3c8_bit8() { *(u32*)((char*)this + 0x3c8) |= 0x8; }

void TObjEneMe1CanadinLeader__sub_8009E27C(void* p) { *(u32*)((char*)p + 0x3c8) |= 0x4; }

void TObjEneMe1CanadinLeader::set_attack_flag() { *(u32*)((char*)this + 0x3c8) |= 0x2; }

void TObjEneMe1CanadinLeader::set_leader_index(s32 arg1, s32 arg2) {
    set_target_player__12TObjEneDD_STFPv(this);
    *(s32 *)((s8 *)this + 0x400) = arg2;
    *(s32 *)((s8 *)this + 0x3C8) = (s32) (*(s32 *)((s8 *)this + 0x3C8) | 1);
}

void fn_8009E2DC(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 0x400) = 0;
    *(s32 *)((s8 *)arg0 + 0x3C8) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C8) | 1);
}

int TObjEneMe1Canadin::vfunc_116() { return 1; }

void TObjEneMe1Canadin::vfunc_117() {  }

s32 fn_8009E300(u8 *arg0) {
    if (*(s32 *)((s8 *)arg0 + 0x3C8) & 0x40000) {
        return *(s32 *)((s8 *)arg0 + 0x390);
    }
    return 0;
}

u8 TObjEneMe1CanadinLeader__sub_8009E31C(u8 *arg0, s32 arg1) {
    return (u8) ((*(s32 *)((s8 *)arg0 + 0x3C8) & arg1) != 0);
}

void TObjEneMe1CanadinLeader__sub_8009E334(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 0x3C8) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C8) | 0x200);
    *(s32 *)((s8 *)arg0 + 0x3C8) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C8) & 0xFFFFFEFF);
}

void TObjEneMe1CanadinLeader__sub_8009E350(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 0x3C8) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C8) | 0x100);
    *(s32 *)((s8 *)arg0 + 0x3C8) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C8) & 0xFFFFFDFF);
}

int TObjEneMe1CanadinLeader__sub_8009E36C(void* p) { return (*(u32*)((char*)p + 0x3c8) >> 15) & 0x1; }

void fn_8009E378(void *arg0) {
    if ((s16) *(s16 *)((s8 *)arg0 + 0x326) == 2) {
        *(s32 *)((s8 *)arg0 + 0x3C0) = (s32)find_entity_by_id(*(u16 *)((s8 *)arg0 + 0x4C8));
        fn_8009E2DC((u8 *)((void*)((void*)(*(s32 *)((s8 *)arg0 + 0x3C0)))));
    }
}

int TObjEneMe1Canadin::vfunc_109() { return 1; }

void TObjEneMe1Canadin::vfunc_113() {
    *lbl_805D4FEC = *(s32 *)((s8 *)this + 0x4B4);
    *lbl_805D4FF0 = *(s32 *)((s8 *)this + 0x4B4);
}

void TObjEneMe1Canadin::pack_color_rgba() {
    u8 *arg0 = (u8 *)this;
    *(u32 *)((s8 *)arg0 + 0x4B4) = ((u8) __cvt_fp2unsigned(lbl_805D9914 * *(f32 *)((s8 *)arg0 + 0x4AC)) << 24)
        | ((u8) __cvt_fp2unsigned(lbl_805D9914 * *(f32 *)((s8 *)arg0 + 0x4B0)) << 16)
        | ((u8) __cvt_fp2unsigned(TObjEneMe1Canadin__data_805D98B4 * (lbl_805D9914 * *(f32 *)((s8 *)arg0 + 0x4A4))) << 8)
        | (u8) __cvt_fp2unsigned(lbl_805D9914 * *(f32 *)((s8 *)arg0 + 0x4A8));
}

void TObjEneMe1Canadin::reset_map_core(void * _w1) { ((int (*)(void*))copy_vec4__13TRaderMapCoreFPv)((char*)this + 0x4a4); pack_color_rgba(); }

void TObjEneMe1CanadinLeader__sub_8009E4AC(u8 *arg0, s32 arg1) {
    ((TObjEneMe1Canadin *)arg0)->reset_map_core(&canadin_formation_fade_start_color.value);
    *(s32 *)((s8 *)arg0 + 0x4B8) = 3;
    *(s32 *)((s8 *)arg0 + 0x4BC) = arg1;
    *(s32 *)((s8 *)arg0 + 0x4C0) = 2;
    *(s32 *)((s8 *)arg0 + 0x4C4) = 0;
}

#define p ((Canadin_8009E504 *)pv)
void TObjEneMe1CanadinLeader::update_fade_sequence(void *pv) {
    switch (p->state) {
    case 0:
        break;
    case 1:
        if (p->f4a4 > lbl_805D9898) {
            p->f4a4 = p->f4a4 - lbl_805D9918;
        } else {
            p->f4a4 = lbl_805D9898;
            p->state = 0;
        }
        ((TObjEneMe1Canadin *)p)->pack_color_rgba();
        break;
    case 2:
        if (p->f4a4 < lbl_805D98D4) {
            p->f4a4 = p->f4a4 + lbl_805D9918;
        } else {
            p->f4a4 = lbl_805D98D4;
            p->state = 0;
        }
        ((TObjEneMe1Canadin *)p)->pack_color_rgba();
        break;
    case 3:
        p->timer++;
        if ((f32)p->timer >= lbl_805D98B0) {
            p->timer = 0;
            switch (((s8 **)canadin_leader_fade_sequence_table)[p->tblIdx][p->pos++]) {
            case 0x62:
                p->f4a4 = lbl_805D9898;
                break;
            case 0x63:
                p->state = 0;
                copy_vec4__13TRaderMapCoreFPv(&p->f4a4, (void *)canadin_formation_reset_vec4);
                break;
            case 0x61:
                p->f4a4 = lbl_805D98D4;
                break;
            }
            ((TObjEneMe1Canadin *)p)->pack_color_rgba();
        }
        break;
    }
}
#undef p

int select_and_apply_target__17TObjEneMe1CanadinFPv(void* p) { return select_and_apply_target__12TObjEneDD_STFf(p); }

void noop__17TObjEneMe1CanadinFv(void) {  }

s32 TObjEneMe1Canadin::try_trigger_action() {
    if ((u32) *(u32 *)((s8 *)this + 0x390) == 0U) {
        transition_enemy_state__9TObjEneDDFs(this, 0xE);
        return 1;
    }
    return 0;
}

s32 TObjEneMe1Canadin::vfunc_108() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r4;
    temp_r4 = *(s32 *)((s8 *)arg0 + 0x3C8);
    if (temp_r4 & 0x20) {
        *(s32 *)((s8 *)arg0 + 0x3C8) = (s32) (temp_r4 & 0xFFFFFFDF);
        transition_enemy_state__9TObjEneDDFs(arg0, 0xA);
        *(s32 *)((s8 *)arg0 + 0x40C) = 0;
        return 1;
    }
    if (temp_r4 & 0x40) {
        *(s32 *)((s8 *)arg0 + 0x3C8) = (s32) (temp_r4 & 0xFFFFFFBF);
        transition_enemy_state__9TObjEneDDFs(arg0, 0xB);
        return 1;
    }
    return 0;
}

void TObjEneMe1Canadin::vfunc_107() {  }

s32 TObjEneMe1Canadin__sub_8009E76C(u8 *arg0) {
    return *(f32 *)((s8 *)arg0 + 0x3F4) < lbl_805D991C;
}

void advance_state_5_to_4__17TObjEneMe1CanadinFPv(void *arg0) {
    if ((s32) *(s32 *)((s8 *)arg0 + 0x3FC) == 5) {
        *(s16 *)((s8 *)arg0 + 0xB8) = 3;
        *(s32 *)((s8 *)arg0 + 0x3FC) = 4;
    }
}

void TObjEneMe1Canadin::advance_state_4_to_5() {
    if ((s32) *(s32 *)((s8 *)this + 0x3FC) == 4) {
        *(s16 *)((s8 *)this + 0xB8) = 2;
        *(s32 *)((s8 *)this + 0x3FC) = 5;
    }
}

s32 TObjEneMe1Canadin::check_target() {
    f32 sp8;
    s32 var_r31;

    var_r31 = 0;
    if (*(f32 *)((s8 *)this + 0x3AC) < lbl_805D98E4) {
        var_r31 = 1;
        *(void **)((s8 *)this + 0x3C0) = find_entity_by_id(*(u16 *)((s8 *)this + 0x4C8));
        if ((((VObj_8009E7C4_8009E474 *)(*(void **)((s8 *)this + 0x3C0)))->m114(*(s32 *)((s8 *)this + 0x390)) == 0) && (TObjEneMe1Canadin__sub_8009E860((Canadin_8009E860 *)(this), &sp8, lbl_805D9920) != 0) && (sp8 > lbl_805D98E4)) {
            var_r31 = 0;
        }
    }
    return var_r31;
}

s32 TObjEneMe1Canadin__sub_8009E860(Canadin_8009E860 *self, f32 *out, f32 _w2) {
    Entry_8009E860 list[5];
    s32 found;
    s32 count;
    u32 id;
    s32 i;
    found = 0;
    *out = lbl_805D98F4;
    count = collect_enemy_target_candidates(self, list);
    for (i = 0; i < count; i++) {
        id = (u32)get_player_by_client_id(list[i].id);
        if (id != self->owner) {
            self->target = (Target_8009E860 *)find_entity_by_id(self->target_id);
            if (self->target->m114(id) != 0) {
                *out = newton_sqrtf(list[i].dist);
                found = 1;
                ((void (*)(void *, u32))set_target_player__12TObjEneDD_STFPv)(self, id);
                break;
            }
        }
    }
    return found;
}

void TObjEneMe1Canadin__sub_8009E930(u8 *arg0) {
    u8 *temp_r4;
    temp_r4 = *(u8 **)((s8 *)arg0 + 0xA4);
    *(s32 *)((s8 *)temp_r4 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r4 + 0x18) & ~0x28);
}

void TObjEneMe1Canadin__sub_8009E948(u8 *arg0) {
    u8 *temp_r3;
    temp_r3 = *(u8 **)((s8 *)arg0 + 0xA4);
    *(s32 *)((s8 *)temp_r3 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r3 + 0x18) | 0x28);
}

void TObjEneMe1Canadin::vfunc_89() { vfunc_89__9TObjEneDDFv(this); }

void TObjEneMe1Canadin::vfunc_105() {
    u8 *arg0 = (u8 *)this;
    if (*(s32 *)((s8 *)arg0 + 0x3C8) & 0x100) {
        transition_enemy_state__9TObjEneDDFs(arg0, 7);
        return;
    }
    if ((s32) *(s32 *)((s8 *)arg0 + 0x3C4) == 0) {
        if ((s32) *(s32 *)((s8 *)arg0 + 0x46C) < 2) {
            transition_enemy_state__9TObjEneDDFs(arg0, 6);
            *(s32 *)((s8 *)arg0 + 0x46C) = (s32) (*(s32 *)((s8 *)arg0 + 0x46C) + 1);
            return;
        }
        transition_enemy_state__9TObjEneDDFs(arg0, 7);
        *(s32 *)((s8 *)arg0 + 0x46C) = 0;
        return;
    }
    transition_enemy_state__9TObjEneDDFs(arg0, 6);
}

void TObjEneMe1Canadin::update_move(void* p) { if (((TObjEneDD_ST *)p)->enemy_has_live_target() != 0) { ((TObjEneDD_ST *)p)->enemy_copy_target_destination(); ((TObjEneDD *)p)->update_velocity(); ((TObjEneMe1Canadin *)p)->update_angle(); } }

void TObjEneMe1Canadin::update_angle() {
    *(s32 *)((s8 *)this + 0x60) = approach_angle_limited(*(s32 *)((s8 *)this + 0x60), (s32) (lbl_8043A3C8 * atan2_float(*(f32 *)((s8 *)this + 0x3A0), *(f32 *)((s8 *)this + 0x3A8))), 0x400);
    *(s32 *)((s8 *)this + 0x60) = (s32) (s16) *(s32 *)((s8 *)this + 0x60);
}

void TObjEneMe1Canadin::update_hover_height() {
    TObjEneMe1Canadin__sub_8009EB14((u8*)this, (*(f32 *)((s8 *)this + 0x3E8) + *(f32 *)((s8 *)this + 0x3C)));
}

void TObjEneMe1Canadin::set_target_speed_z() {
    TObjEneMe1Canadin__sub_8009EB14((u8*)this, (*(f32 *)((s8 *)this + 0x3EC) + *(f32 *)((s8 *)this + 0x3C)));
}

void TObjEneMe1Canadin__sub_8009EB14(u8 *arg0, f32 height) {
    Stack_800CBDBC stack;
    ((s32 (*)(u8*, f32))TObjEneMe1Canadin__sub_8009EB98)(arg0, height);
    VecCopy((Vec *)(&stack.sp8), (const Vec *)(arg0 + 0x38));
    stack.spC = *(f32 *)((s8 *)arg0 + 0x3F8);
    ((TObjEneMe1Canadin *)(arg0))->vfunc_101((u8 *)&stack.sp8);
}

void TObjEneMe1Canadin::update_position_with_offset() {
    TObjEneMe1Canadin__sub_8009EB98((u8 *)this, *(f32 *)((s8 *)this + 0x3C) + *(f32 *)((s8 *)this + 0x3E8));
}

void TObjEneMe1Canadin__sub_8009EB98(u8 *arg0, f32 farg0) {
    f32 temp_f3;
    temp_f3 = farg0 - *(f32 *)((s8 *)arg0 + 0x3F8);
    *(s32 *)((s8 *)arg0 + 0x3C8) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C8) & 0xFFF7FFFF);
    if (temp_f3 >= TObjEneMe1Canadin__data_805D98BC) {
        *(f32 *)((s8 *)arg0 + 0x3F8) = (f32) (*(f32 *)((s8 *)arg0 + 0x3F8) + TObjEneMe1Canadin__data_805D98BC);
        return;
    }
    if (temp_f3 <= lbl_805D9924) {
        *(f32 *)((s8 *)arg0 + 0x3F8) = (f32) (*(f32 *)((s8 *)arg0 + 0x3F8) - TObjEneMe1Canadin__data_805D98BC);
        return;
    }
    *(f32 *)((s8 *)arg0 + 0x3F8) = farg0;
    *(s32 *)((s8 *)arg0 + 0x3C8) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C8) | 0x80000);
}

u8 *TObjEneMe1Canadin::vfunc_101(u8 *) {
    if (vfunc_101__9TObjEneDDFPUc() == 0U) {
        *(s32 *)((s8 *)this + 0x3C8) = (s32) (*(s32 *)((s8 *)this + 0x3C8) & 0xFEFFFFFF);
        return;
    }
    *(s32 *)((s8 *)this + 0x3C8) = (s32) (*(s32 *)((s8 *)this + 0x3C8) | 0x01000000);
}

#pragma push
#pragma fp_contract on
void calc_move_vector__17TObjEneMe1CanadinFiPv(s32 actor, void *arg1) {
    f32 temp_f1;
    f32 temp_f31;
    s32 random_scaled;

    random_scaled = TObjEneDD::get_random_scaled();
    f32 fv = calc_boss4_scale__10TObjPlayerFi(actor);
    temp_f31 = (lbl_805D98D0 * fv) + lbl_805D989C;
    temp_f1 = temp_f31 * ((f32 (*)(s32, f32))sin_table_lookup)(random_scaled, fv);
    *(f32 *)((s8 *)arg1 + 0) = temp_f1;
    *(f32 *)((s8 *)arg1 + 4) = (f32) lbl_805D9898;
    *(f32 *)((s8 *)arg1 + 8) = (f32) (temp_f31 * ((f32 (*)(s32, f32))cos_table_lookup)(random_scaled, temp_f1));
    ((s32 (*)(void *, s32))vec3_add_to)(arg1, actor + 0x38);
}
extern int fold_flush_1;
#pragma pop

void TObjEneMe1Canadin::vfunc_106() {
    *(s32 *)((s8 *)this + 0x34) = (s32) *(s32 *)((s8 *)(*(void **)((s8 *)lbl_805D4FD0 + 0x42C)) + 8);
    *(s32 *)((s8 *)this + 0x24) = (s32) *(s32 *)((s8 *)(*(void **)((s8 *)lbl_805D4FD0 + 0x42C)) + 0x1C);
}

void TObjEneMe1Canadin::update_by_field_0x354() {
    if ((s32) get_random_float__21TObjEneMe3ShinowaRealFv(*(f32 *)((s8 *)this + 0x354)) == 0) {
        ((s32 (*)(void *))TObjEneMe1CanadinLeader__sub_8009E350)(this);
        return;
    }
    ((s32 (*)(void *))TObjEneMe1CanadinLeader__sub_8009E334)(this);
}

void TObjEneMe1Canadin::vfunc_88() {
    struct VBase_8009ED5C_8009ECE0 *o = (struct VBase_8009ED5C_8009ECE0 *)this;
    *(f32 *)((s8 *)this + 0x3F4) = (f32) (*(f32 *)((s8 *)this + 0x3F8) - *(f32 *)((s8 *)this + 0x3C));
    if (*(f32 *)((s8 *)this + 0x3F4) < lbl_805D98D0) {
        o->m96();
    } else {
        o->m95();
    }
    *(f32 *)((s8 *)(*(void **)((s8 *)this + 0xA4)) + 4) = (f32) *(f32 *)((s8 *)this + 0x3F4);
}

void TObjEneMe1Canadin::copy_pos() {
    u8 *arg0 = (u8 *)this;
    *(f32 *)((s8 *)arg0 + 0x2FC) = (f32) *(f32 *)((s8 *)arg0 + 0x38);
    *(f32 *)((s8 *)arg0 + 0x300) = (f32) *(f32 *)((s8 *)arg0 + 0x3F8);
    *(f32 *)((s8 *)arg0 + 0x304) = (f32) *(f32 *)((s8 *)arg0 + 0x40);
    VecCopy((Vec *)(arg0 + 0x74), (const Vec *)(arg0 + 0x2FC));
}

void TObjEneMe1Canadin::vfunc_61() {  }

void TObjEneMe1Canadin::vfunc_62() { if (*(short*)((char*)this + 0x326) != 12) { ((int (*)(void*, void*))transition_enemy_state__9TObjEneDDFs)(this, (void*)12); } }

void TObjEneMe1Canadin::vfunc_63() {
    s16 temp_r0;

    temp_r0 = *(s16 *)((s8 *)this + 0x326);
    if ((temp_r0 != 0xD) && (temp_r0 != 0xB)) {
        ((int (*)(void*, void*))transition_enemy_state__9TObjEneDDFs)(this, (void*)(0xD));
    }
}

void TObjEneMe1Canadin::vfunc_28() {  }

void TObjEneMe1Canadin::run_task() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r3;
    if (TObjPlayer::check_demo_mode() != 0) {
        this->update_if_ready();
        return;
    }
    if (((s32) *(s32 *)((s8 *)arg0 + 0x3C4) == 1) && ((*(u8 **)((s8 *)arg0 + 0x3C0) = (u8 *)find_entity_by_id(*(u16 *)((s8 *)arg0 + 0x4C8)), temp_r3 = *(u8 **)((s8 *)arg0 + 0x3C0), ((temp_r3 == NULL) != 0)) || (((TObject *)temp_r3)->all_parents_unqueued_for_destruction() == 0))) {
        ((void (*)(void *))queue_destruction__7TObjectFv)(arg0);
        return;
    }
    if (this->vfunc_83() != 4) {
        this->vfunc_85();
        TObjEneMe1CanadinLeader::update_fade_sequence(arg0);
    }
    copy_pos();
    ((TBoss8Dragon *)arg0)->set_player_state_default();
    this->vfunc_100();
}

void *__dt__17TObjEneMe1CanadinFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__17TObjEneMe1Canadin;
        if (*(void **)((s8 *)arg0 + 0x4A0) != NULL) { ((void (*)(void *))queue_destruction__7TObjectFv)(*(void **)((s8 *)arg0 + 0x4A0)); *(s32 *)((s8 *)arg0 + 0x4A0) = 0; }
        ((void (*)(void *))queue_destruction__7TObjectFv)(*(void **)((s8 *)arg0 + 0x408));
        *(s32 *)((s8 *)arg0 + 0x408) = 0;
        free_collision_body_parts(arg0);
        __dt__13TUnk_80494938Fv((s8 *)arg0 + 0x3CC, -1);
        __dt__12TObjEneDD_STFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

#pragma push
#pragma fp_contract on
void TObjEneMe1Canadin::setup_enemy() {
    u8 *arg0 = (u8 *)this;
    s32 i;
    void *p;

    ((TObjEneDD *)arg0)->init_position_vectors();
    this->vfunc_106();
    init_model__9TObjEneDDFv(arg0, lbl_8048FECC, 1);
    ((TObjMotion *)arg0)->set_field_d8((s32)lbl_8048FF30);
    ((TObjMotion *)arg0)->set_field_dc(*(s32 *)((s8 *)(*(u8 * *)&lbl_805D4FD0) + 0x430));
    *(s16 *)((s8 *)arg0 + 0xB8) = 0;
    ((TObjMotion *)arg0)->set_animation(*(s16 *)((s8 *)arg0 + 0xB8));
    ((TObjMotion *)arg0)->set_field_b8(*(s16 *)((s8 *)arg0 + 0xB8));
    reset_hp__9TObjEneDDFv(arg0, lbl_80500930[*(s32 *)((s8 *)arg0 + 0x3C4)], lbl_8050093C[*(s32 *)((s8 *)arg0 + 0x3C4)], lbl_80500948[*(s32 *)((s8 *)arg0 + 0x3C4)]);
    ((TObjEneDD *)arg0)->check_state_flag_4();
    *(void **)((s8 *)arg0 + 0x350) = canadin_setup_param_block;
    initialize_enemy_state__9TObjEneDDFv(arg0, 0x1C);
    *(f32 *)((s8 *)arg0 + 0x37C) = lbl_805D989C;
    ((TObjEneDD_ST *)arg0)->enemy_init_acquire_period(0x2D);
    ((TObjEneDD_ST *)arg0)->enemy_init_validate_period(0x2D);
    ((TObjEneDD_ST *)arg0)->set_active();
    *(s32 *)((s8 *)arg0 + 0x30) |= 0x01000000;
    *(s32 *)((s8 *)arg0 + 0x468) = lbl_80500954[*(s32 *)((s8 *)arg0 + 0x3C4)];
    ((VSub_8009F004 *)(arg0 + 0x3CC))->m2();
    *(f32 *)((s8 *)arg0 + 0x3E8) = lbl_805D9928;
    *(f32 *)((s8 *)arg0 + 0x3EC) = lbl_805D98A4;
    *(f32 *)((s8 *)arg0 + 0x3F0) = TObjEneMe1Canadin__data_805D98AC * (lbl_805D992C * (f32)rand()) + lbl_805D98A4;
    *(f32 *)((s8 *)arg0 + 0x3F4) = *(f32 *)((s8 *)arg0 + 0x3EC);
    *(f32 *)((s8 *)arg0 + 0x3F8) = *(f32 *)((s8 *)arg0 + 0x3C) + *(f32 *)((s8 *)arg0 + 0x3F4);
    *(s32 *)((s8 *)arg0 + 0x3FC) = 4;
    *(s32 *)((s8 *)arg0 + 0x400) = 0;
    *(s32 *)((s8 *)arg0 + 0x404) = 0;
    p = ((void * (*)(u32))__nw__7TObjectFUl)(0x38);
    if (p != NULL) {
        p = __ct__26TObjEneMe1Canadin_EffLightFP7TObjectl(p, arg0, 5);
    }
    *(void **)((s8 *)arg0 + 0x408) = p;
    *(s32 *)((s8 *)arg0 + 0x40C) = 0;
    *(s32 *)((s8 *)arg0 + 0x410) = 0;
    for (i = 0; i < 7; i++) {
        VecCopy((Vec *)(&((Obj_8009F004 *)arg0)->v[i]), (const Vec *)(arg0 + 0x38));
    }
    *(s32 *)((s8 *)arg0 + 0x46C) = 0;
    *(s32 *)((s8 *)arg0 + 0x470) = 0;
    *(s32 *)((s8 *)arg0 + 0x474) = 0;
    *(s32 *)((s8 *)arg0 + 0x478) = 0;
    *(s32 *)((s8 *)arg0 + 0x47C) = 0;
    *(s32 *)((s8 *)arg0 + 0x480) = 0;
    *(f32 *)((s8 *)arg0 + 0x484) = lbl_805D9898;
    *(f32 *)((s8 *)arg0 + 0x488) = lbl_805D9898;
    *(f32 *)((s8 *)arg0 + 0x48C) = lbl_805D9898;
    *(f32 *)((s8 *)arg0 + 0x490) = lbl_805D9898;
    *(f32 *)((s8 *)arg0 + 0x494) = lbl_805D9898;
    *(f32 *)((s8 *)arg0 + 0x498) = lbl_805D9898;
    *(s32 *)((s8 *)arg0 + 0x49C) = 0;
    *(s32 *)((s8 *)arg0 + 0x4A0) = 0;
    ((void (*)(void *, void *))copy_vec4__13TRaderMapCoreFPv)(arg0 + 0x4A4, TObjEneMe1Canadin__map_core_default_vec4);
    *(f32 *)((s8 *)arg0 + 0x4A4) = lbl_805D9898;
    *(s32 *)((s8 *)arg0 + 0x4B8) = 0;
    *(s32 *)((s8 *)arg0 + 0x4B4) = 0;
    *(s32 *)((s8 *)arg0 + 0x4BC) = 0;
    *(s32 *)((s8 *)arg0 + 0x4C0) = 0;
    *(s32 *)((s8 *)arg0 + 0x4C4) = 0;
    copy_pos();
    set_part_position__9TObjEneDDFPvPvi(arg0, *(s32 *)((s8 *)arg0 + 0xA4), 0);
    *(s16 *)((s8 *)arg0 + 0x326) = 0;
    ((VObj_8009F004 *)arg0)->m85(*(s16 *)((s8 *)arg0 + 0x326), 4);
    if (*(void **)((s8 *)arg0 + 0x3C0) != NULL) {
        *(u16 *)((s8 *)arg0 + 0x4C8) = ((u16 (*)(void *))obj_getField1c)(*(void **)((s8 *)arg0 + 0x3C0));
    } else {
        *(u16 *)((s8 *)arg0 + 0x4C8) = 0xFFFF;
    }
}
extern int fold_flush_2;
#pragma pop

u8 *TObjEneMe1Canadin__ct(u8 *arg0, s32 arg1, u8 *arg2, s32 arg3, s16 arg4, s16 arg5) {
    ((TObjEneDD_ST *)arg0)->init_object();
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_8009F2E0___vt__17TObjEneMe1Canadin *)&__vt__17TObjEneMe1Canadin).value;
    ((TUnk_80494938 *)(arg0 + 0x3CC))->init_common();
    *(s32 *)((s8 *)arg0 + 0) = (s32) (*(s32 *)&TObjEneMe1Canadin__class_name);
    *(u8 **)((s8 *)arg0 + 0x3C0) = arg2;
    ((TObjEneDD *)arg0)->init_common_from((u8 *)(*(u8 **)((s8 *)arg0 + 0x3C0)));
    *(s16 *)((s8 *)arg0 + 0x1C) = arg4;
    *(s16 *)((s8 *)arg0 + 0x2C) = arg5;
    ((s32 (*)(void *, void *))calc_move_vector__17TObjEneMe1CanadinFiPv)((void *) (*(u8 **)((s8 *)arg0 + 0x3C0)), arg0 + 0x38);
    VecCopy((Vec *)(arg0 + 0x38), (const Vec *)(arg3));
    *(s32 *)((s8 *)arg0 + 0x60) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x3C0)) + 0x60);
    *(s32 *)((s8 *)arg0 + 0x3C8) = 0;
    *(s32 *)((s8 *)arg0 + 0x3C4) = 1;
    ((TObjEneMe1Canadin *)arg0)->setup_enemy();
    return arg0;
}

void *TObjEneMe1Canadin::init(void *arg1, void *arg2, void *arg3) {
    init_object();
    *(s32 **)((s8 *)this + 0x18) = __vt__17TObjEneMe1Canadin;
    ((TUnk_80494938 *)((char *)this + 972))->init_common();
    *(void **)((s8 *)this + 0x0) = TObjEneMe1Canadin__class_name;
    invoke_initialization_hook__9TObjEneDDFv(this, arg2);
    *(u32 *)((s8 *)this + 0x3C8) = 0;
    update_by_field_0x354();
    *(void **)((s8 *)this + 0x3C0) = this;
    *(void **)((s8 *)this + 0x3C4) = arg3;
    setup_enemy();
    return this;
}
}
void bringer_effect_cleanup_noop(void);
u8 * construct_bringer_rush_effect(u8 *arg0, s32 arg1, u8 *arg2, s32 arg3, f32 farg0);
u8 *construct_bringer_rush_effect(u8 *arg0, s32 arg1, u8 *arg2, s32 arg3, f32 farg0);
