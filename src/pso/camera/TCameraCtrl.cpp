#define PSO_SDK_COMPACT_MATH
#include <dolphin/gx/GXTransform.h>
#include <dolphin/gx/GXCull.h>
#undef PSO_SDK_COMPACT_MATH
#include "pso/ui/frontend/CharacterSelectionRequest.h"
#include "types.h"
#include "pso/camera/TCameraFixed.h"
#include "pso/camera/TCameraScripted.h"
#include "pso/camera/TCameraDebugOrbit.h"
#include "pso/camera/TCameraDebugView.h"
#include "pso/camera/TCameraOrbit.h"
#include "pso/camera/TCameraWatchPlayer.h"
#include "pso/system/vector.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/camera/TCameraController.h"
#include "pso/camera/CameraViewParams.h"
#include "pso/system/PadRumble.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/network/client_id.h"
#include "pso/map/FloorArea.h"
#include "pso/system/task/TObject.h"
#include "pso/camera/CreationCamera.h"
#include "pso/system/task/TMainTask.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_8007E418.h"
#include "pso/system/ControllerInput.h"
#include "pso/math/AngleLookup.h"
#include "pso/system/ControllerInputState.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/camera/TCameraVolOpt.h"
#include "pso/camera/TCameraFollow.h"
#include "pso/camera/TCameraVolOptFollow.h"
#include "pso/unk/text_803D853C.h"
#include "pso/map/CsnQuery.h"
#include "pso/math/MatrixVector.h"
#include "pso/camera/CameraHelpers.h"
#include "pso/render/Draw2D.h"
#include "pso/render/GinjaView.h"
#include "pso/system/NinjaTypes.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/scene/OfflineGameScene.h"
#include "pso/quest/QuestOpcodeTables.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"

// The Ninja camera the view matrix is built from each frame: position,
// direction, roll, angle and clip planes.
NJS_CAMERA ninja_camera;
Vec camera_right;
Vec camera_pitch_rotated_up_vector;
CameraViewState TCameraCtrl::view_state;
CameraViewParams TCameraCtrl::view_params;
CameraViewParams TCameraCtrl::saved_view_params;
Vec TCameraCtrl::up_vector;
CameraMatrix TCameraCtrl::view_matrix;
CameraMatrix TCameraCtrl::view_matrices[4];

s16 TCameraCtrl::viewport_width = 640;
s16 TCameraCtrl::viewport_height = 480;
const char *camera_ctrl_class_name = "TCameraCtrl";
f32 camera_default_view_value;
f32 camera_default_view_value_b;
TCameraCtrl *camera_ctrl_instance;
s32 camera_view_state_flag;
s8 TCameraCtrl::active_view;
s16 TCameraCtrl::viewport_x;
s16 TCameraCtrl::viewport_y;
s32 TCameraCtrl::pose_snap_flags;
int TCameraCtrl::camera_id;
s16 TCameraCtrl::camera_mode;
s16 TCameraCtrl::view_offset_active;
typedef TCameraController *(*CameraControllerFactory)(void);

TCameraController *camera_controller_registry[13] = {
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
};
// One factory per registry slot; the constructor fills the registry from them.
CameraControllerFactory camera_controller_factories[13] = {
    &TCameraFollow::create, &TCameraFollow::create, &TCameraFollow::create, &TCameraFollow::create,
    &TCameraDebugOrbit::create, &TCameraScripted::create, &TCameraDebugView::create, &TCameraOrbit::create,
    &CreationCamera::create, &TCameraFixed::create, &TCameraWatchPlayer::create,
    &TCameraVolOpt::create, &TCameraVolOptFollow::create,
};


#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

void set_fixed_camera(const Vec *position, const Vec *target) {
    set_fixed_camera_override(position, target);
}

void TCameraCtrl::reset_battle_camera() { reset_camera_to_local_player(); }

int is_float_nonfinite(f32 value) {
    union {
        f32 f;
        u32 bits;
    } word;
    word.f = value;
    return (word.bits & 0x7F800000) == 0x7F800000;
}
int is_quest_active() { return quest_active_flag; }
s32 TMainTask::get_task_flags() { return task_flags; }

u16 TCameraController::get_actor_id() { return actor_id; }
void TCameraCtrl::set_target_coords(int x, int y) { TCameraCtrl::viewport_x = x; TCameraCtrl::viewport_y = y; }
void TCameraCtrl::set_target(int width, int height) { TCameraCtrl::viewport_width = width; TCameraCtrl::viewport_height = height; }
int TCameraCtrl::get_camera_id() { return TCameraCtrl::camera_id; }

int TCameraCtrl::get_view_count() { return camera_split_screen_selector; }

