// The Vol Opt follow camera (mode 12), TCameraController::set_target and
// TCameraFollow::set_target_yaw.
#include "types.h"
#include "pso/camera/TCameraVolOptFollow.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/system/ControllerInput.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/math/MatrixVector.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/ControllerInputState.h"
#include "pso/system/vector.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/base/TObjBase.h"

// Eye offsets from the followed player; update_follow_settings uses the first.
const Vec vol_opt_follow_eye_offsets[2] = {
    {0.0f, 25.43f, 45.42f},
    {0.0f, 30.0f, 40.0f},
};

void TCameraController::set_target(TObjPlayer *object) {
    actor = object;
    if (object != NULL) {
        actor_id = object->get_entity_id();
    }
}

#pragma push
#pragma fp_contract on
void TCameraVolOptFollow::update_target_follow() {
    Vec dir;
    Vec *focus = TBoss3Volopt::get_camera_focus();
    if (focus != NULL) {
        dir.x = actor->position.x - focus->x;
        f32 dz = actor->position.z - focus->z;
        dir.y = 0.0f;
        dir.z = dz;
        f32 distance = vector_length(&dir);
        if (0.0f != distance) {
            normalize_vector(&dir);
        } else {
            return;
        }
        switch (follow_state) {
        case 0:
            target.x = focus->x;
            target.z = focus->z;
            target.y = focus->y;
            if (target.y >= 50.0f) {
                target.y = 60.0f;
            }
            position.x = 45.42f * dir.x + actor->position.x;
            position.z = 45.42f * dir.z + actor->position.z;
            position.y = 15.0f + actor->position.y;
            if (distance < 100.0f) {
                follow_state = 1;
                locked_target_offset.x = target.x - actor->position.x;
                locked_target_offset.y = target.y - actor->position.y;
                locked_target_offset.z = target.z - actor->position.z;
                locked_eye_offset.x = position.x - actor->position.x;
                locked_eye_offset.y = position.y - actor->position.y;
                locked_eye_offset.z = position.z - actor->position.z;
                return;
            }
            break;
        case 1:
            if (distance > 100.0f) {
                follow_state = 0;
            }
            target.x = locked_target_offset.x + actor->position.x;
            target.y = locked_target_offset.y + actor->position.y;
            target.z = locked_target_offset.z + actor->position.z;
            position.x = locked_eye_offset.x + actor->position.x;
            position.y = locked_eye_offset.y + actor->position.y;
            position.z = locked_eye_offset.z + actor->position.z;
            break;
        }
    }
}
#pragma pop

void TCameraVolOptFollow::update_follow_settings() {
    Vec to_target;
    flags = FLAG_CHECK_OBSTRUCTION | FLAG_SMOOTH_POSE | FLAG_SMOOTH_TARGET_HEIGHT;
    eye_rate = 1.65f;
    to_target.x = camera_ctrl_instance->tgt.x - target.x;
    to_target.y = camera_ctrl_instance->tgt.y - target.y;
    to_target.z = camera_ctrl_instance->tgt.z - target.z;
    at_rate = (0.7f * vector_length(&to_target)) / 100.0f;
    if (predict_obstruction() != 0) {
        follow_flags = follow_flags | 1;
    } else {
        follow_flags = follow_flags & ~1;
    }
    target_offset.x = 0.0f;
    target_offset.y = 19.8f;
    target_offset.z = -5.0f;
    VecCopy(&eye_offset, &vol_opt_follow_eye_offsets[0]);
}

TCameraController *TCameraVolOptFollow::create() {
    return new TCameraVolOptFollow();
}

void TCameraVolOptFollow::run_task() {
    flags = FLAG_CHECK_OBSTRUCTION | FLAG_SMOOTH_POSE | FLAG_SMOOTH_TARGET_HEIGHT;
    if (test_previous_buttons_packed(&controller_input_state.controllers[0], 0x10000) != 0) {
        TCameraFollow::run_task();
    } else {
        update_target_follow();
    }
    flags = flags | FLAG_SMOOTH_TARGET_HEIGHT;
}

TCameraVolOptFollow::~TCameraVolOptFollow() {}

TCameraVolOptFollow::TCameraVolOptFollow() {
    flags = FLAG_CHECK_OBSTRUCTION | FLAG_SMOOTH_POSE | FLAG_SMOOTH_TARGET_HEIGHT;
    eye_rate = 0.65f;
    follow_state = 0;
    pad_110 = 0;
}

void TCameraFollow::set_target_yaw(s32 v) { target_yaw = v; }
