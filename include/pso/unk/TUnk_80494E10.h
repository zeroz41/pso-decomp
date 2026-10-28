#ifndef PSO_UNK_TUNK_80494E10_H
#define PSO_UNK_TUNK_80494E10_H
#include "types.h"
#include "pso/object/TObjMotion.h"

class TUnk_80494E10 : public TObjCollidable {
public:
    virtual ~TUnk_80494E10();
    virtual void run_task();
    u8 unk_AC[0xC];
    f32 m_b8;
    u8 unk_BC[0x4];
    f32 m_c0;
    u8 unk_C4[0x18];
    f32 m_dc;
    u8 unk_E0[0x4];
    s32 m_e4;
    u8 unk_E8[0xC];
    s32 m_f4;
    u8 unk_F8[0x4];
    s16 m_fc;
    u8 unk_FE[0x2];
};
typedef char TUnk_80494E10_size[sizeof(TUnk_80494E10) == 0x100 ? 1 : -1];

#endif
