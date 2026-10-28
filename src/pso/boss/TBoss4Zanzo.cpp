#pragma readonly_strings on
#include "types.h"
#include "pso/system/PadRumble.h"
#include "pso/boss/TBoss4Type3_800524E8.h"
#include "pso/boss/TBoss4Zanzo.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/player/TUnk_804806E8.h"
#include "pso/boss/TUnk_80486924.h"
#include "pso/TBoss4Zanzo.h"
#include <stddef.h>
#include "pso/TObjBs4CutAtk.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/TParticleCtrl.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/boss/TBoss4DarkFalz.h"
#include "pso/boss/TBoss4Type3.h"
#include "pso/boss/TBoss4Uro.h"
#include "pso/boss/TBoss6PlotFalz.h"
#include "pso/boss/TObjDFRecover.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/enemy/TObjEneLappy.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TNowLoading.h"
#include "pso/misc/TTecGrants.h"
#include "pso/misc/TTecMegid.h"
#include "pso/misc/TTecRaFoie.h"
#include "pso/misc/TTecResta.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
extern "C" TObjEnemy *__ct__9TObjEnemyFP7TObject(void *, void *);

struct Arr_800579A0 { u8 pad[0x42C]; s32 f42C[8]; };

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
struct Vec_80055F5C { f32 x, y, z; };

struct Vec_80055BC0 { f32 x, y, z; };

struct Obj_80055BC0 { u8 pad[0x450]; Vec_80055BC0 f450; Vec_80055BC0 f45c; };

