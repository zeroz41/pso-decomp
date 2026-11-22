#include "pso/unk/text_80087278.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/system/BmlAccessors.h"
#include "pso/system/BmlResource.h"
#include "types.h"
#include "pso/system/ModelNodePositionCapture.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/render/NinjaUtil.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjChara.h"
#include "pso/boss/olgaflow/TBoss6Mag.h"
#include "pso/boss/olgaflow/TBoss6Type2.h"
#include "pso/boss/olgaflow/OlgaFlowActions.h"
#include "pso/boss/olgaflow/TBoss6Type2BattleAction.h"
#include <stddef.h>
#include "pso/boss/olgaflow/TBoss6EffHyoui.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include "pso/boss/olgaflow/TBoss6Rock.h"
#include "pso/boss/olgaflow/TBoss6RockChase.h"
#include "pso/boss/olgaflow/TBoss6Type1.h"
#include "pso/enemy/lappy/TObjEneLappy.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/boss/darkfalz/TObjDFDemo5.h"
#include "pso/boss/olgaflow/Boss6Type2Data.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/olgaflow/TBoss6SwordWave.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/boss/darkfalz/TObjDFJisin.h"
#include "pso/system/SoundEffect.h"
#include <stdlib.h>
#include "pso/render/render_util.h"
#include "pso/effect/particle/TParticleCtrl_800874F4.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"

#include "pso/object/TObjControl.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/unk/text_803D96A8.h"

// One row per body motion. update_motion_tracks loops a mode 0 row, holds a
// mode 2 row on its last frame and goes on to row `next`.
struct TBoss6Type2Motion {
    s32 mode;
    s32 next;
    s32 motion[1];  // BML motion of each track (motion_track_count tracks)
    f32 speed;      // frames per update
};

CollisionBody boss6_type2_collision_parts[3] = {
    { { 0.0f, 0.0f, 0.0f }, 15.0f, 0.0f, 0, 0x801B },
    { { 0.0f, 0.0f, 0.0f }, 15.0f, 0.0f, 0, 0x801B },
    { { 0.0f, 0.0f, 0.0f }, 15.0f, 0.0f, 0, 0x801B },
};

TBoss6Type2Motion TBoss6Type2__motion_table[15] = {
    { 0, 0, { 0x37 }, 0.6f },
    { 2, 0, { 0x27 }, 0.2f },
    { 0, 2, { 0x3A }, 0.28f },
    { 0, 3, { 0x3B }, 0.25f },
    { 2, 5, { 0x18 }, 0.48f },
    { 0, 5, { 0x19 }, 0.6f },
    { 2, 0, { 0x10 }, 0.35f },
    { 2, 0, { 0x06 }, 0.3f },
    { 2, 0, { 0x1B }, 0.42f },
    { 2, 0, { 0x1A }, 0.42f },
    { 2, 0, { 0x1C }, 0.45f },
    { 2, 0xD, { 0x02 }, 0.5f },
    { 2, 0, { 0x01 }, 0.6f },
    { 0, 0xD, { 0x39 }, 0.6f },
    { 0, 0xE, { 0x3C }, 0.32f },
};

// The two offsets request_default_follow_camera hands to request_follow_camera_offsets.
Vec lbl_804DFAC4 = { 0.0f, 34.8f, -5.0f };
Vec lbl_804DFAD0 = { 0.0f, 10.43f, 70.42f };

struct Boss_802B9C80;
struct T2_802BB498;
struct T2_802BB554;
struct Obj_802BCD2C;

struct Ent_802BCEF4 { s32 f0; u8 pad4[4]; f32 f8; u8 padC[8]; s32 f14; u8 pad18[4]; };

struct O_802BCEF4 { u8 pad[0x3FC]; s32 model; u8 pad400[0x498 - 0x400]; Ent_802BCEF4 ents[1]; };

struct Prm_802BCAB8 { s32 a; s32 c; f32 b; f32 d; };

struct Ent_802BCAB8 { s32 a; s32 b; };

struct Obj_802BCAB8 { u8 pad[0x400]; Ent_802BCAB8 ents[2]; };

struct Obj_802BC050;
struct T2_802BB768;
struct Obj_802B9D6C;
struct O_802BCEF4;

struct Tmp_802BE0D4 { s32 a; s16 b; s16 c; u8 pad[0x10]; };

struct Ent_802BE0D4 { s32 a; s32 b; };

struct Ents_802BE0D4 { u8 pad[0x400]; Ent_802BE0D4 ents[2]; };

struct Arr_802BE0D4 { u8 pad[0x378]; s32 arr[32]; };

union TypedVector_802BA6DC {
    struct { f32 x, y, z; } f;
    struct { s32 x, y, z; } bits;
};

union TypedVector_802BAA74 {
    struct { f32 x, y, z; } f;
    struct { s32 x, y, z; } bits;
};

extern "C" {
s32 submit_cursor_candidate(void *, int);
s32 play_persistent_sound(s32 id, saddr a1, uaddr src, s32 a3, s32 flags);
void TObjPlayer__sub_8023DEE0(s16 *p, s16 a, s16 b, u16 id);
void TBoss6Type2__sub_802BA7BC(u8 *o);
void *get_player_by_client_id(s32 i);
f32 xyz_distance(void *, void *);
void TBoss6Type2__sub_802BA598(TBoss6Type2 *self, s32 elapsed, s32 duration);
}
void draw_model_blend_motion(void *arg0, void *arg1, f32 farg0);
extern "C" {
void draw_model_motion(void *arg0, void *arg1, f32 farg0);
f32 sin_table_lookup(int);
f32 cos_table_lookup(int);
s32 init_collision_body_parts(void *, void *, int);
void TBoss6Type2__sub_802BA7B0(void* p);
s32 TBoss6Type2__sub_802BB694(TBoss6Type2 *self);
void TBoss6Type2__sub_802BB818(TBoss6Type2 *self, f32);
void TBoss6Type2__sub_802BBC74(TBoss6Type2 *self);
void TBoss4DarkFalz__sub_8004B4F0(void *dst, void *src);
void TBoss6Rock__sub_80354A44(void);
void free_collision_body_parts(void *);
void set_screen_pos__11TBoss6Type2FPv(void *arg0);
void TBoss6Type2__sub_802BE4E0(s32 *arg0, s32 *boss6_type2_zero_vec);
void TBoss6Type2__sub_802BD938(TBoss6Type2 *self, u8 *arg1);

f64 atan2_float(f32, f32);
struct Stack_802B9D90
{
  s32 sp8;
  s32 spC;
};

struct Obj_802B9D6C { u8 pad[0x77c]; s32 arr[14]; };

struct Obj_802BA158 { u8 pad[0x55c]; u16 f55c; u8 pad2[0x570 - 0x55e]; s32 f570; u8 pad3[0x58c - 0x574]; s32 f58c; s32 f590; s32 f594; s32 f598; };

struct V3_802B9C00 { s32 x, y, z; };

struct T1_802B9C00 {
    u8 pad0[0x38];
    V3_802B9C00 pos;
};

struct V3_802BA078 { s32 x; f32 y; s32 z; };

struct Player_802BA078 { u8 pad0[0x30]; s32 f30; u8 pad34[4]; V3_802BA078 pos; };

struct Boss_802BA078 { u8 pad0[0x4B8]; s32 f4B8; u8 pad4BC[0x55C - 0x4BC]; u16 f55C; };

struct Tb_802B9C80 { s32 a; s32 b; };

struct Boss_802B9C80 {
    u8 pad0[0x38];
    Vec pos;
    u8 pad44[0x77C - 0x44];
    u32 arr[14];
};

typedef struct Stack_802B9D90 Stack_802B9D90;

struct Ent_802BA7BC { s32 idx; s32 arg; f32 lo; };

struct T2_802BA9E4 { u8 pad0[0x38]; u8 f38[0x438]; s32 f470; };

struct Boss_802BA944 { u8 pad[0x4BC]; u32 f4BC; };

struct T2_802BB498 { u8 pad0[0x374]; s32 f374; };

struct T2_802BB554 { u8 pad0[0x374]; s32 f374; };

struct T2_802BB768 { u8 pad0[0x410]; uaddr f410; uaddr f414; };

struct T2_802BB7C0 { u8 pad0[0x410]; uaddr f410; uaddr f414; };

struct Ent_802BC050 { s16 f0; s16 v[5]; };

struct Obj_802BC050 {
    u8 pad0[0x31C];
    Ent_802BC050 *ent;
    u8 pad320[0x434 - 0x320];
    Ent_802BC050 local;
    u8 pad440[0x454 - 0x440];
    s16 max;
    s16 min;
};

struct ByteBlock_C { u8 bytes[0xc]; };


struct RecoveredFields_802BC754_arg0 {
    u8 unknown_0[0x4B4];
    s32 field_4B4;
    s32 field_4B8;
    s32 field_4BC;
    s32 field_4C0;
    s32 field_4C4;
    s32 field_4C8;
    s32 field_4CC;
    s32 field_4D0;
    s32 field_4D4;
    f32 field_4D8;
    f32 field_4DC;
    f32 field_4E0;
    f32 field_4E4;
    f32 field_4E8;
    s32 field_4EC;
};

struct RecoveredFields_802BC754_temp_r3 {
    u8 unknown_0[0x4];
    f32 field_4;
    u8 unknown_8[0x8];
    f32 field_10;
    f32 field_14;
    s32 field_18;
    s32 field_1C;
    s32 field_20;
    s32 field_24;
    s32 field_28;
    s32 field_2C;
};

struct RecoveredFields_802BC754_temp_r3_3 {
    f32 field_0;
    f32 field_4;
    f32 field_8;
    f32 field_C;
};

struct RecoveredFields_802BC754_temp_r3_4 {
    u8 unknown_0[0x8];
    f32 field_8;
    f32 field_C;
};

struct Obj_8004D8C8 { u8 pad[0x2D4]; u16 f2d4; u16 f2d6; };

struct T2_802BD378 { u8 pad0[0x60]; s32 f60; u8 pad64[0x59C - 0x64]; Vec v[1]; };

struct T2_802BD76C { u8 pad0[0x42C]; s32 f42C; };




struct Type2ActionSendStorage {
    OlgaFlowType2ActionMsg message;
    u8 stack_padding[4];
};

LAYOUT_ASSERT(RecoveredFields_802BC754_arg0_4B4_offset, offsetof(RecoveredFields_802BC754_arg0, field_4B4) == 0x4B4);

LAYOUT_ASSERT(RecoveredFields_802BC754_arg0_4B8_offset, offsetof(RecoveredFields_802BC754_arg0, field_4B8) == 0x4B8);

LAYOUT_ASSERT(RecoveredFields_802BC754_arg0_4BC_offset, offsetof(RecoveredFields_802BC754_arg0, field_4BC) == 0x4BC);

LAYOUT_ASSERT(RecoveredFields_802BC754_arg0_4C0_offset, offsetof(RecoveredFields_802BC754_arg0, field_4C0) == 0x4C0);

LAYOUT_ASSERT(RecoveredFields_802BC754_arg0_4C4_offset, offsetof(RecoveredFields_802BC754_arg0, field_4C4) == 0x4C4);

LAYOUT_ASSERT(RecoveredFields_802BC754_arg0_4C8_offset, offsetof(RecoveredFields_802BC754_arg0, field_4C8) == 0x4C8);

LAYOUT_ASSERT(RecoveredFields_802BC754_arg0_4CC_offset, offsetof(RecoveredFields_802BC754_arg0, field_4CC) == 0x4CC);

LAYOUT_ASSERT(RecoveredFields_802BC754_arg0_4D0_offset, offsetof(RecoveredFields_802BC754_arg0, field_4D0) == 0x4D0);

LAYOUT_ASSERT(RecoveredFields_802BC754_arg0_4D4_offset, offsetof(RecoveredFields_802BC754_arg0, field_4D4) == 0x4D4);

LAYOUT_ASSERT(RecoveredFields_802BC754_arg0_4D8_offset, offsetof(RecoveredFields_802BC754_arg0, field_4D8) == 0x4D8);

LAYOUT_ASSERT(RecoveredFields_802BC754_arg0_4DC_offset, offsetof(RecoveredFields_802BC754_arg0, field_4DC) == 0x4DC);

LAYOUT_ASSERT(RecoveredFields_802BC754_arg0_4E0_offset, offsetof(RecoveredFields_802BC754_arg0, field_4E0) == 0x4E0);

LAYOUT_ASSERT(RecoveredFields_802BC754_arg0_4E4_offset, offsetof(RecoveredFields_802BC754_arg0, field_4E4) == 0x4E4);

LAYOUT_ASSERT(RecoveredFields_802BC754_arg0_4E8_offset, offsetof(RecoveredFields_802BC754_arg0, field_4E8) == 0x4E8);

LAYOUT_ASSERT(RecoveredFields_802BC754_arg0_4EC_offset, offsetof(RecoveredFields_802BC754_arg0, field_4EC) == 0x4EC);

LAYOUT_ASSERT(RecoveredFields_802BC754_temp_r3_4_offset, offsetof(RecoveredFields_802BC754_temp_r3, field_4) == 0x4);

LAYOUT_ASSERT(RecoveredFields_802BC754_temp_r3_10_offset, offsetof(RecoveredFields_802BC754_temp_r3, field_10) == 0x10);

LAYOUT_ASSERT(RecoveredFields_802BC754_temp_r3_14_offset, offsetof(RecoveredFields_802BC754_temp_r3, field_14) == 0x14);

LAYOUT_ASSERT(RecoveredFields_802BC754_temp_r3_18_offset, offsetof(RecoveredFields_802BC754_temp_r3, field_18) == 0x18);

LAYOUT_ASSERT(RecoveredFields_802BC754_temp_r3_1C_offset, offsetof(RecoveredFields_802BC754_temp_r3, field_1C) == 0x1C);

LAYOUT_ASSERT(RecoveredFields_802BC754_temp_r3_20_offset, offsetof(RecoveredFields_802BC754_temp_r3, field_20) == 0x20);

LAYOUT_ASSERT(RecoveredFields_802BC754_temp_r3_24_offset, offsetof(RecoveredFields_802BC754_temp_r3, field_24) == 0x24);

LAYOUT_ASSERT(RecoveredFields_802BC754_temp_r3_28_offset, offsetof(RecoveredFields_802BC754_temp_r3, field_28) == 0x28);

LAYOUT_ASSERT(RecoveredFields_802BC754_temp_r3_2C_offset, offsetof(RecoveredFields_802BC754_temp_r3, field_2C) == 0x2C);

LAYOUT_ASSERT(RecoveredFields_802BC754_temp_r3_3_0_offset, offsetof(RecoveredFields_802BC754_temp_r3_3, field_0) == 0x0);

LAYOUT_ASSERT(RecoveredFields_802BC754_temp_r3_3_4_offset, offsetof(RecoveredFields_802BC754_temp_r3_3, field_4) == 0x4);

LAYOUT_ASSERT(RecoveredFields_802BC754_temp_r3_3_8_offset, offsetof(RecoveredFields_802BC754_temp_r3_3, field_8) == 0x8);

LAYOUT_ASSERT(RecoveredFields_802BC754_temp_r3_3_C_offset, offsetof(RecoveredFields_802BC754_temp_r3_3, field_C) == 0xC);

LAYOUT_ASSERT(RecoveredFields_802BC754_temp_r3_4_8_offset, offsetof(RecoveredFields_802BC754_temp_r3_4, field_8) == 0x8);

LAYOUT_ASSERT(RecoveredFields_802BC754_temp_r3_4_C_offset, offsetof(RecoveredFields_802BC754_temp_r3_4, field_C) == 0xC);

struct Boss_802BC23C {
    u8 pad[0x418];
    s32 f418;
    u8 pad41c[0x4CC - 0x41C];
    s32 f4cc;
    s32 f4d0;
};

u16 obj_getArrU16_FC(void *obj, s32 i);
u16 get_entity_id(void *);
s32 is_split_screen();
void request_follow_camera_offsets(void *arg0, void *arg1, u16 arg2);
s32 project_actor_to_ground(void *, void *, int);
int pick_random_active_player__14TBoss6PlotFalzFv(void*);
f32 TBoss6PlotFalz__sub_802AB684(void *);
void TBoss6PlotFalz__sub_802AC724(void *, void *);
void world_to_grid_pos__11TBoss6Type2FPvPvPv(f32 *arg0, s8 *arg1, s8 *arg2);
void grid_to_world_pos__11TBoss6Type2FccPv(s8 arg0, s8 arg1, f32 *arg2);
void init_parts__11TBoss6Type2FPv(saddr self);
void TBoss6Type2__sub_802B9D6C(Obj_802B9D6C *self);
s32 grab_player__11TBoss6Type2FPvUs(u8 *arg0, u16 arg1);
s32 TBoss6Type2__sub_802BA944(Boss_802BA944 *o);
s32 TBoss6Type2__sub_802BA9E4(T2_802BA9E4 *arg0);
s32 snap_to_ground__11TBoss6Type2FPv(TBoss6Type2 *self);
void TBoss6Type2__sub_802BAD04(saddr arg0);
void request_player_camera_offsets__11TBoss6Type2FPvff(TBoss6Type2 *, f32, f32);
f32 fabs_float(f32);
void TBoss6Type2__sub_802BB4DC(TBoss6Type2 *self);
void TBoss6Type2__sub_802BB5B4(TBoss6Type2 *self, u16 *first, u16 *second);
void TBoss6Type2__sub_802BB768(T2_802BB768 *arg0);
void TBoss6Type2__sub_802BB7C0(T2_802BB7C0 *arg0);
s32 calc_field4f0_delta__11TBoss6Type2FPv(void *arg0);
void TBoss6Type2__sub_802BCC54(void *, int);
void TBoss6Type2__sub_802BD340(void);
void TBoss6Type2__sub_802BD378(T2_802BD378 *arg0, s32 arg1, void *arg2, s32 *arg3);
void TBoss6Type2__sub_8032E708(void *p, s32 v);
void TBoss6Type2__sub_80356E50(s32 arg0, s32 cnt, s32 force);
s32 spawn_flow_soul__11TBoss6Type2Fiii(saddr parent, saddr pos, saddr state_duration);
f32 vec3_add_to(void *, void *);
f32 vector_length(Vec *);
void subtract_vector(Vec *, Vec *);

extern s32 local_client_id;
extern s32 game_difficulty_selection;

// Read by the TBoss6Type2_802BE588/_802BF558 units and TBoss6Rock; emitted ahead of the literal pool.
extern const f32 lbl_805DE3F0 = 400.0f;
extern const f32 lbl_805DE3F4 = 0.2f;
extern const f32 lbl_805DE3F8 = 0.35f;
extern const f32 lbl_805DE3FC = 0.42f;
extern const f32 lbl_805DE400 = 0.5f;
extern const f32 lbl_805DE404 = 0.6f;
extern const f32 lbl_805DE408 = 0.6f;

extern const s32 boss6_type2_hit_check_value_table[] = { 1, 13, 24, 26 };
extern const Ent_802BA7BC boss6_type2_motion_param_table[] = {
    { 3, 3, 11.0f }, { 4, 4, 9.0f }, { 5, 5, 5.0f }, { 8, 0, 11.0f }, { 9, 1, 9.0f }, { 10, 2, 5.0f },
};
extern const s32 boss6_type2_hit_effect_node_table[] = { 4, 9, 11, 0 };

LAYOUT_ASSERT(TypedVector_802BA6DC_size, sizeof(TypedVector_802BA6DC) == 12);

LAYOUT_ASSERT(TypedVector_802BAA74_size, sizeof(TypedVector_802BAA74) == 12);

struct MagParams_802BB818 {
    s16 x;
    u8 pad02[4];
    u16 z;
    s16 active;
    u8 pad0A[6];
    Vec pos;
    u8 pad1C[0x24];
    TBoss6Type2 *owner;
    Vec origin;
    s32 rotation_y;
    s32 index;
    s32 flags;
    s32 variant;
};

struct Mags_802BB818 { u8 pad[0x410]; TBoss6Type2 *mags[2]; };

saddr create_mag__11TBoss6Type2Fl(MagParams_802BB818 *params);

s32 matrix_mult_vec(int, void *, void *);
void set_matrix_identity(u8 *arg0);

struct Anim_802BCD2C { u8 pad[4]; u32 n; };
struct Trk_802BCD2C { Anim_802BCD2C *anim; f32 t; f32 dt; f32 a; f32 da; Anim_802BCD2C *prev_anim; f32 prev_t; };
struct Obj_802BCD2C {
    u8 pad0[0x490];
    s32 f490;
    s32 f494;
    Trk_802BCD2C trk[1];
};

struct Blk_802BCFD4;

// The body runs one motion track (trk[], TBoss6Type2Motion::motion[]); track 0 follows
// the motion table rows. The code loads both from .sdata2, and CW puts them inside the
// literal pool at their first user, so they are file constants read through references.
static const s32 motion_track_count = 1;
static const s32 main_motion_track = 0;

inline const s32 &get_motion_track_count() { return motion_track_count; }
inline const s32 &get_main_motion_track() { return main_motion_track; }

extern "C" u8 *get_enemy_entity(u16 arg0);

struct Fish_802BE014 { u8 pad[0x764]; void *fish[1]; };

}

