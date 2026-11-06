#include "types.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/object/base/TObjChara.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/unk/TLobby.h"
#include "pso/enemy/slime/TObjEneSlimeOne.h"
#include "pso/enemy/slime/TObjEneSlimeTailAttack.h"
#include "pso/enemy/slime/TObjEneSlimeWaterBomb.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/math/AngleLookup.h"
#include "pso/unk/text_80087278.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/effect/particle/TParticleCtrl_800874F4.h"
extern "C" void has_flag_0x800__9TObjCharaFv();
extern "C" void test_flag30_512__9TObjCharaFv();
extern "C" void test_flag_1000__9TObjCharaFv();
extern "C" void test_flag_256__9TObjCharaFv();
#include "pso/system/vector.h"

#include <stddef.h>
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/enemy/lappy/TObjEneLappy.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/object/ambient/TObjFish.h"

struct Obj_800E9BCC {
    u8 pad0[0x38];
    f32 pos[3];
    f32 prev[3];
    u8 pad50[0x60 - 0x50];
    s32 rotation_y;
    u8 pad64[0x390 - 0x64];
    s32 state_timer;
    u8 pad394[0x3CC - 0x394];
    s32 target_client_id;
};

typedef struct { f32 x, y, z; } Vec_800EB654;

struct Vec_800EAD84 { f32 x, y, z; };

struct Obj_800EAD84 { u8 pad0[0x38]; Vec_800EAD84 pos; };

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

struct Vec_800EAEE8 { f32 x, y, z; };
extern "C" {



f64 atan2_float(f32, f32);
u32 csnLookAt(void *, void *);
s32 project_actor_to_ground(void *, void *, int);
s32 vec3_add_to(void *, void *);
f32 vector_length(void *);
void normalize_vector(void *);
f32 random_ratio__9TObjCharaFv(void *);
s32 TObjEneSlimeOne__sub_800EAD84(Obj_800EAD84 *arg0);
void scale_matrix_vec3(u8 *arg0, u8 *arg1);
s32 push_matrix();
s32 post_translate_matrix(void *);
void render__15TObjEneSlimeOneFv(TObjEneSlimeOne *arg0);
s32 TObjFish__sub_8001EDB0(s32, s32);
s32 get_bml_model(s32, s32);
u8 *get_instance__15TObjEneSlimeOneFv();
s32 init_collision_body_parts(void *, void *, int);
extern void *lbl_80496368[2];
extern void *lbl_8049639C[28];
struct RecoveredGlobal_800E8128_lbl_80496704 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_800E8128_lbl_80496710 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_800E8128_lbl_80501010 {
    s32 value;
    u8 remaining[0x3C];
};

struct RecoveredGlobal_800E80C0_lbl_80501010 {
    s32 value;
    u8 remaining[0x3C];
};

struct B_800E80E8 { s32 w[3]; };

struct A_800E80E8 { s32 w[12]; };

struct S_800E80E8 { B_800E80E8 a; A_800E80E8 d; };

typedef struct { f32 x, y, z; } Vec_800E81B4;

struct Rot_800E81B4 { s32 x, y, z; };

struct Obj_800E81B4 { u8 pad[0x39C]; Vec_800E81B4 pts[4]; };

struct Vec_800E82B8 { f32 x, y, z; };

typedef char RecoveredGlobal_800E8128_lbl_80496704_size[sizeof(RecoveredGlobal_800E8128_lbl_80496704) == 0xC ? 1 : -1];

typedef char RecoveredGlobal_800E8128_lbl_80496710_size[sizeof(RecoveredGlobal_800E8128_lbl_80496710) == 0xC ? 1 : -1];

typedef char RecoveredGlobal_800E8128_lbl_80501010_size[sizeof(RecoveredGlobal_800E8128_lbl_80501010) == 0x40 ? 1 : -1];

typedef char RecoveredGlobal_800E80C0_lbl_80501010_size[sizeof(RecoveredGlobal_800E80C0_lbl_80501010) == 0x40 ? 1 : -1];

struct Hit_800E8AD0 { s32 kind; f32 dmg; };

struct Base_800E8AD0 { u8 pad[0x18]; };

struct Ent_800E8AD0 : Base_800E8AD0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual f32 m21(s32, Hit_800E8AD0, s32, s32, s32);
    virtual void v22();
    virtual void m23(void *);
};

struct Vec_800E8D4C { f32 x, y, z; };

struct Bomb_800E8D4C {
    u8 pad0[0x38];
    Vec_800E8D4C pos;
    u8 pad44[0x248 - 0x44];
    u8 hit[0x374 - 0x248];
    Vec_800E8D4C vel;
    f32 ground;
    f32 life;
    void *link;
    s32 owner;
    u8 pad390[4];
    s32 timer;
};

typedef struct { f32 x, y, z; } Vec_800E8C6C;

struct Vec_800E9090 { f32 x, y, z; };

struct Bomb_800E9090 {
    u8 pad0[0x38];
    Vec_800E9090 pos;
    u8 pad44[0x374 - 0x44];
    Vec_800E9090 vel;
    s32 f380;
    u8 pad384[0x3A0 - 0x384];
    f32 f3A0;
    u8 pad3A4[0x3F4 - 0x3A4];
    s32 f3F4;
};

struct Stack_800E9238 {
    f32 sp8;
    f32 spC;
    f32 sp10;
};

typedef struct Vec_800E984C { f32 x, y, z; } Vec_800E984C;

typedef struct Tgt_800E984C { u8 pad[0x30]; u32 flags; u8 pad34[4]; Vec_800E984C pos; } Tgt_800E984C;

typedef struct Self_800E984C {
    u8 pad0[0x38];
    Vec_800E984C pos;
    u8 pad44[0x60 - 0x44];
    s32 rotation_y;
    u8 pad64[0x388 - 0x64];
    s32 f388;
    u8 pad38C[0x390 - 0x38C];
    s32 state_timer;
    u8 pad394[0x3CC - 0x394];
    s32 target;
    Vec_800E984C dest;
} Self_800E984C;

struct Obj_800E9DC8 { u8 pad0[0x60]; s32 rotation_y; u8 pad1[0x390 - 0x64]; s32 state_timer; u8 pad2[0x3C4 - 0x394]; s32 turn_speed; };

struct RecoveredGlobal_800EA678_lbl_8043D230 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_800EA678_lbl_8043D23C {
    s32 value;
    u8 remaining[0x8];
};

struct Vec_800EA364 { f32 x, y, z; };

typedef char RecoveredGlobal_800EA678_lbl_8043D230_size[sizeof(RecoveredGlobal_800EA678_lbl_8043D230) == 0xC ? 1 : -1];

typedef char RecoveredGlobal_800EA678_lbl_8043D23C_size[sizeof(RecoveredGlobal_800EA678_lbl_8043D23C) == 0xC ? 1 : -1];

struct Stack_800EB3D4 {
    s32 sp8;
    u8 pad_C[0x2];
    s16 spE;
    u8 trailing_storage[0x4];
};

struct RecoveredGlobal_800EB3D4___vt__15TObjEneSlimeOne {
    s32 value;
    u8 remaining[0x148];
};

struct Stack_800EB4A0 {
    s32 sp8;
    u8 pad_C[0x2];
    s16 spE;
    u8 trailing_storage[0x4];
};

struct RecoveredGlobal_800EB4A0___vt__15TObjEneSlimeOne {
    s32 value;
    u8 remaining[0x148];
};


typedef char RecoveredGlobal_800EB3D4___vt__15TObjEneSlimeOne_size[sizeof(RecoveredGlobal_800EB3D4___vt__15TObjEneSlimeOne) == 0x14C ? 1 : -1];

typedef char RecoveredGlobal_800EB4A0___vt__15TObjEneSlimeOne_size[sizeof(RecoveredGlobal_800EB4A0___vt__15TObjEneSlimeOne) == 0x14C ? 1 : -1];

struct Vec_800E9EFC { f32 x, y, z; };

