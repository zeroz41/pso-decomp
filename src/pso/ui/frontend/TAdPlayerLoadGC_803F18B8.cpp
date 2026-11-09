#include "types.h"
#include <string.h>
#include <stdio.h>
#include "pso/ui/frontend/TAdPlayerLoadGC_803F18B8.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "dolphin/os.h"
#include "dolphin/card.h"

struct S_803F3328 { u8 pad0[4]; s32 state; CARDFileInfo file_info; CARDStat stat; };
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
// Per-slot card state: the last CARDProbeEx result and the sizes it reported.
struct CardInfo_803F31D8 { s32 state; s32 mem_size; s32 sector_size; };

extern "C" {
extern s32 lbl_805D7940;
void *CARDGetDiskID(s32);
s32 CARDSetDiskID(s32, void *);
extern void *lbl_805D7950;
extern u8 lbl_805E10EC[4];
extern u8 lbl_805E10F4[2];
u8 lbl_805A28C0[0x20];
Slot_803F3478 TAdPlayerLoadGC__load_request_slots[2];
S_803F3328 lbl_805A29B0[100];
CardInfo_803F31D8 lbl_805A5ED0[4];

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
extern void *lbl_805D7960;
// "%4d/%02d/%02d %02d:%02d:%02d" (.rodata, outside this unit's split)
extern const char lbl_8047FD08[];
void TAdPlayerLoadGC__sub_803F1908(s32 card_channel) {
    u8 *disk_id;
    s32 i;
    s32 found;
    CARDStat stat;
    u8 company[2];
    u8 game_name[4];
    OSCalendarTime ct;
    char date[0x20];

    switch (TAdPlayerLoadGC__load_request_slots[card_channel].f48) {
    case 1:
        TAdPlayerLoadGC__load_request_slots[card_channel].f5C = CARDMountAsync(card_channel, lbl_805D7960, 0, 0);
        if (TAdPlayerLoadGC__load_request_slots[card_channel].f5C < 0) {
            TAdPlayerLoadGC__load_request_slots[card_channel].f58 = -200;
            TAdPlayerLoadGC__load_request_slots[card_channel].f48 = 0x18;
            break;
        }
        TAdPlayerLoadGC__load_request_slots[card_channel].f48 = 2;
    case 2:
        TAdPlayerLoadGC__load_request_slots[card_channel].f5C = CARDGetResultCode(card_channel);
        if (TAdPlayerLoadGC__load_request_slots[card_channel].f5C == 0 || TAdPlayerLoadGC__load_request_slots[card_channel].f5C == -6) {
            TAdPlayerLoadGC__load_request_slots[card_channel].f48 = 3;
        } else {
            if (TAdPlayerLoadGC__load_request_slots[card_channel].f5C != -1) {
                TAdPlayerLoadGC__load_request_slots[card_channel].f58 = -200;
                TAdPlayerLoadGC__load_request_slots[card_channel].f48 = 0x18;
            }
            break;
        }
    case 3:
        TAdPlayerLoadGC__load_request_slots[card_channel].f5C = CARDCheckAsync(card_channel, 0);
        if (TAdPlayerLoadGC__load_request_slots[card_channel].f5C < 0) {
            TAdPlayerLoadGC__load_request_slots[card_channel].f58 = -201;
            TAdPlayerLoadGC__load_request_slots[card_channel].f48 = 0x18;
            break;
        }
        TAdPlayerLoadGC__load_request_slots[card_channel].f48 = 4;
    case 4:
        TAdPlayerLoadGC__load_request_slots[card_channel].f5C = CARDGetResultCode(card_channel);
        if (TAdPlayerLoadGC__load_request_slots[card_channel].f5C == 0) {
            TAdPlayerLoadGC__load_request_slots[card_channel].f48 = 5;
        } else {
            if (TAdPlayerLoadGC__load_request_slots[card_channel].f5C != -1) {
                TAdPlayerLoadGC__load_request_slots[card_channel].f58 = -201;
                TAdPlayerLoadGC__load_request_slots[card_channel].f48 = 0x18;
                CARDUnmount(card_channel);
            }
            break;
        }
    case 5:
        TAdPlayerLoadGC__load_request_slots[card_channel].f5C = CARDGetSectorSize(card_channel, (u32 *)&lbl_805A5ED0[card_channel].sector_size);
        if (TAdPlayerLoadGC__load_request_slots[card_channel].f5C < 0) {
            TAdPlayerLoadGC__load_request_slots[card_channel].f58 = -202;
            TAdPlayerLoadGC__load_request_slots[card_channel].f48 = 0x18;
        } else {
            if (TAdPlayerLoadGC::get_or_set_channel_flag(card_channel, 2) == 1) {
                lbl_805D7950 = CARDGetDiskID(card_channel);
                memcpy(lbl_805A28C0, lbl_805D7950, 0x20);
                memcpy(lbl_805A28C0, lbl_805E10EC, 4);
                memcpy(lbl_805A28C0 + 4, lbl_805E10F4, 2);
                CARDSetDiskID(card_channel, lbl_805A28C0);
            }
            if (TAdPlayerLoadGC::get_or_set_channel_flag(card_channel, 2) != 1) {
                disk_id = (u8 *)CARDGetDiskID(card_channel);
                memcpy(game_name, disk_id, 4);
                memcpy(company, disk_id + 4, 2);
            } else {
                memcpy(game_name, lbl_805E10EC, 4);
                memcpy(company, lbl_805E10F4, 2);
            }
            found = 0;
            for (i = 0; i < 127; i++) {
                if (CARDGetStatus(card_channel, i, &stat) >= 0) {
                    OSTicksToCalendarTime(stat.time * (__OSBusClock / 4), &ct);
                    sprintf(date, lbl_8047FD08, ct.year, ct.mon + 1, ct.mday, ct.hour, ct.min, ct.sec);
                    if (strcmp(stat.fileName, TAdPlayerLoadGC__load_request_slots[card_channel].name) == 0 &&
                        memcmp(stat.gameName, game_name, 4) == 0 && memcmp(stat.company, company, 2) == 0) {
                        found = 1;
                        break;
                    }
                }
            }
            if (TAdPlayerLoadGC::get_or_set_channel_flag(card_channel, 2) == 1 && lbl_805D7950 != NULL) {
                CARDSetDiskID(card_channel, lbl_805D7950);
            }
            if (found == 0) {
                TAdPlayerLoadGC__load_request_slots[card_channel].f58 = -102;
            } else {
                TAdPlayerLoadGC__load_request_slots[card_channel].f58 = 0;
            }
            TAdPlayerLoadGC__load_request_slots[card_channel].f48 = 0x16;
        }
        CARDUnmount(card_channel);
        break;
    case 0: case 6: case 7: case 8: case 9: case 0xA: case 0xB: case 0xC:
    case 0xD: case 0xE: case 0xF: case 0x10: case 0x11: case 0x12: case 0x13: case 0x14: case 0x15: case 0x16: case 0x17: case 0x18:
        return;
    }
}

void TAdPlayerLoadGC::step_set_attributes(s32 card_channel) {

    switch (TAdPlayerLoadGC__load_request_slots[card_channel].f48) {

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
            TAdPlayerLoadGC__load_request_slots[card_channel].f48 = 0x18;
            break;
        }
        TAdPlayerLoadGC__load_request_slots[card_channel].f48 = 0x12;
    case 0x12:
        TAdPlayerLoadGC__load_request_slots[card_channel].f5C = CARDGetResultCode(card_channel);
        if (TAdPlayerLoadGC__load_request_slots[card_channel].f5C == 0) {
            if (TAdPlayerLoadGC::get_or_set_channel_flag(card_channel, 2) == 1 && lbl_805D7950 != NULL) {
                CARDSetDiskID(card_channel, lbl_805D7950);
            }
            TAdPlayerLoadGC__load_request_slots[card_channel].f58 = 0;
            TAdPlayerLoadGC__load_request_slots[card_channel].f48 = 0x16;
        } else if (TAdPlayerLoadGC__load_request_slots[card_channel].f5C != -1) {
            if (TAdPlayerLoadGC::get_or_set_channel_flag(card_channel, 2) == 1 && lbl_805D7950 != NULL) {
                CARDSetDiskID(card_channel, lbl_805D7950);
            }
            TAdPlayerLoadGC__load_request_slots[card_channel].f58 = -0xD4;
            TAdPlayerLoadGC__load_request_slots[card_channel].f48 = 0x18;
        }
        break;
    case 0x13: case 0x14: case 0x15: case 0x16: case 0x17: case 0x18:
        return;
    }
}
void TAdPlayerLoadGC::update_card_delete(s32 card_channel) {
    Slot_803F1E90 *s;

    switch (TAdPlayerLoadGC__load_request_slots[card_channel].f48) {
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
            TAdPlayerLoadGC__load_request_slots[card_channel].f48 = 0x18;
            break;
        }
        TAdPlayerLoadGC__load_request_slots[card_channel].f48 = 0x10;
    case 0x10:
        TAdPlayerLoadGC__load_request_slots[card_channel].f5C = CARDGetResultCode(card_channel);
        if (TAdPlayerLoadGC__load_request_slots[card_channel].f5C == 0) {
            if (TAdPlayerLoadGC::get_or_set_channel_flag(card_channel, 2) == 1 && lbl_805D7950 != NULL) {
                CARDSetDiskID(card_channel, lbl_805D7950);
            }
            TAdPlayerLoadGC__load_request_slots[card_channel].f58 = 0;
            TAdPlayerLoadGC__load_request_slots[card_channel].f48 = 0x16;
        } else if (TAdPlayerLoadGC__load_request_slots[card_channel].f5C != -1) {
            if (TAdPlayerLoadGC::get_or_set_channel_flag(card_channel, 2) == 1 && lbl_805D7950 != NULL) {
                CARDSetDiskID(card_channel, lbl_805D7950);
            }
            TAdPlayerLoadGC__load_request_slots[card_channel].f58 = -0xD3;
            TAdPlayerLoadGC__load_request_slots[card_channel].f48 = 0x18;
        }
        break;
    case 0x11: case 0x12: case 0x13: case 0x14: case 0x15: case 0x16: case 0x17: case 0x18:
        return;
    }
}
void TAdPlayerLoadGC::update_card_rename(s32 card_channel) {

    switch (TAdPlayerLoadGC__load_request_slots[card_channel].f48) {
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
            TAdPlayerLoadGC__load_request_slots[card_channel].f48 = 0x18;
            break;
        }
        TAdPlayerLoadGC__load_request_slots[card_channel].f48 = 0xe;
    case 0xe:
        TAdPlayerLoadGC__load_request_slots[card_channel].f5C = CARDGetResultCode(card_channel);
        if (TAdPlayerLoadGC__load_request_slots[card_channel].f5C == 0) {
            if (TAdPlayerLoadGC::get_or_set_channel_flag(card_channel, 2) == 1 && lbl_805D7950 != NULL) {
                CARDSetDiskID(card_channel, lbl_805D7950);
            }
            TAdPlayerLoadGC__load_request_slots[card_channel].f58 = 0;
            TAdPlayerLoadGC__load_request_slots[card_channel].f48 = 0x16;
        } else if (TAdPlayerLoadGC__load_request_slots[card_channel].f5C != -1) {
            if (TAdPlayerLoadGC::get_or_set_channel_flag(card_channel, 2) == 1 && lbl_805D7950 != NULL) {
                CARDSetDiskID(card_channel, lbl_805D7950);
            }
            TAdPlayerLoadGC__load_request_slots[card_channel].f58 = -210;
            TAdPlayerLoadGC__load_request_slots[card_channel].f48 = 0x18;
        }
        break;
    case 0xf: case 0x10: case 0x11: case 0x12: case 0x13: case 0x14: case 0x15: case 0x16: case 0x17: case 0x18:
        return;
    }
}
void TAdPlayerLoadGC__sub_803F2240(s32 file) {
    switch (TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f48) {
    case 11:
        s32 chan = lbl_805A29B0[file].state;
        if (TAdPlayerLoadGC::get_or_set_channel_flag(chan, 2) == 1) {
            lbl_805D7950 = CARDGetDiskID(chan);
            memcpy(lbl_805A28C0, lbl_805D7950, 0x20);
            memcpy(lbl_805A28C0, lbl_805E10EC, 4);
            memcpy(lbl_805A28C0 + 4, lbl_805E10F4, 2);
            CARDSetDiskID(chan, lbl_805A28C0);
        }
        TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f5C = CARDWriteAsync(&lbl_805A29B0[file].file_info, (void *)TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f0, TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f50, TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f4C, 0);
        if (TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f5C < 0) {
            s32 ch = lbl_805A29B0[file].state;
            if (TAdPlayerLoadGC::get_or_set_channel_flag(ch, 2) == 1 && lbl_805D7950 != NULL) {
                CARDSetDiskID(ch, lbl_805D7950);
            }
            TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f58 = -206;
            TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f48 = 0x18;
            break;
        }
        TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f48 = 12;
    case 12:
        TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f5C = CARDGetResultCode(lbl_805A29B0[file].state);
        if (TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f5C == 0) {
            s32 ch = lbl_805A29B0[file].state;
            if (TAdPlayerLoadGC::get_or_set_channel_flag(ch, 2) == 1 && lbl_805D7950 != NULL) {
                CARDSetDiskID(ch, lbl_805D7950);
            }
            TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f48 = 20;
        } else {
            if (TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f5C != -1) {
                s32 ch = lbl_805A29B0[file].state;
                if (TAdPlayerLoadGC::get_or_set_channel_flag(ch, 2) == 1 && lbl_805D7950 != NULL) {
                    CARDSetDiskID(ch, lbl_805D7950);
                }
                TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f58 = -206;
                TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f48 = 0x18;
            }
            break;
        }
    case 20:
        chan = lbl_805A29B0[file].state;
        if (TAdPlayerLoadGC::get_or_set_channel_flag(chan, 2) == 1) {
            lbl_805D7950 = CARDGetDiskID(chan);
            memcpy(lbl_805A28C0, lbl_805D7950, 0x20);
            memcpy(lbl_805A28C0, lbl_805E10EC, 4);
            memcpy(lbl_805A28C0 + 4, lbl_805E10F4, 2);
            CARDSetDiskID(chan, lbl_805A28C0);
        }
        TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f5C = CARDSetStatusAsync(lbl_805A29B0[file].state, lbl_805A29B0[file].file_info.fileNo, &lbl_805A29B0[file].stat, 0);
        if (TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f5C < 0) {
            s32 ch = lbl_805A29B0[file].state;
            if (TAdPlayerLoadGC::get_or_set_channel_flag(ch, 2) == 1 && lbl_805D7950 != NULL) {
                CARDSetDiskID(ch, lbl_805D7950);
            }
            TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f58 = -208;
            TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f48 = 0x18;
            break;
        }
        TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f48 = 21;
    case 21:
        TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f5C = CARDGetResultCode(lbl_805A29B0[file].state);
        if (TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f5C == 0) {
            s32 ch = lbl_805A29B0[file].state;
            if (TAdPlayerLoadGC::get_or_set_channel_flag(ch, 2) == 1 && lbl_805D7950 != NULL) {
                CARDSetDiskID(ch, lbl_805D7950);
            }
            TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f58 = 0;
            TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f48 = 0x16;
        } else if (TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f5C != -1) {
            s32 ch = lbl_805A29B0[file].state;
            if (TAdPlayerLoadGC::get_or_set_channel_flag(ch, 2) == 1 && lbl_805D7950 != NULL) {
                CARDSetDiskID(ch, lbl_805D7950);
            }
            TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f58 = -208;
            TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f48 = 0x18;
        }
        break;
    case 22: case 23: case 24:
        return;
    }
}

