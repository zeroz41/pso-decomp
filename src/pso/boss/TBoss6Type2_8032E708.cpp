#include "types.h"
#include "pso/misc/TLobby.h"
#include "pso/boss/TBoss6Mag.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TUnk_804806E8.h"
#include "pso/enemy/TObjEnemy.h"
extern "C" void has_flag_0x800__13TUnk_804806E8Fv();
extern "C" void test_flag30_512__13TUnk_804806E8Fv();
extern "C" void test_flag_1000__13TUnk_804806E8Fv();
extern "C" void test_flag_256__13TUnk_804806E8Fv();
#include "pso/system/vector.h"
#include "pso/boss/TBoss6Rock.h"
#include "pso/boss/TBoss6Type2.h"

struct Stack_8032EAE4
{
  f32 sp8;
  f32 spC;
  f32 sp10;
};

struct Stack_8032FE50 {
    s32 sp8;
    s32 spC;
    f32 sp10;
    f32 sp14;
};

struct RecoveredGlobal_803300C8_lbl_80477404 {
    s32 value;
    u8 remaining[0x20];
};

struct RecoveredGlobal_803300C8_lbl_80477428 {
    s32 value;
    u8 remaining[0x18];
};

struct Ent_8032FFC0 { s32 a; s32 next; s32 c; f32 d; };
struct Anim_8032FFC0 { s32 a; u32 count; };

struct O_8032FFC0 {
    u8 pad[0x3D4];
    s32 f3d4;
    s32 mode;
    Anim_8032FFC0 *anim;
    f32 t;
    f32 speed;
    f32 f3e8;
    f32 f3ec;
};

struct RecoveredGlobal_803300C8_lbl_804EDD94 {
    s32 value;
    u8 remaining[0x4C];
};

struct RecoveredGlobal_8032FF24_lbl_804EDD94 {
    s32 value;
    u8 remaining[0x4C];
};

struct RecoveredFields_8032F174_arg0
{
  u8 unknown_0[0x3C];
  f32 field_3C;
  u8 unknown_40[0x340];
  s32 field_380;
  u8 unknown_384[0x84];
  u16 field_408;
};

#include "pso/object/TObjFish.h"

#include "pso/TParticleCtrl.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/boss/TBoss6PlotFalz.h"
#include "pso/enemy/TObjEneLappy.h"

#include "pso/misc/TNowLoading.h"
union MemberActionStorage_803301B8 { s32 words[3]; void (TBoss6Type2::*action)(); };

struct RecoveredGlobal_803301B8_lbl_804EF028 {
    s32 value;
    u8 remaining[0xD4];
};

struct T_8032E748 { u8 pad[0x380]; s32 phase; };

struct T_8032EA10 { u8 pad[0x43C]; s32 arr[4]; };

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct In_80330178 { s32 w[7]; };

struct S_80330178 { s32 a; s32 b; In_80330178 c; };

struct T_8032F2C4 { u8 pad[0x3B8]; f32 v[2]; };

struct V3_8032E7B4 { s32 x; s32 y; s32 z; };

struct O_8032E7B4 { u8 pad[0x38]; V3_8032E7B4 pos; u8 pad2[0x43C - 0x44]; u32 arr[4]; };

struct E_8032E7B4 { s32 a; s32 b; };

struct V3_8032F304 { f32 x; f32 y; f32 z; };

struct O_8032F304 { u8 pad[0x414]; s32 n; V3_8032F304 v[4]; s32 pad2; u8 mine[1]; };

struct V3_8032F360 { f32 x; f32 y; f32 z; };

struct O_8032F360 { u8 pad[0x410]; s32 z; s32 n; V3_8032F360 v[3]; };

struct V3_8032FB84 { f32 x; f32 y; f32 z; };

struct O_8032FB84 { u8 pad[0x38]; V3_8032FB84 pos; u8 pad2[0x60 - 0x44]; s32 f60; u8 pad3[0x378 - 0x64]; void *p378; u8 pad4[0x384 - 0x37C]; s32 f384; };

struct V3_8032E834 { f32 x; f32 y; f32 z; };

struct E_8032E834 { s32 a; s32 b; };

struct O_8032E834 { u8 pad[0x38]; V3_8032E834 pos; u8 pad2[0x43C - 0x44]; u32 h[4]; V3_8032E834 v[4]; };

struct V3_8032F5FC { f32 x; f32 y; f32 z; };

struct O_8032F5FC { u8 pad[0x38]; V3_8032F5FC pos; u8 pad2[0x5C - 0x44]; s32 f5c; s32 f60; u8 pad3[0x378 - 0x64]; s32 f378; u8 pad4[0x3C4 - 0x37C]; f32 f3c4; };

struct Vec_8032EF34 { f32 x, y, z; };

struct Ent_8032FCA4 { s16 f0; s16 v[5]; };

struct Obj_8032FCA4 { u8 pad[0x31C]; Ent_8032FCA4 *ent; u8 pad2[0x394 - 0x320]; u8 local[0x20]; s16 max; s16 min; };

struct T_8032E748;
struct O_8032E7B4;
struct Obj_8032E8DC { u8 pad[0x38]; u8 sw[0x340]; s32 f378; u8 pad2[0x3C8 - 0x37C]; s32 f3C8; };

struct V3_8032EBB4 { f32 x; f32 y; f32 z; };

struct O_8032EBB4 { u8 pad[0x38]; V3_8032EBB4 pos; u8 pad2[0x378 - 0x44]; void *p378; };

struct V3_8032F034 { f32 x; f32 y; f32 z; };

struct O_8032F034 {
    u8 pad[0x60]; s32 f60;
    u8 pad2[0x3B8 - 0x64]; f32 f3b8;
    u8 pad3[0x408 - 0x3BC]; u16 f408;
    u8 pad4[0x44C - 0x40A]; V3_8032F034 home;
};

typedef struct Vec_8032ECE0 { f32 x; f32 y; f32 z; } Vec_8032ECE0;

typedef struct Vec_8032F690 { f32 x; f32 y; f32 z; } Vec_8032F690;

typedef struct Vec_8032F418 { f32 x; f32 y; f32 z; } Vec_8032F418;

struct Vec_8032EF34;
struct V3_8032F824 { f32 x; f32 y; f32 z; };

struct O_8032F824 {
    u8 pad[0x38];
    V3_8032F824 pos;
    u8 pad2[0x5C - 0x44];
    s32 f5c;
    s32 f60;
    u8 pad3[0x378 - 0x64];
    void *p378;
    u8 pad4[0x384 - 0x37C];
    s32 f384;
};

struct T_8033053C { u8 pad[4]; };
typedef void (T_8033053C::*Fn_8033053C)();
struct Ent_8033053C { u8 pad[0x18]; Fn_8033053C fn; };
#pragma readonly_strings on