u16 find_nearest_visible_player(void *, void *, f32);
void queue_destruction__7TObjectFv(void *);
f32 * dispatch_shared_handler_a__6TLobbyFl(s32);
u8 * get_bml_motion(s32, s32);
s32 exchange_object_state__9TObjEnemyFls(void *, void *, int);
void transform_to_view__11TCameraCtrlFii(s32, s32);
void TObjPlayer__sub_800E80C0(u8 *arg0);
S_800E80E8 * TObjPlayer__sub_800E80E8(S_800E80E8 *dst, S_800E80E8 *src);
void TObjPlayer__sub_800E8128(void);
void TObjPlayer__sub_800E81A8(void);
void render__22TObjEneSlimeTailAttackFv(u8 *arg0);
s32 TObjPlayer__sub_800E85BC(TObjEneSlimeTailAttack *self);
void run_task__22TObjEneSlimeTailAttackFv(u8 *arg0);
void * create__22TObjEneSlimeTailAttackFiiii(s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void * dt__22TObjEneSlimeTailAttackFPvs(void *arg0, s16 arg1);
void *TObjEneSlimeTailAttack__ct(TObjEneSlimeTailAttack *, void *, s32, s32, s32);
void run_task__21TObjEneSlimeWaterBombFv(Bomb_800E8D4C *arg0);
void *TObjEneSlimeWaterBomb__ct(TObjEneSlimeWaterBomb *arg0, void *arg1, void *arg2);
void fn_800E9238(s32 arg0);
void set_display_mode__15TObjEneSlimeOneFPvi(void *arg0, s32 arg1);
void set_random_timer__15TObjEneSlimeOneFPvii(void *arg0, s32 arg1, s32 arg2);
u8 * TObjEneSlimeOne__ct(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
u8 * init__15TObjEneSlimeOneFPviii(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
s16 check_player_field_7cc__15TObjEneSlimeOneFv();
void draw_blob_shadow(s32 arg0);
void * __ct__11TObjControlFP7TObject(void *, s32);
u8 *get_enemy_entity(u16 arg0);
int get_entity_id(void *);
void *__dt__9TObjEnemyFv(TObjEnemy *arg0, s16 arg1);
s32 __ct__9TObjEnemyFP7TObject(void *);
}

s32 water_bomb_hit_nearby(u8 *arg0);
extern "C" {


void free_collision_body_parts(void *);
void __dl__7TObjectFPv(void *);
void * __nw__7TObjectFUl(s32);
s32 scale_matrix(int, f32, f32, f32);
s32 rotate_matrix_z(int, int);
void subtract_vector(void *, void *);
void translate_matrix(u32 arg0, f32 x, f32 y, f32 z);
s32 rotate_matrix_x(int, int);
s32 scale_current_matrix(Vec_800E8C6C *);


// This TU's .rodata objects in address order (names stay placeholders).
extern const char lbl_8043D008[] = "bm4_ps_ma_body.nj";
extern const char lbl_8043D01C[] = "bm4_ps_ma_tail.nj";
extern const char lbl_8043D030[] = "bm4_ps_mar_body.nj";
extern const char lbl_8043D044[] = "bm4_ps_mar_tail.nj";
extern const char lbl_8043D058[] = "bm4_ps_mb_body.nj";
extern const char lbl_8043D06C[] = "bm4_ps_mbr_body.nj";
extern const char lbl_8043D080[] = "apear_bm4_ps_mb_body.njm";
extern const char lbl_8043D09C[] = "apper_bm4_ps_ma_body.njm";
extern const char lbl_8043D0B8[] = "atack_bm4_ps_ma_body.njm";
extern const char lbl_8043D0D4[] = "damage_bm4_ps_ma_body.njm";
extern const char lbl_8043D0F0[] = "kie_bm4_ps_ma_body.njm";
extern const char lbl_8043D108[] = "kie_bm4_ps_mb_body.njm";
extern const char lbl_8043D120[] = "move_bm4_ps_mb_body.njm";
extern const char lbl_8043D138[] = "move_bm4_ps_mb_body.njs";
extern const char lbl_8043D150[] = "nodam_bm4_ps_ma_body.njm";
extern const char lbl_8043D16C[] = "tlatk_bm4_ps_ma_tail.njm";
extern const char lbl_8043D188[] = "wait_bm4_ps_ma_body.njm";
extern const char lbl_8043D1A0[] = "wait_bm4_ps_mb_body.njm";
extern const char lbl_8043D1B8[] = "wait_bm4_ps_mb_body.njs";
extern const char lbl_8043D1D0[] = "wait2_bm4_ps_ma_body.njm";
extern const char lbl_8043D1EC[] = "bm4_ps_ma_body.bml";
extern const char lbl_8043D200[] = "TObjEneSlime";
extern const char lbl_8043D210[] = "BLUE";
// Debug label strings; slime_debug_label_table points at them.
extern const char lbl_805DA668[] = "RED";
extern const s32 lbl_8043D218[2] = {0, 0};
extern const char lbl_8043D220[] = "TObjEneSlimeOne";
extern const RecoveredGlobal_800EA678_lbl_8043D230 lbl_8043D230 = {0x40200000, {0x00, 0x00, 0x00, 0x00, 0x40, 0x20, 0x00, 0x00}};
extern const RecoveredGlobal_800EA678_lbl_8043D23C lbl_8043D23C = {0x3F800000, {0x3F, 0x80, 0x00, 0x00, 0x3F, 0x80, 0x00, 0x00}};
extern const char lbl_8043D248[] = "TObjEneSlimeWaterBomb";
extern s32 __vt__15TObjEneSlimeOne[];
extern s32 __vt__21TObjEneSlimeWaterBomb[];
RecoveredGlobal_800E8128_lbl_80501010 lbl_80501010;
void *slime_bml_resource;
int lbl_805D52B4;
extern s32 registered_player_count;
extern s32 tl_04;


void vfunc_6__8TObjBaseFPsl();

void vfunc_29__9TObjCharaFv();

void recalc_stats__9TObjCharaFv();

void vfunc_28__9TObjCharaFv();

void vfunc_67__9TObjCharaFf();

void vfunc_66__9TObjCharaFv();

void get_anim_node_position__9TObjCharaFlP3Vec();

void vfunc_63__9TObjCharaFv();

void vfunc_62__9TObjCharaFv();

void vfunc_61__9TObjCharaFv();

void vfunc_60__9TObjCharaFv();

void vfunc_59__9TObjCharaFv();

void vfunc_58__9TObjCharaFv();

void vfunc_43__9TObjCharaFv();

void vfunc_18__9TObjCharaFPUc();

void interact__14TObjCollidableFl();

void vfunc_74__9TObjEnemyFl();

void add_actor_exp__9TObjCharaFl();

void apply_action_hold_status__9TObjCharaFf();

void apply_anti_technique__9TObjCharaFl();

void apply_attack_stat_status__9TObjCharaFPv();

void apply_confusion_status__9TObjCharaFv();

void apply_hit_message_flags__9TObjEnemyFPv();

void apply_knockback_from_attacker__9TObjCharaFPUcf();

void apply_movement_ailment__9TObjCharaFl();

void apply_object_set_data__8TObjBaseFPv();

void apply_paralysis__9TObjCharaFv();

void apply_poison_status__9TObjCharaFv();

void apply_set_data__9TObjEnemyFPv();

void apply_shock_status__9TObjCharaFv();

void apply_slow_status__9TObjCharaFv();

void apply_switch_attack__9TObjCharaFv();

void calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf();

void vfunc_79__9TObjEnemyFPl();

void classify_actor_view_detail__8TObjBaseFfff();

void clear_all_status_effects__9TObjCharaFv();

void clear_harmful_statuses__9TObjCharaFv();

void clear_lobby_object_state__9TObjEnemyFv();

void consume_timer_field__9TObjCharaFl();

void cure_paralysis__9TObjCharaFv();

void cure_poison_ailment__9TObjCharaFv();

void enemy_spawn_jellen_effect__9TObjCharaFv();

void enemy_spawn_zalure_effect__9TObjCharaFv();

void vfunc_78__9TObjCharaFl();

void vfunc_77__9TObjCharaFv();

void vfunc_76__9TObjCharaFf();

void vfunc_75__9TObjCharaFf();

void get_center__9TObjCharaFv();

void get_actor_level_index__9TObjCharaFv();

void get_name__9TObjEnemyFv();

void get_pos__9TObjCharaFl();

void is_actor_cadence_frame__9TObjCharaFl();

void is_target_in_attack_range__9TObjCharaFv();

void receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll();
s32 minimap_render_dot(void *, s32, s32, s32);
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);

void receive_physical_attack__9TObjCharaFPvf();

void receive_weapon_special_attack__9TObjCharaFPvPv();
void apply_defense_stat_status__9TObjCharaFPv();

void render_shadows__9TObjEnemyFv(u8 *arg0);

void reset_motion_fields__9TObjCharaFv();

void reset_pose__9TObjCharaFv();

void roll_physical_accuracy__9TObjCharaFPvlf();

void select_melee_contact_body__9TObjCharaFPvf();

void trigger_switch_attack__9TObjCharaFv(s32 arg0);

void try_start_action__9TObjCharaFll();

void update_action_hold_status__9TObjCharaFv();

s32 vfunc_37__9TObjCharaFv(u8 *arg0);

void update_actor_ground_y__9TObjCharaFv();

s32 update_attack_stat_status__9TObjCharaFv(u8 *arg0);

s32 update_defense_stat_status__9TObjCharaFv(u8 *arg0);

void update_flag30_timer__9TObjCharaFv();

void update_movement_status__9TObjCharaFv();

void update_object_view_visibility__8TObjBaseFff();

void update_poison_status__9TObjCharaFv();

void update_shock_clock__9TObjCharaFv();
extern void *slime_model_name_ptr_table[7];
extern void *bm4_ps_ma_body_motion_names[15];

void *slime_model_name_ptr_table[7] = {
    (void *)&lbl_8043D008, (void *)&lbl_8043D01C, (void *)&lbl_8043D030, (void *)&lbl_8043D044,
    (void *)&lbl_8043D058, (void *)&lbl_8043D06C, (void *)0x0,
};
void *bm4_ps_ma_body_motion_names[15] = {
    (void *)&lbl_8043D080, (void *)&lbl_8043D09C, (void *)&lbl_8043D0B8, (void *)&lbl_8043D0D4,
    (void *)&lbl_8043D0F0, (void *)&lbl_8043D108, (void *)&lbl_8043D120, (void *)&lbl_8043D138,
    (void *)&lbl_8043D150, (void *)&lbl_8043D16C, (void *)&lbl_8043D188, (void *)&lbl_8043D1A0,
    (void *)&lbl_8043D1B8, (void *)&lbl_8043D1D0, (void *)0x0,
};
void *slime_pair_resource_descriptor[4] = {
    (void *)&lbl_8043D1EC, (void *)&slime_model_name_ptr_table, (void *)&bm4_ps_ma_body_motion_names, (void *)0x6000e,
};
__declspec(section ".data") void *slime_debug_label_table[2] = {
    (void *)&lbl_8043D210, (void *)lbl_805DA668,
};
__declspec(section ".data") void *lbl_80496368[2] = {
    (void *)0x4, (void *)0x5,
};
void *lbl_80496370[11] = {
    (void *)0x0, (void *)0x41700000, (void *)0x0, (void *)0x40f00000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_8049639C[28] = {
    (void *)0x10000, (void *)0xa, (void *)0x3f000000, (void *)0x0,
    (void *)0x20002, (void *)0xa, (void *)0x3f000000, (void *)0x0,
    (void *)0x10000, (void *)0xd, (void *)0x3f000000, (void *)0x0,
    (void *)0x20000, (void *)0x2, (void *)0x3f4ccccd, (void *)0x0,
    (void *)0x30000, (void *)0x8, (void *)0x3f4ccccd, (void *)0x0,
    (void *)0x30000, (void *)0x3, (void *)0x3f4ccccd, (void *)0x0,
    (void *)0x30000, (void *)0x9, (void *)0x3f4ccccd, (void *)0x0,
};
/* State table of TObjEneSlimeOne: {enter, update} per state, indexed by state; built by the TU's __sinit. */
typedef void (TObjEneSlimeOne::*SlimeOneStateFn)();
struct SlimeOneState { SlimeOneStateFn enter; SlimeOneStateFn update; };
static SlimeOneState lbl_80496574[15] = {
    { &TObjEneSlimeOne::init_state, &TObjEneSlimeOne::update_wait_search },
    { &TObjEneSlimeOne::reset_display, &TObjEneSlimeOne::sub_800EA820 },
    { &TObjEneSlimeOne::init_slime_display, &TObjEneSlimeOne::sub_800EA678 },
    { &TObjEneSlimeOne::sub_800EA56C, &TObjEneSlimeOne::sub_800EA364 },
    { &TObjEneSlimeOne::enter_slime_state, &TObjEneSlimeOne::update_slime_timer },
    { &TObjEneSlimeOne::enter_appear_state, &TObjEneSlimeOne::update_dive_timer },
    { &TObjEneSlimeOne::sub_800EA120, &TObjEneSlimeOne::sub_800E9EFC },
    { &TObjEneSlimeOne::init_slime_state, &TObjEneSlimeOne::sub_800E9DC8 },
    { &TObjEneSlimeOne::sub_800E9D7C, &TObjEneSlimeOne::sub_800E9BCC },
    { &TObjEneSlimeOne::begin_appear, &TObjEneSlimeOne::update_water_bomb_timer },
    { &TObjEneSlimeOne::start_tail_attack, &TObjEneSlimeOne::tick_timer },
    { &TObjEneSlimeOne::reset_display_state, &TObjEneSlimeOne::update_tick },
    { &TObjEneSlimeOne::init_split_effect, &TObjEneSlimeOne::sub_800E969C },
    { &TObjEneSlimeOne::sub_800E95F4, &TObjEneSlimeOne::update_effect_fade_lifetime },
    { &TObjEneSlimeOne::sub_800E9538, &TObjEneSlimeOne::sub_800E92D8 },
};
__declspec(section ".data") void *lbl_804966DC[2] = {
    (void *)0x0, (void *)0x2,
};
__declspec(section ".data") void *slime_tail_attack_id_pair[2] = {
    (void *)0x4, (void *)0x5,
};
__declspec(section ".data") void *TObjEneSlime__attack_target_param_table[2] = {
    (void *)0x30, (void *)0x34,
};
__declspec(section ".data") void *lbl_804966F4[2] = {
    (void *)0x1, (void *)0x3,
};
__declspec(section ".data") void *lbl_804966FC[2] = {
    (void *)0x30, (void *)0x34,
};
void *slime_tail_attack_zero_vec[3] = {
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *slime_tail_attack_transform[3] = {
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *__vt__22TObjEneSlimeTailAttack[83] = {
    (void *)0x0, (void *)0x0, (void *)&dt__22TObjEneSlimeTailAttackFPvs, (void *)&run_task__22TObjEneSlimeTailAttackFv,
    (void *)&render__22TObjEneSlimeTailAttackFv, (void *)&render_shadows__9TObjEnemyFv, (void *)&vfunc_6__8TObjBaseFPsl, (void *)&apply_object_set_data__8TObjBaseFPv,
    (void *)&reset_motion_fields__9TObjCharaFv, (void *)&get_center__9TObjCharaFv, (void *)&update_object_view_visibility__8TObjBaseFff, (void *)&classify_actor_view_detail__8TObjBaseFfff,
    (void *)&get_name__9TObjEnemyFv, (void *)&interact__14TObjCollidableFl, (void *)&add_actor_exp__9TObjCharaFl, (void *)&consume_timer_field__9TObjCharaFl,
    (void *)&get_actor_level_index__9TObjCharaFv, (void *)&update_actor_ground_y__9TObjCharaFv, (void *)&vfunc_18__9TObjCharaFPUc, (void *)&is_actor_cadence_frame__9TObjCharaFl,
    (void *)&select_melee_contact_body__9TObjCharaFPvf, (void *)&calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf, (void *)&receive_physical_attack__9TObjCharaFPvf, (void *)&receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll,
    (void *)&receive_weapon_special_attack__9TObjCharaFPvPv, (void *)&apply_knockback_from_attacker__9TObjCharaFPUcf, (void *)&try_start_action__9TObjCharaFll, (void *)&roll_physical_accuracy__9TObjCharaFPvlf,
    (void *)&vfunc_28__9TObjCharaFv, (void *)&vfunc_29__9TObjCharaFv, (void *)&is_target_in_attack_range__9TObjCharaFv, (void *)&test_flag_256__9TObjCharaFv,
    (void *)&test_flag30_512__9TObjCharaFv, (void *)&has_flag_0x800__9TObjCharaFv, (void *)&test_flag_1000__9TObjCharaFv, (void *)&update_poison_status__9TObjCharaFv,
    (void *)&update_action_hold_status__9TObjCharaFv, (void *)&vfunc_37__9TObjCharaFv, (void *)&update_flag30_timer__9TObjCharaFv, (void *)&update_movement_status__9TObjCharaFv,
    (void *)&update_shock_clock__9TObjCharaFv, (void *)&update_attack_stat_status__9TObjCharaFv, (void *)&update_defense_stat_status__9TObjCharaFv, (void *)&vfunc_43__9TObjCharaFv,
    (void *)&apply_poison_status__9TObjCharaFv, (void *)&apply_paralysis__9TObjCharaFv, (void *)&apply_slow_status__9TObjCharaFv, (void *)&apply_confusion_status__9TObjCharaFv,
    (void *)&apply_movement_ailment__9TObjCharaFl, (void *)&apply_shock_status__9TObjCharaFv, (void *)&clear_harmful_statuses__9TObjCharaFv, (void *)&apply_attack_stat_status__9TObjCharaFPv,
    (void *)&apply_defense_stat_status__9TObjCharaFPv, (void *)&cure_poison_ailment__9TObjCharaFv, (void *)&cure_paralysis__9TObjCharaFv, (void *)&clear_all_status_effects__9TObjCharaFv,
    (void *)&apply_action_hold_status__9TObjCharaFf, (void *)&apply_anti_technique__9TObjCharaFl, (void *)&vfunc_58__9TObjCharaFv, (void *)&vfunc_59__9TObjCharaFv,
    (void *)&vfunc_60__9TObjCharaFv, (void *)&vfunc_61__9TObjCharaFv, (void *)&vfunc_62__9TObjCharaFv, (void *)&vfunc_63__9TObjCharaFv,
    (void *)&reset_pose__9TObjCharaFv, (void *)&get_anim_node_position__9TObjCharaFlP3Vec, (void *)&vfunc_66__9TObjCharaFv, (void *)&vfunc_67__9TObjCharaFf,
    (void *)&get_pos__9TObjCharaFl, (void *)&apply_switch_attack__9TObjCharaFv, (void *)&enemy_spawn_jellen_effect__9TObjCharaFv, (void *)&trigger_switch_attack__9TObjCharaFv,
    (void *)&enemy_spawn_zalure_effect__9TObjCharaFv, (void *)&recalc_stats__9TObjCharaFv, (void *)&vfunc_74__9TObjEnemyFl, (void *)&vfunc_75__9TObjCharaFf,
    (void *)&vfunc_76__9TObjCharaFf, (void *)&vfunc_77__9TObjCharaFv, (void *)&vfunc_78__9TObjCharaFl, (void *)&vfunc_79__9TObjEnemyFPl,
    (void *)&apply_hit_message_flags__9TObjEnemyFPv, (void *)&apply_set_data__9TObjEnemyFPv, (void *)&clear_lobby_object_state__9TObjEnemyFv,
};
#define slime_tail_attack_id_pair ((s32 *)slime_tail_attack_id_pair)
#define TObjEneSlime__attack_target_param_table ((s32 *)TObjEneSlime__attack_target_param_table)
#define slime_tail_attack_zero_vec (*(RecoveredGlobal_800E8128_lbl_80496704 *)slime_tail_attack_zero_vec)
#define slime_tail_attack_transform (*(RecoveredGlobal_800E8128_lbl_80496710 *)slime_tail_attack_transform)
#define __vt__22TObjEneSlimeTailAttack ((s32 *)__vt__22TObjEneSlimeTailAttack)


extern const char lbl_8043D268[];
// .sdata: the class-name pointers the constructors store in TObject's name field.
const char *lbl_805D2AD8 = lbl_8043D200;
const char *TObjEneSlimeOne_class_name = lbl_8043D220;
const char *lbl_805D2AE0 = lbl_8043D248;
const char *TObjEneSlimeTailAttack__name = lbl_8043D268;


f32 fabs_float(f32);
}


// ---- folded from src/pso/unk/text_800EB778.cpp ----
#include "types.h"
#include "pso/system/vector.h"
#include "pso/enemy/slime/TObjEneSlimeOne.h"
struct E_800EB8DC { s32 f0; s32 f4; };

struct O_800EB8DC { u8 pad[0x3b8]; E_800EB8DC arr[4]; };

struct Slot_800EB778 { s32 state; void *obj; };

struct Obj_800EB778 { u8 pad[0x1c]; u16 id; u8 pad2[0x3b8 - 0x1e]; Slot_800EB778 slots[4]; };

struct Tmpl_800EB7BC {
    s16 a;
    s16 b;
    s16 c;
    u16 d;
    u8 pad8[8];
    Vec_800EB654 pos;
    u8 rest[0x40 - 0x1C];
};

struct Blob_800EB7BC { u8 bytes[0x40]; };

struct Slot_800EB7BC { s32 active; u32 obj; };

struct Obj_800EB7BC {
    u8 pad0[0x38];
    Vec_800EB654 pos;
    u8 pad44[0x374 - 0x44];
    Tmpl_800EB7BC tmpl;
    s32 count;
    Slot_800EB7BC slots[8];
};

extern "C" {
s32 has_no_active_slot(O_800EB8DC *self);
void fn_800EB778(Obj_800EB778 *self, s32 id);
s32 spawn_slime_in_slot(Obj_800EB7BC *origin, s32 arg1, Vec_800EB654 *arg2, Vec_800EB654 *arg3);

}

// ---- folded from src/pso/enemy/TObjEneSlime.cpp ----
#include "types.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/enemy/slime/TObjEneSlimeOne_800EC394.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/slime/TObjEneSlime.h"
#include "pso/player/TObjPlayer.h"

#define CAT2(a,b) a##b
#define CAT(a,b) CAT2(a,b)
#define VA virtual void CAT(f,__LINE__)();
struct Base_800EBB18_800EB9F0 { char pad[0x18]; };
struct VObj_800EBB18_800EB9F0 : Base_800EBB18_800EB9F0 {
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
    virtual void m77(s32 *);
};

struct Slot_800EB910 { s32 state; void *obj; };

struct Obj_800EB910 { u8 pad[0x3b8]; Slot_800EB910 slots[4]; };

struct Slot_800EB984 { s32 state; void *obj; };

struct Obj_800EB984 { u8 pad[0x3b8]; Slot_800EB984 slots[4]; };

extern "C" {
s32 set_global_param__8TObjFishFl();
extern u32 model_render_flags;



void TObjEneSlime__sub_800EB9F0(void* p, void* q);




}

// ---- folded from src/pso/enemy/TObjEneSlime_800EBBC8.cpp ----
#include "types.h"
#include "pso/enemy/slime/TObjEneSlime.h"
#include "pso/enemy/slime/TObjEneSlime_800EBBC8.h"
#include "pso/boss/darkfalz/TObjDFHorming.h"
#include "pso/enemy/slime/TObjEneSlime.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_800EBC28___vt__12TObjEneSlime {
    s32 value;
    u8 remaining[0x14C];
};

extern "C" {
s32 __ct__9TObjEnemyFP7TObject(void *);
extern s32 __vt__12TObjEneSlime[];
void TLobby__sub_8001FE7C(void*, int);
void __dl__7TObjectFPv(void *);
void *__dt__9TObjEnemyFv(TObjEnemy *arg0, s16 arg1);

}
extern "C" {


typedef char RecoveredGlobal_800EBC28___vt__12TObjEneSlime_size[sizeof(RecoveredGlobal_800EBC28___vt__12TObjEneSlime) == 0x150 ? 1 : -1];


}

// ---- folded from src/pso/enemy/TObjEneSlime_800EBD38.cpp ----
#include "types.h"
#include "pso/enemy/slime/TObjEneSlime_800EBBC8.h"
#include "pso/enemy/slime/TObjEneSlime.h"

extern "C" {

void *load_resource_from_descriptor(void *, s32, s32 *, s32, s32, s32);





}

// ---- folded from src/pso/player/TObjPlayer_800EBE2C.cpp ----
#include "types.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/player/TObjPlayer_800EBE2C.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/enemy/slime/TObjEneSlimeTailAttack.h"
#include "pso/player/TObjPlayer.h"
#include "pso/enemy/slime/TObjEneSlimeOne.h"

struct Stack_800EBE74 {
    f32 sp8;
    f32 spC;
    f32 sp10;
    f32 sp14;
};

extern "C" {
extern int saved_model_render_flags;
extern int saved_chunk_polygon_flags_and_mask;
extern int saved_chunk_polygon_flags_or_mask;
extern int chunk_polygon_flags_or_mask;
extern int chunk_polygon_flags_and_mask;
s32 find_nearest_hittable_enemy__10TObjPlayerFiPvf(void *, int, f32);



}


void TObjPlayer::push_material_color_override(f32 farg0, f32 farg1, f32 farg2, f32 farg3) {
    Stack_800EBE74 stack;
    (*(s32 *)&saved_model_render_flags) = (*(s32 *)&model_render_flags);
    (*(s32 *)&saved_chunk_polygon_flags_and_mask) = (*(s32 *)&chunk_polygon_flags_and_mask);
    (*(s32 *)&saved_chunk_polygon_flags_or_mask) = (*(s32 *)&chunk_polygon_flags_or_mask);
    (*(s32 *)&model_render_flags) |= 0x20;
    set_chunk_material_override_pair(0xFF00, 0x800);
    stack.spC = farg1;
    stack.sp10 = farg2;
    stack.sp8 = -1.0f + farg0;
    stack.sp14 = farg3;
    set_constant_material((const NJS_ARGB *)((&stack.sp8)));
}

void TObjPlayer__sub_800EBE48(f32 farg0) {
    TObjPlayer::push_material_color_override(farg0, 0.0f, 0.0f, 0.0f);
}

void TObjPlayer::init_render_globals() { chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask; chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask; model_render_flags = saved_model_render_flags; }

s32 TObjEneSlime::create(s32 arg0) {
    void *ene_slime;
    void *var_r4;

    ene_slime = __nw__7TObjectFUl(0x3D8);
    if (ene_slime != 0) {
        var_r4 = __nw__7TObjectFUl(0x20);
        if (var_r4 != 0) {
            var_r4 = __ct__11TObjControlFP7TObject(var_r4, tl_04);
        }
        ene_slime = TObjEneSlime__ct((TObjEneSlime *)ene_slime, (s32)var_r4, (u8 *)arg0);
    }
    return (s32)ene_slime;
}

void TObjEneSlime::spawn_pair() {
    void *temp_r4;
    void *temp_r5;
    void *temp_r5_2;

    temp_r4 = ::operator new(0x440);
    if (temp_r4 != NULL) {
        temp_r4 = load_resource_from_descriptor(temp_r4, 1, (s32 *)slime_pair_resource_descriptor, 0, 0, 0);
    }
    slime_bml_resource = temp_r4;
    temp_r5 = *(void **)((s8 *)temp_r4 + 0x42C);
    TObjEneSlime::spawn_child(0x28, *(s32 *)((s8 *)temp_r5 + 0x48), *(s32 *)((s8 *)temp_r5 + 0x4C), 10.0f, 0.0f);
    temp_r5_2 = *(void **)((s8 *)slime_bml_resource + 0x42C);
    TObjEneSlime::spawn_child(0x29, *(s32 *)((s8 *)temp_r5_2 + 0x58), *(s32 *)((s8 *)temp_r5_2 + 0x5C), 10.0f, 0.0f);
}

void TObjEneSlime::free_instance() {
    if ((u32) slime_bml_resource != 0U) {
        TLobby__sub_8001FE7C((void*)slime_bml_resource, 1);
        slime_bml_resource = 0U;
    }
}

u8 *TObjEneSlime__ct(TObjEneSlime *ene_slime, s32 arg1, u8 *arg2) {
    s32 temp_r0;
    __ct__9TObjEnemyFP7TObject(ene_slime);
    *(s32 **)((s8 *)ene_slime + 0x18) = &(*(RecoveredGlobal_800EBC28___vt__12TObjEneSlime *)&__vt__12TObjEneSlime).value;
    *(s32 *)((s8 *)ene_slime + 0) = (s32) lbl_805D2AD8;
    ((TObjEneSlime *)(ene_slime))->apply_set_data(arg2);
    ((TObjEneSlime *)(ene_slime))->clear_lobby_object_state();
    ((TBoss3Volopt *)ene_slime)->reset_photon_effect();
    TBoss4DarkFalz__sub_8004B4F0(((u8 *)ene_slime + 0x374), (arg2));
    ene_slime->m_3b4 = (s32) *(s16 *)((s8 *)arg2 + 2);
    temp_r0 = ene_slime->m_3b4;
    if (temp_r0 < 1) {
        if (TObjPlayer::check_demo_mode() != 0) {
            ene_slime->m_3b4 = 3;
        }
    } else if (temp_r0 > 4) {
        ene_slime->m_3b4 = 4;
    }
    ene_slime->actorFlags = (s32) (ene_slime->actorFlags | 0x02000000);
    ene_slime->init_slots();
    return (u8 *)ene_slime;
}

TObjEneSlime::~TObjEneSlime() {
    this->release_split_slimes();
}

void TObjEneSlime::vfunc_63() { this->release_split_slimes(); }

void TObjEneSlime::run_task() {
    s32 sp8;

    if ((TObjPlayer::check_demo_mode() == 0) && (has_no_active_slot((O_800EB8DC *)this) != 0)) {
        sp8 = 0x800;
        send_6x0A_enemy_state(&sp8);
        exchange_object_state((s32)&sp8, (s16)0);
        ((VObj_800EBB18_800EB9F0 *)this)->m77(&sp8);
        send_entity_set_flags();
        queue_destruction__7TObjectFv(this);
    }
}

void TObjEneSlime::render() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r30;
    s32 temp_r30_2;
    s32 temp_r31;
    temp_r31 = this->defer_render();
    if (TObjPlayer::check_demo_mode() != 0) {
        temp_r30 = (this->state36C * 4) & 4;
        debug_printf_at(0x130020, "TYPE [0/1] : %s", (int) (*(s32 *)((s8 *)((u8 *)slime_debug_label_table + temp_r30) + 0)));
        TObjPlayer::toggle_particle_effect();
        push_matrix();
        temp_r30_2 = *(s32 *)((s8 *)((u8 *)lbl_80496368 + temp_r30) + 0);
        post_translate_matrix((void *) ((u8 *)arg0 + 0x38));
        TObjFish__sub_8001EDB0((s32)slime_bml_resource, temp_r30_2);
        set_global_param__8TObjFishFl();
        if (temp_r31 != 0) {
            model_render_flags |= 0x400000;
            set_chunk_render_flags(1);
            draw_chunk_object((void *)get_bml_model((s32)slime_bml_resource, temp_r30_2));
            clear_chunk_render_flags();
            model_render_flags &= 0xFFBFFFFF;
        } else {
            set_chunk_render_flags(2);
            set_cull_back();
            draw_chunk_object((void *)get_bml_model((s32)slime_bml_resource, temp_r30_2));
            set_cull_front();
            draw_chunk_object((void *)get_bml_model((s32)slime_bml_resource, temp_r30_2));
            set_cull_none();
            clear_chunk_render_flags();
        }
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}

void TObjEneSlime__sub_800EB9F0(void* p, void* q) { *(u32*)((char*)p + 0x0) = *(u32*)((char*)q + 0x0); *(u32*)((char*)p + 0x4) = *(u32*)((char*)q + 0x4); }

void TObjEneSlime::init_slots() {
    s32 i;
    for (i = 0; i < 4; i++) {
        TObjEneSlime__sub_800EB9F0(&((Obj_800EB984 *)this)->slots[i], (void *)&lbl_8043D218);
    }
    spawn_slime_in_slot((Obj_800EB7BC *)this, 0, NULL, NULL);
}

void TObjEneSlime::release_split_slimes() {
    Obj_800EB910 *self = (Obj_800EB910 *)this;
    s32 i;
    for (i = 0; i < 4; i++) {
        Slot_800EB910 *s = &self->slots[i];
        if (s->state == 1) {
            if (s->obj != 0) {
                TObjEneSlimeOne__sub_800EC470(s->obj);
                s->obj = 0;
            }
            s->state = 2;
        }
    }
}

s32 has_no_active_slot(O_800EB8DC *self) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (self->arr[i].f0 == 1) {
            return 0;
        }
    }
    return 1;
}

s32 spawn_slime_in_slot(Obj_800EB7BC *origin, s32 arg1, Vec_800EB654 *arg2, Vec_800EB654 *arg3) {
    Tmpl_800EB7BC t;
    Slot_800EB7BC *slot;
    s32 n;
    if (arg1 < 0 || arg1 >= origin->count || origin->slots[arg1].active != 0) {
        return 0;
    }
    *(Blob_800EB7BC *) &t = *(Blob_800EB7BC *) &origin->tmpl;
    n = arg1 + 1;
    t.a = origin->tmpl.a + n;
    t.b = 0;
    t.d = origin->tmpl.d + n;
    if (arg2 == NULL) {
        VecCopy((Vec *)&t.pos, (const Vec *)&origin->pos);
    } else {
        VecCopy((Vec *)&t.pos, (const Vec *)arg2);
    }
    slot = &origin->slots[arg1];
    if (arg3 == 0) {
        slot->obj = TObjEneSlimeOne::create((s32) origin, (s32) &t);
    } else {
        slot->obj = TObjEneSlimeOne::create((s32) origin, (s32) &t, (s32) arg3);
    }
    if (slot->obj == 0) {
        return 0;
    }
    slot->active = 1;
    return 1;
}

void fn_800EB778(Obj_800EB778 *self, s32 id) {
    s32 i = id - self->id - 1;
    if (i < 0 || i >= 4 || self->slots[i].state != 1) {
        return;
    }
    self->slots[i].obj = 0;
    self->slots[i].state = 2;
}

struct Bomb_800E9090;

s32 TObjEneSlimeOne::try_spawn_child(void *arg1) {
    s32 i;
    Vec_800EB654 pos;
    Vec_800EB654 dir;
    s32 ang;
    s32 n;
    int origin = (int)this;
    n = *(s32 *)((s8 *)origin + 0x3B4);
    for (i = 0; i < n && *(s32 *)((s8 *)((u8 *) origin + i * 8) + 0x3B8) != 0; i++) {
    }
    if (i == n) {
        return 0;
    }
    VecCopy((Vec *)&pos, (const Vec *)arg1);
    pos.y += 10.0f;
    ang = (s16) (65535.0f * ((f32 (*)(int)) random_ratio__9TObjCharaFv)(origin));
    dir.x = sin_table_lookup(ang);
    dir.y = 0.0f;
    dir.z = cos_table_lookup(ang);
    if (vector_length(&dir) <= 0.01f) {
        dir.x = 1.0f;
        dir.y = 0.0f;
        dir.z = 0.0f;
    } else {
        normalize_vector(&dir);
    }
    play_sound_effect(0x4003A619, &pos, 0, 0);
    return spawn_slime_in_slot((Obj_800EB7BC *) origin, i, &pos, &dir);
}

s32 TObjEneSlimeOne::create(s32 arg0, s32 arg1) {
    s32 var_r31;
    s32 var_r4;

    var_r31 = ((s32 (*)(s32))__nw__7TObjectFUl)(0x3F8);
    if (var_r31 != 0) {
        var_r4 = ((s32 (*)(s32))__nw__7TObjectFUl)(0x20);
        if (var_r4 != 0) {
            var_r4 = ((s32 (*)(s32, s32))__ct__11TObjControlFP7TObject)(var_r4, tl_04);
        }
        var_r31 = ((s32)init__15TObjEneSlimeOneFPviii((u8 *)var_r31, (s32)var_r4, (s32)arg0, (s32)arg1));
    }
    return var_r31;
}

s32 TObjEneSlimeOne::create(s32 arg0, s32 arg1, s32 arg2) {
    s32 actor;
    s32 var_r4;

    actor = ((s32 (*)(s32))__nw__7TObjectFUl)(0x3F8);
    if (actor != 0) {
        var_r4 = ((s32 (*)(s32))__nw__7TObjectFUl)(0x20);
        if (var_r4 != 0) {
            var_r4 = ((s32 (*)(s32, s32))__ct__11TObjControlFP7TObject)(var_r4, tl_04);
        }
        actor = ((s32)TObjEneSlimeOne__ct((u8 *)actor, (s32)var_r4, (s32)arg0, (s32)arg1, (s32)arg2));
    }
    return actor;
}

u8 *init__15TObjEneSlimeOneFPviii(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    typedef char sp8_offset[(offsetof(Stack_800EB4A0, sp8) == 0x0) ? 1 : -1];
    typedef char spE_offset[(offsetof(Stack_800EB4A0, spE) == 0x6) ? 1 : -1];
    Stack_800EB4A0 stack;
    __ct__9TObjEnemyFP7TObject(arg0);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_800EB4A0___vt__15TObjEneSlimeOne *)&__vt__15TObjEneSlimeOne).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TObjEneSlimeOne_class_name;
    ((TObjChara *)arg0)->add_flags_2e4(2);
    ((TObjEneSlimeOne *)(arg0))->apply_set_data((void *)arg3);
    if (exchange_object_state__9TObjEnemyFls(arg0, &stack.sp8, 1) != 0) {
        stack.sp8 = 0;
        stack.spE = 0;
        exchange_object_state__9TObjEnemyFls(arg0, &stack.sp8, 0);
    }
    ((TObjEneSlimeOne *)arg0)->parent_slime = arg2;
    ((TObjEneSlimeOne *)arg0)->initialize_slime_instance_state();
    project_actor_to_ground(arg0, arg0 + 0x38, 0);
    ((TObjEneSlimeOne *)arg0)->set_state((s32)((void*)(0)));
    return arg0;
}

