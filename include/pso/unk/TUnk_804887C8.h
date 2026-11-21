#ifndef PSO_UNK_TUNK_804887C8_H
#define PSO_UNK_TUNK_804887C8_H
#include "types.h"
#include "pso/unk/TUnk_80488A28.h"

class TUnk_804887C8 : public TUnk_80488A28 {
public:
    TUnk_804887C8();
    virtual ~TUnk_804887C8();
    virtual void run_task();
};
LAYOUT_ASSERT(TUnk_804887C8_size, sizeof(TUnk_804887C8) == 0x6C);

#endif