const char *lbl_805D4220 = "TBoss6Mag";
extern const E_8032E7B4 TBoss6Type2__effect_emitter_id_table[4] = { {555, -1}, {556, -1}, {537, -1}, {542, 0} };
extern const u32 lbl_804773DC[8] = { 3, 0, 0, 0, 0xFFFFFFFF, 0, 0, 0 };
extern const u32 lbl_804773FC[2] = { 0xFFFF0000, 1 };
extern const RecoveredGlobal_803300C8_lbl_80477404 boss6_type2_zero_vec3_block = { 0 };
extern const RecoveredGlobal_803300C8_lbl_80477428 boss6_type2_initial_state = { 0, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x3D, 0x88, 0x88, 0x89 } };
extern const s32 lbl_80477444[3] = { -0x2000, 0, 0x2000 };
extern const char lbl_80477450[8] = { 0 };
struct P_80330240 { s32 a; s32 b; };
struct O_80330240 { u8 pad[0x388]; s32 f388; };
extern "C" {
void *fn_8033068C(void *arg0, s16 arg1);
void run_task__9TBoss6MagFv(u8 *arg0);
void render__9TBoss6MagFv(void* p);
f32 receive_physical_attack__9TBoss6MagFPvf(void *arg0);
f32 fn_80330240(O_80330240 *arg0, void *arg1, P_80330240 arg2, void *arg3, void *arg4, void *arg5);
void spawn_ground_effect__10TObjPlayerFPv(u8 *arg0);
void vfunc_63__9TBoss6MagFv(u8 *arg0);
void vfunc_6__13TUnk_804B9870FPsl();
void vfunc_29__13TUnk_804806E8Fv();
void recalc_stats__13TUnk_804806E8Fv();
void vfunc_28__13TUnk_804806E8Fv();
void consume_timer_field__13TUnk_804806E8Fl();
void vfunc_67__13TUnk_804806E8Ff();
void vfunc_66__13TUnk_804806E8Fv();
void get_anim_node_position__13TUnk_804806E8FlP3Vec();
void vfunc_61__13TUnk_804806E8Fv();
void vfunc_60__13TUnk_804806E8Fv();
void vfunc_59__13TUnk_804806E8Fv();
void vfunc_58__13TUnk_804806E8Fv();
void apply_slow_status__13TUnk_804806E8Fv();
void update_shock_clock__13TUnk_804806E8Fv();
void vfunc_43__13TUnk_804806E8Fv();
void vfunc_18__13TUnk_804806E8FPUc();
void interact__13TUnk_804AF8A0Fl();
void vfunc_74__9TObjEnemyFl();
void apply_hit_message_flags__9TObjEnemyFPv();
void add_actor_exp__13TUnk_804806E8Fl();
void apply_action_hold_status__13TUnk_804806E8Ff();
void apply_anti_technique__13TUnk_804806E8Fl();
void apply_attack_stat_status__13TUnk_804806E8FPv();
void apply_confusion_status__13TUnk_804806E8Fv();
void apply_knockback_from_attacker__13TUnk_804806E8FPUc();
void apply_movement_ailment__13TUnk_804806E8Fl();
void apply_object_set_data__13TUnk_804B9870FPv();
void apply_paralysis__13TUnk_804806E8Fv();
void apply_poison_status__13TUnk_804806E8Fv();
void apply_set_data__9TObjEnemyFPv();
void apply_shock_status__13TUnk_804806E8Fv();
void apply_switch_attack__13TUnk_804806E8Fv();
void calc_distance_accuracy_penalty__13TUnk_804806E8FPvPvPvf();
void vfunc_79__9TObjEnemyFv();
void classify_actor_view_detail__13TUnk_804B9870Ffff();
void clear_all_status_effects__13TUnk_804806E8Fv();
void clear_harmful_statuses__13TUnk_804806E8Fv();
void cure_paralysis__13TUnk_804806E8Fv();
void cure_poison_ailment__13TUnk_804806E8Fv();
void enemy_spawn_jellen_effect__13TUnk_804806E8Fv();
void enemy_spawn_zalure_effect__13TUnk_804806E8Fv();
void vfunc_78__13TUnk_804806E8Fl();
void vfunc_77__13TUnk_804806E8Fv();
void vfunc_76__13TUnk_804806E8Fv();
void vfunc_75__13TUnk_804806E8Ff();
void clear_lobby_object_state__9TObjEnemyFv();
void vfunc_9__13TUnk_804806E8Fv();
void get_actor_level_index__13TUnk_804806E8Fv();
void get_name__9TObjEnemyFv();
void get_pos__13TUnk_804806E8Fl();
void is_actor_cadence_frame__13TUnk_804806E8Fl();
void is_target_in_attack_range__13TUnk_804806E8Fv();
void receive_weapon_special_attack__13TUnk_804806E8FPvPv();
void apply_defense_stat_status__13TUnk_804806E8FPv();
void render_shadows__9TObjEnemyFv();
void reset_motion_fields__13TUnk_804806E8Fv();
void reset_pose__13TUnk_804806E8Fv();
void roll_physical_accuracy__13TUnk_804806E8FPvlf();
void select_melee_contact_body__13TUnk_804806E8FPvf();
void trigger_switch_attack__13TUnk_804806E8Fv(s32 arg0);
void try_start_action__13TUnk_804806E8Fll();
void update_action_hold_status__13TUnk_804806E8Fv();
s32 vfunc_37__13TUnk_804806E8Fv(u8 *player);
void update_actor_ground_y__13TUnk_804806E8Fv();
s32 update_attack_stat_status__13TUnk_804806E8Fv(u8 *player);
s32 update_defense_stat_status__13TUnk_804806E8Fv(u8 *player);
void update_flag30_timer__13TUnk_804806E8Fv();
void update_movement_status__13TUnk_804806E8Fv();
void update_object_view_visibility__13TUnk_804B9870Fff();
void update_poison_status__13TUnk_804806E8Fv();
void *TBoss6Mag__collision_body_parts[11] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x41f00000,
    (void *)0x0, (void *)0x0, (void *)0x807b, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
Ent_8032FFC0 boss6_type2_motion_table[5] = {
    {0x0, 0x0, 0x36, 0.8f},
    {0x0, 0x1, 0x31, 0.8f},
    {0x2, 0x3, 0x3, 0.4f},
    {0x0, 0x3, 0x32, 0.4f},
    {0x2, 0x0, 0xc, 0.5f},
};
__declspec(section ".data") void *TBoss6Type2__instance_slots[2] = {
    (void *)0x0, (void *)0x0,
};
void *lbl_804EDDEC[83] = {

    (void *)0x0, (void *)0x0, (void *)fn_8033068C, (void *)run_task__9TBoss6MagFv,
    (void *)render__9TBoss6MagFv, (void *)render_shadows__9TObjEnemyFv, (void *)vfunc_6__13TUnk_804B9870FPsl, (void *)apply_object_set_data__13TUnk_804B9870FPv,
    (void *)reset_motion_fields__13TUnk_804806E8Fv, (void *)vfunc_9__13TUnk_804806E8Fv, (void *)update_object_view_visibility__13TUnk_804B9870Fff, (void *)classify_actor_view_detail__13TUnk_804B9870Ffff,
    (void *)get_name__9TObjEnemyFv, (void *)interact__13TUnk_804AF8A0Fl, (void *)add_actor_exp__13TUnk_804806E8Fl, (void *)consume_timer_field__13TUnk_804806E8Fl,
    (void *)get_actor_level_index__13TUnk_804806E8Fv, (void *)update_actor_ground_y__13TUnk_804806E8Fv, (void *)vfunc_18__13TUnk_804806E8FPUc, (void *)is_actor_cadence_frame__13TUnk_804806E8Fl,
    (void *)select_melee_contact_body__13TUnk_804806E8FPvf, (void *)calc_distance_accuracy_penalty__13TUnk_804806E8FPvPvPvf, (void *)receive_physical_attack__9TBoss6MagFPvf, (void *)fn_80330240,
    (void *)receive_weapon_special_attack__13TUnk_804806E8FPvPv, (void *)apply_knockback_from_attacker__13TUnk_804806E8FPUc, (void *)try_start_action__13TUnk_804806E8Fll, (void *)roll_physical_accuracy__13TUnk_804806E8FPvlf,
    (void *)vfunc_28__13TUnk_804806E8Fv, (void *)vfunc_29__13TUnk_804806E8Fv, (void *)is_target_in_attack_range__13TUnk_804806E8Fv, (void *)&test_flag_256__13TUnk_804806E8Fv,
    (void *)&test_flag30_512__13TUnk_804806E8Fv, (void *)&has_flag_0x800__13TUnk_804806E8Fv, (void *)&test_flag_1000__13TUnk_804806E8Fv, (void *)update_poison_status__13TUnk_804806E8Fv,
    (void *)update_action_hold_status__13TUnk_804806E8Fv, (void *)vfunc_37__13TUnk_804806E8Fv, (void *)update_flag30_timer__13TUnk_804806E8Fv, (void *)update_movement_status__13TUnk_804806E8Fv,
    (void *)update_shock_clock__13TUnk_804806E8Fv, (void *)update_attack_stat_status__13TUnk_804806E8Fv, (void *)update_defense_stat_status__13TUnk_804806E8Fv, (void *)vfunc_43__13TUnk_804806E8Fv,
    (void *)apply_poison_status__13TUnk_804806E8Fv, (void *)apply_paralysis__13TUnk_804806E8Fv, (void *)apply_slow_status__13TUnk_804806E8Fv, (void *)apply_confusion_status__13TUnk_804806E8Fv,
    (void *)apply_movement_ailment__13TUnk_804806E8Fl, (void *)apply_shock_status__13TUnk_804806E8Fv, (void *)clear_harmful_statuses__13TUnk_804806E8Fv, (void *)apply_attack_stat_status__13TUnk_804806E8FPv,
    (void *)apply_defense_stat_status__13TUnk_804806E8FPv, (void *)cure_poison_ailment__13TUnk_804806E8Fv, (void *)cure_paralysis__13TUnk_804806E8Fv, (void *)clear_all_status_effects__13TUnk_804806E8Fv,
    (void *)apply_action_hold_status__13TUnk_804806E8Ff, (void *)apply_anti_technique__13TUnk_804806E8Fl, (void *)vfunc_58__13TUnk_804806E8Fv, (void *)vfunc_59__13TUnk_804806E8Fv,
    (void *)vfunc_60__13TUnk_804806E8Fv, (void *)vfunc_61__13TUnk_804806E8Fv, (void *)spawn_ground_effect__10TObjPlayerFPv, (void *)vfunc_63__9TBoss6MagFv,
    (void *)reset_pose__13TUnk_804806E8Fv, (void *)get_anim_node_position__13TUnk_804806E8FlP3Vec, (void *)vfunc_66__13TUnk_804806E8Fv, (void *)vfunc_67__13TUnk_804806E8Ff,
    (void *)get_pos__13TUnk_804806E8Fl, (void *)apply_switch_attack__13TUnk_804806E8Fv, (void *)enemy_spawn_jellen_effect__13TUnk_804806E8Fv, (void *)trigger_switch_attack__13TUnk_804806E8Fv,
    (void *)enemy_spawn_zalure_effect__13TUnk_804806E8Fv, (void *)recalc_stats__13TUnk_804806E8Fv, (void *)vfunc_74__9TObjEnemyFl, (void *)vfunc_75__13TUnk_804806E8Ff,
    (void *)vfunc_76__13TUnk_804806E8Fv, (void *)vfunc_77__13TUnk_804806E8Fv, (void *)vfunc_78__13TUnk_804806E8Fl, (void *)vfunc_79__9TObjEnemyFv,
    (void *)apply_hit_message_flags__9TObjEnemyFPv, (void *)apply_set_data__9TObjEnemyFPv, (void *)clear_lobby_object_state__9TObjEnemyFv,
};

f32 vec3_add_to(void *, int);
f32 vector_length(void *);
f32 subtract_vector(void *, int);
f32 normalize_vector(void *);
void TBoss6Type2__sub_8032F5C4(void *arg0);
s32 TObjFish__sub_8001EDB0(s32, s32);
s32 get_bml_model(s32, s32);
s32 clear_render_callback__8TObjFishFv(s32);
}
void draw_model_blend_motion(void *arg0, void *arg1, f32 farg0);
extern "C" {
void draw_model_motion(void *arg0, void *arg1, f32 farg0);
s32 get_bml_motion(int, int);

extern Ent_8032FFC0 boss6_type2_motion_table[];
void TBoss6Type2__sub_803300C8(u8 *arg0);
void update_all_parts__11TBoss6Type2FPv(s32 arg0);
extern Ent_8033053C boss6_type2_action_table[];
void TBoss6Type2__sub_8032EA10(T_8032EA10 *self);
int copy_vec3__11TBoss6Type2Fii(s32 _w0, s32 _w1);
extern void *TBoss6Type2__instance_slots[];
void TBoss6Type2__sub_8032F2F0(void* p, void* q);

void *create_particle_emitter(void *pos, s32 id);

void spawn_mag_mine_at__13TBoss6MagMineFPvPv(void *, void *);
void set_path_points__11TBoss6Type2FPvPvi(O_8032F360 *arg0, V3_8032F360 *arg1, s32 arg2);
void TBoss6Type2__sub_802BD378(void *, s32, void *, void *);
s32 TBoss6Type2__sub_8032FB84(O_8032FB84 *arg0);

s32 angle_difference_abs(s32, s32);
s32 TBoss6Type2__sub_8032EAB8(void *arg0, s32 arg1);
f32 atan2_float(f32, f32);
f32 TBoss5GryphonLightningWing__sub_80324CEC(f32);

s32 calc_dir_angles__11TBoss6Type2FPvPvPvPv(void *arg0, s32 *arg1, s32 *arg2, Vec_8032EF34 *arg3);
void *spawn_particle_effect_with_flags(void *pos, s32 id, s32 flags);
s32 is_active__11TBoss6Type2Fv(int);
u8 *get_player_by_client_id(s32);
f32 sin_table_lookup(void *);
f32 cos_table_lookup(void *);
f32 xyz_distance(void *, void *);

s32 approach_angle_limited(s32, s32, s32);
s32 project_actor_to_ground(void *, void *, s32);
void send_6xAD_grid_positions__11TBoss6Type2FUcll(s32, void *, s32);
s32 rand(void);

void TBoss6Type2__sub_8032E708(void* p, s32 v);
s32 is_local_client_floor_leader();
f32 fabs_float(f32);

void TBoss6Type2__sub_8032E708(void* p, s32 v) { *(s32*)((char*)p + 0x40c) = v; }
void TBoss6Type2::set_action_field_0x408(s16 v) { *(s16*)((char*)this + 0x408) = v; }
void TBoss6Type2::set_target_nodes(void* a1, void* a2) { *(void**)((char*)this + 0x2e4) = a1; *(void**)((char*)this + 0x390) = a2; update_segment_angles(); }
void TBoss6Type2::set_anim_frame(s32 v) { *(s32*)((char*)this + 0x37c) = v; }

s32 TBoss6Mag::is_phase_active() {
    T_8032E748 *self = (T_8032E748 *)this;
    switch (self->phase) {
    case 4:
    case 5:
        return 0;
    }
    return 1;
}

#pragma push
#pragma opt_common_subs off
void TBoss6Type2::destroy_part_object(s32 arg1) {
    s32 arg0 = (s32)this;
    u32 temp_r3;
    u8 *temp_r31;
    temp_r31 = (u8 *)(arg0 + (arg1 * 4));
    temp_r3 = *(u32 *)((s8 *)temp_r31 + 0x43C);
    if (temp_r3 != 0U) {
        TBoss4Type2::request_destroy(temp_r3);
        *(u32 *)((s8 *)temp_r31 + 0x43C) = 0U;
    }
}
#pragma pop

void TBoss6Type2::ensure_particle_emitter(s32 arg1) {
    O_8032E7B4 *arg0 = (O_8032E7B4 *)this;
    if (arg0->arr[arg1] == 0) {
        V3_8032E7B4 v = arg0->pos;
        arg0->arr[arg1] = (u32)create_particle_emitter(&v, TBoss6Type2__effect_emitter_id_table[arg1].a);
        if (arg0->arr[arg1] != 0) {
            ((TBoss4Type2 *)((void *)arg0->arr[arg1]))->set_flags(0x40);
        }
    }
}

void TBoss6Mag::update_effect_positions() {
    O_8032E834 *arg0 = (O_8032E834 *)this;
    s32 i;
    E_8032E834 *e = ((E_8032E834 *)&TBoss6Type2__effect_emitter_id_table);
    for (i = 0; i < 4; i++) {
        V3_8032E834 p = arg0->pos;
        E_8032E834 *ep = &e[i];
        if (arg0->h[i] != 0) {
            if (ep->b >= 0) {
                VecCopy((Vec *)&p, (const Vec *)&arg0->v[ep->b]);
            }
            ((TNowLoading *)(arg0->h[i]))->copy_pos(&p);
        }
    }
}

void TBoss6Mag::sub_8032E8DC() {
    switch (((TBoss6Type2 *)(((Obj_8032E8DC *)this)->f378))->get_state()) {
    case 14:
    case 24:
    case 25:
    case 26:
        if (this->is_phase_active() != 0) {
            ((TBoss6Type2 *)this)->ensure_particle_emitter(1);
        } else {
            ((TBoss6Type2 *)this)->destroy_part_object(1);
        }
        ((TBoss6Type2 *)this)->destroy_part_object(2);
        break;
    case 5:
    case 9:
    case 10:
    case 11:
        ((TBoss6Type2 *)this)->destroy_part_object(1);
        ((TBoss6Type2 *)this)->ensure_particle_emitter(2);
        break;
    default:
        ((TBoss6Type2 *)((Obj_8032E8DC *)this))->destroy_part_object(1);
        ((TBoss6Type2 *)this)->destroy_part_object(2);
        break;
    }
    if (!(((Obj_8032E8DC *)this)->f3C8 & 0x1F) && is_active__11TBoss6Type2Fv(((Obj_8032E8DC *)this)->f378) != 0) {
        spawn_particle_effect_with_flags(((Obj_8032E8DC *)this)->sw, 0x224, 0x2040);
    }
}

void update_all_parts__11TBoss6Type2FPv(s32 arg0) {
    s32 var_r31;
    var_r31 = 0;
    do {
        ((TBoss6Type2 *)arg0)->destroy_part_object(var_r31);
        var_r31 += 1;
    } while (var_r31 < 4);
}

void TBoss6Type2__sub_8032EA10(T_8032EA10 *self) {
    s32 i;
    for (i = 0; i < 4; i++) {
        self->arr[i] = 0;
    }
}

s32 TBoss6Type2::step_angle_toward(s32 arg1, s32 arg2, s32 arg3) {
    s32 t;
    TBoss6Type2__sub_8032EAB8(this, arg3);
    if (angle_difference_abs(arg2, arg1) <= arg3) {
        return arg2;
    }
    t = arg1 + TBoss6Type2__sub_8032EAB8(this, arg3);
    if (angle_difference_abs(arg2, t) <= arg3) {
        return arg2;
    }
    return t;
}

s32 TBoss6Type2__sub_8032EAB8(void *arg0, s32 arg1) {
    if ((s32) *(s32 *)((s8 *)arg0 + 0x384) == 0) {
        return arg1;
    }
    return -arg1;
}

f32 TBoss6Type2::apply_direction_sign(f32 farg0) {
    if ((s32) *(s32 *)((s8 *)this + 0x384) != 0) {
        return -farg0;
    }
    return farg0;
}

typedef struct Stack_8032EAE4 Stack_8032EAE4;
void TBoss6Type2::enforce_min_distance() {
    u8 *arg0 = (u8 *)this;
  Stack_8032EAE4 stack;
  f32 temp_f1;
  if (((u32) (*((u32 *) (((s8 *) arg0) + 0x37C)))) != 0U)
  {
    VecCopy((Vec *)(&stack.sp8), (const Vec *)(arg0 + 0x38));
    subtract_vector(&stack.sp8, (int) ((*((u32 *) (((s8 *) arg0) + 0x37C))) + 0x38));
    temp_f1 = vector_length(&stack.sp8);
    if (!(temp_f1 >= (4e+01f)))
    {
      if (temp_f1 <= (1e-05f))
      {
        stack.sp8 = apply_direction_sign((f32) (1.0f));
      }
      normalize_vector(&stack.sp8);
      stack.sp8 *= (4e+01f);
      stack.spC = (0.0f);
      stack.sp10 *= (4e+01f);
      vec3_add_to(&stack.sp8, (int) ((*((u32 *) (((s8 *) arg0) + 0x37C))) + 0x38));
      VecCopy((Vec *)(arg0 + 0x38), (const Vec *)(&stack.sp8));
    }
  }
}

void TBoss6Type2::push_out_from_points() {
    O_8032EBB4 *arg0 = (O_8032EBB4 *)this;
    V3_8032EBB4 v;
    V3_8032EBB4 pts[2];
    s32 i;
    f32 len;
    f32 f;
    if (arg0->p378 != 0) {
        ((TBoss6Type2 *)(arg0->p378))->get_push_points((s32)&pts[0], (s32)&pts[1]);
        for (i = 0; i < 2; i++) {
            VecCopy((Vec *)&v, (const Vec *)&pts[i]);
            ((f32 (*)(void *, void *))subtract_vector)(&v, &arg0->pos);
            if (v.y < 0.0f || v.y > 50.0f) {
                continue;
            }
            v.y = 0.0f;
            len = vector_length(&v);
            if (len > 50.0f) {
                continue;
            }
            if (len <= 0.00001f) {
                v.x = 1.0f;
            }
            normalize_vector(&v);
            f = 50.0f - len;
            if (f > 1.0f) {
                f *= 0.25f;
            }
            v.x *= f;
            v.z *= f;
            ((f32 (*)(void *, void *))subtract_vector)(&arg0->pos, &v);
        }
    }
}

void TBoss6Type2::push_out_from_target() {
    u8 *arg0 = (u8 *)this;
    Vec_8032ECE0 b;
    Vec_8032ECE0 a;
    Vec_8032ECE0 c;
    Vec_8032ECE0 d;
    f32 dist;
    f32 len;
    if (*(void **)((s8 *)arg0 + 0x378) == NULL) {
        return;
    }
    ((TBoss6Type2 *)(*(void **)((s8 *)arg0 + 0x378)))->copy_pos_59c((s32)&a);
    VecCopy((Vec *)&b, (const Vec *)(arg0 + 0x38));
    ((f32 (*)(void *, void *))subtract_vector)(&b, &a);
    len = vector_length(&b);
    if (len >= (5e+01f)) {
        return;
    }
    if (len <= (1e-05f)) {
        b.x = (1.0f);
    }
    normalize_vector(&b);
    b.x *= (5e+01f);
    b.y *= (5e+01f);
    b.z *= (5e+01f);
    ((f32 (*)(void *, void *))vec3_add_to)(&b, &a);
    VecCopy((Vec *)&c, (const Vec *)(arg0 + 0x38));
    ((f32 (*)(void *, void *))subtract_vector)(&c, arg0 + 0x44);
    dist = vector_length(&c);
    VecCopy((Vec *)&d, (const Vec *)&b);
    ((f32 (*)(void *, void *))subtract_vector)(&d, arg0 + 0x44);
    len = vector_length(&d);
    if (dist <= (1e-05f) || len <= (1e-05f)) {
        VecCopy((Vec *)(arg0 + 0x38), (const Vec *)&b);
        return;
    }
    normalize_vector(&c);
    normalize_vector(&d);
    ((f32 (*)(void *, void *))vec3_add_to)(&d, &c);
    if (vector_length(&d) <= (1e-05f)) {
        VecCopy((Vec *)(arg0 + 0x38), (const Vec *)&b);
        return;
    }
    normalize_vector(&d);
    d.x *= dist;
    d.y *= dist;
    d.z *= dist;
    ((f32 (*)(void *, void *))vec3_add_to)(&d, arg0 + 0x44);
    VecCopy((Vec *)(arg0 + 0x38), (const Vec *)&d);
}

void TBoss6Type2::compute_random_dir_vec(s32 arg0, u8 *arg1, s32 arg2, s32 arg3) {
    f32 temp_f31;
    f32 temp_f30;

    temp_f31 = -sin_table_lookup((void *)arg3);
    temp_f30 = (1.0f) - fabs_float(temp_f31);
    *(f32 *)((s8 *)arg1 + 0) = (f32) (temp_f30 * sin_table_lookup((void *)arg2));
    *(f32 *)((s8 *)arg1 + 4) = temp_f31;
    *(f32 *)((s8 *)arg1 + 8) = (f32) (temp_f30 * cos_table_lookup((void *)arg2));
}

typedef struct RecoveredFields_8032F174_arg0 RecoveredFields_8032F174_arg0;

s32 calc_dir_angles__11TBoss6Type2FPvPvPvPv(void *arg0, s32 *arg1, s32 *arg2, Vec_8032EF34 *arg3) {
    Vec_8032EF34 v;
    VecCopy((Vec *)&v, (const Vec *)arg3);
    if (vector_length(&v) <= (1e-05f)) {
        return 0;
    }
    normalize_vector(&v);
    if (v.y < (-0.99999f)) {
        *arg1 = 0;
        *arg2 = 0x7FFF;
        return 1;
    }
    if (v.y > (0.99999f)) {
        *arg1 = 0;
        *arg2 = -0x7FFF;
        return 1;
    }
    *arg1 = (10430.38043493439) * atan2_float(v.x, v.z);
    *arg2 = (10430.38043493439) * TBoss5GryphonLightningWing__sub_80324CEC(-v.y);
    return 1;
}

#pragma push
#pragma fp_contract on
s32 TBoss6Mag::is_target_in_front_range() {
    O_8032F034 *arg0 = (O_8032F034 *)this;
    u8 *p = 0;
    if (arg0->f408 != 0xFFFF) {
        p = get_player_by_client_id(arg0->f408);
    }
    if (p == 0) {
        return 0;
    }
    V3_8032F034 a;
    VecCopy((Vec *)&a, (const Vec *)(p + 0x38));
    a.y = 0.0f;
    V3_8032F034 b = arg0->home;
    if (0.0f == arg0->f3b8) {
        if (angle_difference_abs(arg0->f60, (s32)((10430.38043493439) * atan2_float(a.x - b.x, a.z - b.z))) > 0x2000) {
            return 0;
        }
    }
    V3_8032F034 c;
    VecCopy((Vec *)&c, (const Vec *)&b);
    c.x += 90.0f * sin_table_lookup((void *)arg0->f60);
    c.y = 0.0f;
    c.z += 90.0f * cos_table_lookup((void *)arg0->f60);
    if (xyz_distance(&c, &a) <= 100.0f) {
        return 1;
    }
    return 0;
}
#pragma pop

s32 TBoss6Mag::is_action_ready() {
    u8 *arg0 = (u8 *)this;
  if (((((RecoveredFields_8032F174_arg0 *) arg0)->field_380 == 2) && (((RecoveredFields_8032F174_arg0 *) arg0)->field_408 != ((-1) & 0xFFFF))) && (((RecoveredFields_8032F174_arg0 *) arg0)->field_3C <= (75.0f)))
  {
    return 1;
  }
  return 0;
}

void TBoss6Mag::update_rotation_ramp() {
    if ((is_action_ready() == 0) || (is_target_in_front_range() == 0)) {
        *(f32 *)((s8 *)this + 0x3BC) = (f32) (0.0f);
        *(f32 *)((s8 *)this + 0x3B8) += (-0.06666667f);
        if (*(f32 *)((s8 *)this + 0x3B8) < (0.0f)) {
            *(f32 *)((s8 *)this + 0x3B8) = (f32) (0.0f);
        }
    } else if ((1.0f) == *(f32 *)((s8 *)this + 0x3B8)) {
        *(f32 *)((s8 *)this + 0x3BC) += (0.033333335f);
        if (*(f32 *)((s8 *)this + 0x3BC) > (1.0f)) {
            *(f32 *)((s8 *)this + 0x3BC) = (f32) (1.0f);
        }
        if ((1.0f) == *(f32 *)((s8 *)this + 0x3BC)) {
            if (is_local_client_floor_leader() != 0) {
                u32 tmp378 = (u32) *(u32 *)((s8 *)this + 0x378);
                if (tmp378 != 0U) {
                    if (((TBoss6Type2 *)tmp378)->get_rotation_timer() == 0) {
                        spawn_falling_rocks();
                    }
                }
            }
            *(f32 *)((s8 *)this + 0x3B8) = (f32) (0.0f);
            *(f32 *)((s8 *)this + 0x3BC) = (f32) (0.0f);
        }
    } else {
        *(f32 *)((s8 *)this + 0x3BC) = (f32) (0.0f);
        *(f32 *)((s8 *)this + 0x3B8) += (0.06666667f);
        if (*(f32 *)((s8 *)this + 0x3B8) > (1.0f)) {
            *(f32 *)((s8 *)this + 0x3B8) = (f32) (1.0f);
        }
    }
}

void TBoss6Type2::init_with_global_table() {
    T_8032F2C4 *self = (T_8032F2C4 *)this;
    TBoss6Type2__sub_8032F2F0((void*)self->v, (void*)lbl_80477450);
}

void TBoss6Type2__sub_8032F2F0(void* p, void* q) { *(f32*)((char*)p + 0x0) = *(f32*)((char*)q + 0x0); *(f32*)((char*)p + 0x4) = *(f32*)((char*)q + 0x4); }

void TBoss6Type2::spawn_mag_mines() {
    O_8032F304 *arg0 = (O_8032F304 *)this;
    void *m = arg0->mine;
    s32 i;
    for (i = 0; i < arg0->n; i++) {
        spawn_mag_mine_at__13TBoss6MagMineFPvPv(m, &arg0->v[i]);
    }
}

void set_path_points__11TBoss6Type2FPvPvi(O_8032F360 *arg0, V3_8032F360 *arg1, s32 arg2) {
    s32 i;
    s32 n = arg2;
    arg0->z = 0;
    if (n > 3) {
        n = 3;
    }
    for (i = 0; i < n; i++) {
        VecCopy((Vec *)&arg0->v[i], (const Vec *)&arg1[i]);
    }
    arg0->n = n;
    ((TBoss6Mag *)arg0)->set_action(3);
}

void TBoss6Type2::set_path_points_by_index(s32 i, void *pts, s32 n) {
    void *p = TBoss6Type2__instance_slots[i];
    if (p != 0) {
        set_path_points__11TBoss6Type2FPvPvi((O_8032F360 *)(p), (V3_8032F360 *)(pts), n);
    }
}

#pragma push
#pragma fp_contract on
void TBoss6Mag::spawn_falling_rocks() {
    u8 *arg0 = (u8 *)this;
    Vec_8032F418 pts[3];
    Vec_8032F418 *p;
    s32 i;
    s32 ang;
    f32 r;
    s32 d;
    for (i = 0; i < 3; i++) {
        ang = *(s32 *)((s8 *)arg0 + 0x60) + lbl_80477444[i] + (s32)((4096.0f) * ((0.5f) - (3.0517578e-05f) * (f32)rand()));
        r = (4e+01f) * ((3.0517578e-05f) * (f32)rand()) + (8e+01f);
        p = &pts[i];
        VecCopy((Vec *)p, (const Vec *)(arg0 + 0x44C));
        p->x = r * ((f32 (*)(s32))sin_table_lookup)(ang) + p->x;
        p->y = (0.0f);
        p->z = r * ((f32 (*)(s32))cos_table_lookup)(ang) + p->z;
        ((TBoss6Rock *)p)->push_out_of_rocks((1e+01f));
    }
    send_6xAD_grid_positions__11TBoss6Type2FUcll(*(s32 *)((s8 *)arg0 + 0x384), pts, 3);
}
#pragma pop

void TBoss6Type2__sub_8032F5C4(void *boss6_mag) {
    *(s32 *)((s8 *)boss6_mag + 0x30) = (s32) ((*(s32 *)((s8 *)boss6_mag + 0x30)) & ~0xA00);
    *(s16 *)((s8 *)boss6_mag + 0x32C) = (s16) *(s32 *)((s8 *)boss6_mag + 0x38C);
    ((TBoss6Mag *)boss6_mag)->sync_hp();
}

void TBoss6Type2::apply_random_drift() {
    O_8032F5FC *arg0 = (O_8032F5FC *)this;
    V3_8032F5FC v;
    f32 k;
    TBoss6Type2::compute_random_dir_vec((s32)arg0, (u8 *)&v, arg0->f60, arg0->f5c);
    k = (1.3333334f);
    if (((TBoss6Type2 *)(arg0->f378))->get_state() == 0xE) {
        k *= arg0->f3c4;
    }
    v.x = v.x * k;
    v.y = v.y * k;
    v.z = v.z * k;
    vec3_add_to(&arg0->pos, (int)&v);
}

#pragma push
#pragma fp_contract on
struct Vec_8032EF34;
void TBoss6Type2::turn_toward_target() {
    Vec_8032F690 v;
    s32 a;
    s32 b;
    s32 turn;
    u8 *p;
    u16 id;
    p = NULL;
    id = *(u16 *)((s8 *)((u8 *)this) + 0x408);
    if (id != 0xFFFF) {
        p = ((u8 *(*)(u16))get_player_by_client_id)(id);
    }
    if (p == NULL) {
        if (*(u8 **)((s8 *)((u8 *)this) + 0x378) == NULL) {
            VecCopy((Vec *)&v, (const Vec *)(((u8 *)this) + 0x50));
        } else {
            s32 ang;
            u8 *t;
            ang = (s32)((12288.0f) * this->apply_direction_sign((1.0f)) + (f32)*(s32 *)((s8 *)(*(u8 **)((s8 *)((u8 *)this) + 0x378)) + 0x60));
            t = *(u8 **)((s8 *)((u8 *)this) + 0x378);
            VecCopy((Vec *)&v, (const Vec *)(t + 0x38));
            v.x += (5e+01f) * ((f32 (*)(s32))sin_table_lookup)(ang);
            v.z += (5e+01f) * ((f32 (*)(s32))cos_table_lookup)(ang);
        }
        v.y = (3e+01f);
    } else {
        VecCopy((Vec *)&v, (const Vec *)(p + 0x38));
        v.y = (3e+01f);
    }
    if (project_actor_to_ground(this, &v, 0) != 0) {
        v.y += (3e+01f);
    }
    ((f32 (*)(void *, void *))subtract_vector)(&v, ((u8 *)this) + 0x38);
    turn = 0x1B4;
    if (((TBoss6Type2 *)(*(s32 *)((s8 *)((u8 *)this) + 0x378)))->get_state() == 0xE) {
        turn = 0x6D0;
    }
    calc_dir_angles__11TBoss6Type2FPvPvPvPv(this, &a, &b, (Vec_8032EF34 *)((struct Vec_8032EF34 *)&v));
    *(s32 *)((s8 *)((u8 *)this) + 0x60) = this->step_angle_toward(*(s32 *)((s8 *)((u8 *)this) + 0x60), a, turn);
    *(s32 *)((s8 *)((u8 *)this) + 0x5C) = approach_angle_limited(*(s32 *)((s8 *)((u8 *)this) + 0x5C), b, 0x1B4);
}
#pragma pop

#pragma push
#pragma fp_contract on
s32 TBoss6Type2::fly_toward_target() {
    O_8032F824 *o = (O_8032F824 *)this;
    V3_8032F824 tgt;
    V3_8032F824 d;
    V3_8032F824 h;
    V3_8032F824 a;
    V3_8032F824 r;
    s32 t;
    s32 rx;
    s32 ry;
    f32 len;
    if (o->p378 == 0) {
        return 0;
    }
    TBoss6Type2__sub_802BD378(o->p378, o->f384, &tgt, &t);
    tgt.y += (35.0f);
    VecCopy((Vec *)&d, (const Vec *)&tgt);
    subtract_vector(&d, (int)&o->pos);
    if (!(vector_length(&d) > (3e+01f))) {
        d.x *= (0.25f);
        d.y *= (0.25f);
        d.z *= (0.25f);
        if (vector_length(&d) > (4.4444447f)) {
            normalize_vector(&d);
            d.x *= (4.4444447f);
            d.y *= (4.4444447f);
            d.z *= (4.4444447f);
        }
        vec3_add_to(&o->pos, (int)&d);
        o->f60 = step_angle_toward(o->f60, t, 0x5B0);
        o->f5c = approach_angle_limited(o->f5c, 0, 0x5B0);
        return 1;
    }
    VecCopy((Vec *)&h, (const Vec *)&d);
    h.y = (0.0f);
    len = vector_length(&h);
    if (!(len < (1e+02f))) {
        f32 dy;
        o->f60 = step_angle_toward(o->f60, (s32)((10430.38043493439) * atan2_float(d.x, d.z)), 0x5B0);
        o->f5c = approach_angle_limited(o->f5c, 0, 0x5B0);
        VecCopy((Vec *)&a, (const Vec *)&o->pos);
        a.x += (4.4444447f) * sin_table_lookup((void *)o->f60);
        a.z += (4.4444447f) * cos_table_lookup((void *)o->f60);
        if (project_actor_to_ground(o, &a, 0) == 0) {
            o->pos.x = a.x;
            o->pos.z = a.z;
            return 0;
        }
        a.y += (5e+01f);
        o->pos.x = a.x;
        o->pos.z = a.z;
        dy = 0.25f * (a.y - o->pos.y);
        if (dy < -4.4444447f) {
            dy = -4.4444447f;
        } else if (dy > 4.4444447f) {
            dy = 4.4444447f;
        }
        o->pos.y += dy;
        return 0;
    }
    if (len < (1e+01f)) {
        s32 ang;
        o->f60 = step_angle_toward(o->f60, t, 0x5B0);
        ang = 0x7FFF;
        if (tgt.y > o->pos.y) {
            ang *= -1;
        }
        o->f5c = approach_angle_limited(o->f5c, ang, 0x5B0);
    } else {
        calc_dir_angles__11TBoss6Type2FPvPvPvPv(o, &rx, &ry, (Vec_8032EF34 *)&d);
        o->f60 = step_angle_toward(o->f60, rx, 0x5B0);
        o->f5c = approach_angle_limited(o->f5c, ry, 0x5B0);
    }
    TBoss6Type2::compute_random_dir_vec((s32)o, (u8 *)&r, o->f60, o->f5c);
    r.x *= (4.4444447f);
    r.y *= (4.4444447f);
    r.z *= (4.4444447f);
    vec3_add_to(&o->pos, (int)&r);
    return 0;
}
#pragma pop

s32 TBoss6Type2__sub_8032FB84(O_8032FB84 *arg0) {
    V3_8032FB84 v;
    s32 t;
    if (arg0->p378 == 0) {
        return 0;
    }
    TBoss6Type2__sub_802BD378(arg0->p378, arg0->f384, &v, &t);
    v.y += (35.0f);
    VecCopy((Vec *)&arg0->pos, (const Vec *)&v);
    arg0->f60 = t;
    return 1;
}

void TBoss6Type2::update_segment_angles() {
    s16 temp_r0;
    temp_r0 = *(s16 *)((s8 *)this + 0x3B4);
    *(s16 *)((s8 *)this + 0x39E) = temp_r0;
    *(s16 *)((s8 *)this + 0x39C) = temp_r0;
    *(s16 *)((s8 *)this + 0x39A) = temp_r0;
    *(s16 *)((s8 *)this + 0x398) = temp_r0;
    *(s16 *)((s8 *)this + 0x396) = temp_r0;
    switch (*(s32 *)((s8 *)this + 0x390)) {
    case 1:
        *(s16 *)((s8 *)this + 0x396) = (s16) *(s16 *)((s8 *)this + 0x3B6);
        break;
    case 2:
        *(s16 *)((s8 *)this + 0x398) = (s16) *(s16 *)((s8 *)this + 0x3B6);
        break;
    case 3:
        *(s16 *)((s8 *)this + 0x39A) = (s16) *(s16 *)((s8 *)this + 0x3B6);
        break;
    case 4:
        *(s16 *)((s8 *)this + 0x39C) = (s16) *(s16 *)((s8 *)this + 0x3B6);
        break;
    case 5:
        *(s16 *)((s8 *)this + 0x39E) = (s16) *(s16 *)((s8 *)this + 0x3B6);
        break;
    }
    *(s16 *)((s8 *)this + 0x2F2) = (s16) *(s16 *)((s8 *)this + 0x396);
    *(s16 *)((s8 *)this + 0x2F4) = (s16) *(s16 *)((s8 *)this + 0x39A);
    *(s16 *)((s8 *)this + 0x2F6) = (s16) *(s16 *)((s8 *)this + 0x398);
    *(s16 *)((s8 *)this + 0x2F8) = (s16) *(s16 *)((s8 *)this + 0x39E);
    *(s16 *)((s8 *)this + 0x2FA) = (s16) *(s16 *)((s8 *)this + 0x39C);
}

void TBoss6Type2::init_segment_angle_range() {
    Obj_8032FCA4 *arg0 = (Obj_8032FCA4 *)this;
    Ent_8032FCA4 *e = arg0->ent;
    s32 lo;
    s32 hi;
    hi = e->v[0];
    lo = hi;
    if (lo > e->v[1]) {
        lo = e->v[1];
    } else if (hi < e->v[1]) {
        hi = e->v[1];
    }
    if (lo > e->v[2]) {
        lo = e->v[2];
    } else if (hi < e->v[2]) {
        hi = e->v[2];
    }
    if (lo > e->v[3]) {
        lo = e->v[3];
    } else if (hi < e->v[3]) {
        hi = e->v[3];
    }
    if (lo > e->v[4]) {
        lo = e->v[4];
    } else if (hi < e->v[4]) {
        hi = e->v[4];
    }
    arg0->min = lo;
    arg0->max = hi;
    ((TLobby *)(arg0->local))->copy_entry(arg0->ent);
    arg0->ent = (Ent_8032FCA4 *)arg0->local;
    update_segment_angles();
}

#pragma push
#pragma opt_common_subs off
void TBoss6Mag::decay_glow_and_calc_hp_ratio() {
    *(f32 *)((s8 *)this + 0x3F8) += (-0.06666667f);
    if (*(f32 *)((s8 *)this + 0x3F8) < (0.0f)) {
        *(f32 *)((s8 *)this + 0x3F8) = (f32) (0.0f);
    }
    *(f32 *)((s8 *)this + 0x3FC) = (f32) ((f32) *(s16 *)((s8 *)this + 0x32C) / (f32) *(s16 *)((s8 *)this + 0x33E));
}
#pragma pop

void TBoss6Mag::sync_hp_apply_damage() {
    s16 temp_r0;
    s32 temp_r4;
    temp_r4 = *(s32 *)((s8 *)this + 0x404);
    temp_r0 = *(s16 *)((s8 *)this + 0x32C);
    if (temp_r4 != temp_r0) {
        if (temp_r4 < temp_r0) {
            sync_hp();
            return;
        }
        ((TBoss6Type2 *)(*(s32 *)((s8 *)this + 0x378)))->apply_damage(temp_r4 - temp_r0);
        *(s32 *)((s8 *)this + 0x404) = (s32) *(s16 *)((s8 *)this + 0x32C);
    }
}
void TBoss6Mag::sync_hp() {
    *(s32 *)((s8 *)this + 0x404) = (s32) *(s16 *)((s8 *)this + 0x32C);
}
void TBoss6Mag::draw_model_motion_blend() {
    Stack_8032FE50 stack;
    s32 temp_r31;
    s32 bml_model;
    TObjPlayer::set_global_flag();
    temp_r31 = TObjFish__sub_8001EDB0(*(s32 *)((s8 *)this + 0x374), 1);
    bml_model = get_bml_model(*(s32 *)((s8 *)this + 0x374), 1);
    TObjFish::set_global_param(temp_r31);
    if ((0.0f) == *(f32 *)((s8 *)this + 0x3E8)) {
        ((TObjFish *)(*(s32 *)((s8 *)this + 0x458)))->set_draw_callback_list();
        draw_model_motion((void *)bml_model, (void *)(*(s32 *)((s8 *)this + 0x3DC)), *(f32 *)((s8 *)this + 0x3E0));
        clear_render_callback__8TObjFishFv(*(s32 *)((s8 *)this + 0x458));
    } else {
        stack.sp8 = *(s32 *)((s8 *)this + 0x3F0);
        stack.sp10 = *(f32 *)((s8 *)this + 0x3F4);
        stack.spC = *(s32 *)((s8 *)this + 0x3DC);
        stack.sp14 = *(f32 *)((s8 *)this + 0x3E0);
        ((TObjFish *)(*(s32 *)((s8 *)this + 0x458)))->set_draw_callback_list();
        draw_model_blend_motion((void *)bml_model, &stack.sp8, *(f32 *)((s8 *)this + 0x3E8));
        clear_render_callback__8TObjFishFv(*(s32 *)((s8 *)this + 0x458));
    }
    TObjPlayer::clear_global_state();
}

#pragma push
#pragma opt_common_subs off
typedef char RecoveredGlobal_8032FF24_lbl_804EDD94_size[sizeof(RecoveredGlobal_8032FF24_lbl_804EDD94) == 0x50 ? 1 : -1];
void TBoss6Mag::change_motion(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    s32 temp_r31;
    s32 bml_motion;
    if ((arg1 != -1) && (arg1 != (s32) *(s32 *)((s8 *)arg0 + 0x3D4))) {
        *(s32 *)((s8 *)arg0 + 0x3D4) = arg1;
        temp_r31 = arg1 * 0x10;
        *(s32 *)((s8 *)arg0 + 0x3D8) = (s32) *(s32 *)((s8 *)((u8 *)(&(*(RecoveredGlobal_8032FF24_lbl_804EDD94 *)&boss6_type2_motion_table).value) + temp_r31) + 0);
        bml_motion = get_bml_motion((int) (*(s32 *)((s8 *)arg0 + 0x374)), (int) (*(s32 *)((s8 *)((u8 *)(&(*(RecoveredGlobal_8032FF24_lbl_804EDD94 *)&boss6_type2_motion_table).value) + temp_r31) + 8)));
        *(f32 *)((s8 *)arg0 + 0x3E8) = (f32) *(f32 *)((s8 *)arg0 + 0x3EC);
        *(s32 *)((s8 *)arg0 + 0x3F0) = (s32) *(s32 *)((s8 *)arg0 + 0x3DC);
        *(f32 *)((s8 *)arg0 + 0x3F4) = (f32) *(f32 *)((s8 *)arg0 + 0x3E0);
        *(f32 *)((s8 *)arg0 + 0x3E4) = (f32) *(f32 *)((s8 *)((u8 *)(&(*(RecoveredGlobal_8032FF24_lbl_804EDD94 *)&boss6_type2_motion_table).value) + temp_r31) + 0xC);
        *(s32 *)((s8 *)arg0 + 0x3DC) = bml_motion;
        *(f32 *)((s8 *)arg0 + 0x3E0) = (f32) (0.0f);
    }
}
#pragma pop
void TBoss6Mag::update_motion_playback() {
    O_8032FFC0 *arg0 = (O_8032FFC0 *)this;
    f32 n;
    f32 lim;

    n = (f32)arg0->anim->count;
    arg0->t += arg0->speed;
    switch (arg0->mode) {
    case 0:
        if (arg0->t >= n) {
            arg0->t -= n;
        }
        break;
    case 1:
        break;
    case 2:
        lim = n - 1.0f;
        if (arg0->t >= lim) {
            arg0->t = lim;
            change_motion(boss6_type2_motion_table[arg0->f3d4].next);
        }
        break;
    }
    if (0.0f != arg0->f3e8) {
        if ((arg0->f3e8 += arg0->f3ec) >= 1.0f) {
            arg0->f3e8 = 0.0f;
        }
    }
}

void TBoss6Type2__sub_803300C8(u8 *arg0) {
    s32 bml_motion;
    copy_vec3__11TBoss6Type2Fii((s32)(arg0 + 0x3D4), (s32)&boss6_type2_zero_vec3_block.value);
    ((TBoss6Type2 *)(arg0 + 0x3DC))->copy_state((void*)&boss6_type2_initial_state.value);
    bml_motion = get_bml_motion((int) (*(s32 *)((s8 *)arg0 + 0x374)), (int) (*(s32 *)((s8 *)(&(*(RecoveredGlobal_803300C8_lbl_804EDD94 *)boss6_type2_motion_table).value) + 8)));
    *(s32 *)((s8 *)arg0 + 0x3F0) = bml_motion;
    *(s32 *)((s8 *)arg0 + 0x3DC) = bml_motion;
    *(f32 *)((s8 *)arg0 + 0x3E4) = (f32) *(f32 *)((s8 *)(&(*(RecoveredGlobal_803300C8_lbl_804EDD94 *)boss6_type2_motion_table).value) + 0xC);
}
void TBoss6Type2::copy_state(void* q) { *(u32*)((char*)this + 0x0) = *(u32*)((char*)q + 0x0); *(f32*)((char*)this + 0x4) = *(f32*)((char*)q + 0x4); *(f32*)((char*)this + 0x8) = *(f32*)((char*)q + 0x8); *(f32*)((char*)this + 0xc) = *(f32*)((char*)q + 0xc); *(f32*)((char*)this + 0x10) = *(f32*)((char*)q + 0x10); *(u32*)((char*)this + 0x14) = *(u32*)((char*)q + 0x14); *(f32*)((char*)this + 0x18) = *(f32*)((char*)q + 0x18); }

typedef char MemberActionStorage_803301B8_size[sizeof(MemberActionStorage_803301B8) == 12 ? 1 : -1];
typedef char RecoveredGlobal_803301B8_lbl_804EF028_size[sizeof(RecoveredGlobal_803301B8_lbl_804EF028) == 0xD8 ? 1 : -1];

int copy_vec3__11TBoss6Type2Fii(s32 _w0, s32 _w1) {
    S_80330178 *d = (S_80330178 *)_w0;
    S_80330178 *s = (S_80330178 *)_w1;
    d->a = s->a;
    d->b = s->b;
    d->c = s->c;
    return _w0;
}

void TBoss6Mag::set_action(s32 arg1) {
    MemberActionStorage_803301B8 member_action;
    u8 *temp_r31;
    *(s32 *)((s8 *)((u8 *)this) + 0x380) = arg1;
    temp_r31 = (u8 *)((void *)((u8 *)boss6_type2_action_table + (*(s32 *)((s8 *)((u8 *)this) + 0x380) * 0x24)));
    this->change_motion((s32)((int) (*(s32 *)((s8 *)temp_r31 + 4))));
    *(s32 *)((s8 *)((u8 *)this) + 0x388) = (s32) *(s32 *)((s8 *)temp_r31 + 8);
    member_action.words[0] = *(s32 *)((s8 *)temp_r31 + 0xC);
    member_action.words[1] = *(s32 *)((s8 *)temp_r31 + 0x10);
    member_action.words[2] = *(s32 *)((s8 *)temp_r31 + 0x14);
    if (member_action.action != 0) {
        (((TBoss6Type2 *)(this))->*member_action.action)();
    }
}

typedef char RecoveredGlobal_803300C8_lbl_80477404_size[sizeof(RecoveredGlobal_803300C8_lbl_80477404) == 0x24 ? 1 : -1];
typedef char RecoveredGlobal_803300C8_lbl_80477428_size[sizeof(RecoveredGlobal_803300C8_lbl_80477428) == 0x1C ? 1 : -1];
typedef char RecoveredGlobal_803300C8_lbl_804EDD94_size[sizeof(RecoveredGlobal_803300C8_lbl_804EDD94) == 0x50 ? 1 : -1];

f32 receive_direct_attack__13TUnk_804806E8FPv19DirectAttackPayloadPvll(void *, void *, P_80330240, void *, void *, void *);
s32 query_teammate_state__9TObjEneDDFv();

f32 fn_80330240(O_80330240 *arg0, void *att, P_80330240 arg2, void *coll, void *tech, void *arg5) {
    while (arg0->f388 == 0) {
        if (arg2.a != 0x14 && query_teammate_state__9TObjEneDDFv() == 0) {
            return (0.0f);
        }
        break;
    }
    return receive_direct_attack__13TUnk_804806E8FPv19DirectAttackPayloadPvll(arg0, att, arg2, coll, tech, arg5);
}
s32 play_sound_effect(int, void *, int, int);
s32 TBoss6Type2__sub_802BD340(int);
f32 receive_physical_attack__13TUnk_804806E8FPvf();

f32 TBoss6Mag::receive_physical_attack(void *, f32) {
    if ((s32) *(s32 *)((s8 *)this + 0x388) != 0) {
        return receive_physical_attack__13TUnk_804806E8FPvf();
    }
    return (0.0f);
}
void TBoss6Mag::vfunc_63() {
    u8 *arg0 = (u8 *)this;
    switch (*(s32 *)((s8 *)arg0 + 0x380)) {
    case 3:
    case 4:
    case 5:
        return;
    default:
        TBoss6Type2__sub_802BD340((int) (*(s32 *)((s8 *)arg0 + 0x378)));
        *(f32 *)((s8 *)arg0 + 0x3F8) = (f32) (1.0f);
        ((TBoss6Mag *)arg0)->set_action(4);
        play_sound_effect(0x69E17, arg0 + 0x38, 0, 0);
        break;
    }
}

void spawn_ground_effect__10TObjPlayerFPv(u8 *arg0) {
    *(f32 *)((s8 *)arg0 + 0x3F8) = (f32) (1.0f);
    *(s32 *)((s8 *)arg0 + 0x30) = (s32) (*(s32 *)((s8 *)arg0 + 0x30) & 0xFFFFFDFF);
    play_sound_effect(0x6A816, arg0 + 0x38, 0, 0);
    *(f32 *)((s8 *)arg0 + 0x3BC) = (f32) (0.0f);
}
void TBoss6PlotFalz__sub_802AC008(f32, f32);
s32 pop_matrix(void);
s32 rotate_matrix_y(int, int);
s32 rotate_matrix_x(int, int);
s32 push_matrix();
s32 post_translate_matrix(void *);
void queue_destruction__7TObjectFv(void *object);
s32 submit_cursor_candidate(void *, int);
s32 add_radar_scaled_marker(void *, int, int, int, f32);
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);

