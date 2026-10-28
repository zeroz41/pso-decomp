#include "types.h"
#include "pso/system/NinjaUtil.h"
#include "pso/TMainTask.h"
#include "pso/unk/text_80141550.h"
#include "pso/TObject.h"
#include "pso/misc/TOTrap.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjChara.h"
#include "pso/object/TObjMotion.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/misc/TOTrapAncient02.h"
#include "pso/misc/TOTrapAncient02R.h"
#include "pso/map/CurrentArea.h"
#include "pso/player/TObjPlayer_80083594.h"
extern "C" void has_flag_0x800__9TObjCharaFv();
extern "C" void test_flag30_512__9TObjCharaFv();
extern "C" void test_flag_1000__9TObjCharaFv();
extern "C" void test_flag_256__9TObjCharaFv();
#include "pso/render/depth_buffer.h"
#include "pso/system/vector.h"

#include "pso/misc/TTecZonde.h"
#include "pso/TParticleCtrl.h"
#include "pso/boss/TObjBoss2Tunnel.h"
#include "pso/misc/TOKeyMachine01.h"

#include "pso/misc/TTecFoie.h"
#include "pso/misc/TTecGiBarta.h"
#include "pso/misc/TTecGiFoie.h"
#include "pso/misc/TTecMegid.h"
#include "pso/object/TObjFish.h"
#include "pso/object/TObjSeabedSuisoBrakable.h"

struct Vec_8017A3C0 { f32 x, y, z; };

struct Dmg_8017A3C0 { s32 type; f32 v; };

struct VB_8017A3C0 { u8 pad[0x18]; };

struct Trap_8017A3C0 : VB_8017A3C0 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20();
    virtual void m21(void *, Dmg_8017A3C0, s32, s32, s32);
    virtual void m22(); virtual void m23();
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27();
    virtual void m28(); virtual void m29(); virtual void m30(); virtual void m31();
    virtual void m32(); virtual void m33(); virtual void m34(); virtual void m35();
    virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39();
    virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43();
    virtual void m44(); virtual void m45(); virtual void m46(); virtual void m47();
    virtual void m48(); virtual void m49(); virtual void m50(); virtual void m51();
    virtual void m52(); virtual void m53(); virtual void m54(); virtual void m55();
    virtual void m56(); virtual void m57(); virtual void m58(); virtual void m59();
    virtual void m60(); virtual void m61(); virtual void m62(); virtual void m63();
    virtual void m64(); virtual void m65(); virtual void m66(); virtual void m67();
    virtual void m68(); virtual void m69(); virtual void m70(); virtual void m71();
    virtual void m72(); virtual void m73(); virtual void m74(); virtual void m75();
    virtual void m76(); virtual void m77(); virtual void m78(); virtual void m79();
    virtual void m80(); virtual void m81(); virtual void m82(); virtual void m83();
    virtual void m84();
    virtual f32 m85(f32);
};

struct Obj_8017A3C0 {
    u8 pad0[0x28];
    s16 f28;
    u8 pad2A[4];
    s16 f2E;
    u8 pad30[8];
    Vec_8017A3C0 pos;
    u8 pad44[0x60 - 0x44];
    s32 angle;
    u8 pad64[0x2A8 - 0x64];
    Obj_8017A3C0 *target;
    u8 pad2AC[0x2FC - 0x2AC];
    Vec_8017A3C0 f2FC;
    u8 pad308[0x326 - 0x308];
    s16 mode;
    s16 sub;
    u8 pad32A[0x334 - 0x32A];
    f32 range;
    f32 f338;
    u16 idx;
    u8 pad33E[0x344 - 0x33E];
    f32 f344;
    f32 f348;
    u8 pad34C[0x35C - 0x34C];
    s32 kind;
    s32 level;
};

extern "C" {
u16 find_nearest_visible_player(void *, int, f32);
s32 get_current_floor(void);
f32 atan2_float(f32 y, f32 x);
void *spawn_particle_effect(void *pos, s32 id);
f32 horizontal_distance_squared(void *, void *);
f32 get_collision_body_radius(void *, s32);
void submit_cursor_candidate(void *, s32);
void *get_player_by_client_id(s32 i);
void play_sound_effect(s32, void *, s32, s32);
void * __nw__7TObjectFUl(int);
void rotate_vector_by_matrix(int, void *, void *);
s32 rotate_matrix_y(int, int);
void subtract_vector(void *, void *);
s32 push_matrix_from(void *src);
s32 pop_matrix();
extern const f64 lbl_80442F38;
extern Vec_8017A3C0 lbl_8050BEE0[];
extern Vec_8017A3C0 lbl_8050BF00[];
extern u8 identity_matrix[];
extern const f32 lbl_805DBA78;
extern const f32 lbl_805DBA80;
extern const f32 lbl_805DBA84;
extern const f32 lbl_805DBA88;
extern const f32 lbl_805DBA8C;
extern const f32 lbl_805DBA90;
extern const f32 lbl_805DBA94;
extern const f32 lbl_805DBA98;
void TOTrapAncient02R__vt79(Obj_8017A3C0 *o);
void vfunc_82__16TOTrapAncient02RFv(void *arg0);
f32 TObjPlayer__sub_8017A1A4(void *, s32);
void send_6x2C_impose_hold(void *, void *, s32, s32, f32);
extern s32 local_client_id;
struct Obj_8017A8B0 {
    u8 pad[0x38];
    f32 pos[3];
    u8 pad44[0x2A8 - 0x44];
    u8 *target;
    u8 pad2ac[0x326 - 0x2AC];
    s16 state;
    u8 pad328[0x334 - 0x328];
    f32 range;
    u8 pad338[0x33C - 0x338];
    u16 idx;
    u8 pad33e[0x364 - 0x33E];
    s32 switchId;
};

struct Vec_8017A988 { f32 x, y, z; };

struct VBase_8017A988 { u8 pad[0x18]; };

struct Obj_8017A988 : VBase_8017A988 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4(s16 *, s32);
    u16 id;
    u8 pad1e[0x38 - 0x1E];
    Vec_8017A988 pos;
    u8 pad44[0x80 - 0x44];
    u32 x80;
    u8 pad84[0x326 - 0x84];
    s16 state;
    u8 pad328[0x344 - 0x328];
    f32 x344;
    f32 x348;
    u8 pad34c[0x368 - 0x34C];
    s32 timer;
};

