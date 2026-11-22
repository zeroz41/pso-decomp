#include "pso/system/BmlResource.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/boss/goldragon/TBoss8Dragon_80065C90.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/map/CsnGroundQuery.h"
#include "pso/npc/NpcModelRegistry.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/unk/SampledMotionPoints.h"
#include "pso/enemy/dolmolm/TObjEneDolmOlm.h"
#include "pso/render/reflection.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/text_803D853C.h"
#pragma defer_codegen on

#include "types.h"
#include "pso/system/AreaSound.h"
#include "pso/enemy/TUnk_80493450.h"
#include "pso/object/base/TObjChara.h"
#include "pso/player/TObjPlayer.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/base/TObjMotion.h"

#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/unk/text_803D96A8.h"

#include "pso/system/vector.h"
#include "pso/enemy/recon/TObjEneRecon.h"
#include "pso/system/task/TObject.h"
#include "pso/effect/particle/TParticleCtrl.h"

#include "pso/render/TUnk_80494938.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/boss/volopt/TBoss3VoloptHiraisin.h"

struct Base_80301690_80300CE4 { char pad[0x18]; };
struct VObj_80301690_80300CE4 : Base_80301690_80300CE4 {
#define V(n) virtual void m##n();
    V(0)V(1)V(2)V(3)V(4)V(5)V(6)V(7)V(8)V(9)
    V(10)V(11)V(12)V(13)V(14)V(15)V(16)V(17)V(18)V(19)
    V(20)V(21)V(22)V(23)V(24)V(25)V(26)V(27)V(28)V(29)
    V(30)V(31)V(32)V(33)V(34)V(35)V(36)V(37)V(38)V(39)
    V(40)V(41)V(42)V(43)V(44)V(45)V(46)V(47)V(48)V(49)
    V(50)V(51)V(52)V(53)V(54)V(55)V(56)V(57)V(58)V(59)
    V(60)V(61)V(62)V(63)V(64)V(65)V(66)V(67)V(68)V(69)
    V(70)V(71)V(72)V(73)V(74)V(75)V(76)V(77)V(78)V(79)
    V(80)V(81)V(82)V(83)V(84)V(85)V(86)V(87)V(88)V(89)
    V(90)V(91)V(92)V(93)V(94)V(95)V(96)V(97)V(98)V(99)
    virtual void m100();
#undef V
};

#include <stddef.h>
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/enemy/beast/TObjEneBeast.h"
#include "pso/enemy/lappy/TObjEneLappy.h"
#include "pso/enemy/sinowzoa/TObjEneMe3SinowZoa.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/unk/TLobby.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/boss/volopt/TBoss3VoloptHiraisin.h"
#include "pso/effect/TUnk_80494968.h"
#include "pso/system/task/TMainTask.h"

struct RecoveredGlobal_80300FC0_lbl_8058D490 { s32 value; u8 remaining[0x2C]; };
LAYOUT_ASSERT(RecoveredGlobal_80300FC0_lbl_8058D490_size, sizeof(RecoveredGlobal_80300FC0_lbl_8058D490) == 0x30);

struct RecoveredGlobal_80301264_lbl_8058D490 { s32 value; u8 remaining[0x2C]; };

struct VBase_18_477421
{
  char pad[0x18];
};

struct VObj_18_477421 : VBase_18_477421 {
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
    virtual s32 m82();
    virtual s32 m83();
    virtual s32 m84();
    virtual s32 m85();
    virtual s32 m86();
    virtual s32 m87();
    virtual s32 m88();
    virtual s32 m89();
    virtual s32 m90();
    virtual void m91();
    virtual void m92();
    virtual void m93();
    virtual void m94();
    virtual void m95();
    virtual void m96();
    virtual void m97();
    virtual void m98();
    virtual s32 m99();
};

struct RecoveredFields_8030247C_arg0
{
  u8 unknown_0[0x2B4];
  f32 field_2B4;
  u8 unknown_2B8[0x6E];
  s16 field_326;
  u8 unknown_328[0xBC];
  s32 field_3E4;
};

struct E_80302D80 { s32 a; s32 b; s32 c; s32 d; };

struct G_80302D80 { u8 pad[0x42c]; E_80302D80 *e; };

struct O_80302D80 { u8 pad[0x24]; s32 f24; u8 pad2[0xc]; s32 f34; };

struct B14_80302004 { char pad[0x14]; };

struct V14_80302004 : B14_80302004 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual s32 m5();
};

struct Ene_80302004 {
    u8 pad0[0x38];
    u8 sub38[0x2ee];
    s16 s326;
    s16 s328;
    u8 pad1[0x390 - 0x32a];
    s32 f390;
    u8 pad2[0x3a8 - 0x394];
    V14_80302004 obj;
};

struct Ene_80302A34 { u8 pad0[0x18]; void *vt; u8 pad1[0x3a8 - 0x1c]; u8 sub[0x1c]; void *obj[2]; };

struct VBase_800A7A14 { char pad[0x18]; };

struct VObj_800A7A14 : VBase_800A7A14 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4(Vec *, Vec *);
};

typedef struct Obj_800A7A14 {
    u8 pad0[0x38];
    Vec pos;
    u8 pad44[0x60 - 0x44];
    s32 f60;
    u8 pad64[0xB8 - 0x64];
    s16 fB8;
    u8 padBA[0xC0 - 0xBA];
    f32 fC0;
    u8 padC4[0x3C4 - 0xC4];
    VObj_800A7A14 *effs[2];
} Obj_800A7A14;


struct O_80302D80;
struct E16_80301148 { u8 pad[8]; NJS_OBJECT *v; u8 pad2[4]; };

struct E8_80301148 { u8 pad[4]; NJS_MOTION *v; };

struct T_80301148 { u8 pad[0x42C]; E16_80301148 *a; E8_80301148 *b; };

struct VBase_14_fa0828 { char pad[0x14]; };
struct VObj_14_fa0828 : VBase_14_fa0828 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual s32 m3();
};
struct VSubBase_803021AC { char pad[0x14]; };

struct VSub_803021AC : VSubBase_803021AC {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual s32 m6();
    virtual s32 m7();
    virtual s32 m8();
    u8 rest[0x3c - 0x18];
};

struct Mesh_803021AC { u8 pad[6]; s16 flags; };

struct L3_803021AC { u8 pad[4]; Mesh_803021AC *mesh; };

struct L2_803021AC { u8 pad[4]; L3_803021AC *p; };

struct L1_803021AC { u8 pad[0x30]; L2_803021AC *p; };

struct Model_803021AC { u8 pad[0x2c]; L1_803021AC *p; };

struct EBase_803021AC { char pad[0x18]; };

struct Ene_803021AC : EBase_803021AC {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual s32 m9(f32, f32, f32);
    u8 pad1c[8];
    s32 f24;
    u8 pad28[8];
    u32 f30;
    Model_803021AC *model;
    u8 pos[0x60 - 0x38];
    s32 rotY;
    u8 pad64[0x326 - 0x64];
    s16 state;
    u8 pad328[0x380 - 0x328];
    f32 f380;
    u8 pad384[0x390 - 0x384];
    s32 f390;
    u8 pad394[0x3a8 - 0x394];
    VSub_803021AC sub;
    u32 f3e4;
};


struct Param_8030177C { u8 pad0[0x10]; f32 range; u8 pad14[0x18 - 0x14]; s32 angle; s32 power; };

struct Move_8030177C { u8 pad0[8]; s32 turn; };

struct Obj_8030177C {
    u8 pad0[0x30];
    u32 f30;
    u8 pad34[0x38 - 0x34];
    Vec pos;
    u8 pad44[0x60 - 0x44];
    s32 rotY;
    u8 pad64[0xB8 - 0x64];
    s16 fb8;
    u8 padBA[0xC4 - 0xBA];
    f32 fc4;
    f32 fc8;
    u8 padCC[0x2A8 - 0xCC];
    Obj_8030177C *target;
    u8 pad2AC[0x2FC - 0x2AC];
    Vec f2fc;
    u8 pad308[0x326 - 0x308];
    s16 f326;
    s16 f328;
    u8 pad32A[0x338 - 0x32A];
    u16 f338;
    u8 pad33A[0x350 - 0x33A];
    Move_8030177C *move;
    u8 pad354[0x368 - 0x354];
    s32 kind;
};

