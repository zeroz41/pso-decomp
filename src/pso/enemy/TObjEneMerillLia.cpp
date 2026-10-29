#include "types.h"
#include "pso/enemy/TUnk_80493450.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjChara.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/TObjMotion.h"
#include "pso/enemy/TObjEneMerillLia.h"
#include "pso/misc/TLobby.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/misc/TOBoss4Rock.h"
extern "C" void has_flag_0x800__9TObjCharaFv();
extern "C" void test_flag30_512__9TObjCharaFv();
extern "C" void test_flag_1000__9TObjCharaFv();
#include "pso/object/obj_band.h"
#include "pso/system/vector.h"

#include "pso/enemy/TUnk_80494938.h"
extern "C" void test_flag_256__13TUnk_80493450Fv();

struct Obj_800D5614 { u8 pad0[0x38]; u8 pos[0xC]; u8 pad44[0x2A8 - 0x44]; void *f2a8; u8 pad2ac[0x326 - 0x2AC]; s16 f326; s16 f328; u8 pad32a[0x338 - 0x32A]; u16 f338; u8 pad33a[0x350 - 0x33A]; f32 *f350; u8 pad354[0x3D0 - 0x354]; f32 f3d0; };
struct Pl_800D5614 { u8 pad0[0x38]; u8 pos[0xC]; };

#include <stddef.h>
#include "pso/TParticleCtrl.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/enemy/TObjEneBeast.h"
#include "pso/enemy/TObjEneLappy.h"
#include "pso/enemy/TObjEneMe3SinowZoa.h"
#include "pso/enemy/TObjEnePanarms.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/object/TObjFish.h"

struct Stack_800D5060 {
    f32 sp8;
    f32 spC;
    f32 sp10;
};

struct RecoveredGlobal_800D5060_lbl_8058D490 { s32 value; u8 remaining[0x2C]; };
typedef char RecoveredGlobal_800D5060_lbl_8058D490_size[sizeof(RecoveredGlobal_800D5060_lbl_8058D490) == 0x30 ? 1 : -1];

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

struct Stack_800D6810
{
  f32 sp8;
  f32 spC;
  f32 sp10;
};

struct VBase_18_ca64a0
{
  char pad[0x18];
};

struct VObj_18_ca64a0 : VBase_18_ca64a0 {
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
};

struct VBase_14_fddec9
{
  char pad[0x14];
};

struct VObj_14_fddec9 : VBase_14_fddec9 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual s32 m6();
    virtual s32 m7();
    virtual s32 m8();
};

struct RecoveredFields_800D6810_arg0
{
  u8 unknown_0[0x24];
  s32 field_24;
  u8 unknown_28[0xC];
  s32 field_34;
  u8 unknown_38[0x28];
  s32 field_60;
  u8 unknown_64[0x2C2];
  s16 field_326;
  u8 unknown_328[0x58];
  f32 field_380;
};

struct E_800D7274 { s32 f0; s32 f4; s32 f8; s32 fc; };

struct D_800D7274 { u8 pad[0x42c]; E_800D7274 *entries; };

struct O_800D7274 { u8 pad[0x24]; s32 f24; u8 pad2[0xc]; s32 f34; };

struct Sub_800D5100 { u8 pad[0x18]; s32 f18; };

struct Obj_800D5100 { u8 pad[0x2b0]; Sub_800D5100 *f2b0; };

struct Obj_800D5150 { u8 pad[0x334]; s32 f334; u8 pad2[0x368 - 0x338]; s32 f368; };

struct VBase_14_800D5570 { char pad[0x14]; };

struct VObj_14_800D5570 : VBase_14_800D5570 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4();
    virtual s32 m5();
};

struct Obj_800D5570 { u8 pad0[0x38]; u8 sub38[0xB8 - 0x38]; s16 fb8; u8 padba[0x326 - 0xBA]; s16 f326; s16 state; };

typedef struct Ene_800D51C8 {
    u8 pad0[0xB8];
    s16 fB8;
    u8 padBA[0x326 - 0xBA];
    s16 state;
    s16 f328;
    u8 pad32A[0x34C - 0x32A];
    void *f34C;
} Ene_800D51C8;

struct Base_800D64F0 {
    char pad[0x18];
};

struct Ene_800D64F0 : Base_800D64F0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79(); virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83(); virtual void v84(); virtual void v85(); virtual void v86(); virtual void v87(); virtual void v88(); virtual void v89(); virtual void v90(); virtual void v91(); virtual void v92(); virtual void v93(); virtual void v94();
    virtual void m95();
    u8 pad1C[0xB4 - 0x1C];
    u32 fB4;
    s16 fB8;
    u8 padBA[0x326 - 0xBA];
    s16 state;
    s16 sub;
    u8 pad32A[0x338 - 0x32A];
    s16 target;
    u8 pad33A[0x350 - 0x33A];
    f32 *param;
    u8 pad354[0x390 - 0x354];
    s32 f390;
};

typedef struct Ene_800D52DC {
    u8 pad0[0xB8];
    s16 fB8;
    u8 padBA[0x326 - 0xBA];
    s16 state;
    s16 f328;
    u8 pad32A[0x34C - 0x32A];
    void *f34C;
} Ene_800D52DC;

struct Vec_800D57C8 { s32 x, y, z; };

struct Vec_800D6618 { f32 x, y, z; };

struct Stack_800D4D74 {
    s32 sp8;
    f32 spC;
    f32 sp10;
};

struct Vec_800D6110 { f32 x, y, z; };

struct VBase_18_800D6110 { char pad[0x18]; };

struct VObj_18_800D6110 : VBase_18_800D6110 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16();
    virtual s32 m17(s32);
    virtual void m18(); virtual void m19(); virtual void m20(); virtual void m21();
    virtual void m22(); virtual void m23(); virtual void m24(); virtual void m25();
    virtual void m26(); virtual void m27(); virtual void m28(); virtual void m29();
    virtual void m30(); virtual void m31(); virtual void m32(); virtual void m33();
    virtual void m34(); virtual void m35(); virtual void m36(); virtual void m37();
    virtual void m38(); virtual void m39(); virtual void m40(); virtual void m41();
    virtual void m42(); virtual void m43(); virtual void m44(); virtual void m45();
    virtual void m46(); virtual void m47(); virtual void m48(); virtual void m49();
    virtual void m50(); virtual void m51(); virtual void m52(); virtual void m53();
    virtual void m54(); virtual void m55(); virtual void m56(); virtual void m57();
    virtual void m58(); virtual void m59(); virtual void m60(); virtual void m61();
    virtual void m62(); virtual void m63(); virtual void m64(); virtual void m65();
    virtual void m66(); virtual void m67(); virtual void m68(); virtual void m69();
    virtual void m70(); virtual void m71(); virtual void m72(); virtual void m73();
    virtual void m74(); virtual void m75(); virtual void m76(); virtual void m77();
    virtual void m78(); virtual void m79(); virtual void m80(); virtual void m81();
    virtual void m82(); virtual void m83(); virtual void m84(); virtual void m85();
    virtual void m86(); virtual void m87(); virtual void m88(); virtual void m89();
    virtual void m90(); virtual void m91(); virtual void m92(); virtual void m93();
    virtual void m94(); virtual void m95(); virtual void m96();
    virtual void m97();
};

struct Pl_800D6110 { u8 pad0[0x38]; Vec_800D6110 pos; u8 pad44[0x2FC - 0x44]; Vec_800D6110 p2fc; };

struct Model_800D6110 { u8 pad0[0xC]; f32 radius; u8 pad10[8]; u32 flags; };

struct Obj_800D6110 : VObj_18_800D6110 {
    u8 pad1C[0x38 - 0x1C]; Vec_800D6110 pos; u8 pad44[0xA4 - 0x44]; Model_800D6110 *model;
    u8 padA8[0xB8 - 0xA8]; s16 fb8; u8 padBA[0x2A8 - 0xBA]; Pl_800D6110 *f2a8;
    u8 pad2ac[0x308 - 0x2AC]; u8 ang308[0x326 - 0x308]; s16 f326; s16 f328;
    u8 pad32a[0x338 - 0x32A]; u16 f338; u8 pad33a[0x350 - 0x33A]; f32 *f350;
    u8 pad354[0x374 - 0x354]; s16 f374; u8 pad376[0x398 - 0x376]; f32 f398;
    u8 pad39c[0x3D4 - 0x39C]; f32 f3d4;
};

struct Vec_800D5BCC { f32 x, y, z; };

struct Param_800D5BCC { u8 pad0[4]; f32 speed; s32 turn; };

struct Sub_800D5BCC { u8 pad0[0xC]; f32 fC; };

struct Lia_800D5BCC {
    u8 pad0[0x38];
    Vec_800D5BCC pos;
    Vec_800D5BCC prev;
    Vec_800D5BCC home;
    u8 pad5C[0x60 - 0x5C];
    s32 angle;
    u8 pad64[0xA4 - 0x64];
    Sub_800D5BCC *fA4;
    u8 padA8[0xB8 - 0xA8];
    s16 fB8;
    u8 padBA[0x290 - 0xBA];
    Vec_800D5BCC f290;
    Vec_800D5BCC f29C;
    u8 pad2A8[0x2FC - 0x2A8];
    Vec_800D5BCC f2FC;
    u8 pad308[0x328 - 0x308];
    s16 state;
    u8 pad32A[0x348 - 0x32A];
    Lia_800D5BCC *partner;
    u8 pad34C[0x350 - 0x34C];
    Param_800D5BCC *param;
    u8 pad354[0x358 - 0x354];
    f32 f358;
    u8 pad35C[0x378 - 0x35C];
    s32 f378;
    s32 count;
    u8 pad380[0x394 - 0x380];
    f32 f394;
};

struct VBase_18_4c2345 { char pad[0x18]; };
struct VObj_18_4c2345 : VBase_18_4c2345 {
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
    virtual s32 m79(s32);
    virtual s32 m80();
};

void move_with_wall_slide(u8 *arg0);

