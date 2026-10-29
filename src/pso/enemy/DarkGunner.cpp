#include "pso/player/TObjPlayer_800D8FDC.h"
#include "pso/system/ChunkMaterialState.h"
#include "types.h"
#include "pso/enemy/TUnk_804909C4.h"
#include "pso/system/NinjaUtil.h"
#include "pso/player/TObjChara.h"
#include "pso/enemy/TObjEneDarkGunCenter.h"
#include "pso/player/TObjPlayer.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/TObjMotion.h"
#include "pso/enemy/TObjEneDarkGunner.h"
extern "C" void update_movement_status__17TObjEneDarkGunnerFv();
extern "C" void has_flag_0x800__9TObjCharaFv();
extern "C" void test_flag30_512__9TObjCharaFv();
extern "C" void test_flag_1000__9TObjCharaFv();
extern "C" void test_flag_256__9TObjCharaFv();
#include "pso/system/vector.h"

#include "pso/player/TUnk_80490470.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/enemy/TObjEneLappy.h"
#include "pso/enemy/TObjEneMe1GiGue.h"
#include "pso/enemy/TObjEnePanarms.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TNowLoading.h"
#include "pso/object/TObjFish.h"
#include "pso/object/TObjGyaranzoMissile.h"
#include "pso/misc/TEneEffHamon.h"
#include "pso/misc/TLanguage_801E4874.h"
#include "pso/enemy/SaverLifecycle.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/misc/MaterialColorFade.h"
#include "pso/TParticleCtrl.h"
#pragma readonly_strings on

struct VBase_18_800A2F94 { char pad[0x18]; };
struct VObj_18_800A2F94 : VBase_18_800A2F94 {
#define V(n) virtual void m##n();
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
    V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
    V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49)
    V(50) V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59)
    V(60) V(61) V(62) V(63) V(64) V(65) V(66) V(67) V(68) V(69)
    V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77) V(78)
#undef V
    virtual void m79(void *);
};

struct Atk_800A2F94 { s32 w[4]; };
struct Obj_800A2F94 { u8 pad[0x3F0]; s32 f3F0[4]; };

struct V_800A1FEC { f32 x, y, z; };

struct Obj_800A1FEC {
    u8 pad0[0x30];
    u32 f30;
    u8 pad34[0x38 - 0x34];
    V_800A1FEC pos;
    u8 pad44[0xB8 - 0x44];
    s16 fB8;
    u8 padBA[0xC0 - 0xBA];
    f32 fC0;
    u8 padC4[0x2A8 - 0xC4];
    u8 *target;
    u8 pad2AC[0x338 - 0x2AC];
    u16 f338;
    u8 pad33A[0x37C - 0x33A];
    s32 state;
    u8 pad380[0x388 - 0x380];
    u32 f388;
    u8 pad38C[0x394 - 0x38C];
    f32 f394;
    u8 pad398[0x39A - 0x398];
    s16 timer;
    u8 pad39C[0x3B0 - 0x39C];
    s32 count;
    V_800A1FEC f3B4;
    V_800A1FEC f3C0[4];
    void *parts[4];
};

typedef struct Obj_800A1814 Obj_800A1814;
struct Sub_800A2390 { u8 pad[0x18]; u32 f18; };

struct P_800A2390 {
    u8 pad0[0x30];
    u32 f30;
    u8 pad34[0x60 - 0x34];
    s32 f60;
    s32 f64;
    u8 pad68[0xA4 - 0x68];
    Sub_800A2390 *fA4;
    u8 padA8[0xB8 - 0xA8];
    s16 fB8;
    u8 padBA[0x308 - 0xBA];
    f32 f308;
    f32 f30C;
    f32 f310;
    u8 pad314[0x37C - 0x314];
    s32 state;
    u8 pad380[0x388 - 0x380];
    u32 f388;
    u8 pad38C[0x398 - 0x38C];
    s16 f398;
    u8 pad39A[0x39E - 0x39A];
    s16 f39E;
    f32 f3A0;
    f32 f3A4;
    s32 f3A8;
    s32 f3AC;
};

