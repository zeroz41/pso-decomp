#include "types.h"
#include "pso/misc/TCameraCtrl_8006C254.h"
#include "pso/misc/TUnk_80488B38.h"
#include "pso/misc/TUnk_80488B68.h"
#include "pso/misc/TUnk_80488B08.h"
#include "pso/system/vector.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/CameraHelpers.h"
#include <stddef.h>
#include "pso/misc/TOKeyMachine01.h"
#include "pso/misc/TCameraCtrl_80067FC0.h"
#include "pso/misc/TCameraCtrl_8006C580.h"
#include "pso/system/memory.h"
#include "pso/misc/TUnk_80488D70.h"
#include "pso/misc/TScene.h"
#include "pso/map/CurrentArea.h"

#pragma push
#pragma fp_contract on
#pragma pop

struct Stack_8006C03C {
    s32 sp8;
    s32 spC;
    s32 sp10;
    f32 sp14;
    f32 sp18;
    f32 sp1C;
    f32 sp20;
    f32 sp24;
    f32 sp28;
};

struct RecoveredGlobal_8006C03C_lbl_804383E0 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_8006C03C_lbl_804FF5E8 {
    s32 value;
    u8 remaining[0x24];
};

struct RecoveredFields_8006C03C_arg0 {
    u8 unknown_0[0x3C];
    f32 field_3C;
    f32 field_40;
    f32 field_44;
    f32 field_48;
    f32 field_4C;
    f32 field_50;
};

struct RecoveredFields_8006C03C_lbl_805D4DF0 {
    u8 unknown_0[0x178];
    f32 field_178;
    f32 field_17C;
    f32 field_180;
    f32 field_184;
    f32 field_188;
    f32 field_18C;
};

extern "C" {
void direction_to_pitch_yaw(u8 *arg0, s32 *arg1, s32 *arg2);
}
void set_camera_look_at(u8 *eye, u8 *target, u8 *up);
extern RecoveredGlobal_8006C03C_lbl_804383E0 camera_look_at_up_vec;
extern RecoveredGlobal_8006C03C_lbl_804FF5E8 lbl_804FF5E8;
extern void *camera_ctrl_instance;
extern void* camera_controller_registry[];
void* camera_controller_registry[];

struct CameraMotionData;
struct CameraPathMode { u32 field_00; u32 flags; };
struct ScriptedCameraState {
    u8 object_state[0x6C];
    Vec position_origin;
    Vec target_origin;
    CameraAngles angles;
    CameraMotionData* motion_data;
    CameraPathMode* mode;
    CameraPlayback playback;
};
typedef char ScriptedCameraSize[(sizeof(ScriptedCameraState) == 0xA4) ? 1 : -1];
typedef char ScriptedCameraPositionOffset[(offsetof(ScriptedCameraState, position_origin) == 0x6C) ? 1 : -1];
typedef char ScriptedCameraTargetOffset[(offsetof(ScriptedCameraState, target_origin) == 0x78) ? 1 : -1];
typedef char ScriptedCameraYawOffset[(offsetof(ScriptedCameraState, angles) + offsetof(CameraAngles, yaw) == 0x88) ? 1 : -1];
typedef char ScriptedCameraPlaybackOffset[(offsetof(ScriptedCameraState, playback) == 0x98) ? 1 : -1];
extern "C" {
f32 vector_length(const Vec*);
void approach_vector_fixed_distance(const Vec*, const Vec*, Vec*, f32);
extern const f64 lbl_804383D8;

u16 TCameraCtrl__sub_8006A5DC();
f32 fabs_float(f32);
f32 atan2_float(f32 y, f32 x);
f32 newton_sqrtf(f32);
extern const f64 lbl_804383D0;
s32 angle_difference_abs(s32, s32);
s32 approach_angle_limited(s32, s32, s32);

}

s32 approach_camera_scalar(f32 *arg0, f32 *arg1, f32 farg0);
s32 approach_camera_scalar(f32 *arg0, f32 *target, f32 farg0) {
  f32 step;
  f32 new_var;
  f32 temp_f1;
  temp_f1 = fabs_float((*arg0) - (*target));
  step = (0.16f * temp_f1) * (new_var = farg0);
  if (temp_f1 > step)
  {
    step_camera_scalar((f32 *)((void *) arg0), (f32 *)((void *) target), (f32 *)((void *) arg0), (f32) step);
    return 0;
  }
  *arg0 = *target;
  return 1;
}

void step_camera_scalar(const f32* current, const f32* target, f32* output, f32 step) {
    f32 distance = fabs_float(*current - *target);
    if (0.0f == distance || distance <= step) {
        *output = *target;
        return;
    }
    f32 value = *current;
    if (value < *target) {
        *output = value + step;
        return;
    }
    *output = value - step;
}

