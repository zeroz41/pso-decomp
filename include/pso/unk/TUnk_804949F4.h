#ifndef PSO_UNK_TUNK_804949F4_H
#define PSO_UNK_TUNK_804949F4_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804949F4 : public TObject {
public:
    virtual ~TUnk_804949F4();
    virtual void vfunc_6();
    u8 unk_1C[0xC];
    f32 m_28;
    u8 unk_2C[0x4];
    u32 m_30;
    s32 m_34;
};
typedef char TUnk_804949F4_size[sizeof(TUnk_804949F4) == 0x38 ? 1 : -1];

#endif