extern "C" {
s32 apply_actor_gravity(void *, s32, f32);
s32 advance_animation_playback(void *);
s32 minimap_render_dot(void *, s32, s32, s32);
void TObjPlayer__sub_800A16C4(u8 *arg0);
void queue_destruction__7TObjectFv(void *arg0);
s32 update_if_active__15TObjEneMe1GiGueFl(void *, s32);
void *spawn_particle_effect(void *pos, s32 id);
s32 TObjPlayer__sub_800A3210(s32 i, s32 _w1, s32 _w2);
u8 *TObjPlayer__sub_800A4204(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4);
s32 submit_cursor_candidate(void *, s32);
s32 play_sound_effect(int, void *, int, int);
void * __nw__7TObjectFUl(int);
s32 TObjPlayer__sub_800A1FEC(void *arg0);
void enemy_set_heading_velocity(void *, f32, s32);
f32 TObjPlayer__sub_800A3200(s32 arg0);
s32 play_persistent_sound(int, void *, void *, int, int);
extern s32 actor_frame_tick;
s32 TObjPlayer__sub_800A2390(void *arg0_);
typedef struct Obj_800A0EDC {
    u8 pad0[0x30];
    s32 flags;
    u8 pad34[0x38 - 0x34];
    u8 pos[0x2FC - 0x38];
    u8 home[0x374 - 0x2FC];
    s32 f374;
    u8 pad378[0x37C - 0x378];
    s32 count;
    s32 sel;
    u16 ids[16];
    s32 f3A4;
} Obj_800A0EDC;

typedef struct Vec_800A12C0 {
    f32 x, y, z;
} Vec_800A12C0;

typedef struct Pair_800A12C0 {
    Vec_800A12C0 dest;
    Vec_800A12C0 pos;
} Pair_800A12C0;

typedef struct Obj_800A12C0 {
    u8 pad0[0x30];
    s32 flags30;
    u8 pad34[0x38 - 0x34];
    Vec_800A12C0 pos;
    u8 pad44[0x50 - 0x44];
    Vec_800A12C0 dest;
    u8 pad5C[0xB8 - 0x5C];
    s16 fB8;
    u8 padBA[0x37C - 0xBA];
    s32 state;
    u8 pad380[0x388 - 0x380];
    s32 flags388;
} Obj_800A12C0;

struct G_800A3210 { u8 pad[0x18]; s32 arr[1]; };

struct Obj_800A2EDC { u8 pad0[0x18]; void *vt; u8 pad1c[0x3F0 - 0x1C]; void *items[4]; void *p400; void *p404; };

typedef struct Vec_800A159C {
    f32 x, y, z;
} Vec_800A159C;

typedef struct Obj_800A159C {
    u8 pad0[0x38];
    Vec_800A159C pos;
    u8 pad44[0x60 - 0x44];
    s32 f60;
    s32 f64;
    u8 pad68[0x326 - 0x68];
    s16 f326;
    u8 pad328[0x38C - 0x328];
    f32 f38C;
    f32 hover_height;
    f32 f394;
    u8 pad398[0x3B4 - 0x398];
    u8 mtx3B4[0xC];
    Vec_800A159C v3C0[4];
} Obj_800A159C;

typedef struct Vec_800A1814 {
    f32 x, y, z;
} Vec_800A1814;

typedef struct XZ_800A1814 {
    f32 x, z;
} XZ_800A1814;

typedef struct Ofs_800A1814 {
    XZ_800A1814 v[4];
} Ofs_800A1814;

typedef struct Obj_800A1814 {
    u8 pad0[0x38];
    Vec_800A1814 pos;
    u8 pad44[0x38C - 0x44];
    f32 f38C;
} Obj_800A1814;

struct Vec_800A1D70 { f32 x, y, z; };

struct Vec_800A34E8 { f32 x, y, z; };

struct Raw_800A10A0 { u8 b[12]; };

s32 update_movement_status__9TObjCharaFv();
s32 update_action_hold_status__9TObjCharaFv();
void calc_velocity_toward_destination(void *, Vec_800A12C0, Vec_800A12C0, f32);
s32 check_path_obstructed(void *, Vec_800A1D70 *);
f32 atan2_float(f32, f32);
int TObjFish__sub_8001EDB0(void*, void*);
int get_bml_model(void*);
void TLobby__sub_8001FE7C(void*, int);
u8 * csnVector(void *, Vec_800A34E8 *, s32);
void * __dt__13TUnk_80490470Fv(void *, s16);
s32 trigger_targets_action__10TObjPlayerFv();
u8 * TObjEneDarkGunCenter__ct(u8 *arg0, s32 arg1, s32 arg2);
void clear_lappy_flag_set_param(TObjEneLappy *arg0);
void fn_800A0FDC(TObjEneLappy *arg0);
void TObjPlayer__sub_800A100C(s32 _w0);
s32 update_action_hold_status__17TObjEneDarkGunnerFv(s32 arg0);
void init_scale_global__10TObjPlayerFv(void);
void vfunc_61__17TObjEneDarkGunnerFv(u8 *arg0);
int TObjPlayer__sub_800A1808(void* p);
void TObjPlayer__sub_800A1974(void *);
void TObjPlayer__sub_800A1C84(TObjPlayer *arg0);
void TObjPlayer__sub_800A1D70(u8 *arg0);
void vfunc_62__17TObjEneDarkGunnerFv(void *arg0);
void TObjPlayer__sub_800A27CC(TObjPlayer *arg0);
Obj_800A2EDC * TObjPlayer__sub_800A2EDC(Obj_800A2EDC *arg0, s16 arg1);
u8 *TObjPlayer__sub_800A2F94(u8 *, s32, u8 *);
void vfunc_28__17TObjEneDarkGunnerFv(void);
void vfunc_58__17TObjEneDarkGunnerFv(void);
void vfunc_59__17TObjEneDarkGunnerFv(void);
void TEneEffHamon__sub_800A380C(void);
u8 * __ct__12TEneEffHamonFv(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, f32 farg0);
void *__dt__15TObjEnemyCustomFv(void *arg0, s16 arg1);
u8 *get_enemy_entity(u16 arg0);
s32 __ct__9TObjEnemyFP7TObject(void *);
s32 angle_diff_s16(s32, s32);
s32 free_collision_body_parts(void *);
s32 init_collision_body_parts(void *, void *, int);
s32 project_actor_to_ground(void *, void *, int);
void free_if_valid__10TObjPlayerFl(void*);
s32 __dl__7TObjectFPv(void *);
s32 rand();
s32 vec3_add_to(void *, void *);
s32 matrix_mult_vec(int, void *, void *);
f32 vector_length(void *);
void rotate_vector_by_matrix(int, void *, void *);
s32 rotate_matrix_y(int, int);
s32 rotate_matrix_z(int, int);
s32 subtract_vector(void *, void *);
s32 push_matrix_from(void *);
s32 push_matrix();
s32 pop_matrix();
s32 post_translate_matrix(s32);
void draw_chunk_object(void *child);

extern s32 __vt__20TObjEneDarkGunCenter[];
extern Ofs_800A1814 hamon_effect_offset_table;
extern Vec_800A159C lbl_8043A6A4;

void obj_setFlags30(void *, u32);
void __ct__15TObjEnemyCustomFP7TObject(void *, s32, void *);
}
void move_with_wall_slide(u8 *arg0);
int initialize_enemy_photon_effect(void *p);
extern "C" {
extern Atk_800A2F94 dark_gunner_attack_binding_desc;
extern s32 dark_gunner_class_name_ptr;
extern s32 lbl_805D4FF8[1];
extern s32 lbl_805D4FFC[1];
extern s32 lbl_805D5000[1];

extern "C" {
void get_anim_node_position__15TObjEnemyCustomFlP3Vec();
}
extern "C" {
void vfunc_6__8TObjBaseFPsl();
}
extern "C" {
void vfunc_63__15TObjEnemyCustomFv();
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
struct VObj_18_800A28A4;
extern "C" {
void TObjPlayer__sub_800A1978(VObj_18_800A28A4 *self);
}
extern "C" {
void TObjPlayer__sub_800A28A4(VObj_18_800A28A4 *self);
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
void vfunc_79__15TObjEnemyCustomFPl();
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
void get_center__9TObjCharaFv();
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
void is_target_in_attack_range__9TObjCharaFv();
}
extern "C" {
extern u8 lbl_8043A498[];
}
extern "C" {
extern u8 lbl_8043A4B0[];
}
extern "C" {
extern u8 lbl_8043A4C8[];
}
extern "C" {
extern u8 lbl_8043A4E0[];
}
extern "C" {
extern u8 lbl_8043A4F0[];
}
extern "C" {
extern u8 lbl_8043A508[];
}
extern "C" {
extern u8 lbl_8043A520[];
}
extern "C" {
extern u8 lbl_8043A538[];
}
extern "C" {
extern u8 lbl_8043A550[];
}
extern "C" {
extern u8 lbl_8043A564[];
}
extern "C" {
extern u8 lbl_8043A578[];
}
extern "C" {
extern u8 lbl_8043A590[];
}
extern "C" {
extern u8 lbl_8043A5A8[];
}
extern "C" {
extern u8 lbl_8043A5C0[];
}
extern "C" {
extern u8 lbl_8043A5D8[];
}
extern "C" {
extern u8 lbl_8043A5EC[];
}
extern "C" {
extern u8 lbl_8043A600[];
}
extern "C" {
extern u8 lbl_8043A618[];
}
extern "C" {
extern u8 lbl_8043A62C[];
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
void vfunc_60__15TObjEnemyCustomFv();
}
extern "C" {
void update_object_view_visibility__8TObjBaseFff();
}
extern "C" {
void update_poison_status__9TObjCharaFv();
}
void *bm_ene_darkgunner_model_names[5] = {
    (void *)&lbl_8043A498, (void *)&lbl_8043A4B0, (void *)&lbl_8043A4C8, (void *)&lbl_8043A4E0,
    (void *)0x0,
};
void *bm_ene_darkgunner_motion_names[15] = {
    (void *)&lbl_8043A4F0, (void *)&lbl_8043A508, (void *)&lbl_8043A520, (void *)&lbl_8043A538,
    (void *)&lbl_8043A550, (void *)&lbl_8043A564, (void *)&lbl_8043A578, (void *)&lbl_8043A590,
    (void *)&lbl_8043A5A8, (void *)&lbl_8043A5C0, (void *)&lbl_8043A5D8, (void *)&lbl_8043A5EC,
    (void *)&lbl_8043A600, (void *)&lbl_8043A618, (void *)0x0,
};
void *bm_ene_darkgunner_resource_descriptor[4] = {
    (void *)&lbl_8043A62C, (void *)&bm_ene_darkgunner_model_names, (void *)&bm_ene_darkgunner_motion_names, (void *)0x4000e,
};
void *lbl_80490668[56] = {
    (void *)0x10000, (void *)0xd, (void *)0x3f800000, (void *)0x0,
    (void *)0x20000, (void *)0xb, (void *)0x3f4ccccd, (void *)0x1,
    (void *)0x20000, (void *)0x5, (void *)0x3f19999a, (void *)0x1,
    (void *)0x20004, (void *)0x0, (void *)0x3f4ccccd, (void *)0x4,
    (void *)0x10004, (void *)0x1, (void *)0x3f800000, (void *)0x4,
    (void *)0x20000, (void *)0x3, (void *)0x3f333333, (void *)0x8,
    (void *)0x20000, (void *)0x2, (void *)0x3f333333, (void *)0x8,
    (void *)0x30007, (void *)0x4, (void *)0x3f333333, (void *)0x10,
    (void *)0x2000b, (void *)0xa, (void *)0x3f333333, (void *)0x0,
    (void *)0x2000c, (void *)0x6, (void *)0x3f19999a, (void *)0x8,
    (void *)0x3000a, (void *)0x7, (void *)0x3f000000, (void *)0x10,
    (void *)0x1000b, (void *)0x8, (void *)0x3f333333, (void *)0x0,
    (void *)0x20000, (void *)0x9, (void *)0x3f19999a, (void *)0x0,
    (void *)0x20000, (void *)0xc, (void *)0x3f333333, (void *)0x4,
};
void *lbl_80490748[14] = {
    (void *)0x42a00000, (void *)0x3e8e38e3, (void *)0x400, (void *)0x1e0000,
    (void *)0x0, (void *)0x1, (void *)0x0, (void *)0x42a00000,
    (void *)0x3e8e38e3, (void *)0x400, (void *)0x1e0000, (void *)0x0,
    (void *)0x1, (void *)0x0,
};
void *lbl_80490780[11] = {
    (void *)0x0, (void *)0x40600000, (void *)0x0, (void *)0x41200000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_804907AC[4] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
};
Vec_800A159C lbl_804907BC[4] = {
    {0.0f, 10.0f, 2.0f}, {0.0f, 10.0f, -2.0f}, {2.0f, 10.0f, 0.0f}, {-2.0f, 10.0f, 0.0f},
};
void *__vt__17TObjEneDarkGunner[83] = {
    (void *)0x0, (void *)0x0, (void *)&TObjPlayer__sub_800A2EDC, (void *)&TObjPlayer__sub_800A28A4,
    (void *)&TObjPlayer__sub_800A1978, (void *)&render_shadows__9TObjEnemyFv, (void *)&vfunc_6__8TObjBaseFPsl, (void *)&apply_object_set_data__8TObjBaseFPv,
    (void *)&reset_motion_fields__9TObjCharaFv, (void *)&get_center__9TObjCharaFv, (void *)&update_object_view_visibility__8TObjBaseFff, (void *)&classify_actor_view_detail__8TObjBaseFfff,
    (void *)&get_name__9TObjEnemyFv, (void *)&interact__14TObjCollidableFl, (void *)&add_actor_exp__9TObjCharaFl, (void *)&consume_timer_field__9TObjCharaFl,
    (void *)&get_actor_level_index__9TObjCharaFv, (void *)&update_actor_ground_y__9TObjCharaFv, (void *)&vfunc_18__9TObjCharaFPUc, (void *)&is_actor_cadence_frame__9TObjCharaFl,
    (void *)&select_melee_contact_body__9TObjCharaFPvf, (void *)&calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf, (void *)&receive_physical_attack__9TObjCharaFPvf, (void *)&receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll,
    (void *)&receive_weapon_special_attack__9TObjCharaFPvPv, (void *)&apply_knockback_from_attacker__9TObjCharaFPUcf, (void *)&try_start_action__9TObjCharaFll, (void *)&roll_physical_accuracy__9TObjCharaFPvlf,
    (void *)&vfunc_28__17TObjEneDarkGunnerFv, (void *)&vfunc_29__9TObjCharaFv, (void *)&is_target_in_attack_range__9TObjCharaFv, (void *)&test_flag_256__9TObjCharaFv,
    (void *)&test_flag30_512__9TObjCharaFv, (void *)&has_flag_0x800__9TObjCharaFv, (void *)&test_flag_1000__9TObjCharaFv, (void *)&update_poison_status__9TObjCharaFv,
    (void *)&update_action_hold_status__17TObjEneDarkGunnerFv, (void *)&vfunc_37__9TObjCharaFv, (void *)&update_flag30_timer__9TObjCharaFv, (void *)&update_movement_status__17TObjEneDarkGunnerFv,
    (void *)&update_shock_clock__9TObjCharaFv, (void *)&update_attack_stat_status__9TObjCharaFv, (void *)&update_defense_stat_status__9TObjCharaFv, (void *)&vfunc_43__9TObjCharaFv,
    (void *)&apply_poison_status__9TObjCharaFv, (void *)&apply_paralysis__9TObjCharaFv, (void *)&apply_slow_status__9TObjCharaFv, (void *)&apply_confusion_status__9TObjCharaFv,
    (void *)&apply_movement_ailment__9TObjCharaFl, (void *)&apply_shock_status__9TObjCharaFv, (void *)&clear_harmful_statuses__9TObjCharaFv, (void *)&apply_attack_stat_status__9TObjCharaFPv,
    (void *)&apply_defense_stat_status__9TObjCharaFPv, (void *)&cure_poison_ailment__9TObjCharaFv, (void *)&cure_paralysis__9TObjCharaFv, (void *)&clear_all_status_effects__9TObjCharaFv,
    (void *)&apply_action_hold_status__9TObjCharaFf, (void *)&apply_anti_technique__9TObjCharaFl, (void *)&vfunc_58__17TObjEneDarkGunnerFv, (void *)&vfunc_59__17TObjEneDarkGunnerFv,
    (void *)&vfunc_60__15TObjEnemyCustomFv, (void *)&vfunc_61__17TObjEneDarkGunnerFv, (void *)&vfunc_62__17TObjEneDarkGunnerFv, (void *)&vfunc_63__15TObjEnemyCustomFv,
    (void *)&reset_pose__9TObjCharaFv, (void *)&get_anim_node_position__15TObjEnemyCustomFlP3Vec, (void *)&vfunc_66__9TObjCharaFv, (void *)&vfunc_67__9TObjCharaFf,
    (void *)&get_pos__9TObjCharaFl, (void *)&apply_switch_attack__9TObjCharaFv, (void *)&enemy_spawn_jellen_effect__9TObjCharaFv, (void *)&trigger_switch_attack__9TObjCharaFv,
    (void *)&enemy_spawn_zalure_effect__9TObjCharaFv, (void *)&recalc_stats__9TObjCharaFv, (void *)&vfunc_74__9TObjEnemyFl, (void *)&vfunc_75__9TObjCharaFf,
    (void *)&vfunc_76__9TObjCharaFv, (void *)&vfunc_77__9TObjCharaFv, (void *)&vfunc_78__9TObjCharaFl, (void *)&vfunc_79__15TObjEnemyCustomFPl,
    (void *)&apply_hit_message_flags__9TObjEnemyFPv, (void *)&apply_set_data__9TObjEnemyFPv, (void *)&clear_lobby_object_state__9TObjEnemyFv,
};

extern u8 identity_matrix[];
extern s32 TObjEneDarkGunCenter__name;
extern s32 lbl_805D5004;
extern f32 player_scale_factor;
extern u32 player_effect_bml_resource;
extern u32 TObjPlayer__effect_resource;
extern s32 lbl_805D5014;
extern s32 lbl_805D5018;
extern s32 TObjPlayer__shadow_chunk_object;
extern void *tl_04;

u8 *TObjEneDarkGunCenter__ct(u8 *arg0, s32 arg1, s32 arg2) {
    Obj_800A0EDC *o;
    s32 i;
    __ct__9TObjEnemyFP7TObject(arg0);
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__20TObjEneDarkGunCenter;
    *(s32 *)((s8 *)arg0 + 0) = TObjEneDarkGunCenter__name;
    ((TObjEneDarkGunCenter *)(arg0))->apply_set_data((void *)arg2);
    ((TBoss3Volopt *)arg0)->reset_photon_effect();
    o = (Obj_800A0EDC *)arg0;
    VecCopy((Vec *)o->home, (const Vec *)o->pos);
    o->flags = o->flags | 0x06000000 | 0x800;
    o->f374 = 0;
    ((TObjEnemy *)arg0)->set_param(0x22);
    o->sel = -1;
    o->count = 0;
    for (i = 0; i < 16; i++) {
        o->ids[i] = 0xFFFF;
    }
    o->f3A4 = -1;
    return arg0;
}

void clear_lappy_flag_set_param(TObjEneLappy *ene_lappy) {
    ene_lappy->m_388 = (s32) (ene_lappy->m_388 & 0xFBFFFFFF);
    ene_lappy->set_param(0x22);
}

void fn_800A0FDC(TObjEneLappy *ene_lappy) {
    ene_lappy->m_388 = (s32) (ene_lappy->m_388 | 0x04000000);
    ene_lappy->set_param(0x23);
}

void TObjPlayer__sub_800A100C(s32 _w0) {  }

s32 TObjEneDarkGunner::update_movement_status() {
    s32 arg0 = (s32)this;
    if (update_movement_status__9TObjCharaFv() != 0) {
        TObjPlayer__sub_800A100C(arg0);
        return 1;
    }
    return 0;
}

s32 TObjEneDarkGunner::update_action_hold_status() {
    s32 arg0 = (s32)this;
    if (update_action_hold_status__9TObjCharaFv() != 0) {
        TObjPlayer__sub_800A100C(arg0);
        return 1;
    }
    return 0;
}

#pragma push
#pragma inline_depth(1)
#pragma auto_inline on
#pragma dont_inline off
void TObjPlayer::step_along_ground() {
    u8 *arg0 = (u8 *)this;
    Raw_800A10A0 pos;
    Raw_800A10A0 vel;
    Raw_800A10A0 dir;
    Raw_800A10A0 v;
    s32 ang;
    s32 sign;
    s32 b;
    s32 a;
    s32 i;
    u8 *hit;
    u8 *q;

    VecCopy(&this->prev_position, (const Vec *)&this->position);
    VecCopy((Vec *)&pos, (const Vec *)&this->m_2fc);
    vel = *(Raw_800A10A0 *)(arg0 + 0x308);
    vec_set_length((Vec *)&vel, 10.0f + ((f32 (*)(int))TObjPlayer__sub_800A3200)(0));
    ((void (*)(void *, void *))vec3_add_to)(&pos, &vel);
    hit = ((u8 * (*)(void *, void *, s32))csnVector)(arg0 + 0x2FC, &pos, -1);
    if (hit != NULL) {
        a = 10430.38043493439 * ((f64 (*)(f32, f32))atan2_float)(*(f32 *)(arg0 + 0x308), *(f32 *)(arg0 + 0x310));
        q = *(u8 **)(hit + 4);
        b = 10430.38043493439 * ((f64 (*)(f32, f32))atan2_float)(*(f32 *)(q + 0xC), *(f32 *)(q + 0x14));
        *(s32 *)(arg0 + 0x3A8) = b - (0x8000 - angle_diff_s16(a, b));
    }
    if ((1.0f / 32768.0f) * (f32)rand() < 0.5f) {
        sign = -1;
    } else {
        sign = 1;
    }
    for (i = 0, ang = 0; i < 15; i++, ang += 0x1000) {
        if (i == 0) {
            VecCopy((Vec *)&dir, (const Vec *)&this->unk_308);
        } else {
            ((void (*)(void *))push_matrix_from)(identity_matrix);
            ((void (*)(int, s32))rotate_matrix_y)(0, sign * ang);
            rotate_vector_by_matrix(0, (u8 *)&this->unk_308, &dir);
            ((void (*)(void))pop_matrix)();
        }
        VecCopy((Vec *)&v, (const Vec *)&this->position);
        ((void (*)(void *, void *))vec3_add_to)(&v, &dir);
        if (project_actor_to_ground(arg0, &v, 0) == 1) {
            VecCopy((Vec *)&this->position, (const Vec *)&v);
            VecCopy((Vec *)&this->unk_308, (const Vec *)&this->position);
            ((void (*)(void *, void *))subtract_vector)(arg0 + 0x308, (u8 *)&this->prev_position);
            return;
        }
    }
}
extern int fold_flush_0;
#pragma pop

void init_scale_global__10TObjPlayerFv(void) {
    player_scale_factor = ((f32 (*)(int))TObjPlayer__sub_800A3200)(3);
}

void TObjPlayer::update_move_to_destination() {
    Obj_800A12C0 *o = (Obj_800A12C0 *)this;
    switch (this->m_37c) {
    case -1:
        break;
    case 0:
        o->flags388 &= ~0x200000;
        o->flags388 |= 0x480000;
        this->requested_action = 0;
        this->m_37c = 1;
    case 1: {
        advance_animation_playback(o);
        if (!(this->actorFlags & 0x800000)) {
            ((s32 (*)(void *, int, f32))apply_actor_gravity)(o, 0, 0.0f);
        }
        calc_velocity_toward_destination(o, o->pos, o->dest, ((f32 (*)(int))TObjPlayer__sub_800A3200)(0));
        move_with_wall_slide((u8 *)o);
        if (xz_distance_squared((Vec *)&o->pos, (Vec *)&o->dest) <= 100.0f) {
            o->flags388 &= ~0x80000;
            apply_fall_damage_flag();
        }
        break;
    }
    }
}

s32 TObjPlayer::update_hide_sequence() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r3;
    s32 temp_r4;
    s32 temp_r5;

    switch (this->m_37c) {
    case 0:
        ((TObjBase *)arg0)->obj_clearFlags30(0x240300);
        *(s32 *)&this->unk_388 = (s32) (*(s32 *)&this->unk_388 | 0x800000);
        temp_r5 = *(s32 *)&this->unk_388;
        temp_r4 = temp_r5 & 0xFFB7FFFF;
        *(s32 *)&this->unk_388 = temp_r4;
        this->requested_action = 8;
        this->m_39c = TObjPlayer__sub_800A3210(1, temp_r4, temp_r5);
        this->m_37c = 1;
    case 1:
        advance_animation_playback(arg0);
        if (!(this->actorFlags & 0x800000)) {
            apply_actor_gravity(arg0, 0, 0.0f);
        }
        ((TObjPlayer *)arg0)->update_collisions();
        temp_r3 = this->m_39c - 1;
        this->m_39c = (s16) temp_r3;
        if ((s16) temp_r3 <= 0) {
            set_hidden_flag();
        }
        break;
    case -1:
        *(s32 *)&this->unk_388 = (s32) (*(s32 *)&this->unk_388 & 0xFF7FFFFF);
        break;
    }
    minimap_render_dot((u8 *)&this->position, -0x5DB4, 1, 0);
    submit_cursor_candidate(arg0, -1);
}

void TObjPlayer::trigger_action_if_not_flagged() {
    if (!(*(s32 *)&this->actorFlags & 0x800) && !(*(s32 *)&this->unk_388 & 0x800000)) {
        update_if_active__15TObjEneMe1GiGueFl(this, 6);
    }
}

void TObjEneDarkGunner::sub_800A1520() {
  s16 temp_r0;
  temp_r0 = *((s16 *) (((0, (s8 *) this)) + 0x326));
  {
    switch (temp_r0)
    {
      case 0:
        TObjPlayer__sub_800A27CC((TObjPlayer *)this);
        return;
      case 1:
        TObjPlayer__sub_800A2390(this);
        return;
      case 2:
        TObjPlayer__sub_800A1FEC((void *)this);
        return;
      case 4:
        TObjPlayer__sub_800A1D70((u8 *)this);
        return;
      case 3:
        TObjPlayer__sub_800A16C4((u8 *)this);
        return;
      case 5:
        TObjPlayer__sub_800A1C84((TObjPlayer *)this);
        return;
      case 6:
        ((TObjPlayer *)((u8 *)this))->update_hide_sequence();
        return;
      case 8:
        ((TObjPlayer *)((u8 *)this))->update_move_to_destination();
        break;
    }
  }
}

void TObjEneDarkGunner::sub_800A159C() {
    Obj_800A159C *o = (Obj_800A159C *)this;
    f32 lo;
    s32 i;
    this->m_394 += (-0.10888889f);
    o->hover_height += this->m_394;
    o->hover_height = (o->hover_height < 0.0f) ? 0.0f : ((o->hover_height < 9.0f) ? o->hover_height : 9.0f);
    push_matrix_from(identity_matrix);
    post_translate_matrix((s32)&o->pos);
    rotate_matrix_z(0, this->rotation_z);
    rotate_matrix_y(0, this->rotation_y);
    Vec_800A159C t = lbl_8043A6A4;
    lo = 5.0f + o->hover_height;
    t.y = lo + this->render_y_offset;
    matrix_mult_vec(0, &t, o->mtx3B4);
    if (this->mode == 2) {
        for (i = 0; i < 4; i++) {
            matrix_mult_vec(0, &lbl_804907BC[i], &o->v3C0[i]);
        }
    }
    pop_matrix();
}

void TObjPlayer__sub_800A16C4(u8 *player) {
    s16 temp_r4;
    switch (((TObjPlayer *)player)->m_37c) {
    case 0:
        *(s32 *)((s8 *)player + 0x388) = (s32) (*(s32 *)((s8 *)player + 0x388) | 1);
        ((TObjBase *)player)->obj_clearFlags30(0x100);
        *(s16 *)((s8 *)player + 0x33C) = (s16) *(s16 *)((s8 *)player + 0x33A);
        ((TObjPlayer *)player)->requested_action = 0;
        ((TObjPlayer *)player)->actorFlags = (s32) (((TObjPlayer *)player)->actorFlags & 0xFF9FFFFF);
        ((TObjPlayer *)player)->m_37c = 1;
        goto case1;
    case 1:
    case1:
        advance_animation_playback(player);
        if (!(((TObjPlayer *)player)->actorFlags & 0x800000)) {
            apply_actor_gravity(player, 0, 0.0f);
        }
        ((TObjPlayer *)player)->update_collisions();
        temp_r4 = *(s16 *)((s8 *)player + 0x33C);
        *(s16 *)((s8 *)player + 0x33C) = (temp_r4 - 1);
        if (temp_r4 < 0) {
            ((TObjPlayer *)player)->m_33e = (s16) ((TObjPlayer *)player)->hp;
            *(s32 *)((s8 *)player + 0x388) = (s32) (*(s32 *)((s8 *)player + 0x388) & 0xFFFFFFFE);
            ((TObjPlayer *)player)->set_hidden_flag();
        }
        break;
    case -1:
        break;
    }
    minimap_render_dot(player + 0x38, -0x5DB4, 1, 0);
}

void TObjEneDarkGunner::vfunc_61() {
    u8 *arg0 = (u8 *)this;
    ((TObjBase *)arg0)->obj_clearFlags30((s32)(0x100U));
    spawn_particle_effect(((u8 *)&this->m_2fc), 0xD7);
    play_sound_effect(0x4003B22D, (u8 *)&this->position, 0, 0);
}

int TObjPlayer__sub_800A1808(void* p) { return (*(u32*)((char*)p + 0x30) >> 23) & 0x1; }

#pragma push
#pragma opt_loop_invariants off
void TObjPlayer::spawn_hamon_effects(s32 arg1, s32 arg2, f32 farg0) {
    Obj_800A1814 *o = (Obj_800A1814 *)this;
    Vec_800A1814 p;
    Ofs_800A1814 ofs = hamon_effect_offset_table;
    s32 i;
    void *e;
    p.y = 0.01f + (o->pos.y + o->f38C);
    for (i = 0; i < 4; i++) {
        p.x = o->pos.x + ofs.v[i].x;
        p.z = o->pos.z + ofs.v[i].z;
        e = __nw__7TObjectFUl(0x60);
        if (e != NULL) {
            __ct__12TEneEffHamonFv((u8 *)e, (s32)&p, arg1, arg2, farg0);
        }
    }
}
extern int fold_flush_1;
#pragma pop

void TObjPlayer::render_shadow() {
    s32 arg0 = (s32)this;
    if (this->obj_testFlags30(0x800) == 0) {
        if (is_flag_set_388_bit26() == 0) {
            TObjFish::set_global_param(lbl_805D5014);
        } else {
            TObjFish::set_global_param(lbl_805D5018);
        }
        push_matrix();
        post_translate_matrix(arg0 + 0x3B4);
        draw_chunk_object((void *)TObjPlayer__shadow_chunk_object);
        pop_matrix();
    }
}

void TObjPlayer__sub_800A1974(void *) {  }

struct Motion_800A28A4 {
    f32 f0;
    f32 speed;
    u8 pad8[0x28 - 0x8];
    f32 blend;
};

struct VObj_18_800A28A4 : VBase_18_800A2F94 {
#define V(n) virtual void m##n();
#define S(n) virtual s32 m##n();
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8)
    virtual s32 m9(f32, f32, f32);
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
    S(30) S(31) V(32) V(33) S(34) V(35) V(36) S(37) S(38) V(39)
    V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49)
    V(50) V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59)
    V(60) V(61)