struct Base_B_8017AC98 { char pad[0x18]; };

struct V_B_8017AC98 : Base_B_8017AC98 {
    virtual void pv15();
    virtual void pv16();
    virtual void pv17();
    virtual void pv18();
    virtual void pv19();
    virtual void pv20();
    virtual void pv21();
    virtual void pv22();
    virtual s32 m8(f32, f32);
};

struct Base_8017B84C_8017AC98 { char pad[0x18]; };

struct VObj_8017B84C_8017AC98 : Base_8017B84C_8017AC98 {
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
};

struct Obj_8017ACA0 {
    u8 pad[0x326];
    s16 state;
    u8 pad328[0x34C - 0x328];
    s32 angle;
};

struct Trap_8017ADC4 {
    u8 pad0[0x2A8];
    void *target;
    u8 pad2AC[0x326 - 0x2AC];
    s16 mode;
    s16 state;
    u8 pad32A[0x33C - 0x32A];
    u16 player;
    u8 pad33E[0x344 - 0x33E];
    f32 h344;
    f32 h348;
    u8 pad34C[0x350 - 0x34C];
    s32 reset;
    s32 timer;
};

struct Base_8017B6D8 { char pad[0x18]; };

struct V_8017B6D8 : Base_8017B6D8 {
    virtual void pv8();
    virtual void pv9();
    virtual void pv10();
    virtual void pv11();
    virtual void pv12();
    virtual void init(void *);
};

struct Trap_8017B6D8 {
    u32 id;
    u8 pad4[0x18 - 0x4];
    void *vt;
    u8 pad1C[0x24 - 0x1C];
    s32 f24;
    u8 pad28[0x30 - 0x28];
    u32 flags;
    void *f34;
    u8 pad38[0x64 - 0x38];
    s32 f64;
    f32 f68;
    u8 pad6C[0x84 - 0x6C];
    s32 f84;
    u8 pad88[0x326 - 0x88];
    s16 mode;
    s16 state;
    u8 pad32A[0x334 - 0x32A];
    f32 range;
    f32 dist;
    u16 player;
    u8 pad33E[0x344 - 0x33E];
    f32 h344;
    f32 h348;
    s32 f34C;
    s32 reset;
    s32 timer;
    s32 f358;
};

u16 get_entity_id(void *);
void obj_setFlags30(void *, u32);
s32 is_split_screen();
void * get_bml_model(void *, int);
void TLobby__sub_8001FE7C(void*, int);
void * load_resource_from_descriptor(void *, int, char *, int, int, int);
s32 check_player_flag1__6TLobbyFv();
s32 free_collision_body_parts(void *);
void init_collision_body_parts(void *, void *, s32);
void *__dt__6TOTrapFv(void *arg0, s16 arg1);
void * TOTrap__ct(void *, void *, void *);
void find_target_player__16TOTrapAncient02RFv(Obj_8017A8B0 *self);
f32 receive_physical_attack__16TOTrapAncient02RFPvf(Obj_8017A988 *self);
void * __dt__16TOTrapAncient02RFv(void *arg0, s16 arg1);
void *TOTrapAncient02R__ct(TOTrapAncient02R *arg0, void *arg1, void *arg2);
void vfunc_84__15TOTrapAncient02Fv(Obj_8017ACA0 *self);
void render__15TOTrapAncient02Fv(void *arg0);
void * __dt__15TOTrapAncient02Fv(void *arg0, s16 arg1);
void * TOTrapAncient02__ct(void *arg0, void *arg1, void *arg2);
void submit_cursor_and_notify__16TOTrapAncient02RFv(void *arg0);
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);
u8 is_current_floor_switch_set(u16);
void __dl__7TObjectFPv(void *);
void scroll_ginja_mesh_uvs(u32, s32, s32, u16, s32);
s32 dispatch_input_to_instance__18TAdEnterPasswordGCFi(void *);
void translate_matrix(u32 arg0, f32 x, f32 y, f32 z);
s32 push_matrix();
s32 post_translate_matrix(void *);
void draw_ginja_model(s32 model);

extern u32 TOTrapAncient02__shared_resource;
extern s32 __vt__15TOTrapAncient02[];
extern u32 lbl_805D31B4;
extern s32 lbl_805D31B8;
extern s32 actor_frame_tick;
extern s32 game_difficulty_selection;
extern s32 lbl_805D5ADC;
extern u32 lbl_805D5AE0;
extern s32 lbl_805D5AE4;
extern const f32 lbl_805DBA7C;
extern const f32 lbl_805DBA9C;
extern const f32 lbl_805DBAA0;
extern const f32 lbl_805DBAA4;

