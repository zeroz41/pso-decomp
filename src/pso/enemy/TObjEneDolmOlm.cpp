#pragma defer_codegen on

#include "types.h"
#include "pso/enemy/TUnk_80493450.h"
#include "pso/player/TUnk_804806E8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/TObjMotion.h"
#include "pso/enemy/TObjEneDolmOlm.h"
extern "C" void has_flag_0x800__13TUnk_804806E8Fv();
extern "C" void test_flag30_512__13TUnk_804806E8Fv();
extern "C" void test_flag_1000__13TUnk_804806E8Fv();
#include "pso/object/obj_band.h"
#include "pso/system/vector.h"
#include "pso/enemy/TObjEneRecon.h"
#include "pso/TObject.h"
#include "pso/TParticleCtrl.h"

#include "pso/enemy/TUnk_80494938.h"
extern "C" void test_flag_256__13TUnk_80493450Fv();

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
#include "pso/boss/TBoss3Volopt.h"
#include "pso/enemy/TObjEneBeast.h"
#include "pso/enemy/TObjEneLappy.h"
#include "pso/enemy/TObjEneMe3SinowZoa.h"
#include "pso/enemy/TObjEnePanarms.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TLobby.h"
#include "pso/object/TObjFish.h"
struct Stack_80300FC0 {
    f32 sp8;
    f32 spC;
    f32 sp10;
};

struct RecoveredGlobal_80300FC0_lbl_8058D490 { s32 value; u8 remaining[0x2C]; };
typedef char RecoveredGlobal_80300FC0_lbl_8058D490_size[sizeof(RecoveredGlobal_80300FC0_lbl_8058D490) == 0x30 ? 1 : -1];

struct Stack_80301264 {
    f32 sp8;
    f32 spC;
    f32 sp10;
};

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

typedef struct Vec_800A7A14 {
    f32 x, y, z;
} Vec_800A7A14;

struct VBase_800A7A14 { char pad[0x18]; };

struct VObj_800A7A14 : VBase_800A7A14 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4(Vec_800A7A14 *, Vec_800A7A14 *);
};

typedef struct Obj_800A7A14 {
    u8 pad0[0x38];
    Vec_800A7A14 pos;
    u8 pad44[0x60 - 0x44];
    s32 f60;
    u8 pad64[0xB8 - 0x64];
    s16 fB8;
    u8 padBA[0xC0 - 0xBA];
    f32 fC0;
    u8 padC4[0x3C4 - 0xC4];
    VObj_800A7A14 *effs[2];
} Obj_800A7A14;

typedef struct Vec_80300D00 { f32 x, y, z; } Vec_80300D00;

typedef struct Hit_80300D00 { s32 flags; u8 *obj; } Hit_80300D00;

struct O_80302D80;
struct E16_80301148 { u8 pad[8]; s32 v; u8 pad2[4]; };

struct E8_80301148 { u8 pad[4]; s32 v; };

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

struct Vec_803021AC { f32 x, y, z; };

struct Vec_8030177C { f32 x, y, z; };

struct Param_8030177C { u8 pad0[0x10]; f32 range; u8 pad14[0x18 - 0x14]; s32 angle; s32 power; };

struct Move_8030177C { u8 pad0[8]; s32 turn; };

