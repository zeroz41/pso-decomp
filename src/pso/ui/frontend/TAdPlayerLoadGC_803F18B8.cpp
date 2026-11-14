#include "types.h"
#include <string.h>
#include <stdio.h>
#include "pso/ui/frontend/TAdPlayerLoadGC_803F18B8.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "dolphin/os.h"
#include "dolphin/card.h"
#include "pso/ui/frontend/CardFileEntry.h"

// Per-slot card state: the last CARDProbeEx result and the sizes it reported.
struct CardInfo_803F31D8 { s32 state; s32 mem_size; s32 sector_size; };

extern "C" {
extern s32 lbl_805D7940;
void *CARDGetDiskID(s32);
s32 CARDSetDiskID(s32, void *);
extern void *saved_card_disk_id;
// lbl_8047FCD8: "mcFsGc Ver 1.10.00 Build:Sep 17 2002 20:22:41" (memory-card library version banner)
extern const char lbl_8047FCD8[];
static const char *const mcfs_version = lbl_8047FCD8;
// inferred: the DVDDiskID gameName/company pair CARDSetDiskID is given in place of the disk's own
static const char card_game_name[] = "G9AE";
static const char card_company[] = "8P";
u8 card_disk_id[0x20];
CardRequestSlot TAdPlayerLoadGC__load_request_slots[2];
CardFileEntry card_open_files[100];
CardInfo_803F31D8 card_slot_info[4];

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

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
// inferred: fills the game name and company that card files are matched against
// (CARDStat.gameName/company below): the card's disk id, or the fixed card_game_name/
// card_company codes when the channel flag says the disk id is overridden.
static inline void get_game_name_and_company(s32 card_channel, u8 *game_name, u8 *company) {
    if (TAdPlayerLoadGC::get_or_set_channel_flag(card_channel, 2) != 1) {
        u8 *disk_id = (u8 *)CARDGetDiskID(card_channel);
        memcpy(game_name, disk_id, 4);
        memcpy(company, disk_id + 4, 2);
    } else {
        memcpy(game_name, card_game_name, 4);
        memcpy(company, card_company, 2);
    }
}

void TAdPlayerLoadGC__sub_803F1908(s32 card_channel) {
    s32 i;
    s32 found;
    CARDStat stat;
    u8 company[2];
    u8 game_name[4];
    OSCalendarTime ct;
    char date[0x20];

    switch (TAdPlayerLoadGC__load_request_slots[card_channel].step) {
    case 1:
        TAdPlayerLoadGC__load_request_slots[card_channel].result = CARDMountAsync(card_channel, lbl_805D7960, 0, 0);
        if (TAdPlayerLoadGC__load_request_slots[card_channel].result < 0) {
            TAdPlayerLoadGC__load_request_slots[card_channel].status = -200;
            TAdPlayerLoadGC__load_request_slots[card_channel].step = 0x18;
            break;
        }
        TAdPlayerLoadGC__load_request_slots[card_channel].step = 2;
    case 2:
        TAdPlayerLoadGC__load_request_slots[card_channel].result = CARDGetResultCode(card_channel);
        if (TAdPlayerLoadGC__load_request_slots[card_channel].result == 0 || TAdPlayerLoadGC__load_request_slots[card_channel].result == -6) {
            TAdPlayerLoadGC__load_request_slots[card_channel].step = 3;
        } else {
            if (TAdPlayerLoadGC__load_request_slots[card_channel].result != -1) {
                TAdPlayerLoadGC__load_request_slots[card_channel].status = -200;
                TAdPlayerLoadGC__load_request_slots[card_channel].step = 0x18;
            }
            break;
        }
    case 3:
        TAdPlayerLoadGC__load_request_slots[card_channel].result = CARDCheckAsync(card_channel, 0);
        if (TAdPlayerLoadGC__load_request_slots[card_channel].result < 0) {
            TAdPlayerLoadGC__load_request_slots[card_channel].status = -201;
            TAdPlayerLoadGC__load_request_slots[card_channel].step = 0x18;
            break;
        }
        TAdPlayerLoadGC__load_request_slots[card_channel].step = 4;
    case 4:
        TAdPlayerLoadGC__load_request_slots[card_channel].result = CARDGetResultCode(card_channel);
        if (TAdPlayerLoadGC__load_request_slots[card_channel].result == 0) {
            TAdPlayerLoadGC__load_request_slots[card_channel].step = 5;
        } else {
            if (TAdPlayerLoadGC__load_request_slots[card_channel].result != -1) {
                TAdPlayerLoadGC__load_request_slots[card_channel].status = -201;
                TAdPlayerLoadGC__load_request_slots[card_channel].step = 0x18;
                CARDUnmount(card_channel);
            }
            break;
        }
    case 5:
        TAdPlayerLoadGC__load_request_slots[card_channel].result = CARDGetSectorSize(card_channel, (u32 *)&card_slot_info[card_channel].sector_size);
        if (TAdPlayerLoadGC__load_request_slots[card_channel].result < 0) {
            TAdPlayerLoadGC__load_request_slots[card_channel].status = -202;
            TAdPlayerLoadGC__load_request_slots[card_channel].step = 0x18;
        } else {
            if (TAdPlayerLoadGC::get_or_set_channel_flag(card_channel, 2) == 1) {
                saved_card_disk_id = CARDGetDiskID(card_channel);
                memcpy(card_disk_id, saved_card_disk_id, 0x20);
                memcpy(card_disk_id, card_game_name, 4);
                memcpy(card_disk_id + 4, card_company, 2);
                CARDSetDiskID(card_channel, card_disk_id);
            }
            get_game_name_and_company(card_channel, game_name, company);
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
            if (TAdPlayerLoadGC::get_or_set_channel_flag(card_channel, 2) == 1 && saved_card_disk_id != NULL) {
                CARDSetDiskID(card_channel, saved_card_disk_id);
            }
            if (found == 0) {
                TAdPlayerLoadGC__load_request_slots[card_channel].status = -102;
            } else {
                TAdPlayerLoadGC__load_request_slots[card_channel].status = 0;
            }
            TAdPlayerLoadGC__load_request_slots[card_channel].step = 0x16;
        }
        CARDUnmount(card_channel);
        break;
    case 0: case 6: case 7: case 8: case 9: case 0xA: case 0xB: case 0xC:
    case 0xD: case 0xE: case 0xF: case 0x10: case 0x11: case 0x12: case 0x13: case 0x14: case 0x15: case 0x16: case 0x17: case 0x18:
        return;
    }
}
#pragma pop

void TAdPlayerLoadGC::step_set_attributes(s32 card_channel) {

    switch (TAdPlayerLoadGC__load_request_slots[card_channel].step) {

    case 0x11:
        if (TAdPlayerLoadGC::get_or_set_channel_flag(card_channel, 2) == 1) {
            saved_card_disk_id = CARDGetDiskID(card_channel);
            memcpy(card_disk_id, saved_card_disk_id, 0x20);
            memcpy(card_disk_id, card_game_name, 4);
            memcpy(card_disk_id + 4, card_company, 2);
            CARDSetDiskID(card_channel, card_disk_id);
        }
        TAdPlayerLoadGC__load_request_slots[card_channel].result = CARDSetAttributesAsync(card_channel, TAdPlayerLoadGC__load_request_slots[card_channel].file_no, TAdPlayerLoadGC__load_request_slots[card_channel].attr, 0);
        if (TAdPlayerLoadGC__load_request_slots[card_channel].result < 0) {
            if (TAdPlayerLoadGC::get_or_set_channel_flag(card_channel, 2) == 1 && saved_card_disk_id != NULL) {
                CARDSetDiskID(card_channel, saved_card_disk_id);
            }
            TAdPlayerLoadGC__load_request_slots[card_channel].status = -0xD4;
            TAdPlayerLoadGC__load_request_slots[card_channel].step = 0x18;
            break;
        }
        TAdPlayerLoadGC__load_request_slots[card_channel].step = 0x12;
    case 0x12:
        TAdPlayerLoadGC__load_request_slots[card_channel].result = CARDGetResultCode(card_channel);
        if (TAdPlayerLoadGC__load_request_slots[card_channel].result == 0) {
            if (TAdPlayerLoadGC::get_or_set_channel_flag(card_channel, 2) == 1 && saved_card_disk_id != NULL) {
                CARDSetDiskID(card_channel, saved_card_disk_id);
            }
            TAdPlayerLoadGC__load_request_slots[card_channel].status = 0;
            TAdPlayerLoadGC__load_request_slots[card_channel].step = 0x16;
        } else if (TAdPlayerLoadGC__load_request_slots[card_channel].result != -1) {
            if (TAdPlayerLoadGC::get_or_set_channel_flag(card_channel, 2) == 1 && saved_card_disk_id != NULL) {
                CARDSetDiskID(card_channel, saved_card_disk_id);
            }
            TAdPlayerLoadGC__load_request_slots[card_channel].status = -0xD4;
            TAdPlayerLoadGC__load_request_slots[card_channel].step = 0x18;
        }
        break;
    case 0x13: case 0x14: case 0x15: case 0x16: case 0x17: case 0x18:
        return;
    }
}
void TAdPlayerLoadGC::update_card_delete(s32 card_channel) {
    CardRequestSlot *s;

    switch (TAdPlayerLoadGC__load_request_slots[card_channel].step) {
    case 0xF:
        if (TAdPlayerLoadGC::get_or_set_channel_flag(card_channel, 2) == 1) {
            saved_card_disk_id = CARDGetDiskID(card_channel);
            memcpy(card_disk_id, saved_card_disk_id, 0x20);
            memcpy(card_disk_id, card_game_name, 4);
            memcpy(card_disk_id + 4, card_company, 2);
            CARDSetDiskID(card_channel, card_disk_id);
        }
        TAdPlayerLoadGC__load_request_slots[card_channel].result = CARDDeleteAsync(card_channel, TAdPlayerLoadGC__load_request_slots[card_channel].name, 0);
        if (TAdPlayerLoadGC__load_request_slots[card_channel].result < 0) {
            if (TAdPlayerLoadGC::get_or_set_channel_flag(card_channel, 2) == 1 && saved_card_disk_id != NULL) {
                CARDSetDiskID(card_channel, saved_card_disk_id);
            }
            TAdPlayerLoadGC__load_request_slots[card_channel].status = -0xD3;
            TAdPlayerLoadGC__load_request_slots[card_channel].step = 0x18;
            break;
        }
        TAdPlayerLoadGC__load_request_slots[card_channel].step = 0x10;
    case 0x10:
        TAdPlayerLoadGC__load_request_slots[card_channel].result = CARDGetResultCode(card_channel);
        if (TAdPlayerLoadGC__load_request_slots[card_channel].result == 0) {
            if (TAdPlayerLoadGC::get_or_set_channel_flag(card_channel, 2) == 1 && saved_card_disk_id != NULL) {
                CARDSetDiskID(card_channel, saved_card_disk_id);
            }
            TAdPlayerLoadGC__load_request_slots[card_channel].status = 0;
            TAdPlayerLoadGC__load_request_slots[card_channel].step = 0x16;
        } else if (TAdPlayerLoadGC__load_request_slots[card_channel].result != -1) {
            if (TAdPlayerLoadGC::get_or_set_channel_flag(card_channel, 2) == 1 && saved_card_disk_id != NULL) {
                CARDSetDiskID(card_channel, saved_card_disk_id);
            }
            TAdPlayerLoadGC__load_request_slots[card_channel].status = -0xD3;
            TAdPlayerLoadGC__load_request_slots[card_channel].step = 0x18;
        }
        break;
    case 0x11: case 0x12: case 0x13: case 0x14: case 0x15: case 0x16: case 0x17: case 0x18:
        return;
    }
}
void TAdPlayerLoadGC::update_card_rename(s32 card_channel) {

    switch (TAdPlayerLoadGC__load_request_slots[card_channel].step) {
    case 0xd:
        if (TAdPlayerLoadGC::get_or_set_channel_flag(card_channel, 2) == 1) {
            saved_card_disk_id = CARDGetDiskID(card_channel);
            memcpy(card_disk_id, saved_card_disk_id, 0x20);
            memcpy(card_disk_id, card_game_name, 4);
            memcpy(card_disk_id + 4, card_company, 2);
            CARDSetDiskID(card_channel, card_disk_id);
        }
        TAdPlayerLoadGC__load_request_slots[card_channel].result = CARDRenameAsync(card_channel, TAdPlayerLoadGC__load_request_slots[card_channel].name, TAdPlayerLoadGC__load_request_slots[card_channel].new_name, 0);
        if (TAdPlayerLoadGC__load_request_slots[card_channel].result < 0) {
            if (TAdPlayerLoadGC::get_or_set_channel_flag(card_channel, 2) == 1 && saved_card_disk_id != NULL) {
                CARDSetDiskID(card_channel, saved_card_disk_id);
            }
            TAdPlayerLoadGC__load_request_slots[card_channel].status = -210;
            TAdPlayerLoadGC__load_request_slots[card_channel].step = 0x18;
            break;
        }
        TAdPlayerLoadGC__load_request_slots[card_channel].step = 0xe;
    case 0xe:
        TAdPlayerLoadGC__load_request_slots[card_channel].result = CARDGetResultCode(card_channel);
        if (TAdPlayerLoadGC__load_request_slots[card_channel].result == 0) {
            if (TAdPlayerLoadGC::get_or_set_channel_flag(card_channel, 2) == 1 && saved_card_disk_id != NULL) {
                CARDSetDiskID(card_channel, saved_card_disk_id);
            }
            TAdPlayerLoadGC__load_request_slots[card_channel].status = 0;
            TAdPlayerLoadGC__load_request_slots[card_channel].step = 0x16;
        } else if (TAdPlayerLoadGC__load_request_slots[card_channel].result != -1) {
            if (TAdPlayerLoadGC::get_or_set_channel_flag(card_channel, 2) == 1 && saved_card_disk_id != NULL) {
                CARDSetDiskID(card_channel, saved_card_disk_id);
            }
            TAdPlayerLoadGC__load_request_slots[card_channel].status = -210;
            TAdPlayerLoadGC__load_request_slots[card_channel].step = 0x18;
        }
        break;
    case 0xf: case 0x10: case 0x11: case 0x12: case 0x13: case 0x14: case 0x15: case 0x16: case 0x17: case 0x18:
        return;
    }
}
#pragma push
#pragma opt_propagation off
#pragma opt_lifetimes off
void TAdPlayerLoadGC__sub_803F2240(s32 file) {
    s32 id;
    s32 *channel;
    s32 off;
    s32 *st;
    s32 *result;
    s32 ioff;

    off = file * 0x88;
    channel = (s32 *)((u8 *)&card_open_files[0].channel + off);
    st = &TAdPlayerLoadGC__load_request_slots[0].step;
    id = *channel;

    switch (st[id * 0x1A]) {
    case 0xB:
        if (TAdPlayerLoadGC::get_or_set_channel_flag(id, 2) == 1) {
            saved_card_disk_id = CARDGetDiskID(id);
            memcpy(card_disk_id, saved_card_disk_id, 0x20);
            memcpy(card_disk_id, card_game_name, 4);
            memcpy(card_disk_id + 4, card_company, 2);
            CARDSetDiskID(id, card_disk_id);
        }
        {
            CARDFileInfo *info = &((CardFileEntry *)((u8 *)card_open_files + off))->file_info;
            s32 rc;
            rc = CARDWriteAsync(info, TAdPlayerLoadGC__load_request_slots[*channel].buffer, TAdPlayerLoadGC__load_request_slots[*channel].length, TAdPlayerLoadGC__load_request_slots[*channel].offset, 0);
            ioff = *channel * 0x68;
            result = (s32 *)((u8 *)&TAdPlayerLoadGC__load_request_slots[0].result + ioff);
            *result = rc;
        }
        if (*result < 0) {
            id = *channel;
            if (TAdPlayerLoadGC::get_or_set_channel_flag(id, 2) == 1 && saved_card_disk_id != NULL) {
                CARDSetDiskID(id, saved_card_disk_id);
            }
            ioff = *channel * 0x68;
            TAdPlayerLoadGC__load_request_slots[*channel].status = -0xCE;
            *(s32 *)((u8 *)st + ioff) = 0x18;
            break;
        }
        *(s32 *)((u8 *)st + ioff) = 0xC;
    case 0xC:
        {
            s32 r = CARDGetResultCode(*channel);
            result = (s32 *)((u8 *)&TAdPlayerLoadGC__load_request_slots[0].result + *channel * 0x68);
            *result = r;
            if (*result == 0) {
                id = *channel;
                if (TAdPlayerLoadGC::get_or_set_channel_flag(id, 2) == 1 && saved_card_disk_id != NULL) {
                    CARDSetDiskID(id, saved_card_disk_id);
                }
                *(s32 *)((u8 *)st + *channel * 0x68) = 0x14;
            } else {
                if (*result != -1) {
                    id = *channel;
                    if (TAdPlayerLoadGC::get_or_set_channel_flag(id, 2) == 1 && saved_card_disk_id != NULL) {
                        CARDSetDiskID(id, saved_card_disk_id);
                    }
                    ioff = *channel * 0x68;
                    TAdPlayerLoadGC__load_request_slots[*channel].status = -0xCE;
                    *(s32 *)((u8 *)st + ioff) = 0x18;
                }
                break;
            }
        }
    case 0x14:
        id = *channel;
        if (TAdPlayerLoadGC::get_or_set_channel_flag(id, 2) == 1) {
            saved_card_disk_id = CARDGetDiskID(id);
            memcpy(card_disk_id, saved_card_disk_id, 0x20);
            memcpy(card_disk_id, card_game_name, 4);
            memcpy(card_disk_id + 4, card_company, 2);
            CARDSetDiskID(id, card_disk_id);
        }
        {
            CardFileEntry *entry = (CardFileEntry *)((u8 *)card_open_files + off);
            s32 rc;
            rc = CARDSetStatusAsync(*channel, entry->file_info.fileNo, &entry->stat, 0);
            ioff = *channel * 0x68;
            result = (s32 *)((u8 *)&TAdPlayerLoadGC__load_request_slots[0].result + ioff);
            *result = rc;
        }
        if (*result < 0) {
            id = *channel;
            if (TAdPlayerLoadGC::get_or_set_channel_flag(id, 2) == 1 && saved_card_disk_id != NULL) {
                CARDSetDiskID(id, saved_card_disk_id);
            }
            ioff = *channel * 0x68;
            TAdPlayerLoadGC__load_request_slots[*channel].status = -0xD0;
            *(s32 *)((u8 *)st + ioff) = 0x18;
            break;
        }
        *(s32 *)((u8 *)st + ioff) = 0x15;
    case 0x15:
        {
            s32 r = CARDGetResultCode(*channel);
            result = (s32 *)((u8 *)&TAdPlayerLoadGC__load_request_slots[0].result + *channel * 0x68);
            *result = r;
            if (*result == 0) {
                id = *channel;
                if (TAdPlayerLoadGC::get_or_set_channel_flag(id, 2) == 1 && saved_card_disk_id != NULL) {
                    CARDSetDiskID(id, saved_card_disk_id);
                }
                ioff = *channel * 0x68;
                TAdPlayerLoadGC__load_request_slots[*channel].status = 0;
                *(s32 *)((u8 *)st + ioff) = 0x16;
            } else if (*result != -1) {
                id = *channel;
                if (TAdPlayerLoadGC::get_or_set_channel_flag(id, 2) == 1 && saved_card_disk_id != NULL) {
                    CARDSetDiskID(id, saved_card_disk_id);
                }
                ioff = *channel * 0x68;
                TAdPlayerLoadGC__load_request_slots[*channel].status = -0xD0;
                *(s32 *)((u8 *)st + ioff) = 0x18;
            }
        }
        break;
    case 0xD: case 0xE: case 0xF: case 0x10: case 0x11: case 0x12: case 0x13:
    case 0x16: case 0x17: case 0x18:
        return;
    default:
        return;
    }
}
#pragma pop

#pragma push
#pragma opt_propagation off
void TAdPlayerLoadGC__sub_803F2610(s32 file) {
    s32 id;
    s32 *channel;
    s32 *st;
    s32 off;
    s32 *result;
    s32 ioff;

    off = file * 0x88;
    channel = (s32 *)((u8 *)&card_open_files[0].channel + off);
    st = &TAdPlayerLoadGC__load_request_slots[0].step;
    id = *channel;

    switch (st[id * 0x1A]) {
    case 0x9:
        if (TAdPlayerLoadGC::get_or_set_channel_flag(id, 2) == 1) {
            saved_card_disk_id = CARDGetDiskID(id);
            memcpy(card_disk_id, saved_card_disk_id, 0x20);
            memcpy(card_disk_id, card_game_name, 4);
            memcpy(card_disk_id + 4, card_company, 2);
            CARDSetDiskID(id, card_disk_id);
        }
        {
            CARDFileInfo *info = &((CardFileEntry *)((u8 *)card_open_files + off))->file_info;
            s32 rc;
            rc = CARDReadAsync(info, TAdPlayerLoadGC__load_request_slots[*channel].buffer, TAdPlayerLoadGC__load_request_slots[*channel].length, TAdPlayerLoadGC__load_request_slots[*channel].offset, 0);
            ioff = *channel * 0x68;
            result = (s32 *)((u8 *)&TAdPlayerLoadGC__load_request_slots[0].result + ioff);
            *result = rc;
        }
        if (*result < 0) {
            id = *channel;
            if (TAdPlayerLoadGC::get_or_set_channel_flag(id, 2) == 1 && saved_card_disk_id != NULL) {
                CARDSetDiskID(id, saved_card_disk_id);
            }
            ioff = *channel * 0x68;
            TAdPlayerLoadGC__load_request_slots[*channel].status = -0xCD;
            *(s32 *)((u8 *)st + ioff) = 0x18;
            break;
        }
        *(s32 *)((u8 *)st + ioff) = 0xA;
    case 0xA:
        {
            s32 r = CARDGetResultCode(*channel);
            result = (s32 *)((u8 *)&TAdPlayerLoadGC__load_request_slots[0].result + *channel * 0x68);
            *result = r;
            if (*result == 0) {
                id = *channel;
                if (TAdPlayerLoadGC::get_or_set_channel_flag(id, 2) == 1 && saved_card_disk_id != NULL) {
                    CARDSetDiskID(id, saved_card_disk_id);
                }
                ioff = *channel * 0x68;
                TAdPlayerLoadGC__load_request_slots[*channel].status = 0;
                *(s32 *)((u8 *)st + ioff) = 0x16;
            } else if (*result != -1) {
                id = *channel;
                if (TAdPlayerLoadGC::get_or_set_channel_flag(id, 2) == 1 && saved_card_disk_id != NULL) {
                    CARDSetDiskID(id, saved_card_disk_id);
                }
                ioff = *channel * 0x68;
                TAdPlayerLoadGC__load_request_slots[*channel].status = -0xCD;
                *(s32 *)((u8 *)st + ioff) = 0x18;
            }
        }
        break;
    case 0xB: case 0xC: case 0xD: case 0xE: case 0xF: case 0x10: case 0x11: case 0x12:
    case 0x13: case 0x14: case 0x15: case 0x16: case 0x17: case 0x18:
        return;
    default:
        return;
    }
}
#pragma pop

#pragma push
#pragma opt_propagation off
void TAdPlayerLoadGC__sub_803F282C(s32 file) {
    s32 *channel;
    s32 *st;
    s32 id;
    s32 off;
    s32 res;
    CardFileEntry *rec;

    off = file * 0x88;
    channel = (s32 *)((u8 *)&card_open_files[0].channel + off);
    st = &TAdPlayerLoadGC__load_request_slots[0].step;
    id = *channel;

    switch (st[id * 0x1A]) {
    case 0x8:
        if (TAdPlayerLoadGC::get_or_set_channel_flag(id, 2) == 1) {
            saved_card_disk_id = CARDGetDiskID(id);
            memcpy(card_disk_id, saved_card_disk_id, 0x20);
            memcpy(card_disk_id, card_game_name, 4);
            memcpy(card_disk_id + 4, card_company, 2);
            CARDSetDiskID(id, card_disk_id);
        }
        res = CARDOpen(*channel, TAdPlayerLoadGC__load_request_slots[*channel].name, &((CardFileEntry *)((u8 *)card_open_files + off))->file_info);
        id = *channel;
        TAdPlayerLoadGC__load_request_slots[id].result = res;
        if (TAdPlayerLoadGC__load_request_slots[id].result < 0) {
            id = *channel;
            if (TAdPlayerLoadGC::get_or_set_channel_flag(id, 2) == 1 && saved_card_disk_id != NULL) {
                CARDSetDiskID(id, saved_card_disk_id);
            }
            id = *channel;
            TAdPlayerLoadGC__load_request_slots[id].status = -0xCC;
            st[id * 0x1A] = 0x18;
            return;
        }
        st[id * 0x1A] = 0x13;
    case 0x13:
        rec = (CardFileEntry *)((u8 *)card_disk_id + off + 0xF0);
        res = CARDGetStatus(*channel, *(s32 *)((u8 *)card_disk_id + off + 0xFC), &rec->stat);
        id = *channel;
        TAdPlayerLoadGC__load_request_slots[id].result = res;
        if (TAdPlayerLoadGC__load_request_slots[id].result < 0) {
            id = *channel;
            if (TAdPlayerLoadGC::get_or_set_channel_flag(id, 2) == 1 && saved_card_disk_id != NULL) {
                CARDSetDiskID(id, saved_card_disk_id);
            }
            id = *channel;
            TAdPlayerLoadGC__load_request_slots[id].status = -0xCF;
            st[id * 0x1A] = 0x18;
            CARDClose(&rec->file_info);
        } else {
            id = *channel;
            if (TAdPlayerLoadGC::get_or_set_channel_flag(id, 2) == 1 && saved_card_disk_id != NULL) {
                CARDSetDiskID(id, saved_card_disk_id);
            }
            id = *channel;
            TAdPlayerLoadGC__load_request_slots[id].status = 0;
            st[id * 0x1A] = 0x16;
        }
        break;
    case 0x14:
    case 0x15:
    case 0x16:
    case 0x17:
    case 0x18:
        return;
    default:
        return;
    }
}
#pragma pop

#pragma push
#pragma opt_propagation off
void TAdPlayerLoadGC__sub_803F2A4C(s32 file) {
  s32 *channel;
  s32 off;
  s32 *st;
  s32 id;
  s32 res;
  CardFileEntry *rec;
  off = file * 0x88;
  channel = (s32 *)((u8 *)&card_open_files[0].channel + off);
  st = &TAdPlayerLoadGC__load_request_slots[0].step;
  id = *channel;
  switch (st[id * 0x1A])
  {
    case 0x6:
      if (TAdPlayerLoadGC::get_or_set_channel_flag(id, 2) == 1)
    {
      saved_card_disk_id = CARDGetDiskID(id);
      memcpy(card_disk_id, saved_card_disk_id, 0x20);
      memcpy(card_disk_id, card_game_name, 4);
      memcpy(card_disk_id + 4, card_company, 2);
      CARDSetDiskID(id, card_disk_id);
    }
      res = CARDCreateAsync(*channel, TAdPlayerLoadGC__load_request_slots[*channel].name, TAdPlayerLoadGC__load_request_slots[*channel].length, &((CardFileEntry *)((u8 *)card_open_files + off))->file_info, 0);
      id = *channel;
      TAdPlayerLoadGC__load_request_slots[id].result = res;
      if (TAdPlayerLoadGC__load_request_slots[id].result < 0)
    {
      id = *channel;
      if ((TAdPlayerLoadGC::get_or_set_channel_flag(id, 2) == 1) && (saved_card_disk_id != 0))
      {
        CARDSetDiskID(id, saved_card_disk_id);
      }
      id = *channel;
      TAdPlayerLoadGC__load_request_slots[id].status = -0xCB;
      st[id * 0x1A] = 0x18;
      return;
    }
      st[id * 0x1A] = 0x7;

    case 0x7:
      res = CARDGetResultCode(*channel);
      id = *channel;
      TAdPlayerLoadGC__load_request_slots[id].result = res;
      if (TAdPlayerLoadGC__load_request_slots[id].result == 0)
    {
      id = *channel;
      if ((TAdPlayerLoadGC::get_or_set_channel_flag(id, 2) == 1) && (saved_card_disk_id != 0))
      {
        CARDSetDiskID(id, saved_card_disk_id);
      }
      st[(*channel) * 0x1A] = 0x13;
    }
    else
      if (TAdPlayerLoadGC__load_request_slots[id].result == (-1))
    {
      return;
    }
    else
    {
      id = (res = *channel);
      if ((TAdPlayerLoadGC::get_or_set_channel_flag(id, 2) == 1) && (saved_card_disk_id != 0))
      {
        CARDSetDiskID(id, saved_card_disk_id);
      }
      id = *channel;
      TAdPlayerLoadGC__load_request_slots[id].status = -0xCB;
      st[id * 0x1A] = 0x18;
      return;
    }

    case 0x13:
      rec = (CardFileEntry *)((((u8 *) card_disk_id) + off) + 0xF0);
      res = CARDGetStatus(*channel, *((s32 *) ((((u8 *) card_disk_id) + off) + 0xFC)), &rec->stat);
      id = *channel;
      TAdPlayerLoadGC__load_request_slots[id].result = res;
      if (TAdPlayerLoadGC__load_request_slots[id].result < 0)
    {
      TAdPlayerLoadGC__load_request_slots[id].status = -0xCF;
      st[id * 0x1A] = 0x18;
      CARDClose(&rec->file_info);
    }
    else
    {
      TAdPlayerLoadGC__load_request_slots[id].status = 0;
      st[id * 0x1A] = 0x16;
    }
      break;

    case 0x14:

    case 0x15:

    case 0x16:

    case 0x17:

    case 0x18:
      return;

    default:
      return;

  }

}
#pragma pop

void TAdPlayerLoadGC__sub_803F2CD0(s32 card_channel, s32 result) {
    TAdPlayerLoadGC__load_request_slots[card_channel].result = result;
    switch (result) {
    default:
        TAdPlayerLoadGC__load_request_slots[card_channel].status = -201;
        TAdPlayerLoadGC__load_request_slots[card_channel].step = 0x18;
        break;
    case 0:
    case -6:
        TAdPlayerLoadGC__load_request_slots[card_channel].step = 5;
        break;
    }
}


void TAdPlayerLoadGC__sub_803F2D20(s32 card_channel) {

    switch (TAdPlayerLoadGC__load_request_slots[card_channel].step) {
    case 1:
        TAdPlayerLoadGC__load_request_slots[card_channel].result = CARDMountAsync(card_channel, lbl_805D7960, 0, 0);
        if (TAdPlayerLoadGC__load_request_slots[card_channel].result < 0) {
            TAdPlayerLoadGC__load_request_slots[card_channel].status = -200;
            TAdPlayerLoadGC__load_request_slots[card_channel].step = 0x18;
            break;
        }
        TAdPlayerLoadGC__load_request_slots[card_channel].step = 2;
    case 2:
        TAdPlayerLoadGC__load_request_slots[card_channel].result = CARDGetResultCode(card_channel);
        if (TAdPlayerLoadGC__load_request_slots[card_channel].result == 0 || TAdPlayerLoadGC__load_request_slots[card_channel].result == -6) {
            TAdPlayerLoadGC__load_request_slots[card_channel].step = 3;
        } else {
            if (TAdPlayerLoadGC__load_request_slots[card_channel].result != -1) {
                TAdPlayerLoadGC__load_request_slots[card_channel].status = -200;
                TAdPlayerLoadGC__load_request_slots[card_channel].step = 0x18;
            }
            break;
        }
    case 3:
        TAdPlayerLoadGC__load_request_slots[card_channel].result = CARDCheckAsync(card_channel, TAdPlayerLoadGC__sub_803F2CD0);
        if (TAdPlayerLoadGC__load_request_slots[card_channel].result < 0) {
            TAdPlayerLoadGC__load_request_slots[card_channel].status = -201;
            TAdPlayerLoadGC__load_request_slots[card_channel].step = 0x18;
            break;
        }
        TAdPlayerLoadGC__load_request_slots[card_channel].step = 4;
    case 4:
        TAdPlayerLoadGC__load_request_slots[card_channel].result = CARDGetResultCode(card_channel);
        if (TAdPlayerLoadGC__load_request_slots[card_channel].result == 0) {
            TAdPlayerLoadGC__load_request_slots[card_channel].step = 5;
        } else {
            if (TAdPlayerLoadGC__load_request_slots[card_channel].result != -1) {
                TAdPlayerLoadGC__load_request_slots[card_channel].status = -201;
                TAdPlayerLoadGC__load_request_slots[card_channel].step = 0x18;
                CARDUnmount(card_channel);
            }
            break;
        }
    case 5:
        TAdPlayerLoadGC__load_request_slots[card_channel].result = CARDGetSectorSize(card_channel, (u32 *)&card_slot_info[card_channel].sector_size);
        if (TAdPlayerLoadGC__load_request_slots[card_channel].result < 0) {
            TAdPlayerLoadGC__load_request_slots[card_channel].status = -202;
            TAdPlayerLoadGC__load_request_slots[card_channel].step = 0x18;
            CARDUnmount(card_channel);
            break;
        }
        TAdPlayerLoadGC__load_request_slots[card_channel].status = 0;
        TAdPlayerLoadGC__load_request_slots[card_channel].step = 0x16;
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
            if (result != card_slot_info[i].state) {
                card_slot_info[i].state = result;
                card_slot_info[i].mem_size = 0;
                card_slot_info[i].sector_size = 0;
            }
            break;
        case -3:
            if (result != card_slot_info[i].state) {
                if (card_slot_info[i].state == 0) {
                    mem_size = card_slot_info[i].mem_size;
                    sector_size = card_slot_info[i].sector_size;
                    card_slot_info[i].state = result;
                    card_slot_info[i].mem_size = 0;
                    card_slot_info[i].sector_size = 0;
                    if (lbl_805D794C != NULL) {
                        enabled = OSDisableInterrupts();
                        lbl_805D794C(i, mem_size, sector_size);
                        OSRestoreInterrupts(enabled);
                    }
                }
                card_slot_info[i].state = result;
                card_slot_info[i].mem_size = 0;
                card_slot_info[i].sector_size = 0;
            }
            break;
        case -2:
            if (result != card_slot_info[i].state) {
                card_slot_info[i].state = result;
                card_slot_info[i].mem_size = 0;
                card_slot_info[i].sector_size = 0;
            }
            break;
        case 0:
            if (result != card_slot_info[i].state) {
                card_slot_info[i].state = result;
                card_slot_info[i].mem_size = mem_size;
                card_slot_info[i].sector_size = sector_size;
                if (lbl_805D7948 != NULL) {
                    enabled = OSDisableInterrupts();
                    lbl_805D7948(i, card_slot_info[i].mem_size, card_slot_info[i].sector_size);
                    OSRestoreInterrupts(enabled);
                }
            }
            break;
        case -1:
            break;
        }
    }
    for (i = 0; i < 2; i++) {
        switch (TAdPlayerLoadGC__load_request_slots[i].kind) {
        case 1:
            TAdPlayerLoadGC__sub_803F2D20(i);
            break;
        case 2:
            TAdPlayerLoadGC__sub_803F2A4C(TAdPlayerLoadGC__load_request_slots[i].file_index);
            break;
        case 3:
            TAdPlayerLoadGC__sub_803F282C(TAdPlayerLoadGC__load_request_slots[i].file_index);
            break;
        case 5:
            TAdPlayerLoadGC__sub_803F2240(TAdPlayerLoadGC__load_request_slots[i].file_index);
            break;
        case 4:
            TAdPlayerLoadGC__sub_803F2610(TAdPlayerLoadGC__load_request_slots[i].file_index);
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

extern const char *lbl_805D7954;

s32 TAdPlayerLoadGC__sub_803F31D8(void *work_area) {
    s32 i;

    lbl_805D7954 = mcfs_version;
    if (lbl_805D7940 > 0) {
        return -1;
    }
    if (work_area == NULL) {
        return -2;
    }
    CARDInit();
    for (i = 0; i < 2; i++) {
        card_slot_info[i].state = -3;
        card_slot_info[i].mem_size = 0;
        card_slot_info[i].sector_size = 0;
        TAdPlayerLoadGC::reset_slot_entry(i);
    }
    lbl_805D7960 = work_area;
    lbl_805D7948 = NULL;
    lbl_805D794C = NULL;
    lbl_805D7940 = 1;
    memset(card_open_files, 0, sizeof(card_open_files));
    return 0;
}

void TAdPlayerLoadGC::reset_slot_entry(s32 arg0) {
    CardRequestSlot *slot = &TAdPlayerLoadGC__load_request_slots[arg0];
    slot->buffer = NULL;
    memset(slot->name, 0, sizeof(slot->name));
    memset(slot->new_name, 0, sizeof(slot->new_name));
    slot->kind = 0;
    slot->step = 0;
    slot->offset = 0;
    slot->length = 0;
    slot->file_index = -1;
    slot->status = 0;
    slot->result = 0;
}

// Returns CARDClose's result; for a file index outside 0..99 ret is never set (as in the game).
s32 TAdPlayerLoadGC::close_card_slot(s32 arg0) {
    CardFileEntry *s;
    s32 ret;
    if (arg0 >= 0 && arg0 < 0x64) {
        s = &card_open_files[arg0];
        ret = CARDClose(&s->file_info);
        memset(s, 0, 0x88);
        s->channel = 2;
    }
    return ret;
}
}
