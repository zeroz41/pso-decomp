#ifndef PSO_WEAPON_TITEMWEAPONFISTTYPES_H
#define PSO_WEAPON_TITEMWEAPONFISTTYPES_H

#include "types.h"

// Mirror plane for the second hand: a point and a normal.
struct MirrorPlane {
    f32 point_x;
    f32 point_y;
    f32 point_z;
    f32 normal_x;
    f32 normal_y;
    f32 normal_z;
};

#endif
