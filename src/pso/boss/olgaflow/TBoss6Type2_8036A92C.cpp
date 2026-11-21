#include "types.h"
#include "pso/boss/olgaflow/TBoss6Type2_8036A92C.h"
#include "pso/boss/olgaflow/TBoss6Type2.h"
#include "pso/system/task/TObject.h"
#include "pso/boss/olgaflow/TBoss6EffFlowSoul.h"

extern "C" {
s32 spawn_flow_soul__11TBoss6Type2Fiii(saddr arg0, saddr arg1, saddr arg2) {
    return (saddr)new TBoss6EffFlowSoul((TObject *)arg0, (Vec *)arg1, 0xFFFF, arg2);
}

void *TBoss6Type2::create_flow_soul(void *parent, void *pos, s32 player, s32 duration) {
    return new TBoss6EffFlowSoul((TObject *)parent, (Vec *)pos, player, duration);
}

}