const CharacterSelectionRequest *get_character_select_request_buffer(void) {
    return &chr_select_request_buffer;
}
#pragma push
#pragma opt_common_subs off
TCameraCtrl::TCameraCtrl(TObject *parent) : TObject(parent) {
    s32 i;
    s32 k;
    s32 j;

    m_name = camera_ctrl_class_name;
    view_updated = 0;
    camera_ctrl_instance = this;
    fov = 0x3555;
    focus_actor = NULL;
    obstructed = 0;
    look.x = 0.0f;
    look.y = 0.0f;
    look.z = 0.0f;
    for (i = 0; i < 4; i++) {
        view_yaw[i] = 0;
        view_pos[i].x = 0.0f;
        view_pos[i].y = 0.0f;
        view_pos[i].z = 0.0f;
        split_look[i].x = 0.0f;
        split_look[i].y = 0.0f;
        split_look[i].z = 0.0f;
        split_obstructed[i] = 0;
    }
    pos.x = 0.0f;
    pos.y = 0.0f;
    pos.z = 0.0f;
    eye.x = 0.0f;
    eye.y = 0.0f;
    eye.z = 0.0f;
    tgt.x = 0.0f;
    tgt.y = 0.0f;
    tgt.z = 0.0f;
    at.x = 0.0f;
    at.y = 0.0f;
    at.z = 0.0f;
    pitch = 0;
    yaw = 0;
    roll = 0;
    shake_timer = 0;
    eye_rate = 0.0f;
    at_rate = 0.0f;
    pad_8C = 0;
    shake_offset.x = 0.0f;
    shake_offset.y = 0.0f;
    shake_offset.z = 0.0f;
    params.controller_variant = 0;
    params.pad_04 = 0;
    params.pad_08 = 0;
    params.pad_0C = 0.0f;
    params.eye_rate = 0.0f;
    params.fov = 0;
    params.pad_44 = 0;
    params.pad_18 = 0.0f;
    params.position.x = 0.0f;
    params.position.y = 0.0f;
    params.position.z = 0.0f;
    params.target.x = 0.0f;
    params.target.y = 0.0f;
    params.target.z = 0.0f;
    params.pad_34 = 0.0f;
    params.pad_38 = 0.0f;
    params.pad_3C = 0.0f;
    pad_74 = 0.0f;
    pad_78 = 0.0f;
    pad_7C = 0.0f;
    pad_80 = 0.0f;
    pad_80 = 0.0f;
    pad_80 = 0.0f;
    {
        for (k = 0; k < 13; k++) {
            camera_controller_registry[TCameraCtrl::view_state.controller_count++] = camera_controller_factories[k]();
        }
    }
    TCameraCtrl::view_state.controller = 0;
    for (j = 0; j < 4; j++) {
        split_pos[j].x = 0.0f;
        split_pos[j].y = 0.0f;
        split_pos[j].z = 0.0f;
        split_tgt[j].x = 0.0f;
        split_tgt[j].y = 0.0f;
        split_tgt[j].z = 0.0f;
    }
    ninja_camera.px = 0.0f;
    ninja_camera.py = 0.0f;
    ninja_camera.pz = 0.0f;
    ninja_camera.vx = 0.0f;
    ninja_camera.vy = 0.0f;
    ninja_camera.vz = -1.0f;
}
#pragma pop

void TCameraCtrl::setup_default_view(Vec *offset) {
    Vec eye_pos;
    Vec at_pos;
    Vec d;
    Vec *pat;
    eye_pos.x = ninja_camera.px;
    eye_pos.y = ninja_camera.py;
    eye_pos.z = ninja_camera.pz;
    if (offset != 0) {
        eye_pos.x += offset->x;
        eye_pos.y += offset->y;
        eye_pos.z += offset->z;
    }
    at_pos.x = ninja_camera.vx + eye_pos.x;
    at_pos.y = ninja_camera.vy + eye_pos.y;
    at_pos.z = ninja_camera.vz + eye_pos.z;
    d.x = eye_pos.x - at_pos.x;
    d.y = eye_pos.y - at_pos.y;
    d.z = eye_pos.z - at_pos.z;
    pat = &at_pos;
    if (0.0f == vec_squared_length(&d)) {
        pat->z += 1.0f;
    }
    if (0.0f == d.x && 0.0f == d.z) {
        pat->z += 1.0f;
    }
    set_perspective_projection_from_fov(fov, 1.1333334f, 1.0f, 21000.0f);
    set_camera_look_at(&eye_pos, &at_pos, &TCameraCtrl::up_vector);
}


CameraMatrix *TCameraCtrl::copy_view_params(CameraMatrix *dst, const CameraMatrix *src) {
    *dst = *src;
    return dst;
}

void TCameraCtrl::run_task() {
    Vec dir;
    Vec *shake;
    s32 i;

    view_updated = 1;
    update_target_from_state();
    cycle_spectate_target();
    update_active_controller();
    reset_view_flags();
    if (camera_ctrl_instance != NULL) {
        if (is_float_nonfinite(camera_ctrl_instance->pos.x) == 0 && is_float_nonfinite(camera_ctrl_instance->pos.y) == 0) {
            is_float_nonfinite(camera_ctrl_instance->pos.z);
        }
        if (is_float_nonfinite(camera_ctrl_instance->pos.x) == 0 && is_float_nonfinite(camera_ctrl_instance->pos.y) == 0) {
            is_float_nonfinite(camera_ctrl_instance->pos.z);
        }
        if (is_float_nonfinite(camera_ctrl_instance->tgt.x) == 0 && is_float_nonfinite(camera_ctrl_instance->tgt.y) == 0) {
            is_float_nonfinite(camera_ctrl_instance->tgt.z);
        }
    }
    if (camera_ctrl_instance != NULL) {
        shake = get_target();
        dir.x = (shake->x + camera_ctrl_instance->tgt.x) - camera_ctrl_instance->pos.x;
        dir.y = (shake->y + camera_ctrl_instance->tgt.y) - camera_ctrl_instance->pos.y;
        dir.z = (shake->z + camera_ctrl_instance->tgt.z) - camera_ctrl_instance->pos.z;
        ninja_camera.px = pos.x;
        ninja_camera.py = pos.y;
        ninja_camera.pz = pos.z;
        if (0.0f != vec_squared_length(&dir)) {
            normalize_vector(&dir);
        }
        ninja_camera.vx = dir.x;
        ninja_camera.vy = dir.y;
        ninja_camera.vz = dir.z;
        vector_length(&dir);
    }
    if (is_split_screen() != 0) {
        if (TCameraCtrl::view_state.controller == 5) {
            store_inverse_current_matrix(&ninja_camera, &TCameraCtrl::view_matrices[TCameraCtrl::get_camera_no()]);
            for (i = 1; i < 4; i++) {
                copy_view_params(&TCameraCtrl::view_matrices[i], &TCameraCtrl::view_matrices[0]);
            }
        } else {
            store_inverse_current_matrix(&ninja_camera, &TCameraCtrl::view_matrices[TCameraCtrl::get_camera_no()]);
        }
    } else {
        store_inverse_current_matrix(&ninja_camera, &TCameraCtrl::view_matrix);
    }
    calc_rotated_axes();
}
#pragma push
#pragma opt_common_subs off
void TCameraCtrl::calc_rotated_axes() {
    Vec right = {1.0f, 0.0f, 0.0f};
    Vec up = {0.0f, 1.0f, 0.0f};
    push_matrix_from(identity_matrix);
    rotate_matrix_y(NULL, yaw);
    rotate_vector_by_current_matrix(&right, &camera_right);
    pop_matrix();
    push_matrix_from(identity_matrix);
    rotate_matrix_x(NULL, pitch);
    rotate_vector_by_current_matrix(&up, &camera_pitch_rotated_up_vector);
    pop_matrix();
}
#pragma pop
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void TCameraCtrl::calc_axes_from_angles(saddr unused_angle, saddr pitch, saddr yaw) {
    Vec right = {1.0f, 0.0f, 0.0f};
    Vec up = {0.0f, 1.0f, 0.0f};
    push_matrix_from(identity_matrix);
    rotate_matrix_y(NULL, yaw);
    rotate_vector_by_current_matrix(&right, &camera_right);
    pop_matrix();
    push_matrix_from(identity_matrix);
    rotate_matrix_x(NULL, pitch);
    rotate_vector_by_current_matrix(&up, &camera_pitch_rotated_up_vector);
    pop_matrix();
}
#pragma pop