extern "C" {

void TBoss6Type2::clear_harmful_statuses() {}

void TBoss6Type2::apply_shock_status() {}

void TBoss6Type2::apply_movement_ailment(s32) {}

void TBoss6Type2::apply_confusion_status() {}

void TBoss6Type2::apply_slow_status() {}

void TBoss6Type2::apply_paralysis() {}

void TBoss6Type2::apply_poison_status() {}

s32 TBoss6Type2::create(saddr arg2_) {
    return (saddr)new TBoss6Type2(new TObjControl(tl_04), (saddr *)arg2_);
}

void TBoss6Type2__sub_802BE4E0(s32 *arg0, s32 *boss6_type2_zero_vec) {
    *arg0 = *boss6_type2_zero_vec;
    *(ByteBlock_C *)((saddr) arg0 + 4) = *(const ByteBlock_C *)((saddr) boss6_type2_zero_vec + 4);
}

#pragma push
#pragma opt_common_subs off
TBoss6Type2::TBoss6Type2(TObject *parent, saddr *params) : TObjEnemy(parent) {
    Tmp_802BE0D4 tmp;
    s32 i;
    s32 id;
    m_name = TBoss6Type2__name;
    m_3f8 = (TBoss6PlotFalz *)params[0];
    apply_set_data(params + 1);
    if (exchange_object_state(&tmp, 1) != 0) {
        tmp.a = 0;
        tmp.c = 0;
        exchange_object_state(&tmp, 0);
    }
    m_3fc = (uaddr)TBoss6PlotFalz::get_scene_archive();
    texlist = 0;
    model = 0;
    VecCopy(&position, &TBoss6Type2__initial_position);
    copy_xyz(&rotation_x, (void *)TBoss6Type2__initial_rotation);
    VecCopy(&prev_position, VecCopy(&home_position, VecCopy(&center, &position)));
    init_collision_body_parts(this, boss6_type2_collision_parts, 3);
    advance_position();
    m_310 = 0.0f;
    y_speed = 0.0f;
    x_speed = 0.0f;
    target = 0;
    bind_enemy_combat_stats((u8 *)(TLobby::register_boss(0x2C)), (u8 *)(TLobby::dispatch_shared_handler_b(0x2C)), (u8 *)(TLobby::register_object(0x2C)));
    referenceHp = m_4f8 = hp;
    ((TBoss3Volopt *)this)->reset_photon_effect();
    set_param(0x4E);
    id = ((s8 *)params)[0x44] % 4;
    add_flags_2e4(TBoss6Type2__initial_actor_flag_masks[id]);
    m_428 = id;
    m_42c = m_430 = boss6_type2_variant_id_table[(((s8 *)params)[0x44] >> 2) % 4];
    init_segment_range();
    {
    s32 k;
    for (k = 0; k < 2; k++) {
        Ent_802BE0D4 *e = &((Ents_802BE0D4 *)this)->ents[k];
        id = lbl_8047128C[k];
        e->a = (saddr)get_bml_texlist((BmlResource *)m_3fc, id);
        e->b = (saddr)get_bml_model((BmlResource *)m_3fc, id);
    }
    }
    init_motion_entries();
    m_764 = ModelNodePositionCapture::create(boss6_type2_effect_desc_table, m_59c);
    scroll_strips.build_tables(boss6_type2_plot_falz_entry_table, 2);
    trail_effect = TBoss6Zanzo::create(this, 7, 0xF);
    m_478 = 0;
    m_47c = 0x11;
    TBoss6Type2__sub_802BE4E0((s32 *)&m_480, (s32 *)boss6_type2_zero_vec);
    m_480 = rotation_y;
    VecCopy((Vec *)&target_position, &position);
    m_474 = 0;
    for (i = 0; i < 32; i++) {
        ((Arr_802BE0D4 *)this)->arr[i] = 0;
    }
    m_418 = 0;
    state_progress = 0.0f;
    m_420 = 0;
    m_424 = 0;
    m_464 = 0xFFFF;
    *(s16 *)((s8 *)this + 0x466) = ((s16 (*)(void *))TBoss6Type2__sub_802BB694)(this);
    m_468 = 0xFFFF;
    m_46a = 0xFFFF;
    m_46c = -1;
    m_470 = 0;
    load_battle_params();
    set_screen_pos__11TBoss6Type2FPv(this);
    copy_anim_state();
    reset_attack_counter();
    reset_indices();
    *(f32 *)((s8 *)this + 0x4FC) = 0.0f;
    m_500 = 1.0f;
    m_508 = 0;
    TBoss6Type2__sub_802BB818(this, 0.0f);
    TBoss6Type2__sub_802BB768((T2_802BB768 *)this);
    TBoss6Rock::create_rock_pool(this);
    TBoss6Type2__sub_802BA7B0(this);
    TBoss6Type2::capture_player_snapshots();
    cache_fish_params();
    init_collected_entries();
    set_fields_554();
    TBoss6Type2__sub_802B9D6C((Obj_802B9D6C *)this);
    spawn_particle_slot(0);
    spawn_particle_slot(1);
    spawn_particle_slot(2);
    spawn_particle_slot(3);
    spawn_particle_slot(4);
    spawn_particle_slot(5);
    set_action_state(0);
}
#pragma pop

TBoss6Type2::~TBoss6Type2() {
    s32 i;
    init_parts__11TBoss6Type2FPv((saddr)this);
    reset_counters();
    TBoss6Rock__sub_80354A44();
    for (i = 0; i < 2; i++) {
        Ent_802BE0D4 *e = &((Ents_802BE0D4 *)this)->ents[i];
        e->a = 0;
        e->b = 0;
    }
    scroll_strips.free_buffer_pairs();
    for (i = 0; i < 1; i++) {
        if (((Fish_802BE014 *)this)->fish[i] != 0) {
            ModelNodePositionCapture::destroy((ModelNodePositionCapture *)((Fish_802BE014 *)this)->fish[i]);
            ((Fish_802BE014 *)this)->fish[i] = 0;
        }
    }
    free_collision_body_parts(this);
}

void TBoss6Type2::build_state_packet(OlgaFlowType2ActionMsg *message) {
    u16 spA;
    u16 sp8;
    message->header.client_id = entity_id;
    message->random_factor = static_cast<u8>(127.0f * (3.0517578e-05f * static_cast<f32>(rand())));
    message->next_motion = choose_random_motion();
    message->target_mode = static_cast<s8>(m_428);
    message->target_state = static_cast<s8>(m_430);
    message->first_client = static_cast<s8>(m_464);
    message->second_client = static_cast<s8>(m_466);
    TBoss6Type2__sub_802BB5B4(this, &spA, &sp8);
    message->first_action_client = static_cast<s8>(spA);
    message->second_action_client = static_cast<s8>(sp8);
}

void TBoss6Type2::parse_action_packet(void *packet) {
    this->m_478 = (u8) *(u8 *)((s8 *)packet + 8);
    this->m_47c = (s32) (s8) *(u8 *)((s8 *)packet + 9);
    set_target_state((s32)(*(s8 *)((s8 *)packet + 0xA)), (s32)(*(s8 *)((s8 *)packet + 0xB)));
    this->m_464 = (u16) (s8) *(u8 *)((s8 *)packet + 0xC);
    this->m_466 = (u16) (s8) *(u8 *)((s8 *)packet + 0xD);
    this->m_468 = (u16) (s8) *(u8 *)((s8 *)packet + 0xE);
    this->m_46a = (u16) (s8) *(u8 *)((s8 *)packet + 0xF);
    if ((u16) this->m_464 >= 4U) {
        this->m_464 = 0xFFFFU;
    }
    if ((u16) this->m_466 >= 4U) {
        this->m_466 = 0xFFFFU;
    }
    if ((u16) this->m_468 >= 4U) {
        this->m_468 = 0xFFFFU;
    }
    if ((u16) this->m_46a >= 4U) {
        this->m_46a = 0xFFFFU;
    }
    ((TBoss6Type2 *)this->m_410[0])->set_action_field_0x408(this->m_468);
    ((TBoss6Type2 *)this->m_410[1])->set_action_field_0x408(this->m_46a);
}

void TBoss6Type2::send_action_packet(s8 arg1) {
    OlgaFlowType2ActionMsg message;
    if (reinterpret_cast<TBoss6PlotFalz *>(m_3f8)->is_idle() != 0) {
        message.initialize();
        build_state_packet(&message);
        message.action = arg1;
        message.send();
    }
}

void TBoss6Type2::send_action_packet_if_idle(s32 arg1, s32 *arg2) {
    Type2ActionSendStorage storage;
    const s8 *bytes;
    s32 i;
    if (reinterpret_cast<TBoss6PlotFalz *>(m_3f8)->is_idle() != 0) {
        storage.message.initialize();
        build_state_packet(&storage.message);
        bytes = reinterpret_cast<const s8 *>(arg2);
        storage.message.action = arg1;
        for (i = 1; i < 4; i++) {
            reinterpret_cast<u8 *>(&storage.message)[i + 4] = *bytes++;
        }
        storage.message.send();
    }
}

void TBoss6Type2::update_action_state() {
    s32 sp8;
    s32 var_r4;

    TBoss6Type2__sub_802BD938(this, (u8 *)&sp8);
    var_r4 = 4;
    if ((s32) this->m_46c == 0) {
        var_r4 = 5;
    }
    send_action_packet_if_idle(var_r4, &sp8);
}

void TBoss6Type2::send_state_action_packet() {
    s32 sp8;
    s32 var_r31;
    if ((s32) this->m_424 != 0) {
        var_r31 = 7;
        if ((s32) this->m_46c == 0) {
            var_r31 = 0xA;
        }
    } else {
        var_r31 = 8;
        if ((s32) this->m_46c == 0) {
            var_r31 = 0xB;
        }
    }
    switch (this->m_374) {
    case 6:
    case 9:
        return;
    case 7:
    case 8:
    case 10:
    case 11:
        this->m_466 = ((s16 (*)(void *))TBoss6Type2__sub_802BB694)(this);
        var_r31 = this->m_374 - 1;
    default:
        TBoss6Type2__sub_802BD938(this, (u8 *)&sp8);
        this->send_action_packet_if_idle(var_r31, &sp8);
        break;
    }
}

void TBoss6Type2::update_attack_target() {
    s32 sp8;
    s32 temp_r0;
    s32 var_r31;
    s32 var_r3;
    u16 temp_r31;
    u16 temp_r3;
    u16 var_r30;

    var_r3 = 0x21;
    if ((s32) this->m_424 != 0) {
        var_r3 = 0x1F;
    }
    temp_r0 = this->m_374;
    var_r31 = var_r3;
    switch (temp_r0) {
    case 0x1D:
        return;
    case 0x1E:
    case 0x1F:
    case 0x20:
    case 0x21:
        temp_r31 = this->m_466;
        temp_r3 = ((u16 (*)(void *))TBoss6Type2__sub_802BB694)(this);
        var_r30 = temp_r3;
        if ((u16) temp_r3 == 0xFFFF) {
            if (TBoss6PlotFalz::is_active((TObjPlayer *)get_player_by_client_id(temp_r31)) != 0) {
                var_r30 = temp_r31;
            }
        }
        this->m_466 = var_r30;
        if ((TBoss6PlotFalz::get_phase() == 0) && (this->m_374 & 1)) {
            this->m_466 = 0xFFFFU;
        }
        var_r31 = this->m_374 - 1;
        break;
    }
    TBoss6Type2__sub_802BD938(this, (u8 *)&sp8);
    send_action_packet_if_idle(var_r31, &sp8);
}

#pragma push
#pragma opt_common_subs off
void TBoss6Type2__sub_802BD938(TBoss6Type2 *self, u8 *arg1) {
    s8 grid_x;
    s8 grid_z;
    Vec target;
    Vec dir;
    f32 dist;
    s32 angle;
    s32 angle2;
    TObjPlayer *player;
    player = (TObjPlayer *)get_player_by_client_id(self->m_466);
    if (player != NULL) {
        VecCopy(&target, &player->position);
    } else {
        self->m_466 = 0xFFFFU;
        angle = (s32) ((6144.0f * -((3.0517578e-05f * (f32) rand()) - 0.5f)) + (f32) (s32) self->rotation_y);
        VecCopy(&target, &self->position);
        target.x += 150.0f * sin_table_lookup(angle);
        target.z += 150.0f * cos_table_lookup(angle);
        if (xyz_distance(&self->position, (Vec *)&boss6_arena_center) > 390.0f) {
            angle2 = (s32) (65535.0f * (3.0517578e-05f * (f32) rand()));
            VecCopy(&target, &boss6_arena_center);
            target.x += 150.0f * sin_table_lookup(angle2);
            target.z += 150.0f * cos_table_lookup(angle2);
        }
    }
    target.y = 0.0f;
    VecCopy(&dir, &target);
    subtract_vector(&dir, &self->position);
    dir.y = 0.0f;
    dist = vector_length(&dir);
    if (dist < 7.874016f) {
        if (dist <= 1e-05f) {
            target.x = 1.0f;
        } else {
            normalize_vector(&dir);
        }
        dir.x *= 7.874016f;
        dir.z *= 7.874016f;
        VecCopy(&target, &dir);
        vec3_add_to(&target, &self->position);
    }
    world_to_grid_pos__11TBoss6Type2FPvPvPv(&target.x, &grid_x, &grid_z);
    arg1[0] = grid_x;
    arg1[1] = grid_z;
}
#pragma pop

extern "C" void handle_6xA5_olga_flow_boss_actions(game_command_header *command) {
    OlgaFlowType2ActionMsg *packet = reinterpret_cast<OlgaFlowType2ActionMsg *>(command);
    TBoss6Type2 *boss;
    saddr state;
    packet->swap_entity_id();
    boss = (TBoss6Type2 *)get_enemy_entity(packet->header.client_id);
    if (boss == NULL) {
        return;
    }
    reinterpret_cast<TBoss6Type2 *>(&packet->action)->call_9A24_plus_1(reinterpret_cast<s32 *>(&boss->m_480));
    boss->parse_action_packet(packet);
    state = packet->action;
    if (state < 0 || state >= 36) {
        return;
    }
    boss->set_action_state(state);
}

int TBoss6Type2::get_table_entry(int a0) {  return TBoss6Type2__initial_actor_flag_masks[a0]; }

s32 TBoss6Type2::find_index_in_table(u32 v) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (v == ((const u32 *)TBoss6Type2__initial_actor_flag_masks)[i]) return i;
    }
    return 0;
}