#pragma push
#pragma fp_contract on
void receive_direct_attack__16TOTrapAncient02RFPv19DirectAttackPayloadPvll();
void receive_weapon_special_attack__16TOTrapAncient02RFPvPv();
void vfunc_86__16TOTrapAncient02RFv();
void vfunc_88__16TOTrapAncient02RFv();
void vfunc_89__6TOTrapFv();
void apply_knockback_from_attacker__6TOTrapFPUc();
void vfunc_29__9TObjCharaFv();
void vfunc_74__9TObjCharaFl();
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
void get_name__8TObjBaseFv();
void add_actor_exp__9TObjCharaFl();
void apply_action_hold_status__9TObjCharaFf();
void apply_anti_technique__9TObjCharaFl();
void apply_attack_stat_status__9TObjCharaFPv();
void apply_confusion_status__9TObjCharaFv();
void apply_movement_ailment__9TObjCharaFl();
void apply_object_set_data__8TObjBaseFPv();
void apply_paralysis__9TObjCharaFv();
void apply_poison_status__9TObjCharaFv();
void apply_shock_status__9TObjCharaFv();
void apply_slow_status__9TObjCharaFv();
void apply_switch_attack__9TObjCharaFv();
void classify_actor_view_detail__8TObjBaseFfff();
void clear_all_status_effects__9TObjCharaFv();
void clear_harmful_statuses__9TObjCharaFv();
void consume_timer_field__9TObjCharaFl();
void cure_paralysis__9TObjCharaFv();
void cure_poison_ailment__9TObjCharaFv();
void apply_defense_stat_status__9TObjCharaFPv();
void enemy_spawn_jellen_effect__9TObjCharaFv();
void enemy_spawn_zalure_effect__9TObjCharaFv();
void vfunc_78__9TObjCharaFl();
void vfunc_77__9TObjCharaFv();
void vfunc_76__9TObjCharaFv();
void vfunc_75__9TObjCharaFf();
void get_center__9TObjCharaFv();
void get_actor_level_index__9TObjCharaFv();
void get_pos__9TObjCharaFl();
void is_actor_cadence_frame__9TObjCharaFl();
void is_target_in_attack_range__9TObjCharaFv();
void play_sounds__6TOTrapFv();
void render_shadows__7TObjectFv();
void reset_motion_fields__9TObjCharaFv();
void reset_pose__9TObjCharaFv();
void is_any_player_matching_stat__16TOTrapAncient02RFv();
void try_start_action__16TOTrapAncient02RFll();
void roll_physical_accuracy__16TOTrapAncient02RFPvlf();
void select_melee_contact_body__16TOTrapAncient02RFPvf();
void calc_distance_accuracy_penalty__16TOTrapAncient02RFPvPvPvf();
void vfunc_6__6TOTrapFPsl();
void trigger_switch_attack__9TObjCharaFv(s32 arg0);
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
void run_task__6TOTrapFv();
extern char lbl_80442E70[];
extern char lbl_80442E88[];
extern char lbl_80442EA4[];
extern char lbl_80442EC0[];
extern char lbl_80442ED8[];
extern char lbl_80442EF0[];
extern const char *lbl_805D31A8[];
extern const char *lbl_805D31AC[];
extern const char *lbl_805D31B0[];
struct TrapAncient02ResourceDescriptor {
    const char *bml_filename;
    const char *const *model_filenames;
    const char *const *motion_filenames;
    s16 model_count;
    s16 motion_count;
};
struct TrapAncient02ResourceRecord {
    const char *model_filenames[2];
    TrapAncient02ResourceDescriptor descriptor;
};
struct TrapAncient02CollisionBody {
    f32 local_center[3];
    f32 radius;
    f32 field_10;
    s32 field_14;
    u32 flags;
    f32 world_center[3];
    f32 field_28;
};
typedef char TrapAncient02ResourceDescriptor_size[(sizeof(TrapAncient02ResourceDescriptor) == 0x10) ? 1 : -1];
typedef char TrapAncient02ResourceRecord_size[(sizeof(TrapAncient02ResourceRecord) == 0x18) ? 1 : -1];
typedef char TrapAncient02CollisionBody_size[(sizeof(TrapAncient02CollisionBody) == 0x2C) ? 1 : -1];
TrapAncient02ResourceRecord trap_ancient02_torabasami_resources = {
    { lbl_80442E70, 0 },
    { lbl_80442E88, trap_ancient02_torabasami_resources.model_filenames, lbl_805D31A8, 1, 0 }
};
TrapAncient02ResourceRecord trap_ancient02_ruins_pillar_resources = {
    { lbl_80442EA4, 0 },
    { lbl_80442EC0, trap_ancient02_ruins_pillar_resources.model_filenames, lbl_805D31AC, 1, 0 }
};
TrapAncient02ResourceRecord trap_ancient02_seabed_pillar_resources = {
    { lbl_80442ED8, 0 },
    { lbl_80442EF0, trap_ancient02_seabed_pillar_resources.model_filenames, lbl_805D31B0, 1, 0 }
};
TrapAncient02CollisionBody trap_ancient02_collision_body = {
    { 0.0f, 8.5f, 0.0f }, 2.0f, 0.0f, 0, 0x38003, { 0.0f, 0.0f, 0.0f }, 0.0f
};
s32 __vt__16TOTrapAncient02R[90] = {
    0,
    0,
    (s32)&__dt__16TOTrapAncient02RFv,
    (s32)&run_task__6TOTrapFv,
    (s32)&render__15TOTrapAncient02Fv,
    (s32)&render_shadows__7TObjectFv,
    (s32)&vfunc_6__6TOTrapFPsl,
    (s32)&apply_object_set_data__8TObjBaseFPv,
    (s32)&reset_motion_fields__9TObjCharaFv,
    (s32)&get_center__9TObjCharaFv,
    (s32)&update_object_view_visibility__8TObjBaseFff,
    (s32)&classify_actor_view_detail__8TObjBaseFfff,
    (s32)&get_name__8TObjBaseFv,
    (s32)&interact__14TObjCollidableFl,
    (s32)&add_actor_exp__9TObjCharaFl,
    (s32)&consume_timer_field__9TObjCharaFl,
    (s32)&get_actor_level_index__9TObjCharaFv,
    (s32)&update_actor_ground_y__9TObjCharaFv,
    (s32)&vfunc_18__9TObjCharaFPUc,
    (s32)&is_actor_cadence_frame__9TObjCharaFl,
    (s32)&select_melee_contact_body__16TOTrapAncient02RFPvf,
    (s32)&calc_distance_accuracy_penalty__16TOTrapAncient02RFPvPvPvf,
    (s32)&receive_physical_attack__16TOTrapAncient02RFPvf,
    (s32)&receive_direct_attack__16TOTrapAncient02RFPv19DirectAttackPayloadPvll,
    (s32)&receive_weapon_special_attack__16TOTrapAncient02RFPvPv,
    (s32)&apply_knockback_from_attacker__6TOTrapFPUc,
    (s32)&try_start_action__16TOTrapAncient02RFll,
    (s32)&roll_physical_accuracy__16TOTrapAncient02RFPvlf,
    (s32)&vfunc_28__9TObjCharaFv,
    (s32)&vfunc_29__9TObjCharaFv,
    (s32)&is_target_in_attack_range__9TObjCharaFv,
    (s32)&test_flag_256__9TObjCharaFv,
    (s32)&test_flag30_512__9TObjCharaFv,
    (s32)&has_flag_0x800__9TObjCharaFv,
    (s32)&test_flag_1000__9TObjCharaFv,
    (s32)&update_poison_status__9TObjCharaFv,
    (s32)&update_action_hold_status__9TObjCharaFv,
    (s32)&vfunc_37__9TObjCharaFv,
    (s32)&update_flag30_timer__9TObjCharaFv,
    (s32)&update_movement_status__9TObjCharaFv,
    (s32)&update_shock_clock__9TObjCharaFv,
    (s32)&update_attack_stat_status__9TObjCharaFv,
    (s32)&update_defense_stat_status__9TObjCharaFv,
    (s32)&vfunc_43__9TObjCharaFv,
    (s32)&apply_poison_status__9TObjCharaFv,
    (s32)&apply_paralysis__9TObjCharaFv,
    (s32)&apply_slow_status__9TObjCharaFv,
    (s32)&apply_confusion_status__9TObjCharaFv,
    (s32)&apply_movement_ailment__9TObjCharaFl,
    (s32)&apply_shock_status__9TObjCharaFv,
    (s32)&clear_harmful_statuses__9TObjCharaFv,
    (s32)&apply_attack_stat_status__9TObjCharaFPv,
    (s32)&apply_defense_stat_status__9TObjCharaFPv,
    (s32)&cure_poison_ailment__9TObjCharaFv,
    (s32)&cure_paralysis__9TObjCharaFv,
    (s32)&clear_all_status_effects__9TObjCharaFv,
    (s32)&apply_action_hold_status__9TObjCharaFf,
    (s32)&apply_anti_technique__9TObjCharaFl,
    (s32)&vfunc_58__9TObjCharaFv,
    (s32)&vfunc_59__9TObjCharaFv,
    (s32)&vfunc_60__9TObjCharaFv,
    (s32)&vfunc_61__9TObjCharaFv,
    (s32)&vfunc_62__9TObjCharaFv,
    (s32)&vfunc_63__9TObjCharaFv,
    (s32)&reset_pose__9TObjCharaFv,
    (s32)&get_anim_node_position__9TObjCharaFlP3Vec,
    (s32)&vfunc_66__9TObjCharaFv,
    (s32)&vfunc_67__9TObjCharaFf,
    (s32)&get_pos__9TObjCharaFl,
    (s32)&apply_switch_attack__9TObjCharaFv,
    (s32)&enemy_spawn_jellen_effect__9TObjCharaFv,
    (s32)&trigger_switch_attack__9TObjCharaFv,
    (s32)&enemy_spawn_zalure_effect__9TObjCharaFv,
    (s32)&recalc_stats__9TObjCharaFv,
    (s32)&vfunc_74__9TObjCharaFl,
    (s32)&vfunc_75__9TObjCharaFf,
    (s32)&vfunc_76__9TObjCharaFv,
    (s32)&vfunc_77__9TObjCharaFv,
    (s32)&vfunc_78__9TObjCharaFl,
    (s32)&find_target_player__16TOTrapAncient02RFv,
    (s32)&submit_cursor_and_notify__16TOTrapAncient02RFv,
    (s32)&TOTrapAncient02R__vt79,
    (s32)&vfunc_82__16TOTrapAncient02RFv,
    (s32)&is_any_player_matching_stat__16TOTrapAncient02RFv,
    (s32)&vfunc_84__15TOTrapAncient02Fv,
    (s32)&play_sounds__6TOTrapFv,
    (s32)&vfunc_86__16TOTrapAncient02RFv,
    (s32)&TOTrap::scale_by_table_value,
    (s32)&vfunc_88__16TOTrapAncient02RFv,
    (s32)&vfunc_89__6TOTrapFv
};