#undef S
#undef V
    u8 pad1C[0x24 - 0x1C];
    s32 texture;
    u8 pad28[0x38 - 0x28];
    Vec_800A159C pos;
    u8 pad44[0x60 - 0x44];
    s32 rotation_y;
    s32 rotation_z;
    u8 pad68[0x74 - 0x68];
    Vec_800A159C prev_pos;
    u8 pad80[0xA4 - 0x80];
    Motion_800A28A4 *motion;
    u8 padA8[0x2FC - 0xA8];
    Vec_800A159C ground_pos;
    u8 pad308[0x326 - 0x308];
    s16 action;
    u8 pad328[0x374 - 0x328];
    s32 next_action;
    u8 pad378[0x37C - 0x378];
    s32 state;
    u8 pad380[0x388 - 0x380];
    u32 flags;
    f32 render_y_offset;
    u8 pad390[0x3B4 - 0x390];
    Vec_800A159C shadow_pos;
    u8 pad3C0[0x3F0 - 0x3C0];
    TObjPlayer *children[4];
    TParticleCtrl *trail_emitter;
    TParticleCtrl *glow_emitter;
    MaterialColorFade fade;
    u8 pad420[0x424 - 0x420];
    s32 material_phase;
};

struct MaterialColor {
    u32 argb;
    f32 r;
    f32 g;
    f32 b;
};

