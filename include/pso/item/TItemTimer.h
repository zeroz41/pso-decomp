#ifndef PSO_ITEM_TITEMTIMER_H
#define PSO_ITEM_TITEMTIMER_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TItemTimer : public TObject {
public:
    TItemTimer(TObject *parent, s32 expire, s32 frames);
    virtual ~TItemTimer();
    virtual void run_task();

    s32 m_1C;
    void* m_20;
    s32 m_24;
public:
    void invoke_callback();
    void reset_fields();
};

#endif
