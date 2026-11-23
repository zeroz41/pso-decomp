#include "types.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/unk/TLobby_802230F8.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/city/BankItemRecord.h"

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

void TLobby::swap_item_data(s32 *item_data) {
    s32 src[8];

    ((TItemData *)src)->copy_from((TItemData *)(this));
    ((TItemData *)this)->copy_from((TItemData *)item_data);
    ((TItemData *)item_data)->copy_from((TItemData *)(src));
}

void BankItemRecord::sort_records(s32 count, s32 key) {
    s32 i;
    s32 j;
    for (i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            switch (key) {
            case 0:
                if (((s32 (*)(u8 *, u8 *))TAdSinglePlyChrSelectGC__sub_8022338C)(this[i].item.data1.data_u8, this[j].item.data1.data_u8) != 0) {
                    this[i].swap_item_data(&this[j]);
                }
                break;
            case 1:
                if (TAdSinglePlyChrSelectGC__sub_80223350(&this[i], &this[j]) != 0) {
                    this[i].swap_item_data(&this[j]);
                }
                break;
            case 2:
                if (TLobby__sub_802232F8(&this[i], &this[j]) != 0) {
                    this[i].swap_item_data(&this[j]);
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
