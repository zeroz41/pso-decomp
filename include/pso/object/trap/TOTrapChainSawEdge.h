#ifndef PSO_OBJECT_TRAP_TOTRAPCHAINSAWEDGE_H
#define PSO_OBJECT_TRAP_TOTRAPCHAINSAWEDGE_H

#include "types.h"
#include "pso/object/trap/TOTrapChainSaw.h"

// One of the two blades a TOTrapChainSawDamage spawns above itself: it starts
// a run each time its parent queues one.
struct TOTrapChainSawEdge : public TOTrapChainSaw {
    TOTrapChainSawEdge(TObject *parent, void *set_data);
    virtual ~TOTrapChainSawEdge();
    virtual void update_extension();
    virtual void update_sweep();
    virtual void draw_model();
    virtual void select_model();
    virtual void check_player_contact();
    s32 extent;         // the extent of the current move (max_offset when a start is taken)
    s32 variant;        // scale.z clamped to 0-1: the 2 m or 4 m saw
    s32 pending_starts; // starts queued by the damage saw (TOTrapChainSawDamage tick 5 / 10)
    s32 phase;          // 0 waiting for a start, 1 moving
    void set_target_offset(s32 offset);
    void queue_runs(s32 count);
};

LAYOUT_ASSERT(TOTrapChainSawEdge_size, sizeof(TOTrapChainSawEdge) == 0x108);

#endif