void TOTrapAncient02R::calc_trap_count() {
    s32 temp_r4;

    *(s32 *)&this->m_360 = (s32) (this->scale.z + ((lbl_805DBA7C * (f32) game_difficulty_selection) + lbl_805DBA78));
    temp_r4 = *(s32 *)&this->m_360;
    if (temp_r4 < 0) {
        *(s32 *)&this->m_360 = 0;
        return;
    }
    if ((s32) game_difficulty_selection == 3) {
        if (temp_r4 > 0x1D) {
            *(s32 *)&this->m_360 = 0x1D;
        }
    } else if (temp_r4 > 0xE) {
        *(s32 *)&this->m_360 = 0xE;
    }
}
#pragma pop

void TOTrapAncient02R::vfunc_82() {
    f32 temp_f1;
    f32 temp_f1_2;
    set_indexed_flags(0, 1);
    submit_cursor_candidate(this, -1);
    switch (this->phase) {
    case 0:
    case 1:
        this->phase = 2;
    case 2:
        this->timer = (this->timer - 1);
        if ((s32) this->timer < 0) {
            this->phase = 3;
            this->timer = (s32) this->reset;
        }
        break;
    case 3:
        if (lbl_805DBA80 < this->h348) {
            this->h348 -= lbl_805DBA78;
            return;
        }
        this->phase = 4;
        this->h348 = (f32) lbl_805DBA80;
        return;
    case 4:
        if (lbl_805DBA80 < this->h344) {
            this->h344 -= lbl_805DBA78;
            return;
        }
        this->mode = 0;
        this->phase = 0;
        this->h344 = (f32) lbl_805DBA80;
        this->player = 0xFFFF;
        this->target = 0;
        break;
    }
}

