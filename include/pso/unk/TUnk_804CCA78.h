#ifndef PSO_UNK_TUNK_804CCA78_H
#define PSO_UNK_TUNK_804CCA78_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804CCA78 : public TObject {
public:
    virtual ~TUnk_804CCA78();
    virtual void run_task();
    u8 unk_1C[0x2];
    s16 m_1e;
    u8 unk_20[0x4];
    s32 m_24;
};
typedef char TUnk_804CCA78_size[sizeof(TUnk_804CCA78) == 0x28 ? 1 : -1];

#endif
