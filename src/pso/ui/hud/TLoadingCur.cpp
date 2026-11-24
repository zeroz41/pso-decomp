#include "pso/system/SoundEffect.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/ui/hud/TLoadingCur.h"
#include <stddef.h>
#include "pso/ui/hud/TNowLoading.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/ControllerInput.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/system/NinjaTypes.h"

#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/math/MatrixVector.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803DCDFC.h"

#pragma push
#pragma readonly_strings on
const char *TLoadingCur::class_name = "TLoadingCur";
#pragma pop
extern const ParticleAngles lbl_804349FC = {0, 0, 0};

void TLoadingCur::update_camera_facing_offset() {
    ParticleAngles angles;
    if (particle != NULL) {
        VecCopy(&pos, &offset);
        angles.x = lbl_804349FC.x;
        angles.y = lbl_804349FC.y;
        angles.z = lbl_804349FC.z;
        facing.x = -ninja_camera.vx;
        facing.y = -ninja_camera.vy;
        facing.z = -ninja_camera.vz;
        direction_to_rotation_xy((u8 *)&facing, &angles.x, &angles.y);
        push_matrix_from(identity_matrix);
        rotate_matrix_y(NULL, angles.y);
        rotate_matrix_x(NULL, angles.x);
        rotate_vector_by_matrix(0, &offset, &pos);
        pop_matrices(1);
        vec3_add_to(&pos, &anchor);
        particle->set_position(&pos);
    }
}

#pragma push
#pragma fp_contract on
extern "C" Vec calc_loading_cursor_pos(TLoadingCur *cursor) {
    if (camera_ctrl_instance != NULL) {
        cursor->anchor.x = 1e+02f * ninja_camera.vx + ninja_camera.px;
        cursor->anchor.y = 1e+02f * ninja_camera.vy + ninja_camera.py;
        cursor->anchor.z = 1e+02f * ninja_camera.vz + ninja_camera.pz;
    }
    return cursor->anchor;
}
#pragma pop

s32 TLoadingCur::calc_clamp_offset(const f32 *screen, NJS_POINT2 *push) {
    f32 x;
    f32 y;
    x = screen[0];
    if (x < 3e+01f) {
        push->x = 3e+01f - x;
    } else if (x > 6.1e+02f) {
        push->x = 6.1e+02f - x;
    } else {
        push->x = 0.0f;
    }
    y = screen[1];
    if (y < 5e+01f) {
        push->y = 5e+01f - y;
    } else if (y > 4.3e+02f) {
        push->y = 4.3e+02f - y;
    } else {
        push->y = 0.0f;
    }
    return (u32)__cntlzw((u32)(push->x * push->x + push->y * push->y <= 0.0f)) >> 5;
}

void TLoadingCur::sub_8001CCD4() {
    f32 screen[2];
    NJS_POINT2 push;
    push_matrix();
    project_world_to_screen(NULL, &pos, screen);
    pop_matrix();
    if (calc_clamp_offset(screen, &push) != 0) {
        Vec step;
        step.x = push.x;
        step.y = push.y;
        step.z = 0.0f;
        step.x *= 0.07f;
        step.y *= (-0.07f);
        step.z *= 0.07f;
        velocity.x += step.x;
        velocity.y += step.y;
        velocity.z += step.z;
    }
}

void TLoadingCur::render() { sub_8001CCD4(); }

#pragma push
#pragma fp_contract on
#pragma opt_propagation off
void TLoadingCur::run_task() {
    f32 x;
    f32 y;
    u32 flags;
    ControllerInputContext *p;
    f32 z;
    x = 0.0f;
    y = x;
    x += 0.0078125f * (f32)controller_input_state.controllers[0].stick_x;
    y -= 0.0078125f * (f32)controller_input_state.controllers[0].stick_y;
    x += 0.0078125f * (f32)controller_input_state.controllers[0].cstick_x;
    y -= 0.0078125f * (f32)controller_input_state.controllers[0].cstick_y;
    flags = controller_input_state.controllers[0].buttons;
    if (flags & 0x10) {
        y += 1.0f;
    }
    if (flags & 0x20) {
        y -= 1.0f;
    }
    if (flags & 0x80) {
        x += 1.0f;
    }
    if (flags & 0x40) {
        x -= 1.0f;
    }
    p = &controller_input_state.keyboard;
    if (test_previous_buttons_color(p, 0x10) != 0) {
        y += 1.0f;
    }
    if (test_previous_buttons_color(p, 0x20) != 0) {
        y -= 1.0f;
    }
    if (test_previous_buttons_color(p, 0x80) != 0) {
        x += 1.0f;
    }
    if (test_previous_buttons_color(p, 0x40) != 0) {
        x -= 1.0f;
    }
    velocity.x += 0.51f * x;
    velocity.y += 0.51f * y;
    velocity.z += (z = 0.0f);
    offset.x += velocity.x;
    offset.y += velocity.y;
    offset.z += velocity.z;
    velocity.x *= 0.9f;
    velocity.y *= 0.9f;
    velocity.z *= 0.9f;
    VecCopy(&anchor, &calc_loading_cursor_pos(this));
    update_camera_facing_offset();
    if (0.0f != x || 0.0f != y) {
        if (is_split_screen() != 0) {
            play_persistent_sound(0x53C10, this, &pos, 0, 1);
        } else {
            play_persistent_sound(0x53C10, this, &pos, 0, 0);
        }
    }
}
#pragma pop

TLoadingCur::~TLoadingCur() {
    if (particle != NULL) {
        particle->queue_destruction();
        particle = NULL;
    }
}

#pragma push
#pragma fp_contract on
TLoadingCur::TLoadingCur(TObject *parent, Vec *pos) : TObject(parent) {
    ParticleAngles angles;
    m_name = class_name;
    offset.x = 0.0f;
    offset.y = 0.0f;
    offset.z = 0.0f;
    velocity.x = 0.0f;
    velocity.y = 0.0f;
    velocity.z = 0.0f;
    anchor.x = 1e+02f * ninja_camera.vx + ninja_camera.px;
    anchor.y = 1e+02f * ninja_camera.vy + ninja_camera.py;
    anchor.z = 1e+02f * ninja_camera.vz + ninja_camera.pz;
    facing.x = -ninja_camera.vx;
    facing.y = -ninja_camera.vy;
    facing.z = -ninja_camera.vz;
    angles.x = 0;
    angles.y = 0;
    angles.z = 0;
    direction_to_rotation_xz((u8 *)&facing, &angles.x, &angles.z);
    particle = create_particle_controller_with_angles(&offset, &angles, 0x16, 1);
}
#pragma pop
