#ifndef PSO_BOSS_TBOSS5GRYPHONLIGHTNINGWING_H
#define PSO_BOSS_TBOSS5GRYPHONLIGHTNINGWING_H

#include "pso/TBoss5GryphonLightning.h"
#include "types.h"

class TBoss5GryphonLightningWing : public TBoss5GryphonLightning {
public:
    virtual ~TBoss5GryphonLightningWing();
    void update_wing_segments();
    virtual void run_task();
    virtual void render();
public:
    static void render();
    void get_wing_position(s32 arg1);
public:
    void apply_lightning_effect();
};

class TBoss5GryphonLightningWing;
extern "C" {
s32 __ct__26TBoss5GryphonLightningWingFv(int arg0, void *arg1, void *a, void *mid, void *b, void *arg5, void *arg6);
void apply_lightning_effect__26TBoss5GryphonLightningWingFv(s32 arg0);
void fn_80351DA8(s32 arg0, u8 *pos, u8 *out, s32 arg3, s32 arg4);
void run_task__26TBoss5GryphonLightningWingFv(TBoss5GryphonLightningWing *arg0);
s32 spawn_lightning_wing__12TBoss8DragonFiiiiii(s32 arg0, s32 arg1, s32 mid, s32 arg3, s32 arg4, s32 arg5);
}

// --- C functions defined in TBoss5GryphonLightningWing.cpp ---
extern "C" {
void run_task__26TBoss5GryphonLightningWingFv(TBoss5GryphonLightningWing *boss5_gryphon_lightning_wing);
}
// --- end of C functions

#endif
