#ifndef PSO_CAMERA_RADAR_MAP_VIEW_STATE_H
#define PSO_CAMERA_RADAR_MAP_VIEW_STATE_H

#include "pso/system/NinjaTypes.h"

struct RadarMapViewState {
    NJS_CAMERA camera;

    void copy_transform(const RadarMapViewState *source);
};

LAYOUT_ASSERT(RadarMapViewState_size, sizeof(RadarMapViewState) == 0x28);

struct RadarScissorRect {
    f32 x0;
    f32 y0;
    f32 x1;
    f32 y1;
};

LAYOUT_ASSERT(RadarScissorRect_size, sizeof(RadarScissorRect) == 0x10);

struct RadarViewportRect {
    f32 center_x;
    f32 center_y;
    f32 screen_width;
    f32 screen_height;
    f32 depth;
};

LAYOUT_ASSERT(RadarViewportRect_size, sizeof(RadarViewportRect) == 0x14);

extern "C" RadarMapViewState TRaderMapCore__map_view_state[3];

#endif
