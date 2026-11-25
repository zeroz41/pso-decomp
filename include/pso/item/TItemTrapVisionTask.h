#ifndef PSO_ITEM_TITEMTRAPVISIONTASK_H
#define PSO_ITEM_TITEMTRAPVISIONTASK_H
#include "types.h"
#include "pso/system/task/TObject.h"

struct TObjPlayer;

// Keeps a player's item timer event running for three frames
// (TItemTimerEvent::start_event_by_index), started by TItemToolTrapVision.
class TItemTrapVisionTask : public TObject {
public:
    TItemTrapVisionTask(TObject *parent, TObjPlayer *player);
    virtual ~TItemTrapVisionTask();
    virtual void run_task();
    static void create(TObject *parent, TObjPlayer *player);
    u16 client_id;
    s16 frames_left;
};
LAYOUT_ASSERT(TItemTrapVisionTask_size, sizeof(TItemTrapVisionTask) == 0x20);

#endif