s32 TBoss6Type2::pick_random_other_index() {
    TBoss6Type2 *o = this;
    s32 t = TBoss6Type2::find_index_in_table(o->m_2e4);
    s32 r = t + (s32)(2.99f * (3.0517578e-05f * (f32)rand())) + 1;
    if (r >= 4) {
        r -= 4;
    }
    return r;
}

s32 TBoss6Type2::choose_next_index() {
    T2_802BD76C *arg0 = (T2_802BD76C *)this;
    s32 k = (s32)(2.99f * (3.0517578e-05f * (f32)rand())) + 1;
    s32 r = arg0->f42C + k;
    if (r > 4) {
        r -= 4;
    }
    return r;
}

void TBoss6Type2::set_target_state(s32 arg1, s32 arg2) {
    u32 temp_r31;
    s32 temp_r30;

    temp_r31 = this->m_2e4;
    temp_r30 = *(s32 *)&this->m_42c;
    this->m_2e4 = TBoss6Type2::get_table_entry(arg1);
    *(s32 *)&this->m_42c = arg2;
    update_segments();
    if ((temp_r31 != (u32) this->m_2e4) || (temp_r30 != (s32) *(s32 *)&this->m_42c)) {
        set_state_0x34();
    }
    if (this->m_410[0] != 0) {
        ((TBoss6Type2 *)this->m_410[0])->set_target_nodes((void*)this->m_2e4, (void*)(*(saddr *)&this->m_42c));
    }
    if (this->m_410[1] != 0) {
        ((TBoss6Type2 *)this->m_410[1])->set_target_nodes((void*)this->m_2e4, (void*)(*(saddr *)&this->m_42c));
    }
}

s32 TBoss6Type2::count_matching_values(s32 arg1, s32 arg2) {
    s32 i;
    s32 cnt;
    if (arg2 > 0x20) {
        arg2 = 0x20;
    }
    cnt = 0;
    for (i = 0; i < arg2; i++) {
        if (m_378[i] == arg1) {
            cnt++;
        }
    }
    return cnt;
}

void TBoss6Type2::run_hit_reaction() {
    actorFlags = (s32) (actorFlags & 0xFFFFFDFF);
    *(f32 *)((s8 *)this + 0x4FC) = 1.0f;
    {
        int diff = m_4f8 - hp;
        if (diff > 0) {
            add_damage(diff);
        }
    }
    if ((s32) m_418 != 0) {
        ((s32 (*)(int, void *, int, int))play_sound_effect)(0x68A24, &position, 0, 1);
    }
}

void TBoss6Type2::run_death_reaction() { if (*(int *)&m_374 != 35) { set_action_state(35); } }

f32 TBoss6Type2::receive_physical_attack(void *att, f32 scale) {
    s32 var_r31;
    s32 var_r30;
    s32 var_r29;

    var_r31 = 1;
    if (((s32) m_418 != 0) && (att != 0)) {
        var_r30 = 0;
        var_r29 = 0;
        do {
            switch ((s32) (*(u8 *)((TObjPlayer *)att)->get_attribute_entry(var_r29))) {
            case 1:
                var_r30 |= 1;
                break;
            case 2:
                var_r30 |= 2;
                break;
            case 3:
                var_r30 |= 4;
                break;
            case 4:
                var_r30 |= 8;
                break;
            }
            var_r29 += 1;
        } while (var_r29 < 3);
        if (!(m_2e4 & var_r30)) {
            var_r31 = 0;
        }
    }
    if (var_r31 != 0) {
        return TObjChara::receive_physical_attack(att, scale);
    }
    sub_802BA078();
    spawn_hit_effects();
    return 0.0f;
}

f32 TBoss6Type2::receive_direct_attack(void *attacker, DirectAttackPayload msg, void *collision, s32 tech, s32 flags) {
    while ((s32)m_418 != 0) {
        if (msg.kind == 0x14) {
            break;
        }
        if (TObjEneDD::query_teammate_state() != 0) {
            break;
        }
        if (msg.kind == (s32)m_42c) {
            break;
        }
        sub_802BA078();
        spawn_hit_effects();
        return 0.0f;
    }
    return TObjChara::receive_direct_attack(attacker, msg, collision, tech, flags);
}

void TBoss6Type2::get_phase_values(u16 *a, u16 *b, u16 *out) {
    s32 i;
    *a = ((Obj_8004D8C8 *)this)->f2d6;
    *b = ((Obj_8004D8C8 *)this)->f2d4;
    for (i = 0; i < 4; i++) {
        out[i] = obj_getArrU16_FC(this, i);
    }
}

s32 TBoss6Type2::get_rotation_timer() { return this->m_418; }

void TBoss6Type2__sub_802BD378(T2_802BD378 *arg0, s32 arg1, void *arg2, s32 *arg3) {
    VecCopy((Vec *)(arg2), (const Vec *)(&arg0->v[arg1 + 0xE - 0]));
    *arg3 = arg0->f60;
}

void TBoss6Type2::apply_damage(s32 arg1) {
    if ((arg1 > 0) && ((s32) this->m_418 == 0)) {
        add_damage(arg1);
    }
}

void TBoss6Type2__sub_802BD340(void) {  }

void TBoss6Type2::copy_pos_59c(saddr arg1) {
    saddr arg0 = (saddr)this;
    VecCopy((Vec *)arg1, (const Vec *)(arg0 + 0x59C));
}

void TBoss6Type2::get_push_points(saddr arg1, saddr arg2) {
    saddr arg0 = (saddr)this;
    VecCopy((Vec *)(arg1), (const Vec *)(arg0 + 0x5FC));
    VecCopy((Vec *)(arg2), (const Vec *)(arg0 + 0x5C0));
}

void TBoss6Type2::copy_pos_620(saddr arg1) {
    saddr arg0 = (saddr)this;
    VecCopy((Vec *)arg1, (const Vec *)(arg0 + 0x620));
}

