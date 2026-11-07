#include "types.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/system/PadRumble.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjChara.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/boss/darkfalz/TBoss4Type1.h"
#include "pso/unk/text_8004AA04.h"
#include "pso/unk/TLobby.h"
#include "pso/object/TObjControl.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/vector.h"
#include "pso/object/ambient/TObjFish_800E2FFC.h"
#include "pso/system/SoundEffect.h"
#include "pso/math/AngleLookup.h"
#include "pso/unk/text_80087278.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/effect/particle/TParticleCtrl_800874F4.h"
extern "C" void has_flag_0x800__9TObjCharaFv();
extern "C" void test_flag30_512__9TObjCharaFv();
extern "C" void test_flag_1000__9TObjCharaFv();
extern "C" void test_flag_256__9TObjCharaFv();

#include <stddef.h>
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/object/ambient/TObjFish.h"

#include "pso/boss/darkfalz/TObjDFTenchuFuru.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/boss/darkfalz/TBoss4Uro.h"
#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include "pso/enemy/lappy/TObjEneLappy.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/technique/TTecRaFoie.h"
extern "C" TObjEnemy *__ct__9TObjEnemyFP7TObject(void *, void *);

extern "C" {

s32 get_nth_view_player_id__11TCameraCtrlFl(s32);
void request_follow_camera_offsets(void *, void *, s32);
void matrix_mult_vec(int, void *, void *);
f32 vector_length(void *);
void translate_matrix_vec3(int, void *);
void set_matrix_identity(int);
int rotate_matrix_y(void *, void *);
int push_matrix(void);
extern const f32 lbl_805D8B20;
extern const f32 lbl_805D8B24;
extern const f32 lbl_805D8B28;
extern const f32 lbl_805D8B2C;
extern const f32 lbl_805D8B30;
extern const f32 lbl_805D8B34;
extern const f32 lbl_805D8B38;
extern const f32 lbl_805D8B3C;
extern const f32 lbl_805D8B40;
struct RecoveredGlobal_80052C58_lbl_80486218 {
    s32 value;
    u8 remaining[0x8];
};

typedef struct Vec_80052CDC {
    f32 x, y, z;
} Vec_80052CDC;

typedef struct Params_80052CDC {
    s32 owner;
    s16 a[3];
    s16 b;
    s16 c;
    u8 pad[0x14 - 0xE];
    Vec_80052CDC pos;
    u8 pad20[0x48 - 0x20];
} Params_80052CDC;

typedef struct Spot_80052CDC {
    Vec_80052CDC pos;
    u8 padc[0x18 - 0xC];
} Spot_80052CDC;

typedef struct Obj_80052CDC {
    u8 pad0[0x38C];
    s32 owner;
    u8 pad390[0x398 - 0x390];
    s32 timer;
    u8 pad39c[0x3A8 - 0x39C];
    s32 idx;
    u8 pad3ac[0x3C4 - 0x3AC];
    s32 max;
    s32 count;
    u8 pad3cc[0x3D0 - 0x3CC];
    s32 f3d0;
    u8 pad3d4[0x444 - 0x3D4];
    Spot_80052CDC spots[1];
} Obj_80052CDC;

struct Ent_8005294C { u8 b[0xC]; };

struct Obj_8005294C { u8 pad[0x484]; Ent_8005294C ents[1]; };

typedef struct { char pad[0x444]; struct { char b[0x18]; } arr[1]; } Foo;

typedef char RecoveredGlobal_80052C58_lbl_80486218_size[sizeof(RecoveredGlobal_80052C58_lbl_80486218) == 0xC ? 1 : -1];

typedef struct Vec_80053440 {
    f32 x, y, z;
} Vec_80053440;

typedef struct Obj_80053440 {
    u8 pad0[0x38];
    Vec_80053440 pos;
    u8 pad44[0x374 - 0x44];
    s32 state;
    u8 f378[0x3F8 - 0x378];
    void *a[4];
    void *b[4];
} Obj_80053440;

struct Boss_800535A8 {
    u8 pad0[0x32C];
    s16 hp;
    u8 pad32e[0x3A8 - 0x32E];
    s32 x3a8;
    u8 pad3ac[0x3D8 - 0x3AC];
    s32 x3d8;
};

struct Vec_80053914 { f32 x, y, z; };

struct O_80053914 {
    u8 pad0[0x38];
    Vec_80053914 pos;
};

struct Obj_80053CEC { u8 pad[0x38C]; void *target; u8 pad390[0x10]; s32 f3a0; u8 pad3a4[4]; s32 f3a8; u8 pad3ac[4]; s32 f3b0; s32 f3b4; };

struct S_80053B48 { u8 pad0[0x3a0]; s32 f3a0; };

struct Obj_80053AD4 { u8 pad0[0x3B0]; s32 i3B0; s32 i3B4; f32 f3B8; f32 f3BC; f32 f3C0; };

typedef struct Vec_80053D4C {
    f32 x, y, z;
} Vec_80053D4C;

typedef struct Spot_80053D4C {
    Vec_80053D4C pos;
    u8 padc[0x18 - 0xC];
} Spot_80053D4C;

typedef struct Part_80053D4C {
    Vec_80053D4C pos;
    u8 padc[0x1C - 0xC];
    Vec_80053D4C local;
    u8 pad28[0x2C - 0x28];
} Part_80053D4C;

typedef struct Obj_80053D4C {
    u8 pad0[0x38];
    Vec_80053D4C pos;
    u8 pad44[0x60 - 0x44];
    s32 angle;
    u8 pad64[0x394 - 0x64];
    Part_80053D4C *parts;
    u8 pad398[0x438 - 0x398];
    Spot_80053D4C spots[3];
} Obj_80053D4C;

struct Vec_80053E40 { f32 x, y, z; };

struct XZ_80053E40 { f32 x, z; };

struct Obj_80053E40 {
    u8 pad0[0x38];
    Vec_80053E40 pos;
    u8 pad44[0x60 - 0x44];
    void *x60;
    u8 pad64[0x3D0 - 0x64];
    s32 count;
};

struct RecoveredGlobal_80054530_lbl_80485EC8 {
    s32 value;
    u8 remaining[0x1DC];
};

struct V_80054224 { f32 x, y, z; };

struct S_80054224 { u8 pad0[0x38]; V_80054224 pos; u8 pad44[0x39c - 0x44]; f32 f39c; };

struct Boss_800542B0 {
    u8 pad0[0x374];
    s32 state;
    u8 pad378[0x3D0 - 0x378];
    s32 f3d0;
    u8 pad3d4[0x3F8 - 0x3D4];
    void *items[13];
};

/* One state of the TBoss4Type2 state machine (same shape as the TBoss4Zanzo.cpp table). */
struct Entry_800542B0 {
    u8 *f0;
    s32 f4;
    void (TBoss4Type2::*enter)();
    void (TBoss4Type2::*update_idle)();
    void (TBoss4Type2::*update)();
};

struct RecoveredGlobal_8005455C_lbl_80485EC8 {
    s32 value;
    u8 remaining[0x1DC];
};

typedef char RecoveredGlobal_80054530_lbl_80485EC8_size[sizeof(RecoveredGlobal_80054530_lbl_80485EC8) == 0x1E0 ? 1 : -1];

typedef char RecoveredGlobal_8005455C_lbl_80485EC8_size[sizeof(RecoveredGlobal_8005455C_lbl_80485EC8) == 0x1E0 ? 1 : -1];

struct RecoveredGlobal_80054F6C_lbl_804FF2A0 {
    s32 value;
    u8 remaining[0x2FC];
};

typedef char RecoveredGlobal_80054F6C_lbl_804FF2A0_size[sizeof(RecoveredGlobal_80054F6C_lbl_804FF2A0) == 0x300 ? 1 : -1];

struct Vec_80052EF8 { f32 x, y, z; };

struct O_80052EF8 {
    u8 pad0[0x38];
    u8 f38[0x398 - 0x38];
    s32 f398;
    f32 f39c;
    s32 f3a0;
    s32 f3a4;
    s32 f3a8;
    s32 f3ac;
    u8 pad3b0[0x3CC - 0x3B0];
    s32 f3cc;
};

typedef struct Vec_800530C0 {
    f32 x, y, z;
} Vec_800530C0;

typedef struct Obj_800530C0 {
    u8 pad0[0x398];
    s32 timer;
    f32 f39c;
} Obj_800530C0;

struct Stack_80053670 {
    f32 sp8;
    u8 pad_C[0x4];
    f32 sp10;
};

f32 random_ratio__9TObjCharaFv(void *);
void VecCopy__FP3VecPC3Vec(void *, void *);
int get_player_data__10TObjPlayerFi(int a0);
u16 get_entity_id(void *);
f32 atan2_float(f32 y, f32 x);
s32 get_bml_motion(s32, s32);
s32 TObjFish__sub_8001EDB0(s32, s32);
s32 get_bml_model(s32, s32);
s32 TBoss4DarkFalz__sub_8004AF5C(s32, s16 *, s16 *);
void TBoss4DarkFalz__sub_8004B4F0(void *, void *);
void *create__16TObjDFBeamCursorFPvPv(void *arg0, void *arg1);
s32 TBoss4Type3__sub_8005254C(u16);
void TBoss4Type2__sub_80053504(TBoss4Type2 *arg0);
void TBoss4Type2__sub_800535A8(Boss_800535A8 *arg0);
void pick_target_position__13TRaderMapCoreFPvPv(O_80053914 *self, Vec_80053914 *out);
f32 calc_wave_offset__11TBoss4Type2Ff(f32 farg0);
void set_pos_from_scaled_offset__11TBoss4Type2FPvPvPv(S_80054224 *o, void *src, V_80054224 *in);
u8 * TBoss4Type2__sub_80054384(void *self, s32 i, s32 j);
void TBoss4Type2__sub_80054DA8(TBoss4Type2 *boss);
void create_all_tenchu_furu__11TBoss4Type2Fi(s32 arg0);
void TBoss4Type2__sub_80054FC0(u8 *center, f32 min_dist);
void TBoss4Type2__sub_80055300(void);
Vec_80053E40 * get_position_ptr__10TObjPlayerFv(void *);
void * create__9TBoss4UroFi(Params_80052CDC *);
int toggle_particle_effect__10TObjPlayerFv(void*);
s32 clear_render_callback__8TObjFishFv(s32);
void *__dt__9TObjEnemyFv(TObjEnemy *arg0, s16 arg1);
void free_collision_body_parts(void *);
s32 project_actor_to_ground(void *, void *, int);
s32 add_radar_scaled_marker(void *, s32, s16, s32, f32);
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);
void __dl__7TObjectFPv(void *);
s32 __nw__7TObjectFUl(s32);
void create__11TTecRaBartaFPvPvPvPv(void *source, void *origin, void *pos, void *level);
void TBoss6PlotFalz__sub_802AC008(f32 farg0, f32 farg1);
void vec3_add_to(Vec_80053440 *, Vec_80053440 *);
void subtract_vector(Vec_80053D4C *, Vec_80053D4C *);
void normalize_vector(void *);
int post_translate_matrix(void*);
s32 set_global_param__8TObjFishFl();
f32 xyz_distance(Vec_80053914 *, Vec_80053914 *);
void draw_model_motion(void *arg0, void *arg1, f32 farg0);