extern "C" {
f32 random_ratio__9TObjCharaFv(void *);
s32 play_sound_effect(void *, void *, int, int);
void TObjEneMerillLia__sub_800D4EC8(s32 arg0);
void vfunc_99__16TObjEneMerillLiaFv(s32 arg0);
void vfunc_98__16TObjEneMerillLiaFv(s32 arg0);
void vfunc_97__16TObjEneMerillLiaFv(s32 arg0);
void vfunc_96__16TObjEneMerillLiaFv(s32 arg0);
void TObjEneMerillLia__sub_800D501C(s32 arg0);
void TObjPlayer__sub_800D92BC(s32 point, s32 delay);
f32 vec3_add_to(void *, void *);
s32 rotate_vector_by_matrix(int, void *, void *);
s32 rotate_matrix_y(int, int);
s32 push_matrix_from(void *);
s32 pop_matrix();
extern RecoveredGlobal_800D5060_lbl_8058D490 identity_matrix;
extern const f32 TObjEneMerillLia__data_805DA300;
extern const f32 lbl_805DA304;
extern const f32 TObjEneMerillLia__data_805DA308;
void vfunc_94__16TObjEneMerillLiaFv(u8 *arg0);
extern const f32 lbl_805DA2EC;
extern const f32 lbl_805DA334;
extern const f32 lbl_805DA338;
s32 copy_position__20TBoss3VoloptHiraisinFv(void *);
s32 get_current_floor();
f32 xz_distance_squared(void *, void *);
void *get_player_by_client_id(s32 i);
s32 submit_cursor_candidate(void *, int);
extern const f32 TObjEneMerillLia__data_805DA2F4;
void run_task__16TObjEneMerillLiaFv(u8 *arg0);
void restore_scene_lighting(void);
void select_actor_lighting(s32 obj);
s32 defer_render__7TObjectFv(void *);
void translate_matrix(u32 arg0, f32 x, f32 y, f32 z);
s32 push_matrix();
f32 post_translate_matrix(void *);
void draw_chunk_object(void *child);
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
extern const f32 lbl_805DA314;
extern const f32 lbl_805DA324;
extern const f32 lbl_805DA328;
extern const f32 lbl_805DA32C;
extern const f32 lbl_805DA330;
void render__16TObjEneMerillLiaFv(u8 *arg0);
extern u32 TObjEneMerillLia__entry_params_resource;
extern s32 game_difficulty_selection;
s32 TObjEneMe3SinowZoa__sub_800D758C(void *);
s32 advance_animation_playback(void *);
s32 obj_testFlags30__14TObjCollidableFUl(void *, int);
void vfunc_59__16TObjEneMerillLiaFv(Ene_800D51C8 *arg0);
s16 find_nearest_visible_player(void *, s32, f32);
s32 obj_setFlags30(void *, s32);
void vfunc_83__16TObjEneMerillLiaFv(Ene_800D64F0 *arg0);
void vfunc_60__16TObjEneMerillLiaFv(Ene_800D52DC *arg0);
s32 minimap_render_dot(void *, int, int, int);
s32 create__9TTecKafunFlllllff(void *, void *, int, int, int, f32, f32);
s32 matrix_mult_vec(int, void *, void *);
extern u32 TObjEneMerillLia__rock_param_table;
extern s32 anim_model_matrix_array;
extern const f32 lbl_805DA30C;
extern const f32 lbl_805DA310;
s32 apply_actor_gravity(void *, int, f32);
s32 enemy_move_toward(void *, s32, void *, int, f32);
f32 horizontal_distance_squared(void *, void *);
s32 test_elt_flag__13TUnk_80493450Fll(void *, int, int);
extern const f32 lbl_805DA31C;
extern const f32 lbl_805DA320;
void beast_update_approach__16TObjEneMerillLiaFv(u8 *arg0);
void attach_particle_model(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 farg0);
s32 *csnVectorUnder(s32 arg0, u32 *arg1, s32 arg2);
void *spawn_particle_effect(void *pos, s32 id);
void fn_800D88E4(void *pos);
s32 rand(void);
extern s32 actor_frame_tick;
extern const f32 lbl_805DA2F0;
extern const f32 lbl_805DA2F8;
extern const f32 lbl_805DA2FC;
void spawn_ground_effect__16TObjEneMerillLiaFPv(u8 *arg0);
f32 enemy_backstep_from_point(void *, void *, f32);
u32 csnVector(void *, void *, s32);
f32 normalize_vector(void *);
extern const f32 lbl_805DA318;
void beast_update_group_chase__16TObjEneMerillLiaFv(Obj_800D6110 *arg0);
void enemy_wander_home__9TObjEnemyFlfff(void *, s32, f32, f32, f32);
f32 fabs_float(f32);
f64 atan2_float(f32, f32);
void link_chain_nodes__10TObjPlayerFPvPvPv(void *, void *, void *);
s32 approach_angle_limited(s32, s32, s32);
s32 project_actor_to_ground(void *, void *, s32);
s32 subtract_vector(void *, void *);
s32 pop_matrices(int);
extern Vec_800D5BCC scratch_vec;
extern Vec_800D5BCC lbl_8050BF00;
void TObjEneMerillLia__sub_800D5BCC(u8 *arg0);
void * TObjEneMerillLia__create(void *arg0);
void vfunc_101__16TObjEneMerillLiaFv(void);
void vfunc_93__16TObjEneMerillLiaFv(void);
void *__dt__16TObjEneMerillLiaFPvs(void *arg0, s16 arg1);
void vfunc_58__16TObjEneMerillLiaFv(void *arg0);
void TLobby__sub_8001FE7C(void*, int);
void *__ct__11TObjControlFP7TObject(void *, void *);
void free_collision_body_parts(void *);
void *TObjEneMerillLia__ct(void *, void *, void *);
void *__dt__13TUnk_80493450Fv(void *arg0, s16 arg1);
void __dl__7TObjectFPv(void *);
void *__dt__13TUnk_80494938Fv(void *arg0, s16 arg1);
void *__nw__7TObjectFUl(int);
s32 is_split_screen(void);
u8 *load_resource_from_descriptor(void *, s32, BmlResourceDescriptor *, s32, s32, s32);
void TObjEneMerillLia__sub_800D6D64(void);

extern "C" void vfunc_6__8TObjBaseFPsl();
extern "C" void TObjEneMerillLia__sub_800D59E4(u8 *arg0);
extern "C" void vfunc_29__9TObjCharaFv();
extern "C" void recalc_stats__9TObjCharaFv();
extern "C" void consume_timer_field__9TObjCharaFl();
extern "C" void vfunc_67__9TObjCharaFf();
extern "C" void vfunc_66__9TObjCharaFv();
extern "C" void get_anim_node_position__9TObjCharaFlP3Vec();
extern "C" void apply_slow_status__9TObjCharaFv();
extern "C" void update_shock_clock__9TObjCharaFv();
extern "C" void vfunc_43__9TObjCharaFv();
extern "C" void vfunc_18__9TObjCharaFPUc();
extern "C" void interact__14TObjCollidableFl();
extern "C" void vfunc_100__13TUnk_80493450Fv();
extern "C" void vfunc_89__13TUnk_80493450Fv();
extern "C" void update_turn_toward_target__13TUnk_80493450Fv();
extern "C" void vfunc_95__13TUnk_80493450Fv();
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
extern "C" void beast_retire_corpse__13TUnk_80493450Fv();
extern "C" void beast_select_target();
extern "C" void beast_update_attack__13TUnk_80493450Fv();
extern "C" void beast_update_dead__13TUnk_80493450Fv();
extern "C" void calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf();
extern "C" void vfunc_79__9TObjEnemyFPl();
extern "C" void classify_actor_view_detail__8TObjBaseFfff();
extern "C" void clear_all_status_effects__9TObjCharaFv();
extern "C" void vfunc_61__13TUnk_80493450Fv();
extern "C" void clear_harmful_statuses__9TObjCharaFv();
extern "C" void cure_paralysis__9TObjCharaFv();
extern "C" void cure_poison_ailment__9TObjCharaFv();
extern "C" void enemy_spawn_jellen_effect__9TObjCharaFv();
extern "C" void enemy_spawn_zalure_effect__9TObjCharaFv();
extern "C" void vfunc_62__13TUnk_80493450Fv();
extern "C" void enter_state_8__10TObjPlayerFv();
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
extern "C" void is_target_in_attack_range__9TObjCharaFv();
extern "C" u8 lbl_8043C478[];
extern "C" u8 lbl_8043C494[];
extern "C" u8 lbl_8043C4B0[];
extern "C" u8 lbl_8043C4D4[];
extern "C" u8 lbl_8043C4F4[];
extern "C" u8 lbl_8043C514[];
extern "C" u8 lbl_8043C538[];
extern "C" u8 lbl_8043C558[];
extern "C" u8 lbl_8043C578[];
extern "C" u8 lbl_8043C598[];
extern "C" u8 lbl_8043C5BC[];
extern "C" u8 lbl_8043C5DC[];
extern "C" u8 lbl_8043C5F4[];
extern "C" u8 lbl_8043C614[];
extern "C" u8 lbl_8043C634[];
extern "C" u8 lbl_8043C650[];
extern "C" u8 lbl_8043C66C[];
extern "C" u8 lbl_8043C68C[];
extern "C" void receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll();
extern "C" void receive_physical_attack__9TObjCharaFPvf();
extern "C" void receive_weapon_special_attack__9TObjCharaFPvPv();
extern "C" void apply_defense_stat_status__9TObjCharaFPv();
extern "C" void render_shadows__9TObjEnemyFv();
extern "C" void request_stand_action__13TUnk_80493450Fv();
extern "C" void reset_motion_fields__9TObjCharaFv();
extern "C" void reset_pose__9TObjCharaFv();
extern "C" void roll_physical_accuracy__9TObjCharaFPvlf();
extern "C" void select_melee_contact_body__9TObjCharaFPvf();
extern "C" void update_movement_status__13TUnk_80493450Fv();
extern "C" void trigger_switch_attack__9TObjCharaFv(s32 arg0);
extern "C" void try_start_action__9TObjCharaFll();
extern "C" void update_action_hold_status__13TUnk_80493450Fv();
extern "C" s32 vfunc_37__9TObjCharaFv(u8 *player);
extern "C" void update_actor_ground_y__9TObjCharaFv();
extern "C" s32 update_attack_stat_status__9TObjCharaFv(u8 *player);
extern "C" s32 update_defense_stat_status__9TObjCharaFv(u8 *player);
extern "C" void update_flag30_timer__9TObjCharaFv();
extern "C" void update_object_view_visibility__8TObjBaseFff();
extern "C" void update_poison_status__9TObjCharaFv();
extern void *lbl_804944D0[3];
extern void *lbl_804944DC[13];
extern void *lbl_80494520[3];
extern void *lbl_8049452C[13];
void *lbl_804944D0[3] = {
    (void *)&lbl_8043C478, (void *)&lbl_8043C494, (void *)0x0,
};
void *lbl_804944DC[13] = {
    (void *)&lbl_8043C4B0, (void *)&lbl_8043C4D4, (void *)&lbl_8043C4F4, (void *)&lbl_8043C514,
    (void *)&lbl_8043C538, (void *)&lbl_8043C558, (void *)&lbl_8043C578, (void *)&lbl_8043C598,
    (void *)&lbl_8043C5BC, (void *)&lbl_8043C5DC, (void *)&lbl_8043C5F4, (void *)&lbl_8043C614,
    (void *)0x0,
};
BmlResourceDescriptor bm_ene_re8_merill_lia_resource_descriptor = {
    (const char *)lbl_8043C634, (const char *const *)lbl_804944D0, (const char *const *)lbl_804944DC, 2, 12,
};
void *lbl_80494520[3] = {
    (void *)&lbl_8043C650, (void *)&lbl_8043C66C, (void *)0x0,
};
void *lbl_8049452C[13] = {
    (void *)&lbl_8043C4B0, (void *)&lbl_8043C4D4, (void *)&lbl_8043C4F4, (void *)&lbl_8043C514,
    (void *)&lbl_8043C538, (void *)&lbl_8043C558, (void *)&lbl_8043C578, (void *)&lbl_8043C598,
    (void *)&lbl_8043C5BC, (void *)&lbl_8043C5DC, (void *)&lbl_8043C5F4, (void *)&lbl_8043C614,
    (void *)0x0,
};
BmlResourceDescriptor bm_ene_re8_merill_lia_low_resource_descriptor = {
    (const char *)lbl_8043C68C, (const char *const *)lbl_80494520, (const char *const *)lbl_8049452C, 2, 12,
};
void *lbl_80494570[56] = {
    (void *)0x10000, (void *)0x5, (void *)0x3f19999a, (void *)0x1,
    (void *)0x10001, (void *)0x6, (void *)0x3f4ccccd, (void *)0x1,
    (void *)0x10002, (void *)0x8, (void *)0x3f19999a, (void *)0x1,
    (void *)0x20000, (void *)0x1, (void *)0x3f4ccccd, (void *)0x4,
    (void *)0x20000, (void *)0x2, (void *)0x3f800000, (void *)0x4,
    (void *)0x10000, (void *)0x9, (void *)0x3f800000, (void *)0x1,
    (void *)0x20000, (void *)0x3, (void *)0x3f4ccccd, (void *)0x8,
    (void *)0x20000, (void *)0x7, (void *)0x3f4ccccd, (void *)0x20,
    (void *)0x30000, (void *)0x4, (void *)0x3f19999a, (void *)0x10,
    (void *)0x30000, (void *)0x4, (void *)0x3f19999a, (void *)0x10,
    (void *)0x20000, (void *)0x5, (void *)0x3f19999a, (void *)0x20,
    (void *)0x20000, (void *)0x0, (void *)0x3f000000, (void *)0x20,
    (void *)0x20000, (void *)0xa, (void *)0x3f333333, (void *)0x4,
    (void *)0x20001, (void *)0xb, (void *)0x3f19999a, (void *)0x20,
};
void *lbl_80494650[21] = {
    (void *)0x43610000, (void *)0x3ecccccd, (void *)0x400, (void *)0x0,
    (void *)0x1e0000, (void *)0x1, (void *)0x0, (void *)0x437a0000,
    (void *)0x3f0ccccd, (void *)0x400, (void *)0x0, (void *)0x1e0000,
    (void *)0x1, (void *)0x0, (void *)0x43960000, (void *)0x3f333333,
    (void *)0x400, (void *)0x0, (void *)0x1e0000, (void *)0x1,
    (void *)0x0,
};
void *lbl_804946A4[33] = {
    (void *)0x0, (void *)0x40f00000, (void *)0x0, (void *)0x41000000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x40f00000, (void *)0x0, (void *)0x41000000, (void *)0x0,
    (void *)0x0, (void *)0x8003, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x41200000,
    (void *)0x0, (void *)0x41000000, (void *)0x0, (void *)0x0,
    (void *)0x8003, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0,
};
void *lbl_80494728[103] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__16TObjEneMerillLiaFPvs, (void *)&run_task__16TObjEneMerillLiaFv,
    (void *)&render__16TObjEneMerillLiaFv, (void *)&render_shadows__9TObjEnemyFv, (void *)&vfunc_6__8TObjBaseFPsl, (void *)&apply_object_set_data__8TObjBaseFPv,
    (void *)&reset_motion_fields__9TObjCharaFv, (void *)&get_center__9TObjCharaFv, (void *)&update_object_view_visibility__8TObjBaseFff, (void *)&classify_actor_view_detail__8TObjBaseFfff,
    (void *)&get_name__9TObjEnemyFv, (void *)&interact__14TObjCollidableFl, (void *)&add_actor_exp__9TObjCharaFl, (void *)&consume_timer_field__9TObjCharaFl,
    (void *)&get_actor_level_index__9TObjCharaFv, (void *)&update_actor_ground_y__9TObjCharaFv, (void *)&vfunc_18__9TObjCharaFPUc, (void *)&is_actor_cadence_frame__9TObjCharaFl,
    (void *)&select_melee_contact_body__9TObjCharaFPvf, (void *)&calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf, (void *)&receive_physical_attack__9TObjCharaFPvf, (void *)&receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll,
    (void *)&receive_weapon_special_attack__9TObjCharaFPvPv, (void *)&apply_knockback_from_attacker__9TObjCharaFPUcf, (void *)&try_start_action__9TObjCharaFll, (void *)&roll_physical_accuracy__9TObjCharaFPvlf,
    (void *)&beast_select_target, (void *)&vfunc_29__9TObjCharaFv, (void *)&is_target_in_attack_range__9TObjCharaFv, (void *)&test_flag_256__13TUnk_80493450Fv,
    (void *)&test_flag30_512__9TObjCharaFv, (void *)&has_flag_0x800__9TObjCharaFv, (void *)&test_flag_1000__9TObjCharaFv, (void *)&update_poison_status__9TObjCharaFv,
    (void *)&update_action_hold_status__13TUnk_80493450Fv, (void *)&vfunc_37__9TObjCharaFv, (void *)&update_flag30_timer__9TObjCharaFv, (void *)&update_movement_status__13TUnk_80493450Fv,
    (void *)&update_shock_clock__9TObjCharaFv, (void *)&update_attack_stat_status__9TObjCharaFv, (void *)&update_defense_stat_status__9TObjCharaFv, (void *)&vfunc_43__9TObjCharaFv,
    (void *)&apply_poison_status__9TObjCharaFv, (void *)&apply_paralysis__9TObjCharaFv, (void *)&apply_slow_status__9TObjCharaFv, (void *)&apply_confusion_status__9TObjCharaFv,
    (void *)&apply_movement_ailment__9TObjCharaFl, (void *)&apply_shock_status__9TObjCharaFv, (void *)&clear_harmful_statuses__9TObjCharaFv, (void *)&apply_attack_stat_status__9TObjCharaFPv,
    (void *)&apply_defense_stat_status__9TObjCharaFPv, (void *)&cure_poison_ailment__9TObjCharaFv, (void *)&cure_paralysis__9TObjCharaFv, (void *)&clear_all_status_effects__9TObjCharaFv,
    (void *)&apply_action_hold_status__9TObjCharaFf, (void *)&apply_anti_technique__9TObjCharaFl, (void *)&vfunc_58__16TObjEneMerillLiaFv, (void *)&vfunc_59__16TObjEneMerillLiaFv,
    (void *)&vfunc_60__16TObjEneMerillLiaFv, (void *)&vfunc_61__13TUnk_80493450Fv, (void *)&vfunc_62__13TUnk_80493450Fv, (void *)&enter_state_8__10TObjPlayerFv,
    (void *)&reset_pose__9TObjCharaFv, (void *)&get_anim_node_position__9TObjCharaFlP3Vec, (void *)&vfunc_66__9TObjCharaFv, (void *)&vfunc_67__9TObjCharaFf,
    (void *)&get_pos__9TObjCharaFl, (void *)&apply_switch_attack__9TObjCharaFv, (void *)&enemy_spawn_jellen_effect__9TObjCharaFv, (void *)&trigger_switch_attack__9TObjCharaFv,
    (void *)&enemy_spawn_zalure_effect__9TObjCharaFv, (void *)&recalc_stats__9TObjCharaFv, (void *)&vfunc_74__9TObjEnemyFl, (void *)&vfunc_75__9TObjCharaFf,
    (void *)&vfunc_76__9TObjCharaFv, (void *)&vfunc_77__9TObjCharaFv, (void *)&vfunc_78__9TObjCharaFl, (void *)&vfunc_79__9TObjEnemyFPl,
    (void *)&apply_hit_message_flags__9TObjEnemyFPv, (void *)&apply_set_data__9TObjEnemyFPv, (void *)&clear_lobby_object_state__9TObjEnemyFv, (void *)&vfunc_83__16TObjEneMerillLiaFv,
    (void *)&TObjEneMerillLia__sub_800D5BCC, (void *)&update_turn_toward_target__13TUnk_80493450Fv, (void *)&beast_update_approach__16TObjEneMerillLiaFv, (void *)&beast_update_group_chase__16TObjEneMerillLiaFv,
    (void *)&beast_update_attack__13TUnk_80493450Fv, (void *)&vfunc_89__13TUnk_80493450Fv, (void *)&TObjEneMerillLia__sub_800D59E4, (void *)&beast_update_dead__13TUnk_80493450Fv,
    (void *)&beast_retire_corpse__13TUnk_80493450Fv, (void *)&vfunc_93__16TObjEneMerillLiaFv, (void *)&vfunc_94__16TObjEneMerillLiaFv, (void *)&vfunc_95__13TUnk_80493450Fv,
    (void *)&vfunc_96__16TObjEneMerillLiaFv, (void *)&vfunc_97__16TObjEneMerillLiaFv, (void *)&vfunc_98__16TObjEneMerillLiaFv, (void *)&vfunc_99__16TObjEneMerillLiaFv,
    (void *)&vfunc_100__13TUnk_80493450Fv, (void *)&vfunc_101__16TObjEneMerillLiaFv, (void *)&request_stand_action__13TUnk_80493450Fv,
};
#define lbl_80494728 ((s32 *)lbl_80494728)

