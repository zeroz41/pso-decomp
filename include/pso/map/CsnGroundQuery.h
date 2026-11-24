#ifndef PSO_MAP_CSN_GROUND_QUERY_H
#define PSO_MAP_CSN_GROUND_QUERY_H
#include "types.h"
#include <dolphin/mtx.h>

struct CsnGroundSurface {
    Vec point;
    Vec normal;
    u32 flags;
    u8 unknown_1c[0x1c];
    Vec point_38;
    u8 unknown_44[0x10];
    Vec point_54;
};

struct CsnGroundHit {
    u32 flags;
    CsnGroundSurface *surface;
};

// Ground and segment queries share this record and its contact array.
struct CsnContact {
    Vec point;
    Vec normal;
    u32 flags;

    void reset();
};

struct CsnHit {
    u32 hit_mask;
    CsnContact *contact;

    CsnHit *init_and_return();
};

LAYOUT_ASSERT(CsnContactSize, sizeof(CsnContact) == 0x1C);
LAYOUT_ASSERT(CsnHitSize, sizeof(CsnHit) == 8);

// A cached query uses caller-provided storage for up to 14 groups and a null terminator.
struct CsnGroup;
class TObjCollidable;
extern "C" {
CsnHit *csnVectorUnder(Vec *origin, CsnGroup **cached_groups, u32 mask);
// The ground straight below origin, NULL for none.
CsnHit *csnVecterUnder(Vec *origin, u32 mask);
// Drops pos onto the ground under it (from 10 units up, through the actor's
// ground cache when it has one); 1 if found, the ground normal in *normal.
s32 project_actor_to_ground(TObjCollidable *actor, Vec *pos, Vec *normal);
}
#endif
