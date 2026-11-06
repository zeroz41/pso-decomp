#ifndef PSO_PLAYER_TUNK_8049F130_H
#define PSO_PLAYER_TUNK_8049F130_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_8049F130 : public TObject {
public:
    TUnk_8049F130(TObject *parent, s16 a, u8 b);
    virtual ~TUnk_8049F130();
    virtual void run_task();
    u8 unk_1C[0x4];
    s32 m_20;
    u8 unk_24[0x4];
    u16 m_28;
    u8 unk_2A[0x2];
    u32 m_2c;
};
typedef char TUnk_8049F130_size[sizeof(TUnk_8049F130) == 0x30 ? 1 : -1];

#endif