extern "C" {
extern s32 saved_model_render_flags;
extern u32 model_render_flags;
extern const MaterialColor lbl_8043A668;
extern const Vec_800A159C lbl_8043A678;
void translate_matrix(u32 arg0, f32 x, f32 y, f32 z);
void set_chunk_material_override_pair(s32 first, s32 second);
void restore_scene_lighting(void);
void select_actor_lighting(s32 obj);
f32 sin_table_lookup(s32 angle);
f32 fabs_float(f32 x);
extern s32 lbl_805D5020;
extern s32 lbl_805D5024;
extern s32 lbl_805D5028;
void TObjPlayer__sub_8023DEE0(s16 *p, s16 a, s16 b, u16 id);
TParticleCtrl *create_particle_emitter(void *pos, s32 id);
}


void TObjPlayer__sub_800A1978(VObj_18_800A28A4 *self) {
    s32 view;
    s32 drawn;
    s32 visible;
    BOOL cancel;
    s32 i;

    if (((TObjEnemy *)self)->obj_testFlags30(0x02000000) == 0) {
        view = self->m9(150.0f, 400.0f, 15.0f);
        if (view != 0) {
            select_actor_lighting((s32)self);
            TObjPlayer::toggle_particle_effect();
            drawn = 1;
            push_matrix();
            saved_model_render_flags = model_render_flags;
            model_render_flags &= ~0x10;
            translate_matrix(0, self->pos.x, self->pos.y + self->render_y_offset, self->pos.z);
            rotate_matrix_z(0, self->rotation_z);
            rotate_matrix_y(0, self->rotation_y);
            if (self->flags & 0x400000) {
                f32 s;
                model_render_flags |= 0x820;
                set_chunk_material_override_pair(0xFF00, 0x800);
                s = -0.25f * fabs_float(sin_table_lookup(self->material_phase));
                MaterialColor color = lbl_8043A668;
                color.r = s;
                color.g = s;
                color.b = s;
                set_constant_material((const NJS_ARGB *)&color);
                TObjFish::set_global_param(TObjPlayer__effect_resource);
            } else {
                TObjFish::set_global_param(self->texture);
            }
            if (self->flags & 4) {
                if (self->fade.has_visible_opacity() != 0) {
                    self->fade.set_flags_and_apply_damage_color();
                    visible = 1;
                    if (((TObject *)self)->defer_render() != 0) {
                        visible = 0;
                    }
                    if (visible != 0) {
                        if (view == 1) {
                            ((TObjMotion *)self)->draw();
                        } else {
                            ((TObjEnemy *)self)->draw_motion_model();
                        }
                    }
                    self->fade.clear_flag_and_notify();
                } else {
                    drawn = 0;
                }
            } else if (view == 1) {
                ((TObjMotion *)self)->draw();
            } else {
                ((TObjEnemy *)self)->draw_motion_model();
            }
            if (self->flags & 0x400000) {
                set_constant_material((const NJS_ARGB *)lbl_804907AC);
                set_chunk_material_override_pair(0xFF00, 0);
            }
            model_render_flags = saved_model_render_flags;
            pop_matrix();
            ((TObjPlayer *)self)->render_shadow();
            restore_scene_lighting();
            TParticleCtrl::end_effect_render();
            cancel = view == 1 && (self->flags & 0x200000) && ((TObjEnemy *)self)->obj_testFlags30(0x22) == 0;
            for (i = 0; i < 4; i++) {
                if (self->children[i] != NULL) {
                    if (cancel) {
                        self->children[i]->set_cancel_flag();
                    } else {
                        self->children[i]->clear_counter();
                    }
                }
            }
            if (((TObjEnemy *)self)->obj_testFlags30(0x800) == 0 && drawn != 0 &&
                ((TObjEnemy *)self)->obj_testFlags30(0x800000) != 0) {
                Vec_800A159C offset = lbl_8043A678;
                ((TObjEnemy *)self)->render_with_position_override((u8 *)&offset, 0);
            }
        }
    }
}