#pragma push
#pragma fp_contract on
void TOTrapAncient02R__vt79(Obj_8017A3C0 *o) {
    f32 d;
    s32 ang;
    ((TObjCollidable *)o)->set_indexed_flags(0, 1);
    submit_cursor_candidate(o, -1);
    switch (o->sub) {
    case 0:
        if (o->f344 < lbl_805DBA84) {
            o->f344 += lbl_805DBA78;
        } else {
            o->sub = 1;
            o->f344 = lbl_805DBA84;
        }
        break;
    case 1:
        o->f348 += lbl_805DBA78;
        if (lbl_805DBA88 <= o->f348) {
            o->sub = 2;
            o->f348 = lbl_805DBA88;
        }
        break;
    case 2:
        o->idx = find_nearest_visible_player(o, 0, o->range);
        if (o->idx != 0xFFFF) {
            Obj_8017A3C0 *p = (Obj_8017A3C0 *)get_player_by_client_id(o->idx);
            o->target = p;
            if (o->target != NULL && ((TObjPlayer *)p)->get_field_3e4() == get_current_floor() &&
                (o->target->f2E == o->f2E || o->target->f28 == o->f28 || o->target->f28 == o->f2E)) {
                d = horizontal_distance_squared(&o->target->pos, &o->pos);
                o->f338 = o->range + get_collision_body_radius(o->target, 0);
                if (d < o->f338 * o->f338) {
                    o->mode = 3;
                    o->sub = 2;
                    VecCopy((Vec *)lbl_8050BEE0, (const Vec *)&o->pos);
                    lbl_8050BEE0->y += o->f344 + o->f348;
                    VecCopy((Vec *)lbl_8050BF00, (const Vec *)&o->target->f2FC);
                    subtract_vector(lbl_8050BF00, lbl_8050BEE0);
                    if (((TObjBoss2Tunnel *)lbl_8050BF00)->update_scale() < lbl_805DBA8C) {
                        lbl_8050BF00->x = lbl_8050BF00->y = lbl_805DBA80;
                        lbl_8050BF00->z = lbl_805DBA78;
                        push_matrix_from(identity_matrix);
                        rotate_matrix_y(0, o->angle);
                        rotate_vector_by_matrix(0, lbl_8050BF00, lbl_8050BF00);
                        pop_matrix();
                    }
                    ang = lbl_80442F38 * atan2_float(lbl_8050BF00->x, lbl_8050BF00->z);
                    switch (o->kind) {
                    case 1: {
                        Dmg_8017A3C0 dmg;
                        dmg.type = 3;
                        dmg.v = ((TOTrapAncient02R *)o)->vfunc_87(lbl_805DBA94 * (f32)o->level + lbl_805DBA90);
                        ((Trap_8017A3C0 *)o->target)->m21(o, dmg, 0, -1, -1);
                        spawn_particle_effect(lbl_8050BEE0, 0xB9);
                        spawn_particle_effect(lbl_8050BEE0, 0xBA);
                        {
                            void *t = __nw__7TObjectFUl(0x260);
                            if (t != NULL) {
                                ((TTecZonde *)t)->construct_bolt_effect((u8 *)tl_07, (u8 *)lbl_8050BEE0, (u8 *)lbl_8050BF00, 0x14000000, 0x14, o->range, (f32)lbl_805DBA98);
                            }
                        }
                        play_sound_effect(0x4002A408, lbl_8050BEE0, 0, 0);
                        break;
                    }
                    case 0:
                        TTecFoie::create_ex((void *)o, (void *)lbl_8050BEE0, &o->target->f2FC, (void *)o->level);
                        break;
                    case 2:
                        ((TTecGiBarta *)o)->create_ex((void *)lbl_8050BEE0, (void *)ang, (void *)o->level);
                        break;
                    case 3:
                        TTecMegid::create((s32)o, (s32)lbl_8050BEE0, (s32)&o->target->f2FC, o->level);
                        break;
                    case 4:
                        TTecGiFoie::create((void *)o, (void *)lbl_8050BEE0, (void *)o->level);
                        break;
                    }
                } else {
                    o->idx = 0xFFFF;
                    o->target = NULL;
                }
            } else {
                o->idx = 0xFFFF;
                o->target = NULL;
            }
        } else {
            o->target = NULL;
        }
        if (o->target == NULL) {
            o->sub = 3;
        }
        break;
    case 3:
        if (lbl_805DBA80 < o->f348) {
            o->f348 -= lbl_805DBA78;
        } else {
            o->sub = 4;
            o->f348 = lbl_805DBA80;
        }
        break;
    case 4:
        if (lbl_805DBA80 < o->f344) {
            o->f344 -= lbl_805DBA78;
        } else {
            o->mode = 0;
            o->sub = 0;
            o->f344 = lbl_805DBA80;
            o->idx = 0xFFFF;
            o->target = NULL;
        }
        break;
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
void TOTrapAncient02R::find_target_player() {
    Obj_8017A8B0 *self = (Obj_8017A8B0 *)this;
    ((TObjCollidable *)self)->clear_player_status_flag(0, 1);
    ((TObjChara *)self)->calc_attach_pos();
    if (*(s32 *)&this->m_364 == -1 || is_current_floor_switch_set(*(s32 *)&this->m_364) == 1) {
        this->player = find_nearest_visible_player(self, 0, this->range);
        if (this->player != 0xFFFF) {
            this->target = (u8 *)get_player_by_client_id(this->player);
            if (this->target != NULL) {
                if (horizontal_distance_squared(this->target + 0x38, self->pos) < this->range * this->range) {
                    this->mode = 2;
                }
            } else {
                this->player = 0xFFFF;
                this->target = NULL;
            }
        } else {
            this->target = NULL;
        }
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
f32 TOTrapAncient02R::receive_physical_attack(void *, f32) {
    Obj_8017A988 *self = (Obj_8017A988 *)this;
    s16 msg;
    if (self->id >= 0x4000 && self->x80 != 0) {
        Vec_8017A988 v = self->pos;
        v.y += self->x344 + self->x348;
        spawn_particle_effect(&v, 0x1D0);
        spawn_particle_effect(&v, 1);
        if (--self->timer <= 0) {
            self->timer = 0;
            if (((TObjCollidable *)self)->access_object_saved_state(&msg, 1) != 0) {
                self->state = 4;
                msg = self->state;
                ((TObjCollidable *)self)->send_object_state_update(&msg);
                ((TObjCollidable *)self)->access_object_saved_state(&msg, 0);
                self->m4(&msg, 1);
            }
        }
    }
    return lbl_805DBA80;
}
#pragma pop

#pragma push
#pragma fp_contract on
void *TOTrapAncient02R::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x36C);
    if (o != NULL) {
        o = TOTrapAncient02R__ct((TOTrapAncient02R *)o, tl_05, arg0);
    }
    return o;
}
#pragma pop

#pragma push
#pragma fp_contract on
void *__dt__16TOTrapAncient02RFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__16TOTrapAncient02R;
        ((void (*)(void *, int))__dt__15TOTrapAncient02Fv)(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
#pragma pop

#pragma push
#pragma fp_contract on
#pragma fp_contract on
void *TOTrapAncient02R__ct(TOTrapAncient02R *trap_ancient02_r, void *arg1, void *arg2) {
    ((s32 (*)(void *, void *))TOTrapAncient02__ct)(trap_ancient02_r, arg1);
    *(s32 **)((s8 *)trap_ancient02_r + 0x18) = __vt__16TOTrapAncient02R;
    *(s32 *)((s8 *)trap_ancient02_r + 0) = (s32) lbl_805D31B8;
    trap_ancient02_r->apply_object_set_data(arg2);
    ((TObjPlayer *)trap_ancient02_r)->init_position_vectors();
    ((TObjChara *)trap_ancient02_r)->calc_attach_pos();
    *(s32 *)((s8 *)trap_ancient02_r + 0x34) = (s32) *(s32 *)((s8 *)(*(void **)((s8 *)(*(void * *)&TOTrapAncient02__shared_resource) + 0x42C)) + 8);
    trap_ancient02_r->texlist = (s32) *(s32 *)((s8 *)(*(void **)((s8 *)(*(void * *)&TOTrapAncient02__shared_resource) + 0x42C)) + 0xC);
    trap_ancient02_r->mode = 0;
    trap_ancient02_r->phase = 0;
    trap_ancient02_r->range = lbl_805DBAA0 * trap_ancient02_r->scale.x + lbl_805DBA9C;
    trap_ancient02_r->dist = trap_ancient02_r->range;
    trap_ancient02_r->reset = (s32) (lbl_805DBA9C + (f32) trap_ancient02_r->set_params[0]);
    if (trap_ancient02_r->reset < 0) {
        trap_ancient02_r->reset = 0;
    }
    trap_ancient02_r->timer = trap_ancient02_r->reset;
    trap_ancient02_r->init_trap_object_id();
    trap_ancient02_r->clamp_trap_level_param();
    trap_ancient02_r->calc_trap_count();
    trap_ancient02_r->init_trap_param_clamped();
    trap_ancient02_r->player = 0xFFFF;
    *(s32 *)((s8 *)trap_ancient02_r + 0x2A8) = 0;
    trap_ancient02_r->h348 = lbl_805DBA80;
    trap_ancient02_r->h344 = lbl_805DBA80;
    *(s32 *)&trap_ancient02_r->m_34c = 0;
    if (trap_ancient02_r->rotation_z > 0) {
        *(s32 *)&trap_ancient02_r->m_358 = 1;
    } else {
        *(s32 *)&trap_ancient02_r->m_358 = 0;
    }
    return trap_ancient02_r;
}
#pragma pop

void TOTrapAncient02::vfunc_86() {  }

void TOTrapAncient02::vfunc_88() {  }

void TOTrapAncient02::vfunc_84() {
    Obj_8017ACA0 *self = (Obj_8017ACA0 *)this;
    if (lbl_805D5ADC != actor_frame_tick && lbl_805D5AE0 != 0) {
        lbl_805D5ADC = actor_frame_tick;
        scroll_ginja_mesh_uvs(lbl_805D5AE0, 0, 0xE, lbl_805D5AE4, 1);
    }
    this->m_34c += 0x888;
    switch (this->mode) {
    case 1:
    case 2:
    case 3:
        switch (get_current_area()) {
        case 3:
        case 4:
        case 5:
            play_persistent_sound(0x4461B, (s32)self, (u32)((u8 *)self + 0x38), 0, 0);
            return;
        case 6:
        case 7:
            play_persistent_sound(0x4004C612, (s32)self, (u32)((u8 *)self + 0x38), 0, 0);
            return;
        case 8:
        case 9:
        case 10:
            play_persistent_sound(0x4004C618, (s32)self, (u32)((u8 *)self + 0x38), 0, 0);
            return;
        case 21:
        case 22:
            play_persistent_sound(0x4004C610, (s32)self, (u32)((u8 *)self + 0x38), 0, 0);
        case 0:
            return;
        case 1:
            return;
        case 2:
            return;
        case 11:
            return;
        case 12:
            return;
        case 13:
            return;
        case 14:
            return;
        case 15:
            return;
        case 16:
            return;
        case 17:
            return;
        case 18:
            return;
        case 19:
            return;
        case 20:
            return;
        }
        break;
    }
}

void TOTrapAncient02::vfunc_82() {
    Trap_8017ADC4 *self = (Trap_8017ADC4 *)this;
    s32 p;
    submit_cursor_candidate(self, -1);
    switch (self->state) {
    case 0:
    case 1:
        self->state = 2;
    case 2:
        if (self->target != NULL) {
            obj_setFlags30(self->target, 0x200);
            ((TObjEnemy *)(self->target))->sub_8002AE64();
            ((TObjEnemy *)(self->target))->sub_800A7798(lbl_805DBA78);
            self->timer--;
            if (self->timer < 0) {
                self->state = 3;
                self->timer = self->reset;
                if (self->target != NULL && local_client_id == get_entity_id(self->target)) {
                    p = (s32)get_player_by_client_id(local_client_id);
                    if (p != 0 && check_player_flag1__6TLobbyFv() != 0) {
                        TObjPlayer::send_code_45_1(p);
                    }
                }
            }
        } else {
            self->state = 3;
            self->timer = self->reset;
        }
        break;
    case 3:
        if (lbl_805DBA80 < self->h348) {
            self->h348 -= lbl_805DBA78;
        } else {
            self->state = 4;
            self->h348 = lbl_805DBA80;
        }
        break;
    case 4:
        if (lbl_805DBA80 < self->h344) {
            self->h344 -= lbl_805DBA78;
        } else {
            self->mode = 0;
            self->state = 0;
            self->h344 = lbl_805DBA80;
            self->player = 0xFFFF;
            self->target = NULL;
        }
        break;
    }
}
}
void setup_particle_tev(s32 arg0);

void TOTrapAncient02::vfunc_81() {
    TOTrapAncient02 *self = this;
    void *p;
    f32 d;
    submit_cursor_candidate(self, -1);
    switch (self->phase) {
    case 0:
        if (self->h344 < lbl_805DBA84) {
            self->h344 += lbl_805DBA78;
        } else {
            self->phase = 1;
            self->h344 = lbl_805DBA84;
        }
        break;
    case 1:
        self->h348 += lbl_805DBA78;
        if (lbl_805DBA88 <= self->h348) {
            self->phase = 2;
            self->h348 = lbl_805DBA88;
        }
        break;
    case 2:
        self->player = find_nearest_visible_player(self, 0, self->range);
        if (self->player != 0xFFFF) {
            p = (void *)get_player_by_client_id((self->player));
            self->target = (u8 *)p;
            if (self->target != NULL) {
                d = horizontal_distance_squared((u8 *)self->target + 0x38, &self->position);
                self->dist = self->range - TObjPlayer__sub_8017A1A4(p, 0);
                if (d < self->dist * self->dist) {
                    if (self->player == local_client_id) {
                        send_6x2C_impose_hold(p, &self->position, self->timer, 0, self->dist);
                    }
                    self->mode = 3;
                    self->phase = 2;
                } else {
                    self->player = 0xFFFF;
                    self->target = NULL;
                }
            }
        } else {
            self->target = NULL;
        }
        if (self->target == NULL) {
            self->phase = 3;
        }
        break;
    case 3:
        if (lbl_805DBA80 < self->h348) {
            self->h348 -= lbl_805DBA78;
        } else {
            self->phase = 4;
            self->h348 = lbl_805DBA80;
        }
        break;
    case 4:
        if (lbl_805DBA80 < self->h344) {
            self->h344 -= lbl_805DBA78;
        } else {
            self->mode = 0;
            self->phase = 0;
            self->h344 = lbl_805DBA80;
            self->player = 0xFFFF;
            self->target = NULL;
        }
        break;
    }
}

void TOTrapAncient02::render_particle_chain() {
    u8 *temp_r31;
    u8 *temp_r31_2;
    u8 *temp_r31_3;
    u8 *temp_r31_4;

    push_matrix();
    post_translate_matrix((u8 *)&this->position);
    rotate_matrix_y(0, this->rotation_y);
    temp_r31 = (unsigned char *) (this->model);
    translate_matrix(0, (f32) (*(f32 *)((s8 *)temp_r31 + 8)), (f32) (*(f32 *)((s8 *)temp_r31 + 0xC) + this->h344), (f32) (*(f32 *)((s8 *)temp_r31 + 0x10)));
    setup_particle_tev(0);
    TObjFish::set_global_param(this->texlist);
    load_projection_tex_matrix(0x38E);
    draw_ginja_model((*(s32 *)((s8 *)temp_r31 + 4)));
    reset_particle_tev();
    push_matrix();
    temp_r31_2 = (unsigned char *) (*(void **)((s8 *)temp_r31 + 0x2C));
    translate_matrix(0, (f32) (*(f32 *)((s8 *)temp_r31_2 + 8)), (f32) (*(f32 *)((s8 *)temp_r31_2 + 0xC) + this->h348), (f32) (*(f32 *)((s8 *)temp_r31_2 + 0x10)));
    setup_particle_tev(0);
    TObjFish::set_global_param(this->texlist);
    load_projection_tex_matrix(0x38E);
    draw_ginja_model((*(s32 *)((s8 *)temp_r31_2 + 4)));
    reset_particle_tev();
    TParticleCtrl::begin_effect_render();
    push_matrix();
    temp_r31_3 = (unsigned char *) (*(void **)((s8 *)temp_r31_2 + 0x2C));
    post_translate_matrix(temp_r31_3 + 8);
    setup_particle_tev(1);
    TObjFish::set_global_param(this->texlist);
    load_projection_tex_matrix(0x38E);
    draw_ginja_model((*(s32 *)((s8 *)temp_r31_3 + 4)));
    reset_particle_tev();
    pop_matrix();
    push_matrix();
    temp_r31_4 = (unsigned char *) (*(void **)((s8 *)temp_r31_3 + 0x30));
    post_translate_matrix(temp_r31_4 + 8);
    rotate_matrix_y(0, this->m_34c);
    setup_particle_tev(0);
    TObjFish::set_global_param(this->texlist);
    load_projection_tex_matrix(0x38E);
    draw_ginja_model((*(s32 *)((s8 *)temp_r31_4 + 4)));
    reset_particle_tev();
    pop_matrix();
    TParticleCtrl::end_effect_render();
    pop_matrix();
    pop_matrix();
}

void TOTrapAncient02::draw_effect_chain() {
    u8 *temp_r31;
    u8 *temp_r31_2;
    u8 *temp_r31_3;
    u8 *temp_r31_4;

    push_matrix();
    TObjFish::set_global_param(this->texlist);
    post_translate_matrix((u8 *)&this->position);
    rotate_matrix_y(0, this->rotation_y);
    temp_r31 = (unsigned char *) (this->model);
    translate_matrix(0, (f32) (*(f32 *)((s8 *)temp_r31 + 8)), (f32) (*(f32 *)((s8 *)temp_r31 + 0xC) + this->h344), (f32) (*(f32 *)((s8 *)temp_r31 + 0x10)));
    draw_ginja_model((*(s32 *)((s8 *)temp_r31 + 4)));
    push_matrix();
    temp_r31_2 = (unsigned char *) (*(void **)((s8 *)temp_r31 + 0x2C));
    translate_matrix(0, (f32) (*(f32 *)((s8 *)temp_r31_2 + 8)), (f32) (*(f32 *)((s8 *)temp_r31_2 + 0xC) + this->h348), (f32) (*(f32 *)((s8 *)temp_r31_2 + 0x10)));
    draw_ginja_model((*(s32 *)((s8 *)temp_r31_2 + 4)));
    TParticleCtrl::begin_effect_render();
    push_matrix();
    temp_r31_3 = (unsigned char *) (*(void **)((s8 *)temp_r31_2 + 0x2C));
    post_translate_matrix(temp_r31_3 + 8);
    draw_ginja_model((*(s32 *)((s8 *)temp_r31_3 + 4)));
    pop_matrix();
    push_matrix();
    temp_r31_4 = (unsigned char *) (*(void **)((s8 *)temp_r31_3 + 0x30));
    post_translate_matrix(temp_r31_4 + 8);
    rotate_matrix_y(0, this->m_34c);
    draw_ginja_model((*(s32 *)((s8 *)temp_r31_4 + 4)));
    pop_matrix();
    TParticleCtrl::end_effect_render();
    pop_matrix();
    pop_matrix();
}

void TOTrapAncient02::render() {
    if (TMainTask::get_render_pass() != 1) {
        this->m_340 = ((V_B_8017AC98 *) this)->m8(lbl_805DBAA4, lbl_805DBA94);
        if (((s32) this->m_340 == 1) && (((s32) this->m_358 == 0) || (is_split_screen() != 0) || (dispatch_input_to_instance__18TAdEnterPasswordGCFi(this) == 0))) {
            set_depth_buffer_settings_id(3);
            if ((s32) this->m_358 != 0) {
                this->render_particle_chain();
            } else {
                this->draw_effect_chain();
            }
            restore_draw_list_mask();
        }
    }
}

void *TOTrapAncient02::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x35C);
    if (o != NULL) {
        o = TOTrapAncient02__ct(o, tl_05, arg0);
    }
    return o;
}