u8 *TObjEneSlimeOne__ct(u8 *actor, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    typedef char sp8_offset[(offsetof(Stack_800EB3D4, sp8) == 0x0) ? 1 : -1];
    typedef char spE_offset[(offsetof(Stack_800EB3D4, spE) == 0x6) ? 1 : -1];
    Stack_800EB3D4 stack;
    __ct__9TObjEnemyFP7TObject(actor);
    *(s32 **)((s8 *)actor + 0x18) = &(*(RecoveredGlobal_800EB3D4___vt__15TObjEneSlimeOne *)&__vt__15TObjEneSlimeOne).value;
    *(s32 *)((s8 *)actor + 0) = (s32) TObjEneSlimeOne_class_name;
    ((TObjChara *)actor)->add_flags_2e4(2);
    ((TObjEneSlimeOne *)(actor))->apply_set_data((void *)arg3);
    if (exchange_object_state__9TObjEnemyFls(actor, &stack.sp8, 1) != 0) {
        stack.sp8 = 0;
        stack.spE = 0;
        exchange_object_state__9TObjEnemyFls(actor, &stack.sp8, 0);
    }
    ((TObjEneSlimeOne *)actor)->parent_slime = arg2;
    VecCopy((Vec *)(actor + 0x3DC), (const Vec *)(arg4));
    ((TObjEneSlimeOne *)actor)->initialize_slime_instance_state();
    ((TObjEneSlimeOne *)actor)->set_state((s32)((void*)(0xE)));
    return actor;
}

