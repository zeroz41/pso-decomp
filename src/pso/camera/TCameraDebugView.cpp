#include "types.h"
#include "pso/camera/TCameraDebugView.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/quest/TQuestListVM_8007EAF8.h"
#include "pso/system/ControllerInput.h"
#include "pso/math/AngleLookup.h"
#include "pso/system/ControllerInputState.h"
#include "pso/system/vector.h"
#include "pso/unk/text_803D853C.h"

static const Vec default_target_position = {0.0f, 0.0f, 0.0f};

TCameraController *TCameraDebugView::create() {
    return new TCameraDebugView();
}

#pragma push
#pragma fp_contract on
void TCameraDebugView::run_task() {
    Vec focus = {0.0f, 0.0f, 0.0f};
    ControllerInputContext *pad = &controller_input_state.controllers[2];
    s16 stick_x = controller_input_state.controllers[2].stick_x;
    s16 stick_y = controller_input_state.controllers[2].stick_y;
    f32 radius;
    if (test_previous_buttons_packed(pad, 0x100) != 0) {
        debug_printf_at(0xC0014, "PERS = %d", (s32)(0.0054931640625 * fov + 1.0));
        if (test_pressed_buttons_packed(pad, 0x20000) != 0) {
            fov += 0xB6;
        }
        if (test_pressed_buttons_packed(pad, 0x10000) != 0) {
            fov -= 0xB6;
        }
    }
    VecCopy(&focus, &(const Vec &)get_demo_camera_position());
    set_target_pos(&focus);
    if (test_previous_buttons_packed(pad, 0x200) != 0) {
        if (test_previous_buttons_packed(pad, 0x10) != 0) {
            distance -= 2.0f;
        }
        if (test_previous_buttons_packed(pad, 0x20) != 0) {
            distance += 2.0f;
        }
        if (distance < 20.0f) {
            distance = 20.0f;
        }
        if (distance > 400.0f) {
            distance = 400.0f;
        }
    }
    if (test_previous_buttons_packed(pad, 0x400) != 0) {
        yaw += stick_x * 3;
        pitch += stick_y * 3;
    }
    if (pitch > 0x3800) {
        pitch = 0x3800;
    }
    if (pitch < -0x3800) {
        pitch = -0x3800;
    }
    radius = distance * cos_table_lookup(pitch);
    position.x = radius * sin_table_lookup(yaw) + target.x;
    position.y = -(distance * sin_table_lookup(pitch) - target.y);
    position.z = radius * cos_table_lookup(yaw) + target.z;
}
#pragma pop

TCameraDebugView::~TCameraDebugView() {}

TCameraDebugView::TCameraDebugView() {
    distance = 20.0f;
    flags = 0;
}

Vec TCameraDebugView::get_demo_camera_position() {
    Vec def = default_target_position;
    CameraParams *camera = demo_camera_params_table[demo_camera_index];
    if (camera != 0) {
        return camera->position;
    }
    return def;
}
