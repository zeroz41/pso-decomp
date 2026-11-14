#include "types.h"
#include "pso/camera/TCameraCtrl_8006C254.h"
#include "pso/unk/TUnk_80488B38.h"
#include "pso/unk/TUnk_80488B68.h"
#include "pso/unk/TUnk_80488B08.h"
#include "pso/system/vector.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/camera/CameraHelpers.h"
#include <stddef.h>
#include "pso/camera/TCameraCtrl_80067FC0.h"
#include "pso/camera/TCameraCtrl_8006C580.h"
#include "pso/system/memory.h"
#include "pso/unk/TUnk_80488D70.h"
#include "pso/system/scene/TScene.h"
#include "pso/map/FloorArea.h"

#pragma push
#pragma fp_contract on
#pragma pop

struct RecoveredGlobal_8006C03C_lbl_804FF5E8 {
    s32 value;
    u8 remaining[0x24];
};

extern "C" {
void direction_to_pitch_yaw(u8 *arg0, s32 *arg1, s32 *arg2);
}
void set_camera_look_at(u8 *eye, u8 *target, u8 *up);
extern RecoveredGlobal_8006C03C_lbl_804FF5E8 lbl_804FF5E8;
extern TCameraCtrl *camera_ctrl_instance;
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

u16 TCameraCtrl__sub_8006A5DC();
f32 fabs_float(f32);
f32 atan2_float(f32 y, f32 x);
f32 newton_sqrtf(f32);
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
  *arg2 = (s32) (10430.38043493439 * atan2_float(-(*((f32 *) (((s8 *) arg0) + 0))), -(*((f32 *) (((s8 *) arg0) + 8)))));
  temp_f1 = *((f32 *) (((s8 *) arg0) + 0));
  temp_f0 = *((f32 *) (((s8 *) arg0) + 8));
  new_var = newton_sqrtf((temp_f1 * temp_f1) + (temp_f0 * temp_f0));
  *arg1 = (s32) (10430.38043493439 * atan2_float((f64) (*((f32 *) (((s8 *) arg0) + 4))), new_var));
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
        if (step >= 5.0) {
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

typedef char RecoveredGlobal_8006C03C_lbl_804FF5E8_size[sizeof(RecoveredGlobal_8006C03C_lbl_804FF5E8) == 0x28 ? 1 : -1];
void TUnk_80488B68::post_update_view() {
    Vec at;
    Vec dir;
    dir.x = target.x - position.x;
    dir.y = target.y - position.y;
    dir.z = target.z - position.z;
    direction_to_pitch_yaw((u8 *)&dir, (s32 *)&camera_ctrl_instance->pitch, (s32 *)&camera_ctrl_instance->yaw);
    at.x = camera_ctrl_instance->tgt_x;
    at.y = camera_ctrl_instance->tgt_y;
    at.z = camera_ctrl_instance->tgt_z;
    Vec up = {0.0f, 1.0f, 0.0f};
    set_camera_look_at((u8 *)&camera_ctrl_instance->pos_x, (u8 *)&at, (u8 *)&up);
    *(f32 *)((s8 *)&lbl_804FF5E8.value + 0) = camera_ctrl_instance->pos_x;
    *(f32 *)((s8 *)&lbl_804FF5E8.value + 4) = camera_ctrl_instance->pos_y;
    *(f32 *)((s8 *)&lbl_804FF5E8.value + 8) = camera_ctrl_instance->pos_z;
}

void CameraPlayback::cache_target_and_forward(s32 angle) const {
    if ((void *) camera_ctrl_instance != NULL) {
        TCameraCtrl__saved_projection_angle = *(s32 *)((s8 *)camera_ctrl_instance + 0x19C);
        scripted_camera_projection_angle = angle;
    }
    configure_scripted_camera_playback((u8 *)this, angle);
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
        camera->mode = &paths[get_current_floor_area()].modes[camera->playback.bank];
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
