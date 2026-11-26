#include <string.h>
#include "types.h"
#include "pso/unk/text_8014618C.h"
#include "pso/unk/text_803F3BF8.h"
#include "pso/unk/text_803F4D84.h"
#include "pso/network/NetworkInfoLoader.h"
#include "pso/network/NetworkInfoRequests.h"
#include "pso/system/save/McFsGc.h"
#include "pso/system/save/McFsGcRequests.h"
#include "pso/unk/text_80145A94.h"
#include "pso/ui/frontend/TAdTrialModemChkGC.h"
#include "pso/system/main_loop.h"
#include "pso/system/memory.h"
#include "pso/network/TLobby.h"
#include "pso/unk/TLobby_80145E40.h"
#include "pso/system/SwitcherLaunch.h"




void *network_info_work;
u16 network_info_flags;
u16 network_config_open;
int network_lease_time;
s32 load_network_info(void) {
    LoadNetworkInfoBuf buf;
    LoadNetworkInfoIds ids = {0, 1};
    s32 res;
    s32 extra;
    u32 status;
    s32 found;
    void *mem;
    s32 id;
    s32 running;
    s32 state;
    s32 sub;
    s32 end;
    s32 i;
    s32 start;
    found = 0;
    network_info_flags = 0;
    get_network_adapter_type((s32 *)&status);
    if (status == 5) {
        status = 4;
    }
    if (network_config_open != 0) {
        close_network_config();
        network_config_open = 0;
    }
    open_network_config(0, network_info_work, status);
    network_config_open = 1;
    init_card_lib((void *)TLobby::get_global_63e0());
    start = 0;
    end = 2;
    switch (disc_error_code) {
    case 0:
        start = 0;
        end = 2;
        break;
    case 1:
        start = 0;
        end = 1;
        break;
    case 2:
        start = 1;
        end = 2;
        break;
    }
    for (i = start; i < end; i++) {
        id = ids.v[i];
        running = 1;
        state = 1;
        sub = 1;
        while (running) {
            update_card_requests();
            update_network_info_request();
            switch (state) {
            case 0:
                running = 0;
                break;
            case 1:
                switch (sub) {
                case 1:
                    if (request_network_info_exists(id) < 0) {
                        state = 0;
                        sub = 0;
                        break;
                    }
                    sub = 2;
                case 2:
                    switch (take_network_info_exists_result(&res, &extra)) {
                    case 200:
                        break;
                    case 0:
                        if (res == 0) {
                            state = 2;
                            sub = 1;
                        } else {
                            state = 0;
                            sub = 0;
                        }
                        break;
                    default:
                        state = 0;
                        sub = 0;
                        break;
                    }
                    break;
                }
                break;
            case 2:
                switch (sub) {
                case 1:
                    mem = xmalloc(get_network_info_file_size());
                    if (mem == NULL) {
                        state = 0;
                        sub = 0;
                        break;
                    }
                    if (request_network_info_load(id, mem) < 0) {
                        xfree(mem);
                        state = 0;
                        sub = 0;
                        break;
                    }
                    sub = 2;
                case 2:
                    switch (take_network_info_request_result(&res, &extra)) {
                    case 200:
                        break;
                    case 0:
                        xfree(mem);
                        state = 0;
                        sub = 0;
                        found = 1;
                        network_info_flags |= 1;
                        break;
                    default:
                        xfree(mem);
                        state = 0;
                        sub = 0;
                        break;
                    }
                    break;
                }
                break;
            }
            render_tick();
        }
        if (found != 0) {
            break;
        }
    }
    check_card_lib_ready();
    TLobby::load_player_data();
    if (found != 0) {
        if (TLobby__sub_8014618C() != 0) {
            return 1;
        }
        memset(&buf, 0, 0x270);
        copy_current_entry_name(buf.name, 0x80);
        TLobby__sub_803F53A0(0, (char *)buf.x, 0x40);
        if (buf.name[0] == 0 || buf.x[0] == 0) {
            return 0;
        }
    }
    return found;
}
s32 TLobby__sub_80145DB4(s32 mode) {
    s32 adapter_type;
    get_network_adapter_type(&adapter_type);
    switch (adapter_type) {
    case 0:
    case 1:
        return 0;
    case 2:
        if (mode == 1) {
            return 1;
        }
        break;
    case 4:
    case 5:
        if (mode != 1) {
            return 1;
        }
        break;
    case 3:
        break;
    }
    return 0;
}