extern u8 lbl_80487150[];
extern "C" {
s32 add_radar_scaled_marker(void *, u32, int, int, f32);
s32 vec3_add_to(void *, void *);
f32 vector_length(void *);
s32 subtract_vector(void *, void *);
s32 normalize_vector(void *);
extern u32 boss4_type3_radar_marker_colors[];
extern const f32 TBoss4Type3__data_805D8C40;
u32 spawn_particle_effect(void *, int);
u32 create_particle_emitter(void *, int);
s32 play_sound_effect(int, void *, int, int);
f64 atan2_float(f32, f32);
u8 * dispatch_shared_handler_a__6TLobbyFl(s32);

void TBoss4Type2__sub_80057128(void *arg0);
s32 angle_diff_s16(int, int);
s32 play_persistent_sound(int, void *, void *, int, int);
s32 create__11TTecRaBartaFPvPvPvPv(void *, void *, void *, s32);
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
extern s32 boss4_type2_attack_pattern_table[];
extern s32 game_difficulty_selection;
s32 TBoss4Type2__sub_80054DA8();
s32 create_all_tenchu_furu__11TBoss4Type2Fi();
struct ByteBlock_C { u8 bytes[0xc]; };

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

struct Obj_80056F38 { u8 pad[0x38C]; void *target; u8 pad390[0x10]; s32 f3a0; u8 pad3a4[8]; s32 f3ac; s32 f3b0; };

struct Obj_80056F90 { u8 pad[0x38C]; void *target; u8 pad390[0x10]; s32 f3a0; u8 pad3a4[8]; s32 f3ac; s32 f3b0; u8 pad3b4[0x10]; u16 f3c4; };

struct Obj_80056FEC { u8 pad[0x38C]; void *target; u8 pad390[0x10]; s32 f3a0; u8 pad3a4[8]; s32 f3ac; s32 f3b0; u8 pad3b4[0x10]; u16 f3c4; };

struct Obj_80056EA8 { u8 pad[0x3A0]; s32 yaw; s32 turn_yaw; s32 goal_yaw; s32 grid_x; s32 grid_z; u8 pad3b4[0x10]; u16 target_player; };

struct Obj_80057224 { u8 pad[0x3A0]; s32 f3a0; };

struct S_800578E8 {
    u8 pad0[0x18];
    void *vt;
    u8 pad1c[0x378 - 0x1c];
    u8 f378[0x1c];
    s32 f394;
    u8 pad398[0x42c - 0x398];
    void *ptr[8];
    void *f44c;
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

struct Vec_8005676C { f32 x, y, z; };

struct Zanzo_8005676C {
    Vec_8005676C pos;
    s32 f0c;
    s32 f10;
    s32 f14;
    s32 f18;
    f32 f1c;
    f32 f20;
    f32 f24;
    s32 f28;
};

struct Row_8005676C {
    s32 a;
    s32 b;
    s32 c[2];
};

struct Obj_8005676C {
    u8 pad0[0x38];
    Vec_8005676C pos;
    u8 pad44[0x60 - 0x44];
    s32 f60;
    u8 pad64[0x390 - 0x64];
    s32 f390;
    u8 pad394[0x3c8 - 0x394];
    s32 f3c8;
    u8 pad3cc[0x3d0 - 0x3cc];
    f32 f3d0;
};

struct Vec_8005683C { f32 x, y, z; };

struct Bishi_8005683C {
    s32 f0;
    s16 id;
    s16 f6;
    s16 f8;
    s16 id2;
    s16 f0c;
    u8 pad0e[6];
    Vec_8005683C pos;
    u8 pad2c[0x20];
};

struct Ofs_8005683C { f32 x, z; };

struct Obj_8005683C {
    u8 pad0[0x38c];
    s32 f38c;
};

struct Obj_80056A54 {
    u8 pad0[0x32c];
    s16 f32c;
    u8 pad32e[0x3ec - 0x32e];
    s32 f3ec;
};

struct Grid_80056A54 {
    f32 x, y, z;
};

struct Row_80057270 {
    s32 a;
    s32 b;
    s32 c[2];
};

struct Obj_80057270 {
    u8 pad0[0x390];
    s32 f390;
    u8 pad394[0x3c0 - 0x394];
    f32 f3c0;
    u8 pad3c4[0x3c8 - 0x3c4];
    s32 f3c8;
    u8 pad3cc[0x3d0 - 0x3cc];
    f32 f3d0;
    u8 pad3d4[0x3e4 - 0x3d4];
    s32 f3e4;
    u8 pad3e8[0x3f0 - 0x3e8];
    f32 f3f0;
    f32 f3f4;
    u8 pad3f8[0x44c - 0x3f8];
    s32 f44c;
};

struct Vec_80056C30 { f32 x, y, z; };

struct O_80056C30 {
    u8 pad0[0x38];
    Vec_80056C30 pos;
};

typedef char RecoveredGlobal_80054530_lbl_80485EC8_size[sizeof(RecoveredGlobal_80054530_lbl_80485EC8) == 0x1E0 ? 1 : -1];

typedef char RecoveredGlobal_8005455C_lbl_80485EC8_size[sizeof(RecoveredGlobal_8005455C_lbl_80485EC8) == 0x1E0 ? 1 : -1];

struct Vec_80058848 { f32 x, y, z; };

struct O_80058848 {
    u8 pad0[0x38];
    Vec_80058848 pos;
    u8 pad44[0x398 - 0x44];
    s32 f398;
};

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

struct Stack_80059450 {
    s32 sp8;
    s32 spC;
    s32 sp10;
    s32 sp14;
    s32 sp18;
    s32 sp1C;
    s32 sp20;
    s32 sp24;
    s32 sp28;
    s32 sp2C;
    s32 sp30;
    s32 sp34;
};

struct RecoveredGlobal_80059450_lbl_80437854 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_80059450_lbl_80437860 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_80059450_lbl_8043786C {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_80059450_lbl_80437878 {
    s32 value;
    u8 remaining[0xC];
};

struct Obj_80059EA8 { u8 pad[0x38C]; void *target; u8 pad390[0x10]; s32 f3a0; u8 pad3a4[4]; s32 f3a8; u8 pad3ac[0xC]; u16 f3b8; u16 f3ba; };

struct Obj_80059F04 { u8 pad[0x38C]; void *target; u8 pad390[0x10]; s32 f3a0; u8 pad3a4[4]; s32 f3a8; u8 pad3ac[0xC]; u16 f3b8; u16 f3ba; };

struct Obj_80059F64 { u8 pad[0x38C]; void *target; u8 pad390[0x10]; s32 f3a0; u8 pad3a4[4]; s32 f3a8; u8 pad3ac[0xC]; u16 f3b8; u16 f3ba; };

struct Obj_8005A2A4 { u8 pad[0x404]; void *parts[13]; };

struct Ply_80059ABC { u8 pad[0x38]; f32 f38; u8 pad3c[4]; f32 f40; };

class TBoss4Type3_8005A398 { public: u8 pad[0x374]; s32 f374; };

union MemberAction_8005A398 { s32 words[3]; void (TBoss4Type3_8005A398::*action)(); };

struct Row_8005A398 { s32 f0; s32 f4; s32 f8; s32 fc; s32 f10; u8 pad[0x18]; };

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

typedef char RecoveredGlobal_80059450_lbl_80437854_size[sizeof(RecoveredGlobal_80059450_lbl_80437854) == 0xC ? 1 : -1];

typedef char RecoveredGlobal_80059450_lbl_80437860_size[sizeof(RecoveredGlobal_80059450_lbl_80437860) == 0xC ? 1 : -1];

typedef char RecoveredGlobal_80059450_lbl_8043786C_size[sizeof(RecoveredGlobal_80059450_lbl_8043786C) == 0xC ? 1 : -1];

typedef char RecoveredGlobal_80059450_lbl_80437878_size[sizeof(RecoveredGlobal_80059450_lbl_80437878) == 0x10 ? 1 : -1];

struct RecoveredGlobal_8005A678_TBoss4Type3__data_80486FC8 {
    s32 value;
    u8 remaining[0xC4];
};

struct RecoveredGlobal_8005A6A4_TBoss4Type3__data_80486FC8 {
    s32 value;
    u8 remaining[0xC4];
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

typedef char RecoveredGlobal_8005A678_TBoss4Type3__data_80486FC8_size[sizeof(RecoveredGlobal_8005A678_TBoss4Type3__data_80486FC8) == 0xC8 ? 1 : -1];

typedef char RecoveredGlobal_8005A6A4_TBoss4Type3__data_80486FC8_size[sizeof(RecoveredGlobal_8005A6A4_TBoss4Type3__data_80486FC8) == 0xC8 ? 1 : -1];

struct Obj_80056DF0 { u8 pad0[0x3AC]; s32 i3AC; s32 i3B0; f32 f3B4; f32 f3B8; f32 f3BC; };

struct Vec_80059C20 { f32 x, y, z; };

struct Dmg_8005B218 { s32 type; f32 val; };

f32 calc_boss4_scale__10TObjPlayerFi(void *);
void * get_player_data__10TObjPlayerFi(s32 i);
u16 get_entity_id(void *);
s32 is_split_screen();
s32 get_bml_motion(s32, s32);
s32 TObjFish__sub_8001EDB0(s32, s32);
s32 get_bml_model(s32, s32);
s32 fn_80044330(void *);
void fn_8004AA04(void *);
s32 pick_random_target_player__11TBoss4Type3Fv(void);
s32 TBoss4DarkFalz__sub_8004AF5C(s32, s16 *, s16 *);
s32 TBoss4DarkFalz__sub_8004B4F0(void *, void *);
s32 TObjPlayer__sub_80052390(f32);
s32 TBoss4Type2__sub_80055300();
void find_target_pos__11TBoss4Type2FPvPv(O_80056C30 *self, Vec_80056C30 *out);
S_800578E8 * __dt__13TUnk_80486924Fv(S_800578E8 *o, s16 flag);
int TBoss4Type3__sub_800599F4(void*, void*, void*);
void TBoss4Type3__sub_80059EA8(Obj_80059EA8 *self, s32 arg1, s32 arg2);
void TBoss4Type3__sub_80059F64(Obj_80059F64 *self, s32 arg1);
void TBoss4Type3__sub_8005A150(void);
void TBoss4Type3__sub_8005A86C(void* p);
S_8005AD50 * __dt__11TBoss4Type3Fv(S_8005AD50 *o, s16 flag);
s32 TBoss4Type3__ct(s32, s32, s32);
void * __ct__13TObjBs4CutAtkFv(void *arg0, s32 arg1, s32 arg2, s32 arg3);
s32 create__11TBoss4BishiFi(void *);
s32 request_follow_camera_offsets(void *, void *, int);
int toggle_particle_effect__10TObjPlayerFv(void*);
void __dt__11TBoss4Type3FPvs(void *, s16);
s32 clear_render_callback__8TObjFishFv(s32);
s32 TObjControl__ct(s32, s32);
void __dt__9TObjEnemyFv(void *, s32);
s32 approach_angle_limited(s32, s32, s32);
void free_collision_body_parts(void *);
Ply_80059ABC * get_player_by_client_id(u16);
s32 TObjEneRe4Sorcerer__sub_801E3F1C(f32, f32);
void __dl__7TObjectFPv(void *);
void * __nw__7TObjectFUl(int);
void __ct__7TObjectFP7TObject(void *);
s32 rand();
s32 matrix_mult_vec(int, void *, void *);
s32 set_matrix_identity(int);
s32 rotate_matrix_y(int, int);
s32 push_matrix();
f32 post_translate_matrix(void *);
f32 xyz_distance(Vec_80056C30 *, Vec_80056C30 *);
s32 draw_model_motion(int, int, f32);

extern u8 TBoss4DarkFalz__data_804FF1E8[];
extern RecoveredGlobal_8005A678_TBoss4Type3__data_80486FC8 TBoss4Type3__anim_state_table;
extern const f32 TBoss4Type3__data_805D8C34;
extern s32 __vt__11TBoss4Zanzo[];
extern void* __vt__13TObjBs4CutAtk[];
extern s32 boss4_type3_effect_ids[];
extern RecoveredGlobal_80059450_lbl_80437854 lbl_80437854;
extern RecoveredGlobal_80059450_lbl_80437860 lbl_80437860;
extern RecoveredGlobal_80059450_lbl_8043786C lbl_8043786C;
extern RecoveredGlobal_80059450_lbl_80437878 boss4_type3_follow_camera_offsets;
extern const f64 lbl_80437890[];
extern Ofs_8005683C bishi_spawn_offset_table[];
extern u8 lbl_80486924[];
extern Row_8005A398 boss4_type3_states[];
extern u8 lbl_80486FB0[];
extern u8 boss4_type3_index_table[];
extern Vec_80059C20 boss4_type3_default_position;
extern Vec_80059C20 boss4_type3_interp_origin_vec;
extern u8 __vt__11TBoss4Type3[];
extern s32 TObjBs4CutAtk_name;
extern s32 lbl_805D4D80;
extern u8 lbl_805D4D84;
extern s32 local_client_id;
extern s32 lbl_805D586C;
struct Def_804867C8 { s32 value; s32 remaining[39]; };

f32 get_random_float__21TObjEneMe3ShinowaRealFv(f32);
void init_model_node_tables(void *, void *, int);
s32 TObjFish__sub_800E3124(void *, void *, f32);
s32 init_collision_body_parts(void *, void *, int);
const char *boss4_type2_class_name = "TBoss4Type2";

struct TBoss4Type2Action {
    const char *name;
    s32 attack_index;
    void (TBoss4Type2::*enter)();
    void (TBoss4Type2::*update_idle)();
    void (TBoss4Type2::*update)();
};
static TBoss4Type2Action boss4_type2_action_table[14] = {
    {"APPEAR", 0, &TBoss4Type2::appear_enter, &TBoss4Type2::appear_idle, &TBoss4Type2::appear_update},
    {"WAITNEXT", 0, 0, &TBoss4Type2::wait_next_idle, 0},
    {"WAITKILL", -1, 0, 0, 0},
    {"DEAD", 2, &TBoss4Type2::dead_enter, &TBoss4Type2::dead_idle, &TBoss4Type2::dead_update},
    {"MOVE", 0, &TBoss4Type2::move_enter, &TBoss4Type2::move_idle, &TBoss4Type2::move_update},
    {"JISIN", 4, &TBoss4Type2::jisin_enter, &TBoss4Type2::jisin_idle, &TBoss4Type2::jisin_update},
    {"BEAM_L", 0, &TBoss4Type2::beam_enter, &TBoss4Type2::beam_idle, &TBoss4Type2::beam_update},
    {"BEAM_R", 0, &TBoss4Type2::beam_enter, &TBoss4Type2::beam_idle, &TBoss4Type2::beam_update},
    {"TENCHU", 8, &TBoss4Type2::tenchu_enter, &TBoss4Type2::tenchu_idle, &TBoss4Type2::tenchu_update},
    {"MD_STOP1", 0, &TBoss4Type2::md_stop1_enter, &TBoss4Type2::md_stop_idle, &TBoss4Type2::md_stop_update},
    {"MD_STOP2", 0, &TBoss4Type2::md_stop2_enter, &TBoss4Type2::md_stop_idle, &TBoss4Type2::md_stop_update},
    {"MD_STOP3", 0, &TBoss4Type2::md_stop3_enter, &TBoss4Type2::md_stop_idle, &TBoss4Type2::md_stop_update},
    {"MD_STOP4", 0, &TBoss4Type2::md_stop4_enter, &TBoss4Type2::md_stop_idle, &TBoss4Type2::md_stop_update},
    {"MD_RECOVER", 3, &TBoss4Type2::md_recover_enter, &TBoss4Type2::md_recover_idle, &TBoss4Type2::md_recover_update},
};
static u32 boss4_type2_collision_body_parts[11] = {
    0, 0x42700000, 0, 0x42200000, 0, 0, 0x8003, 0, 0, 0, 0,
};
__declspec(section ".data") s32 boss4_zanzo_bml_index_table[2] = {
    0xb, 0xa,
};
}
u32 drain_player_hp(s32 id, u32 arg1);
Def_804867C8 TBoss4Type2__attack_pattern_table = {
    0x0, {
        0x0, 0x52, 0x51, 0x2, 0x0, 0xd, 0xc, 0x1, 0x0, 0x12, 0x11, 0x2, 0x5, 0x31, 0x30, 0x2, 0x0, 0x33, 0x32, 0x2, 0x0, 0x3f, 0x3e, 0x2, 0x0, 0x3, 0x2, 0x2, 0x0, 0x7, 0x6, 0x2, 0x9, 0x52, 0x44, 0x2, 0x0, 0x52, 0x3e,
    },
};
void *lbl_80486868[16] = {
    (void *)0xf, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x55, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x6b, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
static f32 boss4_type2_start_position[3] = {0.0f, -50.0f, -300.0f};
static f32 boss4_type2_next_action_weights_a[4] = {0.3f, 0.25f, 0.25f, 0.2f};
static s32 boss4_type2_next_actions_a[4] = {5, 6, 7, 13};
static f32 boss4_type2_next_action_weights_b[3] = {0.4f, 0.3f, 0.3f};
static s32 boss4_type2_next_actions_b[3] = {5, 6, 7};
Ofs_8005683C bishi_spawn_offset_table[3] = {{0.0f, -12.5f}, {-10.75f, 6.25f}, {10.75f, 6.25f}};
__declspec(section ".data") s32 boss4_type2_attack_pattern_table[2] = {6, 7};

struct Vec_80057598 { f32 x, y, z; };

static const s32 boss4_type2_emitter_ids[2] = {0x144, 0x145};
static const s32 boss4_type2_model_node_table[18] = {
    0xB, 3, 0, 0xA, 5, 0, 0xA, 0x60, 0, 0xA, 0x63, 0, 0xA, 0x65, 0, 0xA, 0x68, 0,
};
static const Vec_80057598 boss4_type2_follow_camera_offset_a = {0.0f, 19.8f, -5.0f};
static const Vec_80057598 boss4_type2_follow_camera_offset_b = {0.0f, 15.43f, 55.42f};
const char *TBoss4Zanzo__name = "TBoss4Zanzo";
extern s32 model_render_flags;
extern s32 tl_04;

extern "C" {
#pragma push
#pragma fp_contract on

void render__11TBoss4ZanzoFv(u8 *arg0) {
    f32 temp_f31;
    f32 temp_f5;
    temp_f5 = *(f32 *)((s8 *)arg0 + 0x3C);
    temp_f31 = (((f32) *(s32 *)((s8 *)arg0 + 0x48) / (f32) *(s32 *)((s8 *)arg0 + 0x44)) * (*(f32 *)((s8 *)arg0 + 0x40) - temp_f5)) + temp_f5;
    if (!(temp_f31 <= 0.01f)) {
        push_matrix();
        TObjPlayer::set_global_flag();
        post_translate_matrix(arg0 + 0x1C);
        rotate_matrix_y(0, (int) (*(s32 *)((s8 *)arg0 + 0x28)));
        TObjFish::set_global_param((int) (*(s32 *)((s8 *)arg0 + 0x2C)));
        TObjPlayer__sub_80052390(temp_f31);
        draw_model_motion((int) (*(s32 *)((s8 *)arg0 + 0x30)), (int) (*(s32 *)((s8 *)arg0 + 0x34)), (f32) (*(f32 *)((s8 *)arg0 + 0x38)));
        TObjPlayer::sync_player_globals();
        TObjPlayer::clear_global_state();
        pop_matrix();
    }
}
extern int fold_flush_0;
#pragma pop

void run_task__11TBoss4ZanzoFv(void *arg0) {
    s32 temp_r4;

    temp_r4 = *(s32 *)((s8 *)arg0 + 0x48) + 1;
    *(s32 *)((s8 *)arg0 + 0x48) = temp_r4;
    if (temp_r4 >= (s32) *(s32 *)((s8 *)arg0 + 0x44)) {
        ((s32 (*)(void))queue_destruction__7TObjectFv)();
    }
}

TBoss4Zanzo::~TBoss4Zanzo() {}

void *__ct__11TBoss4ZanzoFv(void *object, void *arg1, void *arg2) {
    __ct__7TObjectFP7TObject(object);
    *(s32 **)((s8 *)object + 0x18) = __vt__11TBoss4Zanzo;
    *(const char **)((s8 *)object + 0x0) = TBoss4Zanzo__name;
    ((void (*)(void *, void *))fn_8005586C)((void *)((char *)object + 28), arg2);
    *(u32 *)((s8 *)object + 0x48) = 0;
    return object;
}

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void fn_8005586C(u8 *arg0, u8 *arg1) {
    *(ByteBlock_C *)(arg0) = *(const ByteBlock_C *)(arg1);
    *(s32 *)((s8 *)arg0 + 0xC) = (s32) *(s32 *)((s8 *)arg1 + 0xC);
    *(s32 *)((s8 *)arg0 + 0x10) = (s32) *(s32 *)((s8 *)arg1 + 0x10);
    *(s32 *)((s8 *)arg0 + 0x14) = (s32) *(s32 *)((s8 *)arg1 + 0x14);
    *(s32 *)((s8 *)arg0 + 0x18) = (s32) *(s32 *)((s8 *)arg1 + 0x18);
    *(f32 *)((s8 *)arg0 + 0x1C) = (f32) *(f32 *)((s8 *)arg1 + 0x1C);
    *(f32 *)((s8 *)arg0 + 0x20) = (f32) *(f32 *)((s8 *)arg1 + 0x20);
    *(f32 *)((s8 *)arg0 + 0x24) = (f32) *(f32 *)((s8 *)arg1 + 0x24);
    *(s32 *)((s8 *)arg0 + 0x28) = (s32) *(s32 *)((s8 *)arg1 + 0x28);
}
extern int fold_flush_1;
#pragma pop

void *TBoss4Type2::create_zanzo(void *arg0, void *arg1) {
    void *o;
    o = __nw__7TObjectFUl(0x4C);
    if (o != NULL) {
        o = __ct__11TBoss4ZanzoFv(o, arg0, arg1);
    }
    return o;
}

void TBoss4Type2::md_recover_update() {
    u8 *boss4_type2 = (u8 *)this;
  Stack_80055918 stack;
  int temp_r0;
  u16 temp_r3_4;
  unsigned int temp_r3;
  unsigned int particle_emitter;
  unsigned int particle_effect;
  unsigned int temp_r3_5;
  unsigned int temp_r3_6;
  unsigned int *new_var;
  if (((*((int *) (((s8 *) boss4_type2) + 0x3C8))) == 5) && ((*((f32 *) (((s8 *) boss4_type2) + 0x3D0))) > 28.0f))
  {
    temp_r3 = *((unsigned int *) (((s8 *) boss4_type2) + 0x448));
    if (temp_r3 != 0)
    {
      TBoss4Type2::request_destroy((u32)((int) temp_r3));
      *((unsigned int *) (((s8 *) boss4_type2) + 0x448)) = 0;
    }
  }
  else
    if ((*((unsigned int *) (((s8 *) boss4_type2) + 0x448))) == 0)
  {
    particle_emitter = create_particle_emitter(boss4_type2 + 0x468, 0x143);
    new_var = (unsigned int *) (((s8 *) boss4_type2) + 0x448);
    *new_var = particle_emitter;
    if (particle_emitter != 0)
    {
      ((TBoss4Type2 *)(*new_var))->set_flags(0x40);
    }
  }
  if ((*((int *) (((s8 *) boss4_type2) + 0x398))) == 0x46)
  {
    particle_effect = spawn_particle_effect(boss4_type2 + 0x468, 0x13E);
    if (particle_effect != 0)
    {
      ((TBoss4Type2 *)particle_effect)->set_flags(0x40);
    }
    temp_r3_4 = *((u16 *) (((s8 *) boss4_type2) + 0x3C4));
    if (temp_r3_4 != ((unsigned short) (-1)))
    {
      temp_r3_5 = ((u32 (*)(int))get_player_by_client_id)((int) temp_r3_4);
      if (temp_r3_5 != 0)
      {
        VecCopy((Vec *)(&stack.sp8), (const Vec *)((int) ((TObjPlayer *)temp_r3_5)->get_position_ptr()));
        stack.spC += 10.0f;
        temp_r3_6 = spawn_particle_effect(&stack.sp8, 0x38);
        if (temp_r3_6 != 0)
        {
          ((TBoss4Type2 *)temp_r3_6)->set_flags(0x40);
        }
      }
    }
    ((TBoss4Type2 *)boss4_type2)->apply_resta_heal();
    TObjDFRecover::create((TObject *)boss4_type2, (u16)((int) (*((u16 *) (((s8 *) boss4_type2) + 0x3C4)))), (const f32 *)(boss4_type2 + 0x468));
  }
  temp_r0 = (*((int *) (((s8 *) boss4_type2) + 0x398))) - 1;
  *((int *) (((s8 *) boss4_type2) + 0x398)) = temp_r0;
  if (temp_r0 < 0)
  {
    ((s32 (*)(s32, void *, s32, s32))play_sound_effect)(0x4003AD1A, boss4_type2 + 0x38, 0, 1);
    TTecResta::create((void *)boss4_type2, boss4_type2 + 0x38, (void *)(*((int *) (((s8 *) boss4_type2) + 0x428))));
    ((TBoss4Type2 *)((void *) boss4_type2))->change_action((int) (*((int *) (((s8 *) boss4_type2) + 0x424))));
  }
}

void TBoss4Type2::md_recover_idle() {  }

void TBoss4Type2::md_recover_enter() {
    u8 *arg0 = (u8 *)this;
    *(f32 *)((s8 *)arg0 + 0x3E8) = (f32) 0.0f;
    ((s32 (*)(s32, void *, s32, s32))play_sound_effect)(0x40039E21, arg0 + 0x38, 0, 1);
    *(s32 *)((s8 *)arg0 + 0x398) = 0x96;
}

void TBoss4Type2::md_stop_update() {
    void *arg0 = (void *)this;
    s32 temp_r0;

    temp_r0 = *(s32 *)((s8 *)arg0 + 0x398) - 1;
    *(s32 *)((s8 *)arg0 + 0x398) = temp_r0;
    if (temp_r0 < 0) {
        ((TBoss4Type2 *)(arg0))->change_action(1);
    }
}

void TBoss4Type2::md_stop_idle() {
    void *boss4_type2 = (void *)this;
    if ((s32) *(s32 *)((s8 *)boss4_type2 + 0x398) == 0) {
        if (((f32 (*)(void))calc_boss4_scale__10TObjPlayerFi)() < 0.75f) {
            ((TBoss4Type2 *)boss4_type2)->choose_next_action();
            return;
        }
        ((TBoss4Type2 *)boss4_type2)->sub_80056F90(4, ((TBoss4Type2 *)boss4_type2)->sub_80057224());
    }
}

void TBoss4Type2::md_stop4_enter() {
    void *arg0 = (void *)this;
    *(f32 *)((s8 *)arg0 + 0x3E8) = (f32) 0.0f;
    *(s32 *)((s8 *)arg0 + 0x398) = 0x12C;
}

void TBoss4Type2::md_stop3_enter() {
    void *arg0 = (void *)this;
    *(f32 *)((s8 *)arg0 + 0x3E8) = (f32) 0.0f;
    *(s32 *)((s8 *)arg0 + 0x398) = 0xE1;
}

void TBoss4Type2::md_stop2_enter() {
    void *arg0 = (void *)this;
    *(f32 *)((s8 *)arg0 + 0x3E8) = (f32) 0.0f;
    *(s32 *)((s8 *)arg0 + 0x398) = 0x96;
}

void TBoss4Type2::md_stop1_enter() {
    void *arg0 = (void *)this;
    *(f32 *)((s8 *)arg0 + 0x3E8) = (f32) 0.0f;
    *(s32 *)((s8 *)arg0 + 0x398) = 0x4B;
}

void TBoss4Type2::tenchu_update() {
    Obj_80055BC0 *o = (Obj_80055BC0 *)this;
    Vec_80055BC0 sp14 = o->f450;
    Vec_80055BC0 sp8 = o->f45c;
    u8 *arg0 = (u8 *)o;
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
    temp_r0 = *(s32 *)((s8 *)arg0 + 0x398);
    if (temp_r0 == 6) {
        create_all_tenchu_furu__11TBoss4Type2Fi();
    } else if (temp_r0 == 1) {
        TBoss4Type2__sub_80054DA8();
    }
    if ((s32) *(s32 *)((s8 *)arg0 + 0x3C8) == 8) {
        temp_f1 = *(f32 *)((s8 *)arg0 + 0x3D0);
        if (temp_f1 > 28.0f) {
            temp_r3 = *(u32 *)((s8 *)arg0 + 0x438);
            if (temp_r3 != 0) {
                TBoss4Type2::request_destroy((u32)((void *)temp_r3));
                *(u32 *)((s8 *)arg0 + 0x438) = 0U;
            }
            temp_r3_2 = *(u32 *)((s8 *)arg0 + 0x440);
            if (temp_r3_2 != 0) {
                TBoss4Type2::request_destroy((u32)((void *)temp_r3_2));
                *(u32 *)((s8 *)arg0 + 0x440) = 0U;
            }
        } else if (temp_f1 >= 15.0f) {
            if ((u32) *(u32 *)((s8 *)arg0 + 0x438) == 0) {
                temp_r3_3 = create_particle_emitter(&sp14, 0x142);
                *(u32 *)((s8 *)arg0 + 0x438) = temp_r3_3;
                if (temp_r3_3 != 0) {
                    ((TBoss4Type2 *)((void *) *(u32 *)((s8 *)arg0 + 0x438)))->set_flags(0x40U);
                }
            }
            if ((u32) *(u32 *)((s8 *)arg0 + 0x440) == 0) {
                temp_r3_4 = create_particle_emitter(&sp8, 0x142);
                *(u32 *)((s8 *)arg0 + 0x440) = temp_r3_4;
                if (temp_r3_4 != 0) {
                    ((TBoss4Type2 *)((void *) *(u32 *)((s8 *)arg0 + 0x440)))->set_flags(0x40U);
                }
            }
        }
        temp_r3_5 = *(u32 *)((s8 *)arg0 + 0x438);
        if (temp_r3_5 != 0) {
            ((TNowLoading *)temp_r3_5)->copy_pos(&sp14);
        }
        temp_r3_6 = *(u32 *)((s8 *)arg0 + 0x440);
        if (temp_r3_6 != 0) {
            ((TNowLoading *)temp_r3_6)->copy_pos(&sp8);
        }
    }
    if ((s32) *(s32 *)((s8 *)arg0 + 0x3C8) == 9) {
        temp_f1_2 = *(f32 *)((s8 *)arg0 + 0x3D0);
        if (temp_f1_2 > 10.0f) {
            temp_r3_7 = *(u32 *)((s8 *)arg0 + 0x438);
            if (temp_r3_7 != 0) {
                TBoss4Type2::request_destroy((u32)((void *)temp_r3_7));
                *(u32 *)((s8 *)arg0 + 0x438) = 0U;
            }
            temp_r3_8 = *(u32 *)((s8 *)arg0 + 0x43C);
            if (temp_r3_8 != 0) {
                TBoss4Type2::request_destroy((u32)((void *)temp_r3_8));
                *(u32 *)((s8 *)arg0 + 0x43C) = 0U;
            }
            temp_r3_9 = *(u32 *)((s8 *)arg0 + 0x440);
            if (temp_r3_9 != 0) {
                TBoss4Type2::request_destroy((u32)((void *)temp_r3_9));
                *(u32 *)((s8 *)arg0 + 0x440) = 0U;
            }
            temp_r3_10 = *(u32 *)((s8 *)arg0 + 0x444);
            if (temp_r3_10 != 0) {
                TBoss4Type2::request_destroy((u32)((void *)temp_r3_10));
                *(u32 *)((s8 *)arg0 + 0x444) = 0U;
            }
        } else if (temp_f1_2 >= 2.0f) {
            if ((u32) *(u32 *)((s8 *)arg0 + 0x438) == 0) {
                particle_emitter = create_particle_emitter(&sp14, 0x13A);
                *(u32 *)((s8 *)arg0 + 0x438) = particle_emitter;
                if (particle_emitter != 0) {
                    ((TBoss4Type2 *)((void *) *(u32 *)((s8 *)arg0 + 0x438)))->set_flags(0x40U);
                }
                play_sound_effect(0x40039717, arg0 + 0x38, 0, 1);
            }
            if ((u32) *(u32 *)((s8 *)arg0 + 0x43C) == 0) {
                temp_r3_12 = create_particle_emitter(&sp14, 0x13B);
                *(u32 *)((s8 *)arg0 + 0x43C) = temp_r3_12;
                if (temp_r3_12 != 0) {
                    ((TBoss4Type2 *)((void *) *(u32 *)((s8 *)arg0 + 0x43C)))->set_flags(0x40U);
                }
            }
            if ((u32) *(u32 *)((s8 *)arg0 + 0x440) == 0) {
                temp_r3_13 = create_particle_emitter(&sp8, 0x13A);
                *(u32 *)((s8 *)arg0 + 0x440) = temp_r3_13;
                if (temp_r3_13 != 0) {
                    ((TBoss4Type2 *)((void *) *(u32 *)((s8 *)arg0 + 0x440)))->set_flags(0x40U);
                }
            }
            if ((u32) *(u32 *)((s8 *)arg0 + 0x444) == 0) {
                temp_r3_14 = create_particle_emitter(&sp8, 0x13B);
                *(u32 *)((s8 *)arg0 + 0x444) = temp_r3_14;
                if (temp_r3_14 != 0) {
                    ((TBoss4Type2 *)((void *) *(u32 *)((s8 *)arg0 + 0x444)))->set_flags(0x40U);
                }
            }
        }
        temp_r3_15 = *(u32 *)((s8 *)arg0 + 0x438);
        if (temp_r3_15 != 0) {
            ((TNowLoading *)temp_r3_15)->copy_pos(&sp14);
        }
        temp_r3_16 = *(u32 *)((s8 *)arg0 + 0x43C);
        if (temp_r3_16 != 0) {
            ((TNowLoading *)temp_r3_16)->copy_pos(&sp14);
        }
        temp_r3_17 = *(u32 *)((s8 *)arg0 + 0x440);
        if (temp_r3_17 != 0) {
            ((TNowLoading *)temp_r3_17)->copy_pos(&sp8);
        }
        temp_r3_18 = *(u32 *)((s8 *)arg0 + 0x444);
        if (temp_r3_18 != 0) {
            ((TNowLoading *)temp_r3_18)->copy_pos(&sp8);
        }
    }
    if ((s32) *(s32 *)((s8 *)arg0 + 0x398) > 6) {
        play_persistent_sound(0x4003AD16, arg0, arg0 + 0x38, 0, 1);
    }
    temp_r0_2 = *(s32 *)((s8 *)arg0 + 0x398) - 1;
    *(s32 *)((s8 *)arg0 + 0x398) = temp_r0_2;
    if (temp_r0_2 < 0) {
        ((TBoss4Type2 *)(arg0))->change_action((int) (*(s32 *)((s8 *)arg0 + 0x424)));
    }
}

void TBoss4Type2::tenchu_idle() {  }

void TBoss4Type2::tenchu_enter() {
    u8 *arg0 = (u8 *)this;
    *(f32 *)((s8 *)arg0 + 0x3E8) = (f32) (0.0f);
    TBoss4Type2__sub_80055300();
    *(s32 *)((s8 *)arg0 + 0x398) = 0x96;
}

#pragma push
#pragma fp_contract on
void TBoss4Type2::beam_update() {
    s32 idx = *(s32 *)((s8 *)this + 0x374) - 6;
    u8 *arg0 = (u8 *)this;
    Vec_80055F5C v = ((Vec_80055F5C *)(arg0 + 0x450))[idx];
    Vec_80055F5C p;
    s32 a;
    s32 b;
    u32 h;
    f32 t;
    if (*(s32 *)((s8 *)arg0 + 0x398) == 0x4B) {
        ((TBoss4Type2 *)arg0)->set_attack_pattern_by_index(boss4_type2_attack_pattern_table[idx]);
    }
    if (*(s32 *)((s8 *)arg0 + 0x3C8) == 6 || *(s32 *)((s8 *)arg0 + 0x3C8) == 7) {
        t = *(f32 *)((s8 *)arg0 + 0x3D0);
        if (t > 17.0f) {
            if (*(u32 *)((s8 *)arg0 + 0x434) != 0) {
                TBoss4Type2::request_destroy((u32)(*(void **)((s8 *)arg0 + 0x434)));
                *(u32 *)((s8 *)arg0 + 0x434) = 0;
            }
        } else if (t >= 8.0f && *(u32 *)((s8 *)arg0 + 0x434) == 0) {
            if ((*(u32 *)((s8 *)arg0 + 0x434) = create_particle_emitter(&v, 0xF7)) != 0) {
                ((TBoss4Type2 *)(*(void **)((s8 *)arg0 + 0x434)))->set_flags(0x40);
            }
        }
        if (*(f32 *)((s8 *)arg0 + 0x3D0) >= 8.0f && *(f32 *)((s8 *)arg0 + 0x3D0) <= 17.0f) {
            play_persistent_sound(0x4003B512, arg0, arg0 + 0x38, 0, 1);
        }
    }
    if (*(s32 *)((s8 *)arg0 + 0x398) == 0x26) {
        h = spawn_particle_effect(&v, 0xFD);
        if (h != 0) {
            ((TBoss4Type2 *)h)->set_flags(0x40);
        }
        play_sound_effect(0x4003A813, arg0 + 0x38, 0, 1);
        start_pad_rumble_all(0xC0, 0xF);
    }
    if (*(s32 *)((s8 *)arg0 + 0x398) <= 0x26 && *(s32 *)((s8 *)arg0 + 0x398) >= 4 && !(*(s32 *)((s8 *)arg0 + 0x398) & 1)) {
        VecCopy((Vec *)&p, (const Vec *)(arg0 + 0x410));
        p.x += 20.0f * *(f32 *)((s8 *)arg0 + 0x404);
        p.z += 20.0f * *(f32 *)((s8 *)arg0 + 0x40C);
        if (idx == 0) {
            create__11TTecRaBartaFPvPvPvPv(arg0, &p, &p, *(s32 *)((s8 *)(dispatch_shared_handler_a__6TLobbyFl(0x36)) + 0x1C));
        } else {
            ((TTecRaFoie *)arg0)->create(&p, &p, (void *)(*(s32 *)((s8 *)(dispatch_shared_handler_a__6TLobbyFl(0x36)) + 0x18)));
        }
        add_radar_scaled_marker(&p, -0x5DB4, 1, 1, 2.5f);
        *(f32 *)((s8 *)arg0 + 0x404) *= -1.0f;
        *(f32 *)((s8 *)arg0 + 0x40C) *= -1.0f;
        if (vector_length(arg0 + 0x410) > 280.0f) {
            normalize_vector(arg0 + 0x410);
            *(f32 *)((s8 *)arg0 + 0x410) *= 280.0f;
            *(f32 *)((s8 *)arg0 + 0x418) *= 280.0f;
            a = (s32)((10430.38043493439) * atan2_float(*(f32 *)((s8 *)arg0 + 0x410), *(f32 *)((s8 *)arg0 + 0x418)));
            b = (s32)((10430.38043493439) * atan2_float(*(f32 *)((s8 *)arg0 + 0x3F8), *(f32 *)((s8 *)arg0 + 0x400)));
            b += angle_diff_s16(b, a);
            *(f32 *)((s8 *)arg0 + 0x3F8) = -sin_table_lookup(b);
            *(f32 *)((s8 *)arg0 + 0x400) = -cos_table_lookup(b);
        }
        *(f32 *)((s8 *)arg0 + 0x410) = 50.0f * *(f32 *)((s8 *)arg0 + 0x3F8) + *(f32 *)((s8 *)arg0 + 0x410);
        *(f32 *)((s8 *)arg0 + 0x418) = 50.0f * *(f32 *)((s8 *)arg0 + 0x400) + *(f32 *)((s8 *)arg0 + 0x418);
    }
    if (*(s32 *)((s8 *)arg0 + 0x398) > 0x87) {
        *(f32 *)((s8 *)arg0 + 0x3E8) = (f32)(0x96 - *(s32 *)((s8 *)arg0 + 0x398)) / 15.0f;
    } else if (*(s32 *)((s8 *)arg0 + 0x398) >= 0x11) {
        *(f32 *)((s8 *)arg0 + 0x3E8) = 1.0f;
    } else if (*(s32 *)((s8 *)arg0 + 0x398) > 2) {
        *(f32 *)((s8 *)arg0 + 0x3E8) = (f32)(*(s32 *)((s8 *)arg0 + 0x398) - 2) / 15.0f;
    } else {
        *(f32 *)((s8 *)arg0 + 0x3E8) = 0.0f;
    }
    TBoss4Type2__sub_80057128(arg0);
    if (--*(s32 *)((s8 *)arg0 + 0x398) < 0) {
        if (game_difficulty_selection == 3) {
            ((TBoss4Type2 *)arg0)->spawn_bishi_around_players();
        }
        ((TBoss4Type2 *)(arg0))->change_action(*(s32 *)((s8 *)arg0 + 0x424));
    }
}
#pragma pop

void TBoss4Type2::beam_idle() {  }

void TBoss4Type2::beam_enter() {
    u8 *arg0 = (u8 *)this;
  s32 temp_r31;
  s32 var_r31;
  VecCopy((Vec *)(arg0 + 0x3F8), (const Vec *)(arg0 + 0x3B4));
  subtract_vector(arg0 + 0x3F8, arg0 + 0x38);
  *((f32 *) (((s8 *) arg0) + 0x3FC)) = (f32) 0.0f;
  if (vector_length(arg0 + 0x3F8) <= 0.01f)
  {
    *((f32 *) (((s8 *) arg0) + 0x3F8)) = (f32) 1.0f;
    *((f32 *) (((s8 *) arg0) + 0x3FC)) = (f32) 0.0f;
    *((f32 *) (((s8 *) arg0) + 0x400)) = (f32) 0.0f;
  }
  else
  {
    normalize_vector(arg0 + 0x3F8);
  }
  var_r31 = (s32) ((10430.38043493439) * atan2_float((f32) (*((f32 *) (((s8 *) arg0) + 0x3F8))), (f32) (*((f32 *) (((s8 *) arg0) + 0x400)))));
  temp_r31 = var_r31;
  if (((*((s32 *) (((s8 *) arg0) + 0x374))) - 6) == 0)
  {
    var_r31 = temp_r31 + 0x4000;
  }
  else
  {
    var_r31 = 0x4000;
    var_r31 = temp_r31 - var_r31;
  }
  *((f32 *) (((s8 *) arg0) + 0x404)) = ((f32 (*)(int))sin_table_lookup)((int) var_r31);
  *((f32 *) (((s8 *) arg0) + 0x40C)) = ((f32 (*)(int))cos_table_lookup)((int) var_r31);
  *((f32 *) (((s8 *) arg0) + 0x408)) = (f32) 0.0f;
  VecCopy((Vec *)(arg0 + 0x410), (const Vec *)(arg0 + 0x38));
  *((f32 *) (((s8 *) arg0) + 0x414)) = (f32) 0.0f;
  normalize_vector(arg0 + 0x410);
  *((f32 *) (((s8 *) arg0) + 0x410)) *= 280.0f;
  *((f32 *) (((s8 *) arg0) + 0x418)) *= 280.0f;
  *((s32 *) (((s8 *) arg0) + 0x398)) = 0x96;
}

void TBoss4Type2::jisin_update() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0;
    if ((s32) *(s32 *)((s8 *)arg0 + 0x398) == 0x1E) {
        TCameraCtrl::set_shake_preset(1);
        TBoss4Type2::create_jisin((void *)arg0, (void *)(*(s32 *)((s8 *)arg0 + 0x3A0)));
    }
    if ((s32) *(s32 *)((s8 *)arg0 + 0x398) <= 0x1E) {
        play_persistent_sound(0x4003AD16, arg0, arg0 + 0x38, 0, 1);
    }
    temp_r0 = *(s32 *)((s8 *)arg0 + 0x398) - 1;
    *(s32 *)((s8 *)arg0 + 0x398) = temp_r0;
    if (temp_r0 < 0) {
        ((TBoss4Type2 *)(arg0))->change_action(8);
    }
}

void TBoss4Type2::jisin_idle() {  }

void TBoss4Type2::jisin_enter() {
    void *arg0 = (void *)this;
    *(f32 *)((s8 *)arg0 + 0x3E8) = (f32) (0.0f);
    *(s32 *)((s8 *)arg0 + 0x398) = 0x4B;
}

void TBoss4Type2::move_update() {
    u8 *boss4_type2 = (u8 *)this;
    f32 temp_f1;
    s32 temp_r0;
    s32 temp_r3;
    s32 temp_r5;

    temp_r5 = *(s32 *)((s8 *)boss4_type2 + 0x398);
    if (temp_r5 > 7) {
        *(f32 *)((s8 *)boss4_type2 + 0x39C) = ((f32 (*)(void *, f32))compute_wave_offset__11TBoss4Type2Ff)(boss4_type2, (1.0f) - ((temp_r5 - 7) / (f32) *(s32 *)((s8 *)boss4_type2 + 0x420)));
    } else {
        *(f32 *)((s8 *)boss4_type2 + 0x39C) = (f32) (1.0f);
    }
    TBoss4Type2__sub_80057128(boss4_type2);
    if ((s32) game_difficulty_selection == 3) {
        temp_r3 = angle_diff_s16((int) (*(s32 *)((s8 *)boss4_type2 + 0x3A4)), (int) (*(s32 *)((s8 *)boss4_type2 + 0x3A8)));
        if (!(*(s32 *)((s8 *)boss4_type2 + 0x398) & 3)) {
            temp_f1 = *(f32 *)((s8 *)boss4_type2 + 0x39C);
            if ((temp_f1 > 0.05f) && (temp_f1 < 0.95f) && ((temp_r3 <= -0x4000) || (temp_r3 >= 0x4000))) {
                ((TBoss4Type2 *)boss4_type2)->spawn_afterimages();
            }
        }
    }
    temp_r0 = *(s32 *)((s8 *)boss4_type2 + 0x398) - 1;
    *(s32 *)((s8 *)boss4_type2 + 0x398) = temp_r0;
    if (temp_r0 < 0) {
        ((TBoss4Type2 *)(boss4_type2))->change_action(1);
    }
}

void TBoss4Type2::move_idle() {
    if (*(s32 *)((s8 *)this + 0x398) == 0) {
        sub_80056998();
    }
}

void TBoss4Type2::move_enter() {
    void *arg0 = (void *)this;
    *(f32 *)((s8 *)arg0 + 0x3E8) = (f32) (0.0f);
    *(s32 *)((s8 *)arg0 + 0x3E0) = (s32) (*(s32 *)((s8 *)arg0 + 0x3E0) + 1);
    *(s32 *)((s8 *)arg0 + 0x398) = (s32) *(s32 *)((s8 *)arg0 + 0x41C);
}

void TBoss4Type2::dead_update() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0;
    temp_r0 = *(s32 *)((s8 *)arg0 + 0x398) - 1;
    *(s32 *)((s8 *)arg0 + 0x398) = temp_r0;
    if (temp_r0 < 0) {
        ((TBoss4Type2 *)(arg0))->change_action(2);
    }
}

void TBoss4Type2::dead_idle() {  }

void TBoss4Type2::dead_enter() {
    *(s32 *)((s8 *)this + 0x398) = 75;
}

void TBoss4Type2::wait_next_idle() {
    u8 *boss4_type2 = (u8 *)this;
    if (*(s32 *)((s8 *)boss4_type2 + 0x30) & 0x800) {
        ((TBoss4Type2 *)boss4_type2)->sub_80056FEC(2);
        return;
    }
    ((TBoss4Type2 *)(boss4_type2))->change_action(9);
}

void TBoss4Type2::appear_update() {
    void *arg0 = (void *)this;
    s32 temp_r0;
    temp_r0 = *(s32 *)((s8 *)arg0 + 0x398) - 1;
    *(s32 *)((s8 *)arg0 + 0x398) = temp_r0;
    if (temp_r0 < 0) {
        ((TBoss4Type2 *)(arg0))->change_action(1);
    }
}

void TBoss4Type2::appear_idle() {
    u8 *boss4_type2 = (u8 *)this;
    if ((s32) *(s32 *)((s8 *)boss4_type2 + 0x398) == 0) {
        ((TBoss4Type2 *)boss4_type2)->sub_80056F90(4, (s32)((int) (((TBoss4Type2 *)boss4_type2)->sub_80057224())));
    }
}

void TBoss4Type2::appear_enter() {
    void *arg0 = (void *)this;
    *(f32 *)((s8 *)arg0 + 0x3E8) = (f32) 0.0f;
    *(s32 *)((s8 *)arg0 + 0x398) = 0x3C;
}

void TBoss4Type2::spawn_afterimages() {
    Zanzo_8005676C z;
    s32 i;
    VecCopy((Vec *)&z.pos, (const Vec *)(&((Obj_8005676C *)this)->pos));
    z.f0c = ((Obj_8005676C *)this)->f60;
    z.f1c = ((Obj_8005676C *)this)->f3d0;
    z.f20 = 0.75f;
    z.f24 = 0.0f;
    z.f28 = 10;
    for (i = 0; i < 2; i++) {
        z.f10 = TObjFish__sub_8001EDB0(((Obj_8005676C *)this)->f390, boss4_zanzo_bml_index_table[i]);
        z.f14 = get_bml_model(((Obj_8005676C *)this)->f390, boss4_zanzo_bml_index_table[i]);
        z.f18 = get_bml_motion(((Obj_8005676C *)this)->f390, ((Row_8005676C *)&TBoss4Type2__attack_pattern_table)[((Obj_8005676C *)this)->f3c8].c[i]);
        TBoss4Type2::create_zanzo(this, &z);
    }
}

void TBoss4Type2::spawn_bishi_around_players() {
    Obj_8005683C *arg0 = (Obj_8005683C *)this;
    Bishi_8005683C b;
    s32 i;
    s32 j;
    u8 *pl;
    TBoss4DarkFalz__sub_8004B4F0(&b.id, TBoss4DarkFalz__data_804FF1E8);
    b.f0 = arg0->f38c;
    b.f0c = 1;
    for (i = 0; i < lbl_805D586C; i++) {
        pl = (u8 *)get_player_data__10TObjPlayerFi(i);
        if (pl != 0 && TBoss4Type3__sub_8005254C(get_entity_id(pl)) != 0) {
            for (j = 0; j < 3; j++) {
                if (TBoss4DarkFalz__sub_8004AF5C(arg0->f38c, &b.id, &b.id2) != 0) {
                    VecCopy((Vec *)&b.pos, (const Vec *)(pl + 0x38));
                    b.pos.x += bishi_spawn_offset_table[j].x;
                    b.pos.z += bishi_spawn_offset_table[j].z;
                    create__11TBoss4BishiFi(&b);
                }
            }
        }
    }
}

void TBoss4Type2::apply_resta_heal() {
    s16 temp_r31;
    void *temp_r4;

    temp_r4 = *(void **)((s8 *)this + 0x2B0);
    temp_r31 = *(s16 *)((s8 *)temp_r4 + 2);
    drain_player_hp(*(u16 *)((s8 *)this + 0x3C4), (temp_r31 / 5) + (s32) TTecResta::calc_heal_amount(*(s32 *)((s8 *)(((void * (*)(s32, void *))dispatch_shared_handler_a__6TLobbyFl)(0x37, temp_r4)) + 0x1C)));
}

void TBoss4Type2::sub_80056998() {
    s32 temp_r3;
    s32 var_r4;
    s32 var_r5;
    if (((s32) *(s32 *)((s8 *)((u8 *)this) + 0x3E0) < 3) && (calc_boss4_scale__10TObjPlayerFi(this) < 0.1f)) {
        sub_80056F90(4, (s32)((int)((void *) (sub_80057224()))));
        return;
    }
    if (calc_boss4_scale__10TObjPlayerFi(this) < 0.1f) {
        temp_r3 = *(s32 *)((s8 *)((u8 *)this) + 0x424);
        var_r5 = temp_r3 + 1;
        var_r4 = temp_r3;
        if (var_r5 < temp_r3) {
            var_r4 = var_r5;
            var_r5 = temp_r3;
        }
        if (var_r4 < 9) {
            var_r4 = 9;
        }
        if (var_r5 > 0xC) {
            var_r5 = 0xC;
        }
        ((s32 (*)(void *, int, int))TBoss4Type2__sub_80056B3C)(this, var_r4, var_r5);
        return;
    }
    this->choose_next_action();
}

void TBoss4Type2::choose_next_action() {
    Grid_80056A54 grid;
    s32 r;
    s32 id;
    id = ((s32 (*)(void *))pick_random_target_player__11TBoss4Type3Fv)(this);
    if (((Obj_80056A54 *)this)->f32c <= ((Obj_80056A54 *)this)->f3ec && (u16)id != 0xFFFF) {
        r = TBoss4Type2::pick_weighted_random(4, boss4_type2_next_action_weights_a, boss4_type2_next_actions_a);
    } else {
        r = TBoss4Type2::pick_weighted_random(3, boss4_type2_next_action_weights_b, boss4_type2_next_actions_b);
    }
    switch (r) {
    case 6:
    case 7:
        find_target_pos__11TBoss4Type2FPvPv((O_80056C30 *)(((Obj_80056A54 *)this)), (Vec_80056C30 *)(&grid));
        ((TBoss4Type2 *)((Obj_80056A54 *)this))->set_grid_pos(&grid);
        sub_80056FEC(r);
        break;
    case 13:
        ((TBoss4Type2 *)((Obj_80056A54 *)this))->send_attack_code(r, id);
        break;
    default:
        sub_80056FEC(r);
        break;
    }
}

void TBoss4Type2__sub_80056B3C(void *actor, s32 lo, s32 hi) {
    f32 step;
    f32 acc;
    f32 scale;
    s32 t;
    s32 i;

    if (lo < 9 || lo > 12 || hi < 9 || hi > 12) {
        return;
    }
    if (hi < lo) {
        t = hi;
        hi = lo;
        lo = t;
    }
    step = 1.0f / (f32)(hi - lo + 1);
    acc = step;
    scale = calc_boss4_scale__10TObjPlayerFi(actor);
    for (i = lo; i < hi; i++) {
        if (scale < acc) {
            break;
        }
        acc += step;
    }
    ((TBoss4Type2 *)actor)->sub_80056FEC(i);
}

#pragma push
#pragma opt_propagation off
void find_target_pos__11TBoss4Type2FPvPv(O_80056C30 *self, Vec_80056C30 *out) {
    s32 a1;
    O_80056C30 *found;
    s32 i;
    O_80056C30 *p;
    f32 best;
    f32 d;
    f32 s;
    s32 ang;
    s32 b;
    Vec_80056C30 res;
    best = 0.0f;
    found = NULL;
    for (i = 0; i < lbl_805D586C; i++) {
        p = (O_80056C30 *)get_player_data__10TObjPlayerFi(i);
        if (p == NULL) {
            continue;
        }
        if (TBoss4Type3__sub_8005254C(get_entity_id(p)) == 0) {
            continue;
        }
        {
            Vec_80056C30 v = p->pos;
            v.y = 0.0f;
            d = xyz_distance(&v, &self->pos);
            if (d <= 560.0f && d > best) {
                best = d;
                found = p;
                VecCopy((Vec *)&res, (const Vec *)&v);
            }
        }
    }
    if (found != NULL) {
        VecCopy((Vec *)out, (const Vec *)&res);
        return;
    }
    s = 200.625f * calc_boss4_scale__10TObjPlayerFi(self);
    a1 = (s32)((10430.38043493439) * atan2_float(-self->pos.x, -self->pos.z));
    b = (s32)(49152.0f * calc_boss4_scale__10TObjPlayerFi(self));
    ang = b + a1;
    ang -= 0x6000;
    out->x = s * sin_table_lookup(ang);
    out->y = 0.0f;
    out->z = s * cos_table_lookup(ang);
}
extern int fold_flush_2;
#pragma pop

void TBoss4Type2::set_grid_pos(void *arg1) {
    *(s32 *)((s8 *)this + 0x3AC) = (s32) ((235.0f + *(f32 *)((s8 *)arg1 + 0)) / 29.375f);
    *(s32 *)((s8 *)this + 0x3B0) = (s32) ((235.0f + *(f32 *)((s8 *)arg1 + 8)) / 29.375f);
}

#pragma push
#pragma fp_contract on
void TBoss4Type2::calc_grid_target_position() {
    Obj_80056DF0 *arg0 = (Obj_80056DF0 *)this;
    arg0->f3B4 = 29.375f * (0.5f + (f32)arg0->i3AC) - 235.0f;
    arg0->f3B8 = 0.0f;
    arg0->f3BC = 29.375f * (0.5f + (f32)arg0->i3B0) - 235.0f;
}
extern int fold_flush_3;
#pragma pop

f32 compute_wave_offset__11TBoss4Type2Ff(f32 farg0) {
    return 0.5f * (1.0f - cos_table_lookup((s32) (32768.0f * farg0)));
}

void TBoss4Type2__sub_80056EA8(Obj_80056EA8 *self, u32 code) {
    s32 target_bits;
    s32 pattern;

    self->yaw = self->turn_yaw = (code << 8) & 0xF000;
    self->goal_yaw = (code << 4) & 0xF000;
    self->grid_x = (code >> 12) & 0xF;
    self->grid_z = (code >> 16) & 0xF;
    target_bits = code >> 20;
    self->target_player = target_bits & 0xF;
    if (((code >> 20) & 0xF) == 0xF) {
        self->target_player = 0xFFFF;
    }
    ((TBoss4Type2 *)self)->calc_grid_target_position();
    pattern = code & 0xF;
    if (pattern < 0 || pattern >= 14) {
        return;
    }
    ((TBoss4Type2 *)(self))->change_action(pattern);
}

void TBoss4Type2::send_attack_code(s32 arg1, s32 arg2) {
    Obj_80056F38 *self = (Obj_80056F38 *)this;
    if (self->target != 0) {
        ((TBoss4DarkFalz *)(self->target))->send_code_25_4((arg1 & 0xF) | (((self->f3a0 >> 12) & 0xF) << 4) | (((self->f3a0 >> 12) & 0xF) << 8) | ((self->f3ac & 0xF) << 12) | ((self->f3b0 & 0xF) << 16) | ((arg2 & 0xF) << 20));
    }
}

void TBoss4Type2::sub_80056F90(s32 arg1, s32 arg2) {
    if (((Obj_80056F90 *)this)->target != 0) {
        ((TBoss4DarkFalz *)(((Obj_80056F90 *)this)->target))->send_code_25_4((arg1 & 0xF) | (((((Obj_80056F90 *)this)->f3a0 >> 12) & 0xF) << 4) | (((arg2 >> 12) & 0xF) << 8) | ((((Obj_80056F90 *)this)->f3ac & 0xF) << 12) | ((((Obj_80056F90 *)this)->f3b0 & 0xF) << 16) | ((((Obj_80056F90 *)this)->f3c4 & 0xF) << 20));
    }
}

void TBoss4Type2::sub_80056FEC(s32 arg1) {
    if (((Obj_80056FEC *)this)->target != 0) {
        ((TBoss4DarkFalz *)(((Obj_80056FEC *)this)->target))->send_code_25_4((arg1 & 0xF) | (((((Obj_80056FEC *)this)->f3a0 >> 12) & 0xF) << 4) | (((((Obj_80056FEC *)this)->f3a0 >> 12) & 0xF) << 8) | ((((Obj_80056FEC *)this)->f3ac & 0xF) << 12) | ((((Obj_80056FEC *)this)->f3b0 & 0xF) << 16) | ((((Obj_80056FEC *)this)->f3c4 & 0xF) << 20));
    }
}

struct TBoss4Type2_80057048 { u8 pad[0x374]; s32 action; u8 pad378[0x3E0 - 0x378]; s32 move_count; u8 pad3e4[0x42C - 0x3E4]; void *parts[8]; };

void TBoss4Type2::change_action(s32 action) {
    TBoss4Type2_80057048 *self = (TBoss4Type2_80057048 *)this;
    s32 i;
    void (TBoss4Type2::*enter)();

    self->action = action;
    for (i = 2; i < 8; i++) {
        void **part = &self->parts[i];
        if (*part != NULL) {
            TBoss4Type2::request_destroy((u32)*part);
            *part = NULL;
        }
    }
    if (self->action != 4) {
        self->move_count = 0;
    }
    set_attack_pattern_by_index(boss4_type2_action_table[self->action].attack_index);
    enter = boss4_type2_action_table[self->action].enter;
    if (enter != 0) {
        (this->*enter)();
    }
}

struct Obj_80057128 {
    u8 pad0[0x38];
    f32 x;
    f32 y;
    f32 z;
    u8 pad44[0x60 - 0x44];
    s32 rot_y;
    u8 pad64[0x39C - 0x64];
    f32 turn_rate;
    s32 angle;
    s32 base_angle;
    s32 target_angle;
    u8 pad3AC[0x3E8 - 0x3AC];
    f32 wave;
};

extern "C" {
}

#pragma push
#pragma fp_contract on
void TBoss4Type2__sub_80057128(void *arg0) {
    Obj_80057128 *self = (Obj_80057128 *)arg0;
    f32 radius;
    f32 height;

    self->angle = self->base_angle + (s32)(self->turn_rate * (f32)angle_diff_s16(self->base_angle, self->target_angle));
    radius = 300.0f;
    height = -50.0f;
    if (self->wave > 0.0f) {
        f32 w = TBoss4Type3::compute_wave_offset(self->wave);
        radius = 30.0f * w + 300.0f;
        height = -45.0f * w + -50.0f;
    }
    self->x = radius * sin_table_lookup(self->angle);
    self->y = height;
    self->z = -radius * cos_table_lookup(self->angle);
    self->rot_y = -self->angle;
}
#pragma pop

s32 TBoss4Type2::sub_80057224() {
    return (s32)(49152.0f * calc_boss4_scale__10TObjPlayerFi(((Obj_80057224 *)this))) + 0x2000 + ((Obj_80057224 *)this)->f3a0;
}

void TUnk_80486924::draw_hanger() {
    Obj_80057270 *arg0 = (Obj_80057270 *)this;
    s32 i;
    TObjPlayer::set_global_flag();
    for (i = 0; i < 2; i++) {
        TObjFish::set_global_param(TObjFish__sub_8001EDB0(arg0->f390, boss4_zanzo_bml_index_table[i]));
        switch (i) {
        case 1:
            model_render_flags |= 0x20000;
            TObjEneRe4Sorcerer__sub_801E3F1C(0.0f, arg0->f3c0);
            ((TObjFish *)(arg0->f44c))->set_draw_callback_list();
            ((s32 (*)(s32, s32, f32))draw_model_motion)(get_bml_model(arg0->f390, boss4_zanzo_bml_index_table[i]),
                get_bml_motion(arg0->f390, (s32)(((Row_80057270 *)&TBoss4Type2__attack_pattern_table)[arg0->f3c8].c[i])),
                arg0->f3d0);
            clear_render_callback__8TObjFishFv(arg0->f44c);
            model_render_flags &= ~0x20000;
            break;
        default:
            TBoss6PlotFalz__sub_802AC008(arg0->f3f0, arg0->f3f4);
            ((s32 (*)(s32, s32, f32))draw_model_motion)(get_bml_model(arg0->f390, boss4_zanzo_bml_index_table[i]),
                get_bml_motion(arg0->f390, (s32)(((Row_80057270 *)&TBoss4Type2__attack_pattern_table)[arg0->f3c8].c[i])),
                arg0->f3d0);
            TBoss6PlotFalz::update_camera_target();
            break;
        }
    }
    TObjPlayer::clear_global_state();
    arg0->f3e4 = 0;
}

void TBoss4Type2::set_attack_pattern_by_index(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    if (arg1 != -1) {
        *(s32 *)((s8 *)arg0 + 0x3c8) = arg1;
        *(f32 *)((s8 *)arg0 + 0x3d0) = (f32) (0.0f);
        *(s32 *)((s8 *)arg0 + 0x3dc) = (s32) *(s32 *)((s8 *)((u8 *)&TBoss4Type2__attack_pattern_table.value + (arg1 << 0x4)) + 0);
    }
}

#pragma push
#pragma opt_common_subs off
void TBoss4Type2::update_phase_timer() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f1;
    f32 temp_f1_2;
    *(s32 *)((s8 *)arg0 + 0x3d8) = 0;
    *(f32 *)((s8 *)arg0 + 0x3d0) = (f32) (*(f32 *)((s8 *)arg0 + 0x3d0) + *(f32 *)((s8 *)arg0 + 0x3d4));
    switch (*(s32 *)((s8 *)arg0 + 0x3dc)) {
    case 0:
        temp_f1 = *(f32 *)((s8 *)arg0 + 0x3d0);
        if (temp_f1 >= 30.0f) {
            *(f32 *)((s8 *)arg0 + 0x3d0) = (f32) (temp_f1 - 30.0f);
            *(s32 *)((s8 *)arg0 + 0x3d8) = 1;
        }
        break;
    case 1:
        if (*(f32 *)((s8 *)arg0 + 0x3d0) >= 29.0f) {
            *(f32 *)((s8 *)arg0 + 0x3d0) = (f32) 29.0f;
            *(s32 *)((s8 *)arg0 + 0x3d8) = 1;
        }
        break;
    case 2:
        if (*(f32 *)((s8 *)arg0 + 0x3d0) >= 29.0f) {
            *(s32 *)((s8 *)arg0 + 0x3c8) = (s32) *(s32 *)((s8 *)((u8 *)&(*(RecoveredGlobal_8005455C_lbl_80485EC8 *)&TBoss4Type2__attack_pattern_table).value + (*(s32 *)((s8 *)arg0 + 0x3c8) << 0x4)) + 4);
            *(s32 *)((s8 *)arg0 + 0x3dc) = (s32) *(s32 *)((s8 *)(&(*(RecoveredGlobal_8005455C_lbl_80485EC8 *)&TBoss4Type2__attack_pattern_table).value) + (*(s32 *)((s8 *)arg0 + 0x3c8) << 0x4));
            *(f32 *)((s8 *)arg0 + 0x3d0) = (f32) 0.0f;
            *(s32 *)((s8 *)arg0 + 0x3d8) = 1;
        }
        break;
    }
    temp_f1_2 = *(f32 *)((s8 *)arg0 + 0x3d0);
    if ((temp_f1_2 < 0.0f) || (temp_f1_2 >= 30.0f)) {
        *(f32 *)((s8 *)arg0 + 0x3d0) = (f32) 0.0f;
    }
}
extern int fold_flush_4;
#pragma pop

void TUnk_80486924::init_hanger() { toggle_particle_effect__10TObjPlayerFv(this); ((int (*)(void))push_matrix)(); ((int (*)(void*))post_translate_matrix)((char*)this + 0x38); ((int (*)(void*, void*))rotate_matrix_y)((void*)0, *(void**)((char*)this + 0x60)); draw_hanger(); ((int (*)(void))pop_matrix)(); TParticleCtrl::end_effect_render(); }

void TBoss4Type2::advance_afterimage() {
    u8 *arg0 = (u8 *)this;
    VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)(arg0 + 0x38));
    *(f32 *)((s8 *)arg0 + 0x300) += 75.0f;
}

