#ifndef PSO_UNK_TUNK_80488D70_H
#define PSO_UNK_TUNK_80488D70_H
#include "types.h"
#include "pso/camera/TCameraController.h"

class TUnk_80488D70 : public TCameraController {
public:
    virtual ~TUnk_80488D70();
    virtual void run_task();
    virtual void apply_camera_params(s32 pass);
    void *init_subobject();
};
LAYOUT_ASSERT(TUnk_80488D70_size, sizeof(TUnk_80488D70) == 0x6C);

#endif
