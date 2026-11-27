#ifndef PSO_BOSS_GOLDRAGON_DRAGONATTACKRANGE_H
#define PSO_BOSS_GOLDRAGON_DRAGONATTACKRANGE_H

#include "types.h"
#include <dolphin/mtx/GeoTypes.h>

struct DragonAttackParams;
struct NJS_OBJECT;
class TObjBoss5PillarCtrl;

s32 is_within_xz_distance(const Vec *pos, const NJS_OBJECT *node, f32 range_squared);
f32 calc_sq_offset(const DragonAttackParams *params, f32 padding);

// Gal Gryphon attack hits on the arena: the grass and stone floors, and the pillars (boss5_ctrl_instance).
void boss5_attack_floor_in_range(const Vec *pos, const DragonAttackParams *params);
void boss5_attack_pillars_in_range(const Vec *pos, const DragonAttackParams *params);
void trigger_pillars_in_range(TObjBoss5PillarCtrl *pillar_controller, const Vec *pos, const DragonAttackParams *params);

#endif