void TObjPlayer::save_position() {
    s32 arg0 = (s32)this;
    VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)(arg0 + 0x38));
}

void TBoss6Mag::sub_8033040C() {
    f32 temp_f1;
    f32 temp_f1_2;
    s32 var_r31;
    TObjPlayer::toggle_particle_effect();
    push_matrix();
    post_translate_matrix((void *) ((u8 *)this + 0x38));
    rotate_matrix_y(0, (int) (*(s32 *)((s8 *)((u8 *)this) + 0x60)));
    rotate_matrix_x(0, (int) (*(s32 *)((s8 *)((u8 *)this) + 0x5C)));
    temp_f1 = *(f32 *)((s8 *)((u8 *)this) + 0x3F8);
    var_r31 = 0;
    if (temp_f1 > (0.0f)) {
        TBoss6PlotFalz__sub_802AC008(temp_f1, *(f32 *)((s8 *)((u8 *)this) + 0x3FC));
        var_r31 = 1;
    } else {
        temp_f1_2 = *(f32 *)((s8 *)((u8 *)this) + 0x400);
        if (temp_f1_2 > (0.0f)) {
            TBoss6PlotFalz::apply_fade_material_color(temp_f1_2, (0.5f), (0.5f), (0.5f));
            var_r31 = 1;
        }
    }
    this->draw_model_motion_blend();
    if (var_r31 != 0) {
        TBoss6PlotFalz::update_camera_target();
    }
    pop_matrix();
    TParticleCtrl::end_effect_render();
}

