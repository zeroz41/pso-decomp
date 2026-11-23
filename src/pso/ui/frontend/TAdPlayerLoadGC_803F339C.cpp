#include "types.h"
#include "pso/ui/frontend/TAdPlayerLoadGC_803F339C.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include <string.h>
#define PSO_SDK_COMPACT_MATH
#include "pso/ui/frontend/CardFileEntry.h"
#undef PSO_SDK_COMPACT_MATH

extern "C" {
extern CardRequestSlot load_request_slots[];
extern CardFileEntry card_open_files[];

s32 TAdPlayerLoadGC::take_card_read_result(s32 arg0, s32 *arg1) {
    s32 r;
    s32 t;
    if (TAdPlayerLoadGC::get_load_state() < 1) {
        return -1;
    }
    if (load_request_slots[arg0].kind == 0x4) {
        *arg1 = load_request_slots[arg0].result;
        t = load_request_slots[arg0].status;
        r = t;
        if (t != 200) {
            load_request_slots[arg0].buffer = NULL;
            memset(load_request_slots[arg0].name, 0, 0x20);
            memset(load_request_slots[arg0].new_name, 0, 0x20);
            load_request_slots[arg0].kind = 0;
            load_request_slots[arg0].step = 0;
            load_request_slots[arg0].offset = 0;
            load_request_slots[arg0].length = 0;
            load_request_slots[arg0].file_index = -1;
            load_request_slots[arg0].status = 0;
            load_request_slots[arg0].result = 0;
        }
    } else {
        *arg1 = 0;
        r = -4;
    }
    return r;
}

s32 TAdPlayerLoadGC::request_card_read(s32 file, void *buffer, s32 length, s32 offset) {
    s32 chan;

    if (TAdPlayerLoadGC::get_load_state() < 1) {
        return -1;
    }
    if (file < 0 || file >= 100 || ((chan = card_open_files[file].channel) != 0 && chan != 1)) {
        return -2;
    }
    if (load_request_slots[chan].kind != 0) {
        return -4;
    }
    load_request_slots[chan].kind = 4;
    load_request_slots[chan].step = 9;
    load_request_slots[chan].status = 200;
    load_request_slots[chan].buffer = buffer;
    load_request_slots[chan].length = length;
    load_request_slots[chan].offset = offset;
    load_request_slots[chan].file_index = file;
    return 0;
}
s32 TAdPlayerLoadGC::take_card_open_result(s32 arg0, s32 *arg1) {
    s32 r;
    s32 t;

    if (TAdPlayerLoadGC::get_load_state() < 1) {
        return -1;
    }
    if (load_request_slots[arg0].kind == 3) {
        *arg1 = load_request_slots[arg0].result;
        t = load_request_slots[arg0].status;
        r = t;
        if (t != 200) {
            if (r != 0) {
                memset(&card_open_files[load_request_slots[arg0].file_index], 0, 0x88);
                card_open_files[load_request_slots[arg0].file_index].channel = 2;
            }
            load_request_slots[arg0].buffer = NULL;
            memset(load_request_slots[arg0].name, 0, 0x20);
            memset(load_request_slots[arg0].new_name, 0, 0x20);
            load_request_slots[arg0].kind = 0;
            load_request_slots[arg0].step = 0;
            load_request_slots[arg0].offset = 0;
            load_request_slots[arg0].length = 0;
            load_request_slots[arg0].file_index = -1;
            load_request_slots[arg0].status = 0;
            load_request_slots[arg0].result = 0;
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
    if (load_request_slots[chan].kind != 0) {
        return -4;
    }
    i = 0;
    while (i < 100) {
        if (card_open_files[i].in_use == 0) {
            break;
        }
        i++;
    }
    if (i == 100) {
        return -204;
    }
    card_open_files[i].in_use = 1;
    pc = &card_open_files[i].channel;
    *pc = chan;
    idx = *pc;
    load_request_slots[idx].kind = 3;
    load_request_slots[idx].step = 8;
    load_request_slots[idx].status = 200;
    memset(load_request_slots[idx].name, 0, 0x20);
    strcpy(load_request_slots[*pc].name, name);
    load_request_slots[*pc].file_index = i;
    return i;
}
#pragma pop

void TAdPlayerLoadGC::unmount_card(s32 chan) {
    CARDUnmount(chan);
}
s32 TAdPlayerLoadGC::take_card_mount_result(s32 arg0, s32 *arg1) {
    s32 r;
    s32 t;

    if (TAdPlayerLoadGC::get_load_state() < 1) {
        return -1;
    }
    if (load_request_slots[arg0].kind == 1) {
        *arg1 = load_request_slots[arg0].result;
        t = load_request_slots[arg0].status;
        r = t;
        if (t != 200) {
            load_request_slots[arg0].buffer = NULL;
            memset(load_request_slots[arg0].name, 0, 0x20);
            memset(load_request_slots[arg0].new_name, 0, 0x20);
            load_request_slots[arg0].kind = 0;
            load_request_slots[arg0].step = 0;
            load_request_slots[arg0].offset = 0;
            load_request_slots[arg0].length = 0;
            load_request_slots[arg0].file_index = -1;
            load_request_slots[arg0].status = 0;
            load_request_slots[arg0].result = 0;
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
    if (load_request_slots[chan].kind != 0) {
        r = -4;
    } else {
        load_request_slots[chan].kind = 1;
        load_request_slots[chan].step = 1;
        r = 0;
        load_request_slots[chan].status = 200;
    }
    return r;
}

s32 TAdPlayerLoadGC::take_card_find_result(s32 arg0, s32 *arg1) {
    s32 r;
    s32 t;

    if (TAdPlayerLoadGC::get_load_state() < 1) {
        return -1;
    }
    if (load_request_slots[arg0].kind == 9) {
        *arg1 = load_request_slots[arg0].result;
        t = load_request_slots[arg0].status;
        r = t;
        if (t != 200) {
            load_request_slots[arg0].buffer = NULL;
            memset(load_request_slots[arg0].name, 0, 0x20);
            memset(load_request_slots[arg0].new_name, 0, 0x20);
            load_request_slots[arg0].kind = 0;
            load_request_slots[arg0].step = 0;
            load_request_slots[arg0].offset = 0;
            load_request_slots[arg0].length = 0;
            load_request_slots[arg0].file_index = -1;
            load_request_slots[arg0].status = 0;
            load_request_slots[arg0].result = 0;
        }
    } else {
        *arg1 = 0;
        r = -4;
    }
    return r;
}
s32 TAdPlayerLoadGC::request_card_find(s32 arg0, const char *arg1) {
    s32 r = 0;
    s32 n = 0;

    if (TAdPlayerLoadGC::get_load_state() < 1) {
        return -1;
    }
    if (strlen(arg1) >= 0x20) {
        return -2;
    }
    if (load_request_slots[arg0].kind != 0) {
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
    load_request_slots[arg0].kind = 9;
    load_request_slots[arg0].step = 1;
    load_request_slots[arg0].status = 200;
    memset(load_request_slots[arg0].name, 0, 0x20);
    strcpy(load_request_slots[arg0].name, arg1);
    return 0;
}
}