void TUnk_80486924::render() { this->init_hanger(); }

void submit_cursor_candidate(void *, int);
void TBoss4Type2::update_main() {
    u8 *arg0 = (u8 *)this;
    void (TBoss4Type2::*fn)();

    if (((TBoss4DarkFalz *)(*(void **)((s8 *)arg0 + 0x38C)))->is_field378_zero() != 0) {
        fn = boss4_type2_action_table[*(s32 *)((s8 *)arg0 + 0x374)].update_idle;
        if (fn != 0) {
            (this->*fn)();
        }
    }
    fn = boss4_type2_action_table[*(s32 *)((s8 *)arg0 + 0x374)].update;
    if (fn != 0) {
        (this->*fn)();
    }
    update_phase_timer();
    advance_afterimage();
    if (0.0f == *(f32 *)((s8 *)arg0 + 0x3E8)) {
        *(u32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x394)) + 0x18) |= 1;
        ((TObjPlayer *)arg0)->update_collisions();
        submit_cursor_candidate(arg0, -1);
    } else {
        *(u32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x394)) + 0x18) &= ~1;
    }
    add_radar_scaled_marker(arg0 + 0x2FC, 0xFFFFA24C, 1, 1, 5.0f);
    if (*(s32 *)((s8 *)arg0 + 0x374) != 2) {
        Vec_80057598 pos = *(Vec_80057598 *)(arg0 + 0x38);
        Vec_80057598 dir = *(Vec_80057598 *)(arg0 + 0x38);
        dir.y = 0.0f;
        normalize_vector(&dir);
        dir.x *= -50.0f;
        dir.z *= -50.0f;
        dir.y = 50.0f;
        vec3_add_to(&pos, &dir);
        if (*(void **)((s8 *)arg0 + 0x42C) != NULL) {
            ((TNowLoading *)(*(void **)((s8 *)arg0 + 0x42C)))->copy_pos(&pos);
        }
        if (*(void **)((s8 *)arg0 + 0x430) != NULL) {
            ((TNowLoading *)(*(void **)((s8 *)arg0 + 0x430)))->copy_pos(&pos);
        }
        ((TBoss4Type2 *)(arg0 + 0x378))->scroll_strips();
    }
    {
        Vec_80057598 a = boss4_type2_follow_camera_offset_a;
        Vec_80057598 b = boss4_type2_follow_camera_offset_b;
        request_follow_camera_offsets(&a, &b, 0xFFFF);
    }
    if ((*(f32 *)((s8 *)arg0 + 0x3C0) += 0.022222223f) >= 1.0f) {
        *(f32 *)((s8 *)arg0 + 0x3C0) -= 1.0f;
    }
    *(f32 *)((s8 *)arg0 + 0x3F0) += -0.06666667f;
    if (*(f32 *)((s8 *)arg0 + 0x3F0) < 0.0f) {
        *(f32 *)((s8 *)arg0 + 0x3F0) = 0.0f;
    }
    *(f32 *)((s8 *)arg0 + 0x3F4) = (f32)*(s16 *)((s8 *)arg0 + 0x32C) / (f32)*(s16 *)((s8 *)arg0 + 0x33E);
}