#pragma push
#pragma opt_common_subs off
void TBoss6Type2::run_task() {
    u8 *arg0 = (u8 *)this;
    TBoss6Type2BattleHandler handler;
    update_lower_contact_delta();
    handler = boss6_type2_battle_actions[m_374].update;
    if (handler) {
        (this->*handler)();
    }
    if (((TBoss6PlotFalz *)m_3f8)->is_idle() != 0) {
        handler = boss6_type2_battle_actions[m_374].idle;
        if (handler) {
            (this->*handler)();
        }
    }
    update_motion_tracks();
    advance_position();
    this->sub_802BBE20();
    update_parts_flags();
    ((TObjPlayer *)arg0)->update_collisions();
    submit_cursor_candidate(arg0, -1);
    add_radar_scaled_marker(&this->position, -0x5DB4, 1, 1, 4.0f);
    ((TBoss6Type2 *)arg0)->apply_rock_hits_to_players();
    ((TBoss6Type2 *)arg0)->sub_802BB498();
    ((TBoss6Type2 *)arg0)->sub_802BC124();
    ((TBoss6Type2 *)arg0)->scroll_strips.scroll_strips_uv(8, 0);
    TObjPlayer__sub_8023DEE0((s16 *)(*(saddr *)((s8 *)(*(u8 **)((s8 *)(find_model_node((uaddr)get_bml_model((BmlResource *)this->m_3fc, 1), 1)) + 4)) + 4)), 8, 0, 0);
    ((TBoss6Type2 *)arg0)->sub_802BB554();
    copy_vec_array();
    if ((s32) this->m_418 != 0) {
        play_persistent_sound(0x4006B00C, (saddr)arg0, (uaddr)(arg0 + 0x38), 0, 0);
    }
    update_countdown();
    ((TBoss6Type2 *)arg0)->update_possess_target();
    update_footstep_effects();
    TBoss6Type2__sub_802BA7BC(arg0);
    update_part_positions();
    this->m_4f8 = (s32) this->hp;
}
#pragma pop

void TBoss6Type2::set_action_state(s32 action) {
    s32 i;
    const TBoss6Type2BattleAction *entry;
    TBoss6Type2BattleHandler handler;
    m_374 = action;
    for (i = 31; i > 0; i--) {
        m_378[i] = m_378[i - 1];
    }
    m_378[0] = m_374;
    entry = &boss6_type2_battle_actions[m_374];
    TBoss6Type2__sub_802BCC54(this, entry->motion);
    m_474 = entry->flags;
    handler = entry->enter;
    if (handler) {
        (this->*handler)();
    }
}

Blk_802BCFD4 *TBoss6Type2::copy_block(Blk_802BCFD4 *d, const Blk_802BCFD4 *s) {
    *d = *s;
    return d;
}

void TBoss6Type2::copy_transform(void* q) { *(u32*)((char*)this + 0x0) = *(u32*)((char*)q + 0x0); *(f32*)((char*)this + 0x4) = *(f32*)((char*)q + 0x4); *(f32*)((char*)this + 0x8) = *(f32*)((char*)q + 0x8); *(f32*)((char*)this + 0xc) = *(f32*)((char*)q + 0xc); *(f32*)((char*)this + 0x10) = *(f32*)((char*)q + 0x10); *(u32*)((char*)this + 0x14) = *(u32*)((char*)q + 0x14); *(f32*)((char*)this + 0x18) = *(f32*)((char*)q + 0x18); }

void TBoss6Type2::init_motion_entries() {
    O_802BCEF4 *o = (O_802BCEF4 *)this;
    s32 i;
    TBoss6Type2::copy_block((Blk_802BCFD4 *)((u8 *)o + 0x490), &boss6_type2_zero_motion_block);
    for (i = 0; i < get_motion_track_count(); i++) {
        Ent_802BCEF4 *e = &o->ents[i];
        s32 r;
        ((TBoss6Type2 *)e)->copy_transform((void *)boss6_type2_motion_entry_transform);
        r = (saddr)get_bml_motion((BmlResource *)this->m_3fc, TBoss6Type2__motion_table[0].motion[i]);
        e->f14 = r;
        e->f0 = r;
        e->f8 = TBoss6Type2__motion_table[0].speed;
    }
}

void TBoss6Type2::update_motion_tracks() {
    Obj_802BCD2C *self = (Obj_802BCD2C *)this;
    s32 i;
    Trk_802BCD2C *e;
    f32 n;
    f32 lim;

    for (i = 0; i < get_motion_track_count(); i++) {
        if (i != get_main_motion_track()) {
            e = &self->trk[i];
            n = (f32)e->anim->n;
            e->t += e->dt;
            if (e->t >= n) {
                e->t -= n;
            }
            if (0.0f != e->a) {
                if ((e->a += e->da) >= 1.0f) {
                    e->a = 0.0f;
                }
            }
        }
    }
    e = &self->trk[get_main_motion_track()];
    n = (f32)e->anim->n;
    e->t += e->dt;
    switch (self->f494) {
    case 0:
        if (e->t >= n) {
            e->t -= n;
        }
        break;
    case 1:
        break;
    case 2:
        lim = n - 1.0f;
        if (e->t >= lim) {
            e->t = lim;
            TBoss6Type2__sub_802BCC54(self, TBoss6Type2__motion_table[self->f490].next);
        }
        break;
    }
    if (0.0f != e->a) {
        if ((e->a += e->da) >= 1.0f) {
            e->a = 0.0f;
        }
    }
}

void TBoss6Type2__sub_802BCC54(void *p, int motion) {
    Obj_802BCD2C *self = (Obj_802BCD2C *)p;
    if (motion != -1 && motion != self->f490) {
        TBoss6Type2Motion *ent;
        s32 i;
        self->f490 = motion;
        ent = &TBoss6Type2__motion_table[motion];
        self->f494 = ent->mode;
        for (i = 0; i < get_motion_track_count(); i++) {
            Trk_802BCD2C *e = &self->trk[i];
            Anim_802BCD2C *anim = (Anim_802BCD2C *)get_bml_motion((BmlResource *)(((TBoss6Type2 *)p)->m_3fc), ent->motion[i]);
            e->a = e->da;
            e->prev_anim = e->anim;
            e->prev_t = e->t;
            e->dt = TBoss6Type2__motion_table[motion].speed;
            e->anim = anim;
            e->t = 0.0f;
        }
    }
}

void TBoss6Type2::draw_body_models() {
    u8 *arg0 = (u8 *)this;
    Prm_802BCAB8 prm;
    f32 zero;
    f32 a;
    s32 b;
    ModelNodePositionCapture *capture;
    s32 done;
    s32 i;
    Ent_802BCAB8 *e;
    s32 p0;
    saddr p1;
    set_motion_packed_rotation();
    capture = m_764;
    done = 0;
    if (capture != NULL) {
        zero = 0.0f;
        for (i = 0; i < 2; i++) {
            e = &((Obj_802BCAB8 *)arg0)->ents[i];
            p0 = e->a;
            p1 = e->b;
            switch (i) {
            case 0:
                a = 1.0f - this->state_progress;
                break;
            case 1:
            default:
                a = this->state_progress;
                break;
            }
            if (zero != a) {
                if (a < 1.0f) {
                    TBoss6PlotFalz::set_fade_material_color(a);
                }
                TObjFish::set_global_param((saddr)(p0));
                if (0.0f == *(f32 *)((s8 *)arg0 + 0x4A4)) {
                    if (done != 0) {
                        draw_model_motion((void *)p1, (void *)(*(saddr *)((s8 *)arg0 + 0x498)), *(f32 *)((s8 *)arg0 + 0x49C));
                    } else {
                        capture->install();
                        draw_model_motion((void *)p1, (void *)(*(saddr *)((s8 *)arg0 + 0x498)), *(f32 *)((s8 *)arg0 + 0x49C));
                        capture->clear();
                        done = 1;
                    }
                } else {
                    prm.a = *(s32 *)((s8 *)arg0 + 0x4AC);
                    prm.b = *(f32 *)((s8 *)arg0 + 0x4B0);
                    prm.c = *(s32 *)((s8 *)arg0 + 0x498);
                    prm.d = *(f32 *)((s8 *)arg0 + 0x49C);
                    if (done != 0) {
                        draw_model_blend_motion((void *)p1, &prm, *(f32 *)((s8 *)arg0 + 0x4A4));
                    } else {
                        capture->install();
                        draw_model_blend_motion((void *)p1, &prm, *(f32 *)((s8 *)arg0 + 0x4A4));
                        capture->clear();
                        done = 1;
                    }
                }
                if (a < 1.0f) {
                    TObjFish::reset_fish_globals();
                }
            }
        }
    }
    clear_motion_packed_rotation();
}

void TBoss6Type2::load_battle_params() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0;
    s32 temp_r3_2;
    u8 *temp_r3;
    u8 *temp_r3_3;
    u8 *temp_r3_4;
    temp_r3 = (u8 *)(TLobby::dispatch_shared_handler_a(0x2C));
    ((RecoveredFields_802BC754_arg0 *)arg0)->field_4B4 = (s32) ((RecoveredFields_802BC754_temp_r3 *)temp_r3)->field_4;
    if ((f32) ((RecoveredFields_802BC754_arg0 *)arg0)->field_4B4 <= 0.0f) {
        ((RecoveredFields_802BC754_arg0 *)arg0)->field_4B4 = TBoss6Type2__default_battle_parameters.int_params[0];
    }
    ((RecoveredFields_802BC754_arg0 *)arg0)->field_4B8 = (s32) ((RecoveredFields_802BC754_temp_r3 *)temp_r3)->field_10;
    if ((f32) ((RecoveredFields_802BC754_arg0 *)arg0)->field_4B8 <= 0.0f) {
        ((RecoveredFields_802BC754_arg0 *)arg0)->field_4B8 = TBoss6Type2__default_battle_parameters.int_params[1];
    }
    ((RecoveredFields_802BC754_arg0 *)arg0)->field_4D4 = (s32) ((RecoveredFields_802BC754_temp_r3 *)temp_r3)->field_14;
    if ((f32) ((RecoveredFields_802BC754_arg0 *)arg0)->field_4D4 <= 0.0f) {
        ((RecoveredFields_802BC754_arg0 *)arg0)->field_4D4 = TBoss6Type2__default_battle_parameters.int_params[8];
    }
    ((RecoveredFields_802BC754_arg0 *)arg0)->field_4BC = (s32) ((RecoveredFields_802BC754_temp_r3 *)temp_r3)->field_18;
    if ((s32) ((RecoveredFields_802BC754_arg0 *)arg0)->field_4BC <= 0) {
        ((RecoveredFields_802BC754_arg0 *)arg0)->field_4BC = TBoss6Type2__default_battle_parameters.int_params[2];
    }
    ((RecoveredFields_802BC754_arg0 *)arg0)->field_4C0 = (s32) ((RecoveredFields_802BC754_temp_r3 *)temp_r3)->field_1C;
    if ((s32) ((RecoveredFields_802BC754_arg0 *)arg0)->field_4C0 <= 0) {
        ((RecoveredFields_802BC754_arg0 *)arg0)->field_4C0 = TBoss6Type2__default_battle_parameters.int_params[3];
    }
    ((RecoveredFields_802BC754_arg0 *)arg0)->field_4C4 = (s32) ((RecoveredFields_802BC754_temp_r3 *)temp_r3)->field_20;
    if ((s32) ((RecoveredFields_802BC754_arg0 *)arg0)->field_4C4 <= 0) {
        ((RecoveredFields_802BC754_arg0 *)arg0)->field_4C4 = TBoss6Type2__default_battle_parameters.int_params[4];
    }
    ((RecoveredFields_802BC754_arg0 *)arg0)->field_4C8 = (s32) ((RecoveredFields_802BC754_temp_r3 *)temp_r3)->field_24;
    if ((s32) ((RecoveredFields_802BC754_arg0 *)arg0)->field_4C8 <= 0) {
        ((RecoveredFields_802BC754_arg0 *)arg0)->field_4C8 = TBoss6Type2__default_battle_parameters.int_params[5];
    }
    ((RecoveredFields_802BC754_arg0 *)arg0)->field_4CC = (s32) ((RecoveredFields_802BC754_temp_r3 *)temp_r3)->field_28;
    ((RecoveredFields_802BC754_arg0 *)arg0)->field_4D0 = (s32) ((RecoveredFields_802BC754_temp_r3 *)temp_r3)->field_2C;
    temp_r0 = ((RecoveredFields_802BC754_arg0 *)arg0)->field_4CC;
    if ((temp_r0 < 0) || (temp_r0 > 0x64) || (temp_r3_2 = ((RecoveredFields_802BC754_arg0 *)arg0)->field_4D0, ((temp_r3_2 < 0) != 0)) || (temp_r3_2 > 0x64) || ((s32) (temp_r0 + temp_r3_2) > 0x64)) {
        ((RecoveredFields_802BC754_arg0 *)arg0)->field_4CC = TBoss6Type2__default_battle_parameters.int_params[6];
        ((RecoveredFields_802BC754_arg0 *)arg0)->field_4D0 = TBoss6Type2__default_battle_parameters.int_params[7];
    }
    temp_r3_3 = (u8 *)(TLobby::dispatch_shared_handler_a(0x2F));
    ((RecoveredFields_802BC754_arg0 *)arg0)->field_4D8 = (f32) ((RecoveredFields_802BC754_temp_r3_3 *)temp_r3_3)->field_0;
    if (((RecoveredFields_802BC754_arg0 *)arg0)->field_4D8 <= 0.0f) {
        ((RecoveredFields_802BC754_arg0 *)arg0)->field_4D8 = TBoss6Type2__default_battle_parameters.float_params[0];
    }
    ((RecoveredFields_802BC754_arg0 *)arg0)->field_4DC = (f32) ((RecoveredFields_802BC754_temp_r3_3 *)temp_r3_3)->field_4;
    if (((RecoveredFields_802BC754_arg0 *)arg0)->field_4DC <= 0.0f) {
        ((RecoveredFields_802BC754_arg0 *)arg0)->field_4DC = TBoss6Type2__default_battle_parameters.float_params[1];
    }
    ((RecoveredFields_802BC754_arg0 *)arg0)->field_4E8 = (f32) ((RecoveredFields_802BC754_temp_r3_3 *)temp_r3_3)->field_8;
    if (((RecoveredFields_802BC754_arg0 *)arg0)->field_4E8 <= 0.0f) {
        ((RecoveredFields_802BC754_arg0 *)arg0)->field_4E8 = TBoss6Type2__default_battle_parameters.float_params[4];
    }
    ((RecoveredFields_802BC754_arg0 *)arg0)->field_4EC = (s32) ((RecoveredFields_802BC754_temp_r3_3 *)temp_r3_3)->field_C;
    if ((f32) ((RecoveredFields_802BC754_arg0 *)arg0)->field_4EC <= 0.0f) {
        ((RecoveredFields_802BC754_arg0 *)arg0)->field_4EC = TBoss6Type2__default_battle_parameters.last_param;
    }
    temp_r3_4 = (u8 *)(TLobby::dispatch_shared_handler_a(0x2E));
    ((RecoveredFields_802BC754_arg0 *)arg0)->field_4E0 = (f32) ((RecoveredFields_802BC754_temp_r3_4 *)temp_r3_4)->field_8;
    if (((RecoveredFields_802BC754_arg0 *)arg0)->field_4E0 <= 0.0f) {
        ((RecoveredFields_802BC754_arg0 *)arg0)->field_4E0 = TBoss6Type2__default_battle_parameters.float_params[2];
    }
    ((RecoveredFields_802BC754_arg0 *)arg0)->field_4E4 = (f32) ((RecoveredFields_802BC754_temp_r3_4 *)temp_r3_4)->field_C;
    if (((RecoveredFields_802BC754_arg0 *)arg0)->field_4E4 <= 0.0f) {
        ((RecoveredFields_802BC754_arg0 *)arg0)->field_4E4 = TBoss6Type2__default_battle_parameters.float_params[3];
    }
}