extern u8 TBoss4DarkFalz__data_804FF1E8[];
extern Vec_800530C0 lbl_80437604;
extern Vec_800530C0 boss4_type2_effect_offset_vec_b;
extern const f64 lbl_80437620[];
extern const f64 lbl_80437630;
RecoveredGlobal_80054F6C_lbl_804FF2A0 TBoss4Type2__tenchu_furu_array;
extern s32 registered_player_count;
extern const f32 lbl_805D8AF8;
extern const f32 lbl_805D8AFC;
extern const f32 lbl_805D8B00;
extern const f32 lbl_805D8B04;
extern f32 lbl_805D8B08;
extern const f32 lbl_805D8B0C;
extern const f32 lbl_805D8B10;
extern const f32 lbl_805D8B14;
extern const f32 lbl_805D8B18;
extern const f32 lbl_805D8B1C;
extern const f32 lbl_805D8B44;
extern const f32 lbl_805D8B48;
extern const f32 lbl_805D8B4C;
extern const f32 lbl_805D8B50;
extern const f32 lbl_805D8B54;
extern const f32 lbl_805D8B58;
extern const f32 lbl_805D8B5C;
extern const f32 lbl_805D8B60;
extern const f32 lbl_805D8B64;
extern const f32 lbl_805D8B68;
extern const f32 lbl_805D8B6C;
extern const f32 lbl_805D8B70;
extern const f32 lbl_805D8B74;
extern const f32 lbl_805D8B78;
extern const f32 lbl_805D8B7C;
extern const f32 lbl_805D8B80;struct Cam_800531C8 { u8 pad[0x178]; Vec_80053E40 pos; };
extern Vec_80053E40 lbl_804375EC;
extern Vec_80053E40 lbl_804375F8;
extern Cam_800531C8 *camera_ctrl_instance;

