#ifndef PSO_ITEM_TITEMTIMER_H
#define PSO_ITEM_TITEMTIMER_H

#include "pso/system/task/TObject.h"
#include "types.h"

// Called with a timer's object when the timer runs out.
typedef void (*ItemTimerCallback)(TObject *object);

// What a TItemTimer runs when it expires: `callback(target)`.
struct TItemTimerCallback {
    TObject *target;
    ItemTimerCallback callback;

    void invoke();
    void reset();
    void set(TObject *target, ItemTimerCallback callback);
};

class TItemTimer : public TObject {
public:
    TItemTimer(TObject *parent, ItemTimerCallback expire, s32 frames);
    virtual ~TItemTimer();
    virtual void run_task();

    s32 frames_left;
    TItemTimerCallback on_expire;  // target is the object whose lifetime ends the timer too

    static const char *class_name;
    static const char class_name_string[];
};

#endif