void set_screen_pos__11TBoss6Type2FPv(void *arg0) {
    f32 var_f0;
    f32 var_f1;

    if ((s32) *(s32 *)((s8 *)arg0 + 0x424) != 0) {
        var_f1 = 0.28f * *(f32 *)((s8 *)arg0 + 0x4E0);
        var_f0 = 0.28f * *(f32 *)((s8 *)arg0 + 0x4E4);
    } else {
        var_f1 = 0.28f * *(f32 *)((s8 *)arg0 + 0x4D8);
        var_f0 = 0.28f * *(f32 *)((s8 *)arg0 + 0x4DC);
    }
    TBoss6Type2__motion_table[2].speed = var_f1;
    TBoss6Type2__motion_table[3].speed = var_f1;
    TBoss6Type2__motion_table[14].speed = var_f0;
}

void TBoss6Type2::copy_anim_state() {
    *(s32 *)((s8 *)this + 0x4F0) = (s32) this->hp;
}

s32 calc_field4f0_delta__11TBoss6Type2FPv(void *arg0) {
    return *(s32 *)((s8 *)arg0 + 0x4F0) - *(s16 *)((s8 *)arg0 + 0x32C);
}

void TBoss6Type2::reset_attack_counter() {
    *(s32 *)((s8 *)this + 0x4F4) = 0;
}

void TBoss6Type2::add_damage(s32 diff) {
    s32 temp_r0;
    s32 var_r4;

    var_r4 = diff;
    temp_r0 = this->m_374;
    if (temp_r0 < 9) {
        if (temp_r0 == 5) {
            goto block_4;
        }
        goto block_5;
    } else if (temp_r0 < 0xC) {
block_4:
        var_r4 *= 2;
    }
block_5:
    *(s32 *)((s8 *)this + 0x4F4) = (s32) (*(s32 *)((s8 *)this + 0x4F4) + var_r4);
}

s32 TBoss6Type2::get_hit_count() {
    return *(s32 *)((s8 *)this + 0x4F4);
}

void TBoss6Type2::reset_indices() {
    *(s32 *)((s8 *)this + 0x518) = -1;
    *(s32 *)((s8 *)this + 0x51C) = 0;
}

void TBoss6Type2::start_countdown_sound_state() {
    u8 *arg0 = (u8 *)this;
    *(s32 *)((s8 *)arg0 + 0x518) = 0x34;
    *(s32 *)((s8 *)arg0 + 0x51C) = 0;
    play_sound_if_no_target();
}

void TBoss6Type2::set_state_0x34() {
    u8 *arg0 = (u8 *)this;
    *(s32 *)((s8 *)arg0 + 0x518) = 0x34;
    *(s32 *)((s8 *)arg0 + 0x51C) = 1;
    play_sound_if_no_target();
}

s32 TBoss6Type2::is_active() {
    s32 var_r4;

    var_r4 = 0;
    if ((((s32) *(s32 *)((s8 *)this + 0x51C) != 0) && ((s32) *(s32 *)((s8 *)this + 0x518) >= 0)) || ((s32) this->m_374 == 1)) {
        var_r4 = 1;
    }
    return (u8)((u8) var_r4);
}

void TBoss6Type2::update_countdown() {
    s32 temp_r0;
    void *player;

    if (is_active() != 0) {
        update_attack_switch();
    }
    temp_r0 = *(s32 *)((s8 *)this + 0x518);
    if (temp_r0 < 0) {
        *(s32 *)((s8 *)this + 0x51C) = 0;
        *(s32 *)((s8 *)this + 0x518) = (s32) (*(s32 *)((s8 *)this + 0x518) - 1);
        if ((s32) *(s32 *)((s8 *)this + 0x518) < -0x12C) {
            *(s32 *)((s8 *)this + 0x518) = -0x12C;
        }
        if (((s32) this->m_418 != 0) && ((s32) *(s32 *)((s8 *)this + 0x518) == -0x12C)) {
            player = get_player_by_client_id(*(u16 *)((s8 *)this + 0x55C));
            if ((TBoss6PlotFalz::is_active((TObjPlayer *)player) != 0) && ((s16) *(s16 *)((s8 *)player + 0x326) == 1)) {
                start_countdown_sound_state();
            }
        }
    } else {
        if (temp_r0 == 0) {
            play_phase_sound();
        }
        *(s32 *)((s8 *)this + 0x518) = (s32) (*(s32 *)((s8 *)this + 0x518) - 1);
    }
}

void TBoss6Type2::play_sound_if_no_target() {
    u8 *arg0 = (u8 *)this;
    if (is_target_valid() == 0) {
        play_sound_effect(TBoss6Type2__no_target_sound_ids[TBoss6Type2::find_index_in_table(this->m_2e4)], arg0 + 0x38, 0, 1);
    }
}

void TBoss6Type2::play_phase_sound() {
    u8 *arg0 = (u8 *)this;
    s32 var_r3;

    if (is_target_valid() == 0) {
        switch (this->m_42c) {
        case 1:
            var_r3 = 0x6852C;
            break;
        case 2:
            var_r3 = 0x6852D;
            break;
        case 3:
            var_r3 = 0x6852E;
            break;
        case 4:
            var_r3 = 0x6852F;
            break;
        case 5:
        default:
            var_r3 = 0x6852B;
            break;
        }
        play_sound_effect(var_r3, arg0 + 0x38, 0, 1);
    }
}

void TBoss6Type2::update_attack_switch() {
    u8 *arg0 = (u8 *)this;
    if ((*(s32 *)((s8 *)arg0 + 0x518) % 24) == 0) {
        spawn_particle_effect_with_flags((const Vec *)(arg0 + 0x38), 0x224, 0x2040);
    }
}

s32 TBoss6Type2::is_target_valid() {
    if ((s32) this->m_418 == 0) {
        return 0;
    }
    if ((u16) *(u16 *)((s8 *)this + 0x55C) == 0xFFFF) {
        return 1;
    }
    if (is_split_screen() != 0) {
        return 0;
    }
    return (local_client_id - (s32) *(u16 *)((s8 *)this + 0x55C)) != 0 ? 1 : 0;
}

s32 TBoss6Type2::choose_random_motion() {
    struct Boss_802BC23C *arg0 = (struct Boss_802BC23C *)this;
    s32 m;
    f32 r;
    f32 a;
    f32 b;

    m = choose_turn_motion();
    r = (1.0f / 32768.0f) * (f32)rand();
    if (arg0->f418 == 0) {
        if (r < 0.2f) {
            return 0x11;
        }
        return m;
    }
    if (r < 0.6f) {
        m = 0x11;
    }
    r = (1.0f / 32768.0f) * (f32)rand();
    a = (f32)arg0->f4d0 / 100.0f;
    b = (f32)arg0->f4cc / 100.0f + a;
    if (r <= a) {
        m += 6;
    } else if (r <= b) {
        m += 3;
    }
    return m;
}

s32 TBoss6Type2::choose_turn_motion() {
    f32 temp_f3;
    f64 temp_f0;
    s32 var_r31;
    s32 var_r31_2;
    void *player;

    var_r31_2 = 0xF;
    player = get_player_by_client_id(this->m_466);
    if (this->m_478 & 1) {
        var_r31_2 = 0x10;
    }
    if (player == NULL) {
        return var_r31_2;
    }
    temp_f3 = *(f32 *)((s8 *)player + 0x38);
    temp_f0 = ((f64 (*)(f32, f32, f32))atan2_float)(temp_f3 - *(f32 *)((s8 *)this + 0x38), *(f32 *)((s8 *)player + 0x40) - *(f32 *)((s8 *)this + 0x40), temp_f3);
    var_r31 = 0xF;
    if (angle_diff_s16(this->rotation_y, (s32) (10430.38043493439 * temp_f0)) < 0) {
        var_r31 = 0x10;
    }
    return var_r31;
}

void TBoss6Type2::sub_802BC124() {
    this->m_4fc += -0.06666667f;
    if (this->m_4fc < 0.0f) {
        this->m_4fc = 0.0f;
    }
    this->m_500 = (f32) ((f32) this->hp / (f32) this->referenceHp);
}

void TBoss6Type2::init_segment_range() {
    Obj_802BC050 *o = (Obj_802BC050 *)this;
    Ent_802BC050 *e = (Ent_802BC050 *)this->param_block;
    s32 min;
    s32 max;
    max = e->v[0];
    min = max;
    if (min > e->v[1]) { min = e->v[1]; } else if (max < e->v[1]) { max = e->v[1]; }
    if (min > e->v[2]) { min = e->v[2]; } else if (max < e->v[2]) { max = e->v[2]; }
    if (min > e->v[3]) { min = e->v[3]; } else if (max < e->v[3]) { max = e->v[3]; }
    if (min > e->v[4]) { min = e->v[4]; } else if (max < e->v[4]) { max = e->v[4]; }
    o->min = min;
    this->m_454 = max;
    ((TLobby *)(&o->local))->copy_entry(this->param_block);
    this->param_block = (ActorParamBlock *)&o->local;
    update_segments();
}

void TBoss6Type2::update_segments() {
    s16 temp_r0;

    temp_r0 = this->m_454;
    this->m_434.m_2[4] = temp_r0;
    this->m_434.m_2[3] = temp_r0;
    this->m_434.m_2[2] = temp_r0;
    this->m_434.m_2[1] = temp_r0;
    this->m_434.m_2[0] = temp_r0;
    switch (*(s32 *)&this->m_42c) {
    case 1:
        this->m_434.m_2[0] = (s16) this->m_456;
        break;
    case 2:
        this->m_434.m_2[1] = (s16) this->m_456;
        break;
    case 3:
        this->m_434.m_2[2] = (s16) this->m_456;
        break;
    case 4:
        this->m_434.m_2[3] = (s16) this->m_456;
        break;
    case 5:
        this->m_434.m_2[4] = (s16) this->m_456;
        break;
    }
    this->m_2f2 = (s16) this->m_434.m_2[0];
    this->m_2f4 = (s16) this->m_434.m_2[2];
    this->m_2f6 = (s16) this->m_434.m_2[1];
    this->m_2f8 = (s16) this->m_434.m_2[4];
    this->m_2fa = (s16) this->m_434.m_2[3];
}

void TBoss6Type2::copy_vec_array() {
    u8 *arg0 = (u8 *)this;
    Vec *src;
    Vec *end;
    Vec *dst;
    src = (Vec *)(arg0 + 0x59C);
    dst = (Vec *)(arg0 + 0x680);
    end = (Vec *)((u8 *)src + 0xE4);
    for (; src < end; src++, dst++) {
        VecCopy((Vec *)dst, (const Vec *)src);
    }
}

void TBoss6Type2::advance_position() {
    VecCopy(&body_center, &position);
    body_center.y += 30.0f;
}

void TBoss6Type2::sub_802BBE20() {
    Vec v;
    s32 i;
    Vec *base;
    CollisionBody *e;
    if (this->bodies != NULL) {
        for (i = 0; i < 3; i++) {
            const Tbl_802BBE20 *t;
            e = &this->bodies[i];
            t = &lbl_8047130C[i];
            base = NULL;
            switch (t->kind) {
            case 0:
                base = this->m_59c;
                break;
            }
            if (base == NULL) {
                return;
            }
            VecCopy(&v, &base[t->idx]);
            subtract_vector(&v, &this->position);
            push_matrix();
            set_matrix_identity(0);
            rotate_matrix_y(0, -this->rotation_y);
            matrix_mult_vec(0, &v, e);
            pop_matrix();
            VecCopy(&e->center, &e->offset);
            vec3_add_to(&e->center, &this->position);
        }
    }
}

void TBoss6Type2::update_parts_flags() {
    clear_part_flags();
    if (this->m_474 & 1) {
        set_child_flags();
    }
    if (this->m_474 & 2) {
        set_owner_flag_bit0();
    }
}

