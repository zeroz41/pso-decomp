#include "types.h"
#include "pso/misc/TUnk_80488A28.h"
#include "pso/system/vector.h"
#include "pso/boss/TBoss8Dragon.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TUnk_80488E00.h"
#include "pso/camera/CameraArrivalReset.h"
#include "pso/camera/FollowCameraController.h"
#include "pso/map/FloorArea.h"
extern "C" __declspec(section ".rodata") FollowVector lbl_80438528 = { 0.0f, 0.0f, 45.42f };
__declspec(section ".rodata") FollowVector lbl_80438534 = { 0.0f, 0.0f, 45.42f };

struct Base_8006CE78_8006CC30 { char pad[0x18]; };
struct VObj_8006CE78_8006CC30 : Base_8006CE78_8006CC30 {
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
    virtual void m12(s32);
};

struct RecoveredGlobal_8006CD78_TCameraCtrl__data_80488DE8 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_8006CD78_lbl_80488DF4 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_8006CDD0_TCameraCtrl__data_80488DE8 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_8006CDD0_lbl_80488DF4 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_8006CD2C_TCameraCtrl__data_80488DE8 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_8006D494_camera_controller_registry {
    s32 value;
    u8 remaining[0x64];
};

struct RecoveredGlobal_8006D494_TCameraCtrl__data_804FF628 {
    u8 value;
    u8 remaining[0xB];
};

struct RecoveredGlobal_8006D460_camera_controller_registry {
    s32 value;
    u8 remaining[0x64];
};

struct RecoveredGlobal_8006D460_TCameraCtrl__data_804FF628 {
    u8 value;
    u8 remaining[0xB];
};

struct RecoveredFields_8006DCD4_arg0 {
    u8 unknown_0[0x3C];
    f32 field_3C;
    f32 field_40;
    f32 field_44;
    f32 field_48;
    f32 field_4C;
    f32 field_50;
};

struct RecoveredGlobal_8006D610_camera_controller_registry {
    s32 value;
    u8 remaining[0x64];
};

struct RecoveredGlobal_8006D610_TCameraCtrl__data_804FF628 {
    u8 value;
    u8 remaining[0xB];
};

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

struct Ply_8006D2B0 { u8 pad[0x60]; s32 f60; };

struct Vec_8006D95C { f32 x, y, z; };

struct Tgt_8006D95C { u8 pad[0x38]; Vec_8006D95C pos; };

struct Cam_8006D95C { u8 pad[0x1C]; Tgt_8006D95C *tgt; u8 pad20[0x10]; s32 f30; u8 pad34[8]; Vec_8006D95C pos; u8 pad48[0xDC - 0x48]; u8 fdc[1]; };

struct Ply_8006D344 {
    u8 pad0[0x60];
    s32 f60;
};

struct VBase_8006E714 { char pad[0x18]; };

struct VObj_8006E714 : VBase_8006E714 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8();
};

struct Slot_8006E714 { u8 data[0x1c]; };

struct Obj_8006E714 {
    u8 pad0[0x18];
    void *vt;
    u8 pad1c[0x38 - 0x1c];
    s32 f38;
    u8 pad3c[0x6c - 0x3c];
    Slot_8006E714 slots[4];
    f32 fdc;
    f32 fe0;
    f32 fe4;
    f32 fe8;
    f32 fec;
    f32 ff0;
    s32 ff4;
    s32 ff8;
    s32 ffc;
    s32 f100;
    s32 f104;
    f32 f108;
    s32 f10c;
};

struct Pad_8006D1A4 {
    u8 pad0[0x14];
    s16 sx;
    u8 pad16[0x24 - 0x16];
    f32 mag;
};

struct Pads_8006D1A4 {
    u8 pad0[0x20];
    Pad_8006D1A4 p;
};

struct Obj_8006D1A4 {
    u8 pad0[0x30];
    s32 f30;
};

struct Cam_8006DB68 {
    u8 pad0[0x1C];
    u8 *actor;
    u8 pad20[0x18];
    s32 state;
    u8 pad3c[0x1C];
    f32 f58;
    u8 pad5c[0xA0];
    u32 flags;
};

typedef ArrivalCameraPose Cam_8006DD78;

typedef ArrivalCameraActor Tgt_8006DD78;

struct Hit_8006DD78 {
    u32 f0;
    FollowVector *point;
};

struct Tgt_8006DEF8 { u8 pad0[0x38]; FollowVector pos; u8 pad44[0x1C]; s32 angle; };

struct Preset_8006DEF8 { FollowVector pos; FollowVector target; s32 id; f32 a; f32 b; };

struct Cam_8006DEF8 {
    u8 pad0[0x30];
    s32 angle;
    u8 pad34[8];
    FollowVector pos;
    FollowVector target;
    s32 id;
};

struct Tgt_8006E170 { u8 pad0[0x38]; FollowVector pos; u8 pad44[0x1C]; s32 angle; };

struct Cam_8006E170 {
    u8 pad0[0x1C];
    Tgt_8006E170 *actor;
    u8 pad20[0x48 - 0x20];
    FollowVector pos;
    u8 pad54[0xE8 - 0x54];
    FollowVector fE8;
    u8 padF4[0x100 - 0xF4];
    s32 f100;
    u8 pad104[4];
    f32 f108;
};

struct Vec_8006D9F0 { f32 x, y, z; };

struct Ply_8006D9F0 { u8 pad[0x60]; s32 f60; };

struct CamBase_8006D9F0 { u8 pad0[0x18]; };

struct Cam_8006D9F0 : CamBase_8006D9F0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12(s32);
    Ply_8006D9F0 *ply;
    u8 pad20[0xDC - 0x20];
    Vec_8006D9F0 pos;
    f32 fE8;
    f32 fEC;
    f32 fF0;
    u8 padF4[0xFC - 0xF4];
    u32 flags;
};

