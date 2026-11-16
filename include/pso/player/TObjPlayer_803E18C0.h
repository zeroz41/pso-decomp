#ifndef PSO_PLAYER_TOBJPLAYER_803E18C0_H
#define PSO_PLAYER_TOBJPLAYER_803E18C0_H

#include "types.h"
#include <dolphin/mtx/GeoTypes.h>

struct Line_803E18C0 { Vec o; Vec d; };

extern "C" {
// The distance from p to the line l; the closest point on l goes to out when it is not NULL.
f32 project_point_onto_line(Vec *p, Line_803E18C0 *l, Vec *out);
}

// --- C functions defined in TObjPlayer_803E18C0.cpp ---
extern "C" {
f32 project_point_onto_line(Vec *p, Line_803E18C0 *l, Vec *out);
}
// --- end of C functions

#endif
