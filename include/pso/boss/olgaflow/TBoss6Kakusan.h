#ifndef PSO_BOSS_OLGAFLOW_TBOSS6KAKUSAN_H
#define PSO_BOSS_OLGAFLOW_TBOSS6KAKUSAN_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TBoss6Kakusan : public TObject {
    virtual ~TBoss6Kakusan();
    u32 m_1c;
    u16 m_20;
    u8 unk_22[0x2];
    f32 m_24;
    f32 m_28;
    u32 m_2c;
    void* m_30;
    u8 _pad34[0x8];
    void* m_3c;
    u8 _pad40[0x8];
    void* m_48;
    u8 _pad4C[0x8];
    u32 m_54;
    void check_beam_player_hits();
    s32 is_out_of_range();
    virtual void render();
    virtual void run_task();
};

typedef char TBoss6Kakusan_size[sizeof(TBoss6Kakusan) == 0x58 ? 1 : -1];
#endif