// The death-fade object at +0x408 keeps its vtable pointer at +0x14.
struct VObj_14_800A1C84 {
    u8 pad[0x14];
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual s32 m4();
};

extern "C" {
void TObjPlayer__sub_800A04F0(void *);
}

void TObjPlayer__sub_800A1C84(TObjPlayer *enemy) {
    *(s32 *)((s8 *)enemy + 0x388) &= 0xFF07FFFF;
    switch (enemy->m_37c) {
    case 0:
        enemy->requested_action = 7;
        enemy->refresh_lobby_state();
        ((TObjEnemy *)enemy)->send_entity_set_flags();
        TObjPlayer__sub_800A04F0((u8 *)enemy + 0x408);
        fn_800D911C((Vec *)((u8 *)enemy + 0x2FC));
        *(s32 *)((s8 *)enemy + 0x388) |= 4;
        play_sound_effect(0x4003AD37, (u8 *)enemy + 0x38, 0, 0);
        enemy->m_37c = 1;
        break;
    case 1:
        advance_animation_playback(enemy);
        apply_actor_gravity(enemy, 0, 0.0f);
        if (((VObj_14_800A1C84 *)((u8 *)enemy + 0x408))->m4() == 1) {
            TObjPlayer::apply_effect_variant_a((s32)((u8 *)enemy + 0x38), 0);
            queue_destruction__7TObjectFv(enemy);
        }
        break;
    case -1:
        break;
    }
}

