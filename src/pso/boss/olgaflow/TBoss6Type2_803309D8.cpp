#include "types.h"
#include "pso/boss/olgaflow/TBoss6Type2_803309D8.h"
#include "pso/boss/olgaflow/TBoss6Type2.h"
#include "pso/system/task/TObject.h"
#include "pso/object/TObjControl.h"
#include "pso/system/task/TMainTask.h"
#include "pso/boss/olgaflow/TBoss6Mag.h"

struct Base_803309D8 { char pad[0x18]; };
struct VObj_803309D8 : Base_803309D8 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
};

TBoss6Mag *TBoss6Type2::create_mag(TBoss6MagSpawnParams *params) {
    return new TBoss6Mag(new TObjControl(tl_04), params);
}

extern "C" {

void fn_80330A40(u8 *arg0) {

    ((VObj_803309D8 *) ((unsigned char *) (*(void **)((s8 *)arg0 + 0x2C))))->m7();
    *(s8 *)((s8 *)arg0 + 0x1C) = 0x22;
}

}
