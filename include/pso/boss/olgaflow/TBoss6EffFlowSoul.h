#ifndef PSO_BOSS_OLGAFLOW_TBOSS6EFFFLOWSOUL_H
#define PSO_BOSS_OLGAFLOW_TBOSS6EFFFLOWSOUL_H

#include "pso/system/task/TObject.h"
#include "types.h"
#include <dolphin/mtx.h>

struct TBoss6Type2;
class TParticleCtrl;

// A soul that flies from where it spawns to a player (or, for player 0xFFFF, back to the
// Type2 body) over duration frames, carrying particle effect 0x225.
class TBoss6EffFlowSoul : public TObject {
public:
    TBoss6Type2 *owner;  // the parent; spawn_flow_soul / create_flow_soul pass the Type2 body
    TParticleCtrl *emitter;
    u16 player;  // client id to fly to; 0xFFFF flies to the owner
    Vec position;
    s32 duration;
    s32 age;
public:
    TBoss6EffFlowSoul(TObject *parent, Vec *pos, s32 player, s32 duration);
    virtual ~TBoss6EffFlowSoul();
    virtual void run_task();
};

#endif