void TAdPlayerLoadGC__sub_803F2610(s32 file) {
    switch (TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f48) {
    case 9:
        s32 chan = lbl_805A29B0[file].state;
        if (TAdPlayerLoadGC::get_or_set_channel_flag(chan, 2) == 1) {
            lbl_805D7950 = CARDGetDiskID(chan);
            memcpy(lbl_805A28C0, lbl_805D7950, 0x20);
            memcpy(lbl_805A28C0, lbl_805E10EC, 4);
            memcpy(lbl_805A28C0 + 4, lbl_805E10F4, 2);
            CARDSetDiskID(chan, lbl_805A28C0);
        }
        TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f5C = CARDReadAsync(&lbl_805A29B0[file].file_info, (void *)TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f0, TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f50, TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f4C, 0);
        if (TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f5C < 0) {
            s32 ch = lbl_805A29B0[file].state;
            if (TAdPlayerLoadGC::get_or_set_channel_flag(ch, 2) == 1 && lbl_805D7950 != NULL) {
                CARDSetDiskID(ch, lbl_805D7950);
            }
            TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f58 = -205;
            TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f48 = 0x18;
            break;
        }
        TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f48 = 10;
    case 10:
        TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f5C = CARDGetResultCode(lbl_805A29B0[file].state);
        if (TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f5C == 0) {
            s32 ch = lbl_805A29B0[file].state;
            if (TAdPlayerLoadGC::get_or_set_channel_flag(ch, 2) == 1 && lbl_805D7950 != NULL) {
                CARDSetDiskID(ch, lbl_805D7950);
            }
            TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f58 = 0;
            TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f48 = 0x16;
        } else if (TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f5C != -1) {
            s32 ch = lbl_805A29B0[file].state;
            if (TAdPlayerLoadGC::get_or_set_channel_flag(ch, 2) == 1 && lbl_805D7950 != NULL) {
                CARDSetDiskID(ch, lbl_805D7950);
            }
            TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f58 = -205;
            TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f48 = 0x18;
        }
        break;
    case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19: case 20: case 21: case 22: case 23: case 24:
        return;
    }
}

