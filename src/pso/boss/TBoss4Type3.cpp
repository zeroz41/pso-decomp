#include "types.h"
#include "pso/system/PadRumble.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TUnk_804806E8.h"
#include "pso/boss/TBoss4DarkFalz.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/boss/TBoss4Type3.h"
#include "pso/misc/TNowLoading.h"
#include "pso/player/TObjPlayer.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/boss/TUnk_80486924.h"
#include "pso/misc/TLobby.h"
extern "C" void has_flag_0x800__13TUnk_804806E8Fv();
extern "C" void test_flag30_512__13TUnk_804806E8Fv();
extern "C" void test_flag_1000__13TUnk_804806E8Fv();
extern "C" void test_flag_256__13TUnk_804806E8Fv();

extern const char TObjBs4CutAtk_type_name[] = "TObjBs4CutAtk";
extern const char TBoss4Type3_type_name[] = "TBoss4Type3";
extern const char boss4_type3_state_name_appear[] = "APPEAR";
extern const char boss4_type3_state_name_wait_next[] = "WAITNEXT";
extern const char boss4_type3_state_name_wait_kill[] = "WAITKILL";
extern const char boss4_type3_state_name_dead[] = "DEAD";
extern const char boss4_type3_state_name_cut2[] = "CUT2";
extern const char boss4_type3_state_name_cut3[] = "CUT3";
extern const char boss4_type3_state_name_cut4[] = "CUT4";
extern const char boss4_type3_state_name_cut5[] = "CUT5";
extern const char boss4_type3_state_name_go_up[] = "GOUP";
extern const char boss4_type3_state_name_go_down[] = "GODOWN";
extern const char boss4_type3_state_name_homing[] = "HORMING";
extern const char boss4_type3_state_name_light_magic[] = "LMAGIC";
extern const char boss4_type3_state_name_dark_magic[] = "DMAGIC";
extern const char boss4_type3_state_name_capture[] = "CAPTURE";
extern const char boss4_type3_state_name_bura[] = "BURA";
extern const char boss4_type3_state_name_libera[] = "LIBERA";
extern const char boss4_type3_state_name_cut[] = "CUT";
extern const s32 boss4_type3_model_node_specs[2][3] = {{12,74,1},{14,74,1}};
extern const s32 boss4_type3_effect_ids[8] = {326,326,326,326,328,327,327,323};
const char *TObjBs4CutAtk_name = TObjBs4CutAtk_type_name;
const char *TBoss4Type3_name = TBoss4Type3_type_name;
typedef TBoss4Type3Handler Type3Handler;
struct Type3MotionView { s32 kind, flags, motions[3]; };
#include "pso/TBoss4Zanzo.h"
#include <stddef.h>
#include "pso/TObjBs4CutAtk.h"
#include "pso/TParticleCtrl.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/boss/TBoss4Uro.h"
#include "pso/boss/TBoss6PlotFalz.h"
#include "pso/boss/TObjDFRecover.h"
#include "pso/enemy/TObjEneLappy.h"
#include "pso/enemy/TObjEneMe3ShinowaReal.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TTecGrants.h"
#include "pso/misc/TTecRaBarta.h"
#include "pso/misc/TTecRaFoie.h"
#include "pso/misc/TTecResta.h"
#include "pso/object/TObjFish.h"
extern "C" TObjEnemy *__ct__9TObjEnemyFP7TObject(void *, void *);
#pragma defer_codegen on

struct Vec_8005A1AC { f32 x, y, z; };

struct Obj_8005A1AC {
    u8 pad0[0x3ba];
    u16 f3ba;
    u8 pad3bc[0x404 - 0x3bc];
    void *f404[13];
    u8 pad438[0x444 - 0x438];
    Vec_8005A1AC f444;
    Vec_8005A1AC f450;
    Vec_8005A1AC f45c;
    u8 pad468[0x480 - 0x468];
    Vec_8005A1AC f480;
    Vec_8005A1AC f48c;
    Vec_8005A1AC f498;
    u8 pad4a4[0x4d4 - 0x4a4];
    Vec_8005A1AC f4d4;
    Vec_8005A1AC f4e0;
};

struct Ply_80059ABC;
struct Vec_800597A8 { f32 x, y, z; };

struct Vec_800584E4 { f32 x, y, z; };

struct Obj_8005683C;

struct Seg_8005AE60 { u8 b[0x48]; };
struct Self_8005AE60 {
    s32 f0;
    u8 pad4[0x18 - 0x4];
    void *vt;
    u8 pad1c[0x24 - 0x1c];
    s32 f24;
    u8 pad28[0x34 - 0x28];
    s32 f34;
    u8 v38[0xC];
    u8 v44[0xC];
    u8 v50[0xC];
    s32 f5C;
    s32 f60;
    u8 pad64[0x74 - 0x64];
    u8 v74[0xC];
    u8 pad80[0x2A8 - 0x80];
    s32 f2A8;
    u8 pad2ac[0x2FC - 0x2AC];
    u8 v2FC[0xC];
    f32 f308;
    f32 f30C;
    f32 f310;
    u8 pad314[0x32C - 0x314];
    s16 f32C;
    u8 pad32e[0x33E - 0x32E];
    s16 f33E;
    u8 pad340[0x378 - 0x340];
    u8 f378[0x38C - 0x378];
    s32 f38C;
    s32 f390;
    s32 f394;
    u8 pad398[0x3A0 - 0x398];
    s32 f3A0;
    s32 f3A4;
    s32 f3A8;
    s32 f3AC;
    f32 f3B0;
    s32 f3B4;
    u16 f3B8;
    u16 f3BA;
    s32 f3BC;
    u8 pad3c0[4];
    s32 f3C4;
    f32 f3C8;
    s32 f3CC;
    s32 f3D0;
    s32 f3D4;
    s32 f3D8;
    f32 f3DC;
    s32 f3E0;
    s32 f3E4;
    f32 f3E8;
    f32 f3EC;
    s32 f3F0;
    f32 f3F4;
    f32 f3F8;
    s32 f3FC;
    u8 pad400[0x438 - 0x400];
    s32 a438[3];
    Seg_8005AE60 a444[3];
    u8 pad57c[0x51C - 0x51C];
};

union TypedVector_80059B78 {
    struct { f32 x, y, z; } f;
    struct { s32 x, y, z; } bits;
};

extern "C" {
s32 VecCopy__FP3VecPC3Vec(void *, void *);
s32 add_radar_scaled_marker(void *, u32, int, int, f32);
s32 vec3_add_to(void *, void *);
f32 vector_length(void *);
s32 subtract_vector(void *, void *);
s32 normalize_vector(void *);
void *spawn_particle_effect(void *pos, s32 id);
void *create_particle_emitter(void *pos, s32 id);
s32 play_sound_effect(int, void *, int, int);
f64 atan2_float(f32, f32);
u8 * dispatch_shared_handler_a__6TLobbyFl(s32);
s32 angle_diff_s16(int, int);
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
s32 pick_random_target_player__11TBoss4Type3Fv(void);
s32 TBoss4Type3__sub_8005254C(u16);
struct Stack_80055918
{
  s32 sp8;
  f32 spC;
};

typedef struct Stack_80055918 Stack_80055918;

struct RecoveredGlobal_80054530_lbl_80485EC8 {
    s32 value;
    u8 remaining[0x1DC];
};

struct RecoveredGlobal_8005455C_lbl_80485EC8 {
    s32 value;
    u8 remaining[0x1DC];
};

struct S_80058224 {
    u8 pad0[0x398];
    s32 f398;
    u8 pad39c[0x3b8 - 0x39c];
    u16 f3b8;
    u16 f3ba;
};

struct S_800582B4 {
    u8 pad0[0x398];
    s32 f398;
    u8 pad39c[0x3b8 - 0x39c];
    u16 f3b8;
    u16 f3ba;
};

struct Obj_8005683C {
    u8 pad0[0x38c];
    s32 f38c;
};

struct Vec_80056C30 { f32 x, y, z; };

typedef char RecoveredGlobal_80054530_lbl_80485EC8_size[sizeof(RecoveredGlobal_80054530_lbl_80485EC8) == 0x1E0 ? 1 : -1];

typedef char RecoveredGlobal_8005455C_lbl_80485EC8_size[sizeof(RecoveredGlobal_8005455C_lbl_80485EC8) == 0x1E0 ? 1 : -1];

struct O_80058D70 { u8 pad[0x398]; s32 f398; u8 pad2[0x1c]; u16 f3b8; };

struct Obj_80059010 { u8 pad[0x398]; s32 f398; u8 pad39c[0x1C]; u16 f3b8; u16 f3ba; };

struct Obj_80059390 { u8 pad[0x30]; u32 flags; u8 pad34[0x384]; u16 f3b8; u16 f3ba; };

struct Obj_80058E64 { u8 pad[0x32C]; s16 f32c; u8 pad2[0x6A]; s32 f398; u8 pad3[0x1C]; u16 f3b8; u16 f3ba; u8 pad4[0x24]; s32 f3e0; };

struct Vec_80058848 { f32 x, y, z; };

struct O_80058848 {
    u8 pad0[0x38];
    Vec_80058848 pos;
    u8 pad44[0x398 - 0x44];
    s32 f398;
};

struct Grant_80058A48 { s32 f0; u16 f4; s16 f6; u8 pad[0x58]; };

struct O_80058BA0 {
    u8 pad0[0x38];
    u8 f38[0x398 - 0x38];
    s32 f398;
    u8 pad39c[0x3B8 - 0x39C];
    u16 f3b8;
    u8 pad3ba[0x424 - 0x3BA];
    void *f424;
    void *f428;
    u8 pad42c[0x450 - 0x42C];
    u8 f450[0xC];
    u8 f45c[0x52C - 0x45C];
    s32 f52c;
};

struct Vec_800590F4
{
  f32 x;
  f32 y;
  f32 z;
};

struct VBase_800590F4
{
  char pad[0x18];
};

struct VObj_800590F4 : VBase_800590F4 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4(Vec_800590F4 *, Vec_800590F4 *);
};

struct O_800590F4
{
  u8 pad0[0x38];
  u8 f38[0x28];
  s32 f60;
  u8 pad64[0x374 - 0x64];
  s32 f374;
  u8 pad378[0x398 - 0x378];
  s32 f398;
  f32 f39c;
  u8 pad3a0[0x3A8 - 0x3A0];
  s32 f3a8;
  u8 pad3ac[0x3F4 - 0x3AC];
  f32 f3f4;
  u8 pad3f8[0x51C - 0x3F8];
  s32 f51c[2];
  VObj_800590F4 *f524[2];
};

typedef struct O_800590F4 O_800590F4;

typedef struct VBase_800590F4 VBase_800590F4;

typedef struct VObj_800590F4 VObj_800590F4;

typedef struct Vec_800590F4 Vec_800590F4;

struct Obj_80059EA8 { u8 pad[0x38C]; void *target; u8 pad390[0x10]; s32 f3a0; u8 pad3a4[4]; s32 f3a8; u8 pad3ac[0xC]; u16 f3b8; u16 f3ba; };

struct Obj_80059F04 { u8 pad[0x38C]; void *target; u8 pad390[0x10]; s32 f3a0; u8 pad3a4[4]; s32 f3a8; u8 pad3ac[0xC]; u16 f3b8; u16 f3ba; };

struct Obj_80059F64 { u8 pad[0x38C]; void *target; u8 pad390[0x10]; s32 f3a0; u8 pad3a4[4]; s32 f3a8; u8 pad3ac[0xC]; u16 f3b8; u16 f3ba; };

struct Obj_8005A2A4 { u8 pad[0x404]; void *parts[13]; };

struct Obj_80059ABC { u8 pad[0x60]; s32 f60; };

struct Ply_80059ABC { u8 pad[0x38]; f32 f38; u8 pad3c[4]; f32 f40; };

struct Obj_8005A300 { u8 pad[0x38]; u8 f38[0x3CC]; u32 f404[13]; };

struct Obj_8005A438 { u8 pad[0x3B0]; f32 f3b0; };

struct Pair_8005A438 { void *p; f32 f; };

struct Words_8005A438 { void *p; u32 w; };

