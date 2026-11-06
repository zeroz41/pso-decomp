#ifndef PSO_UNK_TUNK_804CCD0C_H
#define PSO_UNK_TUNK_804CCD0C_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804CCD0C : public TObject {
public:
    TUnk_804CCD0C(s32 arg1, s32 arg2);
    virtual ~TUnk_804CCD0C();
    u8 unk_1C[0x10];
    s32 m_2c;
    u8 unk_30[0x4];
};
typedef char TUnk_804CCD0C_size[sizeof(TUnk_804CCD0C) == 0x34 ? 1 : -1];

#endif