struct Obj_8030177C {
    u8 pad0[0x30];
    u32 f30;
    u8 pad34[0x38 - 0x34];
    Vec_8030177C pos;
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
    Vec_8030177C f2fc;
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

struct Desc_80302784 { s32 f0; void *f4; s32 f8; s32 fC; };

struct Row_80302784 { u8 pad[0xC]; f32 fC; u8 pad2[0x1C]; };

struct Ent_80302784 { s32 f0; s32 f4; s32 f8; s32 fC; };

struct Pair_80302784 { s32 a; s32 b; };

struct Res_80302784 { u8 pad[0x42C]; Ent_80302784 *x42C; Pair_80302784 *x430; };

extern "C" {
s32 TObjEneDolmOlm__sub_80300CF0(void);
extern s32 TObjEneDolmOlm__effect_render_state;
s32 copy_target_state__14TObjEnePanarmsFPv(void *, int);
s32 play_sound_effect(void *, void *, int, int);
void vfunc_98__14TObjEneDolmOlmFv(s32 arg0);
void vfunc_97__14TObjEneDolmOlmFv(s32 arg0);
void vfunc_96__14TObjEneDolmOlmFv(s32 arg0);
void vfunc_95__14TObjEneDolmOlmFv(s32 arg0);
s32 TObjPlayer__sub_800D92BC(void *, int);
f32 vec3_add_to(void *, void *);
s32 rotate_vector_by_matrix(int, void *, void *);
s32 rotate_matrix_y(int, int);
s32 push_matrix_from(void *);
s32 pop_matrix();
extern RecoveredGlobal_80300FC0_lbl_8058D490 identity_matrix;
extern const f32 TObjEneDolmOlm__data_805DEF54;
extern const f32 lbl_805DEF58;
extern const f32 TObjEneDolmOlm__data_805DEF5C;
void vfunc_94__14TObjEneDolmOlmFv(u8 *arg0);
s32 check_path_obstructed(void *, void *);
s32 pop_matrices(int);
extern const f32 TObjEneDolmOlm__data_805DEF68;
void check_path_ahead__14TObjEneDolmOlmFlf(u8 *arg0, s32 arg1, f32 farg0);
s32 copy_position__20TBoss3VoloptHiraisinFv(void *);
s32 submit_cursor_candidate(void *, int);
s32 TObjEneDolmOlm__sub_80301C3C(void *);
extern const f32 TObjEneDolmOlm__data_805DEF50;
void run_task__14TObjEneDolmOlmFv(u8 *arg0);
extern u32 TObjEneDolmOlm__resource_bundle;
void advance_animation_playback(void);
void TObjEneMe3SinowZoa__sub_800D758C(void *);
void vfunc_83__14TObjEneDolmOlmFv(Ene_80302004 *self);
void queue_destruction__7TObjectFv(void *);
void __dt__13TUnk_80493450Fv(void *, int);
void __dt__13TUnk_80494938Fv(void *, int);
void free_collision_body_parts(void *);
void __dl__7TObjectFPv(void *);
Ene_80302A34 *TObjEneDolmOlm__sub_80302A34(Ene_80302A34 *self, s16 flag);
s32 mult_vec_array__10TObjPlayerFUll(int, int, void *, int);
s32 set_matrix_identity(int);
s32 push_matrix();
s32 post_translate_matrix(void *);
extern u32 TObjEneDolmOlm__data_805D6A14;
extern u32 TObjEneDolmOlm__data_805D6A18;
extern const f32 lbl_805DEF60;
void vfunc_93__14TObjEneDolmOlmFv(Obj_800A7A14 *o);
void attach_particle_model(s32, s32, s32, s32, s32, f32);
Hit_80300D00 *csnVectorUnder(void *, void *, s32, f32);
s32 spawn_particle_effect(void *, int);
void fn_800D88E4(void *);
extern s32 actor_frame_tick;
extern const f32 lbl_805DEF4C;
void spawn_ground_effects__14TObjEneDolmOlmFPvPv(u8 *arg0, Vec_80300D00 *arg1);
s32 draw_trail_with_colors(u32, s32, s32, int, int);
extern const f32 lbl_805DEF64;
s32 obj_testFlags30__13TUnk_804AF8A0FUl(void *, u32);
void vfunc_59__14TObjEneDolmOlmFv(u8 *arg0);
f32 calc_boss4_scale__10TObjPlayerFi();
s32 obj_setFlags30(void *, s32);
s32 get_current_floor();
f32 fabs_float(f32);
u8 *get_enemy_entity(u32);
f32 horizontal_distance_squared(void *, void *);
u8 *get_player_by_client_id(u32);
extern u32 TObjEneDolmOlm__behavior_params_by_variant;
extern const f32 TObjEneDolmOlm__data_805DEF6C;
void vfunc_60__14TObjEneDolmOlmFv(u8 *arg0);
s32 is_split_screen();
s32 restore_scene_lighting();
s32 select_actor_lighting(void *);
s32 defer_render__7TObjectFv(void *);
s32 translate_matrix(int, f32, f32, f32);
s32 draw_chunk_object(void *);
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;
extern const f32 lbl_805DEF70;
extern const f32 lbl_805DEF84;
extern const f32 lbl_805DEF88;
extern const f32 lbl_805DEF8C;
void render__14TObjEneDolmOlmFv(Ene_803021AC *arg0);
s32 apply_actor_gravity(void *, int, f32);
s32 update_angle__10TObjPlayerFlPv(void *, s32, void *);
s32 is_locally_controlled__10TObjPlayerFPv(void *);
s32 get_entity_id(void *);
f64 atan2_float(f32, f32);
s32 angle_difference_abs(s32, s32);
s32 minimap_render_dot(void *, int, int, int);
void subtract_vector(void *, void *);
extern const f64 lbl_804750C8[];
s32 TObjEneDolmOlm__sub_8030177C(void *arg0_);
}
struct Vec_80301C3C { f32 x, y, z; };
struct Elem_80301C3C { u8 pad[0xC]; f32 r; u8 pad2[0x1C]; };
struct Tgt_80301C3C { u8 pad[0xA4]; Elem_80301C3C *arr; s32 count; };
void move_with_wall_slide(u8 *arg0);
extern "C" {
s32 enemy_set_heading_velocity(void *, s32, f32);
s32 select_enemy_destination(void *, void *, int);
s32 copy_position_if_valid__10TObjPlayerFii(void *, void *);
s32 enemy_turn_toward_dest(void *, s32);
s32 test_elt_flag__13TUnk_80493450Fll(void *, int, int);
extern const f32 lbl_805DEF74;
extern const f32 lbl_805DEF78;
extern const f32 lbl_805DEF7C;
extern const f32 lbl_805DEF80;
s32 dispatch_shared_handler_a__6TLobbyFl(int);
s32 register_object__6TLobbyFl(int);
s32 dispatch_shared_handler_b__6TLobbyFl(int);
s32 register_boss__6TLobbyFl(int);
u8 *load_resource_from_descriptor(void *, int, void *, int, int, int);
u8 *init_trail_buffer__11TBoss4Type3FPvifff(void *, int, f32, f32, f32);
u8 *mem_alloc(s32);
s32 spawn_npc_enemy__6TLobbyFslllff(s16, s32, s32, void *, f32, f32);
extern u32 dolm_olm_combat_stat_id_pair;
extern u32 TObjEneDolmOlm__shared_handler_ids;
extern u32 TObjEneDolmOlm__registered_object_ids;
extern const f32 lbl_805DEF90;
extern void *lbl_804E67B8[4];
extern void *lbl_804E6774[4];
extern s32 TObjEneDolmOlm__param_table[52];
extern s32 lbl_804E68D0[22];
void * TObjEneDolmOlm__create(void *arg0);
void vfunc_101__14TObjEneDolmOlmFv(void);
void request_stand_action__14TObjEneDolmOlmFv(void* p);
void vfunc_100__14TObjEneDolmOlmFv(void *arg0);
void vfunc_58__14TObjEneDolmOlmFv(void *arg0);
void TLobby__sub_8001FE7C(void*, int);
void *TObjControl__ct(void *, void *);
u8 *TObjEneDolmOlm__ct(u8 *, s32, s32);
void __dt__11TBoss4Type3FPvs(void*, int);
void *__nw__7TObjectFUl(int);
void mem_free(void*);
s32 get_mode__11TCameraCtrlFPv(void *);
s32 init_enemy_base__13TUnk_80493450Fv(void *, s32);
s32 create__12TObjEneSaverFPvPv(u32, u32);
}
void restore_render_scissor(s32 arg0);
int initialize_enemy_photon_effect(void *p);
extern "C" {
s32 init_collision_body_parts(void *, void *, int);
extern s32 obj_ene_dolm_olm_class_name;
extern const f32 lbl_805DEF94;
extern const f32 lbl_805DEF98;
extern "C" {
void vfunc_6__13TUnk_804B9870FPsl();
}
extern "C" {
void vfunc_29__13TUnk_804806E8Fv();
}
extern "C" {
void recalc_stats__13TUnk_804806E8Fv();
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
void vfunc_99__13TUnk_80493450Fv();
}
extern "C" {
void vfunc_89__13TUnk_80493450Fv();
}
extern "C" {
void update_turn_toward_target__13TUnk_80493450Fv();
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
void beast_idle_update__13TUnk_80493450Fv();
}
extern "C" {
void beast_retire_corpse__13TUnk_80493450Fv();
}
extern "C" {
void beast_select_target();
}
extern "C" {
void beast_update_approach__13TUnk_80493450Fv();
}
extern "C" {
void beast_update_attack__13TUnk_80493450Fv();
}
extern "C" {
void beast_update_dead__13TUnk_80493450Fv();
}
extern "C" {
void beast_update_group_chase__13TUnk_80493450Fv();
}
extern "C" {
void beast_update_hurt__13TUnk_80493450Fv();
}
extern "C" {
void calc_distance_accuracy_penalty__13TUnk_804806E8FPvPvPvf();
}
extern "C" {
void vfunc_79__9TObjEnemyFv();
}
extern "C" {
void classify_actor_view_detail__13TUnk_804B9870Ffff();
}
extern "C" {
void clear_all_status_effects__13TUnk_804806E8Fv();
}
extern "C" {
void vfunc_61__13TUnk_80493450Fv();
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
void vfunc_62__13TUnk_80493450Fv();
}
extern "C" {
void enter_state_8__10TObjPlayerFv();
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
extern const u8 lbl_80474F08[];
}
extern "C" {
extern const u8 lbl_80474F1C[];
}
extern "C" {
extern const u8 lbl_80474F34[];
}
extern "C" {
extern const u8 lbl_80474F54[];
}
extern "C" {
extern const u8 lbl_80474F74[];
}
extern "C" {
extern const u8 lbl_80474F90[];
}
extern "C" {
extern const u8 lbl_80474FAC[];
}
extern "C" {
extern const u8 lbl_80474FC8[];
}
extern "C" {
extern const u8 lbl_80474FE4[];
}
extern "C" {
extern const u8 lbl_80475000[];
}
extern "C" {
extern const u8 lbl_8047501C[];
}
extern "C" {
extern const u8 lbl_80475038[];
}
extern "C" {
extern const u8 lbl_80475054[];
}
extern "C" {
extern const u8 lbl_8047506C[];
}
extern "C" {
extern const u8 lbl_80475084[];
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
void render_shadows__9TObjEnemyFv();
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
void update_movement_status__13TUnk_80493450Fv();
}
extern "C" {
void trigger_switch_attack__13TUnk_804806E8Fv();
}
extern "C" {
void try_start_action__13TUnk_804806E8Fll();
}
extern "C" {
void update_action_hold_status__13TUnk_80493450Fv();
}
extern "C" {
void vfunc_37__13TUnk_804806E8Fv();
}
extern "C" {
void update_actor_ground_y__13TUnk_804806E8Fv();
}
extern "C" {
void update_attack_stat_status__13TUnk_804806E8Fv();
}
extern "C" {
void update_defense_stat_status__13TUnk_804806E8Fv();
}
extern "C" {
void update_flag30_timer__13TUnk_804806E8Fv();
}
extern "C" {
void update_object_view_visibility__13TUnk_804B9870Fff();
}
extern "C" {
void update_poison_status__13TUnk_804806E8Fv();
}
void *lbl_804E6740[3] = {
    (void *)&lbl_80474F08, (void *)&lbl_80474F1C, (void *)0x0,
};
void *lbl_804E674C[10] = {
    (void *)&lbl_80474F34, (void *)&lbl_80474F54, (void *)&lbl_80474F74, (void *)&lbl_80474F90,
    (void *)&lbl_80474FAC, (void *)&lbl_80474FC8, (void *)&lbl_80474FE4, (void *)&lbl_80475000,
    (void *)&lbl_8047501C, (void *)0x0,
};
void *lbl_804E6774[4] = {
    (void *)&lbl_80475038, (void *)&lbl_804E6740, (void *)&lbl_804E674C, (void *)0x20009,
};
void *lbl_804E6784[3] = {
    (void *)&lbl_80475054, (void *)&lbl_8047506C, (void *)0x0,
};
void *lbl_804E6790[10] = {
    (void *)&lbl_80474F34, (void *)&lbl_80474F54, (void *)&lbl_80474F74, (void *)&lbl_80474F90,
    (void *)&lbl_80474FAC, (void *)&lbl_80474FC8, (void *)&lbl_80474FE4, (void *)&lbl_80475000,
    (void *)&lbl_8047501C, (void *)0x0,
};
void *lbl_804E67B8[4] = {
    (void *)&lbl_80475084, (void *)&lbl_804E6784, (void *)&lbl_804E6790, (void *)0x20009,
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
void *lbl_804E6928[103] = {
    (void *)0x0, (void *)0x0, (void *)&TObjEneDolmOlm__sub_80302A34, (void *)&run_task__14TObjEneDolmOlmFv,
    (void *)&render__14TObjEneDolmOlmFv, (void *)&render_shadows__9TObjEnemyFv, (void *)&vfunc_6__13TUnk_804B9870FPsl, (void *)&apply_object_set_data__13TUnk_804B9870FPv,
    (void *)&reset_motion_fields__13TUnk_804806E8Fv, (void *)&vfunc_9__13TUnk_804806E8Fv, (void *)&update_object_view_visibility__13TUnk_804B9870Fff, (void *)&classify_actor_view_detail__13TUnk_804B9870Ffff,
    (void *)&get_name__9TObjEnemyFv, (void *)&interact__13TUnk_804AF8A0Fl, (void *)&add_actor_exp__13TUnk_804806E8Fl, (void *)&consume_timer_field__13TUnk_804806E8Fl,
    (void *)&get_actor_level_index__13TUnk_804806E8Fv, (void *)&update_actor_ground_y__13TUnk_804806E8Fv, (void *)&vfunc_18__13TUnk_804806E8FPUc, (void *)&is_actor_cadence_frame__13TUnk_804806E8Fl,
    (void *)&select_melee_contact_body__13TUnk_804806E8FPvf, (void *)&calc_distance_accuracy_penalty__13TUnk_804806E8FPvPvPvf, (void *)&receive_physical_attack__13TUnk_804806E8FPvf, (void *)&receive_direct_attack__13TUnk_804806E8FPv19DirectAttackPayloadPvll,
    (void *)&receive_weapon_special_attack__13TUnk_804806E8FPvPv, (void *)&apply_knockback_from_attacker__13TUnk_804806E8FPUc, (void *)&try_start_action__13TUnk_804806E8Fll, (void *)&roll_physical_accuracy__13TUnk_804806E8FPvlf,
    (void *)&beast_select_target, (void *)&vfunc_29__13TUnk_804806E8Fv, (void *)&is_target_in_attack_range__13TUnk_804806E8Fv, (void *)&test_flag_256__13TUnk_80493450Fv,
    (void *)&test_flag30_512__13TUnk_804806E8Fv, (void *)&has_flag_0x800__13TUnk_804806E8Fv, (void *)&test_flag_1000__13TUnk_804806E8Fv, (void *)&update_poison_status__13TUnk_804806E8Fv,
    (void *)&update_action_hold_status__13TUnk_80493450Fv, (void *)&vfunc_37__13TUnk_804806E8Fv, (void *)&update_flag30_timer__13TUnk_804806E8Fv, (void *)&update_movement_status__13TUnk_80493450Fv,
    (void *)&update_shock_clock__13TUnk_804806E8Fv, (void *)&update_attack_stat_status__13TUnk_804806E8Fv, (void *)&update_defense_stat_status__13TUnk_804806E8Fv, (void *)&vfunc_43__13TUnk_804806E8Fv,
    (void *)&apply_poison_status__13TUnk_804806E8Fv, (void *)&apply_paralysis__13TUnk_804806E8Fv, (void *)&apply_slow_status__13TUnk_804806E8Fv, (void *)&apply_confusion_status__13TUnk_804806E8Fv,
    (void *)&apply_movement_ailment__13TUnk_804806E8Fl, (void *)&apply_shock_status__13TUnk_804806E8Fv, (void *)&clear_harmful_statuses__13TUnk_804806E8Fv, (void *)&apply_attack_stat_status__13TUnk_804806E8FPv,
    (void *)&apply_defense_stat_status__13TUnk_804806E8FPv, (void *)&cure_poison_ailment__13TUnk_804806E8Fv, (void *)&cure_paralysis__13TUnk_804806E8Fv, (void *)&clear_all_status_effects__13TUnk_804806E8Fv,
    (void *)&apply_action_hold_status__13TUnk_804806E8Ff, (void *)&apply_anti_technique__13TUnk_804806E8Fl, (void *)&vfunc_58__14TObjEneDolmOlmFv, (void *)&vfunc_59__14TObjEneDolmOlmFv,
    (void *)&vfunc_60__14TObjEneDolmOlmFv, (void *)&vfunc_61__13TUnk_80493450Fv, (void *)&vfunc_62__13TUnk_80493450Fv, (void *)&enter_state_8__10TObjPlayerFv,
    (void *)&reset_pose__13TUnk_804806E8Fv, (void *)&get_anim_node_position__13TUnk_804806E8FlP3Vec, (void *)&vfunc_66__13TUnk_804806E8Fv, (void *)&vfunc_67__13TUnk_804806E8Ff,
    (void *)&get_pos__13TUnk_804806E8Fl, (void *)&apply_switch_attack__13TUnk_804806E8Fv, (void *)&enemy_spawn_jellen_effect__13TUnk_804806E8Fv, (void *)&trigger_switch_attack__13TUnk_804806E8Fv,
    (void *)&enemy_spawn_zalure_effect__13TUnk_804806E8Fv, (void *)&recalc_stats__13TUnk_804806E8Fv, (void *)&vfunc_74__9TObjEnemyFl, (void *)&vfunc_75__13TUnk_804806E8Ff,
    (void *)&vfunc_76__13TUnk_804806E8Fv, (void *)&vfunc_77__13TUnk_804806E8Fv, (void *)&vfunc_78__13TUnk_804806E8Fl, (void *)&vfunc_79__9TObjEnemyFv,
    (void *)&apply_hit_message_flags__9TObjEnemyFPv, (void *)&apply_set_data__9TObjEnemyFPv, (void *)&clear_lobby_object_state__9TObjEnemyFv, (void *)&vfunc_83__14TObjEneDolmOlmFv,
    (void *)&beast_idle_update__13TUnk_80493450Fv, (void *)&update_turn_toward_target__13TUnk_80493450Fv, (void *)&beast_update_approach__13TUnk_80493450Fv, (void *)&beast_update_group_chase__13TUnk_80493450Fv,
    (void *)&beast_update_attack__13TUnk_80493450Fv, (void *)&vfunc_89__13TUnk_80493450Fv, (void *)&beast_update_hurt__13TUnk_80493450Fv, (void *)&beast_update_dead__13TUnk_80493450Fv,
    (void *)&beast_retire_corpse__13TUnk_80493450Fv, (void *)&vfunc_93__14TObjEneDolmOlmFv, (void *)&vfunc_94__14TObjEneDolmOlmFv, (void *)&vfunc_95__14TObjEneDolmOlmFv,
    (void *)&vfunc_96__14TObjEneDolmOlmFv, (void *)&vfunc_97__14TObjEneDolmOlmFv, (void *)&vfunc_98__14TObjEneDolmOlmFv, (void *)&vfunc_99__13TUnk_80493450Fv,
    (void *)&vfunc_100__14TObjEneDolmOlmFv, (void *)&vfunc_101__14TObjEneDolmOlmFv, (void *)&request_stand_action__14TObjEneDolmOlmFv,
};

    extern int lbl_805D69E8;

extern void *tl_04;

typedef struct RecoveredFields_8030247C_arg0 RecoveredFields_8030247C_arg0;
typedef struct VBase_18_477421 VBase_18_477421;
typedef struct VObj_18_477421 VObj_18_477421;

s32 TObjEneDolmOlm__sub_80301C3C(void *arg0_);
u8 *TObjEneDolmOlm__ct(u8 *arg0, s32 arg1, s32 arg2);

extern const u8 lbl_80474F08[0x14];
__declspec(section ".rodata") const u8 lbl_80474F08[0x14] ATTRIBUTE_ALIGN(4) = "abgc01_wola_body.nj";
extern const u8 lbl_80474F1C[0x15];
__declspec(section ".rodata") const u8 lbl_80474F1C[0x15] ATTRIBUTE_ALIGN(4) = "abgc01l_wola_body.nj";
extern const u8 lbl_80474F34[0x1D];
__declspec(section ".rodata") const u8 lbl_80474F34[0x1D] ATTRIBUTE_ALIGN(4) = "atack_l_abgc01_wola_body.njm";
extern const u8 lbl_80474F54[0x1D];
__declspec(section ".rodata") const u8 lbl_80474F54[0x1D] ATTRIBUTE_ALIGN(4) = "atack_r_abgc01_wola_body.njm";
extern const u8 lbl_80474F74[0x1C];
__declspec(section ".rodata") const u8 lbl_80474F74[0x1C] ATTRIBUTE_ALIGN(4) = "damage_abgc01_wola_body.njm";
extern const u8 lbl_80474F90[0x1A];
__declspec(section ".rodata") const u8 lbl_80474F90[0x1A] ATTRIBUTE_ALIGN(4) = "dead_abgc01_wola_body.njm";
extern const u8 lbl_80474FAC[0x1B];
__declspec(section ".rodata") const u8 lbl_80474FAC[0x1B] ATTRIBUTE_ALIGN(4) = "odori_abgc01_wola_body.njm";
extern const u8 lbl_80474FC8[0x1A];
__declspec(section ".rodata") const u8 lbl_80474FC8[0x1A] ATTRIBUTE_ALIGN(4) = "wait_abgc01_wola_body.njm";
extern const u8 lbl_80474FE4[0x1B];
__declspec(section ".rodata") const u8 lbl_80474FE4[0x1B] ATTRIBUTE_ALIGN(4) = "wait2_abgc01_wola_body.njm";
extern const u8 lbl_80475000[0x1A];
__declspec(section ".rodata") const u8 lbl_80475000[0x1A] ATTRIBUTE_ALIGN(4) = "wake_abgc01_wola_body.njm";
extern const u8 lbl_8047501C[0x1A];
__declspec(section ".rodata") const u8 lbl_8047501C[0x1A] ATTRIBUTE_ALIGN(4) = "walk_abgc01_wola_body.njm";
extern const u8 lbl_80475038[0x1C];
__declspec(section ".rodata") const u8 lbl_80475038[0x1C] ATTRIBUTE_ALIGN(4) = "bm_ene_abgc01_wola_body.bml";
extern const u8 lbl_80475054[0x17];
__declspec(section ".rodata") const u8 lbl_80475054[0x17] ATTRIBUTE_ALIGN(4) = "lo_abgc01_wola_body.nj";
extern const u8 lbl_8047506C[0x18];
__declspec(section ".rodata") const u8 lbl_8047506C[0x18] ATTRIBUTE_ALIGN(4) = "lo_abgc01l_wola_body.nj";
extern const u8 lbl_80475084[0x20];
__declspec(section ".rodata") const u8 lbl_80475084[0x20] ATTRIBUTE_ALIGN(4) = "bm_ene_abgc01_wola_body_low.bml";
extern const u8 lbl_804750A4[0xF];
__declspec(section ".rodata") const u8 lbl_804750A4[0xF] ATTRIBUTE_ALIGN(4) = "TObjEneDolmOlm";

void TObjEneDolmOlm::load_params_from_table(s32 i) {
    O_80302D80 *self = (O_80302D80 *)this;
    self->f34 = (*(G_80302D80 * *)&TObjEneDolmOlm__resource_bundle)->e[i].c;
    self->f24 = (*(G_80302D80 * *)&TObjEneDolmOlm__resource_bundle)->e[i].d;
}
u8 *TObjEneDolmOlm__ct(u8 *arg0, s32 arg1, s32 arg2) {
    u32 col;

    init_enemy_base__13TUnk_80493450Fv(arg0, arg1);
    *(void **)((s8 *)arg0 + 0x18) = lbl_804E6928;
    ((TUnk_80494938 *)(arg0 + 0x3A8))->init_common();
    *(s32 *)((s8 *)arg0 + 0) = obj_ene_dolm_olm_class_name;
    ((TObjEneDolmOlm *)arg0)->apply_set_data((void *)arg2);
    ((TObjPlayer *)arg0)->init_position_vectors();
    ((TObjEneDolmOlm *)arg0)->sub_80301148();
    *(void * *)&((TObjEneDolmOlm *)arg0)->action_table = TObjEneDolmOlm__param_table;
    ((TObjMotion *)arg0)->set_field_d8((s32)(*(void * *)&((TObjEneDolmOlm *)arg0)->action_table));
    *(s32 *)((s8 *)arg0 + 0xDC) = *(s32 *)((s8 *)TObjEneDolmOlm__resource_bundle + 0x430);
    ((TObjEneDolmOlm *)arg0)->m_b8 = 0;
    ((TObjMotion *)arg0)->set_animation(((TObjEneDolmOlm *)arg0)->m_b8);
    ((TObjMotion *)arg0)->set_field_b8(((TObjEneDolmOlm *)arg0)->m_b8);
    init_collision_body_parts(arg0, (u8 *) lbl_804E68D0 + *(s32 *)&((TObjEneDolmOlm *)arg0)->variant * 0x2C, 1);
    ((TObjEnemy *)arg0)->bind_enemy_combat_stats((u8 *)(((s32 *) dolm_olm_combat_stat_id_pair)[*(s32 *)&((TObjEneDolmOlm *)arg0)->variant]), (u8 *)(((s32 *) TObjEneDolmOlm__shared_handler_ids)[*(s32 *)&((TObjEneDolmOlm *)arg0)->variant]), (u8 *)(((s32 *) TObjEneDolmOlm__registered_object_ids)[*(s32 *)&((TObjEneDolmOlm *)arg0)->variant]));
    *(u8 * *)&((TObjEneDolmOlm *)arg0)->movementParameters = (u8 *) lbl_804E6898 + *(s32 *)&((TObjEneDolmOlm *)arg0)->variant * 0x1C;
    ((TObjEneDolmOlm *)arg0)->referenceHp = ((TObjEneDolmOlm *)arg0)->hp;
    ((TObjEneDolmOlm *)arg0)->advance_position();
    copy_position__20TBoss3VoloptHiraisinFv(arg0);
    initialize_enemy_photon_effect(arg0);
    *(s32 *)&((TObjEneDolmOlm *)arg0)->m_2ac = lbl_805DEF94 * (lbl_805DEF98 * ((f32 (*)(void *)) calc_boss4_scale__10TObjPlayerFi)(arg0));
    *(s16 *)&((TObjEneDolmOlm *)arg0)->resetTimer = 0xF;
    *(s16 *)&((TObjEneDolmOlm *)arg0)->timer = *(s16 *)&((TObjEneDolmOlm *)arg0)->resetTimer;
    ((TObjEneDolmOlm *)arg0)->phase = 0;
    ((TObjEneDolmOlm *)arg0)->m_374 = 0;
    *(s16 *)&((TObjEneDolmOlm *)arg0)->m_376 = 0;
    *(s32 *)&((TObjEneDolmOlm *)arg0)->m_3e4 = 0;
    VecCopy((Vec *)(arg0 + 0x3D8), (const Vec *)(arg0 + 0x38));
    *(s32 *)&((TObjEneDolmOlm *)arg0)->m_378 = 0;
    *(s32 *)&((TObjEneDolmOlm *)arg0)->m_37c = 0;
    ((TUnk_804806E8 *)arg0)->add_flags_2e4(2);
    ((TObjEneDolmOlm *)arg0)->actorFlags |= 0x40000;
    switch (*(s32 *)&((TObjEneDolmOlm *)arg0)->variant) {
    default:
        col = 0xFFDE20BD;
        break;
    case 1:
        col = 0xFFCDDE62;
        break;
    }
    ((VObj_14_fa0828 *) (arg0 + 0x3A8))->m3();
    ((TObjEneDolmOlm *)arg0)->m_390 = 1;
    *(s32 *)&((TObjEneDolmOlm *)arg0)->m_3c4 = create__12TObjEneSaverFPvPv(0xA0303030, col);
    *(s32 *)&((TObjEneDolmOlm *)arg0)->m_3c8 = create__12TObjEneSaverFPvPv(0xA0303030, col);
    *(f32 *)&((TObjEneDolmOlm *)arg0)->m_398 = ((f32 **) TObjEneDolmOlm__behavior_params_by_variant)[*(s32 *)&((TObjEneDolmOlm *)arg0)->variant][0];
    *(f32 *)&((TObjEneDolmOlm *)arg0)->m_3a0 = ((f32 **) TObjEneDolmOlm__behavior_params_by_variant)[*(s32 *)&((TObjEneDolmOlm *)arg0)->variant][1];
    *(f32 *)((s8 *)arg0 + 0x39C) = ((f32 **) TObjEneDolmOlm__behavior_params_by_variant)[*(s32 *)&((TObjEneDolmOlm *)arg0)->variant][2];
    *(f32 *)((s8 *)arg0 + 0x3A4) = ((f32 **) TObjEneDolmOlm__behavior_params_by_variant)[*(s32 *)&((TObjEneDolmOlm *)arg0)->variant][3];
    ((TObjEneDolmOlm *)arg0)->m_b8 = 1;
    *(f32 *)((s8 *)arg0 + 0x3D4) = TObjEneDolmOlm__data_805DEF54;
    ((TObjEnemy *)arg0)->sub_8002AE64();
    ((TObjEneDolmOlm *)arg0)->clear_lobby_object_state();
    return arg0;
}
Ene_80302A34 *TObjEneDolmOlm__sub_80302A34(Ene_80302A34 *self, s16 flag) {
    s32 i;
    if (self != NULL) {
        self->vt = lbl_804E6928;
        for (i = 0; i < 2; i++) {
            if (self->obj[i] != NULL) {
                queue_destruction__7TObjectFv(self->obj[i]);
                self->obj[i] = 0;
            }
        }
        ((TUnk_80493450 *)self)->unlink_enemy_group_relations();
        free_collision_body_parts(self);
        __dt__13TUnk_80494938Fv(self->sub, -1);
        __dt__13TUnk_80493450Fv(self, 0);
        if (flag > 0) {
            __dl__7TObjectFPv(self);
        }
    }
    return self;
}
void TObjEneDolmOlm::load_shared_resources() {
    u8 *p;
    s32 i;
    if (is_split_screen() != 0) {
        p = (u8 *)::operator new(0x440);
        if (p != NULL) {
            p = load_resource_from_descriptor(p, 1, lbl_804E67B8, 0, 0, 0);
        }
        TObjEneDolmOlm__resource_bundle = (u32) p;
    } else {
        p = (u8 *)::operator new(0x440);
        if (p != NULL) {
            p = load_resource_from_descriptor(p, 1, lbl_804E6774, 0, 0, 0);
        }
        TObjEneDolmOlm__resource_bundle = (u32) p;
    }
    p = (u8 *)::operator new(0x18);
    if (p != NULL) {
        p = init_trail_buffer__11TBoss4Type3FPvifff(p, 2, TObjEneDolmOlm__data_805DEF54, TObjEneDolmOlm__data_805DEF6C, lbl_805DEF90);
    }
    TObjEneDolmOlm__data_805D6A14 = (u32) p;
    p = (u8 *)::operator new(0x18);
    if (p != NULL) {
        p = init_trail_buffer__11TBoss4Type3FPvifff(p, 2, TObjEneDolmOlm__data_805DEF54, TObjEneDolmOlm__data_805DEF6C, lbl_805DEF90);
    }
    TObjEneDolmOlm__data_805D6A18 = (u32) p;
    TObjPlayer::set_global_flag();
    draw_trail_with_colors(TObjEneDolmOlm__data_805D6A14, ((Res_80302784 *)TObjEneDolmOlm__resource_bundle)->x42C->f8,
        ((Res_80302784 *)TObjEneDolmOlm__resource_bundle)->x430[((s32 *) TObjEneDolmOlm__param_table)[13]].b, 0x1C, 0x1D);
    draw_trail_with_colors(TObjEneDolmOlm__data_805D6A18, ((Res_80302784 *)TObjEneDolmOlm__resource_bundle)->x42C->f8,
        ((Res_80302784 *)TObjEneDolmOlm__resource_bundle)->x430[((s32 *) TObjEneDolmOlm__param_table)[17]].b, 0x14, 0x15);
    TObjPlayer::clear_global_state();
    dolm_olm_combat_stat_id_pair = (u32) mem_alloc(8);
    TObjEneDolmOlm__shared_handler_ids = (u32) mem_alloc(8);
    TObjEneDolmOlm__registered_object_ids = (u32) mem_alloc(8);
    TObjEneDolmOlm__behavior_params_by_variant = (u32) mem_alloc(8);
    ((s32 *) dolm_olm_combat_stat_id_pair)[0] = register_boss__6TLobbyFl(0x4F);
    ((s32 *) dolm_olm_combat_stat_id_pair)[1] = register_boss__6TLobbyFl(0x50);
    ((s32 *) TObjEneDolmOlm__shared_handler_ids)[0] = dispatch_shared_handler_b__6TLobbyFl(0x54);
    ((s32 *) TObjEneDolmOlm__shared_handler_ids)[1] = dispatch_shared_handler_b__6TLobbyFl(0x55);
    ((s32 *) TObjEneDolmOlm__registered_object_ids)[0] = register_object__6TLobbyFl(0x4E);
    ((s32 *) TObjEneDolmOlm__registered_object_ids)[1] = register_object__6TLobbyFl(0x4F);
    ((s32 *) TObjEneDolmOlm__behavior_params_by_variant)[0] = dispatch_shared_handler_a__6TLobbyFl(0x4E);
    ((s32 *) TObjEneDolmOlm__behavior_params_by_variant)[1] = dispatch_shared_handler_a__6TLobbyFl(0x4F);
    TObjEneDolmOlm__effect_render_state = 0;
    {
        s16 ids[2] = { 69, 79 };
        Desc_80302784 d = { *(s32 *)((s8 *)TObjEneDolmOlm__resource_bundle + 0x430), TObjEneDolmOlm__param_table, 2, 0xC0000 };
        for (i = 0; i < 2; i++) {
            Ent_80302784 *e = &(*(Ent_80302784 **)((s8 *)TObjEneDolmOlm__resource_bundle + 0x42C))[i];
            spawn_npc_enemy__6TLobbyFslllff(ids[i], e->f8, e->fC, &d, ((Row_80302784 *) lbl_804E68D0)[i].fC, TObjEneDolmOlm__data_805DEF54);
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
        __dt__11TBoss4Type3FPvs((void*)TObjEneDolmOlm__data_805D6A18, 1);
        TObjEneDolmOlm__data_805D6A18 = 0U;
    }
    if ((u32) TObjEneDolmOlm__data_805D6A14 != 0U) {
        __dt__11TBoss4Type3FPvs((void*)TObjEneDolmOlm__data_805D6A14, 1);
        TObjEneDolmOlm__data_805D6A14 = 0U;
    }
    if ((u32) TObjEneDolmOlm__resource_bundle != 0U) {
        TLobby__sub_8001FE7C((void*)TObjEneDolmOlm__resource_bundle, 1);
        TObjEneDolmOlm__resource_bundle = 0U;
    }
}
void * TObjEneDolmOlm__create(void *arg0) {
    void *o;
    void *o2;
    o = __nw__7TObjectFUl(0x20);
    if (o != NULL) {
        o = TObjControl__ct(o, tl_04);
    }
    o2 = __nw__7TObjectFUl(0x3E8);
    if (o2 != NULL) {
        o2 = ((void *(*)(void *, void *, void *))TObjEneDolmOlm__ct)(o2, o, arg0);
    }
    return o2;
}
void TObjEneDolmOlm::run_task() {
  s16 temp_r0;
  if (TObjPlayer::check_demo_mode() == 1)
  {
    (this->vfunc_101());
    return;
  }
  temp_r0 = ((RecoveredFields_8030247C_arg0 *) ((u8 *)this))->field_326;
  {
    switch (temp_r0)
    {
      case 0:
        (this->vfunc_83());
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
  copy_position__20TBoss3VoloptHiraisinFv((void *) ((u8 *)this));
  submit_cursor_candidate((void *) this, -1);
  if (((RecoveredFields_8030247C_arg0 *) ((u8 *)this))->field_3E4 & 0x4000)
  {
    TObjEneRecon::set_active();
  }
  ((RecoveredFields_8030247C_arg0 *) ((u8 *)this))->field_2B4 = (f32) (((RecoveredFields_8030247C_arg0 *) ((u8 *)this))->field_2B4 + TObjEneDolmOlm__data_805DEF50);
}
void TObjEneDolmOlm::render() {
    s32 vis;
    s16 saved;
    Ene_803021AC *arg0 = (Ene_803021AC *)this;
    if (arg0->f30 & 0x02000000) {
        return;
    }
    if (is_split_screen() != 0) {
        TCameraCtrl::get_camera_mode();
    }
    vis = arg0->m9(lbl_805DEF84, lbl_805DEF88, lbl_805DEF70);
    if (vis != 0 && ((TObjEneDolmOlm *)arg0)->render_model_if_visible() == 0) {
    select_actor_lighting(arg0);
    model_render_flags |= 1;
    TObjFish::set_global_param(arg0->f24);
    push_matrix();
    translate_matrix(0, TObjEneDolmOlm__data_805DEF54, arg0->f380, TObjEneDolmOlm__data_805DEF54);
    post_translate_matrix(arg0->pos);
    rotate_matrix_y(0, arg0->rotY);
    if (TObjPlayer::check_demo_mode() == 1) {
        draw_chunk_object(arg0->model);
    } else {
        switch (arg0->state) {
        case 0:
        case 1:
        case 8:
        case 9: {
            s16 t;
            Mesh_803021AC *m = arg0->model->p->p->p->mesh;
            t = m->flags;
            saved = t;
            m->flags = (u8)t;
            break;
        }
        }
        TObjPlayer::toggle_particle_effect();
        TObjEneDolmOlm__effect_render_state = 0;
        TObjEneRe7Berura::set_global_state((s32)((void *)TObjEneDolmOlm::toggle_effect_render));
        if (arg0->f390 == 1) {
            if (arg0->sub.m8() != 0) {
                saved_model_render_flags = model_render_flags;
                saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
                saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
                arg0->sub.m6();
                if (defer_render__7TObjectFv(arg0) == 0) {
                    model_render_flags |= 1;
                    ((TObjMotion *)arg0)->draw();
                    model_render_flags &= ~1;
                }
                arg0->sub.m7();
                chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
                chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
                model_render_flags = saved_model_render_flags;
            }
        } else if (vis == 1) {
            ((TObjMotion *)arg0)->draw();
        } else {
            ((TObjEnemy *)arg0)->render_world_model();
        }
        TObjEneRe7Berura::set_global_state((s32)NULL);
        TParticleCtrl::end_effect_render();
        switch (arg0->state) {
        case 0:
        case 1:
        case 8:
        case 9:
            arg0->model->p->p->p->mesh->flags = saved;
            break;
        }
    }
    pop_matrix();
    model_render_flags &= ~1;
    restore_scene_lighting();
    switch (arg0->state) {
    case 0:
    case 1:
    case 8:
    case 9:
        break;
    default:
        if (!(arg0->f3e4 & 0x4000)) {
            Vec_803021AC v;
            v.x = lbl_805DEF8C;
            v.y = TObjEneDolmOlm__data_805DEF50;
            v.z = TObjEneDolmOlm__data_805DEF68;
            ((TObjEnemy *)arg0)->render_with_position_override((u8 *)&v, 0);
        }
        break;
    }
    }
}
s32 TObjEneDolmOlm::render_model_if_visible() {
    if (get_mode__11TCameraCtrlFPv(((s32 *)&main_task)) & 0x20) {
        if (((TObjEneRecon *)(((u8 *)this) + 0x3D8))->push_reflect_matrix() != 0) {
            TObjFish::set_global_param(this->texture_id);
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
void TObjEneDolmOlm::toggle_effect_render() {
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
void TObjEneDolmOlm::vfunc_83() {
    Ene_80302004 *self = (Ene_80302004 *)this;
    advance_animation_playback();
    switch (this->phase) {
    case 0:
    default:
        if (this->m_390 != 0) {
            TObjEneMe3SinowZoa__sub_800D758C(&self->obj);
            ((TBoss3Volopt *)(self->sub38))->play_area_sound_effect();
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
void TObjEneDolmOlm::vfunc_100() {
    if (calc_boss4_scale__10TObjPlayerFi() < *(f32 *)((s8 *)this + 0x3CC)) {
        this->mode = 0xA;
        this->phase = 0;
    }
}
#pragma push
#pragma opt_common_subs off
#define ADV ((void (*)(void *))advance_animation_playback)
#define arg0 ((u8 *)arg0_)
s32 TObjEneDolmOlm__sub_80301C3C(void *arg0_) {
    Vec_80301C3C v;
    f32 f;

    switch (*(s16 *)((s8 *)arg0 + 0x328)) {
    case 0:
        apply_actor_gravity(arg0, 0, TObjEneDolmOlm__data_805DEF54);
        ADV(arg0);
        *(s16 *)((s8 *)arg0 + 0x328) = 1;
        *(s16 *)((s8 *)arg0 + 0xB8) = 2;
        *(f32 *)((s8 *)arg0 + 0x3D4) = TObjEneDolmOlm__data_805DEF54;
        *(f32 *)((s8 *)arg0 + 0xC8) *= TObjEneDolmOlm__data_805DEF68;
        break;
    default:
    case 1:
        if (*(u8 **)((s8 *)arg0 + 0x2A8) != NULL) {
            if (test_elt_flag__13TUnk_80493450Fll(arg0, 0, 0x300000) != 0) {
                if ((f32) (*(u32 *)((s8 *)arg0 + 0x38C))++ < lbl_805DEF74) {
                    VecCopy((Vec *)&v, (const Vec *)(arg0 + 0x50));
                } else {
                    VecCopy((Vec *)&v, (const Vec *)(*(u8 **)((s8 *)arg0 + 0x2A8) + 0x2FC));
                }
            } else {
                *(u32 *)((s8 *)arg0 + 0x38C) = 0;
                VecCopy((Vec *)&v, (const Vec *)(*(u8 **)((s8 *)arg0 + 0x2A8) + 0x2FC));
            }
            ADV(arg0);
            play_sound_effect((void *)copy_target_state__14TObjEnePanarmsFPv(arg0, 0x4003B205), arg0 + 0x38, 0, 0);
            if (horizontal_distance_squared(arg0 + 0x29C, arg0 + 0x38) < lbl_805DEF78 || ((VObj_18_cc39a7 *)(arg0))->m17(0x1E) != 0) {
                Vec_80301C3C a = v;
                if (select_enemy_destination(arg0, &a, 1) != 0) {
                    Vec_80301C3C b = *(Vec_80301C3C *)(arg0 + 0x2FC);
                    copy_position_if_valid__10TObjPlayerFii(arg0, &b);
                }
            }
            f = lbl_805DEF7C * *(f32 *)((s8 *)arg0 + 0x394);
            if (((s32 (*)(u8 *, s32, f32))check_path_ahead__14TObjEneDolmOlmFlf)(arg0, *(s32 *)((s8 *)arg0 + 0x60) + 0x8000, f) == 0) {
                enemy_turn_toward_dest(arg0, *(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x350)) + 8));
                enemy_set_heading_velocity(arg0, *(s32 *)((s8 *)arg0 + 0x60) + 0x8000, f);
                move_with_wall_slide(arg0);
                *(f32 *)((s8 *)arg0 + 0x3D4) += f;
                if (*(f32 *)((s8 *)arg0 + 0x3D4) >= lbl_805DEF80) {
                    *(s16 *)((s8 *)arg0 + 0x328) = 2;
                }
                f32 d = horizontal_distance_squared(*(u8 **)((s8 *)arg0 + 0x2A8) + 0x2FC, arg0 + 0x38);
                for (s32 i = 0; i < (*(Tgt_80301C3C **)((s8 *)arg0 + 0x2A8))->count; i++) {
                    if (d > ((*(Tgt_80301C3C **)((s8 *)arg0 + 0x2A8))->arr[i].r + ((TUnk_804806E8 *)arg0)->get_target_value()) * ((*(Tgt_80301C3C **)((s8 *)arg0 + 0x2A8))->arr[i].r + ((TUnk_804806E8 *)arg0)->get_target_value())) {
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
        ((TUnk_804B9870 *)arg0)->obj_clearFlags30(0x04040000);
        ((TUnk_804AF8A0 *)arg0)->clear_player_status_flag(0, 0x0A000000);
        ((TUnk_80493450 *)arg0)->update_target_near_flag();
        ((TUnk_80493450 *)arg0)->sub_800C4E08();
        break;
    }
    ((TObjPlayer *)arg0)->update_collisions();
    minimap_render_dot(arg0 + 0x38, -0x5DB4, 1, 0);
    ((TUnk_804B9870 *)arg0)->obj_clearFlags30(0x200000);
}
#undef arg0
#undef ADV
#pragma pop
#pragma push
#pragma opt_common_subs off
#define arg0 ((Obj_8030177C *)arg0_)
s32 TObjEneDolmOlm__sub_8030177C(void *arg0_) {
    if (arg0->f338 < 0x1000) {
        Obj_8030177C *tgt = (Obj_8030177C *)get_player_by_client_id(arg0->f338);
        f32 d = horizontal_distance_squared(&tgt->pos, &arg0->pos);
        if (tgt != 0 && ((TObjPlayer *)tgt)->get_field_3e4() == get_current_floor() &&
            d < (*(Param_8030177C ** *)&TObjEneDolmOlm__behavior_params_by_variant)[arg0->kind]->range * (*(Param_8030177C ** *)&TObjEneDolmOlm__behavior_params_by_variant)[arg0->kind]->range) {
            arg0->target = tgt;
        } else {
            arg0->target = 0;
        }
    } else {
        arg0->f338 = 0xFFFF;
        arg0->target = 0;
    }
    ((TUnk_804B9870 *)arg0)->obj_clearFlags30(0x4040000);
    ((void (*)(void *))advance_animation_playback)(arg0);
    switch (arg0->f328) {
    case 0:
        if (arg0->target == 0 || (u16)get_entity_id(arg0->target) >= 0x1000) {
            arg0->f30 &= ~0x200000;
            arg0->f328 = 2;
            arg0->fb8 = 2;
        } else {
            Obj_8030177C *p = arg0->target;
            if (((TLobby *)p)->check_player_flag1() != 0) {
                if (fabs_float(p->pos.y - arg0->pos.y) < TObjEneDolmOlm__data_805DEF6C) {
                    arg0->f326 = 5;
                    arg0->f328 = 1;
                    if (TObjEneDolmOlm__data_805DEF5C < ((f32 (*)(void *))calc_boss4_scale__10TObjPlayerFi)(arg0)) {
                        arg0->fb8 = 3;
                    } else {
                        arg0->fb8 = 4;
                    }
                } else {
                    arg0->f326 = 3;
                    arg0->f328 = 1;
                    arg0->fb8 = 2;
                    arg0->f30 &= ~0x200000;
                    ((TUnk_804B9870 *)arg0)->obj_clearFlags30(0x4040000);
                    ((TUnk_804AF8A0 *)arg0)->clear_player_status_flag(0, 0xA000000);
                }
            } else {
                arg0->f328 = 1;
            }
        }
        apply_actor_gravity(arg0, 0, TObjEneDolmOlm__data_805DEF54);
        break;
    case 1:
        if (arg0->target != 0) {
            Vec_8030177C v;
            VecCopy((Vec *)&v, (const Vec *)&arg0->target->f2fc);
            subtract_vector(&v, &arg0->f2fc);
            if (update_angle__10TObjPlayerFlPv(arg0, arg0->move->turn, &v) < (*(Param_8030177C ** *)&TObjEneDolmOlm__behavior_params_by_variant)[arg0->kind]->angle) {
                arg0->f328 = 3;
                arg0->fb8 = 0xC;
                play_sound_effect((void *)copy_target_state__14TObjEnePanarmsFPv(arg0, 0x4003A804), &arg0->pos, 0, 0);
                spawn_particle_effect(&arg0->pos, 0x20E);
            }
        } else {
            arg0->fb8 = arg0->f328 = 2;
        }
        apply_actor_gravity(arg0, 0, TObjEneDolmOlm__data_805DEF54);
        break;
    case 3:
        apply_actor_gravity(arg0, 0, TObjEneDolmOlm__data_805DEF54);
        if (arg0->target != 0) {
            Vec_8030177C v;
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
                if (obj_testFlags30__13TUnk_804AF8A0FUl(arg0->target, 0x4000000) == 0) {
                    Obj_8030177C *pl = (Obj_8030177C *)get_player_by_client_id((u16)a);
                    if (pl != 0 && is_locally_controlled__10TObjPlayerFPv(pl) != 0 &&
                        ((TObject *)pl)->all_parents_unqueued_for_destruction() != 0 &&
                        obj_testFlags30__13TUnk_804AF8A0FUl(pl, 0x800) == 0 && ((TLobby *)pl)->check_player_flag1() == 0) {
                        TObjPlayer::play_effect((s32)pl, (s32)((s32)(lbl_805DEF70 * (f32)(*(Param_8030177C ** *)&TObjEneDolmOlm__behavior_params_by_variant)[arg0->kind]->power)), 2);
                    }
                }
            }
        }
        if (objInBand((GameObj *)arg0, (f32)(arg0->fc4 - TObjEneDolmOlm__data_805DEF50 - arg0->fc8)) != 0) {
            arg0->fb8 = arg0->f328 = 2;
        }
        break;
    case 2:
        apply_actor_gravity(arg0, 0, TObjEneDolmOlm__data_805DEF54);
        arg0->f30 &= ~0x200000;
        arg0->f326 = 3;
        arg0->f328 = 1;
        arg0->fb8 = 2;
        ((TUnk_804B9870 *)arg0)->obj_clearFlags30(0x4040000);
        ((TUnk_804AF8A0 *)arg0)->clear_player_status_flag(0, 0xA000000);
        break;
    }
    ((TObjPlayer *)arg0)->update_collisions();
    minimap_render_dot(&arg0->pos, -0x5DB4, 1, 0);
}
#undef arg0
#pragma pop
void TObjEneDolmOlm::vfunc_58() {

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
void TObjEneDolmOlm::vfunc_59() {
    u8 *arg0 = (u8 *)this;
    if (obj_testFlags30__13TUnk_804AF8A0FUl(arg0, 0x1000U) != 0) {
        this->mode = 4;
    }
    switch (this->mode) {
    case 1:
        this->phase = 0;
        if ((u32) this->children == 0U) {
            this->mode = 3;
            this->m_b8 = 7;
        } else {
            this->mode = 2;
            this->m_b8 = 0xA;
        }
        ((TUnk_804B9870 *)arg0)->obj_clearFlags30(0x04040000U);
        ((TUnk_804AF8A0 *)arg0)->clear_player_status_flag(0, 0x0A000000U);
        return;
    case 4:
        this->m_b8 = 5;
        return;
    default:
        this->mode = 3;
        this->phase = 1;
        this->m_b8 = 2;
        ((TUnk_804B9870 *)arg0)->obj_clearFlags30(0x04040000U);
        ((TUnk_804AF8A0 *)arg0)->clear_player_status_flag(0, 0x0A000000U);
        return;
    case 2:
    case 3:
    case 10:
        return;
    }
}
void TObjEneDolmOlm::vfunc_60() {
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
            this->m_b8 = 7;
        } else {
            this->mode = 2;
            this->m_b8 = 0xA;
        }
        obj_clearFlags30(0x04040000);
        this->clear_player_status_flag(0, 0x0A000000);
        break;
    default:
        id = this->targetId;
        var_r29 = 0;
        var_f30 = TObjEneDolmOlm__data_805DEF6C;
        if (id < 0x1000U) {
            player = get_player_by_client_id(id);
            if (player != NULL) {
                temp_f31 = horizontal_distance_squared(player + 0x38, (void *) (((u8 *)this) + 0x38));
                var_f30 = fabs_float(*(f32 *)((s8 *)player + 0x3C) - *(f32 *)((s8 *)((u8 *)this) + 0x3C));
                if (((TObjPlayer *)player)->get_field_3e4() == get_current_floor()) {
                    if ((temp_f31 < (*(f32 *)((s8 *)(*(s32 *)((s8 *)TObjEneDolmOlm__behavior_params_by_variant + (this->variant * 4))) + 0x10) * *(f32 *)((s8 *)(*(s32 *)((s8 *)TObjEneDolmOlm__behavior_params_by_variant + (this->variant * 4))) + 0x10))) && (((f32 (*)(void *)) calc_boss4_scale__10TObjPlayerFi)(this) < this->m_3d0)) {
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
        if (var_f30 < TObjEneDolmOlm__data_805DEF6C) {
            this->mode = 5;
            this->phase = 1;
            if (TObjEneDolmOlm__data_805DEF5C < ((f32 (*)(void *)) calc_boss4_scale__10TObjPlayerFi)(this)) {
                this->m_b8 = 3;
            } else {
                this->m_b8 = 4;
            }
            obj_setFlags30(this, 0x200000);
            obj_clearFlags30(0x04040000);
            this->clear_player_status_flag(0, 0x0A000000);
        }
        break;
    }
}
void TObjEneDolmOlm::advance_position() {
    VecCopy((Vec *)&this->m_2fc, (const Vec *)&this->position);
    this->m_300 = (f32) (this->m_300 + TObjEneDolmOlm__data_805DEF6C);
}
void TObjEneDolmOlm::request_stand_action() { this->m_b8 = 1; }
#pragma push
#pragma fp_contract on
void TObjEneDolmOlm::check_path_ahead(s32 arg1, f32 farg0) {
    typedef char sp8_offset[(offsetof(Stack_80301264, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_80301264, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_80301264, sp10) == 0x8) ? 1 : -1];
    Stack_80301264 stack;
    stack.spC = TObjEneDolmOlm__data_805DEF54;
    stack.sp8 = TObjEneDolmOlm__data_805DEF54;
    stack.sp10 = (TObjEneDolmOlm__data_805DEF68 * farg0) + *(f32 *)((s8 *)this->bodies + 0xC);
    push_matrix_from((void *) (&(*(RecoveredGlobal_80301264_lbl_8058D490 *)&identity_matrix).value));
    rotate_matrix_y(0, arg1);
    rotate_vector_by_matrix(0, &stack.sp8, &stack.sp8);
    pop_matrices(1);
    vec3_add_to(&stack.sp8, (void *) (((u8 *)this) + 0x2FC));
    check_path_obstructed(this, &stack.sp8);
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
    TObjPlayer::set_global_flag();
    draw_trail_with_colors(TObjEneDolmOlm__data_805D6A14,
        ((T_80301148 *)TObjEneDolmOlm__resource_bundle)->a[*(s32 *)&this->variant].v,
        ((T_80301148 *)TObjEneDolmOlm__resource_bundle)->b[TObjEneDolmOlm__param_table[13]].v, 0x1C, 0x1D);
    draw_trail_with_colors(TObjEneDolmOlm__data_805D6A18,
        ((T_80301148 *)TObjEneDolmOlm__resource_bundle)->a[*(s32 *)&this->variant].v,
        ((T_80301148 *)TObjEneDolmOlm__resource_bundle)->b[TObjEneDolmOlm__param_table[17]].v, 0x14, 0x15);
    TObjPlayer::clear_global_state();
    *(f32 *)((s8 *)((u8 *)this) + 0x3CC) = lbl_805DEF64 + *(f32 *)((s8 *)((u8 *)this) + 0x35C);
    this->m_3d0 = lbl_805DEF64 + *(f32 *)((s8 *)((u8 *)this) + 0x360);
}
void TObjEneDolmOlm::vfunc_93() {
    Obj_800A7A14 *o = (Obj_800A7A14 *)this;
    Vec_800A7A14 b;
    Vec_800A7A14 a;
    u32 e;
    s32 idx;
    VObj_800A7A14 *eff;
    if (!(this->m_c0 < lbl_805DEF60)) {
        return;
    }
    switch (this->m_b8) {
    case 3:
        e = TObjPlayer::lookup_entry_by_value((void *)(*(s32 *)&TObjEneDolmOlm__data_805D6A14), this->m_c0);
        idx = 0;
        break;
    case 4:
        e = TObjPlayer::lookup_entry_by_value((void *)(*(s32 *)&TObjEneDolmOlm__data_805D6A18), this->m_c0);
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
    mult_vec_array__10TObjPlayerFUll(0, e, &a, 2);
    pop_matrix();
    eff = o->effs[idx];
    if (eff != NULL) {
        eff->m4(&a, &b);
    }
}
void TObjEneDolmOlm::vfunc_94() {
    u8 *arg0 = (u8 *)this;
    typedef char sp8_offset[(offsetof(Stack_80300FC0, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_80300FC0, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_80300FC0, sp10) == 0x8) ? 1 : -1];
    Stack_80300FC0 stack;
    stack.sp8 = TObjEneDolmOlm__data_805DEF54;
    stack.spC = lbl_805DEF58;
    stack.sp10 = TObjEneDolmOlm__data_805DEF5C * *(f32 *)(this->m_2b0 + 0x10);
    push_matrix_from((void *)&identity_matrix.value);
    rotate_matrix_y(0, this->rotation_y);
    rotate_vector_by_matrix(0, (void *)&stack.sp8, (void *)&stack.sp8);
    pop_matrix();
    vec3_add_to((void *)&stack.sp8, (void *)(arg0 + 0x38));
    ((TObjPlayer *)(&stack.sp8))->spawn_ground_effect(0x23);
    TObjPlayer__sub_800D92BC((void *)&stack.sp8, 0xF);
}
void TObjEneDolmOlm::vfunc_95() {
    s32 arg0 = (s32)this;
    play_sound_effect((void *) (copy_target_state__14TObjEnePanarmsFPv((void *)arg0, 0x4003AD00)), (void *)(arg0 + 0x38), 0, 0);
}
void TObjEneDolmOlm::vfunc_96() {
    s32 arg0 = (s32)this;
    play_sound_effect((void *) (copy_target_state__14TObjEnePanarmsFPv((void *)arg0, 0x4003B203)), (void *)(arg0 + 0x38), 0, 0);
}
void TObjEneDolmOlm::vfunc_97() {
    s32 arg0 = (s32)this;
    play_sound_effect((void *) (copy_target_state__14TObjEnePanarmsFPv((void *)arg0, 0x4003A802)), (void *)(arg0 + 0x38), 0, 0);
}
void TObjEneDolmOlm::vfunc_98() {
    s32 arg0 = (s32)this;
    play_sound_effect((void *) (copy_target_state__14TObjEnePanarmsFPv((void *)arg0, 0x4003A801)), (void *)(arg0 + 0x38), 0, 0);
}
void TObjEneDolmOlm::init_body_sub() {
    spawn_ground_effects__14TObjEneDolmOlmFPvPv((u8 *)this, (Vec_80300D00 *)((s8 *)this + 0x38));
}
void spawn_ground_effects__14TObjEneDolmOlmFPvPv(u8 *arg0, Vec_80300D00 *arg1) {
    Vec_80300D00 v;
    Hit_80300D00 *hit;
    f32 y;
    s32 e;
    VecCopy((Vec *)&v, (const Vec *)arg1);
    y = v.y;
    v.y = y + lbl_805DEF4C;
    hit = csnVectorUnder(&v, arg0 + 0x120, 0x4007, y);
    if (hit != NULL) {
        if (hit->flags & 4) {
            if (actor_frame_tick % 5 == 0) {
                fn_800D88E4(arg0 + 0x38);
            }
            e = spawn_particle_effect(hit->obj + 0x38, 0x49);
            if (e != 0) {
                attach_particle_model(e, TParticleCtrl::get_particle_model(2), TParticleCtrl::get_instance(), 0, 1, TObjEneDolmOlm__data_805DEF50);
            }
            spawn_particle_effect(hit->obj + 0x38, 0xA4);
        } else if (hit->flags & 2) {
            if (actor_frame_tick % 10 == 0) {
                fn_800D88E4(arg0 + 0x38);
            }
            e = spawn_particle_effect(hit->obj + 0x54, 0x49);
            if (e != 0) {
                attach_particle_model(e, TParticleCtrl::get_particle_model(2), TParticleCtrl::get_instance(), 0, 1, TObjEneDolmOlm__data_805DEF50);
            }
            spawn_particle_effect(hit->obj + 0x54, 0xA4);
        }
        *(s32 *)(arg0 + 0x3E4) = *(s32 *)(hit->obj + 0x18);
        if (*(s32 *)(arg0 + 0x3E4) & 0x4000) {
            VecCopy((Vec *)(arg0 + 0x3D8), (const Vec *)hit->obj);
        } else {
            VecCopy((Vec *)(arg0 + 0x3D8), (const Vec *)(arg0 + 0x38));
        }
    }
}
void TObjEneDolmOlm::vfunc_101() {  }
s32 TObjEneDolmOlm__sub_80300CF0(void) {
    return 0x7FFFFFFF;
}
void TObjEneDolmOlm::reset_count() { lbl_805D69E8 = 0; }

__declspec(section ".rodata") const f64 lbl_804750C8[] = {10430.38043493439};
}