struct Vec_80059618 { f32 x, y, z; };

struct O_80059618 {
    u8 pad0[0x32C];
    s16 f32c;
    u8 pad32e[0x374 - 0x32E];
    s32 f374;
    u8 pad378[0x3BA - 0x378];
    u16 f3ba;
    u8 pad3bc[0x3E4 - 0x3BC];
    s32 f3e4;
    u8 pad3e8[0x480 - 0x3E8];
    Vec_80059618 f480;
};

struct Obj_8005ACBC { u8 pad[0x374]; s32 f374; u8 pad378[0x40]; u16 f3b8; u16 f3ba; };

struct S_8005AD50 {
    u8 pad0[0x18];
    void *vt;
    u8 pad1c[0x378 - 0x1c];
    u8 f378[0x1c];
    s32 f394;
    u8 pad398[0x438 - 0x398];
    void *fx[3];
    u8 pad444[0x51c - 0x444];
    void *f51c;
    void *f520;
    void *f524;
    void *f528;
};

struct S_80058380 {
    u8 pad0[0x398];
    s32 f398;
    f32 f39c;
};

struct Vec_80059C20 { f32 x, y, z; };

struct Dmg_8005B218 { s32 type; f32 val; };

struct VBase_8005B218 { char pad[0x18]; };

struct VObj_8005B218 : VBase_8005B218 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20();
    virtual void m21(s32, Dmg_8005B218 *, s32, s32, s32);
};

f32 calc_boss4_scale__10TObjPlayerFi(void *);
int get_player_data__10TObjPlayerFi(int a0);
u16 get_entity_id(void *);
s32 is_split_screen();
void queue_destruction__7TObjectFv(void *);
s16 * register_boss__6TLobbyFl(s32);
s32 get_bml_motion(s32, s32);
s32 TObjFish__sub_8001EDB0(s32, s32);
s32 get_bml_model(s32, s32);
void fn_80044330(void *p);
void fn_8004AA04(void *);
void TObjPlayer__sub_80052390(f32 x);
f32 TBoss4Type3__sub_800524E8(f32);
void TBoss4Type3__sub_800599F4(void*, int, int);
void TBoss4Type3__sub_80059EA8(Obj_80059EA8 *self, s32 arg1, s32 arg2);
void TBoss4Type3__sub_80059F64(Obj_80059F64 *self, s32 arg1);

void TBoss4Type3__sub_8005A150(TBoss4Type3 *self);
void TBoss4Type3__sub_80059DCC(TBoss4Type3 *self, u32 packed);
void TBoss4Type3__sub_8005A86C(void* p);
void reset_action_to_3__11TBoss4Type3FPv(Obj_8005ACBC *self);
void init_effect__11TBoss4Type3FPv(u8 *arg0);
S_8005AD50 * __dt__11TBoss4Type3Fv(S_8005AD50 *o, s16 flag);
void * __ct__13TObjBs4CutAtkFv(void *arg0, s32 arg1, s32 arg2, s32 arg3);
void * create__13TObjBs4CutAtkFPvPvPv(void *arg0, void *arg1, void *arg2);
void request_follow_camera_offsets(void *arg0, void *arg1, u16 arg2);
s32 query_teammate_state__9TObjEneDDFv(void *);
int toggle_particle_effect__10TObjPlayerFv(void*);
u8 * lookup_entry_by_value__10TObjPlayerFPvf(s32);
s32 *__dt__11TBoss4Type3FPvs(s32 *arg0, s16 arg1);
s32 clear_render_callback__8TObjFishFv(s32);
s32 TObjControl__ct(s32, s32);
void *__dt__9TObjEnemyFv(TObjEnemy *arg0, s16 arg1);
s32 approach_angle_limited(s32, s32, s32);
void free_collision_body_parts(void *);
s32 TObjEneRe4Sorcerer__sub_801E3F1C(f32, f32);
void __dl__7TObjectFPv(void *);
void * __nw__7TObjectFUl(int);
void __ct__7TObjectFP7TObject(void *);
s32 create__9TTecMegidFllll(void *, Vec_80058848 *, u8 *, s32);
void TBoss6PlotFalz__sub_802AC008(f32 farg0, f32 farg1);
s32 rand();
s32 matrix_mult_vec(int, void *, void *);
void set_matrix_identity(u8 *arg0);
s32 rotate_matrix_y(int, int);
s32 push_matrix();
s32 pop_matrix();
f32 post_translate_matrix(void *);
f32 xyz_distance(Vec_80056C30 *, Vec_80056C30 *);
void draw_model_motion(void *arg0, void *arg1, f32 farg0);

extern void* __vt__13TObjBs4CutAtk[];

extern s32 local_client_id;

void init_model_node_tables(void *, void *, int);
s32 TObjFish__sub_800E3124(u8 *list, s32 vecs);
s32 init_collision_body_parts(void *, void *, int);
extern s32 model_render_flags;
extern s32 tl_04;

extern "C" {
void apply_poison_status__11TBoss4Type3Fv();
}
extern "C" {
void apply_paralysis__11TBoss4Type3Fv();
}
extern "C" {
void apply_slow_status__11TBoss4Type3Fv();
}
extern "C" {
void apply_confusion_status__11TBoss4Type3Fv();
}
extern "C" {
void apply_movement_ailment__11TBoss4Type3Fl();
}
extern "C" {
void apply_shock_status__11TBoss4Type3Fv();
}
extern "C" {
void clear_harmful_statuses__11TBoss4Type3Fv();
}
extern "C" {
void run_task__11TBoss4Type3Fv();
}
extern "C" {
void vfunc_6__13TUnk_804B9870FPsl();
}
extern "C" {
void vfunc_29__13TUnk_804806E8Fv();
}
extern "C" {
extern u8 apply_anti_technique__13TUnk_804806E8Fl[];
}
extern "C" {
void recalc_stats__13TUnk_804806E8Fv();
}
extern "C" {
extern u8 enemy_spawn_zalure_effect__13TUnk_804806E8Fv[];
}
extern "C" {
extern u8 enemy_spawn_jellen_effect__13TUnk_804806E8Fv[];
}
extern "C" {
void vfunc_28__13TUnk_804806E8Fv();
}
extern "C" {
extern u8 get_actor_level_index__13TUnk_804806E8Fv[];
}
extern "C" {
void consume_timer_field__13TUnk_804806E8Fl();
}
extern "C" {
extern u8 add_actor_exp__13TUnk_804806E8Fl[];
}
extern "C" {
extern u8 is_actor_cadence_frame__13TUnk_804806E8Fl[];
}
extern "C" {
extern u8 receive_weapon_special_attack__13TUnk_804806E8FPvPv[];
}
extern "C" {
extern u8 receive_direct_attack__13TUnk_804806E8FPv19DirectAttackPayloadPvll[];
}
extern "C" {
extern u8 apply_knockback_from_attacker__13TUnk_804806E8FPUc[];
}
extern "C" {
extern u8 receive_physical_attack__13TUnk_804806E8FPvf[];
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
extern u8 apply_action_hold_status__13TUnk_804806E8Ff[];
}
extern "C" {
extern u8 clear_all_status_effects__13TUnk_804806E8Fv[];
}
extern "C" {
extern u8 cure_paralysis__13TUnk_804806E8Fv[];
}
extern "C" {
extern u8 cure_poison_ailment__13TUnk_804806E8Fv[];
}
extern "C" {
extern u8 apply_defense_stat_status__13TUnk_804806E8FPv[];
}
extern "C" {
extern u8 apply_attack_stat_status__13TUnk_804806E8FPv[];
}
extern "C" {
extern u8 calc_distance_accuracy_penalty__13TUnk_804806E8FPvPvPvf[];
}
extern "C" {
extern u8 roll_physical_accuracy__13TUnk_804806E8FPvlf[];
}
extern "C" {
extern u8 select_melee_contact_body__13TUnk_804806E8FPvf[];
}
extern "C" {
extern u8 update_defense_stat_status__13TUnk_804806E8Fv[];
}
extern "C" {
extern u8 update_attack_stat_status__13TUnk_804806E8Fv[];
}
extern "C" {
void update_shock_clock__13TUnk_804806E8Fv();
}
extern "C" {
extern u8 update_movement_status__13TUnk_804806E8Fv[];
}
extern "C" {
extern u8 update_action_hold_status__13TUnk_804806E8Fv[];
}
extern "C" {
extern u8 update_poison_status__13TUnk_804806E8Fv[];
}
extern "C" {
void vfunc_43__13TUnk_804806E8Fv();
}
extern "C" {
extern u8 is_target_in_attack_range__13TUnk_804806E8Fv[];
}
extern "C" {
void vfunc_18__13TUnk_804806E8FPUc();
}
extern "C" {
extern u8 update_actor_ground_y__13TUnk_804806E8Fv[];
}
extern "C" {
extern u8 vfunc_9__13TUnk_804806E8Fv[];
}
extern "C" {
extern u8 reset_motion_fields__13TUnk_804806E8Fv[];
}
extern "C" {
void interact__13TUnk_804AF8A0Fl();
}
extern "C" {
extern u8 render_shadows__9TObjEnemyFv[];
}
extern "C" {
void vfunc_74__9TObjEnemyFl();
}
extern "C" {
void apply_hit_message_flags__9TObjEnemyFPv();
}
extern "C" {
extern u8 apply_set_data__9TObjEnemyFPv[];
}
extern "C" {
void apply_switch_attack__13TUnk_804806E8Fv();
}
extern "C" {
void vfunc_79__9TObjEnemyFv();
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
extern u8 apply_object_set_data__13TUnk_804B9870FPv[];
}
extern "C" {
extern u8 classify_actor_view_detail__13TUnk_804B9870Ffff[];
}
extern "C" {
extern u8 update_object_view_visibility__13TUnk_804B9870Fff[];
}
extern "C" {
void get_name__9TObjEnemyFv();
}
extern "C" {
void get_pos__13TUnk_804806E8Fl();
}
extern "C" {
void reset_pose__13TUnk_804806E8Fv();
}
extern "C" {
void trigger_switch_attack__13TUnk_804806E8Fv(s32 arg0);
}
extern "C" {
void try_start_action__13TUnk_804806E8Fll();
}
extern "C" {
s32 vfunc_37__13TUnk_804806E8Fv(u8 *arg0);
}
extern "C" {
void update_flag30_timer__13TUnk_804806E8Fv();
}
extern void *lbl_80487090[28];
extern void *lbl_80487100[12];

