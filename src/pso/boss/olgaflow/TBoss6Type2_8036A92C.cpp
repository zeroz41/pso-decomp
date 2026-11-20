#include "types.h"
#include "pso/boss/olgaflow/TBoss6Type2_8036A92C.h"
#include "pso/boss/olgaflow/TBoss6Type2.h"
#include "pso/system/task/TObject.h"

extern "C" {
void *TBoss6EffFlowSoul__ct(void *, void *, void *, void *, void *);
s32 spawn_flow_soul__11TBoss6Type2Fiii(saddr arg0, saddr arg1, saddr arg2) {
    saddr boss6_eff_flow_soul;
    s32 var_r0;
    boss6_eff_flow_soul = ((saddr)TObject::operator new(0x3C));
    var_r0 = boss6_eff_flow_soul;
    if (var_r0 != 0) {
        var_r0 = ((saddr)TBoss6EffFlowSoul__ct((void *)boss6_eff_flow_soul, (void *)arg0, (void *)arg1, (void *)(0xFFFF), (void *)arg2));
    }
    return var_r0;
}

void *TBoss6Type2::create_flow_soul(void *arg0, void *arg1, void *arg2, void *arg3) {
    void *o;
    o = TObject::operator new(0x3C);
    if (o != NULL) {
        o = TBoss6EffFlowSoul__ct(o, arg0, arg1, arg2, arg3);
    }
    return o;
}

}
