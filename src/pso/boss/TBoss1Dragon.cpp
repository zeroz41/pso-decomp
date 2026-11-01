#include "pso/animation/MotionContext.h"
#include "pso/math/FloatRounding.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/TObjEneRe7Berura_803E4CE0.h"
#include "pso/protocol/protocol_types.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/enemy/EnemyStateEvent.h"
#include "pso/enemy/TObjEneMe3ShinowaReal_8002ADD8.h"
#include "pso/enemy/TObjEneMe3ShinowaReal.h"
#include "pso/misc/TWindowKeyBoardHard.h"
#include "pso/misc/TLobby_801E43E4.h"
#include "pso/system/byteswap.h"
#include "pso/boss/TBoss1Dragon.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/boss/TObjBoss1Rock.h"
#include "pso/system/vector.h"
#include "pso/enemy/TObjEneEpsilon.h"
#include "pso/enemy/TObjEneDD_ST.h"
#include "pso/player/TObjChara.h"
#include "pso/misc/MaterialColorFade.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/TObjMotion.h"
#include "pso/boss/TUnk_80481B34.h"
extern "C" void has_flag_0x800__9TObjCharaFv();
extern "C" void test_flag30_512__9TObjCharaFv();
extern "C" void test_flag_1000__9TObjCharaFv();
extern "C" void test_flag_256__9TObjCharaFv();
#include "pso/object/TObjMotion.h"
#include "pso/boss/TObjBoss1Crater.h"
#include "pso/misc/TMainCursor.h"
#include "pso/TObject.h"
#include "pso/TParticleCtrl.h"
#include "pso/boss/TBoss1DragonEffTail.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/boss/TBoss4DarkFalz.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/boss/TBoss8Dragon.h"

#include "pso/boss/TObjBoss2Tunnel.h"

#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/misc/RenderFadeState.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TNowLoading.h"
#include "pso/misc/TWindowCtrl.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TUnk_804928CC.h"
extern "C" void apply_paralysis__12TBoss1DragonFv();
extern "C" void apply_confusion_status__12TBoss1DragonFv();
extern "C" void apply_movement_ailment__12TBoss1DragonFl();
extern "C" void apply_shock_status__12TBoss1DragonFv();

extern "C" {

void TObjLight__sub_801337F8(s32);
s32 scale_matrix(s32, f32, f32, f32);
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();
s32 pop_matrix();
s32 post_translate_matrix(void *);
void draw_model_motion(void *, void *, f32);
extern s32 current_scene_light;
extern s32 model_render_flags;

}

struct ByteBlock_C { u8 bytes[0xc]; };

struct Obj_80021260;
#include "types.h"
#include "pso/system/PadRumble.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct ByteBlock_8 { u8 bytes[0x8]; };

#include <dolphin/mtx.h>
#include <stddef.h>

struct RecoveredGlobal_8002116C_lbl_80434F20 { s32 value; u8 remaining[0x88]; };

struct DragonCaptureVectors { DragonModelVector vectors[3]; };
struct DragonModelState { s32 state[2]; f32 params[4]; };

struct RecoveredGlobal_80027AAC_lbl_80434EB4 {
    s32 value;
    u8 remaining[0x10];
};

struct RecoveredGlobal_8002826C_lbl_80480D00 {
    s32 value;
    u8 remaining[0x44];
};

struct RecoveredGlobal_8002826C_lbl_80480D48 {
    s32 value;
    u8 remaining[0x23C];
};

struct RecoveredFields_8002826C_arg0 {
    u8 unknown_0[0x67C];
    s32 field_67C;
    u8 unknown_680[0xE0];
    s32 field_760;
};

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

struct ByteBlock_10 { u8 bytes[0x10]; };

struct RecoveredGlobal_800646F0_lbl_80437944 {
    s32 value;
    u8 remaining[0x10];
};

struct RecoveredGlobal_800646F0_lbl_804FF5B4 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_8006435C_lbl_80437D2C {
    s32 value;
    u8 remaining[0x10];
};

struct RecoveredGlobal_80064CFC_lbl_80487848 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_80064CFC_lbl_804FF5A0 {
    s32 value;
    u8 remaining[0x10];
};

