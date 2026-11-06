#include "types.h"
#include "pso/system/vector.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/unk/TUnk_80488A28.h"
#include "pso/camera/CameraViewParams.h"
#include "pso/system/PadRumble.h"
#include "pso/camera/TCameraCtrl_8006A03C.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/network/client_id.h"
#include "pso/map/FloorArea.h"
#include "pso/system/task/TObject.h"
#include "pso/camera/CreationCamera.h"
#include "pso/system/task/TMainTask.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"

struct RecoveredGlobal_8006ABAC_lbl_804FF61C {
    s32 value;
    u8 remaining[0x8];
};
struct C30_8006AD34 { u8 b[0x30]; };


f32 lbl_804FF5E8[10];
f32 camera_right[3];
RecoveredGlobal_8006ABAC_lbl_804FF61C camera_pitch_rotated_up_vector;
u8 TCameraCtrl__view_state[12];
u32 TCameraCtrl__data_804FF634[18];
u32 lbl_804FF67C[18];
u32 TCameraCtrl__up_vector[3];
u8 TCameraCtrl__view_matrix[0x30];
C30_8006AD34 TCameraCtrl__view_matrices[4];

struct Cam_80069F20 {
    s32 f0;
    s32 f4;
    s32 flags;
};

struct Out_80069F20 {
    u8 pad0[0x20];
    s32 f20;
    s32 f24;
    s32 f28;
    f32 f2c;
    f32 f30;
    s32 f34;
    f32 f38;
    f32 f3c;
    f32 f40;
    f32 f44;
    f32 f48;
    f32 f4c;
    f32 f50;
    f32 f54;
    f32 f58;
    f32 f5c;
    u8 pad60[4];
    s16 f64;
};

struct RecoveredGlobal_800691C8_main_task {
    s32 value;
    u8 remaining[0x30];
};

struct RecoveredGlobal_80069148_TCameraCtrl__data_804FF6D0 {
    s32 value;
    u8 remaining[0x2C];
};

struct RecoveredGlobal_80069148_TCameraCtrl__data_804FF700 {
    s32 value;
    u8 remaining[0xBC];
};

struct RecoveredGlobal_80069C94_camera_controller_registry {
    s32 value;
    u8 remaining[0x64];
};

struct RecoveredGlobal_80069C94_TCameraCtrl__data_804FF628 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_80069D04_camera_controller_registry {
    s32 value;
    u8 remaining[0x64];
};

struct RecoveredGlobal_80069D04_TCameraCtrl__data_804FF628 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_800687C8_TCameraCtrl__data_804FF6C4 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_80069304_TCameraCtrl__data_804FF628 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_8006961C_TCameraCtrl__data_804FF628 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_8006961C_TCameraCtrl__data_804FF634 {
    s32 value;
    u8 remaining[0x44];
};

struct RecoveredGlobal_8006961C_lbl_8058CA60 {
    s32 value;
    u8 remaining[0x54];
};

struct RecoveredGlobal_80069258_TCameraCtrl__data_804FF6D0 {
    s32 value;
    u8 remaining[0x2C];
};

struct RecoveredGlobal_80069258_TCameraCtrl__data_804FF700 {
    s32 value;
    u8 remaining[0xBC];
};

struct RecoveredGlobal_80069258_main_task {
    s32 value;
    u8 remaining[0x30];
};

struct RecoveredGlobal_80069A6C_camera_controller_registry {
    s32 value;
    u8 remaining[0x64];
};

struct RecoveredGlobal_80069A6C_TCameraCtrl__data_804FF628 {
    u8 value;
    u8 remaining[0xB];
};

#include <stddef.h>
struct Stack_80069318 {
    s32 sp8;
    u8 pad_C[0x4];
    f32 sp10;
    f32 sp14;
    u8 pad_18[0x8];
    f32 sp20;
    u8 pad_24[0xC];
    f32 sp30;
    f32 sp34;
    f32 sp38;
    f32 sp3C;
    f32 sp40;
    f32 sp44;
};

struct Stack_800693F4 {
    s32 sp8;
    u8 pad_C[0x4];
    f32 sp10;
    f32 sp14;
    u8 pad_18[0x8];
    f32 sp20;
    u8 pad_24[0xC];
    f32 sp30;
    f32 sp34;
    f32 sp38;
    f32 sp3C;
    f32 sp40;
    f32 sp44;
    f32 sp48;
    f32 sp4C;
};

struct RecoveredGlobal_800693F4_TCameraCtrl__data_804FF634 { s32 value; u8 remaining[0x44]; };

struct Stack_800694A8 {
    s32 sp8;
    u8 pad_C[0x4];
    f32 sp10;
    f32 sp14;
    u8 pad_18[0x18];
    f32 sp30;
    f32 sp34;
    f32 sp38;
    f32 sp3C;
    f32 sp40;
    f32 sp44;
    f32 sp48;
    f32 sp4C;
};

struct RecoveredGlobal_800694A8_TCameraCtrl__data_804FF628 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_80069534_TCameraCtrl__data_804FF628 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_80069D7C_TCameraCtrl__data_804FF628 {
    s32 value;
    u8 remaining[0x8];
};

struct VBase_18_f8ef8c
{
  char pad[0x18];
};

struct VObj_18_f8ef8c : VBase_18_f8ef8c {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual s32 m5();
};

struct RecoveredGlobal_80069E7C_camera_controller_registry
{
  s32 value;
  u8 remaining[0x64];
};

struct RecoveredGlobal_80069E7C_TCameraCtrl__data_804FF628
{
  s32 value;
  u8 remaining[0x8];
};

struct Cam_80068958 { u8 pad[0x10]; s32 ids[4]; u8 pad20[0x4]; };

struct G_800695A0 { s32 a; s32 b; u32 flags; };

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct M_80068FCC { f32 m[3][4]; };

struct W_80068FCC { f32 x, y; };

struct O_80068FCC { M_80068FCC m; W_80068FCC a; W_80068FCC b; W_80068FCC c; };

struct Cam_800688D0 { u8 pad[0x10]; s32 slots[4]; };


struct Vec_80068810 { f32 x, y, z; };

struct Cam_80068810 {
    u8 pad0[0x94];
    void *view_yaw[4];
    Vec_80068810 view_pos[4];
    u8 padd4[0x178 - 0xD4];
    Vec_80068810 pos;
    u8 pad184[0x194 - 0x184];
    void *yaw;
};

struct Vec_800696D0 { f32 x, y, z; };

struct Hit_800696D0 { u32 f0; Vec_800696D0 *point; };

struct View_800696D0 {
    u8 pad0[0xD4];
    Vec_800696D0 split_pos[4];
    Vec_800696D0 split_tgt[4];
    Vec_800696D0 split_look[4];
    s32 split_obstructed[4]; // per view: obstructed below
    s32 obstructed; // set by resolve_anchor_obstruction when csnVector(look, eye) hits; gates clamp_to_target_obstruction
    Vec_800696D0 pos;
    Vec_800696D0 tgt;
    u8 pad190[0x1A0 - 0x190];
    Vec_800696D0 eye;
    u8 pad1AC[0x1C8 - 0x1AC];
    Vec_800696D0 look;
};

struct Vec_800698C8 { f32 x, y, z; };

struct Hit_800698C8 { u32 f0; Vec_800698C8 *point; };

struct View_800698C8 {
    u8 pad0[0xD4];
    Vec_800698C8 split_pos[4];
    Vec_800698C8 split_tgt[4];
    Vec_800698C8 split_look[4];
    s32 split_obstructed[4];
    s32 obstructed;
    Vec_800698C8 pos;
    Vec_800698C8 tgt;
    u8 pad190[0x1C8 - 0x190];
    Vec_800698C8 look;
};
extern "C" {



void TCameraCtrl__sub_800689E8(void);
s32 is_split_screen();
s32 approach_camera_vector(void *, void *, f32);
extern s32 TCameraCtrl__pose_snap_flags;
s32 GXSetViewport(f32, f32, f32, f32, f32, f32);
s32 GXSetScissor(int, int, int, int);
s32 GXSetScissorBoxOffset(int, int);
s16 TCameraCtrl__viewport_size = 640;
s16 TCameraCtrl__viewport_height = 480;
const char *lbl_805D283C = "TCameraCtrl";
extern s16 TCameraCtrl__viewport_x;
extern s16 TCameraCtrl__viewport_y;
s32 set_perspective_projection_from_fov(int, f32, f32, f32);
s32 get_entity_id(void *);
s32 get_camera_mode__11TCameraCtrlFv();
s32 TCameraCtrl__sub_8006B358(void *p);
extern void *camera_controller_registry[13];
extern u8 *camera_ctrl_instance;
void TCameraCtrl__sub_801E32D8(f32, f32);
extern s16 TCameraCtrl__data_805D4E0A;
s32 get_mode__11TCameraCtrlFPv(void *);
s32 matrix_mult_vec(int, void *, void *);
s32 push_matrix();
s32 pop_matrix();
void transform_to_view__11TCameraCtrlFii(s32 arg0, s32 arg1);
void set_active_camera_pose(u8 *arg0, u8 *arg1);
void set_active_camera_pose_from_params(u8 *arg0);
void TCameraCtrl__sub_800687C8(void);
s32 TCameraCtrl__sub_80069304(void);
extern RecoveredGlobal_8006961C_lbl_8058CA60 scene_projection_state;
s32 camera_renderer_setup_nop(void *, int);
s32 fn_803D64F8(void *);
extern f32 camera_default_view_value;
extern f32 camera_default_view_value_b;
extern s16 TCameraCtrl__camera_mode;
s32 set_viewport_scissor__11TCameraCtrlFiPv(int, void *);
s32 activate_camera_mode(s32 arg0);
bool TCameraCtrl__sub_800689F4(void);
Cam_80068958 *get_character_select_request_buffer(void);
}

