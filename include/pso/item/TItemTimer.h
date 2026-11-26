#ifndef PSO_ITEM_TITEMTIMER_H
#define PSO_ITEM_TITEMTIMER_H

#include "pso/system/task/TObject.h"
#include "types.h"

// What a TItemTimer runs when it expires: `callback(target)`.
struct TItemTimerCallback {
    void *target;
    s32 (*callback)(s32);

    void invoke();
    void reset();
    void set(s32 target, s32 callback);
};

class TItemTimer : public TObject {
public:
    TItemTimer(TObject *parent, s32 expire, s32 frames);
    virtual ~TItemTimer();
    virtual void run_task();

    s32 frames_left;
    TItemTimerCallback on_expire;  // target is the object whose lifetime ends the timer too
};

#endif