TBoss4Type3State boss4_type3_states[17] = {
    { boss4_type3_state_name_appear, 0x0, &TBoss4Type3::enter_appear, &TBoss4Type3::advance_appear, &TBoss4Type3::update_appear },
    { boss4_type3_state_name_wait_next, 0x0, 0, &TBoss4Type3::advance_wait_next, 0 },
    { boss4_type3_state_name_wait_kill, -1, 0, 0, 0 },
    { boss4_type3_state_name_dead, 0x9, &TBoss4Type3::enter_dead, &TBoss4Type3::advance_dead, &TBoss4Type3::update_dead },
    { boss4_type3_state_name_cut, 0x3, &TBoss4Type3::enter_cut, &TBoss4Type3::advance_cut, &TBoss4Type3::update_cut },
    { boss4_type3_state_name_cut2, 0x4, &TBoss4Type3::enter_cut, &TBoss4Type3::advance_cut, &TBoss4Type3::update_cut },
    { boss4_type3_state_name_cut3, 0x3, &TBoss4Type3::enter_cut, &TBoss4Type3::advance_cut, &TBoss4Type3::update_cut },
    { boss4_type3_state_name_cut4, 0x4, &TBoss4Type3::enter_cut, &TBoss4Type3::advance_cut, &TBoss4Type3::update_cut },
    { boss4_type3_state_name_cut5, 0x3, &TBoss4Type3::enter_cut, &TBoss4Type3::advance_cut, &TBoss4Type3::update_cut },
    { boss4_type3_state_name_go_up, 0x1, &TBoss4Type3::enter_go_up, &TBoss4Type3::advance_go_up, &TBoss4Type3::update_go_up },
    { boss4_type3_state_name_go_down, 0x2, &TBoss4Type3::enter_go_down, &TBoss4Type3::advance_go_down, &TBoss4Type3::update_go_down },
    { boss4_type3_state_name_homing, 0x0, &TBoss4Type3::enter_homing, &TBoss4Type3::advance_homing, &TBoss4Type3::update_homing },
    { boss4_type3_state_name_light_magic, 0x0, &TBoss4Type3::enter_light_magic, &TBoss4Type3::advance_light_magic, &TBoss4Type3::update_light_magic },
    { boss4_type3_state_name_dark_magic, 0x7, &TBoss4Type3::enter_dark_magic, &TBoss4Type3::advance_dark_magic, &TBoss4Type3::update_dark_magic },
    { boss4_type3_state_name_capture, 0x0, &TBoss4Type3::enter_capture, &TBoss4Type3::advance_capture, &TBoss4Type3::update_capture },
    { boss4_type3_state_name_bura, 0x0, &TBoss4Type3::enter_bura, &TBoss4Type3::advance_bura, &TBoss4Type3::update_bura },
    { boss4_type3_state_name_libera, 0x0, &TBoss4Type3::enter_libera, &TBoss4Type3::advance_libera, &TBoss4Type3::update_libera },
};
void *boss4_type3_collision_body_desc[11] = {
    (void *)0x0, (void *)0x41a00000, (void *)0x0, (void *)0x42340000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_80486FB0[3] = {
    (void *)0xc, (void *)0xd, (void *)0xd,
};
void *boss4_type3_index_table[3] = {
    (void *)0xe, (void *)0xf, (void *)0xf,
};
Type3MotionView TBoss4Type3__anim_state_table[10] = {
    { 0, 0, 83, 84, 85 },
    { 0, 0, 52, 53, 54 },
    { 0, 0, 55, 56, 57 },
    { 2, 0, 64, 65, 66 },
    { 2, 0, 72, 73, 74 },
    { 2, 0, 89, 84, 85 },
    { 2, 0, 58, 59, 60 },
    { 2, 0, 37, 84, 85 },
    { 2, 0, 14, 15, 16 },
    { 1, 0, 19, 84, 85 },
};
void *lbl_80487090[28] = {
    (void *)0x38, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x34, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x35, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x9, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0xa, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x39, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_80487100[12] = {
    (void *)0xb, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0xc, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *boss4_type3_start_position[3] = {
    (void *)0x461c4000, (void *)0xc1200000, (void *)0x0,
};
void *boss4_type3_effect_desc_ptr_table[3] = {
    (void *)&lbl_80487090, (void *)&lbl_80487100, (void *)&lbl_80487100,
};
__declspec(section ".data") void *boss4_type3_run_task_params[2] = {
    (void *)0x34, (void *)0x35,
};
void *lbl_80487150[3] = {
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *boss4_type3_default_position[3] = {
    (void *)0x461c4000, (void *)0xc1200000, (void *)0x0,
};
void *boss4_type3_interp_origin_vec[3] = {
    (void *)0x461c4000, (void *)0x43960000, (void *)0x0,
};
void *boss4_type3_radar_marker_colors[4] = {
    (void *)0xffff0000, (void *)0xff00ff00, (void *)0xffffff00, (void *)0xff0000ff,
};
void *__vt__11TBoss4Type3[83] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__11TBoss4Type3Fv, (void *)&run_task__11TBoss4Type3Fv,
    (void *)&TBoss4Type3__sub_8005A86C, (void *)&render_shadows__9TObjEnemyFv, (void *)&vfunc_6__13TUnk_804B9870FPsl, (void *)&apply_object_set_data__13TUnk_804B9870FPv,
    (void *)&reset_motion_fields__13TUnk_804806E8Fv, (void *)&vfunc_9__13TUnk_804806E8Fv, (void *)&update_object_view_visibility__13TUnk_804B9870Fff, (void *)&classify_actor_view_detail__13TUnk_804B9870Ffff,
    (void *)&get_name__9TObjEnemyFv, (void *)&interact__13TUnk_804AF8A0Fl, (void *)&add_actor_exp__13TUnk_804806E8Fl, (void *)&consume_timer_field__13TUnk_804806E8Fl,
    (void *)&get_actor_level_index__13TUnk_804806E8Fv, (void *)&update_actor_ground_y__13TUnk_804806E8Fv, (void *)&vfunc_18__13TUnk_804806E8FPUc, (void *)&is_actor_cadence_frame__13TUnk_804806E8Fl,
    (void *)&select_melee_contact_body__13TUnk_804806E8FPvf, (void *)&calc_distance_accuracy_penalty__13TUnk_804806E8FPvPvPvf, (void *)&receive_physical_attack__13TUnk_804806E8FPvf, (void *)&receive_direct_attack__13TUnk_804806E8FPv19DirectAttackPayloadPvll,
    (void *)&receive_weapon_special_attack__13TUnk_804806E8FPvPv, (void *)&apply_knockback_from_attacker__13TUnk_804806E8FPUc, (void *)&try_start_action__13TUnk_804806E8Fll, (void *)&roll_physical_accuracy__13TUnk_804806E8FPvlf,
    (void *)&vfunc_28__13TUnk_804806E8Fv, (void *)&vfunc_29__13TUnk_804806E8Fv, (void *)&is_target_in_attack_range__13TUnk_804806E8Fv, (void *)&test_flag_256__13TUnk_804806E8Fv,
    (void *)&test_flag30_512__13TUnk_804806E8Fv, (void *)&has_flag_0x800__13TUnk_804806E8Fv, (void *)&test_flag_1000__13TUnk_804806E8Fv, (void *)&update_poison_status__13TUnk_804806E8Fv,
    (void *)&update_action_hold_status__13TUnk_804806E8Fv, (void *)&vfunc_37__13TUnk_804806E8Fv, (void *)&update_flag30_timer__13TUnk_804806E8Fv, (void *)&update_movement_status__13TUnk_804806E8Fv,
    (void *)&update_shock_clock__13TUnk_804806E8Fv, (void *)&update_attack_stat_status__13TUnk_804806E8Fv, (void *)&update_defense_stat_status__13TUnk_804806E8Fv, (void *)&vfunc_43__13TUnk_804806E8Fv,
    (void *)&apply_poison_status__11TBoss4Type3Fv, (void *)&apply_paralysis__11TBoss4Type3Fv, (void *)&apply_slow_status__11TBoss4Type3Fv, (void *)&apply_confusion_status__11TBoss4Type3Fv,
    (void *)&apply_movement_ailment__11TBoss4Type3Fl, (void *)&apply_shock_status__11TBoss4Type3Fv, (void *)&clear_harmful_statuses__11TBoss4Type3Fv, (void *)&apply_attack_stat_status__13TUnk_804806E8FPv,
    (void *)&apply_defense_stat_status__13TUnk_804806E8FPv, (void *)&cure_poison_ailment__13TUnk_804806E8Fv, (void *)&cure_paralysis__13TUnk_804806E8Fv, (void *)&clear_all_status_effects__13TUnk_804806E8Fv,
    (void *)&apply_action_hold_status__13TUnk_804806E8Ff, (void *)&apply_anti_technique__13TUnk_804806E8Fl, (void *)&vfunc_58__13TUnk_804806E8Fv, (void *)&vfunc_59__13TUnk_804806E8Fv,
    (void *)&vfunc_60__13TUnk_804806E8Fv, (void *)&vfunc_61__13TUnk_804806E8Fv, (void *)&init_effect__11TBoss4Type3FPv, (void *)&reset_action_to_3__11TBoss4Type3FPv,
    (void *)&reset_pose__13TUnk_804806E8Fv, (void *)&get_anim_node_position__13TUnk_804806E8FlP3Vec, (void *)&vfunc_66__13TUnk_804806E8Fv, (void *)&vfunc_67__13TUnk_804806E8Ff,
    (void *)&get_pos__13TUnk_804806E8Fl, (void *)&apply_switch_attack__13TUnk_804806E8Fv, (void *)&enemy_spawn_jellen_effect__13TUnk_804806E8Fv, (void *)&trigger_switch_attack__13TUnk_804806E8Fv,
    (void *)&enemy_spawn_zalure_effect__13TUnk_804806E8Fv, (void *)&recalc_stats__13TUnk_804806E8Fv, (void *)&vfunc_74__9TObjEnemyFl, (void *)&vfunc_75__13TUnk_804806E8Ff,
    (void *)&vfunc_76__13TUnk_804806E8Fv, (void *)&vfunc_77__13TUnk_804806E8Fv, (void *)&vfunc_78__13TUnk_804806E8Fl, (void *)&vfunc_79__9TObjEnemyFv,
    (void *)&apply_hit_message_flags__9TObjEnemyFPv, (void *)&apply_set_data__9TObjEnemyFPv, (void *)&clear_lobby_object_state__9TObjEnemyFv,
};
#define lbl_80486FB0 ((u8 *)lbl_80486FB0)
#define boss4_type3_index_table ((u8 *)boss4_type3_index_table)
#define lbl_80487150 ((u8 *)lbl_80487150)
#define boss4_type3_default_position (*(Vec_80059C20 *)boss4_type3_default_position)
#define boss4_type3_interp_origin_vec (*(Vec_80059C20 *)boss4_type3_interp_origin_vec)
#define boss4_type3_radar_marker_colors ((u32 *)boss4_type3_radar_marker_colors)
#define __vt__11TBoss4Type3 ((u8 *)__vt__11TBoss4Type3)

extern "C" {
Ply_80059ABC * get_player_by_client_id(int);
}
}
u32 drain_player_hp(s32 id, u32 arg1);

struct Obj_80059ABC;
struct TBoss4Type3;

typedef char TypedVector_80059B78_size[(sizeof(TypedVector_80059B78) == 12) ? 1 : -1];

extern "C" {
void update_collisions__10TObjPlayerFv(void *);
void submit_cursor_candidate(void *, int);
struct O_80059618;
struct Obj_8005A1AC;
struct Ply_80059ABC;

s32 init_trail_buffer__11TBoss4Type3FPvifff(void *, s32, f32, f32, f32);
}
extern "C" {
s32 create__12TObjEneSaverFPvPv(s32, s32);
void draw_trail_with_colors(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

Self_8005AE60 *TBoss4Type3__ct(Self_8005AE60 *, s32, s32 *);
}

void * create__13TObjBs4CutAtkFPvPvPv(void *arg0, void *arg1, void *arg2) {
    void *o;
    o = __nw__7TObjectFUl(0x28);
    if (o != NULL) {
        o = __ct__13TObjBs4CutAtkFv((void *)o, (s32)arg0, (s32)arg1, (s32)arg2);
    }
    return o;
}

void *__ct__13TObjBs4CutAtkFv(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    ((s32 (*)(void))__ct__7TObjectFP7TObject)();
    *(void **)((s8 *)arg0 + 0x18) = __vt__13TObjBs4CutAtk;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TObjBs4CutAtk_name;
    if (arg3 == 0) {
        *(s32 *)((s8 *)arg0 + 0x1C) = -0x1554;
        *(s32 *)((s8 *)arg0 + 0x1C) = (s32) (*(s32 *)((s8 *)arg0 + 0x1C) + (arg2 << 0xC));
        *(s32 *)((s8 *)arg0 + 0x20) = 0x71C;
    } else {
        *(s32 *)((s8 *)arg0 + 0x1C) = 0xE38;
        *(s32 *)((s8 *)arg0 + 0x1C) = (s32) (*(s32 *)((s8 *)arg0 + 0x1C) + (arg2 << 0xC));
        *(s32 *)((s8 *)arg0 + 0x20) = -0x71C;
    }
    *(s32 *)((s8 *)arg0 + 0x24) = 0;
    return arg0;
}

TObjBs4CutAtk::~TObjBs4CutAtk() {}

void TObjBs4CutAtk::run_task() {
    s32 lo;
    s32 hi;
    s32 i;
    VObj_8005B218 *p;
    s32 id;
    u16 ang;

    lo = (u16)this->angle;
    hi = lo + 0x71C;
    if (query_teammate_state__9TObjEneDDFv(this) != 0) {
        return;
    }
    for (i = 0; i < TLobby::get_game_mode(); i++) {
        p = (VObj_8005B218 *)get_player_data__10TObjPlayerFi(i);
        if (TBoss4Type3__sub_8005254C(get_entity_id(p)) == 0) {
            continue;
        }
        ang = (s32)(10430.38043493439 * atan2_float(-(*(f32 *)((s8 *)p + 0x38) - 10000.0f), *(f32 *)((s8 *)p + 0x40)));
        if (ang >= lo && ang < hi) {
            Dmg_8005B218 d;
            id = *(s32 *)&this->m_up;
            d.type = 0;
            d.val = *register_boss__6TLobbyFl(0x38);
            {
                Dmg_8005B218 t = d;
                p->m21(id, &t, 0, -1, -1);
            }
        }
    }
    if (++this->age >= 6) {
        queue_destruction__7TObjectFv(this);
        return;
    }
    this->angle += this->angle_step;
}

void TObjBs4CutAtk::render() {  }

s32 TBoss4Type3::create(s32 arg0) {
    s32 var_r31;
    s32 var_r4;

    var_r31 = ((s32 (*)(s32))__nw__7TObjectFUl)(0x530);
    if (var_r31 != 0) {
        var_r4 = ((s32 (*)(s32))__nw__7TObjectFUl)(0x20);
        if (var_r4 != 0) {
            var_r4 = TObjControl__ct(var_r4, tl_04);
        }
        var_r31 = (s32)TBoss4Type3__ct((Self_8005AE60 *)var_r31, var_r4, (s32 *)arg0);
    }
    return var_r31;
}

extern "C" {

Self_8005AE60 *TBoss4Type3__ct(Self_8005AE60 *self, s32 parent, s32 *arg2) {
    s32 i;
    s32 model;
    s32 p;

    __ct__9TObjEnemyFP7TObject(self, (void*)parent);
    self->vt = __vt__11TBoss4Type3;
    self->f0 = (s32)TBoss4Type3_name;
    ((TUnk_804806E8 *)self)->add_flags_2e4(8);
    self->f38C = arg2[0];
    ((TBoss4Type3 *)self)->apply_set_data(arg2 + 1);
    self->f390 = TBoss4Uro::get_instance_count();
    self->f24 = 0;
    self->f34 = 0;
    VecCopy__FP3VecPC3Vec(self->v38, boss4_type3_start_position);
    self->f60 = 0;
    VecCopy__FP3VecPC3Vec(self->v44,
        (void *)VecCopy__FP3VecPC3Vec(self->v50,
            (void *)VecCopy__FP3VecPC3Vec(self->v74, self->v38)));
    self->f394 = init_collision_body_parts(self, boss4_type3_collision_body_desc, 1);
    VecCopy__FP3VecPC3Vec(self->v2FC, self->v38);
    self->f308 = self->f30C = self->f310 = 0.0f;
    self->f2A8 = 0;
    ((TObjEnemy *)self)->bind_enemy_combat_stats((u8 *)((int)register_boss__6TLobbyFl(0x38)), (u8 *)(TLobby::dispatch_shared_handler_b(0x38)), (u8 *)(TLobby::register_object(0x38)));
    self->f33E = self->f3E4 = self->f32C;
    ((TBoss3Volopt *)self)->reset_photon_effect();
    ((TObjEnemy *)self)->set_param(0x2F);
    self->f3F0 = 0;
    self->f3FC = 0;
    self->f3F8 = 0.6f;
    self->f3F4 = 0.0f;
    for (i = 0; i < 3; i++) {
        self->a438[i] = TObjFish__sub_800E3124((u8 *)(((void **)boss4_type3_effect_desc_ptr_table)[i]), (s32)&self->a444[i]);
    }
    TObjPlayer::set_global_flag();
    model = get_bml_model(self->f390, ((s32 *)lbl_80486FB0)[0]);
    p = (s32)::operator new(0x18);
    if (p != 0) {
        p = init_trail_buffer__11TBoss4Type3FPvifff((void *)p, 2, 3.0f, 9.0f, 0.6f);
    }
    *(s32 *)((u8 *)self + 0x51C) = p;
    draw_trail_with_colors((u8 *)(*(s32 *)((u8 *)self + 0x51C)), model, get_bml_motion(self->f390, ((s32 *)&TBoss4Type3__anim_state_table)[0x44 / 4]), 0x16, 0x17);
    *(s32 *)((u8 *)self + 0x524) = create__12TObjEneSaverFPvPv(0xA0303030, 0xFFFF0088);
    p = (s32)::operator new(0x18);
    if (p != 0) {
        p = init_trail_buffer__11TBoss4Type3FPvifff((void *)p, 2, 3.0f, 9.0f, 0.6f);
    }
    *(s32 *)((u8 *)self + 0x520) = p;
    draw_trail_with_colors((u8 *)(*(s32 *)((u8 *)self + 0x520)), model, get_bml_motion(self->f390, ((s32 *)&TBoss4Type3__anim_state_table)[0x58 / 4]), 9, 10);
    *(s32 *)((u8 *)self + 0x528) = create__12TObjEneSaverFPvPv(0xA0303030, 0xFFFF0088);
    TObjPlayer::clear_global_state();
    ((TBoss4Type3 *)self)->create_particle_emitters();
    init_model_node_tables(self->f378, (void *)boss4_type3_model_node_specs, 2);
    self->f3D4 = self->f32C;
    self->f3CC = 0;
    self->f3D0 = *(s32 *)(dispatch_shared_handler_a__6TLobbyFl(0x38) + 0x24);
    self->f3B0 = 1.0f;
    self->f3B4 = 0;
    self->f3A4 = 0x10;
    self->f3A0 = 0x10;
    self->f3AC = 0;
    self->f3A8 = 0;
    self->f3B8 = 0xFFFF;
    self->f3BA = 0xFFFF;
    self->f3C4 = -0x5DB4;
    self->f3BC = 0;
    self->f3C8 = 0.0f;
    self->f3D8 = 0;
    self->f3DC = 0.0f;
    self->f3E0 = self->f32C / 2;
    self->f3E8 = 0.0f;
    self->f3EC = 1.0f;
    *(s32 *)((u8 *)self + 0x52C) = 0;
    ((TBoss4Type3 *)self)->set_action_from_table(0);
    return self;
}

S_8005AD50 *__dt__11TBoss4Type3Fv(S_8005AD50 *o, s16 flag) {
    s32 i;
    if (o != 0) {
        o->vt = __vt__11TBoss4Type3;
        fn_8004AA04(o->f378);
        ((TBoss4Type3 *)o)->destroy_parts();
        if (o->f51c != 0) {
            __dt__11TBoss4Type3FPvs((s32 *)o->f51c, 1);
            o->f51c = 0;
        }
        if (o->f524 != 0) {
            queue_destruction__7TObjectFv(o->f524);
            o->f524 = 0;
        }
        if (o->f520 != 0) {
            __dt__11TBoss4Type3FPvs((s32 *)o->f520, 1);
            o->f520 = 0;
        }
        if (o->f528 != 0) {
            queue_destruction__7TObjectFv(o->f528);
            o->f528 = 0;
        }
        for (i = 0; i < 3; i++) {
            TObjFish::init_state_1(o->fx[i]);
            o->fx[i] = 0;
        }
        free_collision_body_parts(o);
        o->f394 = 0;
        __dt__9TObjEnemyFv((TObjEnemy *)o, 0);
        if (flag > 0) {
            __dl__7TObjectFPv(o);
        }
    }
    return o;
}

void init_effect__11TBoss4Type3FPv(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 0x30) = (s32) (*(s32 *)((s8 *)arg0 + 0x30) & 0xFFFFFDFF);
    *(f32 *)((s8 *)arg0 + 0x3E8) = (f32) 1.0f;
    ((s32 (*)(int, void *, int, int, void *))play_sound_effect)(0x4003B734, arg0 + 0x38, 0, 1, arg0);
}

void reset_action_to_3__11TBoss4Type3FPv(Obj_8005ACBC *self) {
    if (self->f374 != 3 && self->f374 != 2) {
        self->f3b8 = 0xFFFF;
        self->f3ba = 0xFFFF;
        ((TBoss4Type3 *)self)->set_action_from_table(3);
    }
}

}

#pragma push
#pragma fp_contract on
void TBoss4Type3::run_task() {
    u8 v[2][0xC];
    Type3Handler fn;
    void *p;
    f32 lim;
    u8 *e;

    if (this->m_3ba != 0xFFFF && TBoss4Type3__sub_8005254C(this->m_3ba) == 0) {
        this->m_3ba = 0xFFFF;
    }
    if (this->m_3b8 != 0xFFFF && TBoss4Type3__sub_8005254C(this->m_3b8) == 0) {
        this->m_3b8 = 0xFFFF;
    }
    if (((TBoss4DarkFalz *)((void *)this->m_38c))->is_field378_zero()) {
        fn = boss4_type3_states[this->m_374].advance;
        if (fn) {
            (this->*fn)();
        }
    }
    fn = boss4_type3_states[this->m_374].update;
    if (fn) {
        (this->*fn)();
    }
    update_phase_timer();
    advance_afterimage();
    if (this->m_3a0 != 17) {
        this->m_394->flags |= 1;
        update_collisions__10TObjPlayerFv(this);
        submit_cursor_candidate(this, -1);
    } else {
        this->m_394->flags &= ~1;
    }
    update_radar_markers();
    update_scale_sound();
    this->m_394->radius = this->m_3b0 * (f32)(this->m_3cc - this->m_3d0) + (f32)this->m_3d0;
    handle_damage_taken();
    if (this->m_374 != 2) {
        copy_positions_to_parts();
        ((TBoss4Type2 *)(&this->m_378))->scroll_strips();
    }
    if (this->m_3ba == 0xFFFF) {
        if ((this->m_3c8 -= 0.06666667f) < 0.0f) {
            this->m_3c8 = 0.0f;
        }
    } else {
        if ((this->m_3c8 += 0.06666667f) > 1.0f) {
            this->m_3c8 = 1.0f;
        }
        if (get_player_by_client_id(this->m_3ba) == 0) {
            this->m_3c8 = 0.0f;
        }
    }
    update_target_effect_timer();
    this->m_3d4 = this->hp;
    request_follow_camera_default_offsets();
    if ((this->m_3dc += 0.022222223f) >= 1.0f) {
        this->m_3dc -= 1.0f;
    }
    lim = this->m_3f4;
    if (lim > 29.0f) {
        lim = 29.0f;
    }
    p = ::operator new(0x18);
    if (p != 0) {
        p = (void *)init_trail_buffer__11TBoss4Type3FPvifff(p, 2, lim, lim, 0.6f);
    }
    TObjPlayer::set_global_flag();
    ((TBoss4Type3 *)p)->draw_motion_trail((s32)(get_bml_model(this->m_390, ((s32 *)lbl_80486FB0)[0])), (s32)(get_bml_motion(this->m_390, TBoss4Type3__anim_state_table[this->m_3f0].motions[0])), (s32)boss4_type3_run_task_params, 0);
    TObjPlayer::clear_global_state();
    e = ((u8 *(*)(void *, f32))lookup_entry_by_value__10TObjPlayerFPvf)(p, lim);
    push_matrix();
    set_matrix_identity(0);
    post_translate_matrix(&this->position.x);
    rotate_matrix_y(0, this->rotation_y);
    matrix_mult_vec(0, e, v[0]);
    matrix_mult_vec(0, e + 0xC, v[1]);
    pop_matrix();
    if (e != 0) {
        if (this->effect_parts[5] != 0) {
            ((TNowLoading *)(this->effect_parts[5]))->copy_pos(v[0]);
        }
        if (this->effect_parts[6] != 0) {
            ((TNowLoading *)(this->effect_parts[6]))->copy_pos(v[1]);
        }
    }
    __dt__11TBoss4Type3FPvs((s32 *)p, 1);
    this->m_3e8 += -0.06666667f;
    if (this->m_3e8 < 0.0f) {
        this->m_3e8 = 0.0f;
    }
    this->m_3ec = (f32)this->hp / (f32)this->referenceHp;
}
#pragma pop

void TBoss4Type3__sub_8005A86C(void* p) { ((TBoss4Type3 *)p)->draw(); }

void TBoss4Type3::advance_afterimage() {
    VecCopy__FP3VecPC3Vec(((u8 *)this) + 0x2FC, ((u8 *)this) + 0x38);
    *(f32 *)((s8 *)((u8 *)this) + 0x300) += 25.0f;
}

void TBoss4Type3::draw() {
    ((void (*)(void *))toggle_particle_effect__10TObjPlayerFv)(this);
    ((void (*)(void))push_matrix)();
    ((void (*)(void *))post_translate_matrix)((void *)((char *)this + 56));
    ((void (*)(int, void *))rotate_matrix_y)(0, *(void * *)&this->rotation_y);
    sub_8005A438();
    ((void (*)(void))pop_matrix)();
    ((void (*)(void))push_matrix)();
    ((void (*)(void *))post_translate_matrix)((void *)((char *)this + 1152));
    ((void (*)(int, void *))rotate_matrix_y)(0, *(void * *)&this->rotation_y);
    TObjPlayer::draw_player_model_by_id(this->m_3ba, this->m_3c8);
    ((void (*)(void))pop_matrix)();
    TParticleCtrl::end_effect_render();
}

#pragma push
#pragma opt_common_subs off
void TBoss4Type3::update_phase_timer() {
    f32 temp_f1;
    f32 temp_f1_2;
    *(s32 *)((s8 *)((u8 *)this) + 0x3FC) = 0;
    *(f32 *)((s8 *)((u8 *)this) + 0x3F4) = (f32) (*(f32 *)((s8 *)((u8 *)this) + 0x3F4) + *(f32 *)((s8 *)((u8 *)this) + 0x3F8));
    switch (*(s32 *)((s8 *)((u8 *)this) + 0x400)) {
    case 0:
        temp_f1 = *(f32 *)((s8 *)((u8 *)this) + 0x3F4);
        if (temp_f1 >= 30.0f) {
            *(f32 *)((s8 *)((u8 *)this) + 0x3F4) = (f32) (temp_f1 - 30.0f);
            *(s32 *)((s8 *)((u8 *)this) + 0x3FC) = 1;
        }
        break;
    case 1:
        if (*(f32 *)((s8 *)((u8 *)this) + 0x3F4) >= 29.0f) {
            *(f32 *)((s8 *)((u8 *)this) + 0x3F4) = (f32) 29.0f;
            *(s32 *)((s8 *)((u8 *)this) + 0x3FC) = 1;
        }
        break;
    case 2:
        if (*(f32 *)((s8 *)((u8 *)this) + 0x3F4) >= 29.0f) {
            *(s32 *)((s8 *)((u8 *)this) + 0x3F0) = TBoss4Type3__anim_state_table[*(s32 *)((s8 *)((u8 *)this) + 0x3F0)].flags;
            *(s32 *)((s8 *)((u8 *)this) + 0x400) = TBoss4Type3__anim_state_table[*(s32 *)((s8 *)((u8 *)this) + 0x3F0)].kind;
            *(f32 *)((s8 *)((u8 *)this) + 0x3F4) = (f32) 0.0f;
            *(s32 *)((s8 *)((u8 *)this) + 0x3FC) = 1;
        }
        break;
    }
    temp_f1_2 = *(f32 *)((s8 *)((u8 *)this) + 0x3F4);
    if ((temp_f1_2 < 0.0f) || (temp_f1_2 >= 30.0f)) {
        *(f32 *)((s8 *)((u8 *)this) + 0x3F4) = (f32) 0.0f;
    }
}
#pragma pop

void TBoss4Type3::set_anim_state(s32 arg1) {
    if (arg1 != -1) {
        this->m_3f0 = arg1;
        this->m_3f4 = (f32) 0.0f;
        *(s32 *)&this->_pad400 = TBoss4Type3__anim_state_table[arg1].kind;
    }
}

#pragma push
#pragma opt_propagation off
void TBoss4Type3::draw_model_set(const s32 *tbl, f32 t) {
    f32 c;
    s32 i;
    f32 v;
    s32 off;

    if (this->m_3f0 < 0 || this->m_3f0 >= 0xA) {
        return;
    }
    v = this->m_3f4;
    c = 0.0f;
    if (v < c || v >= 30.0f) {
        return;
    }
    if (c == t) {
        return;
    }
    if (t < 1.0f) {
        TObjPlayer__sub_80052390(t);
    } else if (tbl == (const s32 *)lbl_80486FB0) {
        TBoss6PlotFalz__sub_802AC008(this->m_3e8, this->m_3ec);
    }
    model_render_flags |= 0x20000;
    TObjEneRe4Sorcerer__sub_801E3F1C(0.0f, this->m_3dc);
    TObjPlayer::set_global_flag();
    for (i = 0; i < 3; i++) {
        TObjFish::set_global_param(TObjFish__sub_8001EDB0(this->m_390, tbl[i]));
        off = i;
        ((TObjFish *)((s32)this->render_lists[off]))->set_draw_callback_list();
        draw_model_motion((void *)(get_bml_model(this->m_390, tbl[i])), (void *)(get_bml_motion(this->m_390, TBoss4Type3__anim_state_table[this->m_3f0].motions[i])), this->m_3f4);
        clear_render_callback__8TObjFishFv((s32)this->render_lists[off]);
    }
    TObjPlayer::clear_global_state();
    model_render_flags &= ~0x20000;
    if (t < 1.0f) {
        TObjPlayer::sync_player_globals();
        return;
    }
    if (tbl == (const s32 *)lbl_80486FB0) {
        TBoss6PlotFalz::update_camera_target();
    }
}
#pragma pop

void TBoss4Type3::copy_pair(void* q) { *(u32 *)&this->m_name = *(u32*)((char*)q + 0x0); (*(f32 *)&this->m_flags) = *(f32*)((char*)q + 0x4); }

void TBoss4Type3::sub_8005A438() {
    Pair_8005A438 b;
    Pair_8005A438 a;
    Words_8005A438 tmp;
    Pair_8005A438 *pb = &b;
    a.p = lbl_80486FB0;
    a.f = ((Obj_8005A438 *)this)->f3b0;
    b.p = boss4_type3_index_table;
    b.f = 1.0f - a.f;
    if (a.f < 0.5f) {
        tmp.p = lbl_80486FB0;
        tmp.w = *(u32 *)&a.f;
        ((TBoss4Type3 *)(&a))->copy_pair(pb);
        ((TBoss4Type3 *)pb)->copy_pair(&tmp);
    }
    this->draw_model_set((const s32 *)a.p, a.f);
    this->draw_model_set((const s32 *)b.p, b.f);
}

void TBoss4Type3::set_action_from_table(s32 arg1) {
    Type3Handler m;
    TBoss4Type3__sub_8005A150(this);
    this->m_374 = arg1;
    set_anim_state(boss4_type3_states[this->m_374].animation);
    m = boss4_type3_states[this->m_374].enter;
    if (m != 0) {
        (this->*m)();
    }
}

void TBoss4Type3::create_particle_emitters() {
    Obj_8005A300 *self = (Obj_8005A300 *)this;
    s32 i;
    for (i = 0; i < 8; i++) {
        self->f404[i] = (u32)create_particle_emitter(self->f38, boss4_type3_effect_ids[i]);
        if (self->f404[i] != 0) {
            ((TBoss4Type2 *)(self->f404[i]))->set_flags(0x40);
        }
    }
    for (; i < 13; i++) {
        self->f404[i] = 0;
    }
}

void TBoss4Type3::destroy_parts() {
    Obj_8005A2A4 *self = (Obj_8005A2A4 *)this;
    s32 i;
    for (i = 0; i < 13; i++) {
        if (self->parts[i] != 0) {
            TBoss4Type2::request_destroy((u32)self->parts[i]);
            self->parts[i] = 0;
        }
    }
}

void TBoss4Type3::copy_positions_to_parts() {
    Vec_8005A1AC *pos[8] = {
        &((Obj_8005A1AC *)this)->f48c, &((Obj_8005A1AC *)this)->f498, &((Obj_8005A1AC *)this)->f4d4, &((Obj_8005A1AC *)this)->f4e0,
        &((Obj_8005A1AC *)this)->f444, &((Obj_8005A1AC *)this)->f450, &((Obj_8005A1AC *)this)->f45c, 0
    };
    Vec_8005A1AC **p = pos;
    s32 i;
    for (i = 0; i < 8; i++, p++) {
        if (((Obj_8005A1AC *)this)->f404[i] != 0 && *p != 0) {
            ((TNowLoading *)(((Obj_8005A1AC *)this)->f404[i]))->copy_pos(*p);
        }
    }
    if (((Obj_8005A1AC *)this)->f3ba == 0xFFFF) {
        ((TNowLoading *)(((Obj_8005A1AC *)this)->f404[7]))->copy_pos(lbl_80487150);
    } else {
        ((TNowLoading *)(((Obj_8005A1AC *)this)->f404[7]))->copy_pos(&((Obj_8005A1AC *)this)->f480);
    }
}

void TBoss4Type3__sub_8005A150(TBoss4Type3 *self) {
    s32 i;
    for (i = 8; i < 13; i++) {
        u32 *slot = &((Obj_8005A300 *)self)->f404[i];
        if (*slot != 0) {
            TBoss4Type2::request_destroy(*slot);
            *slot = 0;
        }
    }
}

#pragma push
#pragma opt_common_subs off
void TBoss4Type3::update_scale_sound() {
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f31;
    s32 temp_r0;
    s32 temp_r0_2;
    s32 var_r3;
    s32 var_r5;
    s32 var_r6;
    u8 *var_r31;
    u8 *var_r4;
    var_r31 = ((u8 *)this);
    temp_r0 = *(s32 *)((s8 *)((u8 *)this) + 0x374);
    temp_f31 = *(f32 *)((s8 *)((u8 *)this) + 0x3B0);
    if ((temp_r0 == 2) || (temp_r0 == 3)) {
        temp_f1 = (*(f32 *)((s8 *)var_r31 + 0x3B0) += 0.1f);
        if (temp_f1 > 1.0f) {
            *(f32 *)((s8 *)var_r31 + 0x3B0) = (f32) 1.0f;
        }
    } else {
        var_r3 = *(s32 *)((s8 *)var_r31 + 0x3B4);
        *(s32 *)((s8 *)var_r31 + 0x3B4) = (var_r3 + 1);
        temp_r0_2 = *(s32 *)((s8 *)var_r31 + 0x3B4);
        if (temp_r0_2 < 0x78) {
            *(f32 *)((s8 *)var_r31 + 0x3B0) = (f32) 1.0f;
        } else if (temp_r0_2 < 0x96) {
            temp_f1_2 = (*(f32 *)((s8 *)var_r31 + 0x3B0) += (-0.033333335f));
            if (temp_f1_2 < 0.0f) {
                *(f32 *)((s8 *)var_r31 + 0x3B0) = (f32) 0.0f;
            }
        } else if (temp_r0_2 < 0x10E) {
            *(f32 *)((s8 *)var_r31 + 0x3B0) = (f32) 0.0f;
        } else if (temp_r0_2 < 0x12C) {
            temp_f1_3 = (*(f32 *)((s8 *)var_r31 + 0x3B0) += 0.033333335f);
            if (temp_f1_3 > 1.0f) {
                *(f32 *)((s8 *)var_r31 + 0x3B0) = (f32) 1.0f;
            }
        } else {
            *(f32 *)((s8 *)var_r31 + 0x3B0) = (f32) 1.0f;
            *(s32 *)((s8 *)var_r31 + 0x3B4) = 0;
        }
        if (((0.0f == temp_f31) && (*(f32 *)((s8 *)var_r31 + 0x3B0) > 0.0f)) || ((1.0f == temp_f31) && (*(f32 *)((s8 *)var_r31 + 0x3B0) < 1.0f))) {
            var_r3 = 0x40040000;
            var_r4 = var_r31 + 0x38;
            var_r3 = 0x4003B02F;
            var_r5 = 0;
            var_r6 = 1;
            ((s32 (*)(s32, s32, s32, s32))play_sound_effect)(0x4003B02F, (s32)var_r4, 0, 1);
        }
        if ((temp_f31 > 0.0f) && (0.0f == *(f32 *)((s8 *)var_r31 + 0x3B0))) {
            var_r3 = 0x40040000;
            var_r4 = var_r31 + 0x38;
            var_r3 = 0x4003AD30;
            var_r5 = 0;
            var_r6 = 1;
            ((s32 (*)(s32, s32, s32, s32))play_sound_effect)(0x4003AD30, (s32)var_r4, 0, 1);
        }
    }
}
#pragma pop

void TBoss4Type3__sub_80059F64(Obj_80059F64 *self, s32 arg1) {
    if (self->target != 0) {
        ((TBoss4DarkFalz *)(self->target))->send_code_25_4((arg1 & 0x1F) | ((self->f3a0 & 0x1F) << 5) | ((self->f3a0 & 0x1F) << 10) | ((self->f3a8 & 0xF) << 15) | ((self->f3a8 & 0xF) << 19) | ((self->f3b8 & 0xF) << 23) | ((self->f3ba & 0xF) << 27));
    }
}

void TBoss4Type3::send_packed_action(s32 arg1, s32 arg2, s32 arg3) {
    Obj_80059F04 *self = (Obj_80059F04 *)this;
    if (self->target != 0) {
        ((TBoss4DarkFalz *)(self->target))->send_code_25_4((arg1 & 0x1F) | ((self->f3a0 & 0x1F) << 5) | ((arg2 & 0x1F) << 10) | ((self->f3a8 & 0xF) << 15) | ((arg3 & 0xF) << 19) | ((self->f3b8 & 0xF) << 23) | ((self->f3ba & 0xF) << 27));
    }
}

void TBoss4Type3__sub_80059EA8(Obj_80059EA8 *self, s32 arg1, s32 arg2) {
    if (self->target != 0) {
        ((TBoss4DarkFalz *)(self->target))->send_code_25_4((arg1 & 0x1F) | ((self->f3a0 & 0x1F) << 5) | ((self->f3a0 & 0x1F) << 10) | ((self->f3a8 & 0xF) << 15) | ((self->f3a8 & 0xF) << 19) | ((arg2 & 0xF) << 23) | ((self->f3ba & 0xF) << 27));
    }
}

void TBoss4Type3::spawn_random_effect() {
    s32 arg0 = (s32)this;
    s32 temp_r5;

    temp_r5 = (s32) (15.99f * ((f32 (*)(void))calc_boss4_scale__10TObjPlayerFi)());
    send_packed_action(0xF, temp_r5, temp_r5);
}

void TBoss4Type3__sub_80059DCC(TBoss4Type3 *self, u32 packed) {
    u16 v;
    s32 action;
    self->m_3a4 = (packed >> 5) & 0x1F;
    self->m_3a0 = (packed >> 10) & 0x1F;
    self->m_3ac = (packed >> 15) & 0xF;
    self->m_3a8 = (packed >> 19) & 0xF;
    v = (packed >> 23) & 0xF;
    self->m_3b8 = v;
    if (v == 0xF) {
        self->m_3b8 = 0xFFFF;
    }
    v = (packed >> 27) & 0xF;
    self->m_3ba = v;
    if (v == 0xF) {
        self->m_3ba = 0xFFFF;
    }
    action = packed & 0x1F;
    if (action < 0 || action >= 17) {
        return;
    }
    self->set_action_from_table(action);
}

#pragma push
#pragma fp_contract on
void TBoss4Type3::interp_position_between_nodes() {
    u8 *arg0 = (u8 *)this;
    Vec_80059C20 pts[2];
    s32 ids[2];
    s32 id;
    Vec_80059C20 *p;
    s32 a;
    s32 i;

    a = this->m_3ac << 12;
    this->rotation_y = approach_angle_limited(this->rotation_y, -(a + (s32)(this->m_39c * (f32)((s32 (*)(s32, s32))angle_diff_s16)(a, this->m_3a8 << 12))), 0x888);
    ids[0] = this->m_3a4;
    ids[1] = this->m_3a0;
    for (i = 0; i < 2; i++) {
        id = ids[i];
        switch (id) {
        case 16:
            ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&pts[i], &boss4_type3_default_position);
            break;
        case 17:
            ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&pts[i], &boss4_type3_interp_origin_vec);
            break;
        default:
            p = &pts[i];
            ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(p, &boss4_type3_default_position);
            id <<= 12;
            p->x += (-100.0f) * sin_table_lookup(id);
            p->z += 100.0f * cos_table_lookup(id);
            break;
        }
    }
    ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(arg0 + 0x38, &pts[1]);
    subtract_vector((u8 *)&this->position, &pts[0]);
    this->position.x *= this->m_39c;
    this->position.y *= this->m_39c;
    this->position.z *= this->m_39c;
    vec3_add_to((u8 *)&this->position, &pts[0]);
}
#pragma pop

