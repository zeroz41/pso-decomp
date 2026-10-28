#include "types.h"
#include "pso/player/TUnk_804806E8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/TObject.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TLobby.h"
#include "pso/enemy/TObjEneSlimeOne.h"
#include "pso/enemy/TObjEneSlimeTailAttack.h"
#include "pso/enemy/TObjEneSlimeWaterBomb.h"
extern "C" void has_flag_0x800__13TUnk_804806E8Fv();
extern "C" void test_flag30_512__13TUnk_804806E8Fv();
extern "C" void test_flag_1000__13TUnk_804806E8Fv();
extern "C" void test_flag_256__13TUnk_804806E8Fv();
#include "pso/system/vector.h"

#include <stddef.h>
#include "pso/TParticleCtrl.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/enemy/TObjEneLappy.h"
#include "pso/enemy/TObjEnePanarms.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/misc/TNowLoading.h"
#include "pso/object/TObjFish.h"

struct Obj_800E9BCC {
    u8 pad0[0x38];
    f32 pos[3];
    f32 prev[3];
    u8 pad50[0x60 - 0x50];
    s32 f60;
    u8 pad64[0x390 - 0x64];
    s32 f390;
    u8 pad394[0x3CC - 0x394];
    s32 f3CC;
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
s32 angle_difference_abs(s32, s32);
s32 approach_angle_limited(s32, s32, s32);
s32 project_actor_to_ground(void *, void *, int);
s32 vec3_add_to(void *, void *);
f32 vector_length(void *);
void normalize_vector(void *);
extern const f64 lbl_8043D280[];
extern const f32 lbl_805DA718;
extern const f32 lbl_805DA71C;
extern const f32 lbl_805DA720;
extern const f32 lbl_805DA724;
void TObjPlayer__sub_800E9BCC(Obj_800E9BCC *o);
f32 calc_boss4_scale__10TObjPlayerFi(void *);
s32 spawn_slime_in_slot(void *, s32, Vec_800EB654 *, Vec_800EB654 *);
s32 play_sound_effect(int, void *, int, int);
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
extern const f32 lbl_805DA66C;
extern const f32 lbl_805DA6B4;
extern const f32 lbl_805DA758;
extern const f32 lbl_805DA6AC;
s32 TObjEneSlimeOne__sub_800EAD84(Obj_800EAD84 *arg0);
void TObjPlayer__sub_800EBE48(f32 farg0);
s32 defer_render__7TObjectFv(void *);
void scale_matrix_vec3(u8 *arg0, u8 *arg1);
s32 rotate_matrix_y(int, int);
s32 push_matrix();
s32 pop_matrix();
s32 post_translate_matrix(void *);
extern const f32 lbl_805DA67C;
extern const f32 lbl_805DA6E4;
extern const f32 lbl_805DA728;
void render__15TObjEneSlimeOneFv(TObjEneSlimeOne *arg0);
s32 TObjFish__sub_8001EDB0(s32, s32);
s32 get_bml_model(s32, s32);
u8 *get_instance__15TObjEneSlimeOneFv();
s32 fn_800ECA28(void *, void *);
s32 init_collision_body_parts(void *, void *, int);
extern const f32 lbl_805DA754;
extern void *lbl_80496574[90];
extern void *lbl_80496368[2];
extern void *lbl_8049639C[118];
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
    s32 f60;
    u8 pad64[0x388 - 0x64];
    s32 f388;
    u8 pad38C[0x390 - 0x38C];
    s32 f390;
    u8 pad394[0x3CC - 0x394];
    s32 target;
    Vec_800E984C dest;
} Self_800E984C;

struct Obj_800E9DC8 { u8 pad0[0x60]; s32 f60; u8 pad1[0x390 - 0x64]; s32 f390; u8 pad2[0x3C4 - 0x394]; s32 f3C4; };

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

struct TSlime_800EAE78;

typedef void (TSlime_800EAE78::*Action_800EAE78)();

struct Ent_800EAE78 { Action_800EAE78 fn; Action_800EAE78 update; };

