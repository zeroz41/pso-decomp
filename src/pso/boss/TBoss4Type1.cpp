#include "types.h"
#include "pso/system/PadRumble.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TUnk_804806E8.h"
#include "pso/object/TObjMotion.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/boss/TBoss4Type1.h"
#include "pso/misc/TLobby.h"
extern "C" void has_flag_0x800__13TUnk_804806E8Fv();
extern "C" void test_flag30_512__13TUnk_804806E8Fv();
extern "C" void test_flag_1000__13TUnk_804806E8Fv();
extern "C" void test_flag_256__13TUnk_804806E8Fv();

#include <stddef.h>
#include "pso/boss/TBoss4Type2.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/misc/TWindowSubSymbolChatPartsSet.h"
#include "pso/object/TObjFish.h"

#include "pso/TObjDFTenchuFuru.h"
#include "pso/TParticleCtrl.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/boss/TBoss4DarkFalz.h"
#include "pso/boss/TBoss4Uro.h"
#include "pso/boss/TBoss6PlotFalz.h"
#include "pso/enemy/TObjEneLappy.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TNowLoading.h"
#include "pso/misc/TTecRaFoie.h"
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
int pop_matrix(void);
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

typedef void (Boss_800542B0::*Act_800542B0)();

struct Entry_800542B0 {
    u8 *f0;
    s32 f4;
    Act_800542B0 enter;
    Act_800542B0 a;
    Act_800542B0 b;
};

struct RecoveredGlobal_8005455C_lbl_80485EC8 {
    s32 value;
    u8 remaining[0x1DC];
};

struct Obj_80054738 {
    u8 pad0[0x32C];
    s16 x32c;
    u8 pad32e[0x33E - 0x32E];
    s16 x33e;
    u8 pad340[0x374 - 0x340];
    s32 x374;
    u8 pad378[0x38C - 0x378];
    s32 x38c;
    u8 pad390[0x3DC - 0x390];
    f32 x3dc;
    f32 x3e0;
    void m();
};

typedef void (Obj_80054738::*Act_80054738)();

typedef char RecoveredGlobal_80054530_lbl_80485EC8_size[sizeof(RecoveredGlobal_80054530_lbl_80485EC8) == 0x1E0 ? 1 : -1];

typedef char RecoveredGlobal_8005455C_lbl_80485EC8_size[sizeof(RecoveredGlobal_8005455C_lbl_80485EC8) == 0x1E0 ? 1 : -1];

struct S_80054938 {
    u8 pad0[0x18];
    void *vt;
    u8 pad1c[0x378 - 0x1c];
    u8 f378[0x1c];
    s32 f394;
    u8 pad398[0x3f8 - 0x398];
    void *parts[13];
    void *fx[3];
    u8 pad438[0x480 - 0x438];
    void *f480;
};

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

f32 calc_boss4_scale__10TObjPlayerFi(void *);
void VecCopy__FP3VecPC3Vec(void *, void *);
int get_player_data__10TObjPlayerFi(int a0);
u16 obj_getField1c(void *);
f32 atan2_float(f32 y, f32 x);
u8 * dispatch_shared_handler_a__6TLobbyFl(s32);
s32 get_bml_motion(s32, s32);
s32 TObjFish__sub_8001EDB0(s32, s32);
s32 get_bml_model(s32, s32);
void fn_8004AA04(void *);
s32 TBoss4DarkFalz__sub_8004AF5C(s32, s16 *, s16 *);
void TBoss4DarkFalz__sub_8004B4F0(void *, void *);
void TBoss4DarkFalz__sub_8004D990(s32);
void *create__16TObjDFBeamCursorFPvPv(void *arg0, void *arg1);
s32 TBoss4Type3__sub_8005254C(u16);
void TBoss4Type2__sub_800525AC(u8 *arg0);
void TBoss4Type2__sub_800528B8(void *arg0);
void init_timer__11TBoss4Type2FPv(u8 *arg0);
void update_tech_charge__11TBoss4Type2FPv(u8 *arg0);
void update_scale_state__11TBoss4Type2FPv(void *arg0);
void init_child_and_set_timer__11TBoss4Type2FPv(void *arg0);
void update_attack_countdown__11TBoss4Type2FPv(u8 *arg0);
void update_state__11TBoss4Type2FPv(void *arg0);
void set_motion_for_state__11TBoss4Type2FPv(TBoss4Type2 *arg0);
void tick_countdown_set_state7__11TBoss4Type2FPv(TBoss4Type2 *arg0);
void update_spawn_uro__14TBoss4DarkFalzFPv(Obj_80052CDC *arg0);
void tick_state_398_timer__11TBoss4Type2FPv(TBoss4Type2 *arg0);
void TBoss4Type2__sub_80052EE8(void);
void TBoss4Type2__sub_80052EEC(void* p);
void update_state_transition__11TBoss4Type2FPv(void* p);
void TBoss4Type2__sub_8005307C(void* p);
void update_flag800_state__11TBoss4Type2FPv(void *arg0);
void check_state_if_idle__11TBoss4Type2FPv(void* p);
void TBoss4Type2__sub_800531BC(void* p);
void TBoss4Type2__sub_80053504(TBoss4Type2 *arg0);
void TBoss4Type2__sub_800535A8(Boss_800535A8 *arg0);
void pick_target_position__13TRaderMapCoreFPvPv(O_80053914 *self, Vec_80053914 *out);
f32 calc_wave_offset__11TBoss4Type2Ff(f32 farg0);
void set_pos_from_scaled_offset__11TBoss4Type2FPvPvPv(S_80054224 *o, void *src, V_80054224 *in);
u8 * TBoss4Type2__sub_80054384(void *self, s32 i, s32 j);
void render_and_update_effects__10TObjPlayerFPv(void* p);
void request_state_3__11TBoss4Type2FPv(TBoss4Type2 *arg0);
void fn_800548E4(u8 *arg0);
S_80054938 * __dt__11TBoss4Type1Fv(S_80054938 *o, s16 flag);
void TBoss4Type2__sub_80054DA8(TBoss4Type2 *boss);
void create_all_tenchu_furu__11TBoss4Type2Fi(s32 arg0);
s32 TBoss4Type2__sub_80054FC0(void *, f32);
void TBoss4Type2__sub_80055300(void);
Vec_80053E40 * get_position_ptr__10TObjPlayerFv(void *);
void * create__9TBoss4UroFi(Params_80052CDC *);
void *spawn_particle_effect(void *, s32);
void *create_particle_emitter(void *pos, s32 id);
int toggle_particle_effect__10TObjPlayerFv(void*);
s32 clear_render_callback__8TObjFishFv(s32);
s32 TObjControl__ct(s32, s32);
void *__dt__9TObjEnemyFv(TObjEnemy *arg0, s16 arg1);
s32 angle_diff_s16(s32, s32);
void free_collision_body_parts(void *);
s32 project_actor_to_ground(void *, void *, int);
s32 submit_cursor_candidate(void *, s32);
s32 add_radar_scaled_marker(void *, s32, s16, s32, f32);
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);
s32 play_sound_effect(int, void *, int, int);
void __dl__7TObjectFPv(void *);
s32 __nw__7TObjectFUl(s32);
void create__11TTecRaBartaFPvPvPvPv(void *source, void *origin, void *pos, void *level);
void TBoss6PlotFalz__sub_802AC008(f32 farg0, f32 farg1);
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
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
extern RecoveredGlobal_80054F6C_lbl_804FF2A0 TBoss4Type2__tenchu_furu_array;
extern s32 lbl_805D586C;
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
extern const f32 lbl_805D8B80;
extern s32 tl_04;

#pragma push
#pragma fp_contract on
struct Cam_800531C8 { u8 pad[0x178]; Vec_80053E40 pos; };

