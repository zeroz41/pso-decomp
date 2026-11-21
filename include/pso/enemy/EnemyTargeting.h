#ifndef PSO_ENEMY_ENEMYTARGETING_H
#define PSO_ENEMY_ENEMYTARGETING_H

#include "types.h"

class TObjChara;
struct Vec;

extern "C" {
// The nearest visible player on the current floor, with its direction if requested.
u16 find_nearest_visible_player(TObjChara *searcher, Vec *direction, f32 range);
u16 find_nearest_hittable_enemy__10TObjPlayerFiPvf(s32 searcher_address, Vec *direction, f32 range);
}

#endif
