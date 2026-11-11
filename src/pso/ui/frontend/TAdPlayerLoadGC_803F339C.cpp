#include "types.h"
#include "pso/ui/frontend/TAdPlayerLoadGC_803F339C.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/network/NetworkInfoLoader.h"
#include <dolphin/os/OSAlloc.h>

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
    u8 pad60[8];
} Slot_803F3478;

struct S_803F3690 { s16 f0; s16 pad2; s32 state; u8 card[0x80]; };

extern "C" {
s32 CARDUnmount(s32 chan);
s32 memset(void *, int, int);
extern Slot_803F3478 TAdPlayerLoadGC__load_request_slots[];
extern S_803F3328 lbl_805A29B0[];
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
    if (TAdPlayerLoadGC__load_request_slots[arg0].f44 == 0x4) {
        *arg1 = TAdPlayerLoadGC__load_request_slots[arg0].f5C;
        t = TAdPlayerLoadGC__load_request_slots[arg0].f58;
        r = t;
        if (t != 200) {
            TAdPlayerLoadGC__load_request_slots[arg0].f0 = 0;
            memset(TAdPlayerLoadGC__load_request_slots[arg0].name, 0, 0x20);
            memset(TAdPlayerLoadGC__load_request_slots[arg0].name2, 0, 0x20);
            TAdPlayerLoadGC__load_request_slots[arg0].f44 = 0;
            TAdPlayerLoadGC__load_request_slots[arg0].f48 = 0;
            TAdPlayerLoadGC__load_request_slots[arg0].f4C = 0;
            TAdPlayerLoadGC__load_request_slots[arg0].f50 = 0;
            TAdPlayerLoadGC__load_request_slots[arg0].f54 = -1;
            TAdPlayerLoadGC__load_request_slots[arg0].f58 = 0;
            TAdPlayerLoadGC__load_request_slots[arg0].f5C = 0;
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
    if (arg0 < 0 || arg0 >= 100 || ((chan = lbl_805A29B0[arg0].state) != 0 && chan != 1)) {
        return -2;
    }
    if (TAdPlayerLoadGC__load_request_slots[chan].f44 != 0) {
        return -4;
    }
    TAdPlayerLoadGC__load_request_slots[chan].f44 = 4;
    TAdPlayerLoadGC__load_request_slots[chan].f48 = 9;
    TAdPlayerLoadGC__load_request_slots[chan].f58 = 200;
    TAdPlayerLoadGC__load_request_slots[chan].f0 = arg1;
    TAdPlayerLoadGC__load_request_slots[chan].f50 = arg2;
    TAdPlayerLoadGC__load_request_slots[chan].f4C = arg3;
    TAdPlayerLoadGC__load_request_slots[chan].f54 = arg0;
    return 0;
}
s32 TAdPlayerLoadGC::finish_load_slot_state3(s32 arg0, s32 *arg1) {
    s32 r;
    s32 t;

    if (TAdPlayerLoadGC::get_load_state() < 1) {
        return -1;
    }
    if (TAdPlayerLoadGC__load_request_slots[arg0].f44 == 3) {
        *arg1 = TAdPlayerLoadGC__load_request_slots[arg0].f5C;
        t = TAdPlayerLoadGC__load_request_slots[arg0].f58;
        r = t;
        if (t != 200) {
            if (r != 0) {
                memset(&lbl_805A29B0[TAdPlayerLoadGC__load_request_slots[arg0].f54], 0, 0x88);
                lbl_805A29B0[TAdPlayerLoadGC__load_request_slots[arg0].f54].state = 2;
            }
            TAdPlayerLoadGC__load_request_slots[arg0].f0 = 0;
            memset(TAdPlayerLoadGC__load_request_slots[arg0].name, 0, 0x20);
            memset(TAdPlayerLoadGC__load_request_slots[arg0].name2, 0, 0x20);
            TAdPlayerLoadGC__load_request_slots[arg0].f44 = 0;
            TAdPlayerLoadGC__load_request_slots[arg0].f48 = 0;
            TAdPlayerLoadGC__load_request_slots[arg0].f4C = 0;
            TAdPlayerLoadGC__load_request_slots[arg0].f50 = 0;
            TAdPlayerLoadGC__load_request_slots[arg0].f54 = -1;
            TAdPlayerLoadGC__load_request_slots[arg0].f58 = 0;
            TAdPlayerLoadGC__load_request_slots[arg0].f5C = 0;
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
    if (TAdPlayerLoadGC__load_request_slots[chan].f44 != 0) {
        return -4;
    }
    i = 0;
    while (i < 100) {
        if (((S_803F3690 *)&lbl_805A29B0)[i].f0 == 0) {
            break;
        }
        i++;
    }
    if (i == 100) {
        return -204;
    }
    ((S_803F3690 *)&lbl_805A29B0)[i].f0 = 1;
    pc = &((S_803F3690 *)&lbl_805A29B0)[i].state;
    *pc = chan;
    idx = *pc;
    TAdPlayerLoadGC__load_request_slots[idx].f44 = 3;
    TAdPlayerLoadGC__load_request_slots[idx].f48 = 8;
    TAdPlayerLoadGC__load_request_slots[idx].f58 = 200;
    memset(TAdPlayerLoadGC__load_request_slots[idx].name, 0, 0x20);
    strcpy(TAdPlayerLoadGC__load_request_slots[*pc].name, name);
    TAdPlayerLoadGC__load_request_slots[*pc].f54 = i;
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
    if (TAdPlayerLoadGC__load_request_slots[arg0].f44 == 1) {
        *arg1 = TAdPlayerLoadGC__load_request_slots[arg0].f5C;
        t = TAdPlayerLoadGC__load_request_slots[arg0].f58;
        r = t;
        if (t != 200) {
            TAdPlayerLoadGC__load_request_slots[arg0].f0 = 0;
            memset(TAdPlayerLoadGC__load_request_slots[arg0].name, 0, 0x20);
            memset(TAdPlayerLoadGC__load_request_slots[arg0].name2, 0, 0x20);
            TAdPlayerLoadGC__load_request_slots[arg0].f44 = 0;
            TAdPlayerLoadGC__load_request_slots[arg0].f48 = 0;
            TAdPlayerLoadGC__load_request_slots[arg0].f4C = 0;
            TAdPlayerLoadGC__load_request_slots[arg0].f50 = 0;
            TAdPlayerLoadGC__load_request_slots[arg0].f54 = -1;
            TAdPlayerLoadGC__load_request_slots[arg0].f58 = 0;
            TAdPlayerLoadGC__load_request_slots[arg0].f5C = 0;
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
    if (TAdPlayerLoadGC__load_request_slots[chan].f44 != 0) {
        r = -4;
    } else {
        TAdPlayerLoadGC__load_request_slots[chan].f44 = 1;
        TAdPlayerLoadGC__load_request_slots[chan].f48 = 1;
        r = 0;
        TAdPlayerLoadGC__load_request_slots[chan].f58 = 200;
    }
    return r;
}

s32 TAdPlayerLoadGC::take_network_info_poll_result(s32 arg0, s32 *arg1) {
    s32 r;
    s32 t;

    if (TAdPlayerLoadGC::get_load_state() < 1) {
        return -1;
    }
    if (TAdPlayerLoadGC__load_request_slots[arg0].f44 == 9) {
        *arg1 = TAdPlayerLoadGC__load_request_slots[arg0].f5C;
        t = TAdPlayerLoadGC__load_request_slots[arg0].f58;
        r = t;
        if (t != 200) {
            TAdPlayerLoadGC__load_request_slots[arg0].f0 = 0;
            memset(TAdPlayerLoadGC__load_request_slots[arg0].name, 0, 0x20);
            memset(TAdPlayerLoadGC__load_request_slots[arg0].name2, 0, 0x20);
            TAdPlayerLoadGC__load_request_slots[arg0].f44 = 0;
            TAdPlayerLoadGC__load_request_slots[arg0].f48 = 0;
            TAdPlayerLoadGC__load_request_slots[arg0].f4C = 0;
            TAdPlayerLoadGC__load_request_slots[arg0].f50 = 0;
            TAdPlayerLoadGC__load_request_slots[arg0].f54 = -1;
            TAdPlayerLoadGC__load_request_slots[arg0].f58 = 0;
            TAdPlayerLoadGC__load_request_slots[arg0].f5C = 0;
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
    if (TAdPlayerLoadGC__load_request_slots[arg0].f44 != 0) {
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
    TAdPlayerLoadGC__load_request_slots[arg0].f44 = 9;
    TAdPlayerLoadGC__load_request_slots[arg0].f48 = 1;
    TAdPlayerLoadGC__load_request_slots[arg0].f58 = 200;
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