// The motion set TLobby::spawn_npc_enemy copies for each spawned part.
struct NpcSpawnMotions { void *motions; void *actions; s32 initial_action; s32 counts; };

// One 0x2C-byte record of the collision body table init_collision_body_parts reads.
struct CollisionPartRecord { u8 pad_0[0xC]; f32 radius; u8 pad_10[0x1C]; };

__declspec(section ".rodata") static NpcSpawnMotions merill_lia_spawn_motions = {0, lbl_80494570, 2, 0xC0000};
static const Vec_800D57C8 zero_offset = {0, 0, 0};

void TObjEneMerillLia::vfunc_101() {  }

void spawn_ground_effect__16TObjEneMerillLiaFPv(u8 *arg0) {
    typedef char sp8_offset[(offsetof(Stack_800D4D74, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_800D4D74, spC) == 0x4) ? 1 : -1];
    Stack_800D4D74 stack;
    s32 temp_r29;
    s32 particle_effect;
    u8 *temp_r3;
    VecCopy((Vec *)&stack.sp8, (const Vec *)(arg0 + 0x38));
    stack.spC += lbl_805DA2EC;
    temp_r3 = (u8 *)(csnVectorUnder((s32)&stack.sp8, (u32 *)(arg0 + 0x120), 5));
    if ((temp_r3 != NULL) && (*(s32 *)((s8 *)temp_r3 + 0) & 4)) {
        if (((s32) ((f32) actor_frame_tick * (lbl_805DA2F0 * (f32) rand())) % 5) == 0) {
            particle_effect = (s32)spawn_particle_effect((void *)(*(s32 *)((s8 *)temp_r3 + 4) + 0x38), 0x49);
            if (particle_effect != 0) {
                attach_particle_model((u8 *)particle_effect, (s32)(TParticleCtrl::get_particle_model(2)), (s32)(TParticleCtrl::get_instance()), 0, 1, (f32)TObjEneMerillLia__data_805DA2F4);
            }
            spawn_particle_effect((void *)(*(s32 *)((s8 *)temp_r3 + 4) + 0x38), 0xA4);
        }
        if ((objInBand((GameObj *)arg0, (f32)lbl_805DA2F8) != 0) || (objInBand((GameObj *)((GameObj *)arg0), (f32)((f32)lbl_805DA2FC)) != 0)) {
            fn_800D88E4((arg0 + 0x38));
        }
    }
}