void TObjEneSlimeOne::initialize_slime_instance_state() {
  void *p;
  s32 id;
  s32 *new_var2;
  u8 *new_var;
    u8 *actor = (u8 *)this;
  ((TObjEneSlimeOne *)actor)->model_archive = get_instance__15TObjEneSlimeOneFv();
  if ((random_ratio__9TObjCharaFv(actor) < 0.002f) || ((((TObjEneSlimeOne *)actor)->state36C) & 1))
  {
    *((s32 *) (((s8 *) actor) + 0x3F4)) = 1;
  }
  else
  {
    *((s32 *) (((s8 *) actor) + 0x3F4)) = 0;
  }
  new_var2 = &(*((s32 *) (((s8 *) actor) + 0x3F4)));
  id = ((s32 *) lbl_804966DC)[*new_var2];
  ((TObjEneSlimeOne *)actor)->texlist = TObjFish__sub_8001EDB0((s32)(((TObjEneSlimeOne *)actor)->model_archive), id);
  *((s32 *) (((s8 *) actor) + 0x34)) = get_bml_model((s32)(((TObjEneSlimeOne *)actor)->model_archive), id);
  VecCopy((Vec *)(actor + 0x44), (const Vec *)((u8 *)VecCopy((Vec *)(actor + 0x50), (const Vec *)((void *)VecCopy((Vec *)(actor + 0x74), (const Vec *)(actor + 0x38))))));
  *((s32 *) (((s8 *) actor) + 0x38C)) = init_collision_body_parts(actor, lbl_80496370, 1);
  ((TObjMotion *)actor)->set_field_d8((s32)lbl_8049639C);
  ((TObjMotion *)actor)->set_field_dc(*((s32 *) (((s8 *) (((TObjEneSlimeOne *)actor)->model_archive)) + 0x430)));
  ((TObjMotion *)actor)->set_animation(0);
  ((TObjMotion *)actor)->set_field_b8(0);
  VecCopy((Vec *)(new_var = actor + 0x2FC), (const Vec *)(actor + 0x38));
  ((TObjEneSlimeOne *)actor)->m_310 = 0.0f;
  *((f32 *) (((s8 *) actor) + 0x30C)) = 0.0f;
  *((f32 *) (((s8 *) actor) + 0x308)) = 0.0f;
  *((s32 *) (((s8 *) actor) + 0x2A8)) = 0;
  if ((*new_var2) == 0)
  {
    ((TObjEnemy *)actor)->bind_enemy_combat_stats((u8 *)(TLobby::register_boss(0x30)), (u8 *)(TLobby::dispatch_shared_handler_b(0x30)), (u8 *)(TLobby::register_object(0x30)));
  }
  else
  {
    ((TObjEnemy *)actor)->bind_enemy_combat_stats((u8 *)(TLobby::register_boss(0x34)), (u8 *)(TLobby::dispatch_shared_handler_b(0x34)), (u8 *)(TLobby::register_object(0x34)));
  }
  ((TObjEneSlimeOne *)actor)->referenceHp = ((TObjEneSlimeOne *)actor)->hp;
  ((TBoss3Volopt *)actor)->reset_photon_effect();
  *((s32 *) (((s8 *) actor) + 0x350)) = 0;
  if ((*new_var2) == 0)
  {
    ((TObjEnemy *)actor)->set_param(0x13);
  }
  else
  {
    ((TObjEnemy *)actor)->set_param(0x14);
  }
  p = ::operator new(0x34);
  if (p != 0)
  {
    p = fn_800ECA28(p, (s32)actor);
  }
  *((void **) (((s8 *) actor) + 0x388)) = p;
  *((s32 *) (((s8 *) actor) + 0x3E8)) = 0;
  ((TObjEneSlimeOne *)actor)->target_client_id = 0xFFFF;
  ((TObjEneSlimeOne *)actor)->copy_position();
}

TObjEneSlimeOne::~TObjEneSlimeOne() {
    free_collision_body_parts(this);
    this->collision_body_parts = NULL;
    if (this->particle != NULL) {
        TParticleCtrl::release(this->particle);
        this->particle = NULL;
    }
    __dt__15TObjEneSlimeOneFis((s32)this->m_388, 1);
    this->m_388 = 0;
}

void TObjEneSlimeOne::run_task() {
    if (TObjPlayer::check_demo_mode() == 0) {
        if ((s32)this->state != 13 && (this->parent_slime == 0 || ((TObject *)this->parent_slime)->all_parents_unqueued_for_destruction() == 0)) {
            set_state(13);
        }
        set_target_flag_bit0();
        {
            SlimeOneState *tbl = lbl_80496574;
            SlimeOneStateFn a = tbl[this->state].update;
            if (a != 0) {}
            (this->*a)();
        }
        update_prev_position();
        ((TObjPlayer *)this)->update_collisions();
        if ((s32)this->m_3ec != 0) {
            submit_cursor_candidate(this, -1);
        }
        ((TObjEneSlimeOne *)this->m_388)->advance_animation_state();
        play_persistent_sound(0x4003B21C, (s32)this, (u32)&this->position, 0, 0);
        fn_800E9238((s32)this);
        clear_child_flag();
        if ((s32)this->state != 13) {
            minimap_render_dot((u8 *)this + 0x2FC, -0x5DB4, 1, 0);
        }
    }
}
void render__15TObjEneSlimeOneFv(TObjEneSlimeOne *ene_slime_one) {
    s32 temp_r31;
    if ((TObjPlayer::check_demo_mode() == 0) && !(ene_slime_one->alpha <= 0.0f) && (((VObj_18_26a62c *)(ene_slime_one))->m8(500.0f, 20.0f) != 0)) {
        temp_r31 = ene_slime_one->defer_render();
        if (ene_slime_one->alpha < 1.0f) {
            TObjPlayer__sub_800EBE48(ene_slime_one->alpha);
        }
        TObjPlayer::toggle_particle_effect();
        push_matrix();
        {
            Vec_800EAEE8 v = *(Vec_800EAEE8 *)((u8 *)ene_slime_one + 0x38);
            v.y += ene_slime_one->draw_offset_y;
            post_translate_matrix(&v);
        }
        rotate_matrix_y(0, ene_slime_one->rotation_y);
        scale_matrix_vec3(0, ((u8 *)ene_slime_one + 0x3A8));
        ((TObjEneSlimeOne *)(ene_slime_one->m_388))->draw_part(temp_r31);
        pop_matrix();
        TParticleCtrl::end_effect_render();
        if (ene_slime_one->alpha < 1.0f) {
            TObjPlayer::init_render_globals();
        }
        ene_slime_one->sub_800E9090();
    }
}

void TObjEneSlimeOne::set_state(s32 arg1) {
    this->state = arg1;
    SlimeOneStateFn a = lbl_80496574[this->state].enter;
    if (a != 0) {}
    (this->*a)();
}

void set_random_timer__15TObjEneSlimeOneFPvii(void *arg0, s32 arg1, s32 arg2) {
    *(s32 *)((s8 *)arg0 + 0x390) = (s32) (arg1 + (s32) ((f32) arg2 * ((f32 (*)(void))random_ratio__9TObjCharaFv)()));
}
s32 TObjEneSlimeOne__sub_800EAD84(Obj_800EAD84 *arg0) {
    Vec_800EAD84 sp = arg0->pos;
    sp.y += 5.0f;
    if (project_actor_to_ground(arg0, &sp, 0) != 0) {
        arg0->pos.y += 0.5f * (sp.y - arg0->pos.y);
        return 1;
    }
    return 0;
}

void set_display_mode__15TObjEneSlimeOneFPvi(void *arg0, s32 arg1) {
    void *temp_r5;
    void *temp_r5_2;
    void *temp_r6;

    temp_r6 = *(void **)((s8 *)arg0 + 0x38C);
    *(s32 *)((s8 *)temp_r6 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r6 + 0x18) & 0xF5FFF297);
    switch (arg1) {
    case 0:
        temp_r5 = *(void **)((s8 *)arg0 + 0x38C);
        *(s32 *)((s8 *)temp_r5 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r5 + 0x18) | 0x0A000000 | 0x528);
        *(s32 *)((s8 *)arg0 + 0x3EC) = 0;
        return;
    case 1:
        temp_r5_2 = *(void **)((s8 *)arg0 + 0x38C);
        *(s32 *)((s8 *)temp_r5_2 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r5_2 + 0x18) | 0x0A000000 | 0x28);
        *(s32 *)((s8 *)arg0 + 0x3EC) = 0;
        return;
    case 2:
        *(s32 *)((s8 *)arg0 + 0x3EC) = 1;
        return;
    }
}

