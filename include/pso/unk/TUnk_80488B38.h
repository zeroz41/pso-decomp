#ifndef PSO_UNK_TUNK_80488B38_H
#define PSO_UNK_TUNK_80488B38_H
#include "types.h"
#include "pso/camera/TCameraController.h"

class TUnk_80488B38 : public TCameraController {
public:
    TUnk_80488B38();
    virtual ~TUnk_80488B38();
    virtual void run_task();
    u8 unk_6C[0x4];
};
LAYOUT_ASSERT(TUnk_80488B38_size, sizeof(TUnk_80488B38) == 0x70);

#endif
