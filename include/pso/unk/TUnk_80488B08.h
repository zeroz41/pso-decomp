#ifndef PSO_UNK_TUNK_80488B08_H
#define PSO_UNK_TUNK_80488B08_H
#include "types.h"
#include "pso/camera/TCameraController.h"

class TUnk_80488B08 : public TCameraController {
public:
    TUnk_80488B08();
    virtual ~TUnk_80488B08();
    virtual void apply_camera_params(s32 pass);
    virtual void run_task();
};
LAYOUT_ASSERT(TUnk_80488B08_size, sizeof(TUnk_80488B08) == 0x6C);

#endif