struct TSlime_800EAE78 {
    u8 pad[0x384];
    s32 state;
    void run(s32 s);
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
void *spawn_particle_effect(void *pos, s32 id);
void *create_particle_emitter(void *pos, s32 id);
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
void * __dt__21TObjEneSlimeWaterBombFv(void *arg0, s16 arg1);
void *TObjEneSlimeWaterBomb__ct(TObjEneSlimeWaterBomb *arg0, void *arg1, void *arg2);
void fn_800E9238(s32 arg0);
void fn_800E9538(u8 *arg0);
void fn_800E95F4(u8 *arg0);
void TObjEneSlimeOne__sub_800E969C(TObjEneSlimeOne *arg0);
void init_split_effect__15TObjEneSlimeOneFPv(u8 *arg0);
void update_tick__15TObjEneSlimeOneFPv(TObjEneSlimeOne *arg0);
void reset_display_state__15TObjEneSlimeOneFPv(void* a0);
void tick_timer__15TObjEneSlimeOneFPv(TObjEneSlimeOne *arg0);
void start_tail_attack__15TObjEneSlimeOneFPv(Self_800E984C *self);
void update_water_bomb_timer__15TObjEneSlimeOneFPv(u8 *arg0);
void begin_appear__15TObjEneSlimeOneFPv(void* p);
void TObjPlayer__sub_800E9D7C(void* p);
void TObjPlayer__sub_800E9DC8(Obj_800E9DC8 *arg0);
void init_slime_state__10TObjPlayerFPv(void *arg0);
void TObjPlayer__sub_800EA120(u8 *arg0);
void update_dive_timer__10TObjPlayerFPv(u8 *arg0);
void enter_appear_state__10TObjPlayerFPv(u8 *arg0);
void update_slime_timer__10TObjPlayerFPv(u8 *arg0);
void enter_slime_state__10TObjPlayerFPv(u8 *arg0);
void TObjPlayer__sub_800EA364(u8 *arg0);
void TObjPlayer__sub_800EA56C(u8 *arg0);
void TObjPlayer__sub_800EA678(u8 *arg0);
void init_slime_display__10TObjPlayerFPv(void* a0);
void TObjPlayer__sub_800EA820(u8 *arg0);
void reset_display__15TObjEneSlimeOneFPv(void* a0);
void update_wait_search__15TObjEneSlimeOneFPv(TObjEneSlimeOne *arg0);
void init_state__15TObjEneSlimeOneFPv(void* a0);
void set_display_mode__15TObjEneSlimeOneFPvi(void *arg0, s32 arg1);
void set_random_timer__15TObjEneSlimeOneFPvii(void *arg0, s32 arg1, s32 arg2);
void * __dt__15TObjEneSlimeOneFv(void *arg0, s16 arg1);
u8 * TObjEneSlimeOne__ct(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
u8 * init__15TObjEneSlimeOneFPviii(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
void fn_800EB778(void *, s32);
s16 check_player_field_7cc__15TObjEneSlimeOneFv();
s32 __dt__15TObjEneSlimeOneFis(s32 arg0, s16 arg1);
void draw_blob_shadow(s32 arg0);
void * TObjControl__ct(void *, s32);
u8 *get_enemy_entity(u16 arg0);
int get_entity_id(void *);
void *__dt__9TObjEnemyFv(TObjEnemy *arg0, s16 arg1);
s32 __ct__9TObjEnemyFP7TObject(void *);
f32 horizontal_distance_squared(void *, void *);
}
s32 water_bomb_hit_nearby(u8 *arg0);
void update_effect_fade_lifetime(u8 *arg0);
void direction_to_rotation_xz(u8 *arg0, s32 *arg1, s32 *arg2);
extern "C" {
s32 advance_animation_playback(void *);
void free_collision_body_parts(void *);
s32 get_player_by_client_id(void *);
void __dl__7TObjectFPv(void *);
void * __nw__7TObjectFUl(s32);
s32 scale_matrix(int, f32, f32, f32);
s32 rotate_matrix_z(int, int);
void subtract_vector(void *, void *);
void translate_matrix(u32 arg0, f32 x, f32 y, f32 z);
s32 rotate_matrix_x(int, int);
s32 scale_current_matrix(Vec_800E8C6C *);
void draw_chunk_object(void *child);

extern s32 __vt__15TObjEneSlimeOne[];
extern s32 __vt__21TObjEneSlimeWaterBomb[];
extern const RecoveredGlobal_800EA678_lbl_8043D230 lbl_8043D230;
extern const RecoveredGlobal_800EA678_lbl_8043D23C lbl_8043D23C;
extern Hit_800E8AD0 lbl_8043D260[];
extern RecoveredGlobal_800E8128_lbl_80501010 lbl_80501010;
extern s32 TObjEneSlimeOne_class_name;
extern s32 lbl_805D2AE0;
extern int lbl_805D52B4;
extern s32 lbl_805D586C;
extern const f32 lbl_805DA670;
extern const f32 lbl_805DA674;
extern const f32 lbl_805DA678;
extern const f32 lbl_805DA680;
extern const f32 lbl_805DA684;
extern const f32 lbl_805DA688;
extern const f32 lbl_805DA68C;
extern const f32 lbl_805DA690;
extern const f32 lbl_805DA694;
extern const f32 lbl_805DA698;
extern const f32 lbl_805DA69C;
extern const f32 lbl_805DA6A0;
extern const f32 lbl_805DA6A4;
extern const f32 lbl_805DA6A8;
extern const f32 lbl_805DA6B0;
extern const f32 lbl_805DA6B8;
extern const f32 lbl_805DA6BC;
extern const f32 lbl_805DA6C0;
extern const f32 lbl_805DA6C4;
extern const f32 lbl_805DA6C8;
extern const f32 lbl_805DA6CC;
extern const f32 lbl_805DA6D0;
extern const f32 lbl_805DA6D4;
extern const f32 lbl_805DA6D8;
extern const f32 lbl_805DA6DC;
extern const f32 lbl_805DA6E0;
extern const f32 lbl_805DA6E8;
extern const f32 lbl_805DA6EC;
extern const f32 lbl_805DA6F0;
extern const f32 lbl_805DA6F4;
extern const f32 lbl_805DA6F8;
extern const f32 lbl_805DA6FC;
extern const f32 lbl_805DA708;
extern const f32 lbl_805DA70C;
extern const f32 lbl_805DA710;
extern const f32 lbl_805DA714;
extern const f32 lbl_805DA72C;
extern const f32 lbl_805DA730;
extern const f32 lbl_805DA734;
extern const f32 lbl_805DA738;
extern const f32 lbl_805DA73C;
extern const f32 lbl_805DA740;
extern const f32 lbl_805DA744;
extern const f32 lbl_805DA748;
extern const f32 lbl_805DA74C;
extern const f32 lbl_805DA750;
extern s32 tl_04;

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
extern "C" {
void TBoss8Dragon__sub_800E92D8(TObjEneSlimeOne *self);
}
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
void vfunc_28__13TUnk_804806E8Fv();
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
void vfunc_63__13TUnk_804806E8Fv();
}
extern "C" {
void vfunc_62__13TUnk_804806E8Fv();
}
extern "C" {
void vfunc_61__13TUnk_804806E8Fv();
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
void apply_hit_message_flags__9TObjEnemyFPv();
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
void apply_slow_status__13TUnk_804806E8Fv();
}
extern "C" {
void apply_switch_attack__13TUnk_804806E8Fv();
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
void clear_harmful_statuses__13TUnk_804806E8Fv();
}
extern "C" {
void clear_lobby_object_state__9TObjEnemyFv();
}
extern "C" {
void consume_timer_field__13TUnk_804806E8Fl();
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
void get_center__13TUnk_804806E8Fv();
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
extern u8 lbl_8043D008[];
}
extern "C" {
extern u8 lbl_8043D01C[];
}
extern "C" {
extern u8 lbl_8043D030[];
}
extern "C" {
extern u8 lbl_8043D044[];
}
extern "C" {
extern u8 lbl_8043D058[];
}
extern "C" {
extern u8 lbl_8043D06C[];
}
extern "C" {
extern u8 lbl_8043D080[];
}
extern "C" {
extern u8 lbl_8043D09C[];
}
extern "C" {
extern u8 lbl_8043D0B8[];
}
extern "C" {
extern u8 lbl_8043D0D4[];
}
extern "C" {
extern u8 lbl_8043D0F0[];
}
extern "C" {
extern u8 lbl_8043D108[];
}
extern "C" {
extern u8 lbl_8043D120[];
}
extern "C" {
extern u8 lbl_8043D138[];
}
extern "C" {
extern u8 lbl_8043D150[];
}
extern "C" {
extern u8 lbl_8043D16C[];
}
extern "C" {
extern u8 lbl_8043D188[];
}
extern "C" {
extern u8 lbl_8043D1A0[];
}
extern "C" {
extern u8 lbl_8043D1B8[];
}
extern "C" {
extern u8 lbl_8043D1D0[];
}
extern "C" {
extern u8 lbl_8043D1EC[];
}
extern "C" {
extern u8 lbl_8043D210[];
}
extern "C" {
extern u8 lbl_805DA668[];
}
extern "C" {
void receive_direct_attack__13TUnk_804806E8FPv19DirectAttackPayloadPvll();
s32 submit_cursor_candidate(void *, s32);
s32 minimap_render_dot(void *, s32, s32, s32);
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);
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
extern "C" {
void update_shock_clock__13TUnk_804806E8Fv();
}
extern void *slime_model_name_ptr_table[7];
extern void *bm4_ps_ma_body_motion_names[15];
extern "C" {
void TObjPlayer__sub_800E9EFC(u8 *arg0);
}
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
    (void *)&lbl_8043D210, (void *)&lbl_805DA668,
};
__declspec(section ".data") void *lbl_80496368[2] = {
    (void *)0x4, (void *)0x5,
};
void *lbl_80496370[11] = {
    (void *)0x0, (void *)0x41700000, (void *)0x0, (void *)0x40f00000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_8049639C[118] = {
    (void *)0x10000, (void *)0xa, (void *)0x3f000000, (void *)0x0,
    (void *)0x20002, (void *)0xa, (void *)0x3f000000, (void *)0x0,
    (void *)0x10000, (void *)0xd, (void *)0x3f000000, (void *)0x0,
    (void *)0x20000, (void *)0x2, (void *)0x3f4ccccd, (void *)0x0,
    (void *)0x30000, (void *)0x8, (void *)0x3f4ccccd, (void *)0x0,
    (void *)0x30000, (void *)0x3, (void *)0x3f4ccccd, (void *)0x0,
    (void *)0x30000, (void *)0x9, (void *)0x3f4ccccd, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)&init_state__15TObjEneSlimeOneFPv, (void *)0x0,
    (void *)0xffffffff, (void *)&update_wait_search__15TObjEneSlimeOneFPv, (void *)0x0, (void *)0xffffffff,
    (void *)&reset_display__15TObjEneSlimeOneFPv, (void *)0x0, (void *)0xffffffff, (void *)&TObjPlayer__sub_800EA820,
    (void *)0x0, (void *)0xffffffff, (void *)&init_slime_display__10TObjPlayerFPv, (void *)0x0,
    (void *)0xffffffff, (void *)&TObjPlayer__sub_800EA678, (void *)0x0, (void *)0xffffffff,
    (void *)&TObjPlayer__sub_800EA56C, (void *)0x0, (void *)0xffffffff, (void *)&TObjPlayer__sub_800EA364,
    (void *)0x0, (void *)0xffffffff, (void *)&enter_slime_state__10TObjPlayerFPv, (void *)0x0,
    (void *)0xffffffff, (void *)&update_slime_timer__10TObjPlayerFPv, (void *)0x0, (void *)0xffffffff,
    (void *)&enter_appear_state__10TObjPlayerFPv, (void *)0x0, (void *)0xffffffff, (void *)&update_dive_timer__10TObjPlayerFPv,
    (void *)0x0, (void *)0xffffffff, (void *)&TObjPlayer__sub_800EA120, (void *)0x0,
    (void *)0xffffffff, (void *)&TObjPlayer__sub_800E9EFC, (void *)0x0, (void *)0xffffffff,
    (void *)&init_slime_state__10TObjPlayerFPv, (void *)0x0, (void *)0xffffffff, (void *)&TObjPlayer__sub_800E9DC8,
    (void *)0x0, (void *)0xffffffff, (void *)&TObjPlayer__sub_800E9D7C, (void *)0x0,
    (void *)0xffffffff, (void *)&TObjPlayer__sub_800E9BCC, (void *)0x0, (void *)0xffffffff,
    (void *)&begin_appear__15TObjEneSlimeOneFPv, (void *)0x0, (void *)0xffffffff, (void *)&update_water_bomb_timer__15TObjEneSlimeOneFPv,
    (void *)0x0, (void *)0xffffffff, (void *)&start_tail_attack__15TObjEneSlimeOneFPv, (void *)0x0,
    (void *)0xffffffff, (void *)&tick_timer__15TObjEneSlimeOneFPv, (void *)0x0, (void *)0xffffffff,
    (void *)&reset_display_state__15TObjEneSlimeOneFPv, (void *)0x0, (void *)0xffffffff, (void *)&update_tick__15TObjEneSlimeOneFPv,
    (void *)0x0, (void *)0xffffffff, (void *)&init_split_effect__15TObjEneSlimeOneFPv, (void *)0x0,
    (void *)0xffffffff, (void *)&TObjEneSlimeOne__sub_800E969C, (void *)0x0, (void *)0xffffffff,
    (void *)&fn_800E95F4, (void *)0x0, (void *)0xffffffff, (void *)&update_effect_fade_lifetime,
    (void *)0x0, (void *)0xffffffff, (void *)&fn_800E9538, (void *)0x0,
    (void *)0xffffffff, (void *)&TBoss8Dragon__sub_800E92D8,
};
void *lbl_80496574[90] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0,
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
    (void *)&render__22TObjEneSlimeTailAttackFv, (void *)&render_shadows__9TObjEnemyFv, (void *)&vfunc_6__13TUnk_804B9870FPsl, (void *)&apply_object_set_data__13TUnk_804B9870FPv,
    (void *)&reset_motion_fields__13TUnk_804806E8Fv, (void *)&get_center__13TUnk_804806E8Fv, (void *)&update_object_view_visibility__13TUnk_804B9870Fff, (void *)&classify_actor_view_detail__13TUnk_804B9870Ffff,
    (void *)&get_name__9TObjEnemyFv, (void *)&interact__13TUnk_804AF8A0Fl, (void *)&add_actor_exp__13TUnk_804806E8Fl, (void *)&consume_timer_field__13TUnk_804806E8Fl,
    (void *)&get_actor_level_index__13TUnk_804806E8Fv, (void *)&update_actor_ground_y__13TUnk_804806E8Fv, (void *)&vfunc_18__13TUnk_804806E8FPUc, (void *)&is_actor_cadence_frame__13TUnk_804806E8Fl,
    (void *)&select_melee_contact_body__13TUnk_804806E8FPvf, (void *)&calc_distance_accuracy_penalty__13TUnk_804806E8FPvPvPvf, (void *)&receive_physical_attack__13TUnk_804806E8FPvf, (void *)&receive_direct_attack__13TUnk_804806E8FPv19DirectAttackPayloadPvll,
    (void *)&receive_weapon_special_attack__13TUnk_804806E8FPvPv, (void *)&apply_knockback_from_attacker__13TUnk_804806E8FPUc, (void *)&try_start_action__13TUnk_804806E8Fll, (void *)&roll_physical_accuracy__13TUnk_804806E8FPvlf,
    (void *)&vfunc_28__13TUnk_804806E8Fv, (void *)&vfunc_29__13TUnk_804806E8Fv, (void *)&is_target_in_attack_range__13TUnk_804806E8Fv, (void *)&test_flag_256__13TUnk_804806E8Fv,
    (void *)&test_flag30_512__13TUnk_804806E8Fv, (void *)&has_flag_0x800__13TUnk_804806E8Fv, (void *)&test_flag_1000__13TUnk_804806E8Fv, (void *)&update_poison_status__13TUnk_804806E8Fv,
    (void *)&update_action_hold_status__13TUnk_804806E8Fv, (void *)&vfunc_37__13TUnk_804806E8Fv, (void *)&update_flag30_timer__13TUnk_804806E8Fv, (void *)&update_movement_status__13TUnk_804806E8Fv,
    (void *)&update_shock_clock__13TUnk_804806E8Fv, (void *)&update_attack_stat_status__13TUnk_804806E8Fv, (void *)&update_defense_stat_status__13TUnk_804806E8Fv, (void *)&vfunc_43__13TUnk_804806E8Fv,
    (void *)&apply_poison_status__13TUnk_804806E8Fv, (void *)&apply_paralysis__13TUnk_804806E8Fv, (void *)&apply_slow_status__13TUnk_804806E8Fv, (void *)&apply_confusion_status__13TUnk_804806E8Fv,
    (void *)&apply_movement_ailment__13TUnk_804806E8Fl, (void *)&apply_shock_status__13TUnk_804806E8Fv, (void *)&clear_harmful_statuses__13TUnk_804806E8Fv, (void *)&apply_attack_stat_status__13TUnk_804806E8FPv,
    (void *)&apply_defense_stat_status__13TUnk_804806E8FPv, (void *)&cure_poison_ailment__13TUnk_804806E8Fv, (void *)&cure_paralysis__13TUnk_804806E8Fv, (void *)&clear_all_status_effects__13TUnk_804806E8Fv,
    (void *)&apply_action_hold_status__13TUnk_804806E8Ff, (void *)&apply_anti_technique__13TUnk_804806E8Fl, (void *)&vfunc_58__13TUnk_804806E8Fv, (void *)&vfunc_59__13TUnk_804806E8Fv,
    (void *)&vfunc_60__13TUnk_804806E8Fv, (void *)&vfunc_61__13TUnk_804806E8Fv, (void *)&vfunc_62__13TUnk_804806E8Fv, (void *)&vfunc_63__13TUnk_804806E8Fv,
    (void *)&reset_pose__13TUnk_804806E8Fv, (void *)&get_anim_node_position__13TUnk_804806E8FlP3Vec, (void *)&vfunc_66__13TUnk_804806E8Fv, (void *)&vfunc_67__13TUnk_804806E8Ff,
    (void *)&get_pos__13TUnk_804806E8Fl, (void *)&apply_switch_attack__13TUnk_804806E8Fv, (void *)&enemy_spawn_jellen_effect__13TUnk_804806E8Fv, (void *)&trigger_switch_attack__13TUnk_804806E8Fv,
    (void *)&enemy_spawn_zalure_effect__13TUnk_804806E8Fv, (void *)&recalc_stats__13TUnk_804806E8Fv, (void *)&vfunc_74__9TObjEnemyFl, (void *)&vfunc_75__13TUnk_804806E8Ff,
    (void *)&vfunc_76__13TUnk_804806E8Fv, (void *)&vfunc_77__13TUnk_804806E8Fv, (void *)&vfunc_78__13TUnk_804806E8Fl, (void *)&vfunc_79__9TObjEnemyFv,
    (void *)&apply_hit_message_flags__9TObjEnemyFPv, (void *)&apply_set_data__9TObjEnemyFPv, (void *)&clear_lobby_object_state__9TObjEnemyFv,
};
#define lbl_80496574 ((Ent_800EAE78 *)lbl_80496574)
#define slime_tail_attack_id_pair ((s32 *)slime_tail_attack_id_pair)
#define TObjEneSlime__attack_target_param_table ((s32 *)TObjEneSlime__attack_target_param_table)
#define slime_tail_attack_zero_vec (*(RecoveredGlobal_800E8128_lbl_80496704 *)slime_tail_attack_zero_vec)
#define slime_tail_attack_transform (*(RecoveredGlobal_800E8128_lbl_80496710 *)slime_tail_attack_transform)
#define __vt__22TObjEneSlimeTailAttack ((s32 *)__vt__22TObjEneSlimeTailAttack)

