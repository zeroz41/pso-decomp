#ifndef PSO_BOSS_OLGAFLOW_TBOSS6DPB_H
#define PSO_BOSS_OLGAFLOW_TBOSS6DPB_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TBoss6DPB : public TObject {
public:
    TBoss6DPB(TObject *parent, s32 position, f32 arg3);
    virtual ~TBoss6DPB();
    void apply_shower_damage_to_players();
    void sub_8035D8B0();
    virtual void run_task();
    virtual void render();
public:
    static void render();
    u8 pad_1C[0x20];
};

#endif