struct P2_80052E10 { s32 a, b; };
struct S_80052E10 {
    u8 pad0[0x374];
    s32 f374;
    u8 pad378[0x398 - 0x378];
    s32 f398;
    u8 pad39c[0x3a8 - 0x39c];
    s32 idx;
    u8 pad3ac[0x3c8 - 0x3ac];
    s32 f3c8;
    u8 pad3cc[4];
    s32 f3d0;
};
extern "C" u8 lbl_8043750C[];
extern "C" u8 lbl_80437514[];
extern "C" u8 lbl_80437520[];
extern "C" u8 lbl_8043752C[];
extern "C" u8 lbl_80437534[];
extern "C" u8 lbl_80437540[];
extern "C" u8 lbl_8043754C[];
extern "C" u8 lbl_80437558[];
extern "C" u8 lbl_80437560[];
extern "C" u8 lbl_80437568[];
extern "C" u8 lbl_80437570[];
void *lbl_80485AE0[10] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x41c80000,
    (void *)0x40000000, (void *)0x41c80000, (void *)0x3f000000, (void *)0x3f000000,
    (void *)0x3f000000, (void *)0x3f000000,
};
s32 lbl_80485B08[2] = { 0xFB, 0xFC };
Entry_800542B0 lbl_80485C48[11] = {
    { lbl_8043750C, 0, &TBoss4Type2::sub_800531BC, &TBoss4Type2::check_state_if_idle, &TBoss4Type2::sub_800530C0 },
    { lbl_80437514, 0, 0, &TBoss4Type2::update_flag800_state, 0 },
    { lbl_80437520, 0, &TBoss4Type2::sub_8005307C, &TBoss4Type2::update_state_transition, &TBoss4Type2::sub_80052EF8 },
    { lbl_8043752C, 1, &TBoss4Type2::sub_80052EEC, &TBoss4Type2::sub_80052EE8, &TBoss4Type2::tick_state_398_timer },
    { lbl_80437534, -1, 0, 0, 0 },
    { lbl_80437540, 2, &TBoss4Type2::start_motion_for_index, 0, &TBoss4Type2::update_spawn_uro },
    { lbl_8043754C, 2, &TBoss4Type2::start_motion_for_index, 0, &TBoss4Type2::tick_countdown_set_state7 },
    { lbl_80437558, 4, &TBoss4Type2::set_motion_for_state, &TBoss4Type2::update_state, &TBoss4Type2::update_attack_countdown },
    { lbl_80437560, 11, &TBoss4Type2::init_child_and_set_timer, &TBoss4Type2::update_scale_state, &TBoss4Type2::update_tech_charge },
    { lbl_80437568, 12, &TBoss4Type2::init_child_and_set_timer, &TBoss4Type2::update_scale_state, &TBoss4Type2::update_tech_charge },
    { lbl_80437570, 13, &TBoss4Type2::init_timer, &TBoss4Type2::sub_800528B8, &TBoss4Type2::sub_800525AC },
};
CollisionBody lbl_80485E2C[3] = {
    { { 135.0f, 25.0f, 0.0f }, 30.0f, 0.0f, 0, 0x801B, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 25.0f, 135.0f }, 30.0f, 0.0f, 0, 0x801B, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { -135.0f, 25.0f, 0.0f }, 30.0f, 0.0f, 0, 0x801B, { 0.0f, 0.0f, 0.0f }, 0.0f },
};
void *lbl_80485EB0[6] = {
    (void *)0x9, (void *)0x7, (void *)0x5, (void *)0x4,
    (void *)0x6, (void *)0x3,
};
void *boss4_type1_motion_states[120] = {
    (void *)0x0, (void *)0x0, (void *)0x50, (void *)0x4e,
    (void *)0x4d, (void *)0x4d, (void *)0x4d, (void *)0x4c,
    (void *)0x1, (void *)0x0, (void *)0x50, (void *)0x4e,
    (void *)0x15, (void *)0x15, (void *)0x15, (void *)0x14,
    (void *)0x2, (void *)0x3, (void *)0x50, (void *)0x4e,
    (void *)0x2a, (void *)0x4d, (void *)0x4d, (void *)0x14,
    (void *)0x0, (void *)0x4, (void *)0x50, (void *)0x4e,
    (void *)0x28, (void *)0x4d, (void *)0x4d, (void *)0x14,
    (void *)0x2, (void *)0x0, (void *)0x50, (void *)0x4e,
    (void *)0x2c, (void *)0x4d, (void *)0x4d, (void *)0x14,
    (void *)0x2, (void *)0x6, (void *)0x50, (void *)0x4e,
    (void *)0x4d, (void *)0x2a, (void *)0x4d, (void *)0x14,
    (void *)0x0, (void *)0x7, (void *)0x50, (void *)0x4e,
    (void *)0x4d, (void *)0x28, (void *)0x4d, (void *)0x14,
    (void *)0x2, (void *)0x0, (void *)0x50, (void *)0x4e,
    (void *)0x4d, (void *)0x2c, (void *)0x4d, (void *)0x14,
    (void *)0x2, (void *)0x9, (void *)0x50, (void *)0x4e,
    (void *)0x4d, (void *)0x4d, (void *)0x2a, (void *)0x14,
    (void *)0x0, (void *)0xa, (void *)0x50, (void *)0x4e,
    (void *)0x4d, (void *)0x4d, (void *)0x28, (void *)0x14,
    (void *)0x2, (void *)0x0, (void *)0x50, (void *)0x4e,
    (void *)0x4d, (void *)0x4d, (void *)0x2c, (void *)0x14,
    (void *)0x2, (void *)0x0, (void *)0x50, (void *)0x4e,
    (void *)0x4d, (void *)0x4d, (void *)0x4d, (void *)0x0,
    (void *)0x2, (void *)0x0, (void *)0x50, (void *)0x4e,
    (void *)0x4d, (void *)0x4d, (void *)0x4d, (void *)0x4,
    (void *)0x2, (void *)0xe, (void *)0x50, (void *)0x4e,
    (void *)0x4d, (void *)0x4d, (void *)0x4d, (void *)0x43,
    (void *)0x2, (void *)0x0, (void *)0x50, (void *)0x4e,
    (void *)0x4d, (void *)0x4d, (void *)0x4d, (void *)0x3d,
};
void *player_collider_radius_table[6] = {
    (void *)0x42960000, (void *)0x42700000, (void *)0x42700000, (void *)0x42700000,
    (void *)0x42200000, (void *)0x41f00000,
};
void *boss4_type1_xz_offset_table[12] = {
    (void *)0x0, (void *)0x0, (void *)0x42480000, (void *)0x0,
    (void *)0x0, (void *)0x42480000, (void *)0xc2480000, (void *)0x0,
    (void *)0x0, (void *)0xc2a00000, (void *)0x0, (void *)0x0,
};
void *lbl_804860F0[12] = {
    (void *)0x1a, (void *)0xc1700000, (void *)0x0, (void *)0x0,
    (void *)0x1a, (void *)0x0, (void *)0x40f00000, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_80486120[12] = {
    (void *)0xe, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x54, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
Vec lbl_80486150 = { 0.0f, 0.0f, -120.0f };
void *lbl_8048615C[14] = {
    (void *)0x0, (void *)0xc000, (void *)0x8000, (void *)0x4000,
    (void *)0x3e800000, (void *)0x3e800000, (void *)0x3f000000, (void *)0x8,
    (void *)0x9, (void *)0xa, (void *)0x3f000000, (void *)0x3f000000,
    (void *)0x8, (void *)0x9,
};
void *boss4_type1_vec_table[12] = {
    (void *)0x42480000, (void *)0x41200000, (void *)0x0, (void *)0xc2480000,
    (void *)0x41200000, (void *)0x0, (void *)0x0, (void *)0x41200000,
    (void *)0x42480000, (void *)0x0, (void *)0x41200000, (void *)0xc2480000,
};
void *boss4_type2_motion_vec_table[12] = {
    (void *)0x0, (void *)0x0, (void *)0xc32f0000, (void *)0x432f0000,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x432f0000, (void *)0xc32f0000, (void *)0x0, (void *)0x0,
};
void *lbl_804861F4[3] = {
    (void *)0x2, (void *)0x5, (void *)0x8,
};
void *lbl_80486200[6] = {
    (void *)0x43020000, (void *)0x0, (void *)0x0, (void *)0x43020000,
    (void *)0xc3020000, (void *)0x0,
};
void *boss4_type2_state_motion_index_table[3] = {
    (void *)0x4, (void *)0x7, (void *)0xa,
};
#define lbl_80485AE0 ((u8 *)lbl_80485AE0)
#define lbl_80485EB0 ((s32 *)lbl_80485EB0)
#define boss4_type1_motion_states (*(RecoveredGlobal_80054530_lbl_80485EC8 *)boss4_type1_motion_states)
#define player_collider_radius_table ((f32 *)player_collider_radius_table)
#define boss4_type1_xz_offset_table ((XZ_80053E40 *)boss4_type1_xz_offset_table)
#define lbl_8048615C ((u8 * *)lbl_8048615C)
#define boss4_type1_vec_table ((Vec_80053440 *)boss4_type1_vec_table)
#define boss4_type2_motion_vec_table ((Vec_80052EF8 *)boss4_type2_motion_vec_table)
#define boss4_type2_state_motion_index_table (*(RecoveredGlobal_80052C58_lbl_80486218 *)boss4_type2_state_motion_index_table)
}


extern "C" s32 init_collision_body_parts(void *, void *, int);
extern s32 boss4_type1_emitter_id_table[];
extern const ModelNodeSpec boss4_type1_model_node_table[];
extern const char *TBoss4Type1__name;
extern const f32 lbl_805D8B84;

extern "C" {


extern const f32 lbl_805D8B88;
}

extern "C" {
void TBoss4Type2__sub_80055300(void) { TBoss4Type2__sub_80054FC0(NULL, lbl_805D8B20); }

void create_all_tenchu_furu__11TBoss4Type2Fi(s32 arg0) {
    s32 *var_r31;
    s32 var_r30;
    var_r30 = 0;
    var_r31 = &TBoss4Type2__tenchu_furu_array.value;
    do {
        ((TObjDFTenchuFuru *)arg0)->create((void *)var_r31);
        var_r30 += 1;
        var_r31 = (s32 *)((u8 *)var_r31 + (0xC));
    } while (var_r30 < 0x40);
}

s32 is_split_screen(void);
extern const f32 lbl_805D8B8C;
extern const f32 lbl_805D8B90;
extern const f32 lbl_805D8B94;
extern const f32 lbl_805D8B98;
extern s32 local_client_id;
int rand(void);

extern "C" void TBoss4Type2__sub_80054FC0(u8 *arg0, f32 arg1) {
  u8 *out;
  s32 total;
  s32 cnt;
  s32 i;
  s32 k;
  s32 ang;
  s32 j;
  u8 *arr[4];
  s32 tries;
  f32 f24;
  f32 zero;
  Vec_80053914 w;
  Vec_80053914 v;
  out = (u8 *) (&TBoss4Type2__tenchu_furu_array);
  for (total = 0; total < 0x40; total++, out += 0xc)
  {
    VecCopy__FP3VecPC3Vec((Vec_80053914 *) out, lbl_80485AE0);
  }

  total = 0;
  out = (u8 *) (&TBoss4Type2__tenchu_furu_array);
  cnt = 0;
  if (is_split_screen())
  {
    cnt = TLobby::get_game_mode();
    if (cnt > 4)
    {
      cnt = 4;
    }
    for (i = 0; i < cnt; i++)
    {
      arr[i] = (u8 *) get_player_data__10TObjPlayerFi(i);
      if (arr[i] == 0)
      {
        break;
      }
    }

  }
  else
  {
    arr[0] = (u8 *) get_player_by_client_id(local_client_id);
    if (arr[0] != 0)
    {
      cnt = 1;
    }
  }
  f24 = lbl_805D8B8C;
  for (k = 0; k < cnt; k++)
  {
    total++;
    ((Vec_80053914 *) out)->x = *((f32 *) (arr[k] + 0x38));
    ((Vec_80053914 *) out)->z = *((f32 *) (arr[k] + 0x40));
    out += 0xc;
    for (ang = 0, j = 0; j < 8; j++, ang += 0x2000)
    {
      ((Vec_80053914 *) out)->x = (*((f32 *) (arr[k] + 0x38))) + (f24 * sin_table_lookup(ang));
      (*((Vec_80053914 *) out)).z = (*((f32 *) (arr[k] + 0x40))) + (f24 * cos_table_lookup(ang));
      out += 0xc;
      total++;
    }

  }

  tries = 0;
  while ((tries < 0x100) && (total < 0x40))
  {
    w.x = lbl_805D8B4C * ((lbl_805D8B90 * ((f32) rand())) - lbl_805D8B60);
    w.z = lbl_805D8B4C * ((lbl_805D8B90 * ((f32) rand())) - lbl_805D8B60);
    w.y = lbl_805D8B20;
    if (((w.x * w.x) + (w.z * w.z)) >= lbl_805D8B94)
    {
      goto next;
    }
    if (arg0 != 0)
    {
      VecCopy__FP3VecPC3Vec(&v, arg0);
      subtract_vector((Vec_80053D4C *) (&v), (Vec_80053D4C *) (&w));
      v.y = lbl_805D8B20;
      if (vector_length(&v) <= arg1)
      {
        goto next;
      }
    }
    u8 *p;
    s32 found;
    s32 m;
    found = 0;
    p = (u8 *) (&TBoss4Type2__tenchu_furu_array);
    for (m = 0; m < total; m++)
    {
      if (xyz_distance(&w, (Vec_80053914 *) p) <= lbl_805D8B98)
      {
        found = 1;
        break;
      }
      p += 0xc;
    }

    if (found == 0)
    {
      ((Vec_80053914 *) out)->x = w.x;
      ((Vec_80053914 *) out)->z = w.z;
      out += 0xc;
      total++;
    }
    next:
    tries++;
  }
}

void TBoss4Type2__sub_80054DA8(TBoss4Type2 *boss) {
    Vec_80053914 *spot;
    s32 i;
    s32 n;
    TObjPlayer *player;
    s32 hit;
    s32 count;
    Vec_80053914 *target;
    s32 j;
    f32 power;
    Vec_80053914 pos;

    power = (f32)((TBoss4Type2Params *)TLobby::dispatch_shared_handler_a(0x36))->power;
    spot = (Vec_80053914 *)&TBoss4Type2__tenchu_furu_array;
    for (i = 0; i < 0x40; i++) {
        TParticleCtrl *effect = (TParticleCtrl *)spawn_particle_effect(spot, lbl_80485B08[i & 1]);
        if (effect != NULL) {
            effect->set_flags(0x40);
        }
        spot++;
    }
    count = TLobby::get_game_mode();
    for (n = 0; n < count; n++) {
        player = TObjPlayer::get_player_data(n);
        hit = 0;
        if (player == NULL) {
            continue;
        }
        if (TBoss4Type3__sub_8005254C(get_entity_id(player)) == 0) {
            continue;
        }
        target = (Vec_80053914 *)&TBoss4Type2__tenchu_furu_array;
        VecCopy__FP3VecPC3Vec(&pos, player->get_position_ptr());
        pos.y = lbl_805D8B20;
        for (j = 0; j < 0x40; j++) {
            if (xyz_distance(&pos, target) < lbl_805D8B88) {
                hit = 1;
                break;
            }
            target++;
        }
        if (hit != 0) {
            DirectAttackPayload h;
            h.kind = 0;
            h.power = power;
            player->receive_direct_attack(boss, h, 0, -1, -1);
        }
    }
    play_sound_effect(0x4003A818, 0, 0, 0);
    start_pad_rumble_all(0xC0, 0xF);
}

s32 TBoss4Type1::create(s32 arg0) {
    return (s32)new TBoss4Type1(new TObjControl(tl_04), (s32 *)arg0);
}

}

TBoss4Type1::TBoss4Type1(TObject *parent, s32 *params) : TObjEnemy(parent) {
    s32 i;
    s32 j;

    m_name = TBoss4Type1__name;
    add_flags_2e4(8);
    owner = (TBoss4DarkFalz *)params[0];
    apply_set_data(params + 1);
    clear_lobby_object_state();
    unk_390 = TBoss4Uro::get_instance_count();
    texlist = 0;
    model = 0;
    VecCopy(&position, &lbl_80486150);
    rotation_y = 0;
    VecCopy(&prev_position, VecCopy(&home_position, VecCopy(&center, &position)));
    unk_394 = init_collision_body_parts(this, lbl_80485E2C, 3);
    VecCopy((Vec *)&m_2fc, &position);
    x_speed = y_speed = m_310 = lbl_805D8B20;
    target = 0;
    bind_enemy_combat_stats((u8 *)TLobby::register_boss(0x36), (u8 *)TLobby::dispatch_shared_handler_b(0x36), (u8 *)TLobby::register_object(0x36));
    referenceHp = hp;
    ((TBoss3Volopt *)this)->reset_photon_effect();
    set_param(0x2F);
    unk_3ec = lbl_805D8B84;
    for (i = 0; i < 3; i++) {
        fx[i] = (void *)TObjFish__sub_800E3124((u8 *)lbl_804860F0, (s32)unk_438[i]);
    }
    unk_480 = (void *)TObjFish__sub_800E3124((u8 *)lbl_80486120, (s32)unk_484);
    for (j = 0; j < 8; j++) {
        parts[j] = create_particle_emitter(&position, boss4_type1_emitter_id_table[j]);
    }
    for (; j < 13; j++) {
        parts[j] = 0;
    }
    init_model_node_tables(&model_nodes, boss4_type1_model_node_table, 7);
    unk_3a4 = 0;
    unk_3a0 = 0;
    unk_3ac = 1;
    unk_3a8 = 1;
    move_frames = ((TBoss4Type2Params *)TLobby::dispatch_shared_handler_a(0x36))->move_seconds;
    if (move_frames < 1 || move_frames > 60) {
        move_frames = 25;
    }
    move_frames = (f32)move_frames * lbl_805D8B78;
    unk_3c4 = ((TBoss4Type2Params *)TLobby::dispatch_shared_handler_a(0x39))->rafoie_level;
    if (unk_3c4 < 1) {
        unk_3c4 = 1;
    } else if (unk_3c4 > 6) {
        unk_3c4 = 6;
    }
    unk_3c8 = 0;
    unk_3d0 = 5;
    unk_3d4 = 0;
    unk_3d8 = hp / 2;
    unk_3dc = lbl_805D8B20;
    hp_ratio = lbl_805D8B18;
    ((TBoss4Type2 *)this)->set_state(0);
}


extern "C" {
TBoss4Type1::~TBoss4Type1() {
    s32 i;
    s32 j;
    fn_8004AA04(&model_nodes);
    for (i = 0; i < 13; i++) {
        if (parts[i] != 0) {
            TParticleCtrl::release(parts[i]);
            parts[i] = 0;
        }
    }
    for (j = 0; j < 3; j++) {
        TObjFish::init_state_1(fx[j]);
        fx[j] = 0;
    }
    TObjFish::init_state_1(unk_480);
    unk_480 = 0;
    free_collision_body_parts(this);
    unk_394 = 0;
}

void TBoss4Type1::vfunc_62() {
    actorFlags &= ~0x200;
    unk_3d4 = 1;
    unk_3dc = lbl_805D8B18;
    play_sound_effect(0x4003A822, &position, 0, 1);
}

void TBoss4Type1::vfunc_63() {
    if (state != 3 && state != 4) {
        ((TBoss4Type2 *)this)->set_state(3);
    }
}

}

#pragma push
#pragma opt_common_subs off
extern "C" {
void TBoss4Type1::run_task() {
    void (TBoss4Type2::*act)();
    if (owner->is_field378_zero() != 0) {
        act = lbl_80485C48[state].update_idle;
        if (act) {
            (((TBoss4Type2 *)this)->*act)();
        }
    }
    act = lbl_80485C48[state].update;
    if (act) {
        (((TBoss4Type2 *)this)->*act)();
    }
    update_boss4_phase_timer();
    snapshot_position();
    sub_80053D4C();
    ((TObjPlayer *)this)->update_collisions();
    submit_cursor_candidate(this, -1);
    sub_80053670();
    sub_80053440();
    {
        f32 x = unk_3dc;
        unk_3dc = x + lbl_805D8B80;
        if (unk_3dc < lbl_805D8B20) {
            unk_3dc = lbl_805D8B20;
        }
    }
    hp_ratio = (f32)hp / (f32)referenceHp;
}

}
#pragma pop

extern "C" {
void TBoss4Type1::render() {
    push_players_out_of_colliders();
    render_effects();
    update_follow_camera_offsets();
}

void TBoss4Type1::snapshot_position() {
    u8 *arg0 = (u8 *)this;
    VecCopy__FP3VecPC3Vec(arg0 + 0x2FC, arg0 + 0x38);
    *(f32 *)((s8 *)arg0 + 0x300) = (f32) (*(f32 *)((s8 *)arg0 + 0x300) + lbl_805D8B24);
}

void TBoss4Type1::render_effects() { toggle_particle_effect__10TObjPlayerFv(this); push_matrix(); post_translate_matrix((char*)this + 0x38); rotate_matrix_y((void*)0, *(void**)((char*)this + 0x60)); this->draw_parts(); pop_matrix(); TParticleCtrl::end_effect_render(); }

}

#pragma push
#pragma opt_common_subs off
extern "C" {
void TBoss4Type1::update_boss4_phase_timer() {
    f32 temp_f1;
    f32 temp_f1_2;
    *(s32 *)((s8 *)((u8 *)this) + 0x3F4) = 0;
    *(f32 *)((s8 *)((u8 *)this) + 0x3E8) = (f32) (*(f32 *)((s8 *)((u8 *)this) + 0x3E8) + *(f32 *)((s8 *)((u8 *)this) + 0x3EC));
    switch (*(s32 *)((s8 *)((u8 *)this) + 0x3F0)) {
    case 0:
        temp_f1 = *(f32 *)((s8 *)((u8 *)this) + 0x3E8);
        if (temp_f1 >= lbl_805D8B78) {
            *(f32 *)((s8 *)((u8 *)this) + 0x3E8) = (f32) (temp_f1 - lbl_805D8B78);
            *(s32 *)((s8 *)((u8 *)this) + 0x3F4) = 1;
        }
        break;
    case 1:
        if (*(f32 *)((s8 *)((u8 *)this) + 0x3E8) >= lbl_805D8B7C) {
            *(f32 *)((s8 *)((u8 *)this) + 0x3E8) = (f32) lbl_805D8B7C;
            *(s32 *)((s8 *)((u8 *)this) + 0x3F4) = 1;
        }
        break;
    case 2:
        if (*(f32 *)((s8 *)((u8 *)this) + 0x3E8) >= lbl_805D8B7C) {
            *(s32 *)((s8 *)((u8 *)this) + 0x3E4) = (s32) *(s32 *)((s8 *)((u8 *)&boss4_type1_motion_states.value + (*(s32 *)((s8 *)((u8 *)this) + 0x3E4) << 5)) + 4);
            *(s32 *)((s8 *)((u8 *)this) + 0x3F0) = (s32) *(s32 *)((s8 *)&boss4_type1_motion_states.value + (*(s32 *)((s8 *)((u8 *)this) + 0x3E4) << 5));
            *(f32 *)((s8 *)((u8 *)this) + 0x3E8) = (f32) lbl_805D8B20;
            *(s32 *)((s8 *)((u8 *)this) + 0x3F4) = 1;
        }
        break;
    }
    temp_f1_2 = *(f32 *)((s8 *)((u8 *)this) + 0x3E8);
    if ((temp_f1_2 < lbl_805D8B20) || (temp_f1_2 >= lbl_805D8B78)) {
        *(f32 *)((s8 *)((u8 *)this) + 0x3E8) = (f32) lbl_805D8B20;
    }
}

}
#pragma pop

extern "C" {
void TBoss4Type2::set_motion_index(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    if (arg1 != -1) {
        *(s32 *)((s8 *)arg0 + 0x3E4) = arg1;
        *(f32 *)((s8 *)arg0 + 0x3E8) = (f32) lbl_805D8B20;
        *(s32 *)((s8 *)arg0 + 0x3F0) = (s32) *(s32 *)((s8 *)((u8 *)&boss4_type1_motion_states.value + (arg1 << 5)) + 0);
    }
}

}

#pragma push
#pragma opt_propagation off
extern "C" {
void TBoss4Type1::draw_parts() {
    u8 *arg0 = (u8 *)this;
    s32 i;
    s32 off;
    s32 a;
    set_motion_packed_rotation();
    for (i = 0; i < 6; i++) {
        TObjFish__sub_8001EDB0(*(s32 *)((s8 *)arg0 + 0x390), lbl_80485EB0[i]);
        set_global_param__8TObjFishFl();
        switch (i) {
        case 2:
        case 3:
        case 4:
            TBoss6PlotFalz__sub_802AC008(*(f32 *)((s8 *)arg0 + 0x3DC), *(f32 *)((s8 *)arg0 + 0x3E0));
            off = (i - 2) * 4 + 0x42C;
            ((TObjFish *)(*(s32 *)(arg0 + off)))->set_draw_callback_list();
            a = get_bml_model(*(s32 *)((s8 *)arg0 + 0x390), lbl_80485EB0[i]);
            draw_model_motion((void *)a, (void *)(get_bml_motion(*(s32 *)((s8 *)arg0 + 0x390), *(s32 *)((s8 *)((u8 *)&boss4_type1_motion_states.value + (*(s32 *)((s8 *)arg0 + 0x3E4) << 5) + i * 4) + 8))), *(f32 *)((s8 *)arg0 + 0x3E8));
            clear_render_callback__8TObjFishFv(*(s32 *)(arg0 + off));
            TBoss6PlotFalz::update_camera_target();
            break;
        case 5:
            ((TObjFish *)(*(s32 *)((s8 *)arg0 + 0x480)))->set_draw_callback_list();
            draw_model_motion((void *)(get_bml_model(*(s32 *)((s8 *)arg0 + 0x390), lbl_80485EB0[i])), (void *)(get_bml_motion(*(s32 *)((s8 *)arg0 + 0x390), *(s32 *)((s8 *)((u8 *)&boss4_type1_motion_states.value + (*(s32 *)((s8 *)arg0 + 0x3E4) << 5) + i * 4) + 8))), *(f32 *)((s8 *)arg0 + 0x3E8));
            clear_render_callback__8TObjFishFv(*(s32 *)((s8 *)arg0 + 0x480));
            break;
        default:
            draw_model_motion((void *)(get_bml_model(*(s32 *)((s8 *)arg0 + 0x390), lbl_80485EB0[i])), (void *)(get_bml_motion(*(s32 *)((s8 *)arg0 + 0x390), *(s32 *)((s8 *)((u8 *)&boss4_type1_motion_states.value + (*(s32 *)((s8 *)arg0 + 0x3E4) << 5) + i * 4) + 8))), *(f32 *)((s8 *)arg0 + 0x3E8));
            break;
        }
    }
    clear_motion_packed_rotation();
    *(s32 *)((s8 *)arg0 + 0x3D4) = 0;
}

}
#pragma pop

extern "C" {
u8 *TBoss4Type2__sub_80054384(void *self, s32 i, s32 j) {
    return lbl_8048615C[i] + (j - 1) * 0x4000;
}

void TBoss4Type2::set_state(s32 arg1) {
    s32 i;
    void **p;

    ((Boss_800542B0 *)this)->state = arg1;
    for (i = 8; i < 13; i++) {
        p = &((Boss_800542B0 *)this)->items[i];
        if (*p != NULL) {
            TParticleCtrl::release(*p);
            *p = NULL;
        }
    }
    ((Boss_800542B0 *)this)->f3d0 = 5;
    ((TBoss4Type2 *)((Boss_800542B0 *)this))->set_motion_index(lbl_80485C48[((Boss_800542B0 *)this)->state].f4);
    void (TBoss4Type2::*f)() = lbl_80485C48[((Boss_800542B0 *)this)->state].enter;
    if (f) {
        (this->*f)();
    }
}

void set_pos_from_scaled_offset__11TBoss4Type2FPvPvPv(S_80054224 *o, void *src, V_80054224 *in) {
    V_80054224 v = *in;
    ((void (*)(void *))subtract_vector)(&v);
    v.x *= o->f39c;
    v.y *= o->f39c;
    v.z *= o->f39c;
    VecCopy__FP3VecPC3Vec(&o->pos, src);
    ((void (*)(void *, void *))vec3_add_to)(&o->pos, &v);
}

void TBoss4Type2::calc_scaled_field(s32 arg1, s32 arg2) {
    *(s32 *)((s8 *)this + 0x60) = (s32) (arg1 + (s32) (*(f32 *)((s8 *)this + 0x39C) * (f32) angle_diff_s16(arg1, arg2)));
}

f32 calc_wave_offset__11TBoss4Type2Ff(f32 farg0) {
    return lbl_805D8B60 * (lbl_805D8B18 - cos_table_lookup((s32) (lbl_805D8B74 * farg0)));
}

void TBoss4Type1::push_players_out_of_colliders() {
    Obj_80053E40 *o = (Obj_80053E40 *)this;
    XZ_80053E40 pts[7];
    Vec_80053E40 in;
    Vec_80053E40 out;
    s32 i;
    s32 p;
    u8 *pl;
    s32 j;

    push_matrix();
    set_matrix_identity(0);
    translate_matrix_vec3(0, &o->pos);
    rotate_matrix_y(0, o->x60);
    for (i = 0; i < o->count; i++) {
        in.x = boss4_type1_xz_offset_table[i].x;
        in.y = lbl_805D8B20;
        in.z = boss4_type1_xz_offset_table[i].z;
        matrix_mult_vec(0, &in, &out);
        pts[i].x = out.x;
        pts[i].z = out.z;
    }
    pop_matrix();
    for (p = 0; p < registered_player_count; p++) {
        pl = (u8 *)get_player_data__10TObjPlayerFi(p);
        if (pl != NULL && ((TBoss3Volopt *)pl)->get_field_3e0() == 0xE) {
            Vec_80053E40 pos = *get_position_ptr__10TObjPlayerFv(pl);
            Vec_80053E40 d;
            Vec_80053E40 q;
            for (j = 0; j < o->count; j++) {
                f32 r = player_collider_radius_table[j];
                f32 dist;
                VecCopy__FP3VecPC3Vec(&d, &pos);
                d.x = d.x - pts[j].x;
                d.y = lbl_805D8B20;
                d.z = d.z - pts[j].z;
                dist = vector_length(&d);
                if (!(dist > r)) {
                    if (lbl_805D8B20 == dist) {
                        VecCopy__FP3VecPC3Vec(&d, &pos);
                        d.y = lbl_805D8B20;
                        if (lbl_805D8B20 == vector_length(&d)) {
                            d.y = lbl_805D8B20;
                            d.x = lbl_805D8B18;
                            d.z = lbl_805D8B20;
                        }
                    }
                    normalize_vector(&d);
                    {
                        f32 s = (*(const f32 *)&lbl_805D8B08) + r;
                        d.x *= s;
                        d.z *= s;
                    }
                    pos.x = d.x + pts[j].x;
                    pos.z = d.z + pts[j].z;
                    VecCopy__FP3VecPC3Vec(&q, &pos);
                    for (;;) {
                        f32 m;
                        q.y += lbl_805D8B44;
                        if (project_actor_to_ground(o, &q, 0) != 0) {
                            break;
                        }
                        q.y = lbl_805D8B20;
                        m = vector_length(&q) - lbl_805D8B70;
                        normalize_vector(&q);
                        q.x *= m;
                        q.z *= m;
                    }
                    VecCopy__FP3VecPC3Vec(&pos, &q);
                }
            }
            if (((f32 (*)(void *, void *))xyz_distance)(get_position_ptr__10TObjPlayerFv(pl), &pos) > lbl_805D8B20) {
                ((TObjBase *)pl)->set_position_from(&pos);
                ((TBoss4DarkFalz *)pl)->save_position();
                ((TObjCollidable *)pl)->set_indexed_flags(0, 0x900000);
                *(u32 *)(pl + 0x30) &= ~0x20;
            }
        }
    }
}

}

extern "C" {
void TBoss4Type1::sub_80053D4C() {
    Obj_80053D4C *arg0 = (Obj_80053D4C *)this;
    Part_80053D4C *q;
    s32 i;
    f32 s;
    f32 c;
    q = arg0->parts;
    for (i = 0; i < 3; i++, q++) {
        Vec_80053D4C v = arg0->spots[i].pos;
        VecCopy__FP3VecPC3Vec(&q->local, &v);
        subtract_vector(&v, &arg0->pos);
        s = sin_table_lookup(-arg0->angle);
        c = cos_table_lookup(-arg0->angle);
        Vec_80053D4C t = v;
        v.x = c * t.x + s * t.z;
        v.z = -s * t.x + c * t.z;
        VecCopy__FP3VecPC3Vec(q, &v);
    }
}

}

extern "C" {
void TBoss4Type2::send_state_to_target(s32 arg1) {
    Obj_80053CEC *self = (Obj_80053CEC *)this;
    if (self->target != 0) {
        ((TBoss4DarkFalz *)(self->target))->send_code_25_4((arg1 & 0xF) | ((self->f3a0 & 3) << 4) | ((self->f3a0 & 3) << 6) | ((self->f3a8 & 3) << 8) | ((self->f3a8 & 3) << 10) | ((self->f3b0 & 0xF) << 12) | ((self->f3b4 & 0xF) << 16));
    }
}

void TBoss4Type2::send_darkfalz_code(s32 arg1, s32 arg2, s32 arg3) {
    u8 *arg0 = (u8 *)this;
    u8 *boss4_dark_falz;
    boss4_dark_falz = (u8 *)(*(u8 **)((s8 *)arg0 + 0x38C));
    if (boss4_dark_falz != NULL) {
        ((TBoss4DarkFalz *)boss4_dark_falz)->send_code_25_4(((((((((((((*(s32 *)((s8 *)arg0 + 0x3A0) * 0x10) & 0x30 & ~0xF) | (arg1 & 0xF)) & ~0xC0) | ((arg2 << 6) & 0xC0)) & ~0x300) | ((*(s32 *)((s8 *)arg0 + 0x3A8) << 8) & 0x300)) & ~0xC00) | ((arg3 << 0xA) & 0xC00)) & ~0xF000) | ((*(s32 *)((s8 *)arg0 + 0x3B0) << 0xC) & 0xF000)) & ~0xF0000) | ((*(s32 *)((s8 *)arg0 + 0x3B4) << 0x10) & 0xF0000));
    }
}

void TBoss4Type2::apply_packed_state(u32 arg1) {
    s32 n;
    *(s32 *)((s8 *)this + 0x3A4) = (s32) ((arg1 >> 4U) & 3);
    *(s32 *)((s8 *)this + 0x3A0) = (s32) ((arg1 >> 6U) & 3);
    *(s32 *)((s8 *)this + 0x3AC) = (s32) ((arg1 >> 8U) & 3);
    *(s32 *)((s8 *)this + 0x3A8) = (s32) ((arg1 >> 0xAU) & 3);
    if (*(s32 *)((s8 *)this + 0x3AC) > 2 || *(s32 *)((s8 *)this + 0x3A8) > 2) {
        return;
    }
    *(s32 *)((s8 *)this + 0x3B0) = (s32) ((arg1 >> 0xCU) & 0xF);
    *(s32 *)((s8 *)this + 0x3B4) = (s32) ((arg1 >> 0x10U) & 0xF);
    calc_target_position();
    n = arg1 & 0xF;
    if (n < 0 || n >= 0xB) {
        return;
    }
    set_state(n);
}

void TBoss4Type2::calc_scale_slot_indices(s32 *a, s32 *b) {
    f32 s;
    s32 v;
    v = ((S_80053B48 *)this)->f3a0 + (s32)(lbl_805D8B64 * random_ratio__9TObjCharaFv(((S_80053B48 *)this)));
    v += 1;
    if (v >= 4) {
        v -= 4;
    }
    *a = v;
    s = random_ratio__9TObjCharaFv(this);
    if (s <= lbl_805D8B68) {
        *b = 0;
    } else if (s <= lbl_805D8B6C) {
        *b = 1;
    } else {
        *b = 2;
    }
}

}

extern "C" {
void TBoss4Type2::calc_target_position() {
    Obj_80053AD4 *arg0 = (Obj_80053AD4 *)this;
    arg0->f3B8 = lbl_805D8B5C * (lbl_805D8B60 + (f32)arg0->i3B0) - lbl_805D8B58;
    arg0->f3BC = lbl_805D8B20;
    arg0->f3C0 = lbl_805D8B5C * (lbl_805D8B60 + (f32)arg0->i3B4) - lbl_805D8B58;
}

}

extern "C" {
void TRaderMapCore::set_map_position(void *arg1) {
    *(s32 *)((s8 *)this + 0x3B0) = (s32) ((lbl_805D8B58 + *(f32 *)((s8 *)arg1 + 0)) / lbl_805D8B5C);
    *(s32 *)((s8 *)this + 0x3B4) = (s32) ((lbl_805D8B58 + *(f32 *)((s8 *)arg1 + 8)) / lbl_805D8B5C);
}

}

#pragma push
#pragma opt_propagation off
extern "C" {
void pick_target_position__13TRaderMapCoreFPvPv(O_80053914 *self, Vec_80053914 *out) {
    s32 a1;
    O_80053914 *found;
    s32 i;
    O_80053914 *p;
    f32 best;
    f32 d;
    f32 s;
    s32 ang;
    s32 b;
    Vec_80053914 res;
    best = lbl_805D8B20;
    found = NULL;
    for (i = 0; i < registered_player_count; i++) {
        p = (O_80053914 *)get_player_data__10TObjPlayerFi(i);
        if (p == NULL) {
            continue;
        }
        if (TBoss4Type3__sub_8005254C(get_entity_id(p)) == 0) {
            continue;
        }
        {
            Vec_80053914 v = p->pos;
            v.y = lbl_805D8B20;
            d = xyz_distance(&v, &self->pos);
            if (d <= lbl_805D8B4C && d > best) {
                best = d;
                found = p;
                ((s32 (*)(Vec_80053914 *, Vec_80053914 *))VecCopy__FP3VecPC3Vec)(&res, &v);
            }
        }
    }
    if (found != NULL) {
        ((s32 (*)(Vec_80053914 *, Vec_80053914 *))VecCopy__FP3VecPC3Vec)(out, &res);
        return;
    }
    s = lbl_805D8B50 * random_ratio__9TObjCharaFv(self);
    a1 = (s32)(lbl_80437630 * atan2_float(-self->pos.x, -self->pos.z));
    b = (s32)(lbl_805D8B54 * random_ratio__9TObjCharaFv(self));
    ang = b + a1;
    ang -= 0x6000;
    out->x = s * sin_table_lookup(ang);
    out->y = lbl_805D8B20;
    out->z = s * cos_table_lookup(ang);
}

}
#pragma pop

extern "C" {
void TBoss4Type1::sub_80053670() {
    typedef char sp8_offset[(offsetof(Stack_80053670, sp8) == 0x0) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_80053670, sp10) == 0x8) ? 1 : -1];
    Stack_80053670 stack;

    f32 temp_f26;
    f32 temp_f26_2;
    f32 temp_f26_3;
    f32 temp_f28;
    f32 temp_f27;
    f32 temp_f29;
    f32 temp_f30;
    s32 temp_r30;
    s32 var_r29;
    s32 var_r28;
    u8 *arg0 = (u8 *)this;

    add_radar_scaled_marker(arg0 + 0x38, -0x5DB4, 1, 1, lbl_805D8B44);
    add_radar_scaled_marker(arg0 + 0x438, -0x5DB4, 1, 1, lbl_805D8B44);
    add_radar_scaled_marker(arg0 + 0x450, -0x5DB4, 1, 1, lbl_805D8B44);
    add_radar_scaled_marker(arg0 + 0x468, -0x5DB4, 1, 1, lbl_805D8B44);
    temp_f29 = sin_table_lookup(*(s32 *)((s8 *)arg0 + 0x60));
    temp_f30 = cos_table_lookup(*(s32 *)((s8 *)arg0 + 0x60));
    temp_f27 = lbl_805D8B48;
    var_r29 = 0;
    var_r28 = 0x25;
    do {
        ((s32 (*)(Vec_80053914 *, Vec_80053914 *))VecCopy__FP3VecPC3Vec)((Vec_80053914 *)&stack.sp8, (Vec_80053914 *)(arg0 + 0x38));
        stack.sp8 += (f32)(-var_r28) * temp_f30;
        stack.sp10 += (f32)var_r28 * temp_f29;
        add_radar_scaled_marker(&stack.sp8, -0x5DB4, 1, 1, lbl_805D8B44);
        ((s32 (*)(Vec_80053914 *, Vec_80053914 *))VecCopy__FP3VecPC3Vec)((Vec_80053914 *)&stack.sp8, (Vec_80053914 *)(arg0 + 0x38));
        stack.sp8 += (f32)var_r28 * temp_f29;
        stack.sp10 += (f32)var_r28 * temp_f30;
        add_radar_scaled_marker(&stack.sp8, -0x5DB4, 1, 1, lbl_805D8B44);
        ((s32 (*)(Vec_80053914 *, Vec_80053914 *))VecCopy__FP3VecPC3Vec)((Vec_80053914 *)&stack.sp8, (Vec_80053914 *)(arg0 + 0x38));
        stack.sp8 += (f32)var_r28 * temp_f30;
        stack.sp10 += (f32)(-var_r28) * temp_f29;
        add_radar_scaled_marker(&stack.sp8, -0x5DB4, 1, 1, lbl_805D8B44);
        if (var_r29 < 2) {
            ((s32 (*)(Vec_80053914 *, Vec_80053914 *))VecCopy__FP3VecPC3Vec)((Vec_80053914 *)&stack.sp8, (Vec_80053914 *)(arg0 + 0x38));
            stack.sp8 += (f32)(-var_r28) * temp_f29;
            stack.sp10 += (f32)(-var_r28) * temp_f30;
            add_radar_scaled_marker(&stack.sp8, -0x5DB4, 1, 1, lbl_805D8B44);
        }
        var_r29 += 1;
        var_r28 = (s32) ((f32) var_r28 + temp_f27);
    } while (var_r29 < 3);
}

