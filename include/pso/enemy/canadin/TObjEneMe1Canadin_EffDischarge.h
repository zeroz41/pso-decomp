#ifndef PSO_ENEMY_CANADIN_TOBJENEME1CANADIN_EFFDISCHARGE_H
#define PSO_ENEMY_CANADIN_TOBJENEME1CANADIN_EFFDISCHARGE_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TObjEneMe1Canadin_EffDischarge : public TObject {
public:
    virtual ~TObjEneMe1Canadin_EffDischarge();
    virtual void render();
    virtual void run_task();
    u8 unk_1C[0x4];
    f32 m_20;
    u8 unk_24[0x4];
    f32 m_28;
    u8 unk_2C[0x4];
    f32 m_30;
    u8 unk_34[0x1C];
    f32 m_50;
    u8 unk_54[0x4];
    f32 m_58;
    u8 unk_5C[0x8];
    f32 m_64;
};
typedef char TObjEneMe1Canadin_EffDischarge_size[sizeof(TObjEneMe1Canadin_EffDischarge) == 0x68 ? 1 : -1];

#endif
