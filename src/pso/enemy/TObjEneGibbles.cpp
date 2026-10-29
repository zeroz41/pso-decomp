#include "pso/player/PlayerAttackParams.h"
#include "pso/enemy/TObjEneRe7Berura_803E4CE0.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/TParticleCtrl.h"
#include "types.h"
#include "pso/player/TObjChara.h"
#include "pso/player/TObjPlayer.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/TObjMotion.h"
#include "pso/enemy/TObjEneGibbles.h"
#include "pso/map/FloorArea.h"
extern "C" void has_flag_0x800__9TObjCharaFv();
extern "C" void test_flag30_512__9TObjCharaFv();
extern "C" void test_flag_1000__9TObjCharaFv();
#include "pso/system/vector.h"

#include "pso/enemy/TUnk_80494938.h"
#include <stddef.h>
#include "pso/boss/TBoss4DarkFalz.h"
#include "pso/enemy/TObjEneLappy.h"
#include "pso/enemy/TObjEneMe3SinowZoa.h"
#include "pso/enemy/TObjEnePanarms.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/misc/RenderFadeState.h"
#include "pso/misc/TLobby.h"
#include "pso/object/TObjFish.h"
extern "C" TObjEnemy *__ct__9TObjEnemyFP7TObject(void *, void *);

struct Vec_802D9EB4 { f32 x, y, z; };

struct Vec_802D7ACC { f32 x, y, z; };

struct V_802DA7A4Base { u8 pad[0x14]; };

struct V_802DA7A4 : V_802DA7A4Base {
    virtual void v0();
    virtual void v1();
    virtual void m2();
    virtual void v3();
    virtual s32 m4();
};

struct Obj_800A6B14;
struct Vec_802DA0BC { s32 x, y, z; };

struct FadeBase_802DB200 { char pad[0x14]; };

struct Fade_802DB200 : FadeBase_802DB200 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual s32 m8();
    char pad2[4];
};

struct ObjBase_802DB200 { char pad[0x18]; };

struct Obj_802DB200 : ObjBase_802DB200 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual s32 m8(f32, f32);
    virtual s32 m9(f32, f32, f32);
    char pad1[0x3C0 - 0x1C];
    Fade_802DB200 sub;
    Fade_802DB200 fades[4];
};

struct VBase_802DAD50 { char pad[0x18]; };

struct VObj_802DAD50 : VBase_802DAD50 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4();
    virtual void m5(); virtual void m6(); virtual void m7(); virtual void m8(); virtual void m9();
    virtual void m10(); virtual void m11(); virtual void m12(); virtual void m13(); virtual void m14();
    virtual void m15(); virtual void m16();
    virtual s32 m17(s32);
};

struct Sub_802D8984 { u8 pad[0x18]; u32 f18; };

struct Prm_802D8984 { u8 pad[0xC]; f32 fC; u8 pad10[8]; s32 f18; };

struct Spawn_802DB7C0 { s32 a; s32 b; s32 c; s32 d; };

struct O_802DBC94;
struct VBase_14_802DBA18 { char pad[0x14]; };

struct VObj_14_802DBA18 : VBase_14_802DBA18 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
};

struct Part_802DBA18 { u8 pad[0x1C]; };

struct G_802DBA18 { u8 pad[0x3DC]; Part_802DBA18 parts[4]; };

struct Base14 { char pad[0x14]; };

struct VObj14 : Base14 {
    virtual s32 m0();
    virtual s32 m1();
    virtual s32 m2();
    virtual s32 m3();
    virtual s32 m4();
    virtual s32 m5();
};

extern "C" {
f32 calc_xz_distance_sq(void *, void *, Vec_802D9EB4 *);
f64 atan2_float(f32, f32);
s32 angle_difference_abs(s32, s32);
extern const f64 TObjEneGibbles__data_80472798;
extern u32 gibbles_combat_stat_entries;
extern const f32 lbl_805DE834;
extern const f32 lbl_805DE85C;
s32 is_target_in_attack_range__14TObjEneGibblesFv(u8 *arg0);
void apply_actor_gravity(TObjEnemy *arg0, s32 *arg1, f32 farg0);
s16 get_attack_params_atp_min(void *);
s32 get_current_floor();
s32 get_enemy_entity();
void check_enemy_body_collisions(void *arg0);
s32 submit_cursor_candidate(void *, int);
u32 get_player_by_client_id(void *);
s32 minimap_render_dot(void *, int, int, int);
s32 play_sound_effect(int, void *, int, int);
void TObjEneGibbles__sub_802D7DAC(s32 arg0);
void TObjEneGibbles__sub_802D9644(void *, int, f32);
extern const f32 TObjEneGibbles__data_805DE7E4;
extern const f32 lbl_805DE838;
void TObjEneGibbles__sub_802D8E8C(u8 *arg0);
void attach_particle_model(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 farg0);
s32 * csnVectorUnder(s32 *, s32, s32, f32);
void *spawn_particle_effect(void *pos, s32 id);
extern const f32 TObjEneGibbles__data_805DE7E8;
extern const f32 TObjEneGibbles__data_805DE7EC;
extern const f32 lbl_805DE7F0;
s32 TObjEneGibbles__sub_802D7BE0(s32 arg0);
extern const f32 TObjEneGibbles__data_805DE7F8;
extern const f32 TObjEneGibbles__data_805DE830;
extern const f32 lbl_805DE874;
f32 random_ratio__9TObjCharaFv(void *, int);
s32 enemy_move_toward(void *, s32, void *, int, f32);
s32 select_enemy_destination(void *, Vec_802DA0BC *, int);
s32 copy_position_if_valid__10TObjPlayerFii(s32 arg0, s32 arg1);
f32 horizontal_distance_squared(int, void *);
extern u8 *TObjEneGibbles__ai_parameters;
extern const f32 lbl_805DE860;
extern const f32 lbl_805DE864;
s32 is_split_screen();
s32 get_camera_mode__11TCameraCtrlFv();
s32 update__15RenderFadeStateFv(void *);
void restore_scene_lighting(void);
void select_actor_lighting(s32 obj);
s32 defer_render__7TObjectFv(void *);
void scale_matrix_vec3(u8 *arg0, u8 *arg1);
void translate_matrix_vec3(u8 *arg0, u8 *arg1);
s32 rotate_matrix_y(int, int);
s32 push_matrix_from(void *);
s32 pop_matrix();
void draw_model__14TObjEneGibblesFPv(TObjEneGibbles *arg0);
f32 subtract_vector(void *, void *);
s32 check_path_obstructed(void *, void *);
u8 * get_player_data__10TObjPlayerFi(s32);
s32 obj_testFlags30__14TObjCollidableFUl(void *, int);
u16 get_entity_id(void *);
s32 is_valid_and_active__10TObjPlayerFUl();
void enemy_set_heading_velocity(void *, s32, f32);
void calc_velocity_toward_destination(void *, Vec_802DA0BC, Vec_802DA0BC, f32);
f32 newton_sqrtf(f32);
s32 TObjEneGibbles__sub_800D8988(void *);
void TObjEneGibbles__sub_802D7A54(void *arg0);
s32 TObjEneGibbles__sub_802D9A04(void *arg0);
extern f32 lbl_805DE80C;
extern const f32 lbl_805DE814;
extern const f32 lbl_805DE828;
extern const f32 lbl_805DE82C;
s32 dispatch_shared_handler_a__6TLobbyFl(int);
s32 register_object__6TLobbyFl(int);
s32 dispatch_shared_handler_b__6TLobbyFl(int);
s32 register_boss__6TLobbyFl(int);
u8 *load_resource_from_descriptor(void *, int, void *, int, int, int);
void *mem_alloc(u32 size);
extern Spawn_802DB7C0 gibbles_resource_binding_desc;
extern s32 gibbles_boss_stat_handle;
extern s32 gibbles_combat_stats_handle;
extern u32 TObjEneGibbles__resource_bundle;
void copy_position__20TBoss3VoloptHiraisinFv(s32 arg0);
void init_collision_body_parts(void *, void *, int);
void *__ct__14TObjCollidableFP7TObject(void *, int);
void * __nw__7TObjectFUl(int);
void __construct_array(void *, void *, void *, int, int);
void *__dt__15RenderFadeStateFv(void *arg0, s16 arg1);
void __ct__15RenderFadeStateFv(void);
extern s32 lbl_805D3F60;
u8 *TObjEneGibbles__ct(u8 *arg0, void *arg1, s32 arg2);
s32 update_movement_status__9TObjCharaFv();
s32 update_movement_status__14TObjEneGibblesFv(u8 *arg0);
s32 update_action_hold_status__9TObjCharaFv();
s32 update_action_hold_status__14TObjEneGibblesFv(u8 *arg0);
struct Stack_802D7BE0 {
    s32 sp8;
    f32 spC;
};

struct Stack_802D8140
{
  f32 sp8;
  f32 spC;
  f32 sp10;
};

struct Stack_802D7ED4 {
    s32 sp8;
    s32 spC;
    s32 sp10;
};

struct RecoveredGlobal_802D7ED4_lbl_80472780 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_802D7ED4_lbl_8058D490 {
    s32 value;
    u8 remaining[0x2C];
};


typedef char RecoveredGlobal_802D7ED4_lbl_80472780_size[sizeof(RecoveredGlobal_802D7ED4_lbl_80472780) == 0x10 ? 1 : -1];

typedef char RecoveredGlobal_802D7ED4_lbl_8058D490_size[sizeof(RecoveredGlobal_802D7ED4_lbl_8058D490) == 0x30 ? 1 : -1];

typedef struct Stack_802D8140 Stack_802D8140;

struct GibBase_802da394_802D87D8 { char pad[0x14]; };

struct GibVObj_802da394_802D87D8 : GibBase_802da394_802D87D8 {
    virtual s32 m0();
    virtual s32 m1();
    virtual s32 m2();
    virtual s32 m3();
    virtual s32 m4();
    virtual s32 m5();
};

struct VBase802DAAC8_802daac8_802D87D8 { char pad[0x14]; };

struct VObj802DAAC8_802daac8_802D87D8 : VBase802DAAC8_802daac8_802D87D8 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual s32 m8();
};

struct E_802DBC94 { s32 a; s32 b; s32 c; s32 d; };

struct G_802DBC94 { u8 pad[0x42c]; E_802DBC94 *e; };

struct O_802DBC94 { u8 pad[0x24]; s32 f24; u8 pad2[0xc]; s32 f34; };

struct RecoveredGlobal_800A6BE0_lbl_804FF5E8 {
    s32 value;
    u8 remaining[0x24];
};

struct RecoveredGlobal_800A6BE0_lbl_80500978 {
    s32 value;
    u8 remaining[0xC];
};

struct Vec_800A6B14 { f32 x, y, z; };

struct Tgt_800A6B14 { u8 pad[0x2fc]; Vec_800A6B14 pos; };

struct Obj_800A6B14 {
    u8 pad[0x60]; s32 angle;
    u8 pad2[0x2a8 - 0x64]; Tgt_800A6B14 *target;
    u8 pad3[0x2fc - 0x2ac]; Vec_800A6B14 pos;
};

struct Vec_800A6B14;

struct Vec_802D8828 { f32 x, y, z; };

struct Vec_802D9D64 { f32 x, y, z; };

typedef char RecoveredGlobal_800A6BE0_lbl_804FF5E8_size[sizeof(RecoveredGlobal_800A6BE0_lbl_804FF5E8) == 0x28 ? 1 : -1];

typedef char RecoveredGlobal_800A6BE0_lbl_80500978_size[sizeof(RecoveredGlobal_800A6BE0_lbl_80500978) == 0x10 ? 1 : -1];

struct Arg_802D9A04 { s32 a; f32 b; };

struct VBase_802D9A04 { char pad[0x18]; };

struct VObj_802D9A04 : VBase_802D9A04 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20();
    virtual f32 m21(void *, Arg_802D9A04 *, s32, s32, s32);
    virtual void m22();
    virtual void m23(void *);
};

struct Hit_802D9B80 { s32 x; f32 y; };

struct Vec_802D9B80 { f32 x, y, z; };

struct VBase_18_22e4b0 { char pad[0x18]; };

struct VObj_18_22e4b0 : VBase_18_22e4b0 {
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
    virtual s32 m21(s32, struct Hit_802D9B80 *, s32, s32, s32);
    virtual void m22();
    virtual s32 m23(s32);
};

s32 get_main_phase();
f32 calc_distance_to_client__10TObjPlayerFlUsUl(void *, u16, Vec_802D8828 *);
s32 obj_setFlags30(void *, int);
s32 queue_destruction__7TObjectFv();
void TLobby__sub_8001FE7C(void*, int);
void TCameraCtrl__sub_8006A044(s32, f32);
s32 *csnVecterUnder(s32 origin, s32 mask);
s32 rotate_xz_pair_by_angle(f32 *, f32 *, s32, f32);
s32 test_action_mask__10TObjPlayerFl(void *, int);
s32 TObjEneMe3SinowZoa__sub_800D758C(void *);
void TObjPlayer__sub_800D93C4(s32 point, s32 delay);
void * __ct__11TObjControlFP7TObject(void *, void *);
s32 angle_diff_s16(s32, s32);
s32 lerp_angle_half__Fll(s32, s32);
void mem_free(void*);
s32 get_room__8TObjBaseFv(void *);
void TObjEneGibbles__sub_802D7E3C(void);
void render_and_get_joint_pos__14TObjEneGibblesFPvii(u8 *arg0, s32 arg1, s32 arg2);
void TObjEneGibbles__sub_802D8034(void);
void vfunc_63__14TObjEneGibblesFv(void *arg0);
void TObjEneGibbles__sub_802D8580(TObjEneGibbles *self);
void vfunc_61__14TObjEneGibblesFv(void *arg0);
s32 test_flag_256__14TObjEneGibblesFv(u8 *arg0);
struct Gib_802D9110;
void TObjEneGibbles__sub_802D9110(Gib_802D9110 *);
void vfunc_60__14TObjEneGibblesFv(u8 *arg0);
void vfunc_58__14TObjEneGibblesFv(u8 *arg0);
void run_task__14TObjEneGibblesFv(TObjEneGibbles *arg0);
void* get_center__14TObjEneGibblesFv(void* p);
s32 vec3_add_to(f32 *, void *);
s32 matrix_mult_vec(int, void *, void *);
s32 rotate_matrix_x(s32, s32);
f32 post_translate_matrix(void *);

