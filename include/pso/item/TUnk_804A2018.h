#ifndef PSO_ITEM_TUNK_804A2018_H
#define PSO_ITEM_TUNK_804A2018_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TEffStarLight2D;

// Keeps a 2D star light on a weapon joint while the item stays drawn.
class TUnk_804A2018 : public TObject {
public:
    TUnk_804A2018(TObject *parent, s32 item_id, s32 joint);
    virtual ~TUnk_804A2018();
    virtual void run_task();

    s32 item_id;
    s32 joint;
    TEffStarLight2D *star_light;
    u32 item_generation;  // get_item_system_generation() when built; a change ends it
};
LAYOUT_ASSERT(TUnk_804A2018_size, sizeof(TUnk_804A2018) == 0x2C);

#endif