void TBoss6Mag::spawn_trap_by_stat() {
    s32 var_r3;

    var_r3 = 0x4006C919;
    if (*(f32 *)((s8 *)((u8 *)this) + 0x3B8) > (0.0f)) {
        var_r3 = 0x6B015;
        if (*(f32 *)((s8 *)((u8 *)this) + 0x3BC) > (0.0f)) {
            var_r3 = 0x6B518;
        }
    }
    play_persistent_sound((s32)var_r3, (s32)this, (u32)(((u8 *)this) + 0x38), 0, 0);
}

void TBoss6Mag::render() { sub_8033040C(); }

void TBoss6Mag::run_task() {
    u8 *arg0 = (u8 *)this;
    s32 var_r4;

    if (TObjPlayer::check_demo_mode() == 0) {
        if (TBoss6PlotFalz::is_boss_active() == 0) {
            *(s32 *)((s8 *)arg0 + 0x378) = 0;
            queue_destruction__7TObjectFv(arg0);
            return;
        }
        VecCopy((Vec *)(arg0 + 0x44), (const Vec *)(arg0 + 0x38));
        {
            Fn_8033053C fn = boss6_type2_action_table[*(s32 *)((s8 *)arg0 + 0x380)].fn;
            if (fn) {
                (((T_8033053C *)arg0)->*fn)();
            }
        }
        ((TBoss6Mag *)arg0)->update_rotation_ramp();
        ((TBoss6Mag *)arg0)->update_motion_playback();
        ((TObjPlayer *)arg0)->save_position();
        if ((s32) *(s32 *)((s8 *)arg0 + 0x388) != 0) {
            ((TObjPlayer *)arg0)->update_collisions();
            submit_cursor_candidate(arg0, -1);
        }
        ((TBoss6Rock *)(arg0 + 0x38))->break_rocks_in_radius((f32) (1e+01f));
        var_r4 = 0xFF7F5126;
        if ((s32) *(s32 *)((s8 *)arg0 + 0x388) != 0) {
            var_r4 = -0x5DB4;
        }
        add_radar_scaled_marker(arg0 + 0x38, var_r4, 1, 1, (f32) (2.0f));
        ((TBoss6Mag *)arg0)->decay_glow_and_calc_hp_ratio();
        ((TBoss6Mag *)arg0)->sync_hp_apply_damage();
        ((TBoss6Mag *)arg0)->spawn_trap_by_stat();
        ((TBoss6Mag *)arg0)->sub_8032E8DC();
        ((TBoss6Mag *)arg0)->update_effect_positions();
        *(s32 *)((s8 *)arg0 + 0x3C8) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C8) + 1);
    }
}
void *__dt__9TObjEnemyFv(TObjEnemy *arg0, s16 arg1);
s32 free_collision_body_parts(void *);
s32 __dl__7TObjectFPv(void *);

