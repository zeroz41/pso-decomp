#include "pso/render/GinjaView.h"
#include "types.h"

#pragma push
#pragma use_lmw_stmw off

#pragma push
#pragma opt_common_subs off

void update_projection_params(const ScreenProjection *view) {
    f32 center_y, center_x, distance;
    screen_projection.distance = distance = view->distance;
    screen_projection.center_x = center_x = view->center_x;
    screen_projection.center_y = center_y = view->center_y;
    screen_projection.scale_x = screen_projection.width * distance;
    screen_projection.scale_y = -(screen_projection.height * distance);
    screen_projection.inv_scale_x = 1.0f / screen_projection.scale_x;
    screen_projection.inv_scale_y = 1.0f / screen_projection.scale_y;
    camera_clip_parameters[2] = camera_clip_parameters[8] - center_x;
    camera_clip_parameters[3] = camera_clip_parameters[6] - center_x;
    camera_clip_parameters[4] = camera_clip_parameters[9] - center_y;
    camera_clip_parameters[5] = camera_clip_parameters[7] - center_y;
}
#pragma pop
#pragma pop
