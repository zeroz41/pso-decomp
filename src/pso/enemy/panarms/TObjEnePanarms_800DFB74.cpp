#include "types.h"
#include "pso/enemy/panarms/TObjEnePanarms_800DFB74.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"

int TObjEnePanarms__sub_800DFB74(u8 *arg0) {
    u8 var_r4;
    var_r4 = 0;
    if (((s32) *(s32 *)((s8 *)arg0 + 0x378) == 4) && ((s32) *(s32 *)((s8 *)arg0 + 0x3B4) < 0)) {
        var_r4 = 1;
    }
    return var_r4;
}

u8 TObjEnePanarms__sub_800DFB9C(u8 *arg0) {
    return (u8) (*(s32 *)((s8 *)arg0 + 0x378) == 0xB);
}

u8 TObjEnePanarms__sub_800DFBB0(u8 *arg0) {
    return (u8) (*(s32 *)((s8 *)arg0 + 0x378) == 8);
}

int TObjEnePanarms__sub_800DFBC4(void* p) { return (*(u32*)((char*)p + 0x30) >> 4) & 0x1; }