void TObjPlayer__sub_800E80C0(u8 *dst) {
    TObjPlayer__sub_800E80E8((S_800E80E8 *)(dst), (S_800E80E8 *)(&(*(RecoveredGlobal_800E80C0_lbl_80501010 *)&lbl_80501010).value));
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
S_800E80E8 *TObjPlayer__sub_800E80E8(S_800E80E8 *dst, S_800E80E8 *src) {
    dst->a = src->a;
    dst->d = src->d;
    return dst;
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TObjPlayer__sub_800E8128(void) {
    if ((s32) (*(s32 *)&lbl_805D52B4) == 7) {
        transform_to_view__11TCameraCtrlFii((s32) &slime_tail_attack_zero_vec.value, (s32) &lbl_80501010.value);
    }
    if (((s32) (*(s32 *)&lbl_805D52B4) >= 4) && ((s32) (*(s32 *)&lbl_805D52B4) < 8)) {
        transform_to_view__11TCameraCtrlFii((s32) &slime_tail_attack_transform.value, (s32) ((u8 *)&lbl_80501010.value + (((*(s32 *)&lbl_805D52B4) - 4) * 0xC) + 0xC));
    }
    (*(s32 *)&lbl_805D52B4) += 1;
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TObjPlayer__sub_800E81A8(void) { lbl_805D52B4 = 0; }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TObjPlayer::draw_blob_shadows() {
    s32 i;
    f32 k;
    s32 spC;
    s32 sp8;
    k = lbl_805DA66C;
    for (i = 0; i < 4; i++) {
        Vec_800E81B4 v = ((Obj_800E81B4 *)this)->pts[i];
        Rot_800E81B4 rot;
        v.y += k;
        if (((s32 (*)(void *, Vec_800E81B4 *, Rot_800E81B4 *))project_actor_to_ground)(this, &v, &rot) != 0) {
            push_matrix();
            translate_matrix(0, v.x, lbl_805DA670 + v.y, v.z);
            direction_to_rotation_xz((u8 *)&rot, &spC, &sp8);
            rotate_matrix_z(0, sp8);
            rotate_matrix_x(0, spC + 0x4000);
            scale_matrix(0, lbl_805DA674, lbl_805DA674, lbl_805DA674);
            draw_blob_shadow(0);
            pop_matrix();
        }
    }
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma fp_contract on
void TObjEneSlimeTailAttack::draw_stretched_segment(void *arg1, void *arg2, f32 t) {
    f32 len;
    f32 k;
    f32 saved;
    Vec_800E82B8 d;
    VecCopy((Vec *)&d, (const Vec *)((Vec_800E82B8 *)arg2));
    ((s32 (*)(void *, void *))subtract_vector)(&d, ((Vec_800E82B8 *)arg1));
    len = vector_length(&d);
    push_matrix();
    k = lbl_805DA678 * (lbl_805DA67C + t);
    {
        Vec_800E82B8 p = *((Vec_800E82B8 *)arg1);
        p.x += k * d.x;
        p.y += k * d.y + lbl_805DA680;
        p.z += k * d.z;
        post_translate_matrix(&p);
    }
    rotate_matrix_y(0, (s32)(lbl_8043D280[0] * atan2_float(d.x, d.z)));
    {
        f32 r = lbl_805DA67C - t;
        scale_matrix(0, lbl_805DA67C, lbl_805DA678, r * len / lbl_805DA66C);
    }
    TObjFish::set_global_param(this->texlist);
    TObjPlayer__sub_800EBE48(lbl_805DA688 * t + lbl_805DA684);
    saved = this->m_c0;
    this->m_c0 = lbl_805DA68C;
    this->draw();
    this->m_c0 = saved;
    TObjPlayer::init_render_globals();
    pop_matrix();
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TObjEneSlimeTailAttack::sub_800E841C() {
    u8 *arg0 = (u8 *)this;
    push_matrix();
    post_translate_matrix((u8 *)&this->position);
    rotate_matrix_y(0, (int) (((TObjEneSlimeTailAttack *)arg0)->rotation_y));
    TObjFish::set_global_param((int) (((TObjEneSlimeTailAttack *)arg0)->texlist));
    if ((s32) *(s32 *)((s8 *)arg0 + 0x378) != 0) {
        TObjPlayer__sub_800E81A8();
        TObjEneRe7Berura::set_global_state((s32)TObjPlayer__sub_800E8128);
        ((TObjMotion *)arg0)->draw();
        TObjEneRe7Berura::set_global_state(NULL);
        TObjPlayer__sub_800E80C0(arg0 + 0x390);
        VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)(arg0 + 0x390));
    } else {
        TObjPlayer__sub_800EBE48((f32) (*(f32 *)((s8 *)arg0 + 0x38C)));
        scale_matrix_vec3(0, (arg0 + 0x380));
        TObjPlayer__sub_800E81A8();
        TObjEneRe7Berura::set_global_state((s32)TObjPlayer__sub_800E8128);
        ((TObjMotion *)arg0)->draw();
        TObjEneRe7Berura::set_global_state(NULL);
        TObjPlayer__sub_800E80C0(arg0 + 0x390);
        VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)(arg0 + 0x390));
        TObjPlayer::init_render_globals();
    }
    pop_matrix();
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TObjEneSlimeTailAttack::render() {
  f32 temp_f1;
  f32 temp_f3;
  sub_800E841C();
  if (((s32) (*((s32 *) (((s8 *) ((u8 *)this)) + 0x378)))) != 0)
  {
    temp_f3 = this->m_c0;
    temp_f1 = lbl_805DA68C;
    if (temp_f3 < temp_f1)
    {
      draw_stretched_segment((Vec_800E82B8 *)((void *) ((*((s32 *) (((s8 *) ((u8 *)this)) + 0x374))) + 0x38)), (Vec_800E82B8 *)(((u8 *)this) + 0x38), (f32) (temp_f3 / temp_f1));
    }
    else
      if ((temp_f3 >= lbl_805DA690) && (temp_f3 < lbl_805DA694))
    {
      draw_stretched_segment((Vec_800E82B8 *)(((u8 *)this) + 0x38), (Vec_800E82B8 *)((void *) ((*((s32 *) (((s8 *) ((u8 *)this)) + 0x374))) + 0x38)), (f32) ((temp_f3 - lbl_805DA690) / temp_f1));
    }
  }
  temp_f1 = this->m_c0;
  if ((temp_f1 >= lbl_805DA698) && (temp_f1 < lbl_805DA69C))
  {
    ((TObjPlayer *)((u8 *)this))->draw_blob_shadows();
  }
}
#pragma pop

s32 TObjPlayer__sub_800E85BC(TObjEneSlimeTailAttack *self) {
    Hit_800E8AD0 hit;
    s32 result;
    Ent_800E8AD0 *e;
    Ent_800E8AD0 *e2;
    u16 id;
    s32 id2;
    f32 t = self->m_c0;
    if (t < lbl_805DA6A0 || t > lbl_805DA6A4) {
        return 0;
    }
    hit.kind = 0;
    result = 0;
    hit.dmg = *(s16 *)TLobby::register_boss((s32)lbl_804966FC[((TObjEneSlimeOne *)(*(s32 *)((u8 *)self + 0x374)))->get_attack_target()]);
    id = find_nearest_visible_player(self, 0, lbl_805DA6A8);
    if (id != 0xFFFF && id != *(s32 *)((u8 *)self + 0x37C)) {
        e = ((Ent_800E8AD0 *(*)(s32))get_player_by_client_id)(id);
        if (e != NULL) {
            TObjPlayer *pl = (TObjPlayer *)e;
            f32 lo = pl->position.y - lbl_805DA6AC;
            f32 hi = lbl_805DA6AC + (pl->position.y + pl->m_d48);
            if (!(self->m_300 < lo) && !(self->m_300 > hi) &&
                !(horizontal_distance_squared(&self->m_2fc, &pl->position) > lbl_805DA6B0)) {
                if (e->m21(*(s32 *)((u8 *)self + 0x374), hit, 0, -1, -1) != lbl_805DA6B4) {
                    e->m23(self);
                }
                *(s32 *)((u8 *)self + 0x37C) = id;
                result = 1;
            }
        }
    }
    id2 = self->find_nearest_enemy_with_flag(lbl_805DA6A8);
    if (id2 != 0xFFFF) {
        void *owner = *(void **)((u8 *)self + 0x374);
        if (owner == NULL || id2 != (u16)get_entity_id(owner)) {
            e2 = (Ent_800E8AD0 *)get_enemy_entity(id2);
            if (e2 != NULL && !(horizontal_distance_squared(&self->m_2fc, (u8 *)e2 + 0x2FC) > lbl_805DA6B0)) {
                if (e2->m21(*(s32 *)((u8 *)self + 0x374), hit, 0, -1, -1) != lbl_805DA6B4) {
                    e2->m23(self);
                }
                result = 1;
            }
        }
    }
    return result;
}

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma fp_contract on
void TObjEneSlimeTailAttack::run_task() {
    if ((s32) *(s32 *)((s8 *)((u8 *)this) + 0x378) != 0) {
        TObjPlayer__sub_800E85BC(this);
        advance_animation_playback(this);
        if (this->animationFlags & 0x10) {
            queue_destruction__7TObjectFv(this);
            return;
        }
        if (((TObjEneSlimeOne *)(*(s32 *)((s8 *)((u8 *)this) + 0x374)))->is_in_water_bomb_states() != 0) {
            *(s32 *)((s8 *)((u8 *)this) + 0x378) = 0;
        }
    } else {
        this->m_c0 += lbl_805DA670 * (lbl_805DA68C - this->m_c0);
        *(f32 *)((s8 *)((u8 *)this) + 0x38C) = (f32) (*(f32 *)((s8 *)((u8 *)this) + 0x38C) + lbl_805DA6B8);
        *(f32 *)((s8 *)((u8 *)this) + 0x3C) = (f32) (*(f32 *)((s8 *)((u8 *)this) + 0x3C) + lbl_805DA6BC);
        *(f32 *)((s8 *)((u8 *)this) + 0x380) = (f32) (*(f32 *)((s8 *)((u8 *)this) + 0x380) + lbl_805DA6C0);
        *(f32 *)((s8 *)((u8 *)this) + 0x384) = (f32) (*(f32 *)((s8 *)((u8 *)this) + 0x384) + lbl_805DA6C4);
        *(f32 *)((s8 *)((u8 *)this) + 0x388) = (f32) (*(f32 *)((s8 *)((u8 *)this) + 0x388) + lbl_805DA6C0);
        if (*(f32 *)((s8 *)((u8 *)this) + 0x384) <= lbl_805DA684) {
            queue_destruction__7TObjectFv(this);
        }
    }
}
#pragma pop

void *create__22TObjEneSlimeTailAttackFiiii(s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    void *obj;
    void *ctrl;

    obj = __nw__7TObjectFUl(0x3CC);
    if (obj != 0) {
        ctrl = __nw__7TObjectFUl(0x20);
        if (ctrl != 0) {
            ctrl = TObjControl__ct(ctrl, tl_04);
        }
        obj = TObjEneSlimeTailAttack__ct((TObjEneSlimeTailAttack *)obj, (void *)ctrl, (s32)arg2, (s32)arg3, (s32)arg4);
    }
    return obj;
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

extern "C" {
extern s32 TObjEneSlimeTailAttack__name;
void *TObjEneSlimeTailAttack__ct(TObjEneSlimeTailAttack *ene_slime_tail_attack, void *arg1, s32 arg2, s32 arg3, s32 arg4) {
  unsigned int id;
  u8 *inst;
  ((s32 (*)(void *, void *)) __ct__9TObjEnemyFP7TObject)(ene_slime_tail_attack, arg1);
  *((u8 **) (((s8 *) ene_slime_tail_attack) + 0x18)) = (u8 *) __vt__22TObjEneSlimeTailAttack;
  *((s32 *) (((s8 *) ene_slime_tail_attack) + 0)) = TObjEneSlimeTailAttack__name;
  *((s32 *) (((s8 *) ene_slime_tail_attack) - -0x374)) = arg4;
  inst = get_instance__15TObjEneSlimeOneFv();
  id = ((s32 *) lbl_804966F4)[((TObjEneSlimeOne *)(*((s32 *) (((s8 *) ene_slime_tail_attack) + (0x374 & 0xFFFF)))))->get_attack_target()];
  ene_slime_tail_attack->texlist = TObjFish__sub_8001EDB0((s32) inst, id);
  *((s32 *) (((s8 *) ene_slime_tail_attack) + 0x34)) = get_bml_model((s32) inst, id);
  ene_slime_tail_attack->action_table = (u8 *) lbl_8049639C;
  ((TObjMotion *)ene_slime_tail_attack)->set_field_d8((s32) ((u8 *) lbl_8049639C));
  *((s32 *) (((s8 *) ene_slime_tail_attack) + 0xDC)) = *((s32 *) (((s8 *) inst) + 0x430));
  ((TObjMotion *)ene_slime_tail_attack)->set_field_dc(*((s32 *) (((s8 *) inst) + 0x430)));
  ene_slime_tail_attack->m_b8 = 6;
  ((TObjMotion *)ene_slime_tail_attack)->set_animation(ene_slime_tail_attack->m_b8);
  ((TObjMotion *)ene_slime_tail_attack)->set_field_b8(ene_slime_tail_attack->m_b8);
  ene_slime_tail_attack->rotation_y = arg3;
  VecCopy((Vec *)(((u8 *) ene_slime_tail_attack) + 0x38), (const Vec *)arg2);
  *((s32 *) (((s8 *) ene_slime_tail_attack) + 0x378)) = 1;
  *((s32 *) (((s8 *) ene_slime_tail_attack) + 0x37C)) = 0xFFFF;
  *((f32 *) (((s8 *) ene_slime_tail_attack) + 0x388)) = lbl_805DA67C;
  *((f32 *) (((s8 *) ene_slime_tail_attack) + 0x384)) = lbl_805DA67C;
  *((f32 *) (((s8 *) ene_slime_tail_attack) + 0x380)) = lbl_805DA67C;
  *((f32 *) (((s8 *) ene_slime_tail_attack) + 0x38C)) = lbl_805DA67C;
  return ene_slime_tail_attack;
}
}
s32 water_bomb_hit_nearby(u8 *target) {
    s32 hit;
    Ent_800E8AD0 *e;
    Ent_800E8AD0 *e2;
    Hit_800E8AD0 h = lbl_8043D260[0];
    u16 id;
    s32 id2;
    hit = 0;
    h.dmg = *(f32 *)((s8 *)target + 0x390);
    VecCopy((Vec *)(target + 0x2FC), (const Vec *)(target + 0x38));
    id = ((u16 (*)(void *, s32, f32))find_nearest_visible_player)(target, 0, lbl_805DA6A8);
    if (id != 0xFFFF) {
        e = ((Ent_800E8AD0 *(*)(s32))get_player_by_client_id)(id);
        if (e != NULL && !(horizontal_distance_squared(target + 0x2FC, (u8 *)e + 0x2FC) > lbl_805DA6A8)) {
            if (lbl_805DA6B4 != e->m21(((TObjEneSlimeWaterBomb *)target)->m_38c, h, 0, -1, -1)) {
                e->m23(target);
            }
            hit = 1;
        }
    }
    id2 = ((TObjEneSlimeWaterBomb *)target)->find_nearest_enemy_masked(lbl_805DA6A8);
    if (id2 != 0xFFFF) {
        e2 = (Ent_800E8AD0 *)get_enemy_entity(id2);
        if (e2 != NULL && !(horizontal_distance_squared(target + 0x2FC, (u8 *)e2 + 0x2FC) > lbl_805DA6A8)) {
            if (lbl_805DA6B4 != e2->m21(((TObjEneSlimeWaterBomb *)target)->m_38c, h, 0, -1, -1)) {
                e2->m23(target);
            }
            hit = 1;
        }
    }
    return hit;
}

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
void TObjEneSlimeWaterBomb::render() {
    u8 *arg0 = (u8 *)this;
    Vec_800E8C6C v;
    s32 spC;
    s32 sp8;
    f32 d;
    f32 k;
    ((int (*)(void*))push_matrix)(arg0);
    translate_matrix(0, *(f32 *)((s8 *)arg0 + 0x38), lbl_805DA670 + this->m_380, *(f32 *)((s8 *)arg0 + 0x40));
    direction_to_rotation_xz((u8 *)&this->m_248, &spC, &sp8);
    rotate_matrix_z(0, sp8);
    rotate_matrix_x(0, spC + 0x4000);
    d = *(f32 *)((s8 *)arg0 + 0x3C) - this->m_380;
    if (d > lbl_805DA6C8) {
        d = lbl_805DA6C8;
    } else if (d < lbl_805DA6B4) {
        d = lbl_805DA6B4;
    }
    k = lbl_805DA6CC * (lbl_805DA67C - d / lbl_805DA6C8) + lbl_805DA670;
    v.x = v.y = k;
    v.z = lbl_805DA67C;
    scale_current_matrix(&v);
    draw_blob_shadow(0);
    ((int (*)(void))pop_matrix)();
}
#pragma pop

void run_task__21TObjEneSlimeWaterBombFv(Bomb_800E8D4C *arg0) {
    s32 die = 0;
    arg0->vel.y += lbl_805DA6D0;
    vec3_add_to(&arg0->pos, &arg0->vel);
    if (++arg0->timer > 0x14F) {
        die = 1;
    }
    {
        Vec_800E8D4C p = arg0->pos;
        p.y += lbl_805DA6AC;
        if (((s32 (*)(void *, void *, void *))project_actor_to_ground)(arg0, &p, arg0->hit) != 0) {
            arg0->ground = p.y;
            if (arg0->pos.y <= arg0->ground) {
                arg0->pos.y = arg0->ground;
                arg0->vel.y *= lbl_805DA6D4;
                spawn_particle_effect(&arg0->pos, 0xE2);
            }
        } else {
            die = 1;
        }
    }
    if (arg0->link != NULL) {
        ((TNowLoading *)(arg0->link))->copy_pos(&arg0->pos);
    }
    if (((TObjEneSlimeOne *)(arg0->owner))->is_in_water_bomb_states() != 0 || ((s32 (*)(void *))water_bomb_hit_nearby)(arg0) != 0) {
        die = 1;
    }
    {
        f32 t = arg0->life + lbl_805DA6D8;
        arg0->life = t;
        if (t >= lbl_805DA6DC || die != 0) {
            spawn_particle_effect(&arg0->pos, 0xE2);
            ((s32 (*)(void *))queue_destruction__7TObjectFv)(arg0);
        }
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

void *__dt__21TObjEneSlimeWaterBombFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__21TObjEneSlimeWaterBomb;
        if (*(void **)((s8 *)arg0 + 0x388) != NULL) { TBoss4Type2::request_destroy((u32)(*(void **)((s8 *)arg0 + 0x388))); ((TObjEneSlimeWaterBomb *)arg0)->m_388 = 0; }
        __dt__9TObjEnemyFv((TObjEnemy *)arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
void *TObjEneSlimeWaterBomb__ct(TObjEneSlimeWaterBomb *ene_slime_water_bomb, void *arg1, void *arg2) {
    f32 s;
    f32 c;
    ((s32 (*)(void *, void *))__ct__9TObjEnemyFP7TObject)(ene_slime_water_bomb, arg1);
    *(s32 **)((s8 *)ene_slime_water_bomb + 0x18) = __vt__21TObjEneSlimeWaterBomb;
    *(s32 *)((s8 *)ene_slime_water_bomb + 0) = lbl_805D2AE0;
    *(void **)((s8 *)ene_slime_water_bomb + 0x38C) = arg2;
    ene_slime_water_bomb->rotation_y = *(s32 *)((s8 *)(*(u8 * *)&ene_slime_water_bomb->m_up) + 0x60);
    VecCopy((Vec *)((u8 *) ene_slime_water_bomb + 0x38), (const Vec *)(*(u8 * *)&ene_slime_water_bomb->m_up + 0x38));
    s = sin_table_lookup(ene_slime_water_bomb->rotation_y);
    c = cos_table_lookup(ene_slime_water_bomb->rotation_y);
    *(f32 *)((s8 *)ene_slime_water_bomb + 0x38) += lbl_805DA6E0 * s;
    *(f32 *)((s8 *)ene_slime_water_bomb + 0x3C) += lbl_805DA6E4;
    *(f32 *)((s8 *)ene_slime_water_bomb + 0x40) += lbl_805DA6E0 * c;
    *(f32 *)((s8 *)ene_slime_water_bomb + 0x374) = lbl_805DA6D8 * s;
    *(f32 *)((s8 *)ene_slime_water_bomb + 0x378) = lbl_805DA6B4;
    ene_slime_water_bomb->m_37c = lbl_805DA6D8 * c;
    *(f32 *)((s8 *)ene_slime_water_bomb + 0x384) = lbl_805DA6B4;
    *(s32 *)&ene_slime_water_bomb->m_388 = (s32)create_particle_emitter((u8 *) ene_slime_water_bomb + 0x38, 0xCF);
    *(f32 *)((s8 *)ene_slime_water_bomb + 0x390) = *dispatch_shared_handler_a__6TLobbyFl(TObjEneSlime__attack_target_param_table[((TObjEneSlimeOne *)(*(s32 *)&ene_slime_water_bomb->m_38c))->get_attack_target()]);
    if (*(f32 *)((s8 *)ene_slime_water_bomb + 0x390) < lbl_805DA6B4) {
        *(f32 *)((s8 *)ene_slime_water_bomb + 0x390) = lbl_805DA6B4;
    }
    *(s32 *)&ene_slime_water_bomb->m_394 = 0;
    return ene_slime_water_bomb;
}
#pragma pop

void TObjEneSlimeOne::sub_800E9090() {
    Bomb_800E9090 *self = (Bomb_800E9090 *)this;
    Vec_800E9090 c;
    Vec_800E9090 b;
    f32 s;
    s32 ang;
    s32 t;
    s32 w1;
    s32 w0;
    s = lbl_805DA678 * self->f3A0;
    Vec_800E9090 a = self->pos;
    subtract_vector(&a, &self->vel);
    a.x *= lbl_805DA678;
    a.y *= lbl_805DA678;
    a.z *= lbl_805DA678;
    VecCopy((Vec *)&c, (const Vec *)&self->vel);
    vec3_add_to(&c, &a);
    c.y += lbl_805DA6E8;
    ang = (*(const f64 *)&lbl_8043D280) * ((f32 (*)(f32, f32))atan2_float)(a.x, a.z);
    b.x = lbl_805DA6EC;
    b.y = lbl_805DA6F0;
    b.z = lbl_805DA6EC * vector_length(&a) / lbl_805DA6F4;
    if (b.x > b.z) {
        b.x = b.z;
    }
    if (s < lbl_805DA684 || b.x < lbl_805DA684) {
        return;
    }
    TObjPlayer::push_material_color_override(s, lbl_805DA6F8, lbl_805DA6B4, lbl_805DA67C);
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

void fn_800E9238(s32 arg0) {
    typedef char sp8_offset[(offsetof(Stack_800E9238, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_800E9238, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_800E9238, sp10) == 0x8) ? 1 : -1];
    Stack_800E9238 stack;
    VecCopy((Vec *)(&stack.sp8), (const Vec *)(arg0 + 0x38));
    ((f32 (*)(void *, void *))subtract_vector)((void *)&stack.sp8, (void *)(arg0 + 0x374));
    stack.sp8 *= lbl_805DA6FC;
    stack.spC *= lbl_805DA6FC;
    stack.sp10 *= lbl_805DA6FC;
    ((f32 (*)(void *, void *))vec3_add_to)((void *)(arg0 + 0x374), (void *)&stack.sp8);
}

void TObjEneSlimeOne::copy_position() {
    s32 arg0 = (s32)this;
    VecCopy((Vec *)(arg0 + 0x374), (const Vec *)(arg0 + 0x38));
}

f32 fabs_float(f32);
extern const f32 lbl_805DA700;
extern const f32 lbl_805DA704;

#pragma push
#pragma fp_contract on
void TBoss8Dragon__sub_800E92D8(TObjEneSlimeOne *self) {
    s32 landed = 0;
    s32 tries = 4;
    s32 angle;
    f32 s;
    f32 c;

    self->m_3dc.y += lbl_805DA700;
    do {
        Vec next;
        Vec probe;
        VecCopy(&next, &self->position);
        vec3_add_to(&next, &self->m_3dc);
        VecCopy(&probe, &next);
        probe.y += lbl_805DA6AC + fabs_float(self->m_3dc.y);
        if (project_actor_to_ground(self, &probe, 0) != 0) {
            VecCopy(&self->position, &next);
            if (!(self->position.y > probe.y)) {
                self->position.y = probe.y;
                landed = 1;
            }
            break;
        }
        s = sin_table_lookup(0x4000);
        c = cos_table_lookup(0x4000);
        self->m_3dc.x = c * self->m_3dc.x + s * self->m_3dc.z;
        self->m_3dc.z = -s * self->m_3dc.x + c * self->m_3dc.z;
    } while (--tries > 0);
    if (tries == 0) {
        Vec probe;
        self->m_3dc.x = self->m_3dc.z = lbl_805DA6B4;
        VecCopy(&probe, &self->position);
        probe.y += lbl_805DA6AC + fabs_float(self->m_3dc.y);
        if (project_actor_to_ground(self, &probe, 0) != 0) {
            if (!(self->position.y > probe.y)) {
                self->position.y = probe.y;
                landed = 1;
            }
        } else {
            landed = 1;
        }
    }
    if (self->m_3e8 != NULL) {
        ((TNowLoading *)self->m_3e8)->copy_pos(&self->position);
    }
    if (landed != 0) {
        if (self->m_3e8 != NULL) {
            TBoss4Type2::request_destroy((u32)self->m_3e8);
            self->m_3e8 = NULL;
        }
        for (angle = 0; angle < 0xFFFF; angle += 0x1000) {
            Vec p = *&self->position;
            p.x = lbl_805DA704 * sin_table_lookup(angle) + p.x;
            p.y += lbl_805DA708;
            p.z = lbl_805DA704 * cos_table_lookup(angle) + p.z;
            spawn_particle_effect(&p, 0xE2);
        }
        TObjEneSlimeOne__sub_800EAD84((Obj_800EAD84 *)self);
        self->set_state(1);
    }
}
#pragma pop

void fn_800E9538(u8 *ene_slime_one) {
    *(s32 *)((s8 *)ene_slime_one + 0x3E8) = (s32)create_particle_emitter((ene_slime_one + 0x38), 0xE1);
    *(f32 *)((s8 *)ene_slime_one + 0x3A4) = (f32) lbl_805DA708;
    ((TObjEneSlimeOne *)ene_slime_one)->m_3b0 = (f32) lbl_805DA6B4;
    *(f32 *)((s8 *)ene_slime_one + 0x3AC) = (f32) lbl_805DA6B4;
    *(f32 *)((s8 *)ene_slime_one + 0x3A8) = (f32) lbl_805DA6B4;
    ((TObjEneSlimeOne *)ene_slime_one)->m_3a0 = (f32) lbl_805DA6B4;
    ((TObjEneSlimeOne *)(((TObjEneSlimeOne *)ene_slime_one)->m_388))->set_motion_state(7);
    set_display_mode__15TObjEneSlimeOneFPvi(ene_slime_one, 0);
}
}

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void update_effect_fade_lifetime(u8 *object) {
    f32 temp_f1;
    s32 temp_r0;
    temp_f1 = *(f32 *)((s8 *)object + 0x3A0) + lbl_805DA70C;
    *(f32 *)((s8 *)object + 0x3A0) = temp_f1;
    if (temp_f1 < lbl_805DA6B4) {
        *(f32 *)((s8 *)object + 0x3A0) = (f32) lbl_805DA6B4;
    }
    temp_r0 = *(s32 *)((s8 *)object + 0x390) - 1;
    *(s32 *)((s8 *)object + 0x390) = temp_r0;
    if (temp_r0 <= 0) {
        queue_destruction__7TObjectFv(object);
    }
}
#pragma pop

void fn_800E95F4(u8 *arg0) {
    u8 *object;
    object = (u8 *)(*(u8 **)((s8 *)arg0 + 0x3F0));
    if ((object != NULL) && (((TObject *)object)->all_parents_unqueued_for_destruction() != 0)) {
        fn_800EB778(*(u8 **)((s8 *)arg0 + 0x3F0), (s32) *(u16 *)((s8 *)arg0 + 0x1C));
    }
    *(f32 *)((s8 *)arg0 + 0x3B0) = (f32) lbl_805DA67C;
    *(f32 *)((s8 *)arg0 + 0x3AC) = (f32) lbl_805DA67C;
    *(f32 *)((s8 *)arg0 + 0x3A8) = (f32) lbl_805DA67C;
    *(s32 *)((s8 *)arg0 + 0x390) = 5;
    ((TObjPlayer *)arg0)->refresh_lobby_state();
    ((s32 (*)(s32, u32, s16, s32))play_sound_effect)(0x4003A81B, (u32)(arg0 + 0x38), 0, 0);
    spawn_particle_effect((arg0 + 0x2FC), 0xFE);
    ((TObjEneSlimeOne *)(*(u8 **)((s8 *)arg0 + 0x388)))->set_motion_state(5);
    set_display_mode__15TObjEneSlimeOneFPvi(arg0, 0);
}

void TObjEneSlimeOne__sub_800E969C(TObjEneSlimeOne *ene_slime_one) {
    if (ene_slime_one->animationFlags & 0x10) {
        ene_slime_one->set_state(5);
    }
}

void init_split_effect__15TObjEneSlimeOneFPv(u8 *arg0) {
    *(f32 *)((s8 *)arg0 + 0x3B0) = (f32) lbl_805DA67C;
    *(f32 *)((s8 *)arg0 + 0x3AC) = (f32) lbl_805DA67C;
    *(f32 *)((s8 *)arg0 + 0x3A8) = (f32) lbl_805DA67C;
    spawn_particle_effect((arg0 + 0x2FC), 0xCE);
    play_sound_effect(0x4003A61A, arg0 + 0x38, 0, 0);
    ((TObjEneSlimeOne *)(*(s32 *)((s8 *)arg0 + 0x388)))->set_motion_state(5);
    ((s32 (*)(void *, int))set_display_mode__15TObjEneSlimeOneFPvi)(arg0, 0);
}

void update_tick__15TObjEneSlimeOneFPv(TObjEneSlimeOne *ene_slime_one) {
    s32 temp_r3;

    temp_r3 = *(s32 *)((s8 *)ene_slime_one + 0x394) + 1;
    *(s32 *)((s8 *)ene_slime_one + 0x394) = temp_r3;
    if (!(temp_r3 & 3)) {
        spawn_particle_effect(((u8 *)ene_slime_one + 0x2FC), 0xE0);
    }
    if (ene_slime_one->animationFlags & 0x10) {
        if (ene_slime_one->is_timer_active() != 0) {
            ene_slime_one->set_state(7);
            return;
        }
        ene_slime_one->set_state(6);
    }
}

void reset_display_state__15TObjEneSlimeOneFPv(void* a0) { *(float*)((char*)a0 + 0x3b0) = lbl_805DA67C; *(float*)((char*)a0 + 0x3ac) = lbl_805DA67C; *(float*)((char*)a0 + 0x3a8) = lbl_805DA67C; *(int*)((char*)a0 + 0x394) = 0; ((TObjEneSlimeOne *)(*(int*)((char*)a0 + 0x388)))->set_motion_state((s32)((void*)4)); ((int (*)(void*, void*))set_display_mode__15TObjEneSlimeOneFPvi)(a0, (void*)2); }

void tick_timer__15TObjEneSlimeOneFPv(TObjEneSlimeOne *ene_slime_one) {
    s32 temp_r0;

    temp_r0 = ene_slime_one->m_390 - 1;
    ene_slime_one->m_390 = temp_r0;
    if (temp_r0 <= 0) {
        ene_slime_one->set_state(5);
    }
}

#pragma push
#pragma fp_contract on
void start_tail_attack__15TObjEneSlimeOneFPv(Self_800E984C *self) {
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
    r = lbl_805DA6AC * calc_boss4_scale__10TObjPlayerFi(self) + lbl_805DA710;
    ang = lbl_805DA714 * calc_boss4_scale__10TObjPlayerFi(self);
    self->dest.x = r * sin_table_lookup(ang) + self->dest.x;
    self->dest.z = r * cos_table_lookup(ang) + self->dest.z;
    Vec_800E984C dir = self->dest;
    subtract_vector(&dir, &self->pos);
    len = vector_length(&dir);
    if (lbl_805DA6B4 == len) {
        ((TObjEneSlimeOne *)self)->set_state(5);
        return;
    }
    n = len / lbl_805DA66C;
    if (vector_length(&dir) <= lbl_805DA718) {
        dir.x = (*(const f32 *)&lbl_805DA67C);
        dir.z = dir.y = lbl_805DA6B4;
    } else {
        normalize_vector(&dir);
    }
    dir.x *= lbl_805DA66C;
    dir.y *= lbl_805DA66C;
    dir.z *= lbl_805DA66C;
    Vec_800E984C pos = self->pos;
    pos.y += lbl_805DA6AC;
    while (n > 0) {
        Vec_800E984C tmp = pos;
        if (project_actor_to_ground(self, &tmp, 0) == 0 || csnLookAt(&self->pos, &pos) != 0) {
            ((TObjEneSlimeOne *)self)->set_state(9);
            return;
        }
        n--;
        ((void (*)(void *, void *))vec3_add_to)(&pos, &dir);
    }
    self->f390 = 0x5A;
    ((TObjEneSlimeOne *)((void *)self->f388))->set_motion_state((s32)((void*)((void *)0)));
    play_sound_effect(0x4003A318, &self->dest, 0, 0);
    ((void (*)(void *, void *, s32, void *))create__22TObjEneSlimeTailAttackFiiii)(self, &self->dest, self->f60, self);
    ((int (*)(void*, void*))set_display_mode__15TObjEneSlimeOneFPvi)(self, (void*)((void *)2));
}
#pragma pop

void update_water_bomb_timer__15TObjEneSlimeOneFPv(u8 *arg0) {
    s32 temp_r0;
    s32 temp_r0_2;

    *(s32 *)((s8 *)arg0 + 0x394) = (s32) (*(s32 *)((s8 *)arg0 + 0x394) - 1);
    temp_r0 = *(s32 *)((s8 *)arg0 + 0x394);
    if (temp_r0 > 0) {
        spawn_particle_effect(arg0 + 0x2FC, 0xFF);
    } else if (temp_r0 == 0) {
        ((s32 (*)(s32, void *, s32, s32))play_sound_effect)(0x4003A017, arg0 + 0x38, 0, 0);
        spawn_particle_effect(arg0 + 0x2FC, 0xE2);
        ((TObjEneSlimeWaterBomb *)arg0)->create(arg0);
    }
    temp_r0_2 = *(s32 *)((s8 *)arg0 + 0x390) - 1;
    *(s32 *)((s8 *)arg0 + 0x390) = temp_r0_2;
    if (temp_r0_2 <= 0) {
        if (((TObjEneSlimeOne *)arg0)->is_timer_active() != 0) {
            ((TObjEneSlimeOne *)arg0)->set_state(7);
            return;
        }
        ((TObjEneSlimeOne *)arg0)->set_state(5);
    }
}

void begin_appear__15TObjEneSlimeOneFPv(void* p) { *(int*)((char*)p + 0x390) = 90; *(int*)((char*)p + 0x394) = 19; ((TObjEneSlimeOne *)(*(void**)((char*)p + 0x388)))->set_motion_state((s32)((void*)3)); ((int (*)(void*, void*))set_display_mode__15TObjEneSlimeOneFPvi)(p, (void*)2); }

void TObjPlayer__sub_800E9BCC(Obj_800E9BCC *o) {
    f32 v[3];
    s32 t;
    v[0] = 1.0f;
    v[1] = 0.0f;
    v[2] = 0.0f;
    if (o->f3CC != 0xFFFF) {
        TObjPlayer::calc_distance_to_client((s32)o, (u16)o->f3CC, (u32)v);
    }
    t = (s32) (lbl_8043D280[0] * atan2_float(v[0], v[2]));
    o->f60 = approach_angle_limited(o->f60, t, 0x200);
    if (angle_difference_abs(o->f60, t) < 0x200) {
        o->f390 = 0;
    }
    VecCopy((Vec *)o->prev, (const Vec *)o->pos);
    if (vector_length(v) <= lbl_805DA718) {
        v[0] = 1.0f;
        v[1] = 0.0f;
        v[2] = 0.0f;
    } else {
        normalize_vector(v);
    }
    v[0] *= lbl_805DA71C;
    v[1] *= lbl_805DA71C;
    v[2] *= lbl_805DA71C;
    vec3_add_to(o->pos, v);
    if (project_actor_to_ground(o, o->pos, 0) == 0 || csnLookAt(o->prev, o->pos) != 0) {
        VecCopy((Vec *)o->pos, (const Vec *)o->prev);
    }
    if (--o->f390 <= 0) {
        if (vector_length(v) > lbl_805DA720 || calc_boss4_scale__10TObjPlayerFi(o) < lbl_805DA724) {
            ((TObjEneSlimeOne *)o)->set_state(9);
        } else {
            ((TObjEneSlimeOne *)o)->set_state(10);
        }
    }
}

void TObjPlayer__sub_800E9D7C(void* p) { ((int (*)(void*, void*, void*))set_random_timer__15TObjEneSlimeOneFPvii)(p, (void*)30, (void*)30); ((TObjEneSlimeOne *)(*(void**)((char*)p + 0x388)))->set_motion_state((s32)((void*)0)); ((int (*)(void*, void*))set_display_mode__15TObjEneSlimeOneFPvi)(p, (void*)2); }

void TObjPlayer__sub_800E9DC8(Obj_800E9DC8 *arg0) {
    f32 sp[3];
    s32 r = 0;
    s32 t;
    arg0->f60 = arg0->f60 + arg0->f3C4;
    if (((TObjEneSlimeOne *)arg0)->find_nearest_enemy_with_flag((s32)sp, (f32)lbl_805DA728) != 0xFFFF) {
        t = (s32) (lbl_8043D280[0] * atan2_float(sp[0], sp[2]));
        if (angle_difference_abs(arg0->f60, t) < 0x444) {
            arg0->f60 = t;
            r = 1;
        }
    }
    arg0->f390 = arg0->f390 - 1;
    if (r != 0 || arg0->f390 < 0) {
        ((TObjEneSlimeOne *)arg0)->set_state(9);
    }
}

void init_slime_state__10TObjPlayerFPv(void *actor) {
    ((s32 (*)(void *, s32, s32))set_random_timer__15TObjEneSlimeOneFPvii)(actor, 0x1E, 0x1E);
    ((TObjPlayer *)actor)->m_3c4 = 0x888;
    if (calc_boss4_scale__10TObjPlayerFi(actor) > lbl_805DA678) {
        ((TObjPlayer *)actor)->m_3c4 = ((TObjPlayer *)actor)->m_3c4 * 0xFFFFFFFF;
    }
    ((TObjEneSlimeOne *)(*(s32 *)((s8 *)actor + 0x388)))->set_motion_state((s32)((void*)(1)));
    ((int (*)(void*, int))set_display_mode__15TObjEneSlimeOneFPvi)(actor, 2);
}

#pragma push
#pragma fp_contract on
void TObjPlayer__sub_800E9EFC(u8 *ene_slime_one) {
    Vec_800E9EFC sp14;
    Vec_800E9EFC sp8;
    f32 f;
    u16 r;
    s32 n;

    f = sin_table_lookup(*(s32 *)((s8 *)ene_slime_one + 0x39C));
    if (f < lbl_805DA6B4) {
        f = lbl_805DA6B4;
    }
    ((TObjEneSlimeOne *)ene_slime_one)->rotation_y = f * (f32)*(s32 *)((s8 *)ene_slime_one + 0x3C4) + (f32)((TObjEneSlimeOne *)ene_slime_one)->rotation_y;
    if (((TObjEneSlimeOne *)ene_slime_one)->m_3cc == 0xFFFF) {
        r = find_nearest_visible_player(ene_slime_one, &sp14, lbl_805DA72C);
        if (r != 0xFFFF &&
            angle_difference_abs(((TObjEneSlimeOne *)ene_slime_one)->rotation_y, (s32)(lbl_8043D280[0] * ((f32 (*)(f32, f32))atan2_float)(sp14.x, sp14.z))) < 0x1C71) {
            *(s32 *)((s8 *)ene_slime_one + 0x39C) = 0;
            ((TObjEneSlimeOne *)ene_slime_one)->m_3cc = r;
        }
    }
    *(s32 *)((s8 *)ene_slime_one + 0x39C) -= 0x600;
    if (*(s32 *)((s8 *)ene_slime_one + 0x39C) <= 0) {
        n = (f32)*(u32 *)((s8 *)(get_bml_motion(*(s32 *)((s8 *)ene_slime_one + 0x380), 10)) + 4) / lbl_805DA678;
        *(s32 *)((s8 *)ene_slime_one + 0x39C) = 0;
        if (((TObjEneSlimeOne *)ene_slime_one)->m_3cc != 0xFFFF) {
            sp8.x = 1.0f;
            sp8.y = 0.0f;
            sp8.z = 0.0f;
            TObjPlayer::calc_distance_to_client((s32)ene_slime_one, (u16)(((TObjEneSlimeOne *)ene_slime_one)->m_3cc), (u32)&sp8);
            ((TObjEneSlimeOne *)ene_slime_one)->rotation_y = approach_angle_limited(((TObjEneSlimeOne *)ene_slime_one)->rotation_y, (s32)(lbl_8043D280[0] * ((f32 (*)(f32, f32))atan2_float)(sp8.x, sp8.z)), 0x280);
        }
        if (((TObjEneSlimeOne *)ene_slime_one)->m_390 > n) {
            ((TObjEneSlimeOne *)((void *)((TObjEneSlimeOne *)ene_slime_one)->m_388))->set_motion_state((s32)((void *)0));
            ((TObjEneSlimeOne *)ene_slime_one)->m_390 = n;
        } else if (--((TObjEneSlimeOne *)ene_slime_one)->m_390 <= 0) {
            if (((TObjEneSlimeOne *)ene_slime_one)->m_3cc == 0xFFFF) {
                ((TObjEneSlimeOne *)ene_slime_one)->set_state(5);
            } else {
                ((TObjEneSlimeOne *)ene_slime_one)->set_state(8);
            }
        }
    }
}
#pragma pop

void TObjPlayer__sub_800EA120(u8 *actor) {
  unsigned int new_var;
  *((s32 *) (((s8 *) actor) + 0x3CC)) = 0xFFFF;
  *((s32 *) (((s8 *) actor) + 0x39C)) = (s32) ((((s32) (lbl_805DA730 * calc_boss4_scale__10TObjPlayerFi((void *)((s32) actor)))) + 4) << 0x10);
  *((s32 *) (((s8 *) actor) + 0x390)) = 0x7FFFFFFF;
  *((s32 *) (((s8 *) actor) + 0x3C4)) = 0x400;
  new_var = 1;
  if (calc_boss4_scale__10TObjPlayerFi((void *)((s32) actor)) > (*(const f32 *)&lbl_805DA678))
  {
    *((s32 *) (((s8 *) actor) + 0x3C4)) = (s32) ((*((s32 *) (((s8 *) actor) + 0x3C4))) * (-new_var));
  }
  ((TObjEneSlimeOne *)(*((s32 *) (((s8 *) actor) + 0x388))))->set_motion_state((s32)((void*)((int) new_var)));
  ((int (*)(void*, int))set_display_mode__15TObjEneSlimeOneFPvi)(actor, 2);
}

void update_dive_timer__10TObjPlayerFPv(u8 *ene_slime_one) {
    s32 temp_r0;

    temp_r0 = *(s32 *)((s8 *)ene_slime_one + 0x394) - 1;
    *(s32 *)((s8 *)ene_slime_one + 0x394) = temp_r0;
    if (temp_r0 == 0) {
        spawn_particle_effect(ene_slime_one + 0x2FC, 0xCD);
    }
    if (((TObjEneSlimeOne *)(((TObjEneSlimeOne *)ene_slime_one)->m_388))->is_reached_target_depth() == 1) {
        ((TObjEneSlimeOne *)ene_slime_one)->set_state(3);
    }
}

void enter_appear_state__10TObjPlayerFPv(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 0x394) = 0x14;
    ((s32 (*)(s32, void *, s32, s32))play_sound_effect)(0x4003AD1D, arg0 + 0x38, 0, 0);
    ((TObjEneSlimeOne *)(*(s32 *)((s8 *)arg0 + 0x388)))->set_motion_state((s32)((void*)(0xA)));
    ((int (*)(void*, int))set_display_mode__15TObjEneSlimeOneFPvi)(arg0, 1);
}

void update_slime_timer__10TObjPlayerFPv(u8 *ene_slime_one) {
    s32 temp_r0;

    temp_r0 = *(s32 *)((s8 *)ene_slime_one + 0x394) - 1;
    *(s32 *)((s8 *)ene_slime_one + 0x394) = temp_r0;
    if (temp_r0 == 0) {
        spawn_particle_effect(ene_slime_one + 0x2FC, 0xCD);
    }
    if (((TObjEneSlimeOne *)(((TObjEneSlimeOne *)ene_slime_one)->m_388))->is_reached_target_depth() == 1) {
        if (((TObjEneSlimeOne *)ene_slime_one)->is_timer_active() != 0) {
            ((TObjEneSlimeOne *)ene_slime_one)->set_state(7);
            return;
        }
        ((TObjEneSlimeOne *)ene_slime_one)->set_state(6);
    }
}

void enter_slime_state__10TObjPlayerFPv(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 0x394) = 8;
    ((TObjEneSlimeOne *)(*(s32 *)((s8 *)arg0 + 0x388)))->set_motion_state((s32)((void*)(9)));
    ((s32 (*)(s32, void *, s32, s32))play_sound_effect)(0x4003AD1D, arg0 + 0x38, 0, 0);
    ((int (*)(void*, int))set_display_mode__15TObjEneSlimeOneFPvi)(arg0, 1);
}

#pragma push
#pragma fp_contract on
#pragma fp_contract on
void TObjPlayer__sub_800EA364(u8 *ene_slime_one) {
    Vec_800EA364 sp8;
    f32 s;
    f32 c;
    f32 t;
    f32 d;
    s32 i;
    s32 ang;
    ((TObjEneSlimeOne *)ene_slime_one)->rotation_y += 0x100;
    if (((TObjEneSlimeOne *)ene_slime_one)->m_398 > lbl_805DA6B4) {
        *(s32 *)((s8 *)ene_slime_one + 0x39C) += 0xC00;
        d = 0.25f * (0.5f * (0.5f + sin_table_lookup(*(s32 *)((s8 *)ene_slime_one + 0x39C))));
        t = *(f32 *)((s8 *)ene_slime_one + 0x3B4) + d;
        *(f32 *)((s8 *)ene_slime_one + 0x3B4) = t;
        if (t > 2.5f) {
            *(f32 *)((s8 *)ene_slime_one + 0x3B4) = 2.5f;
        }
    } else {
        t = *(f32 *)((s8 *)ene_slime_one + 0x3B4) - lbl_805DA734;
        *(f32 *)((s8 *)ene_slime_one + 0x3B4) = t;
        if (t < lbl_805DA6B4) {
            *(f32 *)((s8 *)ene_slime_one + 0x3B4) = lbl_805DA6B4;
        }
    }
    ((TObjEneSlimeOne *)ene_slime_one)->m_398 -= *(f32 *)((s8 *)ene_slime_one + 0x3B4);
    VecCopy((Vec *)(ene_slime_one + 0x44), (const Vec *)(ene_slime_one + 0x38));
    for (i = 1; i < 15; i++) {
        *(f32 *)((s8 *)ene_slime_one + 0x38) += *(f32 *)((s8 *)ene_slime_one + 0x3B4) * ((TObjEneSlimeOne *)ene_slime_one)->m_3b8;
        *(f32 *)((s8 *)ene_slime_one + 0x3C) += *(f32 *)((s8 *)ene_slime_one + 0x3B4) * *(f32 *)((s8 *)ene_slime_one + 0x3BC);
        *(f32 *)((s8 *)ene_slime_one + 0x40) += *(f32 *)((s8 *)ene_slime_one + 0x3B4) * ((TObjEneSlimeOne *)ene_slime_one)->m_3c0;
        if (TObjEneSlimeOne__sub_800EAD84((Obj_800EAD84 *)(ene_slime_one)) != 0 && csnLookAt(ene_slime_one + 0x44, ene_slime_one + 0x38) == 0) {
            break;
        }
        ang = i << 12;
        if (i & 1) {
            ang *= -1;
        }
        s = sin_table_lookup(ang);
        c = cos_table_lookup(ang);
        ((TObjEneSlimeOne *)ene_slime_one)->m_3b8 = c * ((TObjEneSlimeOne *)ene_slime_one)->m_3b8 - s * ((TObjEneSlimeOne *)ene_slime_one)->m_3c0;
        ((TObjEneSlimeOne *)ene_slime_one)->m_3c0 = s * ((TObjEneSlimeOne *)ene_slime_one)->m_3b8 + c * ((TObjEneSlimeOne *)ene_slime_one)->m_3c0;
        VecCopy((Vec *)(ene_slime_one + 0x38), (const Vec *)(ene_slime_one + 0x44));
    }
    if (((TObjEneSlimeOne *)ene_slime_one)->m_398 <= lbl_805DA6B4 && lbl_805DA6B4 == *(f32 *)((s8 *)ene_slime_one + 0x3B4)) {
        if (find_nearest_visible_player(ene_slime_one, &sp8, lbl_805DA720) != 0xFFFF && vector_length(&sp8) > lbl_805DA6E0) {
            ((TObjEneSlimeOne *)ene_slime_one)->set_state(4);
        } else {
            ((TObjEneSlimeOne *)ene_slime_one)->set_state(3);
        }
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
#pragma fp_contract on
void TObjPlayer__sub_800EA56C(u8 *actor) {
    s32 temp_r31;
    *(f32 *)((s8 *)actor + 0x3B4) = (f32) (*(const f32 *)&lbl_805DA6B4);
    if (find_nearest_visible_player(actor, actor + 0x3B8, lbl_805DA6DC) == 0xFFFF) {
        ((TObjEneSlimeOne *)actor)->set_state(2);
        return;
    }
    temp_r31 = (s32) (lbl_805DA738 * calc_boss4_scale__10TObjPlayerFi(actor));
    *(f32 *)((s8 *)actor + 0x3B8) = (f32) ((lbl_805DA6E0 * sin_table_lookup(temp_r31)) + *(f32 *)((s8 *)actor + 0x3B8));
    *(f32 *)((s8 *)actor + 0x3C0) = (f32) ((lbl_805DA6E0 * cos_table_lookup(temp_r31)) + *(f32 *)((s8 *)actor + 0x3C0));
    if (vector_length(actor + 0x3B8) <= lbl_805DA718) {
        ((TObjEneSlimeOne *)actor)->set_state(2);
        return;
    }
    ((s32 (*)(void *))normalize_vector)(actor + 0x3B8);
    *(f32 *)((s8 *)actor + 0x398) = ((lbl_805DA6E4 * calc_boss4_scale__10TObjPlayerFi(actor)) + lbl_805DA720);
    *(f32 *)((s8 *)actor + 0x3A0) = (f32) (*(const f32 *)&lbl_805DA67C);
    ((TObjEneSlimeOne *)((void *) *(s32 *)((s8 *)actor + 0x388)))->set_motion_state((s32)((void *) 8));
    ((int (*)(void*, int))set_display_mode__15TObjEneSlimeOneFPvi)(actor, 1);
}
#pragma pop

#pragma push
#pragma fp_contract on
void TObjPlayer__sub_800EA678(u8 *ene_slime_one) {
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f1_4;
    f32 var_f31;
    var_f31 = (*(const f32 *)&lbl_805DA67C);
    *(f32 *)((s8 *)ene_slime_one + 0x3A4) = (f32) (lbl_805DA708 * ((*(const f32 *)&lbl_805DA67C) - ((TObjEneSlimeOne *)ene_slime_one)->m_398));
    *(f32 *)((s8 *)ene_slime_one + 0x3A8) = (f32) ((((TObjEneSlimeOne *)ene_slime_one)->m_398 * (*(f32 *)((s8 *)&lbl_8043D23C.value + 0) - *(f32 *)((s8 *)&lbl_8043D230.value + 0))) + *(f32 *)((s8 *)&lbl_8043D230.value + 0));
    *(f32 *)((s8 *)ene_slime_one + 0x3AC) = (f32) ((((TObjEneSlimeOne *)ene_slime_one)->m_398 * (*(f32 *)((s8 *)&lbl_8043D23C.value + 4) - *(f32 *)((s8 *)&lbl_8043D230.value + 4))) + *(f32 *)((s8 *)&lbl_8043D230.value + 4));
    ((TObjEneSlimeOne *)ene_slime_one)->m_3b0 = (f32) ((((TObjEneSlimeOne *)ene_slime_one)->m_398 * (*(f32 *)((s8 *)&lbl_8043D23C.value + 8) - *(f32 *)((s8 *)&lbl_8043D230.value + 8))) + *(f32 *)((s8 *)&lbl_8043D230.value + 8));
    temp_f1 = ((TObjEneSlimeOne *)ene_slime_one)->m_398;
    if (temp_f1 > lbl_805DA740) {
        var_f31 = ((*(const f32 *)&lbl_805DA67C) - temp_f1) / lbl_805DA73C;
    }
    temp_f1_2 = var_f31 * (lbl_805DA744 * sin_table_lookup(((TObjEneSlimeOne *)ene_slime_one)->m_390 << 0xA));
    *(f32 *)((s8 *)ene_slime_one + 0x3A8) = (f32) (*(f32 *)((s8 *)ene_slime_one + 0x3A8) * ((*(const f32 *)&lbl_805DA67C) + temp_f1_2));
    ((TObjEneSlimeOne *)ene_slime_one)->m_3b0 = (f32) (((TObjEneSlimeOne *)ene_slime_one)->m_3b0 * ((*(const f32 *)&lbl_805DA67C) - temp_f1_2));
    ((TObjEneSlimeOne *)ene_slime_one)->m_390 = (s32) (((TObjEneSlimeOne *)ene_slime_one)->m_390 + 1);
    temp_f1_3 = ((TObjEneSlimeOne *)ene_slime_one)->m_398;
    if (temp_f1_3 >= (*(const f32 *)&lbl_805DA678)) {
        ((TObjEneSlimeOne *)ene_slime_one)->m_3a0 = (f32) (*(const f32 *)&lbl_805DA67C);
    } else {
        ((TObjEneSlimeOne *)ene_slime_one)->m_3a0 = (f32) (lbl_805DA748 * temp_f1_3);
    }
    temp_f1_4 = ((TObjEneSlimeOne *)ene_slime_one)->m_398 + lbl_805DA74C;
    ((TObjEneSlimeOne *)ene_slime_one)->m_398 = temp_f1_4;
    if (temp_f1_4 < (*(const f32 *)&lbl_805DA6B4)) {
        ((TObjEneSlimeOne *)ene_slime_one)->set_state(0);
    }
}
#pragma pop

void init_slime_display__10TObjPlayerFPv(void* a0) { *(float*)((char*)a0 + 0x398) = lbl_805DA67C; *(float*)((char*)a0 + 0x3a4) = lbl_805DA6B4; ((int (*)(void*, int))set_display_mode__15TObjEneSlimeOneFPvi)(a0, 0); ((TObjEneSlimeOne *)(*(int*)((char*)a0 + 0x388)))->set_motion_state((s32)((void*)((void*)7))); }

#pragma push
#pragma fp_contract on
void TObjPlayer__sub_800EA820(u8 *ene_slime_one) {
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f1_4;
    f32 var_f31;
    var_f31 = (*(const f32 *)&lbl_805DA67C);
    *(f32 *)((s8 *)ene_slime_one + 0x3A4) = (f32) (lbl_805DA708 * ((*(const f32 *)&lbl_805DA67C) - ((TObjEneSlimeOne *)ene_slime_one)->m_398));
    *(f32 *)((s8 *)ene_slime_one + 0x3A8) = (f32) ((((TObjEneSlimeOne *)ene_slime_one)->m_398 * (*(f32 *)((s8 *)&lbl_8043D23C.value + 0) - *(f32 *)((s8 *)&lbl_8043D230.value + 0))) + *(f32 *)((s8 *)&lbl_8043D230.value + 0));
    *(f32 *)((s8 *)ene_slime_one + 0x3AC) = (f32) ((((TObjEneSlimeOne *)ene_slime_one)->m_398 * (*(f32 *)((s8 *)&lbl_8043D23C.value + 4) - *(f32 *)((s8 *)&lbl_8043D230.value + 4))) + *(f32 *)((s8 *)&lbl_8043D230.value + 4));
    ((TObjEneSlimeOne *)ene_slime_one)->m_3b0 = (f32) ((((TObjEneSlimeOne *)ene_slime_one)->m_398 * (*(f32 *)((s8 *)&lbl_8043D23C.value + 8) - *(f32 *)((s8 *)&lbl_8043D230.value + 8))) + *(f32 *)((s8 *)&lbl_8043D230.value + 8));
    temp_f1 = ((TObjEneSlimeOne *)ene_slime_one)->m_398;
    if (temp_f1 > lbl_805DA740) {
        var_f31 = ((*(const f32 *)&lbl_805DA67C) - temp_f1) / lbl_805DA73C;
    }
    temp_f1_2 = var_f31 * (lbl_805DA670 * sin_table_lookup(((TObjEneSlimeOne *)ene_slime_one)->m_390 << 0xC));
    *(f32 *)((s8 *)ene_slime_one + 0x3A8) = (f32) (*(f32 *)((s8 *)ene_slime_one + 0x3A8) * ((*(const f32 *)&lbl_805DA67C) + temp_f1_2));
    ((TObjEneSlimeOne *)ene_slime_one)->m_3b0 = (f32) (((TObjEneSlimeOne *)ene_slime_one)->m_3b0 * ((*(const f32 *)&lbl_805DA67C) - temp_f1_2));
    ((TObjEneSlimeOne *)ene_slime_one)->m_390 = (s32) (((TObjEneSlimeOne *)ene_slime_one)->m_390 + 1);
    temp_f1_3 = ((TObjEneSlimeOne *)ene_slime_one)->m_398;
    if (temp_f1_3 >= (*(const f32 *)&lbl_805DA678)) {
        ((TObjEneSlimeOne *)ene_slime_one)->m_3a0 = (f32) (*(const f32 *)&lbl_805DA67C);
    } else {
        ((TObjEneSlimeOne *)ene_slime_one)->m_3a0 = (f32) (lbl_805DA748 * temp_f1_3);
    }
    temp_f1_4 = ((TObjEneSlimeOne *)ene_slime_one)->m_398 + lbl_805DA750;
    ((TObjEneSlimeOne *)ene_slime_one)->m_398 = temp_f1_4;
    if (temp_f1_4 > (*(const f32 *)&lbl_805DA67C)) {
        if (find_nearest_visible_player(ene_slime_one, 0, lbl_805DA6DC) != 0xFFFF) {
            ((TObjEneSlimeOne *)ene_slime_one)->set_state(3);
        } else {
            ((TObjEneSlimeOne *)ene_slime_one)->set_state(2);
        }
    }
}
#pragma pop

void reset_display__15TObjEneSlimeOneFPv(void* a0) { set_display_mode__15TObjEneSlimeOneFPvi(a0, (s32)((void*)(0))); ((TObjEneSlimeOne *)a0)->actorFlags = (((TObjEneSlimeOne *)a0)->actorFlags & 0xfffbffff); ((TObjEneSlimeOne *)a0)->m_398 = lbl_805DA6B4; *(float*)((char*)a0 + 0x3a4) = lbl_805DA708; }

void update_wait_search__15TObjEneSlimeOneFPv(TObjEneSlimeOne *ene_slime_one) {
    s32 temp_r0;
    s32 temp_r0_2;

    temp_r0 = ene_slime_one->m_390 - 1;
    ene_slime_one->m_390 = temp_r0;
    if (temp_r0 <= 0) {
        if (((u16 (*)(void *, s32, f32))find_nearest_visible_player)(ene_slime_one, 0, (*(f32 *)&lbl_805DA6DC)) == 0xFFFF) {
            temp_r0_2 = ene_slime_one->m_3c8 + 1;
            ene_slime_one->m_3c8 = temp_r0_2;
            if (temp_r0_2 >= 5) {
                *(f32 *)((s8 *)ene_slime_one + 0x38) = (f32) *(f32 *)((s8 *)ene_slime_one + 0x50);
                *(f32 *)((s8 *)ene_slime_one + 0x40) = (f32) *(f32 *)((s8 *)ene_slime_one + 0x58);
                ene_slime_one->m_3c8 = 5;
            }
            ene_slime_one->set_random_timer_15();
            return;
        }
        ene_slime_one->set_state((s32)((void*)(1)));
    }
}

void init_state__15TObjEneSlimeOneFPv(void* a0) { ((int (*)(void))TObjEneSlimeOne__sub_800EAD84)(); *(float*)((char*)a0 + 0x3a4) = lbl_805DA708; ((TObjEneSlimeOne *)a0)->m_3b0 = lbl_805DA6B4; *(float*)((char*)a0 + 0x3ac) = lbl_805DA6B4; *(float*)((char*)a0 + 0x3a8) = lbl_805DA6B4; ((TObjEneSlimeOne *)a0)->m_3a0 = lbl_805DA6B4; ((TObjEneSlimeOne *)a0)->m_3c8 = 0; ((TObjEneSlimeOne *)(((TObjEneSlimeOne *)a0)->m_388))->set_motion_state((s32)((void*)7)); set_display_mode__15TObjEneSlimeOneFPvi(a0, (s32)((void*)((void*)0))); ((TObjEneSlimeOne *)a0)->actorFlags = (((TObjEneSlimeOne *)a0)->actorFlags | 0x40000); ((TObjEneSlimeOne *)a0)->set_random_timer_15(); }

void TObjEneSlimeOne::set_random_timer_15() { set_random_timer__15TObjEneSlimeOneFPvii(this, 15, 15); }

void TObjEneSlimeOne::vfunc_61() {
    u8 *arg0 = (u8 *)this;
    if ((s32) this->m_384 != 0xB) {
        this->actorFlags = (s32) (this->actorFlags & 0xFFFFFEFF);
        ((TObjEneSlimeOne *)arg0)->set_state((s32)((void*)(0xB)));
    }
}

void TObjEneSlimeOne::vfunc_62() {
    u8 *arg0 = (u8 *)this;
    if ((s32) this->m_384 != 0xC) {
        if (((s32) this->m_2d4 < (s32) lbl_805D586C) && (((u32 (*)(void))get_player_by_client_id)() != 0U) && (check_player_field_7cc__15TObjEneSlimeOneFv() == 2) && ((u32) this->m_3f0 != 0U) && (((TObject *)((void *) this->m_3f0))->all_parents_unqueued_for_destruction() != 0)) {
            ((TObjEneSlimeOne *)(this->m_3f0))->try_spawn_child((u8 *)&this->position);
        }
        this->actorFlags = (s32) (this->actorFlags & 0xFFFFFDFF);
        ((TObjEneSlimeOne *)arg0)->set_state((s32)((void*)(0xC)));
    }
}

void TObjEneSlimeOne::vfunc_63() { if (*(int *)&this->m_384 != 13) { set_state((s32)((void*)((void*)13))); } }

void TObjEneSlimeOne::clear_child_flag() {
    void *temp_r3;

    if ((s32) this->m_3ec == 0) {
        temp_r3 = *(void **)((s8 *)this + 0x38C);
        *(s32 *)((s8 *)temp_r3 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r3 + 0x18) & 0xFFFFFFFE);
    }
}

void TObjEneSlimeOne::set_target_flag_bit0() {
    void *temp_r3;

    temp_r3 = *(void **)((s8 *)this + 0x38C);
    *(s32 *)((s8 *)temp_r3 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r3 + 0x18) | 1);
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

#pragma push
#pragma fp_contract on
s32 TObjEneSlimeOne__sub_800EAD84(Obj_800EAD84 *arg0) {
    Vec_800EAD84 sp = arg0->pos;
    sp.y = sp.y + lbl_805DA6AC;
    if (project_actor_to_ground(arg0, &sp, 0) != 0) {
        arg0->pos.y += 0.5f * (sp.y - arg0->pos.y);
        return 1;
    }
    return 0;
}
#pragma pop

void set_random_timer__15TObjEneSlimeOneFPvii(void *arg0, s32 arg1, s32 arg2) {
    *(s32 *)((s8 *)arg0 + 0x390) = (s32) (arg1 + (s32) ((f32) arg2 * ((f32 (*)(void))calc_boss4_scale__10TObjPlayerFi)()));
}

void TObjEneSlimeOne::set_state(s32 arg1) {
    ((TSlime_800EAE78 *)this)->state = arg1;
    Action_800EAE78 a = lbl_80496574[((TSlime_800EAE78 *)this)->state].fn;
    if (a != 0) {}
    (((TSlime_800EAE78 *)this)->*a)();
}

struct Bomb_800E9090;
void render__15TObjEneSlimeOneFv(TObjEneSlimeOne *ene_slime_one) {
    s32 temp_r31;
    if ((TObjPlayer::check_demo_mode() == 0) && !(ene_slime_one->m_3a0 <= lbl_805DA6B4) && (((VObj_18_26a62c *)(ene_slime_one))->m8(lbl_805DA728, lbl_805DA6E4) != 0)) {
        temp_r31 = defer_render__7TObjectFv(ene_slime_one);
        if (ene_slime_one->m_3a0 < lbl_805DA67C) {
            TObjPlayer__sub_800EBE48(ene_slime_one->m_3a0);
        }
        TObjPlayer::toggle_particle_effect();
        push_matrix();
        {
            Vec_800EAEE8 v = *(Vec_800EAEE8 *)((u8 *)ene_slime_one + 0x38);
            v.y += *(f32 *)((s8 *)ene_slime_one + 0x3A4);
            post_translate_matrix(&v);
        }
        rotate_matrix_y(0, ene_slime_one->rotation_y);
        scale_matrix_vec3(0, ((u8 *)ene_slime_one + 0x3A8));
        ((TObjEneSlimeOne *)(ene_slime_one->m_388))->draw_part(temp_r31);
        pop_matrix();
        TParticleCtrl::end_effect_render();
        if (ene_slime_one->m_3a0 < lbl_805DA67C) {
            TObjPlayer::init_render_globals();
        }
        ene_slime_one->sub_800E9090();
    }
}

void TObjEneSlimeOne::run_task() {
    if (TObjPlayer::check_demo_mode() == 0) {
        if ((s32)this->m_384 != 13 && (this->m_3f0 == 0 || ((TObject *)this->m_3f0)->all_parents_unqueued_for_destruction() == 0)) {
            set_state(13);
        }
        set_target_flag_bit0();
        {
            Ent_800EAE78 *tbl = lbl_80496574;
            Action_800EAE78 a = tbl[((TSlime_800EAE78 *)this)->state].update;
            if (a != 0) {}
            (((TSlime_800EAE78 *)this)->*a)();
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
        if ((s32)this->m_384 != 13) {
            minimap_render_dot((u8 *)this + 0x2FC, -0x5DB4, 1, 0);
        }
    }
}

void *__dt__15TObjEneSlimeOneFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__15TObjEneSlimeOne;
        free_collision_body_parts(arg0);
        *(s32 *)((s8 *)arg0 + 0x38C) = 0;
        if (((TObjEneSlimeOne *)arg0)->m_3e8 != NULL) { TBoss4Type2::request_destroy((u32)(((TObjEneSlimeOne *)arg0)->m_3e8)); *(s32 *)((s8 *)arg0 + 0x3E8) = 0; }
        __dt__15TObjEneSlimeOneFis((s32)(*(void **)((s8 *)arg0 + 0x388)), 1);
        ((TObjEneSlimeOne *)arg0)->m_388 = 0;
        __dt__9TObjEnemyFv((TObjEnemy *)arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

void TObjEneSlimeOne::initialize_slime_instance_state() {
  void *p;
  s32 id;
  s32 *new_var2;
  u8 *new_var;
    u8 *actor = (u8 *)this;
  ((TObjEneSlimeOne *)actor)->m_380 = get_instance__15TObjEneSlimeOneFv();
  if ((calc_boss4_scale__10TObjPlayerFi(actor) < lbl_805DA754) || ((((TObjEneSlimeOne *)actor)->state36C) & 1))
  {
    *((s32 *) (((s8 *) actor) + 0x3F4)) = 1;
  }
  else
  {
    *((s32 *) (((s8 *) actor) + 0x3F4)) = 0;
  }
  new_var2 = &(*((s32 *) (((s8 *) actor) + 0x3F4)));
  id = ((s32 *) lbl_804966DC)[*new_var2];
  ((TObjEneSlimeOne *)actor)->texlist = TObjFish__sub_8001EDB0((s32)(((TObjEneSlimeOne *)actor)->m_380), id);
  *((s32 *) (((s8 *) actor) + 0x34)) = get_bml_model((s32)(((TObjEneSlimeOne *)actor)->m_380), id);
  VecCopy((Vec *)(actor + 0x44), (const Vec *)((u8 *)VecCopy((Vec *)(actor + 0x50), (const Vec *)((void *)VecCopy((Vec *)(actor + 0x74), (const Vec *)(actor + 0x38))))));
  *((s32 *) (((s8 *) actor) + 0x38C)) = init_collision_body_parts(actor, lbl_80496370, 1);
  ((TObjMotion *)actor)->set_field_d8((s32)lbl_8049639C);
  ((TObjMotion *)actor)->set_field_dc(*((s32 *) (((s8 *) (((TObjEneSlimeOne *)actor)->m_380)) + 0x430)));
  ((TObjMotion *)actor)->set_animation(0);
  ((TObjMotion *)actor)->set_field_b8(0);
  VecCopy((Vec *)(new_var = actor + 0x2FC), (const Vec *)(actor + 0x38));
  ((TObjEneSlimeOne *)actor)->m_310 = lbl_805DA6B4;
  *((f32 *) (((s8 *) actor) + 0x30C)) = lbl_805DA6B4;
  *((f32 *) (((s8 *) actor) + 0x308)) = lbl_805DA6B4;
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
    p = (void *) fn_800ECA28(p, actor);
  }
  *((void **) (((s8 *) actor) + 0x388)) = p;
  *((s32 *) (((s8 *) actor) + 0x3E8)) = 0;
  ((TObjEneSlimeOne *)actor)->m_3cc = 0xFFFF;
  ((TObjEneSlimeOne *)actor)->copy_position();
}

u8 *TObjEneSlimeOne__ct(u8 *actor, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    typedef char sp8_offset[(offsetof(Stack_800EB3D4, sp8) == 0x0) ? 1 : -1];
    typedef char spE_offset[(offsetof(Stack_800EB3D4, spE) == 0x6) ? 1 : -1];
    Stack_800EB3D4 stack;
    __ct__9TObjEnemyFP7TObject(actor);
    *(s32 **)((s8 *)actor + 0x18) = &(*(RecoveredGlobal_800EB3D4___vt__15TObjEneSlimeOne *)&__vt__15TObjEneSlimeOne).value;
    *(s32 *)((s8 *)actor + 0) = (s32) TObjEneSlimeOne_class_name;
    ((TUnk_804806E8 *)actor)->add_flags_2e4(2);
    ((TObjEneSlimeOne *)(actor))->apply_set_data((void *)arg3);
    if (exchange_object_state__9TObjEnemyFls(actor, &stack.sp8, 1) != 0) {
        stack.sp8 = 0;
        stack.spE = 0;
        exchange_object_state__9TObjEnemyFls(actor, &stack.sp8, 0);
    }
    ((TObjEneSlimeOne *)actor)->m_3f0 = arg2;
    VecCopy((Vec *)(actor + 0x3DC), (const Vec *)(arg4));
    ((TObjEneSlimeOne *)actor)->initialize_slime_instance_state();
    ((TObjEneSlimeOne *)actor)->set_state((s32)((void*)(0xE)));
    return actor;
}

u8 *init__15TObjEneSlimeOneFPviii(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    typedef char sp8_offset[(offsetof(Stack_800EB4A0, sp8) == 0x0) ? 1 : -1];
    typedef char spE_offset[(offsetof(Stack_800EB4A0, spE) == 0x6) ? 1 : -1];
    Stack_800EB4A0 stack;
    __ct__9TObjEnemyFP7TObject(arg0);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_800EB4A0___vt__15TObjEneSlimeOne *)&__vt__15TObjEneSlimeOne).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TObjEneSlimeOne_class_name;
    ((TUnk_804806E8 *)arg0)->add_flags_2e4(2);
    ((TObjEneSlimeOne *)(arg0))->apply_set_data((void *)arg3);
    if (exchange_object_state__9TObjEnemyFls(arg0, &stack.sp8, 1) != 0) {
        stack.sp8 = 0;
        stack.spE = 0;
        exchange_object_state__9TObjEnemyFls(arg0, &stack.sp8, 0);
    }
    ((TObjEneSlimeOne *)arg0)->m_3f0 = arg2;
    ((TObjEneSlimeOne *)arg0)->initialize_slime_instance_state();
    project_actor_to_ground(arg0, arg0 + 0x38, 0);
    ((TObjEneSlimeOne *)arg0)->set_state((s32)((void*)(0)));
    return arg0;
}

s32 TObjEneSlimeOne::create(s32 arg0, s32 arg1, s32 arg2) {
    s32 actor;
    s32 var_r4;

    actor = ((s32 (*)(s32))__nw__7TObjectFUl)(0x3F8);
    if (actor != 0) {
        var_r4 = ((s32 (*)(s32))__nw__7TObjectFUl)(0x20);
        if (var_r4 != 0) {
            var_r4 = ((s32 (*)(s32, s32))TObjControl__ct)(var_r4, tl_04);
        }
        actor = ((s32)TObjEneSlimeOne__ct((u8 *)actor, (s32)var_r4, (s32)arg0, (s32)arg1, (s32)arg2));
    }
    return actor;
}

s32 TObjEneSlimeOne::create(s32 arg0, s32 arg1) {
    s32 var_r31;
    s32 var_r4;

    var_r31 = ((s32 (*)(s32))__nw__7TObjectFUl)(0x3F8);
    if (var_r31 != 0) {
        var_r4 = ((s32 (*)(s32))__nw__7TObjectFUl)(0x20);
        if (var_r4 != 0) {
            var_r4 = ((s32 (*)(s32, s32))TObjControl__ct)(var_r4, tl_04);
        }
        var_r31 = ((s32)init__15TObjEneSlimeOneFPviii((u8 *)var_r31, (s32)var_r4, (s32)arg0, (s32)arg1));
    }
    return var_r31;
}
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
    pos.y += lbl_805DA66C;
    ang = (s16) (lbl_805DA758 * ((f32 (*)(int)) calc_boss4_scale__10TObjPlayerFi)(origin));
    dir.x = sin_table_lookup(ang);
    dir.y = lbl_805DA6B4;
    dir.z = cos_table_lookup(ang);
    if (vector_length(&dir) <= lbl_805DA718) {
        dir.x = 1.0f;
        dir.y = 0.0f;
        dir.z = 0.0f;
    } else {
        normalize_vector(&dir);
    }
    play_sound_effect(0x4003A619, &pos, 0, 0);
    return spawn_slime_in_slot((void *) origin, i, &pos, &dir);
}