void TObjEneMerillLia__sub_800D4EC8(s32 arg0) {
    play_sound_effect((void *) (((TObjEnemy *)((void *)arg0))->remap_sound_for_area((s32)(0x3AD04))), (void *)(arg0 + 0x38), 0, 0);
}

void TObjEneMerillLia::vfunc_99() {
    s32 arg0 = (s32)this;
    play_sound_effect((void *) (((TObjEnemy *)((void *)arg0))->remap_sound_for_area((s32)(0x3B205))), (void *)(arg0 + 0x38), 0, 0);
}

void TObjEneMerillLia::vfunc_98() {
    s32 arg0 = (s32)this;
    play_sound_effect((void *) (((TObjEnemy *)((void *)arg0))->remap_sound_for_area((s32)(0x3AD00))), (void *)(arg0 + 0x38), 0, 0);
}

void TObjEneMerillLia::vfunc_97() {
    s32 arg0 = (s32)this;
    play_sound_effect((void *) (((TObjEnemy *)((void *)arg0))->remap_sound_for_area((s32)(0x3B201))), (void *)(arg0 + 0x38), 0, 0);
}

void TObjEneMerillLia::vfunc_96() {
    s32 arg0 = (s32)this;
    play_sound_effect((void *) (((TObjEnemy *)((void *)arg0))->remap_sound_for_area((s32)(0x3AB02))), (void *)(arg0 + 0x38), 0, 0);
}

void TObjEneMerillLia__sub_800D501C(s32 arg0) {
    play_sound_effect((void *) (((TObjEnemy *)((void *)arg0))->remap_sound_for_area((s32)(0x3B206))), (void *)(arg0 + 0x38), 0, 0);
}

void TObjEneMerillLia::vfunc_94() {
    u8 *arg0 = (u8 *)this;
    typedef char sp8_offset[(offsetof(Stack_800D5060, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_800D5060, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_800D5060, sp10) == 0x8) ? 1 : -1];
    Stack_800D5060 stack;
    stack.sp8 = TObjEneMerillLia__data_805DA300;
    stack.spC = lbl_805DA304;
    stack.sp10 = TObjEneMerillLia__data_805DA308 * *(f32 *)(this->m_2b0 + 0x10);
    push_matrix_from((void *)&identity_matrix.value);
    rotate_matrix_y(0, this->rotation_y);
    rotate_vector_by_matrix(0, (void *)&stack.sp8, (void *)&stack.sp8);
    pop_matrix();
    vec3_add_to((void *)&stack.sp8, (void *)(arg0 + 0x38));
    ((TObjPlayer *)(&stack.sp8))->spawn_ground_effect(0x23);
    TObjPlayer__sub_800D92BC((s32)&stack.sp8, 0xF);
}

void TObjEneMerillLia::vfunc_93() {  }

s32 TObjEneMerillLia::get_clamped_level() {
    TObjEneMerillLia *self = this;
    Sub_800D5100 *p = *(Sub_800D5100 * *)&self->m_2b0;
    s32 v = 0;
    if (p != 0) {
        v = p->f18;
        if (v < 0) {
            v = 0;
        } else if (game_difficulty_selection == 3) {
            if (v > 0x1d) {
                v = 0x1d;
            }
        } else if (v > 0xe) {
            v = 0xe;
        }
    }
    return v;
}

void TObjEneMerillLia::clamp_and_apply_mode_param() {
    Obj_800D5150 *self = (Obj_800D5150 *)this;
    if (self->f334 < 0) {
        self->f334 = 0;
    } else if (self->f334 > 1) {
        self->f334 = 1;
    }
    switch (self->f334) {
    case 1:
        self->f368 = 1;
        ((TObjEnemy *)self)->set_param(0x35);
        break;
    default:
        self->f368 = 0;
        ((TObjEnemy *)self)->set_param(0x34);
        break;
    }
}

void TObjEneMerillLia::vfunc_59() {
    Ene_800D51C8 *arg0 = (Ene_800D51C8 *)this;
    if (obj_testFlags30__14TObjCollidableFUl(arg0, 0x1000) != 0) {
        this->mode = 4;
    }
    switch (this->mode) {
    case 0:
    case 2:
    case 3:
    case 10:
    case 11:
    case 12:
    case 13:
        break;
    case 1:
        this->phase = 0;
        if (this->children == NULL) {
            this->mode = 3;
            this->m_b8 = 7;
        } else {
            this->mode = 2;
            this->m_b8 = 10;
        }
        ((TObjBase *)arg0)->obj_clearFlags30(0x4040000);
        ((TObjCollidable *)arg0)->clear_player_status_flag(0, 0xA000000);
        break;
    case 4:
        this->m_b8 = 5;
        break;
    default:
        this->mode = 3;
        this->phase = 1;
        this->m_b8 = 2;
        ((TObjBase *)arg0)->obj_clearFlags30(0x4040000);
        ((TObjCollidable *)arg0)->clear_player_status_flag(0, 0xA000000);
        break;
    }
}

void TObjEneMerillLia::vfunc_60() {
    Ene_800D52DC *arg0 = (Ene_800D52DC *)this;
    switch (this->mode) {
    case 0:
    case 2:
    case 4:
    case 10:
    case 11:
    case 12:
    case 13:
        break;
    case 1:
        this->phase = 0;
        if (this->children == NULL) {
            this->mode = 3;
            this->m_b8 = 7;
        } else {
            this->mode = 2;
            this->m_b8 = 10;
        }
        ((TObjBase *)arg0)->obj_clearFlags30(0x4040000);
        ((TObjCollidable *)arg0)->clear_player_status_flag(0, 0xA000000);
        break;
    default:
        this->mode = 5;
        this->phase = 1;
        if (TObjEneMerillLia__data_805DA308 < random_ratio__9TObjCharaFv(arg0)) {
            this->m_b8 = 3;
        } else {
            this->m_b8 = 4;
        }
        obj_setFlags30(arg0, 0x200000);
        ((TObjBase *)arg0)->obj_clearFlags30(0x4040000);
        ((TObjCollidable *)arg0)->clear_player_status_flag(0, 0xA000000);
        break;
    }
}

void TObjEneMerillLia::vfunc_58() {
    s32 temp_r0;

    temp_r0 = this->mode;
    if (temp_r0 != 4) {
        if (temp_r0 < 4) {
            if (temp_r0 < 3) {
                if (temp_r0 >= 0) {
                    goto block_end;
                }
                goto block_7;
            } else {
                goto block_7;
            }
        } else if ((temp_r0 >= 0xE) || (temp_r0 < 0xB)) {
block_7:
            if ((s32) this->m_390 != 0) {
                this->mode = 0;
            } else {
                this->mode = 1;
            }
            this->phase = 0;
            obj_setFlags30(this, 0x04040000);
            set_indexed_flags(0, 0x0A000000);
        }
    }
block_end:
    ;
}

void TObjEneMerillLia::reset_state_clear_status() {
    u8 *arg0 = (u8 *)this;
    this->mode = 0xB;
    this->phase = 0;
    this->target = 0;
    ((TObjCollidable *)arg0)->clear_player_status_flag(0, (s32)(0x0A000000U));
}

