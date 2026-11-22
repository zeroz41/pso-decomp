#include "types.h"
#include "pso/boss/olgaflow/TBoss6Type2.h"
#include "pso/system/task/TObject.h"
#include "pso/boss/olgaflow/TBoss6EffFlowSoul.h"

extern "C" {
TBoss6EffFlowSoul *TBoss6Type2::spawn_flow_soul(TObject *parent, Vec *pos, s32 duration) {
    return new TBoss6EffFlowSoul(parent, pos, 0xFFFF, duration);
}

TBoss6EffFlowSoul *TBoss6Type2::create_flow_soul(TObject *parent, Vec *pos, s32 player, s32 duration) {
    return new TBoss6EffFlowSoul(parent, pos, player, duration);
}

}
