#ifndef PSO_UNK_TUNK_80488DA0_H
#define PSO_UNK_TUNK_80488DA0_H
#include "types.h"
#include "pso/unk/TUnk_80488A28.h"

class TUnk_80488DA0 : public TUnk_80488A28 {
public:
    virtual ~TUnk_80488DA0();
    virtual void run_task();
    void set_target_pos(void*);
    u8 unk_6C[0x4];
};
typedef char TUnk_80488DA0_size[sizeof(TUnk_80488DA0) == 0x70 ? 1 : -1];

// --- C functions defined in TUnk_80488DA0.cpp ---
extern "C" {
void *TCameraCtrl__sub_8006CC30(void *a0);
void *TCameraCtrl__vt6(void);
}
// --- end of C functions

#endif
