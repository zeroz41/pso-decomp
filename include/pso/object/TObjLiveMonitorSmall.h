#ifndef PSO_OBJECT_TOBJLIVEMONITORSMALL_H
#define PSO_OBJECT_TOBJLIVEMONITORSMALL_H

#include "pso/object/TObjLiveMonitor.h"
#include "types.h"

// One of the small monitors around the Gol Dragon arena: a node of the small
// monitor model, showing the same screens as the big one.
class TObjLiveMonitorSmall : public TObjLiveMonitor {
public:
    TObjLiveMonitorSmall(TObject *parent, NJS_OBJECT *model);
    virtual ~TObjLiveMonitorSmall();
    virtual void run_task();
    virtual void render();
    // Spawns one under parent for each node of the small monitor model.
    static s32 spawn_all(TObject *parent);
};

#endif
