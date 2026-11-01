#include "types.h"
#include "pso/unk/text_80268384.h"

struct VBase_18_2ead46 { char pad[0x18]; };

struct VObj_18_2ead46 : VBase_18_2ead46 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual s32 m4(s32, s16);
};

struct RecoveredGlobal_80268384_lbl_804D0618 {
    s32 value;
    u8 remaining[0x1C];
};

struct RecoveredGlobal_802683F4_lbl_804D0604 {
    s32 value;
    u8 remaining[0x10];
};

struct RecoveredGlobal_802683F4_lbl_804D0618 {
    s32 value;
    u8 remaining[0x1C];
};

extern "C" {
s32 construct_with_parent__15TWindowAdditionFPv(void *, void *, void *, void *);
extern RecoveredGlobal_80268384_lbl_804D0618 lbl_804D0618;
extern RecoveredGlobal_802683F4_lbl_804D0604 lbl_804D0604;
typedef char RecoveredGlobal_80268384_lbl_804D0618_size[sizeof(RecoveredGlobal_80268384_lbl_804D0618) == 0x20 ? 1 : -1];
u8 *fn_80268384(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    construct_with_parent__15TWindowAdditionFPv((void *)arg0, (void *)arg4, (void *)arg3, (void *)arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = &lbl_804D0618.value;
    ((VObj_18_2ead46 *)(arg0))->m4(arg2, (s16) arg3);
    return arg0;
}
typedef char RecoveredGlobal_802683F4_lbl_804D0604_size[sizeof(RecoveredGlobal_802683F4_lbl_804D0604) == 0x14 ? 1 : -1];
typedef char RecoveredGlobal_802683F4_lbl_804D0618_size[sizeof(RecoveredGlobal_802683F4_lbl_804D0618) == 0x20 ? 1 : -1];
u8 *fn_802683F4(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    construct_with_parent__15TWindowAdditionFPv((void *)arg0, &lbl_804D0604.value, (void *)arg3, (void *)arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_802683F4_lbl_804D0618 *)&lbl_804D0618).value;
    ((VObj_18_2ead46 *)(arg0))->m4(arg2, (s16) arg3);
    return arg0;
}

}
