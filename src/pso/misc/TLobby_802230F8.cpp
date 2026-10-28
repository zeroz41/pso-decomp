#include "types.h"
#include "pso/protocol/protocol_types.h"
#include "pso/misc/TLobby_802230F8.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/misc/TLobby.h"

struct Rec_802231F0 { u8 b[0x18]; };

s32 TLobby::compare_version(void *arg1) {
    u32 b, a;

    a = *(u8 *)&this->m_name;
    b = *(u8 *)((s8 *)arg1 + 0);
    if (a > b) {
        return 1;
    }
    if (a == b) {
        {
            u32 b2, a2;
            a2 = *(u8 *)((s8 *)this + 1);
            b2 = *(u8 *)((s8 *)arg1 + 1);
            if (a2 > b2) {
                return 1;
            }
            if (a2 == b2) {
                if ((u8) *(u8 *)((s8 *)this + 2) > (u8) *(u8 *)((s8 *)arg1 + 2)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

s32 TLobby::compare_greater(void *arg1) {
    u8 temp_r0;
    u8 temp_r5;

    temp_r5 = *(u8 *)&this->m_name;
    temp_r0 = *(u8 *)((s8 *)arg1 + 0);
    if (temp_r5 > temp_r0) {
        return 1;
    }
    if ((temp_r5 == temp_r0) && ((u8) *(u8 *)((s8 *)this + 1) > (u8) *(u8 *)((s8 *)arg1 + 1))) {
        return 1;
    }
    return 0;
}

u32 TLobby__sub_8022318C(u8 *arg0, u8 *arg1) {
    return (u32) (*arg1 - *arg0) >> 0x1FU;
}

void TLobby::swap_item_data(s32 *arg1) {
    s32 sp8[8];

    ((TItemData *)sp8)->copy_from((TItemData *)(this));
    ((TItemData *)this)->copy_from((TItemData *)arg1);
    ((TItemData *)arg1)->copy_from((TItemData *)(sp8));
}

void TLobby::sort_records(s32 arg1, s32 arg2) {
    Rec_802231F0 *arg0 = (Rec_802231F0 *)this;
    s32 i;
    s32 j;
    for (i = 0; i < arg1 - 1; i++) {
        for (j = i + 1; j < arg1; j++) {
            switch (arg2) {
            case 0:
                if (((s32 (*)(u8 *, u8 *))TAdSinglePlyChrSelectGC__sub_8022338C)(arg0[i].b, arg0[j].b) != 0) {
                    ((TAdSinglePlyChrSelectGC *)(&arg0[i]))->swap_item_data((s32 *)&arg0[j]);
                }
                break;
            case 1:
                if (TAdSinglePlyChrSelectGC__sub_80223350(&arg0[i], &arg0[j]) != 0) {
                    ((TAdSinglePlyChrSelectGC *)(&arg0[i]))->swap_item_data((s32 *)&arg0[j]);
                }
                break;
            case 2:
                if (TLobby__sub_802232F8(&arg0[i], &arg0[j]) != 0) {
                    ((TAdSinglePlyChrSelectGC *)(&arg0[i]))->swap_item_data((s32 *)&arg0[j]);
                }
                break;
            }
        }
    }
}

s32 TLobby__sub_802232F8(void *arg0, void *arg1) {
    u32 b, a;

    a = *(u8 *)((s8 *)arg0 + 0);
    b = *(u8 *)((s8 *)arg1 + 0);
    if (a > b) {
        return 1;
    }
    if (a == b) {
        {
            u32 b2, a2;
            a2 = *(u8 *)((s8 *)arg0 + 1);
            b2 = *(u8 *)((s8 *)arg1 + 1);
            if (a2 > b2) {
                return 1;
            }
            if (a2 == b2) {
                if ((u8) *(u8 *)((s8 *)arg0 + 2) > (u8) *(u8 *)((s8 *)arg1 + 2)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

s32 TAdSinglePlyChrSelectGC__sub_80223350(void *arg0, void *arg1) {
    u8 temp_r0;
    u8 temp_r5;

    temp_r5 = *(u8 *)((s8 *)arg0 + 0);
    temp_r0 = *(u8 *)((s8 *)arg1 + 0);
    if (temp_r5 > temp_r0) {
        return 1;
    }
    if ((temp_r5 == temp_r0) && ((u8) *(u8 *)((s8 *)arg0 + 1) > (u8) *(u8 *)((s8 *)arg1 + 1))) {
        return 1;
    }
    return 0;
}

u32 TAdSinglePlyChrSelectGC__sub_8022338C(u8 *arg0, u8 *arg1) {
    return (u32) (*arg1 - *arg0) >> 0x1FU;
}
