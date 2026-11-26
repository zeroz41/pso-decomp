#include "types.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/unk/TLobby_802230F8.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/network/TLobby.h"
#include "pso/ui/city/BankItemRecord.h"

s32 TLobby::compare_version(void *other) {
    u32 b, a;

    a = *(u8 *)&this->m_name;
    b = *(u8 *)((s8 *)other + 0);
    if (a > b) {
        return 1;
    }
    if (a == b) {
        {
            u32 b2, a2;
            a2 = *(u8 *)((s8 *)this + 1);
            b2 = *(u8 *)((s8 *)other + 1);
            if (a2 > b2) {
                return 1;
            }
            if (a2 == b2) {
                if ((u8) *(u8 *)((s8 *)this + 2) > (u8) *(u8 *)((s8 *)other + 2)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

s32 TLobby::compare_greater(void *other) {
    u8 theirs;
    u8 mine;

    mine = *(u8 *)&this->m_name;
    theirs = *(u8 *)((s8 *)other + 0);
    if (mine > theirs) {
        return 1;
    }
    if ((mine == theirs) && ((u8) *(u8 *)((s8 *)this + 1) > (u8) *(u8 *)((s8 *)other + 1))) {
        return 1;
    }
    return 0;
}

u32 TLobby__sub_8022318C(u8 *a, u8 *b) {
    return (u32) (*b - *a) >> 0x1FU;
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

s32 TLobby__sub_802232F8(void *lhs, void *rhs) {
    u32 b, a;

    a = *(u8 *)((s8 *)lhs + 0);
    b = *(u8 *)((s8 *)rhs + 0);
    if (a > b) {
        return 1;
    }
    if (a == b) {
        {
            u32 b2, a2;
            a2 = *(u8 *)((s8 *)lhs + 1);
            b2 = *(u8 *)((s8 *)rhs + 1);
            if (a2 > b2) {
                return 1;
            }
            if (a2 == b2) {
                if ((u8) *(u8 *)((s8 *)lhs + 2) > (u8) *(u8 *)((s8 *)rhs + 2)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

s32 TAdSinglePlyChrSelectGC__sub_80223350(void *lhs, void *rhs) {
    u8 rhs_major;
    u8 lhs_major;

    lhs_major = *(u8 *)((s8 *)lhs + 0);
    rhs_major = *(u8 *)((s8 *)rhs + 0);
    if (lhs_major > rhs_major) {
        return 1;
    }
    if ((lhs_major == rhs_major) && ((u8) *(u8 *)((s8 *)lhs + 1) > (u8) *(u8 *)((s8 *)rhs + 1))) {
        return 1;
    }
    return 0;
}

u32 TAdSinglePlyChrSelectGC__sub_8022338C(u8 *a, u8 *b) {
    return (u32) (*b - *a) >> 0x1FU;
}