s32 TBoss4Type3::choose_attack_heading_sector() {
    s32 arg0 = (s32)this;
    TypedVector_80059B78 sp8;
    f32 temp_f0;
    u16 id;
    id = ((u16 (*)(void))pick_random_target_player__11TBoss4Type3Fv)();
    if ((id == 0xFFFFU) || (TBoss4Type3__sub_8005254C(id) == 0)) {
        return TBoss4Type3::get_random_scaled((void *)arg0);
    }
    VecCopy__FP3VecPC3Vec(&sp8, (void *) (((s32)get_player_by_client_id(id)) + 0x38));
    temp_f0 = sp8.f.x - 10000.0f;
    sp8.f.x = temp_f0;
    return ((u32) ((s32) (10430.38043493439 * atan2_float((f32) (-temp_f0), sp8.f.z)) + 0x800) >> 0xCU) & 0xF;
}

s32 TBoss4Type3::get_random_scaled(void * _w0) {
    return (s32) (15.84f * ((f32 (*)(void))calc_boss4_scale__10TObjPlayerFi)());
}

void TBoss4Type3::turn_toward_player(s32 arg1) {
    Obj_80059ABC *self = (Obj_80059ABC *)this;
    Ply_80059ABC *p;
    if ((u16)arg1 != 0xFFFF) {
        p = get_player_by_client_id((u16)((u16)arg1));
        if (p != NULL) {
            self->f60 = approach_angle_limited(self->f60, (s32)(10430.38043493439 * atan2_float(p->f38 - 10000.0f, p->f40)), 0x888);
            calc_grid_index();
        }
    }
}

