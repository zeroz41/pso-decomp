#ifndef PSO_UNK_TUNK_804CCC28_H
#define PSO_UNK_TUNK_804CCC28_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804CCC28 : public TObject {
public:
    virtual ~TUnk_804CCC28();
    virtual void run_task();
    u8 unk_1C[0xC];
    s32 m_28;
    u8 unk_2C[0xC];
};
typedef char TUnk_804CCC28_size[sizeof(TUnk_804CCC28) == 0x38 ? 1 : -1];

#endif