#include <stddef.h>
#include "pso/misc/TWindowCtrl.h"
struct VBase_18_f70dca { char pad[0x18]; };

struct VObj_18_f70dca : VBase_18_f70dca {
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
    virtual s32 m12(s32);
};

struct VBase_18 { char pad[0x18]; };

struct VObj_18 : VBase_18 {
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
    virtual s32 m10();
};

struct Rec_8006E310 { u8 pad0[0x20]; u8 pad20[0x30]; };

extern RecoveredGlobal_8006CD78_TCameraCtrl__data_80488DE8 TCameraCtrl__override_position;
extern RecoveredGlobal_8006CD78_lbl_80488DF4 camera_fixed_target_position;
extern u8 TCameraCtrl__override_flags;
extern "C" {
s32 get_player_by_client_id(u32);
extern u16 TCameraCtrl__camera_override_client_id;
extern RecoveredGlobal_8006D494_camera_controller_registry camera_controller_registry;
extern RecoveredGlobal_8006D494_TCameraCtrl__data_804FF628 TCameraCtrl__view_state;
void end_conversation_camera(void);
u8 * csnVector(void *, void *, u32);
s32 angle_difference_abs(int, void *);
void begin_conversation_camera(void);
s32 is_split_screen();
void request_follow_camera_offsets(void *arg0, void *arg1, u16 arg2);
void push_matrix_from(void *);
void rotate_matrix_y(s32, s32);
void matrix_mult_vec(s32, void *, void *);
void pop_matrices(s32);
extern u8 identity_matrix[];
int get_camera_mode__11TCameraCtrlFv();
int __ct__13TUnk_80488A28Fv(void);
void TCameraCtrl__sub_8006E804(void* a0);
extern s32 follow_camera_vtable[];
extern Pads_8006D1A4 controller_input_state;
f32 horizontal_distance_squared(void *, void *);
f32 vec_squared_length(FollowVector *);
void normalize_vector(FollowVector *);
extern FollowVector lbl_80438534;
void camera_renderer_setup_nop(void *, s32);
extern FollowVector lbl_80438528;
extern Preset_8006DEF8 *follow_camera_init_pose_table[];
extern u8 lbl_804FF5E8[];
FollowVector *get_position_ptr__10TObjPlayerFv(void *);
FollowVector *get_target_ptr__11TCameraCtrlFv(void *);
}
extern void *local_client_id;
void reset_cameras_to_actor(void *p, s32 x);
extern FollowView *camera_ctrl_instance;