void TBoss4Type3::calc_grid_index() {
    this->m_3ac = (s32) (((u32) -(this->rotation_y + 0x800) >> 0xCU) & 0xF);
    this->m_3a8 = (s32) (((u32) -(this->rotation_y + 0x800) >> 0xCU) & 0xF);
}

void TBoss4Type3__sub_800599F4(void *p, int lo, int hi) {
    s32 sector = ((TBoss4Type3 *)p)->choose_attack_heading_sector();
    s32 n = (s64)(s32)(0.99f * (f32)(hi - lo + 1) * calc_boss4_scale__10TObjPlayerFi(p));
    n += lo;
    ((TBoss4Type3 *)p)->send_packed_action(n + 4, sector, sector);
}

void TBoss4Type3::update_radar_markers() {
    s32 c[3];
    Vec_800597A8 v;
    u32 col;
    s32 sh;
    u8 tgt;
    u16 id;
    s32 i;
    s32 d;
    Ply_80059ABC *p;
    f32 f;
    s32 n;
    s32 j;
    u8 *arg0 = (u8 *)this;
    col = 0xFFFFA24C;
    id = *(u16 *)((s8 *)arg0 + 0x3BA);
    if (id != 0xFFFF) {
        if (id >= 4) return;
        col = boss4_type3_radar_marker_colors[id];
    }
    for (i = 0, sh = 0; i < 3; i++, sh += 8) {
        tgt = col >> sh;
        c[i] = (u8)(*(u32 *)((s8 *)arg0 + 0x3C4) >> sh);
        d = tgt - c[i];
        if (d > 0) {
            if ((c[i] = c[i] + 0x10) > tgt) c[i] = tgt;
        } else if (d < 0) {
            if ((c[i] = c[i] - 0x10) < tgt) c[i] = tgt;
        }
    }
    *(u32 *)((s8 *)arg0 + 0x3C4) = c[0] | ((c[2] << 16) | 0xFF000000 | (c[1] << 8));
    if (0.0f == *(f32 *)((s8 *)arg0 + 0x3B0) && (*(s32 *)((s8 *)arg0 + 0x3C0) & 4)) {
        add_radar_scaled_marker(arg0 + 0x2FC, -1, 1, 1, 5.0f);
    } else {
        add_radar_scaled_marker(arg0 + 0x2FC, *(u32 *)((s8 *)arg0 + 0x3C4), 1, 1, 5.0f);
    }
    if (!(*(s32 *)((s8 *)arg0 + 0x3C0) & 1) && *(u16 *)((s8 *)arg0 + 0x3BA) != 0xFFFF) {
        p = get_player_by_client_id((u16)(*(u16 *)((s8 *)arg0 + 0x3BA)));
        if (p != NULL) {
            VecCopy__FP3VecPC3Vec(&v, (u8 *)p + 0x38);
            subtract_vector(&v, arg0 + 0x38);
            v.y = 0.0f;
            f = vector_length(&v);
            if (!(f < 25.0f)) {
                n = (s32)(f / 25.0f);
                if (n > 0xE) n = 0xE;
                normalize_vector(&v);
                v.x *= 25.0f;
                v.z *= 25.0f;
                {
                Vec_800597A8 w = *(Vec_800597A8 *)(arg0 + 0x38);
                vec3_add_to(&w, &v);
                for (j = 0; j < n; j++) {
                    add_radar_scaled_marker(&w, boss4_type3_radar_marker_colors[*(u16 *)((s8 *)arg0 + 0x3BA)], 1, 1, 2.5f);
                    vec3_add_to(&w, &v);
                }
                }
            }
        }
    }
    (*(s32 *)((s8 *)arg0 + 0x3C0))++;
}

