#ifndef PSO_OBJECT_TOBJLIVEMONITORSMALL_H
#define PSO_OBJECT_TOBJLIVEMONITORSMALL_H

#include "pso/object/TObjLiveMonitor.h"
#include "types.h"

class TObjLiveMonitorSmall : public TObjLiveMonitor {
public:
    virtual ~TObjLiveMonitorSmall();
    virtual void run_task();
    virtual void render();
public:
    s32 spawn_for_each_fish();
};

extern "C" {
void *__ct__20TObjLiveMonitorSmallFv(void *live_monitor_small, void *arg1, void *arg2);
}

#endif
