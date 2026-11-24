#ifndef PSO_EFFECT_ITEM_TITEMEFFLANDHIT_H
#define PSO_EFFECT_ITEM_TITEMEFFLANDHIT_H

#include "pso/system/task/TObject.h"
#include "types.h"
#include "pso/system/vector.h"

class TItem;

class TItemEffLandHit : public TObject {
public:
    Vec start;
    Vec end;
    s32 item_id;
    s32 finished;

    static const char *class_name;

    TItemEffLandHit(TObject *parent, TItem *item, Vec *start, Vec *end);
    virtual ~TItemEffLandHit();
    virtual void run_task();
    // Fires the shooting item's impact callback from start to end and ends the effect.
    void trigger_impact();
    // The item timer's expiry callback for the effect.
    static void on_timer_expired(TObject *object);
};

void spawn_land_hit_effect(TObject *parent, TItem *item, Vec *start, Vec *end, s32 frames);

#endif