extern const f32 TObjEneGibbles__data_805DE7F4;
extern const f32 TObjEneGibbles__data_805DE81C;
extern RecoveredGlobal_802D7ED4_lbl_80472780 gibbles_joint_zero_vec;
extern RecoveredGlobal_802D7ED4_lbl_8058D490 identity_matrix;
extern s32 local_client_id;
extern s32 anim_model_matrix_array;
extern s32 lbl_805D5868;
extern const f32 lbl_805DE7E0;
extern const f32 lbl_805DE7FC;
extern const f32 lbl_805DE800;
extern const f32 lbl_805DE804;
extern const f32 lbl_805DE808;
extern const f32 lbl_805DE810;
extern const f32 lbl_805DE858;
extern const f32 lbl_805DE868;
extern const f32 lbl_805DE86C;
extern const f32 lbl_805DE870;
extern f32 lbl_805DE878;
extern void *tl_04;

struct Obj_802DAD50 : VObj_802DAD50 {
    u16 f1C;
    u8 pad1E[0x30 - 0x1E];
    u32 f30;
    u8 pad34[0x2A8 - 0x34];
    u8 *target;
    u8 pad2AC[0x2FC - 0x2AC];
    Vec_800A6B14 pos;
    u8 pad308[0x338 - 0x308];
    u16 f338;
    u8 pad33A[0x350 - 0x33A];
    f32 *range;
    u8 pad354[0x374 - 0x354];
    u32 f374;
    u32 target_class_mask;
};

struct Gib_802D8984 {
    u8 pad0[0x30];
    u32 f30;
    u8 pad34[4];
    Vec_800A6B14 pos;
    u8 pad44[0x60 - 0x44];
    s32 angle;
    u8 pad64[0xA4 - 0x64];
    Sub_802D8984 *fA4;
    u8 padA8[0xB8 - 0xA8];
    s16 fB8;
    u8 padBA[0xC0 - 0xBA];
    f32 fC0;
    f32 fC4;
    f32 fC8;
    u8 padCC[0x290 - 0xCC];
    Vec_802DA0BC f290;
    Vec_802DA0BC f29C;
    Gib_802D8984 *target;
    u8 pad2AC[0x2FC - 0x2AC];
    Vec_802DA0BC f2FC;
    u8 pad308[0x326 - 0x308];
    s16 mode;
    s16 sub;
    u8 pad32A[0x338 - 0x32A];
    u16 idx;
    u8 pad33A[0x374 - 0x33A];
    u32 f374;
    u8 pad378[0x38C - 0x378];
    f32 f38C;
    f32 f390;
    u8 pad394[0x3A4 - 0x394];
    s32 f3A4;
    s32 f3A8;
};

extern "C" {
void update_target__14TObjEneGibblesFPv(Obj_802DAD50 *self);
}

extern "C" {
void vfunc_6__8TObjBaseFPsl();
}
struct GibblesBody { u8 pad[0x18]; u32 flags; u8 pad1C[0x10]; };
extern "C" {
void TObjEneGibbles__sub_802D8464(TObjEneGibbles *self);
}
extern "C" {
struct Gib_802DB920;
Gib_802DB920 *TObjEneGibbles__sub_802DB920(Gib_802DB920 *self, s16 arg1);
}
extern "C" {
void vfunc_29__9TObjCharaFv();
}
extern "C" {
void recalc_stats__9TObjCharaFv();
}
extern "C" {
void consume_timer_field__9TObjCharaFl();
}
extern "C" {
void vfunc_67__9TObjCharaFf();
}
extern "C" {
void vfunc_66__9TObjCharaFv();
}
extern "C" {
void get_anim_node_position__9TObjCharaFlP3Vec();
}
extern "C" {
void apply_slow_status__9TObjCharaFv();
}
extern "C" {
void update_shock_clock__9TObjCharaFv();
}
extern "C" {
void vfunc_43__9TObjCharaFv();
}
extern "C" {
void vfunc_18__9TObjCharaFPUc();
}
extern "C" {
void interact__14TObjCollidableFl();
}
extern "C" {
void vfunc_74__9TObjEnemyFl();
}
extern "C" {
void apply_hit_message_flags__9TObjEnemyFPv();
}
extern "C" {
void add_actor_exp__9TObjCharaFl();
}
extern "C" {
void apply_action_hold_status__9TObjCharaFf();
}
extern "C" {
void apply_anti_technique__9TObjCharaFl();
}
extern "C" {
void apply_attack_stat_status__9TObjCharaFPv();
}
extern "C" {
void apply_confusion_status__9TObjCharaFv();
}
extern "C" {
void apply_knockback_from_attacker__9TObjCharaFPUcf();
}
extern "C" {
void apply_movement_ailment__9TObjCharaFl();
}
extern "C" {
void apply_object_set_data__8TObjBaseFPv();
}
extern "C" {
void apply_paralysis__9TObjCharaFv();
}
extern "C" {
void apply_poison_status__9TObjCharaFv();
}
extern "C" {
void apply_set_data__9TObjEnemyFPv();
}
extern "C" {
void apply_shock_status__9TObjCharaFv();
}
extern "C" {
void apply_switch_attack__9TObjCharaFv();
}
extern "C" {
void calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf();
}
extern "C" {
void vfunc_79__9TObjEnemyFPl();
}
extern "C" {
void classify_actor_view_detail__8TObjBaseFfff();
}
extern "C" {
void clear_all_status_effects__9TObjCharaFv();
}
extern "C" {
void clear_harmful_statuses__9TObjCharaFv();
}
extern "C" {
void cure_paralysis__9TObjCharaFv();
}
extern "C" {
void cure_poison_ailment__9TObjCharaFv();
}
extern "C" {
void enemy_spawn_jellen_effect__9TObjCharaFv();
}
extern "C" {
void enemy_spawn_zalure_effect__9TObjCharaFv();
}
extern "C" {
void vfunc_78__9TObjCharaFl();
}
extern "C" {
void vfunc_77__9TObjCharaFv();
}
extern "C" {
void vfunc_76__9TObjCharaFv();
}
extern "C" {
void vfunc_75__9TObjCharaFf();
}
extern "C" {
void clear_lobby_object_state__9TObjEnemyFv();
}
extern "C" {
void get_actor_level_index__9TObjCharaFv();
}
extern "C" {
void get_name__9TObjEnemyFv();
}
extern "C" {
void get_pos__9TObjCharaFl();
}
extern "C" {
void is_actor_cadence_frame__9TObjCharaFl();
}
extern "C" {
extern u8 lbl_80472628[];
}
extern "C" {
extern u8 lbl_80472638[];
}
extern "C" {
extern u8 lbl_80472650[];
}
extern "C" {
extern u8 lbl_80472668[];
}
extern "C" {
extern u8 lbl_8047267C[];
}
extern "C" {
extern u8 lbl_80472690[];
}
extern "C" {
extern u8 lbl_804726A4[];
}
extern "C" {
extern u8 lbl_804726B8[];
}
extern "C" {
extern u8 lbl_804726D0[];
}
extern "C" {
extern u8 lbl_804726E4[];
}
extern "C" {
extern u8 lbl_804726F8[];
}
extern "C" {
extern u8 lbl_8047270C[];
}
extern "C" {
extern u8 lbl_80472720[];
}
extern "C" {
extern u8 lbl_80472730[];
}
extern "C" {
void receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll();
}
extern "C" {
void receive_physical_attack__9TObjCharaFPvf();
}
extern "C" {
void receive_weapon_special_attack__9TObjCharaFPvPv();
void apply_defense_stat_status__9TObjCharaFPv();
}
extern "C" {
void render_shadows__9TObjEnemyFv(u8 *arg0);
}
extern "C" {
void reset_motion_fields__9TObjCharaFv();
}
extern "C" {
void reset_pose__9TObjCharaFv();
}
extern "C" {
void roll_physical_accuracy__9TObjCharaFPvlf();
}
extern "C" {
void select_melee_contact_body__9TObjCharaFPvf();
}
extern "C" {
void trigger_switch_attack__9TObjCharaFv(s32 arg0);
}
extern "C" {
void try_start_action__9TObjCharaFll();
}
extern "C" {
s32 vfunc_37__9TObjCharaFv(u8 *arg0);
}
extern "C" {
void update_actor_ground_y__9TObjCharaFv();
}
extern "C" {
s32 update_attack_stat_status__9TObjCharaFv(u8 *arg0);
}
extern "C" {
s32 update_defense_stat_status__9TObjCharaFv(u8 *arg0);
}
extern "C" {
void update_flag30_timer__9TObjCharaFv();
}
extern "C" {
void update_object_view_visibility__8TObjBaseFff();
}
extern "C" {
void update_poison_status__9TObjCharaFv();
}
extern void *TObjEneGibbles__model_filenames[2];
extern void *TObjEneGibbles__motion_names_and_resource_descriptor[11];
extern void *lbl_804E286C[2];
extern void *gibbles_motion_name_table[11];
void vfunc_59__14TObjEneGibblesFv(void *arg0);
__declspec(section ".data") void *TObjEneGibbles__model_filenames[2] = {
    (void *)&lbl_80472628, (void *)0x0,
};
void *TObjEneGibbles__motion_names_and_resource_descriptor[11] = {
    (void *)&lbl_80472638, (void *)&lbl_80472650, (void *)&lbl_80472668, (void *)&lbl_8047267C,
    (void *)&lbl_80472690, (void *)&lbl_804726A4, (void *)&lbl_804726B8, (void *)&lbl_804726D0,
    (void *)&lbl_804726E4, (void *)&lbl_804726F8, (void *)0x0,
};
void *lbl_804E285C[4] = {
    (void *)&lbl_8047270C, (void *)&TObjEneGibbles__model_filenames, (void *)&TObjEneGibbles__motion_names_and_resource_descriptor, (void *)0x1000a,
};
__declspec(section ".data") void *lbl_804E286C[2] = {
    (void *)&lbl_80472720, (void *)0x0,
};
void *gibbles_motion_name_table[11] = {
    (void *)&lbl_80472638, (void *)&lbl_80472650, (void *)&lbl_80472668, (void *)&lbl_8047267C,
    (void *)&lbl_80472690, (void *)&lbl_804726A4, (void *)&lbl_804726B8, (void *)&lbl_804726D0,
    (void *)&lbl_804726E4, (void *)&lbl_804726F8, (void *)0x0,
};
void *lbl_804E28A0[4] = {
    (void *)&lbl_80472730, (void *)&lbl_804E286C, (void *)&gibbles_motion_name_table, (void *)0x1000a,
};
TObjMotionAction gibbles_action_table[10] = {
    {1, 0, 8, 0.3f, 1},
    {1, 0, 9, 0.5f, 1},
    {2, 0, 0, 0.7f, 4},
    {2, 0, 7, 0.6f, 4},
    {1, 0, 5, 0.3f, 4},
    {2, 6, 4, 0.7f, 4},
    {1, 0, 6, 0.7f, 4},
    {1, 0, 3, 0.8f, 0x20},
    {2, 0, 1, 0.8f, 8},
    {3, 0, 2, 0.7f, 0x10},
};
void *lbl_804E2950[7] = {
    (void *)0x437a0000, (void *)0x3fa00000, (void *)0x400, (void *)0x0,
    (void *)0x64, (void *)0x0, (void *)0x0,
};
void *lbl_804E296C[33] = {
    (void *)0x0, (void *)0x41700000, (void *)0x0, (void *)0x41700000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x41700000, (void *)0x0,
    (void *)0x0, (void *)0x8003, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x41f00000, (void *)0x0, (void *)0x0,
    (void *)0x8003, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0,
};
void *lbl_804E29F0[83] = {
    (void *)0x0, (void *)0x0, (void *)&TObjEneGibbles__sub_802DB920, (void *)&run_task__14TObjEneGibblesFv,
    (void *)&draw_model__14TObjEneGibblesFPv, (void *)&render_shadows__9TObjEnemyFv, (void *)&vfunc_6__8TObjBaseFPsl, (void *)&apply_object_set_data__8TObjBaseFPv,
    (void *)&reset_motion_fields__9TObjCharaFv, (void *)&get_center__14TObjEneGibblesFv, (void *)&update_object_view_visibility__8TObjBaseFff, (void *)&classify_actor_view_detail__8TObjBaseFfff,
    (void *)&get_name__9TObjEnemyFv, (void *)&interact__14TObjCollidableFl, (void *)&add_actor_exp__9TObjCharaFl, (void *)&consume_timer_field__9TObjCharaFl,
    (void *)&get_actor_level_index__9TObjCharaFv, (void *)&update_actor_ground_y__9TObjCharaFv, (void *)&vfunc_18__9TObjCharaFPUc, (void *)&is_actor_cadence_frame__9TObjCharaFl,
    (void *)&select_melee_contact_body__9TObjCharaFPvf, (void *)&calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf, (void *)&receive_physical_attack__9TObjCharaFPvf, (void *)&receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll,
    (void *)&receive_weapon_special_attack__9TObjCharaFPvPv, (void *)&apply_knockback_from_attacker__9TObjCharaFPUcf, (void *)&try_start_action__9TObjCharaFll, (void *)&roll_physical_accuracy__9TObjCharaFPvlf,
    (void *)&update_target__14TObjEneGibblesFPv, (void *)&vfunc_29__9TObjCharaFv, (void *)&is_target_in_attack_range__14TObjEneGibblesFv, (void *)&test_flag_256__14TObjEneGibblesFv,
    (void *)&test_flag30_512__9TObjCharaFv, (void *)&has_flag_0x800__9TObjCharaFv, (void *)&test_flag_1000__9TObjCharaFv, (void *)&update_poison_status__9TObjCharaFv,
    (void *)&update_action_hold_status__14TObjEneGibblesFv, (void *)&vfunc_37__9TObjCharaFv, (void *)&update_flag30_timer__9TObjCharaFv, (void *)&update_movement_status__14TObjEneGibblesFv,
    (void *)&update_shock_clock__9TObjCharaFv, (void *)&update_attack_stat_status__9TObjCharaFv, (void *)&update_defense_stat_status__9TObjCharaFv, (void *)&vfunc_43__9TObjCharaFv,
    (void *)&apply_poison_status__9TObjCharaFv, (void *)&apply_paralysis__9TObjCharaFv, (void *)&apply_slow_status__9TObjCharaFv, (void *)&apply_confusion_status__9TObjCharaFv,
    (void *)&apply_movement_ailment__9TObjCharaFl, (void *)&apply_shock_status__9TObjCharaFv, (void *)&clear_harmful_statuses__9TObjCharaFv, (void *)&apply_attack_stat_status__9TObjCharaFPv,
    (void *)&apply_defense_stat_status__9TObjCharaFPv, (void *)&cure_poison_ailment__9TObjCharaFv, (void *)&cure_paralysis__9TObjCharaFv, (void *)&clear_all_status_effects__9TObjCharaFv,
    (void *)&apply_action_hold_status__9TObjCharaFf, (void *)&apply_anti_technique__9TObjCharaFl, (void *)&vfunc_58__14TObjEneGibblesFv, (void *)&vfunc_59__14TObjEneGibblesFv,
    (void *)&vfunc_60__14TObjEneGibblesFv, (void *)&vfunc_61__14TObjEneGibblesFv, (void *)&TObjEneGibbles__sub_802D8464, (void *)&vfunc_63__14TObjEneGibblesFv,
    (void *)&reset_pose__9TObjCharaFv, (void *)&get_anim_node_position__9TObjCharaFlP3Vec, (void *)&vfunc_66__9TObjCharaFv, (void *)&vfunc_67__9TObjCharaFf,
    (void *)&get_pos__9TObjCharaFl, (void *)&apply_switch_attack__9TObjCharaFv, (void *)&enemy_spawn_jellen_effect__9TObjCharaFv, (void *)&trigger_switch_attack__9TObjCharaFv,
    (void *)&enemy_spawn_zalure_effect__9TObjCharaFv, (void *)&recalc_stats__9TObjCharaFv, (void *)&vfunc_74__9TObjEnemyFl, (void *)&vfunc_75__9TObjCharaFf,
    (void *)&vfunc_76__9TObjCharaFv, (void *)&vfunc_77__9TObjCharaFv, (void *)&vfunc_78__9TObjCharaFl, (void *)&vfunc_79__9TObjEnemyFPl,
    (void *)&apply_hit_message_flags__9TObjEnemyFPv, (void *)&apply_set_data__9TObjEnemyFPv, (void *)&clear_lobby_object_state__9TObjEnemyFv,
};

