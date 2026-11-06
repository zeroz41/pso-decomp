#ifndef PSO_UNK_TUNK_804CCD78_H
#define PSO_UNK_TUNK_804CCD78_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804CCD78 : public TObject {
public:
    virtual ~TUnk_804CCD78();
    virtual void run_task();
    u8 unk_1C[0x1C];
    s32 m_38;
    u8 unk_3C[0x4];
};
typedef char TUnk_804CCD78_size[sizeof(TUnk_804CCD78) == 0x40 ? 1 : -1];

#endif