void TBoss4Type2__sub_800535A8(Boss_800535A8 *arg0) {
    u8 pos[0xC];
    s32 r;
    u8 *tbl = lbl_80485AE0;
    if (arg0->x3a8 == 1) {
        if (arg0->hp <= arg0->x3d8) {
            r = TBoss4Type2::pick_weighted_random(3, (f32 *)(tbl + 0x68C), (s32 *)(tbl + 0x698));
        } else {
            r = TBoss4Type2::pick_weighted_random(2, (f32 *)(tbl + 0x6A4), (s32 *)(tbl + 0x6AC));
        }
        switch (r) {
        case 8:
        case 9:
            ((void (*)(void *, void *))pick_target_position__13TRaderMapCoreFPvPv)(arg0, pos);
            ((TRaderMapCore *)arg0)->set_map_position(pos);
            ((TBoss4Type2 *)arg0)->send_state_to_target(r);
            break;
        default:
            ((TBoss4Type2 *)arg0)->send_state_to_target(0xA);
            break;
        }
    } else {
        ((TBoss4Type2 *)arg0)->check_state_transition();
    }
}

void TBoss4Type2::check_state_transition() {
    if (((TBoss4DarkFalz *)*(s32 *)((s8 *)this + 0x38C))->sub_8004D990() <= (s32) (0xC - *(s32 *)((s8 *)this + 0x3C4))) {
        send_state_to_target(5);
        return;
    }
    send_state_to_target(6);
}