void direction_to_pitch_yaw(u8 *arg0, s32 *arg1, s32 *arg2) {
  f32 new_var;
  f32 temp_f0;
  f32 temp_f1;
  *arg2 = (s32) (lbl_804383D0 * atan2_float(-(*((f32 *) (((s8 *) arg0) + 0))), -(*((f32 *) (((s8 *) arg0) + 8)))));
  temp_f1 = *((f32 *) (((s8 *) arg0) + 0));
  temp_f0 = *((f32 *) (((s8 *) arg0) + 8));
  new_var = newton_sqrtf((temp_f1 * temp_f1) + (temp_f0 * temp_f0));
  *arg1 = (s32) (lbl_804383D0 * atan2_float((f64) (*((f32 *) (((s8 *) arg0) + 4))), new_var));
}

BOOL approach_camera_vector(Vec *current, Vec *target, f32 rate) {
    f32 base_step;
    Vec delta;
    delta.x = current->x - target->x;
    delta.y = current->y - target->y;
    delta.z = current->z - target->z;
    f32 distance = vector_length(&delta);
    base_step = 0.16f * distance;
    f32 step = base_step * rate;
    if (distance > step) {
        if (step >= lbl_804383D8) {
            step = 12.0f;
        }
        approach_vector_fixed_distance(current, target, current, step);
        return FALSE;
    }
    target->x = current->x;
    target->y = current->y;
    target->z = current->z;
    return TRUE;
}

s32 TCameraCtrl::clamp_distance(s32 arg0, s32 arg1, s32 arg2) {
    if (angle_difference_abs(arg1, arg0) < (s32) (arg2 * 0x7F)) {
        return arg1;
    }
    return approach_angle_limited(arg0, arg1, arg2 * 0x7F);
}

void set_scripted_camera_pose(const Vec* position, const Vec* target, const CameraAngles* angles) {
    ScriptedCameraState* camera = (ScriptedCameraState*)camera_controller_registry[5];
    if (camera != NULL) {
        VecCopy(&camera->position_origin, position);
        VecCopy(&camera->target_origin, target);
        camera->angles.yaw = angles->yaw;
    }
}

extern s32 TCameraCtrl__saved_projection_angle;
extern s32 scripted_camera_projection_angle;

#pragma push
#pragma opt_common_subs off
typedef char RecoveredGlobal_8006C03C_lbl_804383E0_size[sizeof(RecoveredGlobal_8006C03C_lbl_804383E0) == 0x10 ? 1 : -1];
typedef char RecoveredGlobal_8006C03C_lbl_804FF5E8_size[sizeof(RecoveredGlobal_8006C03C_lbl_804FF5E8) == 0x28 ? 1 : -1];
typedef char RecoveredFields_8006C03C_arg0_3C_offset[offsetof(RecoveredFields_8006C03C_arg0, field_3C) == 0x3C ? 1 : -1];
typedef char RecoveredFields_8006C03C_arg0_40_offset[offsetof(RecoveredFields_8006C03C_arg0, field_40) == 0x40 ? 1 : -1];
typedef char RecoveredFields_8006C03C_arg0_44_offset[offsetof(RecoveredFields_8006C03C_arg0, field_44) == 0x44 ? 1 : -1];
typedef char RecoveredFields_8006C03C_arg0_48_offset[offsetof(RecoveredFields_8006C03C_arg0, field_48) == 0x48 ? 1 : -1];
typedef char RecoveredFields_8006C03C_arg0_4C_offset[offsetof(RecoveredFields_8006C03C_arg0, field_4C) == 0x4C ? 1 : -1];
typedef char RecoveredFields_8006C03C_arg0_50_offset[offsetof(RecoveredFields_8006C03C_arg0, field_50) == 0x50 ? 1 : -1];
typedef char RecoveredFields_8006C03C_lbl_805D4DF0_178_offset[offsetof(RecoveredFields_8006C03C_lbl_805D4DF0, field_178) == 0x178 ? 1 : -1];
typedef char RecoveredFields_8006C03C_lbl_805D4DF0_17C_offset[offsetof(RecoveredFields_8006C03C_lbl_805D4DF0, field_17C) == 0x17C ? 1 : -1];
typedef char RecoveredFields_8006C03C_lbl_805D4DF0_180_offset[offsetof(RecoveredFields_8006C03C_lbl_805D4DF0, field_180) == 0x180 ? 1 : -1];
typedef char RecoveredFields_8006C03C_lbl_805D4DF0_184_offset[offsetof(RecoveredFields_8006C03C_lbl_805D4DF0, field_184) == 0x184 ? 1 : -1];
typedef char RecoveredFields_8006C03C_lbl_805D4DF0_188_offset[offsetof(RecoveredFields_8006C03C_lbl_805D4DF0, field_188) == 0x188 ? 1 : -1];
typedef char RecoveredFields_8006C03C_lbl_805D4DF0_18C_offset[offsetof(RecoveredFields_8006C03C_lbl_805D4DF0, field_18C) == 0x18C ? 1 : -1];
void TCameraCtrl::apply_look_at_from_target() {
    u8 *arg0 = (u8 *)this;
    typedef char sp8_offset[(offsetof(Stack_8006C03C, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_8006C03C, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_8006C03C, sp10) == 0x8) ? 1 : -1];
    typedef char sp14_offset[(offsetof(Stack_8006C03C, sp14) == 0xC) ? 1 : -1];
    typedef char sp18_offset[(offsetof(Stack_8006C03C, sp18) == 0x10) ? 1 : -1];
    typedef char sp1C_offset[(offsetof(Stack_8006C03C, sp1C) == 0x14) ? 1 : -1];
    typedef char sp20_offset[(offsetof(Stack_8006C03C, sp20) == 0x18) ? 1 : -1];
    typedef char sp24_offset[(offsetof(Stack_8006C03C, sp24) == 0x1C) ? 1 : -1];
    typedef char sp28_offset[(offsetof(Stack_8006C03C, sp28) == 0x20) ? 1 : -1];
    Stack_8006C03C stack;
    stack.sp14 = ((RecoveredFields_8006C03C_arg0 *)arg0)->field_48 - ((RecoveredFields_8006C03C_arg0 *)arg0)->field_3C;
    stack.sp18 = ((RecoveredFields_8006C03C_arg0 *)arg0)->field_4C - ((RecoveredFields_8006C03C_arg0 *)arg0)->field_40;
    stack.sp1C = ((RecoveredFields_8006C03C_arg0 *)arg0)->field_50 - ((RecoveredFields_8006C03C_arg0 *)arg0)->field_44;
    direction_to_pitch_yaw((u8 *)((void *)&stack.sp14), (s32 *)((void *) ((*(u8 * *)&camera_ctrl_instance) + 0x190)), (s32 *)((void *) ((*(u8 * *)&camera_ctrl_instance) + 0x194)));
    stack.sp20 = ((RecoveredFields_8006C03C_lbl_805D4DF0 *)(*(u8 * *)&camera_ctrl_instance))->field_184;
    stack.sp24 = ((RecoveredFields_8006C03C_lbl_805D4DF0 *)(*(u8 * *)&camera_ctrl_instance))->field_188;
    stack.sp28 = ((RecoveredFields_8006C03C_lbl_805D4DF0 *)(*(u8 * *)&camera_ctrl_instance))->field_18C;
    stack.sp8 = *(s32 *)((s8 *)&camera_look_at_up_vec.value + 0);
    stack.spC = *(s32 *)((s8 *)&camera_look_at_up_vec.value + 4);
    stack.sp10 = *(s32 *)((s8 *)&camera_look_at_up_vec.value + 8);
    set_camera_look_at(((*(u8 * *)&camera_ctrl_instance) + 0x178), (u8 *)&stack.sp20, (u8 *)&stack.sp8);
    *(f32 *)((s8 *)&lbl_804FF5E8.value + 0) = (f32) ((RecoveredFields_8006C03C_lbl_805D4DF0 *)(*(u8 * *)&camera_ctrl_instance))->field_178;
    *(f32 *)((s8 *)&lbl_804FF5E8.value + 4) = (f32) ((RecoveredFields_8006C03C_lbl_805D4DF0 *)(*(u8 * *)&camera_ctrl_instance))->field_17C;
    *(f32 *)((s8 *)&lbl_804FF5E8.value + 8) = (f32) ((RecoveredFields_8006C03C_lbl_805D4DF0 *)(*(u8 * *)&camera_ctrl_instance))->field_180;
}
#pragma pop