void TObjEneMerillLia::init_attack_state() {
    this->mode = 4;
    this->phase = 0;
    this->m_374 = (s16) this->m_3d8;
    obj_clearFlags30(0x04240000);
    clear_player_status_flag(0, 0x0A000000);
}

void TObjEneMerillLia::reset_action_state() {
    this->mode = 0xA;
    this->phase = 0;
    obj_setFlags30(this, 0x200000);
    obj_clearFlags30(0x04040000);
    clear_player_status_flag(0, 0x0A000000);
}

extern void *tl_04;

typedef struct RecoveredFields_800D6810_arg0 RecoveredFields_800D6810_arg0;
typedef struct Stack_800D6810 Stack_800D6810;
typedef struct VBase_14_fddec9 VBase_14_fddec9;
typedef struct VBase_18_ca64a0 VBase_18_ca64a0;
typedef struct VObj_14_fddec9 VObj_14_fddec9;
typedef struct VObj_18_ca64a0 VObj_18_ca64a0;

void TObjEneMerillLia::sub_800D5570() {
    Obj_800D5570 *arg0 = (Obj_800D5570 *)this;
    switch (this->phase) {
    case 0:
    default:
        this->phase = 1;
        this->m_b8 = 1;
        TObjEneMe3SinowZoa__sub_800D758C((u8 *)arg0 + 0x3A8);
        ((TBoss3Volopt *)(arg0->sub38))->play_area_sound_effect();
        break;
    case 1:
        spawn_ground_effect__16TObjEneMerillLiaFPv((u8 *)arg0);
        if (((VObj_14_800D5570 *)((u8 *)arg0 + 0x3A8))->m5() != 0) {
            this->phase = 2;
        }
        break;
    case 2:
        this->mode = 12;
        break;
    }
    advance_animation_playback(arg0);
}

#define arg0 ((Obj_800D5614 *)ov)
void TObjEneMerillLia::search_target(void *ov) {
    Pl_800D5614 *p;
    s32 v;
    arg0->f338 = find_nearest_visible_player(arg0, 0, *arg0->f350);
    if (arg0->f338 < 0x1000) {
        p = (Pl_800D5614 *)get_player_by_client_id(arg0->f338);
        if (p != NULL) {
            s32 w;
            v = get_current_floor();
            w = ((TObjPlayer *)p)->get_field_3e4();
            if (w == v) {
                if (xz_distance_squared(p->pos, arg0->pos) < arg0->f3d0 * arg0->f3d0) {
                    arg0->f2a8 = p;
                    arg0->f326 = 0;
                    arg0->f328 = 0;
                }
            }
        }
    }
    advance_animation_playback(arg0);
}
#undef arg0

#define arg0 ((u8 *)ov)
s32 TObjEneMerillLia::update_emerge_state(void *ov) {

    advance_animation_playback(arg0);
    switch (*(s16 *)((s8 *)arg0 + 0x328)) {
    case 0:
    default:
        if ((s32) *(s32 *)((s8 *)arg0 + 0x390) == 1) {
            *(s16 *)((s8 *)arg0 + 0x328) = 2;
        } else {
            *(s16 *)((s8 *)arg0 + 0x328) = 1;
            *(s16 *)((s8 *)arg0 + 0xB8) = 0xD;
            ((TObjCollidable *)arg0)->set_indexed_flags(0, 0x0A000000);
            obj_setFlags30(arg0, 0x04000000);
            TObjEneMerillLia__sub_800D501C((s32)arg0);
        }
        break;
    case 1:
        spawn_ground_effect__16TObjEneMerillLiaFPv(arg0);
        if ((u32) *(u32 *)((s8 *)arg0 + 0xB4) != 0x20U) {
            *(s16 *)((s8 *)arg0 + 0x328) = 2;
            *(s32 *)((s8 *)arg0 + 0x390) = 1;
            ((TObjCollidable *)arg0)->clear_player_status_flag(0, 0x0A000000);
            ((TObjBase *)arg0)->obj_clearFlags30(0x04040000);
        }
        break;
    case 2:
        *(s16 *)((s8 *)arg0 + 0x326) = 0xC;
        *(s16 *)((s8 *)arg0 + 0xB8) = 1;
        break;
    }
    ((TObjPlayer *)arg0)->update_collisions();
    ((TObjPlayer *)arg0)->update_enemy_collision_flags();
    minimap_render_dot(arg0 + 0x38, -0x5DB4, 1, 0);
}
#undef arg0

struct Obj_800D5100;
struct RecoveredGlobal_800D5060_lbl_8058D490;
#define arg0 ((u8 *)p)
s32 TObjEneMerillLia::update_kafun_attack(void *p) {
    Vec_800D57C8 sp14;
    advance_animation_playback(arg0);
    switch (*(s16 *)((s8 *)arg0 + 0x328)) {
    default:
    case 0:
        *(s16 *)((s8 *)arg0 + 0x328) = 1;
        *(s16 *)((s8 *)arg0 + 0xB8) = 0xC;
        obj_setFlags30(arg0, 0x200000);
        ((TObjBase *)arg0)->obj_clearFlags30(0x04040000);
        ((TObjCollidable *)arg0)->clear_player_status_flag(0, 0x0A000000);
        break;
    case 1:
        if (objInBand((GameObj *)(arg0), (f32)lbl_805DA30C) != 0) {
            advance_animation_playback(arg0);
            push_matrix_from(&identity_matrix);
            post_translate_matrix(arg0 + 0x38);
            rotate_matrix_y(0, *(s32 *)((s8 *)arg0 + 0x60));
            ((TObjEnemy *)arg0)->render_anim_model(lbl_805DA30C);
            pop_matrix();
            push_matrix_from((void *)(anim_model_matrix_array + 0x450));
            {
                Vec_800D57C8 sp8 = zero_offset;
                matrix_mult_vec(0, &sp8, &sp14);
            }
            pop_matrix();
            create__9TTecKafunFlllllff(arg0, &sp14, 0xF, 0xD3, ((TObjEneMerillLia *)arg0)->get_clamped_level(), *(f32 *)((s8 *)(((void **) TObjEneMerillLia__rock_param_table)[*(s32 *)((s8 *)arg0 + 0x334)]) + 0x10), lbl_805DA310);
            TObjEneMerillLia__sub_800D4EC8((s32)arg0);
        }
        if ((u32) *(u32 *)((s8 *)arg0 + 0xB4) != 4U) {
            *(s16 *)((s8 *)arg0 + 0x328) = 2;
            *(s16 *)((s8 *)arg0 + 0xB8) = 0;
            *(s16 *)((s8 *)arg0 + 0x33C) = 0xF;
        }
        break;
    case 2:
        (*(s16 *)((s8 *)arg0 + 0x33C))--;
        if (*(s16 *)((s8 *)arg0 + 0x33C) < 0) {
            ((TObjBase *)arg0)->obj_clearFlags30(0x200000);
            *(s16 *)((s8 *)arg0 + 0x33C) = 0;
            if (random_ratio__9TObjCharaFv(arg0) <= *(f32 *)((s8 *)arg0 + 0x3C4)) {
                ((TObjEneMerillLia *)arg0)->init_attack_state();
            } else {
                *(s16 *)((s8 *)arg0 + 0x326) = 1;
                *(s16 *)((s8 *)arg0 + 0x328) = 0;
                obj_setFlags30(arg0, 0x04040000);
                ((TObjCollidable *)arg0)->set_indexed_flags(0, 0x0A000000);
            }
        }
        break;
    }
    ((TObjPlayer *)arg0)->update_collisions();
    ((TObjPlayer *)arg0)->update_enemy_collision_flags();
    minimap_render_dot(arg0 + 0x38, -0x5DB4, 1, 0);
}
#undef arg0

f32 get_collision_body_radius(void *, s32);
s32 check_path_obstructed(void *, void *);

void TObjEneMerillLia__sub_800D59E4(u8 *arg0) {
    Vec_800D5BCC pos;

    advance_animation_playback(arg0);
    VecCopy((Vec *)&pos, (const Vec *)(arg0 + 0x2FC));
    scratch_vec.y = TObjEneMerillLia__data_805DA300;
    scratch_vec.x = TObjEneMerillLia__data_805DA300;
    scratch_vec.z = get_collision_body_radius(arg0, 0);
    push_matrix_from(&identity_matrix);
    rotate_matrix_y(0, -*(s32 *)((s8 *)arg0 + 0x60));
    rotate_vector_by_matrix(0, &scratch_vec, &scratch_vec);
    pop_matrix();
    vec3_add_to(&pos, &scratch_vec);
    pos.x = pos.x + *(f32 *)((s8 *)arg0 + 0x308);
    pos.z = pos.z + *(f32 *)((s8 *)arg0 + 0x310);
    if (check_path_obstructed(arg0, &pos) == 0) {
        move_with_wall_slide(arg0);
        *(f32 *)((s8 *)arg0 + 0x308) = *(f32 *)((s8 *)arg0 + 0x308) * TObjEneMerillLia__data_805DA308;
        *(f32 *)((s8 *)arg0 + 0x310) = *(f32 *)((s8 *)arg0 + 0x310) * TObjEneMerillLia__data_805DA308;
    } else {
        *(f32 *)((s8 *)arg0 + 0x310) = TObjEneMerillLia__data_805DA300;
        *(f32 *)((s8 *)arg0 + 0x308) = TObjEneMerillLia__data_805DA300;
    }
    ((TObjPlayer *)arg0)->update_collisions();
    ((TObjPlayer *)arg0)->update_enemy_collision_flags();
    if (objInBand((GameObj *)arg0, TObjEneMerillLia__data_805DA300) != 0) {
        ((TObjEneMerillLia *)arg0)->vfunc_97();
    }
    if (*(u32 *)((s8 *)arg0 + 0xB4) != 8) {
        ((TObjBase *)arg0)->obj_clearFlags30(0x600);
        ((TObjCollidable *)arg0)->clear_player_status_flag(0, 0x04000000);
        if ((f32)*(s16 *)((s8 *)arg0 + 0x32C) <= (f32)*(s16 *)((s8 *)arg0 + 0x2B8) * *(f32 *)((s8 *)arg0 + 0x3CC)) {
            ((TObjEneMerillLia *)arg0)->select_action_by_distance();
        }
        *(s16 *)((s8 *)arg0 + 0x33E) = *(s16 *)((s8 *)arg0 + 0x32C);
    }
    minimap_render_dot(arg0 + 0x38, -0x5DB4, 1, 0);
}