void TBoss4Type2__sub_80053504(TBoss4Type2 *boss4_type2) {
    s32 spC;
    s32 sp8;
    boss4_type2->calc_scale_slot_indices(&spC, &sp8);
    boss4_type2->send_darkfalz_code(2, spC, sp8);
}

void TBoss4Type1::sub_80053440() {
    Vec_80053440 v;
    s32 i;
    Obj_80053440 *arg0 = (Obj_80053440 *)this;
    if (arg0->state == 4) {
        return;
    }
    for (i = 0; i < 4; i++) {
        VecCopy__FP3VecPC3Vec(&v, &arg0->pos);
        vec3_add_to(&v, &boss4_type1_vec_table[i]);
        if (arg0->a[i] != NULL) {
            ((TParticleCtrl *)arg0->a[i])->set_position(&v);
        }
        if (arg0->b[i] != NULL) {
            ((TParticleCtrl *)arg0->b[i])->set_position(&v);
        }
    }
    ((TBoss4Type2 *)(arg0->f378))->scroll_strips();
    play_persistent_sound(0x4003BC0E, (s32)arg0, (u32)&arg0->pos, 0x40, 2);
}

}

extern "C" {
void TBoss4Type1::update_follow_camera_offsets() {
    Obj_80053E40 *o = (Obj_80053E40 *)this;
    XZ_80053E40 pts[7];
    Vec_80053E40 in;
    Vec_80053E40 out;
    f32 best;
    s32 i;
    s32 j;
    f32 t;
    s32 cn;
    best = lbl_805D8B20;
    push_matrix();
    set_matrix_identity(0);
    translate_matrix_vec3(0, &o->pos);
    rotate_matrix_y(0, o->x60);
    for (i = 0; i < o->count; i++) {
        in.x = boss4_type1_xz_offset_table[i].x;
        in.y = lbl_805D8B20;
        in.z = boss4_type1_xz_offset_table[i].z;
        matrix_mult_vec(0, &in, &out);
        pts[i].x = out.x;
        pts[i].z = out.z;
    }
    pop_matrix();
    {
        Vec_80053E40 cam = camera_ctrl_instance->pos;
        Vec_80053E40 d;
        for (j = 0; j < o->count; j++) {
            f32 r = lbl_805D8B24 + player_collider_radius_table[j];
            f32 len;
            d.x = cam.x - pts[j].x;
            d.y = lbl_805D8B20;
            d.z = cam.z - pts[j].z;
            len = vector_length(&d);
            if (!(len >= r)) {
                r -= len;
                if (best < r) {
                    best = r;
                }
            }
        }
    }
    {
        Vec_80053E40 a = lbl_804375EC;
        Vec_80053E40 b = lbl_804375F8;
        if (best > lbl_805D8B28) {
            best = lbl_805D8B28;
        }
        t = best / 40.42f;
        if (t > lbl_805D8B20) {
            a.y = lbl_805D8B30 * t + lbl_805D8B2C;
            a.z = lbl_805D8B34;
            b.y = lbl_805D8B38;
            b.z = lbl_805D8B40 * t + lbl_805D8B3C;
        }
        cn = get_nth_view_player_id__11TCameraCtrlFl(TCameraCtrl::get_camera_no());
        request_follow_camera_offsets(&a, &b, cn);
    }
}

}