void *fn_8033068C(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(void **)((s8 *)arg0 + 0x18) = lbl_804EDDEC;
        update_all_parts__11TBoss6Type2FPv((s32)arg0);
        if ((u32) *(u32 *)((s8 *)arg0 + 0x458) != 0U) {
            TObjFish::init_state_1(*(void **)((s8 *)arg0 + 0x458));
            *(u32 *)((s8 *)arg0 + 0x458) = 0U;
        }
        free_collision_body_parts(arg0);
        TBoss6Type2__instance_slots[*(s32 *)((s8 *)arg0 + 0x384)] = 0;
        __dt__9TObjEnemyFv((TObjEnemy *)arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
}
struct Key_80330724 { s32 a; s16 b; s16 c; s32 d; s32 e; };

extern "C" {
void __ct__9TObjEnemyFP7TObject(void *, s32, void *);
s32 exchange_object_state__9TObjEnemyFls(void *, Key_80330724 *, s32);
void init_collision_body_parts(void *, void *, s32);
f32 *dispatch_shared_handler_a__6TLobbyFl(int);
s32 TObjFish__sub_800E3124(u8 *list, s32 vecs);
void TBoss6Mag__sub_803309C4(void *, void *);

u8 *TBoss6Mag__ct(u8 *arg0, s32 arg1, u8 *arg2) {
    Key_80330724 key;
    f32 *d;
    s32 prm;
    TObjEnemy *enemy;
    __ct__9TObjEnemyFP7TObject(arg0, arg1, arg2);
    *(u8 **)((s8 *)arg0 + 0x18) = (u8 *)lbl_804EDDEC;
    *(s32 *)((s8 *)arg0 + 0) = (s32)lbl_805D4220;
    *(s32 *)((s8 *)arg0 + 0x378) = *(s32 *)((s8 *)arg2 + 0x40);
    VecCopy((Vec *)(arg0 + 0x38), (const Vec *)(arg2 + 0x44));
    *(s32 *)((s8 *)arg0 + 0x60) = *(s32 *)((s8 *)arg2 + 0x50);
    *(s32 *)((s8 *)arg0 + 0x384) = *(s32 *)((s8 *)arg2 + 0x54);
    TBoss6Type2__instance_slots[*(s32 *)((s8 *)arg0 + 0x384)] = arg0;
    ((TBoss6Mag *)arg0)->apply_set_data(arg2);
    if (exchange_object_state__9TObjEnemyFls(arg0, &key, 1) != 0) {
        key.a = 0;
        key.c = 0;
        exchange_object_state__9TObjEnemyFls(arg0, &key, 0);
    }
    *(s32 *)((s8 *)arg0 + 0x374) = TObjFish::get_fish_count();
    *(s32 *)((s8 *)arg0 + 0x37C) = 0;
    *(s32 *)((s8 *)arg0 + 0x24) = 0;
    *(s32 *)((s8 *)arg0 + 0x34) = 0;
    VecCopy((Vec *)(arg0 + 0x44), (const Vec *)((void *)VecCopy((Vec *)(arg0 + 0x50), (const Vec *)((void *)VecCopy((Vec *)(arg0 + 0x74), (const Vec *)(arg0 + 0x38))))));
    init_collision_body_parts(arg0, TBoss6Mag__collision_body_parts, 1);
    VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)(arg0 + 0x38));
    *(f32 *)((s8 *)arg0 + 0x310) = 0.0f;
    *(f32 *)((s8 *)arg0 + 0x30C) = 0.0f;
    *(f32 *)((s8 *)arg0 + 0x308) = 0.0f;
    *(s32 *)((s8 *)arg0 + 0x2A8) = 0;
    ((TObjEnemy *)arg0)->bind_enemy_combat_stats((u8 *)(TLobby::register_boss(0x2E)), (u8 *)(TLobby::dispatch_shared_handler_b(0x2E)), (u8 *)(TLobby::register_object(0x2E)));
    *(s16 *)((s8 *)arg0 + 0x33E) = *(s16 *)((s8 *)arg0 + 0x32C);
    *(s32 *)((s8 *)arg0 + 0x38C) = *(s16 *)((s8 *)arg0 + 0x32C);
    ((TBoss3Volopt *)arg0)->reset_photon_effect();
    enemy = (TObjEnemy *)arg0;
    prm = 0x55;
    if (*(s32 *)((s8 *)arg0 + 0x384) == 1) {
        prm = 0x56;
    }
    enemy->set_param(prm);
    ((TUnk_804806E8 *)arg0)->add_flags_2e4(*(u32 *)((s8 *)arg2 + 0x58));
    *(s32 *)((s8 *)arg0 + 0x390) = *(s32 *)((s8 *)arg2 + 0x5C);
    ((TBoss6Type2 *)arg0)->init_segment_angle_range();
    TBoss6Type2__sub_803300C8(arg0);
    *(s32 *)((s8 *)arg0 + 0x458) = TObjFish__sub_800E3124((u8 *)lbl_804773DC, (s32)(arg0 + 0x44C));
    TBoss6Mag__sub_803309C4(arg0 + 0x408, (void *)lbl_804773FC);
    d = dispatch_shared_handler_a__6TLobbyFl(0x2E);
    *(s32 *)((s8 *)arg0 + 0x3C0) = (s32)d[0];
    if ((f32)*(s32 *)((s8 *)arg0 + 0x3C0) <= 0.0f) {
        *(s32 *)((s8 *)arg0 + 0x3C0) = 0x96;
    }
    *(f32 *)((s8 *)arg0 + 0x3C4) = d[1];
    if (*(f32 *)((s8 *)arg0 + 0x3C4) <= 0.0f) {
        *(f32 *)((s8 *)arg0 + 0x3C4) = 2.0f;
    }
    ((TBoss6Type2 *)arg0)->init_with_global_table();
    *(f32 *)((s8 *)arg0 + 0x3F8) = 0.0f;
    *(f32 *)((s8 *)arg0 + 0x3FC) = 1.0f;
    *(f32 *)((s8 *)arg0 + 0x400) = 0.0f;
    ((TBoss6Mag *)arg0)->sync_hp();
    TBoss6Type2__sub_8032EA10((T_8032EA10 *)arg0);
    ((TBoss6Mag *)arg0)->set_action(0);
    return arg0;
}

}
