#ifndef PSO_UNK_TUNK_804CC0E8_H
#define PSO_UNK_TUNK_804CC0E8_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804CC0E8 : public TObject {
public:
    virtual ~TUnk_804CC0E8();
    virtual void run_task();
    u8 unk_1C[0x2C];
};
LAYOUT_ASSERT(TUnk_804CC0E8_size, sizeof(TUnk_804CC0E8) == 0x48);

#endif
