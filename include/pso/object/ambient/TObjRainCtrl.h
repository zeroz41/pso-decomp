#ifndef PSO_OBJECT_AMBIENT_TOBJRAINCTRL_H
#define PSO_OBJECT_AMBIENT_TOBJRAINCTRL_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TObjRainCtrl : public TObject {
public:
    virtual ~TObjRainCtrl();
    virtual void run_task();
public:
    static void create();
};

extern "C" {
void *TObjRainCtrl__ct(void *rain_ctrl, void *parent);
}

#endif