void TUnk_80486924::vfunc_63() {
    s32 temp_r0;

    temp_r0 = *(s32 *)((s8 *)this + 0x374);
    if ((temp_r0 != 3) && (temp_r0 != 2)) {
        ((TBoss4Type2 *)(this))->change_action(3);
    }
}

void TUnk_80486924::vfunc_62() {
    *(s32 *)((s8 *)((u8 *)this) + 0x3E4) = 1;
    *(f32 *)((s8 *)((u8 *)this) + 0x3F0) = (f32) 1.0f;
    *(s32 *)((s8 *)((u8 *)this) + 0x30) = (s32) (*(s32 *)((s8 *)((u8 *)this) + 0x30) & 0xFFFFFDFF);
    ((s32 (*)(int, void *, int, int, void *))play_sound_effect)(0x4003B723, ((u8 *)this) + 0x38, 0, 1, this);
}

S_800578E8 *__dt__13TUnk_80486924Fv(S_800578E8 *o, s16 flag) {
    s32 i;
    if (o != 0) {
        o->vt = lbl_80486924;
        fn_8004AA04(o->f378);
        for (i = 0; i < 8; i++) {
            if (o->ptr[i] != 0) {
                TBoss4Type2::request_destroy((u32)o->ptr[i]);
                o->ptr[i] = 0;
            }
        }
        TObjFish::init_state_1(o->f44c);
        o->f44c = 0;
        free_collision_body_parts(o);
        o->f394 = 0;
        __dt__9TObjEnemyFv(o, 0);
        if (flag > 0) {
            __dl__7TObjectFPv(o);
        }
    }
    return o;
}

