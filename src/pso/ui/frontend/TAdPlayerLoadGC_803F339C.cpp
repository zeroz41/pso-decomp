#include "types.h"
#include "pso/ui/frontend/TAdPlayerLoadGC_803F339C.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/network/NetworkInfoLoader.h"
#include <dolphin/os/OSAlloc.h>

// One entry of the open-file table: in use, the card slot it is on (2 = none) and its CARD handles.
struct CardFileEntry { s16 in_use; s16 pad2; s32 channel; u8 card[0x80]; }; // card: CARDFileInfo, CARDStat

extern "C" {
s32 CARDUnmount(s32 chan);
s32 memset(void *, int, int);
extern CardRequestSlot TAdPlayerLoadGC__load_request_slots[];
extern CardFileEntry lbl_805A29B0[];
s32 CARDProbe(s32 chan);
char *strcpy(char *, const char *);
u32 strlen(const char *);
extern const char *lbl_805D79AC;
extern const char *const lbl_805E10F8;
extern s32 lobby_net_config_mode;
extern s32 lbl_805D7984;
extern s32 lobby_net_config_load_state;
extern u8 *lobby_net_config_buffer;
extern u8 *lobby_net_config_card_base;

s32 TAdPlayerLoadGC::finish_load_slot_state4(s32 arg0, s32 *arg1) {
    s32 r;
    s32 t;
    if (TAdPlayerLoadGC::get_load_state() < 1) {
        return -1;
    }
    if (TAdPlayerLoadGC__load_request_slots[arg0].kind == 0x4) {
        *arg1 = TAdPlayerLoadGC__load_request_slots[arg0].result;
        t = TAdPlayerLoadGC__load_request_slots[arg0].status;
        r = t;
        if (t != 200) {
            TAdPlayerLoadGC__load_request_slots[arg0].buffer = 0;
            memset(TAdPlayerLoadGC__load_request_slots[arg0].name, 0, 0x20);
            memset(TAdPlayerLoadGC__load_request_slots[arg0].new_name, 0, 0x20);
            TAdPlayerLoadGC__load_request_slots[arg0].kind = 0;
            TAdPlayerLoadGC__load_request_slots[arg0].step = 0;
            TAdPlayerLoadGC__load_request_slots[arg0].offset = 0;
            TAdPlayerLoadGC__load_request_slots[arg0].length = 0;
            TAdPlayerLoadGC__load_request_slots[arg0].file_index = -1;
            TAdPlayerLoadGC__load_request_slots[arg0].status = 0;
            TAdPlayerLoadGC__load_request_slots[arg0].result = 0;
        }
    } else {
        *arg1 = 0;
        r = -4;
    }
    return r;
}

s32 TAdPlayerLoadGC::queue_network_request(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 chan;

    if (TAdPlayerLoadGC::get_load_state() < 1) {
        return -1;
    }
    if (arg0 < 0 || arg0 >= 100 || ((chan = lbl_805A29B0[arg0].channel) != 0 && chan != 1)) {
        return -2;
    }
    if (TAdPlayerLoadGC__load_request_slots[chan].kind != 0) {
        return -4;
    }
    TAdPlayerLoadGC__load_request_slots[chan].kind = 4;
    TAdPlayerLoadGC__load_request_slots[chan].step = 9;
    TAdPlayerLoadGC__load_request_slots[chan].status = 200;
    TAdPlayerLoadGC__load_request_slots[chan].buffer = arg1;
    TAdPlayerLoadGC__load_request_slots[chan].length = arg2;
    TAdPlayerLoadGC__load_request_slots[chan].offset = arg3;
    TAdPlayerLoadGC__load_request_slots[chan].file_index = arg0;
    return 0;
}
s32 TAdPlayerLoadGC::finish_load_slot_state3(s32 arg0, s32 *arg1) {
    s32 r;
    s32 t;

    if (TAdPlayerLoadGC::get_load_state() < 1) {
        return -1;
    }
    if (TAdPlayerLoadGC__load_request_slots[arg0].kind == 3) {
        *arg1 = TAdPlayerLoadGC__load_request_slots[arg0].result;
        t = TAdPlayerLoadGC__load_request_slots[arg0].status;
        r = t;
        if (t != 200) {
            if (r != 0) {
                memset(&lbl_805A29B0[TAdPlayerLoadGC__load_request_slots[arg0].file_index], 0, 0x88);
                lbl_805A29B0[TAdPlayerLoadGC__load_request_slots[arg0].file_index].channel = 2;
            }
            TAdPlayerLoadGC__load_request_slots[arg0].buffer = 0;
            memset(TAdPlayerLoadGC__load_request_slots[arg0].name, 0, 0x20);
            memset(TAdPlayerLoadGC__load_request_slots[arg0].new_name, 0, 0x20);
            TAdPlayerLoadGC__load_request_slots[arg0].kind = 0;
            TAdPlayerLoadGC__load_request_slots[arg0].step = 0;
            TAdPlayerLoadGC__load_request_slots[arg0].offset = 0;
            TAdPlayerLoadGC__load_request_slots[arg0].length = 0;
            TAdPlayerLoadGC__load_request_slots[arg0].file_index = -1;
            TAdPlayerLoadGC__load_request_slots[arg0].status = 0;
            TAdPlayerLoadGC__load_request_slots[arg0].result = 0;
        }
    } else {
        *arg1 = 0;
        r = -4;
    }
    return r;
}

#pragma push
#pragma opt_dead_assignments off
#pragma optimize_for_size off
s32 TAdPlayerLoadGC::begin_card_file_request(s32 chan, const char *name) {
    s32 i;
    s32 *pc;
    s32 idx;
    if (TAdPlayerLoadGC::get_load_state() < 1) {
        return -1;
    }
    if (strlen(name) >= 0x20) {
        return -2;
    }
    if (TAdPlayerLoadGC__load_request_slots[chan].kind != 0) {
        return -4;
    }
    i = 0;
    while (i < 100) {
        if (lbl_805A29B0[i].in_use == 0) {
            break;
        }
        i++;
    }
    if (i == 100) {
        return -204;
    }
    lbl_805A29B0[i].in_use = 1;
    pc = &lbl_805A29B0[i].channel;
    *pc = chan;
    idx = *pc;
    TAdPlayerLoadGC__load_request_slots[idx].kind = 3;
    TAdPlayerLoadGC__load_request_slots[idx].step = 8;
    TAdPlayerLoadGC__load_request_slots[idx].status = 200;
    memset(TAdPlayerLoadGC__load_request_slots[idx].name, 0, 0x20);
    strcpy(TAdPlayerLoadGC__load_request_slots[*pc].name, name);
    TAdPlayerLoadGC__load_request_slots[*pc].file_index = i;
    return i;
}
#pragma pop

void TAdPlayerLoadGC::unmount_card(s32 chan) {
    CARDUnmount(chan);
}
s32 TAdPlayerLoadGC::take_network_info_load_result(s32 arg0, s32 *arg1) {
    s32 r;
    s32 t;

    if (TAdPlayerLoadGC::get_load_state() < 1) {
        return -1;
    }
    if (TAdPlayerLoadGC__load_request_slots[arg0].kind == 1) {
        *arg1 = TAdPlayerLoadGC__load_request_slots[arg0].result;
        t = TAdPlayerLoadGC__load_request_slots[arg0].status;
        r = t;
        if (t != 200) {
            TAdPlayerLoadGC__load_request_slots[arg0].buffer = 0;
            memset(TAdPlayerLoadGC__load_request_slots[arg0].name, 0, 0x20);
            memset(TAdPlayerLoadGC__load_request_slots[arg0].new_name, 0, 0x20);
            TAdPlayerLoadGC__load_request_slots[arg0].kind = 0;
            TAdPlayerLoadGC__load_request_slots[arg0].step = 0;
            TAdPlayerLoadGC__load_request_slots[arg0].offset = 0;
            TAdPlayerLoadGC__load_request_slots[arg0].length = 0;
            TAdPlayerLoadGC__load_request_slots[arg0].file_index = -1;
            TAdPlayerLoadGC__load_request_slots[arg0].status = 0;
            TAdPlayerLoadGC__load_request_slots[arg0].result = 0;
        }
    } else {
        *arg1 = 0;
        r = -4;
    }
    return r;
}

s32 TAdPlayerLoadGC__sub_803F3998(s32 chan) {
    s32 r;
    if (TAdPlayerLoadGC::get_load_state() < 1) {
        return -1;
    }
    if (TAdPlayerLoadGC__load_request_slots[chan].kind != 0) {
        r = -4;
    } else {
        TAdPlayerLoadGC__load_request_slots[chan].kind = 1;
        TAdPlayerLoadGC__load_request_slots[chan].step = 1;
        r = 0;
        TAdPlayerLoadGC__load_request_slots[chan].status = 200;
    }
    return r;
}

s32 TAdPlayerLoadGC::take_network_info_poll_result(s32 arg0, s32 *arg1) {
    s32 r;
    s32 t;

    if (TAdPlayerLoadGC::get_load_state() < 1) {
        return -1;
    }
    if (TAdPlayerLoadGC__load_request_slots[arg0].kind == 9) {
        *arg1 = TAdPlayerLoadGC__load_request_slots[arg0].result;
        t = TAdPlayerLoadGC__load_request_slots[arg0].status;
        r = t;
        if (t != 200) {
            TAdPlayerLoadGC__load_request_slots[arg0].buffer = 0;
            memset(TAdPlayerLoadGC__load_request_slots[arg0].name, 0, 0x20);
            memset(TAdPlayerLoadGC__load_request_slots[arg0].new_name, 0, 0x20);
            TAdPlayerLoadGC__load_request_slots[arg0].kind = 0;
            TAdPlayerLoadGC__load_request_slots[arg0].step = 0;
            TAdPlayerLoadGC__load_request_slots[arg0].offset = 0;
            TAdPlayerLoadGC__load_request_slots[arg0].length = 0;
            TAdPlayerLoadGC__load_request_slots[arg0].file_index = -1;
            TAdPlayerLoadGC__load_request_slots[arg0].status = 0;
            TAdPlayerLoadGC__load_request_slots[arg0].result = 0;
        }
    } else {
        *arg1 = 0;
        r = -4;
    }
    return r;
}
s32 TAdPlayerLoadGC::request_card_open(s32 arg0, const char *arg1) {
    s32 r = 0;
    s32 n = 0;

    if (TAdPlayerLoadGC::get_load_state() < 1) {
        return -1;
    }
    if (strlen(arg1) >= 0x20) {
        return -2;
    }
    if (TAdPlayerLoadGC__load_request_slots[arg0].kind != 0) {
        return -4;
    }
    while (r != 1) {
        if (0x19000 <= n) {
            break;
        }
        r = CARDProbe(arg0);
        n++;
    }
    if (r != 1) {
        return -100;
    }
    TAdPlayerLoadGC__load_request_slots[arg0].kind = 9;
    TAdPlayerLoadGC__load_request_slots[arg0].step = 1;
    TAdPlayerLoadGC__load_request_slots[arg0].status = 200;
    memset(TAdPlayerLoadGC__load_request_slots[arg0].name, 0, 0x20);
    strcpy(TAdPlayerLoadGC__load_request_slots[arg0].name, arg1);
    return 0;
}

// Stores the ntInf library version string ("ntInf Ver 1.17.00 Build:Jul  9 2002").
// The original realigns the stack to 32 bytes (clrlwi/subfic/stwux) without
// using it; no clean source found that does that (see NOTES of lane cJ).
s32 TLobby__sub_803F3BF8(s32 backup_mode, void *buffer, s32 mode) {
    lbl_805D79AC = lbl_805E10F8;
    if (get_network_config_mode() != 0) {
        return -1;
    }
    lobby_net_config_mode = mode;
    lbl_805D7984 = mode;
    if (backup_mode != 0) {
        return -2;
    }
    get_or_set_network_config_mode(1);
    get_or_set_network_config_backup_mode(backup_mode);
    lobby_net_config_load_state = 0;
    if (buffer == NULL) {
        lobby_net_config_buffer = (u8 *)OSAllocFromHeap(__OSCurrHeap, get_network_config_buffer_size(backup_mode));
        if (lobby_net_config_buffer == NULL) {
            return -4;
        }
        lobby_net_config_load_state = 1;
    } else {
        lobby_net_config_buffer = (u8 *)buffer;
    }
    if (backup_mode == 1) {
        lobby_net_config_card_base = lobby_net_config_buffer + 0x19D4;
    }
    set_network_config_card_channel(2);
    return 0;
}

}