#pragma push
#pragma opt_common_subs off
#define o ((Lia_800D5BCC *)arg0)
void TObjEneMerillLia__sub_800D5BCC(u8 *arg0) {
    ((TUnk_80493450 *)o)->update_target_near_flag();
    ((TUnk_80493450 *)o)->sub_800C4E08();
    advance_animation_playback(o);
    if (o->state != 1) {
        o->state = 1;
        ((TUnk_80493450 *)o)->link_into_group_chain();
        o->f378 = ((TObjPlayer *)o)->is_action_available();
    }
    o->count = ((TUnk_80493450 *)o)->countChildren();
    {
        Lia_800D5BCC *p = o->partner;
        if (p != NULL) {
            s32 diff = p->count - o->count;
            if (diff > 1) {
                link_chain_nodes__10TObjPlayerFPvPvPv(o, p, o);
                o->count++;
                p->count--;
            } else if (diff < -1) {
                link_chain_nodes__10TObjPlayerFPvPvPv(o, o, p);
                o->count--;
                p->count++;
            }
        }
    }
    {
    f32 dist = horizontal_distance_squared(&o->pos, &o->home);
    f32 r = o->f358 + (o->param->speed + o->fA4->fC);
    if (r * r < dist) {
        Vec_800D5BCC *d;
        Vec_800D5BCC *v;
        s32 ang;
        VecCopy((Vec *)&o->f29C, (const Vec *)&o->home);
        VecCopy((Vec *)&o->f290, (const Vec *)&o->f2FC);
        VecCopy((Vec *)&o->prev, (const Vec *)&o->pos);
        VecCopy((Vec *)&scratch_vec, (const Vec *)&o->home);
        subtract_vector(&scratch_vec, &o->pos);
        d = &scratch_vec;
        ang = (s32)(10430.38043493439 * atan2_float(d->x, d->z));
        v = &lbl_8050BF00;
        v->x = v->y = TObjEneMerillLia__data_805DA300;
        v->z = o->f394;
        push_matrix_from(&identity_matrix);
        rotate_matrix_y(0, ang);
        rotate_vector_by_matrix(0, &lbl_8050BF00, &lbl_8050BF00);
        pop_matrices(1);
        vec3_add_to(&lbl_8050BF00, &o->pos);
        if (project_actor_to_ground(o, &lbl_8050BF00, 0) == 1) {
            o->fB8 = 2;
            VecCopy((Vec *)&o->pos, (const Vec *)&lbl_8050BF00);
            o->angle = approach_angle_limited(o->angle, ang, o->param->turn);
        } else {
            f32 rr = fabs_float(d->z);
            if (fabs_float(scratch_vec.x) < rr) {
                ang = (s32)(10430.38043493439 * atan2_float(scratch_vec.x, TObjEneMerillLia__data_805DA300));
            } else {
                ang = (s32)(10430.38043493439 * atan2_float(TObjEneMerillLia__data_805DA300, d->z));
            }
            v->y = TObjEneMerillLia__data_805DA300;
            lbl_8050BF00.x = TObjEneMerillLia__data_805DA300;
            v->z = o->f394;
            push_matrix_from(&identity_matrix);
            rotate_matrix_y(0, ang);
            rotate_vector_by_matrix(0, &lbl_8050BF00, &lbl_8050BF00);
            pop_matrices(1);
            vec3_add_to(&lbl_8050BF00, &o->pos);
            if (project_actor_to_ground(o, &lbl_8050BF00, 0) == 1) {
                o->fB8 = 2;
                VecCopy((Vec *)&o->pos, (const Vec *)&lbl_8050BF00);
                o->angle = approach_angle_limited(o->angle, ang, o->param->turn);
            } else {
                s32 ang2;
                rr = fabs_float(d->z);
                if (fabs_float(scratch_vec.x) < rr) {
                    ang2 = (s32)(10430.38043493439 * atan2_float(TObjEneMerillLia__data_805DA300, d->z));
                } else {
                    ang2 = (s32)(10430.38043493439 * atan2_float(scratch_vec.x, TObjEneMerillLia__data_805DA300));
                }
                v->y = TObjEneMerillLia__data_805DA300;
                lbl_8050BF00.x = TObjEneMerillLia__data_805DA300;
                v->z = o->f394;
                push_matrix_from(&identity_matrix);
                rotate_matrix_y(0, ang2);
                rotate_vector_by_matrix(0, &lbl_8050BF00, &lbl_8050BF00);
                pop_matrices(1);
                vec3_add_to(&lbl_8050BF00, &o->pos);
                if (project_actor_to_ground(o, &lbl_8050BF00, 0) == 1) {
                    o->fB8 = 2;
                    VecCopy((Vec *)&o->pos, (const Vec *)&lbl_8050BF00);
                    o->angle = approach_angle_limited(o->angle, ang2, o->param->turn);
                } else {
                    o->fB8 = 2;
                }
            }
        }
    } else if (o->count == 0 && TObjEneMerillLia__data_805DA300 < o->f358) {
        f32 w;
        o->fB8 = 2;
        w = o->f358;
        ((void (*)(void *, f32, f32, f32, s32))enemy_wander_home__9TObjEnemyFlfff)(o, o->param->speed, w, w, o->param->turn);
    } else {
        ((TObjEneMerillLia *)o)->reset_state_clear_status();
    }
    }
    if (obj_testFlags30__14TObjCollidableFUl(o, 0x800000) == 0) {
        apply_actor_gravity(o, 0, TObjEneMerillLia__data_805DA300);
    }
    ((TObjCollidable *)o)->refresh_collision_body_centers();
    minimap_render_dot(&o->pos, -0x5DB4, 1, 0);
    ((TObjBase *)o)->obj_clearFlags30(0x04240000);
    ((TObjCollidable *)o)->clear_player_status_flag(0, 0x0A000000);
}
#undef o
#pragma pop

#pragma push
#pragma fp_contract on
void TObjEneMerillLia::beast_update_group_chase() {
    Obj_800D6110 *arg0 = (Obj_800D6110 *)this;
    Vec_800D6110 save;
    Vec_800D6110 to;
    Vec_800D6110 d;
    f32 dist;
    advance_animation_playback(arg0);
    switch (arg0->f328) {
    case 0:
        arg0->f328 = 1;
        arg0->m97();
        break;
    case 1:
        if (arg0->f2a8 != NULL) {
            spawn_ground_effect__16TObjEneMerillLiaFPv((u8 *)arg0);
            save.x = arg0->pos.x;
            save.y = arg0->pos.y;
            save.z = arg0->pos.z;
            if (arg0->f3d4 <= TObjEneMerillLia__data_805DA300) {
                Vec_800D6110 a = arg0->f2a8->p2fc;
                dist = enemy_backstep_from_point(arg0, &a, arg0->f398);
            } else {
                Vec_800D6110 b = arg0->f2a8->p2fc;
                dist = enemy_backstep_from_point(arg0, &b, arg0->f3d4);
            }
            ((TObjEnemy *)arg0)->turn_toward_direction(((s32 *)arg0->f350)[2], (Vec *)arg0->ang308);
            arg0->f374--;
            if (dist < (arg0->f398 + arg0->model->radius) * (arg0->f398 + arg0->model->radius) || arg0->f374 < 0) {
                arg0->f328 = 2;
                arg0->f374 = 0;
            }
            ((TObjPlayer *)arg0)->update_collisions();
            ((TObjPlayer *)arg0)->update_enemy_collision_flags();
            if (arg0->model->flags & 0x380000) {
                arg0->f328 = 2;
                arg0->f374 = 0;
                break;
            }
            d.x = arg0->pos.x - save.x;
            d.y = arg0->pos.y - save.y;
            d.z = arg0->pos.z - save.z;
            normalize_vector(&d);
            to.x = lbl_805DA314 * d.x + arg0->pos.x;
            to.y = lbl_805DA314 * d.y + arg0->pos.y;
            to.z = lbl_805DA314 * d.z + arg0->pos.z;
            if (csnVector(&save, &to, 0x88E0) != 0) {
                arg0->f328 = 2;
                arg0->f374 = 0;
            }
            break;
        }
        if (arg0->m17(0x1E) != 0) {
            arg0->f338 = find_nearest_visible_player(arg0, 0, *arg0->f350);
        }
        if (arg0->f338 < 0x1000) {
            Pl_800D5614 *p = (Pl_800D5614 *)get_player_by_client_id(arg0->f338);
            if (p != NULL && ((TObjPlayer *)p)->get_field_3e4() == get_current_floor()) {
                arg0->f2a8 = (Pl_800D6110 *)p;
                break;
            }
            arg0->f2a8 = NULL;
            ((TObjEneMerillLia *)arg0)->reset_state_clear_status();
            break;
        }
        arg0->f2a8 = NULL;
        ((TObjEneMerillLia *)arg0)->reset_state_clear_status();
        break;
    case 2:
        ((TObjBase *)arg0)->obj_clearFlags30(0x1000);
        if (arg0->m17(0x1E) != 0) {
            arg0->f338 = find_nearest_visible_player(arg0, 0, *arg0->f350);
        }
        if (arg0->f338 < 0x1000) {
            Pl_800D5614 *p = (Pl_800D5614 *)get_player_by_client_id(arg0->f338);
            if (p != NULL && ((TObjPlayer *)p)->get_field_3e4() == get_current_floor() &&
                xz_distance_squared(p->pos, &arg0->pos) < lbl_805DA318) {
                arg0->f326 = 1;
                arg0->f328 = 0;
                arg0->fb8 = 0xA;
                ((TObjBase *)arg0)->obj_clearFlags30(0x4040000);
                ((TObjCollidable *)arg0)->clear_player_status_flag(0, 0xA000000);
                break;
            }
            ((TObjEneMerillLia *)arg0)->reset_state_clear_status();
        } else {
            ((TObjEneMerillLia *)arg0)->reset_state_clear_status();
        }
        break;
    }
    ((TObjPlayer *)arg0)->update_collisions();
    ((TObjPlayer *)arg0)->update_enemy_collision_flags();
    minimap_render_dot(&arg0->pos, -0x5DB4, 1, 0);
}
#pragma pop

