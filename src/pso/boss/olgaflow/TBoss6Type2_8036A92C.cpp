#include "types.h"
#include "pso/boss/olgaflow/TBoss6Type2_8036A92C.h"
#include "pso/boss/olgaflow/TBoss6Type2.h"

extern "C" {
void *__nw__7TObjectFUl(int);
void *TBoss6EffFlowSoul__ct(void *, void *, void *, void *, void *);
s32 spawn_flow_soul__11TBoss6Type2Fiii(s32 arg0, s32 arg1, s32 arg2) {
    s32 boss6_eff_flow_soul;
    s32 var_r0;
    boss6_eff_flow_soul = ((s32)__nw__7TObjectFUl(0x3C));
    var_r0 = boss6_eff_flow_soul;
    if (var_r0 != 0) {
        var_r0 = ((s32)TBoss6EffFlowSoul__ct((void *)boss6_eff_flow_soul, (void *)arg0, (void *)arg1, (void *)(0xFFFF), (void *)arg2));
    }
    return var_r0;
}

void *TBoss6Type2::create_flow_soul(void *arg0, void *arg1, void *arg2, void *arg3) {
    void *o;
    o = __nw__7TObjectFUl(0x3C);
    if (o != NULL) {
        o = TBoss6EffFlowSoul__ct(o, arg0, arg1, arg2, arg3);
    }
    return o;
}

}