u8 *TBoss4Type2__ct(u8 *arg0, s32 parent, s32 *arg2) {
    s32 i;
    s32 v;

    __ct__9TObjEnemyFP7TObject(arg0, (void*)parent);
    *(u8 **)((s8 *)arg0 + 0x18) = lbl_80486924;
    *(s32 *)((s8 *)arg0 + 0) = (s32)boss4_type2_class_name;
    ((TUnk_804806E8 *)arg0)->add_flags_2e4(8);
    *(s32 *)((s8 *)arg0 + 0x38C) = arg2[0];
    ((TUnk_80486924 *)arg0)->apply_set_data(arg2 + 1);
    ((TUnk_80486924 *)arg0)->clear_lobby_object_state();
    *(s32 *)((s8 *)arg0 + 0x390) = TBoss4Uro::get_instance_count();
    *(s32 *)((s8 *)arg0 + 0x24) = 0;
    *(s32 *)((s8 *)arg0 + 0x34) = 0;
    VecCopy((Vec *)(arg0 + 0x38), (const Vec *)boss4_type2_start_position);
    *(s32 *)((s8 *)arg0 + 0x60) = 0;
    VecCopy((Vec *)(arg0 + 0x44), (const Vec *)((void *) VecCopy((Vec *)(arg0 + 0x50), (const Vec *)((void *) VecCopy((Vec *)(arg0 + 0x74), (const Vec *)(arg0 + 0x38))))));
    *(s32 *)((s8 *)arg0 + 0x394) = init_collision_body_parts(arg0, boss4_type2_collision_body_parts, 1);
    VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)(arg0 + 0x38));
    *(f32 *)((s8 *)arg0 + 0x310) = 0.0f;
    *(f32 *)((s8 *)arg0 + 0x30C) = 0.0f;
    *(f32 *)((s8 *)arg0 + 0x308) = 0.0f;
    *(s32 *)((s8 *)arg0 + 0x2A8) = 0;
    ((TObjEnemy *)arg0)->bind_enemy_combat_stats((u8 *)((int) TLobby::register_boss(0x37)), (u8 *)(TLobby::dispatch_shared_handler_b(0x37)), (u8 *)(TLobby::register_object(0x37)));
    *(s16 *)((s8 *)arg0 + 0x33E) = *(s16 *)((s8 *)arg0 + 0x32C);
    ((TBoss3Volopt *)arg0)->reset_photon_effect();
    ((TObjEnemy *)arg0)->set_param(0x2F);
    *(s32 *)((s8 *)arg0 + 0x3CC) = 0;
    *(s32 *)((s8 *)arg0 + 0x3C8) = 0;
    *(s32 *)((s8 *)arg0 + 0x3D8) = 0;
    *(f32 *)((s8 *)arg0 + 0x3D4) = 0.4f;
    *(f32 *)((s8 *)arg0 + 0x3D0) = 0.0f;
    *(s32 *)((s8 *)arg0 + 0x44C) = TObjFish__sub_800E3124(lbl_80486868, arg0 + 0x450, 0.4f);
    for (i = 0; i < 2; i++) {
        ((Arr_800579A0 *) arg0)->f42C[i] = create_particle_emitter(arg0 + 0x38, boss4_type2_emitter_ids[i]);
    }
    for (; i < 8; i++) {
        ((Arr_800579A0 *) arg0)->f42C[i] = 0;
    }
    init_model_node_tables(arg0 + 0x378, (void *)boss4_type2_model_node_table, 6);
    *(s32 *)((s8 *)arg0 + 0x3A0) = 0;
    *(s32 *)((s8 *)arg0 + 0x3E0) = 0;
    *(u16 *)((s8 *)arg0 + 0x3C4) = 0xFFFF;
    *(s32 *)((s8 *)arg0 + 0x41C) = get_random_float__21TObjEneMe3ShinowaRealFv(*(f32 *) dispatch_shared_handler_a__6TLobbyFl(0x37));
    if (*(s32 *)((s8 *)arg0 + 0x41C) < 1 || *(s32 *)((s8 *)arg0 + 0x41C) > 25) {
        *(s32 *)((s8 *)arg0 + 0x41C) = 4;
    }
    *(s32 *)((s8 *)arg0 + 0x41C) *= 75;
    *(s32 *)((s8 *)arg0 + 0x420) = *(s32 *)((s8 *)arg0 + 0x41C) - 7;
    v = *(s32 *)((s8 *)(dispatch_shared_handler_a__6TLobbyFl(0x37)) + 0x18);
    if (v < 1 || v > 4) {
        v = 1;
    }
    *(s32 *)((s8 *)arg0 + 0x424) = v + 8;
    *(s32 *)((s8 *)arg0 + 0x428) = *(s32 *)((s8 *)(dispatch_shared_handler_a__6TLobbyFl(0x37)) + 0x1C);
    if (*(s32 *)((s8 *)arg0 + 0x428) < 0 || *(s32 *)((s8 *)arg0 + 0x428) > 14) {
        *(s32 *)((s8 *)arg0 + 0x428) = 0;
    }
    *(f32 *)((s8 *)arg0 + 0x3C0) = 0.0f;
    *(s32 *)((s8 *)arg0 + 0x3E4) = 0;
    *(f32 *)((s8 *)arg0 + 0x3E8) = 0.0f;
    *(s32 *)((s8 *)arg0 + 0x3EC) = *(s16 *)((s8 *)arg0 + 0x32C) / 2;
    *(f32 *)((s8 *)arg0 + 0x3F0) = 0.0f;
    *(f32 *)((s8 *)arg0 + 0x3F4) = 1.0f;
    ((TBoss4Type2 *)(arg0))->change_action(0);
    return arg0;
}

s32 TBoss4Type2::create(s32 arg0) {
    s32 var_r31;
    s32 var_r4;

    var_r31 = ((s32 (*)(s32))__nw__7TObjectFUl)(0x474);
    if (var_r31 != 0) {
        var_r4 = ((s32 (*)(s32))__nw__7TObjectFUl)(0x20);
        if (var_r4 != 0) {
            var_r4 = TObjControl__ct(var_r4, tl_04);
        }
        var_r31 = ((s32 (*)(s32, s32, s32))TBoss4Type2__ct)(var_r31, var_r4, arg0);
    }
    return var_r31;
}
}