extern "C" {
void TBoss4Type2::sub_800531BC() { *(s32 *)((char *)this + 0x398) = 75; }

void TBoss4Type2::check_state_if_idle() {
    if (*(int *)((char *)this + 0x398) == 0) {
        check_state_transition();
    }
}

void TBoss4Type2::sub_800530C0() {
    Obj_800530C0 *self = (Obj_800530C0 *)this;
    self->f39c = ((f32 (*)(void *, f32))calc_wave_offset__11TBoss4Type2Ff)(this, lbl_805D8B18 - (f32)self->timer / lbl_805D8B1C);
    Vec_800530C0 a = lbl_80437604;
    Vec_800530C0 b = boss4_type2_effect_offset_vec_b;
    ((void (*)(void *, Vec_800530C0 *, Vec_800530C0 *))set_pos_from_scaled_offset__11TBoss4Type2FPvPvPv)(this, &a, &b);
    if (--self->timer < 0) {
        set_state(1);
    }
}

void TBoss4Type2::update_flag800_state() {
    if (*(s32 *)((s8 *)this + 0x30) & 0x800) {
        send_state_to_target(4);
        return;
    }
    ((s32 (*)(void *))TBoss4Type2__sub_80053504)(this);
}

void TBoss4Type2::sub_8005307C() { *(u32 *)((char *)this + 0x398) = *(u32 *)((char *)this + 0x3cc); }

void TBoss4Type2::update_state_transition() {
    if (*(int *)((char *)this + 0x398) == 0) {
        check_state_transition();
    }
}

void TBoss4Type2::sub_80052EF8() {
    O_80052EF8 *self = (O_80052EF8 *)this;

    self->f39c = ((f32 (*)(void *, f32))calc_wave_offset__11TBoss4Type2Ff)(this, lbl_805D8B18 - (f32)self->f398 / (f32)self->f3cc);
    {
        Vec_80052EF8 a = boss4_type2_motion_vec_table[self->f3a4];
        Vec_80052EF8 b = boss4_type2_motion_vec_table[self->f3a0];
        ((s32 (*)(void *, Vec_80052EF8 *, Vec_80052EF8 *))set_pos_from_scaled_offset__11TBoss4Type2FPvPvPv)(this, &a, &b);
    }
    calc_scaled_field(((s32 (*)(void *, s32, s32))TBoss4Type2__sub_80054384)(this, self->f3a4, self->f3ac), ((s32 (*)(void *, s32, s32))TBoss4Type2__sub_80054384)(this, self->f3a0, self->f3a8));
    play_persistent_sound(0x4003A80D, (s32)this, (u32)self->f38, 0, 0);
    if (--self->f398 < 0) {
        self->f3a4 = self->f3a0;
        self->f3ac = self->f3a8;
        set_state(1);
    }
}

void TBoss4Type2::sub_80052EEC() { *(s32 *)((char *)this + 0x398) = 75; }

void TBoss4Type2::sub_80052EE8() {  }

void TBoss4Type2::tick_state_398_timer() {
    s32 temp_r0;
    temp_r0 = *(s32 *)((s8 *)this + 0x398) - 1;
    *(s32 *)((s8 *)this + 0x398) = temp_r0;
    if (temp_r0 < 0) {
        set_state(4);
    }
}

void TWindowSubSymbolChatPartsSet::copy_vec2(void* q) { *(f32*)((char*)this + 0x0) = *(f32*)((char*)q + 0x0); *(f32*)((char*)this + 0x4) = *(f32*)((char*)q + 0x4); }

void TBoss4Type2::start_motion_for_index() {
    S_80052E10 *self = (S_80052E10 *)this;
    set_motion_index(((s32 *)lbl_804861F4)[self->idx]);
    self->f3c8 = 0;
    ((TWindowSubSymbolChatPartsSet *)((u8 *)boss4_type1_xz_offset_table + 0x28))->copy_vec2(&((P2_80052E10 *)lbl_80486200)[self->idx]);
    self->f3d0 = 6;
    if (self->f374 == 5) {
        self->f398 = 0x12C;
    } else {
        self->f398 = 0x96;
    }
}

void TBoss4Type2::update_spawn_uro() {
    Params_80052CDC p;
    Spot_80052CDC *s;
    s32 t;
    Obj_80052CDC *self = (Obj_80052CDC *)this;
    s = &self->spots[self->idx];
    t = self->timer;
    if (t < 0x106 && (t & 0x1F) == 0 && self->count < self->max) {
        TBoss4DarkFalz__sub_8004B4F0(p.a, TBoss4DarkFalz__data_804FF1E8);
        if (TBoss4DarkFalz__sub_8004AF5C(self->owner, p.a, &p.b) != 0) {
            p.owner = self->owner;
            p.c = 1;
            VecCopy__FP3VecPC3Vec(&p.pos, s);
            if (create__9TBoss4UroFi(&p) != NULL) {
                spawn_particle_effect(s, 0x7D);
                play_sound_effect(0x4003A810, s, 0, 1);
                self->count++;
            }
        }
    }
    ((TBoss4DarkFalz *)self->owner)->sub_8004D990();
    if (self->timer == 0x106) {
        play_sound_effect(0x4003AD0F, s, 0, 1);
    }
    if (--self->timer < 0) {
        self->f3d0 = 5;
        set_state(7);
    }
}

void TBoss4Type2::tick_countdown_set_state7() {
    s32 temp_r0;
    temp_r0 = *(s32 *)((s8 *)this + 0x398) - 1;
    *(s32 *)((s8 *)this + 0x398) = temp_r0;
    if (temp_r0 < 0) {
        *(s32 *)((s8 *)this + 0x3D0) = 5;
        set_state(7);
    }
}

void TBoss4Type2::set_motion_for_state() {
    set_motion_index(*(s32 *)((s8 *)&boss4_type2_state_motion_index_table.value + (*(s32 *)((s8 *)this + 0x3A8) * 4)));
    *(s32 *)((s8 *)this + 0x398) = 0x3C;
}

void TBoss4Type2::update_state() {
    if ((s32) *(s32 *)((s8 *)this + 0x398) == 0) {
        if ((s32) *(s32 *)((s8 *)this + 0x3A8) == 1) {
            ((s32 (*)(void *))TBoss4Type2__sub_800535A8)(this);
            return;
        }
        ((s32 (*)(void *))TBoss4Type2__sub_80053504)(this);
    }
}

void TBoss4Type2::update_attack_countdown() {
    s32 temp_r0;
    if ((s32) *(s32 *)((s8 *)this + 0x398) == 0x2D) {
        play_sound_effect(0x4003AD11, (void *)(&((Foo *)this)->arr[*(s32 *)((s8 *)this + 0x3A8)]), 0, 1);
    }
    temp_r0 = *(s32 *)((s8 *)this + 0x398) - 1;
    *(s32 *)((s8 *)this + 0x398) = temp_r0;
    if (temp_r0 < 0) {
        set_state(1);
    }
}

void TBoss4Type2::init_child_and_set_timer() {
    create__16TObjDFBeamCursorFPvPv(this, ((char *)this + 952));
    *(u32 *)((s8 *)this + 0x398) = 75;
}

void TBoss4Type2::update_scale_state() {
    s32 sp8;
    s32 var_r31;

    if ((s32) *(s32 *)((s8 *)this + 0x398) == 0) {
        if (((f32 (*)(void))random_ratio__9TObjCharaFv)() < lbl_80437620[0]) {
            ((s32 (*)(void *))TBoss4Type2__sub_80053504)(this);
            return;
        }
        var_r31 = 8;
        if ((s32) *(s32 *)((s8 *)this + 0x374) == 8) {
            var_r31 = 9;
        }
        ((s32 (*)(void *, s32 *))pick_target_position__13TRaderMapCoreFPvPv)(this, &sp8);
        ((TRaderMapCore *)this)->set_map_position(&sp8);
        send_state_to_target(var_r31);
    }
}

void TBoss4Type2::update_tech_charge() {
    s32 idx;
    Ent_8005294C *ent;
    u32 r;
    idx = *(s32 *)((s8 *)this + 0x374) - 8;
    ent = &((Obj_8005294C *)this)->ents[idx];
    if (*(f32 *)((s8 *)this + 0x3E8) > lbl_805D8B10) {
        if (*(u32 *)((s8 *)this + 0x418) != 0) {
            TParticleCtrl::release((void *)*(u32 *)((s8 *)this + 0x418));
            *(u32 *)((s8 *)this + 0x418) = 0;
        }
    } else if (*(f32 *)((s8 *)this + 0x3E8) >= lbl_805D8B14 && *(u32 *)((s8 *)this + 0x418) == 0) {
        if ((*(u32 *)((s8 *)this + 0x418) = (u32)create_particle_emitter(ent, 0xF7)) != 0) {
            ((TParticleCtrl *)((void *)*(u32 *)((s8 *)this + 0x418)))->set_flags(0x40);
        }
    }
    if (*(f32 *)((s8 *)this + 0x3E8) >= lbl_805D8B14 && *(f32 *)((s8 *)this + 0x3E8) <= lbl_805D8B10) {
        play_persistent_sound(0x4003B512, (s32)this, (u32)this + 0x38, 0, 1);
    }
    if (*(s32 *)((s8 *)this + 0x398) == 0x26) {
        if ((r = ((u32 (*)(void *, s32))spawn_particle_effect)(ent, 0xFD)) != 0) {
            ((TParticleCtrl *)r)->set_flags(0x40);
        }
        play_sound_effect(0x4003A813, (u8 *)this + 0x38, 0, 1);
        if (idx == 0) {
            TBoss4Type2Params *params = (TBoss4Type2Params *)TLobby::dispatch_shared_handler_a(0x36);
            create__11TTecRaBartaFPvPvPvPv(this, (u8 *)this + 0x3B8, (u8 *)this + 0x3B8, (void *)params->rabarta_level);
        } else {
            TBoss4Type2Params *params = (TBoss4Type2Params *)TLobby::dispatch_shared_handler_a(0x36);
            ((TTecRaFoie *)this)->create((u8 *)this + 0x3B8, (u8 *)this + 0x3B8, (void *)params->rafoie_level);
        }
        start_pad_rumble_all(0xC0, 0xF);
    }
    if (--*(s32 *)((s8 *)this + 0x398) < 0) {
        set_state(1);
    }
}

void TBoss4Type2::init_timer() {
    TBoss4Type2__sub_80054FC0((u8 *)this + 0x38, lbl_805D8B0C);
    *(s32 *)((s8 *)this + 0x398) = 0x96;
}

void TBoss4Type2::sub_800528B8() {
    if ((s32) *(s32 *)((s8 *)this + 0x398) == 0) {
        if (((f32 (*)(void))random_ratio__9TObjCharaFv)() < lbl_805D8B08) {
            ((s32 (*)(void *))TBoss4Type2__sub_800535A8)(this);
            return;
        }
        ((s32 (*)(void *))TBoss4Type2__sub_80053504)(this);
    }
}

}

