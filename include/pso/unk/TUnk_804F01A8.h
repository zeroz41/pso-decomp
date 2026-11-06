#ifndef PSO_UNK_TUNK_804F01A8_H
#define PSO_UNK_TUNK_804F01A8_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804F01A8 : public TObject {
public:
    virtual ~TUnk_804F01A8();
    void *ct();
    void *destroy(s16);
    u8 unk_1C[0x4];
    u32 m_20;
    u8 unk_24[0x4];
    u32 m_28;
    u8 unk_2C[0x4];
};
typedef char TUnk_804F01A8_size[sizeof(TUnk_804F01A8) == 0x30 ? 1 : -1];

#endif
