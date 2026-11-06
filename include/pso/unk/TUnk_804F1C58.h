#ifndef PSO_UNK_TUNK_804F1C58_H
#define PSO_UNK_TUNK_804F1C58_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804F1C58 : public TObject {
public:
    virtual ~TUnk_804F1C58();
    void *destroy(s16);
    u8 unk_1C[0x4];
    s32 m_20;
    u8 unk_24[0x4];
    void * m_28;
    u8 unk_2C[0x4];
    s32 m_30;
    u8 unk_34[0x4];
    s32 m_38;
};
typedef char TUnk_804F1C58_size[sizeof(TUnk_804F1C58) == 0x3C ? 1 : -1];

#endif
