#ifndef PSO_CAMERA_RADAR_MAP_VIEW_STATE_H
#define PSO_CAMERA_RADAR_MAP_VIEW_STATE_H

#include "types.h"
#include <dolphin/mtx.h>
#include <stddef.h>

struct RadarMapViewState {
    Vec position;
    Vec direction;
    s32 rotation_y;
    s32 field1c;
    f32 field20;
    f32 field24;

    void copy_transform(const RadarMapViewState *source);
};

typedef char RadarMapViewState_size[sizeof(RadarMapViewState) == 0x28 ? 1 : -1];
typedef char RadarMapViewState_direction[offsetof(RadarMapViewState, direction) == 0x0C ? 1 : -1];
typedef char RadarMapViewState_rotation[offsetof(RadarMapViewState, rotation_y) == 0x18 ? 1 : -1];
typedef char RadarMapViewState_last_field[offsetof(RadarMapViewState, field24) == 0x24 ? 1 : -1];

extern "C" {
extern RadarMapViewState lbl_804FF5E8;
extern RadarMapViewState TRaderMapCore__map_view_state[3];
void fn_803D64F8(RadarMapViewState *view);
}

#endif