void TObjPlayer__sub_800A1D70(u8 *arg0) {
    f32 temp_f1;
    f32 temp_f31;
    switch (((TObjPlayer *)arg0)->m_37c) {
    case 0:
        ((TObjPlayer *)arg0)->actorFlags = (s32) (((TObjPlayer *)arg0)->actorFlags & 0xFFDFFFFF);
        if (*(s32 *)((s8 *)arg0 + 0x388) & 0x800000) {
            ((TObjPlayer *)arg0)->requested_action = 9;
        } else {
            ((TObjPlayer *)arg0)->requested_action = 5;
        }
        temp_f31 = vector_length(arg0 + 0x308);
        temp_f1 = TObjPlayer__sub_800A3200(2);
        if (temp_f31 > temp_f1) {
            *(f32 *)((s8 *)arg0 + 0x308) = (f32) ((*(f32 *)((s8 *)arg0 + 0x308) * temp_f1) / temp_f31);
            ((TObjPlayer *)arg0)->m_310 = (f32) ((((TObjPlayer *)arg0)->m_310 * temp_f1) / temp_f31);
        }
        if (*(s32 *)((s8 *)arg0 + 0x388) & 0x400000) {
            spawn_particle_effect((arg0 + 0x2FC), 0xD7);
        }
        *(s16 *)((s8 *)arg0 + 0x39E) = 0;
        ((TObjPlayer *)arg0)->m_37c = 1;
    case 1:
        *(f32 *)((s8 *)arg0 + 0x308) *= 0.95;
        ((TObjPlayer *)arg0)->m_310 *= 0.95;
        advance_animation_playback(arg0);
        {
        Vec_800A1D70 v = *(Vec_800A1D70 *)(arg0 + 0x2FC);
        v.x = v.x + *(f32 *)((s8 *)arg0 + 0x308);
        v.z = v.z + ((TObjPlayer *)arg0)->m_310;
        if (check_path_obstructed(arg0, &v) == 0) {
            move_with_wall_slide((arg0));
        } else {
            ((TObjPlayer *)arg0)->m_310 = (f32) 0.0f;
            *(f32 *)((s8 *)arg0 + 0x308) = (f32) 0.0f;
        }
        }
        apply_actor_gravity(arg0, 0, 0.0f);
        ((TObjPlayer *)arg0)->update_collisions();
        if ((u32) ((TObjPlayer *)arg0)->action_flags != 8U) {
            ((TObjBase *)arg0)->obj_clearFlags30(0x40300);
            *(s32 *)((s8 *)arg0 + 0x388) = (s32) ((*(s32 *)((s8 *)arg0 + 0x388)) & 0xFF7FFFFE);
            ((TObjPlayer *)arg0)->m_33e = (s16) ((TObjPlayer *)arg0)->hp;
            ((TObjPlayer *)arg0)->set_hidden_flag();
        }
        break;
    case -1:
        *(s32 *)((s8 *)arg0 + 0x388) = (s32) (*(s32 *)((s8 *)arg0 + 0x388) & 0xFFFFFFFE);
        break;
    }
    minimap_render_dot(arg0 + 0x38, -0x5DB4, 1, 0);
    submit_cursor_candidate(arg0, -1);
}

void TObjEneDarkGunner::vfunc_62() {
    s16 temp_r0;
    temp_r0 = this->mode;
    if (temp_r0 != 4) {
        if ((temp_r0 == 2) && (((TObjPlayer *)this)->is_flag_set_388_bit26() != 0) && (get_enemy_entity(*(u16 *)((s8 *)this + 0x428)) != 0U)) {
            trigger_targets_action__10TObjPlayerFv();
            return;
        }
        ((TObjEneMe1GiGue *)this)->set_state(4);
    }
}

#define self ((Obj_800A1FEC *)arg0)
#pragma push
#pragma opt_loop_invariants off
s32 TObjPlayer__sub_800A1FEC(void *arg0) {
    switch (self->state) {
    case 0:
        self->f30 |= 0x200000;
        self->f388 &= 0xFFB7FFFF;
        self->count = 0;
        self->fB8 = 3;
        play_sound_effect(0x4003B52F, &self->pos, 0, 0);
        play_sound_effect(0x4003AD29, (u8 *)arg0 + 0x38, 0, 0);
        self->state = 1;
        break;
    case 1:
        if (self->fC0 >= 5.0f) {
            self->f394 = 1.6088889f;
        }
        if (self->fB8 != 4) break;
        self->f388 |= 0x200000;
        self->timer = ((s32 (*)(s32))TObjPlayer__sub_800A3210)(0);
        self->state = 2;
        play_sound_effect(0x4003B52A, &self->pos, 0, 0);
        {
            s32 i;
            for (i = 0; i < 4; i++) {
                void *p = __nw__7TObjectFUl(0x348);
                if (p != NULL) {
                    p = TObjPlayer__sub_800A4204((u8 *)p, (u8 *)self, (s32)&self->f3B4, (s32)&self->f3C0[i], 2);
                }
                self->parts[i] = p;
            }
        }
        break;
    case 2:
        self->f394 = 1.6088889f;
        if (--self->timer > 0) break;
        self->timer = 4;
        self->f388 &= ~0x200000;
        {
            s32 i;
            for (i = 0; i < 4; i++) {
                void *q = self->parts[i];
                if (q != NULL) {
                    queue_destruction__7TObjectFv(q);
                    self->parts[i] = NULL;
                }
            }
        }
        self->state = 3;
        if (((TObjPlayer *)self)->is_flag_set_388_bit26() != 0) {
            spawn_particle_effect(&self->f3B4, 0xD8);
        } else {
            spawn_particle_effect(&self->f3B4, 0xD2);
        }
        break;
    case 3:
        self->f394 = 1.6088889f;
        if (--self->timer > 0) break;
        self->count++;
        self->timer = 15;
        self->state = 4;
        ((TObjEnemyCustom *)self)->find_target_in_range(200.0f);
        if (self->f338 == 0xFFFF) break;
        {
            u8 *p = (u8 *)new TUnk_804909C4((u8 *)self, (s32)&self->f3B4, (s32)(self->target + 0x2FC));
        }
        play_sound_effect(0x40039E2B, &self->pos, 0, 0);
        break;
    case 4:
        self->f394 = 1.6088889f;
        if (--self->timer > 0) break;
        self->state = 5;
        self->fB8 = 13;
        self->f394 = 0.0f;
        break;
    case 5:
        if (self->fB8 != 0) break;
        if (self->count < 2) {
            self->state = 1;
            self->fB8 = 3;
            break;
        }
        update_if_active__15TObjEneMe1GiGueFl(self, 1);
        break;
    case -1:
        self->f388 &= ~0x200000;
        self->f30 &= ~0x200000;
        {
            s32 i;
            for (i = 0; i < 4; i++) {
                void *q = self->parts[i];
                if (q != NULL) {
                    queue_destruction__7TObjectFv(q);
                    self->parts[i] = NULL;
                }
            }
        }
        break;
    }
    ((TObjBase *)self)->obj_clearFlags30(0x40000);
    advance_animation_playback(self);
    apply_actor_gravity(self, 0, 0.0f);
    ((TObjPlayer *)self)->update_collisions();
    minimap_render_dot(&self->pos, -23988, 1, 0);
    submit_cursor_candidate(self, -1);
}
#pragma pop
#undef self

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline f32 fmax_800A2390(f32 a, f32 b) {
    if (a > b) {
        return a;
    }
    return b;
}
s32 TObjPlayer__sub_800A2390(void *arg0_) {
    P_800A2390 *enemy = (P_800A2390 *)arg0_;
    ((TObjBase *)enemy)->obj_clearFlags30(0x40000);
    switch (enemy->state) {
    case 0:
        enemy->f388 &= ~0x00200000;
        enemy->f388 |= 0x400000;
        if (enemy->f388 & 0x10000) {
            enemy->f388 &= ~0x30000;
            enemy->f310 = 0.0f;
            enemy->f30C = 0.0f;
            enemy->f308 = 0.0f;
            enemy->state = 1;
        } else {
            enemy->f30 &= 0xFBFBFFFF;
            enemy->state = 3;
        }
        break;
    case 1:
        apply_actor_gravity(enemy, 0, 0.0f);
        enemy->f64 -= 0x1000;
        if (enemy->f64 < 0) {
            enemy->f64 = 0;
        }
        if (enemy->f30 & 0x800000) {
            enemy->f64 = 0;
            enemy->fB8 = 2;
            enemy->state = 2;
            enemy->f30 &= 0xFBFBFFFF;
            enemy->fA4->f18 &= ~4;
            enemy->fA4->f18 |= 2;
            ((TObjPlayer *)enemy)->spawn_hamon_effects(0xF, 0, 2.2f);
            ((TObjPlayer *)enemy)->spawn_hamon_effects(0xF, 3, 2.0f);
            ((TObjPlayer *)enemy)->spawn_hamon_effects(0xF, 6, 1.8f);
        }
        break;
    case 2:
        apply_actor_gravity(enemy, 0, 0.0f);
        if (enemy->fB8 == 0) {
            enemy->state = 3;
        }
        break;
    case 3:
        enemy->f64 = 0;
        enemy->fA4->f18 &= ~4;
        enemy->fA4->f18 |= 2;
        advance_animation_playback(enemy);
        if (enemy->f388 & 0x20000) {
            enemy->f388 &= ~0x20000;
            enemy->f388 |= 0x80000;
            if (enemy->f388 & 0x40000) {
                enemy->f388 &= ~0x40000;
                enemy->state = 4;
            } else {
                enemy->f398 = 0;
                enemy->state = 6;
            }
        } else {
            enemy->f388 &= ~0x80000;
        }
        break;
    case 6:
        enemy->f60 += 0x555;
        enemy->f398++;
        if (enemy->f398 >= 4) {
            enemy->state = 4;
        }
        break;
    case 4:
        enemy->f3A8 = enemy->f60;
        enemy->f3A0 = TObjPlayer__sub_800A3200(0);
        enemy->f3A4 = 0.0f;
        enemy->f3AC = 0;
        enemy->f39E = 0;
        enemy->fB8 = 1;
        enemy->state = 5;
        enemy->f64 = 0;
        enemy->fA4->f18 &= ~4;
        enemy->fA4->f18 |= 2;
    case 5:
        advance_animation_playback(enemy);
        enemy_set_heading_velocity(enemy, enemy->f3A0, enemy->f3A8);
        ((TObjPlayer *)enemy)->step_along_ground();
        enemy->f3A4 += enemy->f3A0;
        enemy->f3A0 = fmax_800A2390(-0.2f + enemy->f3A0, 0.5f);
        if (enemy->f3A4 >= TObjPlayer__sub_800A3200(1)) {
            enemy->f388 &= ~0x80000;
            enemy->state = 3;
        }
        play_persistent_sound(0x4003AD28, enemy, (u8 *)enemy + 0x38, 0, 0);
        if (enemy->f3AC > 0) {
            enemy->f3AC--;
            if (enemy->fA4->f18 & 0x300000) {
                enemy->f3A8 += 0x4000;
                enemy->f3AC = 5;
            }
        }
        if (!(actor_frame_tick & 2)) {
            ((TObjPlayer *)enemy)->spawn_hamon_effects(0xF, 0, 1.5f);
        }
        apply_actor_gravity(enemy, 0, 0.0f);
        break;
    case -1:
        break;
    }
    ((TObjPlayer *)enemy)->update_collisions();
    minimap_render_dot((u8 *)enemy + 0x38, -0x5DB4, 1, 0);
    return submit_cursor_candidate(enemy, -1);
}
#pragma pop