void TBoss4Type3::handle_damage_taken() {
    u8 *p;
    s32 i;
    u32 e;
    if (((O_80059618 *)this)->f3ba == 0xFFFF || ((O_80059618 *)this)->f374 == 2 || ((O_80059618 *)this)->f374 == 3 || ((O_80059618 *)this)->f32c >= ((O_80059618 *)this)->f3e4 ||
        (p = (u8 *)get_player_by_client_id(((O_80059618 *)this)->f3ba)) == NULL) {
        ((O_80059618 *)this)->f3e4 = ((O_80059618 *)this)->f32c;
        return;
    }
    drain_player_hp(((O_80059618 *)this)->f3ba, ((O_80059618 *)this)->f3e4 - ((O_80059618 *)this)->f32c);
    ((O_80059618 *)this)->f3e4 = ((O_80059618 *)this)->f32c;
    TBoss4Type3::create_yutai((void *)((O_80059618 *)this), (void *)2, (void *)((O_80059618 *)this)->f3ba);
    Vec_80059618 pos = *(Vec_80059618 *)(p + 0x2FC);
    Vec_80059618 tgt = ((O_80059618 *)this)->f480;
    Vec_80059618 dir;
    VecCopy__FP3VecPC3Vec(&dir, &tgt);
    subtract_vector(&dir, &pos);
    if (vector_length(&dir) <= 0.01f) {
        return;
    }
    normalize_vector(&dir);
    dir.x *= 25.0f;
    dir.y *= 25.0f;
    dir.z *= 25.0f;
    for (i = 0; i < 8; i++) {
        e = (u32)spawn_particle_effect(&pos, 0x38);
        if (e != 0) {
            ((TBoss4Type2 *)e)->set_flags(0x40);
        }
        vec3_add_to(&pos, &dir);
        if (((f32 (*)(void *, void *))xyz_distance)(&pos, &tgt) <= 12.75f) {
            break;
        }
    }
}