extern "C" {
extern Vec_80053E40 lbl_804375EC;
extern Vec_80053E40 lbl_804375F8;
extern Cam_800531C8 *camera_ctrl_instance;
}

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
extern "C" void start_motion_for_index__11TBoss4Type2FPv(S_80052E10 *o);
extern "C" void TBoss4Type2__sub_80052EF8(O_80052EF8 *o);
extern "C" void TBoss4Type2__sub_800530C0(Obj_800530C0 *arg0);
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
void *lbl_80485B08[80] = {
    (void *)0xfb, (void *)0xfc, (void *)0x0, (void *)0xffffffff,
    (void *)&TBoss4Type2__sub_800531BC, (void *)0x0, (void *)0xffffffff, (void *)&check_state_if_idle__11TBoss4Type2FPv,
    (void *)0x0, (void *)0xffffffff, (void *)&TBoss4Type2__sub_800530C0, (void *)0x0,
    (void *)0xffffffff, (void *)&update_flag800_state__11TBoss4Type2FPv, (void *)0x0, (void *)0xffffffff,
    (void *)&TBoss4Type2__sub_8005307C, (void *)0x0, (void *)0xffffffff, (void *)&update_state_transition__11TBoss4Type2FPv,
    (void *)0x0, (void *)0xffffffff, (void *)&TBoss4Type2__sub_80052EF8, (void *)0x0,
    (void *)0xffffffff, (void *)&TBoss4Type2__sub_80052EEC, (void *)0x0, (void *)0xffffffff,
    (void *)&TBoss4Type2__sub_80052EE8, (void *)0x0, (void *)0xffffffff, (void *)&tick_state_398_timer__11TBoss4Type2FPv,
    (void *)0x0, (void *)0xffffffff, (void *)&start_motion_for_index__11TBoss4Type2FPv, (void *)0x0,
    (void *)0xffffffff, (void *)&update_spawn_uro__14TBoss4DarkFalzFPv, (void *)0x0, (void *)0xffffffff,
    (void *)&start_motion_for_index__11TBoss4Type2FPv, (void *)0x0, (void *)0xffffffff, (void *)&tick_countdown_set_state7__11TBoss4Type2FPv,
    (void *)0x0, (void *)0xffffffff, (void *)&set_motion_for_state__11TBoss4Type2FPv, (void *)0x0,
    (void *)0xffffffff, (void *)&update_state__11TBoss4Type2FPv, (void *)0x0, (void *)0xffffffff,
    (void *)&update_attack_countdown__11TBoss4Type2FPv, (void *)0x0, (void *)0xffffffff, (void *)&init_child_and_set_timer__11TBoss4Type2FPv,
    (void *)0x0, (void *)0xffffffff, (void *)&update_scale_state__11TBoss4Type2FPv, (void *)0x0,
    (void *)0xffffffff, (void *)&update_tech_charge__11TBoss4Type2FPv, (void *)0x0, (void *)0xffffffff,
    (void *)&init_child_and_set_timer__11TBoss4Type2FPv, (void *)0x0, (void *)0xffffffff, (void *)&update_scale_state__11TBoss4Type2FPv,
    (void *)0x0, (void *)0xffffffff, (void *)&update_tech_charge__11TBoss4Type2FPv, (void *)0x0,
    (void *)0xffffffff, (void *)&init_timer__11TBoss4Type2FPv, (void *)0x0, (void *)0xffffffff,
    (void *)&TBoss4Type2__sub_800528B8, (void *)0x0, (void *)0xffffffff, (void *)&TBoss4Type2__sub_800525AC,
};
Entry_800542B0 lbl_80485C48[11] = {
    { lbl_8043750C, 0, 0, 0, 0 },
    { lbl_80437514, 0, 0, 0, 0 },
    { lbl_80437520, 0, 0, 0, 0 },
    { lbl_8043752C, 1, 0, 0, 0 },
    { lbl_80437534, -1, 0, 0, 0 },
    { lbl_80437540, 2, 0, 0, 0 },
    { lbl_8043754C, 2, 0, 0, 0 },
    { lbl_80437558, 4, 0, 0, 0 },
    { lbl_80437560, 11, 0, 0, 0 },
    { lbl_80437568, 12, 0, 0, 0 },
    { lbl_80437570, 13, 0, 0, 0 },
};
void *lbl_80485E2C[33] = {
    (void *)0x43070000, (void *)0x41c80000, (void *)0x0, (void *)0x41f00000,
    (void *)0x0, (void *)0x0, (void *)0x801b, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x41c80000, (void *)0x43070000, (void *)0x41f00000, (void *)0x0,
    (void *)0x0, (void *)0x801b, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0xc3070000, (void *)0x41c80000,
    (void *)0x0, (void *)0x41f00000, (void *)0x0, (void *)0x0,
    (void *)0x801b, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0,
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
void *lbl_80486150[3] = {
    (void *)0x0, (void *)0x0, (void *)0xc2f00000,
};
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
extern "C" void vfunc_6__13TUnk_804B9870FPsl();
extern "C" void vfunc_29__13TUnk_804806E8Fv();
extern "C" void vfunc_73__13TUnk_804806E8Fv();
extern "C" void vfunc_28__13TUnk_804806E8Fv();
extern "C" void consume_timer_field__13TUnk_804806E8Fl();
extern "C" void vfunc_67__13TUnk_804806E8Ff();
extern "C" void vfunc_66__13TUnk_804806E8Fv();
extern "C" void get_anim_node_position__13TUnk_804806E8FlP3Vec();
extern "C" void vfunc_61__13TUnk_804806E8Fv();
extern "C" void vfunc_60__13TUnk_804806E8Fv();
extern "C" void vfunc_59__13TUnk_804806E8Fv();
extern "C" void vfunc_58__13TUnk_804806E8Fv();
extern "C" void vfunc_43__13TUnk_804806E8Fv();
extern "C" void vfunc_18__13TUnk_804806E8FPUc();
extern "C" void vfunc_13__13TUnk_804AF8A0Fl();
extern "C" void TObjPlayer__sub_80055678();
extern "C" void TObjPlayer__sub_8005567C();
extern "C" void TObjPlayer__sub_80055680();
extern "C" void TObjPlayer__sub_80055684();
extern "C" void TObjPlayer__sub_80055688();
extern "C" void TObjPlayer__sub_8005568C();
extern "C" void TObjPlayer__sub_80055690();
extern "C" void vfunc_74__9TObjEnemyFl();
extern "C" void add_actor_exp__13TUnk_804806E8Fl();
extern "C" void apply_action_hold_status__13TUnk_804806E8Ff();
extern "C" void apply_anti_technique__13TUnk_804806E8Fl();
extern "C" void apply_attack_stat_status__13TUnk_804806E8FPv();
extern "C" void apply_hit_message_flags__9TObjEnemyFPv();
extern "C" void apply_knockback_from_attacker__13TUnk_804806E8FPUc();
extern "C" void apply_object_set_data__13TUnk_804B9870FPv();
extern "C" void apply_set_data__9TObjEnemyFPv();
extern "C" void apply_switch_attack__13TUnk_804806E8Fv();
extern "C" void calc_distance_accuracy_penalty__13TUnk_804806E8FPvPvPvf();
extern "C" void vfunc_79__9TObjEnemyFv();
extern "C" void classify_actor_view_detail__13TUnk_804B9870Ffff();
extern "C" void clear_all_status_effects__13TUnk_804806E8Fv();
extern "C" void cure_paralysis__13TUnk_804806E8Fv();
extern "C" void cure_poison_ailment__13TUnk_804806E8Fv();
extern "C" void enemy_spawn_jellen_effect__13TUnk_804806E8Fv();
extern "C" void enemy_spawn_zalure_effect__13TUnk_804806E8Fv();
extern "C" void vfunc_78__13TUnk_804806E8Fl();
extern "C" void vfunc_77__13TUnk_804806E8Fv();
extern "C" void vfunc_76__13TUnk_804806E8Fv();
extern "C" void vfunc_75__13TUnk_804806E8Ff();
extern "C" void clear_lobby_object_state__9TObjEnemyFv();
extern "C" void vfunc_9__13TUnk_804806E8Fv();
extern "C" void get_actor_level_index__13TUnk_804806E8Fv();
extern "C" void get_name__9TObjEnemyFv();
extern "C" void get_pos__13TUnk_804806E8Fl();
extern "C" void is_actor_cadence_frame__13TUnk_804806E8Fl();
extern "C" void is_target_in_attack_range__13TUnk_804806E8Fv();
extern "C" void receive_direct_attack__13TUnk_804806E8FPv19DirectAttackPayloadPvll();
extern "C" void receive_physical_attack__13TUnk_804806E8FPvf();
extern "C" void receive_weapon_special_attack__13TUnk_804806E8FPvPv();
extern "C" void apply_defense_stat_status__13TUnk_804806E8FPv();
extern "C" void render_shadows__9TObjEnemyFv(u8 *arg0);
extern "C" void reset_motion_fields__13TUnk_804806E8Fv();
extern "C" void reset_pose__13TUnk_804806E8Fv();
extern "C" void roll_physical_accuracy__13TUnk_804806E8FPvlf();
extern "C" void select_melee_contact_body__13TUnk_804806E8FPvf();
extern "C" void trigger_switch_attack__13TUnk_804806E8Fv(s32 arg0);
extern "C" void try_start_action__13TUnk_804806E8Fll();
extern "C" void update_action_hold_status__13TUnk_804806E8Fv();
extern "C" s32 vfunc_37__13TUnk_804806E8Fv(u8 *arg0);
extern "C" void update_actor_ground_y__13TUnk_804806E8Fv();
extern "C" s32 update_attack_stat_status__13TUnk_804806E8Fv(u8 *arg0);
extern "C" s32 update_defense_stat_status__13TUnk_804806E8Fv(u8 *arg0);
extern "C" void update_flag30_timer__13TUnk_804806E8Fv();
extern "C" void update_movement_status__13TUnk_804806E8Fv();
extern "C" void update_object_view_visibility__13TUnk_804B9870Fff();
extern "C" void update_poison_status__13TUnk_804806E8Fv();
extern "C" void update_shock_clock__13TUnk_804806E8Fv();
void TBoss4Type2__sub_80054738(Obj_80054738 *self);
void *boss4_type2_state_motion_index_table[3] = {
    (void *)0x4, (void *)0x7, (void *)0xa,
};
void *__vt__11TBoss4Type1[83] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__11TBoss4Type1Fv, (void *)&TBoss4Type2__sub_80054738,
    (void *)&render_and_update_effects__10TObjPlayerFPv, (void *)&render_shadows__9TObjEnemyFv, (void *)&vfunc_6__13TUnk_804B9870FPsl, (void *)&apply_object_set_data__13TUnk_804B9870FPv,
    (void *)&reset_motion_fields__13TUnk_804806E8Fv, (void *)&vfunc_9__13TUnk_804806E8Fv, (void *)&update_object_view_visibility__13TUnk_804B9870Fff, (void *)&classify_actor_view_detail__13TUnk_804B9870Ffff,
    (void *)&get_name__9TObjEnemyFv, (void *)&vfunc_13__13TUnk_804AF8A0Fl, (void *)&add_actor_exp__13TUnk_804806E8Fl, (void *)&consume_timer_field__13TUnk_804806E8Fl,
    (void *)&get_actor_level_index__13TUnk_804806E8Fv, (void *)&update_actor_ground_y__13TUnk_804806E8Fv, (void *)&vfunc_18__13TUnk_804806E8FPUc, (void *)&is_actor_cadence_frame__13TUnk_804806E8Fl,
    (void *)&select_melee_contact_body__13TUnk_804806E8FPvf, (void *)&calc_distance_accuracy_penalty__13TUnk_804806E8FPvPvPvf, (void *)&receive_physical_attack__13TUnk_804806E8FPvf, (void *)&receive_direct_attack__13TUnk_804806E8FPv19DirectAttackPayloadPvll,
    (void *)&receive_weapon_special_attack__13TUnk_804806E8FPvPv, (void *)&apply_knockback_from_attacker__13TUnk_804806E8FPUc, (void *)&try_start_action__13TUnk_804806E8Fll, (void *)&roll_physical_accuracy__13TUnk_804806E8FPvlf,
    (void *)&vfunc_28__13TUnk_804806E8Fv, (void *)&vfunc_29__13TUnk_804806E8Fv, (void *)&is_target_in_attack_range__13TUnk_804806E8Fv, (void *)&test_flag_256__13TUnk_804806E8Fv,
    (void *)&test_flag30_512__13TUnk_804806E8Fv, (void *)&has_flag_0x800__13TUnk_804806E8Fv, (void *)&test_flag_1000__13TUnk_804806E8Fv, (void *)&update_poison_status__13TUnk_804806E8Fv,
    (void *)&update_action_hold_status__13TUnk_804806E8Fv, (void *)&vfunc_37__13TUnk_804806E8Fv, (void *)&update_flag30_timer__13TUnk_804806E8Fv, (void *)&update_movement_status__13TUnk_804806E8Fv,
    (void *)&update_shock_clock__13TUnk_804806E8Fv, (void *)&update_attack_stat_status__13TUnk_804806E8Fv, (void *)&update_defense_stat_status__13TUnk_804806E8Fv, (void *)&vfunc_43__13TUnk_804806E8Fv,
    (void *)&TObjPlayer__sub_80055678, (void *)&TObjPlayer__sub_8005567C, (void *)&TObjPlayer__sub_80055680, (void *)&TObjPlayer__sub_80055684,
    (void *)&TObjPlayer__sub_80055688, (void *)&TObjPlayer__sub_8005568C, (void *)&TObjPlayer__sub_80055690, (void *)&apply_attack_stat_status__13TUnk_804806E8FPv,
    (void *)&apply_defense_stat_status__13TUnk_804806E8FPv, (void *)&cure_poison_ailment__13TUnk_804806E8Fv, (void *)&cure_paralysis__13TUnk_804806E8Fv, (void *)&clear_all_status_effects__13TUnk_804806E8Fv,
    (void *)&apply_action_hold_status__13TUnk_804806E8Ff, (void *)&apply_anti_technique__13TUnk_804806E8Fl, (void *)&vfunc_58__13TUnk_804806E8Fv, (void *)&vfunc_59__13TUnk_804806E8Fv,
    (void *)&vfunc_60__13TUnk_804806E8Fv, (void *)&vfunc_61__13TUnk_804806E8Fv, (void *)&fn_800548E4, (void *)&request_state_3__11TBoss4Type2FPv,
    (void *)&reset_pose__13TUnk_804806E8Fv, (void *)&get_anim_node_position__13TUnk_804806E8FlP3Vec, (void *)&vfunc_66__13TUnk_804806E8Fv, (void *)&vfunc_67__13TUnk_804806E8Ff,
    (void *)&get_pos__13TUnk_804806E8Fl, (void *)&apply_switch_attack__13TUnk_804806E8Fv, (void *)&enemy_spawn_jellen_effect__13TUnk_804806E8Fv, (void *)&trigger_switch_attack__13TUnk_804806E8Fv,
    (void *)&enemy_spawn_zalure_effect__13TUnk_804806E8Fv, (void *)&vfunc_73__13TUnk_804806E8Fv, (void *)&vfunc_74__9TObjEnemyFl, (void *)&vfunc_75__13TUnk_804806E8Ff,
    (void *)&vfunc_76__13TUnk_804806E8Fv, (void *)&vfunc_77__13TUnk_804806E8Fv, (void *)&vfunc_78__13TUnk_804806E8Fl, (void *)&vfunc_79__9TObjEnemyFv,
    (void *)&apply_hit_message_flags__9TObjEnemyFPv, (void *)&apply_set_data__9TObjEnemyFPv, (void *)&clear_lobby_object_state__9TObjEnemyFv,
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
#define __vt__11TBoss4Type1 ((u8 *)__vt__11TBoss4Type1)

void TBoss4Type2__sub_800525AC(u8 *boss4_type2) {
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
    temp_r31 = (boss4_type2 + 0x484);
    temp_r30 = (boss4_type2 + 0x490);
    temp_r0 = *(s32 *)((s8 *)boss4_type2 + 0x398);
    if (temp_r0 == 6) {
        ((s32 (*)(void))create_all_tenchu_furu__11TBoss4Type2Fi)();
    } else if (temp_r0 == 1) {
        TBoss4Type2__sub_80054DA8((TBoss4Type2 *)boss4_type2);
    }
    if ((s32) *(s32 *)((s8 *)boss4_type2 + 0x3E4) == 0xD) {
        temp_f1 = *(f32 *)((s8 *)boss4_type2 + 0x3E8);
        if (temp_f1 > lbl_805D8AF8) {
            temp_r3 = *(u32 *)((s8 *)boss4_type2 + 0x41C);
            if (temp_r3 != 0) {
                TBoss4Type2::request_destroy((u32)temp_r3);
                *(u32 *)((s8 *)boss4_type2 + 0x41C) = 0U;
            }
            temp_r3_2 = *(u32 *)((s8 *)boss4_type2 + 0x424);
            if (temp_r3_2 != 0) {
                TBoss4Type2::request_destroy((u32)temp_r3_2);
                *(u32 *)((s8 *)boss4_type2 + 0x424) = 0U;
            }
        } else if (temp_f1 >= lbl_805D8AFC) {
            if ((u32) *(u32 *)((s8 *)boss4_type2 + 0x41C) == 0) {
                temp_r3_3 = (u32)create_particle_emitter((temp_r31), 0x142);
                *(u32 *)((s8 *)boss4_type2 + 0x41C) = temp_r3_3;
                if (temp_r3_3 != 0) {
                    ((TBoss4Type2 *)((void *) *(u32 *)((s8 *)boss4_type2 + 0x41C)))->set_flags(0x40U);
                }
            }
            if ((u32) *(u32 *)((s8 *)boss4_type2 + 0x424) == 0) {
                temp_r3_4 = (u32)create_particle_emitter((temp_r30), 0x142);
                *(u32 *)((s8 *)boss4_type2 + 0x424) = temp_r3_4;
                if (temp_r3_4 != 0) {
                    ((TBoss4Type2 *)((void *) *(u32 *)((s8 *)boss4_type2 + 0x424)))->set_flags(0x40U);
                }
            }
        }
        temp_r3_5 = *(u32 *)((s8 *)boss4_type2 + 0x41C);
        if (temp_r3_5 != 0) {
            ((TNowLoading *)temp_r3_5)->copy_pos(temp_r31);
        }
        temp_r3_6 = *(u32 *)((s8 *)boss4_type2 + 0x424);
        if (temp_r3_6 != 0) {
            ((TNowLoading *)temp_r3_6)->copy_pos(temp_r30);
        }
    }
    if ((s32) *(s32 *)((s8 *)boss4_type2 + 0x3E4) == 0xE) {
        temp_f1_2 = *(f32 *)((s8 *)boss4_type2 + 0x3E8);
        if (temp_f1_2 > lbl_805D8B00) {
            temp_r3_7 = *(u32 *)((s8 *)boss4_type2 + 0x41C);
            if (temp_r3_7 != 0) {
                TBoss4Type2::request_destroy((u32)temp_r3_7);
                *(u32 *)((s8 *)boss4_type2 + 0x41C) = 0U;
            }
            temp_r3_8 = *(u32 *)((s8 *)boss4_type2 + 0x420);
            if (temp_r3_8 != 0) {
                TBoss4Type2::request_destroy((u32)temp_r3_8);
                *(u32 *)((s8 *)boss4_type2 + 0x420) = 0U;
            }
            temp_r3_9 = *(u32 *)((s8 *)boss4_type2 + 0x424);
            if (temp_r3_9 != 0) {
                TBoss4Type2::request_destroy((u32)temp_r3_9);
                *(u32 *)((s8 *)boss4_type2 + 0x424) = 0U;
            }
            temp_r3_10 = *(u32 *)((s8 *)boss4_type2 + 0x428);
            if (temp_r3_10 != 0) {
                TBoss4Type2::request_destroy((u32)temp_r3_10);
                *(u32 *)((s8 *)boss4_type2 + 0x428) = 0U;
            }
        } else if (temp_f1_2 >= lbl_805D8B04) {
            if ((u32) *(u32 *)((s8 *)boss4_type2 + 0x41C) == 0) {
                particle_emitter = (u32)create_particle_emitter((temp_r31), 0x13A);
                *(u32 *)((s8 *)boss4_type2 + 0x41C) = particle_emitter;
                if (particle_emitter != 0) {
                    ((TBoss4Type2 *)((void *) *(u32 *)((s8 *)boss4_type2 + 0x41C)))->set_flags(0x40U);
                }
                play_sound_effect(0x40039717, boss4_type2 + 0x38, 0, 1);
            }
            if ((u32) *(u32 *)((s8 *)boss4_type2 + 0x420) == 0) {
                temp_r3_12 = (u32)create_particle_emitter((temp_r31), 0x13B);
                *(u32 *)((s8 *)boss4_type2 + 0x420) = temp_r3_12;
                if (temp_r3_12 != 0) {
                    ((TBoss4Type2 *)((void *) *(u32 *)((s8 *)boss4_type2 + 0x420)))->set_flags(0x40U);
                }
            }
            if ((u32) *(u32 *)((s8 *)boss4_type2 + 0x424) == 0) {
                temp_r3_13 = (u32)create_particle_emitter((temp_r30), 0x13A);
                *(u32 *)((s8 *)boss4_type2 + 0x424) = temp_r3_13;
                if (temp_r3_13 != 0) {
                    ((TBoss4Type2 *)((void *) *(u32 *)((s8 *)boss4_type2 + 0x424)))->set_flags(0x40U);
                }
            }
            if ((u32) *(u32 *)((s8 *)boss4_type2 + 0x428) == 0) {
                temp_r3_14 = (u32)create_particle_emitter((temp_r30), 0x13B);
                *(u32 *)((s8 *)boss4_type2 + 0x428) = temp_r3_14;
                if (temp_r3_14 != 0) {
                    ((TBoss4Type2 *)((void *) *(u32 *)((s8 *)boss4_type2 + 0x428)))->set_flags(0x40U);
                }
            }
        }
        temp_r3_15 = *(u32 *)((s8 *)boss4_type2 + 0x41C);
        if (temp_r3_15 != 0) {
            ((TNowLoading *)temp_r3_15)->copy_pos(temp_r31);
        }
        temp_r3_16 = *(u32 *)((s8 *)boss4_type2 + 0x420);
        if (temp_r3_16 != 0) {
            ((TNowLoading *)temp_r3_16)->copy_pos(temp_r31);
        }
        temp_r3_17 = *(u32 *)((s8 *)boss4_type2 + 0x424);
        if (temp_r3_17 != 0) {
            ((TNowLoading *)temp_r3_17)->copy_pos(temp_r30);
        }
        temp_r3_18 = *(u32 *)((s8 *)boss4_type2 + 0x428);
        if (temp_r3_18 != 0) {
            ((TNowLoading *)temp_r3_18)->copy_pos(temp_r30);
        }
    }
    temp_r0_2 = *(s32 *)((s8 *)boss4_type2 + 0x398) - 1;
    *(s32 *)((s8 *)boss4_type2 + 0x398) = temp_r0_2;
    if (temp_r0_2 < 0) {
        ((TBoss4Type2 *)boss4_type2)->set_state(1);
    }
}
#pragma pop

void TBoss4Type2__sub_800528B8(void *arg0) {
    if ((s32) *(s32 *)((s8 *)arg0 + 0x398) == 0) {
        if (((f32 (*)(void))calc_boss4_scale__10TObjPlayerFi)() < lbl_805D8B08) {
            ((s32 (*)(void *))TBoss4Type2__sub_800535A8)(arg0);
            return;
        }
        ((s32 (*)(void *))TBoss4Type2__sub_80053504)(arg0);
    }
}

void init_timer__11TBoss4Type2FPv(u8 *arg0) {
    TBoss4Type2__sub_80054FC0(arg0 + 0x38, lbl_805D8B0C);
    *(s32 *)((s8 *)arg0 + 0x398) = 0x96;
}

void update_tech_charge__11TBoss4Type2FPv(u8 *arg0) {
    s32 idx;
    Ent_8005294C *ent;
    u32 r;
    idx = *(s32 *)((s8 *)arg0 + 0x374) - 8;
    ent = &((Obj_8005294C *)arg0)->ents[idx];
    if (*(f32 *)((s8 *)arg0 + 0x3E8) > lbl_805D8B10) {
        if (*(u32 *)((s8 *)arg0 + 0x418) != 0) {
            TBoss4Type2::request_destroy((u32)(*(u32 *)((s8 *)arg0 + 0x418)));
            *(u32 *)((s8 *)arg0 + 0x418) = 0;
        }
    } else if (*(f32 *)((s8 *)arg0 + 0x3E8) >= lbl_805D8B14 && *(u32 *)((s8 *)arg0 + 0x418) == 0) {
        if ((*(u32 *)((s8 *)arg0 + 0x418) = (u32)create_particle_emitter(ent, 0xF7)) != 0) {
            ((TBoss4Type2 *)((void *)*(u32 *)((s8 *)arg0 + 0x418)))->set_flags(0x40);
        }
    }
    if (*(f32 *)((s8 *)arg0 + 0x3E8) >= lbl_805D8B14 && *(f32 *)((s8 *)arg0 + 0x3E8) <= lbl_805D8B10) {
        play_persistent_sound(0x4003B512, (s32)arg0, (u32)(arg0 + 0x38), 0, 1);
    }
    if (*(s32 *)((s8 *)arg0 + 0x398) == 0x26) {
        if ((r = ((u32 (*)(void *, s32))spawn_particle_effect)(ent, 0xFD)) != 0) {
            ((TBoss4Type2 *)r)->set_flags(0x40);
        }
        play_sound_effect(0x4003A813, arg0 + 0x38, 0, 1);
        if (idx == 0) {
            create__11TTecRaBartaFPvPvPvPv((void *)arg0, arg0 + 0x3B8, arg0 + 0x3B8, (void *)(*(s32 *)((s8 *)(dispatch_shared_handler_a__6TLobbyFl(0x36)) + 0x1C)));
        } else {
            ((TTecRaFoie *)arg0)->create(arg0 + 0x3B8, arg0 + 0x3B8, (void *)(*(s32 *)((s8 *)(dispatch_shared_handler_a__6TLobbyFl(0x36)) + 0x18)));
        }
        start_pad_rumble_all(0xC0, 0xF);
    }
    if (--*(s32 *)((s8 *)arg0 + 0x398) < 0) {
        ((TBoss4Type2 *)arg0)->set_state(1);
    }
}

void update_scale_state__11TBoss4Type2FPv(void *arg0) {
    s32 sp8;
    s32 var_r31;

    if ((s32) *(s32 *)((s8 *)arg0 + 0x398) == 0) {
        if (((f32 (*)(void))calc_boss4_scale__10TObjPlayerFi)() < lbl_80437620[0]) {
            ((s32 (*)(void *))TBoss4Type2__sub_80053504)(arg0);
            return;
        }
        var_r31 = 8;
        if ((s32) *(s32 *)((s8 *)arg0 + 0x374) == 8) {
            var_r31 = 9;
        }
        ((s32 (*)(void *, s32 *))pick_target_position__13TRaderMapCoreFPvPv)(arg0, &sp8);
        ((TRaderMapCore *)arg0)->set_map_position(&sp8);
        ((TBoss4Type2 *)arg0)->send_state_to_target(var_r31);
    }
}

void init_child_and_set_timer__11TBoss4Type2FPv(void *arg0) {
    create__16TObjDFBeamCursorFPvPv(arg0, ((char *)arg0 + 952));
    *(u32 *)((s8 *)arg0 + 0x398) = 75;
}

void update_attack_countdown__11TBoss4Type2FPv(u8 *boss4_type2) {
    s32 temp_r0;
    if ((s32) *(s32 *)((s8 *)boss4_type2 + 0x398) == 0x2D) {
        play_sound_effect(0x4003AD11, (void *)(&((Foo *) boss4_type2)->arr[*(s32 *)((s8 *)boss4_type2 + 0x3A8)]), 0, 1);
    }
    temp_r0 = *(s32 *)((s8 *)boss4_type2 + 0x398) - 1;
    *(s32 *)((s8 *)boss4_type2 + 0x398) = temp_r0;
    if (temp_r0 < 0) {
        ((TBoss4Type2 *)boss4_type2)->set_state(1);
    }
}

void update_state__11TBoss4Type2FPv(void *arg0) {
    if ((s32) *(s32 *)((s8 *)arg0 + 0x398) == 0) {
        if ((s32) *(s32 *)((s8 *)arg0 + 0x3A8) == 1) {
            ((s32 (*)(void *))TBoss4Type2__sub_800535A8)(arg0);
            return;
        }
        ((s32 (*)(void *))TBoss4Type2__sub_80053504)(arg0);
    }
}

void set_motion_for_state__11TBoss4Type2FPv(TBoss4Type2 *boss4_type2) {
    boss4_type2->set_motion_index(*(s32 *)((s8 *)&boss4_type2_state_motion_index_table.value + (*(s32 *)((s8 *)boss4_type2 + 0x3A8) * 4)));
    *(s32 *)((s8 *)boss4_type2 + 0x398) = 0x3C;
}

void tick_countdown_set_state7__11TBoss4Type2FPv(TBoss4Type2 *boss4_type2) {
    s32 temp_r0;
    temp_r0 = *(s32 *)((s8 *)boss4_type2 + 0x398) - 1;
    *(s32 *)((s8 *)boss4_type2 + 0x398) = temp_r0;
    if (temp_r0 < 0) {
        *(s32 *)((s8 *)boss4_type2 + 0x3D0) = 5;
        boss4_type2->set_state(7);
    }
}

void update_spawn_uro__14TBoss4DarkFalzFPv(Obj_80052CDC *arg0) {
    Params_80052CDC p;
    Spot_80052CDC *s;
    s32 t;
    s = &arg0->spots[arg0->idx];
    t = arg0->timer;
    if (t < 0x106 && (t & 0x1F) == 0 && arg0->count < arg0->max) {
        TBoss4DarkFalz__sub_8004B4F0(p.a, TBoss4DarkFalz__data_804FF1E8);
        if (TBoss4DarkFalz__sub_8004AF5C(arg0->owner, p.a, &p.b) != 0) {
            p.owner = arg0->owner;
            p.c = 1;
            VecCopy__FP3VecPC3Vec(&p.pos, s);
            if (create__9TBoss4UroFi(&p) != NULL) {
                spawn_particle_effect(s, 0x7D);
                play_sound_effect(0x4003A810, s, 0, 1);
                arg0->count++;
            }
        }
    }
    TBoss4DarkFalz__sub_8004D990(arg0->owner);
    if (arg0->timer == 0x106) {
        play_sound_effect(0x4003AD0F, s, 0, 1);
    }
    if (--arg0->timer < 0) {
        arg0->f3d0 = 5;
        ((TBoss4Type2 *)arg0)->set_state(7);
    }
}

void start_motion_for_index__11TBoss4Type2FPv(S_80052E10 *o) {
    ((TBoss4Type2 *)o)->set_motion_index(((s32 *)lbl_804861F4)[o->idx]);
    o->f3c8 = 0;
    ((TWindowSubSymbolChatPartsSet *)((u8 *)boss4_type1_xz_offset_table + 0x28))->copy_vec2(&((P2_80052E10 *)lbl_80486200)[o->idx]);
    o->f3d0 = 6;
    if (o->f374 == 5) {
        o->f398 = 0x12C;
    } else {
        o->f398 = 0x96;
    }
}

void TWindowSubSymbolChatPartsSet::copy_vec2(void* q) { *(f32*)((char*)this + 0x0) = *(f32*)((char*)q + 0x0); *(f32*)((char*)this + 0x4) = *(f32*)((char*)q + 0x4); }

void tick_state_398_timer__11TBoss4Type2FPv(TBoss4Type2 *boss4_type2) {
    s32 temp_r0;
    temp_r0 = *(s32 *)((s8 *)boss4_type2 + 0x398) - 1;
    *(s32 *)((s8 *)boss4_type2 + 0x398) = temp_r0;
    if (temp_r0 < 0) {
        boss4_type2->set_state(4);
    }
}

void TBoss4Type2__sub_80052EE8(void) {  }

void TBoss4Type2__sub_80052EEC(void* p) { *(s32*)((char*)p + 0x398) = 75; }

void TBoss4Type2__sub_80052EF8(O_80052EF8 *o) {
    s32 t;

    o->f39c = ((f32 (*)(void *, f32))calc_wave_offset__11TBoss4Type2Ff)(o, lbl_805D8B18 - (f32)o->f398 / (f32)o->f3cc);
    {
        Vec_80052EF8 a = boss4_type2_motion_vec_table[o->f3a4];
        Vec_80052EF8 b = boss4_type2_motion_vec_table[o->f3a0];
        ((s32 (*)(void *, Vec_80052EF8 *, Vec_80052EF8 *))set_pos_from_scaled_offset__11TBoss4Type2FPvPvPv)(o, &a, &b);
    }
    ((TBoss4Type2 *)o)->calc_scaled_field(((s32 (*)(void *, s32, s32))TBoss4Type2__sub_80054384)(o, o->f3a4, o->f3ac), ((s32 (*)(void *, s32, s32))TBoss4Type2__sub_80054384)(o, o->f3a0, o->f3a8));
    play_persistent_sound(0x4003A80D, (s32)o, (u32)o->f38, 0, 0);
    if (--o->f398 < 0) {
        o->f3a4 = o->f3a0;
        o->f3ac = o->f3a8;
        ((TBoss4Type2 *)o)->set_state(1);
    }
}

void update_state_transition__11TBoss4Type2FPv(void* p) { if (*(int*)((char*)p + 0x398) == 0) { ((TBoss4Type2 *)p)->check_state_transition(); } }

void TBoss4Type2__sub_8005307C(void* p) { *(u32*)((char*)p + 0x398) = *(u32*)((char*)p + 0x3cc); }

void update_flag800_state__11TBoss4Type2FPv(void *boss4_type2) {
    if (*(s32 *)((s8 *)boss4_type2 + 0x30) & 0x800) {
        ((TBoss4Type2 *)boss4_type2)->send_state_to_target(4);
        return;
    }
    ((s32 (*)(void *))TBoss4Type2__sub_80053504)(boss4_type2);
}

void TBoss4Type2__sub_800530C0(Obj_800530C0 *arg0) {
    arg0->f39c = ((f32 (*)(void *, f32))calc_wave_offset__11TBoss4Type2Ff)(arg0, lbl_805D8B18 - (f32)arg0->timer / lbl_805D8B1C);
    Vec_800530C0 a = lbl_80437604;
    Vec_800530C0 b = boss4_type2_effect_offset_vec_b;
    ((void (*)(void *, Vec_800530C0 *, Vec_800530C0 *))set_pos_from_scaled_offset__11TBoss4Type2FPvPvPv)(arg0, &a, &b);
    if (--arg0->timer < 0) {
        ((TBoss4Type2 *)arg0)->set_state(1);
    }
}

void check_state_if_idle__11TBoss4Type2FPv(void* p) { if (*(int*)((char*)p + 0x398) == 0) { ((TBoss4Type2 *)p)->check_state_transition(); } }

void TBoss4Type2__sub_800531BC(void* p) { *(s32*)((char*)p + 0x398) = 75; }

#pragma push
#pragma fp_contract on
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
#pragma pop

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
            ((TNowLoading *)(arg0->a[i]))->copy_pos(&v);
        }
        if (arg0->b[i] != NULL) {
            ((TNowLoading *)(arg0->b[i]))->copy_pos(&v);
        }
    }
    ((TBoss4Type2 *)(arg0->f378))->scroll_strips();
    play_persistent_sound(0x4003BC0E, (s32)arg0, (u32)&arg0->pos, 0x40, 2);
}

