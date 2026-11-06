#include "types.h"
#include "pso/boss/olgaflow/TBoss6Tube.h"
#include "pso/boss/olgaflow/TBoss6Tube_802B15F4.h"


struct RecoveredGlobal_802B1654___vt__10TBoss6Tube { s32 value; u8 remaining[0x14]; };
typedef char RecoveredGlobal_802B1654___vt__10TBoss6Tube_size[sizeof(RecoveredGlobal_802B1654___vt__10TBoss6Tube) == 0x18 ? 1 : -1];

extern "C" {
void __ct__7TObjectFP7TObject(void *, void *);
extern s32 __vt__10TBoss6Tube[];
extern s32 lbl_805D3E9C;

}
TBoss6Tube::~TBoss6Tube() {
    TBoss6Tube::reset_state();
}

u8 *TBoss6Tube__ct(TBoss6Tube *boss6_tube, u8 *arg1) {
    __ct__7TObjectFP7TObject(boss6_tube, arg1);
    *(s32 **)((s8 *)boss6_tube + 0x18) = &(*(RecoveredGlobal_802B1654___vt__10TBoss6Tube *)&__vt__10TBoss6Tube).value;
    *(s32 *)((s8 *)boss6_tube + 0) = (s32) lbl_805D3E9C;
    *(u8 **)((s8 *)boss6_tube + 0x2C) = arg1;
    boss6_tube->m_24 = 0;
    boss6_tube->m_28 = 0;
    TBoss6Tube::reset_state();
    boss6_tube->m_20 = 0;
    boss6_tube->m_1c = 0;
    return (u8 *)boss6_tube;
}

