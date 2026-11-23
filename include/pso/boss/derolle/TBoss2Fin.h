#ifndef PSO_BOSS_DEROLLE_TBOSS2FIN_H
#define PSO_BOSS_DEROLLE_TBOSS2FIN_H
#include "pso/object/TObjEZRopeBase.h"
#include "pso/system/vector.h"
#include "types.h"
#include <stddef.h>

// A pair of De Rol Le's hanging fins: two ropes, each hung from one of the boss's anchor points and
// kept out of a sphere just below it.
class TBoss2Fin : public TObjEZRopeBase {
public:
    TBoss2Fin(TObject *parent, Vec *first_anchor, Vec *second_anchor);
    virtual ~TBoss2Fin();
    virtual void run_task();
    virtual void render();
public:
    void init_link_points();
    // Fill and release the fins' rope table from the boss's models (the boss's resource callbacks).
    static void init_effect_table();
    static void release_effect_table();

    TObjEZRopeEnd rope_ends[2];
    TObjEZRopeCollider rope_colliders[3];
    Vec *anchor_a;
    Vec *anchor_b;
};

LAYOUT_ASSERT(TBoss2FinRopeEnds, offsetof(TBoss2Fin, rope_ends) == 0x30);
LAYOUT_ASSERT(TBoss2FinAnchorA, offsetof(TBoss2Fin, anchor_a) == 0x80);
LAYOUT_ASSERT(TBoss2Fin_size, sizeof(TBoss2Fin) == 0x88);

#endif