void TAdPlayerLoadGC__sub_803F282C(s32 file) {
    switch (TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f48) {
    case 8:
        s32 chan = lbl_805A29B0[file].state;
        if (TAdPlayerLoadGC::get_or_set_channel_flag(chan, 2) == 1) {
            lbl_805D7950 = CARDGetDiskID(chan);
            memcpy(lbl_805A28C0, lbl_805D7950, 0x20);
            memcpy(lbl_805A28C0, lbl_805E10EC, 4);
            memcpy(lbl_805A28C0 + 4, lbl_805E10F4, 2);
            CARDSetDiskID(chan, lbl_805A28C0);
        }
        TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f5C = CARDOpen(lbl_805A29B0[file].state, TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].name, &lbl_805A29B0[file].file_info);
        if (TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f5C < 0) {
            s32 ch = lbl_805A29B0[file].state;
            if (TAdPlayerLoadGC::get_or_set_channel_flag(ch, 2) == 1 && lbl_805D7950 != NULL) {
                CARDSetDiskID(ch, lbl_805D7950);
            }
            TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f58 = -204;
            TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f48 = 0x18;
            break;
        }
        TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f48 = 19;
    case 19:
        TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f5C = CARDGetStatus(lbl_805A29B0[file].state, lbl_805A29B0[file].file_info.fileNo, &lbl_805A29B0[file].stat);
        if (TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f5C < 0) {
            s32 ch = lbl_805A29B0[file].state;
            if (TAdPlayerLoadGC::get_or_set_channel_flag(ch, 2) == 1 && lbl_805D7950 != NULL) {
                CARDSetDiskID(ch, lbl_805D7950);
            }
            TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f58 = -207;
            TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f48 = 0x18;
            CARDClose(&lbl_805A29B0[file].file_info);
        } else {
            s32 ch = lbl_805A29B0[file].state;
            if (TAdPlayerLoadGC::get_or_set_channel_flag(ch, 2) == 1 && lbl_805D7950 != NULL) {
                CARDSetDiskID(ch, lbl_805D7950);
            }
            TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f58 = 0;
            TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f48 = 0x16;
        }
        break;
    case 20: case 21: case 22: case 23: case 24:
        return;
    }
}