void TCameraCtrl::render() {
    if ((is_split_screen() == 0) && (TMainTask::get_render_pass() != 1)) {
        if (view_updated == 0) {
            setup_default_view(NULL);
        }
        view_updated = 0;
    }
}

TCameraCtrl::~TCameraCtrl() {
    s32 i;
    camera_ctrl_instance = NULL;
    for (i = 0; i < 13; i++) {
        if (camera_controller_registry[i] != NULL) {
            delete camera_controller_registry[i];
            camera_controller_registry[i] = NULL;
        }
    }
    TCameraCtrl::view_state.controller_count = 0;
}

void TCameraCtrl::update_target_from_state() {
    if ((!(TCameraCtrl::view_state.flags & 4) && !(TCameraCtrl::view_state.flags & 8)) || (TCameraCtrl::view_state.flags & 0x20) || (TCameraCtrl::view_state.flags & 0x80) || (TCameraCtrl::view_state.flags & 0x800)) {
        if (TCameraCtrl::view_state.flags & 2) {
            select_camera_controller(params.controller_variant + 9);
            return;
        }
        if ((TCameraCtrl::view_state.flags & 0x20) || (TCameraCtrl::view_state.flags & 0x80)) {
            select_camera_controller(TCameraCtrl::view_state.previous_controller);
            TObjPlayer *player = get_player_by_client_id(local_client_id);
            if (player != NULL) {
                reset_cameras_to_actor(player, 0);
            }
        }
    }
}

void TCameraCtrl::update_active_controller() {
    s32 flags;
    s32 snap;
    TCameraController *controller;
    s32 camera_no;
    if (TCameraCtrl::view_state.controller != 0) {
        camera_no = 0;
    } else if (is_split_screen() != 0) {
        camera_no = TCameraCtrl::get_camera_no();
    } else {
        camera_no = 0;
    }
    controller = camera_controller_registry[TCameraCtrl::view_state.controller + camera_no];
    if (controller != NULL) {
        if (!(TCameraCtrl::view_state.flags & 0x800)) {
            controller->run_task();
        }
        if (TCameraCtrl::view_state.flags & 2) {
            controller->apply_camera_params(0);
        } else if (TCameraCtrl::view_state.flags & 0x80) {
            controller->apply_camera_params(1);
        }
        apply_camera_controller_pose(controller);
        snap = 0;
        if (is_split_screen() != 0) {
            if (((TCameraCtrl::view_state.flags & 0x20) || (TCameraCtrl::view_state.flags & 0x800)) && !(TCameraCtrl::view_state.flags & (0x1000 << camera_no))) {
                snap = 1;
                TCameraCtrl::view_state.flags &= -0x1001 << camera_no;
            }
        } else if ((TCameraCtrl::view_state.flags & 0x20) || (TCameraCtrl::view_state.flags & 0x800)) {
            snap = 1;
        }
        if (snap != 0) {
            update_position();
        } else {
            if (controller->flags & TCameraController::FLAG_CHECK_OBSTRUCTION) {
                resolve_anchor_obstruction(controller);
            }
            flags = controller->flags;
            if (flags & TCameraController::FLAG_SMOOTH_POSE) {
                update_pose_smoothing();
            } else if (flags & TCameraController::FLAG_SMOOTH_TARGET) {
                update_target_smoothing();
            } else {
                update_position();
            }
            if (controller->flags & TCameraController::FLAG_CHECK_OBSTRUCTION) {
                clamp_to_target_obstruction(controller);
            }
            update_shake();
        }
        set_perspective_projection_from_fov(fov, 1.1333334f, 1.0f, 21000.0f);
        controller->post_update_view();
        if (is_split_screen() == 0) {
            view_yaw[0] = yaw;
        }
    }
}

void select_camera_controller(s32 index) {
    TCameraController *controller;
    TCameraCtrl::view_state.controller = index;
    controller = camera_controller_registry[(u8)index];
    if (controller != NULL) {
        controller->reset_state();
    }
}

void TCameraCtrl::update_shake() {
    f32 amplitude;
    s32 phase;
    if (shake_timer != 0) {
        shake_timer--;
        phase = shake_timer * 40;
        amplitude = shake_amplitude * (f32)shake_timer;
        shake_offset.x = 0.0f;
        shake_offset.y = amplitude * sin_table_lookup((s32)(182.04445f * (f32)phase));
        shake_offset.z = 0.0f;
    }
}
void TCameraCtrl::select_active_controller(s8 index) {
    f32 x;
    f32 y;
    f32 z;
    f32 target_x;
    f32 target_y;
    f32 target_z;
    TCameraController *controller;
    TCameraCtrl::view_state.controller = index;
    controller = camera_controller_registry[(u8)index];
    if (controller != NULL) {
        controller->reset_state();
        if (camera_ctrl_instance != NULL) {
            x = controller->position.x;
            camera_ctrl_instance->eye.x = x;
            camera_ctrl_instance->pos.x = x;
            y = controller->position.y;
            camera_ctrl_instance->eye.y = y;
            camera_ctrl_instance->pos.y = y;
            z = controller->position.z;
            camera_ctrl_instance->eye.z = z;
            camera_ctrl_instance->pos.z = z;
            target_x = controller->target.x;
            camera_ctrl_instance->at.x = target_x;
            camera_ctrl_instance->tgt.x = target_x;
            target_y = controller->target.y;
            camera_ctrl_instance->at.y = target_y;
            camera_ctrl_instance->tgt.y = target_y;
            target_z = controller->target.z;
            camera_ctrl_instance->at.z = target_z;
            camera_ctrl_instance->tgt.z = target_z;
        }
    }
}