void TObjEneGibbles::set_min_clamped_entry_value(s32 arg0, s32 arg1, f32 farg0) {
  f32 var_f1;
  var_f1 = farg0;
  if (var_f1 < lbl_805DE7E0)
  {
    var_f1 = lbl_805DE7E0;
  }
  gibbles_action_table[arg1].speed = var_f1;
}

void TObjEneGibbles__sub_802D7A54(void *arg0) {
    s16 t;
    s16 u;
    u32 r;
    if ((get_main_phase() == 0xF || is_split_screen() == 0) && (r = get_player_by_client_id((void *)local_client_id)) != 0) {
        t = get_room__8TObjBaseFv((void *)r);
        u = get_room__8TObjBaseFv(arg0);
        if (u == t) {
            TCameraCtrl__sub_8006A044(0x1E, lbl_805DE7E0);
        }
    }
}

s32 TObjEneGibbles::spawn_ground_impact_effects(void *pos, f32 farg0) {
    Vec_802D7ACC v;
    f32 y;
    s32 *hit;
    u8 *p;
    if (farg0 <= TObjEneGibbles__data_805DE7E4) {
        return 0;
    }
    VecCopy((Vec *)((Vec_800A6B14 *)&v), (const Vec *)((const Vec_800A6B14 *)pos));
    y = v.y;
    v.y = y + TObjEneGibbles__data_805DE7E8;
    hit = (s32 *)csnVectorUnder((s32 *)&v, (s32)this + 0x120, 5, y);
    if ((hit != NULL) && (hit[0] & 4)) {
        p = (u8 *)spawn_particle_effect((void *)(hit[1] + 0x38), 0x49);
        if (p != NULL) {
            attach_particle_model(p, TParticleCtrl::get_particle_model(2), TParticleCtrl::get_instance(), 0, 1, TObjEneGibbles__data_805DE7EC);
            ((TParticleCtrl *)p)->set_scale(farg0, TObjEneGibbles__data_805DE7EC);
        }
        p = (u8 *)spawn_particle_effect((void *)(hit[1] + 0x38), 0xA4);
        if (p != NULL) {
            ((TParticleCtrl *)p)->set_scale(farg0, lbl_805DE7F0);
        }
        return 1;
    }
    return 0;
}

s32 TObjEneGibbles__sub_802D7BE0(s32 arg0) {
    Stack_802D7BE0 stack;
    f32 temp_f1;
    s32 *temp_r3;
    VecCopy((Vec *)(&stack.sp8), (const Vec *)(arg0 + 0x38));
    temp_f1 = stack.spC;
    stack.spC = temp_f1 + TObjEneGibbles__data_805DE7E8;
    temp_r3 = (s32 *)(csnVectorUnder(&stack.sp8, arg0 + 0x120, 0x15, temp_f1));
    if (temp_r3 != NULL) {
        if (*temp_r3 & 4) {
            ((TObjEneGibbles *)arg0)->spawn_ground_impact_effects((void *)((void *) (arg0 + 0x38)), TObjEneGibbles__data_805DE7F4);
            return 0;
        }
        spawn_particle_effect((void *)(arg0 + 0x38), 0x20E);
        return 1;
    }
    return 2;
}

void TObjEneGibbles::play_distance_sound() {
    s32 arg0 = (s32)this;
    if (((TObjMotion *)arg0)->is_passing_frame((f32)TObjEneGibbles__data_805DE7F8) != 0) {
        if (((s32)spawn_ground_impact_effects((void *)((void *)(arg0 + 0x38)), TObjEneGibbles__data_805DE7F4)) != 0) {
            TObjEneGibbles__sub_800D8988((void *) (arg0 + 0x38));
            return;
        }
        play_sound_effect((int)((void *) (((s32)((TObjEneGibbles*)((void *)(arg0)))->resolve_sound_id((u32)(0x3A83D))))), (void *)((void *) (arg0 + 0x38)), 0, 0);
        return;
    }
    if (((TObjMotion *)arg0)->is_passing_frame((f32)lbl_805DE7FC) != 0) {
        if (((s32)spawn_ground_impact_effects((void *)((void *)(arg0 + 0x38)), TObjEneGibbles__data_805DE7F4)) != 0) {
            TObjEneGibbles__sub_800D8988((void *) (arg0 + 0x38));
            return;
        }
        play_sound_effect((int)((void *) (((s32)((TObjEneGibbles*)((void *)(arg0)))->resolve_sound_id((u32)(0x3A83E))))), (void *)((void *) (arg0 + 0x38)), 0, 0);
        return;
    }
    if (((TObjMotion *)arg0)->is_passing_frame((f32)lbl_805DE800) != 0) {
        if (((s32)spawn_ground_impact_effects((void *)((void *)(arg0 + 0x38)), TObjEneGibbles__data_805DE7F4)) != 0) {
            TObjEneGibbles__sub_800D8988((void *) (arg0 + 0x38));
            return;
        }
        play_sound_effect((int)((void *) (((s32)((TObjEneGibbles*)((void *)(arg0)))->resolve_sound_id((u32)(0x3A83F))))), (void *)((void *) (arg0 + 0x38)), 0, 0);
    }
}

void TObjEneGibbles__sub_802D7DAC(s32 arg0) {
    if ((((TObjMotion *)arg0)->is_passing_frame((f32)lbl_805DE804) != 0) || (((TObjMotion *)arg0)->is_passing_frame((f32)lbl_805DE808) != 0)) {
        if (((s32)((TObjEneGibbles *)arg0)->spawn_ground_impact_effects((void *)((void *) (arg0 + 0x38)), TObjEneGibbles__data_805DE7F4)) != 0) {
            TObjEneGibbles__sub_800D8988((void *) (arg0 + 0x38));
            return;
        }
        play_sound_effect((int)((void *) (((s32)((TObjEneGibbles*)((void *)(arg0)))->resolve_sound_id((u32)(0x3A82B))))), (void *)((void *) (arg0 + 0x38)), 0, 0);
    }
}

void TObjEneGibbles__sub_802D7E3C(void) {  }

void TObjEneGibbles::update_shadow_height() {
    *(f32 *)((s8 *)this->bodies + 4) = (f32) (this->m_300 - this->position.y);
}

void TObjEneGibbles::update_position() {
    u8 *arg0 = (u8 *)this;

    VecCopy((Vec *)(arg0 + 0x2FC), &this->position);
    this->m_300 = (f32) (this->m_300 + TObjEneGibbles__data_805DE7E8);
    switch (this->mode) {
    case 2:
    case 6:
    case 0xA:
        this->m_300 = (f32) (this->m_300 + this->m_38c);
        break;
    }
}

void render_and_get_joint_pos__14TObjEneGibblesFPvii(u8 *enemy, s32 arg1, s32 arg2) {
    typedef char sp8_offset[(offsetof(Stack_802D7ED4, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_802D7ED4, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_802D7ED4, sp10) == 0x8) ? 1 : -1];
    Stack_802D7ED4 stack;
    set_motion_packed_rotation();
    push_matrix_from((void *) (&identity_matrix.value));
    post_translate_matrix((void *) (enemy + 0x38));
    rotate_matrix_y(0, (int) (((TObjEnemy *)enemy)->rotation_y));
    scale_matrix_vec3(0, (enemy + 0x68));
    set_motion_packed_rotation();
    ((TObjEnemy *)enemy)->calc_joint_matrices((f32) (((TObjEnemy *)enemy)->frame));
    clear_motion_packed_rotation();
    pop_matrix();
    push_matrix_from((void *) (anim_model_matrix_array + (arg2 * 0x30)));
    stack.sp8 = *(s32 *)((s8 *)(&gibbles_joint_zero_vec.value) + 0);
    stack.spC = *(s32 *)((s8 *)(&gibbles_joint_zero_vec.value) + 4);
    stack.sp10 = *(s32 *)((s8 *)(&gibbles_joint_zero_vec.value) + 8);
    matrix_mult_vec(0, (void *) (&stack.sp8), (void *)arg1);
    pop_matrix();
    clear_motion_packed_rotation();
}
}
void gibbles_render_node_callback(void);
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 TObjEneGibbles__render_node_index;
extern s32 TObjEneGibbles__render_rotation_x;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;
extern const f32 lbl_805DE87C;
extern const f32 lbl_805DE880;
extern const f32 lbl_805DE884;
extern s32 lbl_80472768[];
extern s32 lbl_80472774[];
extern s32 registered_player_count;
extern s32 lbl_805D5870;
extern const f32 lbl_805DE824;
void move_with_wall_slide(u8 *arg0);
int initialize_enemy_photon_effect(void *p);

u32 TObjEneGibbles::resolve_sound_id(u32 sound_id) {
  s32 area;
  u32 pvVar2;
  area = get_current_floor_area();
  if (sound_id == 0x3a83d) {
    pvVar2 = (u32)(0x4003a321);
    if (area != AREA_TOWER) {
      pvVar2 = sound_id;
    }
  }
  else if (sound_id == 0x3a83e) {
    pvVar2 = (u32)(0x4003a322);
    if (area != AREA_TOWER) {
      pvVar2 = sound_id;
    }
  }
  else if (sound_id == 0x3a83f) {
    pvVar2 = (u32)(0x4003a323);
    if (area != AREA_TOWER) {
      pvVar2 = sound_id;
    }
  }
  else {
    pvVar2 = (u32)(((TObjEnemy *)(this))->remap_sound_for_area((s32)(sound_id)));
  }
  return pvVar2;
}

extern "C" {

void TObjEneGibbles__sub_802D8034(void) {  }

void TObjEneGibbles::sync_state() {
    s32 temp_r3;

    switch (this->m_380) {
    case 0x0:
        break;
    default:
        update_move_state();
    case 0x107:
    case 0x10E:
        if (this->m_374 & 4) {
            if ((s32) *(s32 *)&this->unk_384 != (s32) this->m_380) {
                *(s32 *)&this->unk_384 = this->m_380;
            }
        }
        break;
    }
}

void TObjEneGibbles::update_move_state() {
    s16 temp_r0;
    s16 temp_r6;

    temp_r0 = *(s16 *)&this->unk_38A;
    temp_r6 = this->m_388;
    if (temp_r0 == temp_r6) {
        this->m_380 = 0x101;
        return;
    }
    if ((lbl_805DE80C * (f32) temp_r0) < (f32) temp_r6) {
        this->m_380 = 0x102;
        return;
    }
    if (temp_r6 > 0) {
        this->m_380 = 0x103;
        return;
    }
    this->m_380 = 0;
}

void TObjEneGibbles::sub_802D8140() {
  Stack_802D8140 stack;
  switch (this->phase)
  {
    case 0:
      this->phase = 1;
      *((f32 *) (((s8 *) ((u8 *)this)) + 0x3A0)) = (f32) TObjEneGibbles__data_805DE7E4;
      apply_actor_gravity((TObjEnemy *)this, (s32 *)(0), TObjEneGibbles__data_805DE7E4);
      play_sound_effect((int)((void *) ((s32)this->resolve_sound_id((u32)(0x3A333)))), (void *)(((u8 *)this) + 0x38), 0, 0);
      return;
    case 1:
      advance_animation();
      if ((this->motion_flags) & 0x10)
    {
      this->phase = 4;
      stack.sp8 = TObjEneGibbles__data_805DE7E4;
      stack.spC = TObjEneGibbles__data_805DE7E4;
      stack.sp10 = lbl_805DE810;
      rotate_xz_pair_by_angle(&stack.sp8, &stack.sp10, this->rotation_y, TObjEneGibbles__data_805DE7E4);
      vec3_add_to(&stack.sp8, ((u8 *)this) + 0x38);
      TObjPlayer__sub_800D93C4((s32)&stack.sp8, 0xA);
      ((TObjPlayer *)(&stack.sp8))->spawn_effect_at_ground(0x46);
    }
    case 2:
      return;
    case 4:
      *((f32 *) (((s8 *) ((u8 *)this)) + 0x3C)) = (f32) ((*((f32 *) (((s8 *) ((u8 *)this)) + 0x3C))) - lbl_805DE7E0);
      *((f32 *) (((s8 *) ((u8 *)this)) + 0x3A0)) = (f32) ((*((f32 *) (((s8 *) ((u8 *)this)) + 0x3A0))) + lbl_805DE7E0);
      if ((*((f32 *) (((s8 *) ((u8 *)this)) + 0x3A0))) > lbl_805DE814)
    {
      this->phase = 3;
      return;
    }
      break;
    case 3:
      queue_destruction__7TObjectFv();
      break;
    return;
  }
}

void TObjEneGibbles::vfunc_63() {
    void *temp_r4;

    if ((s16) this->mode != 9) {
        this->mode = 9;
        this->phase = 0;
        this->requested_action = 9;
        temp_r4 = this->bodies;
        *(s32 *)((s8 *)temp_r4 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r4 + 0x18) & 0xFFFFFFFE);
        ((TObjPlayer *)this)->refresh_lobby_state();
        send_entity_set_flags();
    }
}

