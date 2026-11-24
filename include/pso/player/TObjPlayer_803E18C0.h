#ifndef PSO_PLAYER_TOBJPLAYER_803E18C0_H
#define PSO_PLAYER_TOBJPLAYER_803E18C0_H

#include "types.h"
#include <dolphin/mtx/GeoTypes.h>

struct Line { Vec o; Vec d; };

extern "C" {
// The distance from p to the line l; the closest point on l goes to out when it is not NULL.
f32 project_point_onto_line(Vec *p, Line *l, Vec *out);
}

#endif
