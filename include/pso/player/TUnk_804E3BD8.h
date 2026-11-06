#ifndef PSO_PLAYER_TUNK_804E3BD8_H
#define PSO_PLAYER_TUNK_804E3BD8_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804E3BD8 : public TObject {
public:
    virtual ~TUnk_804E3BD8();
    void alloc_breakup_model(s32);
    u8 unk_1C[0x8];
    s32 m_24;
    u8 unk_28[0x4];
};

#endif