void TObjEneGibbles::update_action_state() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r4;

    advance_animation();
    clamp_angle(0);
    switch (this->phase) {
    case 2:
        break;
    case 0:
        this->phase = 1;
        apply_actor_gravity((TObjEnemy *)(arg0), (s32 *)(0), TObjEneGibbles__data_805DE7E4);
        play_sound_effect(((TObjEneGibbles*)((void *)((void *)(arg0))))->resolve_sound_id((u32)(0x3AD34)), (void *) (arg0 + 0x38), 0, 0);
        break;
    case 1:
        this->m_310 = (f32) TObjEneGibbles__data_805DE7E4;
        (*(f32 *)&this->unk_308) = (f32) TObjEneGibbles__data_805DE7E4;
        apply_actor_gravity((TObjEnemy *)(arg0), (s32 *)(0), TObjEneGibbles__data_805DE7E4);
        if ((u32) this->action_flags != 8U) {
            this->phase = 3;
        }
        break;
    case 3:
        if (!((this->actorFlags) & 0x800000)) {
            apply_actor_gravity((TObjEnemy *)(arg0), (s32 *)(0), TObjEneGibbles__data_805DE7E4);
        }
        (this->actorFlags) = (s32) ((this->actorFlags) & 0xFFFFF9FF);
        temp_r4 = (unsigned char *) (this->bodies);
        *(s32 *)((s8 *)temp_r4 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r4 + 0x18) & 0xFBFFFFFF);
        this->referenceHp = (s16) this->hp;
        if (random_ratio__9TObjCharaFv((void *)arg0, (int)temp_r4) < *(f32 *)&this->unk_398) {
            this->mode = 6;
            this->phase = 0;
            this->requested_action = 4;
            this->m_374 = (s32) (this->m_374 | 0x90);
        }
        break;
    }
    ((TObjPlayer *)arg0)->check_object_collisions();
    check_enemy_body_collisions((arg0));
    ((TObjPlayer *)arg0)->update_enemy_collision_flags();
    minimap_render_dot((void *) (arg0 + 0x38), -0x5DB4, 1, 0);
    submit_cursor_candidate(arg0, -1);
    (this->actorFlags) = (s32) ((this->actorFlags) & 0xFFDFFFFF);
}

void TObjEneGibbles__sub_802D8464(TObjEneGibbles *self) {
    if (self->mode != 8) {
        if (self->m_374 & 0x100) {
            s32 i;
            self->referenceHp = self->hp;
            self->actorFlags &= ~0x200;
            self->m_2dc = 0;
            for (i = 0; i < self->body_count; i++) {
                ((GibblesBody *)self->bodies)[i].flags &= ~0x04000000;
            }
        } else {
            Vec v;
            u32 pl = get_player_by_client_id((void *)self->m_2d4);
            if (pl != 0) {
                VecCopy(&v, (const Vec *)(pl + 0x2FC));
                subtract_vector(&v, (u8 *)self + 0x2FC);
                angle_difference_abs(self->rotation_y, (s32) (TObjEneGibbles__data_80472798 * atan2_float(v.x, v.z)));
            }
            self->mode = 8;
            self->requested_action = 8;
            self->phase = 0;
            self->actorFlags &= 0xF9DBFFFF;
        }
    }
    ((GibblesBody *)self->bodies)->flags |= 1;
}

extern const f32 lbl_805DE818;
extern const f32 lbl_805DE820;
s16 TObjPlayer__sub_800A776C(void *p);

#pragma push
#pragma fp_contract on
void TObjEneGibbles__sub_802D8580(TObjEneGibbles *self) {
    self->advance_animation();
    self->clamp_angle(0);
    if (!(self->actorFlags & 0x800000)) {
        apply_actor_gravity(self, (s32 *)0, TObjEneGibbles__data_805DE7E4);
    }
    switch (self->phase) {
    case 0:
        self->phase = 1;
        apply_actor_gravity(self, (s32 *)0, TObjEneGibbles__data_805DE7E4);
        if (self->m_3b0 != NULL) {
            self->m_388 = (s16)((f32)self->m_388 - lbl_805DE818 * (f32)(((TObjPlayer *)self->m_3b0)->get_field_2c8() + ((TObjChara *)self->m_3b0)->get_actor_attack_params_atp_min() + TObjPlayer__sub_800A776C(self->m_3b0) - *(s16 *)((u8 *)self + 0x2CE)));
            if (self->m_388 <= 0) {
                self->m_388 = 0;
                self->m_374 |= 8;
            }
        }
        self->actorFlags |= 0x04000000;
        play_sound_effect(self->resolve_sound_id(0x3A330), (u8 *)self + 0x38, 0, 0);
        break;
    case 1:
        if (self->is_passing_frame(TObjEneGibbles__data_805DE81C) != 0) {
            self->m_380 = 0x107;
        }
        if (self->is_passing_frame(lbl_805DE820) != 0) {
            self->actorFlags &= 0xFBFFFEFF;
            self->m_374 &= ~0x20;
            if (self->test_flag_256() != 0) {
                self->phase = 0;
                self->frame = TObjEneGibbles__data_805DE7E4;
            } else {
                self->phase = 3;
            }
            self->update_move_state();
        }
        break;
    case 3:
    default:
        self->actorFlags &= 0xFBFFFEFF;
        self->m_374 &= ~0x20;
        break;
    }
    ((TObjPlayer *)self)->check_object_collisions();
    check_enemy_body_collisions(self);
    ((TObjPlayer *)self)->update_enemy_collision_flags();
    minimap_render_dot((u8 *)self + 0x38, -0x5DB4, 1, 0);
    self->actorFlags &= 0xFFDFFFFF;
}
#pragma pop


void TObjEneGibbles::vfunc_61() {
    s16 temp_r0;
    void *temp_r5;

    temp_r0 = this->mode;
    if ((temp_r0 != 7) && (temp_r0 != 6)) {
        this->mode = 7;
        this->phase = 0;
        this->requested_action = 7;
    }
    temp_r5 = this->bodies;
    *(s32 *)((s8 *)temp_r5 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r5 + 0x18) | 1);
    this->actorFlags = (s32) (this->actorFlags & 0xF99BFFFF);
}

int TObjEneGibbles::test_flag_256() {
    u8 *arg0 = (u8 *)this;
    Vec_802D8828 v;
    u8 *pl;
    s32 i;
    s32 flags;
    flags = this->m_374;
    if (flags & 0x20) {
        return 1;
    }
    if ((flags & 4) && this->mode != 6 && this->m_388 > 0) {
        for (i = 0; i < registered_player_count; i++) {
            pl = get_player_data__10TObjPlayerFi(i);
            if (pl != NULL && !(((TObjPlayer *)pl)->actorFlags & 0x800)
                && calc_distance_to_client__10TObjPlayerFlUsUl(arg0, i, &v) < lbl_805DE824
                && angle_difference_abs(this->rotation_y, (s32) (TObjEneGibbles__data_80472798 * atan2_float(v.x, v.z))) < 0x2AAA
                && test_action_mask__10TObjPlayerFl(pl, 0xE0) != 0) {
                VecCopy((Vec *)((Vec_800A6B14 *) &v), (const Vec *)((Vec_800A6B14 *) (arg0 + 0x2FC)));
                subtract_vector(&v, pl + 0x2FC);
                if (angle_difference_abs(((TObjPlayer *)pl)->rotation_y, (s32) (TObjEneGibbles__data_80472798 * atan2_float(v.x, v.z))) < 0x2AAA) {
                    this->m_3b0 = pl;
                    this->m_374 |= 0x20;
                    return 1;
                }
            }
        }
    }
    return 0;
}

#pragma push
#pragma opt_loop_invariants off

#define F_802D(off, T) (*(T *)(arg0 + (off)))

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline void to_idle_802D8984(Gib_802D8984 *o) {
    enemy_set_heading_velocity(o, o->angle, TObjEneGibbles__data_805DE7E4);
    o->f374 &= ~0x100;
    o->mode = 3;
    o->sub = 0;
    o->fB8 = 1;
    o->f30 &= 0xF9FBFFFF;
}
#define PRM ((Prm_802D8984 *)TObjEneGibbles__ai_parameters)
void TObjEneGibbles::sub_802D8984() {
    Gib_802D8984 *o = (Gib_802D8984 *)this;
    if (o->idx < 0x1000) {
        Gib_802D8984 *p = (Gib_802D8984 *)get_player_by_client_id((void *)o->idx);
        if (p != NULL && ((TObjPlayer *)p)->get_field_3e4() == get_current_floor()) {
            o->target = p;
        } else {
            o->target = NULL;
        }
    } else if (o->idx < 0x4000) {
        o->target = (Gib_802D8984 *)get_enemy_entity();
    } else {
        o->idx = 0xFFFF;
        o->target = NULL;
    }
    ((TObjMotion *)o)->advance_animation();
    ((TObjEneGibbles *)o)->clamp_angle(0);
    switch (o->sub) {
    case 2:
        break;
    case 0:
        o->f38C = TObjEneGibbles__data_805DE7E4;
        if (!(o->f30 & 0x800000)) {
            apply_actor_gravity((TObjEnemy *)((u8 *)o), (s32 *)(0), TObjEneGibbles__data_805DE7E4);
        }
        o->f3A4 = 0;
        if (o->f374 & 0x80) {
            o->f3A8 = PRM->f18;
            TObjEneGibbles::set_min_clamped_entry_value((s32)o, 6, PRM->fC);
        } else {
            o->f3A8 = PRM->f18;
            TObjEneGibbles::set_min_clamped_entry_value((s32)o, 6, PRM->fC);
        }
        o->sub = 4;
        o->f30 &= 0xF9FFFFFF;
        o->f374 &= ~0x80;
        o->f374 |= 0x100;
        break;
    case 4:
        o->f3A4++;
        if (o->f3A4 >= o->f3A8) {
            if (o->target != NULL) {
                Vec_800A6B14 v;
                Vec_802DA0BC t = o->target->f2FC;
                if (select_enemy_destination(o, &t, 1) != 0) {
                    f32 dist;
                    o->sub = 1;
                    {
                        Vec_802DA0BC q = o->f2FC;
                        copy_position_if_valid__10TObjPlayerFii((s32)o, (s32)&q);
                    }
                    VecCopy((Vec *)&v, (const Vec *)((Vec_800A6B14 *)&o->f29C));
                    subtract_vector(&v, &o->f2FC);
                    dist = newton_sqrtf(v.x * v.x + v.z * v.z);
                    dist -= TObjEneGibbles__data_805DE7E8;
                    calc_velocity_toward_destination(o, o->f290, o->f29C, lbl_805DE828 * dist);
                    play_sound_effect(((TObjEneGibbles*)(o))->resolve_sound_id((u32)(0x3A82F)), &o->pos, 0, 0);
                    o->f390 = lbl_805DE82C;
                    o->fB8 = 5;
                    o->f30 |= 0x06000000;
                    o->fA4->f18 &= ~1;
                    goto done;
                }
            }
            ((void (*)(f32, void *, s32))enemy_set_heading_velocity)(TObjEneGibbles__data_805DE7E4, o, o->angle);
            o->f374 &= ~0x100;
            o->mode = 3;
            o->sub = 0;
            o->fB8 = 1;
            o->f30 &= 0xF9FBFFFF;
        done:
            TObjEneGibbles__sub_802D7BE0((s32)o);
        }
        submit_cursor_candidate(o, -1);
        break;
    case 1:
        if (o->fC0 >= TObjEneGibbles__data_805DE7F8) {
            move_with_wall_slide((u8 *)o);
            o->f38C += o->f390;
            if (o->fC0 >= lbl_805DE814) {
                o->f390 -= TObjEneGibbles__data_805DE830;
            } else {
                o->f390 -= lbl_805DE80C;
            }
        }
        if (((TObjMotion *)o)->is_passing_frame(o->fC4 - TObjEneGibbles__data_805DE7EC - o->fC8) != 0) {
            o->sub = 3;
            o->f38C = TObjEneGibbles__data_805DE7E4;
            switch (TObjEneGibbles__sub_802D9A04(o)) {
            case 0:
                TObjEneGibbles__sub_800D8988(&o->pos);
                break;
            case 1:
            default:
                play_sound_effect(((TObjEneGibbles*)(o))->resolve_sound_id((u32)(0x3AD32)), &o->pos, 0, 0);
                break;
            }
            o->f30 &= 0xF9FFFFFF;
            o->fA4->f18 |= 1;
            o->f374 &= ~0x10;
            o->fB8 = 6;
            TObjEneGibbles__sub_802D7A54(o);
        }
        break;
    case 3:
        if (!(o->f30 & 0x800000)) {
            apply_actor_gravity((TObjEnemy *)((u8 *)o), (s32 *)(0), TObjEneGibbles__data_805DE7E4);
        }
        if (((TObjMotion *)o)->is_passing_frame(o->fC4 - TObjEneGibbles__data_805DE7EC - o->fC8) != 0) {
            o->f30 &= ~0x200000;
            to_idle_802D8984(o);
        }
        submit_cursor_candidate(o, -1);
        break;
    }
    minimap_render_dot(&o->pos, -0x5DB4, 1, 0);
}
#pragma pop

