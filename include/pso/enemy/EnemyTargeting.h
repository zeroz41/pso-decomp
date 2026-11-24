#ifndef PSO_ENEMY_ENEMYTARGETING_H
#define PSO_ENEMY_ENEMYTARGETING_H

#include "types.h"

class TObjBase;
class TObjChara;
struct Vec;

extern "C" {
// Squared distance between actor positions in the x/z plane. A null target
// returns the out-of-range sentinel without writing the optional offset.
f32 calc_xz_distance_sq(const TObjBase *actor, const TObjBase *target, Vec *offset);

// The nearest visible player on the current floor, with its direction if requested.
u16 find_nearest_visible_player(TObjChara *searcher, Vec *direction, f32 range);
}

// The nearest hit-receivable enemy within range of the searcher (0xFFFF for none), with its offset if requested.
u16 find_nearest_hittable_enemy(TObjBase *searcher, Vec *direction, f32 range);

#endif
