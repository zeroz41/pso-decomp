#include <string.h>
#include "types.h"
#include "pso/unk/text_8014618C.h"
#include "pso/unk/text_803F4D84.h"
#include "pso/network/NetworkInfoLoader.h"
#include "pso/network/NetworkInfoRequests.h"
#include "pso/ui/frontend/TAdPlayerLoadGC_803F18B8.h"
#include "pso/ui/frontend/TAdPlayerLoadGC_803F339C.h"
#include "pso/ui/frontend/TAdPlayerLoadGC_803F3CF4.h"
#include "pso/unk/text_80145A94.h"
#include "pso/unk/text_8042EE4C.h"
#include "pso/system/main_loop.h"
#include "pso/system/memory.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobby_80145E40.h"

struct Ids_80145A94 { s32 v[2]; };

struct Buf_80145A94 { s32 hdr; s8 name[0xA0]; s8 x[0x270 - 0xA4]; };

extern "C" {
extern s32 lbl_8043F3E8[];
extern s16 disc_error_code;
extern s32 lbl_805D56C8;
extern u16 lbl_805D56CC;
extern u16 lbl_805D56CE;
s32 TLobby__sub_80145A94(void) {
    Buf_80145A94 buf;
    Ids_80145A94 ids;
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
    lbl_805D56CC = 0;
    ids.v[0] = lbl_8043F3E8[0];
    ids.v[1] = lbl_8043F3E8[1];
    TLobby__sub_8042EE4C((s32 *)&status);
    if (status == 5) {
        status = 4;
    }
    if (lbl_805D56CE != 0) {
        TLobby__sub_803F3D60();
        lbl_805D56CE = 0;
    }
    TLobby__sub_803F3BF8(0, (void *)lbl_805D56C8, status);
    lbl_805D56CE = 1;
    TAdPlayerLoadGC__sub_803F31D8((void *)TLobby::get_global_63e0());
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
            TAdPlayerLoadGC__sub_803F2F1C();
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
                        lbl_805D56CC |= 1;
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
    TAdPlayerLoadGC__sub_803F31BC();
    TLobby::load_player_data();
    if (found != 0) {
        if (TLobby__sub_8014618C() != 0) {
            return 1;
        }
        memset(&buf, 0, 0x270);
        ((TLobby *)(buf.name))->copy_current_entry_name(0x80);
        TLobby__sub_803F53A0(0, (char *)buf.x, 0x40);
        if (buf.name[0] == 0 || buf.x[0] == 0) {
            return 0;
        }
    }
    return found;
}
s32 TLobby__sub_80145DB4(s32 arg0) {
    s32 sp8;
    TLobby__sub_8042EE4C(&sp8);
    switch (sp8) {
    case 0:
    case 1:
        return 0;
    case 2:
        if (arg0 == 1) {
            return 1;
        }
        break;
    case 4:
    case 5:
        if (arg0 != 1) {
            return 1;
        }
        break;
    case 3:
        break;
    }
    return 0;
}

}

extern "C" {
int TLobby__sub_80145E40(void) {  return (lbl_805D56CC & 0x1); }

s32 TLobby::is_status_zero() {
    u8 sp8;

    if ((TLobby__sub_803F517C(&sp8) == 0) && (sp8 == 0)) {
        return 1;
    }
    return 0;
}

s32 TLobby::is_state_active() {
    u8 sp8;

    if (TLobby__sub_803F5678((&sp8)) != 0) {
        return 0;
    }
    if (sp8 == 0) {
        return 0;
    }
    return (u32) __cntlzw(1 - sp8) >> 5;
}
s32 TLobby__sub_80145EE4(void) {
    u8 sp8;
    if (TLobby__sub_803F5678((&sp8)) != 0) {
        return 0;
    }
    if (sp8 == 0) {
        return 1;
    }
    return (sp8 == 1) ? 0 : 0;
}

}


s32 init_struct(u8 *arg0) {
    u8 sp8;

    if (!(lbl_805D56CC & 1)) {
        return 0;
    }
    memset((void *)((int)arg0), 0, 0x26C);
    if (TLobby__sub_803F5678(&sp8) != 0) {
        return 0;
    }
    *(s32 *)((s8 *)arg0 + 4) = (s32) sp8;
    TLobby__sub_803F5748(arg0 + 0xA8);
    TLobby__sub_803F5824(arg0 + 0xAC);
    TLobby__sub_803F5900(arg0 + 0xBC);
    TLobby__sub_803F59DC((char *)(arg0 + 0xC4), 0x40);
    TLobby__sub_803F5B20((char *)(arg0 + 0x144), 0x20);
    TLobby__sub_803F5C58((char *)(arg0 + 0x164), 0x40);
    TLobby__sub_803F5EC8((char *)(arg0 + 0x1A4), 0x40);
    TLobby__sub_803F6000((char *)(arg0 + 0x1E4), 0x20);
    TLobby__sub_803F6138((char *)(arg0 + 0x204), 0x20);
    TLobby__sub_803F6138((char *)(arg0 + 0x204), 0x20);
    TLobby__sub_803F6270((u16 *)(arg0 + 0x244));
    ((TLobby *)(arg0 + 8))->copy_current_entry_name(0x80);
    TLobby__sub_803F4EBC((char *)(arg0 + 0x88), 0x20);
    TLobby__sub_803F4FF4(arg0 + 0xB4);
    TLobby__sub_803F50B8(arg0 + 0xB8);
    return 0;
}

s32 init_work(s32 arg0, u8 *arg1) {
    u8 sp28[0x40];
    u8 dst[0x20];

    memset(arg1, 0, 0x270);
    if (!(lbl_805D56CC & 1)) {
        return 0;
    }
    ((TLobby *)(arg1 + 0x4))->copy_current_entry_name(0x80);
    TLobby__sub_803F4EBC((char *)(arg1 + 0x84), 0x20);
    TLobby__sub_803F4FF4(arg1 + 0x164);
    TLobby__sub_803F50B8(arg1 + 0x168);
    TLobby__sub_803F5C58((char *)(arg1 + 0x16C), 0x20);
    TLobby__sub_803F5D90((char *)(arg1 + 0x18C), 0x40);
    TLobby__sub_803F5EC8((char *)(arg1 + 0x1CC), 0x40);
    TLobby__sub_803F6000((char *)(arg1 + 0x20C), 0x20);
    TLobby__sub_803F6138((char *)(arg1 + 0x22C), 0x20);
    memset(dst, 0, 0x20);
    memset(sp28, 0, 0x40);
    TLobby__sub_803F524C((char *)((s32 *)dst), 0x20);
    TLobby__sub_803F53A0(0, (char *)(arg1 + 0xA4), 0x40);
    TLobby__sub_803F53A0(1, (char *)(arg1 + 0xE4), 0x40);
    TLobby__sub_803F53A0(2, (char *)(arg1 + 0x124), 0x40);
    return 0;
}