void TObjEneSlimeOne::set_target_flag_bit0() {
    void *temp_r3;

    temp_r3 = *(void **)((s8 *)this + 0x38C);
    *(s32 *)((s8 *)temp_r3 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r3 + 0x18) | 1);
}

void TObjEneSlimeOne::clear_child_flag() {
    void *temp_r3;

    if ((s32) this->m_3ec == 0) {
        temp_r3 = *(void **)((s8 *)this + 0x38C);
        *(s32 *)((s8 *)temp_r3 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r3 + 0x18) & 0xFFFFFFFE);
    }
}

f32 TObjEneSlimeOne::receive_direct_attack(void *attacker, DirectAttackPayload payload,
                                         void *source, s32, s32) {
    if (payload.kind == 2 && parent_slime != 0 &&
        ((TObjEneSlimeOne *)parent_slime)->all_parents_unqueued_for_destruction()) {
        ((TObjEneSlimeOne *)parent_slime)->try_spawn_child(&position);
    }
    TObjChara::receive_direct_attack(attacker, payload, source, -1, -1);
    return 0.0f;
}

void TObjEneSlimeOne::vfunc_63() { if (*(int *)&this->state != 13) { set_state((s32)((void*)((void*)13))); } }

void TObjEneSlimeOne::vfunc_62() {
    u8 *arg0 = (u8 *)this;
    if ((s32) this->state != 0xC) {
        if (((s32) this->m_2d4 < (s32) registered_player_count) && (((u32 (*)(void))get_player_by_client_id)() != 0U) && (check_player_field_7cc__15TObjEneSlimeOneFv() == 2) && ((u32) this->parent_slime != 0U) && (((TObject *)((void *) this->parent_slime))->all_parents_unqueued_for_destruction() != 0)) {
            ((TObjEneSlimeOne *)(this->parent_slime))->try_spawn_child((u8 *)&this->position);
        }
        this->actorFlags = (s32) (this->actorFlags & 0xFFFFFDFF);
        ((TObjEneSlimeOne *)arg0)->set_state((s32)((void*)(0xC)));
    }
}

void TObjEneSlimeOne::vfunc_61() {
    u8 *arg0 = (u8 *)this;
    if ((s32) this->state != 0xB) {
        this->actorFlags = (s32) (this->actorFlags & 0xFFFFFEFF);
        ((TObjEneSlimeOne *)arg0)->set_state((s32)((void*)(0xB)));
    }
}

void TObjEneSlimeOne::set_random_timer_15() { set_random_timer__15TObjEneSlimeOneFPvii(this, 15, 15); }

void TObjEneSlimeOne::init_state() { ((int (*)(void))TObjEneSlimeOne__sub_800EAD84)(); this->draw_offset_y = -2.5f; this->draw_scale.z = 0.0f; this->draw_scale.y = 0.0f; this->draw_scale.x = 0.0f; this->alpha = 0.0f; this->m_3c8 = 0; ((TObjEneSlimeOne *)(this->m_388))->set_motion_state((s32)((void*)7)); set_display_mode__15TObjEneSlimeOneFPvi(this, (s32)((void*)((void*)0))); this->actorFlags = (this->actorFlags | 0x40000); this->set_random_timer_15(); }

void TObjEneSlimeOne::update_wait_search() {
    s32 temp_r0;
    s32 temp_r0_2;

    temp_r0 = this->state_timer - 1;
    this->state_timer = temp_r0;
    if (temp_r0 <= 0) {
        if (((u16 (*)(void *, s32, f32))find_nearest_visible_player)(this, 0, (200.0f)) == 0xFFFF) {
            temp_r0_2 = this->m_3c8 + 1;
            this->m_3c8 = temp_r0_2;
            if (temp_r0_2 >= 5) {
                *(f32 *)((s8 *)this + 0x38) = (f32) *(f32 *)((s8 *)this + 0x50);
                *(f32 *)((s8 *)this + 0x40) = (f32) *(f32 *)((s8 *)this + 0x58);
                this->m_3c8 = 5;
            }
            this->set_random_timer_15();
            return;
        }
        this->set_state((s32)((void*)(1)));
    }
}

void TObjEneSlimeOne::reset_display() { set_display_mode__15TObjEneSlimeOneFPvi(this, (s32)((void*)(0))); this->actorFlags = (this->actorFlags & 0xfffbffff); this->m_398 = 0.0f; this->draw_offset_y = -2.5f; }
void TObjEneSlimeOne::sub_800EA820() {
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 var_f31;
    this->draw_offset_y = (f32) (-2.5f * (1.0f - this->m_398));
    this->draw_scale.x = (f32) ((this->m_398 * (*(f32 *)((s8 *)&lbl_8043D23C.value + 0) - *(f32 *)((s8 *)&lbl_8043D230.value + 0))) + *(f32 *)((s8 *)&lbl_8043D230.value + 0));
    this->draw_scale.y = (f32) ((this->m_398 * (*(f32 *)((s8 *)&lbl_8043D23C.value + 4) - *(f32 *)((s8 *)&lbl_8043D230.value + 4))) + *(f32 *)((s8 *)&lbl_8043D230.value + 4));
    this->draw_scale.z = (f32) ((this->m_398 * (*(f32 *)((s8 *)&lbl_8043D23C.value + 8) - *(f32 *)((s8 *)&lbl_8043D230.value + 8))) + *(f32 *)((s8 *)&lbl_8043D230.value + 8));
    var_f31 = 1.0f;
    temp_f1 = this->m_398;
    if (temp_f1 > 0.8f) {
        var_f31 = (1.0f - temp_f1) / 0.19999999f;
    }
    temp_f1_2 = var_f31 * (0.1f * sin_table_lookup(this->state_timer << 0xC));
    this->draw_scale.x = (f32) (this->draw_scale.x * (1.0f + temp_f1_2));
    this->draw_scale.z = (f32) (this->draw_scale.z * (1.0f - temp_f1_2));
    this->state_timer = (s32) (this->state_timer + 1);
    temp_f1_3 = this->m_398;
    if (temp_f1_3 >= 0.5f) {
        this->alpha = (f32) 1.0f;
    } else {
        this->alpha = (f32) (2.0f * temp_f1_3);
    }
    if ((this->m_398 += 0.033333335f) > 1.0f) {
        if (find_nearest_visible_player(((u8 *)this), 0, 200.0f) != 0xFFFF) {
            this->set_state(3);
        } else {
            this->set_state(2);
        }
    }
}

void TObjEneSlimeOne::init_slime_display() { *(float*)((char*)this + 0x398) = 1.0f; this->draw_offset_y = 0.0f; ((int (*)(void*, int))set_display_mode__15TObjEneSlimeOneFPvi)(this, 0); ((TObjEneSlimeOne *)(*(int*)((char*)this + 0x388)))->set_motion_state((s32)((void*)((void*)7))); }
void TObjEneSlimeOne::sub_800EA678() {
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 var_f31;
    this->draw_offset_y = (f32) (-2.5f * (1.0f - this->m_398));
    this->draw_scale.x = (f32) ((this->m_398 * (*(f32 *)((s8 *)&lbl_8043D23C.value + 0) - *(f32 *)((s8 *)&lbl_8043D230.value + 0))) + *(f32 *)((s8 *)&lbl_8043D230.value + 0));
    this->draw_scale.y = (f32) ((this->m_398 * (*(f32 *)((s8 *)&lbl_8043D23C.value + 4) - *(f32 *)((s8 *)&lbl_8043D230.value + 4))) + *(f32 *)((s8 *)&lbl_8043D230.value + 4));
    this->draw_scale.z = (f32) ((this->m_398 * (*(f32 *)((s8 *)&lbl_8043D23C.value + 8) - *(f32 *)((s8 *)&lbl_8043D230.value + 8))) + *(f32 *)((s8 *)&lbl_8043D230.value + 8));
    var_f31 = 1.0f;
    temp_f1 = this->m_398;
    if (temp_f1 > 0.8f) {
        var_f31 = (1.0f - temp_f1) / 0.19999999f;
    }
    temp_f1_2 = var_f31 * (0.15f * sin_table_lookup(this->state_timer << 0xA));
    this->draw_scale.x = (f32) (this->draw_scale.x * (1.0f + temp_f1_2));
    this->draw_scale.z = (f32) (this->draw_scale.z * (1.0f - temp_f1_2));
    this->state_timer = (s32) (this->state_timer + 1);
    temp_f1_3 = this->m_398;
    if (temp_f1_3 >= 0.5f) {
        this->alpha = (f32) 1.0f;
    } else {
        this->alpha = (f32) (2.0f * temp_f1_3);
    }
    if ((this->m_398 += -0.011111111f) < 0.0f) {
        this->set_state(0);
    }
}
void TObjEneSlimeOne::sub_800EA56C() {
    s32 temp_r31;
    u8 *actor = (u8 *)this;
    *(f32 *)((s8 *)actor + 0x3B4) = (f32) 0.0f;
    if (find_nearest_visible_player(actor, actor + 0x3B8, 200.0f) == 0xFFFF) {
        ((TObjEneSlimeOne *)actor)->set_state(2);
        return;
    }
    temp_r31 = (s32) (1048575.0f * random_ratio__9TObjCharaFv(actor));
    *(f32 *)((s8 *)actor + 0x3B8) = (f32) ((15.0f * sin_table_lookup(temp_r31)) + *(f32 *)((s8 *)actor + 0x3B8));
    *(f32 *)((s8 *)actor + 0x3C0) = (f32) ((15.0f * cos_table_lookup(temp_r31)) + *(f32 *)((s8 *)actor + 0x3C0));
    if (vector_length(actor + 0x3B8) <= 0.01f) {
        ((TObjEneSlimeOne *)actor)->set_state(2);
        return;
    }
    ((s32 (*)(void *))normalize_vector)(actor + 0x3B8);
    *(f32 *)((s8 *)actor + 0x398) = ((20.0f * random_ratio__9TObjCharaFv(actor)) + 50.0f);
    *(f32 *)((s8 *)actor + 0x3A0) = (f32) 1.0f;
    ((TObjEneSlimeOne *)((void *) *(s32 *)((s8 *)actor + 0x388)))->set_motion_state((s32)((void *) 8));
    ((int (*)(void*, int))set_display_mode__15TObjEneSlimeOneFPvi)(actor, 1);
}
void TObjEneSlimeOne::sub_800EA364() {
    Vec_800EA364 sp8;
    f32 s;
    f32 c;
    f32 accel;  // inferred: the per-frame speed-up added to move_speed
    s32 i;
    s32 ang;
    rotation_y += 0x100;
    if (m_398 > 0.0f) {
        m_39c += 0xC00;
        accel = 0.25f * (0.5f * (0.5f + sin_table_lookup(m_39c)));
        if ((move_speed += accel) > 2.5f) {
            move_speed = 2.5f;
        }
    } else {
        if ((move_speed -= 0.25f) < 0.0f) {
            move_speed = 0.0f;
        }
    }
    m_398 -= move_speed;
    VecCopy(&prev_position, &position);
    for (i = 1; i < 15; i++) {
        position.x += move_speed * move_dir_x;
        position.y += move_speed * move_dir_y;
        position.z += move_speed * move_dir_z;
        if (TObjEneSlimeOne__sub_800EAD84((Obj_800EAD84 *)this) != 0 && csnLookAt(&prev_position, &position) == 0) {
            break;
        }
        ang = i << 12;
        if (i & 1) {
            ang *= -1;
        }
        s = sin_table_lookup(ang);
        c = cos_table_lookup(ang);
        move_dir_x = c * move_dir_x - s * move_dir_z;
        move_dir_z = s * move_dir_x + c * move_dir_z;
        VecCopy(&position, &prev_position);
    }
    if (m_398 <= 0.0f && 0.0f == move_speed) {
        if (find_nearest_visible_player(this, &sp8, 50.0f) != 0xFFFF && vector_length(&sp8) > 15.0f) {
            set_state(4);
        } else {
            set_state(3);
        }
    }
}

void TObjEneSlimeOne::enter_slime_state() {
    *(s32 *)((s8 *)((u8 *)this) + 0x394) = 8;
    ((TObjEneSlimeOne *)(*(s32 *)((s8 *)((u8 *)this) + 0x388)))->set_motion_state((s32)((void*)(9)));
    ((s32 (*)(s32, void *, s32, s32))play_sound_effect)(0x4003AD1D, ((u8 *)this) + 0x38, 0, 0);
    ((int (*)(void*, int))set_display_mode__15TObjEneSlimeOneFPvi)(((u8 *)this), 1);
}

void TObjEneSlimeOne::update_slime_timer() {
    s32 temp_r0;

    temp_r0 = *(s32 *)((s8 *)((u8 *)this) + 0x394) - 1;
    *(s32 *)((s8 *)((u8 *)this) + 0x394) = temp_r0;
    if (temp_r0 == 0) {
        spawn_particle_effect(((u8 *)this) + 0x2FC, 0xCD);
    }
    if (((TObjEneSlimeOne *)(this->m_388))->is_reached_target_depth() == 1) {
        if (this->is_timer_active() != 0) {
            this->set_state(7);
            return;
        }
        this->set_state(6);
    }
}

void TObjEneSlimeOne::enter_appear_state() {
    *(s32 *)((s8 *)((u8 *)this) + 0x394) = 0x14;
    ((s32 (*)(s32, void *, s32, s32))play_sound_effect)(0x4003AD1D, ((u8 *)this) + 0x38, 0, 0);
    ((TObjEneSlimeOne *)(*(s32 *)((s8 *)((u8 *)this) + 0x388)))->set_motion_state((s32)((void*)(0xA)));
    ((int (*)(void*, int))set_display_mode__15TObjEneSlimeOneFPvi)(((u8 *)this), 1);
}

