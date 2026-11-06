#include "types.h"
#include "pso/ui/frontend/TAdPlayerLoadGC_803F18B8.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"

struct S_803F3328 { u8 pad0[4]; s32 state; u8 card[0x80]; };
typedef struct Slot_803F3478 {
    s32 f0;
    char name[0x20];
    char name2[0x20];
    s32 f44;
    s32 f48;
    s32 f4C;
    s32 f50;
    s32 f54;
    s32 f58;
    s32 f5C;
    s32 f60;
    u8 f64;
    u8 pad65[3];
} Slot_803F3478;
typedef Slot_803F3478 Slot_803F1CC4, Slot_803F1E90, Slot_803F2058;

extern "C" {
extern s32 lbl_805D7940;
s32 memset(void *, int, int);
s32 CARDClose(void *);
void *CARDGetDiskID(s32);
s32 CARDSetDiskID(s32, void *);
s32 CARDGetResultCode(s32);
s32 CARDSetAttributesAsync(s32, s32, u8, void *);
s32 CARDDeleteAsync(s32, const char *, void *);
s32 CARDRenameAsync(s32, const char *, const char *, void *);
void *memcpy(void *, const void *, u32);
extern void *lbl_805D7950;
extern u8 lbl_805E10EC[4];
extern u8 lbl_805E10F4[2];
u8 lbl_805A28C0[0x20];
Slot_803F3478 TAdPlayerLoadGC__load_request_slots[2];
S_803F3328 lbl_805A29B0[100];
u8 lbl_805A5ED0[0x30];

extern s32 player_load_channel_flags;

s32 TAdPlayerLoadGC::get_or_set_channel_flag(s32 arg0, s32 arg1) {
    if (((arg0 != 0) && (arg0 != 1)) || (arg1 < 0) || (arg1 > 2)) {
        return 0;
    }
    if (arg1 != 2) {
        (&player_load_channel_flags)[arg0] = arg1;
    }
    return (&player_load_channel_flags)[arg0];
}

s32 TAdPlayerLoadGC::get_load_state() {
    return lbl_805D7940;
}
#pragma push
#pragma opt_propagation off
void TAdPlayerLoadGC::step_set_attributes(s32 card_channel) {
    s32 *st;
    st = (s32 *)(lbl_805A28C0 + card_channel * 0x68);
    st += 0x1A;

    switch (*st) {

    case 0x11:
        if (TAdPlayerLoadGC::get_or_set_channel_flag(card_channel, 2) == 1) {
            lbl_805D7950 = CARDGetDiskID(card_channel);
            memcpy(lbl_805A28C0, lbl_805D7950, 0x20);
            memcpy(lbl_805A28C0, lbl_805E10EC, 4);
            memcpy(lbl_805A28C0 + 4, lbl_805E10F4, 2);
            CARDSetDiskID(card_channel, lbl_805A28C0);
        }
        TAdPlayerLoadGC__load_request_slots[card_channel].f5C = CARDSetAttributesAsync(card_channel, TAdPlayerLoadGC__load_request_slots[card_channel].f60, TAdPlayerLoadGC__load_request_slots[card_channel].f64, 0);
        if (TAdPlayerLoadGC__load_request_slots[card_channel].f5C < 0) {
            if (TAdPlayerLoadGC::get_or_set_channel_flag(card_channel, 2) == 1 && lbl_805D7950 != NULL) {
                CARDSetDiskID(card_channel, lbl_805D7950);
            }
            TAdPlayerLoadGC__load_request_slots[card_channel].f58 = -0xD4;
            *st = 0x18;
            break;
        }
        *st = 0x12;
    case 0x12:
        TAdPlayerLoadGC__load_request_slots[card_channel].f5C = CARDGetResultCode(card_channel);
        if (TAdPlayerLoadGC__load_request_slots[card_channel].f5C == 0) {
            if (TAdPlayerLoadGC::get_or_set_channel_flag(card_channel, 2) == 1 && lbl_805D7950 != NULL) {
                CARDSetDiskID(card_channel, lbl_805D7950);
            }
            TAdPlayerLoadGC__load_request_slots[card_channel].f58 = 0;
            *st = 0x16;
        } else if (TAdPlayerLoadGC__load_request_slots[card_channel].f5C != -1) {
            if (TAdPlayerLoadGC::get_or_set_channel_flag(card_channel, 2) == 1 && lbl_805D7950 != NULL) {
                CARDSetDiskID(card_channel, lbl_805D7950);
            }
            TAdPlayerLoadGC__load_request_slots[card_channel].f58 = -0xD4;
            *st = 0x18;
        }
        break;
    case 0x13: case 0x14: case 0x15: case 0x16: case 0x17: case 0x18:
        return;
    }
}
#pragma pop
#pragma push
#pragma opt_propagation off
void TAdPlayerLoadGC::update_card_delete(s32 card_channel) {
    s32 *st;
    Slot_803F1E90 *s;
    st = (s32 *)(lbl_805A28C0 + card_channel * 0x68);
    st += 0x1A;

    switch (*st) {
    case 0xF:
        if (TAdPlayerLoadGC::get_or_set_channel_flag(card_channel, 2) == 1) {
            lbl_805D7950 = CARDGetDiskID(card_channel);
            memcpy(lbl_805A28C0, lbl_805D7950, 0x20);
            memcpy(lbl_805A28C0, lbl_805E10EC, 4);
            memcpy(lbl_805A28C0 + 4, lbl_805E10F4, 2);
            CARDSetDiskID(card_channel, lbl_805A28C0);
        }
        TAdPlayerLoadGC__load_request_slots[card_channel].f5C = CARDDeleteAsync(card_channel, TAdPlayerLoadGC__load_request_slots[card_channel].name, 0);
        if (TAdPlayerLoadGC__load_request_slots[card_channel].f5C < 0) {
            if (TAdPlayerLoadGC::get_or_set_channel_flag(card_channel, 2) == 1 && lbl_805D7950 != NULL) {
                CARDSetDiskID(card_channel, lbl_805D7950);
            }
            TAdPlayerLoadGC__load_request_slots[card_channel].f58 = -0xD3;
            *st = 0x18;
            break;
        }
        *st = 0x10;
    case 0x10:
        TAdPlayerLoadGC__load_request_slots[card_channel].f5C = CARDGetResultCode(card_channel);
        if (TAdPlayerLoadGC__load_request_slots[card_channel].f5C == 0) {
            if (TAdPlayerLoadGC::get_or_set_channel_flag(card_channel, 2) == 1 && lbl_805D7950 != NULL) {
                CARDSetDiskID(card_channel, lbl_805D7950);
            }
            TAdPlayerLoadGC__load_request_slots[card_channel].f58 = 0;
            *st = 0x16;
        } else if (TAdPlayerLoadGC__load_request_slots[card_channel].f5C != -1) {
            if (TAdPlayerLoadGC::get_or_set_channel_flag(card_channel, 2) == 1 && lbl_805D7950 != NULL) {
                CARDSetDiskID(card_channel, lbl_805D7950);
            }
            TAdPlayerLoadGC__load_request_slots[card_channel].f58 = -0xD3;
            *st = 0x18;
        }
        break;
    case 0x11: case 0x12: case 0x13: case 0x14: case 0x15: case 0x16: case 0x17: case 0x18:
        return;
    }
}
#pragma pop
#pragma push
#pragma opt_propagation off
void TAdPlayerLoadGC::update_card_rename(s32 card_channel) {
    s32 *st;
    s32 off;
    off = card_channel * 0x68;
    st = (s32 *)(lbl_805A28C0 + off);
    st += 0x1A;

    switch (*st) {
    case 0xd:
        if (TAdPlayerLoadGC::get_or_set_channel_flag(card_channel, 2) == 1) {
            lbl_805D7950 = CARDGetDiskID(card_channel);
            memcpy(lbl_805A28C0, lbl_805D7950, 0x20);
            memcpy(lbl_805A28C0, lbl_805E10EC, 4);
            memcpy(lbl_805A28C0 + 4, lbl_805E10F4, 2);
            CARDSetDiskID(card_channel, lbl_805A28C0);
        }
        TAdPlayerLoadGC__load_request_slots[card_channel].f5C = CARDRenameAsync(card_channel, TAdPlayerLoadGC__load_request_slots[card_channel].name, TAdPlayerLoadGC__load_request_slots[card_channel].name2, 0);
        if (TAdPlayerLoadGC__load_request_slots[card_channel].f5C < 0) {
            if (TAdPlayerLoadGC::get_or_set_channel_flag(card_channel, 2) == 1 && lbl_805D7950 != NULL) {
                CARDSetDiskID(card_channel, lbl_805D7950);
            }
            TAdPlayerLoadGC__load_request_slots[card_channel].f58 = -210;
            *st = 0x18;
            break;
        }
        *st = 0xe;
    case 0xe:
        TAdPlayerLoadGC__load_request_slots[card_channel].f5C = CARDGetResultCode(card_channel);
        if (TAdPlayerLoadGC__load_request_slots[card_channel].f5C == 0) {
            if (TAdPlayerLoadGC::get_or_set_channel_flag(card_channel, 2) == 1 && lbl_805D7950 != NULL) {
                CARDSetDiskID(card_channel, lbl_805D7950);
            }
            TAdPlayerLoadGC__load_request_slots[card_channel].f58 = 0;
            *st = 0x16;
        } else if (TAdPlayerLoadGC__load_request_slots[card_channel].f5C != -1) {
            if (TAdPlayerLoadGC::get_or_set_channel_flag(card_channel, 2) == 1 && lbl_805D7950 != NULL) {
                CARDSetDiskID(card_channel, lbl_805D7950);
            }
            TAdPlayerLoadGC__load_request_slots[card_channel].f58 = -210;
            *st = 0x18;
        }
        break;
    case 0xf: case 0x10: case 0x11: case 0x12: case 0x13: case 0x14: case 0x15: case 0x16: case 0x17: case 0x18:
        return;
    }
}
#pragma pop
void TAdPlayerLoadGC__sub_803F2CD0(s32 card_channel, s32 result) {
    TAdPlayerLoadGC__load_request_slots[card_channel].f5C = result;
    switch (result) {
    default:
        TAdPlayerLoadGC__load_request_slots[card_channel].f58 = -201;
        TAdPlayerLoadGC__load_request_slots[card_channel].f48 = 0x18;
        break;
    case 0:
    case -6:
        TAdPlayerLoadGC__load_request_slots[card_channel].f48 = 5;
        break;
    }
}

struct CardInfo_803F31D8 { s32 state; s32 f4; u32 sector_size; };
s32 CARDMountAsync(s32, void *, void *, void *);
s32 CARDCheckAsync(s32, void (*)(s32, s32));
s32 CARDGetSectorSize(s32, u32 *);
s32 CARDUnmount(s32);
extern void *lbl_805D7960;

#pragma push
#pragma opt_propagation off
void TAdPlayerLoadGC__sub_803F2D20(s32 card_channel) {
    s32 *st;
    st = (s32 *)(lbl_805A28C0 + card_channel * 0x68);
    st += 0x1A;

    switch (*st) {
    case 1:
        TAdPlayerLoadGC__load_request_slots[card_channel].f5C = CARDMountAsync(card_channel, lbl_805D7960, 0, 0);
        if (TAdPlayerLoadGC__load_request_slots[card_channel].f5C < 0) {
            TAdPlayerLoadGC__load_request_slots[card_channel].f58 = -200;
            *st = 0x18;
            break;
        }
        *st = 2;
    case 2:
        TAdPlayerLoadGC__load_request_slots[card_channel].f5C = CARDGetResultCode(card_channel);
        if (TAdPlayerLoadGC__load_request_slots[card_channel].f5C == 0 || TAdPlayerLoadGC__load_request_slots[card_channel].f5C == -6) {
            *st = 3;
        } else {
            if (TAdPlayerLoadGC__load_request_slots[card_channel].f5C != -1) {
                TAdPlayerLoadGC__load_request_slots[card_channel].f58 = -200;
                *st = 0x18;
            }
            break;
        }
    case 3:
        TAdPlayerLoadGC__load_request_slots[card_channel].f5C = CARDCheckAsync(card_channel, TAdPlayerLoadGC__sub_803F2CD0);
        if (TAdPlayerLoadGC__load_request_slots[card_channel].f5C < 0) {
            TAdPlayerLoadGC__load_request_slots[card_channel].f58 = -201;
            *st = 0x18;
            break;
        }
        *st = 4;
    case 4:
        TAdPlayerLoadGC__load_request_slots[card_channel].f5C = CARDGetResultCode(card_channel);
        if (TAdPlayerLoadGC__load_request_slots[card_channel].f5C == 0) {
            *st = 5;
        } else {
            if (TAdPlayerLoadGC__load_request_slots[card_channel].f5C != -1) {
                TAdPlayerLoadGC__load_request_slots[card_channel].f58 = -201;
                *st = 0x18;
                CARDUnmount(card_channel);
            }
            break;
        }
    case 5:
        TAdPlayerLoadGC__load_request_slots[card_channel].f5C = CARDGetSectorSize(card_channel, &((CardInfo_803F31D8 *)lbl_805A5ED0)[card_channel].sector_size);
        if (TAdPlayerLoadGC__load_request_slots[card_channel].f5C < 0) {
            TAdPlayerLoadGC__load_request_slots[card_channel].f58 = -202;
            *st = 0x18;
            CARDUnmount(card_channel);
            break;
        }
        TAdPlayerLoadGC__load_request_slots[card_channel].f58 = 0;
        *st = 0x16;
        break;
    case 0: case 6: case 7: case 8: case 9: case 0xA: case 0xB: case 0xC:
    case 0xD: case 0xE: case 0xF: case 0x10: case 0x11: case 0x12: case 0x13: case 0x14: case 0x15: case 0x16: case 0x17: case 0x18:
        return;
    }
}
#pragma pop

s32 TAdPlayerLoadGC__sub_803F31BC(void) {
    if (lbl_805D7940 == 0) {
        return -1;
    }
    return 0;
}

void TAdPlayerLoadGC::reset_slot_entry(s32 arg0) {
    u8 *temp_r30;
    temp_r30 = (u8 *)TAdPlayerLoadGC__load_request_slots + (arg0 * 0x68);
    *(s32 *)((s8 *)temp_r30 + 0) = 0;
    memset(temp_r30 + 4, 0, 0x20);
    memset(temp_r30 + 0x24, 0, 0x20);
    *(s32 *)((s8 *)temp_r30 + 0x44) = 0;
    *(s32 *)((s8 *)temp_r30 + 0x48) = 0;
    *(s32 *)((s8 *)temp_r30 + 0x4C) = 0;
    *(s32 *)((s8 *)temp_r30 + 0x50) = 0;
    *(s32 *)((s8 *)temp_r30 + 0x54) = -1;
    *(s32 *)((s8 *)temp_r30 + 0x58) = 0;
    *(s32 *)((s8 *)temp_r30 + 0x5C) = 0;
}

s32 TAdPlayerLoadGC::close_card_slot(s32 arg0) {
    S_803F3328 *s;
    s32 ret;
    if (arg0 >= 0 && arg0 < 0x64) {
        s = &lbl_805A29B0[arg0];
        ret = CARDClose(s->card);
        memset(s, 0, 0x88);
        s->state = 2;
    }
    return ret;
}

}
