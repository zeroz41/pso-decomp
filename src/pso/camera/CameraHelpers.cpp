#include "types.h"
#include "pso/camera/CameraHelpers.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/render/GinjaView.h"
#include "pso/camera/TCameraScripted.h"
#include "pso/map/FloorArea.h"
#include "pso/math/MatrixVector.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/render/render_util.h"
#include "pso/system/vector.h"

extern f32 lbl_804FF5E8[];
extern TCameraCtrl *camera_ctrl_instance;
extern void *camera_controller_registry[];

s32 approach_camera_scalar(f32 *current, f32 *target, f32 rate) {
    f32 distance = fabs_float(*current - *target);
    f32 step = 0.16f * distance * rate;
    if (distance > step) {
        step_camera_scalar(current, target, current, step);
        return 0;
    }
    *current = *target;
    return 1;
}

void step_camera_scalar(const f32 *current, const f32 *target, f32 *output, f32 step) {
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

void direction_to_pitch_yaw(Vec *direction, s32 *pitch, s32 *yaw) {
    *yaw = (s32)(10430.38043493439 * atan2_float(-direction->x, -direction->z));
    f32 horizontal = newton_sqrtf(direction->x * direction->x + direction->z * direction->z);
    *pitch = (s32)(10430.38043493439 * atan2_float(direction->y, horizontal));
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

s32 TCameraCtrl::clamp_distance(s32 yaw, s32 to, s32 step_scale) {
    if (angle_difference_abs(to, yaw) < (s32)(step_scale * 0x7F)) {
        return to;
    }
    return approach_angle_limited(yaw, to, step_scale * 0x7F);
}

void set_scripted_camera_pose(const Vec *position, const Vec *target, const CameraAngles *angles) {
    TCameraScripted *camera = (TCameraScripted *)camera_controller_registry[5];
    if (camera != NULL) {
        VecCopy(&camera->position_origin, position);
        VecCopy(&camera->target_origin, target);
        camera->angles.yaw = angles->yaw;
    }
}

void TCameraScripted::post_update_view() {
    Vec at;
    Vec dir;
    dir.x = target.x - position.x;
    dir.y = target.y - position.y;
    dir.z = target.z - position.z;
    direction_to_pitch_yaw(&dir, (s32 *)&camera_ctrl_instance->pitch, (s32 *)&camera_ctrl_instance->yaw);
    at.x = camera_ctrl_instance->tgt.x;
    at.y = camera_ctrl_instance->tgt.y;
    at.z = camera_ctrl_instance->tgt.z;
    Vec up = {0.0f, 1.0f, 0.0f};
    set_camera_look_at((u8 *)&camera_ctrl_instance->pos.x, (u8 *)&at, (u8 *)&up);
    lbl_804FF5E8[0] = camera_ctrl_instance->pos.x;
    lbl_804FF5E8[1] = camera_ctrl_instance->pos.y;
    lbl_804FF5E8[2] = camera_ctrl_instance->pos.z;
}

void CameraPlayback::cache_target_and_forward(s32 angle) const {
    if (camera_ctrl_instance != NULL) {
        saved_projection_angle = camera_ctrl_instance->fov;
        scripted_camera_projection_angle = angle;
    }
    configure_scripted_camera_playback((CameraPlayback *)this, angle);
}

void configure_scripted_camera_playback(CameraPlayback *playback, s32 angle) {
    TCameraScripted *camera = (TCameraScripted *)camera_controller_registry[5];
    if (camera != NULL) {
        camera->playback.index = playback->index;
        camera->playback.bank = playback->bank;
        camera->playback.flags = playback->flags;
        camera->playback.frame = playback->frame;
        camera->playback.frame_step = playback->frame_step;
        camera->bank_file = &camera_path_bank_table[get_current_floor_area()].files[camera->playback.bank];
        camera->motion = camera_banks[playback->bank].directory->motions[camera->playback.index];
    }
}

CameraPlayback *get_scripted_camera_playback() {
    TCameraScripted *camera = (TCameraScripted *)camera_controller_registry[5];
    if (camera != NULL) {
        CameraPlayback *playback = &camera->playback;
        if (TCameraCtrl::get_active_controller() != 5) {
            playback->flags |= 1;
        }
        return playback;
    }
    return NULL;
}