struct RecoveredGlobal_80065EA0_lbl_80487CCC {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_80065EA0_lbl_80487CD8 {
    s32 value;
    u8 remaining[0x350];
};

struct RecoveredGlobal_80065DB4_lbl_804FF5B4 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_80065F08_lbl_80437938 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_8002885C_TBoss1Dragon__data_804FE168 {
    s32 value;
    u8 remaining[0x10];
};

struct RecoveredGlobal_80027634_TBoss1Dragon__data_804FE17C {
    u8 * value;
    u8 remaining[0x8];
};

struct Stack_80027E78 {
    s32 sp8;
    u8 pad_C[0x4];
    f32 sp10;
    u8 trailing_storage[0x8];
};

struct RecoveredGlobal_80027E78_lbl_80434E8C {
    s32 value;
    u8 remaining[0x10];
};

struct RecoveredGlobal_80027E78_TBoss1Dragon__data_804FE17C {
    u8 * value;
    u8 remaining[0x8];
};

struct ByteBlock_14
{
  u8 bytes[0x14];
};

struct RecoveredGlobal_80027650_lbl_80435338
{
  s32 value;
  u8 remaining[0x10];
};

struct RecoveredGlobal_80027650_TBoss1Dragon__data_804FE17C
{
  u8 *value;
  u8 remaining[0x8];
};

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct RecoveredGlobal_80027710_lbl_80435324 {
    s32 value;
    u8 remaining[0x10];
};

struct RecoveredGlobal_80027710_TBoss1Dragon__data_804FE17C {
    f32 * value;
    u8 remaining[0x8];
};

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct RecoveredGlobal_800277D8_lbl_80435310 {
    s32 value;
    u8 remaining[0x10];
};

struct RecoveredGlobal_800277D8_TBoss1Dragon__data_804FE17C {
    u8 * value;
    u8 remaining[0x8];
};

struct pkt_80028530 {
    u8 hdr[2];
    u16 target_id;
    s16 state;
    s16 cursor;
    s32 extra;
    f32 x;
    f32 z;
};

struct dragon_80028530 {
    u8 pad0[0x1C];
    u16 target_id;
    u8 pad1[0x326 - 0x1E];
    s16 mode;
    u8 pad2[0x38C - 0x328];
    u16 extra;
    u8 pad3[0x67C - 0x38E];
    s32 sequence_cursor;
    u8 pad4[0x690 - 0x680];
    f32 outgoing_x;
    f32 outgoing_z;
};

struct Stack_800212D8 {
    s32 sp8;
    f32 spC;
    u8 trailing_storage[0x4];
};
struct Vec_800292C0 { f32 x, y, z; };

struct Vec_80029238 { f32 x, y, z; };

struct Obj_80027320 {
    u8 pad0[0x6E4];
    u8 *f6e4;
    u8 pad1[0x760 - 0x6E8];
    s32 f760;
    u16 f764;
    u8 pad2[2];
    s32 f768;
};

struct Obj_80027010 { u8 pad0[0x38]; f32 f38; u8 pad3C[4]; f32 f40; };

struct Vec_80027010 { f32 x, y, z; };

typedef struct Dragon_80028EA8 {
    u8 pad0[0x6A0];
    s32 count;
    u8 pad6A4[4];
    f32 slots[12];
} Dragon_80028EA8;

typedef struct Vec_80028EA8 {
    f32 x, y, z;
} Vec_80028EA8;

struct Vec_80028CA8 { f32 x, y, z; };

struct Obj_80029C78 {
    u8 pad0[0x18];
    void *vt;
    u8 pad1c[0x3C4 - 0x1C];
    u8 f3C4[0x5F4 - 0x3C4];
    u8 f5F4[0x618 - 0x5F4];
    u8 f618[0x684 - 0x618];
    TObject *f684;
    void *f688;
    TObject *f68C;
    u8 pad690[0x6D8 - 0x690];
    void *f6D8;
    u8 pad6DC[0x6E8 - 0x6DC];
    u8 f6E8[0x774 - 0x6E8];
    TObject *f774;
};

struct Vec_800278A8 { f32 x, y, z; };

struct Params_800278A8 { s32 a; s32 b; f32 scale; s32 c; s32 d; };

struct Vec_80029408 { f32 x, y, z; };

struct Coll_80029408 { Vec_80029408 local; f32 radius; u32 type, attribute, flags; Vec_80029408 world; f32 defense; };

struct Input_80022740 { u8 pad0[8]; s32 flags; u8 padC[0x24 - 0xC]; f32 f24; };
struct Input_80022C38 { u8 pad0[8]; s32 flags; u8 padC[0x24 - 0xC]; f32 f24; };

struct Obj_800288EC {
    u8 pad0[0x60];
    s32 f60;
    u8 pad1[0x658 - 0x64];
    s32 f658;
    u8 pad65C[0x660 - 0x65C];
    s32 f660;
    f32 f664, f668, f66C, f670, f674, f678;
};

struct Vec_80021490 { f32 x, y, z; };

struct DragonEffectRotation { s32 x, y, z; };

struct Tbl_80021490 { u8 pad0[8]; s32 e8; u8 padC[0x14 - 0xC]; s32 e14; u8 pad18[4]; s32 e1C; };

struct Dragon_80021490 {
    u8 pad0[0x38];
    Vec_80021490 pos;
    u8 pad44[0x5C - 0x44];
    s32 rot[3];
    u8 pad68[0xB8 - 0x68];
    s16 action;
    u8 padBA[0xC0 - 0xBA];
    f32 frame;
    u8 padC4[0x40C - 0xC4];
    Vec_80021490 fxpos;
    Vec_80021490 fxdir;
    u8 pad424[0x5D8 - 0x424];
    f32 altitude;
    f32 offset;
    f32 base;
    u8 pad5E4[0x778 - 0x5E4];
    Tbl_80021490 *tbl;
    u8 pad77C[0x864 - 0x77C];
    s32 phase;
    s32 ticks;
    s32 stage;
    s32 demo_active;
    u8 pad874[0x8AC - 0x874];
    u32 mouth;
};

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct Cam_80022EE0 { u8 mode; u8 sub; s16 c; f32 d; f32 e; };

struct Eff_80022EE0 { u32 w[5]; };

struct Vec_80022EE0 { f32 x, y, z; };

struct Vec_80028F9C { f32 x, y, z; };

struct Player_80028F9C { u8 pad0[0x38]; Vec_80028F9C pos; u8 pad44[0x32C - 0x44]; s16 hp; };

struct Glob_800267B8 { u8 *value; u8 remaining[0x8]; };

struct Vec_80020B54 { f32 x, y, z; };

struct Color_80020B54 { f32 a, r, g, b; };

struct Vec_80029DE4 { f32 x, y, z; };
struct E1C_80029DE4 { u8 b[0x1C]; };
struct Obj_80029DE4 {
    u8 p0[0x38];
    Vec_80029DE4 pos;
    u8 p1[0x3E8 - 0x44];
    Vec_80029DE4 v3[3];
    u8 p2[0x430 - 0x40C];
    Vec_80029DE4 v22[0x22];
    u8 p3[0x6A8 - 0x5C8];
    f32 f[12];
    u8 p4[0x6E8 - 0x6D8];
    E1C_80029DE4 e[4];
};
extern f32 lbl_805D4AF8;
extern f32 boss1_dragon_gravity;
extern const f32 lbl_805D4B40;
extern s32 tl_05;

extern const f32 lbl_805D8028;
extern const f32 lbl_805D802C;
extern const f32 lbl_805D8030;
extern const f32 lbl_805D8034;
extern const f32 lbl_805D8038;
extern const f32 lbl_805D803C;
extern const f32 lbl_805D8044;
extern const f32 lbl_805D80AC;
extern const f32 lbl_805D8048;
extern const f32 lbl_805D804C;
extern const f32 lbl_805D8050;
extern const f32 lbl_805D8054;
extern const f32 lbl_805D8058;
extern const f32 lbl_805D805C;
extern const f32 lbl_805D8060;
extern const f32 lbl_805D80C0;
extern const f32 lbl_805D80C4;
extern const f32 lbl_805D80C8;
extern const f32 lbl_805D80CC;
extern const f32 lbl_805D80D0;
extern const f32 lbl_805D80D4;
extern const f32 lbl_805D80D8;
extern const f32 lbl_805D80DC;
extern const f32 lbl_805D80E0;
extern const f32 lbl_805D80E4;
extern const f32 lbl_805D80E8;
extern const f32 lbl_805D80EC;
extern const f32 lbl_805D80F0;
extern const f32 lbl_805D80F4;
extern const f32 lbl_805D80F8;
extern const f32 lbl_805D80FC;
extern const f32 lbl_805D8100;
extern "C" {
f32 sample_acceleration_curve(void *, f32);
s32 init_acceleration_curve(void *, f32, f32, f32, f32);
s32 get_random_scaled__9TObjEneDDFv(void *);
void *spawn_continuous_particle_effect_with_flags(void *parent, s32 idx, s32 flags);

void rotate_vec_xz(void *, void *, s32);
u8 *TBoss1DragonEffBullet__ct(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
void prepare_flight_destination__12TBoss1DragonFPv(u8 *arg0);

extern const f32 lbl_805D800C;
s32 get_current_floor();
u32 get_player_by_client_id(s32);
u32 load_enemy_bml_resource(u8 *);
u32 load_enemy_bml_resource_named(u8 *, u8 *);
extern u8 lbl_80435394[];
extern s32 lbl_805D2648;
extern s32 lbl_805D264C;
extern s32 lbl_805D4B24;
extern s32 TLobby__designated_client_id;
s32 clearState__12TBoss1DragonFv(void *);
s32 isV2Mode__12TBoss1DragonFv(void);
u8 *__nw__7TObjectFUl(s32);
u8 *__ct__16TBoss1DragonDemoFv(u8 *arg0, s32 arg1, s32 arg2, f32 farg0);
s32 play_sound_effect(s32, s32, s32, s32);
void *spawn_particle_effect_with_flags(void *pos, s32 id, s32 flags);
s32 play_cue_stream_file(void *, int);
u32 spawn_particle_effect_with_rotation(void *, void *, void *, int);
s32 queue_destruction__7TObjectFv(void *);
extern s32 tl_01;
extern const u8 boss1_dragon_death_cue_filename[];

s32 VecCopy__FP3VecPC3Vec(s32, s32);
void TBoss1Dragon__sub_800275BC(u8 *arg0, s32 arg1, u8 *arg2, s32 arg3);
s32 beginHeightTransition__12TBoss1DragonFv(void *);
s32 restore_player_cameras(void);
s32 activate_camera_mode(s32);
s32 set_scripted_camera_pose(void *, void *, void *);
void rotate_xz_pair_by_angle(f32 *arg0, f32 *arg1, s32 arg2);
s32 reset_hp__9TObjEneDDFPUcPUcPUc(void *, int, int, int);
s32 vec3_add_to(void *, void *);
extern u8 TBoss1Dragon__head_fall_effect_params[];
extern u8 lbl_80434EC8[];
extern u8 lbl_80434ED4[];
extern s32 TBoss1Dragon__part_hp_stats[5];

void update_death_state__12TBoss1DragonFv(u8 *arg0, u32 arg1);
f32 newton_sqrtf(f32);
s32 is_valid_target__9TObjEneDDFv(void *);
f32 horizontal_distance_squared(void *, void *);

extern const f32 lbl_805D80B8;
s32 next_sequence_action__12TBoss1DragonFv(void *);
s32 restoreTargetPosition__12TBoss1DragonFv();
void send_state_sync__12TBoss1DragonFPv(struct dragon_80028530 *s);
void TBoss1Dragon__sub_80028BE0(u8 *arg0);
s32 is_destination_ahead__12TBoss1DragonFPv(u8 *s);
void calc_target_vector__12TBoss1DragonFPv(u8 *arg0);
void TObjEneEpsilon__sub_800B9384(u8 *arg0, s32 arg1, f32 farg0);
s32 enemy_validate_retained_target();
s32 update_velocity__9TObjEneDDFv(void *);
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);

extern s32 TBoss1Dragon__data_804FE17C[3];

extern const f32 lbl_805D8078;
extern const f32 lbl_805D807C;
extern const f32 lbl_805D8080;
extern const f32 lbl_805D8084;
s32 is_split_screen();
s32 check_parts_visible__12TBoss1DragonFiPv(s32 arg0, Obj_80021260 *arg1);
s32 is_sphere_visible__12TBoss1DragonFf(f32 farg0);
s32 get_camera_mode__11TCameraCtrlFv();
s32 TBoss1Dragon__sub_8002B108(s32, s32);
f32 normalize_vector_xz__FP3Vec(void *, f32, f32);
u8 *find_entity_by_id(s32);
s32 defer_render__7TObjectFv(void *);
s32 rotate_matrix_z(s32, s32);
void subtract_vector(void *, void *);
s32 translate_matrix(s32, f32, f32, f32);
s32 rotate_matrix_x(s32, s32);
void set_material_alpha_compare_reference(s32);
void set_chunk_material_override_pair(s32, s32);
void render__12TBoss1DragonFv(u8 *arg0);
}
void direction_to_rotation_xz(u8 *arg0, s32 *arg1, s32 *arg2);
void dragon_capture_node_points(void);
extern Color_80020B54 dragon_boss1_render_color;
extern u8 lbl_804FE1D0[0xC];
extern u8 lbl_804FE1DC[0xC];
extern u32 TBoss1Dragon__data_805D4B08;
extern s32 TBoss1Dragon__data_805D4B0C;
extern s32 TBoss1Dragon__data_805D4B14;
extern s32 TBoss1Dragon__data_805D4B18;
extern s32 TBoss1Dragon__data_805D4B1C;
extern s32 TBoss1Dragon__data_805D4B20;
extern f32 boss1_dragon_visibility_distance;
extern u8 *camera_ctrl_instance;
extern s32 saved_model_render_flags;

struct G_80025C68 { u8 *value; u8 remaining[0x8]; };
struct Vec_80024314 { f32 x, y, z; };
struct Vec_80025710 { f32 x; f32 y; f32 z; };
extern "C" {
f32 vec3_dot(void *, void *);

void play_se_at_pos__12TBoss1DragonFii(s32 arg0, s32 arg1);
extern const f32 TBoss1Dragon__data_805D8040;
void TBoss1Dragon__sub_80028B28(u8 *arg0);
s32 set_frames__15ProtectionTimerFl(void *, s32);
extern const f32 lbl_805D8090;
f32 calc_burrow_speed__12TBoss1DragonFPv(void *arg0);
extern const f32 lbl_805D80B0;
void TBoss1Dragon__sub_80027A80(u8 *arg0, u8 *arg1);
s32 enemy_set_target_id(void *, u16);
u8 *TBoss1Dragon__ct(u8 *, void *, void *);
extern s32 tl_04;
extern s32 tl_02;
extern const f32 lbl_805D80A8;
s32 is_primary_sequence__12TBoss1DragonFv(void *);
void project_sound_origin_from_camera(s32 arg0, u8 *arg1, f32 farg0);
s32 query_teammate_state__9TObjEneDDFv();
s32 is_main_phase_15__9TObjEneDDFv();
s32 add_radar_scaled_marker(void *, int, int, int, f32);
extern s32 TBoss1Dragon__data_805D4B38;
extern s32 local_client_id;
extern const f32 lbl_805D80C0;
void run_task__12TBoss1DragonFv(u8 *arg0);
void get_camera_ctrl__9TObjEneDDFv(s32, s32);
void update_camera_sequence__9TObjEneDDFv(void);
s32 mult_vec_array__10TObjPlayerFUll(int, void *, int, int);
extern const RecoveredGlobal_8002116C_lbl_80434F20 boss1_dragon_capture_node_table;
extern DragonModelVector lbl_804FE188;
extern DragonCaptureVectors lbl_804FE194;
extern DragonModelState lbl_804FE1B8;
extern s32 lbl_805D4B10;
s32 TBoss1Dragon__sub_80027590(void* object, void* action);
extern const RecoveredGlobal_80027AAC_lbl_80434EB4 boss1_dragon_ground_impact_params;
s32 reload_stats_keep_hp_tp__9TObjEneDDFv(void *, int, int, int);
extern s32 TBoss1Dragon__data_805D4B00;
extern s32 TBoss1Dragon__data_805D4B04;
extern s32 TBoss1Dragon__data_805D4B2C;
void calc_follow_camera_offsets__12TBoss1DragonFv(TBoss1Dragon *self, Vec *eye, Vec *target);
f32 TBoss1Dragon__sub_80027634(void);
extern RecoveredGlobal_80027E78_lbl_80434E8C boss1_dragon_attack_sphere_params;
void apply_landing_attack__12TBoss1DragonFi(s32 arg0);
extern const f32 lbl_805D80BC;
struct Obj_80027320;
extern u8 controller_input_state[];
void TBoss1Dragon__sub_80026C98(TBoss1Dragon *arg0, u32 arg1);
void TBoss1Dragon__sub_80022158(TBoss1Dragon *arg0, u32 arg1);
void TBoss1Dragon__sub_800224A4(TBoss1Dragon *arg0, u32 arg1);
void TBoss1Dragon__sub_80022740(TBoss1Dragon *arg0, u32 arg1);
void TBoss1Dragon__sub_800228E8(TBoss1Dragon *arg0, u32 arg1);
void TBoss1Dragon__sub_80022C38(TBoss1Dragon *arg0, u32 arg1);
void TBoss1Dragon__sub_80023A2C(TBoss1Dragon *arg0, u32 arg1);
void update_dive_state__12TBoss1DragonFv(u8 *arg0, u32 arg1);
void TBoss1Dragon__sub_80026B98(TBoss1Dragon *arg0, u32 arg1);
extern "C" void dispatch_action__12TBoss1DragonFUll();
void send_6x2F_change_player_hp(s32 arg0, s32 arg1, s32 arg2);
s32 TBoss1Dragon__sub_80027514(u8 *arg0, s32 arg1, u8 *arg2, s32 arg3);
void TBoss1Dragon__sub_800277D8(u8 *arg0);
extern const f32 TBoss1Dragon__gravity_accel;
extern const f32 TBoss1Dragon__data_805D8008;
extern const f32 lbl_805D8020;
extern const f32 lbl_805D8024;
void compose_motion_node_matrix(void *arg0);
s32 matrix_mult_vec(int, void *, void *);
s32 push_matrix_from(void *);
extern u8 identity_matrix[];
extern const f32 lbl_805D808C;
f32 TBoss1Dragon__sub_80027010(Obj_80027010 *arg0, f32 farg0, f32 farg1, f32 farg2);
f32 random_ratio__9TObjCharaFv(void);
f32 rand_range__9TObjEneDDFff(void *, f32, f32);

s32 choose_burrow_ring_destination__12TBoss1DragonFPvPv(Dragon_80028EA8 *arg0, Vec_80028EA8 *arg1);
int get_player_data__10TObjPlayerFi(int a0);
u16 get_entity_id(void *);
void enemy_clear_target__12TObjEneDD_STFUs(void *);
s32 is_alive__8TObjBaseFv(void *);
s32 select_forward_target__12TBoss1DragonFPv(u8 *self);
s32 __dt__7TObjectFv(void *, int);
void *__dt__12TObjEneDD_STFv(void *arg0, s16 arg1);
s32 __dt__17AreaAttackHistoryFv(s32 arg0, s16 arg1);
s32 free_collision_body_parts(void *);
void __dl__7TObjectFPv(void *);
s32 __destroy_arr(void *, void *, int, int);
void *__dt__15RenderFadeStateFv(void *arg0, s16 arg1);
Obj_80029C78 *destroy__12TBoss1DragonFPvs(Obj_80029C78 *o, s16 flag);
void render_shadows__12TBoss1DragonFv(u8 *arg0);

u8 *TBoss1DragonColli__ct(u8 *arg0, s32 arg1);
void *TBoss1DragonEffTail__ct(void *, void *, void *);
u8 *TObjBoss1MokoHill_SoloM__ct(u8 *arg0, u8 *arg1, u8 *arg2, s32 arg3);
s32 __ct__14SubtractiveRngFv(void *arg0);
void __ct__12TObjEneDD_STFP7TObject(void *, void *);
void initialize_enemy_state__9TObjEneDDFl(void *, s32);
void init_model__9TObjEneDDFP13CollisionBodyl(void *, void *, s32);
void invoke_initialization_hook__9TObjEneDDFPv(void *, void *);
u8 *__ct__17AreaAttackHistoryFl(u8 *arg0, s32 arg1);
void __ct__7TObjectFP7TObject(void *, void *);
void __construct_array(void *, void *, void *, int, int);
extern u8 __ct__15RenderFadeStateFv[];
extern u8 boss1_dragon_normal_action_table[];
extern u8 boss1_dragon_normal_particle_table[];
extern s32 lbl_805D2650;

extern "C" void vfunc_6__8TObjBaseFPsl();
extern "C" void vfunc_103__9TObjEneDDFPUc();
extern "C" void vfunc_79__9TObjEneDDFPl();
extern "C" void vfunc_84__9TObjEneDDFv();
extern "C" void vfunc_85__9TObjEneDDFv();
extern "C" void vfunc_86__9TObjEneDDFv();
extern "C" void vfunc_89__9TObjEneDDFv();
extern "C" void vfunc_90__9TObjEneDDFv();
extern "C" void vfunc_91__9TObjEneDDFv();
extern "C" void vfunc_92__9TObjEneDDFv();
extern "C" void vfunc_93__9TObjEneDDFv();
extern "C" void vfunc_94__9TObjEneDDFv();
extern "C" void vfunc_95__9TObjEneDDFv();
extern "C" void vfunc_96__9TObjEneDDFv();
extern "C" void vfunc_97__9TObjEneDDFv();
extern "C" void vfunc_98__9TObjEneDDFv();
extern "C" void vfunc_99__9TObjEneDDFv();
extern "C" void vfunc_100__9TObjEneDDFv();
extern "C" void vfunc_101__9TObjEneDDFPUc();
extern "C" void vfunc_102__9TObjEneDDFv();
extern "C" int vfunc_104__12TObjEneDD_STFf(void *p);
extern "C" void vfunc_83__12TObjEneDD_STFv();
extern "C" void vfunc_29__9TObjCharaFv();
extern "C" void recalc_stats__9TObjCharaFv();
extern "C" void consume_timer_field__9TObjCharaFl();
extern "C" void vfunc_67__9TObjCharaFf();
extern "C" void vfunc_66__9TObjCharaFv();
extern "C" void get_anim_node_position__9TObjCharaFlP3Vec();
extern "C" void vfunc_60__9TObjCharaFv();
extern "C" void vfunc_59__9TObjCharaFv();
extern "C" void vfunc_58__9TObjCharaFv();
extern "C" void update_shock_clock__9TObjCharaFv();
extern "C" void vfunc_43__9TObjCharaFv();
extern "C" void vfunc_18__9TObjCharaFPUc();
extern "C" void interact__14TObjCollidableFl();
extern "C" void vfunc_74__9TObjEnemyFl();
extern "C" void apply_hit_message_flags__9TObjEnemyFPv();
extern "C" void add_actor_exp__9TObjCharaFl();
extern "C" void apply_action_hold_status__9TObjCharaFf();
extern "C" void apply_anti_technique__9TObjCharaFl();
extern "C" void apply_attack_stat_status__9TObjCharaFPv();
extern "C" void apply_knockback_from_attacker__9TObjCharaFPUcf();
extern "C" void apply_object_set_data__8TObjBaseFPv();
extern "C" void apply_set_data__9TObjEnemyFPv();
extern "C" void apply_switch_attack__9TObjCharaFv();
extern "C" void calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf();
extern "C" void classify_actor_view_detail__8TObjBaseFfff();
extern "C" void clear_all_status_effects__9TObjCharaFv();
extern "C" void cure_paralysis__9TObjCharaFv();
extern "C" void cure_poison_ailment__9TObjCharaFv();
extern "C" void enemy_spawn_jellen_effect__9TObjCharaFv();
extern "C" void enemy_spawn_zalure_effect__9TObjCharaFv();
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
extern "C" u8 lbl_80434FAC[];
extern "C" u8 lbl_80434FC4[];
extern "C" u8 lbl_80434FDC[];
extern "C" u8 lbl_80434FFC[];
extern "C" u8 lbl_80435018[];
extern "C" u8 lbl_80435034[];
extern "C" u8 lbl_80435050[];
extern "C" u8 lbl_8043506C[];
extern "C" u8 lbl_80435088[];
extern "C" u8 lbl_804350A8[];
extern "C" u8 lbl_804350C4[];
extern "C" u8 lbl_804350E0[];
extern "C" u8 lbl_80435100[];
extern "C" u8 lbl_8043511C[];
extern "C" u8 lbl_80435138[];
extern "C" u8 lbl_80435154[];
extern "C" u8 lbl_80435170[];
extern "C" u8 lbl_80435190[];
extern "C" u8 lbl_804351AC[];
extern "C" u8 lbl_804351C8[];
extern "C" u8 lbl_804351E4[];
extern "C" u8 lbl_80435200[];
extern "C" u8 lbl_80435220[];
extern "C" u8 lbl_80435240[];
extern "C" u8 lbl_8043525C[];
extern "C" u8 lbl_8043527C[];
extern "C" u8 lbl_80435298[];
extern "C" u8 lbl_804352B8[];
extern "C" u8 lbl_804352D8[];
extern "C" void receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll();
extern "C" void receive_physical_attack__9TObjCharaFPvf();
extern "C" void receive_weapon_special_attack__9TObjCharaFPvPv();
extern "C" void apply_defense_stat_status__9TObjCharaFPv();
extern "C" void render_low_detail__12TBoss1DragonFv();
extern "C" void reset_motion_fields__9TObjCharaFv();
extern "C" void reset_pose__9TObjCharaFv();
extern "C" void roll_physical_accuracy__9TObjCharaFPvlf();
extern "C" void select_melee_contact_body__9TObjCharaFPvf();
extern "C" void trigger_switch_attack__9TObjCharaFv(s32 arg0);
extern "C" void try_start_action__9TObjCharaFll();
extern "C" void update_action_hold_status__9TObjCharaFv();
extern "C" s32 vfunc_37__9TObjCharaFv(u8 *arg0);
extern "C" void update_actor_ground_y__9TObjCharaFv();
extern "C" s32 update_attack_stat_status__9TObjCharaFv(u8 *arg0);
extern "C" s32 update_defense_stat_status__9TObjCharaFv(u8 *arg0);
extern "C" void update_flag30_timer__9TObjCharaFv();
extern "C" void update_movement_status__9TObjCharaFv();
extern "C" void update_object_view_visibility__8TObjBaseFff();
extern "C" void update_poison_status__9TObjCharaFv();
extern void *lbl_80480F88[3];
extern void *lbl_80480F94[27];
int vfunc_105__12TBoss1DragonFv(void* p);
void vfunc_61__12TBoss1DragonFv(void);
void vfunc_62__12TBoss1DragonFv(void);
void vfunc_63__12TBoss1DragonFv(void);
void vfunc_28__12TBoss1DragonFv(void);
void apply_poison_status__12TBoss1DragonFv(void);
void apply_slow_status__12TBoss1DragonFv(void);
void clear_harmful_statuses__12TBoss1DragonFv(void);
void vfunc_88__12TBoss1DragonFv(u8 *arg0);
void *TBoss1Dragon__data_80480CE0[8] = {
    (void *)0x2, (void *)0x3, (void *)0x4, (void *)0x5,
    (void *)0x6, (void *)0x7, (void *)0x8, (void *)0x20,
};
void *boss1_dragon_sequence_remap_table[8] = {
    (void *)0x0, (void *)0x0, (void *)0x2, (void *)0x3,
    (void *)0x3, (void *)0x3, (void *)0x0, (void *)0x0,
};
void *lbl_80480D20[10] = {
    (void *)0x2, (void *)0x3, (void *)0x2, (void *)0x3,
    (void *)0x4, (void *)0x5, (void *)0x6, (void *)0x22,
    (void *)0x8, (void *)0x20,
};
void *lbl_80480D48[10] = {
    (void *)0x0, (void *)0x0, (void *)0x2, (void *)0x0,
    (void *)0x2, (void *)0x3, (void *)0x3, (void *)0x3,
    (void *)0x0, (void *)0x0,
};
void *boss1_dragon_action_sequence_table[14] = {
    (void *)0x5, (void *)0x6,
    (void *)0xf, (void *)0x10, (void *)0x12, (void *)0x11,
    (void *)0x12, (void *)0x11, (void *)0x12, (void *)0x13,
    (void *)0x8, (void *)0x2, (void *)0x3, (void *)0x21,
};
void *boss1_dragon_action_sequence_table_b[12] = {
    (void *)0x5, (void *)0x6, (void *)0xf, (void *)0x10,
    (void *)0x12, (void *)0x11, (void *)0x12, (void *)0x23,
    (void *)0x13, (void *)0x8, (void *)0x2, (void *)0x3,
};
__declspec(section ".data") s32 lbl_80480DD8 = 0x21;
s32 boss1_dragon_attack_param_ids[5] = {0x12,0x14,0x15,0x16,0x17};
s32 boss1_dragon_resistance_param_ids[3] = {0x11,0x12,0x13};
s32 boss1_dragon_base_stat_indices[5] = { 0, 0, 0, 0, 0 };
s32 boss1_dragon_attack_stat_indices[5] = { 0, 1, 2, 3, 4 };
s32 boss1_dragon_resistance_stat_indices[5] = { 0, 0, 0, 0, 0 };
void *boss1_dragon_init_params[7] = {
    (void *)0x43610000, (void *)0x0, (void *)0x600, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
struct DragonCollisionBodyPartInit {
    f32 local_center[3];
    f32 radius;
    f32 field_10;
    s32 field_14;
    u32 flags;
    f32 world_center[3];
    f32 field_28;
};
typedef char DragonCollisionBodyPartInit_size[(sizeof(DragonCollisionBodyPartInit) == 0x2C) ? 1 : -1];
DragonCollisionBodyPartInit boss1_dragon_collision_body_parts[7] = {
    { { 0.0f, 0.0f, 0.0f }, 10.0f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, 10.0f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, 10.0f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, 15.0f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, 15.0f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, 10.0f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, 10.0f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f },
};
void *lbl_80480F88[3] = {
    (void *)&lbl_80434FAC, (void *)&lbl_80434FC4, (void *)0x0,
};
void *lbl_80480F94[27] = {
    (void *)&lbl_80434FDC, (void *)&lbl_80434FFC, (void *)&lbl_80435018, (void *)&lbl_80435034,
    (void *)&lbl_80435050, (void *)&lbl_8043506C, (void *)&lbl_80435088, (void *)&lbl_804350A8,
    (void *)&lbl_804350C4, (void *)&lbl_804350E0, (void *)&lbl_80435100, (void *)&lbl_8043511C,
    (void *)&lbl_80435138, (void *)&lbl_80435154, (void *)&lbl_80435170, (void *)&lbl_80435190,
    (void *)&lbl_804351AC, (void *)&lbl_804351C8, (void *)&lbl_804351E4, (void *)&lbl_80435200,
    (void *)&lbl_80435220, (void *)&lbl_80435240, (void *)&lbl_8043525C, (void *)&lbl_8043527C,
    (void *)&lbl_80435298, (void *)&lbl_804352B8, (void *)0x0,
};
BmlResourceDescriptor boss1_dragon_bml_descriptor = {(const char *)&lbl_804352D8, (const char *const *)lbl_80480F88, (const char *const *)lbl_80480F94, 2, 26};
void *lbl_80481010[108] = {
    (void *)0x10000, (void *)0x11, (void *)0x3f000000, (void *)0x0,
    (void *)0x10000, (void *)0x15, (void *)0x3f000000, (void *)0x0,
    (void *)0x30000, (void *)0x10, (void *)0x3f333333, (void *)0x0,
    (void *)0x30000, (void *)0x5, (void *)0x3f666666, (void *)0x0,
    (void *)0x30000, (void *)0x8, (void *)0x3f000000, (void *)0x0,
    (void *)0x10000, (void *)0x9, (void *)0x3ecccccd, (void *)0x0,
    (void *)0x30000, (void *)0xa, (void *)0x3f000000, (void *)0x0,
    (void *)0x30000, (void *)0x12, (void *)0x3f000000, (void *)0x0,
    (void *)0x20009, (void *)0xe, (void *)0x3f000000, (void *)0x0,
    (void *)0x10000, (void *)0x4, (void *)0x3e99999a, (void *)0x0,
    (void *)0x30000, (void *)0xf, (void *)0x3e99999a, (void *)0x0,
    (void *)0x30000, (void *)0x2, (void *)0x3f19999a, (void *)0x0,
    (void *)0x30000, (void *)0x1, (void *)0x3f000000, (void *)0x0,
    (void *)0x30000, (void *)0x19, (void *)0x3f000000, (void *)0x0,
    (void *)0x30000, (void *)0x18, (void *)0x3f000000, (void *)0x0,
    (void *)0x30000, (void *)0xd, (void *)0x3f800000, (void *)0x0,
    (void *)0x10000, (void *)0x7, (void *)0x3f800000, (void *)0x0,
    (void *)0x2000e, (void *)0xc, (void *)0x3f800000, (void *)0x0,
    (void *)0x20010, (void *)0x6, (void *)0x3f8ccccd, (void *)0x0,
    (void *)0x30000, (void *)0x3, (void *)0x3f000000, (void *)0x0,
    (void *)0x10000, (void *)0x17, (void *)0x3f800000, (void *)0x0,
    (void *)0x10000, (void *)0x16, (void *)0x3f000000, (void *)0x0,
    (void *)0x30000, (void *)0x14, (void *)0x3f800000, (void *)0x0,
    (void *)0x10000, (void *)0xb, (void *)0x3f800000, (void *)0x0,
    (void *)0x20010, (void *)0x13, (void *)0x3f000000, (void *)0x80000000,
    (void *)0x30000, (void *)0x0, (void *)0x3f000000, (void *)0x80000000,
    (void *)0x20008, (void *)0x2, (void *)0x3f19999a, (void *)0x0,
};
static void *boss1_dragon_follow_camera_offsets[3] = {
    (void *)0x0, (void *)0x419e6666, (void *)0xc0a00000,
};
static void *lbl_804811CC[3] = {
    (void *)0x0, (void *)0x41cb70a4, (void *)0x4235ae14,
};
static void *boss1_dragon_follow_camera_phase_positions[9] = {
    (void *)0x0, (void *)0x41b80000, (void *)0xc0400000, (void *)0x0,
    (void *)0x42000000, (void *)0x0, (void *)0x0, (void *)0x41c80000,
    (void *)0xc0a00000,
};
static void *boss1_dragon_follow_camera_phase_targets[9] = {
    (void *)0x0, (void *)0x41300000, (void *)0x42200000, (void *)0x0,
    (void *)0x40a00000, (void *)0x420c0000, (void *)0x0, (void *)0x42480000,
    (void *)0x42700000,
};
static void *boss1_dragon_held_camera_positions[12] = {
    (void *)0x0, (void *)0x41a00000, (void *)0xc2f00000, (void *)0x0,
    (void *)0x42f00000, (void *)0xc2f00000, (void *)0x0, (void *)0x41c80000,
    (void *)0xc1f00000, (void *)0x0, (void *)0x42480000, (void *)0xc2a00000,
};
static void *boss1_dragon_held_camera_targets[12] = {
    (void *)0x0, (void *)0x42f00000, (void *)0x42480000, (void *)0x0,
    (void *)0x43960000, (void *)0xc1f00000, (void *)0x0, (void *)0x42200000,
    (void *)0x0, (void *)0x43960000, (void *)0x42f00000, (void *)0x42480000,
};
void *lbl_80481280[107] = {
    (void *)0x0, (void *)0x0, (void *)&destroy__12TBoss1DragonFPvs, (void *)&run_task__12TBoss1DragonFv,
    (void *)&render__12TBoss1DragonFv, (void *)&render_shadows__12TBoss1DragonFv, (void *)&vfunc_6__8TObjBaseFPsl, (void *)&apply_object_set_data__8TObjBaseFPv,
    (void *)&reset_motion_fields__9TObjCharaFv, (void *)&get_center__9TObjCharaFv, (void *)&update_object_view_visibility__8TObjBaseFff, (void *)&classify_actor_view_detail__8TObjBaseFfff,
    (void *)&get_name__9TObjEnemyFv, (void *)&interact__14TObjCollidableFl, (void *)&add_actor_exp__9TObjCharaFl, (void *)&consume_timer_field__9TObjCharaFl,
    (void *)&get_actor_level_index__9TObjCharaFv, (void *)&update_actor_ground_y__9TObjCharaFv, (void *)&vfunc_18__9TObjCharaFPUc, (void *)&is_actor_cadence_frame__9TObjCharaFl,
    (void *)&select_melee_contact_body__9TObjCharaFPvf, (void *)&calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf, (void *)&receive_physical_attack__9TObjCharaFPvf, (void *)&receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll,
    (void *)&receive_weapon_special_attack__9TObjCharaFPvPv, (void *)&apply_knockback_from_attacker__9TObjCharaFPUcf, (void *)&try_start_action__9TObjCharaFll, (void *)&roll_physical_accuracy__9TObjCharaFPvlf,
    (void *)&vfunc_28__12TBoss1DragonFv, (void *)&vfunc_29__9TObjCharaFv, (void *)&is_target_in_attack_range__9TObjCharaFv, (void *)&test_flag_256__9TObjCharaFv,
    (void *)&test_flag30_512__9TObjCharaFv, (void *)&has_flag_0x800__9TObjCharaFv, (void *)&test_flag_1000__9TObjCharaFv, (void *)&update_poison_status__9TObjCharaFv,
    (void *)&update_action_hold_status__9TObjCharaFv, (void *)&vfunc_37__9TObjCharaFv, (void *)&update_flag30_timer__9TObjCharaFv, (void *)&update_movement_status__9TObjCharaFv,
    (void *)&update_shock_clock__9TObjCharaFv, (void *)&update_attack_stat_status__9TObjCharaFv, (void *)&update_defense_stat_status__9TObjCharaFv, (void *)&vfunc_43__9TObjCharaFv,
    (void *)&apply_poison_status__12TBoss1DragonFv, (void *)&apply_paralysis__12TBoss1DragonFv, (void *)&apply_slow_status__12TBoss1DragonFv, (void *)&apply_confusion_status__12TBoss1DragonFv,
    (void *)&apply_movement_ailment__12TBoss1DragonFl, (void *)&apply_shock_status__12TBoss1DragonFv, (void *)&clear_harmful_statuses__12TBoss1DragonFv, (void *)&apply_attack_stat_status__9TObjCharaFPv,
    (void *)&apply_defense_stat_status__9TObjCharaFPv, (void *)&cure_poison_ailment__9TObjCharaFv, (void *)&cure_paralysis__9TObjCharaFv, (void *)&clear_all_status_effects__9TObjCharaFv,
    (void *)&apply_action_hold_status__9TObjCharaFf, (void *)&apply_anti_technique__9TObjCharaFl, (void *)&vfunc_58__9TObjCharaFv, (void *)&vfunc_59__9TObjCharaFv,
    (void *)&vfunc_60__9TObjCharaFv, (void *)&vfunc_61__12TBoss1DragonFv, (void *)&vfunc_62__12TBoss1DragonFv, (void *)&vfunc_63__12TBoss1DragonFv,
    (void *)&reset_pose__9TObjCharaFv, (void *)&get_anim_node_position__9TObjCharaFlP3Vec, (void *)&vfunc_66__9TObjCharaFv, (void *)&vfunc_67__9TObjCharaFf,
    (void *)&get_pos__9TObjCharaFl, (void *)&apply_switch_attack__9TObjCharaFv, (void *)&enemy_spawn_jellen_effect__9TObjCharaFv, (void *)&trigger_switch_attack__9TObjCharaFv,
    (void *)&enemy_spawn_zalure_effect__9TObjCharaFv, (void *)&recalc_stats__9TObjCharaFv, (void *)&vfunc_74__9TObjEnemyFl, (void *)&vfunc_75__9TObjCharaFf,
    (void *)&vfunc_76__9TObjCharaFv, (void *)&vfunc_77__9TObjCharaFv, (void *)&vfunc_78__9TObjCharaFl, (void *)&vfunc_79__9TObjEneDDFPl,
    (void *)&apply_hit_message_flags__9TObjEnemyFPv, (void *)&apply_set_data__9TObjEnemyFPv, (void *)&clear_lobby_object_state__9TObjEnemyFv, (void *)&vfunc_83__12TObjEneDD_STFv,
    (void *)&vfunc_84__9TObjEneDDFv, (void *)&vfunc_85__9TObjEneDDFv, (void *)&vfunc_86__9TObjEneDDFv, (void *)&dispatch_action__12TBoss1DragonFUll,
    (void *)&vfunc_88__12TBoss1DragonFv, (void *)&vfunc_89__9TObjEneDDFv, (void *)&vfunc_90__9TObjEneDDFv, (void *)&vfunc_91__9TObjEneDDFv,
    (void *)&vfunc_92__9TObjEneDDFv, (void *)&vfunc_93__9TObjEneDDFv, (void *)&vfunc_94__9TObjEneDDFv, (void *)&vfunc_95__9TObjEneDDFv,
    (void *)&vfunc_96__9TObjEneDDFv, (void *)&vfunc_97__9TObjEneDDFv, (void *)&vfunc_98__9TObjEneDDFv, (void *)&vfunc_99__9TObjEneDDFv,
    (void *)&vfunc_100__9TObjEneDDFv, (void *)&vfunc_101__9TObjEneDDFPUc, (void *)&vfunc_102__9TObjEneDDFv, (void *)&vfunc_103__9TObjEneDDFPUc,
    (void *)&vfunc_104__12TObjEneDD_STFf, (void *)&vfunc_105__12TBoss1DragonFv, (void *)&render_low_detail__12TBoss1DragonFv,
};

void fill_value_array(s32);
s32 emit_enemy_effect__9TObjEneDDFllPUcl(void *, void *, void *, s32);
s32 update_local_colliders_from_world(void *, void *);
void TBoss1Dragon__sub_800274A4(s32 arg0);

s32 fn_8002AE08(void*);
s32 approach_angle_limited(int, int, int);

f64 atan2_float(f32, f32);
s32 saveCurrentDestination__12TBoss1DragonFv(void *);
s32 restorePosition__12TBoss1DragonFv(void *);
void TBoss1Dragon__sub_80028AFC(u8 *);

extern s32 lbl_80435388[];
s32 disable_dragon_blocking_bodies(int);
s32 enable_dragon_blocking_bodies(int, void *, int);

extern const f32 lbl_805D8014;
extern const f32 TBoss1Dragon__data_805D8018;
extern const f32 lbl_805D801C;
extern const f32 lbl_805D4AF0;
extern const f32 lbl_805D8064;
extern const f32 lbl_805D8068;
extern const f32 lbl_805D806C;
extern const f32 lbl_805D8070;
s32 __ct__21TBoss1DragonEffBreathFP7TObjectPvPv(void *, void *, void *, void *);
extern const f32 lbl_805D8074;
void clear_work__12TBoss1DragonFi(s32 arg0);
void TBoss1Dragon__sub_80028AFC(u8 *arg0);
void spawn_trap__12TBoss1DragonFii(s32 arg0, s32 arg1);
s32 filter_input_flags__12TBoss1DragonFiii(s32 arg1, s32 arg2, s32 arg3);
u8 check_attack_ready__12TBoss1DragonFPv(void *arg0);
void sweep_head_fall_spheres_late__12TBoss1DragonFv(void);
void update_from_data__12TBoss1DragonFv(void);
void sweep_body_attack_spheres__12TBoss1DragonFv(u8 *arg0, f32 a, f32 b, f32 c);
s32 check_flag_100__10TObjPlayerFPv();
u8 *get_enemy_entity(u16 arg0);
s32 angle_diff_s16(s32, s32);
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);
void *init_base__13TUnk_80481B34Fv(void *arg0);
void TLobby__sub_8001FE7C(void*, int);
void __ct__13TUnk_804928CCFP7TObjectP8TObjBase(void *);
s32 update_linked_position__12TObjEneDD_STFf(f32);
void subtractive_rng_seed(void *, u32);
f32 calc_random_ratio__10TObjPlayerFv(void *);
void sub_8002AE64__9TObjEnemyFv(void *);
}
void get_dragon_follow_camera_offsets(u8 *arg0, u8 *arg1);
extern const f32 lbl_805D8094;
extern const RecoveredGlobal_80027650_lbl_80435338 dragon_fireball_impact_damage_params;
extern RecoveredGlobal_80027710_lbl_80435324 dragon_fireball_attack_params;
s32 is_dragon_trail_damaging(u8 *arg0);
extern RecoveredGlobal_800277D8_lbl_80435310 dragon_breath_attack_params;

void set_collider_contact_low(u8 *arg0);
void set_collider_contact_high(u8 *arg0);
void handle_6x12_dragon_boss_actions(TObjPlayer *arg0);
void handle_6x11_dragon_boss_actions(void *arg0);
void handle_6x10_dragon_boss_actions(void *arg0);
extern u32 TBoss1Dragon__data_805D4B28;

extern f32 lbl_805D8088;
extern const f32 TBoss1Dragon__data_805D8010;
extern const f32 lbl_805D8098;
extern const f32 lbl_805D809C;
extern const f32 lbl_805D80A0;
extern s32 enable_v2_features;
extern s32 lbl_805D4B34;
extern u16 TBoss1Dragon__data_805D4B3C;
extern s32 lbl_80481B34[];

bool TBoss1Dragon::isV2Mode() {
    return TObjEneDD::check_v2_mode() != 0;
}

void TBoss1Dragon::render_low_detail() {
    TBoss1Dragon *self = this;
    DragonMotion *m;
    s32 i;
    f32 frame;

    if (((TBoss1Dragon*)self)->update_object_view_visibility((400.0f), (20.0f)) == 0) {
        return;
    }
    TObjFish::set_global_param(self->texlist);
    push_matrix();
    post_translate_matrix(&self->position.x);
    rotate_matrix_y(0, self->rotation_y);
    push_matrix();
    scale_matrix(0, (8.0f), (2.0f), (8.0f));
    pop_matrix();
    scale_matrix(0, (2.0f), (2.0f), (2.0f));
    model_render_flags &= ~0x400;
    i = (s32)self->parameters[0];
    if (i < 0) {
        i = 0;
    } else if (i >= 0x1B) {
        i = 0x1A;
    }
    m = (*(DragonMotionEntry * *)&self->motion_list)[(*(DragonAnimationEntry * *)&self->action_table)[i].motionIndex].motion;
    frame = self->parameters[1];
    if (frame < (0.0f)) {
        frame = (0.0f);
    } else {
        if (frame > (m->frameCount - 1)) {
            frame = (f32)m->frameCount;
        }
    }
    draw_model_motion(self->model, m, frame);
    TObjLight__sub_801337F8(current_scene_light);
    pop_matrix();
}

extern const u8 boss1_dragon_death_cue_filename[] = "dradeath.adx";
static const f64 boss1_dragon_angle_units_per_radian = 10430.38043493439;

int TBoss1Dragon::vfunc_105() { return this->get_target_info(); }

void TBoss1Dragon::render_shadows() {
    s32 temp_r31;
    s32 var_r31;
    u8 *temp_r3;
    u8 *temp_r4;

    var_r31 = 0;
    if (TObjPlayer::check_demo_mode() == 0) {
        if (is_split_screen() != 0) {
            var_r31 = get_camera_mode__11TCameraCtrlFv();
        }
        if ((this->viewFade[var_r31].has_visible_opacity() != 0) && ((((TBoss1Dragon *)((u8 *)this))->heightOffset - ((TBoss1Dragon *)((u8 *)this))->defaultHeightOffset) >= (-5.0f)) && ((s16) ((TBoss1Dragon *)((u8 *)this))->mode != 0x16)) {
            push_matrix();
            post_translate_matrix((void *) (((u8 *)this) + 0x38));
            rotate_matrix_y(0, (int) (((TBoss1Dragon *)((u8 *)this))->rotation_y));
            scale_matrix(0, (2.0f), (2.0f), (2.0f));
            rotate_matrix_x(0, (int) (*(s32 *)((s8 *)((u8 *)this) + 0x5C)));
            rotate_matrix_z(0, (int) (((TBoss1Dragon *)((u8 *)this))->rotation_z));
            temp_r31 = *(s32 *)((s8 *)((u8 *)this) + 0x34);
            temp_r4 = (u8 *)(*(u8 **)((s8 *)TBoss1Dragon__data_805D4B08 + 0x42C));
            *(s32 *)((s8 *)((u8 *)this) + 0x34) = (s32) *(s32 *)((s8 *)temp_r4 + 0x18);
            ((TObjMotion *)((u8 *)this))->draw();
            *(s32 *)((s8 *)((u8 *)this) + 0x34) = temp_r31;
            pop_matrix();
        }
    }
}

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
void TBoss1Dragon::render() {
    s32 view;
    s32 saved;
    s32 i;
    RenderFadeState *ch;
    s32 visible;
    s16 state;
    u8 *ent;
    s32 hit;
    f32 dist;
    view = 0;
    if (TObjPlayer::check_demo_mode() != 0) {
        this->render_low_detail();
        return;
    }
    if (is_split_screen() != 0) {
        view = get_camera_mode__11TCameraCtrlFv();
    }
    TBoss1Dragon__data_805D4B0C = 0;
    TBoss1Dragon__data_805D4B14 = (s32) (((u8 *)this) + 0x3E8);
    TBoss1Dragon__data_805D4B18 = 0;
    TBoss1Dragon__data_805D4B1C = (s32) (((u8 *)this) + 0x430);
    TBoss1Dragon__data_805D4B20 = *(s32 *)&((TBoss1Dragon *)((u8 *)this))->flags;
    this->update_object_view_visibility((1000.0f), (1000.0f));
    ch = &this->viewFade[view];
    if (ch->has_visible_opacity() != 0) {
        if (is_split_screen() != 0 && ((TBoss1Dragon *)((u8 *)this))->heightOffset - ((TBoss1Dragon *)((u8 *)this))->defaultHeightOffset >= (-5.0f) &&
            ((TBoss1Dragon *)((u8 *)this))->mode != 0x16) {
            push_matrix();
            post_translate_matrix(((u8 *)this) + 0x38);
            translate_matrix(0, (0.0f), (2.0f), (0.0f));
            rotate_matrix_y(0, ((TBoss1Dragon *)((u8 *)this))->rotation_y);
            scale_matrix(0, (2.0f), (0.001f), (2.0f));
            rotate_matrix_x(0, *(s32 *)((s8 *)((u8 *)this) + 0x5C));
            rotate_matrix_z(0, ((TBoss1Dragon *)((u8 *)this))->rotation_z);
            Color_80020B54 color = dragon_boss1_render_color;
            saved = *(s32 *)((s8 *)((u8 *)this) + 0x34);
            *(s32 *)((s8 *)((u8 *)this) + 0x34) = *(s32 *)((s8 *)(*(u8 **)((s8 *)TBoss1Dragon__data_805D4B08 + 0x42C)) + 0x18);
            saved_model_render_flags = model_render_flags;
            model_render_flags = saved_model_render_flags | 0x10;
            set_constant_material((const NJS_ARGB *)((&color)));
            ((TObjMotion *)((u8 *)this))->draw();
            model_render_flags = saved_model_render_flags;
            *(s32 *)((s8 *)((u8 *)this) + 0x34) = saved;
            pop_matrix();
        }
        TObjFish::set_global_param(((TBoss1Dragon *)((u8 *)this))->texlist);
        TObjEneDD::clear_global_flag_400();
        saved_model_render_flags = model_render_flags;
        set_material_alpha_compare_reference(0);
        state = ((TBoss1Dragon *)((u8 *)this))->mode;
        visible = 1;
        if (state == 0x16) {
            ch->set_flags_and_apply_damage_color();
            visible = 0;
        } else {
            hit = 0;
            if (camera_ctrl_instance != NULL && state != 0x1D && state != 0x16 && state != 0x15 &&
                ((TBoss1Dragon *)((u8 *)this))->phase == 0) {
                ent = find_entity_by_id(TCameraCtrl::get_camera_target_id(-1));
                if (ent != NULL) {
                    Vec_80020B54 origin;
                    Vec_80020B54 delta;
                    f32 *points[4];
                    Vec_80020B54 probe;
                    VecCopy__FP3VecPC3Vec((s32) &origin, (s32)(camera_ctrl_instance + 0x178));
                    origin.y = (0.0f);
                    VecCopy__FP3VecPC3Vec((s32) &delta, (s32)(ent + 0x38));
                    subtract_vector(&delta, &origin);
                    delta.y = (0.0f);
                    dist = ((f32 (*)(void *)) normalize_vector_xz__FP3Vec)(&delta);
                    VecCopy__FP3VecPC3Vec((s32) lbl_804FE1D0, (s32) &origin);
                    VecCopy__FP3VecPC3Vec((s32) lbl_804FE1DC, (s32) &delta);
                    *(f32 *) &boss1_dragon_visibility_distance = dist;
                    points[0] = (f32 *) (((u8 *)this) + 0x454);
                    points[1] = (f32 *) (((u8 *)this) + 0x460);
                    points[2] = (f32 *) (((u8 *)this) + 0x46C);
                    points[3] = (f32 *) (((u8 *)this) + 0x478);
                    for (i = 0; i < 4; i++) {
                        if (((s32 (*)(void *, void *, f32)) is_sphere_visible__12TBoss1DragonFf)(((u8 *)this), points[i], (12.0f)) != 0) {
                            hit = 1;
                            break;
                        }
                    }
                    if (((TBoss1Dragon *)((u8 *)this))->mode == 9) {
                        if (hit == 0) {
                            probe.x = *(f32 *)((s8 *)((u8 *)this) + 0x38) - (25.0f) * sin_table_lookup(((TBoss1Dragon *)((u8 *)this))->rotation_y);
                            probe.y = (0.0f);
                            probe.z = *(f32 *)((s8 *)((u8 *)this) + 0x40) - (25.0f) * cos_table_lookup(((TBoss1Dragon *)((u8 *)this))->rotation_y);
                            hit = ((s32 (*)(void *, void *, f32)) is_sphere_visible__12TBoss1DragonFf)(((u8 *)this), &probe, (20.0f));
                        }
                        if (hit == 0) {
                            hit = ((s32 (*)(void *, s32)) check_parts_visible__12TBoss1DragonFiPv)(((u8 *)this), TBoss1Dragon__sub_8002B108(*(s32 *)((s8 *)((u8 *)this) + 0x68C), 1));
                        }
                        if (hit == 0) {
                            hit = ((s32 (*)(void *, s32)) check_parts_visible__12TBoss1DragonFiPv)(((u8 *)this), TBoss1Dragon__sub_8002B108(*(s32 *)((s8 *)((u8 *)this) + 0x68C), 2));
                        }
                    }
                }
            }
            if (hit != 0) {
                ch->fadeOut();
            } else {
                ch->restore();
            }
            ch->update();
            if (ch->isFading() != 0) {
                ch->set_flags_and_apply_damage_color();
                visible = 0;
            }
        }
        if (visible == 0) {
            if (defer_render__7TObjectFv(((u8 *)this)) != 0) {
                visible = 0;
            } else {
                visible = 1;
            }
        }
        if (visible != 0) {
            push_matrix();
            post_translate_matrix(((u8 *)this) + 0x38);
            translate_matrix(0, (0.0f), ((TBoss1Dragon *)((u8 *)this))->heightOffset, (0.0f));
            rotate_matrix_y(0, ((TBoss1Dragon *)((u8 *)this))->rotation_y);
            rotate_matrix_x(0, *(s32 *)((s8 *)((u8 *)this) + 0x5C));
            rotate_matrix_z(0, ((TBoss1Dragon *)((u8 *)this))->rotation_z);
            scale_matrix(0, (2.0f), (2.0f), (2.0f));
            set_chunk_model_node_callback((s32)((s32 *) dragon_capture_node_points));
            TObjPlayer::toggle_particle_effect();
            ((TObjMotion *)((u8 *)this))->draw();
            TParticleCtrl::end_effect_render();
            set_chunk_model_node_callback((s32)NULL);
            TObjLight__sub_801337F8(current_scene_light);
            pop_matrix();
        }
        set_chunk_material_override_pair(0xFF00, 0);
        set_material_alpha_compare_reference(0xBF);
        model_render_flags = saved_model_render_flags;
    } else {
        ((TBoss1Dragon *)((u8 *)this))->draw();
        this->update_object_view_visibility((1000.0f), (1000.0f));
    }
    VecCopy__FP3VecPC3Vec((s32) (((u8 *)this) + 0x40C), (s32) (((u8 *)this) + 0x3E8));
    VecCopy__FP3VecPC3Vec((s32) (((u8 *)this) + 0x418), (s32) (((u8 *)this) + 0x3F4));
    subtract_vector(((u8 *)this) + 0x418, ((u8 *)this) + 0x40C);
    VecCopy__FP3VecPC3Vec((s32) (((u8 *)this) + 0x424), (s32) (((u8 *)this) + 0x400));
    saved_model_render_flags = model_render_flags;
    model_render_flags = saved_model_render_flags | 0x400;
    ((TObject *)(((u8 *)this) + 0x3C4))->render_nodes();
    model_render_flags = saved_model_render_flags;
}
#pragma pop

void TBoss1Dragon::draw() {
    s32 temp_r31;

    temp_r31 = *(s32 *)&this->model;
    *(s32 *)&this->model = (s32) TBoss1Dragon__data_805D4B28;
    set_chunk_model_node_callback((s32)(((s32 *)dragon_capture_node_points)));
    push_matrix();
    post_translate_matrix(((u8 *)this) + 0x38);
    translate_matrix(0, (0.0f), this->heightOffset, (0.0f));
    rotate_matrix_y(0, this->rotation_y);
    rotate_matrix_x(0, *(s32 *)&this->rotation_x);
    rotate_matrix_z(0, this->rotation_z);
    scale_matrix(0, (2.0f), (2.0f), (2.0f));
    ((TObjMotion *)((u8 *)this))->draw();
    pop_matrix();
    set_chunk_model_node_callback((s32)NULL);
    *(s32 *)&this->model = temp_r31;
}

void dragon_capture_node_points(void) {
    s32 temp_r0;
    s32 temp_r4;
    if ((s32) TBoss1Dragon__data_805D4B0C == (s32) lbl_805D4B10) {
        push_matrix();
        update_camera_sequence__9TObjEneDDFv();
        mult_vec_array__10TObjPlayerFUll(0, (void *)&lbl_804FE194.vectors[0].x, TBoss1Dragon__data_805D4B14, 3);
        pop_matrix();
    }
    if ((s32) TBoss1Dragon__data_805D4B0C == (s32) *(s32 *)((s8 *)&boss1_dragon_capture_node_table.value + (TBoss1Dragon__data_805D4B18 * 4))) {
        temp_r4 = TBoss1Dragon__data_805D4B1C;
        TBoss1Dragon__data_805D4B1C = temp_r4 + 0xC;
        get_camera_ctrl__9TObjEneDDFv((s32) &lbl_804FE188.x, temp_r4);
        temp_r0 = TBoss1Dragon__data_805D4B18 + 1;
        TBoss1Dragon__data_805D4B18 = temp_r0;
        if ((temp_r0 == 7) && !(TBoss1Dragon__data_805D4B20 & 0x80)) {
            TBoss1Dragon__data_805D4B18 = 0xC;
            TBoss1Dragon__data_805D4B1C += 0x3C;
        }
        if (((s32) TBoss1Dragon__data_805D4B18 == 0x12) && !(TBoss1Dragon__data_805D4B20 & 0x200)) {
            TBoss1Dragon__data_805D4B18 = 0x20;
            TBoss1Dragon__data_805D4B1C += 0xA8;
        }
    }
    TBoss1Dragon__data_805D4B0C += 1;
}

struct Rec_80021260 { u8 pad0[0xC]; f32 f0C; u8 pad10[0xC]; u8 b1C[0x10]; };
struct Obj_80021260 { u8 pad0[0xA4]; Rec_80021260 *recs; s32 count; };
s32 check_parts_visible__12TBoss1DragonFiPv(s32 arg0, Obj_80021260 *arg1) {
    s32 off;
    s32 n;
    s32 i;
    i = 0;
    off = 0;
    n = arg1->count;
    for (; i < n; i++, off += sizeof(Rec_80021260)) {
        Rec_80021260 *r = (Rec_80021260 *)((u8 *)arg1->recs + off);
        if (((s32 (*)(void *, void *, f32))is_sphere_visible__12TBoss1DragonFf)((void *)arg0, r->b1C, r->f0C) != 0) {
            return 1;
        }
    }
    return 0;
}

#pragma push
#pragma fp_contract on
s32 is_sphere_visible__12TBoss1DragonFf(f32 farg0) {
    Stack_800212D8 stack;
    f32 temp_f1;
    ((s32 (*)(void *))VecCopy__FP3VecPC3Vec)(&stack.sp8);
    stack.spC = (0.0f);
    subtract_vector(&stack.sp8, (void *) lbl_804FE1D0);
    temp_f1 = ((f32 (*)(void *))normalize_vector_xz__FP3Vec)(&stack.sp8);
    if ((temp_f1 + farg0) < boss1_dragon_visibility_distance) {
        if (vec3_dot(&stack.sp8, (void *) lbl_804FE1DC) >= (temp_f1 * ((1.0f) / newton_sqrtf((f32) ((temp_f1 * temp_f1) + (farg0 * farg0)))))) {
            return 1;
        }
    }
    return 0;
}
#pragma pop

void TBoss1Dragon::wait_for_players(s32 arg1) {
    switch (arg1) {
    case ENEMY_STATE_ENTER:
        this->requested_action = 0;
        this->stateStep = 0;
        this->position.y = (f32) (0.0f);
        this->heightOffset = (f32) ((300.0f) + this->defaultHeightOffset);
        this->height = (f32) (this->defaultHeightOffset + (this->heightOffset + this->position.y));
        return;
    case 3:
        if ((s32) this->stateStep > 0x96) {
            transition_enemy_state((s16)(8));
        }
    case ENEMY_STATE_LEAVE:
    case 1:
        return;
    case ENEMY_STATE_UPDATE:
        if ((get_player_by_client_id(0) != 0U) || (get_player_by_client_id(1) != 0U) || (get_player_by_client_id(2) != 0U) || (get_player_by_client_id(3) != 0U)) {
            this->stateStep = (this->stateStep + 1);
        }
        break;
    }
}

void TBoss1Dragon::update_appearance_state(u32 reason) {
    Dragon_80021490 *self = (Dragon_80021490 *)this;
    s32 *demo = &self->demo_active;
    u8 *p;
    switch (reason) {
    case ENEMY_STATE_ENTER:
        self->action = 0;
        clearState__12TBoss1DragonFv(self);
        advance_animation();
        self->pos.x = (0.0f);
        self->pos.y = (0.0f);
        self->pos.z = (0.0f);
        self->rot[0] = 0;
        self->rot[1] = 0;
        self->rot[2] = 0;
        self->altitude = (0.0f);
        self->offset = self->base;
        self->mouth = 0;
        switch (isV2Mode__12TBoss1DragonFv()) {
        case 0:
            self->phase = 1;
            break;
        case 1:
            self->phase = 2;
            break;
        }
        self->stage = 0;
        self->ticks = 0;
        *demo = 1;
        p = __nw__7TObjectFUl(0x28);
        if (p != NULL) {
            __ct__16TBoss1DragonDemoFv(p, tl_01, (s32) demo, (0.5f));
        }
        self->action = 25;
        TWindowCtrl::init_all_slots();
        ((TObjEneDD *)self)->get_target_state_b();
        ((TMainCursor *)self)->update_pair();
        break;
    case 2:
    case 9:
        if (self->phase == 4) {
            ((TBoss1Dragon *)self)->request_state_change(0);
        }
        break;
    case ENEMY_STATE_UPDATE:
        switch (self->phase) {
        case 0:
            break;
        case 1:
            advance_animation();
            if (((TObjEneDD *)self)->get_flag_b4() != 0) {
                self->phase = 4;
                TWindowCtrl::init_all_slots2();
                self->action = 0;
            }
            switch (self->stage) {
            case 0:
                if (((TObjMotion *)self)->is_passing_frame((f32)(2.0f)) != 0) {
                    play_sound_effect(0x4003A804, 0, 0, 0);
                    self->stage++;
                }
                break;
            case 1:
                if (((TObjMotion *)self)->is_passing_frame((f32)(32.0f)) != 0) {
                    play_sound_effect(0x4003AD0E, 0, 0, 0);
                }
                if (((TObjMotion *)self)->is_passing_frame((f32)(35.0f)) != 0) {
                    spawn_particle_effect_with_flags(&self->pos, self->tbl->e8, 0x40);
                    self->stage++;
                }
                break;
            case 2:
                if (((TObjMotion *)self)->is_passing_frame((f32)(75.0f)) != 0) {
                    play_sound_effect(0x4003AD06, 0, 0, 0);
                    self->stage++;
                    self->ticks = 0;
                }
                break;
            case 3:
                if (self->frame <= (80.0f)) {
                    self->ticks++;
                    if (self->ticks % 4 == 0) {
                        spawn_particle_effect_with_flags(&self->fxpos, self->tbl->e1C, 0x40);
                    }
                } else {
                    self->stage++;
                }
                break;
            case 4:
                if (((TObjMotion *)self)->is_passing_frame((f32)(105.0f)) != 0) {
                    ((s32 (*)(void *)) play_cue_stream_file)((void*)boss1_dragon_death_cue_filename);
                    self->stage++;
                    self->ticks = 0;
                }
                break;
            case 5:
                if (self->frame < (150.0f)) {
                    DragonEffectRotation rot;
                    direction_to_rotation_xz((u8 *)&self->fxdir, &rot.x, &rot.z);
                    if (self->mouth == 0) {
                        self->mouth = spawn_particle_effect_with_rotation(&self->fxpos, &rot, (void *) self->tbl->e14, 0x40);
                    } else {
                        ((TParticleCtrl *)(void *) self->mouth)->set_position(&self->fxpos);
                        ((TParticleCtrl *)((void *) self->mouth))->set_direction(&rot);
                    }
                } else {
                    if (self->mouth != 0) {
                        queue_destruction__7TObjectFv((void *) self->mouth);
                        self->mouth = 0;
                    }
                    self->stage++;
                }
                break;
            }
            break;
        case 2:
            advance_animation();
            if (((TObjEneDD *)self)->get_flag_b4() != 0) {
                self->phase = 4;
                TWindowCtrl::init_all_slots2();
                self->action = 0;
            }
            switch (self->stage) {
            case 0:
                if (((TObjMotion *)self)->is_passing_frame((f32)(9.0f)) != 0 ||
                    ((TObjMotion *)self)->is_passing_frame((f32)(40.0f)) != 0) {
                    play_sound_effect(0x4003A804, 0, 0, 0);
                }
                if (((TObjMotion *)self)->is_passing_frame((f32)(62.0f)) != 0) {
                    play_sound_effect(0x4003AD0E, 0, 0, 0);
                }
                if (((TObjMotion *)self)->is_passing_frame((f32)(64.0f)) != 0) {
                    play_sound_effect(0x4003A804, 0, 0, 0);
                    spawn_particle_effect_with_flags(&self->pos, self->tbl->e8, 0x40);
                    self->stage++;
                }
                break;
            case 1:
                if (((TObjMotion *)self)->is_passing_frame((f32)(92.0f)) != 0) {
                    play_sound_effect(0x4003AD06, 0, 0, 0);
                    self->stage++;
                    self->ticks = 0;
                }
                break;
            case 2:
                if (self->frame <= (99.0f)) {
                    self->ticks++;
                    if (self->ticks % 4 == 0) {
                        spawn_particle_effect_with_flags(&self->fxpos, self->tbl->e1C, 0x40);
                    }
                } else {
                    self->stage++;
                }
                break;
            case 3:
                if (((TObjMotion *)self)->is_passing_frame((f32)(120.0f)) != 0) {
                    ((s32 (*)(void *)) play_cue_stream_file)((void*)boss1_dragon_death_cue_filename);
                    self->stage++;
                    self->ticks = 0;
                }
                break;
            case 4:
                if (self->frame < (155.0f)) {
                    DragonEffectRotation rot;
                    direction_to_rotation_xz((u8 *)&self->fxdir, &rot.x, &rot.z);
                    if (self->mouth == 0) {
                        self->mouth = spawn_particle_effect_with_rotation(&self->fxpos, &rot, (void *) self->tbl->e14, 0x40);
                    } else {
                        ((TParticleCtrl *)(void *) self->mouth)->set_position(&self->fxpos);
                        ((TParticleCtrl *)((void *) self->mouth))->set_direction(&rot);
                    }
                } else {
                    if (self->mouth != 0) {
                        queue_destruction__7TObjectFv((void *) self->mouth);
                        self->mouth = 0;
                    }
                    self->stage++;
                }
                break;
            }
            break;
        case 3:
            advance_animation();
            if (((TObjEneDD *)self)->get_flag_b4() != 0) {
                self->phase = 4;
                TWindowCtrl::init_all_slots2();
                self->action = 0;
            }
            switch (self->stage) {
            case 0:
                if (((TObjMotion *)self)->is_passing_frame((f32)(2.0f)) != 0) {
                    play_sound_effect(0x4003A804, 0, 0, 0);
                    self->stage++;
                }
                break;
            case 1:
                if (((TObjMotion *)self)->is_passing_frame((f32)(60.0f)) != 0) {
                    play_sound_effect(0x4003AD0E, 0, 0, 0);
                }
                if (((TObjMotion *)self)->is_passing_frame((f32)(63.0f)) != 0) {
                    spawn_particle_effect_with_flags(&self->pos, self->tbl->e8, 0x40);
                    spawn_particle_effect_with_flags(&self->pos, 0x203, 0x40);
                    self->stage++;
                }
                break;
            case 2:
                if (((TObjMotion *)self)->is_passing_frame((f32)(75.0f)) != 0) {
                    play_sound_effect(0x4003AD06, 0, 0, 0);
                    self->stage++;
                    self->ticks = 0;
                }
                break;
            case 3:
                if (self->frame > (80.0f)) {
                    self->stage++;
                }
                break;
            case 4:
                if (((TObjMotion *)self)->is_passing_frame((f32)(105.0f)) != 0) {
                    ((s32 (*)(void *)) play_cue_stream_file)((void*)boss1_dragon_death_cue_filename);
                    self->stage++;
                    self->ticks = 0;
                }
                break;
            case 5:
                if (self->frame < (150.0f)) {
                    DragonEffectRotation rot;
                    direction_to_rotation_xz((u8 *)&self->fxdir, &rot.x, &rot.z);
                    if (self->mouth == 0) {
                        self->mouth = spawn_particle_effect_with_rotation(&self->fxpos, &rot, (void *) self->tbl->e14, 0x40);
                    } else {
                        ((TParticleCtrl *)(void *) self->mouth)->set_position(&self->fxpos);
                        ((TParticleCtrl *)((void *) self->mouth))->set_direction(&rot);
                    }
                } else {
                    if (self->mouth != 0) {
                        queue_destruction__7TObjectFv((void *) self->mouth);
                        self->mouth = 0;
                    }
                    self->stage++;
                }
                break;
            }
            break;
        case 4:
            advance_animation();
            break;
        }
        break;
    case ENEMY_STATE_LEAVE:
        if (self->mouth != 0) {
            queue_destruction__7TObjectFv((void *) self->mouth);
            self->mouth = 0;
        }
        ((TMainCursor *)self)->update_cursor_pair();
        *demo = 0;
        TWindowCtrl::init_all_slots2();
        ((TObjEneDD *)self)->get_target_state_a();
        break;
    }
}

void TBoss1Dragon::update_wander_state(s32 arg1) {
    switch (arg1) {
    case ENEMY_STATE_ENTER:
        this->requested_action = 0xB;
        this->stateStep = 0;
        return;
    case ENEMY_STATE_UPDATE:
        this->stateStep = (this->stateStep + 1);
        if ((s32) this->stateStep > 0x5A) {
            this->stateStep = 0;
            this->requested_action = (this->requested_action + 1);
            if ((s16) this->requested_action >= 0x1B) {
                this->requested_action = 0;
            }
        }
        advance_animation();
    case 3:
    case ENEMY_STATE_LEAVE:
    case 1:
        return;
    }
}

extern "C" {

struct Vec_80021DE4 { f32 x, y, z; };
struct Ext_80021DE4 { u8 pad0[0x3A0]; Vec_80021DE4 dir; };

f32 calc_elapsed_scaled__9TObjEneDDFv(void *);

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
#define self ((TBoss1Dragon *)arg0)
#define ext ((Ext_80021DE4 *)arg0)
void TBoss1Dragon::handle_fall_state(u32 arg1) {
    u8 *arg0 = (u8 *)this;
    switch (arg1) {
    case ENEMY_STATE_ENTER:
        self->requested_action = 0x11;
        this->vfunc_96();
        self->setPhase2();
        TBoss1Dragon__sub_80028AFC(arg0);
        self->flags = self->flags | 0xC00;
        self->flags = self->flags & 0xFFFFFC7F;
        this->vfunc_91();
        this->vfunc_94();
        self->fallVelocity = (0.0f);
        ext->dir.x = -self->position.x;
        ext->dir.y = (0.0f);
        ext->dir.z = -self->position.z;
        ((void (*)(void *))normalize_vector_xz__FP3Vec)(arg0 + 0x3A0);
        this->rotation_y = (s32) (boss1_dragon_angle_units_per_radian * atan2_float(ext->dir.x, ext->dir.z));
        ((TBoss8Dragon *)(*(s32 *)((s8 *)arg0 + 0x6D8)))->set_field_3c();
        return;
    case 2:
    case 11:
        if (self->rootHeight >= (680.0f)) {
            ((TBoss1Dragon *)arg0)->request_state_change(0x13);
        }
        return;
    case 7:
        self->restorePosition();
        return;
    case 6:
        self->saveCurrentDestination();
        return;
    case ENEMY_STATE_UPDATE:
        self->fallVelocity += (0.1f);
        if (self->fallVelocity > (12.0f)) {
            self->fallVelocity = (12.0f);
        }
        self->rootHeight = self->rootHeight + self->fallVelocity;
        self->position.x = ext->dir.x * self->fallVelocity + self->position.x;
        self->position.z = ext->dir.z * self->fallVelocity + self->position.z;
        TBoss1Dragon__sub_800277D8(arg0);
        return;
    case ENEMY_STATE_LEAVE:
        ((TBoss8Dragon *)(*(s32 *)((s8 *)arg0 + 0x6D8)))->spawn_child_object();
        break;
    default:
        return;
    }
}
#undef self
#undef ext
#pragma pop

void TBoss1Dragon::state_circle_flight(u32 arg1) {
    u8 *arg0 = (u8 *)this;
    s32 temp_r4;

    switch (arg1) {
    case ENEMY_STATE_ENTER:
        this->requested_action = 0x11;
        this->vfunc_96();
        ((TBoss1Dragon *)arg0)->setPhase2();
        TBoss1Dragon__sub_80028AFC(arg0);
        this->flags = (s32) (this->flags | 0xC00);
        this->flags = (s32) (this->flags & 0xFFFFFC7F);
        this->vfunc_91();
        this->vfunc_94();
        ((TBoss1Dragon *)arg0)->updateFacingPosition();
        ((TBoss8Dragon *)(*(s32 *)((s8 *)arg0 + 0x6D8)))->set_field_3c();
        return;
    case 2:
    case 11:
        if (((s32) this->stateStep >= 0x1C2) || (filter_input_flags__12TBoss1DragonFiii((s32)arg0, *(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x6E4)) + 8), 0x400) != 0)) {
            ((TBoss1Dragon *)arg0)->request_state_change(0x25);
        }
        return;
    case 7:
        this->facingAngle = (s32) this->savedX;
        if (this->savedZ > (0.0f)) {
            *(s32 *)((s8 *)arg0 + 0x874) = 0x180;
            return;
        }
        *(s32 *)((s8 *)arg0 + 0x874) = -0x180;
        return;
    case 6:
        this->destinationX = (f32) ((65536.0f) * random_ratio__9TObjCharaFv());
        this->destinationZ = calc_elapsed_scaled__9TObjEneDDFv(arg0);
        return;
    case ENEMY_STATE_UPDATE:
        this->facingAngle = (s32) (this->facingAngle + *(s32 *)((s8 *)arg0 + 0x874));
        if ((s32) *(s32 *)((s8 *)arg0 + 0x874) >= 0) {
            this->rotation_y = (this->facingAngle + 0x9800);
        } else {
            this->rotation_y = (this->facingAngle + 0xFFFF6800);
        }
        ((TBoss1Dragon *)arg0)->updateFacingPosition();
        temp_r4 = this->stateStep;
        this->stateStep = (temp_r4 + 1);
        ((void (*)(u8 *, s32))TBoss1Dragon__sub_800277D8)(arg0, temp_r4);
        return;
    case ENEMY_STATE_LEAVE:
        ((TBoss8Dragon *)(*(s32 *)((s8 *)arg0 + 0x6D8)))->spawn_child_object();
        break;
    default:
        break;
    }
}

