#ifndef PSO_ITEM_TUNK_8049F148_H
#define PSO_ITEM_TUNK_8049F148_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_8049F148 : public TObject {
public:
    virtual ~TUnk_8049F148();
    virtual void run_task();
    u8 unk_1C[0x4];
    s32 m_20;
    u8 unk_24[0x4];
    u32 m_28;
};
typedef char TUnk_8049F148_size[sizeof(TUnk_8049F148) == 0x2C ? 1 : -1];

#endif
