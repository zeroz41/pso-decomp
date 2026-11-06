#ifndef PSO_BOSS_OLGAFLOW_TBOSS6DEMO21_TYPE2_DEAD_H
#define PSO_BOSS_OLGAFLOW_TBOSS6DEMO21_TYPE2_DEAD_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TBoss6Demo21_TYPE2_DEAD : public TObject {
public:
    virtual ~TBoss6Demo21_TYPE2_DEAD();
    virtual void render();
    virtual void run_task();
    u8 unk_1C[0x4];
    s32 m_20;
    u8 unk_24[0x1C];
    s32 m_40;
    u8 unk_44[0x4];
    s32 m_48;
    u8 unk_4C[0x4];
    s32 m_50;
    u8 unk_54[0x1C];
    s32 m_70;
    u8 unk_74[0x28];
    s32 m_9c;
    u8 unk_A0[0x14];
public:
    void draw_model_13();
    static void draw_fading_model_8(void *p);
    static void draw_fading_model_5(void *p);
    void draw_fading_model_4();
};
typedef char TBoss6Demo21_TYPE2_DEAD_size[sizeof(TBoss6Demo21_TYPE2_DEAD) == 0xB4 ? 1 : -1];

#endif