void TAdPlayerLoadGC__sub_803F2A4C(s32 file) {
    switch (TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f48) {
    case 6:
        s32 chan = lbl_805A29B0[file].state;
        if (TAdPlayerLoadGC::get_or_set_channel_flag(chan, 2) == 1) {
            lbl_805D7950 = CARDGetDiskID(chan);
            memcpy(lbl_805A28C0, lbl_805D7950, 0x20);
            memcpy(lbl_805A28C0, lbl_805E10EC, 4);
            memcpy(lbl_805A28C0 + 4, lbl_805E10F4, 2);
            CARDSetDiskID(chan, lbl_805A28C0);
        }
        TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f5C = CARDCreateAsync(lbl_805A29B0[file].state, TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].name, TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f50, &lbl_805A29B0[file].file_info, 0);
        if (TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f5C < 0) {
            s32 ch = lbl_805A29B0[file].state;
            if (TAdPlayerLoadGC::get_or_set_channel_flag(ch, 2) == 1 && lbl_805D7950 != NULL) {
                CARDSetDiskID(ch, lbl_805D7950);
            }
            TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f58 = -203;
            TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f48 = 0x18;
            break;
        }
        TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f48 = 7;
    case 7:
        TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f5C = CARDGetResultCode(lbl_805A29B0[file].state);
        if (TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f5C == 0) {
            s32 ch = lbl_805A29B0[file].state;
            if (TAdPlayerLoadGC::get_or_set_channel_flag(ch, 2) == 1 && lbl_805D7950 != NULL) {
                CARDSetDiskID(ch, lbl_805D7950);
            }
            TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f48 = 19;
        } else {
            if (TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f5C != -1) {
                s32 ch = lbl_805A29B0[file].state;
                if (TAdPlayerLoadGC::get_or_set_channel_flag(ch, 2) == 1 && lbl_805D7950 != NULL) {
                    CARDSetDiskID(ch, lbl_805D7950);
                }
                TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f58 = -203;
                TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f48 = 0x18;
            }
            break;
        }
    case 19:
        TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f5C = CARDGetStatus(lbl_805A29B0[file].state, lbl_805A29B0[file].file_info.fileNo, &lbl_805A29B0[file].stat);
        if (TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f5C < 0) {
            TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f58 = -207;
            TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f48 = 0x18;
            CARDClose(&lbl_805A29B0[file].file_info);
        } else {
            TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f58 = 0;
            TAdPlayerLoadGC__load_request_slots[lbl_805A29B0[file].state].f48 = 0x16;
        }
        break;
    case 20: case 21: case 22: case 23: case 24:
        return;
    }
}

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