void TBoss6Type2::clear_part_flags() {
    CollisionBody *p = this->bodies;
    if (p != NULL) {
        CollisionBody *end = p + 3;
        for (; p < end; p++) {
            p->flags &= ~1;
        }
    }
}

void TBoss6Type2::set_child_flags() {
    if (this->bodies != NULL) {
        this->bodies[0].flags |= 1;
        this->bodies[1].flags |= 1;
    }
}

void TBoss6Type2::set_owner_flag_bit0() {
    CollisionBody *bodies = this->bodies;
    if (bodies != NULL) {
        bodies[2].flags |= 1;
    }
}

void TBoss6Type2__sub_802BBC74(TBoss6Type2 *self) {
    s32 end_angle = 0xFFFF;
    f32 radius = 150.0f;
    s32 start_angle = 0;
    s32 sound = 0x40069E08;
    switch (self->m_374) {
    case 15:
    case 18:
    case 21:
        radius = 839.99994f;
        start_angle = (self->rotation_y - 0x1500) & 0xFFFF;
        sound = 0x40069E09;
        end_angle = start_angle + 0x8500;
        break;
    case 16:
    case 19:
    case 22:
        radius = 839.99994f;
        start_angle = (self->rotation_y - 0x7000) & 0xFFFF;
        sound = 0x40069E09;
        end_angle = start_angle + 0x8500;
        break;
    case 17:
    case 20:
    case 23:
        break;
    }
    TBoss6SwordWave::create((TObject *)self, &self->position, start_angle, end_angle, radius);
    play_sound_effect(sound, &self->position, 0, 1);
}

void TBoss6Type2::apply_rock_hits_to_players() {
    DirectAttackPayload a;
    f32 range;
    s32 r;
    s32 i;
    s32 mask;
    s32 j;
    Vec *rock;
    s32 hit;
    TObjChara *p;
    s32 v;
    range = 10.0f;
    for (i = 0; i < 6; i++) {
        rock = &this->m_59c[TBoss6Type2__player_hit_rock_indices[i]];
        TBoss6Rock::break_rocks_in_radius(rock, 10.0f);
        if (!(rock->y - this->position.y > range)) {
            hit = 0;
            if (xyz_distance(rock, &this->m_680[TBoss6Type2__player_hit_rock_indices[i]]) >= 1.0f) {
                hit = 1;
            }
            r = this->push_players_away(rock, 10.0f);
            if (hit != 0 && r != 0) {
                for (mask = 1, j = 0; j < 4; j++, mask <<= 1) {
                    if (mask & r) {
                        p = (TObjChara *)get_player_by_client_id(j);
                        if (TBoss6PlotFalz::is_active((TObjPlayer *)p) != 0) {
                            v = this->m_4b4;
                            if (this->m_418 != 0) {
                                v = (s32)((f32)v * this->m_4e8);
                            }
                            s32 rr = TBoss6PlotFalz::rand_vary_count(v, 0.1f);
                            a.kind = 0;
                            a.power = rr;
                            p->receive_direct_attack(this, a, 0, -1, -1);
                        }
                    }
                }
            }
        }
    }
}

s32 TBoss6Type2::push_players_away(void *target, f32 range) {
    Vec dir;
    Vec pos;
    Vec off;
    s32 mask;
    s32 i;
    s32 n;
    TObjPlayer *pl;
    f32 t;
    f32 dist;
    mask = 0;
    n = TLobby::get_game_mode();
    for (i = 0; i < n; i++) {
        pl = TObjPlayer::get_player_data(i);
        if (TBoss6PlotFalz::is_state_1f((TObjPlayer *)pl) == 0) {
            continue;
        }
        VecCopy(&dir, &pl->position);
        subtract_vector(&dir, (Vec *)target);
        dir.y = 0.0f;
        dist = vector_length(&dir);
        if (dist >= range) {
            continue;
        }
        if (dist <= 1e-05f) {
            dir.x = 1.0f;
        }
        normalize_vector(&dir);
        for (t = range; t > 5.0f; t -= 5.0f) {
            off.x = dir.x * t;
            off.y = 10.0f;
            off.z = dir.z * t;
            VecCopy(&pos, (Vec *)target);
            vec3_add_to(&pos, &off);
            if (project_actor_to_ground(this, &pos, 0) != 0) {
                TBoss6PlotFalz__sub_802AC724(pl, &pos);
                break;
            }
        }
        mask |= 1 << get_entity_id(pl);
    }
    return mask;
}

void TBoss6Type2__sub_802BB818(TBoss6Type2 *self, f32) {
    MagParams_802BB818 params;
    s16 x;
    u16 z;
    s32 i;
    params.owner = self;
    VecCopy(&params.origin, (const Vec *)&self->position);
    params.origin.y += 150.0f;
    params.rotation_y = self->rotation_y;
    TBoss4DarkFalz__sub_8004B4F0(&params, self->m_3f8->get_mag_mine_ptr());
    params.active = 1;
    VecCopy(&params.pos, &params.origin);
    params.flags = self->m_2e4;
    x = params.x;
    z = params.z;
    params.variant = self->m_42c;
    for (i = 0; i < 2; i++) {
        params.index = i;
        params.x = x + lbl_8047133C[i];
        params.z = z + lbl_8047133C[i];
        ((Mags_802BB818 *)self)->mags[i] = (TBoss6Type2 *)create_mag__11TBoss6Type2Fl(&params);
    }
    if (((Mags_802BB818 *)self)->mags[0] == 0 || ((Mags_802BB818 *)self)->mags[1] == 0) {
        return;
    }
    ((Mags_802BB818 *)self)->mags[0]->set_anim_frame((saddr)((Mags_802BB818 *)self)->mags[1]);
    ((Mags_802BB818 *)self)->mags[1]->set_anim_frame((saddr)((Mags_802BB818 *)self)->mags[0]);
}

void TBoss6Type2__sub_802BB7C0(T2_802BB7C0 *arg0) {
    if (arg0->f410 == 0 || arg0->f414 == 0) {
        return;
    }
    TBoss6Type2__sub_8032E708((void *)arg0->f410, 0);
    TBoss6Type2__sub_8032E708((void *)arg0->f414, 0);
}

void TBoss6Type2__sub_802BB768(T2_802BB768 *arg0) {
    if (arg0->f410 == 0 || arg0->f414 == 0) {
        return;
    }
    TBoss6Type2__sub_8032E708((void *)arg0->f410, 1);
    TBoss6Type2__sub_8032E708((void *)arg0->f414, 1);
}

#pragma push
#pragma optimization_level 2
s32 TBoss6Type2__sub_802BB694(TBoss6Type2 *self) {
    s32 count = TBoss6PlotFalz::sort_active_players();
    s32 id = 0xFFFF;
    s32 i;
    if (count < 1) {
        return id;
    }
    if ((s32)self->m_418 == 0) {
        for (i = 0; i < count; i++) {
            id = TBoss6PlotFalz__sub_802AAE48(i);
            if (TBoss6Type2::is_player_in_rock_area(id) == 0) {
                break;
            }
        }
        if (i == count) {
            id = 0xFFFF;
        }
    } else {
        for (i = count - 1; i >= 0; i--) {
            id = TBoss6PlotFalz__sub_802AAE48(i);
            if (TBoss6Type2::is_player_in_rock_area(id) == 0) {
                break;
            }
        }
        if (i < 0) {
            id = 0xFFFF;
        }
    }
    return id;
}
#pragma pop

void TBoss6Type2__sub_802BB5B4(TBoss6Type2 *self, u16 *first, u16 *second) {
    s32 count = TBoss6PlotFalz::sort_active_players();
    *first = 0xFFFF;
    *second = 0xFFFF;
    if (count < 1) {
        return;
    }
    if ((s32)self->m_418 == 0) {
        s32 id0 = TBoss6PlotFalz__sub_802AAE48(0);
        s32 id1 = TBoss6PlotFalz__sub_802AAE48(1);
        if (self->m_478 & 1) {
            *first = id0;
            *second = id1;
        } else {
            *first = id1;
            *second = id0;
        }
        if (TBoss6PlotFalz::get_phase() == 0) {
            s8 flags = *(s8 *)&self->m_478;
            if (flags & 2) {
                if (flags & 4) {
                    *first = 0xFFFF;
                } else {
                    *second = 0xFFFF;
                }
            }
        }
    } else {
        *first = *second = TBoss6PlotFalz__sub_802AAE48(count - 1);
    }
}

void TBoss6Type2::sub_802BB554() {
    switch (((T2_802BB554 *)this)->f374) {
    case 3:
    case 6: case 7: case 8: case 9: case 10: case 11:
    case 0x1B: case 0x1C: case 0x1D: case 0x1E: case 0x1F: case 0x20: case 0x21:
        this->update_target();
        break;
    default:
        TBoss6Type2__sub_802BB4DC(this);
        break;
    }
}

void TBoss6Type2::update_target() {
    TObjPlayer *player = (TObjPlayer *)get_player_by_client_id(this->m_466);
    if (player != NULL) {
        this->aim_toward_point(&player->position);
        return;
    }
    this->aim_toward_point(NULL);
}

void TBoss6Type2__sub_802BB4DC(TBoss6Type2 *self) { self->aim_toward_point(NULL); }

void TBoss6Type2::sub_802BB498() {
    switch (((T2_802BB498 *)this)->f374) {
    case 0xE:
    case 0x1C:
        TBoss6Type2::request_default_follow_camera();
        break;
    default:
        TBoss6Type2::init_range();
        break;
    }
}

void request_player_camera_offsets__11TBoss6Type2FPvff(TBoss6Type2 *self, f32 a, f32 b) {
    Vec pp;
    Vec me;
    Vec off;
    Vec d;
    Vec cam;
    s32 n;
    s32 i;
    TObjPlayer *p;
    s32 flag;
    f32 step;
    f32 t;
    f32 dy;
    f32 k;
    f32 dist;
    f32 sum;
    f32 adj;
    f32 lim;

    n = TLobby::get_game_mode();
    step = 0.125f * b;
    for (i = 0; i < n; i++) {
        lim = fabs_float(b);
        p = TObjPlayer::get_player_data(i);
        if (p == NULL) {
            continue;
        }
        t = 0.0f;
        while (fabs_float(t) <= lim) {
            flag = 0;
            VecCopy(&off, &lbl_80471344);
            VecCopy(&pp, &p->position);
            pp.y += off.y;
            VecCopy(&me, &self->position);
            me.y += a + t;
            VecCopy(&d, &me);
            subtract_vector(&d, &pp);
            dy = d.y;
            d.y = 0.0f;
            dist = off.z + vector_length(&d);
            if (dist <= 15.0f) {
                dist = 15.0f;
            }
            cam.x = 0.0f;
            cam.z = 55.42f;
            cam.y = 25.43f - dy * cam.z / dist;
            if (cam.y < 10.0f) {
                cam.y = 10.0f;
                if (dy > 1e-05f) {
                    k = 9.799999f * dist;
                    cam.z = k / dy;
                    if (cam.z < 47.92f) {
                        sum = 47.92f + dist;
                        cam.z = 47.92f;
                        dy = 47.92f * dy - k;
                        if (fabs_float(sum) > 1e-05f) {
                            adj = dy / sum;
                            if (adj > 2.5f) {
                                adj = 2.5f;
                                flag = 1;
                            }
                            off.y += adj;
                        }
                    }
                }
            }
            request_follow_camera_offsets(&off, &cam, get_entity_id(p));
            if (flag == 0) {
                break;
            }
            t += step;
        }
    }
}

void TBoss6Type2::init_range() {
    ((void (*)(f32, f32))request_player_camera_offsets__11TBoss6Type2FPvff)(100.0f, -125.0f);
}

void TBoss6Type2::request_default_follow_camera() {
    request_follow_camera_offsets(&lbl_804DFAC4, &lbl_804DFAD0, 0xFFFFU);
}

void TBoss6Type2::drop_random_rocks(s32 arg0, s32 force) {
    s32 avail_tbl[32];
    s32 cnt;
    s32 mult;
    s32 avail;
    s32 i;
    s32 *buf;
    s32 step;
    s32 j;
    s32 k;

    mult = 1;
    cnt = game_difficulty_selection;
    if (TBoss6PlotFalz::get_phase() == 1) {
        mult = 4;
    }
    cnt = (4 - cnt) + mult;
    if (force != 0) {
        cnt *= 2;
    }
    if (cnt < 1) {
        return;
    }
    avail = 0;
    for (i = 0; i < 32; i++) {
        avail_tbl[i] = 0;
        if (TBoss6Rock::is_rock_state_2(i) == 0) {
            avail_tbl[i] = 1;
            avail++;
        }
    }
    if (avail < 1) {
        return;
    }
    if (cnt > avail) {
        cnt = avail;
    }
    buf = (s32 *)mem_alloc(cnt * 4);
    step = (s32)(31.0f * (3.0517578e-05f * (f32)rand()));
    j = 0;
    for (k = 0; k < cnt; k++) {
        j += step;
        if (j >= 32) {
            j = 0;
        }
        while (avail_tbl[j] == 0) {
            j++;
            if (j >= 32) {
                j = 0;
            }
        }
        buf[k] = j;
        avail_tbl[j] = 0;
    }
    TBoss6Type2__sub_80356E50((saddr)buf, cnt, force);
    mem_free(buf);
    ((s32 (*)(int, void *, int, int))play_sound_effect)(0x4006AB1D, ((void *)&boss6_arena_center), 0, 1);
}