void TOTrapAncient02::destroy_instance() {
    if ((u32) TOTrapAncient02__shared_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TOTrapAncient02__shared_resource, 1);
        TOTrapAncient02__shared_resource = 0U;
    }
}

void TOTrapAncient02::load_resources() {
    char *base = (char *)&trap_ancient02_torabasami_resources;
    void *obj;
    switch (get_current_area()) {
    case 0x13:
    case 0x14:
        obj = ::operator new(0x440);
        if (obj != 0) {
            obj = load_resource_from_descriptor(obj, 1, base + 0x20, 0, 0, 0);
        }
        TOTrapAncient02__shared_resource = (u32) obj;
        lbl_805D5AE0 = (u32)find_object_node((NJS_OBJECT *)get_bml_model(obj, 0), 2)->model;
        lbl_805D5AE4 = 2;
        lbl_805D5ADC = 0;
        break;
    case 0x17:
    case 0x18:
    case 0x19:
    case 0x1A:
    case 0x1B:
    case 0x1C:
    case 0x1D:
    case 0x22:
    case 0x23:
        obj = ::operator new(0x440);
        if (obj != 0) {
            obj = load_resource_from_descriptor(obj, 1, base + 0x38, 0, 0, 0);
        }
        TOTrapAncient02__shared_resource = (u32) obj;
        lbl_805D5AE0 = (u32)find_object_node((NJS_OBJECT *)get_bml_model(obj, 0), 2)->model;
        lbl_805D5AE4 = 1;
        lbl_805D5ADC = 0;
        break;
    default:
        obj = ::operator new(0x440);
        if (obj != 0) {
            obj = load_resource_from_descriptor(obj, 1, base + 8, 0, 0, 0);
        }
        TOTrapAncient02__shared_resource = (u32) obj;
        lbl_805D5AE0 = *(u32 *)(*(u8 **)(*(u8 **)(*(u8 **)(*(u8 **)((u8 *)obj + 0x42C) + 8) + 0x2C) + 0x2C) + 4);
        lbl_805D5AE4 = 1;
        lbl_805D5ADC = 0;
        break;
    }
}