void TObjEneGibbles__sub_802D8E8C(u8 *arg0) {
    u32 p;
    u16 id;
    id = F_802D(0x338, u16);
    if (id < 0x1000) {
        p = get_player_by_client_id((void *)id);
        if (p != 0 && ((TObjPlayer *)p)->get_field_3e4() == get_current_floor()) {
            F_802D(0x2A8, u32) = p;
        } else {
            F_802D(0x2A8, u32) = 0;
        }
    } else if (id < 0x4000) {
        F_802D(0x2A8, s32) = get_enemy_entity();
    } else {
        F_802D(0x338, u16) = 0xFFFF;
        F_802D(0x2A8, s32) = 0;
    }
    *(s32 *)((s8 *)F_802D(0xA4, u8 *) + 0x18) |= 1;
    F_802D(0x30, s32) &= 0xF9FBFFFF;
    TObjEneGibbles__sub_802D7DAC((s32)arg0);
    ((TObjMotion *)arg0)->advance_animation();
    ((TObjEneGibbles *)arg0)->clamp_angle(0);
    switch (F_802D(0x328, s16)) {
    case 0:
        F_802D(0x328, s16) = 1;
        apply_actor_gravity((TObjEnemy *)arg0, (s32 *)(0), TObjEneGibbles__data_805DE7E4);
        F_802D(0x374, s32) |= 0x100;
        play_sound_effect(((TObjEneGibbles*)(arg0))->resolve_sound_id((u32)(0x3AD2E)), arg0 + 0x38, 0, 0);
        break;
    case 1:
    case 2:
        if (!(F_802D(0x30, s32) & 0x800000)) {
            apply_actor_gravity((TObjEnemy *)arg0, (s32 *)(0), TObjEneGibbles__data_805DE7E4);
        }
        if (((TObjMotion *)arg0)->is_passing_frame(lbl_805DE834) != 0) {
            play_sound_effect(((TObjEneGibbles*)(arg0))->resolve_sound_id((u32)(0x3A82D)), arg0 + 0x2FC, 0, 0);
        }
        if (((TObjMotion *)arg0)->is_passing_frame(lbl_805DE838) != 0) {
            F_802D(0x328, s16) = 2;
        }
        if (F_802D(0x328, s16) == 1) {
            TObjEneGibbles__sub_802D9644(arg0, 1, get_attack_params_atp_min(*(void **)((s8 *)gibbles_combat_stat_entries + 8)));
        }
        if (F_802D(0xB4, u32) != 4) {
            F_802D(0x328, s16) = 3;
            F_802D(0x37E, s16)++;
        }
        break;
    case 3:
        ((TObjEneGibbles *)arg0)->update_move_state();
        if (F_802D(0x37E, s16) >= 2) {
            F_802D(0x37E, s16) = 0;
            F_802D(0x374, s32) &= ~0x108;
        }
        F_802D(0x30, s32) &= 0xFFDFFFFF;
        break;
    }
    ((TObjPlayer *)arg0)->check_object_collisions();
    check_enemy_body_collisions(arg0);
    ((TObjPlayer *)arg0)->update_enemy_collision_flags();
    minimap_render_dot(arg0 + 0x38, -0x5DB4, 1, 0);
    submit_cursor_candidate(arg0, -1);
}

struct Vec_802D9110 { f32 x, y, z; };
struct Param_802D9110 { u8 pad0[4]; f32 speed; s32 turn; };
struct Gib_802D9110 {
    u8 pad0[0x30];
    u32 flags30;
    u8 pad34[0x38 - 0x34];
    u8 snd[0xA4 - 0x38];
    u8 *fA4;
    u8 padA8[0xB8 - 0xA8];
    s16 motion;
    u8 padBA[0xC0 - 0xBA];
    f32 frame;
    f32 frameEnd;
    f32 frameStep;
    u8 padCC[0x2A8 - 0xCC];
    Gib_802D9110 *target;
    u8 pad2AC[0x2FC - 0x2AC];
    Vec_802D9110 pos;
    Vec_802D9110 vel;
    u8 pad314[0x328 - 0x314];
    s16 state;
    u8 pad32A[0x338 - 0x32A];
    u16 targetId;
    s16 timer;
    u8 pad33C[0x350 - 0x33C];
    Param_802D9110 *param;
    u8 pad354[0x374 - 0x354];
    u32 flags374;
};

void TObjEneGibbles__sub_802D9824(void *, int, f32);
extern const f32 lbl_805DE83C;
extern const f32 lbl_805DE840;
extern const f32 lbl_805DE844;
extern const f32 lbl_805DE848;
extern const f32 lbl_805DE84C;
extern const f32 lbl_805DE850;
extern const f32 lbl_805DE854;

void TObjEneGibbles__sub_802D9110(Gib_802D9110 *self) {

    u8 *t = self->fA4;
    *(s32 *)(t + 0x18) |= 1;
    self->flags30 &= 0xF9FBFFFF;
    u16 id = self->targetId;
    if (id < 0x1000) {
        u32 p = get_player_by_client_id((void *)id);
        if (p != 0 && ((TObjPlayer *)p)->get_field_3e4() == get_current_floor()) {
            self->target = (Gib_802D9110 *)p;
        } else {
            self->target = NULL;
        }
    } else if (id < 0x4000) {
        self->target = (Gib_802D9110 *)get_enemy_entity();
    } else {
        self->targetId = 0xFFFF;
        self->target = NULL;
    }
    switch (self->state) {
    case 0:
        if (self->target == NULL) {
            self->state = 0;
            self->flags30 &= 0xFFDFFFFF;
            self->timer = 0;
        } else {
            Vec_802D9110 d;
            s32 diff;
            VecCopy((Vec *)((Vec_800A6B14 *)&d), (const Vec *)((const Vec_800A6B14 *)&self->target->pos));
            subtract_vector(&d, &self->pos);
            diff = ((TObjEnemy *)self)->turn_toward_direction(self->param->turn, (Vec *)&d);
            if (!(self->flags30 & 0x800000)) {
                apply_actor_gravity((TObjEnemy *)((u8 *)self), (s32 *)(0), TObjEneGibbles__data_805DE7E4);
            }
            if (diff < 0x10) {
                self->flags374 |= 0x100;
                self->state = 1;
                self->motion = 2;
                if (check_path_obstructed(self, &self->target->pos) == 1) {
                    self->vel.x = self->vel.y = self->vel.z = TObjEneGibbles__data_805DE7E4;
                } else {
                    ((void (*)(void *, Vec_802D9110, Vec_802D9110, f32))calc_velocity_toward_destination)(self, self->pos, self->target->pos, self->param->speed);
                }
            }
        }
        break;
    case 1:
        self->motion = 2;
        if (((TObjMotion *)self)->is_passing_frame(TObjEneGibbles__data_805DE81C) != 0) {
            self->state = 2;
            play_sound_effect(((TObjEneGibbles*)(self))->resolve_sound_id((u32)(0x3AD34)), self->snd, 0, 0);
        }
        break;
    case 2:
        self->motion = 2;
        if (((TObjMotion *)self)->is_passing_frame(TObjEneGibbles__data_805DE7F8) != 0) {
            ((TObjEneGibbles *)self)->slam_damage_players(0x1F);
        } else {
            TObjEneGibbles__sub_802D9644(self, 0, TObjEneGibbles__data_805DE7E4);
        }
        if (lbl_805DE83C <= self->frame && self->frame <= lbl_805DE840) {
            ((void (*)(void *))TObjEneGibbles__sub_802D8034)(self);
        }
        if (((TObjMotion *)self)->is_passing_frame(TObjEneGibbles__data_805DE7E8) != 0) {
            self->state = 3;
        }
        break;
    case 3:
        self->motion = 2;
        move_with_wall_slide((u8 *)self);
        if (((TObjMotion *)self)->is_passing_frame(lbl_805DE840) != 0) {
            self->state = 4;
            play_sound_effect(((TObjEneGibbles*)(self))->resolve_sound_id((u32)(0x3AD34)), self->snd, 0, 0);
        }
        break;
    case 4:
        self->motion = 2;
        if (((TObjMotion *)self)->is_passing_frame(lbl_805DE7FC) != 0) {
            ((TObjEneGibbles *)self)->slam_damage_players(0x35);
        } else {
            TObjEneGibbles__sub_802D9824(self, 0, TObjEneGibbles__data_805DE7E4);
        }
        if (lbl_805DE838 <= self->frame && self->frame <= lbl_805DE844) {
            ((void (*)(void *))TObjEneGibbles__sub_802D8034)(self);
        }
        if (((TObjMotion *)self)->is_passing_frame(lbl_805DE848) != 0) {
            self->state = 5;
        }
        break;
    case 5:
        self->motion = 2;
        move_with_wall_slide((u8 *)self);
        if (((TObjMotion *)self)->is_passing_frame(lbl_805DE84C) != 0) {
            self->state = 6;
            play_sound_effect(((TObjEneGibbles*)(self))->resolve_sound_id((u32)(0x3AD34)), self->snd, 0, 0);
        }
        break;
    case 6:
        self->motion = 2;
        if (((TObjMotion *)self)->is_passing_frame(lbl_805DE800) != 0) {
            ((TObjEneGibbles *)self)->slam_damage_players(0x1F);
        } else {
            TObjEneGibbles__sub_802D9644(self, 0, TObjEneGibbles__data_805DE7E4);
        }
        if (lbl_805DE850 <= self->frame && self->frame <= lbl_805DE854) {
            ((void (*)(void *))TObjEneGibbles__sub_802D8034)(self);
        }
        if (((TObjMotion *)self)->is_passing_frame((self->frameEnd - TObjEneGibbles__data_805DE7EC) - self->frameStep) != 0) {
            self->motion = 0;
            self->state = 7;
            self->timer = (s16)*(f32 *)(TObjEneGibbles__ai_parameters + 4);
        }
        break;
    case 7:
        if (--self->timer < 0) {
            self->motion = 1;
            self->state = 0;
            self->flags30 &= 0xFFDFFFFF;
            self->timer = 0;
            self->flags374 &= ~0x100;
        }
        break;
    }
    ((TObjEneGibbles *)self)->play_distance_sound();
    ((TObjMotion *)self)->advance_animation();
    ((TObjEneGibbles *)self)->clamp_angle(0);
    ((TObjPlayer *)self)->check_object_collisions();
    check_enemy_body_collisions(self);
    ((TObjPlayer *)self)->update_enemy_collision_flags();
    minimap_render_dot(self->snd, -0x5DB4, 1, 0);
    submit_cursor_candidate(self, -1);
}

s32 TObjEneGibbles__sub_802D9A04(void *target) {
    s32 i;
    VObj_802D9A04 *pl;

    for (i = 0; i < lbl_805D5868; i++) {
        pl = ((VObj_802D9A04 * (*)(s32))get_player_data__10TObjPlayerFi)(i);
        if (is_valid_and_active__10TObjPlayerFUl() != 0 && get_entity_id(pl) < 0x1000U) {
            f32 dist = horizontal_distance_squared((int) ((u8 *) pl + 0x2FC), (void *) ((s32) target + 0x38));
            if (dist <= ((AttackParams *)(*(void **)((s8 *)gibbles_combat_stat_entries + 4)))->get_damage_radius() * ((AttackParams *)(*(void **)((s8 *)gibbles_combat_stat_entries + 4)))->get_damage_radius()) {
                Arg_802D9A04 tmp;
                tmp.a = 0;
                tmp.b = get_attack_params_atp_min(*(void **)((s8 *)gibbles_combat_stat_entries + 4));
                Arg_802D9A04 a = tmp;
                f32 res = pl->m21(target, &a, 0, -1, -1);
                pl->m23(target);
                if (res > TObjEneGibbles__data_805DE7E4) {
                    obj_setFlags30(pl, 0x600);
                }
            }
        }
    }
    return ((s32 (*)(void *))TObjEneGibbles__sub_802D7BE0)(target);
}
#pragma pop

void TObjEneGibbles::slam_damage_players(s32 arg1) {
    Vec_802D9B80 v;
    Hit_802D9B80 a;
    f32 d;
    s32 i;
    u8 *p;
    s32 target = (s32)this;

    if (arg1 == 0x35) {
        ((s32 (*)(s32, void *, int))render_and_get_joint_pos__14TObjEneGibblesFPvii)(target, &v, 0x35);
    } else if (arg1 == 0x1F) {
        ((s32 (*)(s32, void *, int))render_and_get_joint_pos__14TObjEneGibblesFPvii)(target, &v, 0x1F);
    } else {
        return;
    }
    v.y += lbl_805DE808;
    if (csnVecterUnder((s32)&v, 0x16EF) != 0) {
        if (((TObjEneGibbles *)target)->spawn_ground_impact_effects(&v, lbl_805DE858) == 0) {
            v.y += TObjEneGibbles__data_805DE81C;
            spawn_particle_effect(&v, 0x64);
        }
        for (i = 0; i < lbl_805D5868; i++) {
            p = get_player_data__10TObjPlayerFi(i);
            if (((s32 (*)(void *))is_valid_and_active__10TObjPlayerFUl)(p) != 0 && get_entity_id(p) < 0x1000) {
                d = horizontal_distance_squared((int)(p + 0x2FC), &v);
                if (d <= ((AttackParams *)(*(void **)gibbles_combat_stat_entries))->get_damage_radius() * ((AttackParams *)(*(void **)gibbles_combat_stat_entries))->get_damage_radius()) {
                    a.x = 0;
                    a.y = get_attack_params_atp_min(*(void **)gibbles_combat_stat_entries);
                    Hit_802D9B80 h = a;
                    ((VObj_18_22e4b0 *)p)->m21(target, &h, 0, -1, -1);
                    ((VObj_18_22e4b0 *)p)->m23(target);
                }
            }
        }
    }
}