void TObjEneSlimeOne::update_dive_timer() {
    s32 temp_r0;

    temp_r0 = *(s32 *)((s8 *)((u8 *)this) + 0x394) - 1;
    *(s32 *)((s8 *)((u8 *)this) + 0x394) = temp_r0;
    if (temp_r0 == 0) {
        spawn_particle_effect(((u8 *)this) + 0x2FC, 0xCD);
    }
    if (((TObjEneSlimeOne *)(this->m_388))->is_reached_target_depth() == 1) {
        this->set_state(3);
    }
}

void TObjEneSlimeOne::sub_800EA120() {
  unsigned int new_var;
  *((s32 *) (((s8 *) ((u8 *)this)) + 0x3CC)) = 0xFFFF;
  *((s32 *) (((s8 *) ((u8 *)this)) + 0x39C)) = (s32) ((((s32) (4.0f * random_ratio__9TObjCharaFv((void *)((s32) ((u8 *)this))))) + 4) << 0x10);
  *((s32 *) (((s8 *) ((u8 *)this)) + 0x390)) = 0x7FFFFFFF;
  *((s32 *) (((s8 *) ((u8 *)this)) + 0x3C4)) = 0x400;
  new_var = 1;
  if (random_ratio__9TObjCharaFv((void *)((s32) ((u8 *)this))) > 0.5f)
  {
    *((s32 *) (((s8 *) ((u8 *)this)) + 0x3C4)) = (s32) ((*((s32 *) (((s8 *) ((u8 *)this)) + 0x3C4))) * (-new_var));
  }
  ((TObjEneSlimeOne *)(*((s32 *) (((s8 *) ((u8 *)this)) + 0x388))))->set_motion_state((s32)((void*)((int) new_var)));
  ((int (*)(void*, int))set_display_mode__15TObjEneSlimeOneFPvi)(((u8 *)this), 2);
}
void TObjEneSlimeOne::sub_800E9EFC() {
    Vec_800E9EFC sp14;
    Vec_800E9EFC sp8;
    f32 f;
    u16 r;
    s32 n;

    f = sin_table_lookup(*(s32 *)((s8 *)((u8 *)this) + 0x39C));
    if (f < 0.0f) {
        f = 0.0f;
    }
    this->rotation_y = f * (f32)this->turn_speed + (f32)this->rotation_y;
    if (this->target_client_id == 0xFFFF) {
        r = find_nearest_visible_player(((u8 *)this), &sp14, 162.5f);
        if (r != 0xFFFF &&
            angle_difference_abs(this->rotation_y, (s32)(10430.38043493439 * ((f32 (*)(f32, f32))atan2_float)(sp14.x, sp14.z))) < 0x1C71) {
            *(s32 *)((s8 *)((u8 *)this) + 0x39C) = 0;
            this->target_client_id = r;
        }
    }
    *(s32 *)((s8 *)((u8 *)this) + 0x39C) -= 0x600;
    if (*(s32 *)((s8 *)((u8 *)this) + 0x39C) <= 0) {
        n = (f32)*(u32 *)((s8 *)(get_bml_motion(*(s32 *)((s8 *)((u8 *)this) + 0x380), 10)) + 4) / 0.5f;
        *(s32 *)((s8 *)((u8 *)this) + 0x39C) = 0;
        if (this->target_client_id != 0xFFFF) {
            sp8.x = 1.0f;
            sp8.y = 0.0f;
            sp8.z = 0.0f;
            TObjPlayer::calc_distance_to_client((s32)((u8 *)this), (u16)(this->target_client_id), (u32)&sp8);
            this->rotation_y = approach_angle_limited(this->rotation_y, (s32)(10430.38043493439 * ((f32 (*)(f32, f32))atan2_float)(sp8.x, sp8.z)), 0x280);
        }
        if (this->state_timer > n) {
            ((TObjEneSlimeOne *)((void *)this->m_388))->set_motion_state((s32)((void *)0));
            this->state_timer = n;
        } else if (--this->state_timer <= 0) {
            if (this->target_client_id == 0xFFFF) {
                this->set_state(5);
            } else {
                this->set_state(8);
            }
        }
    }
}

void TObjEneSlimeOne::init_slime_state() {
    ((s32 (*)(void *, s32, s32))set_random_timer__15TObjEneSlimeOneFPvii)(this, 0x1E, 0x1E);
    this->turn_speed = 0x888;
    if (random_ratio__9TObjCharaFv(this) > 0.5f) {
        this->turn_speed = this->turn_speed * 0xFFFFFFFF;
    }
    ((TObjEneSlimeOne *)(*(s32 *)((s8 *)this + 0x388)))->set_motion_state((s32)((void*)(1)));
    ((int (*)(void*, int))set_display_mode__15TObjEneSlimeOneFPvi)(this, 2);
}

void TObjEneSlimeOne::sub_800E9DC8() {
    f32 sp[3];
    s32 r = 0;
    s32 t;
    ((Obj_800E9DC8 *)this)->rotation_y = ((Obj_800E9DC8 *)this)->rotation_y + ((Obj_800E9DC8 *)this)->turn_speed;
    if (((TObjEneSlimeOne *)((Obj_800E9DC8 *)this))->find_nearest_enemy_with_flag((s32)sp, 500.0f) != 0xFFFF) {
        t = (s32) (10430.38043493439 * atan2_float(sp[0], sp[2]));
        if (angle_difference_abs(((Obj_800E9DC8 *)this)->rotation_y, t) < 0x444) {
            ((Obj_800E9DC8 *)this)->rotation_y = t;
            r = 1;
        }
    }
    ((Obj_800E9DC8 *)this)->state_timer = ((Obj_800E9DC8 *)this)->state_timer - 1;
    if (r != 0 || ((Obj_800E9DC8 *)this)->state_timer < 0) {
        ((TObjEneSlimeOne *)((Obj_800E9DC8 *)this))->set_state(9);
    }
}

void TObjEneSlimeOne::sub_800E9D7C() { ((int (*)(void*, void*, void*))set_random_timer__15TObjEneSlimeOneFPvii)(this, (void*)30, (void*)30); ((TObjEneSlimeOne *)(*(void**)((char*)this + 0x388)))->set_motion_state((s32)((void*)0)); ((int (*)(void*, void*))set_display_mode__15TObjEneSlimeOneFPvi)(this, (void*)2); }

void TObjEneSlimeOne::sub_800E9BCC() {
    f32 v[3];
    s32 t;
    v[0] = 1.0f;
    v[1] = 0.0f;
    v[2] = 0.0f;
    Obj_800E9BCC *o = (Obj_800E9BCC *)this;
    if (o->target_client_id != 0xFFFF) {
        TObjPlayer::calc_distance_to_client((s32)o, (u16)o->target_client_id, (u32)v);
    }
    t = (s32) (10430.38043493439 * atan2_float(v[0], v[2]));
    o->rotation_y = approach_angle_limited(o->rotation_y, t, 0x200);
    if (angle_difference_abs(o->rotation_y, t) < 0x200) {
        o->state_timer = 0;
    }
    VecCopy((Vec *)o->prev, (const Vec *)o->pos);
    if (vector_length(v) <= 0.01f) {
        v[0] = 1.0f;
        v[1] = 0.0f;
        v[2] = 0.0f;
    } else {
        normalize_vector(v);
    }
    v[0] *= 0.2f;
    v[1] *= 0.2f;
    v[2] *= 0.2f;
    vec3_add_to(o->pos, v);
    if (project_actor_to_ground(o, o->pos, 0) == 0 || csnLookAt(o->prev, o->pos) != 0) {
        VecCopy((Vec *)o->pos, (const Vec *)o->prev);
    }
    if (--o->state_timer <= 0) {
        if (vector_length(v) > 50.0f || random_ratio__9TObjCharaFv(o) < 0.45f) {
            ((TObjEneSlimeOne *)o)->set_state(9);
        } else {
            ((TObjEneSlimeOne *)o)->set_state(10);
        }
    }
}

void TObjEneSlimeOne::begin_appear() { *(int*)((char*)this + 0x390) = 90; *(int*)((char*)this + 0x394) = 19; ((TObjEneSlimeOne *)(*(void**)((char*)this + 0x388)))->set_motion_state((s32)((void*)3)); ((int (*)(void*, void*))set_display_mode__15TObjEneSlimeOneFPvi)(this, (void*)2); }

void TObjEneSlimeOne::update_water_bomb_timer() {
    s32 temp_r0;
    s32 temp_r0_2;

    *(s32 *)((s8 *)((u8 *)this) + 0x394) = (s32) (*(s32 *)((s8 *)((u8 *)this) + 0x394) - 1);
    temp_r0 = *(s32 *)((s8 *)((u8 *)this) + 0x394);
    if (temp_r0 > 0) {
        spawn_particle_effect(((u8 *)this) + 0x2FC, 0xFF);
    } else if (temp_r0 == 0) {
        ((s32 (*)(s32, void *, s32, s32))play_sound_effect)(0x4003A017, ((u8 *)this) + 0x38, 0, 0);
        spawn_particle_effect(((u8 *)this) + 0x2FC, 0xE2);
        ((TObjEneSlimeWaterBomb *)((u8 *)this))->create(((u8 *)this));
    }
    temp_r0_2 = *(s32 *)((s8 *)((u8 *)this) + 0x390) - 1;
    *(s32 *)((s8 *)((u8 *)this) + 0x390) = temp_r0_2;
    if (temp_r0_2 <= 0) {
        if (this->is_timer_active() != 0) {
            this->set_state(7);
            return;
        }
        this->set_state(5);
    }
}
void TObjEneSlimeOne::start_tail_attack() {
    Self_800E984C *self = (Self_800E984C *)this;
    f32 r;
    s32 ang;
    s32 n;
    f32 len;
    Tgt_800E984C *t;
    t = ((Tgt_800E984C * (*)(s32))get_player_by_client_id)(self->target);
    if (t == NULL || (t->flags & 0x02000800)) {
        ((TObjEneSlimeOne *)self)->set_state(5);
        return;
    }
    VecCopy((Vec *)&self->dest, (const Vec *)&t->pos);
    r = 5.0f * random_ratio__9TObjCharaFv(self) + 2.5f;
    ang = 65536.0f * random_ratio__9TObjCharaFv(self);
    self->dest.x = r * sin_table_lookup(ang) + self->dest.x;
    self->dest.z = r * cos_table_lookup(ang) + self->dest.z;
    Vec_800E984C dir = self->dest;
    subtract_vector(&dir, &self->pos);
    len = vector_length(&dir);
    if (0.0f == len) {
        ((TObjEneSlimeOne *)self)->set_state(5);
        return;
    }
    n = len / 10.0f;
    if (vector_length(&dir) <= 0.01f) {
        dir.x = 1.0f;
        dir.z = dir.y = 0.0f;
    } else {
        normalize_vector(&dir);
    }
    dir.x *= 10.0f;
    dir.y *= 10.0f;
    dir.z *= 10.0f;
    Vec_800E984C pos = self->pos;
    pos.y += 5.0f;
    while (n > 0) {
        Vec_800E984C tmp = pos;
        if (project_actor_to_ground(self, &tmp, 0) == 0 || csnLookAt(&self->pos, &pos) != 0) {
            ((TObjEneSlimeOne *)self)->set_state(9);
            return;
        }
        n--;
        ((void (*)(void *, void *))vec3_add_to)(&pos, &dir);
    }
    self->state_timer = 0x5A;
    ((TObjEneSlimeOne *)((void *)self->f388))->set_motion_state((s32)((void*)((void *)0)));
    play_sound_effect(0x4003A318, &self->dest, 0, 0);
    ((void (*)(void *, void *, s32, void *))create__22TObjEneSlimeTailAttackFiiii)(self, &self->dest, self->rotation_y, self);
    ((int (*)(void*, void*))set_display_mode__15TObjEneSlimeOneFPvi)(self, (void*)((void *)2));
}

void TObjEneSlimeOne::tick_timer() {
    s32 temp_r0;

    temp_r0 = this->state_timer - 1;
    this->state_timer = temp_r0;
    if (temp_r0 <= 0) {
        this->set_state(5);
    }
}

void TObjEneSlimeOne::reset_display_state() { *(float*)((char*)this + 0x3b0) = 1.0f; this->draw_scale.y = 1.0f; this->draw_scale.x = 1.0f; *(int*)((char*)this + 0x394) = 0; ((TObjEneSlimeOne *)(*(int*)((char*)this + 0x388)))->set_motion_state((s32)((void*)4)); ((int (*)(void*, void*))set_display_mode__15TObjEneSlimeOneFPvi)(this, (void*)2); }

void TObjEneSlimeOne::update_tick() {
    s32 temp_r3;

    temp_r3 = *(s32 *)((s8 *)this + 0x394) + 1;
    *(s32 *)((s8 *)this + 0x394) = temp_r3;
    if (!(temp_r3 & 3)) {
        spawn_particle_effect(((u8 *)this + 0x2FC), 0xE0);
    }
    if (this->motion_flags & 0x10) {
        if (this->is_timer_active() != 0) {
            this->set_state(7);
            return;
        }
        this->set_state(6);
    }
}

void TObjEneSlimeOne::init_split_effect() {
    *(f32 *)((s8 *)((u8 *)this) + 0x3B0) = 1.0f;
    this->draw_scale.y = 1.0f;
    this->draw_scale.x = 1.0f;
    spawn_particle_effect((((u8 *)this) + 0x2FC), 0xCE);
    play_sound_effect(0x4003A61A, ((u8 *)this) + 0x38, 0, 0);
    ((TObjEneSlimeOne *)(*(s32 *)((s8 *)((u8 *)this) + 0x388)))->set_motion_state(5);
    ((s32 (*)(void *, int))set_display_mode__15TObjEneSlimeOneFPvi)(((u8 *)this), 0);
}

void TObjEneSlimeOne::sub_800E969C() {
    if (this->motion_flags & 0x10) {
        this->set_state(5);
    }
}

