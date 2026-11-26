#ifndef PSO_OBJECT_TRAP_TOTRAPCHAINSAWDAMAGE_H
#define PSO_OBJECT_TRAP_TOTRAPCHAINSAWDAMAGE_H

#include "types.h"
#include "pso/object/trap/TOTrapChainSaw.h"

struct TOTrapChainSawEdge;

struct TOTrapChainSawDamage : public TOTrapChainSaw {
    TOTrapChainSawDamage(TObject *parent, void *set_data);
    virtual ~TOTrapChainSawDamage();
    virtual void select_model();
    virtual void hit_player(TObjPlayer *player);
    virtual void update_state();
    virtual void decode_params();
    virtual void draw_model();
    virtual void draw_debug_labels();
    virtual void start_run();
    virtual void update_run();
    virtual void reach_far_end();
    s32 variant;                    // scale.z clamped to 0-1: the 2 m or 4 m saw
    f32 damage;                     // scale.y: the attack power before scale_by_level
    s32 tick;                       // frames since the run started; the edges start at 5 and 10
    TOTrapChainSawEdge *edges[2];
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TOTrapChainSawDamage_size, sizeof(TOTrapChainSawDamage) == 0x10C);
#endif