struct VBase_18_cc39a7 { char pad[0x18]; };
struct VObj_18_cc39a7 : VBase_18_cc39a7 {
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
    virtual s32 m17(s32);
};


struct Row_80302784 { u8 pad[0xC]; f32 fC; u8 pad2[0x1C]; };

struct Ent_80302784 { s32 f0; s32 f4; NJS_OBJECT *f8; NJS_TEXLIST *texlist; };

struct Pair_80302784 { s32 a; NJS_MOTION *b; };

struct Res_80302784 { u8 pad[0x42C]; Ent_80302784 *x42C; Pair_80302784 *x430; };

extern "C" {
s32 TObjEneDolmOlm__sub_80300CF0(void);
extern s32 TObjEneDolmOlm__effect_render_state;
s32 play_sound_effect(s32, void *, int, int);
void TObjPlayer__sub_800D92BC(s32 point, s32 delay);
f32 vec3_add_to(void *, void *);
s32 rotate_vector_by_matrix(int, void *, void *);
extern RecoveredGlobal_80300FC0_lbl_8058D490 identity_matrix;
s32 check_path_obstructed(void *, void *);
void check_path_ahead__14TObjEneDolmOlmFlf(u8 *arg0, s32 arg1, f32 farg0);
s32 submit_cursor_candidate(void *, int);
extern uaddr TObjEneDolmOlm__resource_bundle;
void __dt__13TUnk_80494938Fv(void *, int);
void free_collision_body_parts(void *);
void set_matrix_identity(u8 *arg0);
s32 post_translate_matrix(void *);
extern uaddr TObjEneDolmOlm__data_805D6A14;
extern uaddr TObjEneDolmOlm__data_805D6A18;
void fn_800D88E4(void *);
extern s32 actor_frame_tick;
void spawn_ground_effects__14TObjEneDolmOlmFPvPv(u8 *arg0, Vec *arg1);
s32 obj_setFlags30(void *, s32);
s32 get_current_floor();
f32 fabs_float(f32);
u8 *get_enemy_entity(u16 arg0);
f32 horizontal_distance_squared(void *, void *);
void *get_player_by_client_id(s32 i);
extern uaddr TObjEneDolmOlm__behavior_params_by_variant;
s32 is_split_screen();
s32 restore_scene_lighting();
s32 select_actor_lighting(void *);
s32 translate_matrix(int, f32, f32, f32);
}
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;
void apply_actor_gravity(TObjEnemy *enemy, s32 *arg1, f32 farg0);
extern "C" {
s32 get_entity_id(void *);
f32 atan2_float(f32 y, f32 x);
s32 angle_difference_abs(s32, s32);
s32 minimap_render_dot(void *, int, int, int);
void subtract_vector(void *, void *);
extern const f64 lbl_804750C8[];
}
struct Elem_80301C3C { u8 pad[0xC]; f32 r; u8 pad2[0x1C]; };
struct Tgt_80301C3C { u8 pad[0xA4]; Elem_80301C3C *arr; s32 count; };
void move_with_wall_slide(u8 *arg0);
void enemy_set_heading_velocity(f32 speed, TObjEnemy *enemy, s32 heading);
extern "C" {
s32 select_enemy_destination(void *, void *, int);
s32 copy_position_if_valid__10TObjPlayerFii(void *, void *);
extern uaddr dolm_olm_combat_stat_id_pair;
extern uaddr TObjEneDolmOlm__shared_handler_ids;
extern uaddr TObjEneDolmOlm__registered_object_ids;
extern void *lbl_804E67B8[4];
extern void *lbl_804E6774[4];
extern s32 TObjEneDolmOlm__param_table[52];
extern s32 lbl_804E68D0[22];
void * TObjEneDolmOlm__create(void *arg0);
void *__ct__11TObjControlFP7TObject(void *, void *);
u8 *__ct__14TObjEneDolmOlmFll(u8 *, s32, s32);
void mem_free(void*);
s32 init_collision_body_parts(void *, void *, int);
extern const char *obj_ene_dolm_olm_class_name;
extern "C" {
extern const u8 lbl_80474F08[];
}
extern "C" {
extern const u8 dolmolm_model_name_abgc01l_wola_body_nj[];
}
extern "C" {
extern const u8 dolmolm_motion_name_atack_l_abgc01_wola_body_njm[];
}
extern "C" {
extern const u8 dolmolm_motion_name_atack_r_abgc01_wola_body_njm[];
}
extern "C" {
extern const u8 dolmolm_motion_name_damage_abgc01_wola_body_njm[];
}
extern "C" {
extern const u8 dolmolm_motion_name_dead_abgc01_wola_body_njm[];
}
extern "C" {
extern const u8 dolmolm_motion_name_odori_abgc01_wola_body_njm[];
}
extern "C" {
extern const u8 dolmolm_motion_name_wait_abgc01_wola_body_njm[];
}
extern "C" {
extern const u8 dolmolm_motion_name_wait2_abgc01_wola_body_njm[];
}
extern "C" {
extern const u8 dolmolm_motion_name_wake_abgc01_wola_body_njm[];
}
extern "C" {
extern const u8 dolmolm_motion_name_walk_abgc01_wola_body_njm[];
}
extern "C" {
extern const u8 bm_ene_abgc01_wola_body_bml_filename[];
}
extern "C" {
extern const u8 dolmolm_model_name_lo_abgc01_wola_body_nj[];
}
extern "C" {
extern const u8 dolmolm_model_name_lo_abgc01l_wola_body_nj[];
}
extern "C" {
extern const u8 bm_ene_abgc01_wola_body_low_bml_filename[];
}
void *lbl_804E6740[3] = {
    (void *)&lbl_80474F08, (void *)&dolmolm_model_name_abgc01l_wola_body_nj, (void *)0x0,
};
void *lbl_804E674C[10] = {
    (void *)&dolmolm_motion_name_atack_l_abgc01_wola_body_njm, (void *)&dolmolm_motion_name_atack_r_abgc01_wola_body_njm, (void *)&dolmolm_motion_name_damage_abgc01_wola_body_njm, (void *)&dolmolm_motion_name_dead_abgc01_wola_body_njm,
    (void *)&dolmolm_motion_name_odori_abgc01_wola_body_njm, (void *)&dolmolm_motion_name_wait_abgc01_wola_body_njm, (void *)&dolmolm_motion_name_wait2_abgc01_wola_body_njm, (void *)&dolmolm_motion_name_wake_abgc01_wola_body_njm,
    (void *)&dolmolm_motion_name_walk_abgc01_wola_body_njm, (void *)0x0,
};
void *lbl_804E6774[4] = {
    (void *)&bm_ene_abgc01_wola_body_bml_filename, (void *)&lbl_804E6740, (void *)&lbl_804E674C, (void *)0x20009,
};
void *lbl_804E6784[3] = {
    (void *)&dolmolm_model_name_lo_abgc01_wola_body_nj, (void *)&dolmolm_model_name_lo_abgc01l_wola_body_nj, (void *)0x0,
};
void *lbl_804E6790[10] = {
    (void *)&dolmolm_motion_name_atack_l_abgc01_wola_body_njm, (void *)&dolmolm_motion_name_atack_r_abgc01_wola_body_njm, (void *)&dolmolm_motion_name_damage_abgc01_wola_body_njm, (void *)&dolmolm_motion_name_dead_abgc01_wola_body_njm,
    (void *)&dolmolm_motion_name_odori_abgc01_wola_body_njm, (void *)&dolmolm_motion_name_wait_abgc01_wola_body_njm, (void *)&dolmolm_motion_name_wait2_abgc01_wola_body_njm, (void *)&dolmolm_motion_name_wake_abgc01_wola_body_njm,
    (void *)&dolmolm_motion_name_walk_abgc01_wola_body_njm, (void *)0x0,
};
void *lbl_804E67B8[4] = {
    (void *)&bm_ene_abgc01_wola_body_low_bml_filename, (void *)&lbl_804E6784, (void *)&lbl_804E6790, (void *)0x20009,
};
s32 TObjEneDolmOlm__param_table[52] = {
    0x10000, 0x5, 0x3f4ccccd, 0x1,
    0x10000, 0x6, 0x3f19999a, 0x20,
    0x10002, 0x8, 0x3f4ccccd, 0x1,
    0x20000, 0x0, 0x3f4ccccd, 0x4,
    0x20000, 0x1, 0x3f4ccccd, 0x4,
    0x10000, 0x8, 0x3f4ccccd, 0x1,
    0x20000, 0x2, 0x3f4ccccd, 0x8,
    0x20000, 0x7, 0x3f4ccccd, 0x20,
    0x30000, 0x3, 0x3f333333, 0x10,
    0x30000, 0x3, 0x3f333333, 0x10,
    0x20000, 0x5, 0x3f4ccccd, 0x20,
    0x10000, 0x5, 0x3f4ccccd, 0x20,
    0x20000, 0x4, 0x3f4ccccd, 0x4,
};
s32 lbl_804E6898[14] = {
    0x43610000, 0x3f400000, 0x400, 0x0,
    0x1e0000, 0x1, 0x0, 0x43960000,
    0x3f800000, 0x400, 0x0, 0x1e0000,
    0x1, 0x0,
};
s32 lbl_804E68D0[22] = {
    0x0, 0x41480000, 0x0, 0x41000000,
    0x0, 0x0, 0x8003, 0x0,
    0x0, 0x0, 0x0, 0x0,
    0x41480000, 0x0, 0x41000000, 0x0,
    0x0, 0x8003, 0x0, 0x0,
    0x0, 0x0,
};

    extern int lbl_805D69E8;


typedef struct RecoveredFields_8030247C_arg0 RecoveredFields_8030247C_arg0;
typedef struct VBase_18_477421 VBase_18_477421;
typedef struct VObj_18_477421 VObj_18_477421;

u8 *__ct__14TObjEneDolmOlmFll(u8 *arg0, s32 arg1, s32 arg2);

extern const u8 lbl_80474F08[0x14];
__declspec(section ".rodata") const u8 lbl_80474F08[0x14] ATTRIBUTE_ALIGN(4) = "abgc01_wola_body.nj";
extern const u8 dolmolm_model_name_abgc01l_wola_body_nj[0x15];
__declspec(section ".rodata") const u8 dolmolm_model_name_abgc01l_wola_body_nj[0x15] ATTRIBUTE_ALIGN(4) = "abgc01l_wola_body.nj";
extern const u8 dolmolm_motion_name_atack_l_abgc01_wola_body_njm[0x1D];
__declspec(section ".rodata") const u8 dolmolm_motion_name_atack_l_abgc01_wola_body_njm[0x1D] ATTRIBUTE_ALIGN(4) = "atack_l_abgc01_wola_body.njm";
extern const u8 dolmolm_motion_name_atack_r_abgc01_wola_body_njm[0x1D];
__declspec(section ".rodata") const u8 dolmolm_motion_name_atack_r_abgc01_wola_body_njm[0x1D] ATTRIBUTE_ALIGN(4) = "atack_r_abgc01_wola_body.njm";
extern const u8 dolmolm_motion_name_damage_abgc01_wola_body_njm[0x1C];
__declspec(section ".rodata") const u8 dolmolm_motion_name_damage_abgc01_wola_body_njm[0x1C] ATTRIBUTE_ALIGN(4) = "damage_abgc01_wola_body.njm";
extern const u8 dolmolm_motion_name_dead_abgc01_wola_body_njm[0x1A];
__declspec(section ".rodata") const u8 dolmolm_motion_name_dead_abgc01_wola_body_njm[0x1A] ATTRIBUTE_ALIGN(4) = "dead_abgc01_wola_body.njm";
extern const u8 dolmolm_motion_name_odori_abgc01_wola_body_njm[0x1B];
__declspec(section ".rodata") const u8 dolmolm_motion_name_odori_abgc01_wola_body_njm[0x1B] ATTRIBUTE_ALIGN(4) = "odori_abgc01_wola_body.njm";
extern const u8 dolmolm_motion_name_wait_abgc01_wola_body_njm[0x1A];
__declspec(section ".rodata") const u8 dolmolm_motion_name_wait_abgc01_wola_body_njm[0x1A] ATTRIBUTE_ALIGN(4) = "wait_abgc01_wola_body.njm";
extern const u8 dolmolm_motion_name_wait2_abgc01_wola_body_njm[0x1B];
__declspec(section ".rodata") const u8 dolmolm_motion_name_wait2_abgc01_wola_body_njm[0x1B] ATTRIBUTE_ALIGN(4) = "wait2_abgc01_wola_body.njm";
extern const u8 dolmolm_motion_name_wake_abgc01_wola_body_njm[0x1A];
__declspec(section ".rodata") const u8 dolmolm_motion_name_wake_abgc01_wola_body_njm[0x1A] ATTRIBUTE_ALIGN(4) = "wake_abgc01_wola_body.njm";
extern const u8 dolmolm_motion_name_walk_abgc01_wola_body_njm[0x1A];
__declspec(section ".rodata") const u8 dolmolm_motion_name_walk_abgc01_wola_body_njm[0x1A] ATTRIBUTE_ALIGN(4) = "walk_abgc01_wola_body.njm";
extern const u8 bm_ene_abgc01_wola_body_bml_filename[0x1C];
__declspec(section ".rodata") const u8 bm_ene_abgc01_wola_body_bml_filename[0x1C] ATTRIBUTE_ALIGN(4) = "bm_ene_abgc01_wola_body.bml";
extern const u8 dolmolm_model_name_lo_abgc01_wola_body_nj[0x17];
__declspec(section ".rodata") const u8 dolmolm_model_name_lo_abgc01_wola_body_nj[0x17] ATTRIBUTE_ALIGN(4) = "lo_abgc01_wola_body.nj";
extern const u8 dolmolm_model_name_lo_abgc01l_wola_body_nj[0x18];
__declspec(section ".rodata") const u8 dolmolm_model_name_lo_abgc01l_wola_body_nj[0x18] ATTRIBUTE_ALIGN(4) = "lo_abgc01l_wola_body.nj";
extern const u8 bm_ene_abgc01_wola_body_low_bml_filename[0x20];
__declspec(section ".rodata") const u8 bm_ene_abgc01_wola_body_low_bml_filename[0x20] ATTRIBUTE_ALIGN(4) = "bm_ene_abgc01_wola_body_low.bml";
extern const char TObjEneDolmOlm__class_name_string[0xF];
__declspec(section ".rodata") const char TObjEneDolmOlm__class_name_string[0xF] ATTRIBUTE_ALIGN(4) = "TObjEneDolmOlm";
}

