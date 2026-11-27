#include "types.h"
#include "pso/network/NetworkInfoEntry.h"
#include <string.h>
#include "pso/network/NetworkConfig.h"
#include "pso/network/NetworkInfoLoader.h"
#include "pso/network/NetworkInfoRequests.h"
#include "pso/system/save/McFsGc.h"
#include "pso/system/save/McFsGcRequests.h"
#include "pso/network/NetworkSettings.h"
#include "pso/ui/frontend/TAdTrialModemChkGC.h"
#include "pso/system/main_loop.h"
#include "pso/system/memory.h"
#include "pso/network/TLobby.h"
#include "pso/system/SwitcherLaunch.h"
#include "pso/player/PlayerDataLoad.h"

BOOL read_dial_prefix(char *dst) {
    if (get_network_config_outside_line_number(dst, 0x20) == 0) {
        return strlen(dst) != 0 ? TRUE : FALSE;
    }
    return FALSE;
}

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
    init_card_lib(get_player_data_load_buffer());
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
    load_player_data();
    if (found != 0) {
        if (has_broadband_adapter() != 0) {
            return 1;
        }
        memset(&buf, 0, 0x270);
        get_network_config_login_user(buf.name, 0x80);
        get_network_config_phone_number(0, (char *)buf.x, 0x40);
        if (buf.name[0] == 0 || buf.x[0] == 0) {
            return 0;
        }
    }
    return found;
}
s32 has_network_adapter(s32 mode) {
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

s32 is_tone_dialing() {
    u8 status;

    if ((get_network_config_dial_type(&status) == 0) && (status == 0)) {
        return 1;
    }
    return 0;
}

s32 is_pppoe_selected() {
    u8 state;

    if (get_network_config_ip_set_type((&state)) != 0) {
        return 0;
    }
    if (state == 0) {
        return 0;
    }
    return (u32) __cntlzw(1 - state) >> 5;
}
s32 is_dhcp_selected(void) {
    u8 state;
    if (get_network_config_ip_set_type((&state)) != 0) {
        return 0;
    }
    if (state == 0) {
        return 1;
    }
    return (state == 1) ? 0 : 0;
}


s32 init_struct(LanConfigRecord *info) {
    u8 state;

    if (!(network_info_flags & 1)) {
        return 0;
    }
    memset(info, 0, sizeof(*info));
    if (get_network_config_ip_set_type(&state) != 0) {
        return 0;
    }
    info->connection_type = state;
    get_network_config_ip_address(&info->ip_addr);
    get_network_config_subnet_mask(&info->netmask);
    get_network_config_default_gateway(&info->gateway);
    get_network_config_pc_name(info->dhcp_hostname, sizeof(info->dhcp_hostname));
    get_network_config_mail_name(info->mail_name, sizeof(info->mail_name));
    get_network_config_mail_address(info->mail_address, sizeof(info->mail_address));
    get_network_config_pop_server(info->pop_server, sizeof(info->pop_server));
    get_network_config_pop_id(info->pop_user, sizeof(info->pop_user));
    get_network_config_pop_password(info->pop_password, sizeof(info->pop_password));
    get_network_config_pop_password(info->pop_password, sizeof(info->pop_password));
    get_network_config_proxy_port(&info->proxy_port);
    get_network_config_login_user(info->ppp_user, sizeof(info->ppp_user));
    get_network_config_login_password(info->ppp_password, sizeof(info->ppp_password));
    get_network_config_dns_server1(&info->dns1);
    get_network_config_dns_server2(&info->dns2);
    return 0;
}

s32 init_work(s32 unused, AccountConfigRecord *info) {
    u8 scratch[0x40];
    u8 dst[0x20];

    memset(info, 0, 0x270);
    if (!(network_info_flags & 1)) {
        return 0;
    }
    get_network_config_login_user(info->login_user, sizeof(info->login_user));
    get_network_config_login_password(info->login_password, sizeof(info->login_password));
    get_network_config_dns_server1(&info->dns1);
    get_network_config_dns_server2(&info->dns2);
    get_network_config_mail_address(info->mail_address, sizeof(info->mail_address));
    get_network_config_mail_server(info->mail_server, sizeof(info->mail_server));
    get_network_config_pop_server(info->pop_server, sizeof(info->pop_server));
    get_network_config_pop_id(info->pop_user, sizeof(info->pop_user));
    get_network_config_pop_password(info->pop_password, sizeof(info->pop_password));
    memset(dst, 0, 0x20);
    memset(scratch, 0, 0x40);
    get_network_config_outside_line_number((char *)((s32 *)dst), 0x20);
    get_network_config_phone_number(0, info->phone[0], sizeof(info->phone[0]));
    get_network_config_phone_number(1, info->phone[1], sizeof(info->phone[1]));
    get_network_config_phone_number(2, info->phone[2], sizeof(info->phone[2]));
    return 0;
}

// Nonzero when the network adapter reports type 1; TAdExNetConfirmGC::vfunc_7 picks its
// message text by it.
s32 is_confirmed() {
    s32 adapter_type;

    get_network_adapter_type(&adapter_type);
    return (u32) __cntlzw(1 - adapter_type) >> 5;
}

s32 has_broadband_adapter(void) {
    s32 status;

    get_network_adapter_type(&status);
    switch (status) {
    case 0:
    case 1:
    case 2:
        return 0;
    case 4:
    case 5:
        return 1;
    default:
        return 0;
    }
}