void TCameraCtrl::cache_target_and_forward(s32 unused) {
    s32 playback_data = (s32)this;
    if ((void *) camera_ctrl_instance != NULL) {
        TCameraCtrl__saved_projection_angle = *(s32 *)((s8 *)camera_ctrl_instance + 0x19C);
        scripted_camera_projection_angle = unused;
    }
    configure_scripted_camera_playback((u8 *)playback_data, (s32)unused);
}

void configure_scripted_camera_playback(u8* playback_data, s32 unused) {
    struct MotionDirectory { CameraMotionData** entries; };
    struct MotionBank { MotionDirectory* directory; u32 unknown_04; };
    struct PathBank { CameraPathMode* modes; u32 unknown_04; };
    const CameraPlayback* playback = (const CameraPlayback*)playback_data;
    ScriptedCameraState* camera = (ScriptedCameraState*)camera_controller_registry[5];
    if (camera != NULL) {
        camera->playback.index = playback->index;
        camera->playback.bank = playback->bank;
        camera->playback.flags = playback->flags;
        camera->playback.frame = playback->frame;
        camera->playback.frame_step = playback->frame_step;
        const PathBank* paths = (const PathBank*)camera_path_bank_table;
        const MotionBank* motions = (const MotionBank*)&TCameraCtrl__camera_banks;
        camera->mode = &paths[get_current_area()].modes[camera->playback.bank];
        camera->motion_data = motions[playback->bank].directory->entries[camera->playback.index];
    }
}

CameraPlayback* get_scripted_camera_playback() {
    ScriptedCameraState* camera = (ScriptedCameraState*)camera_controller_registry[5];
    if (camera != NULL) {
        CameraPlayback* playback = &camera->playback;
        if (TCameraCtrl__sub_8006A5DC() != 5) {
            playback->flags |= 1;
        }
        return playback;
    }
    return NULL;
}

#pragma push
#pragma fp_contract on

#pragma pop
