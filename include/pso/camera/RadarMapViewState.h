#ifndef PSO_CAMERA_RADAR_MAP_VIEW_STATE_H
#define PSO_CAMERA_RADAR_MAP_VIEW_STATE_H

#include "pso/system/NinjaTypes.h"

struct RadarMapViewState {
    NJS_CAMERA camera;

    void copy_transform(const RadarMapViewState *source);
};

LAYOUT_ASSERT(RadarMapViewState_size, sizeof(RadarMapViewState) == 0x28);

extern "C" RadarMapViewState TRaderMapCore__map_view_state[3];

#endif