void TObjEneSlimeOne::sub_800E95F4() {
    u8 *object;
    object = (u8 *)(*(u8 **)((s8 *)((u8 *)this) + 0x3F0));
    if ((object != NULL) && (((TObject *)object)->all_parents_unqueued_for_destruction() != 0)) {
        fn_800EB778(*(Obj_800EB778 **)((s8 *)((u8 *)this) + 0x3F0), (s32) *(u16 *)((s8 *)((u8 *)this) + 0x1C));
    }
    *(f32 *)((s8 *)((u8 *)this) + 0x3B0) = 1.0f;
    this->draw_scale.y = 1.0f;
    this->draw_scale.x = 1.0f;
    *(s32 *)((s8 *)((u8 *)this) + 0x390) = 5;
    ((TObjPlayer *)((u8 *)this))->refresh_lobby_state();
    ((s32 (*)(s32, u32, s16, s32))play_sound_effect)(0x4003A81B, (u32)(((u8 *)this) + 0x38), 0, 0);
    spawn_particle_effect((((u8 *)this) + 0x2FC), 0xFE);
    ((TObjEneSlimeOne *)(*(u8 **)((s8 *)((u8 *)this) + 0x388)))->set_motion_state(5);
    set_display_mode__15TObjEneSlimeOneFPvi(((u8 *)this), 0);
}