struct Vec_80022158 { f32 x, y, z; };
struct Ext_80022158 { u8 pad0[0x38]; Vec_80022158 pos; u8 pad44[0x890 - 0x44]; Vec_80022158 home; };
struct Input_80022158 { u8 pad0[8]; s32 flags; u8 padC[0x1C - 0xC]; s32 angle; u8 pad20[4]; f32 f24; };

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
#define self ((TBoss1Dragon *)arg0)
#define ext ((Ext_80022158 *)arg0)
void TBoss1Dragon__sub_80022158(TBoss1Dragon *arg0, u32 arg1) {
    f32 factor;
    f32 dx;
    f32 dz;
    Vec_80022158 *home;
    Input_80022158 *in;
    extern const u8 TBoss1Dragon__data_80434E80[0xC];

    home = &ext->home;
    switch (arg1) {
    case 4:
        self->requested_action = 0x11;
        ((TBoss1Dragon *)(arg0))->vfunc_96();
        self->setPhase2();
        TBoss1Dragon__sub_80028AFC((u8 *)arg0);
        self->flags = self->flags | 0xC00;
        self->flags = self->flags & 0xFFFFFC7F;
        ((TBoss1Dragon *)(arg0))->vfunc_91();
        ((TBoss1Dragon *)(arg0))->vfunc_94();
        VecCopy__FP3VecPC3Vec((s32)home, (s32)&ext->pos);
        self->stateStep = 0x64;
        self->impactAge = 0;
        home->y = ((const Vec_80022158 *)TBoss1Dragon__data_80434E80)->y;
        self->fallVelocity = (0.0f);
        self->rootHeight = (0.0f);
        ((TBoss8Dragon *)(*(s32 *)((s8 *)arg0 + 0x6D8)))->set_field_1c();
        return;
    case 2:
    case 11:
        if (self->impactAge == 1) {
            ((TBoss1Dragon *)arg0)->request_state_change(0x1B);
            return;
        }
        if ((*(Input_80022158 **)((s8 *)self + 0x6E4))->flags & 2) {
            ((TBoss1Dragon *)arg0)->request_state_change(0x13);
        }
        return;
    case 8:
        self->stateStep = self->stateStep + 1;
        if (self->stateStep >= 0x1E) {
            self->stateStep = 0;
            in = *(Input_80022158 **)((s8 *)self + 0x6E4);
            if (in->f24 <= (0.1f)) {
                self->impactAge = 1;
                return;
            }
            arg0->rotation_y = in->angle;
            self->setDestinationX(arg0->rotation_y);
            send_state_sync__12TBoss1DragonFPv((struct dragon_80028530 *)arg0);
            return;
        }
        break;
    case 7:
        self->copySavedX((int *)((u8 *)arg0 + 0x60));
        return;
    case 6:
        self->setDestinationX(arg0->rotation_y);
        return;
    case 0:
        dx = sin_table_lookup(arg0->rotation_y);
        dz = cos_table_lookup(arg0->rotation_y);
        factor = (4.0f);
        ext->pos.x = dx * factor + ext->pos.x;
        ext->pos.z = dz * factor + ext->pos.z;
        horizontal_distance_squared(&ext->pos, home);
        dx = ((f32 (*)(void))newton_sqrtf)();
        VecCopy__FP3VecPC3Vec((s32)home, (s32)&ext->pos);
        self->fallVelocity = self->fallVelocity + dx;
        return;
    case 5:
        ((TBoss8Dragon *)(*(s32 *)((s8 *)arg0 + 0x6D8)))->spawn_child_object();
        break;
    default:
        return;
    }
}
#undef self
#undef ext
#pragma pop

void TBoss1Dragon::handle_state(u32 arg1) {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r3;

    switch (arg1) {
    case 4:
        this->vfunc_96();
        ((TBoss1Dragon *)arg0)->setPhase2();
        TBoss1Dragon__sub_80028AFC(arg0);
        this->flags = (s32) (this->flags | 0xC00);
        this->flags = (s32) (this->flags & 0xFFFFFC7F);
        this->vfunc_91();
        this->vfunc_94();
        this->stateStep = 0;
        return;
    case 2:
    case 11:
        temp_r3 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x6E4));
        if (*(f32 *)((s8 *)temp_r3 + 0x24) > (0.1f)) {
            ((TBoss1Dragon *)arg0)->request_state_change(0x1C);
            return;
        }
        if (*(s32 *)((s8 *)temp_r3 + 8) & 2) {
            ((TBoss1Dragon *)arg0)->request_state_change(0x13);
            return;
        }
        break;
    case 7:
        restorePosition__12TBoss1DragonFv(arg0);
        return;
    case 6:
        saveCurrentDestination__12TBoss1DragonFv(arg0);
        return;
    case 0:
        this->stateStep = (this->stateStep + 1);
        if ((s32) this->stateStep > 0xA) {
            clear_work__12TBoss1DragonFi((s32)arg0);
            this->stateStep = 0;
        }
        break;
    }
}

void TBoss1Dragon__sub_800224A4(TBoss1Dragon *arg0, u32 arg1) {
    f32 temp_f31;
    f32 temp_f30;
    f32 var_f3;
    s32 temp_r4;
    u8 *temp_r4_2;
    s32 *saved = (s32 *)((u8 *)arg0 + 0x874);

    switch (arg1) {
    case 4:
        arg0->requested_action = 0x10;
        ((TBoss1Dragon *)(arg0))->vfunc_96();
        arg0->setActive();
        TBoss1Dragon__sub_80028B28((u8 *)arg0);
        arg0->flags = (s32) (arg0->flags & ~0xE80);
        arg0->stateStep = 0x64;
        arg0->impactAge = 0;
        return;
    case 11:
        if (((s32) arg0->controlTimer > 0x1C2) || (filter_input_flags__12TBoss1DragonFiii((s32)arg0, *(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x6E4)) + 8), 2) != 0)) {
            ((TBoss1Dragon *)arg0)->request_state_change(8);
            return;
        }
        if ((s32) arg0->impactAge == 1) {
            ((TBoss1Dragon *)arg0)->request_state_change(0x19);
            return;
        }
        if (filter_input_flags__12TBoss1DragonFiii((s32)arg0, *(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x6E4)) + 8), 4) != 0) {
            ((TBoss1Dragon *)arg0)->request_state_change(7);
            return;
        }
        if (arg0->check_can_attack() != 0) {
            ((TBoss1Dragon *)arg0)->request_state_change(0xF);
        }
        return;
    case 2:
        if ((s32) arg0->impactAge == 1) {
            ((TBoss1Dragon *)arg0)->request_state_change(0x19);
            return;
        }
        temp_r4 = *(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x6E4)) + 8);
        if (temp_r4 & 4) {
            ((TBoss1Dragon *)arg0)->request_state_change(7);
            return;
        }
        if (temp_r4 & 2) {
            ((TBoss1Dragon *)arg0)->request_state_change(0xF);
            return;
        }
        if (temp_r4 & 0x400) {
            ((TBoss1Dragon *)arg0)->request_state_change(8);
            return;
        }
        break;
    case 8:
        arg0->stateStep = (arg0->stateStep + 1);
        if ((s32) arg0->stateStep >= 0x1E) {
            arg0->stateStep = 0;
            temp_r4_2 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x6E4));
            if (*(f32 *)((s8 *)temp_r4_2 + 0x24) <= (0.1f)) {
                arg0->impactAge = 1;
                return;
            }
            *saved = *(s32 *)((s8 *)temp_r4_2 + 0x1C);
            arg0->setDestinationX(*saved);
            send_state_sync__12TBoss1DragonFPv((struct dragon_80028530 *)arg0);
            return;
        }
        break;
    case 7:
        arg0->copySavedX((int*)saved);
        return;
    case 6:
        arg0->setDestinationX(*saved);
        return;
    case 0:
        arg0->advance_animation();
        arg0->play_nearby_se();
        TBoss1Dragon__sub_800274A4((s32)arg0);
        arg0->rotation_y = approach_angle_limited(arg0->rotation_y, *saved, 0x200);
        temp_f31 = sin_table_lookup(arg0->rotation_y);
        temp_f30 = cos_table_lookup(arg0->rotation_y);
        var_f3 = (2.0f);
        if ((s32) *(s32 *)((s8 *)arg0 + 0x760) != 0) {
            var_f3 = TBoss1Dragon__sub_80027010((Obj_80027010 *) (arg0), temp_f31, temp_f30, var_f3);
        }
        ((TObjEneDD *)arg0)->move_with_wall_stop(temp_f31, temp_f30, var_f3);
        break;
    default:
        return;
    }
}

#define self ((TBoss1Dragon *)arg0)
void TBoss1Dragon__sub_80022740(TBoss1Dragon *arg0, u32 arg1) {

    Input_80022740 *in;
    s32 flags;

    switch (arg1) {
    case 4:
        self->requested_action = 0x10;
        ((TBoss1Dragon *)(self))->vfunc_96();
        self->setActive();
        TBoss1Dragon__sub_80028B28((u8 *)arg0);
        self->flags = self->flags & ~0xE80;
        return;
    case 11:
        if (self->controlTimer > 0x1C2 || filter_input_flags__12TBoss1DragonFiii((s32)arg0, (*(Input_80022740 **)((s8 *)self + 0x6E4))->flags, 2) != 0) {
            ((TBoss1Dragon *)arg0)->request_state_change(8);
            return;
        }
        in = *(Input_80022740 **)((s8 *)self + 0x6E4);
        if (in->f24 > (0.1f)) {
            ((TBoss1Dragon *)arg0)->request_state_change(0x1A);
            return;
        }
        if (filter_input_flags__12TBoss1DragonFiii((s32)arg0, in->flags, 4) != 0) {
            ((TBoss1Dragon *)arg0)->request_state_change(7);
            return;
        }
        if (arg0->check_can_attack() != 0) {
            ((TBoss1Dragon *)arg0)->request_state_change(0xF);
        }
        return;
    case 2:
        in = *(Input_80022740 **)((s8 *)self + 0x6E4);
        if (in->f24 > (0.1f)) {
            ((TBoss1Dragon *)arg0)->request_state_change(0x1A);
            return;
        }
        flags = in->flags;
        if (flags & 4) {
            ((TBoss1Dragon *)arg0)->request_state_change(7);
            return;
        }
        if (flags & 2) {
            ((TBoss1Dragon *)arg0)->request_state_change(0xF);
            return;
        }
        if (flags & 0x400) {
            ((TBoss1Dragon *)arg0)->request_state_change(8);
            return;
        }
        break;
    case 7:
        self->restorePosition();
        return;
    case 6:
        self->saveCurrentDestination();
        return;
    case 0:
        arg0->advance_animation();
        arg0->play_nearby_se();
        TBoss1Dragon__sub_800274A4((s32)arg0);
        break;
    default:
        return;
    }
}
#undef self

#define filter_input_flags__12TBoss1DragonFiii ((s32 (*)(s32, s32, s32))filter_input_flags__12TBoss1DragonFiii)
#define check_attack_ready__12TBoss1DragonFPv ((u8 (*)(void *))check_attack_ready__12TBoss1DragonFPv)
#define TBoss1Dragon__sub_80027010 ((f32 (*)(void *, f32, f32, f32))TBoss1Dragon__sub_80027010)
#define send_state_sync__12TBoss1DragonFPv ((void (*)(void *))send_state_sync__12TBoss1DragonFPv)
#define TBoss1Dragon__sub_80028BE0 ((void (*)(u8 *))TBoss1Dragon__sub_80028BE0)
void TBoss1Dragon__sub_800228E8(TBoss1Dragon *arg0, u32 arg1) {
    f32 temp_f31;
    f32 temp_f30;
    f32 var_f29;
    f32 temp_f1;
    s32 temp_r4;
    u8 *temp_r4_2;
    s32 *saved = (s32 *)((u8 *)arg0 + 0x874);

    switch (arg1) {
    case 4:
        arg0->requested_action = 1;
        ((TBoss1Dragon *)(arg0))->vfunc_96();
        clearState__12TBoss1DragonFv(arg0);
        beginHeightTransition__12TBoss1DragonFv(arg0);
        arg0->flags = (s32) (arg0->flags & ~0xE80);
        arg0->stateStep = 0;
        arg0->impactAge = 0;
        return;
    case 2:
        if ((s32) arg0->impactAge == 1) {
            ((TBoss1Dragon *)arg0)->request_state_change(0x17);
            return;
        }
        temp_r4 = *(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x6E4)) + 8);
        if (temp_r4 & 4) {
            ((TBoss1Dragon *)arg0)->request_state_change(3);
            return;
        }
        if (temp_r4 & 2) {
            ((TBoss1Dragon *)arg0)->request_state_change(4);
            return;
        }
        if (temp_r4 & 0x400) {
            ((TBoss1Dragon *)arg0)->request_state_change(5);
        }
        return;
    case 11:
        if ((s32) arg0->impactAge == 1) {
            ((TBoss1Dragon *)arg0)->request_state_change(0x17);
            return;
        }
        if (filter_input_flags__12TBoss1DragonFiii((s32)arg0, *(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x6E4)) + 8), 4) != 0) {
            ((TBoss1Dragon *)arg0)->request_state_change(3);
            return;
        }
        if (filter_input_flags__12TBoss1DragonFiii((s32)arg0, *(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x6E4)) + 8), 2) != 0) {
            ((TBoss1Dragon *)arg0)->request_state_change(4);
            return;
        }
        if (((s32 (*)(void *))check_attack_ready__12TBoss1DragonFPv)(arg0) != 0) {
            ((TBoss1Dragon *)arg0)->request_state_change(5);
            return;
        }
        if (filter_input_flags__12TBoss1DragonFiii((s32)arg0, *(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x6E4)) + 8), fn_8002AE08((void *)TBoss1Dragon__data_805D4B3C)) != 0) {
            ((TBoss1Dragon *)arg0)->request_state_change(9);
            return;
        }
        break;
    case 8:
        arg0->stateStep = (arg0->stateStep + 1);
        if ((s32) arg0->stateStep >= 0x1E) {
            arg0->stateStep = 0;
            temp_r4_2 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x6E4));
            if (*(f32 *)((s8 *)temp_r4_2 + 0x24) <= (0.1f)) {
                arg0->impactAge = 1;
                return;
            }
            *saved = *(s32 *)((s8 *)temp_r4_2 + 0x1C);
            arg0->setDestinationX(*saved);
            send_state_sync__12TBoss1DragonFPv(arg0);
            return;
        }
        break;
    case 7:
        arg0->copySavedX((int*)saved);
        return;
    case 6:
        arg0->setDestinationX(arg0->rotation_y);
        return;
    case 0:
        arg0->advance_animation();
        if ((s16) arg0->requested_action == 1) {
            TBoss1Dragon__sub_80028BE0((u8 *)arg0);
        }
        if (((TObjMotion *)arg0)->is_passing_frame((3.0f)) != 0) {
            arg0->apply_foot_attack_pair_0();
        } else if (((TObjMotion *)arg0)->is_passing_frame((24.0f)) != 0) {
            arg0->apply_foot_attack_pair_1();
        }
        var_f29 = (0.8f);
        arg0->play_speed = (f32) (0.48000001907348633f);
        temp_f1 = arg0->frame;
        if ((!(temp_f1 > (4.0f)) || !(temp_f1 < (9.0f))) && (!(temp_f1 > (24.0f)) || !(temp_f1 < (30.0f)))) {
            arg0->rotation_y = approach_angle_limited(arg0->rotation_y, *saved, 0x200);
            temp_f31 = sin_table_lookup(arg0->rotation_y);
            temp_f30 = cos_table_lookup(arg0->rotation_y);
            if ((s32) *(s32 *)((s8 *)arg0 + 0x760) != 0) {
                var_f29 = TBoss1Dragon__sub_80027010(arg0, temp_f31, temp_f30, (0.8f));
            }
            ((TObjEneDD *)arg0)->move_to_shot_position(temp_f31, temp_f30, var_f29);
        }
        break;
    default:
        return;
    }
}
#undef filter_input_flags__12TBoss1DragonFiii
#undef check_attack_ready__12TBoss1DragonFPv
#undef TBoss1Dragon__sub_80027010
#undef send_state_sync__12TBoss1DragonFPv
#undef TBoss1Dragon__sub_80028BE0

#define self ((TBoss1Dragon *)arg0)
void TBoss1Dragon__sub_80022C38(TBoss1Dragon *arg0, u32 arg1) {

    Input_80022C38 *in;
    s32 flags;

    switch (arg1) {
    case 4:
        self->requested_action = 0;
        ((TBoss1Dragon *)(self))->vfunc_96();
        self->clearState();
        self->beginHeightTransition();
        self->flags = self->flags & ~0xE80;
        return;
    case 11:
        in = *(Input_80022C38 **)((s8 *)self + 0x6E4);
        if (in->f24 > (0.1f)) {
            ((TBoss1Dragon *)arg0)->request_state_change(0x18);
            return;
        }
        if (filter_input_flags__12TBoss1DragonFiii((s32)arg0, in->flags, 4) != 0) {
            ((TBoss1Dragon *)arg0)->request_state_change(3);
            return;
        }
        if (filter_input_flags__12TBoss1DragonFiii((s32)arg0, (*(Input_80022C38 **)((s8 *)self + 0x6E4))->flags, 2) != 0) {
            ((TBoss1Dragon *)arg0)->request_state_change(4);
            return;
        }
        if (((s32 (*)(void *))check_attack_ready__12TBoss1DragonFPv)(arg0) != 0) {
            ((TBoss1Dragon *)arg0)->request_state_change(5);
            return;
        }
        if (filter_input_flags__12TBoss1DragonFiii((s32)arg0, (*(Input_80022C38 **)((s8 *)self + 0x6E4))->flags, fn_8002AE08((void *)TBoss1Dragon__data_805D4B3C)) != 0) {
            ((TBoss1Dragon *)arg0)->request_state_change(9);
        }
        return;
    case 2:
        in = *(Input_80022C38 **)((s8 *)self + 0x6E4);
        if (in->f24 > (0.1f)) {
            ((TBoss1Dragon *)arg0)->request_state_change(0x18);
            return;
        }
        flags = in->flags;
        if (flags & 4) {
            ((TBoss1Dragon *)arg0)->request_state_change(3);
            return;
        }
        if (flags & 2) {
            ((TBoss1Dragon *)arg0)->request_state_change(4);
            return;
        }
        if (flags & 0x400) {
            ((TBoss1Dragon *)arg0)->request_state_change(5);
            return;
        }
        break;
    case 7:
        self->restorePosition();
        return;
    case 6:
        self->saveCurrentDestination();
        return;
    case 0:
        arg0->advance_animation();
        break;
    default:
        return;
    }
}
#undef self

void TBoss1Dragon::update_fade_state(u32 arg1) {
    s32 i;

    switch (arg1) {
    case ENEMY_STATE_ENTER:
        this->requested_action = 0x13;
        this->vfunc_95();
        clearState__12TBoss1DragonFv(this);
        beginHeightTransition__12TBoss1DragonFv(this);
        this->flags |= 0xE80;
        for (i = 0; i < 4; i++) {
            ((TBoss8Dragon *)(&this->viewFade[i]))->set_speed((0.005f));
        }
        break;
    case ENEMY_STATE_UPDATE:
        advance_animation();
        for (i = 0; i < 4; i++) {
            if (this->viewFade[i].decay_value_toward_floor() != 0) {
                queue_destruction__7TObjectFv(this);
            }
        }
        break;
    case 1:
        return;
    case 2:
        return;
    case 3:
        return;
    case ENEMY_STATE_LEAVE:
        return;
    case 6:
        return;
    case 7:
        return;
    case 8:
        return;
    case 9:
        return;
    case 10:
        return;
    case 11:
        return;
    }
}

#define TBoss1Dragon__sub_800277D8 ((void (*)(u8 *))TBoss1Dragon__sub_800277D8)
#define clear_work__12TBoss1DragonFi ((void (*)(s32))clear_work__12TBoss1DragonFi)
#define calc_burrow_speed__12TBoss1DragonFPv ((f32 (*)(void *))calc_burrow_speed__12TBoss1DragonFPv)
#define spawn_trap__12TBoss1DragonFii ((void (*)(s32, s32))spawn_trap__12TBoss1DragonFii)

#define F(T, o) (*(T *)(arg0 + (o)))
#define RES(o) (*(s32 *)((u8 *)&TBoss1Dragon__part_hp_stats + (o)))
void update_death_state__12TBoss1DragonFv(u8 *arg0, u32 arg1) {
    Eff_80022EE0 eff1;
    Eff_80022EE0 eff2;
    Cam_80022EE0 cam;
    Vec_80022EE0 rot;
    Vec_80022EE0 v;
    switch (arg1) {
    case 4:
        F(s16, 0xB8) = 0x13;
        ((TBoss1Dragon *)(arg0))->vfunc_95();
        clearState__12TBoss1DragonFv(arg0);
        beginHeightTransition__12TBoss1DragonFv(arg0);
        F(s32, 0x3C0) |= 0xE80;
        F(s32, 0x864) = 0;
        F(s32, 0x868) = 0;
        F(f32, 0x87C) = (0.0f);
        F(u32, 0x8AC) = 0;
        ((s32 (*)(void *))play_cue_stream_file)((void*)boss1_dragon_death_cue_filename);
        TWindowCtrl::init_all_slots();
        switch (isV2Mode__12TBoss1DragonFv()) {
        case 0:
            cam.sub = 0;
            cam.mode = 2;
            cam.c = 0;
            cam.d = (0.0f);
            cam.e = (0.5f);
            activate_camera_mode(5);
            ((TCameraCtrl *)(&cam))->cache_target_and_forward(0x31C7);
            set_scripted_camera_pose(arg0 + 0x38, arg0 + 0x38, arg0 + 0x5C);
            break;
        case 1:
            cam.sub = 1;
            cam.mode = 2;
            cam.c = 0;
            cam.d = (0.0f);
            cam.e = (0.5f);
            activate_camera_mode(5);
            ((TCameraCtrl *)(&cam))->cache_target_and_forward(0x3333);
            set_scripted_camera_pose(arg0 + 0x38, arg0 + 0x38, arg0 + 0x5C);
            break;
        }
        break;
    case 2:
    case 11:
        if (F(s32, 0x868) >= 0x32) {
            ((TBoss1Dragon *)arg0)->request_state_change(0x16);
        }
        break;
    case 9:
        if (F(s32, 0x868) >= 0x32) {
            ((TBoss1Dragon *)arg0)->request_state_change(0x16);
        }
        break;
    case 0:
        ((TObjMotion *)arg0)->advance_animation();
        switch (F(s32, 0x864)) {
        case 0:
            if (((TObjMotion *)arg0)->is_passing_frame((f32)(60.0f)) != 0 || ((TObjMotion *)arg0)->is_passing_frame((f32)((f32)(98.0f))) != 0) {
                play_sound_effect(0x4003AD07, 0, 0, 0);
                start_pad_rumble_all(0xA0, 0xF);
            }
            if (F(f32, 0xC0) >= (25.0f) && F(f32, 0xC0) < (40.0f)) {
                direction_to_rotation_xz(arg0 + 0x418, (s32 *)&rot.x, (s32 *)&rot.z);
                if (F(u32, 0x8AC) == 0) {
                    F(u32, 0x8AC) = spawn_particle_effect_with_rotation(arg0 + 0x40C, &rot, (void *)*(s32 *)((s8 *)(F(u8 *, 0x778)) + 0x14), 0x40);
                }
                if (F(u32, 0x8AC) != 0) {
                    ((TParticleCtrl *)F(void *, 0x8AC))->set_position(arg0 + 0x424);
                    ((TParticleCtrl *)(F(void *, 0x8AC)))->set_direction(&rot);
                }
            } else if (F(u32, 0x8AC) != 0) {
                queue_destruction__7TObjectFv(F(void *, 0x8AC));
                F(u32, 0x8AC) = 0;
            }
            if (((TObjMotion *)arg0)->is_passing_frame((f32)(57.0f)) != 0) {
                eff1 = *(Eff_80022EE0 *)TBoss1Dragon__head_fall_effect_params;
                *(f32 *)&eff1.w[2] = (12.0f);
                ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&v, lbl_80434EC8);
                rotate_xz_pair_by_angle(&v.x, &v.z, F(s32, 0x60));
                vec3_add_to(&v, arg0 + 0x38);
                reset_hp__9TObjEneDDFPUcPUcPUc(arg0, 0, RES(0x10), 0);
                switch (isV2Mode__12TBoss1DragonFv()) {
                case 0:
                    TObjEneDD::emit_effect((void*)arg0, (int)&v, (int)&eff1);
                    break;
                case 1:
                    ((void (*)(u8 *, void *, u8 *, s32))TBoss1Dragon__sub_800275BC)(arg0, &v, (u8 *)&eff1, 0);
                    break;
                }
                reset_hp__9TObjEneDDFPUcPUcPUc(arg0, 0, RES(0), 0);
                spawn_particle_effect_with_flags(&v, *(s32 *)((s8 *)(F(u8 *, 0x778)) + 8), 0x40);
            }
            if (((TObjMotion *)arg0)->is_passing_frame((f32)(88.0f)) != 0) {
                eff2 = *(Eff_80022EE0 *)TBoss1Dragon__head_fall_effect_params;
                *(f32 *)&eff2.w[2] = (25.0f);
                ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&v, lbl_80434ED4);
                rotate_xz_pair_by_angle(&v.x, &v.z, F(s32, 0x60));
                vec3_add_to(&v, arg0 + 0x38);
                reset_hp__9TObjEneDDFPUcPUcPUc(arg0, 0, RES(0x10), 0);
                switch (isV2Mode__12TBoss1DragonFv()) {
                case 0:
                    TObjEneDD::emit_effect((void*)arg0, (int)&v, (int)&eff2);
                    break;
                case 1:
                    ((void (*)(u8 *, void *, u8 *, s32))TBoss1Dragon__sub_800275BC)(arg0, &v, (u8 *)&eff2, 0);
                    break;
                }
                reset_hp__9TObjEneDDFPUcPUcPUc(arg0, 0, RES(0), 0);
                spawn_particle_effect_with_flags(&v, *(s32 *)((s8 *)(F(u8 *, 0x778)) + 8), 0x40);
            }
            if (((TObjMotion *)arg0)->is_passing_frame((f32)(97.0f)) != 0) {
                ((TBoss1Dragon *)arg0)->sweep_death_body_attack();
            }
            if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
                F(s32, 0x864) = 1;
                F(s32, 0x868) = 0;
            }
            break;
        case 1:
            F(s32, 0x868) += 1;
            if (F(s32, 0x868) >= 0x32) {
                TWindowCtrl::init_all_slots2();
                restore_player_cameras();
            }
            break;
        }
        break;
    case 5:
        ((TObjEnemy *)arg0)->refresh_and_send_entity_flags();
        TBoss4DarkFalz::dispatch_by_main_phase(0x17);
        F(s32, 0x30) = 0x12008;
        ((TBoss1Dragon *)(arg0))->vfunc_74(0);
        TWindowCtrl::init_all_slots2();
        restore_player_cameras();
        if (F(u32, 0x8AC) != 0) {
            queue_destruction__7TObjectFv(F(void *, 0x8AC));
            F(u32, 0x8AC) = 0;
        }
        if (F(s32, 0x760) != 0) {
            ((TBoss1Dragon *)arg0)->release_held_player();
        }
        break;
    }
}

struct Vec_80023450 { f32 x, y, z; };