s32 conversation_camera_obstructed(FollowController *self,s32 heading);
void apply_follow_camera_offsets(void *arg0, void *arg1, s32 arg2, u16 arg3);
s32 approach_camera_scalar(f32 *arg0, f32 *target, f32 farg0);
void get_dragon_follow_camera_offsets(u8 *arg0, u8 *arg1);
extern "C" {
void get_camera_offsets__12TBoss8DragonFPvPv(Vec_8006D9F0 *, Vec_8006D9F0 *);
extern Vec_8006D9F0 follow_camera_offset_default;
s32 sub_8006E7FC__13TUnk_80488E00Fv(void* p);
s32 is_flag_set__11TCameraCtrlFv(void);
s32 fn_8006E82C(s32);
s32 approach_angle_limited(s32, s32, s32);
s32 TWindowShortListCtrl__check_controller_button(void *, s32);
s32 is_on_current_screen__11TCameraCtrlFv(void *, s32);
s32 check_flag_100__10TObjPlayerFPv(void *);
void *TCameraCtrl__vt0(void);
void *__dt__13TUnk_80488A28Fv(void *arg0, s16 arg1);
void *TKeyBoardControl__sub_803DEB74(s32);
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

typedef char RecoveredGlobal_8006CD78_TCameraCtrl__data_80488DE8_size[sizeof(RecoveredGlobal_8006CD78_TCameraCtrl__data_80488DE8) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_8006CD78_lbl_80488DF4_size[sizeof(RecoveredGlobal_8006CD78_lbl_80488DF4) == 0xC ? 1 : -1];

typedef char RecoveredGlobal_8006CD2C_TCameraCtrl__data_80488DE8_size[sizeof(RecoveredGlobal_8006CD2C_TCameraCtrl__data_80488DE8) == 0xC ? 1 : -1];

void TCameraCtrl::reset_to_local_player() {
    TCameraCtrl__override_flags = 0;
    TCameraCtrl__camera_override_client_id = 0xFFFF;
    reset_cameras_to_actor(((void *)get_player_by_client_id((u32)local_client_id)), 0);
}

void TCameraCtrl::set_override_position_and_angle(u8 *arg0, s16 arg1) {
    TCameraCtrl__override_flags |= 2;
    VecCopy((Vec *)(&(*(RecoveredGlobal_8006CD2C_TCameraCtrl__data_80488DE8 *)&TCameraCtrl__override_position).value), (const Vec *)arg0);
    (*(s16 *)&TCameraCtrl__camera_override_client_id) = arg1;
}

void TCameraCtrl::set_fixed_position_and_target(u8 *arg0, u8 *arg1) {
    TCameraCtrl__override_flags |= 1;
    VecCopy((Vec *)&TCameraCtrl__override_position.value, (const Vec *)arg0);
    VecCopy((Vec *)&camera_fixed_target_position.value, (const Vec *)arg1);
}

typedef char RecoveredGlobal_8006CDD0_TCameraCtrl__data_80488DE8_size[sizeof(RecoveredGlobal_8006CDD0_TCameraCtrl__data_80488DE8) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_8006CDD0_lbl_80488DF4_size[sizeof(RecoveredGlobal_8006CDD0_lbl_80488DF4) == 0xC ? 1 : -1];
s32 TUnk_80488E00::sub_8006CDD0() {
    u8 *player;
    if ((u8) TCameraCtrl__override_flags != 0) {
        this->m_38 = 0;
        VecCopy((Vec *)(((u8 *)this) + 0x3C), (const Vec *)(&(*(RecoveredGlobal_8006CDD0_TCameraCtrl__data_80488DE8 *)&TCameraCtrl__override_position).value));
        if (TCameraCtrl__override_flags & 2) {
            player = (u8 *)(get_player_by_client_id((u32) TCameraCtrl__camera_override_client_id));
            if (player != NULL) {
                *(f32 *)((s8 *)((u8 *)this) + 0x48) = (f32) *(f32 *)((s8 *)player + 0x38);
                this->target.y = (f32) ((19.8f) + *(f32 *)((s8 *)player + 0x3C));
                *(f32 *)((s8 *)((u8 *)this) + 0x50) = (f32) *(f32 *)((s8 *)player + 0x40);
            }
        } else {
            VecCopy((Vec *)(((u8 *)this) + 0x48), (const Vec *)(&(*(RecoveredGlobal_8006CDD0_lbl_80488DF4 *)&camera_fixed_target_position).value));
        }
        return 1;
    }
    return 0;
}

void TCameraCtrl::set_pos_target(void *arg1, void *arg2, s32 arg3) {
    this->m_fc = (s32) (this->m_fc | 8);
    ((VObj_8006CE78_8006CC30*)this)->m12(arg3);
    *(f32 *)&this->unk_E8 = (f32) *(f32 *)((s8 *)arg1 + 0);
    this->m_ec = (f32) *(f32 *)((s8 *)arg1 + 4);
    *(f32 *)&this->unk_F0 = (f32) *(f32 *)((s8 *)arg1 + 8);
    this->m_dc = (f32) *(f32 *)((s8 *)arg2 + 0);
    *(f32 *)&this->unk_E0 = (f32) *(f32 *)((s8 *)arg2 + 4);
    this->m_e4 = (f32) *(f32 *)((s8 *)arg2 + 8);
}

s32 is_flag_set__11TCameraCtrlFv(void) {
    if (is_split_screen() != 0) {
        return 0;
    }
    return ((u32) *(u32 *)((s8 *)(TKeyBoardControl__sub_803DEB74(0x12)) + 8) >> 0x11U) & 1;
}

typedef char RecoveredGlobal_8006D494_camera_controller_registry_size[sizeof(RecoveredGlobal_8006D494_camera_controller_registry) == 0x68 ? 1 : -1];
typedef char RecoveredGlobal_8006D494_TCameraCtrl__data_804FF628_size[sizeof(RecoveredGlobal_8006D494_TCameraCtrl__data_804FF628) == 0xC ? 1 : -1];

typedef char RecoveredGlobal_8006D460_camera_controller_registry_size[sizeof(RecoveredGlobal_8006D460_camera_controller_registry) == 0x68 ? 1 : -1];
typedef char RecoveredGlobal_8006D460_TCameraCtrl__data_804FF628_size[sizeof(RecoveredGlobal_8006D460_TCameraCtrl__data_804FF628) == 0xC ? 1 : -1];

extern "C" f32 newton_sqrtf(f32);
#pragma push
#pragma fp_contract on
struct Pad_8006CF38 {
    u8 pad0[8];
    u32 buttons;
    u8 padC[0xC];
    u16 r18;
    u8 pad1A[2];
    s16 x;
    s16 y;
};

struct Cam_8006CF38 {
    u8 pad0[0x30];
    s32 f30;
    u8 pad34[0x20];
    s32 f54;
    u8 pad58[0x88];
    f32 fe0;
    f32 fe4;
};

void TUnk_80488E00::sub_8006CF38() {
    Cam_8006CF38 *arg0 = (Cam_8006CF38 *)this;
    Pad_8006CF38 *pad;
    f32 fx;
    f32 fy;
    f32 len;
    s32 r;
    s16 x;
    s16 y;
    s16 t;

    if (is_split_screen() != 0) {
        return;
    }
    pad = (Pad_8006CF38 *)TKeyBoardControl__sub_803DEB74(0x12);
    fx = pad->x;
    fy = pad->y;
    if (-31.0f < fx && fx <= 31.0f) {
        fx = 0.0f;
    }
    if (-31.0f < fy && fy <= 31.0f) {
        fy = 0.0f;
    }
    len = newton_sqrtf(fx * fx + fy * fy);
    if (0.0f != len) {
        len *= 0.0078125f;
    }
    if (len > 1.0f) {
        len = 1.0f;
    }
    r = (s16)pad->r18;
    x = (s16)pad->x;
    y = (s16)pad->y;
    if (len > 0.2f) {
        t = 2.5f * len;
        if (x > 0) {
            arg0->f30 += (s32)(182.04445f * t);
        } else {
            arg0->f30 -= (s32)(182.04445f * t);
        }
        arg0->f30 = (u16)arg0->f30;
    }
    arg0->fe0 -= 0.1f * y;
    arg0->fe4 -= 0.1f * r;
    if (pad->buttons & 0x10) {
        arg0->f54 += 0xB6;
    } else if (pad->buttons & 0x20) {
        arg0->f54 -= 0xB6;
    }
    if (arg0->f54 >= 0x71C7) {
        arg0->f54 = 0x71C7;
    }
    if (arg0->f54 <= 0xE38) {
        arg0->f54 = 0xE38;
    }
}

#pragma pop

void TCameraCtrl::rotate_heading_by_stick() {
    TCameraCtrl *arg0 = this;
    Pad_8006D1A4 *p;
    f32 mag;
    s16 sx;
    s16 amt;
    if (is_split_screen() != 0) {
        return;
    }
    p = &controller_input_state.p;
    if (p == 0) {
        return;
    }
    mag = p->mag;
    sx = p->sx;
    if (mag > (0.2f)) {
        amt = (s16)((2.5f) * mag);
        if (sx > 0) {
            arg0->m_30 += (s32)((182.04445f) * (f32)amt);
        } else {
            arg0->m_30 -= (s32)((182.04445f) * (f32)amt);
        }
        arg0->m_30 = (u16)arg0->m_30;
    }
}

void request_follow_camera_offsets(void *arg0, void *arg1, u16 arg2) {
    Ply_8006D2B0 *p;
    s32 v;
    v = 0x8000;
    p = NULL;
    if (is_split_screen() != 0) {
        if (arg2 != 0xFFFF) {
            p = ((Ply_8006D2B0 *)get_player_by_client_id(arg2));
        }
    } else {
        p = ((Ply_8006D2B0 *)get_player_by_client_id((u32)((*(s32 *)&local_client_id))));
    }
    if (p != NULL) {
        v = p->f60 + 0x8000;
    }
    apply_follow_camera_offsets(arg0, arg1, v, arg2);
}
}

#define REG_8006D344 ((void **)&camera_controller_registry)
void apply_follow_camera_offsets(void *arg0, void *arg1, s32 arg2, u16 arg3) {
    void *cam;
    Ply_8006D344 *p;
    s32 i;
    s32 v;
    if (TCameraCtrl__view_state.value <= 2 || TCameraCtrl__view_state.value == 3) {
        if (is_split_screen() != 0) {
            if (arg3 == 0xFFFF) {
                for (i = 0; i < 4; i++) {
                    cam = REG_8006D344[TCameraCtrl__view_state.value + i];
                    p = (Ply_8006D344 *)get_player_by_client_id(TCameraCtrl::get_nth_view_player_id(i));
                    v = arg2;
                    if (p != 0) {
                        v = p->f60 + arg2;
                    }
                    ((TCameraCtrl *)cam)->set_pos_target(arg0, arg1, v);
                }
                return;
            }
            cam = REG_8006D344[TCameraCtrl__view_state.value + arg3];
        } else {
            cam = REG_8006D344[TCameraCtrl__view_state.value];
        }
        if (cam != 0) {
            ((TCameraCtrl *)cam)->set_pos_target(arg0, arg1, arg2);
        }
    }
}
#undef REG_8006D344

void TCameraCtrl::set_active_camera_flag() {
    u8 *temp_r3;
    if ((u8) (*(RecoveredGlobal_8006D460_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value == 0) {
        temp_r3 = (u8 *)(*(s32 *)((s8 *)(&(*(RecoveredGlobal_8006D460_camera_controller_registry *)&camera_controller_registry).value) + (((*(RecoveredGlobal_8006D460_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value * 4) & 0x3FC)));
        if (temp_r3 != NULL) {
            *(s32 *)((s8 *)temp_r3 + 0x104) = 1;
        }
    }
}

void end_conversation_camera(void) {
    u32 temp_r3;
    if ((u8) TCameraCtrl__view_state.value == 0) {
        temp_r3 = *(s32 *)((s8 *)&camera_controller_registry.value + ((TCameraCtrl__view_state.value * 4) & 0x3FC));
        if (temp_r3 != 0U) {
            ((TCameraCtrl *)temp_r3)->set_field_100(0);
        }
    }
}

#pragma push
#pragma opt_common_subs off
typedef char RecoveredGlobal_8006D610_camera_controller_registry_size[sizeof(RecoveredGlobal_8006D610_camera_controller_registry) == 0x68 ? 1 : -1];
typedef char RecoveredGlobal_8006D610_TCameraCtrl__data_804FF628_size[sizeof(RecoveredGlobal_8006D610_TCameraCtrl__data_804FF628) == 0xC ? 1 : -1];

s32 conversation_camera_obstructed(FollowController *self,s32 heading) {
    FollowVector eye,candidate,offset;
    const FollowVector *source;
    if(((int)is_split_screen()))
        source=&camera_ctrl_instance->split_positions[get_camera_mode__11TCameraCtrlFv()];
    else
        source=&camera_ctrl_instance->position;
    VecCopy((Vec *)(&eye), (const Vec *)(source));
    VecCopy((Vec *)(&offset), (const Vec *)(&self->position_offset));
    offset.z += (7.0f);
    push_matrix_from(identity_matrix);
    rotate_matrix_y(0,heading);
    matrix_mult_vec(0,&offset,&offset);
    pop_matrices(1);
    VecCopy((Vec *)(&candidate), (const Vec *)(&self->actor->position));
    candidate.x+=offset.x;
    candidate.y+=(12.0f)+offset.y;
    candidate.z+=offset.z;
    if(((u32)csnVector(&eye, &candidate, (u32)(0x100))))return 1;
    return ((u32)csnVector(&candidate, &camera_ctrl_instance->target, (u32)(0x100))) ? 1 : 0;
}

void begin_conversation_camera(void) {
    s32 temp_r30;
    s32 temp_r31;
    s32 heading;
    s32 var_r31;
    u8 *temp_r29;
    u8 *temp_r3;
    if (((u8) (*(RecoveredGlobal_8006D610_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value == 0) && (temp_r29 = *(u8 **)((s8 *)((u8 *)(&(*(RecoveredGlobal_8006D610_camera_controller_registry *)&camera_controller_registry).value) + (((*(RecoveredGlobal_8006D610_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value * 4) & 0x3FC)) + 0), ((TCameraCtrl *)temp_r29)->set_field_100(1), temp_r3 = *(u8 **)((s8 *)temp_r29 + 0x1C), ((temp_r3 == NULL) == 0))) {
        temp_r30 = *(s32 *)((s8 *)temp_r3 + 0x60);
        temp_r31 = angle_difference_abs((int) (((TCameraCtrl *)temp_r29)->m_30), (void *)(temp_r30 + 0x6000));
        if (temp_r31 > angle_difference_abs((int) (((TCameraCtrl *)temp_r29)->m_30), (void *)(temp_r30 - 0x6000))) {
            var_r31 = temp_r30 - 0x6000;
            heading = temp_r30 + 0x6000;
        } else {
            var_r31 = temp_r30 + 0x6000;
            heading = temp_r30 - 0x6000;
        }
        if (conversation_camera_obstructed((FollowController *)(temp_r29), var_r31) != 0) {
            if (conversation_camera_obstructed((FollowController *)(temp_r29), heading) == 0) {
                ((TCameraCtrl *)temp_r29)->m_30 = heading;
            }
        } else {
            ((TCameraCtrl *)temp_r29)->m_30 = var_r31;
        }
    }
}
#pragma pop

void TCameraCtrl::update_follow_motion_state() {
    FollowVector d;
    s32 var_r4;
    s32 temp_r3_2;
    s32 temp_r3_3;
    s32 var_r31;
    s32 var_r4_2;
    FollowVector *temp_r31;
    FollowVector *temp_r3;
    u8 *temp_r3_4;
    u8 *temp_r4;
    temp_r31 = get_target_ptr__11TCameraCtrlFv(*(u8 **)((s8 *)((u8 *)this) + 0x1C));
    temp_r3 = get_position_ptr__10TObjPlayerFv(*(u8 **)((s8 *)((u8 *)this) + 0x1C));
    if (temp_r31 == NULL || temp_r3 == NULL) {
        return;
    }
    {
        d.x = temp_r3->x - temp_r31->x;
        d.y = temp_r3->y - temp_r31->y;
        d.z = temp_r3->z - temp_r31->z;
        if (vec_squared_length(&d) < (0.25f)) {
            var_r31 = 0;
        } else {
            var_r31 = 1;
        }
        switch (*(s32 *)&this->unk_F8) {
        case 0:
            if (var_r31 != 0) {
                *(s32 *)&this->unk_F8 = 1;
            }
            temp_r4 = (u8 *)(*(u8 **)((s8 *)((u8 *)this) + 0x1C));
            temp_r3_2 = *(s32 *)((s8 *)temp_r4 + 0x30);
            if ((temp_r3_2 & 0x100000) || (temp_r3_2 & 0x20) || ((s16) *(s16 *)((s8 *)temp_r4 + 0x326) == 8)) {
                this->m_f4 = 0;
            }
            if ((s32) this->m_f4 > 0xFA) {
                *(s32 *)&this->unk_F8 = 2;
                return;
            }
            break;
        case 1:
            this->m_f4 = 0;
            temp_r3_3 = this->m_fc;
            if (temp_r3_3 & 1) {
                if (temp_r3_3 & 0x10) {
                    *(f32 *)((s8 *)((u8 *)this) + 0x58) = (f32) (0.05f);
                    this->m_30 = TCameraCtrl::clamp_distance(this->m_30, (s32)((void *) (sub_8006E7FC__13TUnk_80488E00Fv(this))), 0x16C);
                } else {
                    *(f32 *)((s8 *)((u8 *)this) + 0x58) = (f32) (0.67f);
                    ((VObj_18_f70dca *)(this))->m12(*(s32 *)((s8 *)(*(u8 **)((s8 *)((u8 *)this) + 0x1C)) + 0x60) + 0x8000);
                    this->m_30 = (s32) (*(s32 *)((s8 *)(*(u8 **)((s8 *)((u8 *)this) + 0x1C)) + 0x60) + 0x8000);
                }
            } else {
                var_r4 = (temp_r3_3 & 4) ? 2 : 5;
                var_r4_2 = 0;
                temp_r3_4 = (u8 *)(*(void **)((s8 *)(*(u8 **)((s8 *)((u8 *)this) + 0x1C)) + 0x424));
                if ((temp_r3_4 != NULL) && ((u16) *(u16 *)((s8 *)temp_r3_4 + 0x514) != 0xFFFF) && (*(f32 *)((s8 *)temp_r3_4 + 0x518) <= (4.9e+03f))) {
                    var_r4_2 = 1;
                }
                if (var_r4_2 == 0) {
                    this->m_30 = TCameraCtrl::clamp_distance(this->m_30, (s32)((void *) (sub_8006E7FC__13TUnk_80488E00Fv(this))), var_r4);
                }
            }
            if (var_r31 == 0) {
                *(s32 *)&this->unk_F8 = 0;
                return;
            }
            break;
        case 2:
            ((VObj_18_f70dca *)(this))->m12(*(s32 *)((s8 *)(*(u8 **)((s8 *)((u8 *)this) + 0x1C)) + 0x60) + 0x8000);
            this->m_30 = TCameraCtrl::clamp_distance(this->m_30, (s32)((void *) (sub_8006E7FC__13TUnk_80488E00Fv(this))), 3);
            if (var_r31 != 0) {
                *(s32 *)&this->unk_F8 = 1;
                this->m_f4 = 0;
            }
            break;
        }
    }
}

void TCameraCtrl::calc_follow_position() {
    Cam_8006D95C *self = (Cam_8006D95C *)this;
    Vec_8006D95C v;
    push_matrix_from(identity_matrix);
    rotate_matrix_y(0, self->f30);
    matrix_mult_vec(0, self->fdc, &v);
    pop_matrices(1);
    self->pos.x = self->tgt->pos.x + v.x;
    self->pos.y = self->tgt->pos.y + v.y;
    self->pos.z = self->tgt->pos.z + v.z;
}

void TUnk_80488E00::select_follow_camera_offsets() {
    Cam_8006D9F0 *arg0 = (Cam_8006D9F0 *)this;
    s32 area = get_current_floor_area();
    if (area == AREA_DRAGON) {
        Vec_8006D9F0 b0;
        Vec_8006D9F0 a0;
        Vec_8006D9F0 b1;
        Vec_8006D9F0 a1;
        get_dragon_follow_camera_offsets((u8 *)&a0, (u8 *)&b0);
        request_follow_camera_offsets(&a0, &b0, 0xFFFF);
        get_dragon_follow_camera_offsets((u8 *)&a1, (u8 *)&b1);
        request_follow_camera_offsets(&a1, &b1, 0xFFFF);
    } else if (area == AREA_GAL_GRYPHON) {
        Vec_8006D9F0 b;
        Vec_8006D9F0 a;
        ((TBoss8Dragon *)(&a))->get_follow_camera_offsets((u8 *)&b);
        request_follow_camera_offsets(&a, &b, 0xFFFF);
    } else if (area == AREA_GOL_DRAGON) {
        Vec_8006D9F0 b;
        Vec_8006D9F0 a;
        get_camera_offsets__12TBoss8DragonFPvPv(&a, &b);
        request_follow_camera_offsets(&a, &b, 0xFFFF);
    } else {
        if (!(arg0->flags & 8)) {
            arg0->v12(arg0->ply->f60 + 0x8000);
            arg0->fE8 = (0.0f);
            arg0->fEC = (19.8f);
            arg0->fF0 = (-5.0f);
            arg0->pos.x = follow_camera_offset_default.x;
            arg0->pos.y = follow_camera_offset_default.y;
            arg0->pos.z = follow_camera_offset_default.z;
            if (is_split_screen() != 0 && TCameraCtrl::get_camera_id() == 2) {
                arg0->pos.z *= (1.4f);
                arg0->pos.y *= (0.9f);
            }
        }
        arg0->flags &= ~8;
    }
}

void TUnk_80488E00::update_follow_flags() {
    Cam_8006DB68 *arg0 = (Cam_8006DB68 *)this;
    FollowVector *src;
    arg0->state = 5;
    if (TCameraCtrl::get_camera_id() == 2) {
        arg0->f58 = (0.56f);
    } else {
        arg0->f58 = (0.67f);
    }
    if (is_split_screen() != 0) {
        src = &camera_ctrl_instance->split_positions[get_camera_mode__11TCameraCtrlFv()];
    } else {
        src = &camera_ctrl_instance->position;
    }
    if (horizontal_distance_squared(&camera_ctrl_instance->target, src) >= (529.0f)) {
        arg0->flags |= 4;
    } else {
        arg0->flags &= ~4;
    }
    if (((TUnk_80488E00 *)arg0)->predict_obstruction() != 0) {
        if (is_split_screen() != 0) {
            src = &camera_ctrl_instance->split_positions[get_camera_mode__11TCameraCtrlFv()];
        } else {
            src = &camera_ctrl_instance->position;
        }
        if (horizontal_distance_squared(src, arg0->actor + 0x38) > (4e+02f)) {
            arg0->flags |= 1;
        } else {
            arg0->flags |= 1;
            arg0->flags |= 0x10;
        }
    } else {
        arg0->flags &= ~1;
        arg0->flags &= ~0x10;
    }
    this->select_follow_camera_offsets();
}

void TUnk_80488E00::sub_8006DCC8() { this->m_fc = 0; }

void TUnk_80488E00::vfunc_9(u8 *arg1, u8 *arg2) {
    struct RecoveredFields_8006DCD4_arg0 *arg0 = (struct RecoveredFields_8006DCD4_arg0 *)this;
    u8 *temp_r3;
    if (arg1 != NULL) {
        arg0->field_48 = *(f32 *)((s8 *)arg1 + 0x38);
        arg0->field_4C = (19.8f) + *(f32 *)((s8 *)arg1 + 0x3C);
        arg0->field_50 = *(f32 *)((s8 *)arg1 + 0x40);
        arg0->field_3C = arg0->field_48 + *(f32 *)((s8 *)arg2 + 0);
        arg0->field_40 = arg0->field_4C + *(f32 *)((s8 *)arg2 + 4);
        arg0->field_44 = arg0->field_50 + *(f32 *)((s8 *)arg2 + 8);
        temp_r3 = (u8 *)(csnVector(&arg0->field_48, &arg0->field_3C, 0x100));
        if (temp_r3 != NULL) {
            VecCopy((Vec *)(&arg0->field_3C), (const Vec *)(*(s32 *)((s8 *)temp_r3 + 4)));
        }
    }
}

void TUnk_80488E00::vfunc_8(void *arg1_arg) {
    Cam_8006DD78 *arg0 = (Cam_8006DD78 *)this;
    const Tgt_8006DD78 *arg1 = (const Tgt_8006DD78 *)arg1_arg;
    FollowVector v = lbl_80438534;
    FollowVector d;
    Hit_8006DD78 *hit;
    if (arg1 != NULL) {
        arg0->heading = arg1->heading + 0x8000;
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, arg0->heading);
        matrix_mult_vec(0, &v, &v);
        pop_matrices(1);
        arg0->target.x = arg1->position.x;
        arg0->target.y = (19.8f) + arg1->position.y;
        arg0->target.z = arg1->position.z;
        arg0->position.x = arg0->target.x + v.x;
        arg0->position.y = arg0->target.y + v.y;
        arg0->position.z = arg0->target.z + v.z;
        hit = (Hit_8006DD78 *)csnVector(&arg0->target, &arg0->position, 0x100);
        if (hit != NULL) {
            d.x = arg0->position.x - arg0->target.x;
            d.y = arg0->position.y - arg0->target.y;
            d.z = arg0->position.z - arg0->target.z;
            if ((0.0f) != vec_squared_length(&d)) {
                normalize_vector(&d);
            }
            arg0->position.x = hit->point->x - d.x;
            arg0->position.y = hit->point->y - d.y;
            arg0->position.z = hit->point->z - d.z;
        }
    }
}

void TUnk_80488E00::vfunc_6() {  }

void TUnk_80488E00::vfunc_10() {
    Cam_8006DEF8 *self = (Cam_8006DEF8 *)this;
    FollowVector v = lbl_80438528;
    Tgt_8006DEF8 *p;
    s32 area;
    p = (Tgt_8006DEF8 *)get_player_by_client_id((u32)local_client_id);
    area = get_current_floor_area();
    if (p != NULL) {
        self->angle = p->angle + 0x8000;
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, self->angle);
        matrix_mult_vec(0, &v, &v);
        pop_matrices(1);
        self->target.x = p->pos.x;
        self->target.y = (25.43f) + ((19.8f) + p->pos.y);
        self->target.z = p->pos.z;
        self->pos.x = self->target.x + v.x;
        self->pos.y = self->target.y + v.y;
        self->pos.z = self->target.z + v.z;
    } else {
        switch (area) {
        case AREA_PIONEER2_EP1:
            VecCopy((Vec *)&self->pos, (const Vec *)&follow_camera_init_pose_table[0][0].pos);
            VecCopy((Vec *)&self->target, (const Vec *)&follow_camera_init_pose_table[0][0].target);
            self->id = follow_camera_init_pose_table[0][0].id;
            TCameraCtrl::set_clamped_offsets(follow_camera_init_pose_table[0][0].a, follow_camera_init_pose_table[0][0].b);
            break;
        case AREA_LOBBY:
            VecCopy((Vec *)&self->pos, (const Vec *)&follow_camera_init_pose_table[0][1].pos);
            VecCopy((Vec *)&self->target, (const Vec *)&follow_camera_init_pose_table[0][1].target);
            self->id = follow_camera_init_pose_table[0][1].id;
            TCameraCtrl::set_clamped_offsets(follow_camera_init_pose_table[0][1].a, follow_camera_init_pose_table[0][1].b);
            break;
        case AREA_PIONEER2_EP2:
            VecCopy((Vec *)&self->pos, (const Vec *)&follow_camera_init_pose_table[0][2].pos);
            VecCopy((Vec *)&self->target, (const Vec *)&follow_camera_init_pose_table[0][2].target);
            self->id = follow_camera_init_pose_table[0][2].id;
            TCameraCtrl::set_clamped_offsets(follow_camera_init_pose_table[0][2].a, follow_camera_init_pose_table[0][2].b);
            break;
        }
    }
    camera_renderer_setup_nop(lbl_804FF5E8, self->id);
    TCameraCtrl::update_camera_state(self->pos.x, self->pos.y, self->pos.z);
}

void *TCameraCtrl__vt0(void) {
    void *o = __nw__7TObjectFUl(0x110);
    if (o != NULL) {
        o = TCameraCtrl::construct_view_controller(o);
    }
    return o;
}

#pragma push
#pragma fp_contract on
void TCameraCtrl::compute_follow_target() {
    Cam_8006E170 *self = (Cam_8006E170 *)this;
    FollowVector o;
    FollowVector d;
    f32 k;
    FollowVector *t;
    FollowVector *p;
    f32 x;
    f32 y;
    f32 z;
    t = get_target_ptr__11TCameraCtrlFv(self->actor);
    p = get_position_ptr__10TObjPlayerFv(self->actor);
    d.x = p->x - t->x;
    d.y = p->y - t->y;
    d.z = p->z - t->z;
    vec_squared_length(&d);
    push_matrix_from(identity_matrix);
    rotate_matrix_y(0, self->actor->angle + 0x8000);
    matrix_mult_vec(0, &self->fE8, &o);
    pop_matrices(1);
    x = o.x + self->actor->pos.x + (18.0f) * d.x;
    y = o.y + self->actor->pos.y;
    z = o.z + self->actor->pos.z + (18.0f) * d.z;
    if (is_split_screen() != 0) {
        get_camera_mode__11TCameraCtrlFv();
    }
    self->pos.x = x;
    self->pos.y = y;
    self->pos.z = z;
    if (get_current_floor_area() == AREA_PIONEER2_EP1 || get_current_floor_area() == AREA_PIONEER2_EP2) {
        if (self->f100 != 0) {
            k = (-3.0f);
            approach_camera_scalar(&self->f108, &k, (1.4f));
        } else {
            k = (0.0f);
            approach_camera_scalar(&self->f108, &k, (1.4f));
        }
    }
    self->pos.y += self->f108;
}
#pragma pop

struct Pads_8006D1A4;
struct Cam_8006D95C;
struct Obj_8006D1A4;
struct Cam_8006E170;
void TCameraCtrl::update_follow_camera() {
    u8 *arg0 = (u8 *)this;
    s32 i;
    u8 *player;
    s32 flags;
    *(u8 **)((s8 *)arg0 + 0x1C) = (u8 *)get_player_by_client_id(*(u16 *)&this->m_20);
    if (*(u8 **)((s8 *)arg0 + 0x1C) == NULL) {
        ((TUnk_80488A28 *)arg0)->set_target(get_player_by_client_id((u32)local_client_id));
        *(s32 *)&this->unk_38 = 0;
        return;
    }
    if (is_split_screen() == 0) {
        u8 *p;
        p = (u8 *)get_player_by_client_id((u32)local_client_id);
        if (p != NULL) {
            if (((TObjPlayer *)(*(u8 **)((s8 *)arg0 + 0x1C)))->get_floor() != ((TObjPlayer *)p)->get_floor()) {
                reset_cameras_to_actor((void *)get_player_by_client_id((u32)local_client_id), 0);
                for (i = 0; i < 4; i++) {
                    p = (u8 *)get_player_by_client_id(i);
                    if (p != NULL) {
                        ((TObjPlayer *)p)->refresh_equipment_slot();
                    }
                }
                return;
            }
            if (*(u16 *)&this->m_20 != (s32)local_client_id && *(u8 **)((s8 *)arg0 + 0x1C) != NULL && ((TWindowCtrl *)(*(u8 **)((s8 *)arg0 + 0x1C)))->is_player_flag_4000_set() != 0) {
                reset_cameras_to_actor((void *)get_player_by_client_id((u32)local_client_id), 0);
                for (i = 0; i < 4; i++) {
                    p = (u8 *)get_player_by_client_id(i);
                    if (p != NULL) {
                        ((TObjPlayer *)p)->refresh_equipment_slot();
                    }
                }
            }
        }
    }
    if (*(s32 *)&this->unk_100 != 0) {
        this->m_f4 = 0;
        this->m_54 = approach_angle_limited(this->m_54, 0x22D8, 0xB6);
    } else if (get_current_floor_area() == AREA_PIONEER2_EP1 || get_current_floor_area() == AREA_PIONEER2_EP2) {
        if (is_split_screen() == 0 && is_on_current_screen__11TCameraCtrlFv((u8 *)&controller_input_state + 0x110, 0x20000) == 0) {
            this->m_54 = approach_angle_limited(this->m_54, 0x36C1, 0xB6);
        }
    } else {
        this->m_54 = approach_angle_limited(this->m_54, 0x36C1, 0xB6);
    }
    if (get_current_floor_area() == AREA_PIONEER2_EP1 || get_current_floor_area() == AREA_PIONEER2_EP2) {
        *(f32 *)&this->unk_E0 = (20.43f);
    }
    ((VObj_18 *)(arg0))->m10();
    if (((TUnk_80488E00 *)arg0)->sub_8006CDD0() != 0) {
        end_conversation_camera();
        ((TUnk_80488E00 *)arg0)->sub_8006DCC8();
        return;
    }
    switch (*(s32 *)&this->m_24) {
    case 0:
        *(f32 *)&this->unk_48 = *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x1C)) + 0x38);
        this->m_4c = (19.8f) + *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x1C)) + 0x3C);
        *(f32 *)&this->unk_50 = *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x1C)) + 0x40);
        this->m_30 = *(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x1C)) + 0x60) + 0x8000;
        *(s32 *)&this->m_24 = 1;
        break;
    case 1:
        i = (u16)TCameraCtrl::get_nth_view_player_id(TCameraCtrl::get_camera_no());
        player = (u8 *)get_player_by_client_id(i);
        if ((player != NULL && check_flag_100__10TObjPlayerFPv(player) == 0) || TWindowCtrl::get_flag_bit3() == 1) {
            i = fn_8006E82C(i);
            if ((TWindowShortListCtrl__check_controller_button(&((Rec_8006E310 *)&controller_input_state)[((TRaderMapCore *)player)->get_map_id()].pad20, i) != 0 && *(s32 *)&this->unk_100 == 0) || this->m_104 != 0) {
                this->m_104 = 0;
                this->m_30 = *(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x1C)) + 0x60) + 0x8000;
            }
        }
        if (((s32 (*)(void *))is_flag_set__11TCameraCtrlFv)(arg0) != 0) {
            this->m_f4 = 0;
            ((TUnk_80488E00 *)arg0)->sub_8006CF38();
        } else {
            flags = *(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x1C)) + 0x30);
            if ((flags & 0x100000) || (flags & 0x20)) {
                this->m_f4 = 0;
            } else if (flags & 0x800) {
                this->m_f4 = 0;
                rotate_heading_by_stick();
            } else {
                ((TCameraCtrl *)arg0)->update_follow_motion_state();
            }
        }
        calc_follow_position();
        compute_follow_target();
        break;
    }
    ((TUnk_80488E00 *)arg0)->sub_8006DCC8();
}