void TObjEneDolmOlm::load_params_from_table(s32 i) {
    O_80302D80 *self = (O_80302D80 *)this;
    self->f34 = (*(G_80302D80 * *)&TObjEneDolmOlm__resource_bundle)->e[i].c;
    self->f24 = (*(G_80302D80 * *)&TObjEneDolmOlm__resource_bundle)->e[i].d;
}
int initialize_enemy_photon_effect(void *p);
TObjEneDolmOlm::TObjEneDolmOlm(saddr parent, saddr arg2) : TUnk_80493450((TObject *)parent) {
    u32 col;
    __ct__13TUnk_80494938Fv((((u8 *)this) + 0x3A8));
    m_name = obj_ene_dolm_olm_class_name;
    this->apply_set_data((void *)arg2);
    ((TObjPlayer *)this)->init_position_vectors();
    this->sub_80301148();
    *(void * *)&this->action_table = TObjEneDolmOlm__param_table;
    this->set_field_d8((saddr)(*(void * *)&this->action_table));
    *(s32 *)((s8 *)this + 0xDC) = *(s32 *)((s8 *)TObjEneDolmOlm__resource_bundle + 0x430);
    this->requested_action = 0;
    this->set_animation(this->requested_action);
    this->set_field_b8(this->requested_action);
    init_collision_body_parts(this, (u8 *) lbl_804E68D0 + *(s32 *)&this->variant * 0x2C, 1);
    this->bind_enemy_combat_stats((u8 *)(((saddr *) dolm_olm_combat_stat_id_pair)[*(s32 *)&this->variant]), (u8 *)(((saddr *) TObjEneDolmOlm__shared_handler_ids)[*(s32 *)&this->variant]), (u8 *)(((saddr *) TObjEneDolmOlm__registered_object_ids)[*(s32 *)&this->variant]));
    *(u8 * *)&this->movementParameters = (u8 *) lbl_804E6898 + *(s32 *)&this->variant * 0x1C;
    this->referenceHp = this->hp;
    this->advance_position();
    ((TBoss3VoloptHiraisin *)this)->copy_position();
    initialize_enemy_photon_effect(this);
    *(s32 *)&this->m_2ac = 182.04445f * (360.0f * ((TObjChara *)this)->random_ratio());
    *(s16 *)&this->resetTimer = 0xF;
    *(s16 *)&this->timer = *(s16 *)&this->resetTimer;
    this->phase = 0;
    this->m_374 = 0;
    *(s16 *)&this->m_376 = 0;
    *(s32 *)&this->m_3e4 = 0;
    VecCopy((Vec *)(((u8 *)this) + 0x3D8), (const Vec *)(((u8 *)this) + 0x38));
    *(s32 *)&this->m_378 = 0;
    *(s32 *)&this->m_37c = 0;
    this->add_flags_2e4(2);
    this->actorFlags |= 0x40000;
    switch (*(s32 *)&this->variant) {
    default:
        col = 0xFFDE20BD;
        break;
    case 1:
        col = 0xFFCDDE62;
        break;
    }
    ((VObj_14_fa0828 *) (((u8 *)this) + 0x3A8))->m3();
    this->m_390 = 1;
    *(s32 *)&this->m_3c4 = (saddr)TUnk_80494968::create(0xA0303030, col);
    *(s32 *)&this->m_3c8 = (saddr)TUnk_80494968::create(0xA0303030, col);
    *(f32 *)&this->m_398 = ((f32 **) TObjEneDolmOlm__behavior_params_by_variant)[*(s32 *)&this->variant][0];
    *(f32 *)&this->m_3a0 = ((f32 **) TObjEneDolmOlm__behavior_params_by_variant)[*(s32 *)&this->variant][1];
    *(f32 *)((s8 *)this + 0x39C) = ((f32 **) TObjEneDolmOlm__behavior_params_by_variant)[*(s32 *)&this->variant][2];
    *(f32 *)((s8 *)this + 0x3A4) = ((f32 **) TObjEneDolmOlm__behavior_params_by_variant)[*(s32 *)&this->variant][3];
    this->requested_action = 1;
    *(f32 *)((s8 *)this + 0x3D4) = 0.0f;
    this->sub_8002AE64();
    this->clear_lobby_object_state();
}
TObjEneDolmOlm::~TObjEneDolmOlm() {
    s32 i;
    for (i = 0; i < 2; i++) {
        if (((Ene_80302A34 *)this)->obj[i] != NULL) {
            ((TObject *)(((Ene_80302A34 *)this)->obj[i]))->queue_destruction();
            ((Ene_80302A34 *)this)->obj[i] = 0;
        }
    }
    ((TUnk_80493450 *)this)->unlink_enemy_group_relations();
    free_collision_body_parts(((Ene_80302A34 *)this));
    __dt__13TUnk_80494938Fv(((Ene_80302A34 *)this)->sub, -1);
}

