#ifndef PSO_UNK_TUNK_80488DA0_H
#define PSO_UNK_TUNK_80488DA0_H
#include "types.h"
#include "pso/camera/TCameraController.h"

class TUnk_80488DA0 : public TCameraController {
public:
    TUnk_80488DA0();
    virtual ~TUnk_80488DA0();
    virtual void run_task();
    void set_target_pos(void*);
    u8 unk_6C[0x4];
};
LAYOUT_ASSERT(TUnk_80488DA0_size, sizeof(TUnk_80488DA0) == 0x70);

// --- C functions defined in TUnk_80488DA0.cpp ---
extern "C" {
void *TCameraCtrl__vt6(void);
}
// --- end of C functions

#endif
