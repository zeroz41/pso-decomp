#include "types.h"
#include "pso/system/vector.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TUnk_80488A28.h"
#include "pso/camera/CameraViewParams.h"

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

struct RecoveredGlobal_80069094_camera_controller_registry { s32 value; u8 remaining[0x64]; };
typedef char RecoveredGlobal_80069094_camera_controller_registry_size[sizeof(RecoveredGlobal_80069094_camera_controller_registry) == 0x68 ? 1 : -1];

struct RecoveredGlobal_80069024_TCameraCtrl__data_804FF634 {
    s32 value;
    u8 remaining[0x44];
};

struct RecoveredGlobal_80069024_lbl_804FF67C {
    s32 value;
    u8 remaining[0x44];
};

struct RecoveredGlobal_800695E8_TCameraCtrl__data_804FF628 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_800691C8_TCameraCtrl__data_804FF6D0 {
    s32 value;
    u8 remaining[0x2C];
};

struct RecoveredGlobal_800691C8_TCameraCtrl__data_804FF700 {
    s32 value;
    u8 remaining[0xBC];
};

struct RecoveredGlobal_800691C8_main_task {
    s32 value;
    u8 remaining[0x30];
};

struct RecoveredGlobal_800687E4_TCameraCtrl__data_804FF6C4 {
    s32 value;
    u8 remaining[0x8];
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

struct RecoveredGlobal_80069318_lbl_804FF5E8 { s32 value; u8 remaining[0x24]; };

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

struct Stack_80069534 {
    s32 sp8;
    s32 spC;
    s32 sp10;
    s32 sp14;
};

struct RecoveredGlobal_80069534_lbl_804381BC {
    s32 value;
    u8 remaining[0x10];
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

struct Cam_80068958 { u8 pad[0x10]; s32 ids[4]; };

struct G_800695A0 { s32 a; s32 b; u32 flags; };

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct M_80068FCC { f32 m[3][4]; };

struct W_80068FCC { f32 x, y; };

struct O_80068FCC { M_80068FCC m; W_80068FCC a; W_80068FCC b; W_80068FCC c; };

struct Cam_800688D0 { u8 pad[0x10]; s32 slots[4]; };

struct RecoveredGlobal_800695E8_TCameraCtrl__data_804FF628;
struct RecoveredGlobal_80069094_camera_controller_registry;

struct Vec_80068810 { f32 x, y, z; };

struct Cam_80068810 {
    u8 pad0[0x94];
    void *slots[4];
    Vec_80068810 vecs[4];
    u8 padd4[0x178 - 0xD4];
    Vec_80068810 v178;
    u8 pad184[0x194 - 0x184];
    void *f194;
};

struct Vec_800696D0 { f32 x, y, z; };

struct Hit_800696D0 { u32 f0; Vec_800696D0 *point; };

struct View_800696D0 {
    u8 pad0[0xD4];
    Vec_800696D0 split_pos[4];
    Vec_800696D0 split_tgt[4];
    Vec_800696D0 split_look[4];
    s32 split_flags[4];
    s32 flag;
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
    s32 split_flags[4];
    s32 flag;
    Vec_800698C8 pos;
    Vec_800698C8 tgt;
    u8 pad190[0x1C8 - 0x190];
    Vec_800698C8 look;
};

extern "C" {
void TCameraCtrl__sub_800689E8(void);
s32 is_split_screen();
s32 approach_camera_vector(void *, void *, f32);
extern int TCameraCtrl__pose_snap_flags;
s32 GXSetViewport(f32, f32, f32, f32, f32, f32);
s32 GXSetScissor(int, int, int, int);
s32 GXSetScissorBoxOffset(int, int);
extern s16 TCameraCtrl__viewport_size;
extern s16 TCameraCtrl__viewport_height;
extern s16 TCameraCtrl__viewport_x;
extern s16 TCameraCtrl__viewport_y;
extern const f32 TCameraCtrl__data_805D8FA8;
extern f32 TCameraCtrl__data_805D8FAC;
s32 get_entity_id(int);
s32 get_camera_mode__11TCameraCtrlFv();
s32 TCameraCtrl__sub_8006B358(int);
extern RecoveredGlobal_80069094_camera_controller_registry camera_controller_registry;
extern u8 *camera_ctrl_instance;
void TCameraCtrl__sub_801E32D8(f32, f32);
extern RecoveredGlobal_80069024_TCameraCtrl__data_804FF634 TCameraCtrl__data_804FF634;
extern RecoveredGlobal_80069024_lbl_804FF67C lbl_804FF67C;
extern s16 TCameraCtrl__data_805D4E0A;
extern const f32 TCameraCtrl__data_805D8FC0;
extern const f32 TCameraCtrl__data_805D8FC4;
extern RecoveredGlobal_800695E8_TCameraCtrl__data_804FF628 TCameraCtrl__view_state;
s32 get_mode__11TCameraCtrlFPv(void *);
extern RecoveredGlobal_800691C8_TCameraCtrl__data_804FF6D0 TCameraCtrl__view_matrix;
extern RecoveredGlobal_800691C8_TCameraCtrl__data_804FF700 TCameraCtrl__view_matrices;
extern RecoveredGlobal_800687E4_TCameraCtrl__data_804FF6C4 TCameraCtrl__up_vector;
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
extern RecoveredGlobal_80069318_lbl_804FF5E8 lbl_804FF5E8;
extern f32 camera_default_view_value;
extern f32 camera_default_view_value_b;
extern s16 TCameraCtrl__camera_mode;
extern const f32 TCameraCtrl__data_805D8FB8;
extern const f32 TCameraCtrl__data_805D8FBC;
extern const f32 lbl_805D8FCC;
extern const f32 TCameraCtrl__data_805D8FD0;
extern const f32 TCameraCtrl__data_805D8FD4;
extern const f32 TCameraCtrl__data_805D8FD8;
extern const f32 lbl_805D8FE4;
s32 set_viewport_scissor__11TCameraCtrlFiPv(int, void *);
extern RecoveredGlobal_80069534_lbl_804381BC camera_ctrl_scissor_default_vec;
s32 activate_camera_mode(s32 arg0);
bool TCameraCtrl__sub_800689F4(void);
extern s32 local_client_id;
Cam_80068958 *get_character_select_request_buffer(void);
}
void reset_cameras_to_actor(void *actor, s32 arg1);
extern "C" {
u16 TCameraCtrl__sub_8006A5DC();
u8 *get_player_by_client_id(s32);
extern s32 TCameraCtrl__saved_projection_angle;
s32 restore_player_cameras(void);
u8 *csnVector(void *, void *, u32);
f32 vector_length(void *);
void normalize_vector(void *);
f32 TCameraCtrl__sub_80068A04(void);
u8 *TCameraCtrl__ct(u8 *arg0, void *parent);
void * __nw__7TObjectFUl(s32);

void TUnk_80488A28::run_task() {  }
void*TCameraCtrl::get_target_ptr() { return (char*)this + 0x44; }

typedef char RecoveredGlobal_800687E4_TCameraCtrl__data_804FF6C4_size[sizeof(RecoveredGlobal_800687E4_TCameraCtrl__data_804FF6C4) == 0xC ? 1 : -1];

typedef char RecoveredGlobal_800687C8_TCameraCtrl__data_804FF6C4_size[sizeof(RecoveredGlobal_800687C8_TCameraCtrl__data_804FF6C4) == 0xC ? 1 : -1];
void TCameraCtrl__sub_800687C8(void) {
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_800687C8_TCameraCtrl__data_804FF6C4 *)&TCameraCtrl__up_vector).value) + 0) = (f32) (*(const f32 *)&TCameraCtrl__data_805D8FA8);
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_800687C8_TCameraCtrl__data_804FF6C4 *)&TCameraCtrl__up_vector).value) + 4) = (f32) (*(const f32 *)&TCameraCtrl__data_805D8FAC);
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_800687C8_TCameraCtrl__data_804FF6C4 *)&TCameraCtrl__up_vector).value) + 8) = (f32) (*(const f32 *)&TCameraCtrl__data_805D8FA8);
}

