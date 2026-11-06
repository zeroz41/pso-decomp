#ifndef PSO_BOSS_OLGAFLOW_TBOSS6DEMO20_TYPE2_APPEAR_H
#define PSO_BOSS_OLGAFLOW_TBOSS6DEMO20_TYPE2_APPEAR_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TBoss6Demo20_TYPE2_APPEAR : public TObject {
public:
    virtual ~TBoss6Demo20_TYPE2_APPEAR();
    void draw_fading_model_pair();
    void draw_fading_model_4();
    void draw_fading_model_1_pair();
    void draw_model_12();
    virtual void render();
    virtual void run_task();
    u8 unk_1C[0x60];
    u32 m_7c;
    u8 unk_80[0x3C];
    s32 m_bc;
    u8 unk_C0[0x4];
    s32 m_c4;
    u8 unk_C8[0x4];
    s32 m_cc;
    u8 unk_D0[0x4];
    s32 m_d4;
    u8 unk_D8[0x4];
    s32 m_dc;
    u8 unk_E0[0x4];
    f32 m_e4;
    u8 unk_E8[0x4];
    s32 m_ec;
};
typedef char TBoss6Demo20_TYPE2_APPEAR_size[sizeof(TBoss6Demo20_TYPE2_APPEAR) == 0xF0 ? 1 : -1];

#endif
