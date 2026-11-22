#define PSO_SDK_COMPACT_MATH
#include "types.h"
#include <dolphin/gx/GXTransform.h>
#undef PSO_SDK_COMPACT_MATH
#include "pso/camera/TCameraController.h"
#include "pso/camera/CameraHelpers.h"
#include "pso/camera/TCameraFollow.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/system/NinjaTypes.h"
#include "pso/camera/CameraViewParams.h"
#include "pso/render/GinjaView.h"
#include "pso/map/CsnQuery.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/vector.h"
#include "pso/math/MatrixVector.h"
#include "pso/unk/TLobby_801E2F94.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D8F74.h"


static const Vec camera_forward_axis = {0.0f, 0.0f, -1.0f};
static const Vec actor_forward_axis = {0.0f, 0.0f, -1.0f};

static FollowCameraInitPose follow_camera_init_poses[4][3] = {
    {
        {{28.0f, 100.0f, 176.0f}, {13.0f, 102.0f, 132.0f}, 0x3555, -2.0f, -10000.0f},
        {{-191.0f, 102.0f, 115.0f}, {-165.0f, 94.0f, 97.0f}, 0x3555, -2.0f, -10000.0f},
        {{331.0f, -19.0f, -45.0f}, {322.0f, -15.0f, -62.0f}, 0x3555, -2.0f, -10000.0f},
    },
    {
        {{28.0f, 100.0f, 176.0f}, {13.0f, 102.0f, 132.0f}, 0x3555, -2.0f, -10000.0f},
        {{-191.0f, 102.0f, 115.0f}, {-165.0f, 94.0f, 97.0f}, 0x3555, -2.0f, -10000.0f},
        {{331.0f, -19.0f, -45.0f}, {322.0f, -15.0f, -62.0f}, 0x3555, -2.0f, -10000.0f},
    },
    {
        {{28.0f, 100.0f, 176.0f}, {13.0f, 102.0f, 132.0f}, 0x3555, -2.0f, -10000.0f},
        {{-191.0f, 102.0f, 115.0f}, {-165.0f, 94.0f, 97.0f}, 0x3555, -2.0f, -10000.0f},
        {{331.0f, -19.0f, -45.0f}, {322.0f, -15.0f, -62.0f}, 0x3555, -2.0f, -10000.0f},
    },
    {
        {{28.0f, 100.0f, 176.0f}, {13.0f, 102.0f, 132.0f}, 0x3555, -2.0f, -10000.0f},
        {{-191.0f, 102.0f, 115.0f}, {-165.0f, 94.0f, 97.0f}, 0x3555, -2.0f, -10000.0f},
        {{331.0f, -19.0f, -45.0f}, {322.0f, -15.0f, -62.0f}, 0x3555, -2.0f, -10000.0f},
    },
};

FollowCameraInitPose *follow_camera_init_pose_table[4] = {
    follow_camera_init_poses[0],
    follow_camera_init_poses[1],
    follow_camera_init_poses[2],
    follow_camera_init_poses[3],
};

#pragma push
#pragma fp_contract on
// Probes from the eye towards where the actor is heading; on a hit, keeps the point
// (pulled back 2 units) in obstruction_point.
s32 TCameraController::predict_obstruction() {
    Vec dir;
    Vec probe;
    Vec moved;
    Vec *prev;
    Vec *pos;
    Vec *eye;
    Vec *look;
    CsnHit *hit;
    f32 dist;
    if (this->actor == NULL) {
        return 0;
    }
    prev = this->actor->get_prev_position_ptr();
    pos = this->actor->get_position_ptr();
    moved.x = pos->x - prev->x;
    moved.y = pos->y - prev->y;
    moved.z = pos->z - prev->z;
    dist = vector_length(&moved);
    if (dist < 1.0f) {
        Vec camera_dir = camera_forward_axis;
        Vec actor_dir = actor_forward_axis;
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, camera_ctrl_instance->yaw);
        matrix_mult_vec(0, &camera_dir, &camera_dir);
        pop_matrices(1);
        camera_dir.y = 0.0f;
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, this->actor->rotation_y);
        matrix_mult_vec(0, &actor_dir, &actor_dir);
        pop_matrices(1);
        if (fabs_float(vec3_dot(&camera_dir, &actor_dir)) > 0.25f) {
            dist = 0.0f;
        } else {
            dist *= 13.0f;
        }
    } else {
        dist *= 13.0f;
    }
    if (is_split_screen() != 0) {
        s32 mode = TCameraCtrl::get_camera_mode();
        TCameraCtrl *view = camera_ctrl_instance;
        eye = &view->split_pos[mode];
        look = &view->split_tgt[mode];
        probe.y = view->split_tgt[mode].y;
    } else {
        eye = &camera_ctrl_instance->pos;
        look = &camera_ctrl_instance->tgt;
        probe.y = camera_ctrl_instance->tgt.y;
    }
    dir.x = eye->x - look->x;
    dir.y = eye->y - look->y;
    dir.z = eye->z - look->z;
    if (0.0f != vector_length(&dir)) {
        normalize_vector(&dir);
    }
    probe.x = dist * dir.x + this->actor->position.x;
    probe.z = dist * dir.z + this->actor->position.z;
    if (camera_ctrl_instance == NULL) {
        return 0;
    }
    hit = csnVector(eye, &probe, 0x100);
    if (hit != NULL) {
        VecCopy(&this->obstruction_point, &hit->contact->point);
        this->obstruction_point.x -= 2.0f * dir.x;
        this->obstruction_point.y -= 2.0f * dir.y;
        this->obstruction_point.z -= 2.0f * dir.z;
        return 1;
    }
    return 0;
}
#pragma pop