#pragma push
#pragma fp_contract on
#define TGT_80023450 ((const Vec_80023450 *)TBoss1Dragon__data_80434E80)
#define CLAMP_80023450 ((f32 (*)(void *))normalize_vector_xz__FP3Vec)
#define UPDVEL_80023450 ((s32 (*)(void *, f32))update_velocity__9TObjEneDDFv)

void TBoss1Dragon::update_emergence_state(u32 arg1) {
    f32 factor;
    extern const u8 TBoss1Dragon__data_80434E80[0xC];
    Vec_80023450 *v = (Vec_80023450 *)(((u8 *)this) + 0x890);
    f32 len;

    switch (arg1) {
    case ENEMY_STATE_ENTER:
        this->requested_action = 0x18;
        advance_animation();
        this->vfunc_96();
        this->setPhase2();
        TBoss1Dragon__sub_80028AFC(((u8 *)this));
        this->flags = (s32) (this->flags | 0xC00);
        this->flags = (s32) (this->flags & 0xFFFFFC7F);
        this->stateStep = 0;
        this->impactAge = 0;
        return;
    case 2:
    case 11:
        if (this->stateStep == 6) {
            this->request_state_change(0x19);
        }
        return;
    case 9:
        if (this->stateStep == 6) {
            this->request_state_change(8);
        }
        return;
    case 6:
        if (choose_burrow_ring_destination__12TBoss1DragonFPvPv((Dragon_80028EA8 *)this, (Vec_80028EA8 *)(((u8 *)this) + 0x394)) == 0) {
            this->targetX = (0.0f);
            this->targetY = *(f32 *)((s8 *)((u8 *)this) + 0x3C);
            this->targetZ = (0.0f);
            UPDVEL_80023450(this, (0.0f));
        }
        this->saveTargetDestination();
        return;
    case ENEMY_STATE_UPDATE:
        switch (this->stateStep) {
        case 0:
            (this->impactAge)++;
            if ((f32) this->impactAge >= (100.0f)) {
                this->stateStep = 1;
                restorePosition__12TBoss1DragonFv(this);
                this->flags |= 0x100;
                v->x = TGT_80023450->x - *(f32 *)((s8 *)((u8 *)this) + 0x38);
                v->y = (0.0f);
                v->z = TGT_80023450->z - *(f32 *)((s8 *)((u8 *)this) + 0x40);
                len = CLAMP_80023450(v);
                if (len <= (100.0f)) {
                    this->fallVelocity = (0.0f);
                    *(s32 *)((s8 *)((u8 *)this) + 0x5C) = 0;
                } else {
                    f32 k = (37.333335876464844f);
                    k += newton_sqrtf((298.66668701171875f));
                    this->fallVelocity = len / k;
                    *(s32 *)((s8 *)((u8 *)this) + 0x5C) = (s32) (boss1_dragon_angle_units_per_radian * atan2_float(this->fallVelocity, (15.0f)));
                }
                this->rotation_y = (s32) (boss1_dragon_angle_units_per_radian * atan2_float(v->x, v->z));
                this->rootHeight = (15.0f);
                v->x *= this->fallVelocity;
                v->z *= this->fallVelocity;
                factor = (-11.333333015441895f);
                *(f32 *)((s8 *)((u8 *)this) + 0x38) = v->x * factor + *(f32 *)((s8 *)((u8 *)this) + 0x38);
                *(f32 *)((s8 *)((u8 *)this) + 0x40) = v->z * factor + *(f32 *)((s8 *)((u8 *)this) + 0x40);
                this->height = (-170.0f);
                this->heightOffset = this->defaultHeightOffset + (this->height - *(f32 *)((s8 *)((u8 *)this) + 0x3C));
            }
            break;
        case 1:
            if (this->height > TGT_80023450->y) {
                this->stateStep = 2;
                this->vfunc_92();
                this->vfunc_93();
                this->setActive();
                this->spawn_impact_crater((s32)(((u8 *)this) + 0x38));
                this->apply_ground_impact_attack();
                play_se_at_pos__12TBoss1DragonFii((s32) this, 0x4003AD0F);
            }
            break;
        case 2:
            if (this->height > (110.0f)) {
                this->stateStep = 3;
            }
            break;
        case 3:
            if (this->rootHeight < (0.0f) && this->height < (220.0f)) {
                this->stateStep = 4;
                *(f32 *)((s8 *)((u8 *)this) + 0x884) = (this->rootHeight * this->rootHeight) / (80.0f);
            }
            break;
        case 4:
            if (this->rootHeight > (0.0f)) {
                this->stateStep = 5;
                this->rootHeight = (0.0f);
                this->impactAge = 0;
            }
            break;
        }
        switch (this->stateStep) {
        case 1:
            vec3_add_to(((u8 *)this) + 0x38, v);
            this->height += this->rootHeight;
            this->heightOffset = this->defaultHeightOffset + (this->height - *(f32 *)((s8 *)((u8 *)this) + 0x3C));
            break;
        case 2:
            vec3_add_to(((u8 *)this) + 0x38, v);
            this->rootHeight += (-0.4017857015132904f);
            this->height += this->rootHeight;
            this->heightOffset = this->defaultHeightOffset + (this->height - *(f32 *)((s8 *)((u8 *)this) + 0x3C));
            break;
        case 3:
            advance_animation();
            this->rootHeight += (-0.4017857015132904f);
            this->height += this->rootHeight;
            if (this->frame >= (15.0f)) {
                v->x *= (0.98f);
                v->z *= (0.98f);
            }
            vec3_add_to(((u8 *)this) + 0x38, v);
            *(s32 *)((s8 *)((u8 *)this) + 0x5C) = approach_angle_limited(*(s32 *)((s8 *)((u8 *)this) + 0x5C), 0, 0x80);
            this->heightOffset = this->height - *(f32 *)((s8 *)((u8 *)this) + 0x3C);
            break;
        case 4:
            advance_animation();
            if (this->requested_action == 0x10) {
                this->play_nearby_se();
            }
            this->rootHeight += *(f32 *)((s8 *)((u8 *)this) + 0x884);
            this->height += this->rootHeight;
            this->heightOffset = this->defaultHeightOffset + (this->height - *(f32 *)((s8 *)((u8 *)this) + 0x3C));
            v->x *= (0.98f);
            v->z *= (0.98f);
            vec3_add_to(((u8 *)this) + 0x38, v);
            break;
        case 5:
            advance_animation();
            this->play_nearby_se();
            (this->impactAge)++;
            if (this->impactAge >= 50) {
                this->stateStep = 6;
            }
            break;
        }
        break;
    case ENEMY_STATE_LEAVE:
        *(s32 *)((s8 *)((u8 *)this) + 0x5C) = 0;
        break;
    }
}

#pragma pop

#pragma push
#pragma fp_contract on
void TBoss1Dragon__sub_80023A2C(TBoss1Dragon *arg0, u32 arg1) {
    f32 temp_f1;
    s32 temp_r30;
    s32 temp_r30_2;

    switch (arg1) {
    case 4:
        ((TBoss1Dragon *)(arg0))->vfunc_96();
        arg0->setPhase2();
        TBoss1Dragon__sub_80028AFC((u8 *)arg0);
        arg0->flags = (s32) (arg0->flags | 0xC00);
        arg0->flags = (s32) (arg0->flags & 0xFFFFFC7F);
        ((TBoss1Dragon *)(arg0))->vfunc_91();
        ((TBoss1Dragon *)(arg0))->vfunc_94();
        fill_value_array((int) (*(s32 *)((s8 *)arg0 + 0x688)));
        arg0->stateStep = 0;
        arg0->impactAge = 0;
        arg0->rootHeight = calc_burrow_speed__12TBoss1DragonFPv(arg0);
        arg0->fallVelocity = (f32) ((2.5f) * arg0->rootHeight);
        *(f32 *)((s8 *)arg0 + 0x884) = (f32) (350.0f);
        *(s32 *)((s8 *)arg0 + 0x874) = 0;
        return;
    case 2:
    case 11:
        ((TBoss1Dragon *)arg0)->request_state_change(0x1B);
        return;
    case 9:
        if ((s32) *(s32 *)((s8 *)arg0 + 0x8B8) != 0) {
            next_sequence_action__12TBoss1DragonFv(arg0);
            *(s32 *)((s8 *)arg0 + 0x8B8) = 0;
            return;
        }
        if ((s32) arg0->stateStep == 2) {
            next_sequence_action__12TBoss1DragonFv(arg0);
        }
        return;
    case 6:
        *(f32 *)((s8 *)arg0 + 0x38) = (f32) ((350.0f) * sin_table_lookup(temp_r30 = (s32) ((65536.0f) * random_ratio__9TObjCharaFv())));
        *(f32 *)((s8 *)arg0 + 0x40) = (f32) ((350.0f) * cos_table_lookup(temp_r30));
        saveCurrentDestination__12TBoss1DragonFv(arg0);
        return;
    case 0:
        switch (arg0->stateStep) {
        case 2:
            break;
        case 0:
            arg0->impactAge = (arg0->impactAge + 1);
            if ((f32) arg0->impactAge >= (60.0f)) {
                arg0->impactAge = 0;
                arg0->stateStep = 1;
                ((TBoss8Dragon *)(*(s32 *)((s8 *)arg0 + 0x6D8)))->set_field_3c();
                restorePosition__12TBoss1DragonFv(arg0);
                *(s32 *)((s8 *)arg0 + 0x874) = (s32) (boss1_dragon_angle_units_per_radian * atan2_float((f32) (*(f32 *)((s8 *)arg0 + 0x38)), (f32) (*(f32 *)((s8 *)arg0 + 0x40))));
                return;
            }
            break;
        case 1:
            temp_r30_2 = (s32) (boss1_dragon_angle_units_per_radian * (arg0->fallVelocity / *(f32 *)((s8 *)arg0 + 0x884)));
            *(s32 *)((s8 *)arg0 + 0x874) += temp_r30_2;
            *(f32 *)((s8 *)arg0 + 0x38) = *(f32 *)((s8 *)arg0 + 0x884) * sin_table_lookup(*(s32 *)((s8 *)arg0 + 0x874));
            *(f32 *)((s8 *)arg0 + 0x40) = *(f32 *)((s8 *)arg0 + 0x884) * cos_table_lookup(*(s32 *)((s8 *)arg0 + 0x874));
            *(f32 *)((s8 *)arg0 + 0x884) -= (0.001068115234375f) * (f32) temp_r30_2;
            if (*(f32 *)((s8 *)arg0 + 0x884) < (5.0f)) {
                arg0->stateStep = 2;
            }
            TBoss1Dragon__sub_800277D8((u8 *)arg0);
            arg0->impactAge = (arg0->impactAge + 1);
            if ((s32) arg0->impactAge > 0xA) {
                clear_work__12TBoss1DragonFi((s32)arg0);
                arg0->impactAge = 0;
            }
            spawn_trap__12TBoss1DragonFii((s32)arg0, 0x40038F11);
            return;
        }
        break;
    case 5:
        ((TBoss1Dragon *)(arg0))->vfunc_92();
        ((TBoss1Dragon *)(arg0))->vfunc_93();
        ((TBoss8Dragon *)(*(s32 *)((s8 *)arg0 + 0x6D8)))->spawn_child_object();
        break;
    default:
        return;
    }
}
#pragma pop
#undef TBoss1Dragon__sub_800277D8
#undef clear_work__12TBoss1DragonFi
#undef calc_burrow_speed__12TBoss1DragonFPv
#undef spawn_trap__12TBoss1DragonFii

#define VecCopy__FP3VecPC3Vec ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)
#define TBoss1Dragon__sub_800277D8 ((void (*)(u8 *))TBoss1Dragon__sub_800277D8)
#define clear_work__12TBoss1DragonFi ((void (*)(s32))clear_work__12TBoss1DragonFi)
#define calc_burrow_speed__12TBoss1DragonFPv ((f32 (*)(void *))calc_burrow_speed__12TBoss1DragonFPv)
#define spawn_trap__12TBoss1DragonFii ((void (*)(s32, s32))spawn_trap__12TBoss1DragonFii)
#define sin_table_lookup ((f32 (*)(int))sin_table_lookup)
#define cos_table_lookup ((f32 (*)(int))cos_table_lookup)

#pragma push
#pragma fp_contract on
void TBoss1Dragon::update_burrow_outward_run(u32 arg1) {
    u8 *arg0 = (u8 *)this;
    u8 sp8[0xC];
    switch (arg1) {
    case ENEMY_STATE_ENTER:
        this->vfunc_96();
        ((TBoss1Dragon *)arg0)->setPhase2();
        TBoss1Dragon__sub_80028AFC(arg0);
        this->flags |= 0xC00;
        this->flags &= ~0x380;
        this->vfunc_91();
        this->vfunc_94();
        this->stateStep = 0;
        this->impactAge = 0;
        this->rootHeight = calc_burrow_speed__12TBoss1DragonFPv(arg0);
        ((TBoss8Dragon *)(*(s32 *)((s8 *)arg0 + 0x6D8)))->set_field_1c();
        if (isV2Mode__12TBoss1DragonFv() == 1 && *(s32 *)((s8 *)arg0 + 0x6DC) == 2) {
            *(s32 *)((s8 *)arg0 + 0x6DC) += 1;
            this->rootHeight = calc_burrow_speed__12TBoss1DragonFPv(arg0);
            *(s32 *)((s8 *)arg0 + 0x6DC) -= 1;
        }
        break;
    case 2:
    case 11:
        ((TBoss1Dragon *)arg0)->request_state_change(0x1B);
        break;
    case 9:
        ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(sp8, (u8 *)&this->position);
        if (((f32 (*)(void *))normalize_vector_xz__FP3Vec)(sp8) > (350.0f)) {
            next_sequence_action__12TBoss1DragonFv(arg0);
        }
        break;
    case 7:
        restoreTargetPosition__12TBoss1DragonFv();
        break;
    case 6:
        if (select_forward_target__12TBoss1DragonFPv(arg0) != 0) {
            ((TObjEneDD_ST *)arg0)->enemy_copy_target_destination();
            update_velocity__9TObjEneDDFv(arg0);
        } else {
            *(f32 *)((s8 *)arg0 + 0x3A0) = sin_table_lookup(this->rotation_y);
            *(f32 *)((s8 *)arg0 + 0x3A8) = cos_table_lookup(this->rotation_y);
        }
        this->targetX = (350.0f) * *(f32 *)((s8 *)arg0 + 0x3A0);
        this->targetY = (0.0f);
        this->targetZ = (350.0f) * *(f32 *)((s8 *)arg0 + 0x3A8);
        ((TBoss1Dragon *)arg0)->saveTargetDestination();
        break;
    case ENEMY_STATE_UPDATE:
        update_velocity__9TObjEneDDFv(arg0);
        this->rotation_y = approach_angle_limited(this->rotation_y, (s32) (boss1_dragon_angle_units_per_radian * atan2_float(*(f32 *)((s8 *)arg0 + 0x3A0), *(f32 *)((s8 *)arg0 + 0x3A8))), 0x600);
        this->position.x += this->rootHeight * sin_table_lookup(this->rotation_y);
        this->position.z += this->rootHeight * cos_table_lookup(this->rotation_y);
        TBoss1Dragon__sub_800277D8(arg0);
        this->impactAge += 1;
        if (this->impactAge > 10) {
            clear_work__12TBoss1DragonFi((s32)arg0);
            this->impactAge = 0;
        }
        spawn_trap__12TBoss1DragonFii((s32)arg0, 0x40038F11);
        break;
    case ENEMY_STATE_LEAVE:
        this->vfunc_92();
        this->vfunc_93();
        ((TBoss8Dragon *)(*(s32 *)((s8 *)arg0 + 0x6D8)))->spawn_child_object();
        break;
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
void TBoss1Dragon::update_burrow_inward_run(u32 arg1, s32 arg2) {
    f32 factor;
    s32 temp_r30;
    struct { f32 x, y, z; } v;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f2;

    switch (arg1) {
    case 4:
        this->vfunc_96();
        this->setPhase2();
        TBoss1Dragon__sub_80028AFC(((u8 *)this));
        this->flags = (s32) (this->flags | 0xC00);
        this->flags = (s32) (this->flags & 0xFFFFFC7F);
        this->vfunc_91();
        this->vfunc_94();
        if (arg2 == 0x10) {
            *(s32 *)((s8 *)((u8 *)this) + 0x6DC) = 0;
        } else {
            *(s32 *)((s8 *)((u8 *)this) + 0x6DC) = (s32) (*(s32 *)((s8 *)((u8 *)this) + 0x6DC) + 1);
        }
        fill_value_array((int) (*(s32 *)((s8 *)((u8 *)this) + 0x688)));
        this->stateStep = 0;
        this->impactAge = 0;
        this->fallVelocity = (f32) (0.0f);
        this->rootHeight = calc_burrow_speed__12TBoss1DragonFPv((void *)this);
        return;
    case 2:
    case 11:
        this->request_state_change(0x1B);
        return;
    case 9:
        if ((s32) *(s32 *)((s8 *)((u8 *)this) + 0x8B8) != 0) {
            next_sequence_action__12TBoss1DragonFv((void *)this);
            *(s32 *)((s8 *)((u8 *)this) + 0x8B8) = 0;
            return;
        }
        if ((s32) this->stateStep == 1) {
            VecCopy__FP3VecPC3Vec(&v, (void *) ((u8 *)this + 0x38));
            v.y = (0.0f);
            if (((f32 (*)(void *))normalize_vector_xz__FP3Vec)(&v) < (50.0f)) {
                next_sequence_action__12TBoss1DragonFv((void *)this);
            }
        }
        return;
    case 6:
        *(f32 *)((s8 *)((u8 *)this) + 0x38) = (f32) ((350.0f) * sin_table_lookup(temp_r30 = (s32) ((65536.0f) * random_ratio__9TObjCharaFv())));
        *(f32 *)((s8 *)((u8 *)this) + 0x40) = (f32) ((350.0f) * cos_table_lookup(temp_r30));
        saveCurrentDestination__12TBoss1DragonFv((void *)this);
        return;
    case 0:
        switch (this->stateStep) {
        case 0:
            this->impactAge = (this->impactAge + 1);
            if ((f32) this->impactAge >= (60.0f)) {
                this->impactAge = 0;
                this->stateStep = 1;
                ((TBoss8Dragon *)(*(s32 *)((s8 *)((u8 *)this) + 0x6D8)))->set_field_1c();
                restorePosition__12TBoss1DragonFv((void *)this);
                this->rotation_y = (s32) ((s32) (boss1_dragon_angle_units_per_radian * atan2_float((f32) (*(f32 *)((s8 *)((u8 *)this) + 0x38)), (f32) (*(f32 *)((s8 *)((u8 *)this) + 0x40)))) + 0x8000);
                *(f32 *)((s8 *)((u8 *)this) + 0x3A0) = sin_table_lookup(this->rotation_y);
                *(f32 *)((s8 *)((u8 *)this) + 0x3A8) = cos_table_lookup(this->rotation_y);
            }
            break;
        case 1:
            factor = (0.1f);
            this->fallVelocity = (f32) (this->fallVelocity + factor);
            if (this->fallVelocity > this->rootHeight) {
                this->fallVelocity = this->rootHeight;
            }
            *(f32 *)((s8 *)((u8 *)this) + 0x38) = (f32) ((*(f32 *)((s8 *)((u8 *)this) + 0x3A0) * this->fallVelocity) + *(f32 *)((s8 *)((u8 *)this) + 0x38));
            *(f32 *)((s8 *)((u8 *)this) + 0x40) = (f32) ((*(f32 *)((s8 *)((u8 *)this) + 0x3A8) * this->fallVelocity) + *(f32 *)((s8 *)((u8 *)this) + 0x40));
            TBoss1Dragon__sub_800277D8(((u8 *)this));
            this->impactAge = (this->impactAge + 1);
            if ((s32) this->impactAge > 0xA) {
                clear_work__12TBoss1DragonFi((s32)this);
                this->impactAge = 0;
            }
            break;
        }
        spawn_trap__12TBoss1DragonFii((s32)this, 0x40038F11);
        return;
    case 5:
        this->vfunc_92();
        this->vfunc_93();
        break;
    default:
        return;
    }
}
#pragma pop
#undef VecCopy__FP3VecPC3Vec
#undef TBoss1Dragon__sub_800277D8
#undef clear_work__12TBoss1DragonFi
#undef calc_burrow_speed__12TBoss1DragonFPv
#undef spawn_trap__12TBoss1DragonFii
#undef sin_table_lookup
#undef cos_table_lookup

#define F(T, o) (*(T *)(arg0 + (o)))
#pragma push
#pragma fp_contract on
void update_dive_state__12TBoss1DragonFv(u8 *arg0, u32 arg1) {
    f32 factor;
    extern u8 TBoss1Dragon__data_80434E80[0xC];
    Vec_80024314 pos;
    Vec_80024314 vel;
    s32 r;
    s32 a;
    f32 k;
    f32 t;
    f32 q;
    f32 c;
    f32 sn;
    f32 cs;
    f32 s;
    u8 *mem;

    switch (arg1) {
    case 4:
        F(s16, 0xB8) = 0x10;
        ((TBoss1Dragon *)(arg0))->vfunc_96();
        ((TBoss1Dragon *)arg0)->setActive();
        TBoss1Dragon__sub_80028B28(arg0);
        F(s32, 0x3C0) &= ~0xE80;
        F(s32, 0x864) = 0;
        F(f32, 0x888) = (0.0f);
        F(s32, 0x8A8) = 0;
        F(s32, 0x878) = 0;
        F(s32, 0x874) = boss1_dragon_angle_units_per_radian * atan2_float(F(f32, 0x3A0), F(f32, 0x3A8));
        factor = (5.0f);
        F(f32, 0x3AC) = F(f32, 0x3AC) + factor;
        ((TBoss1Dragon *)arg0)->init_air_turn(F(s32, 0x874));
        k = -(13.0f / lbl_805D4AF8);
        t = newton_sqrtf((2.0f + (F(f32, 0x5DC) - 169.0f / (2.0f * lbl_805D4AF8))) / -boss1_dragon_gravity);
        if (F(f32, 0x3AC) < 50.0f) {
            t = F(f32, 0x3AC) / (k + t);
            F(f32, 0x884) = t;
            F(f32, 0x880) = t;
            F(f32, 0x88C) = (0.0f);
        } else {
            q = 50.0f / t;
            F(f32, 0x884) = q;
            c = (2.0f * (q * k - (F(f32, 0x3AC) - 50.0f))) / k;
            F(f32, 0x88C) = c / k;
            F(f32, 0x880) = q - c;
        }
        F(f32, 0x888) = (13.0f);
        break;
    case 2:
        if (F(s32, 0x864) == 4) {
            ((TBoss1Dragon *)arg0)->request_state_change(0x1B);
        }
        break;
    case 11:
        if (F(s32, 0x864) == 4) {
            ((TBoss1Dragon *)arg0)->request_state_change(0x24);
        }
        break;
    case 9:
        if (F(s32, 0x864) == 4) {
            next_sequence_action__12TBoss1DragonFv(arg0);
        }
        break;
    case 7:
        restoreTargetPosition__12TBoss1DragonFv();
        if (enable_v2_features != 0) {
            update_velocity__9TObjEneDDFv(arg0);
        }
        break;
    case 6:
        if (choose_burrow_ring_destination__12TBoss1DragonFPvPv((Dragon_80028EA8 *)arg0, (Vec_80028EA8 *)(arg0 + 0x394)) == 0) {
            F(f32, 0x394) = (0.0f);
            F(f32, 0x398) = (0.0f);
            F(f32, 0x39C) = (0.0f);
        }
        update_velocity__9TObjEneDDFv(arg0);
        ((TBoss1Dragon *)arg0)->saveTargetDestination();
        break;
    case 0:
        ((TObjMotion *)arg0)->advance_animation();
        switch (F(s32, 0x864)) {
        case 0:
            ((TBoss1Dragon *)arg0)->play_nearby_se();
            TBoss1Dragon__sub_800274A4((s32)arg0);
            if (((TBoss1Dragon *)arg0)->advance_air_turn() != 0) {
                F(s32, 0x658) = 0;
                F(s32, 0x60) = F(s32, 0x874);
                F(s32, 0x864) = 1;
                F(s16, 0xB8) = 0x16;
            }
            break;
        case 1:
            if (F(f32, 0xC0) >= TBoss1Dragon__data_805D8008) {
                F(s32, 0x864) = 2;
                F(s32, 0x3C0) |= 0xC00;
                play_se_at_pos__12TBoss1DragonFii((s32)arg0, 0x4003B210);
            }
            break;
        case 2:
            if (F(f32, 0x888) > (0.0f)) {
                F(f32, 0x888) = F(f32, 0x888) + lbl_805D4AF8;
                F(f32, 0x880) = F(f32, 0x880) + F(f32, 0x88C);
                ((TObjEneDD *)arg0)->move_with_wall_stop(F(f32, 0x3A0), F(f32, 0x3A8), F(f32, 0x880));
            } else {
                F(f32, 0x888) = F(f32, 0x888) + boss1_dragon_gravity;
                ((TObjEneDD *)arg0)->move_with_wall_stop(F(f32, 0x3A0), F(f32, 0x3A8), F(f32, 0x884));
            }
            F(f32, 0x5DC) = F(f32, 0x5DC) + F(f32, 0x888);
            F(f32, 0x5D8) = F(f32, 0x3C) + F(f32, 0x5DC);
            if (F(f32, 0x888) < (0.0f)) {
                a = -(s32)(boss1_dragon_angle_units_per_radian * atan2_float(F(f32, 0x888), F(f32, 0x880)));
                if (a > F(s32, 0x5C)) {
                    F(s32, 0x5C) = a;
                }
                if (F(s32, 0x878) < 0x2800) {
                    F(s32, 0x878) += 0x120;
                }
                F(s32, 0x64) += F(s32, 0x878);
            } else {
                F(s32, 0x5C) = approach_angle_limited(F(s32, 0x5C), 0x4000, 0x200);
            }
            if (F(f32, 0x410) <= *(f32 *)(TBoss1Dragon__data_80434E80 + 4) - (50.0f)) {
                F(s32, 0x864) = 3;
                play_se_at_pos__12TBoss1DragonFii((s32)arg0, 0x4003AD0F);
            }
            if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
                F(s16, 0xB8) = 0x17;
            }
            break;
        case 3:
            if (F(f32, 0x5DC) - F(f32, 0x5E0) <= lbl_805D800C) {
                F(s32, 0x864) = 4;
                F(s32, 0x3C0) &= ~0x100;
            }
            if (F(f32, 0x5DC) - F(f32, 0x5E0) <= (0.0f) && F(s32, 0x8A8) == 0) {
                ((TBoss1Dragon *)arg0)->spawn_impact_crater((s32)(arg0 + 0x38));
                ((TBoss1Dragon *)arg0)->apply_ground_impact_attack();
                F(s32, 0x8A8) = 1;
                ((TBoss1Dragon *)(arg0))->vfunc_91();
                ((TBoss1Dragon *)(arg0))->vfunc_94();
                ((TBoss1Dragon *)arg0)->setPhase2();
            }
            r = get_random_scaled__9TObjEneDDFv(arg0);
            sn = sin_table_lookup(r);
            cs = cos_table_lookup(r);
            pos.x = (20.0f) * sn + F(f32, 0x394);
            pos.y = F(f32, 0x398);
            pos.z = (20.0f) * cs + F(f32, 0x39C);
            s = rand_range__9TObjEneDDFff(arg0, (2.0f), (0.5f));
            vel.x = sn * s;
            vel.y = rand_range__9TObjEneDDFff(arg0, TBoss1Dragon__data_805D8010, (4.0f));
            vel.z = cs * s;
            mem = (u8 *)new TObjBoss1Rock((TObject *)(void *)tl_05, (void *)(void *)&pos, (void *)(void *)&vel);
            F(f32, 0x5DC) = F(f32, 0x5DC) + F(f32, 0x888);
            ((TObjEneDD *)arg0)->move_with_wall_stop(F(f32, 0x3A0), F(f32, 0x3A8), F(f32, 0x884));
            F(f32, 0x5D8) = F(f32, 0x3C) + F(f32, 0x5DC);
            if (F(s32, 0x878) < 0x2800) {
                F(s32, 0x878) += 0x80;
            }
            F(s32, 0x64) += F(s32, 0x878);
            break;
        case 4:
            break;
        }
        break;
    case 5:
        F(s32, 0x5C) = 0;
        F(s32, 0x64) = 0;
        break;
    }
}
#pragma pop
#undef F

#define TBoss1Dragon__sub_800274A4 ((s32 (*)(void *))TBoss1Dragon__sub_800274A4)
#define saveCurrentDestination__12TBoss1DragonFv ((void (*)(void *))saveCurrentDestination__12TBoss1DragonFv)
#define restorePosition__12TBoss1DragonFv ((void (*)(void *))restorePosition__12TBoss1DragonFv)
#define TBoss1Dragon__sub_80028B28 ((s32 (*)(void *))TBoss1Dragon__sub_80028B28)
void TBoss1Dragon::update_roar_state(u32 arg1) {
    u8 *arg0 = (u8 *)this;
    s32 temp_r4;
    s32 temp_r4_2;

    switch (arg1) {
    case ENEMY_STATE_ENTER:
        this->requested_action = 0x10;
        this->vfunc_96();
        ((TBoss1Dragon *)arg0)->setActive();
        TBoss1Dragon__sub_80028B28(arg0);
        this->flags = (s32) (this->flags | 0xC00);
        temp_r4 = this->flags;
        this->flags = (s32) (temp_r4 & ~0x280);
        play_cue_stream_file(lbl_80435388, temp_r4);
        this->vfunc_91();
        this->stateStep = 0;
        return;
    case 9:
        if ((s32) this->stateStep >= 0x3C) {
            next_sequence_action__12TBoss1DragonFv(arg0);
            return;
        }
        break;
    case 11:
        break;
    case 7:
        restorePosition__12TBoss1DragonFv(arg0);
        return;
    case 6:
        saveCurrentDestination__12TBoss1DragonFv(arg0);
        return;
    case ENEMY_STATE_UPDATE:
        advance_animation();
        this->stateStep = this->stateStep + 1;
        play_nearby_se();
        TBoss1Dragon__sub_800274A4(arg0);
        return;
    case ENEMY_STATE_LEAVE:
        this->vfunc_92();
        break;
    }
}
#undef TBoss1Dragon__sub_800274A4
#undef saveCurrentDestination__12TBoss1DragonFv
#undef restorePosition__12TBoss1DragonFv
#undef TBoss1Dragon__sub_80028B28

#define saveCurrentDestination__12TBoss1DragonFv ((void (*)(void *))saveCurrentDestination__12TBoss1DragonFv)
#define restorePosition__12TBoss1DragonFv ((void (*)(void *))restorePosition__12TBoss1DragonFv)
#define play_cue_stream_file ((s32 (*)(void *))play_cue_stream_file)
void TBoss1Dragon::update_stretch_state(u32 arg1) {
    u8 *arg0 = (u8 *)this;
    s32 temp_r4;

    switch (arg1) {
    case ENEMY_STATE_ENTER:
        this->requested_action = 2;
        this->vfunc_95();
        clearState__12TBoss1DragonFv(arg0);
        beginHeightTransition__12TBoss1DragonFv(arg0);
        this->flags = (s32) (this->flags | 0xC00);
        temp_r4 = this->flags;
        this->flags = (s32) (temp_r4 & ~0x280);
        ((TBoss1Dragon *)(arg0))->vfunc_91();
        return;
    case 2:
    case 11:
        if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
            ((TBoss1Dragon *)arg0)->request_state_change(0x17);
            return;
        }
        break;
    case 9:
        if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
            next_sequence_action__12TBoss1DragonFv(arg0);
            return;
        }
        break;
    case 7:
        restorePosition__12TBoss1DragonFv(arg0);
        return;
    case 6:
        saveCurrentDestination__12TBoss1DragonFv(arg0);
        return;
    case ENEMY_STATE_UPDATE:
        advance_animation();
        if (((TObjMotion *)arg0)->is_passing_frame((20.0f)) != 0) {
            play_cue_stream_file(lbl_80435388);
            return;
        }
        break;
    case ENEMY_STATE_LEAVE:
        this->vfunc_92();
        break;
    }
}
#undef saveCurrentDestination__12TBoss1DragonFv
#undef restorePosition__12TBoss1DragonFv
#undef play_cue_stream_file

#define filter_input_flags__12TBoss1DragonFiii ((s32 (*)(s32, s32, s32))filter_input_flags__12TBoss1DragonFiii)
#define TBoss1Dragon__sub_80027010 ((f32 (*)(void *, f32, f32, f32))TBoss1Dragon__sub_80027010)
#define saveCurrentDestination__12TBoss1DragonFv ((s32 (*)(void))saveCurrentDestination__12TBoss1DragonFv)
#define restorePosition__12TBoss1DragonFv ((s32 (*)(void))restorePosition__12TBoss1DragonFv)
#define spawn_trap__12TBoss1DragonFii ((void (*)(s32, s32))spawn_trap__12TBoss1DragonFii)
#define play_se_at_pos__12TBoss1DragonFii ((void (*)(s32, s32))play_se_at_pos__12TBoss1DragonFii)
#define sin_table_lookup ((f32 (*)(int))sin_table_lookup)
#define cos_table_lookup ((f32 (*)(int))cos_table_lookup)
void TBoss1Dragon::update_head_down_attack_state(u32 arg1) {
    u8 *arg0 = (u8 *)this;
    f32 var_f31;
    f32 temp_f30;
    f32 temp_f29;
    f32 temp_f1;

    switch (arg1) {
    case ENEMY_STATE_ENTER:
        this->requested_action = 8;
        this->vfunc_96();
        clearState__12TBoss1DragonFv(arg0);
        beginHeightTransition__12TBoss1DragonFv(arg0);
        this->flags = (s32) (this->flags | 0x680);
        this->flags = (this->flags & 0xFFFFF7FF);
        this->stateStep = 0;
        this->impactAge = 0;
        play_se_at_pos__12TBoss1DragonFii((s32)arg0, 0x4003AD06);
        return;
    case 11:
        if (((s32) this->stateStep >= 0x96) && (filter_input_flags__12TBoss1DragonFiii((s32)arg0, *(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x6E4)) + 8), 2) != 0)) {
            this->stateStep = 0x1C2;
        }
        if (((s32) this->impactAge == 2) && (((TObjEneDD *)arg0)->get_flag_b4() != 0)) {
            ((TBoss1Dragon *)arg0)->request_state_change(0x17);
        }
        return;
    case 2:
        if (((s32) this->impactAge == 2) && (((TObjEneDD *)arg0)->get_flag_b4() != 0)) {
            ((TBoss1Dragon *)arg0)->request_state_change(0x17);
            return;
        }
        break;
    case 9:
        if (((s32) this->impactAge == 2) && (((TObjEneDD *)arg0)->get_flag_b4() != 0)) {
            ((TBoss1Dragon *)arg0)->remap_sequence_after_recovery();
            return;
        }
        break;
    case 7:
        restorePosition__12TBoss1DragonFv();
        return;
    case 6:
        saveCurrentDestination__12TBoss1DragonFv();
        return;
    case ENEMY_STATE_UPDATE:
        advance_animation();
        switch (this->impactAge) {
        case 0:
            if (((TObjMotion *)arg0)->is_passing_frame(lbl_805D8014) != 0) {
                apply_head_fall_attack();
            } else if (((TObjMotion *)arg0)->is_passing_frame(TBoss1Dragon__data_805D8018) != 0) {
                ((void (*)(void *))update_from_data__12TBoss1DragonFv)(arg0);
            } else if (((TObjMotion *)arg0)->is_passing_frame(TBoss1Dragon__data_805D8008) != 0) {
                ((void (*)(void *))sweep_head_fall_spheres_late__12TBoss1DragonFv)(arg0);
            }
            if ((s16) this->requested_action != 8) {
                enable_dragon_blocking_bodies((int) (*(s32 *)((s8 *)arg0 + 0x68C)), (u8 *)&this->position, this->rotation_y);
                this->impactAge = 1;
                return;
            }
            break;
        case 1:
            spawn_trap__12TBoss1DragonFii((s32)arg0, 0x4003AD12);
            this->stateStep = (this->stateStep + 1);
            if ((s32) this->stateStep >= 0x1C2) {
                this->requested_action = 0xA;
                this->impactAge = 2;
                disable_dragon_blocking_bodies((int) (*(s32 *)((s8 *)arg0 + 0x68C)));
                return;
            }
            break;
        case 2:
            var_f31 = lbl_805D801C;
            temp_f30 = sin_table_lookup(this->rotation_y);
            temp_f29 = cos_table_lookup(this->rotation_y);
            if ((s32) *(s32 *)((s8 *)arg0 + 0x760) != 0) {
                var_f31 = TBoss1Dragon__sub_80027010(arg0, temp_f30, temp_f29, lbl_805D801C);
            }
            temp_f1 = this->frame;
            if ((temp_f1 >= (13.0f)) && (temp_f1 <= (20.0f))) {
                ((TObjEneDD *)arg0)->move_to_shot_position(temp_f30, temp_f29, var_f31);
                return;
            }
            break;
        }
        break;
    case ENEMY_STATE_LEAVE:
        this->update_damage_threshold();
        disable_dragon_blocking_bodies((int) (*(s32 *)((s8 *)arg0 + 0x68C)));
        break;
    default:
        return;
    }
}
#undef filter_input_flags__12TBoss1DragonFiii
#undef TBoss1Dragon__sub_80027010
#undef saveCurrentDestination__12TBoss1DragonFv
#undef restorePosition__12TBoss1DragonFv
#undef spawn_trap__12TBoss1DragonFii
#undef play_se_at_pos__12TBoss1DragonFii
#undef sin_table_lookup
#undef cos_table_lookup