void reset_cameras_to_actor(void *actor, s32 arg1);
extern "C" {


u16 TCameraCtrl__sub_8006A5DC(void);
extern s32 TCameraCtrl__saved_projection_angle;
s32 restore_player_cameras(void);
u8 *csnVector(void *, void *, u32);
f32 vector_length(void *);
void normalize_vector(void *);
f32 TCameraCtrl__sub_80068A04(void);
u8 *TCameraCtrl__ct(u8 *arg0, void *parent);
void * __nw__7TObjectFUl(s32);


typedef char RecoveredGlobal_800687C8_TCameraCtrl__data_804FF6C4_size[sizeof(RecoveredGlobal_800687C8_TCameraCtrl__data_804FF6C4) == 0xC ? 1 : -1];

struct Cam_80068958;
inline void quad_80068B34(s32 i) {
    TCameraCtrl::set_target_coords((s32)(320.0f * (f32)(i % 2)), (s32)(240.0f * (f32)(i / 2)));
    TCameraCtrl::set_target(0x140, 0xF0);
}
inline void viewport_80068B34(void) {
    GXSetViewport(TCameraCtrl__viewport_x, TCameraCtrl__viewport_y, TCameraCtrl__viewport_size, TCameraCtrl__viewport_height, 0.0f, 1.0f);
    GXSetScissor(TCameraCtrl__viewport_x, TCameraCtrl__viewport_y, TCameraCtrl__viewport_size, TCameraCtrl__viewport_height);
}

typedef char RecoveredGlobal_800691C8_main_task_size[sizeof(RecoveredGlobal_800691C8_main_task) == 0x34 ? 1 : -1];

typedef char RecoveredGlobal_80069148_TCameraCtrl__data_804FF6D0_size[sizeof(RecoveredGlobal_80069148_TCameraCtrl__data_804FF6D0) == 0x30 ? 1 : -1];
typedef char RecoveredGlobal_80069148_TCameraCtrl__data_804FF700_size[sizeof(RecoveredGlobal_80069148_TCameraCtrl__data_804FF700) == 0xC0 ? 1 : -1];

typedef char RecoveredGlobal_80069258_TCameraCtrl__data_804FF6D0_size[sizeof(RecoveredGlobal_80069258_TCameraCtrl__data_804FF6D0) == 0x30 ? 1 : -1];
typedef char RecoveredGlobal_80069258_TCameraCtrl__data_804FF700_size[sizeof(RecoveredGlobal_80069258_TCameraCtrl__data_804FF700) == 0xC0 ? 1 : -1];
typedef char RecoveredGlobal_80069258_main_task_size[sizeof(RecoveredGlobal_80069258_main_task) == 0x34 ? 1 : -1];


typedef char RecoveredGlobal_80069304_TCameraCtrl__data_804FF628_size[sizeof(RecoveredGlobal_80069304_TCameraCtrl__data_804FF628) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_800694A8_TCameraCtrl__data_804FF628_size[sizeof(RecoveredGlobal_800694A8_TCameraCtrl__data_804FF628) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_80069534_TCameraCtrl__data_804FF628_size[sizeof(RecoveredGlobal_80069534_TCameraCtrl__data_804FF628) == 0xC ? 1 : -1];

typedef char RecoveredGlobal_8006961C_TCameraCtrl__data_804FF628_size[sizeof(RecoveredGlobal_8006961C_TCameraCtrl__data_804FF628) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_8006961C_TCameraCtrl__data_804FF634_size[sizeof(RecoveredGlobal_8006961C_TCameraCtrl__data_804FF634) == 0x48 ? 1 : -1];
typedef char RecoveredGlobal_8006961C_lbl_8058CA60_size[sizeof(RecoveredGlobal_8006961C_lbl_8058CA60) == 0x58 ? 1 : -1];

typedef char RecoveredGlobal_80069A6C_camera_controller_registry_size[sizeof(RecoveredGlobal_80069A6C_camera_controller_registry) == 0x68 ? 1 : -1];
typedef char RecoveredGlobal_80069A6C_TCameraCtrl__data_804FF628_size[sizeof(RecoveredGlobal_80069A6C_TCameraCtrl__data_804FF628) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_80069C94_camera_controller_registry_size[sizeof(RecoveredGlobal_80069C94_camera_controller_registry) == 0x68 ? 1 : -1];
typedef char RecoveredGlobal_80069C94_TCameraCtrl__data_804FF628_size[sizeof(RecoveredGlobal_80069C94_TCameraCtrl__data_804FF628) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_80069D04_camera_controller_registry_size[sizeof(RecoveredGlobal_80069D04_camera_controller_registry) == 0x68 ? 1 : -1];
typedef char RecoveredGlobal_80069D04_TCameraCtrl__data_804FF628_size[sizeof(RecoveredGlobal_80069D04_TCameraCtrl__data_804FF628) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_80069D7C_TCameraCtrl__data_804FF628_size[sizeof(RecoveredGlobal_80069D7C_TCameraCtrl__data_804FF628) == 0xC ? 1 : -1];

typedef struct RecoveredGlobal_80069E7C_TCameraCtrl__data_804FF628 RecoveredGlobal_80069E7C_TCameraCtrl__data_804FF628;
typedef struct RecoveredGlobal_80069E7C_camera_controller_registry RecoveredGlobal_80069E7C_camera_controller_registry;
typedef struct VBase_18_f8ef8c VBase_18_f8ef8c;
typedef struct VObj_18_f8ef8c VObj_18_f8ef8c;
typedef char RecoveredGlobal_80069E7C_camera_controller_registry_size[((sizeof(RecoveredGlobal_80069E7C_camera_controller_registry)) == 0x68) ? (1) : (-1)];
typedef char RecoveredGlobal_80069E7C_TCameraCtrl__data_804FF628_size[((sizeof(RecoveredGlobal_80069E7C_TCameraCtrl__data_804FF628)) == 0xC) ? (1) : (-1)];
#define PSO_VCALL_VObj_18_f8ef8c_m5(_self) (((VObj_18_f8ef8c *)(_self))->m5())
}


struct O_8006A044 { u8 pad[0x1c0]; s32 shake_timer; f32 shake_amplitude; };

struct Big_8006A13C { u8 pad[0x70]; u8 unk70[0x10]; };

struct Sel_8006A13C { u8 busy; u8 pad1; u16 slot; u8 pad4[0x8]; };
extern "C" {



s32 TWindowShortListCtrl__check_controller_button(void *, s32);
s32 is_on_current_screen__11TCameraCtrlFv(void *, s32);
extern Big_8006A13C controller_input_state;
}


struct Vec_8006AF9C { f32 x, y, z; };

struct Obj_8006AF9C {
    u8 pad0[0x19c];
    s32 fov;
};

void set_camera_look_at(u8 *eye, u8 *target, u8 *up);
extern "C" {


f32 vec_squared_length(void *);
}

extern void *lbl_80488AC0[6];

struct A_8006A35C { s8 f0; u8 pad1; s16 f2; s32 f4; s32 f8; };
struct B_8006A35C { u8 pad[8]; f32 f8; f32 fc; u8 pad10[8]; f32 f18; u8 pad1c[0xC]; f32 f28; f32 f2c; f32 f30; f32 f34; f32 f38; f32 f3c; f32 f40; f32 f44; };
struct C_8006A35C { f32 f0; f32 f4; f32 f8; };
#define camera_controller_registry (*(RecoveredGlobal_8006A788_camera_controller_registry *)camera_controller_registry)
extern "C" {


void TCameraCtrl__sub_80068358(void *, void *, f32, f32);
extern s32 camera_view_state_flag;
extern s8 camera_ctrl_view_state_byte;
}

struct RecoveredGlobal_8006A5DC_TCameraCtrl__data_804FF628 {
    u8 value;
    u8 remaining[0xB];
};
struct RecoveredGlobal_8006A788_camera_controller_registry
{
  s32 value;
  u8 remaining[0x64];
};

struct RecoveredGlobal_8006A788_TCameraCtrl__data_804FF628
{
  s8 value;
  u8 remaining[0xB];
};

struct VBase_18_9639c7
{
  char pad[0x18];
};

struct VObj_18_9639c7 : VBase_18_9639c7 {
    virtual void m0();
    virtual s32 m1();
    virtual void m2();
    virtual void m3();
    virtual s32 m4(s32);
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual s32 m9();
};

struct RecoveredGlobal_8006A7D8_camera_controller_registry
{
  s32 value;
  u8 remaining[0x64];
};

struct RecoveredGlobal_8006A7D8_TCameraCtrl__data_804FF628
{
  s32 value;
  u8 remaining[0x8];
};

struct RecoveredGlobal_8006A5EC_camera_controller_registry
{
  s32 value;
  u8 remaining[0x64];
};

struct RecoveredGlobal_8006A5EC_TCameraCtrl__data_804FF628
{
  s8 value;
  u8 remaining[0xB];
};

struct Vec_8006A410
{
  f32 x;
  f32 y;
  f32 z;
};

struct VBase_8006A410
{
  char pad[0x18];
};

struct Ctrl_8006A410 : VBase_8006A410 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6(void *);
    u8 pad1C[0x3C - 0x1C];
    Vec_8006A410 pos;
    Vec_8006A410 tgt;
};

struct Master_8006A410
{
  u8 pad[0xD4];
  Vec_8006A410 pos[4];
  Vec_8006A410 tgt[4];
};

struct Views_8006A410
{
  u8 pad[0x10];
  s32 players[4];
};
extern "C" {



s32 apply_camera_controller_pose(int);
s32 resolve_anchor_obstruction__11TCameraCtrlFv(void *, int);
s32 clamp_to_target_obstruction__11TCameraCtrlFv(void *, int);
void reset__11TCameraCtrlFv(void);
void TCameraCtrl__sub_80068354(void);
}

void select_camera_controller(s32 arg0);
typedef char RecoveredGlobal_8006A5DC_TCameraCtrl__data_804FF628_size[sizeof(RecoveredGlobal_8006A5DC_TCameraCtrl__data_804FF628) == 0xC ? 1 : -1];

typedef struct Ctrl_8006A410 Ctrl_8006A410;
typedef struct Master_8006A410 Master_8006A410;
typedef struct VBase_8006A410 VBase_8006A410;
typedef struct Vec_8006A410 Vec_8006A410;
typedef struct Views_8006A410 Views_8006A410;
extern "C" {

typedef struct RecoveredGlobal_8006A788_TCameraCtrl__data_804FF628 RecoveredGlobal_8006A788_TCameraCtrl__data_804FF628;
typedef struct RecoveredGlobal_8006A788_camera_controller_registry RecoveredGlobal_8006A788_camera_controller_registry;
typedef struct VBase_18_f8ef8c VBase_18_f8ef8c;
typedef struct VObj_18_f8ef8c VObj_18_f8ef8c;
typedef char RecoveredGlobal_8006A788_camera_controller_registry_size[((sizeof(RecoveredGlobal_8006A788_camera_controller_registry)) == 0x68) ? (1) : (-1)];
typedef char RecoveredGlobal_8006A788_TCameraCtrl__data_804FF628_size[((sizeof(RecoveredGlobal_8006A788_TCameraCtrl__data_804FF628)) == 0xC) ? (1) : (-1)];

typedef struct RecoveredGlobal_8006A5EC_TCameraCtrl__data_804FF628 RecoveredGlobal_8006A5EC_TCameraCtrl__data_804FF628;
typedef struct RecoveredGlobal_8006A5EC_camera_controller_registry RecoveredGlobal_8006A5EC_camera_controller_registry;
typedef char RecoveredGlobal_8006A5EC_camera_controller_registry_size[((sizeof(RecoveredGlobal_8006A5EC_camera_controller_registry)) == 0x68) ? (1) : (-1)];
typedef char RecoveredGlobal_8006A5EC_TCameraCtrl__data_804FF628_size[((sizeof(RecoveredGlobal_8006A5EC_TCameraCtrl__data_804FF628)) == 0xC) ? (1) : (-1)];

struct Cam_8006A6C4
{
  u8 pad0[0x68];
  f32 shake_offset_x;
  f32 shake_offset_y;
  f32 shake_offset_z;
  u8 pad74[0x1C0 - 0x74];
  u32 shake_timer;
  f32 shake_amplitude;
};
f32 sin_table_lookup(s32);
}

typedef struct RecoveredGlobal_8006A7D8_TCameraCtrl__data_804FF628 RecoveredGlobal_8006A7D8_TCameraCtrl__data_804FF628;
typedef struct RecoveredGlobal_8006A7D8_camera_controller_registry RecoveredGlobal_8006A7D8_camera_controller_registry;
typedef struct VBase_18_9639c7 VBase_18_9639c7;
typedef struct VObj_18_9639c7 VObj_18_9639c7;
typedef char RecoveredGlobal_8006A7D8_camera_controller_registry_size[((sizeof(RecoveredGlobal_8006A7D8_camera_controller_registry)) == 0x68) ? (1) : (-1)];
typedef char RecoveredGlobal_8006A7D8_TCameraCtrl__data_804FF628_size[((sizeof(RecoveredGlobal_8006A7D8_TCameraCtrl__data_804FF628)) == 0xC) ? (1) : (-1)];
#undef camera_controller_registry
#define PSO_VCALL_VObj_18_9639c7_m1(_self) (((VObj_18_9639c7 *)(_self))->m1())
#define PSO_VCALL_VObj_18_9639c7_m4(_self, _arg0) (((VObj_18_9639c7 *)(_self))->m4((_arg0)))
#define PSO_VCALL_VObj_18_9639c7_m9(_self) (((VObj_18_9639c7 *)(_self))->m9())
#define camera_controller_registry ((Ctl_8006AA90 **)camera_controller_registry)
#define lbl_80488AC0 ((u8 *)lbl_80488AC0)

struct Ctl_8006AA90 {
    u8 pad[0x18];
    virtual ~Ctl_8006AA90();
};
extern "C" {



void __dt__7TObjectFv(void *, s32);
void __dl__7TObjectFPv(void *);
Ctl_8006AA90 *TCameraCtrl__sub_8006AA90(Ctl_8006AA90 *self, s16 arg1);
}


#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#undef camera_controller_registry
#undef lbl_80488AC0
struct ByteBlock_30 { u8 bytes[0x30]; };

struct RecoveredGlobal_8006ABAC_lbl_8058D490 {
    s32 value;
    u8 remaining[0x2C];
};

struct RecoveredGlobal_8006AC70_lbl_804FF61C {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_8006AC70_lbl_8058D490 {
    s32 value;
    u8 remaining[0x2C];
};

struct Vec_8006B0D4 { f32 x, y, z; };
struct Count_8006B0D4 {
    s8 flag;
    s32 count;
    u8 pad8[0x8];
};
struct Cam_8006B0D4 {
    const char *name;
    u8 pad4[0x14];
    void *vt;
    s8 f1C;
    s32 f20;
    s32 f24;
    s32 f28;
    f32 f2C;
    f32 f30;
    s32 f34;
    f32 f38[10];
    u8 pad60[0x4];
    s16 f64;
    Vec_8006B0D4 shake_offset;
    f32 f74;
    f32 f78;
    f32 f7C;
    f32 f80;
    u8 pad84[0x8];
    s32 f8C;
    s32 f90;
    s32 view_yaw[4];
    Vec_8006B0D4 view_pos[4];
    Vec_8006B0D4 split_pos[4];
    Vec_8006B0D4 split_tgt[4];
    Vec_8006B0D4 split_look[4];
    s32 split_obstructed[4];
    s32 obstructed;
    Vec_8006B0D4 pos;
    Vec_8006B0D4 tgt;
    s32 pitch;
    s32 yaw;
    s32 roll;
    s32 fov;
    Vec_8006B0D4 eye;
    Vec_8006B0D4 at;
    f32 eye_rate;
    f32 at_rate;
    s32 shake_timer;
    u8 pad1C4[0x4];
    Vec_8006B0D4 look;
};
extern "C" {



u8 * copy_view_params__11TCameraCtrlFii(C30_8006AD34 *arg0, const C30_8006AD34 *arg1);
extern Cam_80068958 chr_select_request_buffer;
s32 rotate_matrix_y(int, void *);
s32 rotate_matrix_x(int, void *);
s32 push_matrix_from(void *);
f32 rotate_vector_by_current_matrix(void *, void *);
extern RecoveredGlobal_8006ABAC_lbl_8058D490 identity_matrix;
struct V3_8006AD34 { f32 x, y, z; };
u8 *get_target__11TCameraCtrlFv(void *);
s32 reset_view_flags__11TCameraCtrlFv(void *);
s32 cycle_spectate_target__11TCameraCtrlFv(void *);
int TCameraCtrl__sub_8006B370(f32);
int is_quest_active(void);
int TCameraCtrl__sub_8006B3B8(void* p);
void render__11TCameraCtrlFv(void *arg0);
int reset_to_local_player__11TCameraCtrlFv(void*);
int set_fixed_position_and_target__11TCameraCtrlFPUcPUc(void*);


void *TCameraCtrl__vt0(void);

void *TCameraCtrl__vt10(void);

void *TCameraCtrl__vt11(void);

void *TCameraCtrl__vt12(void);

void *TCameraCtrl__vt4(void);

void *TCameraCtrl__vt5(void);

void *TCameraCtrl__vt6(void);

void *TCameraCtrl__vt7(void);

void *TCameraCtrl__vt9(void);

void render_shadows__7TObjectFv();
void __ct__7TObjectFP7TObject(void *, void *);
void run_task__11TCameraCtrlFv(u8 *arg0);
void *camera_controller_registry[13] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0,
};
void *lbl_80488A8C[13] = {
    (void *)&TCameraCtrl__vt0, (void *)&TCameraCtrl__vt0, (void *)&TCameraCtrl__vt0, (void *)&TCameraCtrl__vt0,
    (void *)&TCameraCtrl__vt4, (void *)&TCameraCtrl__vt5, (void *)&TCameraCtrl__vt6, (void *)&TCameraCtrl__vt7,
    (void *)&CreationCamera::create, (void *)&TCameraCtrl__vt9, (void *)&TCameraCtrl__vt10, (void *)&TCameraCtrl__vt11,
    (void *)&TCameraCtrl__vt12,
};
void *lbl_80488AC0[6] = {
    (void *)0x0, (void *)0x0, (void *)&TCameraCtrl__sub_8006AA90, (void *)&run_task__11TCameraCtrlFv,
    (void *)&render__11TCameraCtrlFv, (void *)&render_shadows__7TObjectFv,
};

    extern int camera_split_screen_selector;
typedef char RecoveredGlobal_8006ABAC_lbl_804FF61C_size[sizeof(RecoveredGlobal_8006ABAC_lbl_804FF61C) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_8006ABAC_lbl_8058D490_size[sizeof(RecoveredGlobal_8006ABAC_lbl_8058D490) == 0x30 ? 1 : -1];
typedef char RecoveredGlobal_8006AC70_lbl_804FF61C_size[sizeof(RecoveredGlobal_8006AC70_lbl_804FF61C) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_8006AC70_lbl_8058D490_size[sizeof(RecoveredGlobal_8006AC70_lbl_8058D490) == 0x30 ? 1 : -1];

    extern int TCameraCtrl__camera_id;


    extern short TCameraCtrl__viewport_x;
    extern short TCameraCtrl__viewport_y;

    extern int quest_active_flag;

int TCameraCtrl__sub_8006B3B8(void* p) { return set_fixed_position_and_target__11TCameraCtrlFPUcPUc(p); }

int TCameraCtrl::reset_battle_camera() { return reset_to_local_player__11TCameraCtrlFv(this); }

int TCameraCtrl__sub_8006B370(f32 farg0) {
    u32 v = *(u32 *)&farg0 & 0x7F800000;
    return v == 0x7F800000;
}
int is_quest_active(void) {  return quest_active_flag; }
s32 get_mode__11TCameraCtrlFPv(void* p) { return *(s32*)((char*)p + 0x1c); }

s32 TCameraCtrl__sub_8006B358(void *p) { return *(u16*)((char*)p + 0x20); }
void TCameraCtrl::set_target_coords(int a0, int a1) { TCameraCtrl__viewport_x = a0; TCameraCtrl__viewport_y = a1; }
void TCameraCtrl::set_target(int a0, int a1) { TCameraCtrl__viewport_size = a0; TCameraCtrl__viewport_height = a1; }
int TCameraCtrl::get_camera_id() {  return TCameraCtrl__camera_id; }

int TCameraCtrl::get_instance() {  return camera_split_screen_selector; }

Cam_80068958 *get_character_select_request_buffer(void) {
    return &chr_select_request_buffer;
}
#define self ((Cam_8006B0D4 *)arg0)
#pragma push
#pragma opt_common_subs off
u8 *TCameraCtrl__ct(u8 *arg0, void *parent) {
    s32 i;
    s32 k;
    s32 j;

    __ct__7TObjectFP7TObject(arg0, parent);
    self->vt = (void **)lbl_80488AC0;
    self->name = lbl_805D283C;
    self->f1C = 0;
    camera_ctrl_instance = arg0;
    self->fov = 0x3555;
    self->f90 = 0;
    self->obstructed = 0;
    self->look.x = 0.0f;
    self->look.y = 0.0f;
    self->look.z = 0.0f;
    for (i = 0; i < 4; i++) {
        self->view_yaw[i] = 0;
        self->view_pos[i].x = 0.0f;
        self->view_pos[i].y = 0.0f;
        self->view_pos[i].z = 0.0f;
        self->split_look[i].x = 0.0f;
        self->split_look[i].y = 0.0f;
        self->split_look[i].z = 0.0f;
        self->split_obstructed[i] = 0;
    }
    self->pos.x = 0.0f;
    self->pos.y = 0.0f;
    self->pos.z = 0.0f;
    self->eye.x = 0.0f;
    self->eye.y = 0.0f;
    self->eye.z = 0.0f;
    self->tgt.x = 0.0f;
    self->tgt.y = 0.0f;
    self->tgt.z = 0.0f;
    self->at.x = 0.0f;
    self->at.y = 0.0f;
    self->at.z = 0.0f;
    self->pitch = 0;
    self->yaw = 0;
    self->roll = 0;
    self->shake_timer = 0;
    self->eye_rate = 0.0f;
    self->at_rate = 0.0f;
    self->f8C = 0;
    self->shake_offset.x = 0.0f;
    self->shake_offset.y = 0.0f;
    self->shake_offset.z = 0.0f;
    self->f20 = 0;
    self->f24 = 0;
    self->f28 = 0;
    self->f2C = 0.0f;
    self->f30 = 0.0f;
    self->f34 = 0;
    self->f64 = 0;
    self->f38[0] = 0.0f;
    self->f38[1] = 0.0f;
    self->f38[2] = 0.0f;
    self->f38[3] = 0.0f;
    self->f38[4] = 0.0f;
    self->f38[5] = 0.0f;
    self->f38[6] = 0.0f;
    self->f38[7] = 0.0f;
    self->f38[8] = 0.0f;
    self->f38[9] = 0.0f;
    self->f74 = 0.0f;
    self->f78 = 0.0f;
    self->f7C = 0.0f;
    self->f80 = 0.0f;
    self->f80 = 0.0f;
    self->f80 = 0.0f;
    {
        for (k = 0; k < 13; k++) {
            ((s32 *)camera_controller_registry)[(*(Count_8006B0D4 *)TCameraCtrl__view_state).count++] = ((s32 (**)(void))lbl_80488A8C)[k]();
        }
    }
    (*(Count_8006B0D4 *)TCameraCtrl__view_state).flag = 0;
    for (j = 0; j < 4; j++) {
        self->split_pos[j].x = 0.0f;
        self->split_pos[j].y = 0.0f;
        self->split_pos[j].z = 0.0f;
        self->split_tgt[j].x = 0.0f;
        self->split_tgt[j].y = 0.0f;
        self->split_tgt[j].z = 0.0f;
    }
    lbl_804FF5E8[0] = 0.0f;
    lbl_804FF5E8[1] = 0.0f;
    lbl_804FF5E8[2] = 0.0f;
    lbl_804FF5E8[3] = 0.0f;
    lbl_804FF5E8[4] = 0.0f;
    lbl_804FF5E8[5] = -1.0f;
    return arg0;
}
#pragma pop

void TCameraCtrl::setup_default_view(void *arg1_arg) {
    Vec_8006AF9C *arg1 = (Vec_8006AF9C *)arg1_arg;
    Vec_8006AF9C eye;
    Vec_8006AF9C at;
    Vec_8006AF9C d;
    Vec_8006AF9C *pat;
    eye.x = lbl_804FF5E8[0];
    eye.y = lbl_804FF5E8[1];
    eye.z = lbl_804FF5E8[2];
    if (arg1 != 0) {
        eye.x += arg1->x;
        eye.y += arg1->y;
        eye.z += arg1->z;
    }
    at.x = lbl_804FF5E8[3] + eye.x;
    at.y = lbl_804FF5E8[4] + eye.y;
    at.z = lbl_804FF5E8[5] + eye.z;
    d.x = eye.x - at.x;
    d.y = eye.y - at.y;
    d.z = eye.z - at.z;
    pat = &at;
    if (0.0f == vec_squared_length(&d)) {
        pat->z += 1.0f;
    }
    if (0.0f == d.x && 0.0f == d.z) {
        pat->z += 1.0f;
    }
    set_perspective_projection_from_fov(((Obj_8006AF9C *)this)->fov, 1.1333334f, 1.0f, 21000.0f);
    set_camera_look_at((u8 *)&eye, (u8 *)&at, (u8 *)TCameraCtrl__up_vector);
}
#undef self

u8 * copy_view_params__11TCameraCtrlFii(C30_8006AD34 *arg0, const C30_8006AD34 *arg1) {
    *(ByteBlock_30 *)(arg0) = *(const ByteBlock_30 *)(arg1);
    return (u8 *)arg0;
}
#define ISNAN(x) TCameraCtrl__sub_8006B370(x)
#define G (camera_ctrl_instance)
#define GF(o) (*(f32 *)(G + (o)))
void TCameraCtrl::run_task() {
    u8 *arg0 = (u8 *)this;
    V3_8006AD34 v;
    u8 *t;
    s32 i;
    s32 off;

    arg0[0x1C] = 1;
    ((TCameraCtrl *)arg0)->update_target_from_state();
    cycle_spectate_target__11TCameraCtrlFv(arg0);
    ((TCameraCtrl *)arg0)->update_active_controller();
    reset_view_flags__11TCameraCtrlFv(arg0);
    if (G != NULL) {
        if (ISNAN(GF(0x178)) == 0 && ISNAN(GF(0x17C)) == 0) {
            ISNAN(GF(0x180));
        }
        if (ISNAN(GF(0x178)) == 0 && ISNAN(GF(0x17C)) == 0) {
            ISNAN(GF(0x180));
        }
        if (ISNAN(GF(0x184)) == 0 && ISNAN(GF(0x188)) == 0) {
            ISNAN(GF(0x18C));
        }
    }
    if (G != NULL) {
        t = get_target__11TCameraCtrlFv(arg0);
        v.x = (((f32 *)t)[0] + GF(0x184)) - GF(0x178);
        v.y = (((f32 *)t)[1] + GF(0x188)) - GF(0x17C);
        v.z = (((f32 *)t)[2] + GF(0x18C)) - GF(0x180);
        lbl_804FF5E8[0] = *(f32 *)(arg0 + 0x178);
        lbl_804FF5E8[1] = *(f32 *)(arg0 + 0x17C);
        lbl_804FF5E8[2] = *(f32 *)(arg0 + 0x180);
        if (0.0f != vec_squared_length(&v)) {
            normalize_vector(&v);
        }
        lbl_804FF5E8[3] = v.x;
        lbl_804FF5E8[4] = v.y;
        lbl_804FF5E8[5] = v.z;
        vector_length(&v);
    }
    if (is_split_screen() != 0) {
        if (TCameraCtrl__view_state[0] == 5) {
            ((TObjBoss2Tunnel *)lbl_804FF5E8)->render(&TCameraCtrl__view_matrices[TCameraCtrl::get_camera_no()]);
            for (i = 1; i < 4; i++) {
                copy_view_params__11TCameraCtrlFii(&TCameraCtrl__view_matrices[i], &TCameraCtrl__view_matrices[0]);
            }
        } else {
            ((TObjBoss2Tunnel *)lbl_804FF5E8)->render(&TCameraCtrl__view_matrices[TCameraCtrl::get_camera_no()]);
        }
    } else {
        ((TObjBoss2Tunnel *)lbl_804FF5E8)->render(TCameraCtrl__view_matrix);
    }
    ((TCameraCtrl *)arg0)->calc_rotated_axes();
}
#undef ISNAN
#undef G
#undef GF
#pragma push
#pragma opt_common_subs off
void TCameraCtrl::calc_rotated_axes() {
    Vec right = {1.0f, 0.0f, 0.0f};
    Vec up = {0.0f, 1.0f, 0.0f};
    push_matrix_from((void *) (&(*(RecoveredGlobal_8006AC70_lbl_8058D490 *)&identity_matrix).value));
    rotate_matrix_y(0, (void *)this->yaw);
    rotate_vector_by_current_matrix((void *)&right, (void *)camera_right);
    pop_matrix();
    push_matrix_from((void *) (&(*(RecoveredGlobal_8006AC70_lbl_8058D490 *)&identity_matrix).value));
    rotate_matrix_x(0, (void *)this->pitch);
    rotate_vector_by_current_matrix((void *)&up, (void *) (&(*(RecoveredGlobal_8006AC70_lbl_804FF61C *)&camera_pitch_rotated_up_vector).value));
    pop_matrix();
}
#pragma pop
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void TCameraCtrl::calc_axes_from_angles(s32 arg0, s32 arg1, s32 arg2) {
    Vec right = {1.0f, 0.0f, 0.0f};
    Vec up = {0.0f, 1.0f, 0.0f};
    push_matrix_from((void *)&identity_matrix.value);
    rotate_matrix_y(0, (void *)arg2);
    rotate_vector_by_current_matrix((void *)&right, (void *)camera_right);
    pop_matrix();
    push_matrix_from((void *)&identity_matrix.value);
    rotate_matrix_x(0, (void *)arg1);
    rotate_vector_by_current_matrix((void *)&up, (void *)&camera_pitch_rotated_up_vector.value);
    pop_matrix();
}
#pragma pop

void TCameraCtrl::render() {
    if ((is_split_screen() == 0) && (TMainTask::get_render_pass() != 1)) {
        if ((u8) *(u8 *)((s8 *)this + 0x1C) == 0) {
            setup_default_view((Vec_8006AF9C *)(0));
        }
        *(u8 *)((s8 *)this + 0x1C) = 0U;
    }
}
#define camera_controller_registry ((Ctl_8006AA90 **)camera_controller_registry)
#define lbl_80488AC0 ((u8 *)lbl_80488AC0)
Ctl_8006AA90 *TCameraCtrl__sub_8006AA90(Ctl_8006AA90 *self, s16 arg1) {
    s32 i;
    if (self != NULL) {
        *(u8 **)((u8 *)self + 0x18) = lbl_80488AC0;
        (*(s32 *)&camera_ctrl_instance) = 0;
        for (i = 0; i < 13; i++) {
            if (camera_controller_registry[i] != NULL) {
                delete camera_controller_registry[i];
                camera_controller_registry[i] = NULL;
            }
        }
        ((s32 *)&TCameraCtrl__view_state)[1] = 0;
        __dt__7TObjectFv(self, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(self);
        }
    }
    return self;
}


void TCameraCtrl::update_target_from_state() {
    if ((!(*(s32 *)((s8 *)TCameraCtrl__view_state + 8) & 4) && !(*(s32 *)((s8 *)TCameraCtrl__view_state + 8) & 8)) || (*(s32 *)((s8 *)TCameraCtrl__view_state + 8) & 0x20) || (*(s32 *)((s8 *)TCameraCtrl__view_state + 8) & 0x80) || (*(s32 *)((s8 *)TCameraCtrl__view_state + 8) & 0x800)) {
        if (*(s32 *)((s8 *)TCameraCtrl__view_state + 8) & 2) {
            select_camera_controller(this->m_20 + 9);
            return;
        }
        if ((*(s32 *)((s8 *)TCameraCtrl__view_state + 8) & 0x20) || (*(s32 *)((s8 *)TCameraCtrl__view_state + 8) & 0x80)) {
            select_camera_controller(*(u8 *)((s8 *)TCameraCtrl__view_state + 1));
            u32 temp = (u32)get_player_by_client_id(local_client_id);
            if (temp != 0U) {
                reset_cameras_to_actor((void *)temp, 0);
            }
        }
    }
}
#undef camera_controller_registry
#undef lbl_80488AC0
#define camera_controller_registry (*(RecoveredGlobal_8006A788_camera_controller_registry *)camera_controller_registry)
}


void TCameraCtrl::update_active_controller() {
  s32 temp_r3;
  s32 var_r27;
  s32 camera_no;
  s32 *new_var;
  u8 *temp_r30;
  if (((u8) (*((u8 *) (((s8 *) (&(*(RecoveredGlobal_8006A7D8_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value)) + 0)))) != 0)
  {
    camera_no = 0;
  }
  else
    if (is_split_screen() != 0)
  {
    camera_no = TCameraCtrl::get_camera_no();
  }
  else
  {
    camera_no = 0;
  }
  temp_r30 = (u8 *) (*((void **) (((s8 *) (((u8 *) (&(*(RecoveredGlobal_8006A7D8_camera_controller_registry *)&camera_controller_registry).value)) + (((*((u8 *) (((s8 *) (&(*(RecoveredGlobal_8006A7D8_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value)) + 0))) + camera_no) * 4))) + 0)));
  if (temp_r30 != 0)
  {
    if (!((*((s32 *) (((s8 *) (&(*(RecoveredGlobal_8006A7D8_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value)) + 8))) & 0x800))
    {
      PSO_VCALL_VObj_18_9639c7_m1(temp_r30);
    }
    if ((*((s32 *) (((s8 *) (&(*(RecoveredGlobal_8006A7D8_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value)) + 8))) & 2)
    {
      PSO_VCALL_VObj_18_9639c7_m4(temp_r30, 0);
    }
    else
      if ((*((s32 *) (((s8 *) (&(*(RecoveredGlobal_8006A7D8_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value)) + 8))) & 0x80)
    {
      PSO_VCALL_VObj_18_9639c7_m4(temp_r30, 1);
    }
    apply_camera_controller_pose((int) temp_r30);
    new_var = (s32 *) (((s8 *) (&(*(RecoveredGlobal_8006A7D8_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value)) + 8);
    var_r27 = 0;
    if (is_split_screen() != 0)
    {
      if ((((*new_var) & 0x20) || ((*new_var) & 0x800)) && (!((*new_var) & (0x1000 << camera_no))))
      {
        var_r27 = 1;
        *new_var = (s32) ((*((s32 *) (((s8 *) (&(*(RecoveredGlobal_8006A7D8_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value)) + 8))) & ((-0x1001) << camera_no));
      }
    }
    else
      if (((*new_var) & 0x20) || ((*((s32 *) (((s8 *) (&(*(RecoveredGlobal_8006A7D8_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value)) + 8))) & 0x800))
    {
      var_r27 = 1;
    }
    if (var_r27 != 0)
    {
      update_position();
    }
    else
    {
      if ((*((s32 *) (((s8 *) temp_r30) + 0x38))) & 1)
      {
        resolve_anchor_obstruction__11TCameraCtrlFv((void *) this, (int) temp_r30);
      }
      temp_r3 = *((s32 *) (((s8 *) temp_r30) + 0x38));
      if (temp_r3 & 4)
      {
        update_pose_smoothing();
      }
      else
        if (temp_r3 & 8)
      {
        update_target_smoothing();
      }
      else
      {
        update_position();
      }
      if ((*((s32 *) (((s8 *) temp_r30) + 0x38))) & 1)
      {
        clamp_to_target_obstruction__11TCameraCtrlFv((void *) this, (int) temp_r30);
      }
      update_shake();
    }
    set_perspective_projection_from_fov(this->fov, 1.1333334f, 1.0f, 21000.0f);
    PSO_VCALL_VObj_18_9639c7_m9(temp_r30);
    if (is_split_screen() == 0)
    {
      *((s32 *) (((s8 *) ((u8 *)this)) + 0x94)) = this->yaw;
    }
  }
}
#undef PSO_VCALL_VObj_18_9639c7_m1
#undef PSO_VCALL_VObj_18_9639c7_m4
#undef PSO_VCALL_VObj_18_9639c7_m9

void select_camera_controller(s32 arg0) {
  u8 *temp_r0;
  (*(RecoveredGlobal_8006A788_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value = arg0;
  temp_r0 = (u8 *) (*((s32 *) (((s8 *)&camera_controller_registry.value) + ((arg0 * 4) & 0x3FC))));
  if (temp_r0 != 0)
  {
    PSO_VCALL_VObj_18_f8ef8c_m5(temp_r0);
  }
}
extern "C" {

void TCameraCtrl::update_shake() {
  Cam_8006A6C4 *self = (Cam_8006A6C4 *) this;
  f32 amp;
  s32 k;
  if (self->shake_timer != 0) {
    self->shake_timer--;
    k = self->shake_timer * 40;
    amp = self->shake_amplitude * (f32)self->shake_timer;
    self->shake_offset_x = 0.0f;
    self->shake_offset_y = amp * sin_table_lookup((s32)(182.04445f * (f32)k));
    self->shake_offset_z = 0.0f;
  }
}
void TCameraCtrl::select_active_controller(s8 arg0) {
  f32 temp_f0;
  f32 temp_f0_2;
  f32 temp_f0_3;
  f32 temp_f0_4;
  f32 temp_f0_5;
  f32 temp_f0_6;
  u8 *temp_r31;
  (*(RecoveredGlobal_8006A5EC_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value = arg0;
  temp_r31 = (u8 *) (*((u8 **) (((s8 *) (((u8 *) (&(*(RecoveredGlobal_8006A5EC_camera_controller_registry *)&camera_controller_registry).value)) + ((arg0 * 4) & 0x3FC))) + 0)));
  if (temp_r31 != 0)
  {
    PSO_VCALL_VObj_18_f8ef8c_m5(temp_r31);
    if (((void *) camera_ctrl_instance) != 0)
    {
      temp_f0 = *((f32 *) (((s8 *) temp_r31) + 0x3C));
      *((f32 *) (((s8 *) camera_ctrl_instance) + 0x1A0)) = temp_f0;
      *((f32 *) (((s8 *) camera_ctrl_instance) + 0x178)) = temp_f0;
      temp_f0_2 = *((f32 *) (((s8 *) temp_r31) + 0x40));
      *((f32 *) (((s8 *) camera_ctrl_instance) + 0x1A4)) = temp_f0_2;
      *((f32 *) (((s8 *) camera_ctrl_instance) + 0x17C)) = temp_f0_2;
      temp_f0_3 = *((f32 *) (((s8 *) temp_r31) + 0x44));
      *((f32 *) (((s8 *) camera_ctrl_instance) + 0x1A8)) = temp_f0_3;
      *((f32 *) (((s8 *) camera_ctrl_instance) + 0x180)) = temp_f0_3;
      temp_f0_4 = *((f32 *) (((s8 *) temp_r31) + 0x48));
      *((f32 *) (((s8 *) camera_ctrl_instance) + 0x1AC)) = temp_f0_4;
      *((f32 *) (((s8 *) camera_ctrl_instance) + 0x184)) = temp_f0_4;
      temp_f0_5 = *((f32 *) (((s8 *) temp_r31) + 0x4C));
      *((f32 *) (((s8 *) camera_ctrl_instance) + 0x1B0)) = temp_f0_5;
      *((f32 *) (((s8 *) camera_ctrl_instance) + 0x188)) = temp_f0_5;
      temp_f0_6 = *((f32 *) (((s8 *) temp_r31) + 0x50));
      *((f32 *) (((s8 *) camera_ctrl_instance) + 0x1B4)) = temp_f0_6;
      *((f32 *) (((s8 *) camera_ctrl_instance) + 0x18C)) = temp_f0_6;
    }
  }
}


u16 TCameraCtrl__sub_8006A5DC(void) {
    return (*(RecoveredGlobal_8006A5DC_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value;
}
}

void reset_cameras_to_actor(void *actor, s32 arg1) {
  s32 view = 0;
  u16 new_var;
  s32 count = 0;
  Ctrl_8006A410 *c;
  s32 id;
  s32 i;
  if (actor == 0)
  {
    return;
  }
  new_var = (u16) get_entity_id(actor);
  id = new_var;
  if (is_split_screen() == 0)
  {
    view = 0;
  }
  else
  {
    Views_8006A410 *v = (Views_8006A410 *) get_character_select_request_buffer();
    for (i = 0; i < 4; i++)
    {
      s32 p = v->players[i];
      if (p == id)
      {
        view = count;
      }
      if (p >= 0)
      {
        count++;
      }
    }
  }
  c = ((Ctrl_8006A410 **) (&camera_controller_registry))[((u8) TCameraCtrl__view_state[0]) + view];
  if (c != 0)
  {
    if (is_split_screen() == 0)
    {
      *((void **) (((s8 *) camera_ctrl_instance) + 0x90)) = actor;
    }
    ((TUnk_80488A28 *)c)->set_target((u32)actor);
    c->m6(actor);
    if (is_split_screen() != 0)
    {
      *((s32 *) (((s8 *) TCameraCtrl__view_state) + 8)) |= 0x800;
      if (is_boss_area() == 0)
      {
        *((s32 *) (((s8 *) TCameraCtrl__view_state) + 8)) |= 0x1000;
        *((s32 *) (((s8 *) TCameraCtrl__view_state) + 8)) |= 0x2000;
        *((s32 *) (((s8 *) TCameraCtrl__view_state) + 8)) |= 0x4000;
        *((s32 *) (((s8 *) TCameraCtrl__view_state) + 8)) |= 0x8000;
        *((s32 *) (((s8 *) TCameraCtrl__view_state) + 8)) &= (-0x1001) << view;
      }
    }
    else
    {
      *((s32 *) (((s8 *) TCameraCtrl__view_state) + 8)) |= 0x800;
    }
  }
  c = ((Ctrl_8006A410 **) (&camera_controller_registry))[view];
  if (c != 0)
  {
    ((TUnk_80488A28 *)c)->set_target((u32)actor);
    c->m6(actor);
  }
  if (camera_ctrl_instance != 0)
  {
    VecCopy((Vec *)(&((Master_8006A410 *) camera_ctrl_instance)->pos[view]), (const Vec *)&c->pos);
    VecCopy((Vec *)(&((Master_8006A410 *) camera_ctrl_instance)->tgt[view]), (const Vec *)&c->tgt);
  }
}
extern "C" {

void TCameraCtrl::reset_view_state() {
    A_8006A35C *pa = (A_8006A35C *)TCameraCtrl__view_state;
    B_8006A35C *pb = (B_8006A35C *)TCameraCtrl__data_804FF634;
    C_8006A35C *pc;

    TCameraCtrl__pose_snap_flags = 0;
    ((A_8006A35C *)TCameraCtrl__view_state)->f0 = 0;
    pa->f2 = 0;
    pa->f4 = 0;
    pa->f8 = 0;
    pb->f18 = 0.0f;
    pb->f28 = 0.0f;
    pb->f2c = 0.0f;
    pb->f8 = 0.0f;
    pb->fc = 0.0f;
    pb->f30 = 0.0f;
    pb->f34 = 0.0f;
    pb->f38 = 0.0f;
    pb->f3c = 0.0f;
    pb->f40 = 1.0f;
    pb->f44 = 0.85f;
    TCameraCtrl__sub_80068358(pb, pa, 1.0f, 0.0f);
    ((C_8006A35C *)TCameraCtrl__up_vector)->f0 = 0.0f;
    pc = (C_8006A35C *)TCameraCtrl__up_vector;
    pc->f4 = 1.0f;
    pc->f8 = 0.0f;
    camera_view_state_flag = 0;
    camera_ctrl_view_state_byte = -1;
    TCameraCtrl__data_805D4E0A = 0;
}


void reset__11TCameraCtrlFv(void) {
    TCameraCtrl__data_805D4E0A = 0;
    TCameraCtrl__sub_80068354();
    *(s8 *)((s8 *)TCameraCtrl__view_state + 0) = 0;
    *(s16 *)((s8 *)TCameraCtrl__view_state + 2) = 0;
    *(s32 *)((s8 *)TCameraCtrl__view_state + 4) = 0;
    *(s32 *)((s8 *)TCameraCtrl__view_state + 8) = 0;
}
#undef camera_controller_registry
void TCameraCtrl::cycle_spectate_target() {
    void *pad;
    TObjPlayer *q;
    TObjPlayer *pl;
    s8 tries;
    u16 slot;
    s32 i;
    if (is_split_screen() != 0 || is_quest_active() != 0) {
        return;
    }
    pad = controller_input_state.unk70;
    if (is_on_current_screen__11TCameraCtrlFv(pad, 0x20000) == 0 ||
        TWindowShortListCtrl__check_controller_button(pad, 0x10) == 0 ||
        is_on_current_screen__11TCameraCtrlFv(pad, 0x10000) == 0 ||
        (pl = get_player_by_client_id(local_client_id)) == 0 ||
        (tries = 0, TCameraCtrl__view_state[0] != 0) ||
        get_current_floor_area() == AREA_DRAGON ||
        get_current_floor_area() == AREA_DE_ROL_LE ||
        get_current_floor_area() == AREA_VOL_OPT ||
        get_current_floor_area() == AREA_DARK_FALZ ||
        get_current_floor_area() == AREA_GAL_GRYPHON ||
        get_current_floor_area() == AREA_OLGA_FLOW ||
        get_current_floor_area() == AREA_BARBA_RAY ||
        get_current_floor_area() == AREA_GOL_DRAGON ||
        get_current_floor_area() == AREA_LOBBY ||
        get_current_floor_area() == AREA_PIONEER2_EP2 ||
        get_current_floor_area() == AREA_PIONEER2_EP1) {
        return;
    }
    slot = ((Sel_8006A13C *)TCameraCtrl__view_state)->slot;
    while (tries <= 3) {
        slot++;
        tries++;
        if (slot >= 4) {
            slot = 0;
        }
        q = get_player_by_client_id(slot);
        if (q != 0) {
            if (q->get_floor() == pl->get_floor() && q->obj_testFlags30(0x02000000) == 0) {
                ((Sel_8006A13C *)TCameraCtrl__view_state)->slot = slot;
                reset_cameras_to_actor(q, 0);
                for (i = 0; i < 4; i++) {
                    TObjPlayer *p = get_player_by_client_id(i);
                    if (p != 0) {
                        p->refresh_equipment_slot();
                    }
                }
                return;
            }
        }
    }
}

void TCameraCtrl::set_shake_preset(s32 arg0) {
    void *p;

    if ((void *) camera_ctrl_instance != NULL) {
        switch (arg0) {
        case 0:
            *(s32 *)((s8 *)camera_ctrl_instance + 0x1C0) = 0x14;
            p = camera_ctrl_instance;
            *(f32 *)((s8 *)p + 0x1C4) = 0.0175f;
            start_pad_rumble_all(0x60, 0x14);
            return;
        case 1:
            *(s32 *)((s8 *)camera_ctrl_instance + 0x1C0) = 0x1E;
            p = camera_ctrl_instance;
            *(f32 *)((s8 *)p + 0x1C4) = 0.175f;
            start_pad_rumble_all(0xA0, 0x1E);
            return;
        case 2:
            *(s32 *)((s8 *)camera_ctrl_instance + 0x1C0) = 0x1E;
            p = camera_ctrl_instance;
            *(f32 *)((s8 *)p + 0x1C4) = 0.05f;
            start_pad_rumble_all(0xE0, 0x1E);
            break;
        }
    }
}


void TCameraCtrl__sub_8006A044(s32 id, f32 v) {
    O_8006A044 *p;
    if ((*(O_8006A044 * *)&camera_ctrl_instance) != 0) {
        (*(O_8006A044 * *)&camera_ctrl_instance)->shake_amplitude = v;
        p = (*(O_8006A044 * *)&camera_ctrl_instance);
        p->shake_timer = id;
        start_pad_rumble_all(0x60, id);
    }
}
void*TCameraCtrl::get_params() { return (char*)this + 0x20; }
#define CAM_80069F20 ((Cam_80069F20 *)&TCameraCtrl__view_state)
#define OUT_80069F20 ((Out_80069F20 *)camera_ctrl_instance)

void TCameraCtrl::reset_view_flags() {
    Cam_80069F20 *c = CAM_80069F20;
    f32 v;

    c->flags &= ~0x20;
    c->flags &= ~0x80;
    c->flags &= ~0x800;
    if (c->flags & 2) {
        c->flags &= ~2;
        c->flags |= 0x100;
    } else if (c->flags & 0x100) {
        c->flags |= 0x80;
        c->flags &= ~0x100;
    }
    if (c->flags & 0x40) {
        c->flags &= ~0x40;
    }
    if (c->flags & 0x100) {
        return;
    }
    if (c->flags & 0x80) {
        return;
    }
    if (camera_ctrl_instance == 0) {
        return;
    }
    v = 0.0f;
    OUT_80069F20->f20 = 0;
    OUT_80069F20->f24 = 0;
    OUT_80069F20->f28 = 0;
    OUT_80069F20->f2c = v;
    OUT_80069F20->f30 = v;
    OUT_80069F20->f34 = 0;
    OUT_80069F20->f64 = 0;
    OUT_80069F20->f38 = v;
    OUT_80069F20->f3c = v;
    OUT_80069F20->f40 = v;
    OUT_80069F20->f44 = v;
    OUT_80069F20->f48 = v;
    OUT_80069F20->f4c = v;
    OUT_80069F20->f50 = v;
    OUT_80069F20->f54 = v;
    OUT_80069F20->f58 = v;
    OUT_80069F20->f5c = v;
}
#undef CAM_80069F20
#undef OUT_80069F20

s32 activate_camera_mode(s32 arg0) {
  u8 *temp_r3;
  short new_var;
  if ((*((s32 *) (((s8 *) (&(*(RecoveredGlobal_80069E7C_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value)) + 8))) & 4)
  {
    return 0;
  }
  *((s32 *) (((s8 *) (&(*(RecoveredGlobal_80069E7C_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value)) + 8)) = *((s32 *) (((s8 *) (&(*(RecoveredGlobal_80069E7C_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value)) + 8));
  new_var = 8;
  *((s32 *) (((s8 *) (&(*(RecoveredGlobal_80069E7C_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value)) + new_var)) = (*((s32 *) (((s8 *) (&(*(RecoveredGlobal_80069E7C_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value)) + new_var))) | 4;
  if (arg0 == (*((u8 *) (((s8 *) (&(*(RecoveredGlobal_80069E7C_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value)) + 0))))
  {
    *((u8 *) (((s8 *) (&(*(RecoveredGlobal_80069E7C_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value)) + 0)) = arg0;
  }
  else
  {
    if (((*((u8 *) (((s8 *) (&(*(RecoveredGlobal_80069E7C_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value)) + 0))) != 5) && ((*((u8 *) (((s8 *) (&(*(RecoveredGlobal_80069E7C_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value)) + 0))) != 9))
    {
      *((u8 *) (((s8 *) (&(*(RecoveredGlobal_80069E7C_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value)) + 1)) = *((u8 *) (((s8 *) (&(*(RecoveredGlobal_80069E7C_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value)) + 0));
    }
    *((u8 *) (((s8 *) (&(*(RecoveredGlobal_80069E7C_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value)) + 0)) = arg0;
  }
  temp_r3 = (u8 *) (*((void **) (((s8 *) (((u8 *) (&(*(RecoveredGlobal_80069E7C_camera_controller_registry *)&camera_controller_registry).value)) + ((*((u8 *) (((s8 *) (&(*(RecoveredGlobal_80069E7C_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value)) + 0))) * 4))) + 0)));
  if (temp_r3 != 0)
  {
    PSO_VCALL_VObj_18_f8ef8c_m5(temp_r3);
  }
  return 1;
}

s32 restore_player_cameras(void) {
    s32 identity;
    TObjPlayer *player;
    if (*(u32 *)((s8 *)&TCameraCtrl__view_state + 8) & 4) {
        *(u32 *)((s8 *)&TCameraCtrl__view_state + 8) &= ~4;
        if (TCameraCtrl__sub_8006A5DC() == 5 && *(u8 **)((s8 *)&camera_controller_registry + 0x14) != NULL && TCameraCtrl__saved_projection_angle != 0) {
            *(s32 *)((s8 *)(*(u8 **)((s8 *)&camera_controller_registry + 0x14)) + 0x54) = TCameraCtrl__saved_projection_angle;
        }
        *(u32 *)((s8 *)&TCameraCtrl__view_state + 8) |= 0x20;
    }
    if (is_split_screen() != 0) {
        for (identity = 0; identity < 4; identity++) {
            player = get_player_by_client_id(identity);
            if (player != NULL) {
                reset_cameras_to_actor(player, 0);
            }
        }
    } else {
        player = get_player_by_client_id(local_client_id);
        if (player != NULL) {
            reset_cameras_to_actor(player, 0);
        }
    }
    return 0;
}
#undef PSO_VCALL_VObj_18_f8ef8c_m5
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
s32 TCameraCtrl::release_photon_blast_camera() {
    s32 temp_r0;
    if (*(s32 *)((s8 *)(&(*(RecoveredGlobal_80069D7C_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value) + 8) & 8) {
        temp_r0 = *(s32 *)((s8 *)(&(*(RecoveredGlobal_80069D7C_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value) + 8) & 0xFFFFFFF7;
        *(s32 *)((s8 *)(&(*(RecoveredGlobal_80069D7C_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value) + 8) = temp_r0;
        *(s32 *)((s8 *)(&(*(RecoveredGlobal_80069D7C_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value) + 8) = (s32) (temp_r0 | 0x20);
    }
    return 0;
}
#pragma pop
void set_active_camera_pose_from_params(u8 *arg0) {
    u8 *temp_r4;
    if ((*(s32 *)((s8 *)(&(*(RecoveredGlobal_80069D04_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value) + 8) & 8) || (*(s32 *)((s8 *)(&(*(RecoveredGlobal_80069D04_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value) + 8) & 4)) {
        temp_r4 = (u8 *)(*(s32 *)((s8 *)(&(*(RecoveredGlobal_80069D04_camera_controller_registry *)&camera_controller_registry).value) + (*(u8 *)((s8 *)(&(*(RecoveredGlobal_80069D04_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value) + 0) * 4)));
        if (temp_r4 != NULL) {
            *(f32 *)((s8 *)temp_r4 + 0x3C) = (f32) *(f32 *)((s8 *)arg0 + 0x1C);
            *(f32 *)((s8 *)temp_r4 + 0x40) = (f32) *(f32 *)((s8 *)arg0 + 0x20);
            *(f32 *)((s8 *)temp_r4 + 0x44) = (f32) *(f32 *)((s8 *)arg0 + 0x24);
            *(f32 *)((s8 *)temp_r4 + 0x48) = (f32) *(f32 *)((s8 *)arg0 + 0x28);
            *(f32 *)((s8 *)temp_r4 + 0x4C) = (f32) *(f32 *)((s8 *)arg0 + 0x2C);
            *(f32 *)((s8 *)temp_r4 + 0x50) = (f32) *(f32 *)((s8 *)arg0 + 0x30);
            *(s32 *)((s8 *)temp_r4 + 0x54) = (s32) *(s32 *)((s8 *)arg0 + 0x14);
        }
    }
}
void set_active_camera_pose(u8 *arg0, u8 *arg1) {
    u8 *temp_r5;
    if ((*(s32 *)((s8 *)(&(*(RecoveredGlobal_80069C94_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value) + 8) & 8) || (*(s32 *)((s8 *)(&(*(RecoveredGlobal_80069C94_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value) + 8) & 4)) {
        temp_r5 = (u8 *)(*(s32 *)((s8 *)(&(*(RecoveredGlobal_80069C94_camera_controller_registry *)&camera_controller_registry).value) + (*(u8 *)((s8 *)(&(*(RecoveredGlobal_80069C94_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value) + 0) * 4)));
        if (temp_r5 != NULL) {
            *(f32 *)((s8 *)temp_r5 + 0x3C) = (f32) *(f32 *)((s8 *)arg0 + 0);
            *(f32 *)((s8 *)temp_r5 + 0x40) = (f32) *(f32 *)((s8 *)arg0 + 4);
            *(f32 *)((s8 *)temp_r5 + 0x44) = (f32) *(f32 *)((s8 *)arg0 + 8);
            *(f32 *)((s8 *)temp_r5 + 0x48) = (f32) *(f32 *)((s8 *)arg1 + 0);
            *(f32 *)((s8 *)temp_r5 + 0x4C) = (f32) *(f32 *)((s8 *)arg1 + 4);
            *(f32 *)((s8 *)temp_r5 + 0x50) = (f32) *(f32 *)((s8 *)arg1 + 8);
        }
    }
}
void TCameraCtrl::update_pose_smoothing() {
    u8 *arg0 = (u8 *)this;
  u8 *new_var;
  u8 *temp_r30;
  u8 *current;
  u8 *temp_r31;
  if ((*(s32 *)&TCameraCtrl__pose_snap_flags) & 1)
  {
    update_position();
    TCameraCtrl__sub_800689E8();
    return;
  }
  if (is_split_screen() != 0)
  {
    temp_r30 = (u8 *) (arg0 + (TCameraCtrl::get_camera_no() * 0xC));
    new_var = (temp_r30 + 0xD4);
    temp_r31 = new_var;
    approach_camera_vector((void *) temp_r31, (u8 *)&this->eye_x, this->eye_rate);
    VecCopy((Vec *)(arg0 + 0x178), (const Vec *)temp_r31);
    current = (temp_r30 + 0x104);
    approach_camera_vector((void *) current, (u8 *)&this->at_x, this->at_rate);
    VecCopy((Vec *)(arg0 + 0x184), (const Vec *)current);
    return;
  }
  approach_camera_vector((u8 *)&this->pos_x, (u8 *)&this->eye_x, this->eye_rate);
  approach_camera_vector((u8 *)&this->tgt_x, (u8 *)&this->at_x, this->at_rate);
}

void TCameraCtrl::update_position() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r3;

    this->pos_x = (f32) this->eye_x;
    this->pos_y = (f32) this->eye_y;
    this->pos_z = (f32) this->eye_z;
    this->tgt_x = (f32) this->at_x;
    this->tgt_y = (f32) this->at_y;
    this->tgt_z = (f32) this->at_z;
    this->look_x = (f32) this->pos_x;
    this->look_y = (f32) this->pos_y;
    this->look_z = (f32) this->pos_z;
    if (is_split_screen() != 0) {
        temp_r3 = arg0 + (TCameraCtrl::get_camera_no() * 0xC);
        *(f32 *)((s8 *)temp_r3 + 0x134) = (f32) this->pos_x;
        *(f32 *)((s8 *)temp_r3 + 0x138) = (f32) this->pos_y;
        *(f32 *)((s8 *)temp_r3 + 0x13C) = (f32) this->pos_z;
    }
}

void TCameraCtrl::update_target_smoothing() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r3;
    u8 *temp_r3_2;
    this->pos_x = (f32) this->eye_x;
    this->pos_y = (f32) this->eye_y;
    this->pos_z = (f32) this->eye_z;
    this->look_x = (f32) this->pos_x;
    this->look_y = (f32) this->pos_y;
    this->look_z = (f32) this->pos_z;
    if (is_split_screen() != 0) {
        temp_r3 = arg0 + (TCameraCtrl::get_camera_no() * 0xC);
        *(f32 *)((s8 *)temp_r3 + 0x134) = (f32) this->pos_x;
        *(f32 *)((s8 *)temp_r3 + 0x138) = (f32) this->pos_y;
        *(f32 *)((s8 *)temp_r3 + 0x13C) = (f32) this->pos_z;
    }
    temp_r3_2 = (u8 *)(*(u8 **)((s8 *)((u8 *)(&(*(RecoveredGlobal_80069A6C_camera_controller_registry *)&camera_controller_registry).value) + ((*(RecoveredGlobal_80069A6C_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value * 4)) + 0));
    if ((temp_r3_2 != NULL) && !(*(s32 *)((s8 *)temp_r3_2 + 0x38) & 0x10)) {
        this->tgt_y = (f32) this->at_y;
    }
    approach_camera_vector((u8 *)&this->tgt_x, (u8 *)&this->at_x, this->at_rate);
}

void TCameraCtrl::clamp_to_target_obstruction() {
    View_800698C8 *self = (View_800698C8 *)this;
    s32 n;
    Hit_800698C8 *hit;
    s32 *obstructed;
    n = TCameraCtrl::get_camera_no();
    if (is_split_screen() != 0) {
        obstructed = &self->split_obstructed[n];
    } else {
        obstructed = &self->obstructed;
    }
    if (*obstructed == 0) {
        return;
    }
    if (is_split_screen() != 0) {
        hit = (Hit_800698C8 *)csnVector(&self->split_tgt[n], &self->split_pos[n], 0x901);
    } else {
        hit = (Hit_800698C8 *)csnVector(&self->tgt, &self->pos, 0x901);
    }
    if (hit == NULL) {
        return;
    }
    if (is_split_screen() != 0) {
        self->split_pos[n].x = hit->point->x;
        self->split_pos[n].y = hit->point->y;
        self->split_pos[n].z = hit->point->z;
        VecCopy((Vec *)&self->pos, (const Vec *)&self->split_pos[n]);
    } else {
        self->pos.x = hit->point->x;
        self->pos.y = hit->point->y;
        self->pos.z = hit->point->z;
    }
    if (is_split_screen() != 0) {
        self->split_look[n].x = self->split_pos[n].x + hit->point[1].x;
        self->split_look[n].y = self->split_pos[n].y + hit->point[1].y;
        self->split_look[n].z = self->split_pos[n].z + hit->point[1].z;
    } else {
        self->look.x = self->pos.x + hit->point[1].x;
        self->look.y = self->pos.y + hit->point[1].y;
        self->look.z = self->pos.z + hit->point[1].z;
    }
}

void TCameraCtrl::resolve_anchor_obstruction() {
    View_800696D0 *self = (View_800696D0 *)this;
    Vec_800696D0 d;
    s32 n;
    s32 *obstructed;
    Hit_800696D0 *hit;
    if (is_split_screen() != 0) {
        n = TCameraCtrl::get_camera_no();
        obstructed = &self->split_obstructed[n];
        hit = (Hit_800696D0 *)csnVector(&self->split_look[n], &self->eye, 0x901);
    } else {
        hit = (Hit_800696D0 *)csnVector(&self->look, &self->eye, 0x901);
        obstructed = &self->obstructed;
    }
    if (hit != NULL) {
        if (is_split_screen() != 0) {
            n = TCameraCtrl::get_camera_no();
            d.x = self->eye.x - self->split_look[n].x;
            d.y = self->eye.y - self->split_look[n].y;
            d.z = self->eye.z - self->split_look[n].z;
        } else {
            d.x = self->eye.x - self->look.x;
            d.y = self->eye.y - self->look.y;
            d.z = self->eye.z - self->look.z;
        }
        if (0.0f != vector_length(&d)) {
            normalize_vector(&d);
        }
        if (is_split_screen() != 0) {
            n = TCameraCtrl::get_camera_no();
            self->split_look[n].x = hit->point->x - d.x;
            self->split_look[n].y = hit->point->y - d.y;
            self->split_look[n].z = hit->point->z - d.z;
        } else {
            self->look.x = hit->point->x - d.x;
            self->look.y = hit->point->y - d.y;
            self->look.z = hit->point->z - d.z;
        }
        *obstructed = 1;
    } else {
        if (is_split_screen() != 0) {
            n = TCameraCtrl::get_camera_no();
            VecCopy((Vec *)&self->split_look[n], (const Vec *)&self->split_pos[n]);
        } else {
            VecCopy((Vec *)&self->look, (const Vec *)&self->pos);
        }
        *obstructed = 0;
    }
}

void*TCameraCtrl::get_target() { return (char*)this + 0x68; }
void CameraViewParams::apply() {
    *(s32 *)((s8 *)(&(*(RecoveredGlobal_8006961C_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value) + 8) = (s32) (*(s32 *)((s8 *)(&(*(RecoveredGlobal_8006961C_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value) + 8) | 0x200);
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_8006961C_TCameraCtrl__data_804FF634 *)&TCameraCtrl__data_804FF634).value) + 0x28) = (f32) width;
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_8006961C_TCameraCtrl__data_804FF634 *)&TCameraCtrl__data_804FF634).value) + 0x2C) = (f32) height;
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_8006961C_TCameraCtrl__data_804FF634 *)&TCameraCtrl__data_804FF634).value) + 8) = (f32) center_x;
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_8006961C_TCameraCtrl__data_804FF634 *)&TCameraCtrl__data_804FF634).value) + 0xC) = (f32) center_y;
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_8006961C_TCameraCtrl__data_804FF634 *)&TCameraCtrl__data_804FF634).value) + 0x18) = (f32) *(f32 *)((s8 *)&scene_projection_state.value + 0x50);
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_8006961C_TCameraCtrl__data_804FF634 *)&TCameraCtrl__data_804FF634).value) + 0x1C) = (f32) *(f32 *)((s8 *)&scene_projection_state.value + 0x4C);
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_8006961C_TCameraCtrl__data_804FF634 *)&TCameraCtrl__data_804FF634).value) + 0x20) = 1.0f;
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_8006961C_TCameraCtrl__data_804FF634 *)&TCameraCtrl__data_804FF634).value) + 0x24) = (f32) (*(f32 *)((s8 *)(&(*(RecoveredGlobal_8006961C_TCameraCtrl__data_804FF634 *)&TCameraCtrl__data_804FF634).value) + 0x20) / *(f32 *)((s8 *)&scene_projection_state.value + 0x4C));
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_8006961C_TCameraCtrl__data_804FF634 *)&TCameraCtrl__data_804FF634).value) + 0) = (f32) (*(f32 *)((s8 *)&scene_projection_state.value + 0x4C) * *(f32 *)((s8 *)&scene_projection_state.value + 0x50));
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_8006961C_TCameraCtrl__data_804FF634 *)&TCameraCtrl__data_804FF634).value) + 4) = (f32) -(*(f32 *)((s8 *)(&(*(RecoveredGlobal_8006961C_TCameraCtrl__data_804FF634 *)&TCameraCtrl__data_804FF634).value) + 0x20) * *(f32 *)((s8 *)&scene_projection_state.value + 0x50));
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_8006961C_TCameraCtrl__data_804FF634 *)&TCameraCtrl__data_804FF634).value) + 0x30) = (f32) pad_30[0];
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_8006961C_TCameraCtrl__data_804FF634 *)&TCameraCtrl__data_804FF634).value) + 0x34) = (f32) pad_30[1];
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_8006961C_TCameraCtrl__data_804FF634 *)&TCameraCtrl__data_804FF634).value) + 0x38) = (f32) pad_30[2];
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_8006961C_TCameraCtrl__data_804FF634 *)&TCameraCtrl__data_804FF634).value) + 0x3C) = (f32) pad_30[3];
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_8006961C_TCameraCtrl__data_804FF634 *)&TCameraCtrl__data_804FF634).value) + 0x40) = (f32) pad_30[4];
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_8006961C_TCameraCtrl__data_804FF634 *)&TCameraCtrl__data_804FF634).value) + 0x44) = (f32) pad_30[5];
}

void CameraViewParams::apply_if_overridden() {
    if (*(s32 *)((s8 *)&TCameraCtrl__view_state + 8) & 0x400) {
        apply();
    }
}

s32 CameraViewParams::begin_override() {
    if ((*(G_800695A0 *)&TCameraCtrl__view_state).flags & 0x400) {
        return 0;
    }
    (*(G_800695A0 *)&TCameraCtrl__view_state).flags |= 0x400;
    apply();
    return 1;
}
#pragma push
#pragma opt_common_subs off
void TCameraCtrl::reset_viewport_scissor() {
    // Scissor rectangle in 32-pixel tiles: the full 640x480 screen.
    f32 rect[4] = {0.0f, 0.0f, 20.0f, 15.0f};
    if (*(s32 *)((s8 *)(&(*(RecoveredGlobal_80069534_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value) + 8) & 0x200) {
        *(s32 *)((s8 *)(&(*(RecoveredGlobal_80069534_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value) + 8) = (s32) (*(s32 *)((s8 *)(&(*(RecoveredGlobal_80069534_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value) + 8) & 0xFFFFFDFF);
    }
    set_viewport_scissor__11TCameraCtrlFiPv(0, rect);
}
#pragma pop
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void end_view_override() {
    typedef char sp8_offset[(offsetof(Stack_800694A8, sp8) == 0x0) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_800694A8, sp10) == 0x8) ? 1 : -1];
    typedef char sp14_offset[(offsetof(Stack_800694A8, sp14) == 0xC) ? 1 : -1];
    typedef char sp30_offset[(offsetof(Stack_800694A8, sp30) == 0x28) ? 1 : -1];
    typedef char sp34_offset[(offsetof(Stack_800694A8, sp34) == 0x2C) ? 1 : -1];
    typedef char sp38_offset[(offsetof(Stack_800694A8, sp38) == 0x30) ? 1 : -1];
    typedef char sp3C_offset[(offsetof(Stack_800694A8, sp3C) == 0x34) ? 1 : -1];
    typedef char sp40_offset[(offsetof(Stack_800694A8, sp40) == 0x38) ? 1 : -1];
    typedef char sp44_offset[(offsetof(Stack_800694A8, sp44) == 0x3C) ? 1 : -1];
    typedef char sp48_offset[(offsetof(Stack_800694A8, sp48) == 0x40) ? 1 : -1];
    typedef char sp4C_offset[(offsetof(Stack_800694A8, sp4C) == 0x44) ? 1 : -1];
    Stack_800694A8 stack;
    if (*(s32 *)((s8 *)(&(*(RecoveredGlobal_800694A8_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value) + 8) & 0x400) {
        *(s32 *)((s8 *)(&(*(RecoveredGlobal_800694A8_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value) + 8) = (s32) (*(s32 *)((s8 *)(&(*(RecoveredGlobal_800694A8_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value) + 8) & 0xFFFFFBFF);
    }
    stack.sp10 = 320.0f;
    stack.sp14 = 240.0f;
    stack.sp30 = 640.0f;
    stack.sp34 = 480.0f;
    stack.sp38 = 0.0f;
    stack.sp3C = 0.0f;
    stack.sp40 = 20.0f;
    stack.sp44 = 15.0f;
    stack.sp48 = 1.0f;
    stack.sp4C = 0.85f;
    ((CameraViewParams *)&stack.sp8)->apply();
}
#pragma pop

void TCameraCtrl::init_default_view() {
    typedef char sp8_offset[(offsetof(Stack_800693F4, sp8) == 0x0) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_800693F4, sp10) == 0x8) ? 1 : -1];
    typedef char sp14_offset[(offsetof(Stack_800693F4, sp14) == 0xC) ? 1 : -1];
    typedef char sp20_offset[(offsetof(Stack_800693F4, sp20) == 0x18) ? 1 : -1];
    typedef char sp30_offset[(offsetof(Stack_800693F4, sp30) == 0x28) ? 1 : -1];
    typedef char sp34_offset[(offsetof(Stack_800693F4, sp34) == 0x2C) ? 1 : -1];
    typedef char sp38_offset[(offsetof(Stack_800693F4, sp38) == 0x30) ? 1 : -1];
    typedef char sp3C_offset[(offsetof(Stack_800693F4, sp3C) == 0x34) ? 1 : -1];
    typedef char sp40_offset[(offsetof(Stack_800693F4, sp40) == 0x38) ? 1 : -1];
    typedef char sp44_offset[(offsetof(Stack_800693F4, sp44) == 0x3C) ? 1 : -1];
    typedef char sp48_offset[(offsetof(Stack_800693F4, sp48) == 0x40) ? 1 : -1];
    typedef char sp4C_offset[(offsetof(Stack_800693F4, sp4C) == 0x44) ? 1 : -1];
    Stack_800693F4 stack;
    TCameraCtrl__camera_mode = 0;
    TCameraCtrl::set_target_coords(0, 0);
    TCameraCtrl::set_target(0x280, 0x1E0);
    stack.sp10 = 320.0f;
    stack.sp14 = 240.0f;
    stack.sp30 = 640.0f;
    stack.sp34 = 480.0f;
    stack.sp20 = 250.0f;
    stack.sp38 = 0.0f;
    stack.sp3C = 0.0f;
    stack.sp40 = 20.0f;
    stack.sp44 = 15.0f;
    stack.sp48 = 1.0f;
    stack.sp4C = 0.85f;
    ((CameraViewParams *)&stack.sp8)->apply();
    ((TCameraCtrl *)(&(*(RecoveredGlobal_800693F4_TCameraCtrl__data_804FF634 *)&TCameraCtrl__data_804FF634).value))->update_projection_params();
    camera_default_view_value = 1.0f;
    camera_default_view_value_b = 0.85f;
}

void TCameraCtrl::reset_default_view() {
    typedef char sp8_offset[(offsetof(Stack_80069318, sp8) == 0x0) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_80069318, sp10) == 0x8) ? 1 : -1];
    typedef char sp14_offset[(offsetof(Stack_80069318, sp14) == 0xC) ? 1 : -1];
    typedef char sp20_offset[(offsetof(Stack_80069318, sp20) == 0x18) ? 1 : -1];
    typedef char sp30_offset[(offsetof(Stack_80069318, sp30) == 0x28) ? 1 : -1];
    typedef char sp34_offset[(offsetof(Stack_80069318, sp34) == 0x2C) ? 1 : -1];
    typedef char sp38_offset[(offsetof(Stack_80069318, sp38) == 0x30) ? 1 : -1];
    typedef char sp3C_offset[(offsetof(Stack_80069318, sp3C) == 0x34) ? 1 : -1];
    typedef char sp40_offset[(offsetof(Stack_80069318, sp40) == 0x38) ? 1 : -1];
    typedef char sp44_offset[(offsetof(Stack_80069318, sp44) == 0x3C) ? 1 : -1];
    Stack_80069318 stack;
    TCameraCtrl__camera_mode = 0;
    TCameraCtrl::set_target_coords(0, 0);
    TCameraCtrl::set_target(0x280, 0x1E0);
    TCameraCtrl::set_fullscreen_viewport();
    TCameraCtrl::reset_viewport_scissor();
    fn_803D64F8(lbl_804FF5E8);
    camera_renderer_setup_nop(lbl_804FF5E8, 0x3555);
    TCameraCtrl::update_camera_state(0.0f, 0.0f, 0.0f);
    TCameraCtrl::look_at_position(0.0f, 0.0f, -1.0f);
    stack.sp10 = 320.0f;
    stack.sp14 = 240.0f;
    stack.sp30 = 640.0f;
    stack.sp34 = 480.0f;
    stack.sp20 = 250.0f;
    stack.sp38 = 0.0f;
    stack.sp3C = 0.0f;
    stack.sp40 = 20.0f;
    stack.sp44 = 15.0f;
    camera_default_view_value = 1.0f;
    camera_default_view_value_b = 0.85f;
    ((TCameraCtrl *)(&stack.sp8))->update_projection_params();
}
s32 TCameraCtrl__sub_80069304(void) {
    return ((u32) *(u32 *)((s8 *)(&(*(RecoveredGlobal_80069304_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value) + 8) >> 0xAU) & 1;
}

void TCameraCtrl::create() {
    void *obj = __nw__7TObjectFUl(0x1D4);
    if (obj != 0) {
        TCameraCtrl__ct((u8 *)obj, (void *)tl_camera);
    }
}
s32 *TCameraCtrl::get_view_matrix() {
    if (is_split_screen() != 0) {
        if (get_mode__11TCameraCtrlFPv((void *) (&(*(RecoveredGlobal_80069258_main_task *)&(*(RecoveredGlobal_800691C8_main_task *)&main_task)).value)) & 1) {
            return (long *) ((u8 *)&(*(RecoveredGlobal_80069258_TCameraCtrl__data_804FF700 *)&TCameraCtrl__view_matrices).value + ((TCameraCtrl::get_instance() - 1) * 0x30));
        }
        return (long *) ((u8 *)&(*(RecoveredGlobal_80069258_TCameraCtrl__data_804FF700 *)&TCameraCtrl__view_matrices).value + (TCameraCtrl::get_camera_no() * 0x30));
    }
    return &(*(RecoveredGlobal_80069258_TCameraCtrl__data_804FF6D0 *)&TCameraCtrl__view_matrix).value;
}

void TCameraCtrl::apply_split_screen_view_matrix() {
    if (is_split_screen() != 0) {
        if (get_mode__11TCameraCtrlFPv(&(*(RecoveredGlobal_800691C8_main_task *)&main_task).value) & 1) {
            TCameraCtrl::concat_matrix(0U, (u32) ((u8 *)TCameraCtrl__view_matrices + ((TCameraCtrl::get_instance() - 1) * 0x30)));
            return;
        }
        TCameraCtrl::concat_matrix(0U, (u32) ((u8 *)TCameraCtrl__view_matrices + (TCameraCtrl::get_camera_no() * 0x30)));
        return;
    }
    TCameraCtrl::concat_matrix(0U, (u32) TCameraCtrl__view_matrix);
}
void transform_to_view__11TCameraCtrlFii(s32 arg0, s32 arg1) {
    push_matrix();
    if (is_split_screen() != 0) {
        TCameraCtrl::concat_matrix((u32)(0), (u32)((void *) ((u8 *)&(*(RecoveredGlobal_80069148_TCameraCtrl__data_804FF700 *)&TCameraCtrl__view_matrices).value + (TCameraCtrl::get_camera_no() * 0x30))));
    } else {
        TCameraCtrl::concat_matrix((u32)(0), (u32)((void *) (&(*(RecoveredGlobal_80069148_TCameraCtrl__data_804FF6D0 *)&TCameraCtrl__view_matrix).value)));
    }
    matrix_mult_vec(0, (void *)arg0, (void *)arg1);
    pop_matrix();
}

s32 TCameraCtrl::get_camera_target_id(s32 arg0) {
    s32 var_r31;
    s32 var_r3;
    void *temp_r3;
    void *temp_r3_2;
    if (is_split_screen() != 0) {
        var_r31 = 0xFFFF;
        if (arg0 < 0) {
            var_r3 = arg0;
        } else {
            var_r3 = get_camera_mode__11TCameraCtrlFv();
        }
        if (var_r3 >= 4) {
            return 0xFFFF;
        }
        temp_r3_2 = camera_controller_registry[var_r3];
        if (temp_r3_2 != 0U) {
            var_r31 = TCameraCtrl__sub_8006B358(temp_r3_2);
        }
        return var_r31;
    }
    if ((void *) camera_ctrl_instance != NULL) {
        temp_r3 = *(void **)((s8 *)camera_ctrl_instance + 0x90);
        if (temp_r3 != 0U) {
            return get_entity_id(temp_r3);
        }
    }
    return 0xFFFF;
}

void TCameraCtrl::restore_full_screen_view() {
    if (is_split_screen() == 0) {
        ((TCameraCtrl *)((s32) lbl_804FF67C))->copy_view_state((s32)((s32) TCameraCtrl__data_804FF634));
        TCameraCtrl__sub_801E32D8(320.0f, 240.0f);
        GXSetScissorBoxOffset(0, 0);
        GXSetScissor(0, 0, 0x280, 0x1E0);
        TCameraCtrl__data_805D4E0A = 0;
    }
}



void TCameraCtrl::copy_view_state(s32 src) {
    s32 dst = (s32)this;
    *(O_80068FCC *)dst = *(O_80068FCC *)src;
}

void TCameraCtrl__sub_80068EF0(void) {
    f32 neg_w;
    f32 neg_h;
    if (is_split_screen() == 0) {
        ((TCameraCtrl *)((s32) TCameraCtrl__data_804FF634))->copy_view_state((s32)((s32) lbl_804FF67C));
        neg_w = -(*(f32 *)((s8 *)&TCameraCtrl__data_804FF634 + 8) - 320.0f);
        neg_h = -(*(f32 *)((s8 *)&TCameraCtrl__data_804FF634 + 0xC) - 240.0f);
        if (0.0f == neg_w && 0.0f == neg_h) {
            TCameraCtrl__data_805D4E0A = 0;
        } else {
            TCameraCtrl__data_805D4E0A = 1;
        }
        GXSetScissorBoxOffset((s32) neg_w, (s32) neg_h);
        TCameraCtrl__sub_801E32D8(*(f32 *)((s8 *)&TCameraCtrl__data_804FF634 + 8), *(f32 *)((s8 *)&TCameraCtrl__data_804FF634 + 0xC));
        if ((void *) camera_ctrl_instance != NULL) {
            set_perspective_projection_from_fov((s32) ((TCameraCtrl *) camera_ctrl_instance)->fov, 1.1333334f, 1.0f, 21000.0f);
        }
    }
}

// Dead-stripped from the DOL: no code of it survives, only its literals
// (250, 20, 15, 0.85 at 0x805D8FCC-0x805D8FDB, pooled between get_view_scale's
// and TCameraCtrl__sub_80068EF0's). It fills the full-screen defaults that
// init_default_view, reset_default_view and end_view_override store field by
// field. Name inferred from that role.
void CameraViewParams::set_fullscreen_defaults() {
    center_x = 320.0f;
    center_y = 240.0f;
    pad_10[2] = 250.0f;
    width = 640.0f;
    height = 480.0f;
    pad_30[0] = 0.0f;
    pad_30[1] = 0.0f;
    pad_30[2] = 20.0f;
    pad_30[3] = 15.0f;
    pad_30[4] = 1.0f;
    pad_30[5] = 0.85f;
}

f32 TCameraCtrl::get_view_scale() {
    if (is_split_screen() != 0) {
        if (TCameraCtrl::get_camera_id() == 2) {
            return 1.0f;
        }
        return 0.5f;
    }
    return 1.0f;
}

f32 TCameraCtrl::get_fov() {
    if (is_split_screen() != 0) {
        if (TCameraCtrl::get_camera_id() == 2) {
            return 1.0f;
        }
        return 0.5f;
    }
    return 1.0f;
}
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
void TCameraCtrl::set_split_viewport(s32 arg0, s32 i) {
    switch (arg0) {
    case 1:
        TCameraCtrl::set_fullscreen_viewport();
        break;
    case 2:
        TCameraCtrl::set_target_coords(0, 0);
        TCameraCtrl::set_target(0x280, 0xF0);
        GXSetViewport(0.0f, 0.0f, 640.0f, 480.0f, 0.0f, 1.0f);
        if (i == 0) {
            GXSetScissor(0, 0x6A, 0x280, 0xF0);
            GXSetScissorBoxOffset(0, 0x6A);
        } else {
            GXSetScissor(0, 0x74, 0x280, 0xF0);
            GXSetScissorBoxOffset(0, -0x7C);
        }
        break;
    case 3:
        if (i != 2) {
            quad_80068B34(i);
        } else {
            TCameraCtrl::set_target_coords(0xA0, 0xF0);
            TCameraCtrl::set_target(0x140, 0xF0);
        }
        viewport_80068B34();
        break;
    case 4:
        quad_80068B34(i);
        viewport_80068B34();
        break;
    default:
        TCameraCtrl::set_fullscreen_viewport();
        break;
    }
}
#pragma pop


void TCameraCtrl::set_fullscreen_viewport() {
    TCameraCtrl::set_target_coords(0, 0);
    TCameraCtrl::set_target(0x280, 0x1E0);
    GXSetViewport((f32) TCameraCtrl__viewport_x, (f32) TCameraCtrl__viewport_y, (f32) TCameraCtrl__viewport_size, (f32) TCameraCtrl__viewport_height, 0.0f, 1.0f);
    GXSetScissor((int) ((s32) TCameraCtrl__viewport_x), (int) ((s32) TCameraCtrl__viewport_y), (int) ((s32) TCameraCtrl__viewport_size), (int) ((s32) TCameraCtrl__viewport_height));
    GXSetScissorBoxOffset(0, 0);
}


f32 TCameraCtrl::get_split_offset(s32 arg0) {
    if ((is_split_screen() != 0) && (TCameraCtrl::get_camera_id() == 2)) {
        if (arg0 == 0) {
            return 106.0f;
        }
        return 116.0f;
    }
    return 0.0f;
}

f32 TCameraCtrl__sub_80068A04(void) {
    return 0.0f;
}

bool TCameraCtrl__sub_800689F4(void) {
    return TCameraCtrl__data_805D4E0A != 0;
}

void TCameraCtrl__sub_800689E8(void) { TCameraCtrl__pose_snap_flags = 0; }

u16 TCameraCtrl::get_nth_view_player_id(s32 n) {
    s32 count = 0;
    u16 result = 0;
    Cam_80068958 *cam;
    s32 i;
    s32 v;
    if (is_split_screen() == 0) {
        return local_client_id;
    }
    cam = get_character_select_request_buffer();
    for (i = 0; i < 4; i++) {
        v = cam->ids[i];
        if (v >= 0 && v != 0xFFFF) {
            if (count == n) {
                result = v;
            }
            count++;
        }
    }
    return result;
}

s32 TCameraCtrl::get_split_screen_view_index(u16 id) {
    s32 result = 0;
    s32 n = 0;
    struct Cam_800688D0 *cam;
    s32 i;
    if (is_split_screen() == 0) {
        return 0;
    }
    cam = (struct Cam_800688D0 *) get_character_select_request_buffer();
    for (i = 0; i < 4; i++) {
        if (cam->slots[i] == id) {
            result = n;
        }
        if (cam->slots[i] >= 0) {
            n++;
        }
    }
    return result;
}

void TCameraCtrl::sync_split_view_slots(s32 arg0, s32 arg1) {
    s32 i;
    s32 id;
    if ((*(Cam_80068810 * *)&camera_ctrl_instance) != NULL) {
        id = (u16)TCameraCtrl::get_nth_view_player_id(arg0);
        if (id != 0xFFFF) {
            (*(Cam_80068810 * *)&camera_ctrl_instance)->view_yaw[id] = (*(Cam_80068810 * *)&camera_ctrl_instance)->yaw;
            VecCopy((Vec *)(&(*(Cam_80068810 * *)&camera_ctrl_instance)->view_pos[id]), (const Vec *)(&(*(Cam_80068810 * *)&camera_ctrl_instance)->pos));
        }
    }
    if (arg1 != 0) {
        for (i = 0; i < 4; i++) {
            (*(Cam_80068810 * *)&camera_ctrl_instance)->view_yaw[i] = (*(Cam_80068810 * *)&camera_ctrl_instance)->yaw;
            VecCopy((Vec *)(&(*(Cam_80068810 * *)&camera_ctrl_instance)->view_pos[i]), (const Vec *)(&(*(Cam_80068810 * *)&camera_ctrl_instance)->pos));
        }
    }
}

void TCameraCtrl::copy_vec_to_default(u8 *arg0) {
    VecCopy((Vec *)TCameraCtrl__up_vector, (const Vec *)(arg0));
}
void TCameraCtrl__sub_800687C8(void) {
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_800687C8_TCameraCtrl__data_804FF6C4 *)&TCameraCtrl__up_vector).value) + 0) = 0.0f;
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_800687C8_TCameraCtrl__data_804FF6C4 *)&TCameraCtrl__up_vector).value) + 4) = 1.0f;
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_800687C8_TCameraCtrl__data_804FF6C4 *)&TCameraCtrl__up_vector).value) + 8) = 0.0f;
}
void*TCameraCtrl::get_target_ptr() { return (char*)this + 0x44; }

void TUnk_80488A28::run_task() {  }
}