void TCameraCtrl::copy_vec_to_default(u8 *arg0) {
    VecCopy((Vec *)(&TCameraCtrl__up_vector.value), (const Vec *)(arg0));
}

struct Cam_80068958;

void TCameraCtrl::sync_split_view_slots(s32 arg0, s32 arg1) {
    s32 i;
    s32 id;
    if ((*(Cam_80068810 * *)&camera_ctrl_instance) != NULL) {
        id = (u16)TCameraCtrl::get_nth_view_player_id(arg0);
        if (id != 0xFFFF) {
            (*(Cam_80068810 * *)&camera_ctrl_instance)->slots[id] = (*(Cam_80068810 * *)&camera_ctrl_instance)->f194;
            VecCopy((Vec *)(&(*(Cam_80068810 * *)&camera_ctrl_instance)->vecs[id]), (const Vec *)(&(*(Cam_80068810 * *)&camera_ctrl_instance)->v178));
        }
    }
    if (arg1 != 0) {
        for (i = 0; i < 4; i++) {
            (*(Cam_80068810 * *)&camera_ctrl_instance)->slots[i] = (*(Cam_80068810 * *)&camera_ctrl_instance)->f194;
            VecCopy((Vec *)(&(*(Cam_80068810 * *)&camera_ctrl_instance)->vecs[i]), (const Vec *)(&(*(Cam_80068810 * *)&camera_ctrl_instance)->v178));
        }
    }
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

void TCameraCtrl__sub_800689E8(void) { TCameraCtrl__pose_snap_flags = 0; }

bool TCameraCtrl__sub_800689F4(void) {
    return TCameraCtrl__data_805D4E0A != 0;
}

f32 TCameraCtrl__sub_80068A04(void) {
    return TCameraCtrl__data_805D8FA8;
}

extern f32 lbl_805D8FB0;
extern f32 lbl_805D8FB4;

f32 TCameraCtrl::get_split_offset(s32 arg0) {
    if ((is_split_screen() != 0) && (TCameraCtrl::get_camera_id() == 2)) {
        if (arg0 == 0) {
            return lbl_805D8FB0;
        }
        return lbl_805D8FB4;
    }
    return TCameraCtrl__data_805D8FA8;
}

extern f32 lbl_805D8FC8;

void TCameraCtrl::set_fullscreen_viewport() {
    TCameraCtrl::set_target_coords(0, 0);
    TCameraCtrl::set_target(0x280, 0x1E0);
    GXSetViewport((f32) TCameraCtrl__viewport_x, (f32) TCameraCtrl__viewport_y, (f32) TCameraCtrl__viewport_size, (f32) TCameraCtrl__viewport_height, (f32) ((*(const f32 *)&TCameraCtrl__data_805D8FA8)), (f32) ((*(const f32 *)&TCameraCtrl__data_805D8FAC)));
    GXSetScissor((int) ((s32) TCameraCtrl__viewport_x), (int) ((s32) TCameraCtrl__viewport_y), (int) ((s32) TCameraCtrl__viewport_size), (int) ((s32) TCameraCtrl__viewport_height));
    GXSetScissorBoxOffset(0, 0);
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline void quad_80068B34(s32 i) {
    TCameraCtrl::set_target_coords((s32)(320.0f * (f32)(i % 2)), (s32)(240.0f * (f32)(i / 2)));
    TCameraCtrl::set_target(0x140, 0xF0);
}
inline void viewport_80068B34(void) {
    GXSetViewport(TCameraCtrl__viewport_x, TCameraCtrl__viewport_y, TCameraCtrl__viewport_size, TCameraCtrl__viewport_height, 0.0f, 1.0f);
    GXSetScissor(TCameraCtrl__viewport_x, TCameraCtrl__viewport_y, TCameraCtrl__viewport_size, TCameraCtrl__viewport_height);
}
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

f32 TCameraCtrl::get_fov() {
    if (is_split_screen() != 0) {
        if (TCameraCtrl::get_camera_id() == 2) {
            return TCameraCtrl__data_805D8FAC;
        }
        return lbl_805D8FC8;
    }
    return TCameraCtrl__data_805D8FAC;
}

f32 TCameraCtrl::get_view_scale() {
    if (is_split_screen() != 0) {
        if (TCameraCtrl::get_camera_id() == 2) {
            return TCameraCtrl__data_805D8FAC;
        }
        return lbl_805D8FC8;
    }
    return TCameraCtrl__data_805D8FAC;
}

extern s32 tl_camera;

typedef char RecoveredGlobal_80069024_TCameraCtrl__data_804FF634_size[sizeof(RecoveredGlobal_80069024_TCameraCtrl__data_804FF634) == 0x48 ? 1 : -1];
typedef char RecoveredGlobal_80069024_lbl_804FF67C_size[sizeof(RecoveredGlobal_80069024_lbl_804FF67C) == 0x48 ? 1 : -1];

void TCameraCtrl::copy_view_state(s32 src) {
    s32 dst = (s32)this;
    *(O_80068FCC *)dst = *(O_80068FCC *)src;
}

void TCameraCtrl::restore_full_screen_view() {
    if (is_split_screen() == 0) {
        ((TCameraCtrl *)((s32) &lbl_804FF67C.value))->copy_view_state((s32)((s32) &TCameraCtrl__data_804FF634.value));
        TCameraCtrl__sub_801E32D8(TCameraCtrl__data_805D8FC0, TCameraCtrl__data_805D8FC4);
        GXSetScissorBoxOffset(0, 0);
        GXSetScissor(0, 0, 0x280, 0x1E0);
        TCameraCtrl__data_805D4E0A = 0;
    }
}

s32 TCameraCtrl::get_camera_target_id(s32 arg0) {
    s32 var_r31;
    s32 var_r3;
    u32 temp_r3;
    u32 temp_r3_2;
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
        temp_r3_2 = *(s32 *)((s8 *)&camera_controller_registry.value + (var_r3 * 4));
        if (temp_r3_2 != 0U) {
            var_r31 = TCameraCtrl__sub_8006B358(temp_r3_2);
        }
        return var_r31;
    }
    if ((void *) camera_ctrl_instance != NULL) {
        temp_r3 = *(u32 *)((s8 *)camera_ctrl_instance + 0x90);
        if (temp_r3 != 0U) {
            return get_entity_id(temp_r3);
        }
    }
    return 0xFFFF;
}

typedef char RecoveredGlobal_800691C8_TCameraCtrl__data_804FF6D0_size[sizeof(RecoveredGlobal_800691C8_TCameraCtrl__data_804FF6D0) == 0x30 ? 1 : -1];
typedef char RecoveredGlobal_800691C8_TCameraCtrl__data_804FF700_size[sizeof(RecoveredGlobal_800691C8_TCameraCtrl__data_804FF700) == 0xC0 ? 1 : -1];
typedef char RecoveredGlobal_800691C8_main_task_size[sizeof(RecoveredGlobal_800691C8_main_task) == 0x34 ? 1 : -1];

typedef char RecoveredGlobal_80069148_TCameraCtrl__data_804FF6D0_size[sizeof(RecoveredGlobal_80069148_TCameraCtrl__data_804FF6D0) == 0x30 ? 1 : -1];
typedef char RecoveredGlobal_80069148_TCameraCtrl__data_804FF700_size[sizeof(RecoveredGlobal_80069148_TCameraCtrl__data_804FF700) == 0xC0 ? 1 : -1];
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

void TCameraCtrl::apply_split_screen_view_matrix() {
    if (is_split_screen() != 0) {
        if (get_mode__11TCameraCtrlFPv(&(*(RecoveredGlobal_800691C8_main_task *)&main_task).value) & 1) {
            TCameraCtrl::concat_matrix(0U, (u32) ((u8 *)&TCameraCtrl__view_matrices.value + ((TCameraCtrl::get_instance() - 1) * 0x30)));
            return;
        }
        TCameraCtrl::concat_matrix(0U, (u32) ((u8 *)&TCameraCtrl__view_matrices.value + (TCameraCtrl::get_camera_no() * 0x30)));
        return;
    }
    TCameraCtrl::concat_matrix(0U, (u32) &TCameraCtrl__view_matrix.value);
}

typedef char RecoveredGlobal_80069258_TCameraCtrl__data_804FF6D0_size[sizeof(RecoveredGlobal_80069258_TCameraCtrl__data_804FF6D0) == 0x30 ? 1 : -1];
typedef char RecoveredGlobal_80069258_TCameraCtrl__data_804FF700_size[sizeof(RecoveredGlobal_80069258_TCameraCtrl__data_804FF700) == 0xC0 ? 1 : -1];
typedef char RecoveredGlobal_80069258_main_task_size[sizeof(RecoveredGlobal_80069258_main_task) == 0x34 ? 1 : -1];
s32 *TCameraCtrl::get_view_matrix() {
    if (is_split_screen() != 0) {
        if (get_mode__11TCameraCtrlFPv((void *) (&(*(RecoveredGlobal_80069258_main_task *)&(*(RecoveredGlobal_800691C8_main_task *)&main_task)).value)) & 1) {
            return (long *) ((u8 *)&(*(RecoveredGlobal_80069258_TCameraCtrl__data_804FF700 *)&TCameraCtrl__view_matrices).value + ((TCameraCtrl::get_instance() - 1) * 0x30));
        }
        return (long *) ((u8 *)&(*(RecoveredGlobal_80069258_TCameraCtrl__data_804FF700 *)&TCameraCtrl__view_matrices).value + (TCameraCtrl::get_camera_no() * 0x30));
    }
    return &(*(RecoveredGlobal_80069258_TCameraCtrl__data_804FF6D0 *)&TCameraCtrl__view_matrix).value;
}

void TCameraCtrl::create() {
    void *obj = __nw__7TObjectFUl(0x1D4);
    if (obj != 0) {
        TCameraCtrl__ct((u8 *)obj, (void *)tl_camera);
    }
}

typedef char RecoveredGlobal_800695E8_TCameraCtrl__data_804FF628_size[sizeof(RecoveredGlobal_800695E8_TCameraCtrl__data_804FF628) == 0xC ? 1 : -1];

typedef char RecoveredGlobal_80069304_TCameraCtrl__data_804FF628_size[sizeof(RecoveredGlobal_80069304_TCameraCtrl__data_804FF628) == 0xC ? 1 : -1];
s32 TCameraCtrl__sub_80069304(void) {
    return ((u32) *(u32 *)((s8 *)(&(*(RecoveredGlobal_80069304_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value) + 8) >> 0xAU) & 1;
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
    fn_803D64F8(&lbl_804FF5E8.value);
    camera_renderer_setup_nop(&lbl_804FF5E8.value, 0x3555);
    TCameraCtrl::update_camera_state((f32) ((*(const f32 *)&TCameraCtrl__data_805D8FA8)), (f32) ((*(const f32 *)&TCameraCtrl__data_805D8FA8)), (f32) ((*(const f32 *)&TCameraCtrl__data_805D8FA8)));
    TCameraCtrl::look_at_position((f32) ((*(const f32 *)&TCameraCtrl__data_805D8FA8)), (f32) ((*(const f32 *)&TCameraCtrl__data_805D8FA8)), lbl_805D8FE4);
    stack.sp10 = TCameraCtrl__data_805D8FC0;
    stack.sp14 = TCameraCtrl__data_805D8FC4;
    stack.sp30 = TCameraCtrl__data_805D8FB8;
    stack.sp34 = TCameraCtrl__data_805D8FBC;
    stack.sp20 = lbl_805D8FCC;
    stack.sp38 = (*(const f32 *)&TCameraCtrl__data_805D8FA8);
    stack.sp3C = (*(const f32 *)&TCameraCtrl__data_805D8FA8);
    stack.sp40 = TCameraCtrl__data_805D8FD0;
    stack.sp44 = TCameraCtrl__data_805D8FD4;
    camera_default_view_value = (*(const f32 *)&TCameraCtrl__data_805D8FAC);
    camera_default_view_value_b = TCameraCtrl__data_805D8FD8;
    ((TCameraCtrl *)(&stack.sp8))->update_projection_params();
}

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
    stack.sp10 = TCameraCtrl__data_805D8FC0;
    stack.sp14 = TCameraCtrl__data_805D8FC4;
    stack.sp30 = TCameraCtrl__data_805D8FB8;
    stack.sp34 = TCameraCtrl__data_805D8FBC;
    stack.sp20 = lbl_805D8FCC;
    stack.sp38 = (*(const f32 *)&TCameraCtrl__data_805D8FA8);
    stack.sp3C = (*(const f32 *)&TCameraCtrl__data_805D8FA8);
    stack.sp40 = TCameraCtrl__data_805D8FD0;
    stack.sp44 = TCameraCtrl__data_805D8FD4;
    stack.sp48 = (*(const f32 *)&TCameraCtrl__data_805D8FAC);
    stack.sp4C = TCameraCtrl__data_805D8FD8;
    ((CameraViewParams *)&stack.sp8)->apply();
    ((TCameraCtrl *)(&(*(RecoveredGlobal_800693F4_TCameraCtrl__data_804FF634 *)&TCameraCtrl__data_804FF634).value))->update_projection_params();
    camera_default_view_value = (*(const f32 *)&TCameraCtrl__data_805D8FAC);
    camera_default_view_value_b = TCameraCtrl__data_805D8FD8;
}

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
typedef char RecoveredGlobal_800694A8_TCameraCtrl__data_804FF628_size[sizeof(RecoveredGlobal_800694A8_TCameraCtrl__data_804FF628) == 0xC ? 1 : -1];
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
    stack.sp10 = TCameraCtrl__data_805D8FC0;
    stack.sp14 = TCameraCtrl__data_805D8FC4;
    stack.sp30 = TCameraCtrl__data_805D8FB8;
    stack.sp34 = TCameraCtrl__data_805D8FBC;
    stack.sp38 = (*(const f32 *)&TCameraCtrl__data_805D8FA8);
    stack.sp3C = (*(const f32 *)&TCameraCtrl__data_805D8FA8);
    stack.sp40 = TCameraCtrl__data_805D8FD0;
    stack.sp44 = TCameraCtrl__data_805D8FD4;
    stack.sp48 = (*(const f32 *)&TCameraCtrl__data_805D8FAC);
    stack.sp4C = TCameraCtrl__data_805D8FD8;
    ((CameraViewParams *)&stack.sp8)->apply();
}
#pragma pop

#pragma push
#pragma opt_common_subs off
typedef char RecoveredGlobal_80069534_lbl_804381BC_size[sizeof(RecoveredGlobal_80069534_lbl_804381BC) == 0x14 ? 1 : -1];
typedef char RecoveredGlobal_80069534_TCameraCtrl__data_804FF628_size[sizeof(RecoveredGlobal_80069534_TCameraCtrl__data_804FF628) == 0xC ? 1 : -1];
void TCameraCtrl::reset_viewport_scissor() {
    typedef char sp8_offset[(offsetof(Stack_80069534, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_80069534, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_80069534, sp10) == 0x8) ? 1 : -1];
    typedef char sp14_offset[(offsetof(Stack_80069534, sp14) == 0xC) ? 1 : -1];
    Stack_80069534 stack;
    stack.sp8 = *(s32 *)((s8 *)&camera_ctrl_scissor_default_vec.value + 0);
    stack.spC = *(s32 *)((s8 *)&camera_ctrl_scissor_default_vec.value + 4);
    stack.sp10 = *(s32 *)((s8 *)&camera_ctrl_scissor_default_vec.value + 8);
    stack.sp14 = *(s32 *)((s8 *)&camera_ctrl_scissor_default_vec.value + 0xC);
    if (*(s32 *)((s8 *)(&(*(RecoveredGlobal_80069534_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value) + 8) & 0x200) {
        *(s32 *)((s8 *)(&(*(RecoveredGlobal_80069534_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value) + 8) = (s32) (*(s32 *)((s8 *)(&(*(RecoveredGlobal_80069534_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value) + 8) & 0xFFFFFDFF);
    }
    set_viewport_scissor__11TCameraCtrlFiPv(0, (void *)&stack.sp8);
}
#pragma pop

s32 CameraViewParams::begin_override() {
    if ((*(G_800695A0 *)&TCameraCtrl__view_state).flags & 0x400) {
        return 0;
    }
    (*(G_800695A0 *)&TCameraCtrl__view_state).flags |= 0x400;
    apply();
    return 1;
}

void CameraViewParams::apply_if_overridden() {
    if (*(s32 *)((s8 *)&TCameraCtrl__view_state.value + 8) & 0x400) {
        apply();
    }
}

typedef char RecoveredGlobal_8006961C_TCameraCtrl__data_804FF628_size[sizeof(RecoveredGlobal_8006961C_TCameraCtrl__data_804FF628) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_8006961C_TCameraCtrl__data_804FF634_size[sizeof(RecoveredGlobal_8006961C_TCameraCtrl__data_804FF634) == 0x48 ? 1 : -1];
typedef char RecoveredGlobal_8006961C_lbl_8058CA60_size[sizeof(RecoveredGlobal_8006961C_lbl_8058CA60) == 0x58 ? 1 : -1];
void CameraViewParams::apply() {
    *(s32 *)((s8 *)(&(*(RecoveredGlobal_8006961C_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value) + 8) = (s32) (*(s32 *)((s8 *)(&(*(RecoveredGlobal_8006961C_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value) + 8) | 0x200);
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_8006961C_TCameraCtrl__data_804FF634 *)&TCameraCtrl__data_804FF634).value) + 0x28) = (f32) width;
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_8006961C_TCameraCtrl__data_804FF634 *)&TCameraCtrl__data_804FF634).value) + 0x2C) = (f32) height;
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_8006961C_TCameraCtrl__data_804FF634 *)&TCameraCtrl__data_804FF634).value) + 8) = (f32) center_x;
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_8006961C_TCameraCtrl__data_804FF634 *)&TCameraCtrl__data_804FF634).value) + 0xC) = (f32) center_y;
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_8006961C_TCameraCtrl__data_804FF634 *)&TCameraCtrl__data_804FF634).value) + 0x18) = (f32) *(f32 *)((s8 *)&scene_projection_state.value + 0x50);
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_8006961C_TCameraCtrl__data_804FF634 *)&TCameraCtrl__data_804FF634).value) + 0x1C) = (f32) *(f32 *)((s8 *)&scene_projection_state.value + 0x4C);
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_8006961C_TCameraCtrl__data_804FF634 *)&TCameraCtrl__data_804FF634).value) + 0x20) = (f32) (*(const f32 *)&TCameraCtrl__data_805D8FAC);
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_8006961C_TCameraCtrl__data_804FF634 *)&TCameraCtrl__data_804FF634).value) + 0x24) = (f32) ((*(const f32 *)&TCameraCtrl__data_805D8FAC) / *(f32 *)((s8 *)&scene_projection_state.value + 0x4C));
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_8006961C_TCameraCtrl__data_804FF634 *)&TCameraCtrl__data_804FF634).value) + 0) = (f32) (*(f32 *)((s8 *)&scene_projection_state.value + 0x4C) * *(f32 *)((s8 *)&scene_projection_state.value + 0x50));
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_8006961C_TCameraCtrl__data_804FF634 *)&TCameraCtrl__data_804FF634).value) + 4) = (f32) -((*(const f32 *)&TCameraCtrl__data_805D8FAC) * *(f32 *)((s8 *)&scene_projection_state.value + 0x50));
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_8006961C_TCameraCtrl__data_804FF634 *)&TCameraCtrl__data_804FF634).value) + 0x30) = (f32) pad_30[0];
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_8006961C_TCameraCtrl__data_804FF634 *)&TCameraCtrl__data_804FF634).value) + 0x34) = (f32) pad_30[1];
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_8006961C_TCameraCtrl__data_804FF634 *)&TCameraCtrl__data_804FF634).value) + 0x38) = (f32) pad_30[2];
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_8006961C_TCameraCtrl__data_804FF634 *)&TCameraCtrl__data_804FF634).value) + 0x3C) = (f32) pad_30[3];
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_8006961C_TCameraCtrl__data_804FF634 *)&TCameraCtrl__data_804FF634).value) + 0x40) = (f32) pad_30[4];
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_8006961C_TCameraCtrl__data_804FF634 *)&TCameraCtrl__data_804FF634).value) + 0x44) = (f32) pad_30[5];
}

