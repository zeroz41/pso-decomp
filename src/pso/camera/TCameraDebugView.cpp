#include "types.h"
#include "pso/camera/TCameraDebugView.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/camera/TCameraCtrl_801A6E60.h"
#include "pso/math/AngleLookup.h"
#include "pso/system/ControllerInputState.h"
#include "pso/system/vector.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801A6D60.h"
#include "pso/unk/text_803D853C.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
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
        debug_printf_at(0xC0014, "PERS = %d", (s32)(0.0054931640625 * projection_angle + 1.0));
        if (TWindowShortListCtrl__check_controller_button(pad, 0x20000) != 0) {
            projection_angle += 0xB6;
        }
        if (TWindowShortListCtrl__check_controller_button(pad, 0x10000) != 0) {
            projection_angle -= 0xB6;
        }
    }
    VecCopy(&focus, &TCameraCtrl::get_target_position());
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

struct O_8006CC7C { u8 pad[0x1c]; Vec pos; };
extern O_8006CC7C *demo_camera_controller_table[];
extern s16 demo_camera_controller_index;

Vec TCameraCtrl::get_target_position() {
    Vec def = default_target_position;
    O_8006CC7C *o = demo_camera_controller_table[demo_camera_controller_index];
    if (o != 0) {
        return o->pos;
    }
    return def;
}
