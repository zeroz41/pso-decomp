#ifndef PSO_UNK_TUNK_804999A0_H
#define PSO_UNK_TUNK_804999A0_H
#include "types.h"
#include "pso/boss/TUnk_804999E8.h"

class TUnk_804999A0 : public TUnk_804999E8 {
public:
    virtual ~TUnk_804999A0();
    virtual void run_task();
    virtual void render();
    u8 unk_24[0x8];
};
LAYOUT_ASSERT(TUnk_804999A0_size, sizeof(TUnk_804999A0) == 0x2C);

#endif