void TObjEneMerillLia::vfunc_83() {
    Ene_800D64F0 *arg0 = (Ene_800D64F0 *)this;
    switch (arg0->sub) {
    case 0:
    default:
        if (arg0->f390 != 1) {
            arg0->sub = 2;
        } else {
            arg0->sub = 1;
            arg0->fB8 = 0xB;
            ((TObjCollidable *)arg0)->set_indexed_flags(0, 0xA000000);
            obj_setFlags30(arg0, 0x4000000);
            arg0->m95();
        }
        break;
    case 1:
        spawn_ground_effect__16TObjEneMerillLiaFPv((u8 *)arg0);
        if (objInBand((GameObj *)arg0, (f32)lbl_805DA304) != 0) {
            TObjEneMerillLia__sub_800D501C((s32)arg0);
        }
        if (arg0->fB4 != 0x20) {
            arg0->sub = 2;
            arg0->f390 = 0;
            arg0->fB8 = 0;
            ((TObjCollidable *)arg0)->clear_player_status_flag(0, 0xA000000);
            ((TObjBase *)arg0)->obj_clearFlags30(0x4000000);
        }
        break;
    case 2:
        arg0->target = find_nearest_visible_player(arg0, 0, *arg0->param);
        arg0->state = 1;
        break;
    }
    advance_animation_playback(arg0);
}

void TObjEneMerillLia::beast_update_approach() {
    u8 *arg0 = (u8 *)this;
    Vec_800D6618 sp14;
    f32 r;
    switch (this->phase) {
    case 0:
        apply_actor_gravity(arg0, 0, TObjEneMerillLia__data_805DA300);
        advance_animation_playback(arg0);
        if (this->m_b4 != 0x20U) {
            this->phase = 1;
            this->m_b8 = 2;
        }
        break;
    default:
        spawn_ground_effect__16TObjEneMerillLiaFPv(arg0);
        if (*(u32 *)&this->target != 0U) {
            if (test_elt_flag__13TUnk_80493450Fll(arg0, 0, 0x300000) != 0) {
                if (this->m_38c++ < lbl_805DA31C) {
                    VecCopy((Vec *)&sp14, &this->home_position);
                } else {
                    VecCopy((Vec *)&sp14, (const Vec *)(*(u32 *)&this->target + 0x2FC));
                }
            } else {
                this->m_38c = 0U;
                VecCopy((Vec *)&sp14, (const Vec *)(*(u32 *)&this->target + 0x2FC));
            }
            ((TUnk_80493450 *)arg0)->update_target_near_flag();
            ((TUnk_80493450 *)arg0)->sub_800C4E08();
            advance_animation_playback(arg0);
            {
                Vec_800D6618 sp8 = sp14;
                enemy_move_toward(arg0, *(s32 *)((s8 *)(*(u8 * *)&this->movementParameters) + 8), &sp8, 0, *(f32 *)&this->unk_394);
            }
            if (this->targetId == 0xFFFF) {
                if (horizontal_distance_squared((u8 *)&this->m_29c, (u8 *)&this->position) < (r = *(f32 *)&this->unk_394 + *(f32 *)((s8 *)(*(u8 * *)&this->bodies) + 0xC)) * r ||
                    lbl_805DA320 < (f32) (*(s32 *)&this->m_2ac)++) {
                    *(u32 *)&this->target = 0U;
                    *(s32 *)&this->m_2ac = 0;
                }
            }
        }
        break;
    }
    ((TObjPlayer *)arg0)->update_collisions();
    ((TObjPlayer *)arg0)->update_enemy_collision_flags();
    minimap_render_dot((u8 *)&this->position, -0x5DB4, 1, 0);
    ((TObjBase *)arg0)->obj_clearFlags30(0x200000);
}

void TObjEneMerillLia::render() {
  Stack_800D6810 stack;
  s32 var_r30;
  s16 temp_r0;
  s32 temp_r3;
  s32 var_r29;
  temp_r3 = (((VObj_18_ca64a0 *)(this))->m9((lbl_805DA324), (lbl_805DA328), (lbl_805DA314)));
  if (temp_r3 != 0)
  {
    saved_model_render_flags = model_render_flags;
    select_actor_lighting((s32)this);
    TObjFish::set_global_param((int) ((RecoveredFields_800D6810_arg0 *) ((u8 *)this))->field_24);
    push_matrix();
    translate_matrix(0, (f32) TObjEneMerillLia__data_805DA300, (f32) ((RecoveredFields_800D6810_arg0 *) ((u8 *)this))->field_380, (f32) TObjEneMerillLia__data_805DA300);
    post_translate_matrix(((u8 *)this) + 0x38);
    rotate_matrix_y(0, (int) ((RecoveredFields_800D6810_arg0 *) ((u8 *)this))->field_60);
    if (TObjPlayer::check_demo_mode() == 1)
    {
      draw_chunk_object((void *)((int) ((RecoveredFields_800D6810_arg0 *) ((u8 *)this))->field_34));
    }
    else
    {
      TObjPlayer::toggle_particle_effect();
      var_r30 = 1;
      var_r29 = 0;
      if (((s16) ((RecoveredFields_800D6810_arg0 *) ((u8 *)this))->field_326) == 0xD)
      {
        var_r29 = 1;
        var_r30 = (((VObj_14_fddec9 *)(((u8 *) ((u8 *)this)) + 936))->m8());
      }
      if (var_r29 != 0)
      {
        (((VObj_14_fddec9 *)(((u8 *) ((u8 *)this)) + 936))->m6());
        if (defer_render__7TObjectFv((void *) ((u8 *)this)) != 0)
        {
          var_r30 = 0;
        }
      }
      if (var_r30 != 0)
      {
        if (temp_r3 == 1)
        {
          TObjPlayer::set_global_flag();
          this->draw();
          TObjPlayer::clear_global_state();
        }
        else
        {
          TObjPlayer::set_global_flag();
          this->render_world_model();
          TObjPlayer::clear_global_state();
        }
      }
      TParticleCtrl::end_effect_render();
      if (var_r29 != 0)
      {
        (((VObj_14_fddec9 *)(((u8 *) ((u8 *)this)) + 936))->m7());
      }
    }
    pop_matrix();
    restore_scene_lighting();
    temp_r0 = ((RecoveredFields_800D6810_arg0 *) ((u8 *)this))->field_326;
    if ((temp_r0 >= 0xA) || (temp_r0 < 8))
    {
      stack.sp8 = lbl_805DA32C;
      stack.spC = TObjEneMerillLia__data_805DA2F4;
      stack.sp10 = lbl_805DA330;
      this->render_with_position_override((u8 *)&stack.sp8, 0);
    }
  }
}

#pragma push
#pragma opt_common_subs off
void TObjEneMerillLia::init_params_from_position() {
    u8 *arg0 = (u8 *)this;
    this->m_3d8 = (s16) ((s32) *(f32 *)((s8 *)arg0 + 0x360) + 0x12C);
    this->m_3c4 = (f32) (*(f32 *)((s8 *)arg0 + 0x354) - lbl_805DA334);
    if (this->m_3c4 < TObjEneMerillLia__data_805DA300) {
        this->m_3c4 = (f32) TObjEneMerillLia__data_805DA300;
    }
    *(f32 *)((s8 *)arg0 + 0x3C8) = (f32) (*(f32 *)((s8 *)arg0 + 0x35C) - lbl_805DA334);
    if (*(f32 *)((s8 *)arg0 + 0x3C8) < TObjEneMerillLia__data_805DA300) {
        *(f32 *)((s8 *)arg0 + 0x3C8) = (f32) TObjEneMerillLia__data_805DA300;
    }
    this->m_3d0 = (f32) (lbl_805DA338 + *(f32 *)((s8 *)arg0 + 0x364));
    if (this->m_3d0 < lbl_805DA2EC) {
        this->m_3d0 = (f32) lbl_805DA2EC;
    }
}
#pragma pop

void TObjEneMerillLia::select_action_by_distance() {
    u8 *arg0 = (u8 *)this;
    if (random_ratio__9TObjCharaFv(arg0) <= this->m_3c4) {
        init_attack_state();
        return;
    }
    if (random_ratio__9TObjCharaFv(arg0) <= *(f32 *)((s8 *)arg0 + 0x3C8)) {
        reset_action_state();
    }
}

typedef struct VBase_18_477421 VBase_18_477421;
typedef struct VObj_18_477421 VObj_18_477421;
void TObjEneMerillLia::run_task() {
  s16 temp_r0;
  if (TObjPlayer::check_demo_mode() == 1)
  {
    (this->vfunc_101());
    return;
  }
  temp_r0 = this->mode;
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
        break;
      case 4:
        (this->beast_update_group_chase());
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
        TObjEneMerillLia::update_kafun_attack((void *)this);
        break;
      case 11:
        TObjEneMerillLia::update_emerge_state((void *) ((u8 *)this));
        break;
      case 12:
        TObjEneMerillLia::search_target((void *) ((u8 *)this));
        break;
      case 13:
        this->sub_800D5570();
        break;
    }
  }
  this->update_prev_position();
  copy_position__20TBoss3VoloptHiraisinFv((void *) ((u8 *)this));
  submit_cursor_candidate((void *) this, -1);
  this->m_2b4 = (f32) ((this->m_2b4) + TObjEneMerillLia__data_805DA2F4);
}

void * TObjEneMerillLia__create(void *arg0) {
    void *o;
    void *o2;
    o = __nw__7TObjectFUl(0x20);
    if (o != NULL) {
        o = __ct__11TObjControlFP7TObject(o, tl_04);
    }
    o2 = __nw__7TObjectFUl(0x3DC);
    if (o2 != NULL) {
        o2 = TObjEneMerillLia__ct(o2, o, arg0);
    }
    return o2;
}

extern u32 TObjEneMerillLia__rock_stats_table;
extern u32 merill_lia_rock_buffer;
extern u32 merill_lia_rock_aux_buffer;
extern const f32 lbl_805DA33C;