int is_network_info_loaded(void) {  return (network_info_flags & 0x1); }

s32 TLobby::is_status_zero() {
    u8 status;

    if ((TLobby__sub_803F517C(&status) == 0) && (status == 0)) {
        return 1;
    }
    return 0;
}

s32 is_state_active() {
    u8 state;

    if (TLobby__sub_803F5678((&state)) != 0) {
        return 0;
    }
    if (state == 0) {
        return 0;
    }
    return (u32) __cntlzw(1 - state) >> 5;
}
s32 TLobby__sub_80145EE4(void) {
    u8 state;
    if (TLobby__sub_803F5678((&state)) != 0) {
        return 0;
    }
    if (state == 0) {
        return 1;
    }
    return (state == 1) ? 0 : 0;
}


s32 init_struct(u8 *info) {
    u8 state;

    if (!(network_info_flags & 1)) {
        return 0;
    }
    memset((info), 0, 0x26C);
    if (TLobby__sub_803F5678(&state) != 0) {
        return 0;
    }
    *(s32 *)((s8 *)info + 4) = (s32) state;
    TLobby__sub_803F5748(info + 0xA8);
    TLobby__sub_803F5824(info + 0xAC);
    TLobby__sub_803F5900(info + 0xBC);
    TLobby__sub_803F59DC((char *)(info + 0xC4), 0x40);
    TLobby__sub_803F5B20((char *)(info + 0x144), 0x20);
    TLobby__sub_803F5C58((char *)(info + 0x164), 0x40);
    TLobby__sub_803F5EC8((char *)(info + 0x1A4), 0x40);
    TLobby__sub_803F6000((char *)(info + 0x1E4), 0x20);
    TLobby__sub_803F6138((char *)(info + 0x204), 0x20);
    TLobby__sub_803F6138((char *)(info + 0x204), 0x20);
    TLobby__sub_803F6270((u16 *)(info + 0x244));
    copy_current_entry_name((char *)(info + 8), 0x80);
    TLobby__sub_803F4EBC((char *)(info + 0x88), 0x20);
    TLobby__sub_803F4FF4(info + 0xB4);
    TLobby__sub_803F50B8(info + 0xB8);
    return 0;
}

s32 init_work(s32 unused, u8 *info) {
    u8 scratch[0x40];
    u8 dst[0x20];

    memset(info, 0, 0x270);
    if (!(network_info_flags & 1)) {
        return 0;
    }
    copy_current_entry_name((char *)(info + 0x4), 0x80);
    TLobby__sub_803F4EBC((char *)(info + 0x84), 0x20);
    TLobby__sub_803F4FF4(info + 0x164);
    TLobby__sub_803F50B8(info + 0x168);
    TLobby__sub_803F5C58((char *)(info + 0x16C), 0x20);
    TLobby__sub_803F5D90((char *)(info + 0x18C), 0x40);
    TLobby__sub_803F5EC8((char *)(info + 0x1CC), 0x40);
    TLobby__sub_803F6000((char *)(info + 0x20C), 0x20);
    TLobby__sub_803F6138((char *)(info + 0x22C), 0x20);
    memset(dst, 0, 0x20);
    memset(scratch, 0, 0x40);
    TLobby__sub_803F524C((char *)((s32 *)dst), 0x20);
    TLobby__sub_803F53A0(0, (char *)(info + 0xA4), 0x40);
    TLobby__sub_803F53A0(1, (char *)(info + 0xE4), 0x40);
    TLobby__sub_803F53A0(2, (char *)(info + 0x124), 0x40);
    return 0;
}
