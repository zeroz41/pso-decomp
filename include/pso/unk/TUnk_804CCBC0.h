#ifndef PSO_UNK_TUNK_804CCBC0_H
#define PSO_UNK_TUNK_804CCBC0_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804CCBC0 : public TObject {
public:
    virtual ~TUnk_804CCBC0();
    virtual void run_task();
    u8 unk_1C[0x10];
    s32 m_2c;
};
LAYOUT_ASSERT(TUnk_804CCBC0_size, sizeof(TUnk_804CCBC0) == 0x30);

#endif