void TAdPlayerLoadGC__sub_803F2D20(s32 card_channel) {

    switch (TAdPlayerLoadGC__load_request_slots[card_channel].f48) {
    case 1:
        TAdPlayerLoadGC__load_request_slots[card_channel].f5C = CARDMountAsync(card_channel, lbl_805D7960, 0, 0);
        if (TAdPlayerLoadGC__load_request_slots[card_channel].f5C < 0) {
            TAdPlayerLoadGC__load_request_slots[card_channel].f58 = -200;
            TAdPlayerLoadGC__load_request_slots[card_channel].f48 = 0x18;
            break;
        }
        TAdPlayerLoadGC__load_request_slots[card_channel].f48 = 2;
    case 2:
        TAdPlayerLoadGC__load_request_slots[card_channel].f5C = CARDGetResultCode(card_channel);
        if (TAdPlayerLoadGC__load_request_slots[card_channel].f5C == 0 || TAdPlayerLoadGC__load_request_slots[card_channel].f5C == -6) {
            TAdPlayerLoadGC__load_request_slots[card_channel].f48 = 3;
        } else {
            if (TAdPlayerLoadGC__load_request_slots[card_channel].f5C != -1) {
                TAdPlayerLoadGC__load_request_slots[card_channel].f58 = -200;
                TAdPlayerLoadGC__load_request_slots[card_channel].f48 = 0x18;
            }
            break;
        }
    case 3:
        TAdPlayerLoadGC__load_request_slots[card_channel].f5C = CARDCheckAsync(card_channel, TAdPlayerLoadGC__sub_803F2CD0);
        if (TAdPlayerLoadGC__load_request_slots[card_channel].f5C < 0) {
            TAdPlayerLoadGC__load_request_slots[card_channel].f58 = -201;
            TAdPlayerLoadGC__load_request_slots[card_channel].f48 = 0x18;
            break;
        }
        TAdPlayerLoadGC__load_request_slots[card_channel].f48 = 4;
    case 4:
        TAdPlayerLoadGC__load_request_slots[card_channel].f5C = CARDGetResultCode(card_channel);
        if (TAdPlayerLoadGC__load_request_slots[card_channel].f5C == 0) {
            TAdPlayerLoadGC__load_request_slots[card_channel].f48 = 5;
        } else {
            if (TAdPlayerLoadGC__load_request_slots[card_channel].f5C != -1) {
                TAdPlayerLoadGC__load_request_slots[card_channel].f58 = -201;
                TAdPlayerLoadGC__load_request_slots[card_channel].f48 = 0x18;
                CARDUnmount(card_channel);
            }
            break;
        }
    case 5:
        TAdPlayerLoadGC__load_request_slots[card_channel].f5C = CARDGetSectorSize(card_channel, (u32 *)&lbl_805A5ED0[card_channel].sector_size);
        if (TAdPlayerLoadGC__load_request_slots[card_channel].f5C < 0) {
            TAdPlayerLoadGC__load_request_slots[card_channel].f58 = -202;
            TAdPlayerLoadGC__load_request_slots[card_channel].f48 = 0x18;
            CARDUnmount(card_channel);
            break;
        }
        TAdPlayerLoadGC__load_request_slots[card_channel].f58 = 0;
        TAdPlayerLoadGC__load_request_slots[card_channel].f48 = 0x16;
        break;
    case 0: case 6: case 7: case 8: case 9: case 0xA: case 0xB: case 0xC:
    case 0xD: case 0xE: case 0xF: case 0x10: case 0x11: case 0x12: case 0x13: case 0x14: case 0x15: case 0x16: case 0x17: case 0x18:
        return;
    }
}

