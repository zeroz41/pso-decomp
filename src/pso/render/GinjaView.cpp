#include "pso/render/GinjaView.h"
#include "types.h"
#include "pso/system/NinjaTypes.h"

#include <stddef.h>
#include "pso/camera/TCameraCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/RenderSbssGlobals.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/MatrixVector.h"

Vec camera_look_at_up_vector = {0.0f, 1.0f, 0.0f};

void update_camera_state(f32 x, f32 y, f32 z) {
    translate_view_negated(x, y, z);
}

void look_at_position(f32 x, f32 y, f32 z) {
    Vec eye;
    Vec target;
    get_look_at_eye(&eye);
    target.x = x;
    target.y = y;
    target.z = z;
    set_matrix_identity(NULL);
    set_camera_look_at(&eye, &target, &camera_look_at_up_vector);
}

#pragma push
#pragma scheduling off
void translate_view_negated(f32 x, f32 y, f32 z) {
    translate_matrix(0, -x, -y, -z);
}
#pragma pop

void get_look_at_eye(Vec *eye) {
}

#pragma push
#pragma scheduling off
void set_camera_look_at(const Vec *eye, const Vec *target, const Vec *up) {
    C_MTXLookAt(*current_matrix, eye, up, target);
}
#pragma pop

#pragma push
#pragma opt_common_subs off
#pragma scheduling off

// Clip distances come in as negative view-space z, clamped to [-65535, -1].
void set_clip_planes(f32 near_z, f32 far_z) {
    if (near_z > -1.0f) {
        near_z = -1.0f;
    }
    if (near_z < -65535.0f) {
        near_z = -65535.0f;
    }
    if (far_z > -1.0f) {
        far_z = -1.0f;
    }
    if (far_z < -65535.0f) {
        far_z = -65535.0f;
    }
    camera_clip_parameters[1] = -near_z;
    camera_clip_parameters[0] = -far_z;
}
#pragma pop

void set_screen_size(f32 width, f32 height) {
    f32 scale_x, scale_y;
    screen_projection.width = width;
    screen_projection.height = height;
    screen_projection.aspect = height / width;
    scale_x = (f32)(f64)width * screen_projection.distance;
    screen_projection.scale_x = scale_x;
    scale_y = -((f32)(f64)height * screen_projection.distance);
    screen_projection.scale_y = scale_y;
    screen_projection.inv_scale_x = 1.0f / scale_x;
    screen_projection.inv_scale_y = 1.0f / (f32)(f64)scale_y;
}