void TObjEneDolmOlm::load_shared_resources() {
    u8 *p;
    s32 i;
    if (is_split_screen() != 0) {
        p = (u8 *)new BmlResource(1, (BmlResourceDescriptor *)lbl_804E67B8, 0, 0, NULL);
        TObjEneDolmOlm__resource_bundle = (uaddr) p;
    } else {
        p = (u8 *)new BmlResource(1, (BmlResourceDescriptor *)lbl_804E6774, 0, 0, NULL);
        TObjEneDolmOlm__resource_bundle = (uaddr) p;
    }
    p = (u8 *)new SampledMotionPoints(2, 0.0f, 20.0f, 0.8f);
    TObjEneDolmOlm__data_805D6A14 = (uaddr) p;
    p = (u8 *)new SampledMotionPoints(2, 0.0f, 20.0f, 0.8f);
    TObjEneDolmOlm__data_805D6A18 = (uaddr) p;
    set_motion_packed_rotation();
    ((SampledMotionPoints *)TObjEneDolmOlm__data_805D6A14)->sample_two_nodes(((Res_80302784 *)TObjEneDolmOlm__resource_bundle)->x42C->f8, ((Res_80302784 *)TObjEneDolmOlm__resource_bundle)->x430[((s32 *) TObjEneDolmOlm__param_table)[13]].b, 0x1C, 0x1D);
    ((SampledMotionPoints *)TObjEneDolmOlm__data_805D6A18)->sample_two_nodes(((Res_80302784 *)TObjEneDolmOlm__resource_bundle)->x42C->f8, ((Res_80302784 *)TObjEneDolmOlm__resource_bundle)->x430[((s32 *) TObjEneDolmOlm__param_table)[17]].b, 0x14, 0x15);
    clear_motion_packed_rotation();
    dolm_olm_combat_stat_id_pair = (uaddr) mem_alloc(8);
    TObjEneDolmOlm__shared_handler_ids = (uaddr) mem_alloc(8);
    TObjEneDolmOlm__registered_object_ids = (uaddr) mem_alloc(8);
    TObjEneDolmOlm__behavior_params_by_variant = (uaddr) mem_alloc(8);
    ((s32 *) dolm_olm_combat_stat_id_pair)[0] = (saddr)TLobby::register_boss(0x4F);
    ((s32 *) dolm_olm_combat_stat_id_pair)[1] = (saddr)TLobby::register_boss(0x50);
    ((s32 *) TObjEneDolmOlm__shared_handler_ids)[0] = (saddr)TLobby::dispatch_shared_handler_b(0x54);
    ((s32 *) TObjEneDolmOlm__shared_handler_ids)[1] = (saddr)TLobby::dispatch_shared_handler_b(0x55);
    ((s32 *) TObjEneDolmOlm__registered_object_ids)[0] = (saddr)TLobby::register_object(0x4E);
    ((s32 *) TObjEneDolmOlm__registered_object_ids)[1] = (saddr)TLobby::register_object(0x4F);
    ((s32 *) TObjEneDolmOlm__behavior_params_by_variant)[0] = (saddr)TLobby::dispatch_shared_handler_a(0x4E);
    ((s32 *) TObjEneDolmOlm__behavior_params_by_variant)[1] = (saddr)TLobby::dispatch_shared_handler_a(0x4F);
    TObjEneDolmOlm__effect_render_state = 0;
    {
        s16 ids[2] = { 69, 79 };
        NpcAnimationBinding d = { reinterpret_cast<BmlMotionEntry *>(*(s32 *)((s8 *)TObjEneDolmOlm__resource_bundle + 0x430)), reinterpret_cast<TObjMotionAction *>(TObjEneDolmOlm__param_table), 0, 2, 12 };
        for (i = 0; i < 2; i++) {
            Ent_80302784 *e = &(*(Ent_80302784 **)((s8 *)TObjEneDolmOlm__resource_bundle + 0x42C))[i];
            NpcModelRegistry::register_animated_chunk(ids[i], reinterpret_cast<void *>(e->f8), reinterpret_cast<void *>(e->texlist), &d, ((Row_80302784 *) lbl_804E68D0)[i].fC, 0.0f);
        }
    }
}
void TObjEneDolmOlm::free_shared_resources() {
    if ((u32) dolm_olm_combat_stat_id_pair != 0U) {
        mem_free((void*)dolm_olm_combat_stat_id_pair);
        dolm_olm_combat_stat_id_pair = 0U;
    }
    if ((u32) TObjEneDolmOlm__shared_handler_ids != 0U) {
        mem_free((void*)TObjEneDolmOlm__shared_handler_ids);
        TObjEneDolmOlm__shared_handler_ids = 0U;
    }
    if ((u32) TObjEneDolmOlm__registered_object_ids != 0U) {
        mem_free((void*)TObjEneDolmOlm__registered_object_ids);
        TObjEneDolmOlm__registered_object_ids = 0U;
    }
    if ((u32) TObjEneDolmOlm__behavior_params_by_variant != 0U) {
        mem_free((void*)TObjEneDolmOlm__behavior_params_by_variant);
        TObjEneDolmOlm__behavior_params_by_variant = 0U;
    }
    if ((u32) TObjEneDolmOlm__data_805D6A18 != 0U) {
        delete (SampledMotionPoints *)TObjEneDolmOlm__data_805D6A18;
        TObjEneDolmOlm__data_805D6A18 = 0U;
    }
    if ((u32) TObjEneDolmOlm__data_805D6A14 != 0U) {
        delete (SampledMotionPoints *)TObjEneDolmOlm__data_805D6A14;
        TObjEneDolmOlm__data_805D6A14 = 0U;
    }
    if ((u32) TObjEneDolmOlm__resource_bundle != 0U) {
        delete (BmlResource *)TObjEneDolmOlm__resource_bundle;
        TObjEneDolmOlm__resource_bundle = 0U;
    }
}
void * TObjEneDolmOlm__create(void *arg0) {
    void *o;
    void *o2;
    o = TObject::operator new(0x20);
    if (o != NULL) {
        o = __ct__11TObjControlFP7TObject(o, tl_04);
    }
    o2 = TObject::operator new(0x3E8);
    if (o2 != NULL) {
        o2 = ((void *(*)(void *, void *, void *))__ct__14TObjEneDolmOlmFll)(o2, o, arg0);
    }
    return o2;
}
void TObjEneDolmOlm::run_task() {
  s16 temp_r0;
  if (TObjPlayer::check_demo_mode() == 1)
  {
    (this->run_demo_task());
    return;
  }
  temp_r0 = ((RecoveredFields_8030247C_arg0 *) ((u8 *)this))->field_326;
  {
    switch (temp_r0)
    {
      case 0:
        (this->beast_update_appear());
        break;
      case 1:
        (this->beast_idle_update());
        break;
      case 2:
        (this->update_turn_toward_target());
        break;
      case 3:
        (this->beast_update_approach());
        this->init_body_sub();
        break;
      case 4:
        (this->beast_update_group_chase());
        this->init_body_sub();
        break;
      case 5:
        (this->beast_update_attack());
        break;
      case 6:
        (this->vfunc_89());
        break;
      case 7:
        (this->beast_update_hurt());
        break;
      case 8:
        (this->beast_update_dead());
        break;
      case 9:
        (this->beast_retire_corpse());
        break;
      case 10:
        TObjEneDolmOlm__sub_80301C3C((void *) ((u8 *)this));
        this->init_body_sub();
        break;
      case 11:
        TObjEneDolmOlm__sub_8030177C((void *)this);
        this->init_body_sub();
        break;
    }
  }
  this->advance_position();
  ((TBoss3VoloptHiraisin *)this)->copy_position();
  submit_cursor_candidate((void *) this, -1);
  if (((RecoveredFields_8030247C_arg0 *) ((u8 *)this))->field_3E4 & 0x4000)
  {
    request_reflection_render();
  }
  ((RecoveredFields_8030247C_arg0 *) ((u8 *)this))->field_2B4 += 1.0f;
}
void TObjEneDolmOlm::render() {
    s32 vis;
    s16 saved;
    Ene_803021AC *self = (Ene_803021AC *)this;
    if (self->f30 & 0x02000000) {
        return;
    }
    if (is_split_screen() != 0) {
        TCameraCtrl::get_camera_mode();
    }
    vis = self->m9(200.0f, 400.0f, 30.0f);
    if (vis != 0 && ((TObjEneDolmOlm *)self)->render_model_if_visible() == 0) {
    select_actor_lighting(self);
    model_render_flags |= 1;
    TObjFish::set_global_param(self->f24);
    push_matrix();
    translate_matrix(0, 0.0f, self->f380, 0.0f);
    post_translate_matrix(self->pos);
    rotate_matrix_y(0, self->rotY);
    if (TObjPlayer::check_demo_mode() == 1) {
        draw_chunk_object(self->model);
    } else {
        switch (self->state) {
        case 0:
        case 1:
        case 8:
        case 9: {
            s16 t;
            Mesh_803021AC *m = self->model->p->p->p->mesh;
            t = m->flags;
            saved = t;
            m->flags = (u8)t;
            break;
        }
        }
        TObjPlayer::toggle_particle_effect();
        TObjEneDolmOlm__effect_render_state = 0;
        set_chunk_model_node_callback(TObjEneDolmOlm::toggle_effect_render);
        if (self->f390 == 1) {
            if (self->sub.m8() != 0) {
                saved_model_render_flags = model_render_flags;
                saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
                saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
                self->sub.m6();
                if (((TObject *)self)->defer_render() == 0) {
                    model_render_flags |= 1;
                    ((TObjMotion *)self)->draw();
                    model_render_flags &= ~1;
                }
                self->sub.m7();
                chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
                chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
                model_render_flags = saved_model_render_flags;
            }
        } else if (vis == 1) {
            ((TObjMotion *)self)->draw();
        } else {
            ((TObjEnemy *)self)->draw_motion_model();
        }
        set_chunk_model_node_callback(NULL);
        TParticleCtrl::end_effect_render();
        switch (self->state) {
        case 0:
        case 1:
        case 8:
        case 9:
            self->model->p->p->p->mesh->flags = saved;
            break;
        }
    }
    pop_matrix();
    model_render_flags &= ~1;
    restore_scene_lighting();
    switch (self->state) {
    case 0:
    case 1:
    case 8:
    case 9:
        break;
    default:
        if (!(self->f3e4 & 0x4000)) {
            Vec v;
            v.x = 1.5f;
            v.y = 1.0f;
            v.z = 2.0f;
            ((TObjEnemy *)self)->draw_ground_shadow(&v, 0);
        }
        break;
    }
    }
}
s32 TObjEneDolmOlm::render_model_if_visible() {
    if ((s32)main_task.get_task_flags() & 0x20) {
        if (push_reflection_matrix((Vec *)(((u8 *)this) + 0x3D8)) != 0) {
            TObjFish::set_global_param(this->texlist);
            push_matrix();
            post_translate_matrix((void *) (((u8 *)this) + 0x38));
            rotate_matrix_y(0, this->rotation_y);
            this->draw();
            pop_matrix();
            restore_render_scissor(1);
        }
        return 1;
    }
    return 0;
}
void TObjEneDolmOlm::toggle_effect_render(NJS_OBJECT *) {
    switch (TObjEneDolmOlm__effect_render_state) {
    case 0x15:
    case 0x1d:
    case 0x49:
        TParticleCtrl::begin_effect_render();
        break;
    default:
        TParticleCtrl::end_effect_render();
        break;
    }
    TObjEneDolmOlm__effect_render_state += 1;
}
void TObjEneDolmOlm::beast_update_appear() {
    Ene_80302004 *self = (Ene_80302004 *)this;
    advance_animation();
    switch (this->phase) {
    case 0:
    default:
        if (this->m_390 != 0) {
            ((TUnk_80494938 *)(&self->obj))->start_fade_in();
            play_area_sound_effect((Vec *)(self->sub38));
            this->phase = 1;
            return;
        }
        this->phase = 2;
        return;
    case 1:
        if (self->obj.m5() == 1) {
            this->phase = 2;
            this->m_390 = 0;
        }
        break;
    case 2:
        this->mode = 1;
        this->phase = 0;
        break;
    }
}
void TObjEneDolmOlm::select_post_attack_mode() {
    if (((TObjChara *)this)->random_ratio() < *(f32 *)((s8 *)this + 0x3CC)) {
        this->mode = 0xA;
        this->phase = 0;
    }
}
#pragma push
#pragma opt_common_subs off
#define arg0 ((u8 *)arg0_)
void TObjEneDolmOlm__sub_80301C3C(void *arg0_) {
    Vec v;
    f32 f;

    switch (*(s16 *)((s8 *)arg0 + 0x328)) {
    case 0:
        apply_actor_gravity((TObjEnemy *)arg0, (s32 *)(0), 0.0f);
        ((TObjMotion *)arg0)->advance_animation();
        *(s16 *)((s8 *)arg0 + 0x328) = 1;
        *(s16 *)((s8 *)arg0 + 0xB8) = 2;
        *(f32 *)((s8 *)arg0 + 0x3D4) = 0.0f;
        *(f32 *)((s8 *)arg0 + 0xC8) *= 2.0f;
        break;
    default:
    case 1:
        if (*(u8 **)((s8 *)arg0 + 0x2A8) != NULL) {
            if (((TUnk_80493450 *)arg0)->test_elt_flag(0, 0x300000) != 0) {
                if ((f32) (*(u32 *)((s8 *)arg0 + 0x38C))++ < 60.0f) {
                    VecCopy((Vec *)&v, (const Vec *)(arg0 + 0x50));
                } else {
                    VecCopy((Vec *)&v, (const Vec *)(*(u8 **)((s8 *)arg0 + 0x2A8) + 0x2FC));
                }
            } else {
                *(u32 *)((s8 *)arg0 + 0x38C) = 0;
                VecCopy((Vec *)&v, (const Vec *)(*(u8 **)((s8 *)arg0 + 0x2A8) + 0x2FC));
            }
            ((TObjMotion *)arg0)->advance_animation();
            play_sound_effect(((TObjEnemy *)(arg0))->remap_sound_for_area(0x4003B205), arg0 + 0x38, 0, 0);
            if (horizontal_distance_squared(arg0 + 0x29C, arg0 + 0x38) < 0.00001f || ((VObj_18_cc39a7 *)(arg0))->m17(0x1E) != 0) {
                Vec a = v;
                if (select_enemy_destination(arg0, &a, 1) != 0) {
                    Vec b = *(Vec *)(arg0 + 0x2FC);
                    copy_position_if_valid__10TObjPlayerFii(arg0, &b);
                }
            }
            f = 4.0f * *(f32 *)((s8 *)arg0 + 0x394);
            if (((s32 (*)(u8 *, s32, f32))check_path_ahead__14TObjEneDolmOlmFlf)(arg0, *(s32 *)((s8 *)arg0 + 0x60) + 0x8000, f) == 0) {
                ((TObjEnemy *)arg0)->enemy_turn_toward_dest(*(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x350)) + 8));
                enemy_set_heading_velocity(f, (TObjEnemy *)(arg0), *(s32 *)((s8 *)arg0 + 0x60) + 0x8000);
                move_with_wall_slide(arg0);
                *(f32 *)((s8 *)arg0 + 0x3D4) += f;
                if (*(f32 *)((s8 *)arg0 + 0x3D4) >= 50.0f) {
                    *(s16 *)((s8 *)arg0 + 0x328) = 2;
                }
                f32 d = horizontal_distance_squared(*(u8 **)((s8 *)arg0 + 0x2A8) + 0x2FC, arg0 + 0x38);
                for (s32 i = 0; i < (*(Tgt_80301C3C **)((s8 *)arg0 + 0x2A8))->count; i++) {
                    if (d > ((*(Tgt_80301C3C **)((s8 *)arg0 + 0x2A8))->arr[i].r + ((TObjChara *)arg0)->get_attack_range()) * ((*(Tgt_80301C3C **)((s8 *)arg0 + 0x2A8))->arr[i].r + ((TObjChara *)arg0)->get_attack_range())) {
                        *(s16 *)((s8 *)arg0 + 0x328) = 2;
                        break;
                    }
                }
            } else {
                *(s16 *)((s8 *)arg0 + 0x328) = 2;
            }
        } else {
            *(s16 *)((s8 *)arg0 + 0x328) = 2;
        }
        break;
    case 2:
        *(s16 *)((s8 *)arg0 + 0x326) = 3;
        *(s16 *)((s8 *)arg0 + 0xB8) = 2;
        ((TObjBase *)arg0)->obj_clearFlags30(0x04040000);
        ((TObjCollidable *)arg0)->clear_player_status_flag(0, 0x0A000000);
        ((TUnk_80493450 *)arg0)->update_target_near_flag();
        ((TUnk_80493450 *)arg0)->sub_800C4E08();
        break;
    }
    ((TObjPlayer *)arg0)->update_collisions();
    minimap_render_dot(arg0 + 0x38, -0x5DB4, 1, 0);
    ((TObjBase *)arg0)->obj_clearFlags30(0x200000);
}
#undef arg0
#pragma pop
#pragma push
#pragma opt_common_subs off
#define arg0 ((Obj_8030177C *)arg0_)
void TObjEneDolmOlm__sub_8030177C(void *arg0_) {
    if (arg0->f338 < 0x1000) {
        Obj_8030177C *tgt = (Obj_8030177C *)get_player_by_client_id(arg0->f338);
        f32 d = horizontal_distance_squared(&tgt->pos, &arg0->pos);
        if (tgt != 0 && ((TObjPlayer *)tgt)->get_floor() == get_current_floor() &&
            d < (*(Param_8030177C ** *)&TObjEneDolmOlm__behavior_params_by_variant)[arg0->kind]->range * (*(Param_8030177C ** *)&TObjEneDolmOlm__behavior_params_by_variant)[arg0->kind]->range) {
            arg0->target = tgt;
        } else {
            arg0->target = 0;
        }
    } else {
        arg0->f338 = 0xFFFF;
        arg0->target = 0;
    }
    ((TObjBase *)arg0)->obj_clearFlags30(0x4040000);
    ((TObjMotion *)arg0)->advance_animation();
    switch (arg0->f328) {
    case 0:
        if (arg0->target == 0 || (u16)get_entity_id(arg0->target) >= 0x1000) {
            arg0->f30 &= ~0x200000;
            arg0->f328 = 2;
            arg0->fb8 = 2;
        } else {
            Obj_8030177C *p = arg0->target;
            if (((TObjPlayer *)p)->check_player_flag1() != 0) {
                if (fabs_float(p->pos.y - arg0->pos.y) < 20.0f) {
                    arg0->f326 = 5;
                    arg0->f328 = 1;
                    if (0.5f < ((TObjChara *)arg0)->random_ratio()) {
                        arg0->fb8 = 3;
                    } else {
                        arg0->fb8 = 4;
                    }
                } else {
                    arg0->f326 = 3;
                    arg0->f328 = 1;
                    arg0->fb8 = 2;
                    arg0->f30 &= ~0x200000;
                    ((TObjBase *)arg0)->obj_clearFlags30(0x4040000);
                    ((TObjCollidable *)arg0)->clear_player_status_flag(0, 0xA000000);
                }
            } else {
                arg0->f328 = 1;
            }
        }
        apply_actor_gravity((TObjEnemy *)arg0, (s32 *)(0), 0.0f);
        break;
    case 1:
        if (arg0->target != 0) {
            Vec v;
            VecCopy((Vec *)&v, (const Vec *)&arg0->target->f2fc);
            subtract_vector(&v, &arg0->f2fc);
            if (((TObjEnemy *)arg0)->turn_toward_direction(arg0->move->turn, (Vec *)&v) < (*(Param_8030177C ** *)&TObjEneDolmOlm__behavior_params_by_variant)[arg0->kind]->angle) {
                arg0->f328 = 3;
                arg0->fb8 = 0xC;
                play_sound_effect(((TObjEnemy *)(arg0))->remap_sound_for_area(0x4003A804), &arg0->pos, 0, 0);
                spawn_particle_effect(&arg0->pos, 0x20E);
            }
        } else {
            arg0->fb8 = arg0->f328 = 2;
        }
        apply_actor_gravity((TObjEnemy *)arg0, (s32 *)(0), 0.0f);
        break;
    case 3:
        apply_actor_gravity((TObjEnemy *)arg0, (s32 *)(0), 0.0f);
        if (arg0->target != 0) {
            Vec v;
            s32 a;
            f32 d;
            Param_8030177C *t;
            VecCopy((Vec *)&v, (const Vec *)&arg0->target->f2fc);
            subtract_vector(&v, &arg0->f2fc);
            a = angle_difference_abs(arg0->rotY, (s32)(lbl_804750C8[0] * atan2_float(v.x, v.z)));
            d = horizontal_distance_squared(&arg0->target->pos, &arg0->pos);
            t = (*(Param_8030177C ** *)&TObjEneDolmOlm__behavior_params_by_variant)[arg0->kind];
            if (a < t->angle && d < t->range * t->range) {
                a = get_entity_id(arg0->target);
                if (((TObjCollidable *)(arg0->target))->obj_testFlags30(0x4000000) == 0) {
                    Obj_8030177C *pl = (Obj_8030177C *)get_player_by_client_id((u16)a);
                    if (pl != 0 && TObjPlayer::is_locally_controlled(pl) != 0 &&
                        ((TObject *)pl)->all_parents_unqueued_for_destruction() != 0 &&
                        ((TObjCollidable *)pl)->obj_testFlags30(0x800) == 0 && ((TObjPlayer *)pl)->check_player_flag1() == 0) {
                        TObjPlayer::play_effect((saddr)pl, (s32)((s32)(30.0f * (f32)(*(Param_8030177C ** *)&TObjEneDolmOlm__behavior_params_by_variant)[arg0->kind]->power)), 2);
                    }
                }
            }
        }
        if (((TObjMotion *)arg0)->is_passing_frame((f32)(arg0->fc4 - 1.0f - arg0->fc8)) != 0) {
            arg0->fb8 = arg0->f328 = 2;
        }
        break;
    case 2:
        apply_actor_gravity((TObjEnemy *)arg0, (s32 *)(0), 0.0f);
        arg0->f30 &= ~0x200000;
        arg0->f326 = 3;
        arg0->f328 = 1;
        arg0->fb8 = 2;
        ((TObjBase *)arg0)->obj_clearFlags30(0x4040000);
        ((TObjCollidable *)arg0)->clear_player_status_flag(0, 0xA000000);
        break;
    }
    ((TObjPlayer *)arg0)->update_collisions();
    minimap_render_dot(&arg0->pos, -0x5DB4, 1, 0);
}
#undef arg0
#pragma pop
void TObjEneDolmOlm::run_idle_action() {

    switch (this->mode) {
    case 1:
        if ((s32) this->m_390 != 0) {
            this->mode = 0;
            this->phase = 0;
        }
        break;
    case 10:
        break;
    case 0:
        switch ((s16) this->phase) {
        case 2:
            if ((s32) this->m_390 != 0) {
                this->phase = 0;
            }
            break;
        }
        break;
    default:
        if ((s32) this->m_390 != 0) {
            this->mode = 0;
        } else {
            this->mode = 1;
        }
        this->phase = 0;
        ((VObj_80301690_80300CE4 *) this)->m100();
        obj_setFlags30(this, 0x04040000);
        set_indexed_flags(0, 0x0A000000);
        break;
    }
}
void TObjEneDolmOlm::run_move_action() {
    u8 *self = (u8 *)this;
    if (((TObjCollidable *)self)->obj_testFlags30(0x1000U) != 0) {
        this->mode = 4;
    }
    switch (this->mode) {
    case 1:
        this->phase = 0;
        if ((uaddr) this->children == 0U) {
            this->mode = 3;
            this->requested_action = 7;
        } else {
            this->mode = 2;
            this->requested_action = 0xA;
        }
        ((TObjBase *)self)->obj_clearFlags30(0x04040000U);
        ((TObjCollidable *)self)->clear_player_status_flag(0, 0x0A000000U);
        return;
    case 4:
        this->requested_action = 5;
        return;
    default:
        this->mode = 3;
        this->phase = 1;
        this->requested_action = 2;
        ((TObjBase *)self)->obj_clearFlags30(0x04040000U);
        ((TObjCollidable *)self)->clear_player_status_flag(0, 0x0A000000U);
        return;
    case 2:
    case 3:
    case 10:
        return;
    }
}
void TObjEneDolmOlm::run_attack_action() {
    f32 temp_f31;
    f32 var_f30;
    u16 id;
    s32 var_r29;
    u8 *player;
    u8 *enemy_entity;
    switch (this->mode) {
    case 0:
    case 2:
    case 10:
    case 11:
        break;
    case 1:
        this->phase = 0;
        if (this->children == 0U) {
            this->mode = 3;
            this->requested_action = 7;
        } else {
            this->mode = 2;
            this->requested_action = 0xA;
        }
        obj_clearFlags30(0x04040000);
        this->clear_player_status_flag(0, 0x0A000000);
        break;
    default:
        id = this->targetId;
        var_r29 = 0;
        var_f30 = 20.0f;
        if (id < 0x1000U) {
            player = (u8 *)get_player_by_client_id(id);
            if (player != NULL) {
                temp_f31 = horizontal_distance_squared(player + 0x38, (void *) (((u8 *)this) + 0x38));
                var_f30 = fabs_float(*(f32 *)((s8 *)player + 0x3C) - *(f32 *)((s8 *)((u8 *)this) + 0x3C));
                if (((TObjPlayer *)player)->get_floor() == get_current_floor()) {
                    if ((temp_f31 < (*(f32 *)((s8 *)(*(saddr *)((s8 *)TObjEneDolmOlm__behavior_params_by_variant + (this->variant * 4))) + 0x10) * *(f32 *)((s8 *)(*(saddr *)((s8 *)TObjEneDolmOlm__behavior_params_by_variant + (this->variant * 4))) + 0x10))) && (((TObjChara *)this)->random_ratio() < this->m_3d0)) {
                        var_r29 = 1;
                    }
                }
            }
        } else if (id < 0x4000U) {
            enemy_entity = get_enemy_entity(id);
            if (enemy_entity != NULL) {
                var_f30 = fabs_float(*(f32 *)((s8 *)enemy_entity + 0x3C) - *(f32 *)((s8 *)((u8 *)this) + 0x3C));
            }
        }
        if (var_r29 == 1) {
            this->mode = 0xB;
            this->phase = 0;
            obj_setFlags30(this, 0x200000);
            obj_clearFlags30(0x04040000);
            this->clear_player_status_flag(0, 0x0A000000);
            return;
        }
        if (var_f30 < 20.0f) {
            this->mode = 5;
            this->phase = 1;
            if (0.5f < ((TObjChara *)this)->random_ratio()) {
                this->requested_action = 3;
            } else {
                this->requested_action = 4;
            }
            obj_setFlags30(this, 0x200000);
            obj_clearFlags30(0x04040000);
            this->clear_player_status_flag(0, 0x0A000000);
        }
        break;
    }
}
void TObjEneDolmOlm::advance_position() {
    VecCopy(&this->body_center, (const Vec *)&this->position);
    this->body_center.y += 20.0f;
}
void TObjEneDolmOlm::request_stand_action() { this->requested_action = 1; }
#pragma push
#pragma fp_contract on
void TObjEneDolmOlm::check_path_ahead(s32 angle, f32 farg0) {
    Vec stack;
    stack.y = 0.0f;
    stack.x = 0.0f;
    stack.z = (2.0f * farg0) + *(f32 *)((s8 *)this->bodies + 0xC);
    push_matrix_from((void *) (&(*(RecoveredGlobal_80301264_lbl_8058D490 *)&identity_matrix).value));
    rotate_matrix_y(0, angle);
    rotate_vector_by_matrix(0, &stack.x, &stack.x);
    pop_matrices(1);
    vec3_add_to(&stack.x, (void *) (((u8 *)this) + 0x2FC));
    check_path_obstructed(this, &stack.x);
}
#pragma pop
void TObjEneDolmOlm::sub_80301148() {
    if (*(s32 *)&this->variant < 1) {
        *(s32 *)&this->subtype = 0;
        *(s32 *)&this->variant = 0;
        this->set_param(0x40);
    } else {
        *(s32 *)&this->subtype = 2;
        *(s32 *)&this->variant = 1;
        this->set_param(0x41);
    }
    this->load_params_from_table(*(s32 *)&this->variant);
    set_motion_packed_rotation();
    ((SampledMotionPoints *)TObjEneDolmOlm__data_805D6A14)->sample_two_nodes(((T_80301148 *)TObjEneDolmOlm__resource_bundle)->a[*(s32 *)&this->variant].v, ((T_80301148 *)TObjEneDolmOlm__resource_bundle)->b[TObjEneDolmOlm__param_table[13]].v, 0x1C, 0x1D);
    ((SampledMotionPoints *)TObjEneDolmOlm__data_805D6A18)->sample_two_nodes(((T_80301148 *)TObjEneDolmOlm__resource_bundle)->a[*(s32 *)&this->variant].v, ((T_80301148 *)TObjEneDolmOlm__resource_bundle)->b[TObjEneDolmOlm__param_table[17]].v, 0x14, 0x15);
    clear_motion_packed_rotation();
    *(f32 *)((s8 *)((u8 *)this) + 0x3CC) = 0.3f + *(f32 *)((s8 *)((u8 *)this) + 0x35C);
    this->m_3d0 = 0.3f + *(f32 *)((s8 *)((u8 *)this) + 0x360);
}
void TObjEneDolmOlm::update_attack_trail() {
    Obj_800A7A14 *o = (Obj_800A7A14 *)this;
    Vec b;
    Vec a;
    Vec *e;
    s32 idx;
    VObj_800A7A14 *eff;
    if (!(this->frame < 12.0f)) {
        return;
    }
    switch (this->requested_action) {
    case 3:
        e = ((SampledMotionPoints *)((void *)(*(saddr *)&TObjEneDolmOlm__data_805D6A14)))->lookup(this->frame);
        idx = 0;
        break;
    case 4:
        e = ((SampledMotionPoints *)((void *)(*(saddr *)&TObjEneDolmOlm__data_805D6A18)))->lookup(this->frame);
        idx = 1;
        break;
    default:
        e = 0;
        break;
    }
    if (e == 0) {
        return;
    }
    push_matrix();
    set_matrix_identity(0);
    post_translate_matrix(&o->pos);
    rotate_matrix_y(0, this->rotation_y);
    matrix_mult_vec_array(NULL, e, &a, 2);
    pop_matrix();
    eff = o->effs[idx];
    if (eff != NULL) {
        eff->m4(&a, &b);
    }
}
void TObjEneDolmOlm::spawn_death_effect() {
    u8 *self = (u8 *)this;
    Vec stack;
    stack.x = 0.0f;
    stack.y = 10.0f;
    stack.z = 0.5f * *(f32 *)(this->m_2b0 + 0x10);
    push_matrix_from((void *)&identity_matrix.value);
    rotate_matrix_y(0, this->rotation_y);
    rotate_vector_by_matrix(0, (void *)&stack.x, (void *)&stack.x);
    pop_matrix();
    vec3_add_to((void *)&stack.x, (void *)(self + 0x38));
    ((TObjPlayer *)(&stack.x))->spawn_ground_effect(0x23);
    TObjPlayer__sub_800D92BC((saddr)&stack.x, 0xF);
}
void TObjEneDolmOlm::play_alert_sound() {
    saddr self = (saddr)this;
    play_sound_effect((((TObjEnemy *)((void *)self))->remap_sound_for_area(0x4003AD00)), (void *)(self + 0x38), 0, 0);
}
void TObjEneDolmOlm::play_attack_sound() {
    saddr self = (saddr)this;
    play_sound_effect((((TObjEnemy *)((void *)self))->remap_sound_for_area(0x4003B203)), (void *)(self + 0x38), 0, 0);
}
void TObjEneDolmOlm::play_hurt_sound() {
    saddr self = (saddr)this;
    play_sound_effect((((TObjEnemy *)((void *)self))->remap_sound_for_area(0x4003A802)), (void *)(self + 0x38), 0, 0);
}
void TObjEneDolmOlm::play_death_sound() {
    saddr self = (saddr)this;
    play_sound_effect((((TObjEnemy *)((void *)self))->remap_sound_for_area(0x4003A801)), (void *)(self + 0x38), 0, 0);
}
void TObjEneDolmOlm::init_body_sub() {
    spawn_ground_effects__14TObjEneDolmOlmFPvPv((u8 *)this, (Vec *)((s8 *)this + 0x38));
}
void spawn_ground_effects__14TObjEneDolmOlmFPvPv(u8 *arg0, Vec *arg1) {
    Vec v;
    CsnHit *hit;
    saddr e;
    VecCopy((Vec *)&v, (const Vec *)arg1);
    v.y += 15.0f;
    hit = csnVectorUnder(&v, (CsnGroup **)(arg0 + 0x120), 0x4007);
    if (hit != NULL) {
        if (hit->hit_mask & 4) {
            if (actor_frame_tick % 5 == 0) {
                fn_800D88E4(arg0 + 0x38);
            }
            e = (saddr)spawn_particle_effect(&hit->contact[2].point, 0x49);
            if (e != 0) {
                attach_particle_model((u8 *)e, TParticleCtrl::get_particle_model(2), TParticleCtrl::get_instance(), 0, 1, 1.0f);
            }
            spawn_particle_effect(&hit->contact[2].point, 0xA4);
        } else if (hit->hit_mask & 2) {
            if (actor_frame_tick % 10 == 0) {
                fn_800D88E4(arg0 + 0x38);
            }
            e = (saddr)spawn_particle_effect(&hit->contact[3].point, 0x49);
            if (e != 0) {
                attach_particle_model((u8 *)e, TParticleCtrl::get_particle_model(2), TParticleCtrl::get_instance(), 0, 1, 1.0f);
            }
            spawn_particle_effect(&hit->contact[3].point, 0xA4);
        }
        *(s32 *)(arg0 + 0x3E4) = hit->contact->flags;
        if (*(s32 *)(arg0 + 0x3E4) & 0x4000) {
            VecCopy((Vec *)(arg0 + 0x3D8), &hit->contact->point);
        } else {
            VecCopy((Vec *)(arg0 + 0x3D8), (const Vec *)(arg0 + 0x38));
        }
    }
}
void TObjEneDolmOlm::run_demo_task() {  }
s32 TObjEneDolmOlm__sub_80300CF0(void) {
    return 0x7FFFFFFF;
}
void TObjEneDolmOlm::reset_count() { lbl_805D69E8 = 0; }

__declspec(section ".rodata") const f64 lbl_804750C8[] = {10430.38043493439};
const char *obj_ene_dolm_olm_class_name = TObjEneDolmOlm__class_name_string;


uaddr dolm_olm_combat_stat_id_pair;
uaddr TObjEneDolmOlm__shared_handler_ids;
uaddr TObjEneDolmOlm__registered_object_ids;
uaddr TObjEneDolmOlm__behavior_params_by_variant;
uaddr TObjEneDolmOlm__resource_bundle;
uaddr TObjEneDolmOlm__data_805D6A14;
uaddr TObjEneDolmOlm__data_805D6A18;
s32 TObjEneDolmOlm__effect_render_state;