void TBoss6Type2::spawn_rocks_around_players() {
    Vec p;
    Vec q;
    s32 n;
    s32 cnt;
    s32 i;
    u8 *pl;
    n = 0;
    cnt = TLobby::get_game_mode();
    for (i = 0; i < cnt; i++) {
        pl = (u8 *)TObjPlayer::get_player_data(i);
        if (TBoss6PlotFalz::is_active((TObjPlayer *)pl) != 0) {
            f32 r = 40.0f * (3.0517578e-05f * (f32)rand()) + 10.0f;
            s32 ang = (s32)(65535.0f * (3.0517578e-05f * (f32)rand()));
            VecCopy((Vec *)&p, (const Vec *)(pl + 0x38));
            p.x += r * sin_table_lookup(ang);
            p.y = 0.0f;
            p.z += r * cos_table_lookup(ang);
            TBoss6RockChase::spawn(this, &p);
            n++;
        }
    }
    while (n < 10) {
        f32 dx = 283.68796f * (2.0f * (3.0517578e-05f * (f32)rand()) - 1.0f);
        f32 dz = 283.68796f * (2.0f * (3.0517578e-05f * (f32)rand()) - 1.0f);
        VecCopy((Vec *)&q, &boss6_arena_center);
        q.x += dx;
        q.z += dz;
        TBoss6RockChase::spawn(this, &q);
        n++;
    }
    play_sound_effect(0x4006AB1D, (void *)&boss6_arena_center, 0, 1);
}

void TBoss6Type2__sub_802BAD04(saddr arg0) {
    u8 *temp_r3;
    u8 *temp_r3_2;
    TBoss6Type2::create_dpb(arg0, arg0 + 0x38, 150.0f);
    temp_r3 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x410));
    if ((temp_r3 != NULL) && (((TBoss6Mag *)temp_r3)->is_phase_active() != 0)) {
        TBoss6Type2::create_dpb(arg0, (saddr) (*(u8 **)((s8 *)arg0 + 0x410) + 0x38), 100.0f);
    }
    temp_r3_2 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x414));
    if ((temp_r3_2 != NULL) && (((TBoss6Mag *)temp_r3_2)->is_phase_active() != 0)) {
        TBoss6Type2::create_dpb(arg0, (saddr) (*(u8 **)((s8 *)arg0 + 0x414) + 0x38), 100.0f);
    }
}

s32 snap_to_ground__11TBoss6Type2FPv(TBoss6Type2 *self) {
    Vec p;
    f32 t;
    VecCopy(&p, &self->position);
    p.y += 10.0f;
    if (project_actor_to_ground(self, &p, 0) != 0) {
        VecCopy(&self->position, &p);
        self->position.y = 0.0f;
        return 0;
    }
    VecCopy(&p, &self->position);
    p.x -= -10000.0f;
    p.y = 0.0f;
    t = 398.0f;
    {
        Vec d = p;
        normalize_vector(&d);
        for (; t > 0.0f; t += -2.0f) {
            p.x = t * d.x + -10000.0f;
            p.y = 10.0f + self->position.y;
            p.z = t * d.z;
            if (project_actor_to_ground(self, &p, 0) != 0) {
                break;
            }
        }
    }
    VecCopy(&self->position, &p);
    self->position.y = 0.0f;
    return 1;
}

s32 TBoss6Type2::turn_toward_target_position() {
    s32 var_r31;
    f32 temp_f1;
    s32 temp_r30;
    TypedVector_802BAA74 sp8;
    VecCopy((Vec *)(&sp8), (const Vec *)(&target_position));
    subtract_vector((Vec *)(&sp8), (Vec *)(&position));
    sp8.f.y = 0.0f;
    temp_f1 = vector_length((Vec *)(&sp8));
    if (temp_f1 < 10.0f) {
        return 0;
    }
    if (temp_f1 > 25.0f) {
        var_r31 = 0x1B4;
        if ((s32) m_418 != 0) {
            var_r31 = 0x369;
        }
        temp_r30 = (s32)rotation_y;
        rotation_y = approach_angle_limited((s32)((int) ((s32)rotation_y)), (s32)((s32) ((s32) (10430.38043493439 * atan2_float(sp8.f.x, sp8.f.z)))), var_r31);
        if (var_r31 == angle_difference_abs(temp_r30, (int) ((s32)rotation_y))) {
            if ((s32) m_508 == 0) {
                play_sound_effect(0x4006A602, &position, 0, 0);
                m_508 = 1;
            }
        } else {
            m_508 = 0;
        }
    }
    return 1;
}

void TBoss6Type2::trigger_screen_pos() {
    if (((s32) this->m_424 == 0) && (this->m_500 < 0.33333334f)) {
        this->m_424 = 1;
        ((s32 (*)(void))set_screen_pos__11TBoss6Type2FPv)();
    }
}

s32 TBoss6Type2__sub_802BA9E4(T2_802BA9E4 *arg0) {
    if (arg0->f470 >= 3) {
        return 1;
    }
    return TBoss6PlotFalz__sub_802AB684(arg0->f38) >= 350.0f;
}

s32 TBoss6Type2__sub_802BA944(Boss_802BA944 *o) {
    s32 i;
    if (((TBoss6Type2 *)o)->count_matching_values(0xE, 3) != 0) {
        return 0;
    }
    i = 0;
    do {
        if (((TBoss6Type2 *)o)->count_matching_values(boss6_type2_hit_check_value_table[i], 2) != 0) {
            return 0;
        }
        i++;
    } while (i < 4);
    return (s32)o->f4BC <= ((TBoss6Type2 *)o)->get_hit_count() ? 1 : 0;
}

s32 TBoss6Type2::is_phase_complete() {
    if ((s32) this->m_418 == 0) {
        return 0;
    }
    if (((s32 (*)(void))calc_field4f0_delta__11TBoss6Type2FPv)() >= (s32) *(s32 *)((s8 *)this + 0x4C4)) {
        return 1;
    }
    if ((TBoss6PlotFalz::get_phase() == 0) && ((s32) this->m_420 >= 8)) {
        return 1;
    }
    return 0;
}

s32 TBoss6Type2::is_ready_to_attack() {
    s32 temp;
    if ((s32) this->m_418 != 0) {
        return 0;
    }
    if (is_normal_difficulty() != 0) {
        return 0;
    }
    temp = calc_field4f0_delta__11TBoss6Type2FPv(this);
    return *(s32 *)((s8 *)this + 0x4C0) <= temp ? 1 : 0;
}

void TBoss6Type2__sub_802BA7BC(u8 *o) {
    f32 k = 20.0f;
    s32 i = 0;
    do {
        const Ent_802BA7BC *e = &boss6_type2_motion_param_table[i];
        f32 lo = e->lo;
        f32 v = *(f32 *)(o + e->idx * 0xC + 0x5A0);
        if (v < lo || v > k + lo) {
            ((TBoss6Type2 *)o)->destroy_part(e->arg);
        } else {
            ((TBoss6Type2 *)o)->spawn_particle_slot(e->arg);
        }
        i++;
    } while (i < 6);
}

void TBoss6Type2__sub_802BA7B0(void* p) { *(s32*)((char*)p + 0x520) = -1; }

void TBoss6Type2::update_lower_contact_delta() {
    TypedVector_802BA6DC sp20;
    TypedVector_802BA6DC sp14;
    TypedVector_802BA6DC sp8;
    s32 var_r31;
    lower_contact_delta.z = 0.0f;
    lower_contact_delta.y = 0.0f;
    lower_contact_delta.x = 0.0f;
    VecCopy((Vec *)(&sp14), (const Vec *)(&m_59c[8]));
    subtract_vector((Vec *)(&sp14), (Vec *)(&position));
    VecCopy((Vec *)(&sp8), (const Vec *)(&m_59c[3]));
    subtract_vector((Vec *)(&sp8), (Vec *)(&position));
    var_r31 = 0;
    VecCopy((Vec *)(&sp20), (const Vec *)(&sp14));
    if (sp14.f.y > sp8.f.y) {
        var_r31 = 1;
        VecCopy((Vec *)(&sp20), (const Vec *)(&sp8));
    }
    if ((s32) lower_contact_index == var_r31) {
        VecCopy((Vec *)(&lower_contact_delta), (const Vec *)(&previous_lower_contact));
        subtract_vector((Vec *)(&lower_contact_delta), (Vec *)(&sp20));
        lower_contact_delta.y = 0.0f;
    }
    lower_contact_index = var_r31;
    VecCopy((Vec *)(&previous_lower_contact), (const Vec *)(&sp20));
}

void TBoss6Type2::update_zako() { ((int (*)(void*, void*))vec3_add_to)((char*)this + 0x38, (char*)this + 0x524); ((int (*)(void*))snap_to_ground__11TBoss6Type2FPv)(this); }

void TBoss6Type2__sub_802BA598(TBoss6Type2 *self, s32 elapsed, s32 duration) {
    f32 t = 1.0f - (f32)elapsed / (f32)duration;
    f32 u;
    f32 k;
    if (t <= 0.1f) {
        u = 0.0f;
    } else if (t >= 0.7f) {
        u = 1.0f;
    } else {
        u = (t - 0.1f) / (0.7f - 0.1f);
    }
    k = TBoss6PlotFalz::cosine_ease(u);
    VecCopy((Vec *)&self->position, &boss6_arena_center);
    subtract_vector((Vec *)&self->position, (Vec *)&self->m_50c);
    self->position.x *= k;
    self->position.y *= k;
    self->position.z *= k;
    vec3_add_to(&self->position, &self->m_50c);
}

void TBoss6Type2::cache_fish_params() {
    reset_fish_fields();
    *(saddr *)((s8 *)this + 0x560) = (saddr)get_bml_texlist((BmlResource *)this->m_3fc, 0xB);
    *(saddr *)((s8 *)this + 0x564) = (saddr)get_bml_texlist((BmlResource *)this->m_3fc, 0xA);
    *(saddr *)((s8 *)this + 0x568) = (saddr)get_bml_model((BmlResource *)this->m_3fc, 0xB);
    *(saddr *)((s8 *)this + 0x56C) = (saddr)get_bml_model((BmlResource *)this->m_3fc, 0xA);
}

void TBoss6Type2::reset_counters() {
    if ((u16) *(u16 *)((s8 *)this + 0x55C) != 0xFFFF) {
        restore_target_player_state();
    }
    reset_fish_fields();
    *(s32 *)((s8 *)this + 0x560) = 0;
    *(s32 *)((s8 *)this + 0x564) = 0;
    *(s32 *)((s8 *)this + 0x568) = 0;
    *(s32 *)((s8 *)this + 0x56C) = 0;
}

void TBoss6Type2::update_possess_target() {
    Vec v;
    u8 *pl;
    s32 done;
    u16 id;
    id = *(u16 *)((s8 *)((u8 *)this) + 0x55C);
    if (id != 0xFFFF) {
        done = 0;
        pl = (u8 *)get_player_by_client_id(id);
        if (pl == NULL) {
            done = 1;
        } else if (TBoss6PlotFalz::is_active((TObjPlayer *)pl) == 0) {
            VecCopy((Vec *)&v, (const Vec *)(pl + 0x38));
            v.y += 10.0f;
            spawn_flow_soul__11TBoss6Type2Fiii((saddr)this, (saddr)&v, 0x1E);
            TBoss6EffHyoui::create(*reinterpret_cast<u16 *>((u8 *)this + 0x55C), 1, 0x1E);
            if (this->is_target_valid() == 0) {
                play_sound_effect(0x40069E13, ((u8 *)this) + 0x38, 0, 1);
            }
            spawn_particle_effect((const Vec *)(pl + 0x38), 0x36);
            done = 1;
        }
        if (done != 0) {
            restore_target_player_state();
            this->m_464 = 0xFFFF;
            this->m_428 = this->pick_random_other_index();
            this->m_430 = this->choose_next_index();
        }
        switch (this->m_374) {
        case 0x1A:
            restore_target_player_state();
            this->m_464 = 0xFFFF;
            break;
        }
    }
}

u16 TBoss6Type2::is_falz_ready() { return TBoss6PlotFalz::pick_random_active_player(); }

s32 TBoss6Type2::check_target() {
    if (this->m_464 == 0xFFFF) {
        return 0;
    }
    if (*(u16 *)((s8 *)this + 0x55C) != 0xFFFF) {
        restore_target_player_state();
    }
    if (grab_player__11TBoss6Type2FPvUs((u8 *)this, this->m_464) == 0) {
        this->m_464 = 0xFFFFU;
        return 0;
    }
    return 1;
}

s32 grab_player__11TBoss6Type2FPvUs(u8 *arg0, u16 arg1) {
    u8 *player;
    if ((arg1 == 0xFFFF) || (*(u16 *)((s8 *)arg0 + 0x55C) != 0xFFFF)) {
        return 0;
    }
    player = (u8 *)(get_player_by_client_id(arg1));
    if (player == NULL) {
        return 0;
    }
    if (*(s32 *)((s8 *)player + 0x30) & 0x800) {
        return 0;
    }
    *(u16 *)((s8 *)arg0 + 0x55C) = arg1;
    *(u8 **)((s8 *)arg0 + 0x570) = (unsigned char *) (player + 0x85C);
    ((TBoss6Type2 *)(arg0 + 0x574))->copy_vec2(player + 0xCF4);
    ((TBoss6Type2 *)(arg0 + 0x57C))->copy_vec2(player + 0xA1C);
    ((TBoss6Type2 *)(arg0 + 0x584))->copy_vec2(player + 0xB88);
    *(s32 *)((s8 *)arg0 + 0x58C) = (s32) *(s32 *)((s8 *)player + 0x34);
    *(s32 *)((s8 *)arg0 + 0x590) = (s32) *(s32 *)((s8 *)player + 0x8B0);
    *(s32 *)((s8 *)arg0 + 0x594) = (s32) *(s32 *)((s8 *)player + 0x8AC);
    *(s32 *)((s8 *)arg0 + 0x598) = (s32) *(s32 *)((s8 *)player + 0x8B4);
    ((TBoss6Type2 *)(player + 0xCF4))->copy_vec2((void*)(*(u8 **)((s8 *)arg0 + 0x560)));
    ((TBoss6Type2 *)(player + 0xB88))->copy_vec2((void*)(*(u8 **)((s8 *)arg0 + 0x564)));
    *(s32 *)((s8 *)player + 0x34) = (s32) *(s32 *)((s8 *)arg0 + 0x568);
    *(s32 *)((s8 *)player + 0x8B0) = 0;
    *(s32 *)((s8 *)player + 0x8AC) = 0;
    *(s32 *)((s8 *)player + 0x8B4) = (s32) *(s32 *)((s8 *)arg0 + 0x56C);
    return 1;
}

