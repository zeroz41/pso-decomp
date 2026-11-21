#ifndef PSO_UNK_TUNK_804999D0_H
#define PSO_UNK_TUNK_804999D0_H
#include "types.h"
#include "pso/boss/TUnk_804999E8.h"

class TUnk_804999D0 : public TUnk_804999E8 {
public:
    virtual ~TUnk_804999D0();
    virtual void run_task();
    u8 unk_24[0x4];
};
LAYOUT_ASSERT(TUnk_804999D0_size, sizeof(TUnk_804999D0) == 0x28);

#endif