void*TCameraCtrl::get_target() { return (char*)this + 0x68; }

typedef char RecoveredGlobal_80069A6C_camera_controller_registry_size[sizeof(RecoveredGlobal_80069A6C_camera_controller_registry) == 0x68 ? 1 : -1];
typedef char RecoveredGlobal_80069A6C_TCameraCtrl__data_804FF628_size[sizeof(RecoveredGlobal_80069A6C_TCameraCtrl__data_804FF628) == 0xC ? 1 : -1];

void TCameraCtrl::resolve_anchor_obstruction() {
    View_800696D0 *self = (View_800696D0 *)this;
    Vec_800696D0 d;
    s32 n;
    s32 *flag;
    Hit_800696D0 *hit;
    if (is_split_screen() != 0) {
        n = TCameraCtrl::get_camera_no();
        flag = &self->split_flags[n];
        hit = (Hit_800696D0 *)csnVector(&self->split_look[n], &self->eye, 0x901);
    } else {
        hit = (Hit_800696D0 *)csnVector(&self->look, &self->eye, 0x901);
        flag = &self->flag;
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
        if (TCameraCtrl__data_805D8FA8 != vector_length(&d)) {
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
        *flag = 1;
    } else {
        if (is_split_screen() != 0) {
            n = TCameraCtrl::get_camera_no();
            VecCopy((Vec *)&self->split_look[n], (const Vec *)&self->split_pos[n]);
        } else {
            VecCopy((Vec *)&self->look, (const Vec *)&self->pos);
        }
        *flag = 0;
    }
}

void TCameraCtrl::clamp_to_target_obstruction() {
    View_800698C8 *self = (View_800698C8 *)this;
    s32 n;
    Hit_800698C8 *hit;
    s32 *flag;
    n = TCameraCtrl::get_camera_no();
    if (is_split_screen() != 0) {
        flag = &self->split_flags[n];
    } else {
        flag = &self->flag;
    }
    if (*flag == 0) {
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

void TCameraCtrl::update_target_smoothing() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r3;
    u8 *temp_r3_2;
    this->m_178 = (f32) *(f32 *)&this->unk_1A0;
    this->m_17c = (f32) this->m_1a4;
    this->m_180 = (f32) *(f32 *)&this->unk_1A8;
    this->m_1c8 = (f32) this->m_178;
    *(f32 *)&this->unk_1CC = (f32) this->m_17c;
    this->m_1d0 = (f32) this->m_180;
    if (is_split_screen() != 0) {
        temp_r3 = arg0 + (TCameraCtrl::get_camera_no() * 0xC);
        *(f32 *)((s8 *)temp_r3 + 0x134) = (f32) this->m_178;
        *(f32 *)((s8 *)temp_r3 + 0x138) = (f32) this->m_17c;
        *(f32 *)((s8 *)temp_r3 + 0x13C) = (f32) this->m_180;
    }
    temp_r3_2 = (u8 *)(*(u8 **)((s8 *)((u8 *)(&(*(RecoveredGlobal_80069A6C_camera_controller_registry *)&camera_controller_registry).value) + ((*(RecoveredGlobal_80069A6C_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value * 4)) + 0));
    if ((temp_r3_2 != NULL) && !(*(s32 *)((s8 *)temp_r3_2 + 0x38) & 0x10)) {
        *(f32 *)&this->unk_188 = (f32) *(f32 *)&this->unk_1B0;
    }
    approach_camera_vector((u8 *)&this->m_184, (u8 *)&this->m_1ac, this->m_1bc);
}

void TCameraCtrl::update_position() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r3;

    this->m_178 = (f32) *(f32 *)&this->unk_1A0;
    this->m_17c = (f32) this->m_1a4;
    this->m_180 = (f32) *(f32 *)&this->unk_1A8;
    this->m_184 = (f32) this->m_1ac;
    *(f32 *)&this->unk_188 = (f32) *(f32 *)&this->unk_1B0;
    this->m_18c = (f32) this->m_1b4;
    this->m_1c8 = (f32) this->m_178;
    *(f32 *)&this->unk_1CC = (f32) this->m_17c;
    this->m_1d0 = (f32) this->m_180;
    if (is_split_screen() != 0) {
        temp_r3 = arg0 + (TCameraCtrl::get_camera_no() * 0xC);
        *(f32 *)((s8 *)temp_r3 + 0x134) = (f32) this->m_178;
        *(f32 *)((s8 *)temp_r3 + 0x138) = (f32) this->m_17c;
        *(f32 *)((s8 *)temp_r3 + 0x13C) = (f32) this->m_180;
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
    approach_camera_vector((void *) temp_r31, (u8 *)&this->unk_1A0, (f32) (*((f32 *) (((s8 *) arg0) + 0x1B8))));
    VecCopy((Vec *)(arg0 + 0x178), (const Vec *)temp_r31);
    current = (temp_r30 + 0x104);
    approach_camera_vector((void *) current, (u8 *)&this->m_1ac, this->m_1bc);
    VecCopy((Vec *)(arg0 + 0x184), (const Vec *)current);
    return;
  }
  approach_camera_vector((u8 *)&this->m_178, (u8 *)&this->unk_1A0, (f32) (*((f32 *) (((s8 *) arg0) + 0x1B8))));
  approach_camera_vector((u8 *)&this->m_184, (u8 *)&this->m_1ac, this->m_1bc);
}
typedef char RecoveredGlobal_80069C94_camera_controller_registry_size[sizeof(RecoveredGlobal_80069C94_camera_controller_registry) == 0x68 ? 1 : -1];
typedef char RecoveredGlobal_80069C94_TCameraCtrl__data_804FF628_size[sizeof(RecoveredGlobal_80069C94_TCameraCtrl__data_804FF628) == 0xC ? 1 : -1];
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
typedef char RecoveredGlobal_80069D04_camera_controller_registry_size[sizeof(RecoveredGlobal_80069D04_camera_controller_registry) == 0x68 ? 1 : -1];
typedef char RecoveredGlobal_80069D04_TCameraCtrl__data_804FF628_size[sizeof(RecoveredGlobal_80069D04_TCameraCtrl__data_804FF628) == 0xC ? 1 : -1];
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
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
typedef char RecoveredGlobal_80069D7C_TCameraCtrl__data_804FF628_size[sizeof(RecoveredGlobal_80069D7C_TCameraCtrl__data_804FF628) == 0xC ? 1 : -1];
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

typedef struct RecoveredGlobal_80069E7C_TCameraCtrl__data_804FF628 RecoveredGlobal_80069E7C_TCameraCtrl__data_804FF628;
typedef struct RecoveredGlobal_80069E7C_camera_controller_registry RecoveredGlobal_80069E7C_camera_controller_registry;
typedef struct VBase_18_f8ef8c VBase_18_f8ef8c;
typedef struct VObj_18_f8ef8c VObj_18_f8ef8c;
typedef char RecoveredGlobal_80069E7C_camera_controller_registry_size[((sizeof(RecoveredGlobal_80069E7C_camera_controller_registry)) == 0x68) ? (1) : (-1)];
typedef char RecoveredGlobal_80069E7C_TCameraCtrl__data_804FF628_size[((sizeof(RecoveredGlobal_80069E7C_TCameraCtrl__data_804FF628)) == 0xC) ? (1) : (-1)];
#define PSO_VCALL_VObj_18_f8ef8c_m5(_self) (((VObj_18_f8ef8c *)(_self))->m5())

s32 restore_player_cameras(void) {
    s32 identity;
    u8 *player;
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
    v = TCameraCtrl__data_805D8FA8;
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
}

#undef CAM_80069F20
#undef OUT_80069F20
