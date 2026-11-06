#ifndef PSO_RENDER_TFOGCTRL_EOR_H
#define PSO_RENDER_TFOGCTRL_EOR_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TFogCtrl_EOR : public TObject {
public:
    virtual ~TFogCtrl_EOR();
    u8 *init_object();
    virtual void run_task();
};
typedef char TFogCtrl_EOR_size[sizeof(TFogCtrl_EOR) == 0x1C ? 1 : -1];

#endif