extern u8 lbl_805D7944;
extern void (*lbl_805D7948)(s32, s32, s32);
extern void (*lbl_805D794C)(s32, s32, s32);

s32 TAdPlayerLoadGC__sub_803F2F1C(void) {
    s32 i;
    s32 result;
    s32 mem_size;
    s32 sector_size;
    BOOL enabled;

    if (lbl_805D7940 < 1) {
        return -1;
    }
    if (lbl_805D7944 != 0) {
        return 0;
    }
    lbl_805D7944++;
    for (i = 0; i < 2; i++) {
        result = CARDProbeEx(i, &mem_size, &sector_size);
        switch (result) {
        case -128:
        default:
            if (result != lbl_805A5ED0[i].state) {
                lbl_805A5ED0[i].state = result;
                lbl_805A5ED0[i].mem_size = 0;
                lbl_805A5ED0[i].sector_size = 0;
            }
            break;
        case -3:
            if (result != lbl_805A5ED0[i].state) {
                if (lbl_805A5ED0[i].state == 0) {
                    mem_size = lbl_805A5ED0[i].mem_size;
                    sector_size = lbl_805A5ED0[i].sector_size;
                    lbl_805A5ED0[i].state = result;
                    lbl_805A5ED0[i].mem_size = 0;
                    lbl_805A5ED0[i].sector_size = 0;
                    if (lbl_805D794C != NULL) {
                        enabled = OSDisableInterrupts();
                        lbl_805D794C(i, mem_size, sector_size);
                        OSRestoreInterrupts(enabled);
                    }
                }
                lbl_805A5ED0[i].state = result;
                lbl_805A5ED0[i].mem_size = 0;
                lbl_805A5ED0[i].sector_size = 0;
            }
            break;
        case -2:
            if (result != lbl_805A5ED0[i].state) {
                lbl_805A5ED0[i].state = result;
                lbl_805A5ED0[i].mem_size = 0;
                lbl_805A5ED0[i].sector_size = 0;
            }
            break;
        case 0:
            if (result != lbl_805A5ED0[i].state) {
                lbl_805A5ED0[i].state = result;
                lbl_805A5ED0[i].mem_size = mem_size;
                lbl_805A5ED0[i].sector_size = sector_size;
                if (lbl_805D7948 != NULL) {
                    enabled = OSDisableInterrupts();
                    lbl_805D7948(i, lbl_805A5ED0[i].mem_size, lbl_805A5ED0[i].sector_size);
                    OSRestoreInterrupts(enabled);
                }
            }
            break;
        case -1:
            break;
        }
    }
    for (i = 0; i < 2; i++) {
        switch (TAdPlayerLoadGC__load_request_slots[i].f44) {
        case 1:
            TAdPlayerLoadGC__sub_803F2D20(i);
            break;
        case 2:
            TAdPlayerLoadGC__sub_803F2A4C(TAdPlayerLoadGC__load_request_slots[i].f54);
            break;
        case 3:
            TAdPlayerLoadGC__sub_803F282C(TAdPlayerLoadGC__load_request_slots[i].f54);
            break;
        case 5:
            TAdPlayerLoadGC__sub_803F2240(TAdPlayerLoadGC__load_request_slots[i].f54);
            break;
        case 4:
            TAdPlayerLoadGC__sub_803F2610(TAdPlayerLoadGC__load_request_slots[i].f54);
            break;
        case 6:
            TAdPlayerLoadGC::update_card_rename(i);
            break;
        case 7:
            TAdPlayerLoadGC::update_card_delete(i);
            break;
        case 8:
            TAdPlayerLoadGC::step_set_attributes(i);
            break;
        case 9:
            TAdPlayerLoadGC__sub_803F1908(i);
            break;
        }
    }
    lbl_805D7944--;
    return 0;
}