u16 TCameraCtrl::get_active_controller() {
    return TCameraCtrl::view_state.controller;
}

void reset_cameras_to_actor(TObjPlayer *actor, s32 view_unused) {
    s32 view = 0;
    u16 entity_id;
    s32 count = 0;
    TCameraController *controller;
    s32 id;
    s32 i;
    if (actor == 0) {
        return;
    }
    entity_id = (u16)((TObjBase *)actor)->get_entity_id();
    id = entity_id;
    if (is_split_screen() == 0) {
        view = 0;
    } else {
        const CharacterSelectionRequest *request = get_character_select_request_buffer();
        for (i = 0; i < 4; i++) {
            s32 p = request->player_ids[i];
            if (p == id) {
                view = count;
            }
            if (p >= 0) {
                count++;
            }
        }
    }
    controller = camera_controller_registry[TCameraCtrl::view_state.controller + view];
    if (controller != NULL) {
        if (is_split_screen() == 0) {
            camera_ctrl_instance->focus_actor = actor;
        }
        controller->set_target(actor);
        controller->reset_to_actor(actor);
        if (is_split_screen() != 0) {
            TCameraCtrl::view_state.flags |= 0x800;
            if (is_boss_area() == 0) {
                TCameraCtrl::view_state.flags |= 0x1000;
                TCameraCtrl::view_state.flags |= 0x2000;
                TCameraCtrl::view_state.flags |= 0x4000;
                TCameraCtrl::view_state.flags |= 0x8000;
                TCameraCtrl::view_state.flags &= -0x1001 << view;
            }
        } else {
            TCameraCtrl::view_state.flags |= 0x800;
        }
    }
    controller = camera_controller_registry[view];
    if (controller != NULL) {
        controller->set_target(actor);
        controller->reset_to_actor(actor);
    }
    if (camera_ctrl_instance != NULL) {
        VecCopy(&camera_ctrl_instance->split_pos[view], &controller->position);
        VecCopy(&camera_ctrl_instance->split_tgt[view], &controller->target);
    }
}

void TCameraCtrl::reset_view_state() {
    CameraViewState *state = &TCameraCtrl::view_state;
    CameraViewParams *view = &TCameraCtrl::view_params;
    Vec *up;

    TCameraCtrl::pose_snap_flags = 0;
    TCameraCtrl::view_state.controller = 0;
    state->spectate_client = 0;
    state->controller_count = 0;
    state->flags = 0;
    view->screen.projection.distance = 0.0f;
    view->screen.viewport_width = 0.0f;
    view->screen.viewport_height = 0.0f;
    view->screen.projection.center_x = 0.0f;
    view->screen.projection.center_y = 0.0f;
    view->scissor.x0 = 0.0f;
    view->scissor.y0 = 0.0f;
    view->scissor.x1 = 0.0f;
    view->scissor.y1 = 0.0f;
    view->pad_40[0] = 1.0f;
    view->pad_40[1] = 0.85f;
    on_view_state_reset();
    TCameraCtrl::up_vector.x = 0.0f;
    up = &TCameraCtrl::up_vector;
    up->y = 1.0f;
    up->z = 0.0f;
    camera_view_state_flag = 0;
    TCameraCtrl::active_view = -1;
    TCameraCtrl::view_offset_active = 0;
}