void TBoss4Type2__sub_80053504(TBoss4Type2 *boss4_type2) {
    s32 spC;
    s32 sp8;
    boss4_type2->calc_scale_slot_indices(&spC, &sp8);
    boss4_type2->send_darkfalz_code(2, spC, sp8);
}

void TBoss4Type2::check_state_transition() {
    if (((s32 (*)(s32))TBoss4DarkFalz__sub_8004D990)(*(s32 *)((s8 *)this + 0x38C)) <= (s32) (0xC - *(s32 *)((s8 *)this + 0x3C4))) {
        send_state_to_target(5);
        return;
    }
    send_state_to_target(6);
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

#pragma push
#pragma opt_propagation off
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
    for (i = 0; i < lbl_805D586C; i++) {
        p = (O_80053914 *)get_player_data__10TObjPlayerFi(i);
        if (p == NULL) {
            continue;
        }
        if (TBoss4Type3__sub_8005254C(obj_getField1c(p)) == 0) {
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
    s = lbl_805D8B50 * calc_boss4_scale__10TObjPlayerFi(self);
    a1 = (s32)(lbl_80437630 * atan2_float(-self->pos.x, -self->pos.z));
    b = (s32)(lbl_805D8B54 * calc_boss4_scale__10TObjPlayerFi(self));
    ang = b + a1;
    ang -= 0x6000;
    out->x = s * sin_table_lookup(ang);
    out->y = lbl_805D8B20;
    out->z = s * cos_table_lookup(ang);
}
#pragma pop

void TRaderMapCore::set_map_position(void *arg1) {
    *(s32 *)((s8 *)this + 0x3B0) = (s32) ((lbl_805D8B58 + *(f32 *)((s8 *)arg1 + 0)) / lbl_805D8B5C);
    *(s32 *)((s8 *)this + 0x3B4) = (s32) ((lbl_805D8B58 + *(f32 *)((s8 *)arg1 + 8)) / lbl_805D8B5C);
}

#pragma push
#pragma fp_contract on
void TBoss4Type2::calc_target_position() {
    Obj_80053AD4 *arg0 = (Obj_80053AD4 *)this;
    arg0->f3B8 = lbl_805D8B5C * (lbl_805D8B60 + (f32)arg0->i3B0) - lbl_805D8B58;
    arg0->f3BC = lbl_805D8B20;
    arg0->f3C0 = lbl_805D8B5C * (lbl_805D8B60 + (f32)arg0->i3B4) - lbl_805D8B58;
}
#pragma pop

void TBoss4Type2::calc_scale_slot_indices(s32 *a, s32 *b) {
    f32 s;
    s32 v;
    v = ((S_80053B48 *)this)->f3a0 + (s32)(lbl_805D8B64 * calc_boss4_scale__10TObjPlayerFi(((S_80053B48 *)this)));
    v += 1;
    if (v >= 4) {
        v -= 4;
    }
    *a = v;
    s = calc_boss4_scale__10TObjPlayerFi(this);
    if (s <= lbl_805D8B68) {
        *b = 0;
    } else if (s <= lbl_805D8B6C) {
        *b = 1;
    } else {
        *b = 2;
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

void TBoss4Type2::send_darkfalz_code(s32 arg1, s32 arg2, s32 arg3) {
    u8 *arg0 = (u8 *)this;
    u8 *boss4_dark_falz;
    boss4_dark_falz = (u8 *)(*(u8 **)((s8 *)arg0 + 0x38C));
    if (boss4_dark_falz != NULL) {
        ((TBoss4DarkFalz *)boss4_dark_falz)->send_code_25_4(((((((((((((*(s32 *)((s8 *)arg0 + 0x3A0) * 0x10) & 0x30 & ~0xF) | (arg1 & 0xF)) & ~0xC0) | ((arg2 << 6) & 0xC0)) & ~0x300) | ((*(s32 *)((s8 *)arg0 + 0x3A8) << 8) & 0x300)) & ~0xC00) | ((arg3 << 0xA) & 0xC00)) & ~0xF000) | ((*(s32 *)((s8 *)arg0 + 0x3B0) << 0xC) & 0xF000)) & ~0xF0000) | ((*(s32 *)((s8 *)arg0 + 0x3B4) << 0x10) & 0xF0000));
    }
}

void TBoss4Type2::send_state_to_target(s32 arg1) {
    Obj_80053CEC *self = (Obj_80053CEC *)this;
    if (self->target != 0) {
        ((TBoss4DarkFalz *)(self->target))->send_code_25_4((arg1 & 0xF) | ((self->f3a0 & 3) << 4) | ((self->f3a0 & 3) << 6) | ((self->f3a8 & 3) << 8) | ((self->f3a8 & 3) << 10) | ((self->f3b0 & 0xF) << 12) | ((self->f3b4 & 0xF) << 16));
    }
}

#pragma push
#pragma fp_contract on
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
#pragma pop

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
    for (p = 0; p < lbl_805D586C; p++) {
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
                ((TUnk_804B9870 *)pl)->set_position_from(&pos);
                ((TBoss4DarkFalz *)pl)->save_position();
                ((TUnk_804AF8A0 *)pl)->set_indexed_flags(0, 0x900000);
                *(u32 *)(pl + 0x30) &= ~0x20;
            }
        }
    }
}

f32 calc_wave_offset__11TBoss4Type2Ff(f32 farg0) {
    return lbl_805D8B60 * (lbl_805D8B18 - cos_table_lookup((s32) (lbl_805D8B74 * farg0)));
}

void TBoss4Type2::calc_scaled_field(s32 arg1, s32 arg2) {
    *(s32 *)((s8 *)this + 0x60) = (s32) (arg1 + (s32) (*(f32 *)((s8 *)this + 0x39C) * (f32) angle_diff_s16(arg1, arg2)));
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

void TBoss4Type2::set_state(s32 arg1) {
    s32 i;
    void **p;

    ((Boss_800542B0 *)this)->state = arg1;
    for (i = 8; i < 13; i++) {
        p = &((Boss_800542B0 *)this)->items[i];
        if (*p != NULL) {
            TBoss4Type2::request_destroy((u32)(*p));
            *p = NULL;
        }
    }
    ((Boss_800542B0 *)this)->f3d0 = 5;
    ((TBoss4Type2 *)((Boss_800542B0 *)this))->set_motion_index(lbl_80485C48[((Boss_800542B0 *)this)->state].f4);
    Act_800542B0 f = lbl_80485C48[((Boss_800542B0 *)this)->state].enter;
    if (f) {
        (((Boss_800542B0 *)this)->*f)();
    }
}

u8 *TBoss4Type2__sub_80054384(void *self, s32 i, s32 j) {
    return lbl_8048615C[i] + (j - 1) * 0x4000;
}

#pragma push
#pragma opt_propagation off
void TBoss4Type1::draw_parts() {
    u8 *arg0 = (u8 *)this;
    s32 i;
    s32 off;
    s32 a;
    TObjPlayer::set_global_flag();
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
    TObjPlayer::clear_global_state();
    *(s32 *)((s8 *)arg0 + 0x3D4) = 0;
}
#pragma pop

void TBoss4Type2::set_motion_index(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    if (arg1 != -1) {
        *(s32 *)((s8 *)arg0 + 0x3E4) = arg1;
        *(f32 *)((s8 *)arg0 + 0x3E8) = (f32) lbl_805D8B20;
        *(s32 *)((s8 *)arg0 + 0x3F0) = (s32) *(s32 *)((s8 *)((u8 *)&boss4_type1_motion_states.value + (arg1 << 5)) + 0);
    }
}

#pragma push
#pragma opt_common_subs off
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
#pragma pop

void TBoss4Type1::render_effects() { toggle_particle_effect__10TObjPlayerFv(this); push_matrix(); post_translate_matrix((char*)this + 0x38); rotate_matrix_y((void*)0, *(void**)((char*)this + 0x60)); this->draw_parts(); pop_matrix(); TParticleCtrl::end_effect_render(); }

void TBoss4Type1::snapshot_position() {
    u8 *arg0 = (u8 *)this;
    VecCopy__FP3VecPC3Vec(arg0 + 0x2FC, arg0 + 0x38);
    *(f32 *)((s8 *)arg0 + 0x300) = (f32) (*(f32 *)((s8 *)arg0 + 0x300) + lbl_805D8B24);
}

void render_and_update_effects__10TObjPlayerFPv(void* p) { ((TBoss4Type1 *)p)->push_players_out_of_colliders(); ((TBoss4Type1 *)p)->render_effects(); ((TBoss4Type1 *)p)->update_follow_camera_offsets(); }

#pragma push
#pragma opt_common_subs off
void TBoss4Type2__sub_80054738(Obj_80054738 *self) {
    Act_800542B0 act;
    if (((TBoss4DarkFalz *)(self->x38c))->is_field378_zero() != 0) {
        act = lbl_80485C48[self->x374].a;
        if (act) {
            (((Boss_800542B0 *)self)->*act)();
        }
    }
    act = lbl_80485C48[self->x374].b;
    if (act) {
        (((Boss_800542B0 *)self)->*act)();
    }
    ((TBoss4Type1 *)self)->update_boss4_phase_timer();
    ((TBoss4Type1 *)self)->snapshot_position();
    ((TBoss4Type1 *)self)->sub_80053D4C();
    ((TObjPlayer *)self)->update_collisions();
    submit_cursor_candidate(self, -1);
    ((TBoss4Type1 *)self)->sub_80053670();
    ((TBoss4Type1 *)self)->sub_80053440();
    {
        f32 x = self->x3dc;
        self->x3dc = x + lbl_805D8B80;
        if (self->x3dc < lbl_805D8B20) {
            self->x3dc = lbl_805D8B20;
        }
    }
    self->x3e0 = (f32)self->x32c / (f32)self->x33e;
}
#pragma pop

void request_state_3__11TBoss4Type2FPv(TBoss4Type2 *boss4_type2) {
    s32 temp_r0;

    temp_r0 = *(s32 *)((s8 *)boss4_type2 + 0x374);
    if ((temp_r0 != 3) && (temp_r0 != 4)) {
        boss4_type2->set_state(3);
    }
}

void fn_800548E4(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 0x30) = (s32) (*(s32 *)((s8 *)arg0 + 0x30) & 0xFFFFFDFF);
    *(s32 *)((s8 *)arg0 + 0x3D4) = 1;
    *(f32 *)((s8 *)arg0 + 0x3DC) = (f32) lbl_805D8B18;
    ((s32 (*)(s32, u32, s16, s32))play_sound_effect)(0x4003A822, (u32)(arg0 + 0x38), 0, 1);
}

S_80054938 *__dt__11TBoss4Type1Fv(S_80054938 *o, s16 flag) {
    s32 i;
    s32 j;
    if (o != 0) {
        o->vt = __vt__11TBoss4Type1;
        fn_8004AA04(o->f378);
        for (i = 0; i < 13; i++) {
            if (o->parts[i] != 0) {
                TBoss4Type2::request_destroy((u32)o->parts[i]);
                o->parts[i] = 0;
            }
        }
        for (j = 0; j < 3; j++) {
            TObjFish::init_state_1(o->fx[j]);
            o->fx[j] = 0;
        }
        TObjFish::init_state_1(o->f480);
        o->f480 = 0;
        free_collision_body_parts(o);
        o->f394 = 0;
        __dt__9TObjEnemyFv((TObjEnemy *)o, 0);
        if (flag > 0) {
            __dl__7TObjectFPv(o);
        }
    }
    return o;
}

}
struct VBase_80054A1C { char pad[0x18]; };
struct VObj_80054A1C : VBase_80054A1C {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4();
    virtual void m5(); virtual void m6(); virtual void m7(); virtual void m8(); virtual void m9();
    virtual void m10(); virtual void m11(); virtual void m12(); virtual void m13(); virtual void m14();
    virtual void m15(); virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23(); virtual void m24();
    virtual void m25(); virtual void m26(); virtual void m27(); virtual void m28(); virtual void m29();
    virtual void m30(); virtual void m31(); virtual void m32(); virtual void m33(); virtual void m34();
    virtual void m35(); virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39();
    virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43(); virtual void m44();
    virtual void m45(); virtual void m46(); virtual void m47(); virtual void m48(); virtual void m49();
    virtual void m50(); virtual void m51(); virtual void m52(); virtual void m53(); virtual void m54();
    virtual void m55(); virtual void m56(); virtual void m57(); virtual void m58(); virtual void m59();
    virtual void m60(); virtual void m61(); virtual void m62(); virtual void m63(); virtual void m64();
    virtual void m65(); virtual void m66(); virtual void m67(); virtual void m68(); virtual void m69();
    virtual void m70(); virtual void m71(); virtual void m72(); virtual void m73(); virtual void m74();
    virtual void m75(); virtual void m76(); virtual void m77(); virtual void m78();
    virtual void m79(void *);
    virtual void m80();
};