extern "C" {
void TBoss4Type2::sub_800525AC() {
    f32 temp_f1;
    f32 temp_f1_2;
    s32 temp_r0;
    s32 temp_r0_2;
    u32 temp_r3;
    u32 temp_r3_10;
    u32 particle_emitter;
    u32 temp_r3_12;
    u32 temp_r3_13;
    u32 temp_r3_14;
    u32 temp_r3_15;
    u32 temp_r3_16;
    u32 temp_r3_17;
    u32 temp_r3_18;
    u32 temp_r3_2;
    u32 temp_r3_3;
    u32 temp_r3_4;
    u32 temp_r3_5;
    u32 temp_r3_6;
    u32 temp_r3_7;
    u32 temp_r3_8;
    u32 temp_r3_9;
    u8 *temp_r31;
    u8 *temp_r30;
    temp_r31 = (u8 *)this + 0x484;
    temp_r30 = (u8 *)this + 0x490;
    temp_r0 = *(s32 *)((s8 *)this + 0x398);
    if (temp_r0 == 6) {
        ((s32 (*)(void))create_all_tenchu_furu__11TBoss4Type2Fi)();
    } else if (temp_r0 == 1) {
        TBoss4Type2__sub_80054DA8((TBoss4Type2 *)this);
    }
    if ((s32) *(s32 *)((s8 *)this + 0x3E4) == 0xD) {
        temp_f1 = *(f32 *)((s8 *)this + 0x3E8);
        if (temp_f1 > lbl_805D8AF8) {
            temp_r3 = *(u32 *)((s8 *)this + 0x41C);
            if (temp_r3 != 0) {
                TParticleCtrl::release((void *)temp_r3);
                *(u32 *)((s8 *)this + 0x41C) = 0U;
            }
            temp_r3_2 = *(u32 *)((s8 *)this + 0x424);
            if (temp_r3_2 != 0) {
                TParticleCtrl::release((void *)temp_r3_2);
                *(u32 *)((s8 *)this + 0x424) = 0U;
            }
        } else if (temp_f1 >= lbl_805D8AFC) {
            if ((u32) *(u32 *)((s8 *)this + 0x41C) == 0) {
                temp_r3_3 = (u32)create_particle_emitter((temp_r31), 0x142);
                *(u32 *)((s8 *)this + 0x41C) = temp_r3_3;
                if (temp_r3_3 != 0) {
                    ((TParticleCtrl *)((void *) *(u32 *)((s8 *)this + 0x41C)))->set_flags(0x40U);
                }
            }
            if ((u32) *(u32 *)((s8 *)this + 0x424) == 0) {
                temp_r3_4 = (u32)create_particle_emitter((temp_r30), 0x142);
                *(u32 *)((s8 *)this + 0x424) = temp_r3_4;
                if (temp_r3_4 != 0) {
                    ((TParticleCtrl *)((void *) *(u32 *)((s8 *)this + 0x424)))->set_flags(0x40U);
                }
            }
        }
        temp_r3_5 = *(u32 *)((s8 *)this + 0x41C);
        if (temp_r3_5 != 0) {
            ((TParticleCtrl *)temp_r3_5)->set_position(temp_r31);
        }
        temp_r3_6 = *(u32 *)((s8 *)this + 0x424);
        if (temp_r3_6 != 0) {
            ((TParticleCtrl *)temp_r3_6)->set_position(temp_r30);
        }
    }
    if ((s32) *(s32 *)((s8 *)this + 0x3E4) == 0xE) {
        temp_f1_2 = *(f32 *)((s8 *)this + 0x3E8);
        if (temp_f1_2 > lbl_805D8B00) {
            temp_r3_7 = *(u32 *)((s8 *)this + 0x41C);
            if (temp_r3_7 != 0) {
                TParticleCtrl::release((void *)temp_r3_7);
                *(u32 *)((s8 *)this + 0x41C) = 0U;
            }
            temp_r3_8 = *(u32 *)((s8 *)this + 0x420);
            if (temp_r3_8 != 0) {
                TParticleCtrl::release((void *)temp_r3_8);
                *(u32 *)((s8 *)this + 0x420) = 0U;
            }
            temp_r3_9 = *(u32 *)((s8 *)this + 0x424);
            if (temp_r3_9 != 0) {
                TParticleCtrl::release((void *)temp_r3_9);
                *(u32 *)((s8 *)this + 0x424) = 0U;
            }
            temp_r3_10 = *(u32 *)((s8 *)this + 0x428);
            if (temp_r3_10 != 0) {
                TParticleCtrl::release((void *)temp_r3_10);
                *(u32 *)((s8 *)this + 0x428) = 0U;
            }
        } else if (temp_f1_2 >= lbl_805D8B04) {
            if ((u32) *(u32 *)((s8 *)this + 0x41C) == 0) {
                particle_emitter = (u32)create_particle_emitter((temp_r31), 0x13A);
                *(u32 *)((s8 *)this + 0x41C) = particle_emitter;
                if (particle_emitter != 0) {
                    ((TParticleCtrl *)((void *) *(u32 *)((s8 *)this + 0x41C)))->set_flags(0x40U);
                }
                play_sound_effect(0x40039717, (u8 *)this + 0x38, 0, 1);
            }
            if ((u32) *(u32 *)((s8 *)this + 0x420) == 0) {
                temp_r3_12 = (u32)create_particle_emitter((temp_r31), 0x13B);
                *(u32 *)((s8 *)this + 0x420) = temp_r3_12;
                if (temp_r3_12 != 0) {
                    ((TParticleCtrl *)((void *) *(u32 *)((s8 *)this + 0x420)))->set_flags(0x40U);
                }
            }
            if ((u32) *(u32 *)((s8 *)this + 0x424) == 0) {
                temp_r3_13 = (u32)create_particle_emitter((temp_r30), 0x13A);
                *(u32 *)((s8 *)this + 0x424) = temp_r3_13;
                if (temp_r3_13 != 0) {
                    ((TParticleCtrl *)((void *) *(u32 *)((s8 *)this + 0x424)))->set_flags(0x40U);
                }
            }
            if ((u32) *(u32 *)((s8 *)this + 0x428) == 0) {
                temp_r3_14 = (u32)create_particle_emitter((temp_r30), 0x13B);
                *(u32 *)((s8 *)this + 0x428) = temp_r3_14;
                if (temp_r3_14 != 0) {
                    ((TParticleCtrl *)((void *) *(u32 *)((s8 *)this + 0x428)))->set_flags(0x40U);
                }
            }
        }
        temp_r3_15 = *(u32 *)((s8 *)this + 0x41C);
        if (temp_r3_15 != 0) {
            ((TParticleCtrl *)temp_r3_15)->set_position(temp_r31);
        }
        temp_r3_16 = *(u32 *)((s8 *)this + 0x420);
        if (temp_r3_16 != 0) {
            ((TParticleCtrl *)temp_r3_16)->set_position(temp_r31);
        }
        temp_r3_17 = *(u32 *)((s8 *)this + 0x424);
        if (temp_r3_17 != 0) {
            ((TParticleCtrl *)temp_r3_17)->set_position(temp_r30);
        }
        temp_r3_18 = *(u32 *)((s8 *)this + 0x428);
        if (temp_r3_18 != 0) {
            ((TParticleCtrl *)temp_r3_18)->set_position(temp_r30);
        }
    }
    temp_r0_2 = *(s32 *)((s8 *)this + 0x398) - 1;
    *(s32 *)((s8 *)this + 0x398) = temp_r0_2;
    if (temp_r0_2 < 0) {
        set_state(1);
    }
}

}