#pragma push
#pragma opt_loop_invariants off
void TObjEneMerillLia__sub_800D6D64(void) {
    s32 i;
    u8 *res;

    if (is_split_screen() != 0) {
        res = (u8 *)::operator new(0x440);
        if (res != NULL) {
            res = load_resource_from_descriptor(res, 1, &bm_ene_re8_merill_lia_low_resource_descriptor, 0, 0, 0);
        }
        TObjEneMerillLia__entry_params_resource = (u32)res;
    } else {
        res = (u8 *)::operator new(0x440);
        if (res != NULL) {
            res = load_resource_from_descriptor(res, 1, &bm_ene_re8_merill_lia_resource_descriptor, 0, 0, 0);
        }
        TObjEneMerillLia__entry_params_resource = (u32)res;
    }
    ((CollisionPartRecord *)lbl_804946A4)[0].radius = lbl_805DA2F8;
    ((CollisionPartRecord *)lbl_804946A4)[1].radius = lbl_805DA2F8;
    ((CollisionPartRecord *)lbl_804946A4)[2].radius = lbl_805DA33C;
    TObjEneMerillLia__rock_stats_table = (u32)mem_alloc(8);
    merill_lia_rock_buffer = (u32)mem_alloc(8);
    merill_lia_rock_aux_buffer = (u32)mem_alloc(8);
    TObjEneMerillLia__rock_param_table = (u32)mem_alloc(8);
    ((void **)TObjEneMerillLia__rock_stats_table)[0] = TLobby::register_boss(75);
    ((void **)TObjEneMerillLia__rock_stats_table)[1] = TLobby::register_boss(76);
    ((void **)merill_lia_rock_buffer)[0] = TLobby::dispatch_shared_handler_b(78);
    ((void **)merill_lia_rock_buffer)[1] = TLobby::dispatch_shared_handler_b(79);
    ((void **)merill_lia_rock_aux_buffer)[0] = TLobby::register_object(74);
    ((void **)merill_lia_rock_aux_buffer)[1] = TLobby::register_object(75);
    ((void **)TObjEneMerillLia__rock_param_table)[0] = TLobby::dispatch_shared_handler_a(74);
    ((void **)TObjEneMerillLia__rock_param_table)[1] = TLobby::dispatch_shared_handler_a(75);
    {
        s16 ids[2] = {44, 46};
        NpcSpawnMotions motions = merill_lia_spawn_motions;
        motions.motions = ((BmlResource *)TObjEneMerillLia__entry_params_resource)->motions;
        for (i = 0; i < 2; i++) {
            TLobby::spawn_npc_enemy(ids[i], ((BmlResource *)TObjEneMerillLia__entry_params_resource)->models[i].model,
                ((BmlResource *)TObjEneMerillLia__entry_params_resource)->models[i].m_c, (s32)&motions,
                ((CollisionPartRecord *)lbl_804946A4)[i].radius, TObjEneMerillLia__data_805DA300);
        }
    }
}
#pragma pop

void TObjEneMerillLia::destroy_rocks() {
    if ((u32) TObjEneMerillLia__rock_stats_table != 0U) {
        mem_free((void*)TObjEneMerillLia__rock_stats_table);
        TObjEneMerillLia__rock_stats_table = 0U;
    }
    if ((u32) merill_lia_rock_buffer != 0U) {
        mem_free((void*)merill_lia_rock_buffer);
        merill_lia_rock_buffer = 0U;
    }
    if ((u32) merill_lia_rock_aux_buffer != 0U) {
        mem_free((void*)merill_lia_rock_aux_buffer);
        merill_lia_rock_aux_buffer = 0U;
    }
    if ((u32) TObjEneMerillLia__rock_param_table != 0U) {
        mem_free((void*)TObjEneMerillLia__rock_param_table);
        TObjEneMerillLia__rock_param_table = 0U;
    }
    if ((u32) TObjEneMerillLia__entry_params_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TObjEneMerillLia__entry_params_resource, 1);
        TObjEneMerillLia__entry_params_resource = 0U;
    }
}

void *__dt__16TObjEneMerillLiaFPvs(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_80494728;
        ((TUnk_80493450 *)arg0)->unlink_enemy_group_relations();
        free_collision_body_parts(arg0);
        __dt__13TUnk_80494938Fv((s8 *)arg0 + 0x3A8, -1);
        __dt__13TUnk_80493450Fv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
struct O_800D7274;
struct Obj_800D5150;
s32 init_enemy_base__13TUnk_80493450Fv(void *, s32);
s32 init_collision_body_parts(void *, void *, int);
extern s32 lbl_805D2A88;
extern const f32 lbl_805DA340;
extern const f32 lbl_805DA344;
#define arg0 ((u8 *)arg0v)
void *TObjEneMerillLia__ct(void *arg0v, void *arg1, void *arg2) {
    f32 sc;
    s32 hp;
    s16 t;

    init_enemy_base__13TUnk_80493450Fv(arg0, (s32)arg1);
    *(void **)((s8 *)arg0 + 0x18) = lbl_80494728;
    __ct__13TUnk_80494938Fv((arg0 + 0x3A8));
    *(s32 *)((s8 *)arg0 + 0) = lbl_805D2A88;
    ((VObj_18_4c2345 *) arg0)->m79((s32)arg2);
    ((TObjEneMerillLia *)arg0)->init_params_from_position();
    ((TObjPlayer *)arg0)->init_position_vectors();
    *(s32 *)((s8 *)arg0 + 0x334) = *(s32 *)((s8 *)arg0 + 0x368);
    ((TObjEneMerillLia *)arg0)->clamp_and_apply_mode_param();
    ((TObjEneMerillLia *)arg0)->load_entry_params(*(s32 *)((s8 *)arg0 + 0x368));
    *(void **)((s8 *)arg0 + 0xD8) = lbl_80494570;
    ((TObjMotion *)arg0)->set_field_d8((s32)(*(void **)((s8 *)arg0 + 0xD8)));
    *(s32 *)((s8 *)arg0 + 0xDC) = *(s32 *)((s8 *)TObjEneMerillLia__entry_params_resource + 0x430);
    *(s16 *)((s8 *)arg0 + 0xB8) = 0;
    ((TObjMotion *)arg0)->set_animation(*(s16 *)((s8 *)arg0 + 0xB8));
    ((TObjMotion *)arg0)->set_field_b8(*(s16 *)((s8 *)arg0 + 0xB8));
    init_collision_body_parts(arg0, (u8 *) lbl_804946A4 + *(s32 *)((s8 *)arg0 + 0x334) * 0x2C, 1);
    ((TObjEnemy *)arg0)->bind_enemy_combat_stats((u8 *)(((s32 *) TObjEneMerillLia__rock_stats_table)[*(s32 *)((s8 *)arg0 + 0x334)]), (u8 *)(((s32 *) merill_lia_rock_buffer)[*(s32 *)((s8 *)arg0 + 0x334)]), (u8 *)(((s32 *) merill_lia_rock_aux_buffer)[*(s32 *)((s8 *)arg0 + 0x334)]));
    *(u8 **)((s8 *)arg0 + 0x350) = (u8 *) lbl_80494650 + *(s32 *)((s8 *)arg0 + 0x334) * 0x1C;
    *(s16 *)((s8 *)arg0 + 0x33E) = *(s16 *)((s8 *)arg0 + 0x32C);
    ((TObjEnemy *)arg0)->update_prev_position();
    copy_position__20TBoss3VoloptHiraisinFv(arg0);
    ((TObjPlayer *)arg0)->register_object_by_id();
    *(s32 *)((s8 *)arg0 + 0x2AC) = lbl_805DA340 * (lbl_805DA344 * random_ratio__9TObjCharaFv(arg0));
    *(s16 *)((s8 *)arg0 + 0x33A) = 0xF;
    *(s16 *)((s8 *)arg0 + 0x33C) = *(s16 *)((s8 *)arg0 + 0x33A);
    *(s16 *)((s8 *)arg0 + 0x328) = 0;
    *(s16 *)((s8 *)arg0 + 0x374) = 0;
    *(s16 *)((s8 *)arg0 + 0x376) = 0;
    *(s32 *)((s8 *)arg0 + 0x378) = 0;
    *(s32 *)((s8 *)arg0 + 0x37C) = 0;
    ((TObjChara *)arg0)->add_flags_2e4(2);
    obj_setFlags30(arg0, 0x40000);
    *(f32 *)((s8 *)arg0 + 0x380) = TObjEneMerillLia__data_805DA300;
    *(f32 *)((s8 *)arg0 + 0x398) = ((f32 **) TObjEneMerillLia__rock_param_table)[*(s32 *)((s8 *)arg0 + 0x334)][0];
    *(f32 *)((s8 *)arg0 + 0x3A0) = ((f32 **) TObjEneMerillLia__rock_param_table)[*(s32 *)((s8 *)arg0 + 0x334)][1];
    *(f32 *)((s8 *)arg0 + 0x39C) = ((f32 **) TObjEneMerillLia__rock_param_table)[*(s32 *)((s8 *)arg0 + 0x334)][2];
    *(f32 *)((s8 *)arg0 + 0x3A4) = ((f32 **) TObjEneMerillLia__rock_param_table)[*(s32 *)((s8 *)arg0 + 0x334)][3];
    *(f32 *)((s8 *)arg0 + 0x3D4) = ((f32 **) TObjEneMerillLia__rock_param_table)[*(s32 *)((s8 *)arg0 + 0x334)][5];
    *(f32 *)((s8 *)arg0 + 0x3CC) = ((s32 **) TObjEneMerillLia__rock_param_table)[*(s32 *)((s8 *)arg0 + 0x334)][6] / lbl_805DA338;
    *(s32 *)((s8 *)arg0 + 0x390) = 1;
    *(s16 *)((s8 *)arg0 + 0x326) = 0xD;
    *(s16 *)((s8 *)arg0 + 0xB8) = 1;
    ((VObj_18_4c2345 *) arg0)->m80();
    return arg0;
}
#undef arg0

void TObjEneMerillLia::load_entry_params(s32 i) {
    O_800D7274 *self = (O_800D7274 *)this;
    self->f34 = (*(D_800D7274 * *)&TObjEneMerillLia__entry_params_resource)->entries[i].f8;
    self->f24 = (*(D_800D7274 * *)&TObjEneMerillLia__entry_params_resource)->entries[i].fc;
}

}
