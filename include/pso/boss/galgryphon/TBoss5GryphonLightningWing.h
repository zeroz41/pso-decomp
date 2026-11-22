#ifndef PSO_BOSS_GALGRYPHON_TBOSS5GRYPHONLIGHTNINGWING_H
#define PSO_BOSS_GALGRYPHON_TBOSS5GRYPHONLIGHTNINGWING_H

#include "pso/boss/galgryphon/TBoss5GryphonLightning.h"
#include "types.h"

struct Vec;

class TBoss5GryphonLightningWing : public TBoss5GryphonLightning {
public:
    virtual ~TBoss5GryphonLightningWing();
    void update_wing_segments();
    virtual void run_task();
    virtual void render();
public:
    void get_wing_position(Vec *out);
    void copy_position(void *out);
public:
    void apply_lightning_effect();

    s32 grow_frames;
    s32 life_frames;  // run_task removes the wing once age reaches it
};

class TBoss5GryphonLightningWing;
extern "C" {
s32 __ct__26TBoss5GryphonLightningWingFv(saddr allocation, void *arg1, void *a, void *mid, void *b, void *arg5, void *arg6);
void apply_lightning_effect__26TBoss5GryphonLightningWingFv(s32 arg0);
void fn_80351DA8(s32 self, u8 *pos, u8 *out, s32 arg3, s32 arg4);
void run_task__26TBoss5GryphonLightningWingFv(TBoss5GryphonLightningWing *boss5_gryphon_lightning_wing);
s32 spawn_lightning_wing__12TBoss8DragonFiiiiii(saddr self, saddr pos, saddr mid, saddr arg3, saddr arg4, saddr arg5);
}

// --- C functions defined in TBoss5GryphonLightningWing.cpp ---
extern "C" {
void run_task__26TBoss5GryphonLightningWingFv(TBoss5GryphonLightningWing *boss5_gryphon_lightning_wing);
}
// --- end of C functions

#endif