void TObjEneSlimeOne::update_effect_fade_lifetime() {
    if ((*(f32 *)((s8 *)((u8 *)this) + 0x3A0) += -0.2f) < 0.0f) {
        *(f32 *)((s8 *)((u8 *)this) + 0x3A0) = 0.0f;
    }
    if (--*(s32 *)((s8 *)((u8 *)this) + 0x390) <= 0) {
        queue_destruction__7TObjectFv(((u8 *)this));
    }
}
extern "C" {


void TObjEneSlimeOne::sub_800E9538() {
    *(s32 *)((s8 *)((u8 *)this) + 0x3E8) = (s32)create_particle_emitter((((u8 *)this) + 0x38), 0xE1);
    this->draw_offset_y = -2.5f;
    this->draw_scale.z = 0.0f;
    this->draw_scale.y = 0.0f;
    this->draw_scale.x = 0.0f;
    this->alpha = 0.0f;
    ((TObjEneSlimeOne *)(this->m_388))->set_motion_state(7);
    set_display_mode__15TObjEneSlimeOneFPvi(((u8 *)this), 0);
}
void TObjEneSlimeOne::sub_800E92D8() {
    s32 landed = 0;
    s32 tries = 4;
    s32 angle;
    f32 s;
    f32 c;

    this->launch_velocity.y += -0.075f;
    do {
        Vec next;
        Vec probe;
        VecCopy(&next, &this->position);
        vec3_add_to(&next, &this->launch_velocity);
        VecCopy(&probe, &next);
        probe.y += 5.0f + fabs_float(this->launch_velocity.y);
        if (project_actor_to_ground(this, &probe, 0) != 0) {
            VecCopy(&this->position, &next);
            if (!(this->position.y > probe.y)) {
                this->position.y = probe.y;
                landed = 1;
            }
            break;
        }
        s = sin_table_lookup(0x4000);
        c = cos_table_lookup(0x4000);
        this->launch_velocity.x = c * this->launch_velocity.x + s * this->launch_velocity.z;
        this->launch_velocity.z = -s * this->launch_velocity.x + c * this->launch_velocity.z;
    } while (--tries > 0);
    if (tries == 0) {
        Vec probe;
        this->launch_velocity.x = this->launch_velocity.z = 0.0f;
        VecCopy(&probe, &this->position);
        probe.y += 5.0f + fabs_float(this->launch_velocity.y);
        if (project_actor_to_ground(this, &probe, 0) != 0) {
            if (!(this->position.y > probe.y)) {
                this->position.y = probe.y;
                landed = 1;
            }
        } else {
            landed = 1;
        }
    }
    if (this->particle != NULL) {
        ((TParticleCtrl *)this->particle)->set_position(&this->position);
    }
    if (landed != 0) {
        if (this->particle != NULL) {
            TParticleCtrl::release(this->particle);
            this->particle = NULL;
        }
        for (angle = 0; angle < 0xFFFF; angle += 0x1000) {
            Vec p = *&this->position;
            p.x = 12.5f * sin_table_lookup(angle) + p.x;
            p.y += -2.5f;
            p.z = 12.5f * cos_table_lookup(angle) + p.z;
            spawn_particle_effect(&p, 0xE2);
        }
        TObjEneSlimeOne__sub_800EAD84((Obj_800EAD84 *)this);
        this->set_state(1);
    }
}

void TObjEneSlimeOne::copy_position() {
    s32 arg0 = (s32)this;
    VecCopy((Vec *)(arg0 + 0x374), (const Vec *)(arg0 + 0x38));
}

void fn_800E9238(s32 arg0) {
    typedef char sp8_offset[(offsetof(Stack_800E9238, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_800E9238, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_800E9238, sp10) == 0x8) ? 1 : -1];
    Stack_800E9238 stack;
    VecCopy((Vec *)(&stack.sp8), (const Vec *)(arg0 + 0x38));
    ((f32 (*)(void *, void *))subtract_vector)((void *)&stack.sp8, (void *)(arg0 + 0x374));
    stack.sp8 *= 0.025f;
    stack.spC *= 0.025f;
    stack.sp10 *= 0.025f;
    ((f32 (*)(void *, void *))vec3_add_to)((void *)(arg0 + 0x374), (void *)&stack.sp8);
}

void TObjEneSlimeOne::sub_800E9090() {
    Bomb_800E9090 *self = (Bomb_800E9090 *)this;
    Vec_800E9090 c;
    Vec_800E9090 b;
    f32 s;
    s32 ang;
    s32 t;
    s32 w1;
    s32 w0;
    s = 0.5f * self->f3A0;
    Vec_800E9090 a = self->pos;
    subtract_vector(&a, &self->vel);
    a.x *= 0.5f;
    a.y *= 0.5f;
    a.z *= 0.5f;
    VecCopy((Vec *)&c, (const Vec *)&self->vel);
    vec3_add_to(&c, &a);
    c.y += -1.125f;
    ang = 10430.38043493439 * ((f32 (*)(f32, f32))atan2_float)(a.x, a.z);
    b.x = 1.25f;
    b.y = 0.21428572f;
    b.z = 1.25f * vector_length(&a) / 11.0f;
    if (b.x > b.z) {
        b.x = b.z;
    }
    if (s < 0.05f || b.x < 0.05f) {
        return;
    }
    TObjPlayer::push_material_color_override(s, -1.0f, 0.0f, 1.0f);
    ((void (*)(void))push_matrix)();
    ((void (*)(void *))post_translate_matrix)(&c);
    rotate_matrix_y(0, ang);
    scale_matrix_vec3((u8 *)(0), (u8 *)&b);
    t = slime_tail_attack_id_pair[self->f3F4];
    TObjFish::set_global_param(TObjFish__sub_8001EDB0(self->f380, t));
    draw_chunk_object((void *)(get_bml_model(self->f380, t)));
    ((int (*)(void))pop_matrix)();
    TObjPlayer::init_render_globals();
}
#pragma push
#pragma opt_common_subs off
void *TObjEneSlimeWaterBomb__ct(TObjEneSlimeWaterBomb *ene_slime_water_bomb, void *arg1, void *arg2) {
    f32 s;
    f32 c;
    ((s32 (*)(void *, void *))__ct__9TObjEnemyFP7TObject)(ene_slime_water_bomb, arg1);
    *(s32 **)((s8 *)ene_slime_water_bomb + 0x18) = __vt__21TObjEneSlimeWaterBomb;
    *(s32 *)((s8 *)ene_slime_water_bomb + 0) = (s32) lbl_805D2AE0;
    *(void **)((s8 *)ene_slime_water_bomb + 0x38C) = arg2;
    ene_slime_water_bomb->rotation_y = *(s32 *)((s8 *)(*(u8 * *)&ene_slime_water_bomb->m_up) + 0x60);
    VecCopy((Vec *)((u8 *) ene_slime_water_bomb + 0x38), (const Vec *)(*(u8 * *)&ene_slime_water_bomb->m_up + 0x38));
    s = sin_table_lookup(ene_slime_water_bomb->rotation_y);
    c = cos_table_lookup(ene_slime_water_bomb->rotation_y);
    *(f32 *)((s8 *)ene_slime_water_bomb + 0x38) += 15.0f * s;
    *(f32 *)((s8 *)ene_slime_water_bomb + 0x3C) += 20.0f;
    *(f32 *)((s8 *)ene_slime_water_bomb + 0x40) += 15.0f * c;
    *(f32 *)((s8 *)ene_slime_water_bomb + 0x374) = 0.6f * s;
    *(f32 *)((s8 *)ene_slime_water_bomb + 0x378) = 0.0f;
    ene_slime_water_bomb->m_37c = 0.6f * c;
    *(f32 *)((s8 *)ene_slime_water_bomb + 0x384) = 0.0f;
    *(s32 *)&ene_slime_water_bomb->m_388 = (s32)create_particle_emitter((u8 *) ene_slime_water_bomb + 0x38, 0xCF);
    *(f32 *)((s8 *)ene_slime_water_bomb + 0x390) = *dispatch_shared_handler_a__6TLobbyFl(TObjEneSlime__attack_target_param_table[((TObjEneSlimeOne *)(*(s32 *)&ene_slime_water_bomb->m_38c))->get_attack_target()]);
    if (*(f32 *)((s8 *)ene_slime_water_bomb + 0x390) < 0.0f) {
        *(f32 *)((s8 *)ene_slime_water_bomb + 0x390) = 0.0f;
    }
    *(s32 *)&ene_slime_water_bomb->m_394 = 0;
    return ene_slime_water_bomb;
}
#pragma pop

TObjEneSlimeWaterBomb::~TObjEneSlimeWaterBomb() {
    if (this->m_388 != 0) {
        TParticleCtrl::release((void *)this->m_388);
        this->m_388 = 0;
    }
}

void *TObjEneSlimeWaterBomb::create(void *arg1) {
    void *o;
    o = ((void * (*)(int))__nw__7TObjectFUl)(0x398);
    if (o != NULL) {
        o = TObjEneSlimeWaterBomb__ct((TObjEneSlimeWaterBomb *)o, (void *)this, (void *)arg1);
    }
    return o;
}

void run_task__21TObjEneSlimeWaterBombFv(Bomb_800E8D4C *arg0) {
    s32 die = 0;
    arg0->vel.y += -0.05f;
    vec3_add_to(&arg0->pos, &arg0->vel);
    if (++arg0->timer > 0x14F) {
        die = 1;
    }
    {
        Vec_800E8D4C p = arg0->pos;
        p.y += 5.0f;
        if (((s32 (*)(void *, void *, void *))project_actor_to_ground)(arg0, &p, arg0->hit) != 0) {
            arg0->ground = p.y;
            if (arg0->pos.y <= arg0->ground) {
                arg0->pos.y = arg0->ground;
                arg0->vel.y *= -0.975f;
                spawn_particle_effect(&arg0->pos, 0xE2);
            }
        } else {
            die = 1;
        }
    }
    if (arg0->link != NULL) {
        ((TParticleCtrl *)arg0->link)->set_position(&arg0->pos);
    }
    if (((TObjEneSlimeOne *)(arg0->owner))->is_in_water_bomb_states() != 0 || ((s32 (*)(void *))water_bomb_hit_nearby)(arg0) != 0) {
        die = 1;
    }
    {
        if ((arg0->life += 0.6f) >= 200.0f || die != 0) {
            spawn_particle_effect(&arg0->pos, 0xE2);
            ((s32 (*)(void *))queue_destruction__7TObjectFv)(arg0);
        }
    }
}
void TObjEneSlimeWaterBomb::render() {
    u8 *arg0 = (u8 *)this;
    Vec_800E8C6C v;
    s32 spC;
    s32 sp8;
    f32 d;
    f32 k;
    ((int (*)(void*))push_matrix)(arg0);
    translate_matrix(0, *(f32 *)((s8 *)arg0 + 0x38), 0.1f + this->m_380, *(f32 *)((s8 *)arg0 + 0x40));
    direction_to_rotation_xz((u8 *)&this->ground_normal, &spC, &sp8);
    rotate_matrix_z(0, sp8);
    rotate_matrix_x(0, spC + 0x4000);
    d = *(f32 *)((s8 *)arg0 + 0x3C) - this->m_380;
    if (d > 40.0f) {
        d = 40.0f;
    } else if (d < 0.0f) {
        d = 0.0f;
    }
    k = 0.65f * (1.0f - d / 40.0f) + 0.1f;
    v.x = v.y = k;
    v.z = 1.0f;
    scale_current_matrix(&v);
    draw_blob_shadow(0);
    ((int (*)(void))pop_matrix)();
}
s32 water_bomb_hit_nearby(u8 *target) {
    s32 hit;
    Ent_800E8AD0 *e;
    Ent_800E8AD0 *e2;
    Hit_800E8AD0 h = {0, 0.0f};
    u16 id;
    s32 id2;
    hit = 0;
    h.dmg = *(f32 *)((s8 *)target + 0x390);
    VecCopy((Vec *)(target + 0x2FC), (const Vec *)(target + 0x38));
    id = ((u16 (*)(void *, s32, f32))find_nearest_visible_player)(target, 0, 25.0f);
    if (id != 0xFFFF) {
        e = ((Ent_800E8AD0 *(*)(s32))get_player_by_client_id)(id);
        if (e != NULL && !(horizontal_distance_squared((const Vec *)(target + 0x2FC), (const Vec *)((u8 *)e + 0x2FC)) > 25.0f)) {
            if (0.0f != e->m21(((TObjEneSlimeWaterBomb *)target)->m_38c, h, 0, -1, -1)) {
                e->m23(target);
            }
            hit = 1;
        }
    }
    id2 = ((TObjEneSlimeWaterBomb *)target)->find_nearest_enemy_masked(25.0f);
    if (id2 != 0xFFFF) {
        e2 = (Ent_800E8AD0 *)get_enemy_entity(id2);
        if (e2 != NULL && !(horizontal_distance_squared((const Vec *)(target + 0x2FC), (const Vec *)((u8 *)e2 + 0x2FC)) > 25.0f)) {
            if (0.0f != e2->m21(((TObjEneSlimeWaterBomb *)target)->m_38c, h, 0, -1, -1)) {
                e2->m23(target);
            }
            hit = 1;
        }
    }
    return hit;
}
extern "C" const char lbl_8043D268[] = "TObjEneSlimeTailAttack";
void *TObjEneSlimeTailAttack__ct(TObjEneSlimeTailAttack *ene_slime_tail_attack, void *arg1, s32 arg2, s32 arg3, s32 arg4) {
  unsigned int id;
  u8 *inst;
  ((s32 (*)(void *, void *)) __ct__9TObjEnemyFP7TObject)(ene_slime_tail_attack, arg1);
  *((u8 **) (((s8 *) ene_slime_tail_attack) + 0x18)) = (u8 *) __vt__22TObjEneSlimeTailAttack;
  *((s32 *) (((s8 *) ene_slime_tail_attack) + 0)) = (s32) TObjEneSlimeTailAttack__name;
  *((s32 *) (((s8 *) ene_slime_tail_attack) - -0x374)) = arg4;
  inst = get_instance__15TObjEneSlimeOneFv();
  id = ((s32 *) lbl_804966F4)[((TObjEneSlimeOne *)(*((s32 *) (((s8 *) ene_slime_tail_attack) + (0x374 & 0xFFFF)))))->get_attack_target()];
  ene_slime_tail_attack->texlist = TObjFish__sub_8001EDB0((s32) inst, id);
  *((s32 *) (((s8 *) ene_slime_tail_attack) + 0x34)) = get_bml_model((s32) inst, id);
  ene_slime_tail_attack->action_table = (TObjMotionAction *)lbl_8049639C;
  ((TObjMotion *)ene_slime_tail_attack)->set_field_d8((s32) ((u8 *) lbl_8049639C));
  *((s32 *) (((s8 *) ene_slime_tail_attack) + 0xDC)) = *((s32 *) (((s8 *) inst) + 0x430));
  ((TObjMotion *)ene_slime_tail_attack)->set_field_dc(*((s32 *) (((s8 *) inst) + 0x430)));
  ene_slime_tail_attack->requested_action = 6;
  ((TObjMotion *)ene_slime_tail_attack)->set_animation(ene_slime_tail_attack->requested_action);
  ((TObjMotion *)ene_slime_tail_attack)->set_field_b8(ene_slime_tail_attack->requested_action);
  ene_slime_tail_attack->rotation_y = arg3;
  VecCopy((Vec *)(((u8 *) ene_slime_tail_attack) + 0x38), (const Vec *)arg2);
  *((s32 *) (((s8 *) ene_slime_tail_attack) + 0x378)) = 1;
  *((s32 *) (((s8 *) ene_slime_tail_attack) + 0x37C)) = 0xFFFF;
  *((f32 *) (((s8 *) ene_slime_tail_attack) + 0x388)) = 1.0f;
  *((f32 *) (((s8 *) ene_slime_tail_attack) + 0x384)) = 1.0f;
  *((f32 *) (((s8 *) ene_slime_tail_attack) + 0x380)) = 1.0f;
  *((f32 *) (((s8 *) ene_slime_tail_attack) + 0x38C)) = 1.0f;
  return ene_slime_tail_attack;
}

void *dt__22TObjEneSlimeTailAttackFPvs(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__22TObjEneSlimeTailAttack;
        __dt__9TObjEnemyFv((TObjEnemy *)arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

void *create__22TObjEneSlimeTailAttackFiiii(s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    void *obj;
    void *ctrl;

    obj = __nw__7TObjectFUl(0x3CC);
    if (obj != 0) {
        ctrl = __nw__7TObjectFUl(0x20);
        if (ctrl != 0) {
            ctrl = __ct__11TObjControlFP7TObject(ctrl, tl_04);
        }
        obj = TObjEneSlimeTailAttack__ct((TObjEneSlimeTailAttack *)obj, (void *)ctrl, (s32)arg2, (s32)arg3, (s32)arg4);
    }
    return obj;
}
void TObjEneSlimeTailAttack::run_task() {
    if ((s32) *(s32 *)((s8 *)((u8 *)this) + 0x378) != 0) {
        TObjPlayer__sub_800E85BC(this);
        advance_animation();
        if (this->motion_flags & 0x10) {
            queue_destruction__7TObjectFv(this);
            return;
        }
        if (((TObjEneSlimeOne *)(*(s32 *)((s8 *)((u8 *)this) + 0x374)))->is_in_water_bomb_states() != 0) {
            *(s32 *)((s8 *)((u8 *)this) + 0x378) = 0;
        }
    } else {
        this->frame += 0.1f * (7.0f - this->frame);
        *(f32 *)((s8 *)((u8 *)this) + 0x38C) += -0.033333335f;
        *(f32 *)((s8 *)((u8 *)this) + 0x3C) += -0.016666668f;
        *(f32 *)((s8 *)((u8 *)this) + 0x380) += 0.06666667f;
        *(f32 *)((s8 *)((u8 *)this) + 0x384) += -0.031666666f;
        *(f32 *)((s8 *)((u8 *)this) + 0x388) += 0.06666667f;
        if (*(f32 *)((s8 *)((u8 *)this) + 0x384) <= 0.05f) {
            queue_destruction__7TObjectFv(this);
        }
    }
}

s32 TObjPlayer__sub_800E85BC(TObjEneSlimeTailAttack *self) {
    Hit_800E8AD0 hit;
    s32 result;
    Ent_800E8AD0 *e;
    Ent_800E8AD0 *e2;
    u16 id;
    s32 id2;
    f32 t = self->frame;
    if (t < 17.0f || t > 30.0f) {
        return 0;
    }
    hit.kind = 0;
    result = 0;
    hit.dmg = *(s16 *)TLobby::register_boss((s32)lbl_804966FC[((TObjEneSlimeOne *)(*(s32 *)((u8 *)self + 0x374)))->get_attack_target()]);
    id = find_nearest_visible_player(self, 0, 25.0f);
    if (id != 0xFFFF && id != *(s32 *)((u8 *)self + 0x37C)) {
        e = ((Ent_800E8AD0 *(*)(s32))get_player_by_client_id)(id);
        if (e != NULL) {
            TObjPlayer *pl = (TObjPlayer *)e;
            f32 lo = pl->position.y - 5.0f;
            f32 hi = 5.0f + (pl->position.y + pl->m_d48);
            if (!(self->m_300 < lo) && !(self->m_300 > hi) &&
                !(horizontal_distance_squared((const Vec *)&self->m_2fc, (const Vec *)&pl->position) > 56.25f)) {
                if (e->m21(*(s32 *)((u8 *)self + 0x374), hit, 0, -1, -1) != 0.0f) {
                    e->m23(self);
                }
                *(s32 *)((u8 *)self + 0x37C) = id;
                result = 1;
            }
        }
    }
    id2 = self->find_nearest_enemy_with_flag(25.0f);
    if (id2 != 0xFFFF) {
        void *owner = *(void **)((u8 *)self + 0x374);
        if (owner == NULL || id2 != (u16)get_entity_id(owner)) {
            e2 = (Ent_800E8AD0 *)get_enemy_entity(id2);
            if (e2 != NULL && !(horizontal_distance_squared((const Vec *)&self->m_2fc, (const Vec *)((u8 *)e2 + 0x2FC)) > 56.25f)) {
                if (e2->m21(*(s32 *)((u8 *)self + 0x374), hit, 0, -1, -1) != 0.0f) {
                    e2->m23(self);
                }
                result = 1;
            }
        }
    }
    return result;
}
void TObjEneSlimeTailAttack::render() {
  f32 temp_f1;
  f32 temp_f3;
  sub_800E841C();
  if (((s32) (*((s32 *) (((s8 *) ((u8 *)this)) + 0x378)))) != 0)
  {
    temp_f3 = this->frame;
    temp_f1 = 7.0f;
    if (temp_f3 < temp_f1)
    {
      draw_stretched_segment((Vec_800E82B8 *)((void *) ((*((s32 *) (((s8 *) ((u8 *)this)) + 0x374))) + 0x38)), (Vec_800E82B8 *)(((u8 *)this) + 0x38), (f32) (temp_f3 / temp_f1));
    }
    else
      if ((temp_f3 >= 41.0f) && (temp_f3 < 48.0f))
    {
      draw_stretched_segment((Vec_800E82B8 *)(((u8 *)this) + 0x38), (Vec_800E82B8 *)((void *) ((*((s32 *) (((s8 *) ((u8 *)this)) + 0x374))) + 0x38)), (f32) ((temp_f3 - 41.0f) / temp_f1));
    }
  }
  temp_f1 = this->frame;
  if ((temp_f1 >= 12.0f) && (temp_f1 < 35.0f))
  {
    ((TObjPlayer *)((u8 *)this))->draw_blob_shadows();
  }
}
void TObjEneSlimeTailAttack::sub_800E841C() {
    u8 *arg0 = (u8 *)this;
    push_matrix();
    post_translate_matrix((u8 *)&this->position);
    rotate_matrix_y(0, (int) (((TObjEneSlimeTailAttack *)arg0)->rotation_y));
    TObjFish::set_global_param((int) (((TObjEneSlimeTailAttack *)arg0)->texlist));
    if ((s32) *(s32 *)((s8 *)arg0 + 0x378) != 0) {
        TObjPlayer__sub_800E81A8();
        set_chunk_model_node_callback((s32)TObjPlayer__sub_800E8128);
        ((TObjMotion *)arg0)->draw();
        set_chunk_model_node_callback(NULL);
        TObjPlayer__sub_800E80C0(arg0 + 0x390);
        VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)(arg0 + 0x390));
    } else {
        TObjPlayer__sub_800EBE48((f32) (*(f32 *)((s8 *)arg0 + 0x38C)));
        scale_matrix_vec3(0, (arg0 + 0x380));
        TObjPlayer__sub_800E81A8();
        set_chunk_model_node_callback((s32)TObjPlayer__sub_800E8128);
        ((TObjMotion *)arg0)->draw();
        set_chunk_model_node_callback(NULL);
        TObjPlayer__sub_800E80C0(arg0 + 0x390);
        VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)(arg0 + 0x390));
        TObjPlayer::init_render_globals();
    }
    pop_matrix();
}
void TObjEneSlimeTailAttack::draw_stretched_segment(void *arg1, void *arg2, f32 t) {
    f32 len;
    f32 k;
    f32 saved;
    Vec_800E82B8 d;
    VecCopy((Vec *)&d, (const Vec *)((Vec_800E82B8 *)arg2));
    ((s32 (*)(void *, void *))subtract_vector)(&d, ((Vec_800E82B8 *)arg1));
    len = vector_length(&d);
    push_matrix();
    k = 0.5f * (1.0f + t);
    {
        Vec_800E82B8 p = *((Vec_800E82B8 *)arg1);
        p.x += k * d.x;
        p.y += k * d.y + -0.5f;
        p.z += k * d.z;
        post_translate_matrix(&p);
    }
    rotate_matrix_y(0, (s32)(10430.38043493439 * atan2_float(d.x, d.z)));
    {
        f32 r = 1.0f - t;
        scale_matrix(0, 1.0f, 0.5f, r * len / 10.0f);
    }
    TObjFish::set_global_param(this->texlist);
    TObjPlayer__sub_800EBE48(0.10000001f * t + 0.05f);
    saved = this->frame;
    this->frame = 7.0f;
    this->draw();
    this->frame = saved;
    TObjPlayer::init_render_globals();
    pop_matrix();
}
void TObjPlayer::draw_blob_shadows() {
    s32 i;
    f32 k;
    s32 spC;
    s32 sp8;
    k = 10.0f;
    for (i = 0; i < 4; i++) {
        Vec_800E81B4 v = ((Obj_800E81B4 *)this)->pts[i];
        Rot_800E81B4 rot;
        v.y += k;
        if (((s32 (*)(void *, Vec_800E81B4 *, Rot_800E81B4 *))project_actor_to_ground)(this, &v, &rot) != 0) {
            push_matrix();
            translate_matrix(0, v.x, 0.1f + v.y, v.z);
            direction_to_rotation_xz((u8 *)&rot, &spC, &sp8);
            rotate_matrix_z(0, sp8);
            rotate_matrix_x(0, spC + 0x4000);
            scale_matrix(0, 0.75f, 0.75f, 0.75f);
            draw_blob_shadow(0);
            pop_matrix();
        }
    }
}
void TObjPlayer__sub_800E81A8(void) { lbl_805D52B4 = 0; }
void TObjPlayer__sub_800E8128(void) {
    if ((s32) (*(s32 *)&lbl_805D52B4) == 7) {
        transform_to_view__11TCameraCtrlFii((s32) &slime_tail_attack_zero_vec.value, (s32) &lbl_80501010.value);
    }
    if (((s32) (*(s32 *)&lbl_805D52B4) >= 4) && ((s32) (*(s32 *)&lbl_805D52B4) < 8)) {
        transform_to_view__11TCameraCtrlFii((s32) &slime_tail_attack_transform.value, (s32) ((u8 *)&lbl_80501010.value + (((*(s32 *)&lbl_805D52B4) - 4) * 0xC) + 0xC));
    }
    (*(s32 *)&lbl_805D52B4) += 1;
}
S_800E80E8 *TObjPlayer__sub_800E80E8(S_800E80E8 *dst, S_800E80E8 *src) {
    dst->a = src->a;
    dst->d = src->d;
    return dst;
}

void TObjPlayer__sub_800E80C0(u8 *dst) {
    TObjPlayer__sub_800E80E8((S_800E80E8 *)(dst), (S_800E80E8 *)(&(*(RecoveredGlobal_800E80C0_lbl_80501010 *)&lbl_80501010).value));
}
}

#undef lbl_80496574
#undef slime_tail_attack_id_pair
#undef TObjEneSlime__attack_target_param_table
#undef slime_tail_attack_zero_vec
#undef slime_tail_attack_transform
#undef __vt__22TObjEneSlimeTailAttack