void TObjEneGibbles::vfunc_60() {
    u8 *arg0 = (u8 *)this;
    Vec_802D9D64 v;
    switch (this->m_37c) {
    case 0:
    default: {
        VecCopy((Vec *)((Vec_800A6B14 *) &v), (const Vec *)((Vec_800A6B14 *) (this->target + 0x2FC)));
        subtract_vector(&v, (u8 *)&this->m_2fc);
        f64 t = atan2_float(v.x, v.z);
        this->mode = 4;
        if ((s32) (TObjEneGibbles__data_80472798 * t) < 0x10) {
            this->phase = 1;
            this->requested_action = 2;
        } else {
            this->phase = 0;
            this->requested_action = 1;
        }
        break;
    }
    case 2:
        this->mode = 5;
        this->phase = 0;
        this->requested_action = 3;
        break;
    case 1:
        this->mode = 6;
        this->phase = 0;
        this->requested_action = 4;
        this->m_374 = (s32) (this->m_374 & 0xFFFFFF7F);
        break;
    }
    ((TObjEnemy *)arg0)->bind_enemy_combat_stats((u8 *)(0), (u8 *)(((s32 *) gibbles_combat_stat_entries)[this->m_37c]), (u8 *)(0));
    *(s32 *)((s8 *)(this->bodies) + 0x18) |= 1;
    this->actorFlags = (s32) (this->actorFlags & 0xF9FBFFFF);
    this->actorFlags = (s32) (this->actorFlags | 0x200000);
}

#define TGT_802D9EB4 (((void **)gibbles_combat_stat_entries)[(*(s16 *)(arg0 + 0x37C))])
s32 TObjEneGibbles::is_target_in_attack_range() {
    u8 *arg0 = (u8 *)this;
    Vec_802D9EB4 v;
    f32 rad;
    f32 dist;
    s32 ang;
    u8 *obj;
    u8 *sub;
    if (this->mode >= 3) {
        obj = this->target;
        if (obj != NULL && this->m_318 != 0 && !(*(s32 *)((s8 *)obj + 0x30) & 0x02000800)) {
            dist = calc_xz_distance_sq(arg0, obj, &v);
            ang = angle_difference_abs(this->rotation_y, (s32)(TObjEneGibbles__data_80472798 * atan2_float(v.x, v.z)));
            sub = *(u8 **)(this->target + 0xA4);
            if (sub != NULL) {
                rad = *(f32 *)((s8 *)sub + 0xC);
            } else {
                rad = lbl_805DE834;
            }
            if (this->m_374 & 8) {
                this->m_37c = 2;
                if (dist <= (rad + ((AttackParams *)TGT_802D9EB4)->get_attack_range()) * (rad + ((AttackParams *)TGT_802D9EB4)->get_attack_range()) && ang <= ((AttackParams *)TGT_802D9EB4)->get_attack_angle()) {
                    return 1;
                }
            } else if (this->m_374 & 0x10) {
                this->m_37c = 1;
                if (dist <= (lbl_805DE85C + rad) * (lbl_805DE85C + rad) && ang <= 0xAAA) {
                    return 1;
                }
            } else {
                this->m_37c = 0;
                if (dist <= (rad + ((AttackParams *)TGT_802D9EB4)->get_attack_range()) * (rad + ((AttackParams *)TGT_802D9EB4)->get_attack_range()) && ang <= ((AttackParams *)TGT_802D9EB4)->get_attack_angle()) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

void TObjEneGibbles::sub_802DA0BC() {
    f32 d;
    s32 ok;
    *(u32 *)((s8 *)(this->bodies) + 0x18) |= 1;
    this->actorFlags &= 0xF9DBFFFF;
    if (this->target == NULL) {
        return;
    }
    switch (this->phase) {
    case 2:
        break;
    case 0: {
        Vec_802DA0BC v = *(Vec_802DA0BC *)(this->target + 0x2FC);
        if (select_enemy_destination(this, &v, 7) != 0) {
            this->phase = 1;
            {
                Vec_802DA0BC v2 = *(Vec_802DA0BC *)(((u8 *)this) + 0x2FC);
                copy_position_if_valid__10TObjPlayerFii((s32)this, (s32)&v2);
            }
            apply_actor_gravity((TObjEnemy *)this, (s32 *)(0), TObjEneGibbles__data_805DE7E4);
            *(f32 *)((s8 *)((u8 *)this) + 0x3A0) = TObjEneGibbles__data_805DE7E4;
        } else {
            this->phase = 0;
            this->mode = 0xB;
            this->requested_action = 1;
            this->actorFlags &= 0xF99BFFFF;
        }
        break;
    }
    case 1:
        {
            f32 dt = *(f32 *)((s8 *)TObjEneGibbles__ai_parameters + 8);
            *(f32 *)((s8 *)((u8 *)this) + 0x3A0) += dt;
            Vec_802DA0BC v = *(Vec_802DA0BC *)(this->target + 0x2FC);
            enemy_move_toward(this, *(s32 *)((s8 *)(this->movementParameters) + 8), &v, 0, dt);
        }
        d = horizontal_distance_squared((int)(((u8 *)this) + 0x29C), ((u8 *)this) + 0x38);
        {
            Vec_802DA0BC v = *(Vec_802DA0BC *)(this->target + 0x2FC);
            ok = select_enemy_destination(this, &v, 1);
        }
        if (d >= lbl_805DE860 && ok != 0) {
            this->m_374 |= 0x10;
        } else if (*(f32 *)((s8 *)((u8 *)this) + 0x3A0) >= lbl_805DE864) {
            *(f32 *)((s8 *)((u8 *)this) + 0x3A0) = TObjEneGibbles__data_805DE7E4;
            if (((f32 (*)(void *))random_ratio__9TObjCharaFv)(this) < this->m_394 && ok != 0) {
                this->m_374 |= 0x10;
            } else {
                this->m_374 &= ~0x10;
            }
        } else {
            this->m_374 &= ~0x10;
        }
        {
            f32 r = *(f32 *)((s8 *)(this->movementParameters) + 4) + *(f32 *)((s8 *)(this->bodies) + 0xC);
            if (d < r * r) {
                this->phase = 3;
            }
        }
        break;
    case 3:
        this->m_374 &= ~0x10;
        this->phase = 0;
        break;
    }
    TObjEneGibbles__sub_802D7DAC((s32)this);
    advance_animation();
    turn_toward_target();
    ((TObjPlayer *)((u8 *)this))->check_object_collisions();
    check_enemy_body_collisions(this);
    ((TObjPlayer *)((u8 *)this))->update_enemy_collision_flags();
    minimap_render_dot(((u8 *)this) + 0x38, -0x5DB4, 1, 0);
    submit_cursor_candidate(this, -1);
}

void TObjEneGibbles::update_death_sequence() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r4;

    (this->actorFlags) = (s32) ((this->actorFlags) & 0xFFDFFFFF);
    (this->actorFlags) = (s32) ((this->actorFlags) | 0x06040000);
    temp_r4 = (unsigned char *) (this->bodies);
    *(s32 *)((s8 *)temp_r4 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r4 + 0x18) & 0xFFFFFFFE);
    ((TObjMotion *)arg0)->advance_animation();
    switch (this->phase) {
    case 2:
        break;
    case 0:
        this->phase = 1;
        this->requested_action = 5;
        TObjEneMe3SinowZoa__sub_800D758C((void *) (arg0 + 0x3C0));
        this->m_38c = (f32) lbl_805DE868;
        *(f32 *)&this->unk_390 = (f32) TObjEneGibbles__data_805DE830;
        apply_actor_gravity((TObjEnemy *)(arg0), (s32 *)(0), TObjEneGibbles__data_805DE7E4);
        break;
    case 1:
        if (((struct GibVObj_802da394_802D87D8 *) (arg0 + 0x3C0))->m5() != 0) {
            this->m_38c = (f32) (this->m_38c - *(f32 *)&this->unk_390);
            *(f32 *)&this->unk_390 = (f32) (*(f32 *)&this->unk_390 + TObjEneGibbles__data_805DE830);
        } else {
            this->frame = (f32) lbl_805DE86C;
        }
        if (((TObjMotion *)arg0)->is_passing_frame((this->frame_count - TObjEneGibbles__data_805DE7EC) - this->play_speed) != 0) {
            this->m_38c = (f32) TObjEneGibbles__data_805DE7E4;
            *(f32 *)&this->unk_390 = (f32) TObjEneGibbles__data_805DE7E4;
            switch (TObjEneGibbles__sub_802D9A04(arg0)) {
            case 0:
                TObjEneGibbles__sub_800D8988((void *) (arg0 + 0x38));
                break;
            default:
            case 1:
                ((s32 (*)(void *, void *, int, int))play_sound_effect)((void *) ((TObjEneGibbles*)arg0)->resolve_sound_id(0x3AD32), (void *) (arg0 + 0x38), 0, 0);
                break;
            }
            ((s32 (*)(void *))TObjEneGibbles__sub_802D7A54)(arg0);
            this->phase = 3;
        }
        break;
    case 3:
        if (((TObjMotion *)arg0)->is_passing_frame((this->frame_count - TObjEneGibbles__data_805DE7EC) - this->play_speed) != 0) {
            this->m_374 = (s32) (this->m_374 & 0xFFFF0000);
            this->m_374 = (s32) (this->m_374 | 4);
        }
        break;
    }
    minimap_render_dot((void *) (arg0 + 0x38), -0x5DB4, 1, 0);
}

void TObjEneGibbles::update_spawn_state() {
    u8 *arg0 = (u8 *)this;

    (this->actorFlags) = (s32) ((this->actorFlags) & 0xFFDFFFFF);
    (this->actorFlags) = (s32) ((this->actorFlags) | 0x06040000);
    *(s32 *)((s8 *)this->bodies + 0x18) = (s32) (*(s32 *)((s8 *)this->bodies + 0x18) & 0xFFFFFFFE);
    switch (this->phase) {
    case 0:
        this->phase = 1;
        apply_actor_gravity((TObjEnemy *)arg0, (s32 *)(0), TObjEneGibbles__data_805DE7E4);
        return;
    case 1:
        if (horizontal_distance_squared((int) ((this->target) + 0x2FC), (void *) (arg0 + 0x2FC)) < lbl_805DE870) {
            this->phase = 3;
        }
    case 2:
        return;
    case 3:
        this->m_374 = (s32) (this->m_374 & 0xFFFF0000);
        this->m_374 = (s32) (this->m_374 | 2);
        break;
    }
}

void TObjEneGibbles::vfunc_59() {
  s32 temp_r4;
  void *temp_r3;
  void *temp_r3_2;
  switch (this->mode)
  {
    default:
      temp_r4 = this->m_374;
      if (temp_r4 & 4)
    {
      this->mode = 3;
      this->phase = 0;
      this->requested_action = 1;
      this->actorFlags = (s32) ((this->actorFlags) & 0xF9FBFFFF);
    }
    else
      if (temp_r4 & 1)
    {
      this->mode = 1;
      this->phase = 0;
      this->actorFlags = (s32) ((this->actorFlags) | 0x06040000);
    }
      temp_r3 = this->bodies;
      *((s32 *) (((s8 *) temp_r3) + 0x18)) = (s32) ((*((s32 *) (((s8 *) temp_r3) + 0x18))) | 1);
      return;

    case 1:
      if ((this->m_374) & 2)
    {
      this->mode = 2;
      this->phase = 0;
      this->actorFlags = (s32) ((this->actorFlags) | 0x06040000);
    }
      return;

    case 2:
      if ((this->m_374) & 4)
    {
      this->mode = 3;
      this->phase = 0;
      this->requested_action = 1;
      this->actorFlags = (s32) ((this->actorFlags) & 0xF9FBFFFF);
      return;
    }
      break;

    case 3:
      if ((this->m_374) & 3)
    {
      this->mode = 1;
      this->phase = 0;
      this->actorFlags = (s32) ((this->actorFlags) | 0x06040000);
      this->m_374 = (s32) ((this->m_374) & 0xFFFF0000);
      this->m_374 = (s32) ((this->m_374) | 1);
      temp_r3_2 = this->bodies;
      *((s32 *) (((s8 *) temp_r3_2) + 0x18)) = (s32) ((*((s32 *) (((s8 *) temp_r3_2) + 0x18))) | 1);
      return;
    }
      break;

  }

  return;
}

void TObjEneGibbles::sub_802DA7A4() {
    u8 *temp_r4;
    *(s32 *)&this->actorFlags = (s32) (*(s32 *)&this->actorFlags & 0xFFDFFFFF);
    *(s32 *)&this->actorFlags = (s32) (*(s32 *)&this->actorFlags | 0x06040000);
    this->m_374 = (s32) (this->m_374 & ~0x107);
    temp_r4 = (unsigned char *) (this->bodies);
    *(s32 *)((s8 *)temp_r4 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r4 + 0x18) & 0xFFFFFFFE);
    advance_animation();
    switch (this->phase) {
    default:
    case 0:
        this->phase = 1;
        this->requested_action = 5;
        this->m_38c = (f32) TObjEneGibbles__data_805DE7E4;
        *(f32 *)&this->unk_390 = (f32) lbl_805DE874;
        apply_actor_gravity((TObjEnemy *)(this), (s32 *)(0), TObjEneGibbles__data_805DE7E4);
        break;
    case 1:
        if (is_passing_frame(TObjEneGibbles__data_805DE7F8) != 0) {
            this->phase = 2;
            TObjEneGibbles__sub_802D7BE0((s32) (this));
            play_sound_effect((int)(this->resolve_sound_id((u32)(0x3A82F))), (void *) (((u8 *)this) + 0x38), 0, 0);
            ((V_802DA7A4 *)(((u8 *)this) + 0x3C0))->m2();
        }
        apply_actor_gravity((TObjEnemy *)(this), (s32 *)(0), TObjEneGibbles__data_805DE7E4);
        break;
    case 2:
        if (((V_802DA7A4 *)(((u8 *)this) + 0x3C0))->m4() == 1) {
            this->phase = 3;
        } else {
            this->m_38c = (f32) (this->m_38c + *(f32 *)&this->unk_390);
            *(f32 *)&this->unk_390 = (f32) (*(f32 *)&this->unk_390 - TObjEneGibbles__data_805DE830);
        }
        break;
    case 3:
        ((TObjBase *)((u8 *)this))->set_position_from((void *) (((u8 *)this) + 0x50));
        this->update_prev_position();
        this->scale.z = (f32) TObjEneGibbles__data_805DE7EC;
        this->scale.y = (f32) TObjEneGibbles__data_805DE7EC;
        this->scale.x = (f32) TObjEneGibbles__data_805DE7EC;
        this->m_374 = (s32) (this->m_374 & 0xFFFF0000);
        this->m_374 = (s32) (this->m_374 | 1);
        break;
    }
    minimap_render_dot((void *) (((u8 *)this) + 0x38), -0x5DB4, 1, 0);
}

void TObjEneGibbles::update_wander() {
    f32 var_f1;
    f32 var_f2;
    f32 var_f3;
    s32 var_r5;
    s32 var_r6;
    u8 *var_r31;
    u8 *var_r3;
    u8 *var_r4;
    var_r31 = (u8 *)(this);
    ((TObjMotion *)this)->advance_animation();
    if ((u32) *(u32 *)((s8 *)var_r31 + 0x2A8) != 0U) {
        var_r3 = (u8 *)((void *)3);
        *(s16 *)((s8 *)var_r31 + 0x326) = 3;
        var_r3 = var_r31;
        var_r4 = (u8 *)((void *)0x06240000);
        *(s16 *)((s8 *)var_r31 + 0x328) = 0;
        ((TObjBase *)var_r3)->obj_clearFlags30(0x06240000);
        *(s32 *)((s8 *)var_r31 + 0x374) = (s32) (*(s32 *)((s8 *)var_r31 + 0x374) & 0xFFFF0000);
        *(s32 *)((s8 *)var_r31 + 0x374) = (s32) (*(s32 *)((s8 *)var_r31 + 0x374) | 4);
        var_r3 = (u8 *)(*(u8 **)((s8 *)var_r31 + 0xA4));
        *(s32 *)((s8 *)var_r3 + 0x18) = (s32) (*(s32 *)((s8 *)var_r3 + 0x18) | 1);
    } else {
        *(s32 *)((s8 *)var_r31 + 0x374) = (s32) (*(s32 *)((s8 *)var_r31 + 0x374) & 0xFFFFFFFB);
    }
    var_f2 = (*(const f32 *)&lbl_805DE878);
    var_r3 = var_r31;
    var_r4 = (u8 *)(*(u8 **)((s8 *)var_r31 + 0x350));
    var_f3 = var_f2;
    var_f1 = *(f32 *)((s8 *)var_r4 + 4);
    var_r4 = (u8 *)(*(u8 **)((s8 *)var_r4 + 8));
    ((TObjEnemy *)var_r3)->enemy_wander_home((s32)var_r4, (f32)var_f1, (f32)var_f2, (f32)var_f3);
    var_r3 = var_r31;
    ((TObjCollidable *)var_r3)->refresh_collision_body_centers();
    var_r3 = var_r31;
    ((TObjPlayer *)var_r3)->check_object_collisions();
    var_r3 = var_r31;
    check_enemy_body_collisions((var_r3));
    var_r3 = var_r31;
    ((TObjPlayer *)var_r3)->update_enemy_collision_flags();
    var_r3 = var_r31;
    var_r4 = (u8 *)((void *)0x200000);
    ((TObjBase *)var_r3)->obj_clearFlags30(0x200000);
    var_r3 = var_r31;
    ((s32 (*)(int))TObjEneGibbles__sub_802D7DAC)((int)var_r3);
    var_r3 = (u8 *)(var_r31 + 0x38);
    var_r4 = (u8 *)((void *)-0x5DB4);
    var_r5 = 1;
    var_r6 = 0;
    minimap_render_dot(var_r3, -0x5DB4, 1, 0);
    var_r3 = var_r31;
    var_r4 = (u8 *)((void *)-1);
    ((s32 (*)(int, int))submit_cursor_candidate)((int)var_r3, -1);
}

void TObjEneGibbles::init_state() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r3;

    ((TObjBase *)arg0)->set_position_from((void *) (arg0 + 0x50));
    ((TObjCollidable *)arg0)->refresh_collision_body_centers();
    (this->actorFlags) = (s32) ((this->actorFlags) & 0xFFDFFFFF);
    (this->actorFlags) = (s32) ((this->actorFlags) | 0x06040000);
    temp_r3 = (unsigned char *) (this->bodies);
    *(s32 *)((s8 *)temp_r3 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r3 + 0x18) & 0xFFFFFFFE);
}