void *__dt__15TOTrapAncient02Fv(void *trap, s16 arg1) {
    if (trap != NULL) {
        *(s32 **)((s8 *)trap + 0x18) = __vt__15TOTrapAncient02;
        ((TObjCollidable *)trap)->unregister_object_by_id();
        free_collision_body_parts(trap);
        __dt__6TOTrapFv(trap, 0);
        if (arg1 > 0) {
            ((s32 (*)(void *))__dl__7TObjectFPv)(trap);
        }
    }
    return trap;
}

#pragma push
#pragma fp_contract on
void *TOTrapAncient02__ct(void *arg0, void *arg1, void *arg2) {
    TOTrap__ct(((Trap_8017B6D8 *)arg0), arg1, arg2);
    ((Trap_8017B6D8 *)arg0)->vt = (void *)__vt__15TOTrapAncient02;
    ((Trap_8017B6D8 *)arg0)->id = lbl_805D31B4;
    ((V_8017B6D8 *)((Trap_8017B6D8 *)arg0))->init(arg2);
    ((TObjPlayer *)arg0)->init_position_vectors();
    ((TObjChara *)arg0)->calc_attach_pos();
    ((Trap_8017B6D8 *)arg0)->f34 = *(void **)(*(u8 **)(TOTrapAncient02__shared_resource + 0x42C) + 8);
    ((Trap_8017B6D8 *)arg0)->f24 = *(s32 *)(*(u8 **)(TOTrapAncient02__shared_resource + 0x42C) + 0xC);
    ((Trap_8017B6D8 *)arg0)->mode = 0;
    ((Trap_8017B6D8 *)arg0)->state = 0;
    ((Trap_8017B6D8 *)arg0)->range = lbl_805DBAA0 * ((Trap_8017B6D8 *)arg0)->f68 + lbl_805DBA9C;
    ((Trap_8017B6D8 *)arg0)->dist = ((Trap_8017B6D8 *)arg0)->range;
    ((Trap_8017B6D8 *)arg0)->reset = lbl_805DBA9C + (f32)((Trap_8017B6D8 *)arg0)->f84;
    if (((Trap_8017B6D8 *)arg0)->reset < 0) {
        ((Trap_8017B6D8 *)arg0)->reset = 0;
    }
    ((Trap_8017B6D8 *)arg0)->timer = ((Trap_8017B6D8 *)arg0)->reset;
    ((Trap_8017B6D8 *)arg0)->player = 0xFFFF;
    init_collision_body_parts(((Trap_8017B6D8 *)arg0), (void *)&trap_ancient02_collision_body, 1);
    ((TObjCollidable *)arg0)->refresh_collision_body_centers();
    ((Trap_8017B6D8 *)arg0)->flags |= 0x60000000;
    ((TObjPlayer *)arg0)->register_object_by_id();
    ((Trap_8017B6D8 *)arg0)->h348 = lbl_805DBA80;
    ((Trap_8017B6D8 *)arg0)->h344 = lbl_805DBA80;
    ((Trap_8017B6D8 *)arg0)->f34C = 0;
    if (((Trap_8017B6D8 *)arg0)->f64 > 0) {
        ((Trap_8017B6D8 *)arg0)->f358 = 1;
    } else {
        ((Trap_8017B6D8 *)arg0)->f358 = 0;
    }
    return ((Trap_8017B6D8 *)arg0);
}
#pragma pop

void TOTrapAncient02R::submit_cursor_and_notify() {
    struct VObj_8017B84C_8017AC98 *o = (struct VObj_8017B84C_8017AC98 *)this;
    o->m77();
}