void TBoss1Dragon::handleFallState(u32 reason) {
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;
    switch (reason) {
    case ENEMY_STATE_ENTER:
        this->requested_action = 0x11;
        this->vfunc_96();
        this->clearState();
        TBoss1Dragon__sub_80028B28((u8 *)this);
        this->flags = (s32) (this->flags | 0xE80);
        this->stateStep = 0;
        this->fallVelocity = (f32) (0.0f);
        this->impactAge = 0;
        return;
    case 2:
    case 11:
        this->controlTimer = 0;
        if (get_flag_b4() != 0) {
            this->request_state_change(0x17);
        }
        return;
    case 9:
        if (get_flag_b4() != 0) {
            switch (this->mode) {
            default:
            case 8:
                next_sequence_action__12TBoss1DragonFv(this);
                return;
            case 10:
                this->request_state_change(9);
                return;
            case 11:
                this->request_state_change(0xD);
                return;
            case 12:
                this->request_state_change(0x15);
                return;
            }
        }
        break;
    case 7:
        this->restorePosition();
        return;
    case 6:
        this->saveCurrentDestination();
        return;
    case ENEMY_STATE_UPDATE:
        switch (this->stateStep) {
        case 1:
            break;
        case 0:
            advance_animation();
            this->rootHeight = sample_root_height();
            if (this->frame >= lbl_805D8020) {
                this->stateStep = 1;
            }
            if (is_passing_frame((2.0f)) != 0) {
                play_se_at_pos__12TBoss1DragonFii((s32)this, 0x4003A804);
            }
            if (is_passing_frame(lbl_805D8024) != 0) {
                update_switch_attack();
            }
            break;
        case 2:
            advance_animation();
            break;
        }
        switch (this->stateStep) {
        case 0:
            if (this->frame > TBoss1Dragon__data_805D8008) {
                this->fallVelocity = (f32) (this->fallVelocity + TBoss1Dragon__gravity_accel);
                this->height = (f32) (this->height + this->fallVelocity);
            }
            this->heightOffset = (f32) (this->defaultHeightOffset + ((this->height - this->rootHeight) - this->position.y));
            return;
        case 1:
            this->fallVelocity = (f32) (this->fallVelocity + TBoss1Dragon__gravity_accel);
            this->height = (f32) (this->height + this->fallVelocity);
            temp_f3 = this->position.y;
            temp_f1 = this->rootHeight;
            temp_f2 = this->height;
            if (temp_f2 < (temp_f3 + temp_f1)) {
                this->stateStep = 2;
                this->height = (f32) this->position.y;
                this->heightOffset = (f32) this->defaultHeightOffset;
                play_se_at_pos__12TBoss1DragonFii((s32)this, 0x4003AD0E);
                return;
            }
            this->heightOffset = (f32) (this->defaultHeightOffset + ((temp_f2 - temp_f1) - temp_f3));
            return;
        case 2:
            this->impactAge = (this->impactAge + 1);
            if ((s32) this->impactAge == 4) {
                spawn_particle_effect_with_flags(((void *) &this->position.x), (s32)this->effectResource->data, 0x40);
                TCameraCtrl::set_shake_preset(1);
                apply_landing_attack__12TBoss1DragonFi((s32)this);
                return;
            }
            break;
        }
        break;
    case ENEMY_STATE_LEAVE:
        this->beginHeightTransition();
        break;
    default:
        return;
    }
}

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
void TBoss1Dragon::update_spinning_projectile_attack(u32 reason) {
    TBoss1Dragon *self = this;

    switch (reason) {
    case ENEMY_STATE_ENTER:
        self->requested_action = 0x16;
        self->vfunc_96();
        self->setActive();
        TBoss1Dragon__sub_80028B28((u8 *)self);
        self->flags |= 0xC00;
        self->flags &= ~0x280;
        self->stateStep = 0;
        self->impactAge = 0;
        self->m_86c = 0;
        self->m_874 = 0;
        self->fallVelocity = (13.0f);
        break;
    case 2:
    case 11:
        ((TBoss1Dragon *)self)->request_state_change(0x19);
        break;
    case 9:
        if (self->stateStep == 6) {
            next_sequence_action__12TBoss1DragonFv(self);
        }
        break;
    case 7: {
        u32 seed = (u32)(s32)((100.0f) * self->savedX);
        s32 low = (s32)((100.0f) * self->savedZ);
        seed *= 0x10000UL;
        seed |= (u32)low & 0xFFFFUL;
        subtractive_rng_seed(self->randomState, seed);
        break;
    }
    case 6:
        self->saveCurrentDestination();
        break;
    case ENEMY_STATE_UPDATE:
        switch (self->stateStep) {
        case 0:
            self->advance_animation();
            if (self->frame >= TBoss1Dragon__data_805D8008) {
                self->stateStep = 1;
                play_se_at_pos__12TBoss1DragonFii((s32)self, 0x4003B210);
            }
            break;
        case 1:
            self->advance_animation();
            if (self->frame > lbl_805D8028) {
                self->rotation_x = (s32)(lbl_805D802C * ((self->frame - lbl_805D8028) / (self->frame_count - lbl_805D8028)));
            }
            if (self->get_flag_b4() != 0) {
                self->requested_action = 0x18;
                self->stateStep = 2;
            }
            break;
        case 2:
            self->advance_animation();
            self->rotation_x = 0;
            if (self->frame > lbl_805D8028) {
                self->m_874 = 0x1000;
                self->stateStep = 3;
                self->m_654 = 1;
            }
            break;
        case 3: {
            Vec_80028CA8 position;
            s32 found;
            self->m_874 += 0x40;
            if (self->m_874 > 0x2000) {
                self->m_874 = 0x2000;
            }
            self->impactAge++;
            if (self->impactAge >= 4) {
                self->impactAge = 0;
                self->m_86c += 1;
                if (self->m_86c >= 0x28) {
                    self->stateStep = 4;
                    self->m_654 = 0;
                }
                found = 0;
                if ((self->m_86c & 1) == 0) {
                    TObjPlayer *player = (TObjPlayer *)get_player_by_client_id((u16)((self->m_86c >> 1) % 4));
                    if (is_alive__8TObjBaseFv(player) != 0) {
                        VecCopy__FP3VecPC3Vec((s32)&position, (s32)&player->position);
                        position.x += (100.0f) *
                            (calc_random_ratio__10TObjPlayerFv(self->randomState) - (0.5f));
                        position.z += (100.0f) *
                            (calc_random_ratio__10TObjPlayerFv(self->randomState) - (0.5f));
                        found = 1;
                    }
                }
                if (found == 0) {
                    position.x = lbl_805D8030 *
                        (calc_random_ratio__10TObjPlayerFv(self->randomState) - (0.5f));
                    position.y = (0.0f);
                    position.z = lbl_805D8030 *
                        (calc_random_ratio__10TObjPlayerFv(self->randomState) - (0.5f));
                }
                u8 *bullet = __nw__7TObjectFUl(0x4C);
                if (bullet != NULL) {
                    TBoss1DragonEffBullet__ct(bullet, (s32)self->unknown3C4, (s32)&self->m_40c, (s32)&position);
                }
            }
            self->rotation_x -= self->m_874;
            break;
        }
        case 4: {
            s32 angle;
            self->m_874 -= 0x50;
            if (self->m_874 < 0x1300) {
                self->m_874 = 0x1300;
                self->rotation_x -= self->m_874;
                angle = (u16)self->rotation_x;
                if (angle <= 0x1300 || angle >= 0x10000 - 0x1300) {
                    self->rotation_x = 0;
                    self->m_878 = (s32)(boss1_dragon_angle_units_per_radian *
                        atan2_float(-self->position.x, -self->position.z));
                    self->stateStep = 5;
                }
            } else {
                self->rotation_x -= self->m_874;
            }
            break;
        }
        case 5: {
            f32 delta;
            self->advance_animation();
            delta = (f32)angle_diff_s16(self->rotation_y, self->m_878);
            delta *= lbl_805D8034;
            if ((delta < lbl_805D8038 && delta >= lbl_805D803C) || self->get_flag_b4() != 0) {
                self->rotation_y = self->m_878;
                self->stateStep = 6;
            } else {
                self->rotation_y += (s32)delta;
            }
            break;
        }
        case 6:
            self->advance_animation();
            break;
        }
        if (self->stateStep == 1 || self->stateStep == 2) {
            self->fallVelocity += lbl_805D4B40;
            if (self->fallVelocity < (0.0f)) {
                self->fallVelocity = (0.0f);
            }
            self->heightOffset += self->fallVelocity;
            if (self->heightOffset - self->defaultHeightOffset <= TBoss1Dragon__data_805D8040) {
                self->heightOffset = TBoss1Dragon__data_805D8040 + self->defaultHeightOffset;
            }
        }
        if (self->stateStep == 3 || self->stateStep == 4 || self->stateStep == 5) {
            self->heightOffset -= (1.0f);
            if (self->heightOffset - self->defaultHeightOffset < TBoss1Dragon__data_805D8040) {
                self->heightOffset = TBoss1Dragon__data_805D8040 + self->defaultHeightOffset;
            }
        }
        self->height = self->position.y + self->heightOffset;
        break;
    case ENEMY_STATE_LEAVE:
        self->rotation_x = 0;
        sub_8002AE64__9TObjEnemyFv(self);
        self->m_654 = 0;
        break;
    }
}
#pragma pop

#define VecCopy__FP3VecPC3Vec ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)
#pragma push
#pragma fp_contract on
void TBoss1Dragon::update_air_fire_state(u32 arg1) {
    extern u8 TBoss1Dragon__data_80434E80[0xC];
    Vec_80025710 *tgt;
    f32 dist;
    Vec_80025710 dest;
    Vec_80025710 d;
    Vec_80025710 out;
    u8 *obj;
    u8 *arg0 = (u8 *)this;

    tgt = (Vec_80025710 *)(arg0 + 0x890);
    switch (arg1) {
    case ENEMY_STATE_ENTER:
        this->requested_action = 0x10;
        ((TBoss1Dragon *)(arg0))->vfunc_96();
        ((TBoss1Dragon *)arg0)->setActive();
        TBoss1Dragon__sub_80028B28(arg0);
        this->flags &= ~0xE80;
        this->stateStep = 0;
        this->impactAge = 0;
        *(s32 *)((s8 *)arg0 + 0x86C) = 0;
        *(u32 *)((s8 *)arg0 + 0x8AC) = 0;
        break;
    case 2:
    case 11:
        if (this->stateStep == 3) {
            ((TBoss1Dragon *)arg0)->request_state_change(0x19);
        }
        break;
    case 9:
        if (this->stateStep == 4) {
            next_sequence_action__12TBoss1DragonFv(arg0);
        }
        break;
    case ENEMY_STATE_UPDATE:
        ((TObjMotion *)arg0)->advance_animation();
        switch (this->stateStep) {
        case 0:
            if (((TBoss1Dragon *)arg0)->select_air_fire_target(tgt) != 0) {
                *(s32 *)((s8 *)arg0 + 0x874) = (s32)(boss1_dragon_angle_units_per_radian * atan2_float(tgt->x - *(f32 *)((s8 *)arg0 + 0x38), tgt->z - *(f32 *)((s8 *)arg0 + 0x40)));
            } else {
                *(s32 *)((s8 *)arg0 + 0x874) = get_random_scaled__9TObjEneDDFv(arg0);
                tgt->x = lbl_805D8044 * sin_table_lookup(*(s32 *)((s8 *)arg0 + 0x874));
                tgt->y = (0.0f);
                tgt->z = lbl_805D8044 * cos_table_lookup(*(s32 *)((s8 *)arg0 + 0x874));
            }
            *(s32 *)((s8 *)arg0 + 0x874) = (s16)*(s32 *)((s8 *)arg0 + 0x874);
            this->stateStep = 1;
            if (*(s32 *)((s8 *)arg0 + 0x760) != 0) {
                *(s32 *)((s8 *)arg0 + 0x874) = (s16)this->rotation_y;
                VecCopy__FP3VecPC3Vec(tgt, (u8 *)&this->position);
                tgt->x = lbl_805D8044 * sin_table_lookup(*(s32 *)((s8 *)arg0 + 0x874)) + tgt->x;
                tgt->y = (0.0f);
                tgt->z = lbl_805D8044 * cos_table_lookup(*(s32 *)((s8 *)arg0 + 0x874)) + tgt->z;
                this->stateStep = 2;
                *(s32 *)((s8 *)arg0 + 0x658) = 0;
                this->rotation_y = *(s32 *)((s8 *)arg0 + 0x874);
                this->requested_action = 0x12;
                this->flags |= 0xC00;
            }
            ((TBoss1Dragon *)arg0)->set_result_flag(this->rotation_y, *(s32 *)((s8 *)arg0 + 0x874));
            ((TBoss1Dragon *)arg0)->init_air_turn(*(s32 *)((s8 *)arg0 + 0x874));
        case 1:
            ((TBoss1Dragon *)arg0)->play_nearby_se();
            TBoss1Dragon__sub_800274A4((s32)arg0);
            if (((TBoss1Dragon *)arg0)->advance_air_turn() != 0) {
                *(s32 *)((s8 *)arg0 + 0x658) = 0;
                this->rotation_y = *(s32 *)((s8 *)arg0 + 0x874);
                this->stateStep = 2;
                this->requested_action = 0x12;
                this->flags |= 0xC00;
            }
            break;
        case 2:
            if (((TObjMotion *)arg0)->is_passing_frame((f32)(2.0f)) != 0) {
                play_se_at_pos__12TBoss1DragonFii((s32)arg0, 0x4003A804);
            }
            if (((TObjMotion *)arg0)->is_passing_frame((f32)lbl_805D8048) != 0) {
                play_se_at_pos__12TBoss1DragonFii((s32)arg0, 0x4003AD0A);
            }
            if (((TObjMotion *)arg0)->is_passing_frame((f32)TBoss1Dragon__data_805D8018) != 0 || ((TObjMotion *)arg0)->is_passing_frame((f32)((f32)lbl_805D804C)) != 0) {
                ((TBoss1Dragon *)arg0)->update_switch_attack();
            }
            if (*(void **)((s8 *)arg0 + 0x8AC) == NULL) {
                if (this->frame >= (20.0f)) {
                    *(u32 *)((s8 *)arg0 + 0x8AC) = (u32)spawn_continuous_particle_effect_with_flags(arg0 + 0x40C, *(s32 *)((s8 *)this->effectResource + 0x18), 0x40);
                }
            } else if (this->frame <= (40.0f)) {
                ((TParticleCtrl *)*(void **)((s8 *)arg0 + 0x8AC))->set_position(arg0 + 0x40C);
            } else {
                queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x8AC));
                *(u32 *)((s8 *)arg0 + 0x8AC) = 0;
            }
            if (((TObjMotion *)arg0)->is_passing_frame((f32)lbl_805D8050) != 0) {
                VecCopy__FP3VecPC3Vec(&d, tgt);
                subtract_vector(&d, (u8 *)&this->position);
                dist = ((f32 (*)(void *))normalize_vector_xz__FP3Vec)(&d);
                d.y = (0.0f);
                VecCopy__FP3VecPC3Vec(&dest, tgt);
                dest.y = *(f32 *)((s8 *)TBoss1Dragon__data_80434E80 + 4);
                obj = __nw__7TObjectFUl(0x4C);
                if (obj != NULL) {
                    TBoss1DragonEffBullet__ct((u8 *)obj, (s32)(arg0 + 0x3C4), (s32)(arg0 + 0x40C), (s32)&dest);
                }
                rotate_vec_xz(&d, &out, 0x1000);
                VecCopy__FP3VecPC3Vec(&dest, (u8 *)&this->position);
                dest.x = out.x * dist + dest.x;
                dest.y = *(f32 *)((s8 *)TBoss1Dragon__data_80434E80 + 4);
                dest.z = out.z * dist + dest.z;
                obj = __nw__7TObjectFUl(0x4C);
                if (obj != NULL) {
                    TBoss1DragonEffBullet__ct((u8 *)obj, (s32)(arg0 + 0x3C4), (s32)(arg0 + 0x40C), (s32)&dest);
                }
                rotate_vec_xz(&d, &out, -0x1000);
                VecCopy__FP3VecPC3Vec(&dest, (u8 *)&this->position);
                dest.x = out.x * dist + dest.x;
                dest.y = *(f32 *)((s8 *)TBoss1Dragon__data_80434E80 + 4);
                dest.z = out.z * dist + dest.z;
                obj = __nw__7TObjectFUl(0x4C);
                if (obj != NULL) {
                    TBoss1DragonEffBullet__ct((u8 *)obj, (s32)(arg0 + 0x3C4), (s32)(arg0 + 0x40C), (s32)&dest);
                }
                spawn_particle_effect_with_flags(arg0 + 0x40C, *(s32 *)((s8 *)this->effectResource + 0x1C), 0x40);
                this->stateStep = 3;
                *(s32 *)((s8 *)arg0 + 0x86C) = 0;
                this->flags &= ~0xC00;
            }
            break;
        case 3:
            (*(s32 *)((s8 *)arg0 + 0x86C))++;
            if (*(s32 *)((s8 *)arg0 + 0x86C) > 0xA) {
                (this->impactAge)++;
                if (this->impactAge >= 2) {
                    this->stateStep = 4;
                } else {
                    this->stateStep = 0;
                }
            }
            break;
        }
        break;
    case ENEMY_STATE_LEAVE:
        if (*(void **)((s8 *)arg0 + 0x8AC) != NULL) {
            queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x8AC));
            *(u32 *)((s8 *)arg0 + 0x8AC) = 0;
        }
        break;
    }
}
#pragma pop
#undef VecCopy__FP3VecPC3Vec

#define prepare_flight_destination__12TBoss1DragonFPv ((s32 (*)(void *, void *))prepare_flight_destination__12TBoss1DragonFPv)
#pragma push
#pragma fp_contract on
void TBoss1Dragon::update_flight_state(u32 arg1) {
    u8 *arg0 = (u8 *)this;
    f32 *base;
    s32 var;
    s32 old;
    f32 t;

    base = (f32 *)(arg0 + 0x890);
    switch (arg1) {
    case ENEMY_STATE_ENTER:
        this->requested_action = 0x10;
        this->vfunc_96();
        ((TBoss1Dragon *)arg0)->setActive();
        TBoss1Dragon__sub_80028B28(arg0);
        old = this->flags;
        this->flags = old & ~0xE80;
        ((s32 (*)(void *, s32))update_velocity__9TObjEneDDFv)(arg0, old);
        switch (isV2Mode__12TBoss1DragonFv()) {
        case 0:
            init_acceleration_curve(arg0 + 0x5F4, (0.1f), lbl_805D8054, *(f32 *)((s8 *)arg0 + 0x3AC), (2.0f));
            break;
        case 1:
            init_acceleration_curve(arg0 + 0x5F4, (0.1f), lbl_805D8054, *(f32 *)((s8 *)arg0 + 0x3AC), *(f32 *)((s8 *)(*(G_80025C68 *)&TBoss1Dragon__data_804FE17C).value + 0x14));
            break;
        }
        VecCopy__FP3VecPC3Vec((s32)base, (s32)(arg0 + 0x38));
        var = angle_diff_s16(this->rotation_y, (s32)(boss1_dragon_angle_units_per_radian * atan2_float(*(f32 *)((s8 *)arg0 + 0x3A0), *(f32 *)((s8 *)arg0 + 0x3A8))));
        if (var >= 0) {
            *(s32 *)((s8 *)arg0 + 0x65C) = 1;
        } else {
            var = -var;
            *(s32 *)((s8 *)arg0 + 0x65C) = -1;
        }
        switch (isV2Mode__12TBoss1DragonFv()) {
        case 0:
            init_acceleration_curve(arg0 + 0x618, lbl_805D8058, lbl_805D805C, (f32)var, lbl_805D8038);
            break;
        case 1:
            init_acceleration_curve(arg0 + 0x618, lbl_805D8058, lbl_805D805C, (f32)var, (f32)(s32)(lbl_805D8060 * *(f32 *)((s8 *)(*(G_80025C68 *)&TBoss1Dragon__data_804FE17C).value + 0x14)));
            break;
        }
        *(s32 *)((s8 *)arg0 + 0x874) = this->rotation_y;
        this->stateStep = 0;
        this->fallVelocity = (0.0f);
        break;
    case 2:
        ((TBoss1Dragon *)arg0)->request_state_change(0x19);
        break;
    case 11:
        if (this->stateStep == 2) {
            ((TBoss1Dragon *)arg0)->request_state_change(0xF);
        }
        break;
    case 9:
        if (this->stateStep == 2) {
            next_sequence_action__12TBoss1DragonFv(arg0);
        }
        break;
    case 7:
        restoreTargetPosition__12TBoss1DragonFv();
        break;
    case 6:
        prepare_flight_destination__12TBoss1DragonFPv(arg0, (u8 *)&this->targetX);
        ((TBoss1Dragon *)arg0)->saveTargetDestination();
        break;
    case ENEMY_STATE_UPDATE:
        ((TObjMotion *)arg0)->advance_animation();
        play_nearby_se();
        TBoss1Dragon__sub_800274A4((s32)arg0);
        switch (this->stateStep) {
        case 0:
            this->fallVelocity += (1.0f);
            t = sample_acceleration_curve(arg0 + 0x618, this->fallVelocity);
            this->rotation_y = (s32)((f32)*(s32 *)((s8 *)arg0 + 0x65C) * t + (f32)*(s32 *)((s8 *)arg0 + 0x874));
            if (((TObjBoss2Tunnel *)(arg0 + 0x618))->check_param_threshold(this->fallVelocity) != 0) {
                this->fallVelocity = (0.0f);
                this->stateStep = 1;
            }
            break;
        case 1:
            this->fallVelocity += (1.0f);
            t = sample_acceleration_curve(arg0 + 0x5F4, this->fallVelocity);
            this->position.x = *(f32 *)((s8 *)arg0 + 0x3A0) * t + base[0];
            this->position.z = *(f32 *)((s8 *)arg0 + 0x3A8) * t + base[2];
            if (((TObjBoss2Tunnel *)(arg0 + 0x5F4))->check_param_threshold(this->fallVelocity) != 0) {
                this->stateStep = 2;
            }
            break;
        }
        break;
    case ENEMY_STATE_LEAVE:
        VecCopy__FP3VecPC3Vec((s32)(arg0 + 0x5E8), (s32)(arg0 + 0x3A0));
        break;
    }
}
#pragma pop
#undef prepare_flight_destination__12TBoss1DragonFPv

void TBoss1Dragon::update_lift_state(u32 arg1) {
    u8 *arg0 = (u8 *)this;
    TBoss1Dragon *self = (TBoss1Dragon *)arg0;

    switch (arg1) {
    case 4:
        self->requested_action = 0xF;
        advance_animation();
        this->vfunc_96();
        self->clearState();
        self->beginHeightTransition();
        self->flags = self->flags & ~0xE80;
        self->stateStep = 0;
        self->fallVelocity = (0.0f);
        self->impactAge = 0;
        self->height = self->position.y;
        return;
    case 2:
    case 11:
        self->controlTimer = 0;
        if (self->fallVelocity < (0.0f)) {
            ((TBoss1Dragon *)self)->request_state_change(0x19);
        }
        return;
    case 9:
        if (self->fallVelocity < (0.0f)) {
            next_sequence_action__12TBoss1DragonFv(self);
            return;
        }
        break;
    case 7:
        self->restorePosition();
        return;
    case 6:
        self->saveCurrentDestination();
        return;
    case 0:
        self->stateStep = self->stateStep + 1;
        switch (self->impactAge) {
        case 0:
            if ((self->frame + ((TBoss1Dragon *)self)->play_speed) >= (40.0f)) {
                f32 t;
                self->rootHeight = ((TBoss1Dragon *)self)->sample_root_height();
                t = lbl_805D8064 * lbl_805D4AF0;
                self->fallVelocity = newton_sqrtf(t * (TBoss1Dragon__data_805D8040 - self->rootHeight));
                self->impactAge = 1;
                self->flags = self->flags | 0xC00;
                self->setActive();
            }
            break;
        }
        self->advance_animation();
        if (((TObjMotion *)self)->is_passing_frame((f32)TBoss1Dragon__data_805D8018) != 0) {
            play_se_at_pos__12TBoss1DragonFii((s32)self, 0x4003A804);
        }
        if (((TObjMotion *)self)->is_passing_frame((f32)lbl_805D8068) != 0) {
            play_se_at_pos__12TBoss1DragonFii((s32)self, 0x4003A803);
        }
        if (((TObjMotion *)self)->is_passing_frame((f32)lbl_805D806C) != 0) {
            spawn_particle_effect_with_flags(&self->position.x, self->effectResource->unknown00[1], 0x40);
        }
        switch (self->impactAge) {
        case 1:
            self->heightOffset = self->defaultHeightOffset + (self->rootHeight - ((TBoss1Dragon *)self)->sample_root_height());
            self->height = self->position.y + self->rootHeight;
            self->rootHeight = self->rootHeight + self->fallVelocity;
            self->fallVelocity = self->fallVelocity + lbl_805D4AF0;
            break;
        case 0:
            break;
        }
        break;
    default:
        return;
    }
}

#define next_sequence_action__12TBoss1DragonFv ((s32 (*)(void *))next_sequence_action__12TBoss1DragonFv)
#define beginHeightTransition__12TBoss1DragonFv ((void (*)(void *))beginHeightTransition__12TBoss1DragonFv)
#define clearState__12TBoss1DragonFv ((void (*)(void *))clearState__12TBoss1DragonFv)
void TBoss1Dragon::update_tail_attack_state(u32 arg1) {
    TBoss1Dragon *self = this;
    switch (arg1) {
    case 4:
        self->requested_action = 7;
        self->vfunc_96();
        clearState__12TBoss1DragonFv(self);
        beginHeightTransition__12TBoss1DragonFv(self);
        self->flags &= ~0xC80;
        self->flags |= 0x200;
        self->stateStep = 0;
        ((TBoss1DragonEffTail *)(self->tail))->enable();
        break;
    case 2:
    case 11:
        if (((TObjEneDD *)self)->get_flag_b4() != 0) {
            ((TBoss1Dragon *)self)->request_state_change(0x17);
        }
        break;
    case 9:
        if (((TObjEneDD *)self)->get_flag_b4() != 0) {
            next_sequence_action__12TBoss1DragonFv(self);
        }
        break;
    case 0:
        advance_animation();
        self->stateStep++;
        if (((TObjMotion *)self)->is_passing_frame((f32)(0.0f)) != 0 ||
            ((TObjMotion *)self)->is_passing_frame((f32)(12.0f)) != 0) {
            play_se_at_pos__12TBoss1DragonFii((s32)self, 0x4003AD09);
        }
        if (self->stateStep > 1) {
            if (((TObjMotion *)self)->is_passing_frame((f32)TBoss1Dragon__data_805D8010) != 0) {
                ((TBoss1DragonEffTail *)(self->tail))->disable();
            } else if (((TObjMotion *)self)->is_passing_frame((f32)lbl_805D8070) != 0) {
                ((TBoss1DragonEffTail *)(self->tail))->enable();
            }
            self->tail->run_task();
        }
        break;
    }
}
#undef next_sequence_action__12TBoss1DragonFv
#undef beginHeightTransition__12TBoss1DragonFv
#undef clearState__12TBoss1DragonFv

#define next_sequence_action__12TBoss1DragonFv ((s32 (*)(void))next_sequence_action__12TBoss1DragonFv)
#define spawn_trap__12TBoss1DragonFii ((void (*)(s32, s32))spawn_trap__12TBoss1DragonFii)
#define calc_target_vector__12TBoss1DragonFPv ((void (*)(u8 *))calc_target_vector__12TBoss1DragonFPv)
#define sin_table_lookup ((f32 (*)(int))sin_table_lookup)
#define cos_table_lookup ((f32 (*)(int))cos_table_lookup)
#pragma push
#pragma fp_contract on
#pragma push
#pragma opt_common_subs off
void TBoss1Dragon::update_breath_attack_state(u32 arg1) {
    u8 *arg0 = (u8 *)this;
    DragonEffectRotation rotation;

    switch (arg1) {
    case ENEMY_STATE_ENTER:
        this->requested_action = 4;
        this->vfunc_96();
        clearState__12TBoss1DragonFv(arg0);
        beginHeightTransition__12TBoss1DragonFv(arg0);
        this->flags = (s32) (this->flags & ~0xE80);
        this->stateStep = 0;
        this->impactAge = 2;
        *(s32 *)((s8 *)arg0 + 0x86C) = 0;
        *(u32 *)((s8 *)arg0 + 0x8AC) = 0U;
        *(u32 *)((s8 *)arg0 + 0x8B0) = 0U;
        *(u32 *)((s8 *)arg0 + 0x8B4) = 0U;
        return;
    case 2:
    case 11:
        if ((s32) this->stateStep == 3) {
            ((TBoss1Dragon *)arg0)->request_state_change(0x17);
        }
        return;
    case 9:
        if ((s32) this->stateStep == 3) {
            next_sequence_action__12TBoss1DragonFv();
            return;
        }
        break;
    case 7:
        restoreTargetPosition__12TBoss1DragonFv();
        return;
    case 6:
        if (enemy_validate_retained_target() != 0) {
            ((TObjEneDD_ST *)arg0)->enemy_copy_target_destination();
        } else {
            this->targetX = (f32) ((lbl_805D8074 * sin_table_lookup(this->rotation_y)) + *(f32 *)((s8 *)arg0 + 0x40C));
            this->targetY = (f32) this->position.y;
            this->targetZ = (f32) ((lbl_805D8074 * cos_table_lookup(this->rotation_y)) + *(f32 *)((s8 *)arg0 + 0x414));
        }
        ((TBoss1Dragon *)arg0)->saveTargetDestination();
        return;
    case ENEMY_STATE_UPDATE:
        advance_animation();
        switch (this->stateStep) {
        case 0:
            update_velocity__9TObjEneDDFv(arg0);
            calc_target_vector__12TBoss1DragonFPv(arg0);
            this->rotation_y = approach_angle_limited(this->rotation_y, ((s32) (boss1_dragon_angle_units_per_radian * atan2_float((f32) (*(f32 *)((s8 *)arg0 + 0x3A0)), (f32) (*(f32 *)((s8 *)arg0 + 0x3A8))))), 0xA0);
            this->rotation_y = (s32) (s16) this->rotation_y;
            if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
                this->requested_action = 5;
                this->stateStep = 1;
                return;
            }
            break;
        case 1:
            *(s32 *)((s8 *)arg0 + 0x86C) = (s32) (*(s32 *)((s8 *)arg0 + 0x86C) + 1);
            if ((s32) *(s32 *)((s8 *)arg0 + 0x86C) >= 0x78) {
                this->requested_action = 6;
                if ((u32) *(u32 *)((s8 *)arg0 + 0x8AC) != 0U) {
                    queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x8AC));
                    *(u32 *)((s8 *)arg0 + 0x8AC) = 0U;
                }
                if ((u32) *(u32 *)((s8 *)arg0 + 0x8B0) != 0U) {
                    queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x8B0));
                    *(u32 *)((s8 *)arg0 + 0x8B0) = 0U;
                }
                if ((u32) *(u32 *)((s8 *)arg0 + 0x8B4) != 0U) {
                    queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x8B4));
                    *(u32 *)((s8 *)arg0 + 0x8B4) = 0U;
                }
                this->stateStep = 2;
                this->impactAge = 0;
                return;
            }
            if (!(this->motion_flags & 4)) {
                spawn_trap__12TBoss1DragonFii((s32)arg0, 0x4003AD0D);
                direction_to_rotation_xz(arg0 + 0x418, &rotation.x, &rotation.z);
                this->impactAge = (this->impactAge + 1);
                if ((s32) this->impactAge >= 2) {
                    u8 *o = __nw__7TObjectFUl(0x38);
                    if (o != 0) {
                        __ct__21TBoss1DragonEffBreathFP7TObjectPvPv(o, (u8 *)&this->unknown3C4, arg0 + 0x40C, arg0 + 0x418);
                    }
                    this->impactAge = 0;
                }
                if ((u32) *(u32 *)((s8 *)arg0 + 0x8AC) == 0U) {
                    *(u32 *)((s8 *)arg0 + 0x8AC) = spawn_particle_effect_with_rotation(arg0 + 0x40C, &rotation, (void *) (*(s32 *)((s8 *)this->effectResource + 0x10)), 0x40);
                    if ((u32) *(u32 *)((s8 *)arg0 + 0x8AC) != 0U) {
                        ((TParticleCtrl *)(*(void **)((s8 *)arg0 + 0x8AC)))->enable();
                    }
                } else {
                    ((TParticleCtrl *)*(void **)((s8 *)arg0 + 0x8AC))->set_position(arg0 + 0x424);
                    ((TParticleCtrl *)(*(void **)((s8 *)arg0 + 0x8AC)))->set_direction(&rotation);
                }
                if ((u32) *(u32 *)((s8 *)arg0 + 0x8B4) == 0U) {
                    *(u32 *)((s8 *)arg0 + 0x8B4) = spawn_particle_effect_with_rotation(arg0 + 0x40C, &rotation, (void *) (*(s32 *)((s8 *)this->effectResource + 0x14)), 0x40);
                    if ((u32) *(u32 *)((s8 *)arg0 + 0x8B4) != 0U) {
                        ((TParticleCtrl *)(*(void **)((s8 *)arg0 + 0x8B4)))->enable();
                        return;
                    }
                } else {
                    ((TParticleCtrl *)*(void **)((s8 *)arg0 + 0x8B4))->set_position(arg0 + 0x424);
                    ((TParticleCtrl *)(*(void **)((s8 *)arg0 + 0x8B4)))->set_direction(&rotation);
                    return;
                }
            }
            break;
        case 2:
            this->impactAge = (this->impactAge + 1);
            if ((s32) this->impactAge < 0x1E) {
                spawn_trap__12TBoss1DragonFii((s32)arg0, 0x4003AD0D);
            }
            if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
                this->stateStep = 3;
                return;
            }
            break;
        }
        break;
    case ENEMY_STATE_LEAVE:
        if ((u32) *(u32 *)((s8 *)arg0 + 0x8AC) != 0U) {
            queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x8AC));
            *(u32 *)((s8 *)arg0 + 0x8AC) = 0U;
        }
        if ((u32) *(u32 *)((s8 *)arg0 + 0x8B0) != 0U) {
            queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x8B0));
            *(u32 *)((s8 *)arg0 + 0x8B0) = 0U;
        }
        if ((u32) *(u32 *)((s8 *)arg0 + 0x8B4) != 0U) {
            queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x8B4));
            *(u32 *)((s8 *)arg0 + 0x8B4) = 0U;
        }
        break;
    default:
        return;
    }
}
#pragma pop
#pragma pop
#undef next_sequence_action__12TBoss1DragonFv
#undef spawn_trap__12TBoss1DragonFii
#undef calc_target_vector__12TBoss1DragonFPv
#undef sin_table_lookup
#undef cos_table_lookup