void on_camera_reset() {}
void on_view_state_reset() {}

void TCameraController::post_update_view() {
    Vec look;
    Vec d;
    Vec *t;
    d.x = camera_ctrl_instance->tgt.x - camera_ctrl_instance->pos.x;
    d.y = camera_ctrl_instance->tgt.y - camera_ctrl_instance->pos.y;
    d.z = camera_ctrl_instance->tgt.z - camera_ctrl_instance->pos.z;
    if (0.0f == vector_length(&d)) {
        normalize_vector(&d);
        camera_ctrl_instance->tgt.x = camera_ctrl_instance->pos.x;
        camera_ctrl_instance->tgt.y = camera_ctrl_instance->pos.y;
        camera_ctrl_instance->tgt.z = 1.0f + camera_ctrl_instance->pos.z;
    } else if (0.0f == d.x && 0.0f == d.z) {
        camera_ctrl_instance->tgt.z += 0.01f;
        d.z = 1.0f;
    }
    direction_to_pitch_yaw(&d, &camera_ctrl_instance->pitch, &camera_ctrl_instance->yaw);
    t = camera_ctrl_instance->get_target();
    look.x = camera_ctrl_instance->tgt.x + t->x;
    look.y = camera_ctrl_instance->tgt.y + t->y;
    look.z = camera_ctrl_instance->tgt.z + t->z;
    set_camera_look_at(&camera_ctrl_instance->pos, &look, &TCameraCtrl::up_vector);
    ninja_camera.px = camera_ctrl_instance->pos.x;
    ninja_camera.py = camera_ctrl_instance->pos.y;
    ninja_camera.pz = camera_ctrl_instance->pos.z;
    if (TCameraCtrl::view_state.flags & 0x200) {
        GXSetScissorBoxOffset((s32)-(TCameraCtrl::view_params.screen.projection.center_x - 320.0f), (s32)-(TCameraCtrl::view_params.screen.projection.center_y - 240.0f));
        set_screen_center(TCameraCtrl::view_params.screen.projection.center_x, TCameraCtrl::view_params.screen.projection.center_y);
        set_viewport_scissor(2, &TCameraCtrl::view_params.scissor);
    }
}

// Copies the controller's pose into the view; with view flag 4 or 8 the view snaps to it.
void apply_camera_controller_pose(TCameraController *controller) {
    s32 no;
    if ((TCameraCtrl::view_state.flags & 4) || (TCameraCtrl::view_state.flags & 8)) {
        camera_ctrl_instance->eye.x = controller->position.x;
        camera_ctrl_instance->eye.y = controller->position.y;
        camera_ctrl_instance->eye.z = controller->position.z;
        camera_ctrl_instance->at.x = controller->target.x;
        camera_ctrl_instance->at.y = controller->target.y;
        camera_ctrl_instance->at.z = controller->target.z;
        camera_ctrl_instance->pos.x = camera_ctrl_instance->eye.x;
        camera_ctrl_instance->pos.y = camera_ctrl_instance->eye.y;
        camera_ctrl_instance->pos.z = camera_ctrl_instance->eye.z;
        camera_ctrl_instance->tgt.x = camera_ctrl_instance->at.x;
        camera_ctrl_instance->tgt.y = camera_ctrl_instance->at.y;
        camera_ctrl_instance->tgt.z = camera_ctrl_instance->at.z;
        no = TCameraCtrl::get_camera_no();
        VecCopy(&camera_ctrl_instance->split_pos[no], &controller->position);
        VecCopy(&camera_ctrl_instance->split_tgt[no], &controller->target);
    } else {
        camera_ctrl_instance->eye.x = controller->position.x;
        camera_ctrl_instance->eye.y = controller->position.y;
        camera_ctrl_instance->eye.z = controller->position.z;
        camera_ctrl_instance->at.x = controller->target.x;
        camera_ctrl_instance->at.y = controller->target.y;
        camera_ctrl_instance->at.z = controller->target.z;
    }
    camera_ctrl_instance->eye_rate = controller->eye_rate;
    camera_ctrl_instance->at_rate = controller->at_rate;
    if (camera_ctrl_instance->fov != controller->fov) {
        TCameraCtrl::view_state.flags |= 0x40;
        camera_ctrl_instance->fov = controller->fov;
    }
}

TCameraController::~TCameraController() {

}

TCameraController::TCameraController() : TObject(0) {
    this->position.x = 0.0f;
    this->position.y = 0.0f;
    this->position.z = 0.0f;
    this->pitch = 0;
    this->yaw = 0;
    this->roll = 0;
    this->target.x = 0.0f;
    this->target.y = 0.0f;
    this->target.z = 1.0f;
    this->obstruction_point.x = 0.0f;
    this->obstruction_point.y = 0.0f;
    this->obstruction_point.z = 0.0f;
    this->pad_28 = 0;
    this->state = 0;
    this->flags = 0;
    this->eye_rate = 0.0f;
    this->at_rate = 0.289f;
    this->fov = 0x36C1;
    this->actor_id = 0xFFFF;
}

void TCameraController::run_task() {}

Vec *TObjPlayer::get_prev_position_ptr() { return &this->prev_position; }