void TBoss4Type3::update_target_effect_timer() {
    s32 temp_r30;
    s32 var_r30;

    var_r30 = 1;
    if ((s32) *(s32 *)((s8 *)this + 0x374) == 0x10) {
        var_r30 = 0;
    }
    if (is_split_screen() != 0) {
        if (*(u16 *)((s8 *)this + 0x3BA) == 0xFFFF) {
            var_r30 = 0;
        }
    } else if ((s32) *(u16 *)((s8 *)this + 0x3BA) != (s32) local_client_id) {
        var_r30 = 0;
    }
    if (var_r30 == 0) {
        *(s32 *)((s8 *)this + 0x3D8) = 0;
        return;
    }
    static s32 sound_frame = (s32)8.0f;
    temp_r30 = *(s32 *)((s8 *)this + 0x3D8) % 39;
    if (temp_r30 == 0) {
        start_pad_rumble_client(0x60, 0xF, (s16) *(u16 *)((s8 *)this + 0x3BA));
    }
    if (temp_r30 == sound_frame) {
        ((s32 (*)(s32, s32, s32, s32))play_sound_effect)(0x4003C133, 0, 0, 0);
    }
    *(s32 *)((s8 *)this + 0x3D8) = (s32) (*(s32 *)((s8 *)this + 0x3D8) + 1);
}

#pragma push
#pragma pool_data off
void TBoss4Type3::request_follow_camera_default_offsets() {
    if ((s32) *(s32 *)((s8 *)((u8 *)this) + 0x52C) == 1) {
        Vec target = {0.0f, 3.0f, 32.0f};
        Vec position = {0.0f, 28.8f, -5.0f};
        request_follow_camera_offsets(&position, &target, 0xFFFF);
        return;
    }
    Vec target = {0.0f, 25.43f, 45.42f};
    Vec position = {0.0f, 19.8f, -5.0f};
    request_follow_camera_offsets(&position, &target, 0xFFFF);
}
#pragma pop

void TBoss4Type3::enter_appear() {
    void* p = (void*)this; this->m_398 = 147; }

void TBoss4Type3::advance_appear() {
    void* p = (void*)this; if (this->m_398 == 0) { TBoss4Type3__sub_800599F4(p, 0, 2); } }

void TBoss4Type3::update_appear() {
    void *arg0 = (void *)this;
    s32 temp_r0;
    temp_r0 = this->m_398 - 1;
    this->m_398 = temp_r0;
    if (temp_r0 < 0) {
        ((TBoss4Type3 *)arg0)->set_action_from_table(1);
    }
}

void TBoss4Type3::advance_wait_next() {
    Obj_80059390 *self = (Obj_80059390 *)this;
    if (self->flags & 0x800) {
        ((int (*)(void*, void*))TBoss4Type3__sub_80059F64)(self, (void*)((void *)2));
    } else {
        self->f3b8 = 0xFFFF;
        self->f3ba = 0xFFFF;
        ((int (*)(void*, void*))TBoss4Type3__sub_80059F64)(self, (void*)((void *)10));
    }
}

void TBoss4Type3::enter_dead() {
    *(f32 *)&this->_pad3F8 = (f32) 0.2f;
    this->m_398 = 0x31;
}

void TBoss4Type3::advance_dead() {  }

void TBoss4Type3::update_dead() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0;
    temp_r0 = this->m_398 - 1;
    this->m_398 = temp_r0;
    if (temp_r0 < 0) {
        ((TBoss4Type3 *)arg0)->set_action_from_table(2);
    }
}

void TBoss4Type3::enter_cut() {
    u8 *arg0 = (u8 *)this;
    ((TBoss4Type3 *)(this->m_524))->reset_timer();
    ((TBoss4Type3 *)(this->m_528))->reset_timer();
    ((TBoss4Type3 *)arg0)->set_anim_state((int) (((this->m_374 - 4) & 1) + 3));
    this->m_52c = 0;
    this->m_398 = 0x31;
}

void TBoss4Type3::advance_cut() {
    u8 *arg0 = (u8 *)this;
    s32 random_scaled;
    if ((s32) this->m_398 == 0) {
        if ((s32) this->m_374 == 4) {
            this->m_3bc = 0;
            ((TBoss4Type3 *)arg0)->spawn_random_effect();
            return;
        }
        random_scaled = TBoss4Type3::get_random_scaled(arg0);
        ((TBoss4Type3 *)arg0)->send_packed_action(this->m_374 - 1, random_scaled, random_scaled);
    }
}

void TBoss4Type3::update_cut() {
    O_800590F4 *o = (O_800590F4 *)this;
  s32 pb;
  Vec_800590F4 b;
  Vec_800590F4 a;
  if (o->f398 > 0x2A)
  {
    o->f39c = 1.0f - ((o->f398 - 0x2A) / 7.0f);
  }
  else
  {
    o->f39c = 1.0f;
  }
  ((TBoss4Type3 *)o)->interp_position_between_nodes();
  if (o->f398 == 0x28)
  {
    ((s32 (*)(void *, s32, s32))create__13TObjBs4CutAtkFPvPvPv)(o, o->f3a8, (o->f374 - 4) & 1);
    play_sound_effect(0x4003B228, o->f38, 0, 1);
  }
  if ((o->f3f4 >= 3.0f) && (o->f3f4 <= 9.0f))
  {
    s32 idx = (o->f374 - 4) & 1;
    u8 *e = lookup_entry_by_value__10TObjPlayerFPvf(o->f51c[idx]);
    if (e != 0)
    {
      push_matrix();
      set_matrix_identity(0);
      ((s32 (*)(void *))post_translate_matrix)(o->f38);
      rotate_matrix_y(0, o->f60);
      matrix_mult_vec(0, e, &a);
      pb = (0, (s32)&b);
      matrix_mult_vec(0, e + 0xC, (void *) pb);
      pop_matrix();
      o->f524[idx]->m4(&a, (Vec_800590F4 *) pb);
    }
  }
  if ((--o->f398) < 0)
  {
    ((TBoss4Type3 *)o)->set_action_from_table(1);
  }
}

void TBoss4Type3::enter_go_up() {
    u8 *arg0 = (u8 *)this;
    this->m_3a4 = (s32) this->m_3a0;
    this->m_3a0 = 0x11;
    this->m_3ac = (s32) this->m_3a8;
    play_sound_effect(0x4003B031, arg0 + 0x38, 0, 1);
    this->m_52c = 1;
    this->m_398 = 0x31;
}

void TBoss4Type3::advance_go_up() {
    Obj_80059010 *self = (Obj_80059010 *)this;
    s32 id;
    if (self->f398 == 0) {
        if (self->f3ba != 0xFFFF) {
            ((int (*)(void*, void*))TBoss4Type3__sub_80059F64)(self, (void*)((void *)0xD));
        } else {
            id = pick_random_target_player__11TBoss4Type3Fv();
            if ((u16)id != 0xFFFF) {
                ((void (*)(void *, s32, s32))TBoss4Type3__sub_80059EA8)(self, 0xB, id);
            } else {
                ((int (*)(void*, void*))TBoss4Type3__sub_80059F64)(self, (void*)((void *)0xC));
            }
        }
    }
}

void TBoss4Type3::update_go_up() {
    s32 temp_r0;
    this->m_39c = (f32) (1.0f - ((f32) this->m_398 / 49.0f));
    this->m_39c = TBoss4Type3__sub_800524E8(this->m_39c);
    interp_position_between_nodes();
    temp_r0 = this->m_398 - 1;
    this->m_398 = temp_r0;
    if (temp_r0 < 0) {
        set_action_from_table(1);
    }
}

void TBoss4Type3::enter_go_down() {
    u8 *arg0 = (u8 *)this;
    this->m_3a4 = 0x11;
    this->m_3a0 = 0x10;
    this->m_3ac = (s32) this->m_3a8;
    play_sound_effect(0x4003B032, arg0 + 0x38, 0, 1);
    if ((u16) this->m_3ba == (u16)-1) {
        play_sound_effect(0x4003C62D, (void *)(0), 0, 0);
    }
    this->m_52c = 0;
    this->m_398 = 0x31;
}

void TBoss4Type3::advance_go_down() {
    Obj_80058E64 *self = (Obj_80058E64 *)this;
    s32 t;
    if (self->f398 == 0) {
        if (self->f3ba != 0xFFFF) {
            ((int (*)(void*, void*))TBoss4Type3__sub_80059F64)(self, (void*)16);
            return;
        }
        t = pick_random_target_player__11TBoss4Type3Fv();
        if (self->f32c <= self->f3e0 && (u16)t != 0xFFFF) {
            ((void (*)(void *, s32, s32))TBoss4Type3__sub_80059EA8)(self, 14, t);
            return;
        }
        TBoss4Type3__sub_800599F4(self, 0, 2);
    }
}

void TBoss4Type3::update_go_down() {
    s32 temp_r0;
    this->m_39c = (f32) (1.0f - ((f32) this->m_398 / 49.0f));
    this->m_39c = TBoss4Type3__sub_800524E8(this->m_39c);
    interp_position_between_nodes();
    temp_r0 = this->m_398 - 1;
    this->m_398 = temp_r0;
    if (temp_r0 < 0) {
        set_action_from_table(1);
    }
}

void TBoss4Type3::enter_homing() {
    this->m_3a0 = 0x11;
    this->m_3a4 = 0x11;
    this->m_3ac = (s32) this->m_3a8;
    this->m_52c = 1;
    this->m_398 = 0xC4;
}

void TBoss4Type3::advance_homing() {
    O_80058D70 *self = (O_80058D70 *)this;
    if (self->f398 == 0) {
        self->f3b8 = 0xFFFF;
        ((int (*)(void*, void*))TBoss4Type3__sub_80059F64)(self, (void*)(0xc));
    }
}

void TBoss4Type3::update_homing() {
    O_80058BA0 *o = (O_80058BA0 *)this;
    u8 *a;
    u8 *b;
    s32 n;
    s32 step;
    s32 v;
    s32 i;
    u16 id;
    a = o->f450;
    b = o->f45c;
    id = o->f3b8;
    if (id == 0xFFFF) {
        ((TBoss4Type3 *)o)->set_action_from_table(1);
        return;
    }
    if (o->f398 > 0x93) {
        ((TBoss4Type3 *)o)->turn_toward_player(id);
    } else if (o->f398 == 0x93) {
        if ((o->f424 = create_particle_emitter(a, 0xF7)) != 0) {
            ((TBoss4Type2 *)(o->f424))->set_flags(0x40);
        }
        if ((o->f428 = create_particle_emitter(b, 0xF7)) != 0) {
            ((TBoss4Type2 *)(o->f428))->set_flags(0x40);
        }
        ((TBoss4Type3 *)o)->set_anim_state(6);
    } else if (o->f398 == 0x75) {
        if (o->f424 != 0) {
            TBoss4Type2::request_destroy((u32)o->f424);
            o->f424 = 0;
        }
        if (o->f428 != 0) {
            TBoss4Type2::request_destroy((u32)o->f428);
            o->f428 = 0;
        }
        o->f52c = 0;
    }
    n = *(s32 *)(dispatch_shared_handler_a__6TLobbyFl(0x38) + 0x20);
    if (n < 1 || n > 8) {
        n = 4;
    }
    step = 0x42 / n;
    if (step < 1) {
        step = 1;
    }
    v = 0x75;
    for (i = 0; i < n; i++) {
        if (o->f398 == v) {
            TBoss4Type3::create_horming((void *)o, (void *)a, (void *)o->f3b8);
            TBoss4Type3::create_horming((void *)o, (void *)b, (void *)o->f3b8);
            play_sound_effect(0x4003B229, o->f38, 0, 1);
            break;
        }
        v += step;
    }
    if (o->f424 != 0) {
        ((TNowLoading *)(o->f424))->copy_pos(a);
    }
    if (o->f428 != 0) {
        ((TNowLoading *)(o->f428))->copy_pos(b);
    }
    if (--o->f398 < 0) {
        ((TBoss4Type3 *)o)->set_action_from_table(1);
    }
}

void TBoss4Type3::enter_light_magic() {
    this->m_3a0 = 0x11;
    this->m_3a4 = 0x11;
    this->m_3ac = (s32) this->m_3a8;
    this->m_52c = 1;
    this->m_398 = 0x93;
}

void TBoss4Type3::advance_light_magic() {
    void* p = (void*)this; if (this->m_398 == 0) { ((int (*)(void*, void*))TBoss4Type3__sub_80059F64)(p, (void*)10); } }