void TCameraCtrl::reset() {
    TCameraCtrl::view_offset_active = 0;
    on_camera_reset();
    TCameraCtrl::view_state.controller = 0;
    TCameraCtrl::view_state.spectate_client = 0;
    TCameraCtrl::view_state.controller_count = 0;
    TCameraCtrl::view_state.flags = 0;
}
void TCameraCtrl::cycle_spectate_target() {
    ControllerInputContext *pad;
    TObjPlayer *candidate;
    TObjPlayer *local;
    s8 tries;
    u16 slot;
    s32 i;
    if (is_split_screen() != 0 || is_quest_active() != 0) {
        return;
    }
    pad = &controller_input_state.controllers[1];
    if (test_previous_buttons_packed(pad, 0x20000) == 0 ||
        test_pressed_buttons_packed(pad, 0x10) == 0 ||
        test_previous_buttons_packed(pad, 0x10000) == 0 ||
        (local = get_player_by_client_id(local_client_id)) == 0 ||
        (tries = 0, TCameraCtrl::view_state.controller != 0) ||
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
    slot = TCameraCtrl::view_state.spectate_client;
    while (tries <= 3) {
        slot++;
        tries++;
        if (slot >= 4) {
            slot = 0;
        }
        candidate = get_player_by_client_id(slot);
        if (candidate != 0) {
            if (candidate->get_floor() == local->get_floor() && candidate->test_actor_flags(0x02000000) == 0) {
                TCameraCtrl::view_state.spectate_client = slot;
                reset_cameras_to_actor(candidate, 0);
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

void TCameraCtrl::set_shake_preset(s32 preset) {
    TCameraCtrl *camera;

    if (camera_ctrl_instance != NULL) {
        switch (preset) {
        case 0:
            camera_ctrl_instance->shake_timer = 0x14;
            camera = camera_ctrl_instance;
            camera->shake_amplitude = 0.0175f;
            start_pad_rumble_all(0x60, 0x14);
            return;
        case 1:
            camera_ctrl_instance->shake_timer = 0x1E;
            camera = camera_ctrl_instance;
            camera->shake_amplitude = 0.175f;
            start_pad_rumble_all(0xA0, 0x1E);
            return;
        case 2:
            camera_ctrl_instance->shake_timer = 0x1E;
            camera = camera_ctrl_instance;
            camera->shake_amplitude = 0.05f;
            start_pad_rumble_all(0xE0, 0x1E);
            break;
        }
    }
}

void start_camera_shake(s32 frames, f32 amplitude) {
    TCameraCtrl *camera;
    if (camera_ctrl_instance != NULL) {
        camera_ctrl_instance->shake_amplitude = amplitude;
        camera = camera_ctrl_instance;
        camera->shake_timer = frames;
        start_pad_rumble_all(0x60, frames);
    }
}
CameraParams *TCameraCtrl::get_params() { return &params; }

void TCameraCtrl::reset_view_flags() {
    CameraViewState *state = &TCameraCtrl::view_state;
    f32 zero;

    state->flags &= ~0x20;
    state->flags &= ~0x80;
    state->flags &= ~0x800;
    if (state->flags & 2) {
        state->flags &= ~2;
        state->flags |= 0x100;
    } else if (state->flags & 0x100) {
        state->flags |= 0x80;
        state->flags &= ~0x100;
    }
    if (state->flags & 0x40) {
        state->flags &= ~0x40;
    }
    if (state->flags & 0x100) {
        return;
    }
    if (state->flags & 0x80) {
        return;
    }
    if (camera_ctrl_instance == NULL) {
        return;
    }
    zero = 0.0f;
    camera_ctrl_instance->params.controller_variant = 0;
    camera_ctrl_instance->params.pad_04 = 0;
    camera_ctrl_instance->params.pad_08 = 0;
    camera_ctrl_instance->params.pad_0C = zero;
    camera_ctrl_instance->params.eye_rate = zero;
    camera_ctrl_instance->params.fov = 0;
    camera_ctrl_instance->params.pad_44 = 0;
    camera_ctrl_instance->params.pad_18 = zero;
    camera_ctrl_instance->params.position.x = zero;
    camera_ctrl_instance->params.position.y = zero;
    camera_ctrl_instance->params.position.z = zero;
    camera_ctrl_instance->params.target.x = zero;
    camera_ctrl_instance->params.target.y = zero;
    camera_ctrl_instance->params.target.z = zero;
    camera_ctrl_instance->params.pad_34 = zero;
    camera_ctrl_instance->params.pad_38 = zero;
    camera_ctrl_instance->params.pad_3C = zero;
}

s32 activate_camera_mode(s32 index) {
    TCameraController *controller;
    if (TCameraCtrl::view_state.flags & 4) {
        return 0;
    }
    TCameraCtrl::view_state.flags |= 4;
    if (index == TCameraCtrl::view_state.controller) {
        TCameraCtrl::view_state.controller = index;
    } else {
        if (TCameraCtrl::view_state.controller != 5 && TCameraCtrl::view_state.controller != 9) {
            TCameraCtrl::view_state.previous_controller = TCameraCtrl::view_state.controller;
        }
        TCameraCtrl::view_state.controller = index;
    }
    controller = camera_controller_registry[TCameraCtrl::view_state.controller];
    if (controller != NULL) {
        controller->reset_state();
    }
    return 1;
}

s32 restore_player_cameras(void) {
    s32 client;
    TObjPlayer *player;
    if (TCameraCtrl::view_state.flags & 4) {
        TCameraCtrl::view_state.flags &= ~4;
        if (TCameraCtrl::get_active_controller() == 5 && camera_controller_registry[5] != NULL && scripted_camera_saved_fov != 0) {
            camera_controller_registry[5]->fov = scripted_camera_saved_fov;
        }
        TCameraCtrl::view_state.flags |= 0x20;
    }
    if (is_split_screen() != 0) {
        for (client = 0; client < 4; client++) {
            player = get_player_by_client_id(client);
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
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
s32 TCameraCtrl::release_photon_blast_camera() {
    s32 flags;
    if (TCameraCtrl::view_state.flags & 8) {
        flags = TCameraCtrl::view_state.flags & ~8;
        TCameraCtrl::view_state.flags = flags;
        TCameraCtrl::view_state.flags = flags | 0x20;
    }
    return 0;
}
#pragma pop
void set_active_camera_pose_from_params(CameraParams *params) {
    TCameraController *controller;
    if ((TCameraCtrl::view_state.flags & 8) || (TCameraCtrl::view_state.flags & 4)) {
        controller = camera_controller_registry[TCameraCtrl::view_state.controller];
        if (controller != NULL) {
            controller->position.x = params->position.x;
            controller->position.y = params->position.y;
            controller->position.z = params->position.z;
            controller->target.x = params->target.x;
            controller->target.y = params->target.y;
            controller->target.z = params->target.z;
            controller->fov = params->fov;
        }
    }
}
void set_active_camera_pose(Vec *position, Vec *target) {
    TCameraController *controller;
    if ((TCameraCtrl::view_state.flags & 8) || (TCameraCtrl::view_state.flags & 4)) {
        controller = camera_controller_registry[TCameraCtrl::view_state.controller];
        if (controller != NULL) {
            controller->position.x = position->x;
            controller->position.y = position->y;
            controller->position.z = position->z;
            controller->target.x = target->x;
            controller->target.y = target->y;
            controller->target.z = target->z;
        }
    }
}
void TCameraCtrl::update_pose_smoothing() {
    s32 view;
    if (TCameraCtrl::pose_snap_flags & 1) {
        update_position();
        TCameraCtrl::clear_pose_snap_flags();
        return;
    }
    if (is_split_screen() != 0) {
        view = TCameraCtrl::get_camera_no();
        approach_camera_vector(&split_pos[view], &eye, eye_rate);
        VecCopy(&pos, &split_pos[view]);
        approach_camera_vector(&split_tgt[view], &at, at_rate);
        VecCopy(&tgt, &split_tgt[view]);
        return;
    }
    approach_camera_vector(&pos, &eye, eye_rate);
    approach_camera_vector(&tgt, &at, at_rate);
}

void TCameraCtrl::update_position() {
    s32 view;

    pos.x = eye.x;
    pos.y = eye.y;
    pos.z = eye.z;
    tgt.x = at.x;
    tgt.y = at.y;
    tgt.z = at.z;
    look.x = pos.x;
    look.y = pos.y;
    look.z = pos.z;
    if (is_split_screen() != 0) {
        view = TCameraCtrl::get_camera_no();
        split_look[view].x = pos.x;
        split_look[view].y = pos.y;
        split_look[view].z = pos.z;
    }
}

void TCameraCtrl::update_target_smoothing() {
    s32 view;
    TCameraController *controller;
    pos.x = eye.x;
    pos.y = eye.y;
    pos.z = eye.z;
    look.x = pos.x;
    look.y = pos.y;
    look.z = pos.z;
    if (is_split_screen() != 0) {
        view = TCameraCtrl::get_camera_no();
        split_look[view].x = pos.x;
        split_look[view].y = pos.y;
        split_look[view].z = pos.z;
    }
    controller = camera_controller_registry[TCameraCtrl::view_state.controller];
    if (controller != NULL && !(controller->flags & TCameraController::FLAG_SMOOTH_TARGET_HEIGHT)) {
        tgt.y = at.y;
    }
    approach_camera_vector(&tgt, &at, at_rate);
}

void TCameraCtrl::clamp_to_target_obstruction(TCameraController *controller) {
    s32 n;
    CsnHit *hit;
    s32 *hit_flag;
    n = TCameraCtrl::get_camera_no();
    if (is_split_screen() != 0) {
        hit_flag = &split_obstructed[n];
    } else {
        hit_flag = &obstructed;
    }
    if (*hit_flag == 0) {
        return;
    }
    if (is_split_screen() != 0) {
        hit = csnVector(&split_tgt[n], &split_pos[n], 0x901);
    } else {
        hit = csnVector(&tgt, &pos, 0x901);
    }
    if (hit == NULL) {
        return;
    }
    if (is_split_screen() != 0) {
        split_pos[n].x = hit->contact->point.x;
        split_pos[n].y = hit->contact->point.y;
        split_pos[n].z = hit->contact->point.z;
        VecCopy(&pos, &split_pos[n]);
    } else {
        pos.x = hit->contact->point.x;
        pos.y = hit->contact->point.y;
        pos.z = hit->contact->point.z;
    }
    if (is_split_screen() != 0) {
        split_look[n].x = split_pos[n].x + hit->contact->normal.x;
        split_look[n].y = split_pos[n].y + hit->contact->normal.y;
        split_look[n].z = split_pos[n].z + hit->contact->normal.z;
    } else {
        look.x = pos.x + hit->contact->normal.x;
        look.y = pos.y + hit->contact->normal.y;
        look.z = pos.z + hit->contact->normal.z;
    }
}

void TCameraCtrl::resolve_anchor_obstruction(TCameraController *controller) {
    Vec d;
    s32 n;
    s32 *hit_flag;
    CsnHit *hit;
    if (is_split_screen() != 0) {
        n = TCameraCtrl::get_camera_no();
        hit_flag = &split_obstructed[n];
        hit = csnVector(&split_look[n], &eye, 0x901);
    } else {
        hit = csnVector(&look, &eye, 0x901);
        hit_flag = &obstructed;
    }
    if (hit != NULL) {
        if (is_split_screen() != 0) {
            n = TCameraCtrl::get_camera_no();
            d.x = eye.x - split_look[n].x;
            d.y = eye.y - split_look[n].y;
            d.z = eye.z - split_look[n].z;
        } else {
            d.x = eye.x - look.x;
            d.y = eye.y - look.y;
            d.z = eye.z - look.z;
        }
        if (0.0f != vector_length(&d)) {
            normalize_vector(&d);
        }
        if (is_split_screen() != 0) {
            n = TCameraCtrl::get_camera_no();
            split_look[n].x = hit->contact->point.x - d.x;
            split_look[n].y = hit->contact->point.y - d.y;
            split_look[n].z = hit->contact->point.z - d.z;
        } else {
            look.x = hit->contact->point.x - d.x;
            look.y = hit->contact->point.y - d.y;
            look.z = hit->contact->point.z - d.z;
        }
        *hit_flag = 1;
    } else {
        if (is_split_screen() != 0) {
            n = TCameraCtrl::get_camera_no();
            VecCopy(&split_look[n], &split_pos[n]);
        } else {
            VecCopy(&look, &pos);
        }
        *hit_flag = 0;
    }
}

Vec *TCameraCtrl::get_target() { return &shake_offset; }
#pragma push
#pragma opt_common_subs off
void CameraViewParams::apply() {
    TCameraCtrl::view_state.flags = TCameraCtrl::view_state.flags | 0x200;
    TCameraCtrl::view_params.screen.viewport_width = screen.viewport_width;
    TCameraCtrl::view_params.screen.viewport_height = screen.viewport_height;
    TCameraCtrl::view_params.screen.projection.center_x = screen.projection.center_x;
    TCameraCtrl::view_params.screen.projection.center_y = screen.projection.center_y;
    TCameraCtrl::view_params.screen.projection.distance = scene_projection_state.screen_scale;
    TCameraCtrl::view_params.screen.projection.width = scene_projection_state.aspect;
    TCameraCtrl::view_params.screen.projection.height = 1.0f;
    TCameraCtrl::view_params.screen.projection.aspect = TCameraCtrl::view_params.screen.projection.height / scene_projection_state.aspect;
    TCameraCtrl::view_params.screen.projection.scale_x = scene_projection_state.aspect * scene_projection_state.screen_scale;
    TCameraCtrl::view_params.screen.projection.scale_y = -(TCameraCtrl::view_params.screen.projection.height * scene_projection_state.screen_scale);
    TCameraCtrl::view_params.scissor.x0 = scissor.x0;
    TCameraCtrl::view_params.scissor.y0 = scissor.y0;
    TCameraCtrl::view_params.scissor.x1 = scissor.x1;
    TCameraCtrl::view_params.scissor.y1 = scissor.y1;
    TCameraCtrl::view_params.pad_40[0] = pad_40[0];
    TCameraCtrl::view_params.pad_40[1] = pad_40[1];
}
#pragma pop

void CameraViewParams::apply_if_overridden() {
    if (TCameraCtrl::view_state.flags & 0x400) {
        apply();
    }
}

s32 CameraViewParams::begin_override() {
    if (TCameraCtrl::view_state.flags & 0x400) {
        return 0;
    }
    TCameraCtrl::view_state.flags |= 0x400;
    apply();
    return 1;
}
#pragma push
#pragma opt_common_subs off
void TCameraCtrl::reset_viewport_scissor() {
    // Scissor rectangle in 32-pixel tiles: the full 640x480 screen.
    TileRect rect = {0.0f, 0.0f, 20.0f, 15.0f};
    if (TCameraCtrl::view_state.flags & 0x200) {
        TCameraCtrl::view_state.flags = TCameraCtrl::view_state.flags & ~0x200;
    }
    set_viewport_scissor(0, &rect);
}
#pragma pop
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void end_view_override() {
    CameraViewParams view;
    if (TCameraCtrl::view_state.flags & 0x400) {
        TCameraCtrl::view_state.flags = TCameraCtrl::view_state.flags & ~0x400;
    }
    view.screen.projection.center_x = 320.0f;
    view.screen.projection.center_y = 240.0f;
    view.screen.viewport_width = 640.0f;
    view.screen.viewport_height = 480.0f;
    view.scissor.x0 = 0.0f;
    view.scissor.y0 = 0.0f;
    view.scissor.x1 = 20.0f;
    view.scissor.y1 = 15.0f;
    view.pad_40[0] = 1.0f;
    view.pad_40[1] = 0.85f;
    view.apply();
}
#pragma pop

void TCameraCtrl::init_default_view() {
    CameraViewParams view;
    TCameraCtrl::camera_mode = 0;
    TCameraCtrl::set_target_coords(0, 0);
    TCameraCtrl::set_target(0x280, 0x1E0);
    view.screen.projection.center_x = 320.0f;
    view.screen.projection.center_y = 240.0f;
    view.screen.viewport_width = 640.0f;
    view.screen.viewport_height = 480.0f;
    view.screen.projection.distance = 250.0f;
    view.scissor.x0 = 0.0f;
    view.scissor.y0 = 0.0f;
    view.scissor.x1 = 20.0f;
    view.scissor.y1 = 15.0f;
    view.pad_40[0] = 1.0f;
    view.pad_40[1] = 0.85f;
    view.apply();
    update_projection_params(&TCameraCtrl::view_params.screen.projection);
    camera_default_view_value = 1.0f;
    camera_default_view_value_b = 0.85f;
}

void TCameraCtrl::reset_default_view() {
    CameraViewParams view;
    TCameraCtrl::camera_mode = 0;
    TCameraCtrl::set_target_coords(0, 0);
    TCameraCtrl::set_target(0x280, 0x1E0);
    TCameraCtrl::set_fullscreen_viewport();
    TCameraCtrl::reset_viewport_scissor();
    init_ninja_camera(&ninja_camera);
    camera_renderer_setup_nop(&ninja_camera, 0x3555);
    update_camera_state(0.0f, 0.0f, 0.0f);
    look_at_position(0.0f, 0.0f, -1.0f);
    view.screen.projection.center_x = 320.0f;
    view.screen.projection.center_y = 240.0f;
    view.screen.viewport_width = 640.0f;
    view.screen.viewport_height = 480.0f;
    view.screen.projection.distance = 250.0f;
    view.scissor.x0 = 0.0f;
    view.scissor.y0 = 0.0f;
    view.scissor.x1 = 20.0f;
    view.scissor.y1 = 15.0f;
    camera_default_view_value = 1.0f;
    camera_default_view_value_b = 0.85f;
    update_projection_params(&view.screen.projection);
}
s32 TCameraCtrl::is_view_override_active() {
    return ((u32)TCameraCtrl::view_state.flags >> 10) & 1;
}

void TCameraCtrl::create() {
    new TCameraCtrl(tl_camera);
}
const f32 (*TCameraCtrl::get_view_matrix())[4] {
    if (is_split_screen() != 0) {
        if (main_task.get_task_flags() & 1) {
            return TCameraCtrl::view_matrices[TCameraCtrl::get_view_count() - 1].m;
        }
        return TCameraCtrl::view_matrices[TCameraCtrl::get_camera_no()].m;
    }
    return TCameraCtrl::view_matrix.m;
}

void TCameraCtrl::apply_split_screen_view_matrix() {
    if (is_split_screen() != 0) {
        if (main_task.get_task_flags() & 1) {
            premultiply_matrix(NULL, TCameraCtrl::view_matrices[TCameraCtrl::get_view_count() - 1].m);
            return;
        }
        premultiply_matrix(NULL, TCameraCtrl::view_matrices[TCameraCtrl::get_camera_no()].m);
        return;
    }
    premultiply_matrix(NULL, TCameraCtrl::view_matrix.m);
}
void TCameraCtrl::transform_to_view(const Vec *src, Vec *dst) {
    push_matrix();
    if (is_split_screen() != 0) {
        premultiply_matrix(NULL, TCameraCtrl::view_matrices[TCameraCtrl::get_camera_no()].m);
    } else {
        premultiply_matrix(NULL, TCameraCtrl::view_matrix.m);
    }
    matrix_mult_vec(NULL, src, dst);
    pop_matrix();
}

u16 TCameraCtrl::get_camera_target_id(s32 view) {
    u16 id;
    s32 index;
    TObjPlayer *actor;
    TCameraController *controller;
    if (is_split_screen() != 0) {
        id = 0xFFFF;
        if (view < 0) {
            index = view;
        } else {
            index = TCameraCtrl::get_camera_mode();
        }
        if (index >= 4) {
            return 0xFFFF;
        }
        controller = camera_controller_registry[index];
        if (controller != NULL) {
            id = controller->get_actor_id();
        }
        return id;
    }
    if (camera_ctrl_instance != NULL) {
        actor = camera_ctrl_instance->focus_actor;
        if (actor != NULL) {
            return ((TObjBase *)actor)->get_entity_id();
        }
    }
    return 0xFFFF;
}

void TCameraCtrl::restore_full_screen_view() {
    if (is_split_screen() == 0) {
        TCameraCtrl::saved_view_params.copy_view_state(&TCameraCtrl::view_params);
        set_screen_center(320.0f, 240.0f);
        GXSetScissorBoxOffset(0, 0);
        GXSetScissor(0, 0, 0x280, 0x1E0);
        TCameraCtrl::view_offset_active = 0;
    }
}

void CameraViewParams::copy_view_state(const CameraViewParams *src) {
    *this = *src;
}

void TCameraCtrl::restore_saved_view() {
    f32 offset_x;
    f32 offset_y;
    if (is_split_screen() == 0) {
        TCameraCtrl::view_params.copy_view_state(&TCameraCtrl::saved_view_params);
        offset_x = -(TCameraCtrl::view_params.screen.projection.center_x - 320.0f);
        offset_y = -(TCameraCtrl::view_params.screen.projection.center_y - 240.0f);
        if (0.0f == offset_x && 0.0f == offset_y) {
            TCameraCtrl::view_offset_active = 0;
        } else {
            TCameraCtrl::view_offset_active = 1;
        }
        GXSetScissorBoxOffset((s32)offset_x, (s32)offset_y);
        set_screen_center(TCameraCtrl::view_params.screen.projection.center_x, TCameraCtrl::view_params.screen.projection.center_y);
        if (camera_ctrl_instance != NULL) {
            set_perspective_projection_from_fov(camera_ctrl_instance->fov, 1.1333334f, 1.0f, 21000.0f);
        }
    }
}

// The full-screen defaults that init_default_view, reset_default_view and
// end_view_override store field by field. Nothing calls it, so the game keeps
// only its constants.
void CameraViewParams::set_fullscreen_defaults() {
    screen.projection.center_x = 320.0f;
    screen.projection.center_y = 240.0f;
    screen.projection.distance = 250.0f;
    screen.viewport_width = 640.0f;
    screen.viewport_height = 480.0f;
    scissor.x0 = 0.0f;
    scissor.y0 = 0.0f;
    scissor.x1 = 20.0f;
    scissor.y1 = 15.0f;
    pad_40[0] = 1.0f;
    pad_40[1] = 0.85f;
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
void TCameraCtrl::set_split_viewport(s32 views, s32 view) {
    switch (views) {
    case 1:
        TCameraCtrl::set_fullscreen_viewport();
        break;
    case 2:
        TCameraCtrl::set_target_coords(0, 0);
        TCameraCtrl::set_target(0x280, 0xF0);
        GXSetViewport(0.0f, 0.0f, 640.0f, 480.0f, 0.0f, 1.0f);
        if (view == 0) {
            GXSetScissor(0, 0x6A, 0x280, 0xF0);
            GXSetScissorBoxOffset(0, 0x6A);
        } else {
            GXSetScissor(0, 0x74, 0x280, 0xF0);
            GXSetScissorBoxOffset(0, -0x7C);
        }
        break;
    case 3:
        if (view != 2) {
            TCameraCtrl::set_target_coords(320.0f * (f32)(view % 2), 240.0f * (f32)(view / 2));
            TCameraCtrl::set_target(0x140, 0xF0);
        } else {
            TCameraCtrl::set_target_coords(0xA0, 0xF0);
            TCameraCtrl::set_target(0x140, 0xF0);
        }
        GXSetViewport(TCameraCtrl::viewport_x, TCameraCtrl::viewport_y, TCameraCtrl::viewport_width, TCameraCtrl::viewport_height, 0.0f, 1.0f);
        GXSetScissor(TCameraCtrl::viewport_x, TCameraCtrl::viewport_y, TCameraCtrl::viewport_width, TCameraCtrl::viewport_height);
        break;
    case 4:
        TCameraCtrl::set_target_coords(320.0f * (f32)(view % 2), 240.0f * (f32)(view / 2));
        TCameraCtrl::set_target(0x140, 0xF0);
        GXSetViewport(TCameraCtrl::viewport_x, TCameraCtrl::viewport_y, TCameraCtrl::viewport_width, TCameraCtrl::viewport_height, 0.0f, 1.0f);
        GXSetScissor(TCameraCtrl::viewport_x, TCameraCtrl::viewport_y, TCameraCtrl::viewport_width, TCameraCtrl::viewport_height);
        break;
    default:
        TCameraCtrl::set_fullscreen_viewport();
        break;
    }
}

void TCameraCtrl::set_fullscreen_viewport() {
    TCameraCtrl::set_target_coords(0, 0);
    TCameraCtrl::set_target(0x280, 0x1E0);
    GXSetViewport(TCameraCtrl::viewport_x, TCameraCtrl::viewport_y, TCameraCtrl::viewport_width, TCameraCtrl::viewport_height, 0.0f, 1.0f);
    GXSetScissor(TCameraCtrl::viewport_x, TCameraCtrl::viewport_y, TCameraCtrl::viewport_width, TCameraCtrl::viewport_height);
    GXSetScissorBoxOffset(0, 0);
}

f32 TCameraCtrl::get_split_offset(s32 view) {
    if ((is_split_screen() != 0) && (TCameraCtrl::get_camera_id() == 2)) {
        if (view == 0) {
            return 106.0f;
        }
        return 116.0f;
    }
    return 0.0f;
}

f32 TCameraCtrl::get_split_offset_x(s32 view) {
    return 0.0f;
}

s32 TCameraCtrl::is_view_offset() {
    return TCameraCtrl::view_offset_active ? 1 : 0;
}

void TCameraCtrl::clear_pose_snap_flags() { TCameraCtrl::pose_snap_flags = 0; }

u16 TCameraCtrl::get_nth_view_player_id(s32 n) {
    s32 count = 0;
    u16 result = 0;
    const CharacterSelectionRequest *request;
    s32 i;
    s32 v;
    if (is_split_screen() == 0) {
        return local_client_id;
    }
    request = get_character_select_request_buffer();
    for (i = 0; i < 4; i++) {
        v = request->player_ids[i];
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
    const CharacterSelectionRequest *request;
    s32 i;
    if (is_split_screen() == 0) {
        return 0;
    }
    request = get_character_select_request_buffer();
    for (i = 0; i < 4; i++) {
        if (request->player_ids[i] == id) {
            result = n;
        }
        if (request->player_ids[i] >= 0) {
            n++;
        }
    }
    return result;
}

void TCameraCtrl::sync_split_view_slots(s32 view, s32 all_views) {
    s32 i;
    s32 id;
    if (camera_ctrl_instance != NULL) {
        id = (u16)TCameraCtrl::get_nth_view_player_id(view);
        if (id != 0xFFFF) {
            camera_ctrl_instance->view_yaw[id] = camera_ctrl_instance->yaw;
            VecCopy(&camera_ctrl_instance->view_pos[id], &camera_ctrl_instance->pos);
        }
    }
    if (all_views != 0) {
        for (i = 0; i < 4; i++) {
            camera_ctrl_instance->view_yaw[i] = camera_ctrl_instance->yaw;
            VecCopy(&camera_ctrl_instance->view_pos[i], &camera_ctrl_instance->pos);
        }
    }
}

void TCameraCtrl::copy_vec_to_default(const Vec *up) {
    VecCopy(&TCameraCtrl::up_vector, up);
}
void TCameraCtrl::reset_up_vector() {
    TCameraCtrl::up_vector.x = 0.0f;
    TCameraCtrl::up_vector.y = 1.0f;
    TCameraCtrl::up_vector.z = 0.0f;
}