#define LINKED_800267B8 ((s32 (*)(void))TBoss1Dragon::update_linked_epsilon_position)
#define NEAR_800267B8 ((s32 (*)(void *))is_destination_ahead__12TBoss1DragonFPv)
#define VALID_800267B8 ((s32 (*)(void *))enemy_validate_retained_target)
void TBoss1Dragon::update_walking_state(u32 arg1) {
    u8 *arg0 = (u8 *)this;
    extern u8 TBoss1Dragon__data_80434E80[0xC];
    s32 ticks;
    f32 scale;
    s32 iscale;
    s32 next;
    f32 v;
    switch (arg1) {
    case 4:
        this->requested_action = 1;
        this->vfunc_96();
        clearState__12TBoss1DragonFv(arg0);
        beginHeightTransition__12TBoss1DragonFv(arg0);
        this->flags &= ~0xE80;
        this->stateStep = 0;
        switch (isV2Mode__12TBoss1DragonFv()) {
        case 0:
            this->fallVelocity = (5.0f) + TObjBoss2Tunnel::calc_scaled_value(0x100, (0.8f));
            break;
        case 1:
            {
                f32 s1 = *(f32 *)((s8 *)((*(Glob_800267B8 *)&TBoss1Dragon__data_804FE17C).value) + 0x10);
                this->fallVelocity = (5.0f) + TObjBoss2Tunnel::calc_scaled_value((s32) (lbl_805D8078 * s1), s1);
            }
            break;
        }
        break;
    case 2:
    case 11:
        ((TBoss1Dragon *)arg0)->request_state_change(0x17);
        break;
    case 9:
        ticks = this->stateStep;
        next = 0;
        if (ticks >= 150 && this->m_390 != 0) {
            if (*(f32 *)((s8 *)arg0 + 0x3AC) < this->fallVelocity) {
                next = 1;
            } else if (NEAR_800267B8(arg0) != 0) {
                next = 1;
            } else if (isV2Mode__12TBoss1DragonFv() >= 1 && this->stateStep >= 600) {
                next = 1;
            }
        } else if (ticks >= 300) {
            next = 1;
        }
        if (next != 0) {
            next_sequence_action__12TBoss1DragonFv(arg0);
        }
        break;
    case 8:
        LINKED_800267B8();
        (this->stateStep)++;
        if (this->stateStep % 20 == 19) {
            if (VALID_800267B8(arg0) != 0) {
                ((TObjEneDD_ST *)arg0)->enemy_copy_target_destination();
            } else {
                ((TObjEneDD *)arg0)->set_target_destination((const Vec *)TBoss1Dragon__data_80434E80);
            }
            ((TBoss1Dragon *)arg0)->saveTargetDestination();
            send_state_sync__12TBoss1DragonFPv((struct dragon_80028530 *)(arg0));
        }
        break;
    case 7:
        restoreTargetPosition__12TBoss1DragonFv();
        break;
    case 6:
        *(s32 *)((s8 *)arg0 + 0x3B0) = *(s32 *)((s8 *)arg0 + 0x3B4);
        if (LINKED_800267B8() != 0) {
            ((TObjEneDD_ST *)arg0)->enemy_copy_target_destination();
        } else {
            ((TObjEneDD *)arg0)->set_target_destination((const Vec *)TBoss1Dragon__data_80434E80);
        }
        ((TBoss1Dragon *)arg0)->saveTargetDestination();
        break;
    case 0:
        switch (isV2Mode__12TBoss1DragonFv()) {
        case 0:
            scale = (0.8f);
            break;
        case 1:
            scale = *(f32 *)((s8 *)((*(Glob_800267B8 *)&TBoss1Dragon__data_804FE17C).value) + 0x10);
            break;
        }
        iscale = (s32) (lbl_805D8078 * scale);
        if (this->motion_flags & 4) {
            this->play_speed = lbl_805D807C * scale;
        } else {
            this->play_speed = lbl_805D8080 * scale;
        }
        ((TObjMotion *)arg0)->advance_animation();
        TBoss1Dragon__sub_80028BE0(arg0);
        update_velocity__9TObjEneDDFv(arg0);
        calc_target_vector__12TBoss1DragonFPv(arg0);
        if (((TObjMotion *)arg0)->is_passing_frame((f32)(3.0f)) != 0) {
            ((TBoss1Dragon *)arg0)->apply_foot_attack_pair_0();
        } else if (((TObjMotion *)arg0)->is_passing_frame((f32)(24.0f)) != 0) {
            ((TBoss1Dragon *)arg0)->apply_foot_attack_pair_1();
        }
        v = this->frame;
        if (v < (4.0f)) {
            ((TObjEneDD *)arg0)->move_to_shot_position(sin_table_lookup(this->rotation_y), cos_table_lookup(this->rotation_y), scale);
        } else if (!(v < (9.0f))) {
            if (v < lbl_805D8084) {
                TObjEneEpsilon__sub_800B9384(arg0, iscale, scale);
            } else if (v < (24.0f)) {
                ((TObjEneDD *)arg0)->move_to_shot_position(sin_table_lookup(this->rotation_y), cos_table_lookup(this->rotation_y), scale);
            } else if (!(v < (30.0f))) {
                TObjEneEpsilon__sub_800B9384(arg0, iscale, scale);
            }
        }
        break;
    }
}

void TBoss1Dragon__sub_80026B98(TBoss1Dragon *arg0, u32 arg1) {
    s32 temp_r4;

    switch (arg1) {
    case 4:
        arg0->requested_action = 0;
        arg0->stateStep = 0;
        arg0->height = (f32) *(f32 *)((s8 *)arg0 + 0x3C);
        arg0->heightOffset = (f32) arg0->defaultHeightOffset;
        play_se_at_pos__12TBoss1DragonFii((s32) arg0, 0x4003AD00);
        return;
    case 2:
    case 11:
        if (filter_input_flags__12TBoss1DragonFiii((s32)arg0, (s32) (*(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x6E4)) + 8)), 4) != 0) {
            ((TBoss1Dragon *)arg0)->request_state_change(3);
            return;
        }
        if (filter_input_flags__12TBoss1DragonFiii((s32)arg0, (s32) (*(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x6E4)) + 8)), 0x400) != 0) {
            ((TBoss1Dragon *)arg0)->request_state_change(5);
            return;
        }
        if (*(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x6E4)) + 0x24) > (0.1f)) {
            ((TBoss1Dragon *)arg0)->request_state_change(0x18);
            return;
        }
        break;
    case 0:
        arg0->stateStep = arg0->stateStep + 1;
        arg0->advance_animation();
        break;
    }
}

void TBoss1Dragon__sub_80026C98(TBoss1Dragon *arg0, u32 arg1) {
    switch (arg1) {
    case 4:
        arg0->init_control_mode();
        return;
    case 2:
    case 11:
        ((TBoss1Dragon *)arg0)->request_state_change(0x17);
        return;
    case 9:
        if ((s32) *(s32 *)((s8 *)arg0 + 0x760) != 0) {
            ((TBoss1Dragon *)arg0)->request_state_change(0x17);
            return;
        }
        next_sequence_action__12TBoss1DragonFv(arg0);
    default:
        return;
    }
}

void TBoss1Dragon::dispatch_action(u32 state, s32 reason) {
    switch (state) {
    case 0:
        TBoss1Dragon__sub_80026C98(this, (u32)reason);
        return;
    case 1:
        TBoss1Dragon__sub_80026B98(this, (u32)reason);
        return;
    case 2:
        this->update_walking_state(reason);
        return;
    case 3:
        this->update_breath_attack_state(reason);
        return;
    case 4:
        this->update_tail_attack_state(reason);
        return;
    case 5:
        this->update_lift_state(reason);
        return;
    case 6:
        this->update_flight_state(reason);
        return;
    case 7:
        this->update_air_fire_state((u32)reason);
        return;
    case 8:
    case 10:
    case 11:
    case 12:
        this->handleFallState(reason);
        return;
    case 9:
        this->update_head_down_attack_state(reason);
        return;
    case 13:
        this->update_stretch_state(reason);
        return;
    case 14:
        this->update_roar_state(reason);
        return;
    case 15:
        update_dive_state__12TBoss1DragonFv((u8 *)this, (u32)reason);
        return;
    case 16:
    case 17:
        this->update_burrow_inward_run(reason, state);
        return;
    case 18:
        this->update_burrow_outward_run(reason);
        return;
    case 19:
        this->update_emergence_state((u32)reason);
        return;
    case 21:
        update_death_state__12TBoss1DragonFv((u8 *)this, (u32)reason);
        return;
    case 22:
        this->update_fade_state(reason);
        return;
    case 23:
        TBoss1Dragon__sub_80022C38(this, (u32)reason);
        return;
    case 24:
        TBoss1Dragon__sub_800228E8(this, (u32)reason);
        return;
    case 25:
        TBoss1Dragon__sub_80022740(this, (u32)reason);
        return;
    case 26:
        TBoss1Dragon__sub_800224A4(this, (u32)reason);
        return;
    case 27:
        this->handle_state(reason);
        return;
    case 28:
        TBoss1Dragon__sub_80022158(this, (u32)reason);
        return;
    case 29:
        this->update_appearance_state(reason);
        return;
    case 30:
        this->wait_for_players(reason);
        return;
    case 31:
        this->update_wander_state(reason);
        return;
    case 34:
        this->update_spinning_projectile_attack((u32)reason);
        return;
    case 35:
        TBoss1Dragon__sub_80023A2C(this, (u32)reason);
        return;
    case 36:
        this->state_circle_flight(reason);
        return;
    case 37:
        this->handle_fall_state(reason);
    default:
        return;
    }
}

s32 filter_input_flags__12TBoss1DragonFiii(s32 arg1, s32 arg2, s32 arg3) {
    s32 var_r31;

    var_r31 = arg3;
    if ((get_player_by_client_id(local_client_id) == 0U) || (check_flag_100__10TObjPlayerFPv() != 0)) {
        arg2 &= 0xFFFCF9F9;
    }
    return arg2 & var_r31;
}

}

void TBoss1Dragon::updateFacingPosition() {
    position.x = lbl_805D8088 * sin_table_lookup(facingAngle);
    position.z = lbl_805D8088 * cos_table_lookup(facingAngle);
}

extern "C" {

s32 TBoss1Dragon::check_can_attack() {
    u8 var_r31;

    var_r31 = 0;
    if ((filter_input_flags__12TBoss1DragonFiii((s32)this, (s32)((s32)(*(s32 *)((s8 *)(*(void **)((s8 *)this + 0x6E4)) + 8))), 0x400) != 0) && (this->is_secondary_sequence() != 0)) {
        var_r31 = 1;
    }
    return (u8) var_r31;
}

u8 check_attack_ready__12TBoss1DragonFPv(void *arg0) {
    u8 var_r31;

    var_r31 = 0;
    if (((s32) *(s32 *)((s8 *)arg0 + 0x768) >= 0x96) && (filter_input_flags__12TBoss1DragonFiii((s32)arg0, (s32)((s32)(*(s32 *)((s8 *)(*(void **)((s8 *)arg0 + 0x6E4)) + 8))), 0x400) != 0)) {
        var_r31 = 1;
    }
    return (u8) var_r31;
}

#pragma push
#pragma fp_contract on
f32 TBoss1Dragon__sub_80027010(Obj_80027010 *arg0, f32 farg0, f32 farg1, f32 farg2) {
    Vec_80027010 v;
    v.x = farg0 * farg2 + arg0->f38;
    v.y = (0.0f);
    v.z = farg1 * farg2 + arg0->f40;
    if (vec3_dot(&v, &v) > lbl_805D808C) {
        farg2 = (0.0f);
    }
    return farg2;
}
#pragma pop

void TBoss1Dragon::release_held_player() {
    s32 var_r31;
    u16 temp_r4;
    u8 *temp_r3;
    temp_r3 = (u8 *)(((u8 *)get_player_by_client_id((s32) *(u16 *)((s8 *)((u8 *)this) + 0x764))));
    if (temp_r3 != NULL) {
        ((TObjPlayer *)temp_r3)->end_camera_pan();
        ((TObjPlayer *)temp_r3)->actorFlags = (s32) (((TObjPlayer *)temp_r3)->actorFlags & 0xFDFFFFFF);
        ((TObjPlayer *)(temp_r3 + 0x644))->reset_lobby_model();
        *(f32 *)((s8 *)temp_r3 + 0x3C) = (f32) (0.0f);
        temp_r4 = *(u16 *)((s8 *)((u8 *)this) + 0x764);
        if (((s32) temp_r4 == (s32) local_client_id) && ((s16) this->mode == 0x15)) {
            send_6x2F_change_player_hp((0xFFFFU), (temp_r4), 0);
        }
    }
    *(s32 *)((s8 *)((u8 *)this) + 0x760) = 0;
    if ((s16) this->mode != 0x15) {
        var_r31 = 0;
        if (is_primary_sequence__12TBoss1DragonFv(this) != 0) {
            this->sequenceCursor = 0;
            switch (this->mode) {
            case 23:
            case 24:
                var_r31 = 1;
                this->sequenceCursor = 0;
                break;
            case 3:
                this->sequenceCursor = 2;
                break;
            case 4:
                this->sequenceCursor = 3;
                break;
            case 5:
                this->sequenceCursor = 4;
                break;
            case 25:
            case 26:
                var_r31 = 1;
                this->sequenceCursor = 6;
                break;
            case 7:
                this->sequenceCursor = 6;
                break;
            case 8:
                this->sequenceCursor = 7;
                break;
            case 9:
                this->sequenceCursor = 0;
                break;
            }
        } else {
            this->sequenceCursor = 0;
            switch (this->mode) {
            case 23:
            case 24:
                var_r31 = 1;
                this->sequenceCursor = 0;
                break;
            case 3:
            case 4:
                this->sequenceCursor = 0;
                break;
            case 5:
                this->sequenceCursor = 1;
                break;
            case 25:
            case 26:
                var_r31 = 1;
                this->sequenceCursor = 0xA;
                break;
            case 7:
                this->sequenceCursor = 0xA;
                break;
            case 8:
            case 19:
                this->sequenceCursor = 0xB;
                break;
            case 15:
                this->sequenceCursor = 2;
                break;
            case 36:
            case 37:
                var_r31 = 1;
                this->sequenceCursor = 9;
                break;
            case 9:
                this->sequenceCursor = 0;
                break;
            }
            this->sequenceCursor = (this->sequenceCursor + 0x32);
        }
        if (var_r31 != 0) {
            next_sequence_action__12TBoss1DragonFv(this);
        }
    }
}

#pragma push
#pragma fp_contract on
void TBoss1Dragon::hold_captured_player() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r31;
    s32 temp_r3b;
    u8 *temp_r3;
    temp_r3 = ((u8 *)get_player_by_client_id((s32)(*(u16 *)((s8 *)arg0 + 0x764))));
    if (temp_r3 != NULL) {
        temp_r31 = get_current_floor();
        temp_r3b = ((TObjPlayer *)temp_r3)->get_field_3e4();
        if (temp_r3b == temp_r31) {
            ((TObjPlayer *)temp_r3)->start_freeze();
            set_frames__15ProtectionTimerFl(temp_r3 + 0x644, 0x14);
            ((TObjPlayer *)temp_r3)->actorFlags = (s32) (((TObjPlayer *)temp_r3)->actorFlags & 0xFFEFFFDF);
            VecCopy__FP3VecPC3Vec((s32)(temp_r3 + 0x38), (s32)(arg0 + 0x38));
            *(f32 *)((s8 *)temp_r3 + 0x3C) = (f32) (*(f32 *)((s8 *)temp_r3 + 0x3C) - lbl_805D8090);
            ((TObjPlayer *)temp_r3)->rotation_y = (s32) this->rotation_y;
            return;
        }
    }
    TBoss1Dragon::clearControlOverride();
}
#pragma pop

void TBoss1Dragon::init_control_mode() {
    u16 id;

    if (TBoss1Dragon__data_805D4B38 != 0) {
        ((Obj_80027320 *)this)->f760 = 1;
    } else {
        ((Obj_80027320 *)this)->f760 = 0;
        ((Obj_80027320 *)this)->f764 = 0xFFFF;
        return;
    }
    ((Obj_80027320 *)this)->f768 = 0x96;
    ((Obj_80027320 *)this)->f6e4 = controller_input_state + 0x20;
    if (((s32 (*)(void *))is_main_phase_15__9TObjEneDDFv)(controller_input_state) != 0) {
        if (TBoss1Dragon__data_805D4B3C == 0xFFFF) {
            id = TBoss1Dragon::find_player_on_floor(this);
        } else {
            id = TBoss1Dragon__data_805D4B3C;
        }
    } else {
        id = local_client_id;
    }
    {
        u32 r = get_player_by_client_id(id);
        if (r != 0) {
            ((TObjPlayer *)r)->start_freeze();
        }
    }
    ((Obj_80027320 *)this)->f764 = id;
}

#pragma push
#pragma fp_contract on
u16 TBoss1Dragon::find_player_on_floor(void *arg0) {
    u8 *p;
    u16 idx;
    u16 i;
    p = ((u8 *)get_player_by_client_id(TLobby__designated_client_id));
    if (p != NULL) {
        if (((TObjPlayer *)p)->get_field_3e4() == get_current_floor()) {
            return TLobby__designated_client_id;
        }
    }
    for (i = 0; i < 4; i++) {
        idx = (TLobby__designated_client_id + i + 1) % 4;
        p = ((u8 *)get_player_by_client_id(idx));
        if (p != NULL) {
            if (((TObjPlayer *)p)->get_field_3e4() == get_current_floor()) {
                break;
            }
        }
    }
    return idx;
}
#pragma pop

void TBoss1Dragon__sub_800274A4(s32 arg0) {
    if (((TObjMotion *)arg0)->is_passing_frame(TBoss1Dragon__data_805D8018) != 0) {
        ((TBoss1Dragon *)arg0)->update_switch_attack();
    }
}

void TBoss1Dragon::update_switch_attack() {
    spawn_particle_effect_with_flags(&this->position, *(s32 *)((s8 *)this->effectResource + 4), 0x40);
}

s32 TBoss1Dragon__sub_80027514(u8 *arg0, s32 arg1, u8 *arg2, s32 arg3) {
    ((TBoss1Dragon *)(*(u8 **)((s8 *)arg0 + 0x774)))->get_position();
    *(f32 *)((s8 *)(*(void **)((s8 *)(*(u8 **)((s8 *)arg0 + 0x774)) + 0xA4)) + 0xC) = (f32) *(f32 *)((s8 *)arg2 + 8);
    *(s32 *)((s8 *)(*(void **)((s8 *)(*(u8 **)((s8 *)arg0 + 0x774)) + 0xA4)) + 0x18) = 0x9D03;
    ((TUnk_80481B34 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x774))))->call_vt13_with_default(arg2 + 0xC, arg2, arg3);
}

s32 TBoss1Dragon__sub_80027590(void* object, void* action) {
    TBoss1Dragon__sub_800275BC((u8 *)((s32)object), (s32)((s32)((char*)object + 0x38)), (u8 *)((u8*)action), 0);
}

void TBoss1Dragon__sub_800275BC(u8 *arg0, s32 arg1, u8 *arg2, s32 arg3) {
    ((TBoss1Dragon *)(*(u8 **)((s8 *)arg0 + 0x774)))->get_position();
    *(f32 *)((s8 *)(*(void **)((s8 *)(*(u8 **)((s8 *)arg0 + 0x774)) + 0xA4)) + 0xC) = (f32) *(f32 *)((s8 *)arg2 + 8);
    *(s32 *)((s8 *)(*(void **)((s8 *)(*(u8 **)((s8 *)arg0 + 0x774)) + 0xA4)) + 0x18) = 0x9D03;
    ((TUnk_80481B34 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x774))))->call_vt16_with_default(arg2 + 0xC, (void *)arg3);
}

typedef char RecoveredGlobal_80027634_TBoss1Dragon__data_804FE17C_size[sizeof(RecoveredGlobal_80027634_TBoss1Dragon__data_804FE17C) == 0xC ? 1 : -1];
f32 TBoss1Dragon__sub_80027634(void) {
    return lbl_805D8094 * *(f32 *)((s8 *)TBoss1Dragon__data_804FE17C[0] + 4);
}

typedef struct CopyStack_80027650 CopyStack_80027650;
typedef struct ByteBlock_10 ByteBlock_10;
typedef struct ByteBlock_14 ByteBlock_14;
typedef struct RecoveredGlobal_80027650_TBoss1Dragon__data_804FE17C RecoveredGlobal_80027650_TBoss1Dragon__data_804FE17C;
typedef struct RecoveredGlobal_80027650_lbl_80435338 RecoveredGlobal_80027650_lbl_80435338;
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
typedef char RecoveredGlobal_80027650_lbl_80435338_size[((sizeof(RecoveredGlobal_80027650_lbl_80435338)) == 0x14) ? (1) : (-1)];
typedef char RecoveredGlobal_80027650_TBoss1Dragon__data_804FE17C_size[((sizeof(RecoveredGlobal_80027650_TBoss1Dragon__data_804FE17C)) == 0xC) ? (1) : (-1)];
void TBoss1Dragon::apply_fireball_impact_damage(s32 arg1) {
  struct CopyStack_80027650
  {
    u8 bytes[0x14];
  };
  CopyStack_80027650 copy_storage_80027650;
  *((ByteBlock_14 *) (((s32)(copy_storage_80027650.bytes - 0x4)) + 4)) = *((const ByteBlock_14 *) ((((u8 *)&dragon_fireball_impact_damage_params.value) - 4) + 4));
  *((f32 *)(copy_storage_80027650.bytes + 0x4)) = *((f32 *) (((s8 *) (*(RecoveredGlobal_80027650_TBoss1Dragon__data_804FE17C *)&TBoss1Dragon__data_804FE17C).value) + 4));
  *((s32 *) copy_storage_80027650.bytes) = *((s32 *) (((s8 *) ((u8 *)this)) + 0x770));
  switch (isV2Mode__12TBoss1DragonFv())
  {
    case 0:
      TObjEneDD::setup((void*)this, (int)((void *) arg1), (int)((void *) copy_storage_80027650.bytes));
      return;
    case 1:
      TBoss1Dragon__sub_80027514((u8 *)this, (s32)((void *) arg1), (u8 *)((void *) copy_storage_80027650.bytes), 0);
      return;
  }
}

typedef char RecoveredGlobal_80027710_lbl_80435324_size[sizeof(RecoveredGlobal_80027710_lbl_80435324) == 0x14 ? 1 : -1];
typedef char RecoveredGlobal_80027710_TBoss1Dragon__data_804FE17C_size[sizeof(RecoveredGlobal_80027710_TBoss1Dragon__data_804FE17C) == 0xC ? 1 : -1];
void TBoss1Dragon::deliver_breath_attack(s32 arg1, s32 arg2) {
    struct CopyStack_80027710 { u8 bytes[0x14]; };
    CopyStack_80027710 copy_storage_80027710;
    *(ByteBlock_14 *)(copy_storage_80027710.bytes) = *(const ByteBlock_14 *)((s32) ((u8 *)((void *)((u8 *)&dragon_fireball_attack_params.value + -4))) + 4);
    (*(f32 *)(copy_storage_80027710.bytes + 0x4)) = *(f32 *)((s8 *)((*(RecoveredGlobal_80027710_TBoss1Dragon__data_804FE17C *)&TBoss1Dragon__data_804FE17C).value) + 0);
    (*(s32 *)copy_storage_80027710.bytes) = *(s32 *)((s8 *)((u8 *)this) + 0x770);
    switch (isV2Mode__12TBoss1DragonFv()) {
    case 0:
        TObjEneDD::setup_instance((s32) this, arg1, (copy_storage_80027710.bytes), arg2);
        return;
    case 1:
        TBoss1Dragon__sub_80027514((u8 *)this, (s32)arg1, (u8 *)((copy_storage_80027710.bytes)), (s32)arg2);
        return;
    }
}

typedef char RecoveredGlobal_800277D8_lbl_80435310_size[sizeof(RecoveredGlobal_800277D8_lbl_80435310) == 0x14 ? 1 : -1];
typedef char RecoveredGlobal_800277D8_TBoss1Dragon__data_804FE17C_size[sizeof(RecoveredGlobal_800277D8_TBoss1Dragon__data_804FE17C) == 0xC ? 1 : -1];
void TBoss1Dragon__sub_800277D8(u8 *arg0) {
    struct CopyStack_800277D8 { u8 bytes[0x14]; };
    CopyStack_800277D8 copy_storage_800277D8;
    u8 *temp_r3;
    temp_r3 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x6D8));
    if ((temp_r3 != NULL) && (is_dragon_trail_damaging(temp_r3) != 0)) {
        *(ByteBlock_14 *)(copy_storage_800277D8.bytes) = *(const ByteBlock_14 *)((s32) ((u8 *)((void *)((u8 *)&dragon_breath_attack_params.value + -4))) + 4);
        (*(f32 *)(copy_storage_800277D8.bytes + 0x4)) = *(f32 *)((s8 *)((*(RecoveredGlobal_800277D8_TBoss1Dragon__data_804FE17C *)&TBoss1Dragon__data_804FE17C).value) + 8);
        switch (isV2Mode__12TBoss1DragonFv()) {
        case 0:
            TObjEneDD::setup_instance((s32) arg0, (s32)(arg0 + 0x38), (copy_storage_800277D8.bytes), *(s32 *)((s8 *)arg0 + 0x688));
            return;
        case 1:
            TBoss1Dragon__sub_80027514(arg0, (s32)((s32)(arg0 + 0x38)), (u8 *)((copy_storage_800277D8.bytes)), (s32)(*(s32 *)((s8 *)arg0 + 0x688)));
            break;
        }
    }
}

#pragma push
#pragma opt_common_subs off
void TBoss1Dragon::sweep_death_body_attack() {
    u8 *pts[8];
    Vec_800278A8 pos;
    Params_800278A8 params;
    s32 i;
    s32 off;
    reset_hp__9TObjEneDDFPUcPUcPUc(this, 0, *(s32 *)((s8 *)&TBoss1Dragon__part_hp_stats + 0x10), 0);
    fill_value_array(*(s32 *)((s8 *)((u8 *)this) + 0x688));
    TBoss1Dragon__sub_80027A80((u8 *)&params, TBoss1Dragon__head_fall_effect_params);
    VecCopy__FP3VecPC3Vec((s32)&pos, (s32)(((u8 *)this) + 0x4C0));
    params.scale = (15.0f);
    switch (isV2Mode__12TBoss1DragonFv()) {
    case 0:
        emit_enemy_effect__9TObjEneDDFllPUcl(this, &pos, &params, *(s32 *)((s8 *)((u8 *)this) + 0x688));
        break;
    case 1:
        TBoss1Dragon__sub_800275BC(((u8 *)this), (s32)&pos, (u8 *)&params, *(s32 *)((s8 *)((u8 *)this) + 0x688));
        break;
    }
    params.scale = (12.0f);
    pts[0] = ((u8 *)this) + 0x484;
    pts[1] = ((u8 *)this) + 0x49C;
    for (i = 0; i < 2; i++) {
        switch (isV2Mode__12TBoss1DragonFv()) {
        case 0:
            emit_enemy_effect__9TObjEneDDFllPUcl(this, pts[i], &params, *(s32 *)((s8 *)((u8 *)this) + 0x688));
            break;
        case 1:
            TBoss1Dragon__sub_800275BC(((u8 *)this), (s32)pts[i], (u8 *)&params, *(s32 *)((s8 *)((u8 *)this) + 0x688));
            break;
        }
    }
    params.scale = lbl_805D8024;
    pts[0] = ((u8 *)this) + 0x4D8;
    pts[1] = ((u8 *)this) + 0x4E4;
    pts[2] = ((u8 *)this) + 0x4F0;
    pts[3] = ((u8 *)this) + 0x4FC;
    for (i = 0; i < 4; i++) {
        switch (isV2Mode__12TBoss1DragonFv()) {
        case 0:
            emit_enemy_effect__9TObjEneDDFllPUcl(this, pts[i], &params, *(s32 *)((s8 *)((u8 *)this) + 0x688));
            break;
        case 1:
            TBoss1Dragon__sub_800275BC(((u8 *)this), (s32)pts[i], (u8 *)&params, *(s32 *)((s8 *)((u8 *)this) + 0x688));
            break;
        }
    }
    reset_hp__9TObjEneDDFPUcPUcPUc(this, 0, *(s32 *)((s8 *)&TBoss1Dragon__part_hp_stats + 0), 0);
}
#pragma pop

void TBoss1Dragon__sub_80027A80(u8 *arg0, u8 *arg1) {
    *(ByteBlock_8 *)(arg0) = *(const ByteBlock_8 *)(arg1);
    *(f32 *)((s8 *)arg0 + 8) = (f32) *(f32 *)((s8 *)arg1 + 8);
    *(ByteBlock_8 *)((s32) arg0 + 0xC) = *(const ByteBlock_8 *)((s32) arg1 + 0xC);
}

typedef char RecoveredGlobal_80027AAC_lbl_80434EB4_size[sizeof(RecoveredGlobal_80027AAC_lbl_80434EB4) == 0x14 ? 1 : -1];
void TBoss1Dragon::apply_ground_impact_attack() {
    s32 arg0 = (s32)this;
    reload_impact_stats();
    switch (isV2Mode__12TBoss1DragonFv()) {
    case 0:
        ((TObjEneDD *)arg0)->emit_effect_at_position((void *)&boss1_dragon_ground_impact_params.value);
        break;
    case 1:
        TBoss1Dragon__sub_80027590((void*)arg0, (void*)((void *)&boss1_dragon_ground_impact_params.value));
        break;
    }
    reload_difficulty_stats();
}

void sweep_head_fall_spheres_late__12TBoss1DragonFv(void) {
    ((s32 (*)(f32, f32, f32))sweep_body_attack_spheres__12TBoss1DragonFv)(TBoss1Dragon__data_805D8010, lbl_805D8098, (60.0f));
}

void update_from_data__12TBoss1DragonFv(void) {
    ((s32 (*)(f32, f32, f32))sweep_body_attack_spheres__12TBoss1DragonFv)(TBoss1Dragon__data_805D8010, lbl_805D809C, lbl_805D80A0);
}

struct Vec_80027B78 { f32 x, y, z; };
struct Fx_80027B78 { u32 w0; u32 w1; f32 f8; u32 wc; u32 w10; };
void draw_chunk_object(void *child);
extern s32 lbl_805D28BC;
extern const f32 lbl_805D80A4;
#pragma push
#pragma fp_contract on
void sweep_body_attack_spheres__12TBoss1DragonFv(u8 *arg0, f32 a, f32 b, f32 c) {
    f32 factor;
    Vec_80027B78 pos;
    Vec_80027B78 base;
    Fx_80027B78 fx = *(Fx_80027B78 *)TBoss1Dragon__head_fall_effect_params;
    f32 s0;
    f32 s1;
    f32 d;

    fx.f8 = a - (2.0f);
    fill_value_array(*(s32 *)((s8 *)arg0 + 0x688));
    s0 = sin_table_lookup(((TObjEneDD *)arg0)->rotation_y);
    s1 = cos_table_lookup(((TObjEneDD *)arg0)->rotation_y);
    ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&base, arg0 + 0x38);
    base.x = lbl_805D80A4 * s1 + base.x;
    base.y = (0.0f);
    base.z = base.z - lbl_805D80A4 * s0;
    d = (0.5f) * (b + c);
    ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&pos, &base);
    pos.x += s0 * d;
    pos.z += s1 * d;
    spawn_particle_effect_with_flags(&pos, *(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x778)) + 0xC), 0x40);
    reset_hp__9TObjEneDDFPUcPUcPUc(arg0, 0, *(s32 *)((s8 *)&TBoss1Dragon__part_hp_stats + 0x10), 0);
    c = c - a;
    d = b - a;
    factor = 2.0f;
    a = a * factor;
    b = (0.5f) * ((0.5f) * a);
    while (d > c) {
        ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&pos, &base);
        pos.x += s0 * d;
        pos.z += s1 * d;
        switch (isV2Mode__12TBoss1DragonFv()) {
        case 0:
            emit_enemy_effect__9TObjEneDDFllPUcl(arg0, &pos, &fx, *(s32 *)((s8 *)arg0 + 0x688));
            break;
        case 1:
            ((void (*)(u8 *, void *, void *, s32))TBoss1Dragon__sub_800275BC)(arg0, &pos, &fx, *(s32 *)((s8 *)arg0 + 0x688));
            break;
        }
        d -= a;
        push_matrix();
        post_translate_matrix(&pos);
        scale_matrix(0, b, (2.0f), b);
        draw_chunk_object((void *)lbl_805D28BC);
        pop_matrix();
    }
    reset_hp__9TObjEneDDFPUcPUcPUc(arg0, 0, TBoss1Dragon__part_hp_stats[0], 0);
}

#pragma pop

}

void TBoss1Dragon::apply_head_fall_attack() {
    reset_hp__9TObjEneDDFPUcPUcPUc(this, 0, *(s32 *)((s8 *)&TBoss1Dragon__part_hp_stats + 0x10), 0);
    switch (isV2Mode__12TBoss1DragonFv()) {
    case 0:
        emit_effect_at_position(TBoss1Dragon__head_fall_effect_params);
        break;
    case 1:
        TBoss1Dragon__sub_80027590(this, TBoss1Dragon__head_fall_effect_params);
        break;
    }
    reset_hp__9TObjEneDDFPUcPUcPUc(this, 0, *(s32 *)((s8 *)&TBoss1Dragon__part_hp_stats + 0), 0);
}

typedef char RecoveredGlobal_80027E78_lbl_80434E8C_size[sizeof(RecoveredGlobal_80027E78_lbl_80434E8C) == 0x14 ? 1 : -1];
typedef char RecoveredGlobal_80027E78_TBoss1Dragon__data_804FE17C_size[sizeof(RecoveredGlobal_80027E78_TBoss1Dragon__data_804FE17C) == 0xC ? 1 : -1];
void apply_landing_attack__12TBoss1DragonFi(s32 arg0) {
    typedef char sp8_offset[(offsetof(Stack_80027E78, sp8) == 0x0) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_80027E78, sp10) == 0x8) ? 1 : -1];
    Stack_80027E78 stack;
    TBoss1Dragon__sub_80027A80((u8 *)&stack.sp8, (u8 *)&boss1_dragon_attack_sphere_params.value);
    stack.sp10 = *(f32 *)((s8 *)((*(RecoveredGlobal_80027E78_TBoss1Dragon__data_804FE17C *)&TBoss1Dragon__data_804FE17C).value) + 0xC);
    ((TBoss1Dragon *)arg0)->reload_stats_for_phase((int) ((*(RecoveredGlobal_80027E78_TBoss1Dragon__data_804FE17C *)&TBoss1Dragon__data_804FE17C).value));
    switch (isV2Mode__12TBoss1DragonFv()) {
    case 0:
        ((TObjEneDD *)arg0)->emit_effect_at_position(&stack.sp8);
        break;
    case 1:
        TBoss1Dragon__sub_80027590((void*)arg0, (void*)((void *)&stack.sp8));
        break;
    }
    ((TBoss1Dragon *)arg0)->reload_difficulty_stats();
}

int TBoss1Dragon::apply_foot_attack_pair_1() {
    return apply_foot_step_attack(1);
}

int TBoss1Dragon::apply_foot_attack_pair_0() {
    return apply_foot_step_attack(0);
}

