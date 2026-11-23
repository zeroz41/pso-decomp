#include <stddef.h>
#include "types.h"
#include <string.h>
#include <stdio.h>
#include "pso/system/save/McFsGc.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "dolphin/os.h"
#include "dolphin/card.h"
#include "pso/system/save/CardFileEntry.h"

// memory-card library version banner
static const char *const mcfs_version = "\nmcFsGc Ver 1.10.00 Build:Sep 17 2002 20:22:41\n";
// inferred: the DVDDiskID gameName/company pair CARDSetDiskID is given in place of the disk's own
static const char card_game_name[] = "G9AE";
static const char card_company[] = "8P";
DVDDiskID card_disk_id;
CardRequestSlot load_request_slots[2];
CardFileEntry card_open_files[100];
CardSlotInfo card_slot_info[4];

// The linker places the request slots between the disk ID and open-file table.
// Two state-machine steps address the file record from that shared BSS base.
enum {
    OPEN_FILES_OFFSET = sizeof(card_disk_id) + sizeof(load_request_slots),
    OPEN_FILE_NUMBER_OFFSET = OPEN_FILES_OFFSET + offsetof(CardFileEntry, file_info) + offsetof(CARDFileInfo, fileNo),
};

s32 player_load_channel_flags[2] = {0, 0};
// inferred: set to 1 by the init function (init_card_lib) and checked first by every entry point
s32 card_lib_state;
// inferred: re-entrancy count of the card poll (update_card_requests), raised on entry, dropped on exit
u8 card_poll_depth;
// inferred: called when a slot's probe turns ready (0), with the card's sizes
CardSlotChangeCallback card_attach_callback;
// inferred: called when a ready slot's probe turns to no card (-3), with the sizes it had
CardSlotChangeCallback card_detach_callback;
const DVDDiskID *saved_card_disk_id;
// inferred: the init function stores the version banner pointer here
const char *mcfs_version_ref;

s32 TAdPlayerLoadGC::get_or_set_channel_flag(s32 channel, s32 mode) {
    if (((channel != 0) && (channel != 1)) || (mode < 0) || (mode > 2)) {
        return 0;
    }
    if (mode != 2) {
        player_load_channel_flags[channel] = mode;
    }
    return player_load_channel_flags[channel];
}

s32 TAdPlayerLoadGC::get_load_state() {
    return card_lib_state;
}
// the work area CARDMountAsync is given (its workArea argument), stored by the init function.
// 32-byte aligned: it sits 8 bytes past mcfs_version_ref, as the ntInf globals after it sit on
// 32-byte boundaries.
void *card_work_area __attribute__((aligned(32)));

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
// inferred: fills the game name and company that card files are matched against
// (CARDStat.gameName/company below): the card's disk id, or the fixed card_game_name/
// card_company codes when the channel flag says the disk id is overridden.
static inline void get_game_name_and_company(s32 card_channel, u8 *game_name, u8 *company) {
    if (TAdPlayerLoadGC::get_or_set_channel_flag(card_channel, 2) != 1) {
        const DVDDiskID *disk_id = CARDGetDiskID(card_channel);
        memcpy(game_name, disk_id->gameName, 4);
        memcpy(company, disk_id->company, 2);
    } else {
        memcpy(game_name, card_game_name, 4);
        memcpy(company, card_company, 2);
    }
}

