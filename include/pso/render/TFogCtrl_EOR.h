#ifndef PSO_RENDER_TFOGCTRL_EOR_H
#define PSO_RENDER_TFOGCTRL_EOR_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TFogCtrl_EOR : public TObject {
public:
    TFogCtrl_EOR();
    virtual ~TFogCtrl_EOR();
    virtual void run_task();
};
LAYOUT_ASSERT(TFogCtrl_EOR_size, sizeof(TFogCtrl_EOR) == 0x1C);

#endif