extern "C" {
struct Seg_80054A1C { u8 b[0x18]; };
struct Self_80054A1C {
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
    u8 pad3b0[0x3C4 - 0x3B0];
    s32 f3C4;
    s32 f3C8;
    s32 f3CC;
    s32 f3D0;
    s32 f3D4;
    s32 f3D8;
    f32 f3DC;
    f32 f3E0;
    u8 pad3e4[0x3EC - 0x3E4];
    f32 f3EC;
    u8 pad3f0[0x3F8 - 0x3F0];
    s32 a3F8[13];
    s32 a42C[3];
    Seg_80054A1C a438[3];
    s32 f480;
    u8 v484[0xC];
};

void init_model_node_tables(void *, void *, int);
s32 TObjFish__sub_800E3124(u8 *list, s32 vecs);
s32 init_collision_body_parts(void *, void *, int);
extern s32 boss4_type1_emitter_id_table[];
extern u8 boss4_type1_model_node_table[];
extern s32 TBoss4Type1__name;
extern const f32 lbl_805D8B84;
Self_80054A1C *TBoss4Type1__ct(Self_80054A1C *self, s32 arg1, s32 *arg2);
#pragma push
#pragma opt_loop_invariants off
Self_80054A1C *TBoss4Type1__ct(Self_80054A1C *self, s32 parent, s32 *arg2) {
    s32 i;
    s32 j;

    __ct__9TObjEnemyFP7TObject(self, (void*)parent);
    self->vt = __vt__11TBoss4Type1;
    self->f0 = TBoss4Type1__name;
    ((TUnk_804806E8 *)self)->add_flags_2e4(8);
    self->f38C = arg2[0];
    ((VObj_80054A1C *)self)->m79(arg2 + 1);
    ((VObj_80054A1C *)self)->m80();
    self->f390 = TBoss4Uro::get_instance_count();
    self->f24 = 0;
    self->f34 = 0;
    VecCopy__FP3VecPC3Vec(self->v38, lbl_80486150);
    self->f60 = 0;
    ((void *(*)(void *, void *))VecCopy__FP3VecPC3Vec)(self->v44,
        ((void *(*)(void *, void *))VecCopy__FP3VecPC3Vec)(self->v50,
            ((void *(*)(void *, void *))VecCopy__FP3VecPC3Vec)(self->v74, self->v38)));
    self->f394 = init_collision_body_parts(self, lbl_80485E2C, 3);
    VecCopy__FP3VecPC3Vec(self->v2FC, self->v38);
    self->f308 = self->f30C = self->f310 = lbl_805D8B20;
    self->f2A8 = 0;
    ((TObjEnemy *)self)->bind_enemy_combat_stats((u8 *)(TLobby::register_boss(0x36)), (u8 *)(TLobby::dispatch_shared_handler_b(0x36)), (u8 *)(TLobby::register_object(0x36)));
    self->f33E = self->f32C;
    ((TBoss3Volopt *)self)->reset_photon_effect();
    ((TObjEnemy *)self)->set_param(0x2F);
    self->f3EC = lbl_805D8B84;
    for (i = 0; i < 3; i++) {
        self->a42C[i] = TObjFish__sub_800E3124((u8 *)lbl_804860F0, (s32)&self->a438[i]);
    }
    self->f480 = TObjFish__sub_800E3124((u8 *)lbl_80486120, (s32)self->v484);
    for (j = 0; j < 8; j++) {
        self->a3F8[j] = (s32)create_particle_emitter(self->v38, boss4_type1_emitter_id_table[j]);
    }
    for (; j < 13; j++) {
        self->a3F8[j] = 0;
    }
    init_model_node_tables(self->f378, boss4_type1_model_node_table, 7);
    self->f3A4 = 0;
    self->f3A0 = 0;
    self->f3AC = 1;
    self->f3A8 = 1;
    self->f3CC = *(f32 *)dispatch_shared_handler_a__6TLobbyFl(0x36);
    if (self->f3CC < 1 || self->f3CC > 60) {
        self->f3CC = 25;
    }
    self->f3CC = (f32)self->f3CC * lbl_805D8B78;
    self->f3C4 = *(s32 *)(dispatch_shared_handler_a__6TLobbyFl(0x39) + 0x18);
    if (self->f3C4 < 1) {
        self->f3C4 = 1;
    } else if (self->f3C4 > 6) {
        self->f3C4 = 6;
    }
    self->f3C8 = 0;
    self->f3D0 = 5;
    self->f3D4 = 0;
    self->f3D8 = self->f32C / 2;
    self->f3DC = lbl_805D8B20;
    self->f3E0 = lbl_805D8B18;
    ((TBoss4Type2 *)self)->set_state(0);
    return self;
}

#pragma pop

extern const f32 lbl_805D8B88;

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

    power = (f32)*(s32 *)((u8 *)TLobby::dispatch_shared_handler_a(0x36) + 0x20);
    spot = (Vec_80053914 *)&TBoss4Type2__tenchu_furu_array;
    for (i = 0; i < 0x40; i++) {
        TBoss4Type2 *effect = (TBoss4Type2 *)spawn_particle_effect(spot, (s32)lbl_80485B08[i & 1]);
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
        if (TBoss4Type3__sub_8005254C(obj_getField1c(player)) == 0) {
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
    s32 var_r31;
    s32 var_r4;

    var_r31 = __nw__7TObjectFUl(0x49C);
    if (var_r31 != 0) {
        var_r4 = __nw__7TObjectFUl(0x20);
        if (var_r4 != 0) {
            var_r4 = TObjControl__ct(var_r4, tl_04);
        }
        var_r31 = ((s32 (*)(s32, s32, s32))TBoss4Type1__ct)(var_r31, var_r4, arg0);
    }
    return var_r31;
}

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

void TBoss4Type2__sub_80055300(void) { ((int (*)(s32, f32))TBoss4Type2__sub_80054FC0)(0, lbl_805D8B20); }

}