void update_card_find(s32 card_channel) {
    s32 i;
    s32 found;
    CARDStat stat;
    u8 company[2];
    u8 game_name[4];
    OSCalendarTime ct;
    char date[0x20];

    switch (load_request_slots[card_channel].step) {
    case 1:
        load_request_slots[card_channel].result = CARDMountAsync(card_channel, card_work_area, 0, 0);
        if (load_request_slots[card_channel].result < 0) {
            load_request_slots[card_channel].status = -200;
            load_request_slots[card_channel].step = 0x18;
            break;
        }
        load_request_slots[card_channel].step = 2;
    case 2:
        load_request_slots[card_channel].result = CARDGetResultCode(card_channel);
        if (load_request_slots[card_channel].result == 0 || load_request_slots[card_channel].result == -6) {
            load_request_slots[card_channel].step = 3;
        } else {
            if (load_request_slots[card_channel].result != -1) {
                load_request_slots[card_channel].status = -200;
                load_request_slots[card_channel].step = 0x18;
            }
            break;
        }
    case 3:
        load_request_slots[card_channel].result = CARDCheckAsync(card_channel, 0);
        if (load_request_slots[card_channel].result < 0) {
            load_request_slots[card_channel].status = -201;
            load_request_slots[card_channel].step = 0x18;
            break;
        }
        load_request_slots[card_channel].step = 4;
    case 4:
        load_request_slots[card_channel].result = CARDGetResultCode(card_channel);
        if (load_request_slots[card_channel].result == 0) {
            load_request_slots[card_channel].step = 5;
        } else {
            if (load_request_slots[card_channel].result != -1) {
                load_request_slots[card_channel].status = -201;
                load_request_slots[card_channel].step = 0x18;
                CARDUnmount(card_channel);
            }
            break;
        }
    case 5:
        load_request_slots[card_channel].result = CARDGetSectorSize(card_channel, &card_slot_info[card_channel].sector_size);
        if (load_request_slots[card_channel].result < 0) {
            load_request_slots[card_channel].status = -202;
            load_request_slots[card_channel].step = 0x18;
        } else {
            if (TAdPlayerLoadGC::get_or_set_channel_flag(card_channel, 2) == 1) {
                saved_card_disk_id = CARDGetDiskID(card_channel);
                memcpy(&card_disk_id, saved_card_disk_id, sizeof(card_disk_id));
                memcpy(card_disk_id.gameName, card_game_name, sizeof(card_disk_id.gameName));
                memcpy(card_disk_id.company, card_company, sizeof(card_disk_id.company));
                CARDSetDiskID(card_channel, &card_disk_id);
            }
            get_game_name_and_company(card_channel, game_name, company);
            found = 0;
            for (i = 0; i < 127; i++) {
                if (CARDGetStatus(card_channel, i, &stat) >= 0) {
                    OSTicksToCalendarTime(stat.time * (__OSBusClock / 4), &ct);
                    sprintf(date, "%4d/%02d/%02d %02d:%02d:%02d", ct.year, ct.mon + 1, ct.mday, ct.hour, ct.min, ct.sec);
                    if (strcmp(stat.fileName, load_request_slots[card_channel].name) == 0 &&
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
                load_request_slots[card_channel].status = -102;
            } else {
                load_request_slots[card_channel].status = 0;
            }
            load_request_slots[card_channel].step = 0x16;
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

    switch (load_request_slots[card_channel].step) {

    case 0x11:
        if (TAdPlayerLoadGC::get_or_set_channel_flag(card_channel, 2) == 1) {
            saved_card_disk_id = CARDGetDiskID(card_channel);
            memcpy(&card_disk_id, saved_card_disk_id, sizeof(card_disk_id));
            memcpy(card_disk_id.gameName, card_game_name, sizeof(card_disk_id.gameName));
            memcpy(card_disk_id.company, card_company, sizeof(card_disk_id.company));
            CARDSetDiskID(card_channel, &card_disk_id);
        }
        load_request_slots[card_channel].result = CARDSetAttributesAsync(card_channel, load_request_slots[card_channel].file_no, load_request_slots[card_channel].attr, 0);
        if (load_request_slots[card_channel].result < 0) {
            if (TAdPlayerLoadGC::get_or_set_channel_flag(card_channel, 2) == 1 && saved_card_disk_id != NULL) {
                CARDSetDiskID(card_channel, saved_card_disk_id);
            }
            load_request_slots[card_channel].status = -0xD4;
            load_request_slots[card_channel].step = 0x18;
            break;
        }
        load_request_slots[card_channel].step = 0x12;
    case 0x12:
        load_request_slots[card_channel].result = CARDGetResultCode(card_channel);
        if (load_request_slots[card_channel].result == 0) {
            if (TAdPlayerLoadGC::get_or_set_channel_flag(card_channel, 2) == 1 && saved_card_disk_id != NULL) {
                CARDSetDiskID(card_channel, saved_card_disk_id);
            }
            load_request_slots[card_channel].status = 0;
            load_request_slots[card_channel].step = 0x16;
        } else if (load_request_slots[card_channel].result != -1) {
            if (TAdPlayerLoadGC::get_or_set_channel_flag(card_channel, 2) == 1 && saved_card_disk_id != NULL) {
                CARDSetDiskID(card_channel, saved_card_disk_id);
            }
            load_request_slots[card_channel].status = -0xD4;
            load_request_slots[card_channel].step = 0x18;
        }
        break;
    case 0x13: case 0x14: case 0x15: case 0x16: case 0x17: case 0x18:
        return;
    }
}
void TAdPlayerLoadGC::update_card_delete(s32 card_channel) {
    CardRequestSlot *s;

    switch (load_request_slots[card_channel].step) {
    case 0xF:
        if (TAdPlayerLoadGC::get_or_set_channel_flag(card_channel, 2) == 1) {
            saved_card_disk_id = CARDGetDiskID(card_channel);
            memcpy(&card_disk_id, saved_card_disk_id, sizeof(card_disk_id));
            memcpy(card_disk_id.gameName, card_game_name, sizeof(card_disk_id.gameName));
            memcpy(card_disk_id.company, card_company, sizeof(card_disk_id.company));
            CARDSetDiskID(card_channel, &card_disk_id);
        }
        load_request_slots[card_channel].result = CARDDeleteAsync(card_channel, load_request_slots[card_channel].name, 0);
        if (load_request_slots[card_channel].result < 0) {
            if (TAdPlayerLoadGC::get_or_set_channel_flag(card_channel, 2) == 1 && saved_card_disk_id != NULL) {
                CARDSetDiskID(card_channel, saved_card_disk_id);
            }
            load_request_slots[card_channel].status = -0xD3;
            load_request_slots[card_channel].step = 0x18;
            break;
        }
        load_request_slots[card_channel].step = 0x10;
    case 0x10:
        load_request_slots[card_channel].result = CARDGetResultCode(card_channel);
        if (load_request_slots[card_channel].result == 0) {
            if (TAdPlayerLoadGC::get_or_set_channel_flag(card_channel, 2) == 1 && saved_card_disk_id != NULL) {
                CARDSetDiskID(card_channel, saved_card_disk_id);
            }
            load_request_slots[card_channel].status = 0;
            load_request_slots[card_channel].step = 0x16;
        } else if (load_request_slots[card_channel].result != -1) {
            if (TAdPlayerLoadGC::get_or_set_channel_flag(card_channel, 2) == 1 && saved_card_disk_id != NULL) {
                CARDSetDiskID(card_channel, saved_card_disk_id);
            }
            load_request_slots[card_channel].status = -0xD3;
            load_request_slots[card_channel].step = 0x18;
        }
        break;
    case 0x11: case 0x12: case 0x13: case 0x14: case 0x15: case 0x16: case 0x17: case 0x18:
        return;
    }
}
void TAdPlayerLoadGC::update_card_rename(s32 card_channel) {

    switch (load_request_slots[card_channel].step) {
    case 0xd:
        if (TAdPlayerLoadGC::get_or_set_channel_flag(card_channel, 2) == 1) {
            saved_card_disk_id = CARDGetDiskID(card_channel);
            memcpy(&card_disk_id, saved_card_disk_id, sizeof(card_disk_id));
            memcpy(card_disk_id.gameName, card_game_name, sizeof(card_disk_id.gameName));
            memcpy(card_disk_id.company, card_company, sizeof(card_disk_id.company));
            CARDSetDiskID(card_channel, &card_disk_id);
        }
        load_request_slots[card_channel].result = CARDRenameAsync(card_channel, load_request_slots[card_channel].name, load_request_slots[card_channel].new_name, 0);
        if (load_request_slots[card_channel].result < 0) {
            if (TAdPlayerLoadGC::get_or_set_channel_flag(card_channel, 2) == 1 && saved_card_disk_id != NULL) {
                CARDSetDiskID(card_channel, saved_card_disk_id);
            }
            load_request_slots[card_channel].status = -210;
            load_request_slots[card_channel].step = 0x18;
            break;
        }
        load_request_slots[card_channel].step = 0xe;
    case 0xe:
        load_request_slots[card_channel].result = CARDGetResultCode(card_channel);
        if (load_request_slots[card_channel].result == 0) {
            if (TAdPlayerLoadGC::get_or_set_channel_flag(card_channel, 2) == 1 && saved_card_disk_id != NULL) {
                CARDSetDiskID(card_channel, saved_card_disk_id);
            }
            load_request_slots[card_channel].status = 0;
            load_request_slots[card_channel].step = 0x16;
        } else if (load_request_slots[card_channel].result != -1) {
            if (TAdPlayerLoadGC::get_or_set_channel_flag(card_channel, 2) == 1 && saved_card_disk_id != NULL) {
                CARDSetDiskID(card_channel, saved_card_disk_id);
            }
            load_request_slots[card_channel].status = -210;
            load_request_slots[card_channel].step = 0x18;
        }
        break;
    case 0xf: case 0x10: case 0x11: case 0x12: case 0x13: case 0x14: case 0x15: case 0x16: case 0x17: case 0x18:
        return;
    }
}
#pragma push
#pragma opt_propagation off
#pragma opt_lifetimes off
void update_card_write(s32 file) {
    s32 id;
    s32 *channel;
    s32 off;
    s32 *st;
    s32 *result;
    s32 ioff;

    off = file * 0x88;
    channel = (s32 *)((u8 *)&card_open_files[0].channel + off);
    st = &load_request_slots[0].step;
    id = *channel;

    switch (st[id * 0x1A]) {
    case 0xB:
        if (TAdPlayerLoadGC::get_or_set_channel_flag(id, 2) == 1) {
            saved_card_disk_id = CARDGetDiskID(id);
            memcpy(&card_disk_id, saved_card_disk_id, sizeof(card_disk_id));
            memcpy(card_disk_id.gameName, card_game_name, sizeof(card_disk_id.gameName));
            memcpy(card_disk_id.company, card_company, sizeof(card_disk_id.company));
            CARDSetDiskID(id, &card_disk_id);
        }
        {
            CARDFileInfo *info = &((CardFileEntry *)((u8 *)card_open_files + off))->file_info;
            s32 rc;
            rc = CARDWriteAsync(info, load_request_slots[*channel].buffer, load_request_slots[*channel].length, load_request_slots[*channel].offset, 0);
            ioff = *channel * 0x68;
            result = (s32 *)((u8 *)&load_request_slots[0].result + ioff);
            *result = rc;
        }
        if (*result < 0) {
            id = *channel;
            if (TAdPlayerLoadGC::get_or_set_channel_flag(id, 2) == 1 && saved_card_disk_id != NULL) {
                CARDSetDiskID(id, saved_card_disk_id);
            }
            ioff = *channel * 0x68;
            load_request_slots[*channel].status = -0xCE;
            *(s32 *)((u8 *)st + ioff) = 0x18;
            break;
        }
        *(s32 *)((u8 *)st + ioff) = 0xC;
    case 0xC:
        {
            s32 r = CARDGetResultCode(*channel);
            result = (s32 *)((u8 *)&load_request_slots[0].result + *channel * 0x68);
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
                    load_request_slots[*channel].status = -0xCE;
                    *(s32 *)((u8 *)st + ioff) = 0x18;
                }
                break;
            }
        }
    case 0x14:
        id = *channel;
        if (TAdPlayerLoadGC::get_or_set_channel_flag(id, 2) == 1) {
            saved_card_disk_id = CARDGetDiskID(id);
            memcpy(&card_disk_id, saved_card_disk_id, sizeof(card_disk_id));
            memcpy(card_disk_id.gameName, card_game_name, sizeof(card_disk_id.gameName));
            memcpy(card_disk_id.company, card_company, sizeof(card_disk_id.company));
            CARDSetDiskID(id, &card_disk_id);
        }
        {
            CardFileEntry *entry = (CardFileEntry *)((u8 *)card_open_files + off);
            s32 rc;
            rc = CARDSetStatusAsync(*channel, entry->file_info.fileNo, &entry->stat, 0);
            ioff = *channel * 0x68;
            result = (s32 *)((u8 *)&load_request_slots[0].result + ioff);
            *result = rc;
        }
        if (*result < 0) {
            id = *channel;
            if (TAdPlayerLoadGC::get_or_set_channel_flag(id, 2) == 1 && saved_card_disk_id != NULL) {
                CARDSetDiskID(id, saved_card_disk_id);
            }
            ioff = *channel * 0x68;
            load_request_slots[*channel].status = -0xD0;
            *(s32 *)((u8 *)st + ioff) = 0x18;
            break;
        }
        *(s32 *)((u8 *)st + ioff) = 0x15;
    case 0x15:
        {
            s32 r = CARDGetResultCode(*channel);
            result = (s32 *)((u8 *)&load_request_slots[0].result + *channel * 0x68);
            *result = r;
            if (*result == 0) {
                id = *channel;
                if (TAdPlayerLoadGC::get_or_set_channel_flag(id, 2) == 1 && saved_card_disk_id != NULL) {
                    CARDSetDiskID(id, saved_card_disk_id);
                }
                ioff = *channel * 0x68;
                load_request_slots[*channel].status = 0;
                *(s32 *)((u8 *)st + ioff) = 0x16;
            } else if (*result != -1) {
                id = *channel;
                if (TAdPlayerLoadGC::get_or_set_channel_flag(id, 2) == 1 && saved_card_disk_id != NULL) {
                    CARDSetDiskID(id, saved_card_disk_id);
                }
                ioff = *channel * 0x68;
                load_request_slots[*channel].status = -0xD0;
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
void update_card_read(s32 file) {
    s32 id;
    s32 *channel;
    s32 *st;
    s32 off;
    s32 *result;
    s32 ioff;

    off = file * 0x88;
    channel = (s32 *)((u8 *)&card_open_files[0].channel + off);
    st = &load_request_slots[0].step;
    id = *channel;

    switch (st[id * 0x1A]) {
    case 0x9:
        if (TAdPlayerLoadGC::get_or_set_channel_flag(id, 2) == 1) {
            saved_card_disk_id = CARDGetDiskID(id);
            memcpy(&card_disk_id, saved_card_disk_id, sizeof(card_disk_id));
            memcpy(card_disk_id.gameName, card_game_name, sizeof(card_disk_id.gameName));
            memcpy(card_disk_id.company, card_company, sizeof(card_disk_id.company));
            CARDSetDiskID(id, &card_disk_id);
        }
        {
            CARDFileInfo *info = &((CardFileEntry *)((u8 *)card_open_files + off))->file_info;
            s32 rc;
            rc = CARDReadAsync(info, load_request_slots[*channel].buffer, load_request_slots[*channel].length, load_request_slots[*channel].offset, 0);
            ioff = *channel * 0x68;
            result = (s32 *)((u8 *)&load_request_slots[0].result + ioff);
            *result = rc;
        }
        if (*result < 0) {
            id = *channel;
            if (TAdPlayerLoadGC::get_or_set_channel_flag(id, 2) == 1 && saved_card_disk_id != NULL) {
                CARDSetDiskID(id, saved_card_disk_id);
            }
            ioff = *channel * 0x68;
            load_request_slots[*channel].status = -0xCD;
            *(s32 *)((u8 *)st + ioff) = 0x18;
            break;
        }
        *(s32 *)((u8 *)st + ioff) = 0xA;
    case 0xA:
        {
            s32 r = CARDGetResultCode(*channel);
            result = (s32 *)((u8 *)&load_request_slots[0].result + *channel * 0x68);
            *result = r;
            if (*result == 0) {
                id = *channel;
                if (TAdPlayerLoadGC::get_or_set_channel_flag(id, 2) == 1 && saved_card_disk_id != NULL) {
                    CARDSetDiskID(id, saved_card_disk_id);
                }
                ioff = *channel * 0x68;
                load_request_slots[*channel].status = 0;
                *(s32 *)((u8 *)st + ioff) = 0x16;
            } else if (*result != -1) {
                id = *channel;
                if (TAdPlayerLoadGC::get_or_set_channel_flag(id, 2) == 1 && saved_card_disk_id != NULL) {
                    CARDSetDiskID(id, saved_card_disk_id);
                }
                ioff = *channel * 0x68;
                load_request_slots[*channel].status = -0xCD;
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
void update_card_open(s32 file) {
    s32 *channel;
    s32 *st;
    s32 id;
    s32 off;
    s32 res;
    CardFileEntry *rec;

    off = file * 0x88;
    channel = (s32 *)((u8 *)&card_open_files[0].channel + off);
    st = &load_request_slots[0].step;
    id = *channel;

    switch (st[id * 0x1A]) {
    case 0x8:
        if (TAdPlayerLoadGC::get_or_set_channel_flag(id, 2) == 1) {
            saved_card_disk_id = CARDGetDiskID(id);
            memcpy(&card_disk_id, saved_card_disk_id, sizeof(card_disk_id));
            memcpy(card_disk_id.gameName, card_game_name, sizeof(card_disk_id.gameName));
            memcpy(card_disk_id.company, card_company, sizeof(card_disk_id.company));
            CARDSetDiskID(id, &card_disk_id);
        }
        res = CARDOpen(*channel, load_request_slots[*channel].name, &((CardFileEntry *)((u8 *)card_open_files + off))->file_info);
        id = *channel;
        load_request_slots[id].result = res;
        if (load_request_slots[id].result < 0) {
            id = *channel;
            if (TAdPlayerLoadGC::get_or_set_channel_flag(id, 2) == 1 && saved_card_disk_id != NULL) {
                CARDSetDiskID(id, saved_card_disk_id);
            }
            id = *channel;
            load_request_slots[id].status = -0xCC;
            st[id * 0x1A] = 0x18;
            return;
        }
        st[id * 0x1A] = 0x13;
    case 0x13:
        rec = (CardFileEntry *)(reinterpret_cast<size_t>(&card_disk_id) + off + OPEN_FILES_OFFSET);
        res = CARDGetStatus(*channel, *(s32 *)(reinterpret_cast<size_t>(&card_disk_id) + off + OPEN_FILE_NUMBER_OFFSET), &rec->stat);
        id = *channel;
        load_request_slots[id].result = res;
        if (load_request_slots[id].result < 0) {
            id = *channel;
            if (TAdPlayerLoadGC::get_or_set_channel_flag(id, 2) == 1 && saved_card_disk_id != NULL) {
                CARDSetDiskID(id, saved_card_disk_id);
            }
            id = *channel;
            load_request_slots[id].status = -0xCF;
            st[id * 0x1A] = 0x18;
            CARDClose(&rec->file_info);
        } else {
            id = *channel;
            if (TAdPlayerLoadGC::get_or_set_channel_flag(id, 2) == 1 && saved_card_disk_id != NULL) {
                CARDSetDiskID(id, saved_card_disk_id);
            }
            id = *channel;
            load_request_slots[id].status = 0;
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
void update_card_create(s32 file) {
  s32 *channel;
  s32 off;
  s32 *st;
  s32 id;
  s32 res;
  CardFileEntry *rec;
  off = file * 0x88;
  channel = (s32 *)((u8 *)&card_open_files[0].channel + off);
  st = &load_request_slots[0].step;
  id = *channel;
  switch (st[id * 0x1A])
  {
    case 0x6:
      if (TAdPlayerLoadGC::get_or_set_channel_flag(id, 2) == 1)
    {
      saved_card_disk_id = CARDGetDiskID(id);
      memcpy(&card_disk_id, saved_card_disk_id, sizeof(card_disk_id));
      memcpy(card_disk_id.gameName, card_game_name, sizeof(card_disk_id.gameName));
      memcpy(card_disk_id.company, card_company, sizeof(card_disk_id.company));
      CARDSetDiskID(id, &card_disk_id);
    }
      res = CARDCreateAsync(*channel, load_request_slots[*channel].name, load_request_slots[*channel].length, &((CardFileEntry *)((u8 *)card_open_files + off))->file_info, 0);
      id = *channel;
      load_request_slots[id].result = res;
      if (load_request_slots[id].result < 0)
    {
      id = *channel;
      if ((TAdPlayerLoadGC::get_or_set_channel_flag(id, 2) == 1) && (saved_card_disk_id != 0))
      {
        CARDSetDiskID(id, saved_card_disk_id);
      }
      id = *channel;
      load_request_slots[id].status = -0xCB;
      st[id * 0x1A] = 0x18;
      return;
    }
      st[id * 0x1A] = 0x7;

    case 0x7:
      res = CARDGetResultCode(*channel);
      id = *channel;
      load_request_slots[id].result = res;
      if (load_request_slots[id].result == 0)
    {
      id = *channel;
      if ((TAdPlayerLoadGC::get_or_set_channel_flag(id, 2) == 1) && (saved_card_disk_id != 0))
      {
        CARDSetDiskID(id, saved_card_disk_id);
      }
      st[(*channel) * 0x1A] = 0x13;
    }
    else
      if (load_request_slots[id].result == (-1))
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
      load_request_slots[id].status = -0xCB;
      st[id * 0x1A] = 0x18;
      return;
    }

    case 0x13:
      rec = (CardFileEntry *)((reinterpret_cast<size_t>(&card_disk_id) + off) + OPEN_FILES_OFFSET);
      res = CARDGetStatus(*channel, *((s32 *) ((reinterpret_cast<size_t>(&card_disk_id) + off) + OPEN_FILE_NUMBER_OFFSET)), &rec->stat);
      id = *channel;
      load_request_slots[id].result = res;
      if (load_request_slots[id].result < 0)
    {
      load_request_slots[id].status = -0xCF;
      st[id * 0x1A] = 0x18;
      CARDClose(&rec->file_info);
    }
    else
    {
      load_request_slots[id].status = 0;
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

void card_check_callback(s32 card_channel, s32 result) {
    load_request_slots[card_channel].result = result;
    switch (result) {
    default:
        load_request_slots[card_channel].status = -201;
        load_request_slots[card_channel].step = 0x18;
        break;
    case 0:
    case -6:
        load_request_slots[card_channel].step = 5;
        break;
    }
}


void update_card_mount(s32 card_channel) {

    switch (load_request_slots[card_channel].step) {
    case 1:
        load_request_slots[card_channel].result = CARDMountAsync(card_channel, card_work_area, 0, 0);
        if (load_request_slots[card_channel].result < 0) {
            load_request_slots[card_channel].status = -200;
            load_request_slots[card_channel].step = 0x18;
            break;
        }
        load_request_slots[card_channel].step = 2;
    case 2:
        load_request_slots[card_channel].result = CARDGetResultCode(card_channel);
        if (load_request_slots[card_channel].result == 0 || load_request_slots[card_channel].result == -6) {
            load_request_slots[card_channel].step = 3;
        } else {
            if (load_request_slots[card_channel].result != -1) {
                load_request_slots[card_channel].status = -200;
                load_request_slots[card_channel].step = 0x18;
            }
            break;
        }
    case 3:
        load_request_slots[card_channel].result = CARDCheckAsync(card_channel, card_check_callback);
        if (load_request_slots[card_channel].result < 0) {
            load_request_slots[card_channel].status = -201;
            load_request_slots[card_channel].step = 0x18;
            break;
        }
        load_request_slots[card_channel].step = 4;
    case 4:
        load_request_slots[card_channel].result = CARDGetResultCode(card_channel);
        if (load_request_slots[card_channel].result == 0) {
            load_request_slots[card_channel].step = 5;
        } else {
            if (load_request_slots[card_channel].result != -1) {
                load_request_slots[card_channel].status = -201;
                load_request_slots[card_channel].step = 0x18;
                CARDUnmount(card_channel);
            }
            break;
        }
    case 5:
        load_request_slots[card_channel].result = CARDGetSectorSize(card_channel, &card_slot_info[card_channel].sector_size);
        if (load_request_slots[card_channel].result < 0) {
            load_request_slots[card_channel].status = -202;
            load_request_slots[card_channel].step = 0x18;
            CARDUnmount(card_channel);
            break;
        }
        load_request_slots[card_channel].status = 0;
        load_request_slots[card_channel].step = 0x16;
        break;
    case 0: case 6: case 7: case 8: case 9: case 0xA: case 0xB: case 0xC:
    case 0xD: case 0xE: case 0xF: case 0x10: case 0x11: case 0x12: case 0x13: case 0x14: case 0x15: case 0x16: case 0x17: case 0x18:
        return;
    }
}

s32 update_card_requests(void) {
    s32 i;
    s32 result;
    s32 mem_size;
    s32 sector_size;
    BOOL enabled;

    if (card_lib_state < 1) {
        return -1;
    }
    if (card_poll_depth != 0) {
        return 0;
    }
    card_poll_depth++;
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
                    if (card_detach_callback != NULL) {
                        enabled = OSDisableInterrupts();
                        card_detach_callback(i, mem_size, sector_size);
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
                if (card_attach_callback != NULL) {
                    enabled = OSDisableInterrupts();
                    card_attach_callback(i, card_slot_info[i].mem_size, card_slot_info[i].sector_size);
                    OSRestoreInterrupts(enabled);
                }
            }
            break;
        case -1:
            break;
        }
    }
    for (i = 0; i < 2; i++) {
        switch (load_request_slots[i].kind) {
        case 1:
            update_card_mount(i);
            break;
        case 2:
            update_card_create(load_request_slots[i].file_index);
            break;
        case 3:
            update_card_open(load_request_slots[i].file_index);
            break;
        case 5:
            update_card_write(load_request_slots[i].file_index);
            break;
        case 4:
            update_card_read(load_request_slots[i].file_index);
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
            update_card_find(i);
            break;
        }
    }
    card_poll_depth--;
    return 0;
}

s32 check_card_lib_ready(void) {
    if (card_lib_state == 0) {
        return -1;
    }
    return 0;
}

s32 init_card_lib(void *work_area) {
    s32 i;

    mcfs_version_ref = mcfs_version;
    if (card_lib_state > 0) {
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
    card_work_area = work_area;
    card_attach_callback = NULL;
    card_detach_callback = NULL;
    card_lib_state = 1;
    memset(card_open_files, 0, sizeof(card_open_files));
    return 0;
}

void TAdPlayerLoadGC::reset_slot_entry(s32 channel) {
    CardRequestSlot *slot = &load_request_slots[channel];
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
s32 TAdPlayerLoadGC::close_card_slot(s32 file_handle) {
    CardFileEntry *s;
    s32 ret;
    if (file_handle >= 0 && file_handle < 0x64) {
        s = &card_open_files[file_handle];
        ret = CARDClose(&s->file_info);
        memset(s, 0, 0x88);
        s->channel = 2;
    }
    return ret;
}
