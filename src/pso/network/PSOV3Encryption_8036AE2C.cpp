#include "types.h"
#include "pso/boss/goldragon/TBoss8Dragon_8036AEF8.h"
#include "pso/network/PSOV3Encryption_8036AE2C.h"
#include "pso/system/memory.h"

struct RecoveredGlobal_8036AE2C_lbl_804F3628 {
    s32 value;
    u8 remaining[0x14];
};

struct VObj_0_c5c48e {
    virtual void m0();
    virtual void m1();
    virtual s32 m2(s32);
};

struct RecoveredGlobal_8036AEA4_lbl_804F3628 {
    s32 value;
    u8 remaining[0x14];
};

extern "C" {
s32 memset(void *, int, int);
extern RecoveredGlobal_8036AE2C_lbl_804F3628 lbl_804F3628;
typedef char RecoveredGlobal_8036AE2C_lbl_804F3628_size[sizeof(RecoveredGlobal_8036AE2C_lbl_804F3628) == 0x18 ? 1 : -1];
u8 *__dt__15PSOV3EncryptionFv(u8 *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0) = &lbl_804F3628.value;
        memset(arg0 + 4, 0, 0x828);
        *(s32 *)((s8 *)arg0 + 0x82C) = 0;
        *(s32 *)((s8 *)arg0 + 0x830) = 0;
        TBoss8Dragon__sub_8036AEF8((s32 * *)arg0, 0);
        if (arg1 > 0) {
            ::operator delete((arg0));
        }
    }
    return arg0;
}
typedef char RecoveredGlobal_8036AEA4_lbl_804F3628_size[sizeof(RecoveredGlobal_8036AEA4_lbl_804F3628) == 0x18 ? 1 : -1];
s32 **__ct__15PSOV3EncryptionFv(s32 **arg0) {
    TBoss8Dragon__sub_8036AF40((arg0));
    *(s32 **)((s8 *)arg0 + 0) = &(*(RecoveredGlobal_8036AEA4_lbl_804F3628 *)&lbl_804F3628).value;
    ((VObj_0_c5c48e *)(arg0))->m2(0);
    return arg0;
}

}
