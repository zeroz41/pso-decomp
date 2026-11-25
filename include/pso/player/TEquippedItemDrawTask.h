#ifndef PSO_PLAYER_TEQUIPPEDITEMDRAWTASK_H
#define PSO_PLAYER_TEQUIPPEDITEMDRAWTASK_H
#include "types.h"
#include "pso/system/task/TObject.h"

// Draws the equipped items queued in player_item_id_list (EquippedItemDrawQueue) through
// find_equipped_item and each item's render(); run_task empties the queue every frame.
class TEquippedItemDrawTask : public TObject {
public:
    TEquippedItemDrawTask(TObject *parent);
    virtual ~TEquippedItemDrawTask();
    virtual void render();
    virtual void run_task();

    static void create(TObject *parent);
    static void create_queue();
    static void destroy_queue();
};
LAYOUT_ASSERT(TEquippedItemDrawTask_size, sizeof(TEquippedItemDrawTask) == 0x1C);

#endif
