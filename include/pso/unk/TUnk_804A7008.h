#ifndef PSO_UNK_TUNK_804A7008_H
#define PSO_UNK_TUNK_804A7008_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804A7008 : public TObject {
public:
    virtual ~TUnk_804A7008();
    u8 unk_1C[0x4];
    s32 m_20;
    u8 unk_24[0x4];
    s8 m_28;
    u8 unk_29[0x3];
};
typedef char TUnk_804A7008_size[sizeof(TUnk_804A7008) == 0x2C ? 1 : -1];

#endif