extern ByteBlock_14 TBoss1Dragon__foot_step_attack_params;
int TBoss1Dragon::apply_foot_step_attack(int arg1) {
    ByteBlock_14 params = TBoss1Dragon__foot_step_attack_params;
    u8 *a;
    u8 *b;

    fill_value_array(*(s32 *)((s8 *)((u8 *)this) + 0x688));
    if (arg1 == 0) {
        a = ((u8 *)this) + 0x46C;
        b = ((u8 *)this) + 0x478;
    } else {
        a = ((u8 *)this) + 0x454;
        b = ((u8 *)this) + 0x460;
    }
    reset_hp__9TObjEneDDFPUcPUcPUc(this, 0, TBoss1Dragon__part_hp_stats[0], 0);
    switch (isV2Mode__12TBoss1DragonFv()) {
    case 0:
        emit_enemy_effect__9TObjEneDDFllPUcl(this, a, params.bytes, *(s32 *)((s8 *)((u8 *)this) + 0x688));
        emit_enemy_effect__9TObjEneDDFllPUcl(this, b, params.bytes, *(s32 *)((s8 *)((u8 *)this) + 0x688));
        break;
    case 1:
        TBoss1Dragon__sub_800275BC(((u8 *)this), (s32) a, params.bytes, *(s32 *)((s8 *)((u8 *)this) + 0x688));
        TBoss1Dragon__sub_800275BC(((u8 *)this), (s32) b, params.bytes, *(s32 *)((s8 *)((u8 *)this) + 0x688));
        break;
    }
    reset_hp__9TObjEneDDFPUcPUcPUc(this, 0, TBoss1Dragon__part_hp_stats[0], 0);
    spawn_particle_effect_with_flags(b, *(s32 *)((s8 *)this->effectResource + 0xC), 0x40);
}

void clear_work__12TBoss1DragonFi(s32 arg0) {
    start_pad_rumble_at((Vec *)(arg0 + 0x38), 0xE0, arg0);
}

#pragma push
#pragma fp_contract on
void TBoss1Dragon::spawn_impact_crater(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    Vec position;
    s32 temp_r5;
    VecCopy__FP3VecPC3Vec((s32)&position.x, arg1);
    temp_r5 = *(s32 *)((s8 *)arg0 + 0x6A4);
    if (temp_r5 < 0xC) {
        position.y += lbl_805D80A8 * (f32) temp_r5;
        *(s32 *)((s8 *)arg0 + 0x6A4) = (temp_r5 + 1);
        ((TObjBoss1Crater *)tl_02)->create(&position.x);
    }
    spawn_particle_effect_with_flags((&position.x), (s32)((void *) (**(s32 * *)&this->effectResource)), 0x840);
    TCameraCtrl::set_shake_preset(1);
}
#pragma pop

#pragma push
#pragma fp_contract on
f32 calc_burrow_speed__12TBoss1DragonFPv(void *arg0) {
    return ((4.0f) * (f32) *(s32 *)((s8 *)arg0 + 0x6DC)) + (4.0f);
}
#pragma pop

s32 TBoss1Dragon::check_phase_advance() {
    if ((s16) this->hp <= (s16) this->hpThreshold) {
        if ((s32) this->phase == 1) {
            this->request_state_change(0xA);
            return 1;
        }
        this->request_state_change(9);
        return 1;
    }
    return 0;
}

s32 TBoss1Dragon::update_max_hp_phase() {
    s16 temp_r4;

    if ((s16) this->hp <= (temp_r4 = this->finalHpThreshold)) {
        this->hp = temp_r4;
        this->select_sequence(1);
        if ((s32) this->phase == 0) {
            this->request_state_change(0xD);
            return 1;
        }
        this->request_state_change(0xB);
        return 1;
    }
    return 0;
}

typedef char RecoveredGlobal_8002826C_lbl_80480D00_size[sizeof(RecoveredGlobal_8002826C_lbl_80480D00) == 0x48 ? 1 : -1];
typedef char RecoveredGlobal_8002826C_lbl_80480D48_size[sizeof(RecoveredGlobal_8002826C_lbl_80480D48) == 0x240 ? 1 : -1];
typedef char RecoveredFields_8002826C_arg0_67C_offset[offsetof(RecoveredFields_8002826C_arg0, field_67C) == 0x67C ? 1 : -1];
typedef char RecoveredFields_8002826C_arg0_760_offset[offsetof(RecoveredFields_8002826C_arg0, field_760) == 0x760 ? 1 : -1];

void TBoss1Dragon::remap_sequence_after_recovery() {
    if ((s32) ((RecoveredFields_8002826C_arg0 *)((u8 *)this))->field_760 != 0) {
        next_sequence_action__12TBoss1DragonFv(((u8 *)this));
        return;
    }
    if (((TBoss1Dragon *)((u8 *)this))->update_max_hp_phase() == 0) {
        switch (isV2Mode__12TBoss1DragonFv()) {
        case 0:
            ((RecoveredFields_8002826C_arg0 *)((u8 *)this))->field_67C = (s32) *(s32 *)((s8 *)((s32 *)boss1_dragon_sequence_remap_table) + (((RecoveredFields_8002826C_arg0 *)((u8 *)this))->field_67C * 4));
            break;
        case 1:
            ((RecoveredFields_8002826C_arg0 *)((u8 *)this))->field_67C = (s32) *(s32 *)((s8 *)((s32 *)lbl_80480D48) + (((RecoveredFields_8002826C_arg0 *)((u8 *)this))->field_67C * 4));
            break;
        }
        next_sequence_action__12TBoss1DragonFv(((u8 *)this));
    }
}

struct Dragon_8002830C {
    u8 pad0[0x67C];
    s32 seqPos;
};

s32 next_sequence_action__12TBoss1DragonFv(void *vself) {
#define self ((Dragon_8002830C *)vself)
    s32 idx;
    s32 *seq;
    s32 code;
    s32 again;

    s32 pos = self->seqPos;
    if (pos < 50) {
        idx = pos;
        switch (isV2Mode__12TBoss1DragonFv()) {
        case 0:
            seq = (s32 *)TBoss1Dragon__data_80480CE0;
            break;
        case 1:
            seq = (s32 *)lbl_80480D20;
            break;
        }
    } else {
        idx = pos - 50;
        switch (isV2Mode__12TBoss1DragonFv()) {
        case 0:
            seq = (s32 *)boss1_dragon_action_sequence_table;
            break;
        case 1:
            seq = (s32 *)boss1_dragon_action_sequence_table_b;
            break;
        }
    }
    do {
        code = seq[idx];
        again = 0;
        idx++;
        self->seqPos++;
        switch (code) {
        case 32:
            self->seqPos = 0;
            again = 1;
            idx = 0;
            break;
        case 33:
            self->seqPos = 50;
            again = 1;
            idx = 0;
            break;
        }
    } while (again != 0);
    ((TBoss1Dragon *)self)->request_state_change(code);
#undef self
}

void TBoss1Dragon::saveCurrentDestination() {
    destinationX = position.x;
    destinationZ = position.z;
}

void TBoss1Dragon::setDestinationX(int x) {
    destinationX = (f32)x;
    destinationZ = (0.0f);
}

void TBoss1Dragon::saveTargetDestination() {
    destinationX = targetX;
    destinationZ = targetZ;
}

void TBoss1Dragon::restorePosition() {
    position.x = savedX;
    position.z = savedZ;
}

void TBoss1Dragon::copySavedX(int* x) {
    *x = (int)savedX;
}

void TBoss1Dragon::restoreTargetPosition() {
    targetX = savedX;
    targetZ = savedZ;
}

struct Pkt_800284B4 {
    u16 hdr; u16 owner; s16 state; s16 cursor; s32 target; f32 x; f32 z;
};
struct Dragon_800284B4 {
    u8 pad0[0x1C]; u16 owner; u8 pad1[0x38C - 0x1E]; u16 target; u8 pad2[0x67C - 0x38E];
    s32 cursor; u8 pad3[0x690 - 0x680]; f32 x; f32 z;
};

void TBoss1Dragon::request_state_change(u32 state32) {
    struct Dragon_800284B4 *self = (struct Dragon_800284B4 *)this;
    struct Pkt_800284B4 pkt;

    ((TBoss1Dragon *) self)->dispatch_action(state32, 6);
    ((TObjPlayer *)(&pkt))->set_type_dragon();
    pkt.owner = self->owner;
    pkt.state = state32;
    pkt.cursor = self->cursor;
    pkt.target = self->target;
    pkt.x = self->x;
    pkt.z = self->z;
    ((TObjPlayer *)(&pkt))->send_6x12_packet();
}

void send_state_sync__12TBoss1DragonFPv(struct dragon_80028530 *s) {
    struct pkt_80028530 pkt;
    ((TObjPlayer *)(&pkt))->set_type_dragon();
    pkt.target_id = s->target_id;
    pkt.state = s->mode;
    pkt.cursor = (s16) s->sequence_cursor;
    pkt.extra = s->extra;
    pkt.x = s->outgoing_x;
    pkt.z = s->outgoing_z;
    ((TObjPlayer *)(&pkt))->send_6x12_packet();
}

void TBoss1Dragon::receive_state_request(u8 *arg1) {
    s16 temp_r4;
    enemy_set_target_id(this, (u16) *(s32 *)((s8 *)arg1 + 8));
    this->sequenceCursor = (s32) *(s16 *)((s8 *)arg1 + 6);
    this->savedX = (f32) *(f32 *)((s8 *)arg1 + 0xC);
    this->savedZ = (f32) *(f32 *)((s8 *)arg1 + 0x10);
    this->dispatch_action(*(s16 *)((s8 *)arg1 + 4), 7);
    temp_r4 = *(s16 *)((s8 *)arg1 + 4);
    if ((s16) this->mode != temp_r4) {
        transition_enemy_state(temp_r4);
    }
}

void handle_6x12_dragon_boss_actions(TObjPlayer *arg0) {
    void *x;
    arg0->bswap_6x12_packet();
    x = get_enemy_entity(*(u16 *)((s8 *)arg0 + 0x2));
    if (x != NULL) {
        ((TBoss1Dragon *)x)->receive_state_request((u8 *)arg0);
    }
}

void TBoss1Dragon::set_params(void *arg1) {
    enemy_set_target_id(this, (u16) *(s32 *)((s8 *)arg1 + 8));
    this->sequenceCursor = (s32) *(s16 *)((s8 *)arg1 + 6);
    if ((s16) this->mode != (s16) *(s16 *)((s8 *)arg1 + 4)) {
        transition_enemy_state(*(s16 *)((s8 *)arg1 + 4));
    }
}

void handle_6x11_dragon_boss_actions(void *arg0) {
    void *x;
    ((TObjPlayer *)arg0)->bswap_dragon_boss_fields();
    x = get_enemy_entity(*(u16 *)((s8 *)arg0 + 0x2));
    if (x != NULL) {
        ((TBoss1Dragon *)x)->set_params(arg0);
    }
}

void TBoss1Dragon::copy_params(void *arg1) {
    enemy_set_target_id(this, (u16) *(s32 *)((s8 *)arg1 + 8));
    this->sequenceCursor = (s32) *(s16 *)((s8 *)arg1 + 6);
    transition_enemy_state(*(s16 *)((s8 *)arg1 + 4));
}

void handle_6x10_dragon_boss_actions(void *arg0) {
    void *x;
    ((TObjPlayer *)arg0)->bswap_stats();
    x = get_enemy_entity(*(u16 *)((s8 *)arg0 + 0x2));
    if (x != NULL) {
        ((TBoss1Dragon *)x)->copy_params(arg0);
    }
}

typedef char RecoveredGlobal_800646F0_lbl_80437944_size[sizeof(RecoveredGlobal_800646F0_lbl_80437944) == 0x14 ? 1 : -1];
typedef char RecoveredGlobal_800646F0_lbl_804FF5B4_size[sizeof(RecoveredGlobal_800646F0_lbl_804FF5B4) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_8006435C_lbl_80437D2C_size[sizeof(RecoveredGlobal_8006435C_lbl_80437D2C) == 0x14 ? 1 : -1];
typedef char RecoveredGlobal_80064CFC_lbl_80487848_size[sizeof(RecoveredGlobal_80064CFC_lbl_80487848) == 0x10 ? 1 : -1];
typedef char RecoveredGlobal_80064CFC_lbl_804FF5A0_size[sizeof(RecoveredGlobal_80064CFC_lbl_804FF5A0) == 0x14 ? 1 : -1];

typedef char RecoveredGlobal_8002885C_TBoss1Dragon__data_804FE168_size[sizeof(RecoveredGlobal_8002885C_TBoss1Dragon__data_804FE168) == 0x14 ? 1 : -1];

void TBoss1Dragon::reload_impact_stats() {
    reload_stats_keep_hp_tp__9TObjEneDDFv(this, (&TBoss1Dragon__data_805D4B00)[boss1_dragon_base_stat_indices[3]], ((s32 *)&TBoss1Dragon__part_hp_stats)[boss1_dragon_attack_stat_indices[3]], (&TBoss1Dragon__data_805D4B04)[boss1_dragon_resistance_stat_indices[3]]);
}

void TBoss1Dragon::reload_stats_for_phase(int _w1) {
    reload_stats_keep_hp_tp__9TObjEneDDFv(this, (&TBoss1Dragon__data_805D4B00)[boss1_dragon_base_stat_indices[2]], ((s32 *)&TBoss1Dragon__part_hp_stats)[boss1_dragon_attack_stat_indices[2]], (&TBoss1Dragon__data_805D4B04)[boss1_dragon_resistance_stat_indices[2]]);
}

void TBoss1Dragon::reset_tail_hp() {
    s32 arg0 = (s32)this;
    reset_hp__9TObjEneDDFPUcPUcPUc((void *)arg0, 0, (int) (*(s32 *)((s8 *)(&(*(RecoveredGlobal_8002885C_TBoss1Dragon__data_804FE168 *)&TBoss1Dragon__part_hp_stats).value) + 4)), 0);
}

void TBoss1Dragon::reload_difficulty_stats() {
    reload_stats_keep_hp_tp__9TObjEneDDFv(this,
        (&TBoss1Dragon__data_805D4B00)[boss1_dragon_base_stat_indices[0]],
        ((s32 *)&TBoss1Dragon__part_hp_stats)[boss1_dragon_attack_stat_indices[0]],
        (&TBoss1Dragon__data_805D4B04)[boss1_dragon_resistance_stat_indices[0]]);
}

#pragma push
#pragma fp_contract on
s32 TBoss1Dragon::advance_air_turn() {
    Obj_800288EC *self = (Obj_800288EC *)this;
    f32 t;
    self->f678 += 1.0f;
    t = self->f678;
    if (t <= 35.0f) {
        this->rotation_y = self->f660 + (s32)(t * ((0.5f * self->f664) * t + self->f66C));
        return 0;
    }
    if (t <= 60.0f) {
        t -= 35.0f;
        this->rotation_y = self->f660 + (s32)(t * ((0.5f * self->f668) * t + self->f670) + self->f674);
        return 0;
    }
    return 1;
}
#pragma pop

#pragma push
#pragma fp_contract on
void TBoss1Dragon::init_air_turn(s32 targetAngle) {
    f32 target;
    f32 difference;
    f32 work;
    f32 half;
    airTurnVelocity = (s16)airTurnVelocity;
    target = (f32)airTurnVelocity;
    difference = (f32)angle_diff_s16(rotation_y, targetAngle);
    f32 duration = (35.0f);
    f32 endTime = (25.0f);
    half = 0.5f;
    airTurnFinalAcceleration = -((difference - (target * 0.5f) * duration) *
        (2.0f)) / lbl_805D80AC;
    airTurnAcceleration = -(airTurnFinalAcceleration * endTime + target) / duration;
    airTurnTime = (0.0f);
    airTurnInitialVelocity = target;
    airTurnFinalVelocity = -(airTurnFinalAcceleration * endTime);
    work = half * airTurnAcceleration;
    work = work * duration + target;
    airTurnMidpointAngle = duration * work;
    airTurnStartAngle = rotation_y;
}
#pragma pop

void TBoss1Dragon::set_result_flag(s32 arg1, s32 arg2) {
    if (angle_diff_s16(arg1, arg2) >= 0) {
        *(s32 *)((s8 *)this + 0x65C) = 1;
        return;
    }
    *(s32 *)((s8 *)this + 0x65C) = -1;
}

void TBoss1Dragon__sub_80028AFC(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 0x3C0) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C0) & 0xFFFFFEFF);
    *(f32 *)((s8 *)arg0 + 0x5D8) = (f32) (lbl_805D800C + *(f32 *)((s8 *)arg0 + 0x3C));
    *(f32 *)((s8 *)arg0 + 0x5DC) = (f32) (lbl_805D800C + *(f32 *)((s8 *)arg0 + 0x5E0));
}

void TBoss1Dragon__sub_80028B28(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 0x3C0) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C0) | 0x100);
    *(f32 *)((s8 *)arg0 + 0x5D8) = (f32) (TBoss1Dragon__data_805D8040 + *(f32 *)((s8 *)arg0 + 0x3C));
    *(f32 *)((s8 *)arg0 + 0x5DC) = (f32) (TBoss1Dragon__data_805D8040 + *(f32 *)((s8 *)arg0 + 0x5E0));
}

void TBoss1Dragon::beginHeightTransition() {
    flags |= 0x100;
    height = position.y;
    heightOffset = defaultHeightOffset;
}

void TBoss1Dragon::setPhase2() {
    phase = 2;
}

void TBoss1Dragon::setActive() {
    phase = 1;
}

void TBoss1Dragon::clearState() {
    phase = 0;
}

void TBoss1Dragon::play_nearby_se() {
    s32 arg0 = (s32)this;
    if (((TObjMotion *)arg0)->is_passing_frame((5.0f)) != 0) {
        play_se_at_pos__12TBoss1DragonFii(arg0, 0x4003A804);
    }
}

void TBoss1Dragon__sub_80028BE0(u8 *arg0) {
    if ((((TObjMotion *)arg0)->is_passing_frame((f32)(4.0f)) != 0) || (((TObjMotion *)arg0)->is_passing_frame((f32)((f32)lbl_805D80B0)) != 0)) {
        play_se_at_pos__12TBoss1DragonFii((s32) arg0, 0x4003A801);
    }
}

void spawn_trap__12TBoss1DragonFii(s32 arg0, s32 arg1) {
    play_persistent_sound(arg1, arg0, arg0 + 0x63C, 0, 0);
}

void play_se_at_pos__12TBoss1DragonFii(s32 arg0, s32 arg1) {
    play_sound_effect(arg1, arg0 + 0x63C, 0, 0);
}

s32 select_forward_target__12TBoss1DragonFPv(u8 *self) {
    u16 selected[4];
    Vec_80028CA8 delta;
    Vec_80028CA8 fwd;
    f32 cutoff;
    s32 n;
    s32 count;
    u8 *p;
    s32 i;
    n = 0;
    count = TLobby::get_game_mode();
    if (count > 4) {
        count = 4;
    }
    cutoff = cos_table_lookup(0x3000);
    fwd.x = sin_table_lookup(*(s32 *)(self + 0x60));
    fwd.y = (0.0f);
    fwd.z = cos_table_lookup(*(s32 *)(self + 0x60));
    for (i = 0; i < count; i++) {
        p = (u8 *)get_player_data__10TObjPlayerFi(i);
        if (is_alive__8TObjBaseFv(p) != 0) {
            ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&delta, p + 0x38);
            subtract_vector(&delta, self + 0x38);
            ((void (*)(void *))normalize_vector_xz__FP3Vec)(&delta);
            if (vec3_dot(&delta, &fwd) > cutoff) {
                selected[n++] = get_entity_id(p);
            }
        }
    }
    if (n <= 0) {
        enemy_clear_target__12TObjEneDD_STFUs(self);
        return 0;
    }
    if (n == 1) {
        enemy_set_target_id(self, selected[0]);
        return 1;
    }
    enemy_set_target_id(self, selected[(s32)floor_to_float((f32)n * ((f32 (*)(void *))random_ratio__9TObjCharaFv)(self))]);
    return 1;
}

extern const f32 lbl_805D80B4;

void prepare_flight_destination__12TBoss1DragonFPv(u8 *arg0) {
    extern u8 TBoss1Dragon__data_80434E80[0xC];
    if (((s32 (*)(void))is_primary_sequence__12TBoss1DragonFv)() != 0) {
        ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(arg0 + 0x394, arg0 + 0x38);
        *(f32 *)((s8 *)arg0 + 0x398) = (f32) (0.0f);
        ((s32 (*)(void *))normalize_vector_xz__FP3Vec)(arg0 + 0x394);
        *(f32 *)((s8 *)arg0 + 0x394) = (f32) (*(f32 *)((s8 *)arg0 + 0x394) * lbl_805D80B4);
        *(f32 *)((s8 *)arg0 + 0x39C) = (f32) (*(f32 *)((s8 *)arg0 + 0x39C) * lbl_805D80B4);
        return;
    }
    ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(arg0 + 0x394, TBoss1Dragon__data_80434E80);
}

s32 choose_burrow_ring_destination__12TBoss1DragonFPvPv(Dragon_80028EA8 *arg0, Vec_80028EA8 *arg1) {
    s32 idx;
    f32 r;
    idx = (s32)floor_to_float((12.0f) * random_ratio__9TObjCharaFv());
    if (arg0->count < 12) {
        arg0->count++;
        while ((0.0f) != arg0->slots[idx]) {
            idx++;
            if (idx >= 12) {
                idx = 0;
            }
        }
        r = rand_range__9TObjEneDDFff(arg0, (100.0f), (220.0f));
        arg0->slots[idx] = r;
    } else {
        r = arg0->slots[idx];
    }
    arg1->x = r * sin_table_lookup(idx * 0x1555);
    arg1->y = (0.0f);
    arg1->z = r * cos_table_lookup(idx * 0x1555);
    return 1;
}

#define arg1 ((Vec_80028F9C *)out_)
s32 TBoss1Dragon::select_air_fire_target(void *out_) {
    s32 arg0 = (s32)this;
    Player_80028F9C *p;
    Player_80028F9C *list[12];
    s32 top;
    s32 count;
    s32 i;
    s32 best;
    Vec_80028F9C *apos;
    Player_80028F9C *a;
    Player_80028F9C *b;
    s32 found;
    s32 i2;
    s32 j;
    f32 range;
    s32 sum;
    range = lbl_805D80B8;
    count = 0;
    for (i = 0; i < 12; i++) {
        p = (Player_80028F9C *)get_player_by_client_id(i);
        if (is_valid_target__9TObjEneDDFv(p) != 0 && horizontal_distance_squared(&p->pos, (void *)(arg0 + 0x38)) >= range) {
            list[count++] = p;
        }
    }
    if (count <= 0) {
        return 0;
    }
    if (count == 1) {
        ((s32 (*)(Vec_80028F9C *, Vec_80028F9C *))VecCopy__FP3VecPC3Vec)(arg1, &list[0]->pos);
    } else {
        range = (100.0f);
        best = 0;
        found = 0;
        for (i2 = 0; i2 < count; i2++) {
            a = list[i2];
            apos = &a->pos;
            for (j = i2 + 1; j < count; j++) {
                b = list[j];
                if (newton_sqrtf(horizontal_distance_squared(&b->pos, apos)) < range) {
                    found = 1;
                    sum = a->hp + b->hp;
                    if (sum > best) {
                        best = sum;
                        arg1->x = (0.5f) * (apos->x + b->pos.x);
                        arg1->y = (0.5f) * (apos->y + b->pos.y);
                        arg1->z = (0.5f) * (apos->z + b->pos.z);
                    }
                }
            }
        }
        if (found == 0) {
            s32 k;
            top = 0;
            for (k = 0; k < count; k++) {
                if (top < list[k]->hp) {
                    top = list[k]->hp;
                    ((s32 (*)(Vec_80028F9C *, Vec_80028F9C *))VecCopy__FP3VecPC3Vec)(arg1, &list[k]->pos);
                }
            }
        }
    }
    return 1;
}
#undef arg1

void TBoss1Dragon::update_damage_threshold() {
    s16 current = this->hp;
    s32 hp = this->hpmax;
    s16 step = hp / 10;
    s16 threshold = hp - step;
    step += step;
    while (current <= threshold) {
        threshold -= step;
    }
    hpThreshold = threshold;
}

s32 TBoss1Dragon::is_secondary_sequence() {
    return (u8)(sequenceCursor >= 50);
}

s32 TBoss1Dragon::is_primary_sequence() {
    return sequenceCursor < 50;
}

void TBoss1Dragon::select_sequence(int secondary) {
    if (secondary == 0) {
        sequenceCursor = 0;
        return;
    }
    sequenceCursor = 50;
}

void TBoss1Dragon::restart_primary_sequence() {
    select_sequence(0);
}

f32 TBoss1Dragon::sample_root_height() {
    struct Vec_80029238 v;
    v.x = (0.0f);
    v.y = (0.0f);
    v.z = (0.0f);
    push_matrix_from(identity_matrix);
    scale_matrix(0, (2.0f), (2.0f), (2.0f));
    bind_motion_context((NJS_MOTION *)this->current_motion, this->frame);
    compose_motion_node_matrix(this->model);
    matrix_mult_vec(0, &v, &v);
    pop_matrix();
    return v.y;
}

s32 is_destination_ahead__12TBoss1DragonFPv(u8 *s) {
    Vec_800292C0 pt;
    Vec_800292C0 diff;
    Vec_800292C0 unused;

    ((TBoss1Dragon *)s)->calc_forward_point(&pt.x, &pt.z);
    VecCopy__FP3VecPC3Vec((s32) &diff, (s32)(s + 0x394));
    subtract_vector(&diff, &pt);
    return ((f32 (*)(void *))normalize_vector_xz__FP3Vec)(&diff) <= (35.0f);
}

extern const f32 lbl_805D80B4;

#pragma push
#pragma fp_contract on
void TBoss1Dragon::calc_forward_point(f32 *arg1, f32 *arg2) {
    *arg1 = (lbl_805D80BC * sin_table_lookup(this->rotation_y)) + this->position.x;
    *arg2 = (lbl_805D80BC * cos_table_lookup(this->rotation_y)) + this->position.z;
}
#pragma pop

void calc_target_vector__12TBoss1DragonFPv(u8 *arg0) {
    f32 temp_f1;
    f32 temp_f2;

    temp_f2 = *(f32 *)((s8 *)arg0 + 0x394);
    *(f32 *)((s8 *)arg0 + 0x5C8) = (f32) (temp_f2 - *(f32 *)((s8 *)arg0 + 0x40C));
    *(f32 *)((s8 *)arg0 + 0x5CC) = (f32) (0.0f);
    temp_f1 = *(f32 *)((s8 *)arg0 + 0x39C);
    *(f32 *)((s8 *)arg0 + 0x5D0) = (f32) (temp_f1 - *(f32 *)((s8 *)arg0 + 0x414));
    *(f32 *)((s8 *)arg0 + 0x5D4) = normalize_vector_xz__FP3Vec(arg0 + 0x5C8, temp_f1, temp_f2);
}

void TBoss1Dragon::update_linked_epsilon_position() {
    update_linked_position__12TObjEneDD_STFf((1000.0f));
}

void TBoss1Dragon::vfunc_88() {
    Vec_80029408 pts[7];
    Vec_80029408 *p;
    f32 lim;
    s32 off;
    s32 i;
    Coll_80029408 *c;
    p = pts;
    VecCopy__FP3VecPC3Vec((s32)p++, (s32)(((u8 *)this) + 0x430));
    VecCopy__FP3VecPC3Vec((s32)p++, (s32)(((u8 *)this) + 0x46C));
    VecCopy__FP3VecPC3Vec((s32)p++, (s32)(((u8 *)this) + 0x454));
    VecCopy__FP3VecPC3Vec((s32)p++, (s32)(((u8 *)this) + 0x43C));
    VecCopy__FP3VecPC3Vec((s32)p++, (s32)(((u8 *)this) + 0x5B0));
    VecCopy__FP3VecPC3Vec((s32)p++, (s32)(((u8 *)this) + 0x4C0));
    VecCopy__FP3VecPC3Vec((s32)p, (s32)(((u8 *)this) + 0x4FC));
    update_local_colliders_from_world(this, pts);
    lim = (30.0f);
    i = 0;
    off = 0;
    do {
        c = (Coll_80029408 *)(*(u8 * *)&this->bodies + off);
        if (c->local.y >= lim) {
            set_collider_contact_high((u8 *)c);
        } else {
            set_collider_contact_low((u8 *)c);
        }
        i++;
        off += 0x2C;
    } while (i < 7);
    if (this->mode != 9) {
        set_collider_contact_high((u8 *)(*(Coll_80029408 * *)&this->bodies + 3));
        set_collider_contact_high((u8 *)(*(Coll_80029408 * *)&this->bodies + 4));
    }
    (*(Coll_80029408 * *)&this->bodies)[0].defense = *(s32 *)((s8 *)TBoss1Dragon__data_804FE17C[0] + 0x20);
    (*(Coll_80029408 * *)&this->bodies)[1].defense = *(s32 *)((s8 *)TBoss1Dragon__data_804FE17C[0] + 0x1C);
    (*(Coll_80029408 * *)&this->bodies)[2].defense = *(s32 *)((s8 *)TBoss1Dragon__data_804FE17C[0] + 0x1C);
    (*(Coll_80029408 * *)&this->bodies)[3].defense = *(s32 *)((s8 *)TBoss1Dragon__data_804FE17C[0] + 0x20);
    (*(Coll_80029408 * *)&this->bodies)[4].defense = *(s32 *)((s8 *)TBoss1Dragon__data_804FE17C[0] + 0x20);
    (*(Coll_80029408 * *)&this->bodies)[5].defense = *(s32 *)((s8 *)TBoss1Dragon__data_804FE17C[0] + 0x18);
    (*(Coll_80029408 * *)&this->bodies)[6].defense = *(s32 *)((s8 *)TBoss1Dragon__data_804FE17C[0] + 0x20);
}

void TBoss1Dragon::update_position_history() {
    s32 arg0 = (s32)this;
    VecCopy__FP3VecPC3Vec(arg0 + 0x2FC, arg0 + 0x430);
    VecCopy__FP3VecPC3Vec(arg0 + 0x74, arg0 + 0x2FC);
}

void TBoss1Dragon::vfunc_61() {  }

void TBoss1Dragon::vfunc_62() {  }

void TBoss1Dragon::vfunc_63() {  }

void TBoss1Dragon::vfunc_28() {  }

void TBoss1Dragon::check_death() {
    if (this->is_primary_sequence() != 0) {
        if (update_max_hp_phase() != 0) {
            return;
        }
        goto block_8;
    }
    if (!(this->flags & 0x800) && ((s32) this->hp <= 0)) {
        if ((s32) this->phase == 1) {
            this->request_state_change(0xC);
            return;
        }
        this->request_state_change(0x15);
        return;
    }
block_8:
    this->dispatch_action(this->mode, 0xB);
}

void TBoss1Dragon::choose_next_action() {
    if (this->is_primary_sequence() != 0) {
        if (!(this->flags & 0x400)) {
            if (update_max_hp_phase() == 0) {
                if (check_phase_advance() != 0) {
                    return;
                }
                goto block_12;
            }
        } else {
            goto block_12;
        }
    } else {
        if (!(this->flags & 0x800) && (this->hp <= 0)) {
            if ((s32) this->phase == 1) {
                if ((s32) enable_v2_features != 0) {
                    this->request_state_change(0xC);
                    return;
                }
                transition_enemy_state(0xC);
                return;
            }
            this->request_state_change(0x15);
            return;
        }
block_12:
        if ((s32) lbl_805D4B34 != 0) {
            this->dispatch_action(this->mode, 2);
            return;
        }
        if ((s32) *(s32 *)((s8 *)this + 0x760) != 0) {
            this->dispatch_action(this->mode, 0xB);
            return;
        }
        this->dispatch_action(this->mode, 9);
    }
}