void TBoss4Type3::update_light_magic() {
    void *p;
    Grant_80058A48 g;
    s32 r29;
    u8 *sub;
    s32 i;
    u8 *arg0;
    arg0 = (u8 *)this;
    sub = arg0 + 0x474;
    if ((s32) *(s32 *)((s8 *)arg0 + 0x398) == 0x62) {
        ((TBoss4Type3 *)arg0)->set_anim_state(7);
    }
    if ((s32) *(s32 *)((s8 *)arg0 + 0x398) == 0x49) {
        p = spawn_particle_effect(sub, 0x133);
        if (p != 0) {
            ((TBoss4Type2 *)p)->set_flags(0x40);
        }
    }
    if ((s32) *(s32 *)((s8 *)arg0 + 0x398) == 0x45) {
        r29 = *(s32 *)(dispatch_shared_handler_a__6TLobbyFl(0x38) + 0x18);
        for (i = 0; i < 4; i++) {
            if (TBoss4Type3__sub_8005254C(i) != 0) {
                ((TObjPlayer *)(&g))->construct_target_cursor_records();
                fn_80044330(&g);
                g.f0 = 1;
                g.f4 = i;
                g.f6 = 0;
                TTecGrants::create((void *)arg0, (void *)sub, &g, (void *)r29);
            }
        }
        start_pad_rumble_all(0xC0, 0xF);
    }
    if (--*(s32 *)((s8 *)arg0 + 0x398) < 0) {
        ((TBoss4Type3 *)arg0)->set_action_from_table(1);
    }
}

void TBoss4Type3::enter_dark_magic() {
    this->m_3a0 = 0x11;
    this->m_3a4 = 0x11;
    this->m_3ac = (s32) this->m_3a8;
    play_sound_effect(0x4003B238, (void *)(0), 0, 0);
    this->m_52c = 1;
    this->m_398 = 0x62;
}

void TBoss4Type3::advance_dark_magic() {
    void* p = (void*)this; if (this->m_398 == 0) { ((int (*)(void*, void*))TBoss4Type3__sub_80059F64)(p, (void*)12); } }

#pragma push
#pragma fp_contract on
#pragma opt_propagation off
void TBoss4Type3::update_dark_magic() {
    s32 p;
    s32 r30;
    s32 i;
    O_80058848 *o;
    f32 s;
    o = (O_80058848 *)this;
    if (o->f398 == 0x46) {
        r30 = *(s32 *)(dispatch_shared_handler_a__6TLobbyFl(0x38) + 0x1C);
        for (i = 0; i < TLobby::get_game_mode(); i++) {
            p = ((s32 (*)(s32))get_player_by_client_id)(i);
            if (TBoss4Type3__sub_8005254C(i) != 0) {
                Vec_80058848 v = o->pos;
                p += 0x2FC;
                ((s32 (*)(Vec_80058848 *, u8 *))subtract_vector)(&v, (u8 *)p);
                if (0.0f == ((f32 (*)(Vec_80058848 *))vector_length)(&v)) {
                    v.y = 1.0f;
                } else {
                    ((s32 (*)(Vec_80058848 *))normalize_vector)(&v);
                }
                s = 40.0f * (3.0517578e-05f * (f32)rand()) + 35.0f;
                v.x *= s;
                v.y *= s;
                v.z *= s;
                ((s32 (*)(Vec_80058848 *, u8 *))vec3_add_to)(&v, (u8 *)p);
                create__9TTecMegidFllll(o, &v, (u8 *)p, r30);
            }
        }
        start_pad_rumble_all(0xC0, 0xF);
    }
    if (--o->f398 < 0) {
        ((TBoss4Type3 *)o)->set_action_from_table(1);
    }
}
#pragma pop

void TBoss4Type3::enter_capture() {
    play_sound_effect(0x4003C12B, (void *)(0), 0, 0);
    this->m_52c = 0;
    this->m_398 = 0x62;
}

void TBoss4Type3::advance_capture() {
    void *arg0 = (void *)this;
    if (TBoss4Type3__sub_8005254C(this->m_3b8) == 0) {
        this->m_3b8 = 0xFFFFU;
        this->m_3ba = 0xFFFFU;
        TBoss4Type3__sub_800599F4(arg0, 0, 2);
        return;
    }
    if ((s32) this->m_398 == 0) {
        this->m_3ba = (u16) this->m_3b8;
        this->m_3b8 = 0xFFFFU;
        play_sound_effect(0x4003C12C, (void *)(0), 0, 0);
        this->m_3bc = 0;
        ((TBoss4Type3 *)arg0)->spawn_random_effect();
    }
}

void TBoss4Type3::update_capture() {
    u8 *arg0 = (u8 *)this;
    Vec_800584E4 v;
    Ply_80059ABC *p;
    u16 id;
    void *pos;
    u32 h;
    id = this->m_3b8;
    if (id == 0xFFFF) {
        ((TBoss4Type3 *)arg0)->set_action_from_table(1);
        return;
    }
    if (id == 0xFFFF || (p = get_player_by_client_id(id)) == NULL) {
        v.x = v.y = v.z = 0.0f;
    } else {
        VecCopy__FP3VecPC3Vec(&v, (u8 *)p + 0x2FC);
    }
    ((TBoss4Type3 *)arg0)->turn_toward_player(this->m_3b8);
    if (this->m_398 == 0x31) {
        play_sound_effect(0x4003AA2E, 0, 0, 0);
        start_pad_rumble_client(0xC0, 0xF, (s16)this->m_3b8);
        ((TBoss4Type3 *)arg0)->set_anim_state(5);
    }
    pos = (u8 *)&this->m_474;
    if (this->m_398 < 0x12) {
        if (*(void **)((s8 *)arg0 + 0x42C) != NULL) {
            TBoss4Type2::request_destroy((u32)(*(void **)((s8 *)arg0 + 0x42C)));
            *(void **)((s8 *)arg0 + 0x42C) = NULL;
        }
    } else if (this->m_398 <= 0x21 && *(u32 *)((s8 *)arg0 + 0x42C) == 0) {
        h = (u32)create_particle_emitter(pos, 0x142);
        *(u32 *)((s8 *)arg0 + 0x42C) = h;
        if (h != 0) {
            ((TBoss4Type2 *)(*(void **)((s8 *)arg0 + 0x42C)))->set_flags(0x40);
        }
    }
    if (*(void **)((s8 *)arg0 + 0x42C) != NULL) {
        ((TNowLoading *)(*(void **)((s8 *)arg0 + 0x42C)))->copy_pos(pos);
    }
    if (this->m_398 == 0x21) {
        TBoss4Type3::create_yutai((void *)arg0, (void *)0, (void *)((void *)this->m_3b8));
    }
    if (this->m_398 == 0x1C) {
        h = (u32)spawn_particle_effect(&v, 0x38);
        if (h != 0) {
            ((TBoss4Type2 *)h)->set_flags(0x40);
        }
    }
    pos = &v;
    if (this->m_398 < 2) {
        if (*(void **)((s8 *)arg0 + 0x430) != NULL) {
            TBoss4Type2::request_destroy((u32)(*(void **)((s8 *)arg0 + 0x430)));
            *(void **)((s8 *)arg0 + 0x430) = NULL;
        }
        if (*(void **)((s8 *)arg0 + 0x434) != NULL) {
            TBoss4Type2::request_destroy((u32)(*(void **)((s8 *)arg0 + 0x434)));
            *(void **)((s8 *)arg0 + 0x434) = NULL;
        }
    } else if (this->m_398 <= 0x12) {
        if (*(u32 *)((s8 *)arg0 + 0x430) == 0) {
            h = (u32)create_particle_emitter(pos, 0xEA);
            *(u32 *)((s8 *)arg0 + 0x430) = h;
            if (h != 0) {
                ((TBoss4Type2 *)(*(void **)((s8 *)arg0 + 0x430)))->set_flags(0x40);
            }
        }
        if (*(u32 *)((s8 *)arg0 + 0x434) == 0) {
            h = (u32)create_particle_emitter(pos, 0x139);
            *(u32 *)((s8 *)arg0 + 0x434) = h;
            if (h != 0) {
                ((TBoss4Type2 *)(*(void **)((s8 *)arg0 + 0x434)))->set_flags(0x40);
            }
        }
    }
    if (*(void **)((s8 *)arg0 + 0x430) != NULL) {
        ((TNowLoading *)(*(void **)((s8 *)arg0 + 0x430)))->copy_pos(pos);
    }
    if (*(void **)((s8 *)arg0 + 0x434) != NULL) {
        ((TNowLoading *)(*(void **)((s8 *)arg0 + 0x434)))->copy_pos(pos);
    }
    if (--this->m_398 < 0) {
        ((TBoss4Type3 *)arg0)->set_action_from_table(1);
    }
}

void TBoss4Type3::enter_bura() {
    void* p = (void*)this; this->m_52c = 0; this->m_398 = 147; }

void TBoss4Type3::advance_bura() {
    void *arg0 = (void *)this;
    s32 temp_r0;

    u16 v = this->m_3ba;
    if ((v != 0xFFFF) && (TBoss4Type3__sub_8005254C(v) == 0)) {
        this->m_3b8 = 0xFFFF;
        this->m_3ba = 0xFFFF;
    }
    if ((s32) this->m_398 == 0) {
        this->m_3bc = (this->m_3bc + 1);
        temp_r0 = this->m_3bc;
        if ((temp_r0 >= 5) || ((temp_r0 >= 2) && (calc_boss4_scale__10TObjPlayerFi(arg0) < 0.5f))) {
            ((s32 (*)(void *, s32))TBoss4Type3__sub_80059F64)(arg0, 9);
            return;
        }
        ((TBoss4Type3 *)arg0)->spawn_random_effect();
    }
}

void TBoss4Type3::update_bura() {
    S_80058380 *o = (S_80058380 *)this;
    if (o->f398 > 0x48) {
        o->f39c = 1.0f - (o->f398 - 0x48) / 75.0f;
    } else {
        o->f39c = 1.0f;
    }
    o->f39c = TBoss4Type3__sub_800524E8(o->f39c);
    ((TBoss4Type3 *)o)->interp_position_between_nodes();
    if (--o->f398 < 0) {
        ((TBoss4Type3 *)o)->set_action_from_table(1);
    }
}

void TBoss4Type3::enter_libera() {
    u8 *arg0 = (u8 *)this;
    TBoss4Type3::create_yutai((void *)arg0, (void *)((void *)1), (void *)((void *) this->m_3ba));
    this->m_52c = 0;
    this->m_398 = 0x62;
}

void TBoss4Type3::advance_libera() {
    S_800582B4 *o = (S_800582B4 *)this;
    if (TBoss4Type3__sub_8005254C(o->f3ba) == 0) {
        o->f3b8 = 0xFFFF;
        o->f3ba = 0xFFFF;
        ((void (*)(void *, s32, s32))TBoss4Type3__sub_800599F4)(o, 0, 2);
        return;
    }
    if (o->f398 == 0) {
        o->f3b8 = 0xFFFF;
        o->f3ba = 0xFFFF;
        ((void (*)(void *, s32, s32))TBoss4Type3__sub_800599F4)(o, 0, 2);
    }
}

void TBoss4Type3::update_libera() {
    S_80058224 *o = (S_80058224 *)this;
    u16 id = o->f3ba;
    if (id == 0xFFFF) {
        ((TBoss4Type3 *)o)->set_action_from_table(1);
        return;
    }
    ((TBoss4Type3 *)o)->turn_toward_player(id);
    if (o->f398 == 0x31) {
        start_pad_rumble_client(0xC0, 0xF, (s16)o->f3ba);
        o->f3b8 = 0xFFFF;
        o->f3ba = 0xFFFF;
    }
    if (--o->f398 < 0) {
        ((TBoss4Type3 *)o)->set_action_from_table(1);
    }
}

void TUnk_80486924::clear_harmful_statuses() {  }

void TUnk_80486924::apply_shock_status() {  }

void TUnk_80486924::apply_movement_ailment(s32) {  }

void TUnk_80486924::apply_confusion_status() {  }

void TUnk_80486924::apply_slow_status() {  }

void TUnk_80486924::apply_paralysis() {  }

void TUnk_80486924::apply_poison_status() {  }
