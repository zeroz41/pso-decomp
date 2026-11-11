#ifndef PSO_PLAYER_TOBJPLAYER_803E18C0_H
#define PSO_PLAYER_TOBJPLAYER_803E18C0_H

#include "types.h"

struct V_803E18C0 { f32 x, y, z; };

struct Line_803E18C0 { V_803E18C0 o; V_803E18C0 d; };

extern "C" {
// The distance from p to the line l; the closest point on l goes to out when it is not NULL.
f32 project_point_onto_line(V_803E18C0 *p, Line_803E18C0 *l, V_803E18C0 *out);
}

#endif
