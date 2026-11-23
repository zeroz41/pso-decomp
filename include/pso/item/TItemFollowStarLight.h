#ifndef PSO_ITEM_TITEMFOLLOWSTARLIGHT_H
#define PSO_ITEM_TITEMFOLLOWSTARLIGHT_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TEffStarLight2D;

// Keeps a 2D star light on a weapon joint while the item stays drawn.
class TItemFollowStarLight : public TObject {
public:
    TItemFollowStarLight(TObject *parent, s32 item_id, s32 joint);
    virtual ~TItemFollowStarLight();
    virtual void run_task();

    s32 item_id;
    s32 joint;
    TEffStarLight2D *star_light;
    u32 item_generation;  // get_item_system_generation() when built; a change ends it
};
LAYOUT_ASSERT(TItemFollowStarLight_size, sizeof(TItemFollowStarLight) == 0x2C);

void spawn_item_follow_star_light(TObject *parent, s32 item_id, s32 joint);

#endif