#include "pso/enemy/TObjEnePanarms.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/misc/TQuestVmDownLoadServer.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
extern "C" {
s32 obj_isState2_324__9TObjCharaFv();
void TBoss1Dragon__sub_8002AB6C(u8 *arg0);
void copy_model_node(u8 *arg0, u8 *arg1);

#pragma push
#pragma fp_contract on
void TBoss1Dragon::run_task() {
    s16 temp_r0;
    s16 temp_r3;
    s16 temp_r3_2;
    s16 temp_r3_3;
    s16 temp_r3_4;
    s32 temp_r0_2;
    s32 temp_r30;
    s32 temp_r30_2;
    u8 *arg0 = (u8 *)this;
    if (TObjPlayer::check_demo_mode() != 0) {
        ((TBoss1Dragon *)(arg0))->vfunc_105();
        return;
    }
    if (((TBoss1Dragon *)arg0)->flags & 0x40) {
        ((TObjEnemy *)arg0)->send_entity_set_flags();
        queue_destruction__7TObjectFv(arg0);
        return;
    }
    if ((s32) *(s32 *)((s8 *)arg0 + 0x760) != 0) {
        ((TBoss1Dragon *)arg0)->hold_captured_player();
        ((TBoss1Dragon *)arg0)->controlTimer = (s32) (((TBoss1Dragon *)arg0)->controlTimer + 1);
    } else if ((is_main_phase_15__9TObjEneDDFv() != 0) && ((s32) *(s32 *)((s8 *)arg0 + 0x6E0) == 0)) {
        temp_r30 = *(s32 *)((s8 *)arg0 + 0x3E0);
        if (((TObjEneDD *)arg0)->update_lobby_state() != 0) {
            *(s32 *)((s8 *)arg0 + 0x3E0) = 0;
            if ((s32) *(s32 *)((s8 *)arg0 + 0x3E0) != temp_r30) {
                *(s32 *)((s8 *)arg0 + 0x8B8) = 1;
            }
        } else {
            *(s32 *)((s8 *)arg0 + 0x3E0) = 1;
        }
    }
    temp_r30_2 = query_teammate_state__9TObjEneDDFv();
    ((TBoss1Dragon *)(arg0))->update_attack_stat_status();
    ((TBoss1Dragon *)(arg0))->update_defense_stat_status();
    if (temp_r30_2 == 0) {
        temp_r0 = ((TBoss1Dragon *)arg0)->mode;
        if ((temp_r0 == 0x15) || (temp_r0 == 0x16)) {
            ((TBoss1Dragon *)arg0)->actorFlags = (s32) (((TBoss1Dragon *)arg0)->actorFlags | 0x800);
        } else {
            ((TBoss1Dragon *)arg0)->actorFlags = (s32) (((TBoss1Dragon *)arg0)->actorFlags & 0xFFFFF7FF);
        }
        if ((s32) *(s32 *)((s8 *)arg0 + 0x760) != 0) {
            if ((s32) *(u16 *)((s8 *)arg0 + 0x764) == (s32) local_client_id) {
                if ((((TBoss1Dragon *)(arg0))->test_flag30_512() != 0) && (is_primary_sequence__12TBoss1DragonFv(arg0) != 0)) {
                    ;
                    if ((s16) ((TBoss1Dragon *)arg0)->hp < (s16) ((TBoss1Dragon *)arg0)->finalHpThreshold) {
                        ((TBoss1Dragon *)arg0)->hp = ((TBoss1Dragon *)arg0)->finalHpThreshold;
                    }
                    ((TObjEneDD *)arg0)->clear_attack_receipts();
                }
                if ((s32) TBoss1Dragon__data_805D4B38 == 0) {
                    ((TBoss1Dragon *)arg0)->release_held_player();
                } else {
                    ((TBoss1Dragon *)arg0)->check_death();
                }
                ((TBoss1Dragon *)(arg0))->dispatch_action(((TBoss1Dragon *)arg0)->mode, 8);
                ((TBoss1Dragon *)(arg0))->dispatch_action(((TBoss1Dragon *)arg0)->mode, 0);
            } else {
                if ((((TBoss1Dragon *)(arg0))->test_flag30_512() != 0) && (is_primary_sequence__12TBoss1DragonFv(arg0) != 0)) {
                    ;
                    if ((s16) ((TBoss1Dragon *)arg0)->hp < (s16) ((TBoss1Dragon *)arg0)->finalHpThreshold) {
                        ((TBoss1Dragon *)arg0)->hp = ((TBoss1Dragon *)arg0)->finalHpThreshold;
                    }
                    ((TObjEneDD *)arg0)->clear_attack_receipts();
                }
                if ((s32) TBoss1Dragon__data_805D4B38 == 0) {
                    ((TBoss1Dragon *)arg0)->release_held_player();
                }
                ((TBoss1Dragon *)(arg0))->dispatch_action(((TBoss1Dragon *)arg0)->mode, 0);
            }
        } else {
            temp_r0_2 = *(s32 *)((s8 *)arg0 + 0x3E0);
            if (temp_r0_2 != 1) {
                if (temp_r0_2 == 2) {
                    ((TBoss1Dragon *)(arg0))->dispatch_action(((TBoss1Dragon *)arg0)->mode, 2);
                } else {
                    if ((((TBoss1Dragon *)(arg0))->test_flag30_512() != 0) && (is_primary_sequence__12TBoss1DragonFv(arg0) != 0)) {
                        ;
                        if ((s16) ((TBoss1Dragon *)arg0)->hp < (s16) ((TBoss1Dragon *)arg0)->finalHpThreshold) {
                            ((TBoss1Dragon *)arg0)->hp = ((TBoss1Dragon *)arg0)->finalHpThreshold;
                        }
                        ((TObjEneDD *)arg0)->clear_attack_receipts();
                    }
                    ((TBoss1Dragon *)arg0)->choose_next_action();
                }
                ((TBoss1Dragon *)(arg0))->dispatch_action(((TBoss1Dragon *)arg0)->mode, 8);
                ((TBoss1Dragon *)(arg0))->dispatch_action(((TBoss1Dragon *)arg0)->mode, 0);
            } else {
                if ((((TBoss1Dragon *)(arg0))->test_flag30_512() != 0) && (is_primary_sequence__12TBoss1DragonFv(arg0) != 0)) {
                    ;
                    if ((s16) ((TBoss1Dragon *)arg0)->hp < (s16) ((TBoss1Dragon *)arg0)->finalHpThreshold) {
                        ((TBoss1Dragon *)arg0)->hp = ((TBoss1Dragon *)arg0)->finalHpThreshold;
                    }
                    ((TObjEneDD *)arg0)->clear_attack_receipts();
                }
                ((TBoss1Dragon *)(arg0))->dispatch_action(((TBoss1Dragon *)arg0)->mode, 0);
            }
        }
    }
    ((TObjEneDD *)arg0)->sub_800BBA0C();
    ((TBoss1Dragon *)(arg0))->vfunc_88();
    ((TBoss1Dragon *)arg0)->update_position_history();
    ((TObjEnemy *)arg0)->submit_default_cursor_candidate();
    add_radar_scaled_marker((u8 *)&this->position, -0x5DB4, 1, 1, (f32) (((2.0f))));
    VecCopy__FP3VecPC3Vec((s32)(arg0 + 0x648), (s32)(arg0 + 0x2FC));
    if (temp_r30_2 == 0) {
        ((TObject *)(arg0 + 0x3C4))->run_tasks();
    }
    project_sound_origin_from_camera((s32)(arg0 + 0x38), (u8 *)(arg0 + 0x63C), lbl_805D80C0);
}
#pragma pop

Obj_80029C78 *destroy__12TBoss1DragonFPvs(Obj_80029C78 *o, s16 flag) {
    if (o != 0) {
        o->vt = lbl_80481280;
        if (o->f774 != 0) {
            delete o->f774;
            o->f774 = 0;
        }
        if (o->f6D8 != 0) {
            queue_destruction__7TObjectFv(o->f6D8);
            o->f6D8 = 0;
        }
        if (o->f68C != 0) {
            delete o->f68C;
            o->f68C = 0;
        }
        if (o->f688 != 0) {
            __dt__17AreaAttackHistoryFv((s32)o->f688, 1);
            o->f688 = 0;
        }
        if (o->f684 != 0) {
            delete o->f684;
            o->f684 = 0;
        }
        free_collision_body_parts(o);
        if ((Obj_80029C78 *)TBoss1Dragon__data_805D4B2C == o) {
            TBoss1Dragon__data_805D4B2C = 0;
        }
        __destroy_arr(o->f6E8, (void *)__dt__15RenderFadeStateFv, 0x1c, 4);
        TObjBoss2Tunnel::maybe_delete((s32)o->f618, (s16)(-1));
        TObjBoss2Tunnel::maybe_delete((s32)o->f5F4, (s16)(-1));
        __dt__7TObjectFv(o->f3C4, -1);
        __dt__12TObjEneDD_STFv(o, 0);
        if (flag > 0) {
            __dl__7TObjectFPv(o);
        }
    }
    return o;
}

#define F_29DE4(o, T, off) (*(T *)(o + (off)))
#define O_29DE4 ((Obj_80029DE4 *)arg0)
#pragma push
#pragma opt_loop_invariants off
#pragma opt_common_subs off
u8 *TBoss1Dragon__ct(u8 *arg0, void *arg1, void *arg2) {
    u32 sp8[3];
    s32 i;
    s32 j;
    void *p;

    __ct__12TObjEneDD_STFP7TObject(arg0, arg1);
    F_29DE4(arg0, s32, 0x18) = (s32)lbl_80481280;
    __ct__7TObjectFP7TObject(arg0 + 0x3C4, 0);
    TObjBoss2Tunnel::reset_coords_pass((s32)(arg0 + 0x5F4));
    TObjBoss2Tunnel::reset_coords_pass((s32)(arg0 + 0x618));
    __construct_array(arg0 + 0x6E8, __ct__15RenderFadeStateFv, __dt__15RenderFadeStateFv, 0x1C, 4);
    __ct__14SubtractiveRngFv(arg0 + 0x77C);
    F_29DE4(arg0, s32, 0) = lbl_805D2650;
    if ((u32)TBoss1Dragon__data_805D4B2C == 0U) {
        TBoss1Dragon__data_805D4B2C = (s32)arg0;
    }
    invoke_initialization_hook__9TObjEneDDFPv(arg0, arg2);
    F_29DE4(arg0, s32, 0x3C0) = 0;
    if (((TObjEnemy *)arg0)->exchange_object_state((s32)sp8, (s16)1) != 0 && (sp8[0] & 0x12008) == 0x12008) {
        F_29DE4(arg0, s32, 0x3C0) |= 0x40;
    }
    ((TObjEneDD *)arg0)->init_position_vectors();
    F_29DE4(arg0, s32, 0x34) = F_29DE4(F_29DE4(TBoss1Dragon__data_805D4B08, u8 *, 0x42C), s32, 8);
    F_29DE4(arg0, s32, 0x24) = F_29DE4(F_29DE4(TBoss1Dragon__data_805D4B08, u8 *, 0x42C), s32, 0xC);
    init_model__9TObjEneDDFP13CollisionBodyl(arg0, (void *)boss1_dragon_collision_body_parts, 7);
    F_29DE4(arg0, s32, 0xB0) = 0;
    ((TObjMotion *)arg0)->set_field_d8((s32)((void *)lbl_80481010));
    ((TObjMotion *)arg0)->set_field_dc(F_29DE4(TBoss1Dragon__data_805D4B08, u32, 0x430));
    F_29DE4(arg0, s16, 0xB8) = 0;
    ((TObjMotion *)arg0)->set_animation(F_29DE4(arg0, s16, 0xB8));
    ((TObjMotion *)arg0)->set_field_b8(F_29DE4(arg0, s16, 0xB8));
    reset_hp__9TObjEneDDFPUcPUcPUc(arg0, (&TBoss1Dragon__data_805D4B00)[boss1_dragon_base_stat_indices[0]],
                            ((s32 *)&TBoss1Dragon__part_hp_stats)[boss1_dragon_attack_stat_indices[0]],
                            (&TBoss1Dragon__data_805D4B04)[boss1_dragon_resistance_stat_indices[0]]);
    ((TObjEneDD *)arg0)->check_state_flag_1();
    F_29DE4(arg0, s32, 0x350) = (s32)boss1_dragon_init_params;
    initialize_enemy_state__9TObjEneDDFl(arg0, 0x2C);
    F_29DE4(arg0, f32, 0x37C) = (20.0f);
    ((TObjEneDD_ST *)arg0)->enemy_init_acquire_period(10);
    ((TObjEneDD_ST *)arg0)->enemy_init_validate_period(10);
    F_29DE4(arg0, s32, 0x3E4) = 0;
    F_29DE4(arg0, s32, 0x3C0) |= 0x100;
    for (i = 0; i < 3; i++) {
        VecCopy__FP3VecPC3Vec((s32)&O_29DE4->v3[i], (s32)&O_29DE4->pos);
    }
    VecCopy__FP3VecPC3Vec((s32)(arg0 + 0x40C), (s32)&O_29DE4->pos);
    VecCopy__FP3VecPC3Vec((s32)(arg0 + 0x418), (s32)&O_29DE4->pos);
    VecCopy__FP3VecPC3Vec((s32)(arg0 + 0x424), (s32)&O_29DE4->pos);
    for (i = 0; i < 0x22; i++) {
        VecCopy__FP3VecPC3Vec((s32)&O_29DE4->v22[i], (s32)&O_29DE4->pos);
    }
    F_29DE4(arg0, f32, 0x5C8) = (0.0f);
    F_29DE4(arg0, f32, 0x5CC) = (0.0f);
    F_29DE4(arg0, f32, 0x5D0) = (0.0f);
    F_29DE4(arg0, f32, 0x5D4) = (0.0f);
    F_29DE4(arg0, f32, 0x5D8) = (0.0f);
    F_29DE4(arg0, f32, 0x5E0) = (0.0f);
    F_29DE4(arg0, f32, 0x5DC) = F_29DE4(arg0, f32, 0x5E0);
    F_29DE4(arg0, f32, 0x5E4) = (0.0f);
    F_29DE4(arg0, f32, 0x5E8) = (0.0f);
    F_29DE4(arg0, f32, 0x5EC) = (0.0f);
    F_29DE4(arg0, f32, 0x5F0) = (0.0f);
    ((TObjBoss2Tunnel *)(arg0 + 0x5F4))->reset_coords();
    ((TObjBoss2Tunnel *)(arg0 + 0x618))->reset_coords();
    VecCopy__FP3VecPC3Vec((s32)(arg0 + 0x63C), (s32)&O_29DE4->pos);
    VecCopy__FP3VecPC3Vec((s32)(arg0 + 0x648), (s32)&O_29DE4->pos);
    F_29DE4(arg0, s32, 0x654) = 0;
    F_29DE4(arg0, s32, 0x658) = 0;
    F_29DE4(arg0, s32, 0x65C) = 1;
    F_29DE4(arg0, f32, 0x664) = (0.0f);
    F_29DE4(arg0, f32, 0x668) = (0.0f);
    F_29DE4(arg0, f32, 0x678) = (0.0f);
    F_29DE4(arg0, s32, 0x67C) = 0;
    F_29DE4(arg0, s16, 0x680) = 0;
    F_29DE4(arg0, s16, 0x682) = F_29DE4(arg0, s16, 0x2B8) * 3 / 10;
    F_29DE4(F_29DE4(arg0, u8 *, 0x2B0), f32, 0x10) = TBoss1Dragon__data_805D8010;
    ((TBoss1Dragon *)arg0)->update_damage_threshold();
    p = __nw__7TObjectFUl(0xCC);
    if (p != 0) {
        p = TBoss1DragonEffTail__ct(p, arg0, arg0 + 0x4E4);
    }
    F_29DE4(arg0, void *, 0x684) = p;
    p = ::operator new(0x10);
    if (p != 0) {
        p = __ct__17AreaAttackHistoryFl((u8 *)p, 4);
    }
    F_29DE4(arg0, void *, 0x688) = p;
    p = __nw__7TObjectFUl(0x28);
    if (p != 0) {
        p = TBoss1DragonColli__ct((u8 *)p, (s32)(arg0 + 0x3C4));
    }
    F_29DE4(arg0, void *, 0x68C) = p;
    F_29DE4(arg0, f32, 0x690) = (0.0f);
    F_29DE4(arg0, f32, 0x694) = (0.0f);
    F_29DE4(arg0, f32, 0x698) = (0.0f);
    F_29DE4(arg0, f32, 0x69C) = (0.0f);
    F_29DE4(arg0, s32, 0x6A0) = 0;
    F_29DE4(arg0, s32, 0x6A4) = 0;
    for (i = 0; i < 12; i++) {
        O_29DE4->f[i] = (0.0f);
    }
    p = __nw__7TObjectFUl(0x40);
    if (p != 0) {
        p = TObjBoss1MokoHill_SoloM__ct((u8 *)p, (u8 *)tl_05, (u8 *)(arg0 + 0x38), (s32)(arg0 + 0x60));
    }
    F_29DE4(arg0, void *, 0x6D8) = p;
    F_29DE4(arg0, void *, 0x6DC) = 0;
    for (j = 0; j < 4; j++) {
        ((TBoss1Dragon *)arg0)->viewFade[j].activate_and_dispatch();
    }
    F_29DE4(arg0, s32, 0x758) = 0;
    F_29DE4(arg0, s32, 0x75C) = 0xA8C;
    F_29DE4(arg0, s32, 0x760) = 0;
    F_29DE4(arg0, u16, 0x764) = 0xFFFF;
    F_29DE4(arg0, s32, 0x768) = 0;
    F_29DE4(arg0, s32, 0x76C) = 0;
    switch (isV2Mode__12TBoss1DragonFv()) {
    case 0:
        F_29DE4(arg0, s32, 0x770) = 1;
        F_29DE4(arg0, u8 *, 0x778) = boss1_dragon_normal_action_table;
        break;
    case 1:
        F_29DE4(arg0, s32, 0x770) = 0x13;
        F_29DE4(arg0, u8 *, 0x778) = boss1_dragon_normal_particle_table;
        break;
    }
    p = __nw__7TObjectFUl(0xB0);
    if (p != 0) {
        p = ((void *(*)(void *, s32, void *))init_base__13TUnk_80481B34Fv)(p, 0, arg0);
    }
    F_29DE4(arg0, void *, 0x774) = p;
    F_29DE4(arg0, s32, 0x864) = 0;
    F_29DE4(arg0, s32, 0x868) = 0;
    F_29DE4(arg0, s32, 0x86C) = 0;
    F_29DE4(arg0, s32, 0x870) = 0;
    F_29DE4(arg0, s32, 0x874) = 0;
    F_29DE4(arg0, s32, 0x878) = 0;
    F_29DE4(arg0, f32, 0x87C) = (0.0f);
    F_29DE4(arg0, f32, 0x880) = (0.0f);
    F_29DE4(arg0, f32, 0x884) = (0.0f);
    F_29DE4(arg0, f32, 0x888) = (0.0f);
    F_29DE4(arg0, f32, 0x88C) = (0.0f);
    F_29DE4(arg0, f32, 0x890) = (0.0f);
    F_29DE4(arg0, f32, 0x894) = (0.0f);
    F_29DE4(arg0, f32, 0x898) = (0.0f);
    F_29DE4(arg0, f32, 0x89C) = (0.0f);
    F_29DE4(arg0, f32, 0x8A0) = (0.0f);
    F_29DE4(arg0, f32, 0x8A4) = (0.0f);
    F_29DE4(arg0, s32, 0x8A8) = 0;
    F_29DE4(arg0, s32, 0x8AC) = 0;
    F_29DE4(arg0, s32, 0x8B0) = 0;
    F_29DE4(arg0, s32, 0x8B4) = 0;
    F_29DE4(arg0, u8 *, 0x6E4) = controller_input_state + 0xC0;
    F_29DE4(arg0, s32, 0x6E0) = 0;
    F_29DE4(arg0, s16, 0x326) = 0;
    if (is_main_phase_15__9TObjEneDDFv() != 0) {
        if (((TObjEneDD *)arg0)->update_lobby_state() != 0) {
            F_29DE4(arg0, s32, 0x3E0) = 0;
        } else {
            F_29DE4(arg0, s32, 0x3E0) = 1;
        }
    } else {
        F_29DE4(arg0, s32, 0x3E0) = 0;
    }
    ((TBoss1Dragon *)arg0)->restart_primary_sequence();
    F_29DE4(arg0, s16, 0x326) = 0x1D;
    if (!(F_29DE4(arg0, s32, 0x3C0) & 0x40)) {
        ((TBoss1Dragon *)arg0)->dispatch_action(F_29DE4(arg0, s16, 0x326), 4);
    }
    F_29DE4(arg0, s32, 0x8B8) = 0;
    return arg0;
}
#pragma pop
#undef F_29DE4
#undef O_29DE4

void TBoss1Dragon::clearControlOverride() {
    TBoss1Dragon__data_805D4B38 = 0;
}

void TBoss1Dragon::setControlOverride(s16 controlId) {
    if (enable_v2_features != 0) {
        TBoss1Dragon__data_805D4B3C = controlId;
        TBoss1Dragon__data_805D4B38 = 1;
    }
}

void TBoss1Dragon::requestActionRefresh() {
    lbl_805D4B34 = 1;
}

void TBoss1Dragon::free_resources() {
    if ((u32) TBoss1Dragon__data_805D4B28 != 0U) {
        TAdSinglePlyChrSelectGC::safe_free((u32)((void*)TBoss1Dragon__data_805D4B28));
        TBoss1Dragon__data_805D4B28 = 0U;
    }
    if ((u32) TBoss1Dragon__data_805D4B08 != 0U) {
        TLobby__sub_8001FE7C((void*)TBoss1Dragon__data_805D4B08, 1);
        TBoss1Dragon__data_805D4B08 = 0U;
    }
}

u8 *TBoss1Dragon::create(s32 arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    TBoss4DarkFalz::dispatch_by_main_phase(0x16);
    temp_r3 = (u8 *)(__nw__7TObjectFUl(0x8BC));
    var_r0 = temp_r3;
    if (var_r0 != NULL) {
        var_r0 = (u8 *)(((u8 *(*)(void *, s32, s32))TBoss1Dragon__ct)(temp_r3, tl_04, arg0));
    }
    return var_r0;
}

#pragma push
#pragma opt_propagation off
extern "C" {
s32 TBoss1Dragon__part_hp_stats[5];
s32 TBoss1Dragon__data_804FE17C[3];
DragonModelVector lbl_804FE188;
DragonCaptureVectors lbl_804FE194;
DragonModelState lbl_804FE1B8;
u8 lbl_804FE1D0[0xC];
u8 lbl_804FE1DC[0xC];
}

void TBoss1Dragon::load_resources() {
    DragonModelNode *source;
    DragonPositionKey *nodes;
    s32 *table;
    s32 *out;
    f32 *capture;
    f32 *delta;
    s32 i;

    switch (isV2Mode__12TBoss1DragonFv()) {
    case 0:
        TBoss1Dragon__data_805D4B08 = load_enemy_bml_resource((u8 *)&boss1_dragon_bml_descriptor);
        break;
    case 1:
        TBoss1Dragon__data_805D4B08 = load_enemy_bml_resource_named((u8 *)&boss1_dragon_bml_descriptor, lbl_80435394);
        break;
    }
    source = ((DragonResource *)TBoss1Dragon__data_805D4B08)->model->root;
    lbl_805D4B24 = TBoss1Dragon::countModelNodes(source);
    TBoss1Dragon__data_805D4B28 = (u32)TQuestVmDownLoadServer::alloc(lbl_805D4B24 * 0x50);
    lbl_804FE1B8.state[0] = 0;
    lbl_804FE1B8.state[1] = 0;
    lbl_804FE1B8.params[0] = (0.0f);
    lbl_804FE1B8.params[1] = (0.0f);
    lbl_804FE1B8.params[2] = (0.0f);
    lbl_804FE1B8.params[3] = (0.0f);
    source = ((DragonResource *)TBoss1Dragon__data_805D4B08)->model->root;
    TBoss1Dragon::cloneModelHierarchy(source, (DragonModelNode *)TBoss1Dragon__data_805D4B28, lbl_804FE1B8.state);

    TBoss1Dragon__data_805D4B0C = 0;
    lbl_805D4B10 = 0x3C;
    lbl_804FE188.x = (0.0f);
    lbl_804FE188.y = (0.0f);
    lbl_804FE188.z = (0.0f);
    lbl_804FE194.vectors[0].x = (0.0f);
    lbl_804FE194.vectors[0].y = (0.0f);
    lbl_804FE194.vectors[0].z = (5.0f);
    capture = &lbl_804FE194.vectors[0].x;
    delta = capture + 3;
    delta[0] = (0.0f);
    lbl_804FE194.vectors[1].y = sin_table_lookup(-0x1555);
    lbl_804FE194.vectors[1].z = cos_table_lookup(-0x1555);
    vec3_add_to(delta, &lbl_804FE194.vectors[0].x);
    lbl_804FE194.vectors[2].x = (0.0f);
    lbl_804FE194.vectors[2].y = lbl_805D80C4;
    lbl_804FE194.vectors[2].z = (1.0f);
    TBoss1Dragon__data_805D4B14 = 0;
    TBoss1Dragon__data_805D4B18 = 0;
    TBoss1Dragon__data_805D4B1C = 0;
    TBoss1Dragon__data_805D4B20 = 0;
    TBoss1Dragon__data_805D4B2C = 0;

    DragonMotionData *data = ((DragonResource *)TBoss1Dragon__data_805D4B08)->motions[13].motion->data;
    for (i = 0; i < 1; i++) {
        nodes = data[i].positionKeys;
        nodes[25].value.y -= lbl_805D80C8;
        nodes[26].value.y -= lbl_805D8034;
        nodes[27].value.y -= lbl_805D8080;
        nodes[28].value.y -= (0.8f);
        nodes[29].value.y -= (1.0f);
        nodes[30].value.y -= lbl_805D80CC;
        nodes[31].value.y -= lbl_805D80CC;
        nodes[32].value.y -= lbl_805D80CC;
        nodes[33].value.y -= lbl_805D80CC;
        nodes[34].value.y -= lbl_805D80D0;
        nodes[35].value.y -= lbl_805D80D4;
        nodes[36].value.y += lbl_805D80C0;
        nodes[37].value.y += lbl_805D80D8;
    }
    nodes[38].value.y += lbl_805D80DC;
    nodes[39].value.y += lbl_805D80E0;
    nodes[40].value.y += (30.0f);

    nodes = ((DragonResource *)TBoss1Dragon__data_805D4B08)->motions[12].motion->data->positionKeys;
    nodes[41].value.y += lbl_805D80E4;
    nodes[42].value.y += lbl_805D80E8;
    nodes[43].value.y += (20.0f);
    nodes[44].value.y += lbl_805D8084;
    nodes[45].value.y += lbl_805D80EC;
    nodes[46].value.y += lbl_805D80F0;
    nodes[47].value.y += lbl_805D80F4;
    nodes[48].value.y += lbl_805D80F8;
    nodes[50].value.y -= (2.5f);
    nodes[51].value.y -= (4.0f);
    nodes[52].value.y -= lbl_805D80F8;
    nodes[53].value.y -= lbl_805D80FC;
    nodes[54].value.y -= lbl_805D8100;
    nodes[55].value.y -= (0.5f);

    out = &TBoss1Dragon__data_805D4B00;
    for (s32 i = 0; i < 1; i++) { out[i] = (s32)TLobby::register_boss((&lbl_805D2648)[i]); }
    table = boss1_dragon_attack_param_ids;
    out = (s32 *)&TBoss1Dragon__part_hp_stats;
    for (s32 i = 0; i < 5; i++) {
        out[i] = (s32)TLobby::dispatch_shared_handler_b(table[i]);
    }
    for (s32 i = 0; i < 1; i++) { (&TBoss1Dragon__data_805D4B04)[i] = (s32)TLobby::register_object((&lbl_805D264C)[i]); }
    for (s32 i = 0; i < 3; i++) {
        TBoss1Dragon__data_804FE17C[i] = (s32)TLobby::dispatch_shared_handler_a(boss1_dragon_resistance_param_ids[i]);
    }
    lbl_805D4B34 = 0;
    TBoss1Dragon__data_805D4B38 = 0;
    TBoss1Dragon__data_805D4B3C = 0xFFFF;
    TWindowCtrl::init_all_slots();
    TBoss1Dragon::select_fireball_particle_table();
}
}
#pragma pop

#pragma push
#pragma fp_contract on
void calc_follow_camera_offsets__12TBoss1DragonFv(TBoss1Dragon *self, Vec *eye, Vec *target) {
    s32 phase;
    Vec *limit;

    if (((TBoss1Dragon *)TBoss1Dragon__data_805D4B2C)->mode == 0x16) {
        VecCopy(eye, (Vec *)boss1_dragon_follow_camera_offsets);
        VecCopy(target, (Vec *)lbl_804811CC);
        return;
    }
    switch (self->phase) {
    case 0:
    default:
        phase = 0;
        break;
    case 1:
        phase = 1;
        break;
    case 2:
        phase = 2;
        break;
    }
    VecCopy(eye, (Vec *)boss1_dragon_follow_camera_phase_positions + phase);
    VecCopy(target, (Vec *)boss1_dragon_follow_camera_phase_targets + phase);
    if (*(u32 *)((s8 *)self + 0x654) == 1) {
        target->y += TBoss1Dragon__data_805D8010;
        target->z += TBoss1Dragon__data_805D8010;
    }
    if (*(s32 *)((s8 *)self + 0x760) != 0 && *(u16 *)((s8 *)self + 0x764) == local_client_id) {
        if (self->mode == 0xF) {
            VecCopy(eye, (Vec *)boss1_dragon_held_camera_positions + 3);
            limit = (Vec *)boss1_dragon_held_camera_targets + 3;
            eye->y += (0.5f) * self->height;
            VecCopy(target, limit);
            target->x = (0.0f);
            target->y += self->height;
            if (target->y > limit->x) {
                target->y = limit->x;
            } else if (target->y < TBoss1Dragon__data_805D8010) {
                target->y = (1.0f);
            }
        } else {
            VecCopy(eye, (Vec *)boss1_dragon_held_camera_positions + phase);
            VecCopy(target, (Vec *)boss1_dragon_held_camera_targets + phase);
        }
        eye->y += lbl_805D8090;
        target->y += lbl_805D8090;
    }
}
#pragma pop

typedef char RecoveredGlobal_80065EA0_lbl_80487CCC_size[sizeof(RecoveredGlobal_80065EA0_lbl_80487CCC) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_80065EA0_lbl_80487CD8_size[sizeof(RecoveredGlobal_80065EA0_lbl_80487CD8) == 0x354 ? 1 : -1];
typedef char RecoveredGlobal_80065DB4_lbl_804FF5B4_size[sizeof(RecoveredGlobal_80065DB4_lbl_804FF5B4) == 0xC ? 1 : -1];
void get_dragon_follow_camera_offsets(u8 *arg0, u8 *arg1) {
    if ((void *) (*(u8 * *)&TBoss1Dragon__data_805D4B2C) == NULL) {
        VecCopy__FP3VecPC3Vec((s32)arg0, (s32)(((s32 *)boss1_dragon_follow_camera_offsets)));
        VecCopy__FP3VecPC3Vec((s32)arg1, (s32)(((s32 *)lbl_804811CC)));
        return;
    }
    calc_follow_camera_offsets__12TBoss1DragonFv((TBoss1Dragon *)TBoss1Dragon__data_805D4B2C, (Vec *)arg0, (Vec *)arg1);
}
typedef char RecoveredGlobal_80065F08_lbl_80437938_size[sizeof(RecoveredGlobal_80065F08_lbl_80437938) == 0xC ? 1 : -1];

s32 TBoss1Dragon::get_instance() {
    return TBoss1Dragon__data_805D4B2C;
}

void TUnk_80481B34::apply_hit_if_active(void *arg1, f32 *) {
    ((TObjChara *)(((u8 *)arg1)))->receive_physical_attack((void *)this->m_ac, (1.0f));
    TBoss1Dragon__sub_8002AB6C(((u8 *)arg1));
}

void TUnk_80481B34::area_attack_receive_direct(void *self_arg, f32 *arg2, void *arg3_arg) {
    TObjChara *self = (TObjChara *)self_arg;
    s32 *arg3 = (s32 *)arg3_arg;
    s32 off;
    s32 i;
    CollisionBody *e;

    off = 0;
    for (i = 0; i < self->body_count; i++) {
        e = (CollisionBody *)((u8 *)self->bodies + off);
        if (e->flags & 0x04000000) {
            DirectAttackPayload sp8 = *(DirectAttackPayload *)arg3;
            self->receive_direct_attack((void *)this->m_ac, sp8, e, -1, -1);
            TBoss1Dragon__sub_8002AB6C((u8 *)self);
            return;
        }
        off += 0x2C;
    }
}

void TBoss1Dragon__sub_8002AB6C(u8 *arg0) {
    if (obj_isState2_324__9TObjCharaFv() == 0) {
        ((TBoss1Dragon *)(arg0))->apply_movement_ailment(0);
    }
}

void *TUnk_80481B34::dt(s16 arg1) {
    if (this != NULL) {
        (*(s32 * *)((u8 *)this + 0x18)) = lbl_80481B34;
        __dt__13TUnk_804928CCFv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

void *TUnk_80481B34::init_base() {
    __ct__13TUnk_804928CCFP7TObjectP8TObjBase(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_80481B34;
    return this;
}

DragonModelNode* TBoss1Dragon::cloneModelHierarchy(DragonModelNode* source, DragonModelNode* output, void* model) {
    DragonModelNode* current = output;
    ++output;
    copy_model_node((u8*)current, (u8*)source);
    current->model = model;
    if (source->child != 0) {
        current->child = output;
        output = cloneModelHierarchy(source->child, output, model);
    }
    if (source->sibling != 0) {
        current->sibling = output;
        output = cloneModelHierarchy(source->sibling, output, model);
    }
    return output;
}

void copy_model_node(u8 *arg0, u8 *arg1) {
    *(s32 *)((s8 *)arg0 + 0) = (s32) *(s32 *)((s8 *)arg1 + 0);
    *(s32 *)((s8 *)arg0 + 4) = (s32) *(s32 *)((s8 *)arg1 + 4);
    *(ByteBlock_C *)((s32) arg0 + 8) = *(const ByteBlock_C *)((s32) arg1 + 8);
    *(ByteBlock_C *)((s32) arg0 + 0x14) = *(const ByteBlock_C *)((s32) arg1 + 0x14);
    *(ByteBlock_C *)((s32) arg0 + 0x20) = *(const ByteBlock_C *)((s32) arg1 + 0x20);
    *(s32 *)((s8 *)arg0 + 0x2C) = (s32) *(s32 *)((s8 *)arg1 + 0x2C);
    *(s32 *)((s8 *)arg0 + 0x30) = (s32) *(s32 *)((s8 *)arg1 + 0x30);
    *(f32 *)((s8 *)arg0 + 0x34) = (f32) *(f32 *)((s8 *)arg1 + 0x34);
}

s32 TBoss1Dragon::countModelNodes(DragonModelNode* source) {
    s32 count=1;
    DragonModelNode* child=source->child;
    if(child!=0)count=countModelNodes(child)+1;
    DragonModelNode* sibling=source->sibling;
    if(sibling!=0)count+=countModelNodes(sibling);
    return count;
}

void TBoss1Dragon::apply_poison_status() {  }

void TBoss1Dragon::apply_paralysis() {  }

void TBoss1Dragon::apply_slow_status() {  }

void TBoss1Dragon::apply_confusion_status() {  }

void TBoss1Dragon::apply_movement_ailment(s32) {  }

void TBoss1Dragon::apply_shock_status() {  }

void TBoss1Dragon::clear_harmful_statuses() {  }

extern s32 registered_player_count;

s32 TLobby::get_game_mode() {
    return registered_player_count;
}

extern s16 TCameraCtrl__camera_mode;

s32 TCameraCtrl::get_camera_mode() {
    return TCameraCtrl__camera_mode;
}

extern "C" {
f64 floor(f64);

int TObjEneDD::get_flag_b4() { return (this->motion_flags >> 4) & 0x1; }

f32 floor_to_float(f32 value) {
    return (f32) floor((f64)value);
}
s32 fn_8002AE08(void *p) {
    return ((TBoss8Dragon *)p)->test_card_flag_2() ? 0x20000 : 0x10000;
}

}

int TBoss8Dragon::test_card_flag_2() { return TWindowKeyBoardHard::test_card_flag((s32)this, 2); }

void TBoss8Dragon::set_speed(f32 v) { this->m_10 = v; }

void TObjEnemy::sub_8002AE64() {
    this->motion_flags = (s32) (this->motion_flags & 0xFFFFFFFE);
}

void TObjMotion::set_field_b8(s16 v) { this->requested_action = v; }

extern s32 TLobby__data_805D6144;

void TObjMotion::set_field_dc(s32 v) { *(s32 *)&this->motion_list = v; }
void TObjMotion::set_field_d8(s32 v) { (*(s32 *)&this->action_table) = v; }
void TObjPlayer::reset_lobby_model() { reset_type(); }
void TObjPlayer::reset_type() { *(s32*)((char*)this + 0x0) = 0; }
void ProtectionTimer::set_frames(s32 v) { frames = v; }
void TObjPlayer::send_6x12_packet() { bswap_6x12_packet(); send_subcommand((u8 *)this); }
void TObjPlayer::bswap_6x12_packet() { ((G_ClientIDHeader *)this)->bswap(); bswap_16((u16 *)((char*)this + 0x4)); bswap_16((u16 *)((char*)this + 0x6)); bswap_32((u32 *)((char*)this + 0x8)); }
void TObjPlayer::set_type_dragon() { *(u8*)((char*)this + 0x0) = 18; *(u8*)((char*)this + 0x1) = 5; }
void TObjPlayer::bswap_dragon_boss_fields() { ((G_ClientIDHeader *)this)->bswap(); bswap_16((u16 *)((char*)this + 0x4)); bswap_16((u16 *)((char*)this + 0x6)); bswap_32((u32 *)((char*)this + 0x8)); }
void TObjPlayer::bswap_stats() { ((G_ClientIDHeader *)this)->bswap(); bswap_16((u16 *)((char*)this + 0x4)); bswap_16((u16 *)((char*)this + 0x6)); bswap_32((u32 *)((char*)this + 0x8)); }
s32 TObjEnemy::exchange_object_state(s32 arg1, s16 arg2) {
    s16 temp_r31;
    temp_r31 = *(s16 *)&this->set_index;
    if ((temp_r31 < 0) || (temp_r31 > 0xB4F)) {
        return 0;
    }
    if (arg2 == 0) {
        ((TLobby *)(TLobby__data_805D6144 + (temp_r31 * 0xC)))->copy_header((void *)arg1);
    }
    if (arg2 == 1) {
        ((TLobby *)arg1)->copy_header((void *) (TLobby__data_805D6144 + (temp_r31 * 0xC)));
    }
    return 1;
}

void TLobby::copy_header(void *arg1) {
    *(s32 *)&this->m_name = (s32) *(s32 *)((s8 *)arg1 + 0);
    this->m_flags = (u16) *(u16 *)((s8 *)arg1 + 4);
    this->m_id = (s16) *(s16 *)((s8 *)arg1 + 6);
    *(u8 *)&this->m_prev = (u8) *(u8 *)((s8 *)arg1 + 8);
    *(u8 *)((s8 *)this + 9) = (u8) *(u8 *)((s8 *)arg1 + 9);
    *(u8 *)((s8 *)this + 0xA) = (u8) *(u8 *)((s8 *)arg1 + 0xA);
    *(u8 *)((s8 *)this + 0xB) = (u8) *(u8 *)((s8 *)arg1 + 0xB);
}

struct O_8002B094 { s32 *arr; s32 val; s32 f8; s32 count; };

extern "C" {

void fill_value_array(s32 address) {
    O_8002B094 *self = (O_8002B094 *)address;
    s32 i;
    for (i = 0; i < self->count; i++) {
        self->arr[i] = self->val;
    }
    self->f8 = 0;
}

}

extern "C" {
extern f32 lbl_805D9E80;
extern const f32 lbl_805D4AF0 = 3.0f * lbl_805D9E80;
extern const f32 TBoss1Dragon__gravity_accel = 2.0f * lbl_805D9E80;
f32 lbl_805D4AF8 = 5.0f * lbl_805D9E80;
f32 boss1_dragon_gravity = lbl_805D8014 * lbl_805D9E80;
s32 TBoss1Dragon__data_805D4B00;
s32 TBoss1Dragon__data_805D4B04;
u32 TBoss1Dragon__data_805D4B08;
s32 TBoss1Dragon__data_805D4B0C;
s32 lbl_805D4B10;
s32 TBoss1Dragon__data_805D4B14;
s32 TBoss1Dragon__data_805D4B18;
s32 TBoss1Dragon__data_805D4B1C;
s32 TBoss1Dragon__data_805D4B20;
s32 lbl_805D4B24;
u32 TBoss1Dragon__data_805D4B28;
s32 TBoss1Dragon__data_805D4B2C;
f32 boss1_dragon_visibility_distance;
s32 lbl_805D4B34;
s32 TBoss1Dragon__data_805D4B38;
u16 TBoss1Dragon__data_805D4B3C;
extern const f32 lbl_805D4B40 = 5.0f * lbl_805D9E80;
}