void TBoss6Type2::copy_vec2(void* q) { *(u32*)((char*)this + 0x0) = *(u32*)((char*)q + 0x0); *(u32*)((char*)this + 0x4) = *(u32*)((char*)q + 0x4); }

void TBoss6Type2::restore_target_player_state() {
    u8 *player;
    u32 id = *(u16 *)((s8 *)((u8 *)this) + 0x55C);
    if (id != 0xFFFF) {
        player = (u8 *)get_player_by_client_id(id);
        if (player == NULL) {
            ((TBoss6Type2 *)this)->reset_fish_fields();
            return;
        }
        ((TBoss6Type2 *)(player + 0xCF4))->copy_vec2((void*)((void *) (((u8 *)this) + 0x574)));
        ((TBoss6Type2 *)(player + 0xB88))->copy_vec2((void*)((void *) (((u8 *)this) + 0x584)));
        *(s32 *)((s8 *)player + 0x34) = (s32) *(s32 *)((s8 *)((u8 *)this) + 0x58C);
        *(s32 *)((s8 *)player + 0x8B0) = (s32) *(s32 *)((s8 *)((u8 *)this) + 0x590);
        *(s32 *)((s8 *)player + 0x8AC) = (s32) *(s32 *)((s8 *)((u8 *)this) + 0x594);
        *(s32 *)((s8 *)player + 0x8B4) = (s32) *(s32 *)((s8 *)((u8 *)this) + 0x598);
        ((TBoss6Type2 *)this)->reset_fish_fields();
    }
}

void TBoss6Type2::reset_fish_fields() {
    ((Obj_802BA158 *)this)->f55c = 0xFFFF;
    ((Obj_802BA158 *)this)->f570 = 0;
    ((Obj_802BA158 *)this)->f58c = 0;
    ((Obj_802BA158 *)this)->f590 = 0;
    ((Obj_802BA158 *)this)->f594 = 0;
    ((Obj_802BA158 *)this)->f598 = 0;
}

#pragma push
#pragma opt_common_subs off
void TBoss6Type2::sub_802BA078() {
    Player_802BA078 *p;
    if (((Boss_802BA078 *)this)->f55C != 0xFFFF) {
        p = (Player_802BA078 *)get_player_by_client_id(((Boss_802BA078 *)this)->f55C);
        if (TBoss6PlotFalz::is_active((TObjPlayer *)p) != 0) {
            s32 r = TBoss6PlotFalz::rand_vary_count(((Boss_802BA078 *)this)->f4B8, 0.1f);
            TBoss6PlotFalz::damage_player_hp(((Boss_802BA078 *)this)->f55C, r);
            p->f30 |= 0x200;
            spawn_particle_effect_with_flags((const Vec *)&p->pos, 0x212, 0x40);
            {
                V3_802BA078 v = p->pos;
                v.y += 10.0f;
                spawn_particle_effect_with_flags((const Vec *)&v, 0x223, 0x40);
            }
            if (this->is_target_valid() == 0) {
                ((s32 (*)(s32, u32, s16, s32))play_sound_effect)(0x4000AD13, 0, 0, 0);
            }
        }
    }
}
#pragma pop

void TBoss6Type2::init_collected_entries() {
    s32 i;
    for (i = 0; i < 2; i++) {
        this->m_53c[i].m_0 = (s32 *)((u8 *)find_model_node(this->m_400[i].m_4, 0x28) + 0x18);
        this->m_53c[i].m_4 = *this->m_53c[i].m_0;
        this->m_53c[i].m_8 = 0;
    }
}

void TBoss6Type2::aim_toward_point(void *arg1_arg) {
    Vec *arg1 = (Vec *)arg1_arg;
    Vec v;
    s32 ang;
    s32 i;
    if (arg1 == NULL) {
        ang = 0;
    } else {
        VecCopy(&v, arg1);
        subtract_vector(&v, &this->position);
        ang = (s16)((s32)(10430.38043493439 * atan2_float(v.x, v.z)) - this->rotation_y);
    }
    if (ang < -0x2800 || ang > 0x2800) {
        ang = 0;
    }
    for (i = 0; i < 2; i++) {
        this->m_53c[i].m_8 = approach_angle_limited(this->m_53c[i].m_8, ang, 0x2AA);
    }
}

void TBoss6Type2::sum_offsets() {
    s32 i;
    for (i = 0; i < 2; i++) {
        *this->m_53c[i].m_0 = this->m_53c[i].m_4 + this->m_53c[i].m_8;
    }
}

void TBoss6Type2::restore_effect_values() {
    s32 i;
    for (i = 0; i < 2; i++) {
        *this->m_53c[i].m_0 = this->m_53c[i].m_4;
    }
}

void TBoss6Type2::set_fields_554() { *(s32*)((char*)this + 0x554) = 1; *(s32*)((char*)this + 0x558) = 1; }

#pragma push
#pragma opt_common_subs off
void TBoss6Type2::update_footstep_effects() {
    u8 *arg0 = (u8 *)this;
  Stack_802B9D90 stack;
  s32 temp_r4;
  s32 var_r30;
  u8 *temp_r29;
  s32 var_r28;
  static f32 foot_lift_height = 7.5f;
  static f32 footstep_height_threshold = 5.0f;
  stack.sp8 = (long) (((u8 *) arg0) + 0x614);
  var_r28 = 0;
  var_r30 = 0;
  stack.spC = (long) (((u8 *) arg0) + 0x5D8);
  do
  {
    temp_r4 = var_r30 + 0x554;
    if (((s32) (*((s32 *) (((s8 *) (((u8 *) arg0) + temp_r4)) + 0)))) != 0)
    {
      if ((*((f32 *) (((s8 *) (*((u8 **) (((s8 *) (((u8 *)&stack.sp8) + var_r30)) + 0)))) + 4))) > foot_lift_height)
      {
        *((s32 *) (((s8 *) (((u8 *) arg0) + temp_r4)) + 0)) = 0;
      }
    }
    else
    {
      temp_r29 = (u8 *) (*((u8 **) (((s8 *) (((u8 *)&stack.sp8) + var_r30)) + 0)));
      if ((*((f32 *) (((s8 *) temp_r29) + 4))) < footstep_height_threshold)
      {
        *((s32 *) (((s8 *) (((u8 *) arg0) + temp_r4)) + 0)) = 1;
        ((s32 (*)(s32, u32, s16, s32))play_sound_effect)(0x4006A300, (uaddr) temp_r29, 0, 0);
        spawn_particle_effect_with_flags((const Vec *)temp_r29, 0x220, 0x40);
        if (((s32)this->m_418) == 0)
        {
          spawn_particle_effect((const Vec *)temp_r29, 0x222);
        }
        else
        {
          spawn_particle_effect_with_flags((const Vec *)temp_r29, 0x229, 0x2000);
        }
        TBoss6PlotFalz::apply_radial_effect_to_players((void *)temp_r29, (s16)0xC0, (s16)0xF, 200.0f);
      }
    }
    var_r28 += 1;
    var_r30 += 4;
  }
  while (var_r28 < 2);
}
#pragma pop

void TBoss6Type2__sub_802B9D6C(Obj_802B9D6C *self) {
    s32 i;
    for (i = 0; i < 14; i++) self->arr[i] = 0;
}

void init_parts__11TBoss6Type2FPv(saddr self) {
    s32 var_r31;
    var_r31 = 0;
    do {
        ((TBoss6Type2 *)self)->destroy_part(var_r31);
        var_r31 += 1;
    } while (var_r31 < 0xE);
}

void TBoss6Type2::update_part_positions() {
    Boss_802B9C80 *o = (Boss_802B9C80 *)this;
    s32 i = 0;
    do {
        Vec v = o->pos;
        const Tb_802B9C80 *e = &((const Tb_802B9C80 *)TBoss6Type2__particle_attachment_table)[i];
        if (o->arr[i] != 0) {
            s32 idx = e->b;
            if (idx >= 0) {
                VecCopy((Vec *)((Vec *)(&v)), (const Vec *)((Vec *)((Vec *)((u8 *)o + idx * 0xC + 0x59C))));
            }
            ((TParticleCtrl *)(saddr)o->arr[i])->set_position(&v);
        }
        i++;
    } while (i < 14);
}

void TBoss6Type2::spawn_particle_slot(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    u8 *p = arg0 + arg1 * 4;
    if (*(u32 *)(p + 0x77C) == 0U) {
        V3_802B9C00 v = ((T1_802B9C00 *)arg0)->pos;
        *(u32 *)(p + 0x77C) = (uaddr)create_particle_emitter(&v, TBoss6Type2__particle_attachment_table[arg1].a);
        if (*(u32 *)(p + 0x77C) != 0U) {
            ((TParticleCtrl *)(*(uaddr *)(p + 0x77C)))->set_flags(0x40);
        }
    }
}

#pragma push
#pragma opt_common_subs off
void TBoss6Type2::destroy_part(s32 arg1) {
    saddr arg0 = (saddr)this;
    uaddr temp_r3;
    u8 *temp_r31;
    temp_r31 = (u8 *)(arg0 + (arg1 * 4));
    temp_r3 = *(u32 *)((s8 *)temp_r31 + 0x77C);
    if (temp_r3 != 0U) {
        TParticleCtrl::release((void *)temp_r3);
        *(u32 *)((s8 *)temp_r31 + 0x77C) = 0U;
    }
}
#pragma pop

void TBoss6Type2::spawn_hit_effects() {
    s32 found = 0;
    CollisionBody *e;
    s32 i;
    CollisionBody *t = this->bodies;
    if (t != NULL) {
        e = t;
        for (i = 0; i < 3; i++, e++) {
            if (e->flags & 0x04000000) {
                spawn_particle_effect(&this->m_59c[boss6_type2_hit_effect_node_table[i]], 0x223);
                found = 1;
            }
        }
    }
    if (found == 0) {
        spawn_particle_effect(&body_center, 0x223);
    }
}

s32 TBoss6Type2::is_player_in_rock_area(s32 id) {
    Vec a;
    Vec b;
    f32 r;
    TObjPlayer *p;
    s32 i;
    f32 k;
    p = (TObjPlayer *)get_player_by_client_id((u32)((u16)id));
    if (p == NULL) {
        return 0;
    }
    i = 0;
    k = 0.0f;
    do {
        if (TBoss6Rock__sub_80353A14(i, &a, &r) != 0) {
            VecCopy(&b, &p->position);
            subtract_vector(&b, &a);
            b.y = k;
            if (vector_length(&b) <= r) {
                return 1;
            }
        }
        i++;
    } while (i < 0x20);
    return 0;
}

void TBoss6Type2::unpack_path_entry(s32 *arg1) {
    u8 *arg0 = (u8 *)this;
    *arg1 = (s32) (s16) ((s8) *(u8 *)((s8 *)arg0 + 2) << 8);
    ((s32 (*)(int, int, void *, void *))grid_to_world_pos__11TBoss6Type2FccPv)((int) (*(u8 *)((s8 *)arg0 + 0)), (int) (*(u8 *)((s8 *)arg0 + 1)), (void *) ((u8 *) arg1 + 4), arg0);
}

void TBoss6Type2::call_9A24_plus_1(s32 *arg1) {
    u8 *arg0 = (u8 *)this;
    ((TBoss6Type2 *)(arg0 + 1))->unpack_path_entry(arg1);
}

void grid_to_world_pos__11TBoss6Type2FccPv(s8 arg0, s8 arg1, f32 *arg2) {
    arg2[0] = (f32)((7.874016f * (f32)arg0) + -10500.0f);
    arg2[1] = 0.0f;
    arg2[2] = (f32)((7.874016f * (f32)arg1) + -500.0f);
}

void world_to_grid_pos__11TBoss6Type2FPvPvPv(f32 *arg0, s8 *arg1, s8 *arg2) {
    f32 fa = 0.5f + ((arg0[0] - -10500.0f) / 7.874016f);
    f32 fb = 0.5f + ((arg0[2] - -500.0f) / 7.874016f);
    *arg1 = (s8)fa;
    *arg2 = (s8)fb;
}

s32 TBoss6Type2::get_phase() { return m_378[1]; }

void TBoss6Type2::render() { render_body_effects(); draw(); }

void TBoss6Type2::render_body_effects() {
    s32 var_r31;

    sum_offsets();
    TObjPlayer::toggle_particle_effect();
    push_matrix();
    post_translate_matrix((const f32 *)&this->position);
    rotate_matrix_y(NULL, this->rotation_y);
    var_r31 = 0;
    if ((0.0f == this->state_progress) || (1.0f == this->state_progress)) {
        var_r31 = 1;
    }
    if (var_r31 != 0) {
        TBoss6PlotFalz__sub_802AC008(this->m_4fc, this->m_500);
    }
    this->draw_body_models();
    if (var_r31 != 0) {
        TBoss6PlotFalz::update_camera_target();
    }
    pop_matrix();
    TParticleCtrl::end_effect_render();
    this->restore_effect_values();
}

void TBoss6Type2::draw() {
    if (this->m_55c != 65535) {
        push_matrix();
        post_translate_matrix((const f32 *)&this->m_59c[11]);
        rotate_matrix_y(NULL, this->rotation_y);
        boss6type2_draw_models((saddr)this->m_574, (saddr)this->m_57c, (saddr)this->m_584, this->m_58c, this->m_590, this->m_594, this->m_598, this->m_570, 1.0f);
        pop_matrix();
    }
}
}