void TObjEneGibbles::vfunc_58() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r3;

    switch (this->mode) {
    case 0:
        if (((VObj802DAAC8_802daac8_802D87D8 *)(arg0 + 0x3C0))->m8() != 0) {
            this->mode = 0xA;
            this->phase = 0;
            this->requested_action = 0;
            ((TObjBase *)arg0)->obj_clearFlags30(0x200000);
            obj_setFlags30(arg0, 0x06040000);
            this->m_374 = (s32) (this->m_374 & 0xFFFF0000);
            temp_r3 = (unsigned char *) (this->bodies);
            *(s32 *)((s8 *)temp_r3 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r3 + 0x18) & 0xFFFFFFFE);
        }
    case 6:
    case 11:
        return;
    case 10:
        if (!(this->m_374 & 0x40)) {
            this->mode = 0;
            return;
        }
        break;
    default:
        this->phase = 0;
        this->mode = 0xB;
        this->requested_action = 1;
        this->actorFlags = (s32) (this->actorFlags & 0xF99BFFFF);
        break;
    }
}

#define P_802DAD50(p) ((Obj_802DAD50 *)(p))

s32 TObjEneGibbles::update_movement_status() {
    u8 *arg0 = (u8 *)this;
    if (update_movement_status__9TObjCharaFv() != 0) {
        switch (this->mode) {
        case 0:
        case 1:
        case 2:
        case 0xa:
            if (((VObj14 *)(arg0 + 0x3c0))->m5() == 1) {
                this->m_374 &= ~0x143;
                this->m_374 |= 4;
                this->mode = 3;
                this->phase = 0;
                this->requested_action = 1;
                ((TObjBase *)arg0)->obj_clearFlags30(0x06240000);
            }
            break;
        }
        return 1;
    }
    return 0;
}

s32 TObjEneGibbles::update_action_hold_status() {
    u8 *arg0 = (u8 *)this;
    if (update_action_hold_status__9TObjCharaFv() != 0) {
        switch (this->mode) {
        case 0:
        case 1:
        case 2:
        case 0xa:
            if (((VObj14 *)(arg0 + 0x3c0))->m5() == 1) {
                this->m_374 &= ~0x143;
                this->m_374 |= 4;
                this->mode = 3;
                this->phase = 0;
                this->requested_action = 1;
                ((TObjBase *)arg0)->obj_clearFlags30(0x06240000);
            }
            break;
        }
        return 1;
    }
    return 0;
}

void update_target__14TObjEneGibblesFPv(Obj_802DAD50 *self) {
    if (self->f374 & 0x40) {
        self->f338 = 0xFFFF;
        self->target = NULL;
        return;
    }
    if (self->m17(0x1E) == 0) {
        return;
    }
    if (obj_testFlags30__14TObjCollidableFUl(self, 0x10) != 0) {
        s32 best_id;
        s32 i;
        u8 *p;
        s32 id;
        f32 best;
        f32 d;
        u16 tid;
        i = 0;
        best_id = 0xFFFF;
        Vec_800A6B14 v = *(Vec_800A6B14 *)lbl_80472768;
        best = *self->range * *self->range;
        for (; i < registered_player_count + lbl_805D5870; i++) {
            p = get_player_data__10TObjPlayerFi(i);
            if (((s32 (*)(u8 *))is_valid_and_active__10TObjPlayerFUl)(p) != 0 && p != (u8 *)self) {
                id = ((s32 (*)(void *))get_entity_id)(p);
                if ((u16)id < 0x4000 && (u16)id != self->f1C && !(P_802DAD50(p)->f30 & 0x02000800)) {
                    VecCopy((Vec *)&v, (const Vec *)((Vec_800A6B14 *)(p + 0x2FC)));
                    subtract_vector(&v, &self->pos);
                    d = v.x * v.x + v.z * v.z;
                    if (d < best && check_path_obstructed(self, p + 0x2FC) != 1) {
                        best_id = id;
                        best = d;
                    }
                }
            }
        }
        self->f338 = best_id;
        tid = self->f338;
        if (tid < 0x1000U) {
            u8 *q = ((u8 *(*)(u16))get_player_by_client_id)(tid);
            if (q != NULL) {
                if (((TObjPlayer *)q)->get_field_3e4() == get_current_floor()) {
                    self->target = q;
                    return;
                }
            }
            self->target = NULL;
            return;
        }
        if (tid < 0x4000U) {
            self->target = ((u8 *(*)(u16))get_enemy_entity)(tid);
        }
        return;
    }
    {
        s32 best_id2;
        s32 best_id;
        u8 *p;
        u8 *best_p2;
        u8 *best_p;
        s32 i;
        f32 best2;
        f32 best;
        f32 d;
        Vec_800A6B14 v = *(Vec_800A6B14 *)lbl_80472774;
        best_id = 0xFFFF;
        best_p2 = NULL;
        best_id2 = best_id;
        best_p = NULL;
        i = 0;
        best = *self->range * *self->range;
        best2 = best;
        for (; i < registered_player_count; i++) {
            p = get_player_data__10TObjPlayerFi(i);
            if (p == NULL) continue;
            if ((u16)((s32 (*)(void *))get_entity_id)(p) >= 0x1000) continue;
            if (((TObjPlayer *)p)->get_field_3e4() != get_current_floor()) continue;
            if (P_802DAD50(p)->f30 & 0x02000800) continue;
            VecCopy((Vec *)&v, (const Vec *)((Vec_800A6B14 *)(p + 0x2FC)));
            subtract_vector(&v, &self->pos);
            d = v.x * v.x + v.z * v.z;
            if ((((TObjPlayer *)p)->class_flags & self->target_class_mask) && d < best &&
                check_path_obstructed(self, p + 0x2FC) != 1) {
                best_id = ((s32 (*)(void *))get_entity_id)(p);
                best = d;
                best_p = p;
            }
            if (d < best2 && check_path_obstructed(self, p + 0x2FC) != 1) {
                best_id2 = ((s32 (*)(void *))get_entity_id)(p);
                best2 = d;
                best_p2 = p;
            }
        }
        if (best2 < lbl_805DE824 && best_p2 != NULL) {
            self->f338 = best_id2;
            self->target = best_p2;
            return;
        }
        if (best_p != NULL) {
            self->f338 = best_id;
            self->target = best_p;
            return;
        }
        if (best_p2 != NULL) {
            self->f338 = best_id2;
            self->target = best_p2;
            return;
        }
        self->f338 = 0xFFFF;
        self->target = NULL;
    }
}

void TObjEneGibbles::turn_toward_target() {
    Vec_800A6B14 d;
    VecCopy((Vec *)&d, (const Vec *)(&((Obj_800A6B14 *)this)->target->pos));
    subtract_vector(&d, &((Obj_800A6B14 *)this)->pos);
    ((TObjEneGibbles *)((Obj_800A6B14 *)this))->clamp_angle(angle_diff_s16(((Obj_800A6B14 *)this)->angle, (s32)(TObjEneGibbles__data_80472798 * atan2_float(d.x, d.z))));
}

void TObjEneGibbles::clamp_angle(s32 arg1) {
    s32 target_rot;

    target_rot = arg1;
    if (target_rot < -0x238E) {
        target_rot = -0x238E;
    } else if (target_rot > 0x238E) {
        target_rot = 0x238E;
    }
    this->m_3bc = lerp_angle_half__Fll(this->m_3bc, target_rot);
}
}