void TObjPlayer::set_hidden_flag() {
    if (!(this->actorFlags & 0x800)) {
        update_if_active__15TObjEneMe1GiGueFl(this, 1);
        *(s32 *)&this->unk_388 = (s32) (*(s32 *)&this->unk_388 | 0x20000);
    }
}

void TObjPlayer__sub_800A27CC(TObjPlayer *player) {
    switch (player->m_37c) {
    case 0:
        if (((TObjEneDarkGunner *)player)->m_388 & 0x10000) {
            player->actorFlags |= 0x04040000;
            player->rotation_z = 0x8000;
            player->m_37c = 1;
        } else {
            player->requested_action = 0;
            player->m_37c = 2;
        }
        ((TObjEneDarkGunner *)player)->m_388 |= 0x400000;
        advance_animation_playback(player);
        break;
    case 1:
        break;
    case -1:
        break;
    }
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline f32 fmin_800A28A4(f32 a, f32 b) {
    if (a < b) {
        return a;
    }
    return b;
}
void TObjPlayer::apply_fall_damage_flag() {
    s32 arg0 = (s32)this;
    s32 var_r4;
    if (xz_distance_squared((Vec *)(arg0 + 0x38), (Vec *)(arg0 + 0x50)) > 100.0f) {
        var_r4 = 8;
    } else {
        var_r4 = 0;
    }
    update_if_active__15TObjEneMe1GiGueFl((void *)arg0, (s32)var_r4);
}

inline f32 fmax_800A28A4(f32 a, f32 b) {
    if (a > b) {
        return a;
    }
    return b;
}
void TObjPlayer__sub_800A28A4(VObj_18_800A28A4 *self) {
    if (lbl_805D5020 != actor_frame_tick) {
        lbl_805D5020 = actor_frame_tick;
        TObjPlayer__sub_8023DEE0((s16 *)lbl_805D5024, 8, 0, 1);
        TObjPlayer__sub_8023DEE0((s16 *)lbl_805D5028, 8, 0, 0);
    }
    if (TObjPlayer::check_demo_mode() == 1) {
        ((void (*)(VObj_18_800A28A4 *))init_scale_global__10TObjPlayerFv)(self);
        TObjPlayer__sub_800A1974(self);
        return;
    }
    self->m36();
    if (self->m31() != 0) {
        self->m61();
    } else if (self->m30() != 0) {
        self->m60();
    } else if (((TObjEnemy *)self)->obj_testFlags30(0x100) != 0) {
        self->m59();
    }
    self->m39();
    self->m40();
    if ((self->flags & 0x400000) && ((TObjEnemy *)self)->obj_testFlags30(0x22) == 0) {
        s32 phase = self->material_phase;
        self->material_phase = phase + 0x800;
        self->motion->blend = ((s32 (*)(s32, s32))TObjPlayer__sub_800A3210)(2, phase);
    } else {
        self->motion->blend = 0.0f;
    }
    if ((self->flags & 0x800000) && ((TObjEnemy *)self)->obj_testFlags30(0x22) == 0) {
        if (self->glow_emitter == NULL) {
            self->glow_emitter = create_particle_emitter(&self->ground_pos, 0xDB);
        } else {
            self->glow_emitter->set_position(&self->ground_pos);
        }
    } else if (self->glow_emitter != NULL) {
        queue_destruction__7TObjectFv(self->glow_emitter);
        self->glow_emitter = NULL;
    }
    if ((self->flags & 0x200000) && ((TObjEnemy *)self)->obj_testFlags30(0x22) == 0) {
        if (self->trail_emitter == NULL) {
            if (((TObjPlayer *)self)->is_flag_set_388_bit26() != 0) {
                self->trail_emitter = create_particle_emitter(&self->shadow_pos, 0xD9);
            } else {
                self->trail_emitter = create_particle_emitter(&self->shadow_pos, 0xD4);
            }
        } else {
            self->trail_emitter->set_position(&self->shadow_pos);
        }
    } else if (self->trail_emitter != NULL) {
        queue_destruction__7TObjectFv(self->trail_emitter);
        self->trail_emitter = NULL;
    }
    if (self->m34() != 0 || self->m38() != 0 || self->m37() != 0) {
        submit_cursor_candidate(self, -1);
        minimap_render_dot(&self->pos, -0x5DB4, 1, 0);
        return;
    }
    if (self->action != self->next_action) {
        if (self->state != -1) {
            self->state = -1;
            ((TObjEneDarkGunner *)self)->sub_800A1520();
        }
        self->action = self->next_action;
        self->state = 0;
    }
    ((TObjEneDarkGunner *)self)->sub_800A1520();
    ((TObjEnemy *)self)->update_prev_position();
    self->ground_pos.y += self->render_y_offset;
    VecCopy((Vec *)&self->prev_pos, (const Vec *)&self->shadow_pos);
    if (self->flags & 0x80000) {
        self->render_y_offset = fmin_800A28A4(0.5f + self->render_y_offset, 10.0f);
    } else {
        self->render_y_offset = fmax_800A28A4(self->render_y_offset - 0.5f, 0.0f);
    }
    ((TObjEneDarkGunner *)self)->sub_800A159C();
    self->motion->speed = 4.0f + self->render_y_offset;
    if ((actor_frame_tick & 3) == 0 && (self->flags & 0x400000) && ((TObjEnemy *)self)->obj_testFlags30(0x22) == 0 &&
        self->m9(150.0f, 400.0f, 15.0f) != 0) {
        Vec_800A159C p = self->pos;
        p.y += self->render_y_offset;
        spawn_particle_effect(&p, 0xD6);
    }
}
#pragma pop

void *TObjPlayer::create_instance(void *arg0) {
    void *o = __nw__7TObjectFUl(0x42C);
    if (o != NULL) {
        o = ((void *(*)(void *, void *, void *))TObjPlayer__sub_800A2F94)(o, tl_04, arg0);
    }
    return o;
}

void TObjPlayer::cleanup_effects() {
    if ((u32) player_effect_bml_resource != 0U) {
        TLobby__sub_8001FE7C((void*)player_effect_bml_resource, 1);
        player_effect_bml_resource = 0U;
    }
    if ((u32) TObjPlayer__effect_resource != 0U) {
        free_if_valid__10TObjPlayerFl((void*)TObjPlayer__effect_resource);
        TObjPlayer__effect_resource = 0U;
    }
    TObjPlayer::reset_effect_count();
    TEneEffHamon__sub_800A380C();
}

extern "C" {
extern s32 lbl_805D5024;
extern s32 lbl_805D5028;
void *load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
void TObjPlayer__sub_800A2DCC();
}

struct Node_800A2DCC { u32 flags; s32 *model; u8 pad[0x24]; Node_800A2DCC *child; };

void TObjPlayer__sub_800A2DCC() {
    s32 i;
    void *res = (void *)::operator new(0x440);
    if (res != NULL) {
        res = load_resource_from_descriptor(res, 1, bm_ene_darkgunner_resource_descriptor, 0, 0, 0);
    }
    player_effect_bml_resource = (u32)res;
    TObjPlayer__shadow_chunk_object = ((s32 (*)(void *, s32))get_bml_model)((void *)player_effect_bml_resource, 0);
    lbl_805D5014 = ((s32 (*)(void *, s32))TObjFish__sub_8001EDB0)((void *)player_effect_bml_resource, 0);
    lbl_805D5018 = ((s32 (*)(void *, s32))TObjFish__sub_8001EDB0)((void *)player_effect_bml_resource, 2);
    lbl_805D5024 = ((Node_800A2DCC *(*)(void *, s32))get_bml_model)((void *)player_effect_bml_resource, 1)->child->model[1];
    lbl_805D5028 = ((Node_800A2DCC *(*)(void *, s32))get_bml_model)((void *)player_effect_bml_resource, 0)->model[1];
    TObjPlayer__sub_800A4294();
    init_fish_effects__12TEneEffHamonFv();
    TObjPlayer__effect_resource = (u32)load_gvm_texture_file((s32)"re5_b_gunner_body_pika.gvm");
    for (i = 0; i < 1; i++) {
        lbl_805D4FF8[i] = (s32)TLobby::register_boss(30 + i);
        lbl_805D4FFC[i] = (s32)TLobby::dispatch_shared_handler_b(30 + i);
        lbl_805D5000[i] = (s32)TLobby::register_object(30 + i);
    }
    lbl_805D5004 = (s32)TLobby::dispatch_shared_handler_a(30);
}

Obj_800A2EDC *TObjPlayer__sub_800A2EDC(Obj_800A2EDC *arg0, s16 arg1) {
    s32 i;
    if (arg0 != NULL) {
        arg0->vt = __vt__17TObjEneDarkGunner;
        free_collision_body_parts(arg0);
        for (i = 0; i < 4; i++) {
            if (arg0->items[i] != NULL) {
                queue_destruction__7TObjectFv(arg0->items[i]);
            }
        }
        if (arg0->p400 != NULL) {
            queue_destruction__7TObjectFv(arg0->p400);
        }
        if (arg0->p404 != NULL) {
            queue_destruction__7TObjectFv(arg0->p404);
        }
        __dt__13TUnk_80490470Fv((u8 *)arg0 + 0x408, -1);
        __dt__15TObjEnemyCustomFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

#define F(T, o) (*(T *)((u8 *)self + (o)))
#define G500C ((u8 *)player_effect_bml_resource)
u8 *TObjPlayer__sub_800A2F94(u8 *self, s32 arg1, u8 *arg2) {
    s32 i;

    __ct__15TObjEnemyCustomFP7TObject(self, arg1, arg2);
    F(void *, 0x18) = __vt__17TObjEneDarkGunner;
    __ct__13TUnk_80490470Fv((self + 0x408));
    F(s32, 0) = dark_gunner_class_name_ptr;
    ((VObj_18_800A2F94 *)self)->m79(arg2);
    initialize_enemy_photon_effect(self);
    F(s32, 0x368) = 0;
    ((TObjEnemy *)self)->set_param(0x22);
    ((TObjChara *)self)->add_flags_2e4(8);
    F(s32, 0x36C) = *(s16 *)(arg2 + 0x3E);
    F(s16, 0x33A) = 0xF;
    F(s16, 0x33C) = F(s16, 0x33A);
    VecCopy((Vec *)(self + 0x44), (const Vec *)(self + 0x38));
    VecCopy((Vec *)(self + 0x50), (const Vec *)(self + 0x38));
    VecCopy((Vec *)(self + 0x290), (const Vec *)(self + 0x38));
    VecCopy((Vec *)(self + 0x29C), (const Vec *)(self + 0x38));
    ((TObjEneDarkGunner *)self)->set_fields_24_34_from_global((void *)1);
    F(s32, 0xDC) = *(s32 *)(G500C + 0x430);
    F(void *, 0xD8) = lbl_80490668;
    ((TObjMotion *)self)->set_field_d8(F(s32, 0xD8));
    F(s16, 0xB8) = 0;
    ((TObjMotion *)self)->set_animation(F(s16, 0xB8));
    ((TObjMotion *)self)->set_field_b8(F(s16, 0xB8));
    init_collision_body_parts(self, lbl_80490780, 1);
    F(void *, 0x350) = lbl_80490748;
    ((TObjEnemy *)self)->bind_enemy_combat_stats((u8 *)lbl_805D4FF8[F(s32, 0x368)], (u8 *)lbl_805D4FFC[F(s32, 0x368)], (u8 *)lbl_805D5000[F(s32, 0x368)]);
    ((void (*)(void *))init_scale_global__10TObjPlayerFv)(self);
    F(s16, 0x32C) = F(s16, 0x2B8);
    F(s16, 0x32E) = F(s16, 0x2BA);
    F(s16, 0x33E) = F(s16, 0x32C);
    ((TObjEnemy *)self)->update_prev_position();
    F(s32, 0x388) = 0x550000;
    obj_setFlags30(self, 0x04040000);
    F(s32, 0x64) = 0x8000;
    F(f32, 0x38C) = 0.0f;
    F(f32, 0x394) = 0.0f;
    F(f32, 0x390) = 0.0f;
    F(s32, 0x400) = 0;
    F(s32, 0x404) = 0;
    *(u32 *)(F(u8 *, 0xA4) + 0x18) |= 4;
    *(u32 *)(F(u8 *, 0xA4) + 0x18) &= ~2;
    F(s16, 0x39E) = 0;
    for (i = 0; i < 4; i++) {
        ((Obj_800A2F94 *)self)->f3F0[i] = 0;
    }
    {
        Atk_800A2F94 atk = dark_gunner_attack_binding_desc;
        atk.w[0] = *(s32 *)(G500C + 0x430);
        TLobby::spawn_npc_enemy(0x19, *(s32 *)(*(u8 **)(G500C + 0x42C) + 0x18), *(s32 *)(*(u8 **)(G500C + 0x42C) + 0x1C), (s32)&atk, 10.0f, 0.0f);
    }
    return self;
}

#undef F
#undef G500C

void TObjEneDarkGunner::vfunc_28() {  }

void TObjEneDarkGunner::vfunc_58() {  }

void TObjEneDarkGunner::vfunc_59() {  }

f32 TObjPlayer__sub_800A3200(s32 arg0) {
    return *(f32 *)((s8 *)(lbl_805D5004 + (arg0 * 4)) + 0);
}

s32 TObjPlayer__sub_800A3210(s32 i, s32 _w1, s32 _w2) {
    return (*(G_800A3210 * *)&lbl_805D5004)->arr[i];
}

int TObjPlayer::is_flag_set_388_bit26() { return (*(u32 *)&this->unk_388 >> 26) & 0x1; }

void TObjEneDarkGunner::set_fields_24_34_from_global(void*a1) { *(int *)&this->model = get_bml_model((void*)((*(int *)&player_effect_bml_resource))); *(int *)&this->texlist = TObjFish__sub_8001EDB0((void*)((*(int *)&player_effect_bml_resource)), a1); }

void TObjPlayer::clear_counter() { this->m_340 = 0; }

void TObjPlayer::set_cancel_flag() { *(s32 *)&this->m_340 = 1; }
}