void *TCameraCtrl::deleting_dtor(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = follow_camera_vtable;
        *(s32 *)((s8 *)this + 0x1C) = 0;
        *(s32 *)&this->unk_100 = 0;
        __dt__13TUnk_80488A28Fv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

#define O_8006E714 ((Obj_8006E714 *)arg0)
void *TCameraCtrl::construct_view_controller(void *arg0) {
    s32 i;
    __ct__13TUnk_80488A28Fv();
    O_8006E714->vt = ((u8 *)&follow_camera_vtable);
    TCameraCtrl__override_flags = 0;
    TCameraCtrl__camera_override_client_id = 0xFFFF;
    O_8006E714->ffc = 0;
    O_8006E714->ff4 = 0;
    O_8006E714->ff8 = 0;
    O_8006E714->fdc = (0.0f);
    O_8006E714->fe0 = (0.0f);
    O_8006E714->fe4 = (0.0f);
    O_8006E714->fe8 = (0.0f);
    O_8006E714->fec = (0.0f);
    O_8006E714->ff0 = (0.0f);
    O_8006E714->f38 = 5;
    ((TUnk_80488A28 *)O_8006E714)->set_target(get_player_by_client_id((u32)local_client_id));
    ((VObj_8006E714 *)O_8006E714)->m8();
    O_8006E714->f100 = 0;
    O_8006E714->f104 = 0;
    O_8006E714->f10c = 0;
    O_8006E714->f108 = (0.0f);
    for (i = 0; i < 4; i++) {
        TCameraCtrl__sub_8006E804(&O_8006E714->slots[i]);
    }
    return arg0;
}
#undef O_8006E714

s32 TCameraCtrl::set_field_100(s32 v) { *(s32 *)&this->unk_100 = v; }
s32 TUnk_80488E00::sub_8006E7FC() { return this->m_10c; }

void TCameraCtrl__sub_8006E804(void* a0) { *(int*)((char*)a0 + 0x18) = 0; *(float*)((char*)a0 + 0x0) = (0.0f); *(float*)((char*)a0 + 0x4) = (0.0f); *(float*)((char*)a0 + 0x8) = (0.0f); *(float*)((char*)a0 + 0xc) = (0.0f); *(float*)((char*)a0 + 0x10) = (0.0f); *(float*)((char*)a0 + 0x14) = (0.0f); }