void gibbles_render_node_callback(void) {
    if ((s32) TObjEneGibbles__render_node_index == 0x18) {
        rotate_matrix_x(0, TObjEneGibbles__render_rotation_x);
    }
    TObjEneGibbles__render_node_index += 1;
}
extern "C" {

void draw_model__14TObjEneGibblesFPv(TObjEneGibbles *arg0) {
    Obj_802DB200 *self = (Obj_802DB200 *)arg0;
    Vec_800A6B14 v;
    s32 fade;
    s32 vis;
    s32 cam;
    cam = 0;
    if (is_split_screen() != 0) {
        cam = get_camera_mode__11TCameraCtrlFv();
    }
    if (get_current_floor_area() == AREA_TOWER) {
        vis = self->m9(600.0f, 600.0f, 30.0f);
    } else {
        vis = self->m9(lbl_805DE884, lbl_805DE87C, lbl_805DE880);
    }
    if (vis != 0) {
        update__15RenderFadeStateFv(&self->fades[cam]);
        fade = ((RenderFadeState *)(&self->fades[cam]))->updateFromCamera((const f32*)((u8 *)arg0 + 0x2FC));
        select_actor_lighting((s32)arg0);
        TObjFish::set_global_param(arg0->texlist);
        push_matrix_from(0);
        VecCopy((Vec *)&v, (const Vec *)((Vec_800A6B14 *)((u8 *)arg0 + 0x38)));
        switch (arg0->mode) {
        case 2:
        case 6:
        case 10:
            v.y += arg0->m_38c;
            break;
        }
        translate_matrix_vec3((u8 *)(0), (u8 *)&v);
        rotate_matrix_y(0, arg0->rotation_y);
        scale_matrix_vec3(0, (u8 *)arg0 + 0x68);
        TObjEneGibbles__render_node_index = 0;
        TObjEneGibbles__render_rotation_x = arg0->m_3bc;
        set_chunk_model_node_callback((s32)((void *)gibbles_render_node_callback));
        TObjPlayer::toggle_particle_effect();
        switch (arg0->mode) {
        case 0:
            break;
        case 1:
        case 2:
        case 10:
            if (self->sub.m8() != 0) {
                saved_model_render_flags = model_render_flags;
                saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
                saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
                model_render_flags |= 1;
                self->sub.m6();
                if (defer_render__7TObjectFv(arg0) == 0) {
                    ((TObjMotion *)arg0)->draw();
                }
                self->sub.m7();
                chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
                chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
                model_render_flags = saved_model_render_flags;
            }
            break;
        default:
            if (fade != 0) {
                saved_model_render_flags = model_render_flags;
                saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
                saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
                self->fades[cam].m6();
                if (defer_render__7TObjectFv(arg0) == 0) {
                    if (vis == 1) {
                        ((TObjMotion *)arg0)->draw();
                    } else {
                        ((TObjEnemy *)arg0)->draw_motion_model();
                    }
                }
                self->fades[cam].m7();
                chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
                chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
                model_render_flags = saved_model_render_flags;
            } else if (vis == 1) {
                ((TObjMotion *)arg0)->draw();
            } else {
                ((TObjEnemy *)arg0)->draw_motion_model();
            }
            break;
        }
        TParticleCtrl::end_effect_render();
        set_chunk_model_node_callback((s32)NULL);
        pop_matrix();
        restore_scene_lighting();
        if (!(arg0->m_374 & 1)) {
            ((TObjEnemy *)arg0)->render_with_position_override(0, 0);
        }
    } else {
        arg0->update_position();
    }
}

void TObjEneGibbles::run_task() {
    s16 temp_r0;
    u8 *temp_r4;
    if (TObjPlayer::check_demo_mode() == 1) {
        ((void (*)(u8 *))TObjEneGibbles__sub_802D7E3C)((u8 *)this);
        return;
    }
    {
        switch (this->mode) {
        case 0:
            this->init_state();
            break;
        case 1:
            this->update_spawn_state();
            break;
        case 2:
            this->update_death_sequence();
            break;
        case 3:
            this->sub_802DA0BC();
            break;
        case 4:
            TObjEneGibbles__sub_802D9110((Gib_802D9110 *)this);
            break;
        case 5:
            TObjEneGibbles__sub_802D8E8C((u8 *)this);
            break;
        case 6:
            this->sub_802D8984();
            break;
        case 7:
            TObjEneGibbles__sub_802D8580(this);
            break;
        case 8:
            this->update_action_state();
            break;
        case 9:
            this->sub_802D8140();
            break;
        case 10:
            this->sub_802DA7A4();
            break;
        case 11:
            this->update_wander();
            break;
        }
    }
    temp_r4 = (u8 *)(this->target);
    if ((temp_r4 != NULL) && (*(s32 *)((s8 *)temp_r4 + 0x30) & 0x02000800)) {
        *(s16 *)((s8 *)this + 0x37E) = 0;
        this->actorFlags = (s32) (this->actorFlags & 0xFFDFFFFF);
        this->m_374 = (s32) (this->m_374 & 0xFFFF0000);
        this->target = NULL;
    }
    this->update_position();
    this->update_shadow_height();
    copy_position__20TBoss3VoloptHiraisinFv((s32)this);
    this->sync_state();
    this->m_2b4 = (f32) (this->m_2b4 + TObjEneGibbles__data_805DE7EC);
}

void TObjEneGibbles::init_params() {
    s16 temp_r0;
    s32 temp_r0_2;

    temp_r0 = (s16) (lbl_805DE878 + this->parameters[0]);
    this->m_388 = temp_r0;
    *(s16 *)&this->unk_38A = temp_r0;
    this->m_39c = (s32) *(f32 *)((s8 *)this + 0x358);
    temp_r0_2 = this->m_39c;
    if (temp_r0_2 < 0) {
        this->m_39c = 0;
    } else if (temp_r0_2 > 8) {
        this->m_39c = 8;
    }
    *(s32 *)((s8 *)this + 0x378) = 0;
    *(s32 *)((s8 *)this + 0x378) = (s32) (*(s32 *)((s8 *)this + 0x378) | (1 << this->m_39c));
    this->m_394 = (f32) this->parameters[2];
    *(f32 *)&this->unk_398 = (f32) *(f32 *)((s8 *)this + 0x360);
}

void *TObjEneGibbles::create(void *arg0) {
    void *o;
    void *o2;
    o = __nw__7TObjectFUl(0x20);
    if (o != NULL) {
        o = __ct__11TObjControlFP7TObject(o, tl_04);
    }
    o2 = __nw__7TObjectFUl(0x44C);
    if (o2 != NULL) {
        o2 = TObjEneGibbles__ct((u8 *)o2, (void *)o, (s32)arg0);
    }
    return o2;
}

void TObjEneGibbles::free_static() {
    if ((u32) gibbles_combat_stat_entries != 0U) {
        mem_free((void*)gibbles_combat_stat_entries);
        gibbles_combat_stat_entries = 0U;
    }
    if ((u32) TObjEneGibbles__resource_bundle != 0U) {
        TLobby__sub_8001FE7C((void*)TObjEneGibbles__resource_bundle, 1);
        TObjEneGibbles__resource_bundle = 0U;
    }
}

void TObjEneGibbles::load_resources() {
    u8 *p;
    if (is_split_screen() != 0) {
        p = (u8 *)::operator new(0x440);
        if (p != NULL) {
            p = load_resource_from_descriptor(p, 1, lbl_804E28A0, 0, 0, 0);
        }
        TObjEneGibbles__resource_bundle = (u32) p;
    } else {
        p = (u8 *)::operator new(0x440);
        if (p != NULL) {
            p = load_resource_from_descriptor(p, 1, lbl_804E285C, 0, 0, 0);
        }
        TObjEneGibbles__resource_bundle = (u32) p;
    }
    TObjEneGibbles__render_node_index = 0;
    TObjEneGibbles__render_rotation_x = 0;
    gibbles_combat_stat_entries = (u32) mem_alloc(0xC);
    gibbles_boss_stat_handle = register_boss__6TLobbyFl(0x3D);
    ((s32 *) gibbles_combat_stat_entries)[0] = dispatch_shared_handler_b__6TLobbyFl(0x3D);
    ((s32 *) gibbles_combat_stat_entries)[2] = dispatch_shared_handler_b__6TLobbyFl(0x3E);
    ((s32 *) gibbles_combat_stat_entries)[1] = dispatch_shared_handler_b__6TLobbyFl(0x3F);
    gibbles_combat_stats_handle = register_object__6TLobbyFl(0x3D);
    (*(s32 *)&TObjEneGibbles__ai_parameters) = dispatch_shared_handler_a__6TLobbyFl(0x3D);
    Spawn_802DB7C0 s = gibbles_resource_binding_desc;
    s.a = *(s32 *)((s8 *)TObjEneGibbles__resource_bundle + 0x430);
    TLobby::spawn_npc_enemy((s16)0x44, (s32)(*(s32 *)((s8 *)(*(u8 **)((s8 *)TObjEneGibbles__resource_bundle + 0x42C)) + 8)), (s32)(*(s32 *)((s8 *)(*(u8 **)((s8 *)TObjEneGibbles__resource_bundle + 0x42C)) + 0xC)), (s32)(&s), (f32)(((f32 *)lbl_804E296C)[3]), (f32)TObjEneGibbles__data_805DE7E4);
}

void *__dt__13TUnk_80494938Fv(void *arg0, s16 arg1);
void *__dt__9TObjEnemyFv(TObjEnemy *arg0, s16 arg1);
void free_collision_body_parts(void *);
void __dl__7TObjectFPv(void *);
void __destroy_arr(void *, void *, int, int);

struct PartBase_802DB920 {
    u8 pad0[0x18];
};

struct Part_802DB920 : PartBase_802DB920 {
    virtual ~Part_802DB920();
};

struct Gib_802DB920 {
    u8 pad0[0x18];
    void *vt;
    u8 pad1c[0x3B4 - 0x1C];
    Part_802DB920 *p3b4;
    Part_802DB920 *p3b8;
};

Gib_802DB920 *TObjEneGibbles__sub_802DB920(Gib_802DB920 *self, s16 arg1) {
    if (self != NULL) {
        self->vt = lbl_804E29F0;
        if (self->p3b4 != NULL) {
            free_collision_body_parts(self->p3b4);
            delete self->p3b4;
            self->p3b4 = NULL;
        }
        if (self->p3b8 != NULL) {
            free_collision_body_parts(self->p3b8);
            delete self->p3b8;
            self->p3b8 = NULL;
        }
        free_collision_body_parts(self);
        __destroy_arr((u8 *)self + 0x3DC, (void *)__dt__15RenderFadeStateFv, 0x1C, 4);
        __dt__13TUnk_80494938Fv((u8 *)self + 0x3C0, -1);
        __dt__9TObjEnemyFv((TObjEnemy *)self, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(self);
        }
    }
    return self;
}

u8 *TObjEneGibbles__ct(u8 *arg0, void *parent, s32 arg2) {
    s32 i;
    void *p;
    __ct__9TObjEnemyFP7TObject(arg0, parent);
    *(void **)((s8 *)arg0 + 0x18) = (void *)lbl_804E29F0;
    __ct__13TUnk_80494938Fv((arg0 + 0x3C0));
    __construct_array(arg0 + 0x3DC, (void *)__ct__15RenderFadeStateFv, (void *)__dt__15RenderFadeStateFv, 0x1C, 4);
    *(s32 *)((s8 *)arg0 + 0) = lbl_805D3F60;
    ((TObjEneGibbles *)arg0)->apply_set_data((void *)arg2);
    ((TObjPlayer *)arg0)->init_position_vectors();
    ((TObjEneGibbles *)arg0)->scale.x = ((TObjEneGibbles *)arg0)->scale.y = *(f32 *)((s8 *)arg0 + 0x70) = TObjEneGibbles__data_805DE7EC;
    ((TObjEneGibbles *)arg0)->init_params();
    ((TObjEneGibbles *)arg0)->mode = 0;
    ((TObjEneGibbles *)arg0)->phase = 0;
    ((TObjEneGibbles *)arg0)->variant = 0;
    ((TObjEnemy *)arg0)->set_param(0x3D);
    ((TObjEneGibbles *)arg0)->subtype = 0;
    ((TObjEneGibbles *)arg0)->sub_802DBC94(((TObjEneGibbles *)arg0)->variant);
    ((TObjEneGibbles *)arg0)->action_table = gibbles_action_table;
    ((TObjMotion *)arg0)->set_field_d8((s32)(((TObjEneGibbles *)arg0)->action_table));
    *(s32 *)((s8 *)arg0 + 0xDC) = *(s32 *)((s8 *)TObjEneGibbles__resource_bundle + 0x430);
    ((TObjEneGibbles *)arg0)->requested_action = 0;
    ((TObjMotion *)arg0)->set_animation(((TObjEneGibbles *)arg0)->requested_action);
    ((TObjMotion *)arg0)->set_field_b8(((TObjEneGibbles *)arg0)->requested_action);
    init_collision_body_parts(arg0, lbl_804E296C, 1);
    ((TObjEneGibbles *)arg0)->m_37c = 0;
    *(s16 *)((s8 *)arg0 + 0x37E) = 0;
    ((TObjEneGibbles *)arg0)->movementParameters = (void *)lbl_804E2950;
    ((TObjEnemy *)arg0)->bind_enemy_combat_stats((u8 *)gibbles_boss_stat_handle, (u8 *)(((s32 *)gibbles_combat_stat_entries)[((TObjEneGibbles *)arg0)->m_37c]), (u8 *)gibbles_combat_stats_handle);
    ((TObjEneGibbles *)arg0)->referenceHp = ((TObjEneGibbles *)arg0)->hp;
    ((TObjEneGibbles *)arg0)->update_position();
    ((TObjEneGibbles *)arg0)->update_shadow_height();
    copy_position__20TBoss3VoloptHiraisinFv((s32)arg0);
    initialize_enemy_photon_effect(arg0);
    ((TObjEneGibbles *)arg0)->m_374 = 1;
    *(s32 *)((s8 *)arg0 + 0x3B0) = 0;
    ((TObjEneGibbles *)arg0)->m_3bc = 0;
    ((TObjChara *)arg0)->add_flags_2e4(0x11);
    ((TObjEneGibbles *)arg0)->actorFlags |= 0x06040000;
    ((TObjEneGibbles *)arg0)->m_380 = 0x101;
    *(s32 *)((s8 *)arg0 + 0x384) = 0x101;
    p = __nw__7TObjectFUl(0xAC);
    if (p != NULL) {
        p = __ct__14TObjCollidableFP7TObject(p, 0);
    }
    *(void **)((s8 *)arg0 + 0x3B4) = p;
    init_collision_body_parts(*(void **)((s8 *)arg0 + 0x3B4), (u8 *)lbl_804E296C + 0x2C, 1);
    p = __nw__7TObjectFUl(0xAC);
    if (p != NULL) {
        p = __ct__14TObjCollidableFP7TObject(p, 0);
    }
    ((TObjEneGibbles *)arg0)->m_3b8 = p;
    init_collision_body_parts(((TObjEneGibbles *)arg0)->m_3b8, (u8 *)lbl_804E296C + 0x58, 1);
    ((VObj_14_802DBA18 *)(arg0 + 0x3C0))->m3();
    for (i = 0; i < 4; i++) {
        ((RenderFadeState *)(&((G_802DBA18 *)arg0)->parts[i]))->activate_and_dispatch();
    }
    ((TObjEneGibbles *)arg0)->clear_lobby_object_state();
    return arg0;
}

void *TObjEneGibbles::get_center() { return (char*)this + 0x2fc; }

void TObjEneGibbles::sub_802DBC94(s32 i) {
    ((O_802DBC94 *)this)->f34 = (*(G_802DBC94 * *)&TObjEneGibbles__resource_bundle)->e[i].c;
    ((O_802DBC94 *)this)->f24 = (*(G_802DBC94 * *)&TObjEneGibbles__resource_bundle)->e[i].d;
}
}
