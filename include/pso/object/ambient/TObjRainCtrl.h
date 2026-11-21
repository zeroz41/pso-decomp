#ifndef PSO_OBJECT_AMBIENT_TOBJRAINCTRL_H
#define PSO_OBJECT_AMBIENT_TOBJRAINCTRL_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TObjRainCtrl : public TObject {
public:
    explicit TObjRainCtrl(TObject *parent);
    virtual ~TObjRainCtrl();
    virtual void run_task();

    static void create();

private:
    s32 ticks_until_spawn;
};

LAYOUT_ASSERT(TObjRainCtrlSize, sizeof(TObjRainCtrl) == 0x20);

#endif
