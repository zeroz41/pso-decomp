#ifndef PSO_BOSS_TBOSS6DPB_H
#define PSO_BOSS_TBOSS6DPB_H

#include "pso/TObject.h"
#include "types.h"

class TBoss6DPB : public TObject {
public:
    virtual ~TBoss6DPB();
    void apply_shower_damage_to_players();
    void sub_8035D8B0();
    virtual void run_task();
    virtual void render();
public:
    static void render();
};

extern "C" {
u8 *__ct__9TBoss6DPBFv(u8 *arg0, s32 arg1, s32 arg2, f32 farg0);
}

#endif