s32 TAdPlayerLoadGC__sub_803F31BC(void) {
    if (lbl_805D7940 == 0) {
        return -1;
    }
    return 0;
}

// lbl_8047FCD8: "mcFsGc Ver 1.10.00 Build:Sep 17 2002 20:22:41" (memory-card library version banner)
extern const char lbl_8047FCD8[];
static const char *const lbl_805E10E8 = lbl_8047FCD8;
extern const char *lbl_805D7954;

s32 TAdPlayerLoadGC__sub_803F31D8(void *work_area) {
    s32 i;

    lbl_805D7954 = lbl_805E10E8;
    if (lbl_805D7940 > 0) {
        return -1;
    }
    if (work_area == NULL) {
        return -2;
    }
    CARDInit();
    for (i = 0; i < 2; i++) {
        lbl_805A5ED0[i].state = -3;
        lbl_805A5ED0[i].mem_size = 0;
        lbl_805A5ED0[i].sector_size = 0;
        TAdPlayerLoadGC::reset_slot_entry(i);
    }
    lbl_805D7960 = work_area;
    lbl_805D7948 = NULL;
    lbl_805D794C = NULL;
    lbl_805D7940 = 1;
    memset(lbl_805A29B0, 0, sizeof(lbl_805A29B0));
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
        ret = CARDClose(&s->file_info);
        memset(s, 0, 0x88);
        s->state = 2;
    }
    return ret;
}
}
